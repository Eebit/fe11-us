#include "global.h"

#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "database.hpp"
#include "item.hpp"
#include "map.hpp"
#include "unit.hpp"

extern struct UnkStruct_02196f0c * data_02196f0c;

BOOL ItemData::IsMagical(void)
{
    if (this->type == ITYPE_MAGIC || this->type == ITYPE_STAFF)
    {
        return TRUE;
    }

    if (this->attributes & IA_MAGIC)
    {
        return TRUE;
    }

    return FALSE;
}

BOOL ItemData::IsUsableBy(Unit * unit)
{
    s32 wlvl;
    struct JobData * job;
    u8 * pWeaponLevel;
    s32 type;
    s32 level;
    s32 slot;
    s32 i;

    if (!this->CheckItemAttr(IA_USABLE))
    {
        return FALSE;
    }

    if (this->type < ITYPE_DRAGONSTONE)
    {
        if (!unit->CanEquip(this, FALSE))
        {
            return FALSE;
        }
    }

    switch (this->effect)
    {
        case ITEM_EFFECT_HEAL:
            if (unit->GetHp() >= unit->GetMaxHp())
            {
                return FALSE;
            }

            return TRUE;

        case ITEM_EFFECT_STAT_BOOST:
            if (unit->state2 & (US_UNK_15 | US_UNK_18))
            {
                return FALSE;
            }

            if (this->movBoost != 0)
            {
                if (unit->GetMov() >= MAX_MOV)
                {
                    return FALSE;
                }

                return TRUE;
            }

            for (i = 0; i < UNIT_STAT_COUNT; i++)
            {
                if (this->statBoost[i] == 0)
                {
                    continue;
                }

                if (unit->GetStat(i, NULL, TRUE) >= unit->GetStatCap(i))
                {
                    continue;
                }

                return TRUE;
            }

            return FALSE;

        case ITEM_EFFECT_WLVL_BOOST:
            if (unit->state2 & (US_UNK_15 | US_UNK_18))
            {
                return FALSE;
            }

            slot = unit->GetEquippedWeaponSlot();

            if (slot == -1)
            {
                return FALSE;
            }

            type = unit->items[slot].GetData()->type;

            if (type >= ITYPE_DRAGONSTONE)
            {
                return FALSE;
            }

            if (!unit->GetWeaponLevel(type))
            {
                return FALSE;
            }

            wlvl = unit->GetWeaponLevel(type);

            for (i = 0, pWeaponLevel = gFE11Database->pWeaponLevel; i < 5; i++)
            {
                if (wlvl >= pWeaponLevel[i])
                {
                    break;
                }
            }

            if (i == 0)
            {
                return FALSE;
            }

            return TRUE;

        case ITEM_EFFECT_TEMP_RES_BOOST:
            if (gMapStateManager == NULL)
            {
                return FALSE;
            }

            if (data_02196f0c->state & GAME_STATE_BATTLE_PREP)
            {
                return FALSE;
            }

            for (i = 0; i < UNIT_STAT_COUNT; i++)
            {
                if (this->statBoost[i] == 0)
                {
                    continue;
                }

                if (unit->GetStat(i, NULL, TRUE) >= unit->GetStatCap(i))
                {
                    continue;
                }

                return TRUE;
            }

            return FALSE;

        case ITEM_EFFECT_TORCH:
            if (gMapStateManager == NULL)
            {
                return FALSE;
            }

            if (data_02196f0c->state & GAME_STATE_BATTLE_PREP)
            {
                return FALSE;
            }

            if (data_ov000_021e3324->fogActive == 0)
            {
                return FALSE;
            }

            return TRUE;

        case ITEM_EFFECT_PROMOTE:
            if (IsLinkArena() && !(data_02196f0c->state & GAME_STATE_BATTLE_PREP))
            {
                return FALSE;
            }

            if (unit->state2 & (US_UNK_15 | US_UNK_18))
            {
                return FALSE;
            }

            job = unit->pJobData;

            if (job->pPromoteToJob == NULL)
            {
                return FALSE;
            }

            level = unit->level;

            if (level < 10)
            {
                return FALSE;
            }

            if (this->attributes & IA_ELYSIAN_WHIP)
            {
                if (job != GetJobByJidStr("JID_PEGASUSKNIGHT_F"))
                {
                    return FALSE;
                }
            }

            return TRUE;

        case ITEM_EFFECT_IOTES_SHIELD:
        case ITEM_EFFECT_WARP:
        case ITEM_EFFECT_REPAIR:
        case ITEM_EFFECT_REVIVE:
            break;

        case ITEM_EFFECT_A:
            if (gMapStateManager == NULL)
            {
                return FALSE;
            }

            if (IsLinkArena())
            {
                return FALSE;
            }

            if (data_02196f0c->state & GAME_STATE_BATTLE_PREP)
            {
                return FALSE;
            }

            return TRUE;
    }

    return FALSE;
}

void ItemData::ApplyEffect(Unit * unit)
{
    switch (this->effect)
    {
        case ITEM_EFFECT_HEAL:
        {
            unit->SetHp(unit->GetHp() + this->GetHealAmount());

            break;
        }
        case ITEM_EFFECT_STAT_BOOST:
        {
            s32 mov;
            s32 movBoost;
            s16 * r7;
            s8 * r8;
            s8 * pStatBoosts;
            s32 cap;
            s32 cap2;
            s32 i;

            movBoost = this->movBoost;

            if (this->movBoost != 0)
            {
                mov = unit->GetMov();
                mov += movBoost;

                if (mov < MAX_MOV)
                {
                    unit->mov = unit->mov + this->movBoost;
                }
                else
                {
                    unit->mov = MAX_MOV - unit->pJobData->mov;
                }
            }

            pStatBoosts = this->statBoost;

            for (i = 0; i < UNIT_STAT_COUNT; i++)
            {
                s32 boost;

                if (pStatBoosts[i] == 0)
                {
                    continue;
                }

                r8 = unit->unk_50;
                r7 = unit->unk_58;

                cap = unit->pJobData->caps[i];

                if (unit->GetStat(i, NULL, TRUE) < cap)
                {
                    cap2 = unit->pJobData->caps[i];
                    boost = cap2 - unit->GetStat(i, NULL, TRUE);

                    if (boost > this->statBoost[i])
                    {
                        boost = this->statBoost[i];
                    }

                    r8[i] = (s8)(boost) + r8[i];
                    r7[i] = (s16)(boost * 100) + r7[i];
                }
            }

            break;
        }
        case ITEM_EFFECT_WLVL_BOOST:
        {
            int i; // Type required for match
            u8 * pWeaponLevel;
            s32 wlvl;
            s32 type;
            s32 req;
            struct ItemData * pEquippedItem = unit->items[unit->GetEquippedWeaponSlot()].GetData();
            type = pEquippedItem->type;

            wlvl = unit->GetWeaponLevel(type);

            for (i = 0, pWeaponLevel = gFE11Database->pWeaponLevel; i < 5; i++)
            {
                if (wlvl >= pWeaponLevel[i])
                {
                    break;
                }
            }

            req = pWeaponLevel[i - 1];
            unit->unk_84[type] = req - unit->GetBaseWeaponLevel(type);

            break;
        }
        case ITEM_EFFECT_TEMP_RES_BOOST:
        {
            s8 * pStatBoosts;
            s32 i;

            for (pStatBoosts = this->statBoost, i = 0; i < UNIT_STAT_COUNT; i++)
            {
                if (pStatBoosts[i] == 0)
                {
                    continue;
                }

                if (i != UNIT_STAT_RES)
                {
                    continue;
                }

                unit->unk_91 = this->statBoost[i];
            }

            break;
        }
        case ITEM_EFFECT_TORCH:
        {
            unit->unk_92 = this->statBoost[0] << 1;
            break;
        }
    }

    return;
}

BOOL ItemData::IsUsableOn(u32 x, u32 y)
{
    s32 i;
    Unit * pUnit;
    Item * it;

    if (gMapStateManager == NULL)
    {
        return FALSE;
    }

    if (this->type != ITYPE_STAFF)
    {
        return FALSE;
    }

    switch (this->effect)
    {
        case ITEM_EFFECT_HEAL:
            if (this->attributes & IA_FORTIFY)
            {
                if (x != -1)
                {
                    return FALSE;
                }

                for (pUnit = Force::Get(data_ov000_021e3324->phase)->head; pUnit != NULL; pUnit = pUnit->next)
                {
                    if (pUnit->state2 & (US_UNK_5 | US_NOT_PRESENT | US_HOVERED))
                    {
                        continue;
                    }

                    if (pUnit->GetHp() >= pUnit->GetMaxHp())
                    {
                        continue;
                    }

                    return TRUE;
                }

                return FALSE;
            }

            if (x == -1)
            {
                return FALSE;
            }

            pUnit = GetUnit(gMapStateManager->unk_028[(x | y << 5)]);

            if (pUnit == NULL)
            {
                return FALSE;
            }

            if (!((pUnit->force->id == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            if (pUnit->GetHp() >= pUnit->GetMaxHp())
            {
                return FALSE;
            }

            return TRUE;

        case ITEM_EFFECT_STAT_BOOST:
            break;

        case ITEM_EFFECT_WLVL_BOOST:
            break;

        case ITEM_EFFECT_TEMP_RES_BOOST:
            if (x == -1)
            {
                return FALSE;
            }

            pUnit = GetUnit(gMapStateManager->unk_028[(x | y << 5)]);

            if (pUnit == NULL)
            {
                return FALSE;
            }

            if (!((pUnit->force->id == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            for (i = 0; i < UNIT_STAT_COUNT; i++)
            {
                if (this->statBoost[i] == 0)
                {
                    continue;
                }

                if (pUnit->GetStat(i, NULL, TRUE) >= pUnit->GetStatCap(i))
                {
                    continue;
                }

                return TRUE;
            }

            return FALSE;

        case ITEM_EFFECT_TORCH:
            break;

        case ITEM_EFFECT_PROMOTE:
            break;

        case ITEM_EFFECT_IOTES_SHIELD:
            break;

        case ITEM_EFFECT_WARP:
            if (x == -1)
            {
                return FALSE;
            }

            pUnit = GetUnit(gMapStateManager->unk_028[(x | (y << 5))]);

            if (pUnit == NULL)
            {
                return FALSE;
            }

            if (!((pUnit->force->id == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            return TRUE;

        case ITEM_EFFECT_REPAIR:
            if (x == -1)
            {
                return FALSE;
            }

            pUnit = GetUnit(gMapStateManager->unk_028[(x | (y << 5))]);

            if (pUnit == NULL)
            {
                return FALSE;
            }

            if (!((pUnit->force->id == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            it = pUnit->items;

            for (i = 0; i < UNIT_ITEM_COUNT; it++, i++)
            {
                if (!it->IsRepairable())
                {
                    continue;
                }

                return TRUE;
            }

            return FALSE;

        case ITEM_EFFECT_REVIVE:
            if (IsLinkArena())
            {
                return FALSE;
            }

            if (x != -1)
            {
                return FALSE;
            }

            for (pUnit = Force::Get(3)->head; pUnit != NULL; pUnit = pUnit->next)
            {
                if (pUnit->state2 & US_EVENT_DEAD)
                {
                    continue;
                }

                return TRUE;
            }

            return FALSE;
    }

    return FALSE;
}

void ItemData::ApplyEffect(Unit * self, Unit * target)
{
    s32 i;
    s8 * pStatBoosts;

    switch (this->effect)
    {
        case ITEM_EFFECT_HEAL:
            if (this->attributes & IA_FORTIFY)
            {
                int hp; // Type required for matching
                Unit * pUnit;

                for (pUnit = Force::Get(data_ov000_021e3324->phase)->head; pUnit != NULL; pUnit = pUnit->next)
                {
                    if (pUnit->state2 & (US_UNK_5 | US_NOT_PRESENT | US_HOVERED))
                    {
                        continue;
                    }

                    if (pUnit == self)
                    {
                        continue;
                    }

                    // Seems odd that this couldn't be inlined like the other cases
                    hp = pUnit->GetHp();
                    pUnit->SetHp(hp + this->GetStaffHealAmount(self));
                }
            }
            else
            {
                target->SetHp(target->GetHp() + this->GetStaffHealAmount(self));
            }

            break;

        case ITEM_EFFECT_TEMP_RES_BOOST:
            for (pStatBoosts = this->statBoost, i = 0; i < UNIT_STAT_COUNT; i++)
            {
                if (pStatBoosts[i] == 0)
                {
                    continue;
                }

                if (i != UNIT_STAT_RES)
                {
                    continue;
                }

                target->unk_91 = this->statBoost[i];
            }

            break;
    }

    return;
}

s32 ItemData::GetMaxRange(Unit * unit)
{
    if (this->maxRange != 0xfe)
    {
        return this->maxRange;
    }

    return unit->GetMag(NULL, TRUE) >> 1;
}

s32 ItemData::GetHealAmount(void)
{
    return this->statBoost[0];
}

s32 ItemData::GetStaffHealAmount(Unit * unit)
{
    s32 amount = this->statBoost[0];

    if (this->attributes & IA_HEAL_STAFF)
    {
        amount += (unit->GetMag(NULL, TRUE) >> 1);
    }

    return amount;
}

BOOL ItemData::UnlocksDoor(Unit * unit)
{
    if (this->attributes & IA_UNLOCK_DOOR)
    {
        return TRUE;
    }

    if (this->attributes & IA_UNK_22)
    {
        if (unit != NULL && unit->CheckAttribute(CA_UNK_10))
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL ItemData::UnlocksBridge(Unit * unit)
{
    if (this->attributes & IA_UNLOCK_BRIDGE)
    {
        return TRUE;
    }

    if (this->attributes & IA_UNK_22)
    {
        if (unit != NULL && unit->CheckAttribute(CA_UNK_10))
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL ItemData::UnlocksChest(Unit * unit)
{
    if (this->attributes & IA_UNLOCK_CHEST)
    {
        return TRUE;
    }

    if (this->attributes & IA_UNK_22)
    {
        if (unit != NULL && unit->CheckAttribute(CA_UNK_10))
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL Item::IsRepairable(void)
{
    s32 uses;
    struct ItemData * itemData = this->GetData();

    if (itemData->type == ITYPE_ITEM)
    {
        return FALSE;
    }

    if (itemData->effect == ITEM_EFFECT_REPAIR)
    {
        return FALSE;
    }

    uses = itemData->uses;

    if (uses != 0 && this->uses < uses)
    {
        return TRUE;
    }

    return FALSE;
}

struct JobData * ItemData::GetEffectiveJob(Unit * unit)
{
    if (this->type != ITYPE_DRAGONSTONE)
    {
        return unit->pJobData;
    }

    if (!unit->CanEquip(this, TRUE))
    {
        return unit->pJobData;
    }

    switch (this->effect)
    {
        case ITEM_EFFECT_FIRESTONE:
            return GetJobByJidStr("JID_FIREDRAGON");

        case ITEM_EFFECT_EARTHSTONE:
            return GetJobByJidStr("JID_EARTHDRAGON");

        case ITEM_EFFECT_MAGESTONE:
            return GetJobByJidStr("JID_MAGICDRAGON");

        case ITEM_EFFECT_DIVINESTONE:
            return GetJobByJidStr("JID_GODDESSDRAGON_F");

        default:
            return unit->pJobData;
    }
}
