#ifndef MENU_HPP
#define MENU_HPP

#include "global.h"

#include "heap.hpp"
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

    Menu();

    /* 000 */ virtual void vfunc_00(void); // func_0202806c
    /* 004 */ virtual void vfunc_04(void); // func_02015368
    /* 008 */ virtual void vfunc_08(void);
    /* 00C */ virtual void vfunc_0c(void);
    /* 010 */ virtual void vfunc_10(void);
    /* 014 */ virtual void vfunc_14(void);
    /* 018 */ virtual void vfunc_18(void);
    /* 01C */ virtual void vfunc_1c(void);
    /* 020 */ virtual s32 vfunc_20(s32); // func_02015360
    /* 024 */ virtual s32 vfunc_24(MenuItemState *, s32); // func_02015348
    /* 028 */ virtual s32 vfunc_28(s32); // func_02015340
    /* 02C */ virtual s32 vfunc_2c(MenuItemState *, s32); // func_02015328
    /* 030 */ virtual s32 vfunc_30(s32); // func_02015308
    /* 034 */ virtual s32 vfunc_34(MenuItemState *, s32); // func_02015310
    /* 038 */ virtual s32 vfunc_38(s32); // func_020152e8
    /* 03C */ virtual s32 vfunc_3c(MenuItemState *, s32); // func_020152f0
    /* 040 */ virtual s32 vfunc_40(s32); // func_020152c8
    /* 044 */ virtual s32 vfunc_44(MenuItemState *, s32); // func_020152d0
    /* 048 */ virtual s32 vfunc_48(s32); // func_020152a8
    /* 04C */ virtual s32 vfunc_4c(MenuItemState *, s32); // func_020152b0
    /* 050 */ virtual s32 vfunc_50(s32); // func_02015288
    /* 054 */ virtual s32 vfunc_54(MenuItemState *, s32); // func_02015290
    /* 058 */ virtual s32 vfunc_58(s32); // func_02015268
    /* 05C */ virtual s32 vfunc_5c(MenuItemState *, s32); // func_02015270
    /* 060 */ virtual s32 vfunc_60(void); // func_02015250
    /* 064 */ virtual void vfunc_64(void);
    /* 068 */ virtual void vfunc_68(s32);
    /* 06C */ virtual void vfunc_6c(s32);
    /* 070 */ virtual void vfunc_70(s32);
    /* 074 */ virtual void vfunc_74(s32);
    /* 078 */ virtual s32 vfunc_78(void);
    /* 07C */ virtual s32 vfunc_7c(void);
    /* 080 */ virtual s32 vfunc_80(void);
    /* 084 */ virtual s32 vfunc_84(void);
    /* 088 */ virtual s32 vfunc_88(void);
    /* 08C */ virtual s32 vfunc_8c(void);
    /* 090 */ virtual s32 vfunc_90(void);
    /* 094 */ virtual s32 vfunc_94(s32, s32); // func_02015248
    /* 098 */ virtual s32 vfunc_98(s32, s32); // func_02015240
    /* 09C */ virtual BOOL vfunc_9c(void); // func_02015238
    /* 0A0 */ virtual BOOL vfunc_a0(void); // func_02015230
    /* 0A4 */ virtual BOOL vfunc_a4(void); // func_02015228
    /* 0A8 */ virtual BOOL vfunc_a8(void); // func_02015220
    /* 0AC */ virtual s32 vfunc_ac(void); // func_02015218
    /* 0B0 */ virtual BOOL vfunc_b0(MenuItemState *, s32, s32);
    /* 0B4 */ virtual BOOL vfunc_b4(void);
    /* 0B8 */ virtual void vfunc_b8(s32); // func_02015214
    /* 0BC */ virtual void vfunc_bc(void);
    /* 0C0 */ virtual void vfunc_c0(void);
    /* 0C4 */ virtual void vfunc_c4(void);
    /* 0C8 */ virtual void vfunc_c8(void);
    /* 0CC */ virtual s32 vfunc_cc(void);
    /* 0D0 */ virtual void vfunc_d0(s32);
    /* 0D4 */ virtual s32 vfunc_d4(s32);
    /* 0D8 */ virtual void vfunc_d8(void);
    /* 0DC */ virtual void vfunc_dc(void);
    /* 0E0 */ virtual void vfunc_e0(void); // func_02015210
    /* 0E4 */ virtual void vfunc_e4(void); // func_0201520c
    /* 0E8 */ virtual void vfunc_e8(void);
    /* 0EC */ virtual void vfunc_ec(void);
    /* 0F0 */ virtual void vfunc_f0(s32, s32, s32, s32);
    /* 0F4 */ virtual void vfunc_f4(s32, s32, s32, s32);
    /* 0F8 */ virtual void vfunc_f8(void *, s32, s32, s32, s32);
    /* 0FC */ virtual void vfunc_fc(s32, s32, s32, s32);
    /* 100 */ virtual void vfunc_100(s32, s32, s32, s32);
    /* 104 */ virtual void vfunc_104(void *, s32, s32, s32, s32);
    /* 108 */ virtual void vfunc_108(s32, s32, s32, s32);
    /* 10C */ virtual s32 vfunc_10c(void);
    /* 110 */ virtual void vfunc_110(void);
    /* 114 */ virtual void vfunc_114(void); // func_02028068
    /* 118 */ virtual void vfunc_118(void);
    /* 11C */ virtual void vfunc_11c(void);
    /* 120 */ virtual void vfunc_120(void);
    /* 124 */ virtual void vfunc_124(void);
    /* 128 */ virtual void vfunc_128(void);
    /* 12C */ virtual void vfunc_12c(void);
    /* 130 */ virtual void vfunc_130(/* ? */); // ?
    /* 134 */ virtual void vfunc_134(/* ? */); // ?

    virtual ~Menu();

    void _0202d6fc(s32);
    void _0202f020(s32, s32);
    void _0202f030(s32, s32);
    void _0202f040(s32, s32, s32);
    void _0202f674(void);
    void _0202f6d0(void);
    void _0202f72c(void);
    void _0202f7d0(void);
    s32 _0202f860(void);
    void _0202f8c4(void);
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
    virtual char * vfunc_00(void); // func_02015114; GetLabelText?
    virtual char * vfunc_04(MenuItemState *); // func_0201511c; wraps vfunc_00
    virtual s32 vfunc_08(void); // func_020150f8
    virtual s32 vfunc_0c(MenuItemState *); // func_02015100; wraps vfunc_08
    virtual s32 vfunc_10(MenuItemState *); // GetLabelColor? (1 = White, 2 = Grey, 3 = Cyan, 4 = Gold, 5 = Green)
    virtual s32 vfunc_14(void); // func_020150dc; IsEnabled?
    virtual s32 vfunc_18(s32); // func_020150e4; Wraps vfunc_14
    virtual s32 vfunc_1c(void); // func_020150bc; OnConfirm?
    virtual s32 vfunc_20(MenuItemState *); // func_020150a8; OnConfirm? void *
    virtual s32 vfunc_24(Menu *, MenuItemState *); // func_020150c4; OnConfirm? Menu *, void *
    virtual s32 vfunc_28(void); // func_02015074; OnBPress
    virtual s32 vfunc_2c(MenuItemState *); // func_0201507c; OnBPress; wraps vfunc_28
    virtual s32 vfunc_30(Menu *, MenuItemState *); // func_02015090; OnBPress; wraps vfunc_2c
    virtual s32 vfunc_34(void); // func_02015040; OnXPress
    virtual s32 vfunc_38(MenuItemState *); // func_02015048; OnXPress
    virtual s32 vfunc_3c(Menu *, MenuItemState *); // func_0201505c; OnXPress
    virtual s32 vfunc_40(void); // func_0201500c
    virtual s32 vfunc_44(MenuItemState *); // func_02015014
    virtual s32 vfunc_48(Menu *, MenuItemState *); // func_02015028
    virtual s32 vfunc_4c(void); // func_02014fd8; OnLPress
    virtual s32 vfunc_50(MenuItemState *); // func_02014fe0; OnLPress
    virtual s32 vfunc_54(Menu *, MenuItemState *); // func_02014ff4; OnLPress
    virtual s32 vfunc_58(void); // func_02014fa4; OnRPress
    virtual s32 vfunc_5c(MenuItemState *); // func_02014fac; OnRPress
    virtual s32 vfunc_60(Menu *, MenuItemState *); // func_02014fc0; OnRPress
    virtual s32 vfunc_64(void); // func_02014f70; maybe onexit
    virtual s32 vfunc_68(MenuItemState *); // func_02014f78
    virtual s32 vfunc_6c(Menu *, MenuItemState *); // func_02014f8c
    virtual void vfunc_70(void); // func_02014f40; OnHover? or OnEnter?
    virtual void vfunc_74(MenuItemState *); // func_02014f44; OnHover? void *
    virtual void vfunc_78(Menu *, MenuItemState *); // func_02014f58; OnHover? Menu *, void *
    virtual void vfunc_7c(void); // func_02014f10
    virtual void vfunc_80(MenuItemState *); // func_02014f14
    virtual void vfunc_84(Menu *, MenuItemState *); // func_02014f28
    virtual void vfunc_88(void); // func_02014ee0
    virtual void vfunc_8c(MenuItemState *); // func_02014ee4
    virtual void vfunc_90(Menu *, MenuItemState *); // func_02014ef8
    virtual void vfunc_94(void); // func_02014eb0
    virtual void vfunc_98(MenuItemState *); // func_02014eb4
    virtual void vfunc_9c(Menu *, MenuItemState *); // func_02014ec8
    virtual void vfunc_a0(void); // func_02014e98
    virtual void vfunc_a4(MenuItemState *); // func_02014e9c
    virtual void vfunc_a8(Menu *, MenuItemState *); //
    virtual s32 vfunc_ac(MenuItemState *, s32, s32, s32, s32);
    virtual void vfunc_b0(Menu *, MenuItemState *); // func_02014e94
    virtual void vfunc_b4(Menu *, MenuItemState *);
    virtual void vfunc_b8(Menu *, MenuItemState *);
    virtual void vfunc_bc(Menu *, MenuItemState *);
    virtual void vfunc_c0(Menu *, MenuItemState *);
    virtual u32 vfunc_c4(void); // func_02014e8c
    virtual u32 vfunc_c8(MenuItemState *);
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
    /* 008 */ virtual void vfunc_08(void);
    /* 00C */ virtual void vfunc_0c(void);
    /* 0B0 */ virtual BOOL vfunc_b0(MenuItemState *, s32, s32);

    /* 0E8 */ virtual void vfunc_e8(void)
    {
    }

    /* 0EC */ virtual void vfunc_ec(void)
    {
    }

    /* 0FC */ virtual void vfunc_fc(s32, s32, s32, s32)
    {
    }

    /* 100 */ virtual void vfunc_100(s32, s32, s32, s32)
    {
    }

    /* 108 */ virtual void vfunc_108(s32, s32, s32, s32)
    {
    }
};

class ProcMenu : public ProcEx
{
public:
    /* 38 */ Menu * unk_38;
    /* 3C */ u8 unk_3c;

    ProcMenu(Menu * menu)
    {
        this->unk_38 = menu;
        this->unk_3c = 0;
    }

    virtual ~ProcMenu()
    {
        if (this->unk_3c == 0)
        {
            this->unk_38->_0202f7d0();
        }

        this->unk_38->vfunc_dc();
        this->unk_38->vfunc_ec();

        if (this->unk_38 != NULL)
        {
            this->unk_38->vfunc_134();
        }
    }

    inline void ProcMenu_0202d688()
    {
        this->unk_38->vfunc_e0();
        this->unk_38->vfunc_d8();

        this->unk_38->_0202f674();

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

    Dialog();

    virtual ~Dialog()
    {
    }

    /* 128 */ virtual void vfunc_128(void);
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
public:
    /* 000 */ virtual char * vfunc_00(void); // func_020151e0
    /* 028 */ virtual s32 vfunc_28(void); // func_020151d8
};

class DialogItemNo : public DialogItem
{
public:
    /* 000 */ virtual char * vfunc_00(void); // func_0201518c
    /* 014 */ virtual s32 vfunc_14(void); // func_02015184
    /* 01C */ virtual s32 vfunc_1c(void); // func_02015940
    /* 028 */ virtual s32 vfunc_28(void); // func_0201517c
};

#endif // MENU_HPP