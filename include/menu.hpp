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

    MENU_ENABLED = 0,
    MENU_DISABLED = 1,
    MENU_NOTSHOWN = 2,

    MENU_ACTIVE = 8,
};

class ProcMenu;
class MenuItem;
class MenuItemState;

class Menu
{
public:
    // vtable
    Menu * unk_04; // parent?
    MenuItem ** unk_08; // menu items?
    MenuItemState * unk_0c;
    ProcMenu * unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    s8 unk_34;
    s8 unk_35;
    s8 unk_36;
    s8 unk_37;
    s8 unk_38;
    s8 unk_39;
    u8 unk_3a;
    u8 unk_3b;
    u8 unk_3c;
    s8 unk_3d;
    u8 unk_3e;
    u8 unk_3f;
    u8 unk_40;
    u8 unk_41;
    u8 unk_42;
    u8 unk_43;
    u8 unk_44;
    u8 unk_45;
    u8 unk_46;
    u8 unk_47;
    u8 unk_48;
    u8 unk_49;
    s8 unk_4a[4];
    STRUCT_PAD(0x4E, 0x50);

    Menu(); // func_0202d4c4

    virtual void vfunc_00(void); // ?
    virtual void vfunc_04(/* ? */); // func_02015368
    virtual void vfunc_08(void); // func_0202f2a4
    virtual void vfunc_0c(void); // func_0202f34c
    virtual void vfunc_10(void); // func_0202f468
    virtual void vfunc_14(void); // func_0202f490
    virtual void vfunc_18(void); // func_0202f504
    virtual void vfunc_1c(void); // func_0202f57c
    virtual void vfunc_20(/* ? */); // func_02015360
    virtual s32 vfunc_24(MenuItemState *, s32); // ?
    virtual s32 vfunc_28(void); // ?
    virtual s32 vfunc_2c(MenuItemState *, s32); // func_02015328
    virtual void vfunc_30(/* ? */); // func_02015308
    virtual s32 vfunc_34(MenuItemState *, s32); // func_02015310
    virtual void vfunc_38(/* ? */); // func_020152e8
    virtual s32 vfunc_3c(MenuItemState *, s32); // func_020152f0
    virtual void vfunc_40(/* ? */); // func_020152c8
    virtual s32 vfunc_44(MenuItemState *, s32); // func_020152d0
    virtual void vfunc_48(/* ? */); // func_020152a8
    virtual s32 vfunc_4c(MenuItemState *, s32); // func_020152b0
    virtual void vfunc_50(/* ? */); // func_02015288
    virtual s32 vfunc_54(MenuItemState *, s32); // func_02015290
    virtual s32 vfunc_58(s32); // ?
    virtual void vfunc_5c(/* ? */); // func_02015270
    virtual s32 vfunc_60(void); // func_02015250
    virtual void vfunc_64(/* ? */); // func_0202ddec
    virtual void vfunc_68(s32); // func_0202e7a4
    virtual void vfunc_6c(s32); // func_0202e874
    virtual void vfunc_70(s32); // func_0202e94c
    virtual void vfunc_74(s32); // func_0202e9d8
    virtual s32 vfunc_78(void); // func_0202daf4
    virtual s32 vfunc_7c(void); // func_0202db5c
    virtual s32 vfunc_80(void); // func_0202dbc4
    virtual s32 vfunc_84(void); // func_0202dc2c
    virtual s32 vfunc_88(void); // func_0202dc94
    virtual s32 vfunc_8c(void); // func_0202dcfc
    virtual s32 vfunc_90(void); // func_0202dd84
    virtual s32 vfunc_94(s32, s32); // func_02015248
    virtual s32 vfunc_98(s32, s32); // func_02015240
    virtual BOOL vfunc_9c(void); // func_02015238
    virtual BOOL vfunc_a0(void); // ?
    virtual BOOL vfunc_a4(void); // func_02015228
    virtual BOOL vfunc_a8(void); // ?
    virtual s32 vfunc_ac(void); // func_02015218
    virtual BOOL vfunc_b0(MenuItemState *, s32, s32); // func_0202e6dc
    virtual BOOL vfunc_b4(void); // func_0202e734
    virtual void vfunc_b8(s32); // func_02015214
    virtual void vfunc_bc(void); // func_0202e60c
    virtual void vfunc_c0(void); // func_0202e640
    virtual void vfunc_c4(void); // func_0202e674
    virtual void vfunc_c8(void); // func_0202e6a8
    virtual s32 vfunc_cc(void); // func_0202ebe8
    virtual void vfunc_d0(s32); // func_0202ebf0
    virtual s32 vfunc_d4(s32); // func_0202ebf8
    virtual void vfunc_d8(void); // func_0202ea68
    virtual void vfunc_dc(void); // func_0202eb2c
    virtual void vfunc_e0(/* ? */); // func_02015210
    virtual void vfunc_e4(/* ? */); // func_0201520c
    virtual void vfunc_e8(void); // func_0202ec90
    virtual void vfunc_ec(void); // func_0202edec
    virtual void vfunc_f0(s32, s32, s32, s32); // func_0202ec44
    virtual void vfunc_f4(s32, s32, s32, s32); // func_0202edc0
    virtual void vfunc_f8(void *, s32, s32, s32, s32); // func_0202eef0
    virtual void vfunc_fc(s32, s32, s32, s32); // func_0202eeac
    virtual void vfunc_100(s32, s32, s32, s32); // func_0202ef38
    virtual void vfunc_104(void *, s32, s32, s32, s32); // func_0202efc0
    virtual void vfunc_108(s32, s32, s32, s32); // func_0202ef7c
    virtual s32 vfunc_10c(void); // func_0202effc
    virtual void vfunc_110(/* ? */); // func_0202f008
    virtual void vfunc_114(/* ? */); // func_02028068
    virtual void vfunc_118(/* ? */); // func_0202f2a0
    virtual void vfunc_11c(void); // func_0202f5b4
    virtual void vfunc_120(void); // func_0202f604
    virtual void vfunc_124(void); // func_0202f800
    virtual void vfunc_128(void); // func_0202fa1c
    virtual void vfunc_12c(void); // func_0202f89c
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
    virtual char * vfunc_04(MenuItemState *); // func_0201511c; wraps vfunc_00
    virtual void vfunc_08(/*  */); // func_020150f8
    virtual void vfunc_0c(/*  */); // func_02015100; wraps vfunc_08
    virtual s32
    vfunc_10(MenuItemState *); // func_0202d948; GetLabelColor? (1 = White, 2 = Grey, 3 = Cyan, 4 = Gold, 5 = Green)
    virtual s32 vfunc_14(void); // func_020150dc; IsEnabled?
    virtual s32 vfunc_18(s32); // func_020150e4; Wraps vfunc_14
    virtual s32 vfunc_1c(void); // func_020150bc; OnConfirm?
    virtual s32 vfunc_20(MenuItemState *); // func_020150a8; OnConfirm? void *
    virtual s32 vfunc_24(Menu *, MenuItemState *); // func_020150c4; OnConfirm? Menu *, void *
    virtual s32 vfunc_28(/*  */); // func_02015074; OnBPress
    virtual s32 vfunc_2c(/*  */); // func_0201507c; OnBPress; wraps vfunc_28
    virtual s32 vfunc_30(Menu *, MenuItemState *); // func_02015090; OnBPress; wraps vfunc_2c
    virtual void vfunc_34(/*  */); // func_02015040; OnXPress
    virtual void vfunc_38(/*  */); // func_02015048; OnXPress
    virtual s32 vfunc_3c(Menu *, MenuItemState *); // func_0201505c; OnXPress
    virtual void vfunc_40(/*  */); // func_0201500c
    virtual void vfunc_44(/*  */); // func_02015014
    virtual s32 vfunc_48(Menu *, MenuItemState *); // func_02015028
    virtual void vfunc_4c(/*  */); // func_02014fd8; OnLPress
    virtual void vfunc_50(/*  */); // func_02014fe0; OnLPress
    virtual s32 vfunc_54(Menu *, MenuItemState *); // func_02014ff4; OnLPress
    virtual void vfunc_58(/*  */); // func_02014fa4; OnRPress
    virtual void vfunc_5c(/*  */); // func_02014fac; OnRPress
    virtual s32 vfunc_60(Menu *, MenuItemState *); // func_02014fc0; OnRPress
    virtual void vfunc_64(/*  */); // func_02014f70; maybe onexit
    virtual void vfunc_68(/*  */); // func_02014f78
    virtual s32 vfunc_6c(Menu *, MenuItemState *); // func_02014f8c
    virtual void vfunc_70(void); // func_02014f40; OnHover? or OnEnter?
    virtual void vfunc_74(/*  */); // func_02014f44; OnHover? void *
    virtual s32 vfunc_78(Menu *, MenuItemState *); // func_02014f58; OnHover? Menu *, void *
    virtual void vfunc_7c(/*  */); // func_02014f10
    virtual void vfunc_80(/*  */); // func_02014f14
    virtual s32 vfunc_84(Menu *, MenuItemState *); // func_02014f28
    virtual void vfunc_88(/*  */); // func_02014ee0
    virtual void vfunc_8c(/*  */); // func_02014ee4
    virtual void vfunc_90(Menu *, MenuItemState *); // func_02014ef8
    virtual void vfunc_94(/*  */); // func_02014eb0
    virtual void vfunc_98(/*  */); // func_02014eb4
    virtual void vfunc_9c(Menu *, MenuItemState *); // func_02014ec8
    virtual void vfunc_a0(/*  */); // func_02014e98
    virtual void vfunc_a4(/*  */); // func_02014e9c
    virtual void vfunc_a8(Menu *, MenuItemState *); //
    virtual s32 vfunc_ac(MenuItemState *, s32, s32, s32, s32); // func_0202d78c
    virtual void vfunc_b0(Menu *, MenuItemState *); // func_02014e94
    virtual void vfunc_b4(Menu *, MenuItemState *); // func_0202d960
    virtual void vfunc_b8(Menu *, MenuItemState *); // func_0202d9bc
    virtual void vfunc_bc(Menu *, MenuItemState *); // func_0202da18
    virtual void vfunc_c0(Menu *, MenuItemState *); // func_0202da74
    virtual u32 vfunc_c4(void); // func_02014e8c
    virtual u32 vfunc_c8(MenuItemState *); // func_0202d8c8
    virtual u32 vfunc_cc(void); // func_02014e84
    virtual u32 vfunc_d0(void); // func_02014e7c
    virtual u32 vfunc_d4(void); // func_02014e74
};

class MenuItemState
{
public:
    MenuItem * unk_00;
    s8 unk_04;
    s8 unk_05;
    s8 unk_06;
    s8 unk_07;
    u8 unk_08;
    u8 unk_09;
    STRUCT_PAD(0x0A, 0x0C);
};

class SplitMenu : public Menu
{
public:
    virtual void vfunc_08(void); // func_0203004c
    virtual void vfunc_0c(void); // func_020300ec
    virtual BOOL vfunc_b0(MenuItemState *, s32, s32); // func_0202fffc

    // func_020302dc
    virtual void vfunc_e8(void)
    {
    }

    // func_020302d8
    virtual void vfunc_ec(void)
    {
    }

    // func_020302d4
    virtual void vfunc_fc(s32, s32, s32, s32)
    {
    }

    // func_020302d0
    virtual void vfunc_100(s32, s32, s32, s32)
    {
    }

    // func_020302cc
    virtual void vfunc_108(s32, s32, s32, s32)
    {
    }
};

EC void func_0202f674(Menu *);
EC void func_0202f7d0(Menu *);

class ProcMenu : public ProcEx
{
public:
    Menu * unk_38;
    u8 unk_3c;

    ProcMenu(Menu * menu)
    {
        this->unk_38 = menu;
        this->unk_3c = 0;
    }

    // func_020301f4
    // func_02030264
    virtual ~ProcMenu()
    {
        if (this->unk_3c == 0)
        {
            func_0202f7d0(this->unk_38);
        }

        this->unk_38->vfunc_dc();
        this->unk_38->vfunc_ec();

        if (this->unk_38 != NULL)
        {
            this->unk_38->vfunc_134();
        }
    }

    inline void func_0202d688()
    {
        this->unk_38->vfunc_e0();
        this->unk_38->vfunc_d8();

        func_0202f674(this->unk_38);

        return;
    }
};

class DialogBase : public Menu
{
public:
    void * unk_50;

    DialogBase()
    {
        this->unk_50 = NULL;
    }

    // func_02030ed0
    // func_02030e8c
    virtual ~DialogBase()
    {
        if (this->unk_50 != NULL)
        {
            gHeap.Free(this->unk_50);
        }
    }
};

class Dialog : public DialogBase
{
public:
    u32 unk_54;

    // func_020302e0
    Dialog();

    // func_02030e0c
    // func_02030e50
    virtual ~Dialog()
    {
    }

    virtual void vfunc_128(void); // func_02030330
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