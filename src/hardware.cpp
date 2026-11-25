#include "global.h"

#include "hardware.hpp"
#include "heap.hpp"
#include "proc.h"
#include "unknown_data.h"
#include "unknown_funcs.h"

extern vu8 gMainLoopBlocked;
extern vu8 data_027e125c;
extern vu32 gAnimClock;
extern vu32 gElapsedFrames;

struct UnkStruct_020eea00
{
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
};

extern struct UnkStruct_020eea00 data_020eea00;

struct HardwareProc
{
    PROC_HEADER
    STRUCT_PAD(0x36, 0x5A);
    s16 unk_5a;
};

struct UnkStruct_02010dfc
{
    /* 00 */ u8 unk_00;
    /* 01 */ u8 unk_01;
    /* 02 */ u16 unk_02[1];
};

struct BgConfigEntry
{
    u16 charBaseBlock : 4;
    u16 screenBaseBlock : 5;
    u16 screenSize : 2;
    u16 priority : 2;
    u16 colorMode : 1;
    u16 areaOverflowMode : 1;
};

struct BgConfig
{
    /* 00 */ u8 mode;
    /* 01 */ u8 unk_01;
    /* 02 */ u8 unk_02_0 : 4;
    /* 02 */ u8 unk_02_4 : 4;
    /* 03 */ u8 unk_03;
    /* 04 */ struct BgConfigEntry bg[4];
};

static inline BOOL IsMainScreenActive(void)
{
    return gpActiveScreenSt == gpMainScreenSt ? TRUE : FALSE;
}

#define BIOS_EXTRA_BUTTONS *(vu16 *)0x027FFFA8

// TODO: "nds/io_reg.h"
#define REG_BG0OFS *(vu32 *)(0x04000010)
#define REG_BG1OFS *(vu32 *)(0x04000014)
#define REG_BG2OFS *(vu32 *)(0x04000018)
#define REG_BG3OFS *(vu32 *)(0x0400001C)
#define REG_KEYINPUT (*(vu16 *)0x04000130)
#define REG_EXMEM_CNT *(vu16 *)(0x04000204)
#define REG_IME *(vu16 *)(0x04000208)
#define REG_DIVCNT *((vu16 *)0x04000280)
#define REG_POWER_CNT *(vu16 *)(0x04000304)
#define REG_DISPCNT_SUB *(vu32 *)(0x04001000)
#define REG_BG0OFS_SUB *(vu32 *)(0x04001010)
#define REG_BG1OFS_SUB *(vu32 *)(0x04001014)
#define REG_BG2OFS_SUB *(vu32 *)(0x04001018)
#define REG_BG3OFS_SUB *(vu32 *)(0x0400101C)

#define VRAM_MAIN ((u8 *)0x06000000)
#define VRAM_SUB ((u8 *)0x06200000)

EC u8 __DTCM_LO[];

#define DTCM_IRQ_CHECK_BITS (*(vu32 *)((u32)__DTCM_LO + 0x3FF8))

EC void func_0200f0f0(void);
EC BOOL func_02010810(void);
EC void func_01ff9948(u8);

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

    gAnimClock = 0;
    gElapsedFrames = 0;
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
    Sound_Init();
    Proc_Init();
    func_0201bc28();
    func_0200eecc();
    func_0201f3dc();
    rtc_init();
    Random_Init();
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
    gAnimClock++;

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

    gElapsedFrames++;

    gpActiveScreenSt = tmp;
    data_027e125c = 0;

    func_020aa650(&auStack_28);

    while (REG_DIVCNT & 0x8000)
    {
    };

    DTCM_IRQ_CHECK_BITS |= 1;

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

extern const s16 data_020c53b0[];

static inline s16 sin(u16 angle)
{
    return data_020c53b0[(angle >> 4) * 2];
}

static inline s16 cos(u16 angle)
{
    return data_020c53b0[(angle >> 4) * 2 + 1];
}

EC void func_0200fbf0(struct BgAffineSrcData * src, struct BgAffineDstData * dst)
{
    u16 angle = src->alpha << 8;
    s32 texX = src->texX;
    s32 texY = src->texY;
    s32 x = texX - src->scrX;
    s32 y = texY - src->scrY;

    dst->pa = IntSys_Div(cos(angle) << 8, src->sx) >> 4;
    dst->pb = IntSys_Div(sin(angle) << 8, src->sx) >> 4;
    dst->pc = -IntSys_Div(sin(angle) << 8, src->sy) >> 4;
    dst->pd = IntSys_Div(cos(angle) << 8, src->sy) >> 4;

    dst->dx = dst->pa * (x - texX) + dst->pb * (y - texY) + (texX << 8);
    dst->dy = dst->pc * (x - texX) + dst->pd * (y - texY) + (texY << 8);

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

EC void func_0200fdd8(s32 bg)
{
    s32 x;
    s32 y;

    switch (bg)
    {
        case 3:
            y = gpMainDispIo->unk_40[3] - gpMainScreenSt->unk_3a;
            x = gpMainDispIo->unk_38[3] - gpMainScreenSt->unk_38;
            REG_BG3OFS = (x & 0x1FF) | ((y << 16) & (0x1FF << 16));
            break;
        case 2:
            y = gpMainDispIo->unk_40[2] - gpMainScreenSt->unk_3a;
            x = gpMainDispIo->unk_38[2] - gpMainScreenSt->unk_38;
            REG_BG2OFS = (x & 0x1FF) | ((y << 16) & (0x1FF << 16));
            break;
        case 1:
            y = gpMainDispIo->unk_40[1] - gpMainScreenSt->unk_3a;
            x = gpMainDispIo->unk_38[1] - gpMainScreenSt->unk_38;
            REG_BG1OFS = (x & 0x1FF) | ((y << 16) & (0x1FF << 16));
            break;
        case 0:
            if (gpMainDispIo->dispcnt.unk_3)
            {
                func_020a1478(gpMainDispIo->unk_38[0]);
                return;
            }

            y = gpMainDispIo->unk_40[0] - gpMainScreenSt->unk_3a;
            x = gpMainDispIo->unk_38[0] - gpMainScreenSt->unk_38;
            REG_BG0OFS = (x & 0x1FF) | ((y << 16) & (0x1FF << 16));
            return;
    }

    return;
}

EC void func_0200ff50(s32 bg)
{
    s32 x;
    s32 y;

    switch (bg)
    {
        case 3:
            y = gpSubDispIo->unk_40[3] - gpSubScreenSt->unk_3a;
            x = gpSubDispIo->unk_38[3] - gpSubScreenSt->unk_38;
            REG_BG3OFS_SUB = (x & 0x1FF) | ((y << 16) & (0x1FF << 16));
            break;
        case 2:
            y = gpSubDispIo->unk_40[2] - gpSubScreenSt->unk_3a;
            x = gpSubDispIo->unk_38[2] - gpSubScreenSt->unk_38;
            REG_BG2OFS_SUB = (x & 0x1FF) | ((y << 16) & (0x1FF << 16));
            break;
        case 1:
            y = gpSubDispIo->unk_40[1] - gpSubScreenSt->unk_3a;
            x = gpSubDispIo->unk_38[1] - gpSubScreenSt->unk_38;
            REG_BG1OFS_SUB = (x & 0x1FF) | ((y << 16) & (0x1FF << 16));
            break;
        case 0:
            y = gpSubDispIo->unk_40[0] - gpSubScreenSt->unk_3a;
            x = gpSubDispIo->unk_38[0] - gpSubScreenSt->unk_38;
            REG_BG0OFS_SUB = (x & 0x1FF) | ((y << 16) & (0x1FF << 16));
            break;
    }

    return;
}

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
    s32 prev;

    if (param_1 != 0)
    {
        prev = data_020eea00.unk_08;
        data_020eea00.unk_08 = prev - 1;
    }
    else
    {
        prev = data_020eea00.unk_08;
        data_020eea00.unk_08 = prev + 1;
    }

    return prev == 0;
}

EC BOOL func_02010310(void)
{
    return data_020eea00.unk_08 == 0;
}

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
    u16 value;
    u8 raw[8];
    u16 pos[4];

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

    func_020aab40();

    if (func_020aabd4(raw) == 0)
    {
        func_020aafb8(&pos, raw);
    }
    else
    {
        pos[3] = 3;
    }

    if (pos[3] == 0)
    {
        gTouchSt->unk_00 = pos[0];
        gTouchSt->unk_02 = pos[1];

        if (gTouchSt->unk_12 == 0)
        {
            gTouchSt->unk_14 = 1;
            gTouchSt->unk_04 = pos[0];
            gTouchSt->unk_06 = pos[1];
            gTouchSt->unk_0c = pos[0];
            gTouchSt->unk_08 = gTouchSt->unk_0c;
            gTouchSt->unk_0e = pos[1];
            gTouchSt->unk_0a = gTouchSt->unk_0e;
        }
        else
        {
            gTouchSt->unk_14 = 0;
        }

        gTouchSt->unk_12 = 1;
        gTouchSt->unk_15 = 0;

        value = (pos[0] < gTouchSt->unk_08) ? pos[0] : gTouchSt->unk_08;
        gTouchSt->unk_08 = value;

        value = (pos[0] > gTouchSt->unk_0c) ? pos[0] : gTouchSt->unk_0c;
        gTouchSt->unk_0c = value;

        value = (pos[1] < gTouchSt->unk_0a) ? pos[1] : gTouchSt->unk_0a;
        gTouchSt->unk_0a = value;

        value = (pos[1] > gTouchSt->unk_0e) ? pos[1] : gTouchSt->unk_0e;
        gTouchSt->unk_0e = value;

        if (gTouchSt->unk_10 < 255)
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

EC void func_020106d8(struct HardwareProc * proc)
{
    if (!func_02010668())
    {
        proc->unk_5a = 0;
        return;
    }

    proc->unk_5a = 1;
    func_020106a0();
    return;
}

EC void func_02010704(ProcPtr proc)
{
    if (((BIOS_EXTRA_BUTTONS & 0x8000) >> 15) == 0 || func_02010810() == 0)
    {
        Proc_Break(proc, 1);
        return;
    }

    if (func_02010668())
    {
        return;
    }

    func_020abd14(12, 0, 0);
    Proc_Break(proc, 1);
    return;
}

EC void func_0201076c(struct HardwareProc * proc)
{
    if (proc->unk_5a != 0)
    {
        func_020106bc();
    }

    func_02014728();
    func_020707f0();
    data_020eea00.unk_00 = 0;

    return;
}

EC void func_0201079c(void)
{
    if (!func_02010810())
    {
        return;
    }

    if (((BIOS_EXTRA_BUTTONS & 0x8000) >> 15) == 0)
    {
        return;
    }

    Proc_Start(ProcScr_020ca64c, PROC_TREE_5);
    return;
}

EC BOOL func_020107d8(s32 param_1)
{
    s32 prev;

    if (param_1 != 0)
    {
        prev = data_020eea00.unk_04;
        data_020eea00.unk_04 = prev - 1;
    }
    else
    {
        prev = data_020eea00.unk_04;
        data_020eea00.unk_04 = prev + 1;
    }

    return prev == 0;
}

EC BOOL func_02010810(void)
{
    if (data_020eea00.unk_04 == 0)
    {
        return TRUE;
    }

    return FALSE;
}

EC void SetBackgroundTileDataOffset(u8 idx, u8 val)
{
    u8 * base = IsMainScreenActive() == TRUE ? VRAM_MAIN : VRAM_SUB;

    gpActiveScreenSt->bgTiles[idx] = base + val * 0x4000;
    gpActiveScreenSt->dispIo->bgcnt[idx].charBaseBlock = val;

    return;
}

EC void SetBackgroundMapDataOffset(u8 idx, u8 val)
{
    gpActiveScreenSt->dispIo->bgcnt[idx].screenBaseBlock = val;

    return;
}

EC void SetBackgroundScreenSize(u8 idx, u8 val)
{
    gpActiveScreenSt->dispIo->bgcnt[idx].screenSize = val;

    return;
}

EC void SetupBackgrounds(const struct BgConfig * config, BOOL clear)
{
    const struct BgConfigEntry * bg;
    u8 * base;
    s32 i;

    base = IsMainScreenActive() == TRUE ? VRAM_MAIN : VRAM_SUB;

    if (clear)
    {
        func_0200f700();
    }

    func_0200f864();

    gpActiveScreenSt->dispIo->bldcnt.effect = 0;
    gpActiveScreenSt->dispIo->dispcnt.mode = config->mode;
    gpActiveScreenSt->dispIo->dispcnt.bit_12 = config->unk_02_0;
    gpActiveScreenSt->dispIo->dispcnt.bit_13_14 = config->unk_02_4;

    if (IsMainScreenActive() == TRUE)
    {
        gpMainDispIo->dispcnt.unk_3 = config->unk_01;
        gpMainDispIo->dispcnt.unk_02_bit_0 = config->unk_03;
        gpMainDispIo->dispcnt.unk_02_bit_4 = 0;
    }

    for (i = 0, bg = config->bg; i < 4; i++, bg++)
    {
        void * src;
        s32 size;

        SetBackgroundTileDataOffset(i, bg->charBaseBlock);
        SetBackgroundMapDataOffset(i, bg->screenBaseBlock);
        SetBackgroundScreenSize(i, bg->screenSize);

        gpActiveScreenSt->dispIo->bgcnt[i].priority = bg->priority;
        gpActiveScreenSt->dispIo->bgcnt[i].colorMode = bg->colorMode;
        gpActiveScreenSt->dispIo->bgcnt[i].areaOverflowMode = bg->areaOverflowMode;

        if (!clear)
        {
            continue;
        }

        func_020a5734(0, gpActiveScreenSt->bgTiles[i], 0x40);
        func_01ff9948(i);
        size = func_01ff9894(gpActiveScreenSt->dispIo->dispcnt.mode, i);
        src = base + gpActiveScreenSt->dispIo->bgcnt[i].screenBaseBlock * 0x800;
        func_020a5780(gpActiveScreenSt->tilemap[i], src, size);
    }

    gpActiveScreenSt->dispIo->dispcnt.bg0_on = 1;
    gpActiveScreenSt->dispIo->dispcnt.bg1_on = 1;
    gpActiveScreenSt->dispIo->dispcnt.bg2_on = 1;
    gpActiveScreenSt->dispIo->dispcnt.bg3_on = 1;
    gpActiveScreenSt->dispIo->dispcnt.obj_on = 1;

    return;
}

EC void func_02010c84(const struct BgConfig * config)
{
    u8 * base = IsMainScreenActive() == TRUE ? data_020eaa00 : data_020e6a00;
    s32 i = 0;
    s32 off = i;

    if (config == NULL)
    {
        config = &data_020ca67c;
    }

    for (; i < 4; i++)
    {
        gpActiveScreenSt->tilemap[i] = (u16 *)(base + off);
        off += 0x1000;
    }

    SetupBackgrounds(config, 1);

    return;
}

EC void func_02010d04(void)
{
    func_02010c84(&data_020ca688);

    return;
}

EC void func_02010d18(const struct BgConfig * config)
{
    u8 * base = IsMainScreenActive() == TRUE ? data_020eaa00 : data_020e6a00;
    s32 i = 0;
    s32 off = i;

    if (config == NULL)
    {
        config = &data_020ca67c;
    }

    for (; i < 4; i++)
    {
        gpActiveScreenSt->tilemap[i] = (u16 *)(base + off);
        off += 0x1000;
    }

    SetupBackgrounds(config, 0);

    return;
}

EC void func_02010d98(u16 * dst, s32 count, u32 tile, u32 pal)
{
    s32 i;

    for (i = 0, count >>= 1; i < count; i++, dst++)
    {
        *dst += tile | (pal << 12);
    }

    return;
}

EC void func_02010dcc(u16 * dst, s32 count, u32 val)
{
    s32 i;

    for (i = 0, count >>= 1; i < count; i++, dst++)
    {
        *dst += val << 12;
    }

    return;
}

EC void func_02010dfc(struct UnkStruct_02010dfc * data, u16 * dst, u32 tile, u32 pal)
{
    s32 x;
    s32 w;
    u16 * src;
    s32 h;
    s32 y;

    h = data->unk_01;
    src = data->unk_02;
    y = 0;
    w = data->unk_00;

    for (; y < h; y++)
    {
        for (x = 0; x < w; x++, src++)
        {
            dst[y * 0x20 + x] = *src + ((tile & 0x3ff) | ((pal & 0xf) << 12));
        }
    }

    return;
}

EC void func_02010e74(u16 * dst, s32 w, s32 h, u32 pal)
{
    s32 x;
    s32 y;

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            dst[y * 0x20 + x] &= 0xfff;
            dst[y * 0x20 + x] |= pal << 12;
        }
    }

    return;
}

EC void func_02010ee0(u16 * dst, s32 w, s32 h, u32 tile, u16 pal)
{
    s32 x;
    s32 y;

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            dst[y * 0x20 + x] += tile | (pal << 12);
        }
    }

    return;
}

EC void func_02010f40(u16 * dst, s32 w, s32 h, u32 pal)
{
    s32 x;
    s32 y;

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            dst[y * 0x20 + x] += pal << 12;
        }
    }

    return;
}

EC void func_02010f98(u16 * dst, u16 w, u16 h)
{
    s32 y;

    for (y = 0; y < h; y++)
    {
        func_020a5824(dst, 0, w * 2);
        dst += 0x20;
    }

    return;
}

EC void func_02010fdc(u16 * src, u16 * dst, s32 w, s32 h, s32 flipX, s32 flipY)
{
    s32 x;
    s32 y;
    u32 flags = 0;

    if (flipX != 0)
    {
        flags |= 0x400;
    }

    if (flipY != 0)
    {
        flags |= 0x800;
    }

    for (y = 0; y < h; y++)
    {
        s32 sy = (flipY != 0) ? (h - y - 1) : y;

        for (x = 0; x < w; x++)
        {
            s32 sx = (flipX != 0) ? (w - x - 1) : x;

            dst[y * 0x20 + x] = flags ^ src[sy * 0x20 + sx];
        }
    }

    return;
}

EC void func_02011078(u16 * dst, u16 w, u16 h, s32 scaleX, s32 scaleY)
{
    s32 newW = (w * scaleX) >> 8;
    s32 newH = (h * scaleY) >> 8;

    func_02010f98(dst + ((w - newW) >> 1) + ((h - newH) >> 1) * 0x20, w, h);

    return;
}

EC void func_020110a8(u16 * src, u16 * dst, s32 w, s32 h, s32 scaleX, s32 scaleY, u8 flipX, u8 flipY)
{
    s32 x;
    s32 y;
    s32 cw;
    s32 ch;
    s32 x0;
    s32 y0;
    u32 flags = 0;

    if (scaleX == 0 || scaleY == 0)
    {
        return;
    }

    cw = w * scaleX;
    ch = (h * scaleY) >> 8;
    x0 = (w - (cw >> 8)) >> 1;
    y0 = (h - ch) >> 1;
    cw >>= 8;

    if (flipX)
    {
        flags |= 0x400;
    }

    if (flipY)
    {
        flags |= 0x800;
    }

    for (y = 0; y < ch; y++)
    {
        s32 dy = y0 + y;
        s32 sy = dy;

        if (flipY)
        {
            sy = h - dy - 1;
        }

        for (x = 0; x < cw; x++)
        {
            s32 sx = x0 + x;

            if (flipX)
            {
                sx = w - sx - 1;
            }

            dst[x0 + dy * 0x20 + x] = flags ^ src[sy * 0x20 + sx];
        }
    }

    return;
}

EC void func_020111a4(u16 * dst, s32 w, s32 h, s32 scaleX, s32 scaleY)
{
    s32 newW = (w * scaleX) >> 8;
    s32 newH = (h * scaleY) >> 8;

    if (w > newW)
    {
        if ((newW & (w != 1)) & 1)
        {
            newW++;
        }
    }

    if (newH < h)
    {
        if ((newH & (h != 1)) & 1)
        {
            newH++;
        }
    }

    func_02010f98(dst + ((w - newW) >> 1) + ((h - newH) >> 1) * 0x20, newW, newH);

    return;
}

EC void func_0201122c(u16 * src, u16 * dst, s32 w, s32 h, s32 sx, s32 sy, u8 flipX, u8 flipY)
{
    s32 j;
    s32 outW;
    s32 flags = 0;
    s32 offY;
    s32 i;
    s32 outH;
    s32 x0;
    s32 srcRow;
    s32 col;
    u32 row;

    if (sx == 0 || sy == 0)
    {
        return;
    }

    outW = (w * sx) >> 8;
    outH = (h * sy) >> 8;

    if (w > outW)
    {
        if (outW & (w != 1) & 1)
        {
            outW++;
        }
    }

    if (outH < h)
    {
        if (outH & (h != 1) & 1)
        {
            outH++;
        }
    }

    x0 = w - outW;
    offY = h - outH;

    if (flipX)
    {
        flags |= 0x400;
    }

    if (flipY)
    {
        flags |= 0x800;
    }

    x0 >>= 1;

    for (i = 0; i < outH; i++)
    {
        row = (u32)i + (offY >> 1);

        if (row < ((u32)((h + 1) & ~1) >> 1))
        {
            srcRow = i;
        }
        else
        {
            srcRow = h - (outH - i);
        }

        if (flipY)
        {
            srcRow = h - srcRow - 1;
        }

        for (j = 0; j < outW; j++)
        {
            if ((u32)(x0 + j) < ((u32)((w + 1) & ~1) >> 1))
            {
                col = j;
            }
            else
            {
                col = w - (outW - j);
            }

            if (flipX)
            {
                col = w - col - 1;
            }

            dst[row * 0x20 + x0 + j] = flags ^ src[srcRow * 0x20 + col];
        }
    }

    return;
}

EC void func_020113d0(u16 * dst, u32 tile, u32 pal)
{
    u32 attr = (pal & 0xf) << 12;

    dst[0x00] = tile | attr;
    dst[0x01] = (tile + 1) | attr;
    dst[0x20] = (tile + 2) | attr;
    dst[0x21] = (tile + 3) | attr;

    return;
}

EC void func_02011408(u16 * dst, u32 tile, u32 pal)
{
    u32 attr = (pal & 0xf) << 12;

    dst[0x00] = tile | attr;
    dst[0x01] = (tile + 1) | attr;
    dst[0x02] = (tile + 4) | attr;
    dst[0x20] = (tile + 2) | attr;
    dst[0x21] = (tile + 3) | attr;
    dst[0x22] = (tile + 5) | attr;

    return;
}
