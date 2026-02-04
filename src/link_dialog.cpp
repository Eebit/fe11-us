#include "global.h"

#include <new>

#include "hardware.hpp"
#include "hashtable.hpp"
#include "heap.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"

EC char * func_02039e10(char *);

struct UnkStruct_020cac80
{
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
};

extern struct UnkStruct_020cac80 data_020cac80;

extern struct ProcCmd data_020caccc[];

struct UnkStruct_020efc84
{
    u8 unk_00;
    STRUCT_PAD(0x01, 0x18);
    Dialog * unk_18;
    STRUCT_PAD(0x1C, 0x30);
    s32 unk_30;
};

extern struct UnkStruct_020efc84 data_020efc84;

extern MenuItem ** data_020efcb8;

EC void func_01ff9998(void *, s32, s32);
EC u8 * func_0202b70c(void);

class LinkDialogBlink : public ProcEx
{
public:
    u8 * unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;

    LinkDialogBlink(s32 uVar1)
    {
        this->unk_3c = uVar1;
        this->unk_40 = 0;
        this->unk_44 = 0;
        this->unk_38 = func_0202b70c();
    }

    // func_020158b8
    // func_02015900
    virtual ~LinkDialogBlink()
    {
        func_01ff9998(this->unk_38, this->unk_3c * 0x20, 0x20);
        gHeap.Free(this->unk_38);
    }

    virtual void Loop(void); // func_020147d4
};

class LinkDialogItemNone : public DialogItem
{
public:
    /* 01C */ virtual s32 vfunc_1c(void); // func_02015130
    /* 0A8 */ virtual void vfunc_a8(Menu *, MenuItemState *); // func_02015138
    /* 0AC */ virtual s32 vfunc_ac(MenuItemState *, s32, s32, s32, s32); // func_0201513c
};

class LinkDialogItemOk : public DialogItem
{
public:
    /* 000 */ virtual char * vfunc_00(void); // func_0201514c
    /* 01C */ virtual s32 vfunc_1c(void); // func_02015144
};

class LinkDialogItemNext : public DialogItem
{
public:
    /* 000 */ virtual char * vfunc_00(void); // func_02015160
    /* 01C */ virtual s32 vfunc_1c(void); // func_02015168
};

class LinkDialogItemNoF : public DialogItemNo
{
public:
    /* 01C */ virtual s32 vfunc_1c(void); // func_020151a0
};

class LinkDialogItemNo : public DialogItemNo
{
public:
    /* 014 */ virtual s32 vfunc_14(void); // func_020151d0
    /* 01C */ virtual s32 vfunc_1c(void); // func_020151b8
};

class LinkDialogItemYes : public DialogItemYes
{
public:
    /* 01C */ virtual s32 vfunc_1c(void); // func_020151f4
};

class _LinkDialogCommon : public Dialog
{
public:
    _LinkDialogCommon()
    {
        data_020efc84.unk_00 = 0;
    }

    /* 000 */ virtual void vfunc_00(void); // func_020153cc
    /* 020 */ virtual s32 vfunc_20(s32); // func_0201536c
    /* 028 */ virtual s32 vfunc_28(s32); // func_020153c4

    // func_02015818
    // func_0201586c
    virtual ~_LinkDialogCommon()
    {
        data_020efc84.unk_18 = NULL;
    }
};

class _LinkDialogYesNo : public _LinkDialogCommon
{
public:
    /* 000 */ virtual void vfunc_00(void); // func_020156e4
    /* 028 */ virtual s32 vfunc_28(s32); // func_020156b4

    // func_02015948
    // func_02015994
    // ~_LinkDialogYesNo();
};

class _LinkDialogNone : public _LinkDialogCommon
{
public:
    s16 unk_58;
    s16 unk_5a;

    /* 010 */ virtual void vfunc_10(void);
    /* 0FC */ virtual void vfunc_fc(void); // func_020156b0
    /* 100 */ virtual void vfunc_100(void); // func_020156ac
    /* 108 */ virtual void vfunc_108(void); // func_020156a8
    /* 110 */ virtual void vfunc_110(void); // func_020156a4
    /* 11C */ virtual void vfunc_11c(void);

    // func_0201556c
    // func_02015500
    virtual ~_LinkDialogNone()
    {
        Proc_EndEach(data_020caccc);
    }
};

class _LinkDialogConfirm : public _LinkDialogCommon
{
public:
    /* 110 */ virtual void vfunc_110(void); // func_020154fc

    // func_020159e8
    // func_02015a34
    // ~_LinkDialogConfirm();
};

class LinkErrorDialog : public ProcEx
{
public:
    char * unk_38;

    LinkErrorDialog(char * str)
    {
        this->unk_38 = str;
    }

    // func_02015a88
    // func_02015a8c
    virtual ~LinkErrorDialog()
    {
    }
};

EC void func_020147c0(LinkDialogBlink * proc)
{
    proc->Loop();
    return;
}

EC void func_01ff9a8c(u8 *, s32, s32);

// func_020147d4
void LinkDialogBlink::Loop(void)
{
    s32 tmp;

    if (++this->unk_40 < 4)
    {
        return;
    }

    if (++this->unk_44 >= 0x10)
    {
        this->unk_44 = 0;
    }

    this->unk_40 = 0;

    tmp = this->unk_44;
    if (tmp >= 8)
    {
        tmp = 15 - tmp;
    }

    func_01ff9a8c(this->unk_38 + (tmp * 0x20), this->unk_3c * 0x20, 0x20);
    return;
}

EC void func_0202fef8(Menu *);
EC void func_020303bc(Dialog *, char *, void *, ProcPtr, s32, s32);

EC Dialog * func_02014834(ProcPtr param_1, char * param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    static LinkDialogItemYes data_020efcac;
    static LinkDialogItemNo data_020efca4;
    static LinkDialogItemNoF data_020efca0;
    static LinkDialogItemNext data_020efcc0;
    static LinkDialogItemOk data_020efc8c;
    static LinkDialogItemNone data_020efcb0;

    // clang-format off
    static MenuItem * data_020cac9c[] =
    {
        &data_020efc8c,
    };

    static MenuItem * data_020caca4[] =
    {
        &data_020efcc0,
    };

    static MenuItem * data_020cacac[] =
    {
        &data_020efcb0,
    };

    static MenuItem * data_020cacb4[] =
    {
        &data_020efcac,
        &data_020efca0,
    };

    static MenuItem * data_020cacc0[] =
    {
        &data_020efcac,
        &data_020efca4,
    };
    // clang-format on

    if (data_020efc84.unk_18 != NULL)
    {
        func_0202fef8(data_020efc84.unk_18);
    }

    if (param_3 == 0)
    {
        data_020efc84.unk_18 = new _LinkDialogYesNo();
    }
    else if (param_3 == 3)
    {
        data_020efc84.unk_18 = new _LinkDialogNone();
    }
    else
    {
        data_020efc84.unk_18 = new _LinkDialogConfirm();
    }

    if (param_3 == 1)
    {
        data_020efcb8 = data_020cac9c;
    }
    else if (param_3 == 2)
    {
        data_020efcb8 = data_020caca4;
    }
    else if (param_3 == 3)
    {
        data_020efcb8 = data_020cacac;
    }
    else if (param_6 != 0)
    {
        data_020efcb8 = data_020cacb4;
    }
    else
    {
        data_020efcb8 = data_020cacc0;
    }

    if (param_1 == NULL)
    {
        param_4 = 0;
        param_1 = PROC_TREE_9;
    }

    func_020303bc(data_020efc84.unk_18, param_2, data_020efcb8, param_1, param_4, param_5);

    return data_020efc84.unk_18;
}

EC void func_0202fe9c(Menu *, s32);

EC void func_02014ad0(void)
{
    if (data_020efc84.unk_18 != NULL)
    {
        func_0202fe9c(data_020efc84.unk_18, 0);
    }

    return;
}

EC void func_02014af4(void)
{
    data_020cac80.unk_08 = -1;
    data_020cac80.unk_10 = -1;
    data_020cac80.unk_14 = -1;
    data_020cac80.unk_18 = -1;
    data_020cac80.unk_04 = -1;
    data_020cac80.unk_0c = -1;
    data_020cac80.unk_00 = -1;
    return;
}

// func_02014e74
u32 MenuItem::vfunc_d4(void)
{
    return 1;
}

// func_02014e7c
u32 MenuItem::vfunc_d0(void)
{
    return 0;
}

// func_02014e84
u32 MenuItem::vfunc_cc(void)
{
    return 2;
}

// func_02014e8c
u32 MenuItem::vfunc_c4(void)
{
    return -1;
}

// func_02014e94
void MenuItem::vfunc_b0(Menu * menu, MenuItemState * menuItemState)
{
    return;
}

// func_02014e98
void MenuItem::vfunc_a0(void)
{
    return;
}

// func_02014e9c
void MenuItem::vfunc_a4(MenuItemState * menuItemState)
{
    this->vfunc_a0();
    return;
}

// func_02014eb0
void MenuItem::vfunc_94(void)
{
    return;
}

// func_02014eb4
void MenuItem::vfunc_98(MenuItemState * menuItemState)
{
    this->vfunc_94();
    return;
}

// func_02014ec8
void MenuItem::vfunc_9c(Menu * menu, MenuItemState * menuItemState)
{
    this->vfunc_98(menuItemState);
    return;
}

// func_02014ee0
void MenuItem::vfunc_88(void)
{
    return;
}

// func_02014ee4
void MenuItem::vfunc_8c(MenuItemState * menuItemState)
{
    this->vfunc_88();
    return;
}

// func_02014ef8
void MenuItem::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    this->vfunc_8c(menuItemState);
    return;
}

// func_02014f10
void MenuItem::vfunc_7c(void)
{
    return;
}

// func_02014f14
void MenuItem::vfunc_80(MenuItemState * menuItemState)
{
    this->vfunc_7c();
    return;
}

// func_02014f28
void MenuItem::vfunc_84(Menu * menu, MenuItemState * menuItemState)
{
    this->vfunc_80(menuItemState);
    return;
}

// func_02014f40
void MenuItem::vfunc_70(void)
{
    return;
}

// func_02014f44
void MenuItem::vfunc_74(MenuItemState * menuItemState)
{
    this->vfunc_70();
    return;
}

// func_02014f58
void MenuItem::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    this->vfunc_74(menuItemState);
    return;
}

// func_02014f70
s32 MenuItem::vfunc_64(void)
{
    return 0;
}

// func_02014f78
s32 MenuItem::vfunc_68(MenuItemState * menuItemState)
{
    return this->vfunc_64();
}

// func_02014f8c
s32 MenuItem::vfunc_6c(Menu * menu, MenuItemState * menuItemState)
{
    return this->vfunc_68(menuItemState);
}

// func_02014fa4
s32 MenuItem::vfunc_58(void)
{
    return 0x400;
}

// func_02014fac
s32 MenuItem::vfunc_5c(MenuItemState * menuItemState)
{
    return this->vfunc_58();
}

// func_02014fc0
s32 MenuItem::vfunc_60(Menu * menu, MenuItemState * menuItemState)
{
    return this->vfunc_5c(menuItemState);
}

// func_02014fd8
s32 MenuItem::vfunc_4c(void)
{
    return 0;
}

// func_02014fe0
s32 MenuItem::vfunc_50(MenuItemState * menuItemState)
{
    return this->vfunc_4c();
}

// func_02014ff4
s32 MenuItem::vfunc_54(Menu * menu, MenuItemState * menuItemState)
{
    return this->vfunc_50(menuItemState);
}

// func_0201500c
s32 MenuItem::vfunc_40(void)
{
    return 0;
}

// func_02015014
s32 MenuItem::vfunc_44(MenuItemState * menuItemState)
{
    return this->vfunc_40();
}

// func_02015028
s32 MenuItem::vfunc_48(Menu * menu, MenuItemState * menuItemState)
{
    return this->vfunc_44(menuItemState);
}

// func_02015040
s32 MenuItem::vfunc_34(void)
{
    return 0;
}

// func_02015048
s32 MenuItem::vfunc_38(MenuItemState * menuItemState)
{
    return this->vfunc_34();
}

// func_0201505c
s32 MenuItem::vfunc_3c(Menu * menu, MenuItemState * menuItemState)
{
    return this->vfunc_38(menuItemState);
}

// func_02015074
s32 MenuItem::vfunc_28(void)
{
    return 0x81;
}

// func_0201507c
s32 MenuItem::vfunc_2c(MenuItemState * menuItemState)
{
    return this->vfunc_28();
}

// func_02015090
s32 MenuItem::vfunc_30(Menu * menu, MenuItemState * menuItemState)
{
    return this->vfunc_2c(menuItemState);
}

// func_020150bc
s32 MenuItem::vfunc_1c(void)
{
    return 0;
}

// func_020150a8
s32 MenuItem::vfunc_20(MenuItemState * menuItemState)
{
    return this->vfunc_1c();
}

// func_020150c4
s32 MenuItem::vfunc_24(Menu * menu, MenuItemState * menuItemState)
{
    return this->vfunc_20(menuItemState);
}

// func_020150dc
s32 MenuItem::vfunc_14(void)
{
    return 0;
}

// func_020150e4
s32 MenuItem::vfunc_18(s32 unused)
{
    return this->vfunc_14();
}

// func_020150f8
s32 MenuItem::vfunc_08(void)
{
    return 0;
}

// func_02015100
s32 MenuItem::vfunc_0c(MenuItemState * menuItemState)
{
    return this->vfunc_08();
}

// func_02015114
char * MenuItem::vfunc_00(void)
{
    return 0;
}

// func_0201511c
char * MenuItem::vfunc_04(MenuItemState * menuItemState)
{
    return this->vfunc_00();
}

// func_02015130
s32 LinkDialogItemNone::vfunc_1c(void)
{
    return 0;
}

// func_02015138
void LinkDialogItemNone::vfunc_a8(Menu * menu, MenuItemState * menuItemState)
{
    return;
}

// func_0201513c
s32 LinkDialogItemNone::vfunc_ac(MenuItemState * menuItemState, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    return 0;
}

// func_02015144
s32 LinkDialogItemOk::vfunc_1c(void)
{
    return 0x41;
}

// func_0201514c
char * LinkDialogItemOk::vfunc_00(void)
{
    return func_02039e10("M_OK");
}

// func_02015160
s32 LinkDialogItemNext::vfunc_1c(void)
{
    return 0x41;
}

// func_02015168
char * LinkDialogItemNext::vfunc_00(void)
{
    return func_02039e10("M_NEXT");
}

// func_0201517c
s32 DialogItemNo::vfunc_28(void)
{
    return 0;
}

// func_02015184
s32 DialogItemNo::vfunc_14(void)
{
    return 8;
}

// func_0201518c
char * DialogItemNo::vfunc_00(void)
{
    return func_02039e10("M_いいえ");
}

// func_020151a0
s32 LinkDialogItemNoF::vfunc_1c(void)
{
    data_020efc84.unk_30 = 0;
    return 0x81;
}

// func_020151b8
s32 LinkDialogItemNo::vfunc_1c(void)
{
    data_020efc84.unk_30 = 0;
    return 0x81;
}
// func_020151d0
s32 LinkDialogItemNo::vfunc_14(void)
{
    return 0;
}

// func_020151d8
s32 DialogItemYes::vfunc_28(void)
{
    return 0;
}

// func_020151e0
char * DialogItemYes::vfunc_00(void)
{
    return func_02039e10("M_はい");
}

// func_020151f4
s32 LinkDialogItemYes::vfunc_1c(void)
{
    data_020efc84.unk_30 = 1;
    return 0x41;
}

// func_0201520c
void Menu::vfunc_e4(void)
{
    return;
}

// func_02015210
void Menu::vfunc_e0(void)
{
    return;
}

// func_02015214
void Menu::vfunc_b8(s32 arg0)
{
    return;
}

// func_02015218
s32 Menu::vfunc_ac(void)
{
    return 0;
}

// func_02015220
BOOL Menu::vfunc_a8(void)
{
    return FALSE;
}

// func_02015228
BOOL Menu::vfunc_a4(void)
{
    return FALSE;
}

// func_02015230
BOOL Menu::vfunc_a0(void)
{
    return FALSE;
}

// func_02015238
s32 Menu::vfunc_9c(void)
{
    return 0;
}

// func_02015240
s32 Menu::vfunc_98(s32 arg0, s32 arg1)
{
    return 0;
}
// func_02015248
s32 Menu::vfunc_94(s32 arg0, s32 arg1)
{
    return 0;
}

// func_02015250
s32 Menu::vfunc_60(void)
{
    return this->vfunc_7c() | 0x2000;
}

// func_02015268
s32 Menu::vfunc_58(s32 arg0)
{
    return arg0;
}

// func_02015270
s32 Menu::vfunc_5c(MenuItemState * menuItemState, s32 arg1)
{
    return this->vfunc_58(arg1);
}

// func_02015288
s32 Menu::vfunc_50(s32 arg0)
{
    return arg0;
}

// func_02015290
s32 Menu::vfunc_54(MenuItemState * menuItemState, s32 arg1)
{
    return this->vfunc_50(arg1);
}

// func_020152a8
s32 Menu::vfunc_48(s32 arg0)
{
    return arg0;
}

// func_020152b0
s32 Menu::vfunc_4c(MenuItemState * menuItemState, s32 arg1)
{
    return this->vfunc_48(arg1);
}

// func_020152c8
s32 Menu::vfunc_40(s32 arg0)
{
    return arg0;
}

// func_020152d0
s32 Menu::vfunc_44(MenuItemState * menuItemState, s32 arg1)
{
    return this->vfunc_40(arg1);
}

// func_020152e8
s32 Menu::vfunc_38(s32 arg0)
{
    return arg0;
}

// func_020152f0
s32 Menu::vfunc_3c(MenuItemState * menuItemState, s32 arg1)
{
    return this->vfunc_38(arg1);
}

// func_02015308
s32 Menu::vfunc_30(s32 arg0)
{
    return arg0;
}

// func_02015310
s32 Menu::vfunc_34(MenuItemState * menuItemState, s32 arg1)
{
    return this->vfunc_30(arg1);
}

// func_02015328
s32 Menu::vfunc_2c(MenuItemState * menuItemState, s32 arg1)
{
    return this->vfunc_28(arg1);
}

// func_02015340
s32 Menu::vfunc_28(s32 arg0)
{
    return arg0;
}

// func_02015348
s32 Menu::vfunc_24(MenuItemState * menuItemState, s32 arg1)
{
    return this->vfunc_20(arg1);
}

// func_02015360
s32 Menu::vfunc_20(s32 arg0)
{
    return arg0;
}

// func_02015368
void Menu::vfunc_04(void)
{
    return;
}

extern struct ProcCmd ProcScr_020ce750[];

EC s32 func_020121c0(void);
EC s32 func_02012584(void);

EC s32 func_ov010_02207ab4(void);
EC void func_ov010_0220986c(s32, s32, s32, ProcPtr);
EC s32 func_ov010_02209674(void);

EC s32 func_ov011_022065a4(s32 *, s32 *);
EC s32 func_ov011_022087c8(s32, s32, s32, s32, s32, ProcPtr);
EC void func_ov011_022065b0(void);
EC s32 func_ov011_022082ec(s32, s32, s32);
EC void func_ov011_02206564(s32);

EC s32 func_02014b20(ProcPtr param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 iVar1;
    u32 uVar2;
    u32 puVar10;
    s32 iVar11;
    s32 local_1c;
    s32 local_20;
    s32 uStack_18;

    iVar11 = 0;
    uStack_18 = param_4;

    switch (func_020121c0())
    {
        case 1:
            func_ov010_0220986c(0, 0, func_ov010_02207ab4(), param_1);
            func_ov010_02207ab4();
            data_020efc84.unk_00 = func_ov010_02209674();
            break;

        case 2:
            uVar2 = func_ov011_022065a4(&local_1c, &local_20);
            func_ov011_022087c8(0, 0, uVar2, local_1c, local_20, param_1);
            func_ov011_022065b0();

            switch (local_20)
            {
                case 0:
                case 1:
                case 2:
                    func_ov011_02206564(6);
                    iVar11 = 1;
                    break;
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    break;
            }
            data_020efc84.unk_00 = func_ov011_022082ec(uVar2, local_1c, local_20);
            break;
    }

    switch (param_2)
    {
        case 0:
            break;

        case 1:
            if (func_02012584() != 0)
            {
                iVar11 = 0;
                new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_BreakUp");
            }
            break;
        case 2:
            iVar11 = 0;
            new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_DownloadFailed");
            break;
        case 3:
            iVar11 = 0;
            new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_DownloadCancel");
            break;
        case 4:
            iVar11 = 0;
            if (data_020efc84.unk_00 == 0)
            {
                new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_StorageLoginFailed");
            }
            break;
        case 5:
            if (iVar11 == 1)
            {
                new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_StorageSaveFailed");
            }
            break;
        case 6:
            iVar11 = 0;
            if (data_020efc84.unk_00 == 0)
            {
                new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_StorageLoadFailed");
            }
            break;
        case 7:
            iVar11 = 0;
            if (data_020efc84.unk_00 == 0)
            {
                new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_CollectFailed");
            }
            break;
        case 8:
            iVar11 = 0;
            if (data_020efc84.unk_00 == 0)
            {
                new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_OnlineShopFailed");
            }
    }

    return iVar11;
}

EC Dialog * func_02014834(ProcPtr param_1, char * param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6);

EC void func_02014e10(LinkErrorDialog * param_1)
{
    if (data_020efc84.unk_00 == 0 && data_020efc84.unk_18 == NULL)
    {
        func_02014834(param_1, func_02039e10(param_1->unk_38), 2, 1, 1, 1);
        Proc_Break(param_1, 0);
    }

    return;
}

struct VmMap_Common
{
    STRUCT_PAD(0x00, 0x04);
    u16 unk_04;
    u8 unk_06;
    u8 unk_07;
    void * unk_08;
};

struct UnkStruct_02196f20
{
    STRUCT_PAD(0x000, 0x180);
    /* 180 */ void * flagMgr;
    s32 unk_184;
    u32 unk_188;
    u32 unk_18c;
    s32 unk_190;
    u32 unk_194;
    u8 unk_198;
    u8 unk_199;
    u8 unk_19a;
    u8 unk_19b;
    s8 unk_19c;
    s8 unk_19d;
    STRUCT_PAD(0x19E, 0x1A4);
};

extern struct UnkStruct_02196f20 * data_02196f20;

extern struct TouchState * gTouchSt;

// func_0201536c
s32 _LinkDialogCommon::vfunc_20(s32 param_2)
{
    if ((gMapStateManager != NULL) && (gMapStateManager->unk_14->unk_24) == 0)
    {
        data_02196f20->unk_19a = gTouchSt->unk_15 != 0;
    }

    return param_2;
}

// func_020153c4
s32 _LinkDialogCommon::vfunc_28(s32 arg0)
{
    return 0;
}

// func_020153cc
void _LinkDialogCommon::vfunc_00(void)
{
    struct VmMap_Common * iVar1;

    if ((gMapStateManager != NULL) && (gMapStateManager->unk_14->unk_24 == 0))
    {
        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_DialogFont"));
        this->unk_14 = iVar1->unk_04;
        this->unk_18 = iVar1->unk_06;

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Dialog"));
        this->unk_30 = iVar1->unk_07;
        this->unk_1c = iVar1->unk_04;
        this->unk_20 = iVar1->unk_06;

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_MenuCursor"));
        this->unk_24 = iVar1->unk_04;
        this->unk_28 = iVar1->unk_06;
    }
    else
    {
        this->unk_30 = 0;

        if (data_020cac80.unk_08 != -1)
        {
            this->unk_30 = data_020cac80.unk_08;
        }

        if (data_020cac80.unk_10 != -1)
        {
            this->unk_14 = data_020cac80.unk_10;
        }

        if (data_020cac80.unk_14 != -1)
        {
            this->unk_18 = data_020cac80.unk_14;
        }

        if (data_020cac80.unk_18 != -1)
        {
            this->unk_1c = data_020cac80.unk_18;
        }

        if (data_020cac80.unk_04 != -1)
        {
            this->unk_20 = data_020cac80.unk_04;
        }

        if (data_020cac80.unk_0c != -1)
        {
            this->unk_24 = data_020cac80.unk_0c;
        }

        if (data_020cac80.unk_00 != -1)
        {
            this->unk_28 = data_020cac80.unk_00;
        }
    }

    this->unk_40 = 1;

    return;
}

// func_020154fc
void _LinkDialogConfirm::vfunc_110(void)
{
    return;
}

// func_020155d0
void _LinkDialogNone::vfunc_11c(void)
{
    LinkDialogBlink * puVar1;

    Menu::vfunc_11c();

    puVar1 = new (func_01ffbf90(data_020caccc, PROC_TREE_3)) LinkDialogBlink(this->unk_20);
    func_01ffbfd0(puVar1);

    return;
}

struct UnkStruct_021970c4
{
    void * unk_00;
    void * unk_04;
    void * unk_08;
};

extern struct UnkStruct_021970c4 * data_021970c4;
extern struct UnkStruct_021970c4 * data_021970cc;

EC s32 func_020290f4(struct UnkStruct_021970c4 *, s32);
EC s32 func_02028e7c(struct UnkStruct_021970c4 *, s32, s32);

// func_02015628
void _LinkDialogNone::vfunc_10(void)
{
    u32 iVar1;

    Menu::vfunc_10();

    iVar1 = func_020290f4(data_021970c4, this->unk_54);

    this->unk_37 = (iVar1 << 1) + 4;
    this->unk_5a = this->unk_36;

    iVar1 = func_02028e7c(data_021970c4, this->unk_54, 0);
    iVar1 = (((iVar1 + 7) & ~7) / 8) + 2;

    if (this->unk_5a < iVar1)
    {
        this->unk_5a = iVar1;
        this->unk_36 = this->unk_5a;
    }

    this->unk_5a += 2;

    return;
}

// func_020156a4
void _LinkDialogNone::vfunc_110(void)
{
    return;
}

// func_020156a8
void _LinkDialogNone::vfunc_108(void)
{
    return;
}

// func_020156ac
void _LinkDialogNone::vfunc_100(void)
{
    return;
}

// func_020156b0
void _LinkDialogNone::vfunc_fc(void)
{
    return;
}

// func_020156b4
s32 _LinkDialogYesNo::vfunc_28(s32 arg0)
{
    if (arg0 == 0)
    {
        return this->unk_0c[1].unk_00->vfunc_24(this, &this->unk_0c[1]);
    }

    return arg0;
}

// func_020156e4
void _LinkDialogYesNo::vfunc_00(void)
{
    struct VmMap_Common * iVar1;

    if ((gMapStateManager != NULL) && (gMapStateManager->unk_14->unk_24 == 0))
    {
        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_DialogFont"));
        this->unk_14 = iVar1->unk_04;
        this->unk_18 = iVar1->unk_06;

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Dialog"));
        this->unk_30 = iVar1->unk_07;
        this->unk_1c = iVar1->unk_04;
        this->unk_20 = iVar1->unk_06;

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_MenuCursor"));
        this->unk_24 = iVar1->unk_04;
        this->unk_28 = iVar1->unk_06;
    }
    else
    {
        this->unk_30 = 0;

        if (data_020cac80.unk_08 != -1)
        {
            this->unk_30 = data_020cac80.unk_08;
        }

        if (data_020cac80.unk_10 != -1)
        {
            this->unk_14 = data_020cac80.unk_10;
        }

        if (data_020cac80.unk_14 != -1)
        {
            this->unk_18 = data_020cac80.unk_14;
        }

        if (data_020cac80.unk_18 != -1)
        {
            this->unk_1c = data_020cac80.unk_18;
        }

        if (data_020cac80.unk_04 != -1)
        {
            this->unk_20 = data_020cac80.unk_04;
        }

        if (data_020cac80.unk_0c != -1)
        {
            this->unk_24 = data_020cac80.unk_0c;
        }

        if (data_020cac80.unk_00 != -1)
        {
            this->unk_28 = data_020cac80.unk_00;
        }
    }

    this->unk_40 = 1;
    this->unk_48 = 1;

    return;
}

// func_02015940
s32 DialogItemNo::vfunc_1c(void)
{
    return 0x81;
}