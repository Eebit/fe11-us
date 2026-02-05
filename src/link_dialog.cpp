#include "global.h"

#include <new>

#include "hardware.hpp"
#include "hashtable.hpp"
#include "heap.hpp"
#include "link_dialog.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"

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

extern struct ProcCmd data_020caccc[];

struct UnkStruct_020efc84
{
    u8 unk_00;
    STRUCT_PAD(0x01, 0x18);
    Dialog * unk_18;
    STRUCT_PAD(0x1C, 0x30);
    s32 unk_30;
};

u8 data_020efc84 = 0;

Dialog * data_020efc9c = 0;

s32 data_020efcb4 = 0;

MenuItem ** data_020efcb8 = 0;

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

    virtual ~LinkDialogBlink()
    {
        func_01ff9998(this->unk_38, this->unk_3c * 0x20, 0x20);
        gHeap.Free(this->unk_38);
    }

    virtual void Loop(void);
};

// Ordering required to match?

s32 data_020cac88 = -1;
s32 data_020cac84 = -1;
s32 data_020cac80 = -1;
s32 data_020cac90 = -1;
s32 data_020cac94 = -1;
s32 data_020cac8c = -1;
s32 data_020cac98 = -1;

class _LinkDialogCommon : public Dialog
{
public:
    s16 unk_58;
    s16 unk_5a;

    _LinkDialogCommon()
    {
        data_020efc84 = 0;
    }

    /* 000 */ virtual void vfunc_00(void)
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

            if (data_020cac88 != -1)
            {
                this->unk_30 = data_020cac88;
            }

            if (data_020cac90 != -1)
            {
                this->unk_14 = data_020cac90;
            }

            if (data_020cac94 != -1)
            {
                this->unk_18 = data_020cac94;
            }

            if (data_020cac98 != -1)
            {
                this->unk_1c = data_020cac98;
            }

            if (data_020cac84 != -1)
            {
                this->unk_20 = data_020cac84;
            }

            if (data_020cac8c != -1)
            {
                this->unk_24 = data_020cac8c;
            }

            if (data_020cac80 != -1)
            {
                this->unk_28 = data_020cac80;
            }
        }

        this->unk_40 = 1;

        return;
    }

    /* 028 */ virtual s32 vfunc_28(s32 arg0)
    {
        return 0;
    }

    /* 020 */ virtual s32 vfunc_20(s32 param_2)
    {
        if ((gMapStateManager != NULL) && (gMapStateManager->unk_14->unk_24) == 0)
        {
            data_02196f20->unk_19a = gTouchSt->unk_15 != 0;
        }

        return param_2;
    }

    virtual ~_LinkDialogCommon()
    {
        data_020efc9c = NULL;
    }
};

class _LinkDialogYesNo : public _LinkDialogCommon
{
public:
    /* 000 */ virtual void vfunc_00(void)
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

            if (data_020cac88 != -1)
            {
                this->unk_30 = data_020cac88;
            }

            if (data_020cac90 != -1)
            {
                this->unk_14 = data_020cac90;
            }

            if (data_020cac94 != -1)
            {
                this->unk_18 = data_020cac94;
            }

            if (data_020cac98 != -1)
            {
                this->unk_1c = data_020cac98;
            }

            if (data_020cac84 != -1)
            {
                this->unk_20 = data_020cac84;
            }

            if (data_020cac8c != -1)
            {
                this->unk_24 = data_020cac8c;
            }

            if (data_020cac80 != -1)
            {
                this->unk_28 = data_020cac80;
            }
        }

        this->unk_40 = 1;
        this->unk_48 = 1;

        return;
    }

    /* 028 */ virtual s32 vfunc_28(s32 arg0)
    {
        if (arg0 == 0)
        {
            return this->unk_0c[1].unk_00->vfunc_24(this, &this->unk_0c[1]);
        }

        return arg0;
    }

    // ~_LinkDialogYesNo();
};

class _LinkDialogNone : public _LinkDialogCommon
{
public:
    /* 0FC */ virtual void vfunc_fc(void)
    {
        return;
    }

    /* 100 */ virtual void vfunc_100(void)
    {
        return;
    }

    /* 108 */ virtual void vfunc_108(void)
    {
        return;
    }

    /* 110 */ virtual void vfunc_110(void)
    {
        return;
    }

    /* 010 */ virtual void vfunc_10(void)
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

    /* 11C */ virtual void vfunc_11c(void)
    {
        LinkDialogBlink * proc;

        Menu::vfunc_11c();

        proc = new (func_01ffbf90(data_020caccc, PROC_TREE_3)) LinkDialogBlink(this->unk_20);
        func_01ffbfd0(proc);

        return;
    }

    virtual ~_LinkDialogNone()
    {
        Proc_EndEach(data_020caccc);
    }
};

class _LinkDialogConfirm : public _LinkDialogCommon
{
public:
    /* 110 */ virtual void vfunc_110(void)
    {
        return;
    }

    // ~_LinkDialogConfirm();
};

class LinkDialogItemYes : public DialogItemYes
{
public:
    /* 01C */ virtual s32 vfunc_1c(void)
    {
        data_020efcb4 = 1;
        return 0x41;
    }
};

class LinkDialogItemNo : public DialogItemNo
{
public:
    /* 014 */ virtual s32 vfunc_14(void)
    {
        return 0;
    }

    /* 01C */ virtual s32 vfunc_1c(void)
    {
        data_020efcb4 = 0;
        return 0x81;
    }
};

class LinkDialogItemNoF : public DialogItemNo
{
public:
    /* 01C */ virtual s32 vfunc_1c(void)
    {
        data_020efcb4 = 0;
        return 0x81;
    }
};

class LinkDialogItemNext : public DialogItem
{
public:
    /* 000 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("M_NEXT");
    }

    /* 01C */ virtual s32 vfunc_1c(void)
    {
        return 0x41;
    }
};

class LinkDialogItemOk : public DialogItem
{
public:
    /* 000 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("M_OK");
    }

    /* 01C */ virtual s32 vfunc_1c(void)
    {
        return 0x41;
    }
};

class LinkDialogItemNone : public DialogItem
{
public:
    /* 0AC */ virtual s32 vfunc_ac(MenuItemState * menuItemState, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
    {
        return 0;
    }

    /* 0A8 */ virtual void vfunc_a8(Menu * menu, MenuItemState * menuItemState)
    {
        return;
    }

    /* 01C */ virtual s32 vfunc_1c(void)
    {
        return 0;
    }
};

EC void func_020147c0(LinkDialogBlink * proc)
{
    proc->Loop();
    return;
}

EC void func_01ff9a8c(u8 *, s32, s32);

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

EC Dialog * func_02014834(ProcPtr param_1, char * param_2, s32 param_3, s32 param_4, u8 param_5, s32 param_6)
{
    static LinkDialogItemYes data_020efcac;
    static LinkDialogItemNo data_020efca4;
    static LinkDialogItemNoF data_020efca0;
    static LinkDialogItemNext data_020efcc0;
    static LinkDialogItemOk data_020efc8c;
    static LinkDialogItemNone data_020efcb0;

    // clang-format off
    static MenuItem * data_020cacac[] =
    {
        &data_020efcb0,
    };
    // clang-format on

    // clang-format off
    static MenuItem * data_020cac9c[] =
    {
        &data_020efc8c,
    };
    // clang-format on

    // clang-format off
    static MenuItem * data_020caca4[] =
    {
        &data_020efcc0,
    };
    // clang-format on

    // clang-format off
    static MenuItem * data_020cacb4[] =
    {
        &data_020efcac,
        &data_020efca0,
    };
    // clang-format on

    // clang-format off
    static MenuItem * data_020cacc0[] =
    {
        &data_020efcac,
        &data_020efca4,
    };
    // clang-format on

    if (data_020efc9c != NULL)
    {
        func_0202fef8(data_020efc9c);
    }

    if (param_3 == 0)
    {
        data_020efc9c = new _LinkDialogYesNo();
    }
    else if (param_3 == 3)
    {
        data_020efc9c = new _LinkDialogNone();
    }
    else
    {
        data_020efc9c = new _LinkDialogConfirm();
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

    func_020303bc(data_020efc9c, param_2, data_020efcb8, param_1, param_4, param_5);

    return data_020efc9c;
}

EC void func_0202fe9c(Menu *, s32);

EC void func_02014ad0(void)
{
    if (data_020efc9c != NULL)
    {
        func_0202fe9c(data_020efc9c, 0);
    }

    return;
}

EC void func_02014af4(void)
{
    data_020cac88 = -1;
    data_020cac90 = -1;
    data_020cac94 = -1;
    data_020cac98 = -1;
    data_020cac84 = -1;
    data_020cac8c = -1;
    data_020cac80 = -1;
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
            data_020efc84 = func_ov010_02209674();
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
            data_020efc84 = func_ov011_022082ec(uVar2, local_1c, local_20);
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
            if (data_020efc84 == 0)
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
            if (data_020efc84 == 0)
            {
                new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_StorageLoadFailed");
            }
            break;
        case 7:
            iVar11 = 0;
            if (data_020efc84 == 0)
            {
                new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_CollectFailed");
            }
            break;
        case 8:
            iVar11 = 0;
            if (data_020efc84 == 0)
            {
                new (Proc_StartBlocking(ProcScr_020ce750, param_1)) LinkErrorDialog("MLink_OnlineShopFailed");
            }
    }

    return iVar11;
}

EC void func_02014e10(LinkErrorDialog * param_1)
{
    if (data_020efc84 == 0 && data_020efc9c == NULL)
    {
        func_02014834(param_1, func_02039e10(param_1->unk_38), 2, 1, 1, 1);
        Proc_Break(param_1, 0);
    }

    return;
}
