#include "global.h"

#include <new>

#include "button.hpp"
#include "hardware.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

extern struct UnkStruct_02196f0c * data_02196f0c;

namespace sally
{

class SallyMenu : public Menu
{
public:
    // vtable

    virtual ~SallyMenu();

    virtual void vfunc_00(void);
    virtual s32 vfunc_24(void *, s32);
    virtual s32 vfunc_28(void);
    virtual s32 vfunc_58(void);
    virtual void vfunc_a0(void);
    virtual void vfunc_a8(void);
    virtual void vfunc_e8(void);
    virtual void vfunc_ec(void);
    virtual void vfunc_120(void);
    virtual void vfunc_124(void);
    virtual void vfunc_130(/* ? */); // func_ov005_02206800
    virtual void vfunc_134(/* ? */); // func_ov005_02206814
};

class MIS_SallyEnd : public MenuItem
{
    virtual char * vfunc_00(void);
    virtual s32 vfunc_10(MenuItemState *);
    virtual s32 vfunc_14(void);
    virtual s32 vfunc_24(Menu *, MenuItemState *);
    virtual void vfunc_70(void);
};

class MIS_SallySave : public MenuItem
{
    virtual char * vfunc_00(void);
    virtual s32 vfunc_14(void);
    virtual s32 vfunc_20(MenuItemState *);
    virtual void vfunc_70(void);
};

class MIS_Config : public MenuItem
{
    virtual char * vfunc_00(void);
    virtual s32 vfunc_14(void);
    virtual s32 vfunc_1c(void);
    virtual void vfunc_70(void);
};

class MIS_WeaponShop : public MenuItem
{
    virtual char * vfunc_00(void);
    virtual s32 vfunc_14(void);
    virtual s32 vfunc_1c(void);
    virtual void vfunc_70(void);
};

class MIS_JobSlide : public MenuItem
{
    virtual char * vfunc_00(void);
    virtual s32 vfunc_14(void);
    virtual s32 vfunc_1c(void);
    virtual void vfunc_70(void);
};

class MIS_ItemSetting : public MenuItem
{
    virtual char * vfunc_00(void);
    virtual s32 vfunc_14(void);
    virtual s32 vfunc_1c(void);
    virtual void vfunc_70(void);
};

class MIS_PosChange : public MenuItem
{
    virtual char * vfunc_00(void);
    virtual s32 vfunc_14(void);
    virtual s32 vfunc_1c(void);
    virtual void vfunc_70(void);
};

class MIS_SallySelect : public MenuItem
{
    virtual char * vfunc_00(void);
    virtual s32 vfunc_14(void);
    virtual s32 vfunc_1c(void);
    virtual void vfunc_70(void);
};

class DI_SallyCancelYes : public DialogItemYes
{
public:
    virtual s32 vfunc_1c(void);
};

class DI_SallyCancelNo : public DialogItemNo
{
};

class DI_SallyEndYes : public DialogItemYes
{
public:
    virtual s32 vfunc_1c(void);
};

class DI_SallyEndNo : public DialogItemNo
{
public:
    virtual s32 vfunc_1c(void);
};

} // namespace sally

class UnkStruct_02217560
{
public:
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    STRUCT_PAD(0x0C, 0x10);
    u8 unk_10;
    u8 unk_11;
    STRUCT_PAD(0x12, 0x14);
    u32 unk_14;
    STRUCT_PAD(0x18, 0x20);
    u32 unk_20;

    UnkStruct_02217560()
    {
        this->unk_00 = -1;
        this->unk_04 = -1;
        this->unk_10 = 0;
        this->unk_11 = 0;
        this->unk_20 = -1;
    }
};

extern UnkStruct_02217560 * data_ov005_02217560;

extern u16 data_021970c4[];

namespace sally
{

class MMenuConst
{
};

class MMenu : public ProcEx, public MMenuConst
{
public:
    SallyMenu * unk_38;
    Button * unk_3c;
    Button * unk_40;
    u32 unk_44;
    u32 unk_48;

    MMenu()
    {
        ScreenState * iVar3;

        if (data_ov005_02217560->unk_11 != 0)
        {
            func_0204ac18();

            iVar3 = gpActiveScreenSt;
            gpActiveScreenSt = gpSubScreenSt;

            func_02010c84(0);
            func_02050aa8(this, 3, 0xc);
            func_0202a4dc(1, 0);

            func_020295ec(
                data_021970c4, func_02039e10("MTHL_編成"), gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1],
                2, 0x15, 0x18c, 1, 0, 0);

            gpActiveScreenSt->unk_3e |= 2;

            func_020a8f40("/troop");

            func_0201177c("sub.cg", (u32)gpActiveScreenSt->bgTiles[3]);
            func_0201177c("sub.sc", (u32)gpActiveScreenSt->tilemap[3]);

            func_02011a70("sub.cl", 0x40, 0, 0);

            func_02010d98(gpActiveScreenSt->tilemap[2], 0x600, 0, 2);

            gpActiveScreenSt->unk_3e |= 4;

            func_02051410(this, 2, 0, 0);

            gpActiveScreenSt = iVar3;
        }

        func_ov005_02204c20(this, 1);

        func_0202a4dc(1, 0);
        func_0202a4dc(0x13, 0);

        func_0202b294(gpActiveScreenSt->tilemap[0], 0, 0);
        func_0202b688(gpActiveScreenSt->bgTiles[0], 0, 0, 0);

        func_020a8f40("/sally");

        func_0201177c("sallymenu.cg", (u32)gpActiveScreenSt->bgTiles[3]);

        if (data_ov005_02217560->unk_11 != 0)
        {
            func_0201177c("sallymenu.sc", (u32)gpActiveScreenSt->tilemap[3]);
        }
        else
        {
            func_0201177c("sallytroopmenu.sc", (u32)gpActiveScreenSt->tilemap[3]);
        }

        func_02011a70("sallymenu.cl", 0x40, 0, 0);

        func_02010d98(gpActiveScreenSt->tilemap[2], 0x600, 0, 2);

        gpActiveScreenSt->unk_3e |= 4;

        this->unk_3c = StartButton(this, BUTTON_KIND_START_START, 8, 1, 2);
        this->unk_3c->SetPosition(0x70, 0);
        this->unk_3c->func_020354bc(0);

        this->unk_40 = NULL;

        if (data_ov005_02217560->unk_11 != 0)
        {
            this->unk_3c->SetPosition(0x38, 0);

            this->unk_40 = StartButton(this, BUTTON_KIND_B_CANCEL, 0x14, 1, 2);
            this->unk_40->SetPosition(0x70, 0);
            this->unk_40->func_020354bc(0);
        }

        this->unk_44 = func_0202a564(1);

        func_0202972c(
            data_021970c4, func_02039e10("MSH_コマンド"), gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1],
            0xf, 0x12, 0x170, 1, 0x70, 0x70, 0);

        gpActiveScreenSt->unk_3e |= 2;

        this->unk_48 = 0;

        if (data_ov005_02217560->unk_11 == 0)
        {
            if ((data_02196f20->flagMgr->GetById(0x17)) && (!(data_02196f0c->state & 0x40000)))
            {
                return;
            }

            if (data_02196f24->enableTutorials)
            {
                func_0205038c(0x17, -1);
                func_02050494(this, 0, 0);
            }

            data_02196f20->flagMgr->SetById(0x17);
            data_02196f0c->state |= 0x40000;
        }
    }

    virtual ~MMenu()
    {
        func_0202a5a8(this->unk_44);

        if (data_ov005_02217560->unk_11 != 0)
        {
            func_0204aca8();
        }
        else
        {
            func_0204b260(0);
        }
    }
};

EC sally::MMenu * GetSallyMMenu(void);

class SallyDialogYesNo : public DialogYesNo
{
public:
    // vtable

    // 04 - 48: Menu

    STRUCT_PAD(0x50, 0x5C);

    SallyDialogYesNo()
    {
        if (data_ov005_02217560->unk_11 == 0)
        {
            func_02034930(1, 8, -1);
        }
        else
        {
            GetSallyMMenu()->unk_3c->func_020354bc(0);
            GetSallyMMenu()->unk_3c->SetVisible(1);
        }
    }

    virtual void vfunc_00(void);
    virtual void vfunc_a0(void);
    virtual void vfunc_c0(void);
    virtual void vfunc_130(/* ? */); // func_ov005_02206700
    virtual void vfunc_134(/* ? */); // func_ov005_0220673c
};

class SallyCancelDialogYesNo : public SallyDialogYesNo
{
    virtual void vfunc_c0(void);
    virtual void vfunc_130(/* ? */); // func_ov005_02206780
    virtual void vfunc_134(/* ? */); // func_ov005_022067bc
};

} // namespace sally

EC sally::MMenu * GetSallyMMenu(void);

EC void func_ov005_02205518(char * str)
{
    sally::MMenu * proc = GetSallyMMenu();
    proc->unk_48 = (proc->unk_48 + 1) & 1;

    func_02010f98(gpActiveScreenSt->tilemap[3] + 0xcf, 0xe, 0xc);
    func_020295ec(
        data_021970c4, str, gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0xf, 6,
        proc->unk_48 * 0xa8 + 0x20, 1, 0, 0);
    gpActiveScreenSt->unk_3e |= 2;
    return;
}

EC void func_020303bc(DialogYesNo *, char *, void *, ProcPtr, s32, s32);

EC void func_ov005_022055d8(sally::MMenu * proc)
{
    static sally::DI_SallyEndYes sSallyEndYes;
    static sally::DI_SallyEndNo sSallyEndNo;

    // clang-format off
    static DialogItem * data_ov005_022132a0[] =
    {
        &sSallyEndYes,
        &sSallyEndNo,
    };
    // clang-format on

    sally::SallyDialogYesNo * puVar1 = new sally::SallyDialogYesNo();

    func_020303bc(puVar1, func_02039e10("MD_進撃終了"), data_ov005_022132a0, proc, 1, 0);

    return;
}

EC void func_ov005_022056d8(sally::MMenu * proc)
{
    static sally::DI_SallyCancelYes sSallyCancelYes;
    static sally::DI_SallyEndNo sSallyEndNo;

    // clang-format off
    static DialogItem * data_ov005_02213294[] =
    {
        &sSallyCancelYes,
        &sSallyEndNo,
    };
    // clang-format on

    sally::SallyCancelDialogYesNo * puVar1 = new sally::SallyCancelDialogYesNo();

    func_020303bc(puVar1, func_02039e10("MD_編成中止"), data_ov005_02213294, proc, 1, 0);

    return;
}

EC void func_0202fb38(Menu *, void *, ProcPtr, u32, u32);

// TODO: Member function
EC void func_ov005_022057e4(sally::MMenu * proc)
{
    static sally::MIS_SallySelect sSallySelect;
    static sally::MIS_PosChange sPosChange;
    static sally::MIS_ItemSetting sItemSetting;
    static sally::MIS_JobSlide sJobSlide;
    static sally::MIS_WeaponShop sWeaponShop;
    static sally::MIS_Config sConfig;
    static sally::MIS_SallySave sSallySave;
    static sally::MIS_SallyEnd sSallyEnd;

    // clang-format off
    static MenuItem * data_ov005_022132ac[] =
    {
        &sSallySelect,
        &sPosChange,
        &sItemSetting,
        &sJobSlide,
        &sWeaponShop,
        &sConfig,
        &sSallySave,
        &sSallyEnd,
    };
    // clang-format on

    proc->unk_38 = new sally::SallyMenu();
    func_0202fb38(proc->unk_38, data_ov005_022132ac, proc, 0, 0);
    proc->unk_38->unk_43 = 0;

    return;
}

// TODO: Member function
EC void func_ov005_02205960(sally::MMenu * proc)
{
    proc->unk_38->unk_43 = 2;

    proc->unk_3c->func_020354a0();

    if (proc->unk_40 != NULL)
    {
        proc->unk_40->func_020354a0();
    }

    Proc_Lock((struct Proc *)proc);

    return;
}

// func_ov005_02205998
// TODO: Member function
EC void func_ov005_02205998(sally::MMenu * proc)
{
    proc->unk_38->unk_43 = 0;

    proc->unk_3c->func_020354bc(0);

    if (proc->unk_40 != NULL)
    {
        proc->unk_40->func_020354bc(0);
    }

    return;
}

EC void func_ov005_022059cc(sally::MMenu * proc)
{
    func_ov005_02205998(proc);
    return;
}

EC void func_ov005_022059d8(sally::MMenu * proc)
{
    func_ov005_02205960(proc);
    return;
}

EC void func_ov005_022059e4(sally::MMenu * proc)
{
    func_ov005_022057e4(proc);
    return;
}

// clang-format off

struct ProcCmd ProcScr_Sally_MMenu[] =
{
    PROC_NAME,
    PROC_SLEEP(0),
    PROC_CALL(func_ov005_022059e4),
    PROC_FADE_FROM_BLACK(8, 1, TRUE),
    PROC_CALL(func_ov005_022059d8),
    PROC_CALL(func_ov005_022059cc),
    PROC_FADE_TO_BLACK(8, 1, TRUE),
    PROC_END,
};

// clang-format on

EC sally::MMenu * GetSallyMMenu(void)
{
    return static_cast<sally::MMenu *>(Proc_Find(ProcScr_Sally_MMenu));
}

EC void StartSally_MMenu(ProcPtr param_1)
{
    new (Proc_StartBlocking(ProcScr_Sally_MMenu, param_1)) sally::MMenu();
    return;
}

s32 sally::MIS_SallyEnd::vfunc_24(Menu * param_2, MenuItemState * param_3)
{
    if ((param_3->unk_09 & 7) != 1)
    {
        func_ov005_022055d8(static_cast<sally::MMenu *>(param_2->unk_10));
        return 0x40;
    }

    return 0x100;
}

void sally::MIS_SallyEnd::vfunc_70(void)
{
    if (data_ov005_02217560->unk_11 != 0)
    {
        func_ov005_02205518(func_02039e10("MSH_編成終了"));
    }
    else
    {
        func_ov005_02205518(func_02039e10("MSH_開始"));
    }

    return;
}

s32 sally::MIS_SallyEnd::vfunc_14(void)
{
    s32 uVar1 = 0;

    if (data_ov005_02217560->unk_11 == 0)
    {
        return 0;
    }

    if (Force::Get(0)->Count() == 0)
    {
        uVar1 = 1;
    }

    return uVar1;
}

s32 sally::MIS_SallyEnd::vfunc_10(MenuItemState * param_2)
{
    if ((param_2->unk_09 & 7) == 1)
    {
        return 2;
    }

    return 5;
}

char * sally::MIS_SallyEnd::vfunc_00(void)
{
    if (data_ov005_02217560->unk_11 != 0)
    {
        return func_02039e10("MSM_編成終了");
    }
    else
    {
        return func_02039e10("MSM_開始");
    }
}

s32 sally::MIS_SallySave::vfunc_20(MenuItemState * param_2)
{
    if ((param_2->unk_09 & 7) != 1)
    {
        data_ov005_02217560->unk_08 = 8;
        func_ov005_022054b0(8);
        return 0x41;
    }

    return 0x100;
}

void sally::MIS_SallySave::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_記録"));
    return;
}

EC s32 func_0201f680(void);

s32 sally::MIS_SallySave::vfunc_14(void)
{
    u32 uVar1;

    if (data_ov005_02217560->unk_11 != 0)
    {
        return 2;
    }

    if (func_0201f680())
    {
        uVar1 = 0;
    }
    else
    {
        uVar1 = 1;
    }

    if (data_ov005_02217560->unk_08 == 8)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

char * sally::MIS_SallySave::vfunc_00(void)
{
    return func_02039e10("MSM_記録");
}

s32 sally::MIS_Config::vfunc_1c(void)
{
    data_ov005_02217560->unk_08 = 7;
    func_ov005_022054b0(7);
    return 0x41;
}

void sally::MIS_Config::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_環境"));
    return;
}

s32 sally::MIS_Config::vfunc_14(void)
{
    u32 uVar1 = 0;

    if (data_ov005_02217560->unk_11 != 0)
    {
        return 2; // Not shown
    }

    if (data_ov005_02217560->unk_08 == 7)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

char * sally::MIS_Config::vfunc_00(void)
{
    return func_02039e10("MSM_環境");
}

s32 sally::MIS_WeaponShop::vfunc_1c(void)
{
    data_ov005_02217560->unk_08 = 6;
    func_ov005_022054b0(6);
    return 0x41;
}

void sally::MIS_WeaponShop::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_武器屋"));
    return;
}

s32 sally::MIS_WeaponShop::vfunc_14(void)
{
    u32 uVar1 = 0;

    if (data_ov005_02217560->unk_11 != 0)
    {
        return 2; // Not shown
    }

    if (data_ov005_02217560->unk_08 == 6)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

char * sally::MIS_WeaponShop::vfunc_00(void)
{
    return func_02039e10("MSM_武器屋");
}

s32 sally::MIS_JobSlide::vfunc_1c(void)
{
    data_ov005_02217560->unk_10 = 1;
    data_ov005_02217560->unk_08 = 5;
    func_ov005_022054b0(5);
    return 0x41;
}

void sally::MIS_JobSlide::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_兵種変更"));
    return;
}

s32 sally::MIS_JobSlide::vfunc_14(void)
{
    u32 uVar1 = 0;

    if (data_ov005_02217560->unk_08 == 5)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

char * sally::MIS_JobSlide::vfunc_00(void)
{
    return func_02039e10("MSM_兵種変更");
}

s32 sally::MIS_ItemSetting::vfunc_1c(void)
{
    data_ov005_02217560->unk_10 = 1;
    data_ov005_02217560->unk_08 = 4;
    func_ov005_022054b0(4);
    return 0x41;
}

void sally::MIS_ItemSetting::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_持ち物"));
    return;
}

s32 sally::MIS_ItemSetting::vfunc_14(void)
{
    u32 uVar1 = 0;

    if (data_ov005_02217560->unk_08 == 4)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

char * sally::MIS_ItemSetting::vfunc_00(void)
{
    return func_02039e10("MSM_持ち物");
}

s32 sally::MIS_PosChange::vfunc_1c(void)
{
    data_ov005_02217560->unk_08 = 3;
    func_ov005_022054b0(3);
    return 0x41;
}

void sally::MIS_PosChange::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_マップ"));
    return;
}

s32 sally::MIS_PosChange::vfunc_14(void)
{
    u32 uVar1 = 0;

    if (data_ov005_02217560->unk_11 != 0)
    {
        return 2;
    }

    if (data_ov005_02217560->unk_08 == 3)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

char * sally::MIS_PosChange::vfunc_00(void)
{
    return func_02039e10("MSM_マップ");
}

s32 sally::MIS_SallySelect::vfunc_1c(void)
{
    data_ov005_02217560->unk_10 = 1;
    data_ov005_02217560->unk_08 = 2;
    func_ov005_022054b0(2);
    return 0x41;
}

void sally::MIS_SallySelect::vfunc_70(void)
{
    if (data_ov005_02217560->unk_11 != 0)
    {
        func_ov005_02205518(func_02039e10("MSH_ユニット編成"));
    }
    else
    {
        func_ov005_02205518(func_02039e10("MSH_ユニット"));
    }

    return;
}

s32 sally::MIS_SallySelect::vfunc_14(void)
{
    u32 uVar1 = 0;

    if (data_ov005_02217560->unk_08 == 2)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

char * sally::MIS_SallySelect::vfunc_00(void)
{
    return func_02039e10("MSM_ユニット");
}

void sally::SallyMenu::vfunc_a0(void)
{
    if (GetSallyMMenu()->unk_40 != NULL)
    {
        GetSallyMMenu()->unk_40->func_02035450();
    }

    return;
}

void sally::SallyMenu::vfunc_a8(void)
{
    GetSallyMMenu()->unk_3c->func_02035450();
    return;
}

s32 sally::SallyMenu::vfunc_58(void)
{
    if (data_ov005_02217560->unk_11 != 0)
    {
        if (Force::Get(0)->Count() == 0)
        {
            return 0x100;
        }
    }

    func_ov005_022055d8(static_cast<sally::MMenu *>(this->unk_10));

    return 0x40;
}

s32 sally::SallyMenu::vfunc_28(void)
{
    if (data_ov005_02217560->unk_11 != 0)
    {
        func_ov005_022056d8(static_cast<sally::MMenu *>(this->unk_10));
        return 0x80;
    }

    return 0;
}

s32 sally::SallyMenu::vfunc_24(void * param_2, s32 param_3)
{
    if (!((param_3 & 0x3f) == 0 ? TRUE : FALSE))
    {
        Proc_Release((struct Proc *)GetSallyMMenu());
        return 0x40;
    }

    return param_3;
}

void sally::SallyMenu::vfunc_124(void)
{
    Proc_Break(this->unk_10, 0);
    return;
}

void sally::SallyMenu::vfunc_120(void)
{
    this->unk_0c[this->unk_38].unk_00->vfunc_b4(this, &this->unk_0c[this->unk_38]);
    Proc_Break(this->unk_10, 1);
    return;
}

void sally::SallyMenu::vfunc_ec(void)
{
    return;
}

void sally::SallyMenu::vfunc_e8(void)
{
    return;
}

void sally::SallyMenu::vfunc_00(void)
{
    this->unk_2c = 1;
    this->unk_14 = 0x18c;
    this->unk_18 = 1;
    this->unk_30 = 2;
    this->unk_1c = 0;
    this->unk_20 = 2;
    this->unk_24 = 0;
    this->unk_28 = 0;
    this->unk_41 = 2;
    this->unk_42 = 2;
    this->unk_34 = 1;

    if (data_ov005_02217560->unk_11 != 0)
    {
        this->unk_35 = 8;
    }
    else
    {
        this->unk_35 = 4;
    }

    this->unk_36 = 0xb;
    this->unk_40 = 1;

    return;
}

s32 sally::DI_SallyEndNo::vfunc_1c(void)
{
    if (data_ov005_02217560->unk_11 == 0)
    {
        func_02034930(3, 8, -1);
    }
    else
    {
        GetSallyMMenu()->unk_3c->func_020354a0();
        GetSallyMMenu()->unk_3c->SetVisible(0);
    }

    return 0x81;
}

s32 sally::DI_SallyCancelYes::vfunc_1c(void)
{
    Proc_Release((struct Proc *)GetSallyMMenu());
    func_ov005_022054b0(13);
    return 0x1041;
}

s32 sally::DI_SallyEndYes::vfunc_1c(void)
{
    Proc_Release((struct Proc *)GetSallyMMenu());
    func_ov005_022054b0(9);
    return 0x1041;
}

void sally::SallyDialogYesNo::vfunc_a0(void)
{
    if (GetSallyMMenu()->unk_40 != NULL)
    {
        GetSallyMMenu()->unk_40->func_02035450();
        return;
    }

    GetSallyMMenu()->unk_3c->func_02035450();

    return;
}

void sally::SallyDialogYesNo::vfunc_00(void)
{
    this->unk_48 = 1;
    this->unk_40 = 1;
    this->unk_14 = 0x20;
    this->unk_18 = 3;
    this->unk_30 = 0;
    this->unk_1c = 0;
    this->unk_20 = 0;
    this->unk_24 = 0;
    this->unk_28 = 0;

    return;
}

void sally::SallyCancelDialogYesNo::vfunc_c0(void)
{
    data_020efcc8->unk_b0->vfunc_28(0x10016, 0, 0);
    return;
}

void sally::SallyDialogYesNo::vfunc_c0(void)
{
    data_020efcc8->unk_b0->vfunc_28(0x1000a, 0, 0);
    return;
}
