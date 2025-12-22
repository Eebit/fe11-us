#include "global.h"

#include <new>

#include "unknown_types.h"
#include "unknown_funcs.h"

#include "hardware.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

extern struct UnkStruct_020ca61c * data_020ca61c;

struct UnkStruct_020ca620
{
    STRUCT_PAD(0x00, 0x12);
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
};

extern struct UnkStruct_020ca620 * data_020ca620;

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
    void * unk_40;

    SlideShow()
    {
        this->unk_38 = -1;
        data_020efcc8->unk_b0->vfunc_38(0);
    }

    virtual ~SlideShow()
    {
        func_02016200(this->unk_40);
    };

    virtual void Init(); // func_02005088
    virtual void Loop(); // func_ov008_022052e8
};

EC void func_ov008_022052d4(SlideShow * proc)
{
    proc->Loop();
    return;
}

extern u32 data_020eea30;

struct UnkStruct_02197798
{
    AbstCtrl_04 * unk_00;
    LCDControlBuffer * unk_04;
    // BGCtrl unk_08[4];
    // ObjCtrl unk_68;
};

static inline int max(int a, int b)
{
    return a < b ? a : b;
}

// func_ov008_022052e8
// NONMATCHING
void SlideShow::Loop()
{
    if ((this->unk_38 == -1) && (((data_020ca61c->unk_00 & 0xc0f) != 0 || data_020ca620->unk_14 != 0)) &&
        (data_ov002_021faf40.unk_27 == 0))
    {
        this->unk_38 = 0;

        this->unk_3c = func_0206eca4()->unk_00->unk_00->unk_50;
        this->unk_3d = func_0206ecb0()->unk_00->unk_00->unk_50;

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
EC void func_ov008_02205490(SlideShow * param_1)
{
    // TODO
}

EC void func_ov008_0220598c(SlideShow * proc)
{
    if (data_020efcc8->unk_b0->vfunc_50())
    {
        return;
    }

    proc->unk_40 = func_020161b4();
    Proc_Break(proc, 0);

    return;
}

EC void func_ov008_022059d0(ProcPtr proc)
{
    data_020efcc8->unk_ac->vfunc_28(0x7fff0000, 0, 0);
    func_ov002_021e4020("/ffx/opening1.fx", proc);
    data_ov002_021faf40.unk_25 = 3;
    return;
}

EC void func_ov008_02205a28(ProcPtr proc)
{
    func_ov002_021e4020("/ffx/opening2.fx", proc);
    data_ov002_021faf40.unk_25 = 3;
    return;
}

EC void func_ov008_02205a50(ProcPtr proc)
{
    func_ov002_021e4020("/ffx/opening3.fx", proc);
    data_ov002_021faf40.unk_25 = 3;
    return;
}

EC BOOL func_ov008_02205a78(void)
{
    return data_ov002_021faf40.unk_24 != 0;
}

// clang-format off

struct ProcCmd data_ov008_0220841c[] =
{
    PROC_SLEEP(0),

    PROC_CALL(func_ov008_02205490),
    PROC_REPEAT(func_ov008_0220598c),

    PROC_06(0, func_ov008_022052d4),

    PROC_CALL(func_ov008_022059d0),
    PROC_WHILE(func_ov008_02205a78),

    PROC_CALL(func_ov008_02205a28),
    PROC_WHILE(func_ov008_02205a78),

    PROC_CALL(func_ov008_02205a50),
    PROC_WHILE(func_ov008_02205a78),

PROC_LABEL(99),
    PROC_SLEEP(40),

    PROC_END
};

// clang-format on

EC void func_ov008_02205a94(ProcPtr parent)
{
    new (Proc_StartBlocking(data_ov008_0220841c, parent)) SlideShow();
    return;
}
