#ifndef HARDWARE_HPP
#define HARDWARE_HPP

#include "global.h"

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
    /* bit 13 */ u16 bit_13 : 1;
    /* bit 14 */ u16 bit_14 : 2;
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

struct BgAffineDstData
{
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 dx;
    s32 dy;
};

struct LCDControlBuffer
{
    /* 00 */ struct DispCnt dispcnt; // word?
    /* 04 */ struct DispStat dispstat; // short?
    struct BgCnt unk_06[4];
    // +06 bg0cnt
    // +08 bg1cnt
    // +0a bg2cnt
    // +0c bg3cnt
    /* 0E */ struct WinInCnt winincnt;
    /* 10 */ struct WinOutCnt winoutcnt;
    /* 12 */ struct BlendCnt bldcnt;
    /* 14 */ struct BgAffineDstData bg2affin;
    /* 24 */ struct BgAffineDstData bg3affin;
    STRUCT_PAD(0x34, 0x38);
    // +34 ??
    u16 unk_38;
    u16 unk_3a;
    u16 unk_3c;
    u16 unk_3e;
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u16 unk_46;
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

class AbstCtrl_04
{
public:
    struct LCDControlBuffer * volatile unk_00;
    void * unk_04;
    STRUCT_PAD(0x08, 0x0C);
    s32 unk_0c[4];
    s32 unk_1c;
    s32 unk_20[4];
    void * unk_30;
    void * unk_34;
    s16 unk_38;
    s16 unk_3a;
    s16 unk_3c;
    u8 unk_3e;
    STRUCT_PAD(0x3F, 0x42);
    u8 unk_42;
};

extern AbstCtrl_04 * data_027e0000; // DTCM ptr to data_027e126c
extern AbstCtrl_04 * data_027e0004; // DTCM ptr to data_027e12b0

extern AbstCtrl_04 * data_027e1268;

extern LCDControlBuffer * data_027e0008;
extern LCDControlBuffer * data_027e000c;

#endif // HARDWARE_HPP