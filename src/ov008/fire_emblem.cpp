#include "global.h"

#include <new>

#include "unknown_data.h"
#include "unknown_funcs.h"

#include "hardware.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

struct UnkStruct_02197798
{
    ScreenState * unk_00;
    DispIo * unk_04;
    BGCtrl unk_08[4];
    ObjCtrl unk_68;
};

#define REG_POWER_CNT *(vu16 *)(0x04000304)

extern BGCtrl * data_021976f8;

extern ObjCtrl * data_02197718;
extern BGCtrl * data_02197700;
extern BGCtrl * data_02197704;

class FireEmblem : public ProcEx
{
public:
    void * unk_38;
    void * unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
    s16 unk_50;
    u16 unk_52;
    s16 unk_54;
    u8 unk_56;

    FireEmblem()
    {
        struct UnkStruct_02197798 * iVar1;

        this->unk_48 = 0;
        this->unk_4c = 0x1000;
        this->unk_52 = 0x7fff;
        this->unk_54 = 0;
        this->unk_56 = 0;

        REG_POWER_CNT &= ~0x8000;

        func_ov008_02204f2c(1);

        iVar1 = func_0206ecb0();
        iVar1->unk_04->dispcnt.mode = 3;

        iVar1 = func_0206ecb0();
        iVar1->unk_04->dispcnt.win0_on = 0;
        iVar1->unk_04->dispcnt.win1_on = 0;
        iVar1->unk_04->dispcnt.objWin_on = 0;

        SetDispEnable_Maybe(func_0206ecb0(), 1, 1, 1, 1, 1);
        SetBgPriority_Maybe(func_0206ecb0(), 2, 3, 1, 0);

        func_0206fc44(data_02197718, 0x100010);
        func_0206ef9c(data_02197700, 0, 0, 0x18, 0, 0);
        func_0206eee0(data_02197700, 0, 0, 0x400);
        func_0206f580(data_02197700, 0);
        func_0206ef9c(data_02197704, 0, 1, 0x1a, 0, 0);
        func_0206f0fc(data_021976f8, 0, 0, 0x1c, 0);

        // TODO: Complete as part of `StartTitleFireEmblem`
    }

    virtual ~FireEmblem()
    {
        if (this->unk_38 != 0)
        {
            func_02004460(this->unk_38);
        }
    };

    virtual void Loop(void);
};

EC void FireEmblem_Loop(FireEmblem * proc)
{
    proc->Loop();
    return;
}

extern BGCtrl * data_0219771c;

extern struct TouchState * gTouchSt;

// NONMATCHING: https://decomp.me/scratch/tvPca
void FireEmblem::Loop()
{
    struct UnkStruct_02197798 * puVar4;
    s32 r4;

    this->unk_54++;

    SetBldTargetA_Maybe(func_0206ecb0(), 0, 0, 0, 1, 0, 0);
    SetBldTargetB_Maybe(func_0206ecb0(), 1, 1, 1, 0, 1, 1);

    // Maybe setting blend effect
    puVar4 = func_0206ecb0();
    puVar4->unk_00->dispIo->bldcnt.effect = 1;

    // Maybe setting blend amount
    puVar4 = func_0206ecb0();
    puVar4->unk_00->dispIo->blend_coeff_a = this->unk_56;
    puVar4->unk_00->dispIo->blend_coeff_b = 0x10;

    if ((this->unk_50 < 0x64c) && (this->unk_50 >= 0))
    {
        func_02070148(func_0206eca4(), this->unk_56 / 2);
    }

    func_0206fafc(data_0219771c, 0x6a, 0x16, -0x14, -0x34, this->unk_4c, this->unk_4c, 0);

    func_020045fc(this->unk_3c);
    func_020049b4(this->unk_3c, 0x20, 0x80, 0x60, 0, 0);

    if (this->unk_50 >= 0)
    {
        this->unk_50--;

        if (this->unk_50 < 0)
        {
            func_02006398(func_0206ecb0(), -0x10, 0x10, this);
            func_02006398(func_0206eca4(), -0x10, 0x10, this);

            func_ov008_02204c30(1);

            Proc_Goto(this, 99, 0);
        }
        else if ((gTouchSt->unk_14 != 0) || (gKeySt->pressed & KEY_FACE_BUTTON_ANY))
        {
            func_02006398(func_0206ecb0(), -0x10, 0x3c, this);
            func_02006398(func_0206eca4(), -0x10, 0x3c, this);

            func_ov008_02204c30(0);

            func_ov008_02204fd0();

            if (func_0206ec80(0x10f4) != 0)
            {
                data_020efcc8->unk_b0->vfunc_28(0x1000a, 0, 0);
            }

            data_020efcc8->unk_ac->vfunc_64(0, 0x3c);

            this->unk_50 = -1;

            Proc_Goto(this, 99, 0);
        }
    }

    if (this->unk_52 < 20)
    {
        this->unk_52++;
        this->unk_4c = (this->unk_4c * 3 + 0x800) / 4;
        this->unk_56 = Interpolate(5, 0x10, 0, this->unk_52, 0x14);
    }

    r4 = this->unk_54 & 0xff;

    if (r4 < 15)
    {
        s32 iVar7;
        s32 iVar11;

        u16 * puVar5 = data_021976f8->vfunc_08();

        for (iVar7 = 0; iVar7 < 0xc0; iVar7++)
        {
            *puVar5 &= 0xFFF;
            puVar5++;
        }

        if (r4 != 15)
        {
            u16 * iVar8 = data_021976f8->unk_04->tilemap[data_021976f8->unk_10];

            for (iVar7 = 0; iVar7 < 6; iVar7++)
            {
                for (iVar11 = 0; iVar11 < 4; iVar11++)
                {
                    iVar8[iVar7 * 0x20 + iVar11] |= 0xC000;
                }
            }
        }

        data_021976f8->unk_04->unk_3e |= 1 << data_021976f8->unk_10;
    }

    return;
}

EC void FireEmblem_ov008_02205ee8(FireEmblem * proc)
{
    proc->unk_48 &= ~0x40000000;
    func_0200456c(&proc->unk_3c, proc->unk_38, 1);
    return;
}

EC void FireEmblem_ov008_02205f10(FireEmblem * proc)
{
    if ((proc->unk_48 & 0x100) == 0)
    {
        return;
    }

    Proc_Break(proc, 0);
    func_0200456c(&proc->unk_3c, proc->unk_38, 0);

    proc->unk_52 = 0;
    proc->unk_54 = 0xe8;
    proc->unk_56 = 0x10;

    func_0206f4e0(data_021976f8, 1);

    return;
}

// clang-format off

struct ProcCmd ProcScr_FireEmblem[] =
{
    PROC_06(0, FireEmblem_Loop),
    PROC_SLEEP(30),
    PROC_CALL(FireEmblem_ov008_02205ee8),
    PROC_REPEAT(FireEmblem_ov008_02205f10),
    PROC_02,

PROC_LABEL(99),
    PROC_SLEEP(0),

    PROC_END,
};

// clang-format on

// NONMATCHING: https://decomp.me/scratch/LG68r
EC void StartTitleFireEmblem(ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_FireEmblem, parent)) FireEmblem();
}
