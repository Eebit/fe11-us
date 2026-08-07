#include "global.h"

#include <new>

#include "unknown_types.hpp"

#include "action.hpp"
#include "button.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "hashtable.hpp"
#include "item.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"

#include "constants/sounds.h"

class TargetSelectState
{
public:
    /* 000 */ u8 unk_000[140][2];
    /* 118 */ ItemData * pItemData;
    /* 11C */ Button * pScrollButtons[2];
    /* 124 */ u8 targetCount;
    /* 125 */ s8 selected;
    /* 126 */ u8 xOrigin;
    /* 127 */ u8 yOrigin;
    /* 128 */ s8 unk_128;
    /* 129 */ s8 unk_129;
    /* 12A */ s8 unk_12a;
    /* 12B */ s8 unk_12b;
    /* 12C */ u8 unk_12c;
    /* 12D */ s8 unk_12d;
    /* 12E */ u8 itemUses;
    /* 12F */ STRUCT_PAD(0x12F, 0x130);

    inline s32 GetX(void)
    {
        return (this->unk_000[this->selected][0] & 0x7f);
    }

    inline s32 GetY(void)
    {
        return (this->unk_000[this->selected][1] & 0x7f);
    }

    void _021b4224(void); // func_ov000_021b4224
    void _021b4358(void); // func_ov000_021b4358
    void _021b4430(void); // func_ov000_021b4430
    s32 _021b456c(void); // func_ov000_021b456c
    s32 _021b480c(void); // func_ov000_021b480c
    s32 _021b4ab4(void); // func_ov000_021b4ab4
    void _021b4bc4(void); // func_ov000_021b4bc4
    void _021b4f90(void); // func_ov000_021b4f90
    void _021b53bc(void); // func_ov000_021b53bc
    void _021b5810(void); // func_ov000_021b5810
    void _021b5890(void); // func_ov000_021b5890
    void _021b589c(void); // func_ov000_021b589c
    void _021b5a7c(void); // func_ov000_021b5a7c
    void _021b5dc4(void); // func_ov000_021b5dc4
    void _021b5f6c(void); // func_ov000_021b5f6c
    void _021b5fe4(void); // func_ov000_021b5fe4
    s32 _021b60e8(s32, s32, s32); // func_ov000_021b60e8
    s32 _021b615c(void); // func_ov000_021b615c
    void _021b61c8(ProcPtr); // func_ov000_021b61c8
    BOOL _021b6264(s32, s32); // func_ov000_021b6264
    void _021b62c8(void); // func_ov000_021b62c8
    void _021b63c0(void); // func_ov000_021b63c0
    s32 _021b665c(s32 *); // func_ov000_021b665c
    void _021b6740(void); // func_ov000_021b6740
    BOOL _021b6cb0(void); // func_ov000_021b6cb0
    void _021b6e98(void); // func_ov000_021b6e98
    void _021b7468(void); // func_ov000_021b7468
    void _021b7944(s32, s32, s32); // func_ov000_021b7944
    void _021b7984(void); // func_ov000_021b7984
};

extern TargetSelectState * data_ov000_021e3348;

EC void func_ov000_021b6740(TargetSelectState *);

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

extern struct ProcCmd ProcScr_TargetInfo[];

EC s32 func_ov000_021b665c(TargetSelectState *, s32 *);
EC s32 func_ov000_021b4ab4(TargetSelectState *);
EC void func_ov000_021b62c8(TargetSelectState *);
EC void func_ov000_021b63c0(TargetSelectState *);

EC s32 func_02034f74(s32);

EC s32 GetUnitEquippedWeaponSlot(Unit * unit);
EC void func_0203cc94(Unit * unit, s32 slot, s32 arg_2);
EC BOOL func_0203cd30(Unit * unit, s32 arg_1);

void TargetSelectState::_021b4224(void)
{
    this->pItemData = NULL;

    if (this->unk_129 == -1)
    {
        return;
    }

    switch (this->unk_12c)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            this->pItemData = gMapStateManager->unk_04->unk_00->items[this->unk_129].GetData();
            this->itemUses = gMapStateManager->unk_04->unk_00->items[this->unk_129].uses;

            if (this->pItemData->type != ITYPE_STAFF)
            {
                this->unk_128 = GetUnitEquippedWeaponSlot(gMapStateManager->unk_04->unk_00);
                func_0203cd30(gMapStateManager->unk_04->unk_00, this->unk_129);
                this->unk_12a = 0;
            }
            else
            {
                this->unk_128 = -1;

                if (GetUnitEquippedWeaponSlot(gMapStateManager->unk_04->unk_00) >= 0)
                {
                    this->unk_12a = this->unk_129;
                }
                else
                {
                    func_0203cc94(gMapStateManager->unk_04->unk_00, this->unk_129, 0);
                    this->unk_12a = 0;
                }
            }

            break;
    }

    return;
}

EC void func_0203cc94(Unit * unit, s32 slot, s32 arg_2);
EC void func_0203cdf0(Unit * unit, s32 slot);
EC BOOL func_0203cd30(Unit * unit, s32 arg_1);

void TargetSelectState::_021b4358(void)
{
    if (this->unk_129 == -1)
    {
        return;
    }

    switch (this->unk_12c)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            if (this->pItemData->type != ITYPE_STAFF)
            {
                func_0203cc94(gMapStateManager->unk_04->unk_00, this->unk_12a, this->unk_129);

                if (this->unk_128 != -1)
                {
                    func_0203cd30(gMapStateManager->unk_04->unk_00, this->unk_128);
                }
                else
                {
                    Unit * unit = gMapStateManager->unk_04->unk_00;
                    func_0203cdf0(unit, GetUnitEquippedWeaponSlot(unit));
                }
            }
            else
            {
                func_0203cc94(gMapStateManager->unk_04->unk_00, this->unk_12a, this->unk_129);
            }

            break;
    }

    return;
}

extern s8 data_ov000_021e3350[2][4];

void TargetSelectState::_021b4430(void)
{
    s32 xDiff;
    s32 yDiff;
    s32 dist;
    s32 r5;

    if (this->unk_000[this->selected][1] & 0x80)
    {
        return;
    }

    r5 = (this->unk_000[this->selected][0] & 0x80) ? 1 : 0;

    this->_021b4358();

    yDiff = ABS(this->yOrigin - this->GetY());
    xDiff = ABS(this->xOrigin - this->GetX());

    dist = xDiff + yDiff;

    this->unk_129 = func_02039088(
        gMapStateManager->unk_04->unk_00, this->GetX(), this->GetY(), dist, !r5 ? TRUE : FALSE, r5,
        data_ov000_021e3350[r5][MIN(dist, 3)]);

    if (this->unk_129 == -1)
    {
        this->unk_129 = func_02039088(
            gMapStateManager->unk_04->unk_00, this->GetX(), this->GetY(), dist, !r5 ? TRUE : FALSE, r5, -1);
    }

    this->_021b4224();

    return;
}

s32 TargetSelectState::_021b456c(void)
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

    if (this->unk_000[this->selected][1] & 0x80)
    {
        return 0;
    }

    if (this->unk_12c == 1)
    {
        flag = 1;
    }
    else
    {
        flag = (this->unk_000[this->selected][0] & 0x80) ? 1 : 0;
    }

    this->_021b4358();

    uVar6 = -1;

    yDiff = ABS(this->GetY() - this->yOrigin);
    xDiff = ABS(this->GetX() - this->xOrigin);

    dist = xDiff + yDiff;

    range = data_ov000_021e3350[flag][MIN(dist, 3)];

    if (range == -1)
    {
        range = this->unk_129;
    }

    for (i = range - 1; i >= 0; i--)
    {
        uVar6 = func_02039088(
            gMapStateManager->unk_04->unk_00, this->GetX(), this->GetY(), dist, !flag ? TRUE : FALSE, flag, i);

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
                gMapStateManager->unk_04->unk_00, this->GetX(), this->GetY(), dist, !flag ? TRUE : FALSE, flag,
                i);

            if (uVar6 != -1)
            {
                break;
            }
        }
    }

    if (this->unk_129 != uVar6)
    {
        // clang-format off
        for (j = MIN(dist, 3); j <= MIN(GetItemMaxRange(gMapStateManager->unk_04->unk_00->items[uVar6].GetData(), gMapStateManager->unk_04->unk_00), 3); j++)
        // clang-format on
        {
            data_ov000_021e3350[flag][j] = uVar6;
        }

        this->unk_129 = uVar6;

        result = 1;
    }
    else
    {
        result = 0;
    }

    this->_021b4224();

    return result & 0xff;
}

s32 TargetSelectState::_021b480c(void)
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

    if (this->unk_000[this->selected][1] & 0x80)
    {
        return 0;
    }

    if (this->unk_12c == 1)
    {
        flag = 1;
    }
    else
    {
        flag = (this->unk_000[this->selected][0] & 0x80) ? 1 : 0;
    }

    this->_021b4358();

    uVar6 = -1;

    yDiff = ABS(this->GetY() - this->yOrigin);
    xDiff = ABS(this->GetX() - this->xOrigin);

    dist = xDiff + yDiff;

    range = data_ov000_021e3350[flag][MIN(dist, 3)];

    if (range == -1)
    {
        range = this->unk_129;
    }

    for (i = range + 1; i < 5; i++)
    {
        uVar6 = func_02039088(
            gMapStateManager->unk_04->unk_00, this->GetX(), this->GetY(), dist, !flag ? TRUE : FALSE, flag, i);

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
                gMapStateManager->unk_04->unk_00, this->GetX(), this->GetY(), dist, !flag ? TRUE : FALSE, flag,
                i);

            if (uVar6 != -1)
            {
                break;
            }
        }
    }

    if (this->unk_129 != uVar6)
    {
        // clang-format off
        for (j = MIN(dist, 3); j <= MIN(GetItemMaxRange(gMapStateManager->unk_04->unk_00->items[uVar6].GetData(), gMapStateManager->unk_04->unk_00), 3); j++)
        // clang-format on
        {
            data_ov000_021e3350[flag][j] = uVar6;
        }

        this->unk_129 = uVar6;

        result = 1;
    }
    else
    {
        result = 0;
    }

    this->_021b4224();

    return result & 0xff;
}

s32 TargetSelectState::_021b4ab4(void)
{
    s32 xDiff;
    s32 yDiff;
    s32 i;
    s32 flag;

    if (this->unk_12c == 9)
    {
        return 0;
    }

    if (this->unk_000[this->selected][1] & 0x80)
    {
        return 0;
    }

    if (this->unk_12c == 1)
    {
        flag = 1;
    }
    else
    {
        flag = (this->unk_000[this->selected][0] & 0x80) ? 1 : 0;
    }

    yDiff = ABS(this->GetY() - this->yOrigin);
    xDiff = ABS(this->GetX() - this->xOrigin);

    for (i = 0; i < 5; i++)
    {
        if (i == this->unk_12a)
        {
            continue;
        }

        if (func_02039088(
                gMapStateManager->unk_04->unk_00, this->GetX(), this->GetY(), xDiff + yDiff, !flag ? TRUE : FALSE,
                flag, i) != -1)
        {
            return 1;
        }
    }

    return 0;
}

EC s32 func_02039400(s32, s32);
EC BOOL func_ov000_021a47e4(void);
EC s32 func_ov000_021b615c(TargetSelectState *);

void TargetSelectState::_021b4bc4(void)
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

    this->selected = -1;
    this->targetCount = 0;

    xMin =
        MAX(this->xOrigin - gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange,
            gMapStateManager->unk_24);
    yMin =
        MAX(this->yOrigin - gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange,
            gMapStateManager->unk_25);
    xMax =
        MIN(this->xOrigin + gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange,
            gMapStateManager->unk_26 - 1);
    yMax =
        MIN(this->yOrigin + gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange,
            gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            yDiff = ABS(this->yOrigin - iy);
            xDiff = ABS(this->xOrigin - ix);

            dist = xDiff + yDiff;

            if (dist < gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->minRange)
            {
                continue;
            }

            if (dist > gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange)
            {
                continue;
            }

            unit = GetUnit(gMapStateManager->unk_028[ix | (iy << 5)]);

            if (unit == NULL)
            {
                continue;
            }

            if (func_02039088(gMapStateManager->unk_04->unk_00, ix, iy, dist, 1, 0, this->unk_12a) < 0)
            {
                continue;
            }

            yPos = unit->yPos;
            xPos = unit->xPos;

            slot = this->targetCount;

            this->unk_000[slot][0] = xPos;
            this->unk_000[slot][1] = yPos;

            if ((unit != NULL) && (this->unk_12d == unit->unk_68))
            {
                this->selected = this->targetCount;
            }

            this->targetCount++;
        }
    }

    if (this->selected == -1)
    {
        this->selected = this->_021b615c();
    }

    return;
}

void TargetSelectState::_021b4f90(void)
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

    this->selected = -1;
    this->targetCount = 0;

    if (gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange != 0)
    {
        xMin =
            MAX(this->xOrigin - gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange,
                gMapStateManager->unk_24);
        yMin =
            MAX(this->yOrigin - gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange,
                gMapStateManager->unk_25);
        xMax =
            MIN(this->xOrigin + gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange,
                gMapStateManager->unk_26 - 1);
        yMax =
            MIN(this->yOrigin + gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange,
                gMapStateManager->unk_27 - 1);

        for (iy = yMin; iy <= yMax; iy++)
        {
            for (ix = xMin; ix <= xMax; ix++)
            {
                yDiff = ABS(this->yOrigin - iy);
                xDiff = ABS(this->xOrigin - ix);

                dist = xDiff + yDiff;

                if (dist < gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->minRange)
                {
                    continue;
                }

                if (dist > gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->maxRange)
                {
                    continue;
                }

                if (!func_02039400(ix, iy))
                {
                    continue;
                }

                if (func_02039088(gMapStateManager->unk_04->unk_00, ix, iy, dist, 0, 1, this->unk_12a) < 0)
                {
                    continue;
                }

                slot = this->targetCount;

                this->unk_000[slot][0] = ix;
                this->unk_000[slot][1] = iy;

                unit = GetUnit(gMapStateManager->unk_028[ix | (iy << 5)]);

                if ((unit != NULL) && (this->unk_12d == unit->unk_68))
                {
                    this->selected = this->targetCount;
                }

                this->targetCount++;
            }
        }
    }
    else
    {
        yPos = this->yOrigin;
        xPos = this->xOrigin;

        slot = this->targetCount;

        this->unk_000[slot][0] = xPos;
        this->unk_000[slot][1] = yPos;

        this->targetCount++;
    }

    if (this->selected == -1)
    {
        this->selected = this->_021b615c();
    }

    return;
}

void TargetSelectState::_021b53bc(void)
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

    this->selected = -1;
    this->targetCount = 0;

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

            yDiff = ABS(this->yOrigin - unit->yPos);
            xDiff = ABS(this->xOrigin - unit->xPos);

            dist = xDiff + yDiff;

            if ((dist == 1) && (func_ov000_021a47e4() == 0))
            {
                personB = func_0203c378(unit)->pPersonData->pid;
                personA = func_0203c378(gMapStateManager->unk_04->unk_00)->pPersonData->pid;

                if (EventCaller::CanStartTalkEvent((u32)personA, (u32)personB))
                {
                    slot = this->targetCount;

                    this->unk_000[slot][0] = ix;
                    this->unk_000[slot][1] = iy;

                    this->unk_000[slot][1] |= 0x80;

                    if ((unit != NULL) && (this->unk_12d == unit->unk_68))
                    {
                        this->selected = this->targetCount;
                    }

                    this->targetCount++;
                    continue;
                }
            }

            if (unit != NULL && (func_02039088(gMapStateManager->unk_04->unk_00, ix, iy, dist, 1, 0, -1) >= 0))
            {
                yPos = unit->yPos;
                xPos = unit->xPos;

                slot = this->targetCount;

                this->unk_000[slot][0] = xPos;
                this->unk_000[slot][1] = yPos;

                if ((unit != NULL) && (this->unk_12d == unit->unk_68))
                {
                    this->selected = this->targetCount;
                }

                this->targetCount++;
            }
            else
            {
                if (func_02039088(gMapStateManager->unk_04->unk_00, ix, iy, dist, 0, 1, -1) >= 0)
                {
                    slot = this->targetCount;

                    this->unk_000[slot][0] = ix;
                    this->unk_000[slot][1] = iy;

                    this->unk_000[slot][0] |= 0x80;

                    if ((unit != NULL) && (this->unk_12d == unit->unk_68))
                    {
                        this->selected = this->targetCount;
                    }

                    this->targetCount++;
                }
            }
        }
    }

    return;
}

extern struct UnkStruct_021e3340 * data_ov000_021e3340;

void TargetSelectState::_021b5810(void)
{
    s32 i;

    this->_021b53bc();

    if (this->selected != -1)
    {
        return;
    }

    for (i = 0; i < this->targetCount; i++)
    {
        if (data_ov000_021e3340->unk_04 != (this->unk_000[i][0] & 0x7f))
        {
            continue;
        }

        if (data_ov000_021e3340->unk_05 != (this->unk_000[i][1] & 0x7f))
        {
            continue;
        }

        this->selected = i;
        return;
    }

    return;
}

void TargetSelectState::_021b5890(void)
{
    this->_021b53bc();
    return;
}

EC s32 func_ov000_021b615c(TargetSelectState *);

void TargetSelectState::_021b589c(void)
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

    this->targetCount = 0;

    xMin = MAX(this->xOrigin - 1, gMapStateManager->unk_24);
    yMin = MAX(this->yOrigin - 1, gMapStateManager->unk_25);
    xMax = MIN(this->xOrigin + 1, gMapStateManager->unk_26 - 1);
    yMax = MIN(this->yOrigin + 1, gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            yDiff = ABS(this->yOrigin - iy);
            xDiff = ABS(this->xOrigin - ix);

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

            slot = this->targetCount;

            this->unk_000[slot][0] = ix;
            this->unk_000[slot][1] = iy;

            this->targetCount++;
        }
    }

    this->selected = this->_021b615c();

    return;
}

void TargetSelectState::_021b5a7c(void)
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

    this->targetCount = 0;

    xMin = MAX(this->xOrigin - 1, gMapStateManager->unk_24);
    yMin = MAX(this->yOrigin - 1, gMapStateManager->unk_25);
    xMax = MIN(this->xOrigin + 1, gMapStateManager->unk_26 - 1);
    yMax = MIN(this->yOrigin + 1, gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            yDiff = ABS(this->yOrigin - iy);
            xDiff = ABS(this->xOrigin - ix);

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

            slot = this->targetCount;

            this->unk_000[slot][0] = ix;
            this->unk_000[slot][1] = iy;

            this->targetCount++;
        }
    }

    this->selected = this->_021b615c();

    return;
}

void TargetSelectState::_021b5dc4(void)
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

    this->targetCount = 0;

    xMin = MAX(this->xOrigin - 1, gMapStateManager->unk_24);
    yMin = MAX(this->yOrigin - 1, gMapStateManager->unk_25);
    xMax = MIN(this->xOrigin + 1, gMapStateManager->unk_26 - 1);
    yMax = MIN(this->yOrigin + 1, gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            yDiff = ABS(this->yOrigin - iy);
            xDiff = ABS(this->xOrigin - ix);

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

            slot = this->targetCount;

            this->unk_000[slot][0] = ix;
            this->unk_000[slot][1] = iy;

            this->targetCount++;
        }
    }

    this->selected = this->_021b615c();

    return;
}

EC void func_ov000_021b4f90(TargetSelectState *);
EC void func_ov000_021b5810(TargetSelectState *);

EC void func_01ff9300(void *, s32, s32, s32, s32);

void TargetSelectState::_021b5f6c(void)
{
    switch (this->unk_12c)
    {
        case 0:
            this->_021b4bc4();
            return;

        case 1:
            this->_021b4f90();
            return;

        case 2:
            this->_021b5810();
            return;

        case 3:
            this->_021b5890();
            return;

        case 7:
        case 8:
            this->_021b589c();
            return;

        case 9:
            this->_021b5a7c();
            return;

        case 10:
            this->_021b5dc4();
            return;
    }

    return;
}

void TargetSelectState::_021b5fe4(void)
{
    s32 x;
    s32 y;
    s32 i;

    switch (this->unk_12c)
    {
        case 0:
        case 1:
            break;

        default:
            return;
    }

    x = this->GetX();
    y = this->GetY();

    func_01ff9300(
        gMapStateManager->unk_08, this->xOrigin, this->yOrigin, this->pItemData->minRange,
        this->pItemData->maxRange);

    gMapStateManager->unk_14->unk_04->unk_16 = 1;

    switch (this->unk_12c)
    {
        case 0:
            this->_021b4bc4();
            break;

        case 1:
            this->_021b4f90();
            break;
    }

    for (i = 0; i < this->targetCount; i++)
    {
        if (x != (this->unk_000[i][0] & 0x7f))
        {
            continue;
        }

        if (y != (this->unk_000[i][1] & 0x7f))
        {
            continue;
        }

        this->selected = i;
        return;
    }

    return;
}

s32 TargetSelectState::_021b60e8(s32 param_2, s32 param_3, s32 param_4)
{
    s32 i;

    for (i = 0; i < this->targetCount; i++)
    {
        if (param_2 != (this->unk_000[i][0] & 0x7f))
        {
            continue;
        }

        if (param_3 != (this->unk_000[i][1] & 0x7f))
        {
            continue;
        }

        if ((param_4 != 0) && (i == this->selected))
        {
            return -1;
        }

        return i;
    }

    return -1;
}

s32 TargetSelectState::_021b615c(void)
{
    s32 xDiff;
    s32 result;
    s32 best;
    s32 yDiff;
    s32 i;

    result = -1;
    best = 0xff;

    for (i = 0; i < this->targetCount; i++)
    {
        yDiff = ABS(this->yOrigin - (this->unk_000[i][1] & 0x7f));
        xDiff = ABS(this->xOrigin - (this->unk_000[i][0] & 0x7f));

        if ((xDiff + yDiff) < best)
        {
            result = i;
            best = (xDiff + yDiff);
        }
    }

    return result;
}

void TargetSelectState::_021b61c8(ProcPtr param_2)
{
    s32 bVar1;
    s32 uVar2;
    struct VmMap_Common * vmMap_ObjFree2;

    vmMap_ObjFree2 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_OBJFree2"));
    uVar2 = vmMap_ObjFree2->unk_04;
    bVar1 = vmMap_ObjFree2->unk_06;

    this->pScrollButtons[0] = StartButton(param_2, BUTTON_KIND_SCROLLER_LEFT, uVar2, bVar1 + 8, 2);
    this->pScrollButtons[0]->func_020354bc(1);
    this->pScrollButtons[0]->SetPosition(0, -16);

    this->pScrollButtons[1] = StartButton(param_2, BUTTON_KIND_SCROLLER_RIGHT, uVar2 + func_02034f74(0x12), bVar1 + 8, 2);
    this->pScrollButtons[1]->func_020354bc(1);
    this->pScrollButtons[1]->SetPosition(0, -16);

    return;
}

BOOL TargetSelectState::_021b6264(s32 param_2, s32 param_3)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        if (this->pScrollButtons[i] == NULL)
        {
            continue;
        }

        if (!this->pScrollButtons[i]->func_020353b8())
        {
            continue;
        }

        if (!this->pScrollButtons[i]->func_020353e0(param_2, param_3))
        {
            continue;
        }

        return TRUE;
    }

    return FALSE;
}

EC void func_ov000_021b4224(TargetSelectState *);
EC void func_ov000_021b5f6c(TargetSelectState *);

void TargetSelectState::_021b62c8(void)
{
    switch (this->unk_12c)
    {
        case 0:
        case 1:
        case 3:
        case 7:
        case 8:
        case 9:
        case 10:
            this->xOrigin = gMapStateManager->unk_04->unk_00->xPos;
            this->yOrigin = gMapStateManager->unk_04->unk_00->yPos;
            break;

        case 2:
            this->xOrigin = gMapStateManager->unk_08->unk_0042;
            this->yOrigin = gMapStateManager->unk_08->unk_0043;
            break;
    }

    this->pItemData = NULL;

    switch (this->unk_12c)
    {
        case 0:
        case 1:
        case 2:
            this->_021b4224();
            break;

        case 3:
            if (this->unk_12d != -1)
            {
                this->_021b4224();
            }

            break;
    }

    this->_021b5f6c();

    return;
}

void TargetSelectState::_021b63c0(void)
{
    s32 i;

    if (this->unk_12c != 3)
    {
        gMapStateManager->cursor->isVisible = 1;
        gMapStateManager->cursor->unk_0e = 1;

        gMapStateManager->cursor->SetPosAnimated(this->GetX(), this->GetY(), 1, 0);

        if (GetUnit(gMapStateManager->unk_028[(this->GetY() << 5) | this->GetX()]) != NULL)
        {
            func_0204e1a4(GetUnit(gMapStateManager->unk_028[(this->GetY() << 5) | this->GetX()]), 3, 1);

            func_0204eab8(
                GetUnit(gMapStateManager->unk_028[(this->GetY() << 5) | this->GetX()])->xPos,
                GetUnit(gMapStateManager->unk_028[(this->GetY() << 5) | this->GetX()])->yPos, 0);
        }

        switch (this->unk_12c)
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

    if (this->unk_12d != -1)
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

s32 TargetSelectState::_021b665c(s32 * param_2)
{
    *param_2 = 0;

    switch (this->unk_12c)
    {
        case 0:
            return 1;

        case 2:
        case 3:
            if (this->unk_000[this->selected][1] & 0x80)
            {
                return 2;
            }

            if ((this->unk_000[this->selected][0] & 0x80) == 0)
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

    switch (this->pItemData->effect)
    {
        case 0:
            *param_2 = 1;
            break;

        case 3:
            if (this->pItemData->statBoost[7] != 0)
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
EC s32 func_ov000_021b456c(TargetSelectState *);
EC s32 func_ov000_021b480c(TargetSelectState *);
EC void func_ov000_021b7468(TargetSelectState *);
EC void func_ov000_021b6e98(TargetSelectState *);

void TargetSelectState::_021b6740(void)
{
    s8 prevIdx;
    s32 flag;
    s8 uVar2;
    s32 iVar;
    s32 local;
    Unit * unit;

    prevIdx = this->selected;
    flag = 0;

    gMapStateManager->inputHandler->_021a6438();

    uVar2 = gMapStateManager->inputHandler->unk_27;

    if ((uVar2 != -1) && (uVar2 != 0x7f))
    {
        this->selected = uVar2;
    }

    if (this->selected != -1)
    {
        if (this->targetCount >= 2)
        {
            if (gMapStateManager->inputHandler->keyRepeated & (KEY_DPAD_LEFT | KEY_DPAD_UP))
            {
                if (this->selected != 0)
                {
                    this->selected = this->selected - 1;
                }
                else
                {
                    this->selected = this->targetCount - 1;
                }
            }
            else if (gMapStateManager->inputHandler->keyRepeated & (KEY_DPAD_RIGHT | KEY_DPAD_DOWN))
            {
                if (this->selected < this->targetCount - 1)
                {
                    this->selected = this->selected + 1;
                }
                else
                {
                    this->selected = 0;
                }
            }
        }
        else if (gMapStateManager->inputHandler->IsUsingKeyInputs())
        {
            if (gMapStateManager->camera->func_ov000_021a4f7c(this->GetX(), this->GetY(), 0))
            {
                gMapStateManager->camera->func_ov000_021a4cec(this->GetX(), this->GetY(), 0, 8, 0);

                func_ov000_021b3fd4(func_ov000_021b4210(), 0);
            }
        }

        if ((this->unk_12c != 7) && (this->unk_12c != 8) && (this->unk_12c != 9) && (this->unk_12c != 10))
        {
            if ((gMapStateManager->inputHandler->keyPressed & KEY_BUTTON_X) || this->pScrollButtons[1]->func_02035450())
            {
                flag = this->_021b480c();
            }
            else if (
                (gMapStateManager->inputHandler->keyPressed & KEY_BUTTON_Y) || this->pScrollButtons[0]->func_02035450())
            {
                flag = this->_021b456c();
            }

            if (flag != 0)
            {
                gSoundManager->unk_b0->vfunc_28(SE_SYS_CURSOL2_WIN1, 0, 0);
                this->_021b5fe4();
            }
        }
    }

    if (this->selected != prevIdx)
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

        gMapStateManager->cursor->SetPosAnimated(this->GetX(), this->GetY(), 1, 1);

        func_0204e1a4(GetUnit(gMapStateManager->unk_028[this->GetX() | (this->GetY() << 5)]), 0, 1);

        func_0204eab8(
            GetUnit(gMapStateManager->unk_028[(this->GetY() << 5) | this->GetX()])->xPos,
            GetUnit(gMapStateManager->unk_028[(this->GetY() << 5) | this->GetX()])->yPos, 0);

        func_ov000_021b3fd4(func_ov000_021b4210(), (prevIdx == -1) ? TRUE : FALSE);
    }

    if (this->selected != prevIdx)
    {
        switch (this->unk_12c)
        {
            case 2:
            case 3:
                this->_021b4430();
                break;
        }

        InputHandler * handler = gMapStateManager->inputHandler;

        handler->unk_23 = 0;
        handler->unk_21_0 = 0;
        handler->unk_21_4 = 0;
    }

    if ((this->selected != prevIdx) || (flag != 0))
    {
        iVar = this->_021b665c(&local);

        unit = GetUnit(gMapStateManager->unk_028[this->GetX() | (this->GetY() << 5)]);

        func_ov000_021b3e68(
            func_ov000_021b4210(), unit, this->pItemData, this->itemUses, iVar, local, func_ov000_021b4ab4(this));
    }

    if (uVar2 != -1)
    {
        func_ov000_021b3fd4(func_ov000_021b4210(), 0);
    }

    if ((this->selected == -1) || (uVar2 == 0x7f))
    {
        func_ov000_021a471c();
        return;
    }

    if (func_ov000_021a471c())
    {
        this->_021b7468();
        return;
    }

    if (gMapStateManager->inputHandler->unk_21_0 != 0)
    {
        this->_021b6e98();
        return;
    }

    if ((gMapStateManager->inputHandler->unk_21_4 != 0) || gMapStateManager->inputHandler->_021a5650(0))
    {
        this->_021b7468();
    }

    return;
}

EC void StartSubtitleHelp(char *, s32);

BOOL TargetSelectState::_021b6cb0(void)
{
    s32 unitId;

    if (this->unk_12c != 1)
    {
        if ((this->unk_12c != 2) && (this->unk_12c != 3))
        {
            return FALSE;
        }

        if ((this->unk_000[this->selected][1] & 0x80) || ((this->unk_000[this->selected][0] & 0x80) == 0))
        {
            return FALSE;
        }
    }

    if ((this->xOrigin == this->GetX()) && (this->yOrigin == this->GetY()))
    {
        unitId = gMapStateManager->unk_04->unk_00->unk_68;
    }
    else
    {
        unitId = GetUnit(gMapStateManager->unk_028[this->GetX() | (this->GetY() << 5)])->unk_68;
    }

    switch (gMapStateManager->unk_04->unk_00->items[this->unk_12a].GetData()->effect)
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

    data_ov000_021e3340->unk_07 = this->unk_12c;

    func_ov000_021b0e34(this->xOrigin, this->yOrigin, ACTION_STAFF, unitId, this->unk_12a);

    return TRUE;
}

EC void func_ov000_021a72a8(void *);
EC BOOL func_02002038(void *, void *);

void TargetSelectState::_021b6e98(void)
{
    s32 bVar1;
    s32 unitId;
    s32 x;
    s32 y;
    struct Unit * psVar5;

    switch (this->unk_12c)
    {
        case 0:
        case 1:
        case 3:
            if (this->_021b6cb0())
            {
                break;
            }

            gMapStateManager->cursor->isVisible = FALSE;

            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            if ((this->xOrigin == (this->GetX())) && (this->yOrigin == (this->GetY())))
            {
                bVar1 = gMapStateManager->unk_04->unk_00->unk_68;
            }
            else
            {
                unitId = gMapStateManager->unk_028[(this->GetX()) | ((this->GetY()) << 5)];
                bVar1 = GetUnit(unitId)->unk_68;
            }

            if (this->unk_12c == 0)
            {
                func_ov000_021b0e34(this->xOrigin, this->yOrigin, ACTION_FIGHT, bVar1, this->unk_12a);
            }
            else if (this->unk_12c == 1)
            {
                func_ov000_021b0e34(this->xOrigin, this->yOrigin, ACTION_STAFF, bVar1, this->unk_12a);
            }
            else
            {
                if ((this->unk_000[this->selected][0] & 0x80) != 0)
                {
                    this->_021b4358();
                    PlayerPhase_GotoLabel(20, bVar1, 0);
                    func_ov000_021d6dfc(0);
                    break;
                }

                if (this->unk_000[this->selected][1] & 0x80)
                {
                    func_ov000_021b0e34(this->xOrigin, this->yOrigin, ACTION_STAFF, bVar1, this->unk_12a);
                }
                else
                {
                    func_ov000_021b0e34(this->xOrigin, this->yOrigin, ACTION_FIGHT, bVar1, this->unk_12a);
                }
            }

            PlayerPhase_GotoLabel(40, 0, 0);
            func_ov000_021d6dfc(0);

            break;

        case 2:
            if (this->_021b6cb0())
            {
                break;
            }

            gMapStateManager->cursor->isVisible = FALSE;

            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            psVar5 = NULL;
            gMapStateManager->unk_14->unk_04->unk_15 = 0;

            if ((this->unk_000[this->selected][1] & 0x80) != 0)
            {
                this->_021b4358();
                unitId = gMapStateManager->unk_028[this->GetX() | (this->GetY() << 5)];

                PlayerPhase_GotoLabel(20, GetUnit(unitId)->unk_68, 0);
            }
            else
            {
                x = this->GetX();
                y = this->GetY();

                if ((this->unk_000[this->selected][0] & 0x80) != 0)
                {
                    unitId = gMapStateManager->unk_028[x | (y << 5)];
                    func_ov000_021b0e34(
                        this->xOrigin, this->yOrigin, ACTION_STAFF, GetUnit(unitId)->unk_68, this->unk_12a);
                }
                else
                {
                    unitId = gMapStateManager->unk_028[x | (y << 5)];
                    func_ov000_021b0e34(
                        this->xOrigin, this->yOrigin, ACTION_FIGHT, GetUnit(unitId)->unk_68, this->unk_12a);
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

            unitId = gMapStateManager->unk_028[this->GetX() | (this->GetY() << 5)];

            PlayerPhase_GotoLabel(13, GetUnit(unitId)->unk_68, 0);
            func_ov000_021d6dfc(0);

            break;

        case 9:
            gMapStateManager->cursor->isVisible = FALSE;
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            unitId = gMapStateManager->unk_028[this->GetX() | (this->GetY() << 5)];

            PlayerPhase_GotoLabel(20, GetUnit(unitId)->unk_68, 0);
            func_ov000_021d6dfc(0);

            break;

        case 10:
            gMapStateManager->cursor->isVisible = FALSE;
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            unitId = gMapStateManager->unk_028[this->GetX() | (this->GetY() << 5)];

            func_ov000_021b0e34(this->xOrigin, this->yOrigin, ACTION_IMITATION, GetUnit(unitId)->unk_68, 0);

            PlayerPhase_GotoLabel(40, 0, 0);
            func_ov000_021d6dfc(0);

            break;
    }

    gSoundManager->unk_b0->vfunc_28(SE_SYS_SELECT1, 0, 0);
    func_ov000_021b79f8();

    return;
}

void TargetSelectState::_021b7468(void)
{
    switch (this->unk_12c)
    {
        case 0:
        case 1:
            this->_021b4358();

            this->unk_129 = this->unk_12b;

            this->_021b4224();

            PlayerPhase_GotoLabel(12, this->unk_12c, 0);
            func_ov000_021d6dfc(0);

            gMapStateManager->cursor->isVisible = 0;
            gMapStateManager->cursor->SetPosAnimated(this->xOrigin, this->yOrigin, 1, 1);

            func_0204e1a4(gMapStateManager->unk_04->unk_00, 0, 1);
            func_0204eab8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0);

            break;

        case 2:
            this->_021b4358();

            func_01ff8d88(gMapStateManager->unk_08, gMapStateManager->unk_04->unk_00, -1, 6, 1, 1);

            func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 0, 2, 0);

            func_ov000_021d3fa8();

            gMapStateManager->inputHandler->SetButtonVisibility(0x8f);

            PlayerPhase_GotoLabel(6, 0, 0);
            func_ov000_021d6e30(2);

            break;

        case 3:
            this->_021b4358();

            gMapStateManager->cursor->isVisible = FALSE;
            gMapStateManager->cursor->SetPosAnimated(this->xOrigin, this->yOrigin, 1, 1);

            PlayerPhase_GotoLabel(11, -1, 0);

            func_0204e1a4(gMapStateManager->unk_04->unk_00, 0, 1);
            func_0204eab8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0);

            break;

        case 7:
        case 8:
        case 9:
        case 10:
            gMapStateManager->cursor->isVisible = FALSE;
            gMapStateManager->cursor->SetPosAnimated(this->xOrigin, this->yOrigin, 1, 1);

            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            if (this->unk_12c != 8)
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
    data_ov000_021e3348->_021b62c8();
    return;
}

EC void func_ov000_021b7760(void)
{
    data_ov000_021e3348->_021b63c0();
    return;
}

EC void func_ov000_021b7778(ProcPtr proc)
{
    data_ov000_021e3348->_021b61c8(proc);
    return;
}

EC void func_ov000_021b7794(ProcPtr proc)
{
    s32 unitId;
    s8 selected;
    Unit * pUnit;
    s32 local_2c;
    s32 local_30;
    s32 local_28;

    selected = data_ov000_021e3348->selected;

    if ((selected != -1 ? TRUE : FALSE) & 0xFF)
    {
        unitId = gMapStateManager->unk_028
                    [(data_ov000_021e3348->unk_000[selected][0] & 0x7f) |
                     ((data_ov000_021e3348->unk_000[selected][1] & 0x7f) << 5)];

        pUnit = GetUnit(unitId);

        local_2c = data_ov000_021e3348->_021b665c(&local_28);
        local_30 = data_ov000_021e3348->_021b4ab4();
    }
    else
    {
        pUnit = NULL;
        local_30 = 0;
        local_2c = 0;
        local_28 = 0;
    }

    new (Proc_Start(ProcScr_TargetInfo, proc)) TargetInfo(
        pUnit, local_28, local_2c, local_30, data_ov000_021e3348->xOrigin, data_ov000_021e3348->itemUses,
        data_ov000_021e3348->yOrigin, gMapStateManager->unk_04->unk_00, (u32)data_ov000_021e3348->pScrollButtons[1],
        (u32)data_ov000_021e3348->pScrollButtons[0], (u32)data_ov000_021e3348->pItemData);

    return;
}

EC void func_ov000_021b792c(void)
{
    data_ov000_021e3348->_021b6740();
    return;
}

void TargetSelectState::_021b7944(s32 param_2, s32 param_3, s32 param_4)
{
    this->targetCount = 0;
    this->selected = 0;
    this->unk_12c = param_2;
    this->unk_128 = -1;
    this->unk_129 = param_3;
    this->unk_12b = param_3;
    this->unk_12d = param_4;
    this->unk_12a = -1;
    this->pScrollButtons[0] = NULL;
    this->pScrollButtons[1] = NULL;
    return;
}

// clang-format off
struct ProcCmd ProcScr_TargetSelect[] =
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

EC void func_ov000_021b7984(TargetSelectState * self)
{
    Proc_Start(ProcScr_TargetSelect, PROC_TREE_9);
    return;
}

EC void func_ov000_021b799c(s32 param_1, s32 param_2, s32 param_3)
{
    if (data_ov000_021e3348 == NULL)
    {
        data_ov000_021e3348 = new TargetSelectState();
    }

    data_ov000_021e3348->_021b7944(param_1, param_2, param_3);
    data_ov000_021e3348->_021b7984();

    return;
}

EC void func_ov000_021b79f8(void)
{
    Proc_EndEach(ProcScr_TargetSelect);

    delete data_ov000_021e3348;
    data_ov000_021e3348 = NULL;

    gMapStateManager->cursor->unk_0e = 0;

    return;
}
