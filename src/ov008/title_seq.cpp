#include "global.h"

#include <new>

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

extern AbstCtrl * data_02197718;
extern AbstCtrl * data_021976fc;

extern u32 gClock;

struct PressStart_unk_48
{
    STRUCT_PAD(0x00, 0x04);
    u32 unk_04;
    u32 unk_08; // idk
    u32 unk_0c;
    u16 unk_10; // idk
    u16 unk_12;
    u32 unk_14;
};

struct PressStart : ProcEx
{
    /* 00 - 35 */ // ProcEx

    void * unk_38;
    STRUCT_PAD(0x3C, 0x44);
    u32 unk_44;
    struct PressStart_unk_48 * unk_48;
    struct UnkStruct_02197798 * unk_4c;
    AbstCtrl * unk_50;
    u8 unk_54;
    u8 unk_55;

    PressStart()
    {
        this->unk_44 = 0;
        this->unk_54 = 1;
        this->unk_55 = 0;

        this->unk_48 = (struct PressStart_unk_48 *)func_02004450("/bw/start");

        func_0200452c(&this->unk_38, 0x3c0, 0);
        func_0200456c(&this->unk_38, this->unk_48, 1);

        this->unk_44 |= 0x10;

        if (this->unk_54)
        {
            this->unk_4c = func_0206eca4();
            this->unk_50 = data_021976fc;
        }
        else
        {
            this->unk_4c = func_0206ecb0();
            this->unk_50 = data_02197718;
        }

        func_0206fc44(this->unk_50, 0x10);

        func_0206eeb0(this->unk_50, this->unk_48->unk_04, 0x7800);
        func_0206ef14(this->unk_50, this->unk_48->unk_0c, 0, 0, 0x20);
    }

    virtual ~PressStart()
    {
        func_02004460(this->unk_48);
    }

    virtual void Init(void);
    virtual void Loop(void);
};

struct UnkStruct_02208c40
{
    u8 unk_00;
    STRUCT_PAD(0x01, 0x4);
    PressStart * unk_04;
};

extern struct UnkStruct_02208c40 data_ov008_02208c40;

class TitleSeq : ProcEx
{
public:
    TitleSeq(u32 label)
    {
        data_ov008_02208c40.unk_00 = 0;
        func_020ad244(4);
        Proc_Goto(this, label, 0);
    }

    virtual ~TitleSeq()
    {
        gSoundManager->unk_ac->vfunc_38(0);
        EndTitlePressStart();
        func_020ad244(0x14);
    }
};


EC BOOL func_ov008_02204c20(void)
{
    return data_ov008_02208c40.unk_00;
}

EC void func_ov008_02204c30(BOOL var)
{
    data_ov008_02208c40.unk_00 = var;
    return;
}

void PressStart::Init(void)
{
    return;
}

// NONMATCHING: https://decomp.me/scratch/c3y91
void PressStart::Loop(void)
{
    s32 cVar1;
    s32 uVar2;

    if (this->unk_55 == 0)
    {
        uVar2 = gClock % 0x80;

        if ((uVar2) > 0x40)
        {
            cVar1 = Interpolate(4, 0, 0x10, uVar2, 0x40);
        }
        else
        {
            cVar1 = Interpolate(1, 0x10, 0, uVar2 - 0x40, 0x40);
        }

        this->unk_48->unk_12 &= ~0xc0;
        this->unk_48->unk_12 |= 0x40;

        SetBldTargetA_Maybe(this->unk_4c, 0, 0, 0, 0, 0, 0);
        SetBldTargetB_Maybe(this->unk_4c, 0, 1, 0, 0, 0, 1);

        this->unk_4c->unk_00->dispIo->blend_coeff_a = cVar1;
        this->unk_4c->unk_00->dispIo->blend_coeff_b = 16 - cVar1;

        func_02004348(this->unk_48->unk_14, this->unk_50, 1, 0x80, 0x60, 0x3c0);

        return;
    }

    func_020045fc(this->unk_38);
    func_020049b4(this->unk_38, 0, 0x80, 0x60, 0, 4);

    this->unk_4c->unk_00->dispIo->blend_coeff_a = 0x10;
    this->unk_4c->unk_00->dispIo->blend_coeff_b = 0;

    if ((gClock & 4) != 0)
    {
        func_02004348(this->unk_48->unk_14, this->unk_50, 1, 0x80, 0x60, 0x3c0);
    }

    return;
}

extern struct ProcCmd ProcScr_020ce750[];

EC void StartTitlePressStart(ProcPtr parent)
{
    if (data_ov008_02208c40.unk_04 == NULL)
    {
        data_ov008_02208c40.unk_04 = new (Proc_Start(ProcScr_020ce750, parent)) PressStart();
    }

    return;
}

EC void EndTitlePressStart(void)
{
    Proc_End(data_ov008_02208c40.unk_04);
    data_ov008_02208c40.unk_04 = NULL;
    return;
}

EC void func_ov008_02204f2c(u32 param_1)
{
    PressStart * proc = data_ov008_02208c40.unk_04;

    if (proc != NULL && proc->unk_54 != param_1)
    {
        proc->unk_54 = param_1;

        if ((param_1 & 0xff) != 0)
        {
            proc->unk_4c = func_0206eca4();
            proc->unk_50 = data_021976fc;
        }
        else
        {
            proc->unk_4c = func_0206ecb0();
            proc->unk_50 = data_02197718;
        }

        func_0206fc44(proc->unk_50, 0x10);

        func_0206eeb0(proc->unk_50, proc->unk_48->unk_04, 0x7800);
        func_0206ef14(proc->unk_50, proc->unk_48->unk_0c, 0, 0, 0x20);
    }

    return;
}

EC void func_ov008_02204fd0(void)
{
    if (data_ov008_02208c40.unk_04 != NULL)
    {
        data_ov008_02208c40.unk_04->unk_55 = 1;
    }

    return;
}

EC void TitleSeq_ov008_02204fec(void)
{
    func_0200f308();

    func_0209fa54(1);
    func_0209fce4(2);
    func_0209fe34(0x10);
    func_0209ff34(0x40);

    func_020a04a0(4);
    func_020a0548(8);
    func_020a05b8(0x80);
    func_020a0638(0x100);

    return;
}

EC void TitleSeq_ov008_02205038(void)
{
    func_0200f308();

    func_0209ffe0(1);
    func_020a01b8(0x40);
    func_0209fa54(0x10);
    func_0209fce4(2);
    func_0209fe34(0x20);

    func_020a04a0(4);
    func_020a0548(8);
    func_020a05b8(0x80);
    func_020a0638(0x100);

    return;
}

EC void TitleSeq_ov008_0220508c(ProcPtr proc)
{
    switch (func_ov008_02204c20())
    {
        case 1:
            return;

        case 0:
            func_02022f28(3);
            Proc_End(proc);
            return;
    }
}

EC void TitleSeq_ov008_022050bc(void)
{
    gSoundManager->unk_b0->vfunc_28(0x7a7a0000, 0, 0);
    return;
}

EC void TitleSeq_ov008_022050f0(void)
{
    gSoundManager->unk_ac->vfunc_28(0x7fff0001, 0, 0);
    return;
}

EC void TitleSeq_ov008_02205124(void)
{
    func_020102d8(1);
    return;
}

EC void TitleSeq_ov008_02205134(void)
{
    func_020102d8(0);
    return;
}

// clang-format off

struct ProcCmd ProcScr_TitleSeq[] =
{
    { PROC_CMD_02, 0x0000, 0x00000000 },

PROC_LABEL(0),
    PROC_CALL(TitleSeq_ov008_02205134),
    PROC_CALL(StartTitleMakerLogo),
    PROC_CALL(StartTitleESRBOnlineNotice),
    PROC_CALL(TitleSeq_ov008_02205124),

    // fallthrough

PROC_LABEL(1),
    PROC_CALL(TitleSeq_ov008_02204fec),
    PROC_CALL(EndTitlePressStart),
    PROC_CALL(StartTitleSlideShow),

    // fallthrough

PROC_LABEL(2),
    PROC_CALL(TitleSeq_ov008_02205038),
    PROC_CALL(StartTitlePressStart),
    PROC_CALL(TitleSeq_ov008_022050f0),
    PROC_CALL(StartTitleFireEmblem),
    PROC_CALL(TitleSeq_ov008_0220508c),
    PROC_CALL(StartTitleIntro),
    PROC_SLEEP(30),

    PROC_CALL(TitleSeq_ov008_022050bc),
    PROC_CALL(StartTitleFireEmblem),
    PROC_CALL(TitleSeq_ov008_0220508c),
    PROC_CALL(EndTitlePressStart),

    PROC_GOTO(1),

    PROC_END
};

// clang-format on

EC void StartTitleSeq_Goto2(ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_TitleSeq, parent)) TitleSeq(2);
}

EC void StartTitleSeq_Goto0(ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_TitleSeq, parent)) TitleSeq(0);
}