#include "global.h"

#include "hardware.hpp"
#include "heap.hpp"
#include "proc.h"
#include "unknown_funcs.h"

// extern void * data_027e1268;

// extern void * data_027e0000;
// extern void * data_027e0004;

extern vu8 gMainLoopBlocked;
extern vu8 data_027e125c;
extern vu32 gClock;
extern vu32 data_027e1264;

// TODO: "nds/io_reg.h"
#define REG_EXMEM_CNT *(vu16 *)(0x04000204)
#define REG_IME *(vu16 *)(0x04000208)
#define REG_POWER_CNT *(vu16 *)(0x04000304)
#define REG_DISPCNT_SUB *(vu32 *)(0x04001000)

EC void func_0200f0f0(void);
EC void func_020a25dc(s32, void (*)(void));
EC void func_020a27ac(s32);
EC void func_0209f7d8(s32, s32);

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

void func_0200ef04(void)
{
    AbstCtrl_04 * tmp;
    s32 i;

    gClock = 0;
    data_027e1264 = 0;
    gMainLoopBlocked = 0;
    data_027e125c = 0;

    func_0200edf0();
    func_020120f4();
    func_02012124();
    func_020100ac();
    func_0201032c();
    func_0200f3b8();
    func_0200fcdc();
    func_0200f1e8();
    func_0200f350(1);

    tmp = data_027e1268;

    for (i = 0; i < 2; i++)
    {
        data_027e1268 = i == 0 ? data_027e0000 : data_027e0004;

        func_01ffa764();
        func_02010c84(NULL);
    }

    data_027e1268 = tmp;

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

    tmp = data_027e1268;

    for (i = 0; i < 2; i++)
    {
        data_027e1268 = (i == 0) ? data_027e0000 : data_027e0004;

        func_0201c204();
        func_01ffa720();
    }

    data_027e1268 = tmp;
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

    func_0201018c();
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

#define REG_DIVCNT *((vu16 *)0x04000280)

EC void func_0200f0f0(void)
{
    AbstCtrl_04 * tmp;
    u8 auStack_28[0x1C];

    func_020aa610(&auStack_28);

    data_027e125c = 1;

    tmp = data_027e1268;
    data_027e1268 = data_027e0000;

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

    data_027e1268 = tmp;
    data_027e125c = 0;

    func_020aa650(&auStack_28);

    while (REG_DIVCNT & 0x8000)
    {
    };

    *(vu32 *)0x027e3ff8 |= 1;

    return;
}

extern u8 data_020e4df4[]; // active overlays
extern u8 data_020ca5cc[];
extern u32 data_020ca5d8[]; // overlay table

EC void func_0200f1e8(void)
{
    int i;

    for (i = 0; i < 12; i++)
    {
        data_020e4df4[i] = 0;
    }

    return;
}

EC void LoadOverlay(u32 overlayId)
{
    if (data_020e4df4[overlayId] != 1)
    {
        if (FS_LoadOverlay(0, data_020ca5d8[overlayId]) == TRUE)
        {
            data_020e4df4[overlayId] = 1;
        }
    }

    return;
}

EC void UnloadOverlay(u32 overlayId)
{
    if (data_020e4df4[overlayId] != 0)
    {
        if (FS_UnloadOverlay(0, data_020ca5d8[overlayId]) == TRUE)
        {
            data_020e4df4[overlayId] = 0;
        }
    }

    return;
}

EC BOOL IsOverlayLoaded(u32);

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
    return data_020e4df4[overlayId];
}

EC void func_0200f318(void);
EC void func_0200f338(void);

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

EC void func_0200f308(void);

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

extern void * data_020e4e00;
extern void * data_020e5200;
extern void * data_020e5600;
extern void * data_020e6000;

extern void * data_027e12f4;
extern void * data_027e16f4;

EC void func_0200f3b8(void)
{
    data_027e1268 = data_027e0000;

    data_027e0000->unk_00 = data_027e0008;
    data_027e0000->unk_1c = 0x06400000; // 2D GFX Engine A OBJ VRAM
    data_027e0000->unk_30 = &data_027e12f4;
    data_027e0000->unk_34 = &data_020e4e00;
    data_027e0000->unk_04 = &data_020e6000;
    func_020a5734(0, data_027e0000->unk_30, 0x400);
    data_027e0000->unk_38 = 0;
    data_027e0000->unk_3a = 0;
    data_027e0000->unk_42 = 0;
    data_027e0000->unk_3c = 0;

    data_027e0004->unk_00 = data_027e000c;
    data_027e0004->unk_1c = 0x06600000; // 2D GFX Engine B OBJ VRAM
    data_027e0004->unk_30 = &data_027e16f4;
    data_027e0004->unk_34 = &data_020e5200;
    data_027e0004->unk_04 = &data_020e5600;
    func_020a5734(0, data_027e0004->unk_30, 0x400);
    data_027e0004->unk_38 = 0;
    data_027e0004->unk_3a = 0;
    data_027e0004->unk_42 = 0;
    data_027e0004->unk_3c = 0;

    return;
}

EC void func_0200f4f0(s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    func_020a3d8c(param_1, param_4);

    if (data_027e1268 == data_027e0000 ? TRUE : FALSE)
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

    if (data_027e1268 == data_027e0000 ? TRUE : FALSE)
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

EC BOOL func_0200f5f0(u32 param_1)
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

extern BgAffineSrcData data_020ca608;

EC void func_0200f630(void)
{
    *(u16 *)&data_027e1268->unk_00->dispcnt = 0;
    *(u16 *)&data_027e1268->unk_00->unk_06[0] = 0;
    *(u16 *)&data_027e1268->unk_00->unk_06[1] = 0;
    *(u16 *)&data_027e1268->unk_00->unk_06[2] = 0;
    *(u16 *)&data_027e1268->unk_00->unk_06[3] = 0;

    data_027e1268->unk_00->dispcnt.unk_02_bit_0 = 0;
    data_027e1268->unk_00->dispcnt.unk_02_bit_4 = 0;

    func_0200fbf0(&data_020ca608, &data_027e1268->unk_00->bg2affin);
    func_0200fbf0(&data_020ca608, &data_027e1268->unk_00->bg3affin);

    return;
}

EC void func_0200f700(void)
{
    data_027e1268->unk_00->dispcnt.bg0_on = 0;
    data_027e1268->unk_00->dispcnt.bg1_on = 0;
    data_027e1268->unk_00->dispcnt.bg2_on = 0;
    data_027e1268->unk_00->dispcnt.bg3_on = 0;
    data_027e1268->unk_00->dispcnt.obj_on = 0;

    *(u16 *)&data_027e1268->unk_00->unk_06[0] = 0;
    *(u16 *)&data_027e1268->unk_00->unk_06[1] = 0;
    *(u16 *)&data_027e1268->unk_00->unk_06[2] = 0;
    *(u16 *)&data_027e1268->unk_00->unk_06[3] = 0;

    data_027e1268->unk_00->dispcnt.unk_02_bit_0 = 0;
    data_027e1268->unk_00->dispcnt.unk_02_bit_4 = 0;

    func_0200fbf0(&data_020ca608, &data_027e1268->unk_00->bg2affin);
    func_0200fbf0(&data_020ca608, &data_027e1268->unk_00->bg3affin);

    return;
}

EC void func_0200f864(void)
{
    data_027e1268->unk_00->unk_38[0] = 0;
    data_027e1268->unk_00->unk_40[0] = 0;

    data_027e1268->unk_00->unk_38[1] = 0;
    data_027e1268->unk_00->unk_40[1] = 0;

    data_027e1268->unk_00->unk_38[2] = 0;
    data_027e1268->unk_00->unk_40[2] = 0;

    data_027e1268->unk_00->unk_38[3] = 0;
    data_027e1268->unk_00->unk_40[3] = 0;

    return;
}

EC void func_0200f8d4(void)
{
    *(u16 *)&data_027e1268->unk_00->bldcnt = 0;

    data_027e1268->unk_00->bldcnt.effect = 0;
    data_027e1268->unk_00->blend_coeff_a = 0;
    data_027e1268->unk_00->blend_coeff_b = 0;
    data_027e1268->unk_00->blend_y = 0;

    data_027e1268->unk_00->bldcnt.target1_bg0_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bg1_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bg2_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bg3_on = 0;
    data_027e1268->unk_00->bldcnt.target1_obj_on = 0;
    data_027e1268->unk_00->bldcnt.target1_bd_on = 0;

    data_027e1268->unk_00->bldcnt.target2_bg0_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bg1_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bg2_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bg3_on = 0;
    data_027e1268->unk_00->bldcnt.target2_obj_on = 0;
    data_027e1268->unk_00->bldcnt.target2_bd_on = 0;

    return;
}

EC void func_0200faf8(void)
{
    *(u16 *)&data_027e1268->unk_00->winincnt = 0;
    *(u16 *)&data_027e1268->unk_00->winoutcnt = 0;

    data_027e1268->unk_00->dispcnt.win0_on = 0;
    data_027e1268->unk_00->dispcnt.win1_on = 0;
    data_027e1268->unk_00->dispcnt.objWin_on = 0;

    data_027e1268->unk_00->unk_48 = 0;
    data_027e1268->unk_00->unk_4a = 0;

    data_027e1268->unk_00->unk_49 = 0;
    data_027e1268->unk_00->unk_4b = 0;

    data_027e1268->unk_00->unk_4c = 0;
    data_027e1268->unk_00->unk_4e = 0;

    data_027e1268->unk_00->unk_4d = 0;
    data_027e1268->unk_00->unk_4f = 0;

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
    AbstCtrl_04 * puVar1;
    s32 i;

    data_027e0008->unk_34 = 1;

    data_027e0008->dispstat.vblankFlag = 1;
    data_027e0008->dispstat.hblankFlag = 0;
    data_027e0008->dispstat.vcountFlag = 0;

    data_027e1268->unk_00->dispcnt.bit_12 = 0;
    data_027e1268->unk_00->dispcnt.bit_13_14 = 0;

    puVar1 = data_027e1268;

    for (i = 0; i < 2; i++)
    {
        data_027e1268 = i == 0 ? data_027e0000 : data_027e0004;

        func_0200f630();
        func_0200f864();
        func_0200f8d4();
        func_0200faf8();

        data_027e1268->unk_00->unk_50 = 0;
    }

    data_027e1268 = puVar1;

    return;
}

// #func_0200fdd8

// #func_0200ff50

struct UnkStruct_020ca61c_00
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
};

struct UnkStruct_020ca61c_04
{
    STRUCT_PAD(0x00, 0x10);
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
};

extern struct UnkStruct_020ca61c_00 * data_020ca61c;
extern struct UnkStruct_020ca61c_04 * data_020ca620;

EC void func_020100ac(void)
{
    data_020ca61c->unk_06 = data_020ca61c->unk_04 = data_020ca61c->unk_00 = data_020ca61c->unk_02 = 0;
    data_020ca61c->unk_08 = 10;
    data_020ca61c->unk_0a = 0x30C;

    return;
}

EC void func_02010100(void)
{
    if (!(data_020ca61c->unk_00 & 0x30c))
    {
        return;
    }

    if (data_020ca61c->unk_04 != 0x30c)
    {
        return;
    }

    if (data_020ca61c->unk_04 == data_020ca61c->unk_0a)
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

struct UnkStruct_020eea00
{
    u32 unk_00;
    STRUCT_PAD(0x04, 0x08);
    u32 unk_08;
};

extern struct UnkStruct_020eea00 data_020eea00;

#define REG_KEYINPUT (*(vu16 *)0x04000130)

#define BIOS_EXTRA_BUTTONS *(vu16 *)0x027FFFA8

#define INPUT_MASK_DPAD 0x00F0
#define INPUT_MASK_ABXY 0x2F0F
#define INPUT_MASK_ALLBTNS 0x2FFF
#define INPUT_MASK_HINGE 0x8000

EC void func_0201018c(void)
{
    data_020ca61c->unk_06 = data_020ca61c->unk_04;

    if (data_020eea00.unk_00 != 0)
    {
        data_020ca61c->unk_04 = 0;
    }
    else
    {
        data_020ca61c->unk_04 = (((REG_KEYINPUT | BIOS_EXTRA_BUTTONS) ^ INPUT_MASK_ALLBTNS) & INPUT_MASK_ALLBTNS);
    }

    if ((data_020ca61c->unk_04 & 0x20) && (data_020ca61c->unk_04 & 0x10))
    {
        data_020ca61c->unk_04 &= ~0x30;
    }

    if ((data_020ca61c->unk_04 & 0x40) && (data_020ca61c->unk_04 & 0x80))
    {
        data_020ca61c->unk_04 &= ~0xC0;
    }

    data_020ca61c->unk_00 = (data_020ca61c->unk_04 & (data_020ca61c->unk_04 ^ data_020ca61c->unk_06));
    data_020ca61c->unk_02 = data_020ca61c->unk_00;

    if ((data_020ca61c->unk_04 != 0) && (data_020ca61c->unk_04 == (data_020ca61c->unk_04 & data_020ca61c->unk_06)))
    {
        data_020ca61c->unk_08--;

        if (data_020ca61c->unk_08 == 0)
        {
            data_020ca61c->unk_02 = data_020ca61c->unk_04;
            data_020ca61c->unk_08 = 4;
        }
    }
    else
    {
        data_020ca61c->unk_08 = 10;
    }

    func_02010100();

    data_020ca61c->unk_0a = data_020ca61c->unk_04;

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

    data_020ca620->unk_12 = 0;
    data_020ca620->unk_13 = 0;
    data_020ca620->unk_14 = 0;
    data_020ca620->unk_15 = 0;
    data_020ca620->unk_10 = 0;
    data_020ca620->unk_11 = 10;

    return;
}
