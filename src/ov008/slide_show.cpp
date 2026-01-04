#include "global.h"

#include <new>

#include "unknown_types.h"
#include "unknown_funcs.h"

#include "hardware.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

extern struct KeyState * gKeySt;

extern struct TouchState * gTouchSt;

struct UnkStruct_021faf40
{
    STRUCT_PAD(0x00, 0x24);
    u8 unk_24;
    u8 unk_25;
    u8 unk_26;
    u8 unk_27;
};

extern struct UnkStruct_021faf40 data_ov002_021faf40;

class SlideShow : public ProcEx
{
public:
    s32 unk_38;
    s8 unk_3c;
    s8 unk_3d;
    STRUCT_PAD(0x3e, 0x40);
    u32 unk_40;

    SlideShow()
    {
        this->unk_38 = -1;
        data_020efcc8->unk_b0->vfunc_38(0);
    }

    virtual ~SlideShow();

    virtual void Init();
    virtual void Loop();
};

EC void SlideShow_ov008_022052d4(SlideShow * proc)
{
    proc->Loop();
    return;
}

extern u32 data_020eea30;

struct UnkStruct_02197798
{
    ScreenState * unk_00;
    DispIo * unk_04;
    BGCtrl unk_08[4];
    ObjCtrl unk_68;
};

static inline int max(int a, int b)
{
    return a < b ? a : b;
}

// NONMATCHING
void SlideShow::Loop()
{
    if ((this->unk_38 == -1) && (((gKeySt->pressed & KEY_FACE_BUTTON_ANY) != 0 || gTouchSt->unk_14 != 0)) &&
        (data_ov002_021faf40.unk_27 == 0))
    {
        this->unk_38 = 0;

        this->unk_3c = func_0206eca4()->unk_00->dispIo->unk_50;
        this->unk_3d = func_0206ecb0()->unk_00->dispIo->unk_50;

        data_020efcc8->unk_ac->vfunc_64(0, 0x40);
        data_ov002_021faf40.unk_26 = 0;
    }

    if (this->unk_38 >= 0)
    {
        this->unk_38++;

        func_02070148(func_0206eca4(), Interpolate(0, this->unk_3c, -16, max(this->unk_38, 0x20), 0x20));
        func_02070148(func_0206ecb0(), Interpolate(0, this->unk_3d, -16, max(this->unk_38, 0x20), 0x20));

        if (this->unk_38 < 0x20)
        {
            return;
        }

        if (!(data_020eea30 == 0 ? FALSE : TRUE))
        {
            this->unk_38 = -2;
            func_ov002_021e4174();
            Proc_Goto(this, 99, 0);
        }
    }

    return;
}

// NONMATCHING
EC void SlideShow_ov008_02205490(SlideShow * param_1)
{
    // TODO
}

EC void SlideShow_ov008_0220598c(SlideShow * proc)
{
    if (data_020efcc8->unk_b0->vfunc_50())
    {
        return;
    }

    proc->unk_40 = func_020161b4();
    Proc_Break(proc, 0);

    return;
}

EC void SlideShow_ov008_022059d0(ProcPtr proc)
{
    data_020efcc8->unk_ac->vfunc_28(0x7fff0000, 0, 0);
    func_ov002_021e4020("/ffx/opening1.fx", proc);
    data_ov002_021faf40.unk_25 = 3;
    return;
}

EC void SlideShow_ov008_02205a28(ProcPtr proc)
{
    func_ov002_021e4020("/ffx/opening2.fx", proc);
    data_ov002_021faf40.unk_25 = 3;
    return;
}

EC void SlideShow_ov008_02205a50(ProcPtr proc)
{
    func_ov002_021e4020("/ffx/opening3.fx", proc);
    data_ov002_021faf40.unk_25 = 3;
    return;
}

EC BOOL SlideShow_ov008_02205a78(void)
{
    return data_ov002_021faf40.unk_24 != 0;
}

// clang-format off

struct ProcCmd ProcScr_SlideShow[] =
{
    PROC_SLEEP(0),

    PROC_CALL(SlideShow_ov008_02205490),
    PROC_REPEAT(SlideShow_ov008_0220598c),

    PROC_06(0, SlideShow_ov008_022052d4),

    PROC_CALL(SlideShow_ov008_022059d0),
    PROC_WHILE(SlideShow_ov008_02205a78),

    PROC_CALL(SlideShow_ov008_02205a28),
    PROC_WHILE(SlideShow_ov008_02205a78),

    PROC_CALL(SlideShow_ov008_02205a50),
    PROC_WHILE(SlideShow_ov008_02205a78),

PROC_LABEL(99),
    PROC_SLEEP(40),

    PROC_END
};

// clang-format on

EC void StartTitleSlideShow(ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_SlideShow, parent)) SlideShow();
    return;
}

SlideShow::~SlideShow()
{
    func_02016200(this->unk_40);
}