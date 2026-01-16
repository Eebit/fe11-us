#include "global.h"

#include "hardware.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

extern struct UnkStruct_02196f0c * data_02196f0c;
extern struct UnkStruct_02196f20 * data_02196f20;
extern struct UnkStruct_021974fc * data_021974fc;

class UnkStruct_020e3ca4
{
public:
    STRUCT_PAD(0x00, 0x08);
    struct Unit * unk_08;
    STRUCT_PAD(0x0C, 0x14);

    // func_020024b0
    UnkStruct_020e3ca4();

    // func_020024d0
    ~UnkStruct_020e3ca4();
};

extern UnkStruct_020e3ca4 * data_020e3ca4;

class UnkStruct_02217560
{
public:
    u32 unk_00;
    u32 unk_04;
    STRUCT_PAD(0x08, 0x10);
    u8 unk_10;
    u8 unk_11;
    STRUCT_PAD(0x12, 0x14);
    u32 unk_14;
    STRUCT_PAD(0x18, 0x20);
    u32 unk_20;

    UnkStruct_02217560()
    {
        this->unk_00 = -1;
        this->unk_04 = -1;
        this->unk_10 = 0;
        this->unk_11 = 0;
        this->unk_20 = -1;
    }
};

extern UnkStruct_02217560 * volatile data_ov005_02217560;

extern struct Unit * gUnitList;

EC void func_ov005_02204c20(ProcPtr proc, s32 param_2)
{
    ScreenState * uVar1;

    func_0200f318();

    func_0209ffe0(1);
    func_0209fa54(2);
    func_0209fce4(0x10);
    func_020a01b8(0x20);
    func_0209ff34(0x40);

    uVar1 = gpActiveScreenSt;
    gpActiveScreenSt = gpMainScreenSt;

    func_02010c84(0);

    gpActiveScreenSt->dispIo->dispcnt.bit_12 = 1;
    gpActiveScreenSt->dispIo->dispcnt.bit_13_14 = 1;

    if (param_2 != 0)
    {
        func_02050aa8(proc, 3, 0xc);
    }

    gpActiveScreenSt = uVar1;

    return;
}

EC void func_ov005_02204cf0(void)
{
    func_ov000_021a37c4();
    func_ov000_021a340c();
    func_ov000_021a35a0();
    return;
}

EC void func_ov005_02204d04(void)
{
    data_021974fc->unk_00 = 0;
    data_021974fc->unk_08 = 0;

    func_0204ae60(2, 1);
    func_0204ad38(2, 1, 0);
    func_0204eb24();

    return;
}

EC void func_ov005_02204d48(void)
{
    s32 unitId;
    struct Unit * unit;

    unitId = gMapStateManager->unk_028[gMapStateManager->cursor->xTile | gMapStateManager->cursor->yTile << 5];

    if (unitId == 0)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + unitId - 1;
    }

    data_021974fc->unk_00 = unit;

    func_0204b194(gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile);
    func_0204ae9c(2, 1);
    func_0204eb24();

    return;
}

EC void func_ov005_02204dd0(s32 param_1)
{
    struct Unit * unit = Force::Get(0)->FindByAttribute(2);

    if (unit == NULL)
    {
        unit = Force::Get(0)->head;
    }

    if (((data_02196f0c->state & 0x200) == 0) && (unit != NULL))
    {
        _ZN6Cursor15SetPosImmediateEss(gMapStateManager->cursor, unit->xPos, unit->yPos);

        if (param_1 == 0)
        {
            gMapStateManager->camera->func_ov000_021a4cec(
                gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile, 1, 0x20, 0);
        }
        else
        {
            gMapStateManager->camera->func_ov000_021a4e84(
                gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile, 1);
        }
    }
    else
    {
        _ZN6Cursor14CenterOnCameraEv(gMapStateManager->cursor);
    }

    gMapStateManager->cursor->SetUnk00And02(0, -1, -1);

    return;
}

EC void func_ov005_02204ec8(void)
{
    func_ov005_02204dd0(1);
}

EC void func_ov005_02204ed8(void)
{
    func_ov005_02204dd0(0);
}

EC void func_ov005_02204ee8(ProcPtr proc)
{
    if (gMapStateManager->cursor->unk_0b == 2 ? TRUE : FALSE)
    {
        return;
    }

    if ((gMapStateManager->camera->unk_18 >= 2 ? TRUE : FALSE))
    {
        return;
    }

    Proc_Break(proc, 1);

    return;
}

EC void func_ov005_02204f3c(ProcPtr proc)
{
    func_0205633c();

    func_020563a8(GetItemByIidStr("IID_IRONSWORD"), 0);
    func_020563a8(GetItemByIidStr("IID_IRONLANCE"), 0);
    func_020563a8(GetItemByIidStr("IID_IRONAXE"), 0);
    func_020563a8(GetItemByIidStr("IID_IRONBOW"), 0);
    func_020563a8(GetItemByIidStr("IID_FIRE"), 0);
    func_020563a8(GetItemByIidStr("IID_LIVE"), 0);

    func_02054870(NULL, proc);

    return;
}

EC void func_ov005_02204fd0(void)
{
    struct Unit * unit;
    s32 i;

    if (data_ov005_02217560->unk_11 == 0)
    {
        gSoundManager->unk_a4->vfunc_38(0x20);
    }

    data_02196f0c->state &= ~0x40;
    data_02196f0c->state &= ~0x40000;
    data_02196f0c->state &= ~0x80000;

    if (gMapStateManager != NULL)
    {
        gMapStateManager->unk_14->unk_04->unk_19 = 0;

        for (i = 0; i < 2; i++)
        {
            for (unit = Force::Get(i)->head; unit != NULL; unit = unit->unk_3c)
            {
                unit->state2 &= ~0x2000;
            }
        }

        data_ov000_021e3324->unk_03 = 0;

        func_ov000_021a35a0();
    }

    delete data_ov005_02217560;
    data_ov005_02217560 = NULL;

    func_0204b790();
    func_0204bbb4(0);

    return;
}

EC u32 func_ov005_022050e0(void)
{
    return data_ov005_02217560->unk_11;
}

EC void func_ov005_022050f4(ProcPtr proc)
{
    if (data_02196f0c->state & 0x100)
    {
        return;
    }

    StartBlockingFadeInFromBlack((struct Proc *)proc, 8, 1);

    return;
}

EC void func_ov005_02205120(void)
{
    if (data_ov005_02217560->unk_10 == 0)
    {
        return;
    }

    data_021974fc->unk_00 = data_020e3ca4->unk_08;
    data_021974fc->unk_08 = 0;

    func_0204ae60(3, 1);
    func_0204ad38(1, 1, 1);
    func_0204eb24();

    return;
}

EC void func_ov005_0220518c(void)
{
    if (data_ov005_02217560->unk_10 != 0)
    {
        return;
    }

    data_021974fc->unk_00 = NULL;
    func_0204ae9c(3, 0);

    return;
}

EC void func_ov005_022051c8(void)
{
    data_02196f20->unk_19d = 0;
    return;
}

EC void func_ov005_022051e0(void)
{
    data_02196f20->unk_19d = 1;
    return;
}

// possibly starting convoy view?
EC void func_ov005_022051f8(ProcPtr proc)
{
    func_0205d860(data_ov005_02217560->unk_14, proc);
    return;
}

EC void func_ov005_02205218(void)
{
    data_02196f0c->unk_14 = 0;
    return;
}

EC void func_ov005_02205230(void)
{
    data_02196f0c->unk_14 = 1;
    return;
}

EC void func_ov005_02205248(void)
{
    if (data_020e3ca4 != NULL)
    {
        delete data_020e3ca4;
    }

    data_020e3ca4 = NULL;

    return;
}

EC void func_ov005_02205280(void)
{
    if (data_020e3ca4 == NULL)
    {
        data_020e3ca4 = new UnkStruct_020e3ca4();
    }

    return;
}

EC void func_ov005_022052b8(void)
{
    data_ov005_02217560->unk_10 = 0;
    return;
}

// clang-format off

struct ProcCmd ProcScr_Prep_02212d60[] =
{
    PROC_NAME,
    PROC_SLEEP(0),

    PROC_CALL(func_ov005_02204ec8),

PROC_LABEL(1),
    PROC_CALL(func_ov000_021ae2dc),
    PROC_CALL(func_ov005_02204d04),

    // fallthrough

PROC_LABEL(0),
    PROC_CALL(StartSally_MMenu),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(0),

PROC_LABEL(2),
    PROC_CALL(func_ov005_02205280),
    PROC_CALL(func_ov005_02205120),

    PROC_GOTO(19),

PROC_LABEL(19),
    PROC_CALL(func_ov005_022051c8),
    PROC_CALL(StartSally_Select),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(21),

PROC_LABEL(20),
    PROC_CALL(func_ov005_022051e0),
    PROC_CALL(StartUnitList),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(21),

PROC_LABEL(21),
    PROC_CALL(func_ov005_022052b8),
    PROC_CALL(func_ov005_02205248),
    PROC_CALL(func_ov005_0220518c),

    PROC_GOTO(0),

PROC_LABEL(22),
    PROC_CALL(func_ov005_022052b8),
    PROC_CALL(func_ov005_02205248),
    PROC_CALL(func_ov005_0220518c),

    PROC_GOTO(9),

PROC_LABEL(3),
    PROC_CALL(func_ov005_02204d48),
    PROC_CALL(func_ov005_02204cf0),
    PROC_CALL(func_ov000_021ae30c),
    PROC_CALL(StartProcSeq),
    PROC_CALL(func_ov005_022054c4),

    PROC_02,

PROC_LABEL(4),

    PROC_CALL(func_ov005_02205280),
    PROC_CALL(func_ov005_02205120),
    PROC_CALL(StartSally_Select),
    PROC_CALL(func_ov005_0220518c),
    PROC_CALL(func_ov005_02205248),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(0),

PROC_LABEL(14),
    PROC_CALL(StartSally_IList),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(4),

PROC_LABEL(15),
    PROC_CALL(StartSally_Trade),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(4),

PROC_LABEL(16),
    PROC_CALL(StartSally_IMenu),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(4),

PROC_LABEL(18),
    PROC_CALL(func_ov005_022051f8),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(4),

PROC_LABEL(5),
    PROC_CALL(func_ov005_02205280),
    PROC_CALL(func_ov005_02205120),
    PROC_CALL(StartSally_SelectJS),
    PROC_CALL(func_ov005_0220518c),
    PROC_CALL(func_ov005_02205248),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(23),

PROC_LABEL(23),
    PROC_CALL(StartSally_JobS),
    PROC_CALL(func_ov005_022054c4),

    PROC_GOTO(5),

PROC_LABEL(6),
    PROC_CALL(func_ov005_02204f3c),

    PROC_GOTO(0),

PROC_LABEL(7),
    PROC_CALL(StartUIConfig),

    PROC_GOTO(0),

PROC_LABEL(8),
    PROC_CALL(func_0204ac18),
    PROC_OVERLAY_LOAD(OVERLAY_ID_6),
    PROC_CALL(StartMainMenu_ProcMain),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_6),
    PROC_CALL(func_0204aca8),

    PROC_GOTO(0),

PROC_LABEL(9),
    PROC_GOTO_IF_YES(func_ov005_022050e0, 12),
    PROC_CALL(func_ov005_02204cf0),
    PROC_CALL(func_ov005_02204fd0),
    PROC_CALL(func_ov005_02204d48),
    PROC_CALL(func_ov005_02204ec8),
    PROC_CALL(func_ov000_021ae2f4),

    PROC_01,

PROC_LABEL(10),
    PROC_CALL(func_ov005_02204fd0),
    PROC_CALL(func_ov005_02204ed8),
    PROC_REPEAT(func_ov005_02204ee8),

    PROC_01,

PROC_LABEL(11),
    PROC_CALL(func_ov005_02204fd0),
    PROC_CALL(func_ov005_02204ec8),
    PROC_CALL(func_ov005_022050f4),

    PROC_01,

PROC_LABEL(12),
    PROC_CALL(func_ov005_02204fd0),
    PROC_CALL(func_ov005_02205230),

    PROC_01,

PROC_LABEL(13),
    PROC_CALL(func_ov005_02204fd0),
    PROC_CALL(func_ov005_02205218),

    PROC_END,
};

// clang-format on

EC void func_ov005_022052d0(ProcPtr proc)
{
    if (data_02196f0c->state & 0x800)
    {
        return;
    }

    data_02196f0c->state |= 0x40;

    func_0204b790();

    if (data_ov005_02217560 == NULL)
    {
        data_ov005_02217560 = new UnkStruct_02217560();
    }

    if (gMapStateManager != NULL)
    {
        gMapStateManager->unk_14->unk_04->unk_19 = 1;
    }

    Proc_StartBlocking(ProcScr_Prep_02212d60, proc);

    if (data_02196f0c->pCurrentMap->unk_0a == 0)
    {
        func_ov005_022054b0(11);
        func_ov005_022054c4();
        return;
    }

    gSoundManager->unk_a4->vfunc_30(0x2f, 0, 0);

    return;
}

EC void func_ov005_022053cc(ProcPtr proc)
{
    data_02196f0c->state |= 0x40;

    func_0204b790();

    if (data_ov005_02217560 == NULL)
    {
        data_ov005_02217560 = new UnkStruct_02217560();
    }

    data_ov005_02217560->unk_11 = 1;

    if (gMapStateManager != NULL)
    {
        gMapStateManager->unk_14->unk_04->unk_19 = 1;
    }

    Proc_StartBlocking(ProcScr_Prep_02212d60, proc);

    data_021974fc->unk_00 = 0;
    data_021974fc->unk_08 = 0;

    func_0204ad38(2, 1, 0);
    func_0204eb24();

    func_ov005_022054b0(0);
    func_ov005_022054c4();

    return;
}

EC void func_ov005_022054b0(s32 label)
{
    data_ov005_02217560->unk_20 = label;
    return;
}

EC void func_ov005_022054c4(void)
{
    if (data_ov005_02217560->unk_20 == -1)
    {
        return;
    }

    Proc_Goto(Proc_Find(ProcScr_Prep_02212d60), data_ov005_02217560->unk_20, 0);
    data_ov005_02217560->unk_20 = -1;

    return;
}
