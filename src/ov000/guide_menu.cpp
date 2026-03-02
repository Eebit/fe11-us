#include "global.h"

#include "database.hpp"
#include "hardware.hpp"
#include "map.hpp"
#include "menu.hpp"

#include "unknown_funcs.h"
#include "unknown_types.hpp"

namespace menu
{
class ScrollMenu
{
public:
    /* 00 */ // vtable
    /* 04 */ void * unk_04;
    /* 08 */ void * unk_08;
    /* 0C */ u32 unk_0c;
    /* 10 */ void * unk_10;
    /* 14 */ void * unk_14;
    /* 18 */ ProcEx * unk_18;
    /* 1C */ u32 unk_1c;
    /* 20 */ u32 unk_20;
    /* 24 */ u32 unk_24;
    /* 28 */ u32 unk_28;
    /* 2C */ u32 unk_2c;
    /* 30 */ u32 unk_30;
    /* 34 */ u32 unk_34;
    /* 38 */ u32 unk_38;
    /* 3C */ u32 unk_3c;
    /* 40 */ u32 unk_40;
    /* 44 */ u32 unk_44;
    /* 48 */ u32 unk_48;
    /* 4C */ s8 unk_4c;
    /* 4D */ s8 unk_4d;
    /* 4E */ s8 unk_4e;
    /* 4F */ s8 unk_4f;
    /* 50 */ u16 unk_50;
    /* 52 */ u16 unk_52;
    /* 54 */ u16 unk_54;
    /* 56 */ u8 unk_56;
    /* 57 */ u8 unk_57;
    /* 58 */ s8 unk_58;
    STRUCT_PAD(0x59, 0x5C);
    /* 5C */ s8 unk_5c;
    /* 5D */ s8 unk_5d;
    /* 5E */ u8 unk_5e;
    /* 5F */ s8 unk_5f;
    STRUCT_PAD(0x60, 0x61);
    /* 61 */ u8 unk_61;
    /* 62 */ u8 unk_62;
    /* 63 */ u8 unk_63;
    STRUCT_PAD(0x64, 0x6A);
    /* 6A */ s16 unk_6a;
    STRUCT_PAD(0x6C, 0x7B);
    /* 7B */ u8 unk_7b;
    /* 7C */ u8 unk_7c;
    /* 7D */ s8 unk_7d;
    /* 7E */ u8 unk_7e;
    /* 7F */ u8 unk_7f;

    virtual void vfunc_00(/* ? */); // func_020336d4
    virtual void vfunc_04(/* ? */); // func_020337c8
    virtual void vfunc_08(/* ? */); // func_020338fc
    virtual void vfunc_0c(/* ? */); // func_02033990
    virtual void vfunc_10(/* ? */); // func_02003f84
    virtual void vfunc_14(/* ? */); // func_020316a4
    virtual void vfunc_18(/* ? */); // func_02032f14
    virtual s32 vfunc_1c(void); // func_02033b84
    virtual void vfunc_20(/* ? */); // func_02033b8c
    virtual void vfunc_24(/* ? */); // func_02033bd8
    virtual void vfunc_28(/* ? */); // func_02033d0c
    virtual void vfunc_2c(/* ? */); // func_02033df0
    virtual void vfunc_30(/* ? */); // func_02033dac
    virtual void vfunc_34(/* ? */); // func_02033e38
    virtual void vfunc_38(s32, s32, s32, s32, s32); // func_02033ec0
    virtual void vfunc_3c(/* ? */); // func_02033e7c
    virtual s32 vfunc_40(void); // func_02032ff8
    virtual void vfunc_44(/* ? */); // func_02033004
    virtual void vfunc_48(void); // func_02032ff4
    virtual void vfunc_4c(s32); // func_02003f80
    virtual s32 vfunc_50(void); // func_02032fc4
    virtual void vfunc_54(void); // func_02033c20
    virtual void vfunc_58(void); // func_02033d38
    virtual void vfunc_5c(/* ? */); // func_02031c6c
    virtual void vfunc_60(/* ? */); // func_02031ccc
    virtual void vfunc_64(/* ? */); // func_02031d74
    virtual void vfunc_68(/* ? */); // func_02031d2c
    virtual void vfunc_6c(s32); // func_02031dd4
    virtual void vfunc_70(/* ? */); // func_02031dec
    virtual void vfunc_74(/* ? */); // func_02003f60
    virtual void vfunc_78(/* ? */); // func_02003f68
    virtual void vfunc_7c(/* ? */); // func_02003f40
    virtual void vfunc_80(/* ? */); // func_02003f48
    virtual void vfunc_84(/* ? */); // func_02003f20
    virtual void vfunc_88(/* ? */); // func_02003f28
    virtual void vfunc_8c(/* ? */); // func_02003f18
    virtual void vfunc_90(/* ? */); // func_02003ef8
    virtual void vfunc_94(s32, s32); // func_02003f00
    virtual void vfunc_98(/* ? */); // func_02003ed8
    virtual void vfunc_9c(/* ? */); // func_02003ee0
    virtual void vfunc_a0(/* ? */); // func_02003ed0
    virtual void vfunc_a4(/* ? */); // func_02003ea0
    virtual void vfunc_a8(/* ? */); // func_02003e98
    virtual void vfunc_ac(/* ? */); // func_02003e90
    virtual void vfunc_b0(/* ? */); // func_02003e88
    virtual void vfunc_b4(/* ? */); // func_02003e80
    virtual void vfunc_b8(/* ? */); // func_02003e78
    virtual void vfunc_bc(/* ? */); // func_02003e70
    virtual void vfunc_c0(/* ? */); // func_02032800
    virtual void vfunc_c4(/* ? */); // func_0203288c
    virtual void vfunc_c8(/* ? */); // func_02032918
    virtual void vfunc_cc(/* ? */); // func_020329a4
    virtual void vfunc_d0(void); // func_02033aa4
    virtual void vfunc_d4(void); // func_02033b14
    virtual void vfunc_d8(/* ? */); // func_02032c00
    virtual void vfunc_dc(/* ? */); // func_02003e6c
    virtual void vfunc_e0(/* ? */); // func_02032e98
    virtual void vfunc_e4(/* ? */); // func_02031040
    virtual void vfunc_e8(void); // func_02033efc
    virtual void vfunc_ec(/* ? */); // func_02030fb4
    virtual void vfunc_f0(); // func_02031044
    virtual ~ScrollMenu();

    ScrollMenu();
    void func_02031944();
};

class ScrollMenuItem
{
public:
    virtual char * vfunc_00(s32); // func_020340d8
    virtual s32 vfunc_04(void); // func_0205b454
    virtual s32 vfunc_08(void); // func_0205b464
    virtual void vfunc_0c(/* ? */); // func_0205b45c
    virtual void vfunc_10(s32, s32, s32, s32, s32, s32, s32); // func_02034054
    virtual void vfunc_14(/* ? */); // func_0205b46c
    virtual void vfunc_18(/* ? */); // func_02031cc4
    virtual s32 vfunc_1c(s32, s32); // func_0205ae94
    virtual s32 vfunc_20(s32); // func_02031d24
    virtual s32 vfunc_24(s32, s32); // func_02031d0c
    virtual s32 vfunc_28(s32); // func_02031dcc
    virtual s32 vfunc_2c(s32, s32); // func_02031db4
    virtual void vfunc_30(/* ? */); // func_02031d6c
    virtual void vfunc_34(/* ? */); // func_0205af88
    virtual void vfunc_38(/* ? */); // func_0203127c
    virtual void vfunc_3c(/* ? */); // func_0205af00
    virtual void vfunc_40(/* ? */); // func_020311ec
    virtual void vfunc_44(/* ? */); // func_020327fc
    virtual s32 vfunc_48(s32); // func_0205aef8
    virtual s32 vfunc_4c(s32, s32); // func_020340e0
};
} // namespace menu

namespace map
{
class BMapScrollMenu : public menu::ScrollMenu
{
public:
    // 10 func_ov000_021be768
    // AC func_ov000_021be8f0
    // BC func_ov000_021be8d8

    BMapScrollMenu()
    {
        gpActiveScreenSt->dispIo->bldcnt.effect = 1;

        gpActiveScreenSt->dispIo->blend_coeff_a = 0xe;
        gpActiveScreenSt->dispIo->blend_coeff_b = 2;

        gpActiveScreenSt->dispIo->bldcnt.target1_bg0_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_bg1_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_bg2_on = 1;
        gpActiveScreenSt->dispIo->bldcnt.target1_bg3_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_obj_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_bd_on = 0;

        gpActiveScreenSt->dispIo->bldcnt.target2_bg0_on = 1;
        gpActiveScreenSt->dispIo->bldcnt.target2_bg1_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_bg2_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_bg3_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_obj_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_bd_on = 1;
    }

    virtual ~BMapScrollMenu()
    {
        gpActiveScreenSt->dispIo->bldcnt.effect = 0;
    }
};
} // namespace map

class TutListMenu : public map::BMapScrollMenu
{
public:
    /* 4C */ void vfunc_4c(s32); // func_ov000_021c6a64

    // d1 func_ov000_021c6be4
    // d0 func_ov000_021c6c38
};

class TutListMenuItem : public menu::ScrollMenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(s32); // func_ov000_021c6a1c
    /* 04 */ virtual s32 vfunc_04(void); // func_ov000_021c6a44
    /* 08 */ virtual s32 vfunc_08(void); // func_ov000_021c6a5c
    /* 10 */ virtual void vfunc_10(s32, s32, s32, s32, s32, s32, s32); // func_ov000_021c6994
    /* 1C */ virtual s32 vfunc_1c(s32, s32); // func_ov000_021c692c
    /* 48 */ virtual s32 vfunc_48(s32); // func_ov000_021c696c
};

EC void func_02031594(menu::ScrollMenu *, menu::ScrollMenuItem **, s32, s32, s32, ProcPtr, s32);

EC void func_ov000_021c669c(ProcPtr parent)
{
    static TutListMenuItem sTutListMenuItem;

    // clang-format off
    static menu::ScrollMenuItem * data_ov000_021e34e0[] =
    {
        &sTutListMenuItem,
    };
    // clang-format on

    func_02031594(new TutListMenu(), data_ov000_021e34e0, 0x22, 1, 8, parent, 1);

    return;
}

extern struct UnkStruct_02196f20 * data_02196f20;

EC BOOL func_0204b1e0(void);
EC BOOL func_02050304(s32);

// func_ov000_021c692c
s32 TutListMenuItem::vfunc_1c(s32 param_2, s32 param_3)
{
    if (func_0204b1e0())
    {
        return 0;
    }

    if (func_02050304(param_3))
    {
        return 0;
    }

    func_0205038c(param_3, -1);
    return 0x40;
}

// func_ov000_021c696c
s32 TutListMenuItem::vfunc_48(s32 arg1)
{
    if (!data_02196f20->flagMgr->GetById(arg1))
    {
        return MENU_NOTSHOWN;
    }

    return MENU_ENABLED;
}

struct UnkStruct_021970c4
{
    void * unk_00;
    void * unk_04;
    void * unk_08;
};

extern struct UnkStruct_021970c4 * data_021970c4;

EC s32 func_020295ec(struct UnkStruct_021970c4 *, char *, void *, void *, u32, u32, u32, u32, u32, u32);

// func_ov000_021c6994
void TutListMenuItem::vfunc_10(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    char * str = this->vfunc_00(arg1);

    if (str == NULL)
    {
        return;
    }

    func_020295ec(data_021970c4, str, gpActiveScreenSt->bgTiles[arg2], (void *)arg3, arg4 + 1, arg5, arg6, arg7, 0, 0);

    return;
}

// func_ov000_021c6a1c
char * TutListMenuItem::vfunc_00(s32 param_2)
{
    return func_02039e10(gFE11Database->unk_3c[param_2].unk_00);
}

// func_ov000_021c6a44
s32 TutListMenuItem::vfunc_04(void)
{
    return this->vfunc_08() << 1;
}

// func_ov000_021c6a5c
s32 TutListMenuItem::vfunc_08(void)
{
    return 0x10;
}

// func_ov000_021c6a64
void TutListMenu::vfunc_4c(s32 param_2)
{
    gMapStateManager->unk_14->unk_25 = Interpolate(0, 0, -16, param_2, 4);
    return;
}
