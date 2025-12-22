#include "global.h"

#include <new>

#include "event.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"

#include "unknown_funcs.h"

struct UnkStruct_021e3344
{
    STRUCT_PAD(0x00, 0x14);
    u32 unk_14;
    STRUCT_PAD(0x18, 0x2C);
    s8 unk_2c;
    s8 unk_2d;
    u8 unk_2e;
    u8 unk_2f;
    s8 unk_30;
    s8 unk_31;
    u8 unk_32;
    u8 unk_33;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
};

extern struct UnkStruct_021e3344 * data_ov000_021e3344;

// CpSkip!
struct UnkStruct_021e332c_08
{
    STRUCT_PAD(0x00, 0x06);
    u8 unk_06;

    u8 Get06() const
    {
        return this->unk_06;
    };

    BOOL Check06__()
    {
        if (this->unk_06 == 4)
        {
            return FALSE;
        }
        else if (this->unk_06 == 0)
        {
            return FALSE;
        }
        else if (this->unk_06 == 1)
        {
            return FALSE;
        }

        return TRUE;
    }

    BOOL Check06_State4()
    {
        return this->unk_06 == 4;
    }

    BOOL Check06(s32 state)
    {
        return this->unk_06 == state;
    }

    BOOL Check06_Other()
    {
        return (this->unk_06 == 0) || (this->unk_06 == 2);
    }
};

struct UnkStruct_021e332c_14
{
    u8 unk_00;
    s8 unk_01;
    s8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
};

struct UnkStruct_021e332c
{
    STRUCT_PAD(0x00, 0x08);
    UnkStruct_021e332c_08 * unk_08;
    STRUCT_PAD(0x0C, 0x14);
    struct UnkStruct_021e332c_14 * unk_14;
};

extern struct UnkStruct_021e332c data_ov000_021e332c;

namespace map
{

class ProcPL : public ProcEx
{
public:
    ProcPL();

    // func_ov000_021b0964 d1
    // func_ov000_021b0904 d0
};

}; // namespace map

extern struct Unit * gUnitList;

struct UnkStruct_021974fc
{
    struct Unit * unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8 unk_10;
    STRUCT_PAD(0x11, 0x1C);
};
extern struct UnkStruct_021974fc * data_021974fc;

struct UnkStruct_Func_021af79c
{
    STRUCT_PAD(0x00, 0x32);
    u8 unk_32;
    u8 unk_33;
    STRUCT_PAD(0x34, 0x38);

    void func_ov000_021b0eb4(struct Unit *);
};

extern u8 data_ov000_021e3320[];

EC void func_ov000_021af79c(ProcEx * proc)
{
    map::ProcPL * playerPhaseProc;
    struct Unit * unit;

    playerPhaseProc = dynamic_cast<map::ProcPL *>((ProcEx *)func_020190cc((struct Proc *)proc));

    if (func_ov000_021a478c() != 0 && data_ov000_021e3320[data_ov000_021e3324->phase] != 3)
    {
        if ((playerPhaseProc != NULL) && (data_ov000_021e332c.unk_14->unk_06 & 1))
        {
            struct UnkStruct_Func_021af79c * unk = new struct UnkStruct_Func_021af79c;
            unk->unk_32 = data_ov000_021e3344->unk_2f;
            unk->unk_33 = 0;

            if (data_ov000_021e3344->unk_2f != 0)
            {
                unit = gUnitList + data_ov000_021e3344->unk_2f - 1;
            }
            else
            {
                unit = 0;
            }

            unk->func_ov000_021b0eb4(unit);
            func_02012b64(unk, 0x38);
            delete unk;
        }

        data_ov000_021e3344->unk_14 = func_0201ffc0();

        if (data_ov000_021e3344->unk_32 == 0)
        {
            unit = NULL;
        }
        else
        {
            unit = gUnitList + data_ov000_021e3344->unk_32 - 1;
        }

        func_ov000_021b0eb4(data_ov000_021e3344, unit);
        func_020a58b8(gMapStateManager->unk_08, data_ov000_021e3344, 0x14);
        func_02012b64(data_ov000_021e3344, 0x38);
    }

    if (playerPhaseProc == NULL)
    {
        return;
    }

    if (data_ov000_021e3344->unk_32 == 0)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + data_ov000_021e3344->unk_32 - 1;
    }

    data_021974fc->unk_00 = unit;
    func_0204b194(unit->xPos, unit->yPos);

    return;
}

EC void func_ov000_021af944(ProcEx * param_1)
{
    if (!((!(gMapStateManager->unk_04->unk_04->unk_54 & 1) ? TRUE : FALSE) & 0xFF))
    {
        return;
    }

    if (data_ov000_021e332c.unk_08->Check06__())
    {
        return;
    }

    Proc_Break(param_1, 1);

    return;
}

EC void func_ov000_021af9bc(ProcEx * proc)
{
    s16 xLo;
    s16 xHi;
    char * pidStrA;
    char * pidStrB;
    s16 ix;
    s16 iy;
    s16 yLo;
    s16 yHi;
    s32 iVar3;

    struct Unit * iVar4;
    struct Unit * iVar5;
    struct Unit * unit;

    switch (data_ov000_021e3344->unk_33)
    {
        case 0:
            break;

        case 1:
            if (!data_ov000_021e332c.unk_08->Check06(4))
            {
                if ((data_ov000_021e332c.unk_08->unk_06 == 0) || data_ov000_021e332c.unk_08->Get06() == 2)
                {
                    data_ov000_021e332c.unk_08->unk_06 = 1;
                }
            }

            func_ov000_021ccad0(proc);

            Proc_Goto(proc, 1, 0);

            break;

        case 2:
            if (!data_ov000_021e332c.unk_08->Check06_State4())
            {
                if ((data_ov000_021e332c.unk_08->unk_06 == 0) || data_ov000_021e332c.unk_08->Get06() == 2)
                {
                    data_ov000_021e332c.unk_08->unk_06 = 1;
                }
            }

            func_ov000_021ce2d0(proc);

            Proc_Goto(proc, 1, 0);

            break;

        case 3:
            if (!data_ov000_021e332c.unk_08->Check06_State4())
            {
                if ((data_ov000_021e332c.unk_08->unk_06 == 0) || data_ov000_021e332c.unk_08->Get06() == 2)
                {
                    data_ov000_021e332c.unk_08->unk_06 = 1;
                }
            }

            func_ov000_021ce9b8(proc);

            Proc_Goto(proc, 1, 0);

            break;

        case 0xa:
        case 0xb:
        case 0xc:
        case 0xd:
            Proc_Goto(proc, 1, 0);

            break;

        case 8:
        case 9:
        case 0xe:
            if (!data_ov000_021e332c.unk_08->Check06_State4())
            {
                if ((data_ov000_021e332c.unk_08->unk_06 == 0) || data_ov000_021e332c.unk_08->Get06() == 2)
                {
                    data_ov000_021e332c.unk_08->unk_06 = 1;
                }
            }

            EventCaller::TryStartVisitEvent(
                proc, data_ov000_021e3344->unk_30, data_ov000_021e3344->unk_31, data_ov000_021e3344->unk_33);

            if (EventCaller::func_020479b0() != 0)
            {
                gMapStateManager->unk_04->unk_04->ClearValues();
            }

            Proc_Goto(proc, 0, 0);

            break;

        case 0xf:
            if (data_ov000_021e3344->unk_32 != 0)
            {
                iVar4 = gUnitList + data_ov000_021e3344->unk_32 - 1;
            }
            else
            {
                iVar4 = 0;
            }

            iVar4->state2 |= 0x40;

            if (!data_ov000_021e332c.unk_08->Check06_State4())
            {
                func_ov000_021a7370(proc);
            }

            Proc_Goto(proc, 1, 0);

            break;

        case 0x11:
            func_ov000_021a78f8();
            Proc_Goto(proc, 1, 0);
            break;

        case 0x15:
        {
            s32 uVar2 = func_ov000_021d4968(data_ov000_021e3344->unk_30, data_ov000_021e3344->unk_31, 8);

            if (!data_ov000_021e332c.unk_08->Check06_State4())
            {
                func_ov000_021d4d80(uVar2, proc, 1);
            }
            else
            {
                func_ov000_021d4d80(uVar2, 0, 0);
            }

            Proc_Goto(proc, 1, 0);

            break;
        }

        case 5:
            if (!data_ov000_021e332c.unk_08->Check06_State4())
            {
                if ((data_ov000_021e332c.unk_08->unk_06 == 0) || data_ov000_021e332c.unk_08->Get06() == 2)
                {
                    data_ov000_021e332c.unk_08->unk_06 = 1;
                }
            }

            if (CheckUnitAttribute(gMapStateManager->unk_04->unk_00, 0x400) == 0)
            {
                iVar3 = func_0203d01c(gMapStateManager->unk_04->unk_00);
                if (gMapStateManager->unk_04->unk_00->items[iVar3].func_0203e0f8(NULL) != 0)
                {
                    func_0203ce08(gMapStateManager->unk_04->unk_00, iVar3, 1);
                }
            }

            xLo = MAX(data_ov000_021e3344->unk_30 - 1, gMapStateManager->unk_24);
            yLo = MAX(data_ov000_021e3344->unk_31 - 1, gMapStateManager->unk_25);
            xHi = MIN(data_ov000_021e3344->unk_30 + 1, gMapStateManager->unk_26 - 1);
            yHi = MIN(data_ov000_021e3344->unk_31 + 1, gMapStateManager->unk_27 - 1);

            for (iy = yLo; iy <= yHi; iy++)
            {
                for (ix = xLo; ix <= xHi; ix++)
                {
                    s32 dy = ABS(data_ov000_021e3344->unk_31 - iy);
                    s32 dx = ABS(data_ov000_021e3344->unk_30 - ix);
                    if ((dx + dy >= 1) && (dx + dy <= 1))
                    {
                        EventCaller::TryStartVisitEvent(proc, ix, iy, data_ov000_021e3344->unk_33);
                    }
                }
            }

            if (EventCaller::func_020479b0() != 0)
            {
                gMapStateManager->unk_04->unk_04->ClearValues();
            }

            Proc_Goto(proc, 1, 0);

            break;

        case 7:
            if (!data_ov000_021e332c.unk_08->Check06_State4())
            {
                if ((data_ov000_021e332c.unk_08->unk_06 == 0) || data_ov000_021e332c.unk_08->Get06() == 2)
                {
                    data_ov000_021e332c.unk_08->unk_06 = 1;
                }
            }

            if (CheckUnitAttribute(gMapStateManager->unk_04->unk_00, 0x400) == 0)
            {
                iVar3 = func_0203d094(gMapStateManager->unk_04->unk_00);
                if (gMapStateManager->unk_04->unk_00->items[iVar3].func_0203e0f8(NULL) != 0)
                {
                    func_0203ce08(gMapStateManager->unk_04->unk_00, iVar3, 1);
                }
            }

            xLo = MAX(data_ov000_021e3344->unk_30 - 1, gMapStateManager->unk_24);
            yLo = MAX(data_ov000_021e3344->unk_31 - 1, gMapStateManager->unk_25);
            xHi = MIN(data_ov000_021e3344->unk_30 + 1, gMapStateManager->unk_26 - 1);
            yHi = MIN(data_ov000_021e3344->unk_31 + 1, gMapStateManager->unk_27 - 1);

            for (iy = yLo; iy <= yHi; iy++)
            {
                for (ix = xLo; ix <= xHi; ix++)
                {
                    s32 dy = ABS(data_ov000_021e3344->unk_31 - iy);
                    s32 dx = ABS(data_ov000_021e3344->unk_30 - ix);
                    if ((dx + dy >= 0) && (dx + dy <= 1))
                    {
                        EventCaller::TryStartVisitEvent(proc, ix, iy, data_ov000_021e3344->unk_33);
                    }
                }
            }

            if (EventCaller::func_020479b0() != 0)
            {
                gMapStateManager->unk_04->unk_04->ClearValues();
            }

            Proc_Goto(proc, 1, 0);

            break;

        case 6:
            if (!data_ov000_021e332c.unk_08->Check06_State4())
            {
                if ((data_ov000_021e332c.unk_08->unk_06 == 0) || data_ov000_021e332c.unk_08->Get06() == 2)
                {
                    data_ov000_021e332c.unk_08->unk_06 = 1;
                }
            }

            if (CheckUnitAttribute(gMapStateManager->unk_04->unk_00, 0x400) == 0)
            {
                iVar3 = func_0203d10c(gMapStateManager->unk_04->unk_00);
                if (gMapStateManager->unk_04->unk_00->items[iVar3].func_0203e0f8(NULL) != 0)
                {
                    func_0203ce08(gMapStateManager->unk_04->unk_00, iVar3, 1);
                }
            }

            EventCaller::TryStartVisitEvent(
                proc, data_ov000_021e3344->unk_30, data_ov000_021e3344->unk_31, data_ov000_021e3344->unk_33);

            if (EventCaller::func_020479b0() != 0)
            {
                gMapStateManager->unk_04->unk_04->ClearValues();
            }

            Proc_Goto(proc, 1, 0);

            break;

        case 0x17:
            if (data_ov000_021e3344->unk_32 != 0)
            {
                iVar4 = gUnitList + data_ov000_021e3344->unk_32 - 1;
            }
            else
            {
                iVar4 = 0;
            }

            func_ov000_021d3674("Encount", iVar4, 0, 0, proc, 1);

            Proc_Goto(proc, 1, 0);

            break;

        case 0x14:
            if (!data_ov000_021e332c.unk_08->Check06_State4())
            {
                if ((data_ov000_021e332c.unk_08->unk_06 == 0) || data_ov000_021e332c.unk_08->Get06() == 2)
                {
                    data_ov000_021e332c.unk_08->unk_06 = 1;
                }
            }

            if (data_ov000_021e3344->unk_34 != 0)
            {
                iVar4 = gUnitList + data_ov000_021e3344->unk_34 - 1;
            }
            else
            {
                iVar4 = 0;
            }

            if (data_ov000_021e3344->unk_34 != 0)
            {
                unit = gUnitList + data_ov000_021e3344->unk_34 - 1;
            }
            else
            {
                unit = 0;
            }

            pidStrA = func_0203c378(iVar4)->pPersonData->unk_00;

            if (data_ov000_021e3344->unk_32 != 0)
            {
                iVar5 = gUnitList + data_ov000_021e3344->unk_32 - 1;
            }
            else
            {
                iVar5 = 0;
            }

            pidStrB = func_0203c378(iVar5)->pPersonData->unk_00;

            EventCaller::TryStartTalkEvent(proc, (u32)pidStrB, (u32)pidStrA, (u32)unit);

            Proc_Goto(proc, 1, 0);

            break;

        case 0x10:
            Proc_Goto(proc, 1, 0);
            break;

        case 0x13:
            Proc_Goto(proc, 1, 0);
            break;

        case 4:
            Proc_Goto(proc, 1, 0);
            break;
    }

    return;
}

EC void func_ov000_021b0510(void)
{
    data_020efcc8->unk_a4->vfunc_68(8);
    return;
}

extern s32 data_ov000_021e24c0;

EC void func_ov000_021b0538(ProcPtr proc)
{
    struct Unit * unit;
    s32 uVar4;

    if (data_ov000_021e3344->unk_32 != 0)
    {
        unit = gUnitList + data_ov000_021e3344->unk_32 - 1;
    }
    else
    {
        unit = NULL;
    }

    if ((unit->state2 & 0x48) != 0)
    {
        return;
    }

    if (EventCaller::CanStartVisitEvent(data_ov000_021e3344->unk_30, data_ov000_021e3344->unk_31, 0x12) == 0)
    {
        return;
    }

    uVar4 = data_ov000_021e24c0;

    if (!data_ov000_021e332c.unk_08->Check06_State4())
    {
        if ((data_ov000_021e332c.unk_08->unk_06 == 0) || data_ov000_021e332c.unk_08->Get06() == 2)
        {
            data_ov000_021e332c.unk_08->unk_06 = 1;
        }
    }

    EventCaller::TryStartVisitEvent(proc, data_ov000_021e3344->unk_30, data_ov000_021e3344->unk_31, 0x12);

    if (EventCaller::func_020479b0() != 0)
    {
        gMapStateManager->unk_04->unk_04->ClearValues();
    }

    if (uVar4 == data_ov000_021e24c0)
    {
        return;
    }

    if (data_ov000_021e3320[data_ov000_021e3324->phase] == 1)
    {
        uVar4 = 0x4c;
    }
    else
    {
        uVar4 = 0x4d;
    }

    data_020efcc8->unk_b0->vfunc_28(uVar4, 0, 0);
    func_020183b4(uVar4, 0x20);

    return;
}

EC void func_ov000_021b06ac(ProcPtr proc)
{
    if (data_ov000_021e332c.unk_08->unk_06 == 1)
    {
        data_ov000_021e332c.unk_08->unk_06 = 0;
    }

    Proc_End(proc);

    return;
}

extern struct ProcCmd data_ov000_021dbdf8[];

class ProcMind : public ProcEx
{
};

EC void func_ov000_021b06d4(ProcPtr parent)
{
    new (Proc_StartBlocking(data_ov000_021dbdf8, parent)) ProcMind;

    return;
}
