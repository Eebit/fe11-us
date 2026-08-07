#include "global.h"

#include <new>

#include "unknown_types.hpp"

#include "action.hpp"
#include "button.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"

#include "constants/sounds.h"

class UnkStruct_021e3348
{
public:
    /* 000 */ u8 unk_000[0x8C][2];
    /* 118 */ ItemData * unk_118;
    /* 11C */ Button * unk_11c[2];
    /* 124 */ u8 unk_124;
    /* 125 */ s8 unk_125;
    /* 126 */ u8 unk_126;
    /* 127 */ u8 unk_127;
    /* 128 */ s8 unk_128;
    /* 129 */ s8 unk_129;
    /* 12A */ s8 unk_12a;
    /* 12B */ s8 unk_12b;
    /* 12C */ u8 unk_12c;
    /* 12D */ s8 unk_12d;
    /* 12E */ u8 unk_12e;
    /* 12F */ STRUCT_PAD(0x12F, 0x130);

    inline s32 GetX(void)
    {
        return (this->unk_000[this->unk_125][0] & 0x7f);
    }

    inline s32 GetY(void)
    {
        return (this->unk_000[this->unk_125][1] & 0x7f);
    }
};

extern UnkStruct_021e3348 * data_ov000_021e3348;

EC void func_ov000_021b6740(UnkStruct_021e3348 *);

struct TargetInfo_38
{
    STRUCT_PAD(0x00, 0x40);
};

class TargetInfo;

EC void func_ov000_021b3fd4(TargetInfo *, s32);
EC void func_ov000_021b38ac(TargetInfo *);
EC void func_ov000_021b3d48(TargetInfo *);
EC void func_ov000_021b3d58(TargetInfo *);

class TargetInfo : public ProcEx
{
public:
    /* 38 */ TargetInfo_38 * unk_38;
    /* 3C */ STRUCT_PAD(0x3C, 0x50);
    /* 50 */ Unit * unk_50;
    /* 54 */ Unit * unk_54;
    /* 58 */ s32 unk_58;
    /* 5C */ s32 unk_5c;
    /* 60 */ s32 unk_60;
    /* 64 */ u16 unk_64;
    /* 66 */ u16 unk_66;
    /* 68 */ u16 unk_68;
    /* 6A */ u16 unk_6a;
    /* 6C */ u8 unk_6c;
    /* 6D */ u8 unk_6d;
    /* 6E */ u8 unk_6e;
    /* 6F */ u8 unk_6f;
    /* 70 */ u8 unk_70;
    /* 71 */ u8 unk_71;

    TargetInfo(
        Unit * psVar12, s32 local_28, s32 local_2c, s32 local_30, s32 bVar1, s32 uVar2, s32 bVar3, Unit * uVar5,
        s32 uVar11, s32 uVar10, s32 uVar9)
    {
        this->unk_38 = new TargetInfo_38();
        this->unk_50 = uVar5;
        this->unk_54 = psVar12;
        this->unk_64 = bVar1;
        this->unk_66 = bVar3;
        this->unk_58 = uVar9;
        this->unk_6c = uVar2;
        this->unk_68 = local_2c;
        this->unk_6a = local_28;
        this->unk_70 = local_30;
        this->unk_5c = uVar10;
        this->unk_60 = uVar11;
        this->unk_6d = 0;

        func_ov000_021b3fd4(this, 1);
        func_ov000_021b38ac(this);

        this->unk_71 = 1;
    }

    virtual ~TargetInfo()
    {
        if (this->unk_54 != NULL)
        {
            func_ov000_021b3d48(this);
            func_ov000_021b3d58(this);
        }

        delete this->unk_38;
    }
};

extern struct ProcCmd data_ov000_021dc5f4[];

EC s32 func_ov000_021b665c(UnkStruct_021e3348 *, s32 *);
EC s32 func_ov000_021b4ab4(UnkStruct_021e3348 *);
EC void func_ov000_021b62c8(UnkStruct_021e3348 *);
EC void func_ov000_021b63c0(UnkStruct_021e3348 *);

EC s32 func_02034f74(s32);

EC s32 GetUnitEquippedWeaponSlot(Unit * unit);
EC void func_0203cc94(Unit * unit, s32 slot, s32 arg_2);
EC BOOL func_0203cd30(Unit * unit, s32 arg_1);

EC void func_ov000_021b4224(UnkStruct_021e3348 * param_1)
{
    param_1->unk_118 = NULL;

    if (param_1->unk_129 == -1)
    {
        return;
    }

    switch (param_1->unk_12c)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            param_1->unk_118 = gMapStateManager->unk_04->unk_00->items[param_1->unk_129].GetData();
            param_1->unk_12e = gMapStateManager->unk_04->unk_00->items[param_1->unk_129].uses;

            if (param_1->unk_118->type != 5)
            {
                param_1->unk_128 = GetUnitEquippedWeaponSlot(gMapStateManager->unk_04->unk_00);
                func_0203cd30(gMapStateManager->unk_04->unk_00, (int)param_1->unk_129);
                param_1->unk_12a = 0;
            }
            else
            {
                param_1->unk_128 = -1;

                if (GetUnitEquippedWeaponSlot(gMapStateManager->unk_04->unk_00) >= 0)
                {
                    param_1->unk_12a = param_1->unk_129;
                }
                else
                {
                    func_0203cc94(gMapStateManager->unk_04->unk_00, param_1->unk_129, 0);
                    param_1->unk_12a = 0;
                }
            }

            break;
    }

    return;
}

EC void func_0203cc94(Unit * unit, s32 slot, s32 arg_2);
EC void func_0203cdf0(Unit * unit, s32 slot);
EC BOOL func_0203cd30(Unit * unit, s32 arg_1);

EC void func_ov000_021b4358(UnkStruct_021e3348 * param_1)
{
    if (param_1->unk_129 == -1)
    {
        return;
    }

    switch (param_1->unk_12c)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            if (param_1->unk_118->type != 5)
            {
                func_0203cc94(gMapStateManager->unk_04->unk_00, param_1->unk_12a, param_1->unk_129);

                if (param_1->unk_128 != -1)
                {
                    func_0203cd30(gMapStateManager->unk_04->unk_00, param_1->unk_128);
                }
                else
                {
                    Unit * unit = gMapStateManager->unk_04->unk_00;
                    func_0203cdf0(unit, GetUnitEquippedWeaponSlot(unit));
                }
            }
            else
            {
                func_0203cc94(gMapStateManager->unk_04->unk_00, param_1->unk_12a, param_1->unk_129);
            }

            break;
    }

    return;
}

extern s8 data_ov000_021e3350[2][4];

EC void func_ov000_021b4430(UnkStruct_021e3348 * param_1)
{
    s32 iVar2;
    s32 iVar5;
    s32 dist;
    s32 r5;

    if (param_1->unk_000[param_1->unk_125][1] & 0x80)
    {
        return;
    }

    r5 = (param_1->unk_000[param_1->unk_125][0] & 0x80) ? 1 : 0;

    func_ov000_021b4358(param_1);

    iVar5 = ABS(param_1->unk_127 - param_1->GetY());
    iVar2 = ABS(param_1->unk_126 - param_1->GetX());

    dist = iVar2 + iVar5;

    param_1->unk_129 = func_02039088(
        gMapStateManager->unk_04->unk_00, param_1->GetX(), param_1->GetY(), dist, !r5 ? TRUE : FALSE, r5,
        data_ov000_021e3350[r5][MIN(dist, 3)]);

    if (param_1->unk_129 == -1)
    {
        param_1->unk_129 = func_02039088(
            gMapStateManager->unk_04->unk_00, param_1->GetX(), param_1->GetY(), dist, !r5 ? TRUE : FALSE, r5, -1);
    }

    func_ov000_021b4224(param_1);

    return;
}

EC s32 func_ov000_021b456c(UnkStruct_021e3348 * param_1)
{
    s32 uVar6;
    s32 flag;
    s32 range;
    s32 dist;
    s32 xDiff;
    s32 yDiff;
    s32 i;
    s32 j;
    u8 result;

    if (param_1->unk_000[param_1->unk_125][1] & 0x80)
    {
        return 0;
    }

    if (param_1->unk_12c == 1)
    {
        flag = 1;
    }
    else
    {
        flag = (param_1->unk_000[param_1->unk_125][0] & 0x80) ? 1 : 0;
    }

    func_ov000_021b4358(param_1);

    uVar6 = -1;

    yDiff = ABS(param_1->GetY() - param_1->unk_127);
    xDiff = ABS(param_1->GetX() - param_1->unk_126);

    dist = xDiff + yDiff;

    range = data_ov000_021e3350[flag][MIN(dist, 3)];

    if (range == -1)
    {
        range = param_1->unk_129;
    }

    for (i = range - 1; i >= 0; i--)
    {
        uVar6 = func_02039088(
            gMapStateManager->unk_04->unk_00, param_1->GetX(), param_1->GetY(), dist, !flag ? TRUE : FALSE, flag, i);

        if (uVar6 != -1)
        {
            break;
        }
    }

    if (uVar6 == -1)
    {
        for (i = 4; i >= range; i--)
        {
            uVar6 = func_02039088(
                gMapStateManager->unk_04->unk_00, param_1->GetX(), param_1->GetY(), dist, !flag ? TRUE : FALSE, flag,
                i);

            if (uVar6 != -1)
            {
                break;
            }
        }
    }

    if (param_1->unk_129 != uVar6)
    {
        // clang-format off
        for (j = MIN(dist, 3); j <= MIN(GetItemMaxRange(gMapStateManager->unk_04->unk_00->items[uVar6].GetData(), gMapStateManager->unk_04->unk_00), 3); j++)
        // clang-format on
        {
            data_ov000_021e3350[flag][j] = uVar6;
        }

        param_1->unk_129 = uVar6;

        result = 1;
    }
    else
    {
        result = 0;
    }

    func_ov000_021b4224(param_1);

    return result & 0xff;
}

EC s32 func_ov000_021b480c(UnkStruct_021e3348 * param_1)
{
    u8 result;
    s32 flag;
    s32 xDiff;
    s32 yDiff;
    s32 range;
    s32 dist;
    s32 uVar6;
    s32 i;
    s32 j;

    if (param_1->unk_000[param_1->unk_125][1] & 0x80)
    {
        return 0;
    }

    if (param_1->unk_12c == 1)
    {
        flag = 1;
    }
    else
    {
        flag = (param_1->unk_000[param_1->unk_125][0] & 0x80) ? 1 : 0;
    }

    func_ov000_021b4358(param_1);

    uVar6 = -1;

    yDiff = ABS(param_1->GetY() - param_1->unk_127);
    xDiff = ABS(param_1->GetX() - param_1->unk_126);

    dist = xDiff + yDiff;

    range = data_ov000_021e3350[flag][MIN(dist, 3)];

    if (range == -1)
    {
        range = param_1->unk_129;
    }

    for (i = range + 1; i < 5; i++)
    {
        uVar6 = func_02039088(
            gMapStateManager->unk_04->unk_00, param_1->GetX(), param_1->GetY(), dist, !flag ? TRUE : FALSE, flag, i);

        if (uVar6 != -1)
        {
            break;
        }
    }

    if (uVar6 == -1)
    {
        for (i = 0; i <= range; i++)
        {
            uVar6 = func_02039088(
                gMapStateManager->unk_04->unk_00, param_1->GetX(), param_1->GetY(), dist, !flag ? TRUE : FALSE, flag,
                i);

            if (uVar6 != -1)
            {
                break;
            }
        }
    }

    if (param_1->unk_129 != uVar6)
    {
        // clang-format off
        for (j = MIN(dist, 3); j <= MIN(GetItemMaxRange(gMapStateManager->unk_04->unk_00->items[uVar6].GetData(), gMapStateManager->unk_04->unk_00), 3); j++)
        // clang-format on
        {
            data_ov000_021e3350[flag][j] = uVar6;
        }

        param_1->unk_129 = uVar6;

        result = 1;
    }
    else
    {
        result = 0;
    }

    func_ov000_021b4224(param_1);

    return result & 0xff;
}

EC s32 func_ov000_021b4ab4(UnkStruct_021e3348 * param_1)
{
    s32 xDiff;
    s32 yDiff;
    s32 i;
    s32 flag;

    if (param_1->unk_12c == 9)
    {
        return 0;
    }

    if (param_1->unk_000[param_1->unk_125][1] & 0x80)
    {
        return 0;
    }

    if (param_1->unk_12c == 1)
    {
        flag = 1;
    }
    else
    {
        flag = (param_1->unk_000[param_1->unk_125][0] & 0x80) ? 1 : 0;
    }

    yDiff = ABS(param_1->GetY() - param_1->unk_127);
    xDiff = ABS(param_1->GetX() - param_1->unk_126);

    for (i = 0; i < 5; i++)
    {
        if (i == param_1->unk_12a)
        {
            continue;
        }

        if (func_02039088(
                gMapStateManager->unk_04->unk_00, param_1->GetX(), param_1->GetY(), xDiff + yDiff, !flag ? TRUE : FALSE,
                flag, i) != -1)
        {
            return 1;
        }
    }

    return 0;
}

EC s32 func_02039400(s32, s32);
EC BOOL func_ov000_021a47e4(void);
EC s32 func_ov000_021b615c(UnkStruct_021e3348 *);

EC void func_ov000_021b4bc4(UnkStruct_021e3348 * param_1)
{
    s16 ix;
    s16 iy;
    s16 xMin;
    s16 xMax;
    s16 yMin;
    s16 yMax;
    s32 xDiff;
    s32 yDiff;
    s32 dist;
    s32 slot;
    s32 xPos;
    s32 yPos;
    Unit * unit;

    param_1->unk_125 = -1;
    param_1->unk_124 = 0;

    xMin =
        MAX(param_1->unk_126 - gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange,
            gMapStateManager->unk_24);
    yMin =
        MAX(param_1->unk_127 - gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange,
            gMapStateManager->unk_25);
    xMax =
        MIN(param_1->unk_126 + gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange,
            gMapStateManager->unk_26 - 1);
    yMax =
        MIN(param_1->unk_127 + gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange,
            gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            yDiff = ABS(param_1->unk_127 - iy);
            xDiff = ABS(param_1->unk_126 - ix);

            dist = xDiff + yDiff;

            if (dist < gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->minRange)
            {
                continue;
            }

            if (dist > gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange)
            {
                continue;
            }

            unit = GetUnit(gMapStateManager->unk_028[ix | (iy << 5)]);

            if (unit == NULL)
            {
                continue;
            }

            if (func_02039088(gMapStateManager->unk_04->unk_00, ix, iy, dist, 1, 0, param_1->unk_12a) < 0)
            {
                continue;
            }

            yPos = unit->yPos;
            xPos = unit->xPos;

            slot = param_1->unk_124;

            param_1->unk_000[slot][0] = xPos;
            param_1->unk_000[slot][1] = yPos;

            if ((unit != NULL) && (param_1->unk_12d == unit->unk_68))
            {
                param_1->unk_125 = param_1->unk_124;
            }

            param_1->unk_124++;
        }
    }

    if (param_1->unk_125 == -1)
    {
        param_1->unk_125 = func_ov000_021b615c(param_1);
    }

    return;
}

EC void func_ov000_021b4f90(UnkStruct_021e3348 * param_1)
{
    s16 ix;
    s16 iy;
    s16 xMin;
    s16 xMax;
    s16 yMin;
    s16 yMax;
    s32 xDiff;
    s32 yDiff;
    s32 dist;
    s32 slot;
    s32 xPos;
    s32 yPos;
    Unit * unit;

    param_1->unk_125 = -1;
    param_1->unk_124 = 0;

    if (gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange != 0)
    {
        xMin =
            MAX(param_1->unk_126 - gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange,
                gMapStateManager->unk_24);
        yMin =
            MAX(param_1->unk_127 - gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange,
                gMapStateManager->unk_25);
        xMax =
            MIN(param_1->unk_126 + gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange,
                gMapStateManager->unk_26 - 1);
        yMax =
            MIN(param_1->unk_127 + gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange,
                gMapStateManager->unk_27 - 1);

        for (iy = yMin; iy <= yMax; iy++)
        {
            for (ix = xMin; ix <= xMax; ix++)
            {
                yDiff = ABS(param_1->unk_127 - iy);
                xDiff = ABS(param_1->unk_126 - ix);

                dist = xDiff + yDiff;

                if (dist < gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->minRange)
                {
                    continue;
                }

                if (dist > gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->maxRange)
                {
                    continue;
                }

                if (!func_02039400(ix, iy))
                {
                    continue;
                }

                if (func_02039088(gMapStateManager->unk_04->unk_00, ix, iy, dist, 0, 1, param_1->unk_12a) < 0)
                {
                    continue;
                }

                slot = param_1->unk_124;

                param_1->unk_000[slot][0] = ix;
                param_1->unk_000[slot][1] = iy;

                unit = GetUnit(gMapStateManager->unk_028[ix | (iy << 5)]);

                if ((unit != NULL) && (param_1->unk_12d == unit->unk_68))
                {
                    param_1->unk_125 = param_1->unk_124;
                }

                param_1->unk_124++;
            }
        }
    }
    else
    {
        yPos = param_1->unk_127;
        xPos = param_1->unk_126;

        slot = param_1->unk_124;

        param_1->unk_000[slot][0] = xPos;
        param_1->unk_000[slot][1] = yPos;

        param_1->unk_124++;
    }

    if (param_1->unk_125 == -1)
    {
        param_1->unk_125 = func_ov000_021b615c(param_1);
    }

    return;
}

EC void func_ov000_021b53bc(UnkStruct_021e3348 * param_1)
{
    s32 yDiff;
    s32 xDiff;
    s32 dist;
    s32 unitId;
    s32 slot;
    s32 xPos;
    s32 yPos;
    s16 iy;
    s16 ix;
    char * personA;
    char * personB;
    Unit * unit;

    param_1->unk_125 = 0xff;
    param_1->unk_124 = 0;

    for (iy = (s32)gMapStateManager->unk_25; iy < gMapStateManager->unk_27; iy++)
    {
        for (ix = (s32)gMapStateManager->unk_24; ix < gMapStateManager->unk_26; ix++)
        {
            unitId = gMapStateManager->unk_028[ix | (iy << 5)];

            if (unitId == 0)
            {
                unit = NULL;
            }
            else
            {
                unit = gUnitList + unitId - 1;
            }

            if (!func_02039400(ix, iy))
            {
                continue;
            }

            yDiff = ABS(param_1->unk_127 - unit->yPos);
            xDiff = ABS(param_1->unk_126 - unit->xPos);

            dist = xDiff + yDiff;

            if ((dist == 1) && (func_ov000_021a47e4() == 0))
            {
                personB = func_0203c378(unit)->pPersonData->pid;
                personA = func_0203c378(gMapStateManager->unk_04->unk_00)->pPersonData->pid;

                if (EventCaller::CanStartTalkEvent((u32)personA, (u32)personB))
                {
                    slot = param_1->unk_124;

                    param_1->unk_000[slot][0] = ix;
                    param_1->unk_000[slot][1] = iy;

                    param_1->unk_000[slot][1] |= 0x80;

                    if ((unit != NULL) && (param_1->unk_12d == unit->unk_68))
                    {
                        param_1->unk_125 = param_1->unk_124;
                    }

                    param_1->unk_124++;
                    continue;
                }
            }

            if (unit != NULL && (func_02039088(gMapStateManager->unk_04->unk_00, ix, iy, dist, 1, 0, -1) >= 0))
            {
                yPos = unit->yPos;
                xPos = unit->xPos;

                slot = param_1->unk_124;

                param_1->unk_000[slot][0] = xPos;
                param_1->unk_000[slot][1] = yPos;

                if ((unit != NULL) && (param_1->unk_12d == unit->unk_68))
                {
                    param_1->unk_125 = param_1->unk_124;
                }

                param_1->unk_124++;
            }
            else
            {
                if (func_02039088(gMapStateManager->unk_04->unk_00, ix, iy, dist, 0, 1, -1) >= 0)
                {
                    slot = param_1->unk_124;

                    param_1->unk_000[slot][0] = ix;
                    param_1->unk_000[slot][1] = iy;

                    param_1->unk_000[slot][0] |= 0x80;

                    if ((unit != NULL) && (param_1->unk_12d == unit->unk_68))
                    {
                        param_1->unk_125 = param_1->unk_124;
                    }

                    param_1->unk_124++;
                }
            }
        }
    }

    return;
}

extern struct UnkStruct_021e3340 * data_ov000_021e3340;

EC void func_ov000_021b5810(UnkStruct_021e3348 * param_1)
{
    s32 i;

    func_ov000_021b53bc(param_1);

    if (param_1->unk_125 != -1)
    {
        return;
    }

    for (i = 0; i < param_1->unk_124; i++)
    {
        if (data_ov000_021e3340->unk_04 != (param_1->unk_000[i][0] & 0x7f))
        {
            continue;
        }

        if (data_ov000_021e3340->unk_05 != (param_1->unk_000[i][1] & 0x7f))
        {
            continue;
        }

        param_1->unk_125 = i;
        return;
    }

    return;
}

EC void func_ov000_021b5890(UnkStruct_021e3348 * param_1)
{
    func_ov000_021b53bc(param_1);
    return;
}

EC s32 func_ov000_021b615c(UnkStruct_021e3348 *);

EC void func_ov000_021b589c(UnkStruct_021e3348 * param_1)
{
    s16 ix;
    s16 iy;
    s16 xMin;
    s16 xMax;
    s16 yMin;
    s16 yMax;
    s32 xDiff;
    s32 yDiff;
    u8 hasItem;
    s32 slot;
    Unit * unit;

    hasItem = (gMapStateManager->unk_04->unk_00->items[0].id != 0) ? TRUE : FALSE;

    param_1->unk_124 = 0;

    xMin = MAX(param_1->unk_126 - 1, gMapStateManager->unk_24);
    yMin = MAX(param_1->unk_127 - 1, gMapStateManager->unk_25);
    xMax = MIN(param_1->unk_126 + 1, gMapStateManager->unk_26 - 1);
    yMax = MIN(param_1->unk_127 + 1, gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            yDiff = ABS(param_1->unk_127 - iy);
            xDiff = ABS(param_1->unk_126 - ix);

            if (((xDiff + yDiff) < 1) || ((xDiff + yDiff) > 1))
            {
                continue;
            }

            unit = GetUnit(gMapStateManager->unk_028[ix | (iy << 5)]);

            if (unit == NULL)
            {
                continue;
            }

            if (gMapStateManager->unk_04->unk_00->force->id != unit->force->id)
            {
                continue;
            }

            if (!hasItem && !(u8)((unit->items[0].id != 0) ? TRUE : FALSE))
            {
                continue;
            }

            slot = param_1->unk_124;

            param_1->unk_000[slot][0] = ix;
            param_1->unk_000[slot][1] = iy;

            param_1->unk_124++;
        }
    }

    param_1->unk_125 = func_ov000_021b615c(param_1);

    return;
}

EC void func_ov000_021b5a7c(UnkStruct_021e3348 * param_1)
{
    s16 ix;
    s16 iy;
    s16 xMin;
    s16 xMax;
    s16 yMin;
    s16 yMax;
    s32 xDiff;
    s32 yDiff;
    s32 slot;
    char * personA;
    char * personB;
    Unit * unit;

    param_1->unk_124 = 0;

    xMin = MAX(param_1->unk_126 - 1, gMapStateManager->unk_24);
    yMin = MAX(param_1->unk_127 - 1, gMapStateManager->unk_25);
    xMax = MIN(param_1->unk_126 + 1, gMapStateManager->unk_26 - 1);
    yMax = MIN(param_1->unk_127 + 1, gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            yDiff = ABS(param_1->unk_127 - iy);
            xDiff = ABS(param_1->unk_126 - ix);

            if (((xDiff + yDiff) < 1) || ((xDiff + yDiff) > 1))
            {
                continue;
            }

            unit = GetUnit(gMapStateManager->unk_028[ix | (iy << 5)]);

            if (unit == NULL)
            {
                continue;
            }

            if (func_ov000_021a47e4() != 0)
            {
                continue;
            }

            personB = func_0203c378(unit)->pPersonData->pid;
            personA = func_0203c378(gMapStateManager->unk_04->unk_00)->pPersonData->pid;

            if (!EventCaller::CanStartTalkEvent((u32)personA, (u32)personB))
            {
                continue;
            }

            slot = param_1->unk_124;

            param_1->unk_000[slot][0] = ix;
            param_1->unk_000[slot][1] = iy;

            param_1->unk_124++;
        }
    }

    param_1->unk_125 = func_ov000_021b615c(param_1);

    return;
}

EC void func_ov000_021b5dc4(UnkStruct_021e3348 * param_1)
{
    s16 ix;
    s16 iy;
    s16 xMin;
    s16 xMax;
    s16 yMin;
    s16 yMax;
    s32 xDiff;
    s32 yDiff;
    s32 slot;
    Unit * unit;

    param_1->unk_124 = 0;

    xMin = MAX(param_1->unk_126 - 1, gMapStateManager->unk_24);
    yMin = MAX(param_1->unk_127 - 1, gMapStateManager->unk_25);
    xMax = MIN(param_1->unk_126 + 1, gMapStateManager->unk_26 - 1);
    yMax = MIN(param_1->unk_127 + 1, gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            yDiff = ABS(param_1->unk_127 - iy);
            xDiff = ABS(param_1->unk_126 - ix);

            if (((xDiff + yDiff) < 1) || ((xDiff + yDiff) > 1))
            {
                continue;
            }

            unit = GetUnit(gMapStateManager->unk_028[ix | (iy << 5)]);

            if (unit == NULL)
            {
                continue;
            }

            if (gMapStateManager->unk_04->unk_00->force->id != unit->force->id)
            {
                continue;
            }

            if (CheckUnitAttribute(unit, CA_UNK_24))
            {
                continue;
            }

            slot = param_1->unk_124;

            param_1->unk_000[slot][0] = ix;
            param_1->unk_000[slot][1] = iy;

            param_1->unk_124++;
        }
    }

    param_1->unk_125 = func_ov000_021b615c(param_1);

    return;
}

EC void func_ov000_021b4f90(UnkStruct_021e3348 *);
EC void func_ov000_021b5810(UnkStruct_021e3348 *);

EC void func_01ff9300(void *, s32, s32, s32, s32);

EC void func_ov000_021b5f6c(UnkStruct_021e3348 * param_1)
{
    switch (param_1->unk_12c)
    {
        case 0:
            func_ov000_021b4bc4(param_1);
            return;

        case 1:
            func_ov000_021b4f90(param_1);
            return;

        case 2:
            func_ov000_021b5810(param_1);
            return;

        case 3:
            func_ov000_021b5890(param_1);
            return;

        case 7:
        case 8:
            func_ov000_021b589c(param_1);
            return;

        case 9:
            func_ov000_021b5a7c(param_1);
            return;

        case 10:
            func_ov000_021b5dc4(param_1);
            return;
    }

    return;
}

EC void func_ov000_021b5fe4(UnkStruct_021e3348 * param_1)
{
    s32 bVar1;
    s32 bVar2;
    s32 i;

    switch (param_1->unk_12c)
    {
        case 0:
        case 1:
            break;

        default:
            return;
    }

    bVar1 = param_1->GetX();
    bVar2 = param_1->GetY();

    func_01ff9300(
        gMapStateManager->unk_08, param_1->unk_126, param_1->unk_127, param_1->unk_118->minRange,
        param_1->unk_118->maxRange);

    gMapStateManager->unk_14->unk_04->unk_16 = 1;

    switch (param_1->unk_12c)
    {
        case 0:
            func_ov000_021b4bc4(param_1);
            break;

        case 1:
            func_ov000_021b4f90(param_1);
            break;
    }

    for (i = 0; i < param_1->unk_124; i++)
    {
        if ((bVar1) != (param_1->unk_000[i][0] & 0x7f))
        {
            continue;
        }

        if ((bVar2) != (param_1->unk_000[i][1] & 0x7f))
        {
            continue;
        }

        param_1->unk_125 = i;
        return;
    }

    return;
}

EC s32 func_ov000_021b60e8(UnkStruct_021e3348 * param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 iVar1;

    for (iVar1 = 0; iVar1 < param_1->unk_124; iVar1++)
    {
        if (param_2 != (param_1->unk_000[iVar1][0] & 0x7f))
        {
            continue;
        }

        if (param_3 != (param_1->unk_000[iVar1][1] & 0x7f))
        {
            continue;
        }

        if ((param_4 != 0) && (iVar1 == param_1->unk_125))
        {
            return -1;
        }

        return iVar1;
    }

    return -1;
}

EC s32 func_ov000_021b615c(UnkStruct_021e3348 * param_1)
{
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;
    s32 iVar4;
    s32 iVar5;

    iVar2 = -1;
    iVar3 = 0xff;

    for (iVar5 = 0; iVar5 < param_1->unk_124; iVar5++)
    {
        iVar4 = ABS(param_1->unk_127 - (param_1->unk_000[iVar5][1] & 0x7f));
        iVar1 = ABS(param_1->unk_126 - (param_1->unk_000[iVar5][0] & 0x7f));

        if ((iVar1 + iVar4) < iVar3)
        {
            iVar2 = iVar5;
            iVar3 = (iVar1 + iVar4);
        }
    }

    return iVar2;
}

EC void func_ov000_021b61c8(UnkStruct_021e3348 * param_1, ProcPtr param_2)
{
    s32 bVar1;
    s32 uVar2;
    struct VmMap_Common * iVar3;

    iVar3 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_OBJFree2"));
    uVar2 = iVar3->unk_04;
    bVar1 = iVar3->unk_06;

    param_1->unk_11c[0] = StartButton(param_2, BUTTON_KIND_SCROLLER_LEFT, uVar2, bVar1 + 8, 2);
    param_1->unk_11c[0]->func_020354bc(1);
    param_1->unk_11c[0]->SetPosition(0, -16);

    param_1->unk_11c[1] = StartButton(param_2, BUTTON_KIND_SCROLLER_RIGHT, uVar2 + func_02034f74(0x12), bVar1 + 8, 2);
    param_1->unk_11c[1]->func_020354bc(1);
    param_1->unk_11c[1]->SetPosition(0, -16);

    return;
}

EC BOOL func_ov000_021b6264(UnkStruct_021e3348 * param_1, s32 param_2, s32 param_3)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        if (param_1->unk_11c[i] == NULL)
        {
            continue;
        }

        if (!param_1->unk_11c[i]->func_020353b8())
        {
            continue;
        }

        if (!param_1->unk_11c[i]->func_020353e0(param_2, param_3))
        {
            continue;
        }

        return TRUE;
    }

    return FALSE;
}

EC void func_ov000_021b4224(UnkStruct_021e3348 *);
EC void func_ov000_021b5f6c(UnkStruct_021e3348 *);

EC void func_ov000_021b62c8(UnkStruct_021e3348 * param_1)
{
    switch (param_1->unk_12c)
    {
        case 0:
        case 1:
        case 3:
        case 7:
        case 8:
        case 9:
        case 10:
            param_1->unk_126 = gMapStateManager->unk_04->unk_00->xPos;
            param_1->unk_127 = gMapStateManager->unk_04->unk_00->yPos;
            break;

        case 2:
            param_1->unk_126 = gMapStateManager->unk_08->unk_0042;
            param_1->unk_127 = gMapStateManager->unk_08->unk_0043;
            break;
    }

    param_1->unk_118 = 0;

    switch (param_1->unk_12c)
    {
        case 0:
        case 1:
        case 2:
            func_ov000_021b4224(param_1);
            break;

        case 3:
            if (param_1->unk_12d != -1)
            {
                func_ov000_021b4224(param_1);
            }

            break;
    }

    func_ov000_021b5f6c(param_1);

    return;
}

EC void func_ov000_021b63c0(UnkStruct_021e3348 * param_1)
{
    s32 i;

    if (param_1->unk_12c != 3)
    {
        gMapStateManager->cursor->isVisible = 1;
        gMapStateManager->cursor->unk_0e = 1;

        gMapStateManager->cursor->SetPosAnimated(param_1->GetX(), param_1->GetY(), 1, 0);

        if (GetUnit(gMapStateManager->unk_028[(param_1->GetY() << 5) | param_1->GetX()]) != NULL)
        {
            func_0204e1a4(GetUnit(gMapStateManager->unk_028[(param_1->GetY() << 5) | param_1->GetX()]), 3, 1);

            func_0204eab8(
                GetUnit(gMapStateManager->unk_028[(param_1->GetY() << 5) | param_1->GetX()])->xPos,
                GetUnit(gMapStateManager->unk_028[(param_1->GetY() << 5) | param_1->GetX()])->yPos, 0);
        }

        switch (param_1->unk_12c)
        {
            case 2:
                func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 1, 2, 3);
                break;

            case 7:
            case 8:
            case 10:
                func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 1, 2, 5);
                break;

            case 9:
                func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 1, 2, 6);
                break;
        }
    }
    else
    {
        if (gMapStateManager->unk_14->unk_04->unk_10 == 0)
        {
            func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 1, 1, 4);
        }
    }

    if (param_1->unk_12d != -1)
    {
        return;
    }

    for (i = 0; i < 4; i++)
    {
        data_ov000_021e3350[0][i] = -1;
        data_ov000_021e3350[1][i] = -1;
    }

    return;
}

EC s32 func_ov000_021b665c(UnkStruct_021e3348 * param_1, s32 * param_2)
{
    *param_2 = 0;

    switch (param_1->unk_12c)
    {
        case 0:
            return 1;

        case 2:
        case 3:
            if (param_1->unk_000[param_1->unk_125][1] & 0x80)
            {
                return 2;
            }

            if ((param_1->unk_000[param_1->unk_125][0] & 0x80) == 0)
            {
                return 1;
            }

            break;

        case 7:
        case 8:
            return 4;

        case 9:
        case 10:
            return 2;
    }

    switch (param_1->unk_118->effect)
    {
        case 0:
            *param_2 = 1;
            break;

        case 3:
            if (param_1->unk_118->statBoost[7] != 0)
            {
                *param_2 = 2;
            }

            break;

        case 8:
            return 5;
    }

    return 3;
}

EC void PlayerPhase_GotoLabel(s32 label, s32 arg_1, s32 arg_2);

EC TargetInfo * func_ov000_021b4210(void);
EC void func_ov000_021b3e68(TargetInfo *, Unit *, ItemData *, s32, s32, s32, s32);
EC void func_0202ff08(void);
EC s32 func_ov000_021b456c(UnkStruct_021e3348 *);
EC s32 func_ov000_021b480c(UnkStruct_021e3348 *);
EC void func_ov000_021b7468(UnkStruct_021e3348 *);
EC void func_ov000_021b6e98(UnkStruct_021e3348 *);

EC void func_ov000_021b6740(UnkStruct_021e3348 * param_1)
{
    s8 prevIdx;
    s32 flag;
    s8 uVar2;
    s32 iVar;
    s32 local;
    Unit * unit;

    prevIdx = param_1->unk_125;
    flag = 0;

    gMapStateManager->inputHandler->_021a6438();

    uVar2 = gMapStateManager->inputHandler->unk_27;

    if ((uVar2 != -1) && (uVar2 != 0x7f))
    {
        param_1->unk_125 = uVar2;
    }

    if (param_1->unk_125 != -1)
    {
        if (param_1->unk_124 >= 2)
        {
            if (gMapStateManager->inputHandler->keyRepeated & (KEY_DPAD_LEFT | KEY_DPAD_UP))
            {
                if (param_1->unk_125 != 0)
                {
                    param_1->unk_125 = param_1->unk_125 - 1;
                }
                else
                {
                    param_1->unk_125 = param_1->unk_124 - 1;
                }
            }
            else if (gMapStateManager->inputHandler->keyRepeated & (KEY_DPAD_RIGHT | KEY_DPAD_DOWN))
            {
                if (param_1->unk_125 < param_1->unk_124 - 1)
                {
                    param_1->unk_125 = param_1->unk_125 + 1;
                }
                else
                {
                    param_1->unk_125 = 0;
                }
            }
        }
        else if (gMapStateManager->inputHandler->IsUsingKeyInputs())
        {
            if (gMapStateManager->camera->func_ov000_021a4f7c(param_1->GetX(), param_1->GetY(), 0))
            {
                gMapStateManager->camera->func_ov000_021a4cec(param_1->GetX(), param_1->GetY(), 0, 8, 0);

                func_ov000_021b3fd4(func_ov000_021b4210(), 0);
            }
        }

        if ((param_1->unk_12c != 7) && (param_1->unk_12c != 8) && (param_1->unk_12c != 9) && (param_1->unk_12c != 10))
        {
            if ((gMapStateManager->inputHandler->keyPressed & KEY_BUTTON_X) || param_1->unk_11c[1]->func_02035450())
            {
                flag = func_ov000_021b480c(param_1);
            }
            else if (
                (gMapStateManager->inputHandler->keyPressed & KEY_BUTTON_Y) || param_1->unk_11c[0]->func_02035450())
            {
                flag = func_ov000_021b456c(param_1);
            }

            if (flag != 0)
            {
                gSoundManager->unk_b0->vfunc_28(SE_SYS_CURSOL2_WIN1, 0, 0);
                func_ov000_021b5fe4(param_1);
            }
        }
    }

    if (param_1->unk_125 != prevIdx)
    {
        if (prevIdx == -1)
        {
            func_0202ff08();
            PlayerPhase_GotoLabel(39, 0, 0);

            gMapStateManager->cursor->isVisible = 1;
            gMapStateManager->cursor->unk_0e = 1;

            InputHandler * handler = gMapStateManager->inputHandler;

            handler->unk_23 = 0;
            handler->unk_21_0 = 0;
            handler->unk_21_4 = 0;
        }

        gMapStateManager->cursor->SetPosAnimated(param_1->GetX(), param_1->GetY(), 1, 1);

        func_0204e1a4(GetUnit(gMapStateManager->unk_028[param_1->GetX() | (param_1->GetY() << 5)]), 0, 1);

        func_0204eab8(
            GetUnit(gMapStateManager->unk_028[(param_1->GetY() << 5) | param_1->GetX()])->xPos,
            GetUnit(gMapStateManager->unk_028[(param_1->GetY() << 5) | param_1->GetX()])->yPos, 0);

        func_ov000_021b3fd4(func_ov000_021b4210(), (prevIdx == -1) ? TRUE : FALSE);
    }

    if (param_1->unk_125 != prevIdx)
    {
        switch (param_1->unk_12c)
        {
            case 2:
            case 3:
                func_ov000_021b4430(param_1);
                break;
        }

        InputHandler * handler = gMapStateManager->inputHandler;

        handler->unk_23 = 0;
        handler->unk_21_0 = 0;
        handler->unk_21_4 = 0;
    }

    if ((param_1->unk_125 != prevIdx) || (flag != 0))
    {
        iVar = func_ov000_021b665c(param_1, &local);

        unit = GetUnit(gMapStateManager->unk_028[param_1->GetX() | (param_1->GetY() << 5)]);

        func_ov000_021b3e68(
            func_ov000_021b4210(), unit, param_1->unk_118, param_1->unk_12e, iVar, local, func_ov000_021b4ab4(param_1));
    }

    if (uVar2 != -1)
    {
        func_ov000_021b3fd4(func_ov000_021b4210(), 0);
    }

    if ((param_1->unk_125 == -1) || (uVar2 == 0x7f))
    {
        func_ov000_021a471c();
        return;
    }

    if (func_ov000_021a471c())
    {
        func_ov000_021b7468(param_1);
        return;
    }

    if (gMapStateManager->inputHandler->unk_21_0 != 0)
    {
        func_ov000_021b6e98(param_1);
        return;
    }

    if ((gMapStateManager->inputHandler->unk_21_4 != 0) || gMapStateManager->inputHandler->_021a5650(0))
    {
        func_ov000_021b7468(param_1);
    }

    return;
}

EC void StartSubtitleHelp(char *, s32);

EC BOOL func_ov000_021b6cb0(UnkStruct_021e3348 * param_1)
{
    s32 unitId;

    if (param_1->unk_12c != 1)
    {
        if ((param_1->unk_12c != 2) && (param_1->unk_12c != 3))
        {
            return FALSE;
        }

        if ((param_1->unk_000[param_1->unk_125][1] & 0x80) || ((param_1->unk_000[param_1->unk_125][0] & 0x80) == 0))
        {
            return FALSE;
        }
    }

    if ((param_1->unk_126 == param_1->GetX()) && (param_1->unk_127 == param_1->GetY()))
    {
        unitId = gMapStateManager->unk_04->unk_00->unk_68;
    }
    else
    {
        unitId = GetUnit(gMapStateManager->unk_028[param_1->GetX() | (param_1->GetY() << 5)])->unk_68;
    }

    switch (gMapStateManager->unk_04->unk_00->items[param_1->unk_12a].GetData()->effect)
    {
        case 7:
            PlayerPhase_GotoLabel(7, 0, 0);
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);
            StartSubtitleHelp(func_02039e10("MSPMH_ワープ"), 0);
            break;

        case 8:
            PlayerPhase_GotoLabel(12, 11, unitId);
            gMapStateManager->cursor->isVisible = 0;
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);
            func_ov000_021d6dfc(0);
            break;

        default:
            return FALSE;
    }

    data_ov000_021e3340->unk_07 = param_1->unk_12c;

    func_ov000_021b0e34(param_1->unk_126, param_1->unk_127, ACTION_STAFF, unitId, param_1->unk_12a);

    return TRUE;
}

EC void func_ov000_021a72a8(void *);
EC BOOL func_02002038(void *, void *);

EC void func_ov000_021b6e98(UnkStruct_021e3348 * param_1)
{
    s32 bVar1;
    s32 unitId;
    s32 x;
    s32 y;
    struct Unit * psVar5;

    switch (param_1->unk_12c)
    {
        case 0:
        case 1:
        case 3:
            if (func_ov000_021b6cb0(param_1))
            {
                break;
            }

            gMapStateManager->cursor->isVisible = FALSE;

            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            if ((param_1->unk_126 == (param_1->GetX())) && (param_1->unk_127 == (param_1->GetY())))
            {
                bVar1 = gMapStateManager->unk_04->unk_00->unk_68;
            }
            else
            {
                unitId = gMapStateManager->unk_028[(param_1->GetX()) | ((param_1->GetY()) << 5)];
                bVar1 = GetUnit(unitId)->unk_68;
            }

            if (param_1->unk_12c == 0)
            {
                func_ov000_021b0e34(param_1->unk_126, param_1->unk_127, ACTION_FIGHT, bVar1, param_1->unk_12a);
            }
            else if (param_1->unk_12c == 1)
            {
                func_ov000_021b0e34(param_1->unk_126, param_1->unk_127, ACTION_STAFF, bVar1, param_1->unk_12a);
            }
            else
            {
                if ((param_1->unk_000[param_1->unk_125][0] & 0x80) != 0)
                {
                    func_ov000_021b4358(param_1);
                    PlayerPhase_GotoLabel(20, bVar1, 0);
                    func_ov000_021d6dfc(0);
                    break;
                }

                if (param_1->unk_000[param_1->unk_125][1] & 0x80)
                {
                    func_ov000_021b0e34(param_1->unk_126, param_1->unk_127, ACTION_STAFF, bVar1, param_1->unk_12a);
                }
                else
                {
                    func_ov000_021b0e34(param_1->unk_126, param_1->unk_127, ACTION_FIGHT, bVar1, param_1->unk_12a);
                }
            }

            PlayerPhase_GotoLabel(40, 0, 0);
            func_ov000_021d6dfc(0);

            break;

        case 2:
            if (func_ov000_021b6cb0(param_1))
            {
                break;
            }

            gMapStateManager->cursor->isVisible = FALSE;

            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            psVar5 = NULL;
            gMapStateManager->unk_14->unk_04->unk_15 = 0;

            if ((param_1->unk_000[param_1->unk_125][1] & 0x80) != 0)
            {
                func_ov000_021b4358(param_1);
                unitId = gMapStateManager->unk_028[param_1->GetX() | (param_1->GetY() << 5)];

                PlayerPhase_GotoLabel(20, GetUnit(unitId)->unk_68, 0);
            }
            else
            {
                x = param_1->GetX();
                y = param_1->GetY();

                if ((param_1->unk_000[param_1->unk_125][0] & 0x80) != 0)
                {
                    unitId = gMapStateManager->unk_028[x | (y << 5)];
                    func_ov000_021b0e34(
                        param_1->unk_126, param_1->unk_127, ACTION_STAFF, GetUnit(unitId)->unk_68, param_1->unk_12a);
                }
                else
                {
                    unitId = gMapStateManager->unk_028[x | (y << 5)];
                    func_ov000_021b0e34(
                        param_1->unk_126, param_1->unk_127, ACTION_FIGHT, GetUnit(unitId)->unk_68, param_1->unk_12a);
                }

                if (func_02002038(gMapStateManager->unk_08, gMapStateManager->unk_04->unk_00))
                {
                    func_ov000_021b0de8(
                        gMapStateManager->unk_08->unk_0042, gMapStateManager->unk_08->unk_0043, 0x17, 0);
                }

                PlayerPhase_GotoLabel(40, 0, 0);
            }

            func_ov000_021a72a8(gMapStateManager->unk_04);
            func_ov000_021d6dfc(0);

            break;

        case 4:
        case 5:
        case 6:
            break;

        case 7:
        case 8:
            gMapStateManager->cursor->isVisible = FALSE;
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            unitId = gMapStateManager->unk_028[param_1->GetX() | (param_1->GetY() << 5)];

            PlayerPhase_GotoLabel(13, GetUnit(unitId)->unk_68, 0);
            func_ov000_021d6dfc(0);

            break;

        case 9:
            gMapStateManager->cursor->isVisible = FALSE;
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            unitId = gMapStateManager->unk_028[param_1->GetX() | (param_1->GetY() << 5)];

            PlayerPhase_GotoLabel(20, GetUnit(unitId)->unk_68, 0);
            func_ov000_021d6dfc(0);

            break;

        case 10:
            gMapStateManager->cursor->isVisible = FALSE;
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            unitId = gMapStateManager->unk_028[param_1->GetX() | (param_1->GetY() << 5)];

            func_ov000_021b0e34(param_1->unk_126, param_1->unk_127, ACTION_IMITATION, GetUnit(unitId)->unk_68, 0);

            PlayerPhase_GotoLabel(40, 0, 0);
            func_ov000_021d6dfc(0);

            break;
    }

    gSoundManager->unk_b0->vfunc_28(SE_SYS_SELECT1, 0, 0);
    func_ov000_021b79f8();

    return;
}

EC void func_ov000_021b7468(UnkStruct_021e3348 * param_1)
{
    switch (param_1->unk_12c)
    {
        case 0:
        case 1:
            func_ov000_021b4358(param_1);

            param_1->unk_129 = param_1->unk_12b;

            func_ov000_021b4224(param_1);

            PlayerPhase_GotoLabel(12, param_1->unk_12c, 0);
            func_ov000_021d6dfc(0);

            gMapStateManager->cursor->isVisible = 0;
            gMapStateManager->cursor->SetPosAnimated(param_1->unk_126, param_1->unk_127, 1, 1);

            func_0204e1a4(gMapStateManager->unk_04->unk_00, 0, 1);
            func_0204eab8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0);

            break;

        case 2:
            func_ov000_021b4358(param_1);

            func_01ff8d88(gMapStateManager->unk_08, gMapStateManager->unk_04->unk_00, -1, 6, 1, 1);

            func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 0, 2, 0);

            func_ov000_021d3fa8();

            gMapStateManager->inputHandler->SetButtonVisibility(0x8f);

            PlayerPhase_GotoLabel(6, 0, 0);
            func_ov000_021d6e30(2);

            break;

        case 3:
            func_ov000_021b4358(param_1);

            gMapStateManager->cursor->isVisible = 0;
            gMapStateManager->cursor->SetPosAnimated(param_1->unk_126, param_1->unk_127, 1, 1);

            PlayerPhase_GotoLabel(11, -1, 0);

            func_0204e1a4(gMapStateManager->unk_04->unk_00, 0, 1);
            func_0204eab8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0);

            break;

        case 7:
        case 8:
        case 9:
        case 10:
            gMapStateManager->cursor->isVisible = 0;
            gMapStateManager->cursor->SetPosAnimated(param_1->unk_126, param_1->unk_127, 1, 1);

            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            if (param_1->unk_12c != 8)
            {
                PlayerPhase_GotoLabel(11, -1, 0);
            }
            else
            {
                PlayerPhase_GotoLabel(12, 4, 0);
                func_ov000_021d6dfc(0);
            }

            func_0204e1a4(gMapStateManager->unk_04->unk_00, 0, 1);
            func_0204eab8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0);

            break;
    }

    gSoundManager->unk_b0->vfunc_28(SE_SYS_CANSEL1, 0, 0);

    func_ov000_021b79f8();

    return;
}

EC void func_ov000_021b7748(void)
{
    func_ov000_021b62c8(data_ov000_021e3348);
    return;
}

EC void func_ov000_021b7760(void)
{
    func_ov000_021b63c0(data_ov000_021e3348);
    return;
}

EC void func_ov000_021b7778(ProcPtr param_1)
{
    func_ov000_021b61c8(data_ov000_021e3348, param_1);
    return;
}

EC void func_ov000_021b7794(ProcPtr param_1)
{
    s32 uVar7;
    s8 iVar8;
    Unit * psVar12;
    s32 local_2c;
    s32 local_30;
    s32 local_28;

    iVar8 = data_ov000_021e3348->unk_125;

    if ((iVar8 != -1 ? TRUE : FALSE) & 0xFF)
    {
        uVar7 = gMapStateManager->unk_028
                    [(data_ov000_021e3348->unk_000[iVar8][0] & 0x7f) |
                     ((data_ov000_021e3348->unk_000[iVar8][1] & 0x7f) << 5)];

        psVar12 = GetUnit(uVar7);

        local_2c = func_ov000_021b665c(data_ov000_021e3348, &local_28);
        local_30 = func_ov000_021b4ab4(data_ov000_021e3348);
    }
    else
    {
        psVar12 = NULL;
        local_30 = 0;
        local_2c = 0;
        local_28 = 0;
    }

    new (Proc_Start(data_ov000_021dc5f4, param_1)) TargetInfo(
        psVar12, local_28, local_2c, local_30, data_ov000_021e3348->unk_126, data_ov000_021e3348->unk_12e,
        data_ov000_021e3348->unk_127, gMapStateManager->unk_04->unk_00, (u32)data_ov000_021e3348->unk_11c[1],
        (u32)data_ov000_021e3348->unk_11c[0], (u32)data_ov000_021e3348->unk_118);

    return;
}

EC void func_ov000_021b792c(void)
{
    func_ov000_021b6740(data_ov000_021e3348);
    return;
}

EC void func_ov000_021b7944(UnkStruct_021e3348 * self, s32 param_2, s32 param_3, s32 param_4)
{
    self->unk_124 = 0;
    self->unk_125 = 0;
    self->unk_12c = param_2;
    self->unk_128 = -1;
    self->unk_129 = param_3;
    self->unk_12b = param_3;
    self->unk_12d = param_4;
    self->unk_12a = -1;
    self->unk_11c[0] = NULL;
    self->unk_11c[1] = NULL;
    return;
}

// clang-format off
struct ProcCmd data_ov000_021dc634[] =
{
    PROC_NAME,

    PROC_CALL(func_ov000_021b7748),
    PROC_SLEEP(0),

    PROC_CALL(func_ov000_021b7760),
    PROC_SLEEP(0),

    PROC_CALL(func_ov000_021b7778),
    PROC_SLEEP(0),

    PROC_CALL(func_ov000_021b7794),

    PROC_REPEAT(func_ov000_021b792c),

    PROC_END
};
// clang-format on

EC void func_ov000_021b7984(UnkStruct_021e3348 * self)
{
    Proc_Start(data_ov000_021dc634, PROC_TREE_9);
    return;
}

EC void func_ov000_021b799c(s32 param_1, s32 param_2, s32 param_3)
{
    if (data_ov000_021e3348 == NULL)
    {
        data_ov000_021e3348 = new UnkStruct_021e3348();
    }

    func_ov000_021b7944(data_ov000_021e3348, param_1, param_2, param_3);
    func_ov000_021b7984(data_ov000_021e3348);

    return;
}

EC void func_ov000_021b79f8(void)
{
    Proc_EndEach(data_ov000_021dc634);

    delete data_ov000_021e3348;
    data_ov000_021e3348 = NULL;

    gMapStateManager->cursor->unk_0e = 0;

    return;
}
