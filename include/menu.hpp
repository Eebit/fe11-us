#ifndef MENU_HPP
#define MENU_HPP

#include "global.h"

#include "heap.hpp"
#include "proc_ex.hpp"

EC char * GetText(char *);

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

enum
{
    MENU_ACTION_x1 = (1 << 0),
    MENU_ACTION_x2 = (1 << 1),
    MENU_ACTION_x4 = (1 << 2),
    MENU_ACTION_x8 = (1 << 3), // end this menu?
    MENU_ACTION_x10 = (1 << 4), // end parent menu?
    MENU_ACTION_x20 = (1 << 5), // end all menus?
    MENU_ACTION_x40 = (1 << 6), // process success?
    MENU_ACTION_x80 = (1 << 7), // process cancel?
    MENU_ACTION_x100 = (1 << 8), // process failure?

    MENU_ACTION_x1000 = (1 << 12), // block?
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

    /* 004 */ virtual void vfunc_04(void)
    {
        return;
    }

    /* 008 */ virtual void vfunc_08(void);
    /* 00C */ virtual void vfunc_0c(void);
    /* 010 */ virtual void vfunc_10(void);
    /* 014 */ virtual void vfunc_14(void);
    /* 018 */ virtual void vfunc_18(void);
    /* 01C */ virtual void vfunc_1c(void);
    /* 020 */ virtual s32 vfunc_20(s32 arg0)
    {
        return arg0;
    }

    /* 024 */ virtual s32 vfunc_24(MenuItemState * menuItemState, s32 arg1)
    {
        return this->vfunc_20(arg1);
    }

    /* 028 */ virtual s32 vfunc_28(s32 arg0)
    {
        return arg0;
    }

    /* 02C */ virtual s32 vfunc_2c(MenuItemState * menuItemState, s32 arg1)
    {
        return this->vfunc_28(arg1);
    }

    /* 030 */ virtual s32 vfunc_30(s32 arg0)
    {
        return arg0;
    }

    /* 034 */ virtual s32 vfunc_34(MenuItemState * menuItemState, s32 arg1)
    {
        return this->vfunc_30(arg1);
    }

    /* 038 */ virtual s32 vfunc_38(s32 arg0)
    {
        return arg0;
    }

    /* 03C */ virtual s32 vfunc_3c(MenuItemState * menuItemState, s32 arg1)
    {
        return this->vfunc_38(arg1);
    }

    /* 040 */ virtual s32 vfunc_40(s32 arg0)
    {
        return arg0;
    }

    /* 044 */ virtual s32 vfunc_44(MenuItemState * menuItemState, s32 arg1)
    {
        return this->vfunc_40(arg1);
    }

    /* 048 */ virtual s32 vfunc_48(s32 arg0)
    {
        return arg0;
    }

    /* 04C */ virtual s32 vfunc_4c(MenuItemState * menuItemState, s32 arg1)
    {
        return this->vfunc_48(arg1);
    }

    /* 050 */ virtual s32 vfunc_50(s32 arg0)
    {
        return arg0;
    }

    /* 054 */ virtual s32 vfunc_54(MenuItemState * menuItemState, s32 arg1)
    {
        return this->vfunc_50(arg1);
    }

    /* 058 */ virtual s32 vfunc_58(s32 arg0)
    {
        return arg0;
    }

    /* 05C */ virtual s32 vfunc_5c(MenuItemState * menuItemState, s32 arg1)
    {
        return this->vfunc_58(arg1);
    }

    /* 060 */ virtual s32 vfunc_60(void)
    {
        return this->vfunc_7c() | 0x2000;
    }

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

    /* 094 */ virtual s32 vfunc_94(s32 arg0, s32 arg1)
    {
        return 0;
    }

    /* 098 */ virtual s32 vfunc_98(s32 arg0, s32 arg1)
    {
        return 0;
    }

    /* 09C */ virtual s32 vfunc_9c(void)
    {
        return 0;
    }

    /* 0A0 */ virtual BOOL vfunc_a0(void)
    {
        return FALSE;
    }

    /* 0A4 */ virtual BOOL vfunc_a4(void)
    {
        return FALSE;
    }

    /* 0A8 */ virtual BOOL vfunc_a8(void)
    {
        return FALSE;
    }

    /* 0AC */ virtual s32 vfunc_ac(void)
    {
        return 0;
    }

    /* 0B0 */ virtual BOOL vfunc_b0(MenuItemState *, s32, s32);
    /* 0B4 */ virtual BOOL vfunc_b4(void);

    /* 0B8 */ virtual void vfunc_b8(s32 arg0)
    {
        return;
    }

    /* 0BC */ virtual void vfunc_bc(void);
    /* 0C0 */ virtual void vfunc_c0(void);
    /* 0C4 */ virtual void vfunc_c4(void);
    /* 0C8 */ virtual void vfunc_c8(void);
    /* 0CC */ virtual s32 vfunc_cc(void);
    /* 0D0 */ virtual void vfunc_d0(s32);
    /* 0D4 */ virtual s32 vfunc_d4(s32);
    /* 0D8 */ virtual void vfunc_d8(void);
    /* 0DC */ virtual void vfunc_dc(void);

    /* 0E0 */ virtual void vfunc_e0(void)
    {
        return;
    }

    /* 0E4 */ virtual void vfunc_e4(void)
    {
        return;
    }

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
    virtual s32 vfunc_138(void);

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
    /* 00 */ virtual char * vfunc_00(void)
    {
        return NULL;
    }

    /* 04 */ virtual char * vfunc_04(MenuItemState * menuItemState)
    {
        return this->vfunc_00();
    }

    /* 08 */ virtual s32 vfunc_08(void)
    {
        return 0;
    }

    /* 0C */ virtual s32 vfunc_0c(MenuItemState * menuItemState)
    {
        return this->vfunc_08();
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState *); // GetLabelColor
    // (1 = White, 2 = Grey, 3 = Cyan, 4 = Gold, 5 = Green)

    /* 14 */ virtual s32 vfunc_14(void)
    {
        return 0;
    }

    /* 18 */ virtual s32 vfunc_18(s32 unused)
    {
        return this->vfunc_14();
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        return 0;
    }

    /* 20 */ virtual s32 vfunc_20(MenuItemState * menuItemState)
    {
        return this->vfunc_1c();
    }

    /* 24 */ virtual s32 vfunc_24(Menu * menu, MenuItemState * menuItemState)
    {
        return this->vfunc_20(menuItemState);
    }

    /* 28 */ virtual s32 vfunc_28(void)
    {
        return 0x81;
    }

    /* 2C */ virtual s32 vfunc_2c(MenuItemState * menuItemState)
    {
        return this->vfunc_28();
    }

    /* 30 */ virtual s32 vfunc_30(Menu * menu, MenuItemState * menuItemState)
    {
        return this->vfunc_2c(menuItemState);
    }

    /* 34 */ virtual s32 vfunc_34(void)
    {
        return 0;
    }

    /* 38 */ virtual s32 vfunc_38(MenuItemState * menuItemState)
    {
        return this->vfunc_34();
    }

    /* 3C */ virtual s32 vfunc_3c(Menu * menu, MenuItemState * menuItemState)
    {
        return this->vfunc_38(menuItemState);
    }

    /* 40 */ virtual s32 vfunc_40(void)
    {
        return 0;
    }

    /* 44 */ virtual s32 vfunc_44(MenuItemState * menuItemState)
    {
        return this->vfunc_40();
    }

    /* 48 */ virtual s32 vfunc_48(Menu * menu, MenuItemState * menuItemState)
    {
        return this->vfunc_44(menuItemState);
    }

    /* 4C */ virtual s32 vfunc_4c(void)
    {
        return 0;
    }

    /* 50 */ virtual s32 vfunc_50(MenuItemState * menuItemState)
    {
        return this->vfunc_4c();
    }

    /* 54 */ virtual s32 vfunc_54(Menu * menu, MenuItemState * menuItemState)
    {
        return this->vfunc_50(menuItemState);
    }

    /* 58 */ virtual s32 vfunc_58(void)
    {
        return 0x400;
    }

    /* 5C */ virtual s32 vfunc_5c(MenuItemState * menuItemState)
    {
        return this->vfunc_58();
    }

    /* 60 */ virtual s32 vfunc_60(Menu * menu, MenuItemState * menuItemState)
    {
        return this->vfunc_5c(menuItemState);
    }

    /* 64 */ virtual s32 vfunc_64(void)
    {
        return 0;
    }

    /* 68 */ virtual s32 vfunc_68(MenuItemState * menuItemState)
    {
        return this->vfunc_64();
    }

    /* 6C */ virtual s32 vfunc_6c(Menu * menu, MenuItemState * menuItemState)
    {
        return this->vfunc_68(menuItemState);
    }

    /* 70 */ virtual void vfunc_70(void)
    {
        return;
    }

    /* 74 */ virtual void vfunc_74(MenuItemState * menuItemState)
    {
        this->vfunc_70();
        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        this->vfunc_74(menuItemState);
        return;
    }

    /* 7C */ virtual void vfunc_7c(void)
    {
        return;
    }

    /* 80 */ virtual void vfunc_80(MenuItemState * menuItemState)
    {
        this->vfunc_7c();
        return;
    }

    /* 84 */ virtual void vfunc_84(Menu * menu, MenuItemState * menuItemState)
    {
        this->vfunc_80(menuItemState);
        return;
    }

    /* 88 */ virtual void vfunc_88(void)
    {
        return;
    }

    /* 8C */ virtual void vfunc_8c(MenuItemState * menuItemState)
    {
        this->vfunc_88();
        return;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        this->vfunc_8c(menuItemState);
        return;
    }

    /* 94 */ virtual void vfunc_94(void)
    {
        return;
    }

    /* 98 */ virtual void vfunc_98(MenuItemState * menuItemState)
    {
        this->vfunc_94();
        return;
    }

    /* 9C */ virtual void vfunc_9c(Menu * menu, MenuItemState * menuItemState)
    {
        this->vfunc_98(menuItemState);
        return;
    }

    /* A0 */ virtual void vfunc_a0(void)
    {
        return;
    }

    /* A4 */ virtual void vfunc_a4(MenuItemState * menuItemState)
    {
        this->vfunc_a0();
        return;
    }

    /* A8 */ virtual void vfunc_a8(Menu *, MenuItemState *); //
    /* AC */ virtual s32 vfunc_ac(MenuItemState *, s32, s32, s32, s32);

    /* B0 */ virtual void vfunc_b0(Menu * menu, MenuItemState * menuItemState)
    {
        return;
    }

    /* B4 */ virtual void vfunc_b4(Menu *, MenuItemState *);
    /* B8 */ virtual void vfunc_b8(Menu *, MenuItemState *);
    /* BC */ virtual void vfunc_bc(Menu *, MenuItemState *);
    /* C0 */ virtual void vfunc_c0(Menu *, MenuItemState *);
    /* C4 */ virtual u32 vfunc_c4(void)
    {
        return -1;
    }

    /* C8 */ virtual u32 vfunc_c8(MenuItemState *);

    /* CC */ virtual u32 vfunc_cc(void)
    {
        return 2;
    }

    /* D0 */ virtual u32 vfunc_d0(void)
    {
        return 0;
    }

    /* D4 */ virtual u32 vfunc_d4(void)
    {
        return 1;
    }
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
    virtual ~DialogYesNo()
    {
    }
};

class DialogItem : public MenuItem
{
};

class DialogItemYes : public DialogItem
{
public:
    /* 000 */ virtual char * vfunc_00(void)
    {
        return GetText("M_はい");
    }

    /* 028 */ virtual s32 vfunc_28(void)
    {
        return 0;
    }
};

class DialogItemNo : public DialogItem
{
public:
    /* 000 */ virtual char * vfunc_00(void)
    {
        return GetText("M_いいえ");
    }

    /* 014 */ virtual s32 vfunc_14(void)
    {
        return 8;
    }

    /* 01C */ virtual s32 vfunc_1c(void)
    {
        return 0x81;
    }

    /* 028 */ virtual s32 vfunc_28(void)
    {
        return 0;
    }
};

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
    virtual void vfunc_10(void); // func_02003f84
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
    virtual BOOL vfunc_ac(void); // func_02003e90
    virtual void vfunc_b0(/* ? */); // func_02003e88
    virtual void vfunc_b4(/* ? */); // func_02003e80
    virtual void vfunc_b8(/* ? */); // func_02003e78
    virtual s32 vfunc_bc(void); // func_02003e70
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
} // namespace menu

#endif // MENU_HPP