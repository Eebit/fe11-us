#include "global.h"

#include "unit.h"
#include "unknown_types.hpp"
#include "unknown_funcs.h"
#include "unknown_data.h"
#include "map.hpp"

enum
{
    ITYPE_SWORD       = 0,
    ITYPE_LANCE       = 1,
    ITYPE_AXE         = 2,
    ITYPE_BOW         = 3,
    ITYPE_STAFF       = 4,
    ITYPE_MAGIC       = 5,
    ITYPE_DRAGONSTONE = 6,
    ITYPE_BALLISTA    = 7,
    ITYPE_ITEM        = 8,
};

extern struct UnkStruct_02196f0c * data_02196f0c;

extern struct Unit * gUnitList;

// Forward declarations

EC s32 func_02038e34(struct ItemData * item);
EC s32 func_02038e3c(struct ItemData * item, struct Unit * unit);
EC BOOL func_02038f94(struct Item * item);

EC const char * func_02038328(struct ItemData * item)
{
    return func_02039e10(item->id);
}

EC const char * func_02038338(struct ItemData * item)
{
    return func_02039e10(item->pName);
}

EC BOOL func_02038348(struct ItemData * item)
{
    if (item->type == ITYPE_STAFF || item->type == ITYPE_MAGIC)
    {
        return TRUE;
    }

    if (item->attributes & 4)
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

    switch (item->unk_11)
    {
        case 0:
            hp = unit->hp;

            if (hp >= GetUnitMaxHp(unit))
            {
                return FALSE;
            }

            return TRUE;

        case 1:
            if (unit->state2 & 0x48000)
            {
                return FALSE;
            }

            if (item->unk_1b != 0)
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

                if (item->unk_1c[i] == 0)
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

        case 2:
            if (unit->state2 & 0x48000)
            {
                return FALSE;
            }

            slot = GetUnitEquippedWeaponSlot(unit);

            if (slot == -1)
            {
                return FALSE;
            }

            pItem = GetItemData(unit->items + slot);

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

            for (i = 0, pWeaponLevel = data_02197254->pWeaponLevel; i < 5; i++)
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

        case 3:
            if (gMapStateManager == 0)
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

                if (item->unk_1c[i] == 0)
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

        case 4:
            if (gMapStateManager == 0)
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

        case 5:
            if (func_ov000_021a47e4() && !(data_02196f0c->state & 0x40))
            {
                return FALSE;
            }

            if (unit->state2 & 0x48000)
            {
                return FALSE;
            }

            job = unit->pJobData;

            if (job->pPromoteJob == NULL)
            {
                return FALSE;
            }

            level = unit->level;

            if (level < 10)
            {
                return FALSE;
            }

            if (item->attributes & 0x400000000)
            {
                if (job != GetJobByJidStr("JID_PEGASUSKNIGHT_F"))
                {
                    return FALSE;
                }
            }

            return TRUE;

        case 6:
        case 7:
        case 8:
        case 9:
            break;

        case 10:
            if (gMapStateManager == 0)
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
    switch (item->unk_11)
    {
        case 0:
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
        case 1:
        {
            s32 unk_1b;
            s32 i;
            s16 * r7;
            s8 * r8;
            s8 * r9;
            s32 cap;

            unk_1b = item->unk_1b;

            if (item->unk_1b != 0)
            {
                unk_1b = item->unk_1b;
                unk_1b += func_0203c77c(unit);
                if (unk_1b < 0x20)
                {
                    unit->unk_6d = unit->unk_6d + item->unk_1b;
                }
                else
                {
                    unit->unk_6d = 0x20 - unit->pJobData->mov;
                }
            }

            for (r9 = item->unk_1c, i = 0; i < 8; i++)
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

                        if (r2 > item->unk_1c[i])
                        {
                            r2 = item->unk_1c[i];
                        }

                        r8[i] += (s8)(r2);
                        r7[i] += (s16)(r2 * 100);
                    }

                } while (0);
            }

            break;
        }
        case 2:
        {
            int i;
            u8 * pWeaponLevel;
            int iVar5;
            int type;
            int req;
            struct ItemData * pEquippedItem = GetItemData(unit->items + GetUnitEquippedWeaponSlot(unit));
            type = pEquippedItem->type;

            iVar5 = func_0203c7ac(unit, type);

            for (i = 0, pWeaponLevel = data_02197254->pWeaponLevel; i < 5; i++)
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
        case 3:
        {
            s8 * r2;
            int i;

            for (r2 = item->unk_1c, i = 0; i < 8; i++)
            {
                if (r2[i] == 0)
                {
                    continue;
                }

                if (i != 7)
                {
                    continue;
                }

                unit->unk_91 = item->unk_1c[i];
            }

            break;
        }
        case 4:
        {
            unit->unk_92 = item->unk_1c[0] << 1;
            break;
        }
    }

    return;
}

EC BOOL func_02038914(struct ItemData * item, u32 x, u32 y)
{
    struct Unit ** ppUVar2;
    int i;
    u32 unitId;
    int hp;
    struct Unit * pUnit;
    struct Item * it;

    if (gMapStateManager == 0)
    {
        return FALSE;
    }

    if (item->type != ITYPE_MAGIC)
    {
        return FALSE;
    }

    switch (item->unk_11)
    {
        case 0:
            pUnit = NULL;

            if ((item->attributes & 0x10) != 0)
            {
                if (x != -1)
                {
                    return FALSE;
                }

                ppUVar2 = func_02040c98(data_ov000_021e3324->phase);

                for (pUnit = *ppUVar2; pUnit != 0; pUnit = pUnit->unk_3c)
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

            if (!((pUnit->unk_4c->unk_08 == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            hp = pUnit->hp;

            if (hp >= GetUnitMaxHp(pUnit))
            {
                return FALSE;
            }

            return TRUE;

        case 1:
            break;

        case 2:
            break;

        case 3:
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

            if (!((pUnit->unk_4c->unk_08 == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            for (i = 0; i < 8; i++)
            {
                int cap;

                if (item->unk_1c[i] == 0)
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

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
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

            if (!((pUnit->unk_4c->unk_08 == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
            {
                return FALSE;
            }

            return TRUE;

        case 8:
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

            if (!((pUnit->unk_4c->unk_08 == data_ov000_021e3324->phase ? TRUE : FALSE) & 0xff))
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

        case 9:
            if (func_ov000_021a47e4())
            {
                return FALSE;
            }

            if (x != -1)
            {
                return FALSE;
            }

            ppUVar2 = func_02040c98(3);

            for (pUnit = *ppUVar2; pUnit != NULL; pUnit = pUnit->unk_3c)
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
    struct Unit ** ppUVar3;
    int hp;
    int i;
    struct Unit * pUnit;
    s8 * r2;

    switch (item->unk_11)
    {
        case 0:
            if (item->attributes & 0x10)
            {
                ppUVar3 = func_02040c98(data_ov000_021e3324->phase);
                pUnit = *ppUVar3;

                for (; pUnit != NULL; pUnit = pUnit->unk_3c)
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

        case 3:
            for (r2 = item->unk_1c, i = 0; i < 8; i++)
            {
                if (r2[i] == 0)
                {
                    continue;
                }

                if (i != 7)
                {
                    continue;
                }

                unitB->unk_91 = item->unk_1c[i];
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
    return item->unk_1c[0];
}

EC s32 func_02038e3c(struct ItemData * item, struct Unit * unit)
{
    s32 var = item->unk_1c[0];

    if (item->attributes & 0x20)
    {
        var += (GetUnitMag(unit, NULL, TRUE) >> 1);
    }

    return var;
}

EC BOOL func_02038e80(struct ItemData * item, struct Unit * unit)
{
    if (item->attributes & 0x100000)
    {
        return TRUE;
    }

    if (item->attributes & 0x400000)
    {
        if (unit != NULL && CheckUnitAttribute(unit, 0x400))
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL func_02038edc(struct ItemData * item, struct Unit * unit)
{
    if (item->attributes & 0x200000)
    {
        return TRUE;
    }

    if (item->attributes & 0x400000)
    {
        if (unit != NULL && CheckUnitAttribute(unit, 0x400))
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL func_02038f38(struct ItemData * item, struct Unit * unit)
{
    if (item->attributes & 0x80000)
    {
        return TRUE;
    }

    if ((item->attributes & 0x400000))
    {
        if (unit != NULL && CheckUnitAttribute(unit, 0x400))
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL func_02038f94(struct Item * item)
{
    s32 uses;
    struct ItemData * itemData = GetItemData(item);

    if (itemData->type == 8)
    {
        return FALSE;
    }

    if (itemData->unk_11 == 8)
    {
        return FALSE;
    }

    uses = itemData->uses;

    if (uses != 0 && item->unk_02 < uses)
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

    switch (item->unk_11)
    {
        case 11:
            return GetJobByJidStr("JID_FIREDRAGON\0");

        case 12:
            return GetJobByJidStr("JID_EARTHDRAGON");

        case 13:
            return GetJobByJidStr("JID_MAGICDRAGON");

        case 14:
            return GetJobByJidStr("JID_GODDESSDRAGON_F");

        default:
            return unit->pJobData;
    }
}
