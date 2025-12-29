#include "global.h"

#include "hardware.hpp"
#include "heap.hpp"
#include "proc.h"
#include "unknown_funcs.h"

extern vu8 gMainLoopBlocked;
extern vu8 data_027e125c;
extern vu32 gClock;
extern vu32 data_027e1264;

struct UnkStruct_020eea00
{
    u32 unk_00;
    STRUCT_PAD(0x04, 0x08);
    u32 unk_08;
};

extern struct UnkStruct_020eea00 data_020eea00;

#define BIOS_EXTRA_BUTTONS *(vu16 *)0x027FFFA8

// TODO: "nds/io_reg.h"
#define REG_KEYINPUT (*(vu16 *)0x04000130)
#define REG_EXMEM_CNT *(vu16 *)(0x04000204)
#define REG_IME *(vu16 *)(0x04000208)
#define REG_DIVCNT *((vu16 *)0x04000280)
#define REG_POWER_CNT *(vu16 *)(0x04000304)
#define REG_DISPCNT_SUB *(vu32 *)(0x04001000)

EC void func_0200f0f0(void);

extern s32 data_020dd67c;

EC void func_0200edf0(void)
{
    func_020a3e04();
    func_020a4430();
    func_020a465c();
    func_0209f654();

    data_020dd67c = -1;

    func_0209f658();
    func_0209f80c();

    REG_DISPCNT_SUB &= ~0x10000;

    func_020ab6c0();

    func_020a0480(0x1ff);
    func_020a5734(0, (void *)0x6800000, 0xa4000);

    func_020a094c();

    func_020a5734(0xc0, (void *)0x7000000, 0x400);
    func_020a5734(0, (void *)0x5000000, 0x400);

    func_020a5734(0xc0, (void *)0x7000400, 0x400);
    func_020a5734(0, (void *)0x5000400, 0x400);

    REG_EXMEM_CNT |= 0x8000;
    REG_POWER_CNT &= ~0x8000;

    func_020a4198();
    func_020a41a8();

    return;
}

EC void func_0200eecc(void)
{
    u16 ime;

    func_020a25dc(1, func_0200f0f0);
    func_020a27ac(1);

    ime = REG_IME;
    REG_IME = 1;

    func_0209f7d8(1, ime);

    return;
}

void System_Init(void)
{
    ScreenState * tmp;
    s32 i;

    gClock = 0;
    data_027e1264 = 0;
    gMainLoopBlocked = 0;
    data_027e125c = 0;

    func_0200edf0();
    func_020120f4();
    func_02012124();
    KeyState_Init();
    func_0201032c();
    InitScreenStates();
    func_0200fcdc();
    Overlay_Init();
    func_0200f350(1);

    tmp = gpActiveScreenSt;

    for (i = 0; i < 2; i++)
    {
        gpActiveScreenSt = i == 0 ? gpMainScreenSt : gpSubScreenSt;

        func_01ffa764();
        func_02010c84(NULL);
    }

    gpActiveScreenSt = tmp;

    func_02019bd4();
    Heap::Init();
    func_020115d4();
    func_02015bd0();
    Proc_Init();
    func_0201bc28();
    func_0200eecc();
    func_0201f3dc();
    rtc_init();
    func_0201ff20();
    func_020217b4();

    tmp = gpActiveScreenSt;

    for (i = 0; i < 2; i++)
    {
        gpActiveScreenSt = (i == 0) ? gpMainScreenSt : gpSubScreenSt;

        func_0201c204();
        func_01ffa720();
    }

    gpActiveScreenSt = tmp;
}

EC void func_0200f028(void)
{
    OS_WaitVBlankIntr();
    GX_DispOn();

    REG_DISPCNT_SUB |= 0x10000;
}

EC void func_0200f04c(void)
{
    if (!gMainLoopBlocked)
        return;

    func_02070468();
    gClock++;

    KeyState_Poll();
    func_02010398();
    func_02015fb4();
    func_0201079c();

    Proc_Run(5);
    Proc_Run(6);
    Proc_Run(7);
    Proc_Run(8);
    Proc_Run(9);
    Proc_Run(10);
    Proc_Run(11);
    Proc_Run(12);

    func_02019c30();
    gMainLoopBlocked = FALSE;

    func_02070480();
    OS_WaitIrq(1, 1);
}

EC void func_0200f0f0(void)
{
    ScreenState * tmp;
    u8 auStack_28[0x1C];

    func_020aa610(&auStack_28);

    data_027e125c = 1;

    tmp = gpActiveScreenSt;
    gpActiveScreenSt = gpMainScreenSt;

    if (!gMainLoopBlocked)
    {
        Proc_Run(1);
        Proc_Run(2);
    }

    Proc_Run(3);

    if (!gMainLoopBlocked)
    {
        Proc_Run(4);
        func_01ffa720();
        func_01ff9af8();
        func_01ffa794();

        gMainLoopBlocked = TRUE;
    }

    data_027e1264++;

    gpActiveScreenSt = tmp;
    data_027e125c = 0;

    func_020aa650(&auStack_28);

    while (REG_DIVCNT & 0x8000)
    {
    };

    *(vu32 *)0x027e3ff8 |= 1;

    return;
}

// active overlays
u8 gActiveOverlayLut[12] = {};

// clang-format off

u8 data_020ca5cc[] =
{
    1, 1,
    2, 2,
    12, 4,
    8, 8,
    12, 12,
    12, 12,
};

// overlay table
u32 gOverlayList[] =
{
    OVERLAY_ID_0,
    OVERLAY_ID_1,
    OVERLAY_ID_2,
    OVERLAY_ID_3,
    OVERLAY_ID_4,
    OVERLAY_ID_5,
    OVERLAY_ID_6,
    OVERLAY_ID_7,
    OVERLAY_ID_8,
    OVERLAY_ID_9,
    OVERLAY_ID_A,
    OVERLAY_ID_B,
};

// clang-format on

EC void Overlay_Init(void)
{
    int i;

    for (i = 0; i < 12; i++)
    {
        gActiveOverlayLut[i] = 0;
    }

    return;
}

EC void LoadOverlay(u32 overlayId)
{
    if (gActiveOverlayLut[overlayId] != 1)
    {
        if (FS_LoadOverlay(0, gOverlayList[overlayId]) == TRUE)
        {
            gActiveOverlayLut[overlayId] = 1;
        }
    }

    return;
}

EC void UnloadOverlay(u32 overlayId)
{
    if (gActiveOverlayLut[overlayId] != 0)
    {
        if (FS_UnloadOverlay(0, gOverlayList[overlayId]) == TRUE)
        {
            gActiveOverlayLut[overlayId] = 0;
        }
    }

    return;
}

EC void func_0200f28c(u32 overlayId)
{
    s32 i;

    for (i = 0; i < 12; i++)
    {
        if ((data_020ca5cc[i] & data_020ca5cc[overlayId]) == 0)
        {
            continue;
        }

        if (!IsOverlayLoaded(i))
        {
            continue;
        }

        UnloadOverlay(i);
    }

    if (IsOverlayLoaded(overlayId))
    {
        return;
    }

    LoadOverlay(overlayId);

    return;
}

EC BOOL IsOverlayLoaded(u32 overlayId)
{
    return gActiveOverlayLut[overlayId];
}

EC void func_0200f308(void)
{
    func_0200f318();
    func_0200f338();

    return;
}

EC void func_0200f318(void)
{
    func_020a088c();
    func_020a08a0();
    func_020a08b4();
    func_020a08d8();
    func_020a08fc();
    func_020a0910();

    return;
}

void func_0200f338(void)
{
    func_020a0960();
    func_020a0974();
    func_020a0988();
    func_020a09b0();

    return;
}

EC void func_0200f350(s32 param_1)
{
    func_0200f308();
    func_0209ffe0(1);
    func_0209fa54(2);
    func_020a04a0(4);
    func_020a0548(8);
    func_0209fce4(0x10);
    func_020a01b8(0x20);

    if (param_1 != 0)
    {
        func_0209fe34(0x40);
    }
    else
    {
        func_0209ff34(0x40);
    }

    func_020a05b8(0x80);
    func_020a0638(0x100);

    return;
}

u8 data_020e4e00[0x400] = {};
u8 data_020e5200[0x400] = {};
u8 data_020e5600[0xa00] = {};
u8 data_020e6000[0xa00] = {};

extern void * data_027e12f4;
extern void * data_027e16f4;

EC void InitScreenStates(void)
{
    gpActiveScreenSt = gpMainScreenSt;

    gpMainScreenSt->dispIo = gpMainDispIo;
    gpMainScreenSt->objVram = 0x06400000; // 2D GFX Engine A OBJ VRAM
    gpMainScreenSt->unk_30 = &data_027e12f4;
    gpMainScreenSt->unk_34 = &data_020e4e00;
    gpMainScreenSt->unk_04 = &data_020e6000;
    func_020a5734(0, gpMainScreenSt->unk_30, 0x400);
    gpMainScreenSt->unk_38 = 0;
    gpMainScreenSt->unk_3a = 0;
    gpMainScreenSt->unk_42 = 0;
    gpMainScreenSt->unk_3c = 0;

    gpSubScreenSt->dispIo = gpSubDispIo;
    gpSubScreenSt->objVram = 0x06600000; // 2D GFX Engine B OBJ VRAM
    gpSubScreenSt->unk_30 = &data_027e16f4;
    gpSubScreenSt->unk_34 = &data_020e5200;
    gpSubScreenSt->unk_04 = &data_020e5600;
    func_020a5734(0, gpSubScreenSt->unk_30, 0x400);
    gpSubScreenSt->unk_38 = 0;
    gpSubScreenSt->unk_3a = 0;
    gpSubScreenSt->unk_42 = 0;
    gpSubScreenSt->unk_3c = 0;

    return;
}

EC void func_0200f4f0(s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    func_020a3d8c(param_1, param_4);

    if (gpActiveScreenSt == gpMainScreenSt ? TRUE : FALSE)
    {
        func_020a1ca4();
        func_020a1d44(param_1, param_3 + param_2 * 0x2000, param_4);
        func_020a1db4();
    }
    else
    {
        func_020a1ef4();
        func_020a1f0c(param_1, param_3 + param_2 * 0x2000, param_4);
        func_020a1f70();
    }

    return;
}

EC void func_0200f570(s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    func_020a3d8c(param_1, param_4);

    if (gpActiveScreenSt == gpMainScreenSt ? TRUE : FALSE)
    {
        func_020a1dfc();
        func_020a1e44(param_1, param_3 + param_2 * 0x2000, param_4);
        func_020a1eb0();
    }
    else
    {
        func_020a1fb0();
        func_020a1fc8(param_1, param_3 + param_2 * 0x2000, param_4);
        func_020a202c();
    }

    return;
}

EC BOOL IsAddressInVramRange(u32 param_1)
{
    if ((param_1 >= 0x6000000) && (param_1 < 0x6080000))
    {
        return TRUE;
    }

    if ((param_1 >= 0x6400000) && (param_1 < 0x6440000))
    {
        return TRUE;
    }

    return FALSE;
}

EC void func_0200fbf0(struct BgAffineSrcData *, struct BgAffineDstData *);

// clang-format off

struct BgAffineSrcData data_020ca608 =
{
    .texX = 0x80,
    .texY = 0x60,
    .scrX = 0x80,
    .scrY = 0x60,
    .sx = 0x100,
    .sy = 0x100,
    .alpha = 0,
};

// clang-format on

EC void func_0200f630(void)
{
    *(u16 *)&gpActiveScreenSt->dispIo->dispcnt = 0;
    *(u16 *)&gpActiveScreenSt->dispIo->bgcnt[0] = 0;
    *(u16 *)&gpActiveScreenSt->dispIo->bgcnt[1] = 0;
    *(u16 *)&gpActiveScreenSt->dispIo->bgcnt[2] = 0;
    *(u16 *)&gpActiveScreenSt->dispIo->bgcnt[3] = 0;

    gpActiveScreenSt->dispIo->dispcnt.unk_02_bit_0 = 0;
    gpActiveScreenSt->dispIo->dispcnt.unk_02_bit_4 = 0;

    func_0200fbf0(&data_020ca608, &gpActiveScreenSt->dispIo->bg2affin);
    func_0200fbf0(&data_020ca608, &gpActiveScreenSt->dispIo->bg3affin);

    return;
}

EC void func_0200f700(void)
{
    gpActiveScreenSt->dispIo->dispcnt.bg0_on = 0;
    gpActiveScreenSt->dispIo->dispcnt.bg1_on = 0;
    gpActiveScreenSt->dispIo->dispcnt.bg2_on = 0;
    gpActiveScreenSt->dispIo->dispcnt.bg3_on = 0;
    gpActiveScreenSt->dispIo->dispcnt.obj_on = 0;

    *(u16 *)&gpActiveScreenSt->dispIo->bgcnt[0] = 0;
    *(u16 *)&gpActiveScreenSt->dispIo->bgcnt[1] = 0;
    *(u16 *)&gpActiveScreenSt->dispIo->bgcnt[2] = 0;
    *(u16 *)&gpActiveScreenSt->dispIo->bgcnt[3] = 0;

    gpActiveScreenSt->dispIo->dispcnt.unk_02_bit_0 = 0;
    gpActiveScreenSt->dispIo->dispcnt.unk_02_bit_4 = 0;

    func_0200fbf0(&data_020ca608, &gpActiveScreenSt->dispIo->bg2affin);
    func_0200fbf0(&data_020ca608, &gpActiveScreenSt->dispIo->bg3affin);

    return;
}

EC void func_0200f864(void)
{
    gpActiveScreenSt->dispIo->unk_38[0] = 0;
    gpActiveScreenSt->dispIo->unk_40[0] = 0;

    gpActiveScreenSt->dispIo->unk_38[1] = 0;
    gpActiveScreenSt->dispIo->unk_40[1] = 0;

    gpActiveScreenSt->dispIo->unk_38[2] = 0;
    gpActiveScreenSt->dispIo->unk_40[2] = 0;

    gpActiveScreenSt->dispIo->unk_38[3] = 0;
    gpActiveScreenSt->dispIo->unk_40[3] = 0;

    return;
}

EC void InitBlendConfig(void)
{
    *(u16 *)&gpActiveScreenSt->dispIo->bldcnt = 0;

    gpActiveScreenSt->dispIo->bldcnt.effect = 0;
    gpActiveScreenSt->dispIo->blend_coeff_a = 0;
    gpActiveScreenSt->dispIo->blend_coeff_b = 0;
    gpActiveScreenSt->dispIo->blend_y = 0;

    gpActiveScreenSt->dispIo->bldcnt.target1_bg0_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target1_bg1_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target1_bg2_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target1_bg3_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target1_obj_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target1_bd_on = 0;

    gpActiveScreenSt->dispIo->bldcnt.target2_bg0_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target2_bg1_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target2_bg2_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target2_bg3_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target2_obj_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target2_bd_on = 0;

    return;
}

EC void InitWindowConfig(void)
{
    *(u16 *)&gpActiveScreenSt->dispIo->winincnt = 0;
    *(u16 *)&gpActiveScreenSt->dispIo->winoutcnt = 0;

    gpActiveScreenSt->dispIo->dispcnt.win0_on = 0;
    gpActiveScreenSt->dispIo->dispcnt.win1_on = 0;
    gpActiveScreenSt->dispIo->dispcnt.objWin_on = 0;

    gpActiveScreenSt->dispIo->unk_48 = 0;
    gpActiveScreenSt->dispIo->unk_4a = 0;

    gpActiveScreenSt->dispIo->unk_49 = 0;
    gpActiveScreenSt->dispIo->unk_4b = 0;

    gpActiveScreenSt->dispIo->unk_4c = 0;
    gpActiveScreenSt->dispIo->unk_4e = 0;

    gpActiveScreenSt->dispIo->unk_4d = 0;
    gpActiveScreenSt->dispIo->unk_4f = 0;

    return;
}

extern s16 data_020c53b0[]; // gSinLut?

EC void func_0200fbf0(struct BgAffineSrcData * arg0, struct BgAffineDstData * arg1)
{
    s32 temp_r10_2;
    s32 sl;
    s32 temp_r11;
    s32 temp_r3;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r8;
    s32 temp_r9;

    sl = ((u16)(arg0->alpha << 8) >> 4);

    temp_r11 = data_020c53b0[sl] << 8;

    temp_r6 = arg0->texX;
    temp_r7 = arg0->texY;

    temp_r8 = temp_r6 - arg0->scrX;
    temp_r9 = temp_r7 - arg0->scrY;

    arg1->pa = IntSys_Div(temp_r11, arg0->sx) >> 4;
    temp_r10_2 = data_020c53b0[sl] << 8;
    arg1->pb = IntSys_Div(temp_r10_2, arg0->sx) >> 4;
    arg1->pc = -(IntSys_Div(temp_r10_2, arg0->sy)) >> 4;
    arg1->pd = IntSys_Div(temp_r11, arg0->sy) >> 4;

    temp_r5 = temp_r9 - temp_r7;
    temp_r3 = temp_r8 - temp_r6;

    arg1->dx = (arg1->pa * temp_r3) + (arg1->pb * temp_r5) + (temp_r6 << 8);
    arg1->dy = (arg1->pc * temp_r3) + (arg1->pd * temp_r5) + (temp_r7 << 8);

    return;
}

EC void func_0200fcdc(void)
{
    ScreenState * puVar1;
    s32 i;

    gpMainDispIo->unk_34 = 1;

    gpMainDispIo->dispstat.vblankFlag = 1;
    gpMainDispIo->dispstat.hblankFlag = 0;
    gpMainDispIo->dispstat.vcountFlag = 0;

    gpActiveScreenSt->dispIo->dispcnt.bit_12 = 0;
    gpActiveScreenSt->dispIo->dispcnt.bit_13_14 = 0;

    puVar1 = gpActiveScreenSt;

    for (i = 0; i < 2; i++)
    {
        gpActiveScreenSt = i == 0 ? gpMainScreenSt : gpSubScreenSt;

        func_0200f630();
        func_0200f864();
        InitBlendConfig();
        InitWindowConfig();

        gpActiveScreenSt->dispIo->unk_50 = 0;
    }

    gpActiveScreenSt = puVar1;

    return;
}

// #func_0200fdd8

// #func_0200ff50

extern struct KeyState gKeyStObj;
struct KeyState * gKeySt = &gKeyStObj;

extern struct TouchState gTouchStObj;
struct TouchState * gTouchSt = &gTouchStObj;

EC void KeyState_Init(void)
{
    gKeySt->previous = gKeySt->held = gKeySt->pressed = gKeySt->repeated = 0;
    gKeySt->repeatClock = 10;
    gKeySt->unk_0a = KEY_SOFT_RESET;

    return;
}

EC void func_02010100(void)
{
    if (!(gKeySt->pressed & KEY_SOFT_RESET))
    {
        return;
    }

    if (gKeySt->held != KEY_SOFT_RESET)
    {
        return;
    }

    if (gKeySt->held == gKeySt->unk_0a)
    {
        return;
    }

    if (func_02010310() == 0)
    {
        return;
    }

    if (func_0201236c() == 0)
    {
        return;
    }

    func_0209f80c();

    REG_DISPCNT_SUB &= ~0x10000;

    func_020ad244(4);
    func_020a3d20();
    func_020a3db0();
    func_020a4b84((*(vu32 *)(0x027FFC20)) + 1);

    return;
}

EC void KeyState_Poll(void)
{
    gKeySt->previous = gKeySt->held;

    if (data_020eea00.unk_00 != 0)
    {
        gKeySt->held = 0;
    }
    else
    {
        gKeySt->held = (((REG_KEYINPUT | BIOS_EXTRA_BUTTONS) ^ KEY_ALL_BUTTONS) & KEY_ALL_BUTTONS);
    }

    if ((gKeySt->held & KEY_DPAD_LEFT) && (gKeySt->held & KEY_DPAD_RIGHT))
    {
        gKeySt->held &= ~(KEY_DPAD_LEFT | KEY_DPAD_RIGHT);
    }

    if ((gKeySt->held & KEY_DPAD_UP) && (gKeySt->held & KEY_DPAD_DOWN))
    {
        gKeySt->held &= ~(KEY_DPAD_UP | KEY_DPAD_DOWN);
    }

    gKeySt->pressed = (gKeySt->held & (gKeySt->held ^ gKeySt->previous));
    gKeySt->repeated = gKeySt->pressed;

    if ((gKeySt->held != 0) && (gKeySt->held == (gKeySt->held & gKeySt->previous)))
    {
        gKeySt->repeatClock--;

        if (gKeySt->repeatClock == 0)
        {
            gKeySt->repeated = gKeySt->held;
            gKeySt->repeatClock = 4;
        }
    }
    else
    {
        gKeySt->repeatClock = 10;
    }

    func_02010100();

    gKeySt->unk_0a = gKeySt->held;

    return;
}

EC BOOL func_020102d8(s32 param_1)
{
    s32 iVar1 = data_020eea00.unk_08;

    if (param_1 != 0)
    {
        data_020eea00.unk_08 = iVar1 - 1;
    }
    else
    {
        data_020eea00.unk_08 = iVar1 + 1;
    }

    return iVar1 == 0;
}

// #func_02010310

EC void func_0201032c(void)
{
    u8 subroutine_arg0[8];

    func_020aa90c();

    if (func_020aa984(&subroutine_arg0) != 0)
    {
        func_020aaa18(&subroutine_arg0);
    }

    gTouchSt->unk_12 = 0;
    gTouchSt->unk_13 = 0;
    gTouchSt->unk_14 = 0;
    gTouchSt->unk_15 = 0;
    gTouchSt->unk_10 = 0;
    gTouchSt->unk_11 = 10;

    return;
}

EC void func_020aab40(void);
EC BOOL func_020aabd4(void *);
EC void func_020aafb8(void *, void *);

EC void func_02010398(void)
{
    s32 iVar1;
    u16 uVar2;
    u32 in_r3;
    u16 local_18[4];
    u16 local_12;
    u8 auStack_10[8];
    u32 uStack_8;

    if (data_020eea00.unk_00 != 0)
    {
        gTouchSt->unk_14 = 0;
        gTouchSt->unk_13 = 0;
        gTouchSt->unk_12 = 0;
        gTouchSt->unk_15 = 0;
        gTouchSt->unk_10 = 0;
        gTouchSt->unk_11 = 10;
        return;
    }

    uStack_8 = in_r3;
    func_020aab40();

    if (func_020aabd4(auStack_10) == 0)
    {
        func_020aafb8(&local_18, auStack_10);
    }
    else
    {
        local_12 = 3;
    }

    if (local_12 == 0)
    {

        gTouchSt->unk_00 = local_18[0];
        gTouchSt->unk_02 = local_18[1];

        if (gTouchSt->unk_12 == 0)
        {
            gTouchSt->unk_14 = 1;
            gTouchSt->unk_04 = local_18[0];
            gTouchSt->unk_06 = local_18[1];
            gTouchSt->unk_0c = local_18[0];
            gTouchSt->unk_08 = gTouchSt->unk_0c;
            gTouchSt->unk_0e = local_18[1];
            gTouchSt->unk_0a = gTouchSt->unk_0e;
        }
        else
        {
            gTouchSt->unk_14 = 0;
        }

        gTouchSt->unk_12 = 1;
        gTouchSt->unk_15 = 0;

        uVar2 = local_18[0];

        if (gTouchSt->unk_08 <= local_18[0])
        {
            uVar2 = gTouchSt->unk_08;
        }

        gTouchSt->unk_08 = uVar2;

        if (local_18[0] <= gTouchSt->unk_0c)
        {
            local_18[0] = gTouchSt->unk_0c;
        }

        gTouchSt->unk_0c = local_18[0];

        uVar2 = local_18[1];

        if (gTouchSt->unk_0a <= local_18[1])
        {
            uVar2 = gTouchSt->unk_0a;
        }

        gTouchSt->unk_0a = uVar2;

        if (local_18[1] <= gTouchSt->unk_0e)
        {
            local_18[1] = gTouchSt->unk_0e;
        }

        gTouchSt->unk_0e = local_18[1];

        if (gTouchSt->unk_10 < 0xff)
        {
            gTouchSt->unk_10++;
        }

        gTouchSt->unk_11--;

        if (gTouchSt->unk_11 == 0)
        {
            gTouchSt->unk_13 = gTouchSt->unk_12;
            gTouchSt->unk_11 = 4;
            return;
        }

        gTouchSt->unk_13 = gTouchSt->unk_14;
    }
    else
    {
        if (gTouchSt->unk_12 == 1)
        {
            gTouchSt->unk_15 = 1;
        }
        else
        {
            gTouchSt->unk_15 = 0;
            gTouchSt->unk_10 = 0;
        }

        gTouchSt->unk_14 = 0;
        gTouchSt->unk_13 = 0;
        gTouchSt->unk_12 = 0;
        gTouchSt->unk_11 = 10;
    }

    return;
}

EC BOOL func_020ac04c(s32);

EC void func_02010600(ProcPtr proc)
{
    if (!func_020ac04c(1))
    {
        return;
    }

    Proc_End(proc);

    return;
}

extern struct ProcCmd data_020ca624[];

EC void func_02010624(void)
{
    if (func_020ac04c(1))
    {
        return;
    }

    Proc_Start(data_020ca624, PROC_TREE_5);

    return;
}

EC void func_0201064c(void)
{
    Proc_EndEach(data_020ca624);
    func_020ac04c(0);
    return;
}

EC s32 func_0201239c(void);
EC s32 func_0201f690(void);
EC s32 func_020247d4(void);

EC BOOL func_02010668(void)
{
    if (!func_0201239c())
    {
        return TRUE;
    }

    if (func_0201f690())
    {
        return TRUE;
    }

    if (func_020247d4() != 0)
    {
        return TRUE;
    }

    return FALSE;
}

EC void func_020106a0(void)
{
    func_0201064c();
    data_020eea00.unk_00 = 1;
    return;
}

EC void func_020106bc(void)
{
    func_02010624();
    data_020eea00.unk_00 = 0;
    return;
}
