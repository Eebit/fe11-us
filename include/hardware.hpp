#ifndef HARDWARE_HPP
#define HARDWARE_HPP

#include "global.h"

enum
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

enum
{
    KEY_BUTTON_A      = (1 << 0),
    KEY_BUTTON_B      = (1 << 1),
    KEY_BUTTON_SELECT = (1 << 2),
    KEY_BUTTON_START  = (1 << 3),
    KEY_DPAD_RIGHT    = (1 << 4),
    KEY_DPAD_LEFT     = (1 << 5),
    KEY_DPAD_UP       = (1 << 6),
    KEY_DPAD_DOWN     = (1 << 7),
    KEY_BUTTON_R      = (1 << 8),
    KEY_BUTTON_L      = (1 << 9),
    KEY_BUTTON_X      = (1 << 10),
    KEY_BUTTON_Y      = (1 << 11),

    KEY_ANY           = (1 << 12) - 1,
};

#define KEY_DPAD_ANY (KEY_DPAD_RIGHT | KEY_DPAD_LEFT | KEY_DPAD_UP | KEY_DPAD_DOWN)
#define KEY_BUTTON_ANY (KEY_ANY &~ KEY_DPAD_ANY)
#define KEY_FACE_BUTTON_ANY (KEY_BUTTON_ANY &~ (KEY_BUTTON_L | KEY_BUTTON_R))
#define KEY_SOFT_RESET (KEY_BUTTON_L | KEY_BUTTON_R | KEY_BUTTON_START | KEY_BUTTON_SELECT)
#define KEY_ALL_BUTTONS 0x2FFF

struct DispCnt
{
    /* bit  0 */ u16 mode : 3;
    /* bit  3 */ u16 unk_3 : 1; // reserved, do not use
    /* bit  4 */ u16 bg0_on : 1;
    /* bit  5 */ u16 bg1_on : 1;
    /* bit  6 */ u16 bg2_on : 1;
    /* bit  7 */ u16 bg3_on : 1;
    /* bit  8 */ u16 obj_on : 1;
    /* bit  9 */ u16 win0_on : 1;
    /* bit 10 */ u16 win1_on : 1;
    /* bit 11 */ u16 objWin_on : 1;
    /* bit 12 */ u16 bit_12 : 1;
    /* bit 13 */ u16 bit_13_14 : 2;
    /* bit 15 */ u16 bit_15 : 1;
    u16 unk_02_bit_0 : 3;
    u16 unk_02_bit_4 : 3;
};

struct DispStat
{
    /* bit  0 */ u16 vblankFlag : 1;
    /* bit  1 */ u16 hblankFlag : 1;
    /* bit  2 */ u16 vcountFlag : 1;
    /* bit  3 */ u16 vblankIrqEnable : 1;
    /* bit  4 */ u16 hblankIrqEnable : 1;
    /* bit  5 */ u16 vcountIrqEnable : 1;
    /* bit  6 */ u16 dummy : 2;
    /* bit  8 */ u16 vcountCompare : 8;
};

struct BgCnt
{
    /* bit  0 */ u16 priority : 2;
    /* bit  2 */ u16 charBaseBlock : 2;
    /* bit  4 */ u16 dummy : 2;
    /* bit  6 */ u16 mosaic : 1;
    /* bit  7 */ u16 colorMode : 1;
    /* bit  8 */ u16 screenBaseBlock : 5;
    /* bit 13 */ u16 areaOverflowMode : 1;
    /* bit 14 */ u16 screenSize : 2;
};

struct WinInCnt
{
    u16 win0_enableBg0 : 1;
    u16 win0_enableBg1 : 1;
    u16 win0_enableBg2 : 1;
    u16 win0_enableBg3 : 1;
    u16 win0_enableObj : 1;
    u16 win0_enableBlend : 1;
    u16 : 2;

    u16 win1_enableBg0 : 1;
    u16 win1_enableBg1 : 1;
    u16 win1_enableBg2 : 1;
    u16 win1_enableBg3 : 1;
    u16 win1_enableObj : 1;
    u16 win1_enableBlend : 1;
    u16 : 2;
};

struct WinOutCnt
{
    u16 wout_enableBg0 : 1;
    u16 wout_enableBg1 : 1;
    u16 wout_enableBg2 : 1;
    u16 wout_enableBg3 : 1;
    u16 wout_enableObj : 1;
    u16 wout_enableBlend : 1;
    u16 : 2;

    u16 wobj_enableBg0 : 1;
    u16 wobj_enableBg1 : 1;
    u16 wobj_enableBg2 : 1;
    u16 wobj_enableBg3 : 1;
    u16 wobj_enableObj : 1;
    u16 wobj_enableBlend : 1;
    u16 : 2;
};

struct BlendCnt
{
    u16 target1_bg0_on : 1;
    u16 target1_bg1_on : 1;
    u16 target1_bg2_on : 1;
    u16 target1_bg3_on : 1;
    u16 target1_obj_on : 1;
    u16 target1_bd_on : 1;
    u16 effect : 2;
    u16 target2_bg0_on : 1;
    u16 target2_bg1_on : 1;
    u16 target2_bg2_on : 1;
    u16 target2_bg3_on : 1;
    u16 target2_obj_on : 1;
    u16 target2_bd_on : 1;
};

struct BgAffineSrcData
{
    s32 texX;
    s32 texY;
    s16 scrX;
    s16 scrY;
    s16 sx;
    s16 sy;
    u16 alpha;
};

struct BgAffineDstData
{
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 dx;
    s32 dy;
};

struct DispIo
{
    /* 00 */ struct DispCnt dispcnt; // word?
    /* 04 */ struct DispStat dispstat; // short?
    /* 06 */ struct BgCnt bgcnt[4];
    // +06 bg0cnt
    // +08 bg1cnt
    // +0a bg2cnt
    // +0c bg3cnt
    /* 0E */ struct WinInCnt winincnt;
    /* 10 */ struct WinOutCnt winoutcnt;
    /* 12 */ struct BlendCnt bldcnt;
    /* 14 */ struct BgAffineDstData bg2affin;
    /* 24 */ struct BgAffineDstData bg3affin;
    u32 unk_34;
    s16 unk_38[4];
    s16 unk_40[4];
    // +48-50 win0/win1
    u8 unk_48;
    u8 unk_49;
    u8 unk_4a;
    u8 unk_4b;
    u8 unk_4c;
    u8 unk_4d;
    u8 unk_4e;
    u8 unk_4f;
    s8 unk_50;
    /* 51 */ u8 blend_coeff_a;
    /* 52 */ u8 blend_coeff_b;
    /* 53 */ u8 blend_y;
    // +54 blend stuff...?
};

class ScreenState
{
public:
    /* 00 */ struct DispIo * volatile dispIo;
    void * unk_04;
    STRUCT_PAD(0x08, 0x0C);
    /* 0C */ void * bgTiles[4];
    /* 1C */ s32 objVram;
    /* 20 */ u16 * tilemap[4];
    void * unk_30;
    void * unk_34;
    s16 unk_38;
    s16 unk_3a;
    s16 unk_3c;
    u8 unk_3e;
    STRUCT_PAD(0x3F, 0x42);
    u8 unk_42;
};

struct KeyState
{
    /* 00 */ u16 pressed;
    /* 02 */ u16 repeated;
    /* 04 */ u16 held;
    /* 06 */ u16 previous;
    /* 08 */ u16 repeatClock;
    /* 0A */ u16 unk_0a;
};

struct TouchState
{
    STRUCT_PAD(0x00, 0x10);
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
};

class AbstCtrl
{
public:
    // vtable
    /* 04 */ ScreenState * unk_04;
    u8 unk_08;
    STRUCT_PAD(0x09, 0x0C);

    virtual s32 vfunc_00(void);
    virtual s32 vfunc_04(void);
    virtual u16 * vfunc_08(void);
    virtual void vfunc_0c(s32, s32, s32, s32);
    virtual void vfunc_10(s32, s32, s32, s32, u8);
};

class BGCtrl : public AbstCtrl
{
public:
    struct BgCnt * unk_0c;
    s16 unk_10;
    u8 unk_12;
    s16 unk_14;
    s16 unk_16;

    virtual s32 vfunc_00(void); // func_02008a28
    virtual s32 vfunc_04(void); // func_02008a3c
    virtual u16 * vfunc_08(void); // func_020069f4
    virtual void vfunc_0c(s32, s32, s32, s32);
    virtual void vfunc_10(s32, s32, s32, s32, u8);
};

class ObjCtrl : public AbstCtrl
{
public:
    STRUCT_PAD(0x0C, 0x10);

    virtual s32 vfunc_00(void); // func_02004830
    virtual s32 vfunc_04(void); // func_0207020c
    virtual u16 * vfunc_08(void); // func_020069ec
    virtual void vfunc_0c(s32, s32, s32, s32);
    virtual void vfunc_10(s32, s32, s32, s32, u8);
};

extern ScreenState * gpMainScreenSt; // DTCM ptr to gMainScreenSt
extern ScreenState * gpSubScreenSt; // DTCM ptr to gSubScreenSt

extern ScreenState * gpActiveScreenSt;

extern DispIo * gpMainDispIo;
extern DispIo * gpSubDispIo;

#endif // HARDWARE_HPP