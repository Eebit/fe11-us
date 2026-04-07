#include "global.h"

#include "unknown_types.hpp"
#include "unknown_funcs.h"

#include "database.hpp"
#include "item.hpp"
#include "map.hpp"
#include "unit.hpp"

extern struct UnkStruct_02196f0c * data_02196f0c;

extern struct Unit * gUnitList;

// Forward declarations

EC s32 func_02038e34(struct ItemData * item);
EC s32 func_02038e3c(struct ItemData * item, struct Unit * unit);
EC BOOL func_02038f94(struct Item * item);

EC BOOL func_02038348(struct ItemData * item)
{
    if (item->type == ITYPE_MAGIC || item->type == ITYPE_STAFF)
    {
        return TRUE;
    }

    if (item->attributes & IA_FORTIFY)
    {
        return TRUE;
    }

    return FALSE;
}

// Only checks the lower 32 bits of the item attributes
static inline BOOL CheckItemAttr(struct ItemData * item, u32 attr)
{
    return item->attributes & attr;
}

EC BOOL func_02038384(struct ItemData * item, struct Unit * unit)
{
    struct ItemData * pItem;
    int iVar5;
    struct JobData * job;
    u8 * pWeaponLevel;
    int hp;
    int type;
    int level;
    int slot;
    int i;

    if (!CheckItemAttr(item, 1))
    {
        return FALSE;
    }

    if (item->type < ITYPE_DRAGONSTONE)
    {
        if (!func_0203c834(unit, item, FALSE))
        {
            return FALSE;
        }
    }

    switch (item->effect)
    {
        case ITEM_EFFECT_HEAL:
            hp = unit->hp;

            if (hp >= GetUnitMaxHp(unit))
            {
                return FALSE;
            }

            return TRUE;

        case ITEM_EFFECT_STAT_BOOST:
            if (unit->state2 & 0x48000)
            {
                return FALSE;
            }

            if (item->movBoost != 0)
            {
                if (func_0203c77c(unit) >= 0x20)
                {
                    return FALSE;
                }

                return TRUE;
            }

            for (i = 0; i < 8; i++)
            {
                int cap;

                if (item->statBoost[i] == 0)
                {
                    continue;
                }

                cap = unit->pJobData->caps[i];

                if (GetUnitStat(unit, i, NULL, 1) >= cap)
                {
                    continue;
                }

                return TRUE;
            }

            return FALSE;

        case ITEM_EFFECT_WLVL_BOOST:
            if (unit->state2 & 0x48000)
            {
                return FALSE;
            }

            slot = GetUnitEquippedWeaponSlot(unit);

            if (slot == -1)
            {
                return FALSE;
            }

            pItem = unit->items[slot].GetData();

            type = pItem->type;

            if (type >= ITYPE_DRAGONSTONE)
            {
                return FALSE;
            }

            if (!func_0203c7ac(unit, type))
            {
                return FALSE;
            }

            iVar5 = func_0203c7ac(unit, type);

            for (i = 0, pWeaponLevel = gFE11Database->pWeaponLevel; i < 5; i++)
            {
                if (iVar5 >= pWeaponLevel[i])
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

            if (data_02196f0c->state & 0x40)
            {
                return FALSE;
            }

            for (i = 0; i < 8; i++)
            {
                int cap;

                if (item->statBoost[i] == 0)
                {
                    continue;
                }

                cap = unit->pJobData->caps[i];
                if (GetUnitStat(unit, i, NULL, 1) >= cap)
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

            if (data_02196f0c->state & 0x40)
            {
                return FALSE;
            }

            if (data_ov000_021e3324->unk_02 == 0)
            {
                return FALSE;
            }

            return TRUE;

        case ITEM_EFFECT_PROMOTE:
            if (func_ov000_021a47e4() && !(data_02196f0c->state & 0x40))
            {
                return FALSE;
            }

            if (unit->state2 & 0x48000)
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

            if (item->attributes & IA_ELYSIAN_WHIP)
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

            if (func_ov000_021a47e4())
            {
                return FALSE;
            }

            if (data_02196f0c->state & 0x40)
            {
                return FALSE;
            }

            return TRUE;
    }

    return FALSE;
}

/* NONMATCHING: https://decomp.me/scratch/D8kjb */
EC void func_02038708(struct ItemData * item, struct Unit * unit)
{
    switch (item->effect)
    {
        case ITEM_EFFECT_HEAL:
        {
            s32 hp = unit->hp;
            hp += func_02038e34(item);

            if (hp > GetUnitMaxHp(unit))
            {
                hp = GetUnitMaxHp(unit);
            }

            unit->hp = hp;

            break;
        }
        case ITEM_EFFECT_STAT_BOOST:
        {
            s32 unk_1b;
            s32 i;
            s16 * r7;
            s8 * r8;
            s8 * r9;
            s32 cap;

            unk_1b = item->movBoost;

            if (item->movBoost != 0)
            {
                unk_1b = item->movBoost;
                unk_1b += func_0203c77c(unit);

                if (unk_1b < 0x20)
                {
                    unit->unk_6d = unit->unk_6d + item->movBoost;
                }
                else
                {
                    unit->unk_6d = 0x20 - unit->pJobData->mov;
                }
            }

            for (r9 = item->statBoost, i = 0; i < 8; i++)
            {
                if (r9[i] == 0)
                {
                    continue;
                }

                do
                {
                    s32 r2;

                    r8 = unit->unk_50;
                    r7 = unit->unk_58;

                    cap = unit->pJobData->caps[i];

                    if (GetUnitStat(unit, i, NULL, 1) < cap)
                    {
                        cap = unit->pJobData->caps[i];
                        r2 = cap - GetUnitStat(unit, i, NULL, 1);

                        if (r2 > item->statBoost[i])
                        {
                            r2 = item->statBoost[i];
                        }

                        r8[i] += (s8)(r2);
                        r7[i] += (s16)(r2 * 100);
                    }

                } while (0);
            }

            break;
        }
        case ITEM_EFFECT_WLVL_BOOST:
        {
            int i;
            u8 * pWeaponLevel;
            int iVar5;
            int type;
            int req;
            struct ItemData * pEquippedItem = unit->items[GetUnitEquippedWeaponSlot(unit)].GetData();
            type = pEquippedItem->type;

            iVar5 = func_0203c7ac(unit, type);

            for (i = 0, pWeaponLevel = gFE11Database->pWeaponLevel; i < 5; i++)
            {
                if (iVar5 >= pWeaponLevel[i])
                {
                    break;
                }
            }

            req = pWeaponLevel[i - 1];
            unit->unk_84[type] = req - func_0203c7e4(unit, type);

            break;
        }
        case ITEM_EFFECT_TEMP_RES_BOOST:
        {
            s8 * r2;
            int i;

            for (r2 = item->statBoost, i = 0; i < 8; i++)
            {
                if (r2[i] == 0)
                {
                    continue;
                }

                if (i != 7)
                {
                    continue;
                }

                unit->unk_91 = item->statBoost[i];
            }

            break;
        }
        case ITEM_EFFECT_TORCH:
        {
            unit->unk_92 = item->statBoost[0] << 1;
            break;
        }
    }

    return;
}

EC BOOL func_02038914(struct ItemData * item, u32 x, u32 y)
{
    int i;
    u32 unitId;
    int hp;
    struct Unit * pUnit;
    struct Item * it;

    if (gMapStateManager == NULL)
    {
        return FALSE;
    }

    if (item->type != ITYPE_MAGIC)
    {
        return FALSE;
    }

    switch (item->effect)
    {
        case ITEM_EFFECT_HEAL:
            pUnit = NULL;

            if (item->attributes & IA_FORTIFY)
            {
                if (x != -1)
                {
                    return FALSE;
                }

                for (pUnit = Force::Get(data_ov000_021e3324->phase)->head; pUnit != NULL; pUnit = pUnit->unk_3c)
                {
                    int hp;

                    if (pUnit->state2 & 0x00021020)
                    {
                        continue;
                    }

                    hp = pUnit->hp;

                    if (hp >= GetUnitMaxHp(pUnit))
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

            unitId = gMapStateManager->unk_028[(x | y << 5)];

            if (unitId != 0)
            {
                pUnit = gUnitList + unitId - 1;
            }

            if (pUnit == NULL)
            {
                return FALSE;
            }

            if (!((pUnit->force->id == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            hp = pUnit->hp;

            if (hp >= GetUnitMaxHp(pUnit))
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

            unitId = gMapStateManager->unk_028[(x | y << 5)];

            if (unitId == 0)
            {
                pUnit = NULL;
            }
            else
            {
                pUnit = gUnitList + unitId - 1;
            }

            if (pUnit == NULL)
            {
                return FALSE;
            }

            if (!((pUnit->force->id == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            for (i = 0; i < 8; i++)
            {
                int cap;

                if (item->statBoost[i] == 0)
                {
                    continue;
                }

                cap = pUnit->pJobData->caps[i];

                if (GetUnitStat(pUnit, i, NULL, 1) >= cap)
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

            unitId = gMapStateManager->unk_028[(x | (y << 5))];

            if (unitId == 0)
            {
                pUnit = NULL;
            }
            else
            {
                pUnit = gUnitList + unitId - 1;
            }

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

            unitId = gMapStateManager->unk_028[(x | (y << 5))];

            if (unitId == 0)
            {
                pUnit = NULL;
            }
            else
            {
                pUnit = gUnitList + unitId - 1;
            }

            if (pUnit == NULL)
            {
                return FALSE;
            }

            if (!((pUnit->force->id == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            it = pUnit->items;

            for (i = 0; i < 5; it++, i++)
            {
                if (!func_02038f94(it))
                {
                    continue;
                }

                return TRUE;
            }

            return FALSE;

        case ITEM_EFFECT_REVIVE:
            if (func_ov000_021a47e4())
            {
                return FALSE;
            }

            if (x != -1)
            {
                return FALSE;
            }

            for (pUnit = Force::Get(3)->head; pUnit != NULL; pUnit = pUnit->unk_3c)
            {
                if (pUnit->state2 & 0x20000000)
                {
                    continue;
                }

                return TRUE;
            }

            return FALSE;
    }

    return FALSE;
}

EC void func_02038ce4(struct ItemData * item, struct Unit * unitA, struct Unit * unitB)
{
    int hp;
    int i;
    struct Unit * pUnit;
    s8 * r2;

    switch (item->effect)
    {
        case ITEM_EFFECT_HEAL:
            if (item->attributes & IA_FORTIFY)
            {
                for (pUnit = Force::Get(data_ov000_021e3324->phase)->head; pUnit != NULL; pUnit = pUnit->unk_3c)
                {
                    if (pUnit->state2 & 0x0021020)
                    {
                        continue;
                    }

                    if (pUnit == unitA)
                    {
                        continue;
                    }

                    hp = pUnit->hp;
                    hp += func_02038e3c(item, unitA);

                    if (hp > GetUnitMaxHp(pUnit))
                    {
                        hp = GetUnitMaxHp(pUnit);
                    }

                    pUnit->hp = hp;
                }
            }
            else
            {
                hp = unitB->hp;
                hp += func_02038e3c(item, unitA);

                if (hp > GetUnitMaxHp(unitB))
                {
                    hp = GetUnitMaxHp(unitB);
                }

                unitB->hp = hp;
            }

            break;

        case ITEM_EFFECT_TEMP_RES_BOOST:
            for (r2 = item->statBoost, i = 0; i < 8; i++)
            {
                if (r2[i] == 0)
                {
                    continue;
                }

                if (i != 7)
                {
                    continue;
                }

                unitB->unk_91 = item->statBoost[i];
            }

            break;
    }

    return;
}

EC s32 GetItemMaxRange(struct ItemData * item, struct Unit * unit)
{
    if (item->maxRange != 0xfe)
    {
        return item->maxRange;
    }

    return GetUnitMag(unit, NULL, TRUE) >> 1;
}

EC s32 func_02038e34(struct ItemData * item)
{
    return item->statBoost[0];
}

EC s32 func_02038e3c(struct ItemData * item, struct Unit * unit)
{
    s32 var = item->statBoost[0];

    if (item->attributes & IA_HEAL_STAFF)
    {
        var += (GetUnitMag(unit, NULL, TRUE) >> 1);
    }

    return var;
}

EC BOOL func_02038e80(struct ItemData * item, struct Unit * unit)
{
    if (item->attributes & IA_UNLOCK_DOOR)
    {
        return TRUE;
    }

    if (item->attributes & IA_UNK_22)
    {
        if (unit != NULL && CheckUnitAttribute(unit, CA_UNK_10))
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL func_02038edc(struct ItemData * item, struct Unit * unit)
{
    if (item->attributes & IA_UNLOCK_BRIDGE)
    {
        return TRUE;
    }

    if (item->attributes & IA_UNK_22)
    {
        if (unit != NULL && CheckUnitAttribute(unit, CA_UNK_10))
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL func_02038f38(struct ItemData * item, struct Unit * unit)
{
    if (item->attributes & IA_UNLOCK_CHEST)
    {
        return TRUE;
    }

    if ((item->attributes & IA_UNK_22))
    {
        if (unit != NULL && CheckUnitAttribute(unit, CA_UNK_10))
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL func_02038f94(struct Item * item)
{
    s32 uses;
    struct ItemData * itemData = item->GetData();

    if (itemData->type == ITYPE_ITEM)
    {
        return FALSE;
    }

    if (itemData->effect == ITEM_EFFECT_REPAIR)
    {
        return FALSE;
    }

    uses = itemData->uses;

    if (uses != 0 && item->uses < uses)
    {
        return TRUE;
    }

    return FALSE;
}

EC struct JobData * GetJInfoFromItem(struct ItemData * item, struct Unit * unit)
{
    if (item->type != ITYPE_DRAGONSTONE)
    {
        return unit->pJobData;
    }

    if (!func_0203c834(unit, item, 1))
    {
        return unit->pJobData;
    }

    switch (item->effect)
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
