#ifndef MENU_HPP
#define MENU_HPP

#include "global.h"

#include "proc_ex.hpp"

enum
{
    MENU_COLOR_WHITE = 1,
    MENU_COLOR_GRAY = 2,
    MENU_COLOR_BLUE = 3,
    MENU_COLOR_GOLD = 4,
    MENU_COLOR_GREEN = 5,
};

enum
{
    // Menu availability identifiers

    MENU_ENABLED  = 0,
    MENU_DISABLED = 1,
    MENU_NOTSHOWN = 2,

    MENU_ACTIVE   = 8,
};

class MenuItemState;

class Menu
{
public:
    // vtable
    STRUCT_PAD(0x04, 0x0C);
    MenuItemState * unk_0c;
    ProcEx * unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
    s8 unk_38;
    STRUCT_PAD(0x39, 0x40);
    u8 unk_40;
    u8 unk_41;
    u8 unk_42;
    u8 unk_43;
    STRUCT_PAD(0x44, 0x48);
    u8 unk_48;
    STRUCT_PAD(0x49, 0x50);

    Menu(); // func_0202d4c4

    virtual void vfunc_00(void); // ?
    virtual void vfunc_04(/* ? */); // func_02015368
    virtual void vfunc_08(/* ? */); // func_0202f2a4
    virtual void vfunc_0c(/* ? */); // func_0202f34c
    virtual void vfunc_10(/* ? */); // func_0202f468
    virtual void vfunc_14(/* ? */); // func_0202f490
    virtual void vfunc_18(/* ? */); // func_0202f504
    virtual void vfunc_1c(/* ? */); // func_0202f57c
    virtual void vfunc_20(/* ? */); // func_02015360
    virtual s32 vfunc_24(void *, s32); // ?
    virtual s32 vfunc_28(void); // ?
    virtual void vfunc_2c(/* ? */); // func_02015328
    virtual void vfunc_30(/* ? */); // func_02015308
    virtual void vfunc_34(/* ? */); // func_02015310
    virtual void vfunc_38(/* ? */); // func_020152e8
    virtual void vfunc_3c(/* ? */); // func_020152f0
    virtual void vfunc_40(/* ? */); // func_020152c8
    virtual void vfunc_44(/* ? */); // func_020152d0
    virtual void vfunc_48(/* ? */); // func_020152a8
    virtual void vfunc_4c(/* ? */); // func_020152b0
    virtual void vfunc_50(/* ? */); // func_02015288
    virtual void vfunc_54(/* ? */); // func_02015290
    virtual s32 vfunc_58(void); // ?
    virtual void vfunc_5c(/* ? */); // func_02015270
    virtual void vfunc_60(/* ? */); // func_02015250
    virtual void vfunc_64(/* ? */); // func_0202ddec
    virtual void vfunc_68(/* ? */); // func_0202e7a4
    virtual void vfunc_6c(/* ? */); // func_0202e874
    virtual void vfunc_70(/* ? */); // func_0202e94c
    virtual void vfunc_74(/* ? */); // func_0202e9d8
    virtual void vfunc_78(/* ? */); // func_0202daf4
    virtual void vfunc_7c(/* ? */); // func_0202db5c
    virtual void vfunc_80(/* ? */); // func_0202dbc4
    virtual void vfunc_84(/* ? */); // func_0202dc2c
    virtual void vfunc_88(/* ? */); // func_0202dc94
    virtual void vfunc_8c(/* ? */); // func_0202dcfc
    virtual void vfunc_90(/* ? */); // func_0202dd84
    virtual void vfunc_94(/* ? */); // func_02015248
    virtual void vfunc_98(/* ? */); // func_02015240
    virtual void vfunc_9c(/* ? */); // func_02015238
    virtual void vfunc_a0(void); // ?
    virtual void vfunc_a4(/* ? */); // func_02015228
    virtual void vfunc_a8(void); // ?
    virtual void vfunc_ac(/* ? */); // func_02015218
    virtual void vfunc_b0(/* ? */); // func_0202e6dc
    virtual void vfunc_b4(/* ? */); // func_0202e734
    virtual void vfunc_b8(/* ? */); // func_02015214
    virtual void vfunc_bc(/* ? */); // func_0202e60c
    virtual void vfunc_c0(/* ? */); // func_0202e640
    virtual void vfunc_c4(/* ? */); // func_0202e674
    virtual void vfunc_c8(/* ? */); // func_0202e6a8
    virtual void vfunc_cc(/* ? */); // func_0202ebe8
    virtual void vfunc_d0(/* ? */); // func_0202ebf0
    virtual void vfunc_d4(/* ? */); // func_0202ebf8
    virtual void vfunc_d8(/* ? */); // func_0202ea68
    virtual void vfunc_dc(/* ? */); // func_0202eb2c
    virtual void vfunc_e0(/* ? */); // func_02015210
    virtual void vfunc_e4(/* ? */); // func_0201520c
    virtual void vfunc_e8(void); // ?
    virtual void vfunc_ec(void); // ?
    virtual void vfunc_f0(/* ? */); // func_0202ec44
    virtual void vfunc_f4(/* ? */); // func_0202edc0
    virtual void vfunc_f8(/* ? */); // func_0202eef0
    virtual void vfunc_fc(/* ? */); // func_0202eeac
    virtual void vfunc_100(/* ? */); // func_0202ef38
    virtual void vfunc_104(/* ? */); // func_0202efc0
    virtual void vfunc_108(/* ? */); // func_0202ef7c
    virtual void vfunc_10c(/* ? */); // func_0202effc
    virtual void vfunc_110(/* ? */); // func_0202f008
    virtual void vfunc_114(/* ? */); // func_02028068
    virtual void vfunc_118(/* ? */); // func_0202f2a0
    virtual void vfunc_11c(/* ? */); // func_0202f5b4
    virtual void vfunc_120(void); // ?
    virtual void vfunc_124(void); // ?
    virtual void vfunc_128(/* ? */); // func_0202fa1c
    virtual void vfunc_12c(/* ? */); // func_0202f89c
    virtual void vfunc_130(/* ? */); // ?
    virtual void vfunc_134(/* ? */); // ?

    virtual ~Menu();
};

class MenuState
{
};

class MenuResult
{
};

class MenuItem : public MenuState, public MenuResult
{
public:
    virtual char * vfunc_00(void); // ?; GetLabelText?
    virtual void vfunc_04(/*  */); // func_0201511c; wraps vfunc_00
    virtual void vfunc_08(/*  */); // func_020150f8
    virtual void vfunc_0c(/*  */); // func_02015100; wraps vfunc_08
    virtual s32 vfunc_10(MenuItemState *); // func_0202d948; GetLabelColor? (1 = White, 2 = Grey, 3 = Cyan, 4 = Gold, 5 = Green)
    virtual s32 vfunc_14(void); // func_020150dc; IsEnabled?
    virtual void vfunc_18(/*  */); // func_020150e4; Wraps vfunc_14
    virtual s32 vfunc_1c(void); // func_020150bc; OnConfirm?
    virtual s32 vfunc_20(MenuItemState *); // func_020150a8; OnConfirm? void *
    virtual s32 vfunc_24(Menu *, MenuItemState *); // func_020150c4; OnConfirm? Menu *, void *
    virtual void vfunc_28(/*  */); // func_02015074; OnBPress
    virtual void vfunc_2c(/*  */); // func_0201507c; OnBPress; wraps vfunc_28
    virtual void vfunc_30(/*  */); // func_02015090; OnBPress; wraps vfunc_2c
    virtual void vfunc_34(/*  */); // func_02015040; OnXPress
    virtual void vfunc_38(/*  */); // func_02015048; OnXPress
    virtual void vfunc_3c(/*  */); // func_0201505c; OnXPress
    virtual void vfunc_40(/*  */); // func_0201500c
    virtual void vfunc_44(/*  */); // func_02015014
    virtual void vfunc_48(/*  */); // func_02015028
    virtual void vfunc_4c(/*  */); // func_02014fd8; OnLPress
    virtual void vfunc_50(/*  */); // func_02014fe0; OnLPress
    virtual void vfunc_54(/*  */); // func_02014ff4; OnLPress
    virtual void vfunc_58(/*  */); // func_02014fa4; OnRPress
    virtual void vfunc_5c(/*  */); // func_02014fac; OnRPress
    virtual void vfunc_60(/*  */); // func_02014fc0; OnRPress
    virtual void vfunc_64(/*  */); // func_02014f70; maybe onexit
    virtual void vfunc_68(/*  */); // func_02014f78
    virtual void vfunc_6c(/*  */); // func_02014f8c
    virtual void vfunc_70(void); // func_02014f40; OnHover? or OnEnter?
    virtual void vfunc_74(/*  */); // func_02014f44; OnHover? void *
    virtual void vfunc_78(/*  */); // func_02014f58; OnHover? Menu *, void *
    virtual void vfunc_7c(/*  */); // func_02014f10
    virtual void vfunc_80(/*  */); // func_02014f14
    virtual void vfunc_84(/*  */); // func_02014f28
    virtual void vfunc_88(/*  */); // func_02014ee0
    virtual void vfunc_8c(/*  */); // func_02014ee4
    virtual void vfunc_90(/*  */); // func_02014ef8
    virtual void vfunc_94(/*  */); // func_02014eb0
    virtual void vfunc_98(/*  */); // func_02014eb4
    virtual void vfunc_9c(/*  */); // func_02014ec8
    virtual void vfunc_a0(/*  */); // func_02014e98
    virtual void vfunc_a4(/*  */); // func_02014e9c
    virtual void vfunc_a8(/*  */); //
    virtual void vfunc_ac(/*  */); //
    virtual void vfunc_b0(/*  */); // func_02014e94
    virtual void vfunc_b4(Menu *, MenuItemState *); //
    virtual void vfunc_b8(/*  */); //
    virtual void vfunc_bc(/*  */); //
    virtual void vfunc_c0(/*  */); //
    virtual void vfunc_c4(/*  */); // func_02014e8c
    virtual void vfunc_c8(/*  */); //
    virtual void vfunc_cc(/*  */); // func_02014e84
    virtual void vfunc_d0(/*  */); // func_02014e7c
    virtual void vfunc_d4(/*  */); // func_02014e74
};

class MenuItemState
{
public:
    MenuItem * unk_00;
    void * unk_04;
    u8 unk_08;
    u8 unk_09;
    STRUCT_PAD(0x0A, 0x0C);
};

class DialogBase : public Menu
{
public:
    u32 unk_50;

    DialogBase()
    {
        this->unk_50 = 0;
    }

    virtual ~DialogBase();
};

class Dialog : public DialogBase
{
public:
    Dialog(); // func_020302e0
    virtual ~Dialog();
};

class DialogYesNo : public Dialog
{
public:
    DialogYesNo() {};
    virtual ~DialogYesNo();
};

class DialogItem : public MenuItem
{
};

class DialogItemYes : public DialogItem
{
};

class DialogItemNo : public DialogItem
{
};

#endif // MENU_HPP