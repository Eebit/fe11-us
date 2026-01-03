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

    virtual void vfunc_00(void); // func_ov005_02206488
    virtual s32 vfunc_24(void *, s32); // func_ov005_02206400
    virtual s32 vfunc_28(void); // func_ov005_022063d0
    virtual s32 vfunc_58(void); // func_ov005_02206388
    virtual void vfunc_a0(void); // func_ov005_0220634c
    virtual void vfunc_a8(void); // func_ov005_02206374
    virtual void vfunc_e8(void); // func_ov005_02206484
    virtual void vfunc_ec(void); // func_ov005_02206480
    virtual void vfunc_120(void); // func_ov005_02206440
    virtual void vfunc_124(void); // func_ov005_0220642c
    virtual void vfunc_130(/* ? */); // func_ov005_02206800
    virtual void vfunc_134(/* ? */); // func_ov005_02206814
};

class MIS_SallyEnd : public MenuItem
{
    virtual char * vfunc_00(void); // func_ov005_02205f44
    virtual s32 vfunc_10(MenuItemState *); // func_ov005_02205f2c; GetLabelColor? (1 = White, 2 = Grey, 3 = Cyan, 4 = Gold, 5 = Green)
    virtual s32 vfunc_14(void); // func_ov005_02205ef0
    virtual s32 vfunc_24(Menu *, MenuItemState *); // func_ov005_02205e84; OnConfirm (touch or press)?
    virtual void vfunc_70(void); // func_ov005_02205eac
};

class MIS_SallySave : public MenuItem
{
    virtual char * vfunc_00(void); // func_ov005_02206018
    virtual s32 vfunc_14(void); // func_ov005_02205fd0
    virtual s32 vfunc_20(MenuItemState *); // func_ov005_02205f80
    virtual void vfunc_70(void); // func_ov005_02205fb8
};

class MIS_Config : public MenuItem
{
    virtual char * vfunc_00(void); // func_ov005_02206098; GetLabel
    virtual s32 vfunc_14(void); // func_ov005_02206068
    virtual s32 vfunc_1c(void); // func_ov005_0220602c; OnConfirm
    virtual void vfunc_70(void); // func_ov005_02206050; OnHover?
};

class MIS_WeaponShop : public MenuItem
{
    virtual char * vfunc_00(void); // func_ov005_02206118
    virtual s32 vfunc_14(void); // func_ov005_022060e8
    virtual s32 vfunc_1c(void); // func_ov005_022060ac
    virtual void vfunc_70(void); // func_ov005_022060d0
};

class MIS_JobSlide : public MenuItem
{
    virtual char * vfunc_00(void); // func_ov005_02206194
    virtual s32 vfunc_14(void); // func_ov005_02206174
    virtual s32 vfunc_1c(void); // func_ov005_0220612c
    virtual void vfunc_70(void); // func_ov005_0220615c
};

class MIS_ItemSetting : public MenuItem
{
    virtual char * vfunc_00(void); // func_ov005_02206210
    virtual s32 vfunc_14(void); // func_ov005_022061f0
    virtual s32 vfunc_1c(void); // func_ov005_022061a8
    virtual void vfunc_70(void); // func_ov005_022061d8
};

class MIS_PosChange : public MenuItem
{
    virtual char * vfunc_00(void); // func_ov005_02206290
    virtual s32 vfunc_14(void); // func_ov005_02206260
    virtual s32 vfunc_1c(void); // func_ov005_02206224
    virtual void vfunc_70(void); // func_ov005_02206248
};

class MIS_SallySelect : public MenuItem
{
    virtual char * vfunc_00(void); // func_ov005_02206338
    virtual s32 vfunc_14(void); // func_ov005_02206318
    virtual s32 vfunc_1c(void); // func_ov005_022062a4
    virtual void vfunc_70(void); // func_ov005_022062d4
};

class DI_SallyCancelYes : public DialogItemYes
{
public:
    virtual s32 vfunc_1c(void); // func_ov005_0220654c
};

class DI_SallyCancelNo : public DialogItemNo
{
};

class DI_SallyEndYes : public DialogItemYes
{
public:
    virtual s32 vfunc_1c(void); // func_ov005_0220656c
};

class DI_SallyEndNo : public DialogItemNo
{
public:
    virtual s32 vfunc_1c(void); // func_ov005_022064f8
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

EC void func_0202b294(void *, u32, u32);
EC void func_0202b688(void *, u32, u32, u32);
EC void func_0202a5a8(u32);
EC u32 func_0202a564(u32);
EC void func_0202a4dc(s32, s32);
EC void func_02010d98(void *, u32, u32, u32);
EC void func_02051410(ProcPtr, u32, u32, u32);
EC void func_02050494(ProcPtr, u32, u32);

EC void func_ov005_02204c20(ProcPtr, u32);

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

    // func_ov005_02206660
    // func_ov005_022066b4
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

EC sally::MMenu * func_ov005_022059f0(void);

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
            func_ov005_022059f0()->unk_3c->func_020354bc(0);
            func_ov005_022059f0()->unk_3c->SetVisible(1);
        }
    }

    virtual void vfunc_00(void); // func_ov005_022065c0
    virtual void vfunc_a0(void); // func_ov005_0220658c
    virtual void vfunc_c0(void); // func_ov005_0220662c
    virtual void vfunc_130(/* ? */); // func_ov005_02206700
    virtual void vfunc_134(/* ? */); // func_ov005_0220673c
};

class SallyCancelDialogYesNo : public SallyDialogYesNo
{
    virtual void vfunc_c0(void); // func_ov005_022065f8
    virtual void vfunc_130(/* ? */); // func_ov005_02206780
    virtual void vfunc_134(/* ? */); // func_ov005_022067bc
};

} // namespace sally

EC sally::MMenu * func_ov005_022059f0(void);
EC void func_02010f98(void *, u32, u32);

EC void func_ov005_02205518(char * str)
{
    sally::MMenu * proc = func_ov005_022059f0();
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

struct ProcCmd data_ov005_02213598[] =
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

EC sally::MMenu * func_ov005_022059f0(void)
{
    return static_cast<sally::MMenu *>(Proc_Find(data_ov005_02213598));
}

EC void StartSally_MMenu(ProcPtr param_1)
{
    new (Proc_StartBlocking(data_ov005_02213598, param_1)) sally::MMenu();
    return;
}

// func_ov005_02205e84
s32 sally::MIS_SallyEnd::vfunc_24(Menu * param_2, MenuItemState * param_3)
{
    if ((param_3->unk_09 & 7) != 1)
    {
        func_ov005_022055d8(static_cast<sally::MMenu *>(param_2->unk_10));
        return 0x40;
    }

    return 0x100;
}

// func_ov005_02205eac
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

// func_ov005_02205ef0
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

// func_ov005_02205f2c
s32 sally::MIS_SallyEnd::vfunc_10(MenuItemState * param_2)
{
    if ((param_2->unk_09 & 7) == 1)
    {
        return 2;
    }

    return 5;
}

// func_ov005_02205f44
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

// func_ov005_02205f80
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

// func_ov005_02205fb8
void sally::MIS_SallySave::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_記録"));
    return;
}

EC s32 func_0201f680(void);

// func_ov005_02205fd0
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

// func_ov005_02206018
char * sally::MIS_SallySave::vfunc_00(void)
{
    return func_02039e10("MSM_記録");
}

// func_ov005_0220602c
s32 sally::MIS_Config::vfunc_1c(void)
{
    data_ov005_02217560->unk_08 = 7;
    func_ov005_022054b0(7);
    return 0x41;
}

// func_ov005_02206050
void sally::MIS_Config::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_環境"));
    return;
}

// func_ov005_02206068
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

// func_ov005_02206098
char * sally::MIS_Config::vfunc_00(void)
{
    return func_02039e10("MSM_環境");
}

// func_ov005_022060ac
s32 sally::MIS_WeaponShop::vfunc_1c(void)
{
    data_ov005_02217560->unk_08 = 6;
    func_ov005_022054b0(6);
    return 0x41;
}

// func_ov005_022060d0
void sally::MIS_WeaponShop::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_武器屋"));
    return;
}

// func_ov005_022060e8
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

// func_ov005_02206118
char * sally::MIS_WeaponShop::vfunc_00(void)
{
    return func_02039e10("MSM_武器屋");
}

// func_ov005_0220612c
s32 sally::MIS_JobSlide::vfunc_1c(void)
{
    data_ov005_02217560->unk_10 = 1;
    data_ov005_02217560->unk_08 = 5;
    func_ov005_022054b0(5);
    return 0x41;
}

// func_ov005_0220615c
void sally::MIS_JobSlide::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_兵種変更"));
    return;
}

// func_ov005_02206174
s32 sally::MIS_JobSlide::vfunc_14(void)
{
    u32 uVar1 = 0;

    if (data_ov005_02217560->unk_08 == 5)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

// func_ov005_02206194
char * sally::MIS_JobSlide::vfunc_00(void)
{
    return func_02039e10("MSM_兵種変更");
}

// func_ov005_022061a8
s32 sally::MIS_ItemSetting::vfunc_1c(void)
{
    data_ov005_02217560->unk_10 = 1;
    data_ov005_02217560->unk_08 = 4;
    func_ov005_022054b0(4);
    return 0x41;
}

// func_ov005_022061d8
void sally::MIS_ItemSetting::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_持ち物"));
    return;
}

// func_ov005_022061f0
s32 sally::MIS_ItemSetting::vfunc_14(void)
{
    u32 uVar1 = 0;

    if (data_ov005_02217560->unk_08 == 4)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

// func_ov005_02206210
char * sally::MIS_ItemSetting::vfunc_00(void)
{
    return func_02039e10("MSM_持ち物");
}

// func_ov005_02206224
s32 sally::MIS_PosChange::vfunc_1c(void)
{
    data_ov005_02217560->unk_08 = 3;
    func_ov005_022054b0(3);
    return 0x41;
}

// func_ov005_02206248
void sally::MIS_PosChange::vfunc_70(void)
{
    func_ov005_02205518(func_02039e10("MSH_マップ"));
    return;
}

// func_ov005_02206260
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

// func_ov005_02206290
char * sally::MIS_PosChange::vfunc_00(void)
{
    return func_02039e10("MSM_マップ");
}

// func_ov005_022062a4
s32 sally::MIS_SallySelect::vfunc_1c(void)
{
    data_ov005_02217560->unk_10 = 1;
    data_ov005_02217560->unk_08 = 2;
    func_ov005_022054b0(2);
    return 0x41;
}

// func_ov005_022062d4
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

// func_ov005_02206318
s32 sally::MIS_SallySelect::vfunc_14(void)
{
    u32 uVar1 = 0;

    if (data_ov005_02217560->unk_08 == 2)
    {
        uVar1 |= 8;
    }

    return uVar1;
}

// func_ov005_02206338
char * sally::MIS_SallySelect::vfunc_00(void)
{
    return func_02039e10("MSM_ユニット");
}

// func_ov005_0220634c
void sally::SallyMenu::vfunc_a0(void)
{
    if (func_ov005_022059f0()->unk_40 != NULL)
    {
        func_ov005_022059f0()->unk_40->func_02035450();
    }

    return;
}

// func_ov005_02206374
void sally::SallyMenu::vfunc_a8(void)
{
    func_ov005_022059f0()->unk_3c->func_02035450();
    return;
}

// func_ov005_02206388
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

// func_ov005_022063d0
s32 sally::SallyMenu::vfunc_28(void)
{
    if (data_ov005_02217560->unk_11 != 0)
    {
        func_ov005_022056d8(static_cast<sally::MMenu *>(this->unk_10));
        return 0x80;
    }

    return 0;
}

// func_ov005_02206400
s32 sally::SallyMenu::vfunc_24(void * param_2, s32 param_3)
{
    if (!((param_3 & 0x3f) == 0 ? TRUE : FALSE))
    {
        Proc_Release((struct Proc *)func_ov005_022059f0());
        return 0x40;
    }

    return param_3;
}

// func_ov005_0220642c
void sally::SallyMenu::vfunc_124(void)
{
    Proc_Break(this->unk_10, 0);
    return;
}

// func_ov005_02206440
void sally::SallyMenu::vfunc_120(void)
{
    // int * piVar1;
    // piVar1 = param_1->unk_0c + param_1->unk_38 * 0xc;
    this->unk_0c[this->unk_38].unk_00->vfunc_b4(this, &this->unk_0c[this->unk_38]);
    Proc_Break(this->unk_10, 1);
    return;
}

// func_ov005_02206480
void sally::SallyMenu::vfunc_ec(void)
{
    return;
}

// func_ov005_02206484
void sally::SallyMenu::vfunc_e8(void)
{
    return;
}

// func_ov005_02206488
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

// func_ov005_022064f8
s32 sally::DI_SallyEndNo::vfunc_1c(void)
{
    if (data_ov005_02217560->unk_11 == 0)
    {
        func_02034930(3, 8, -1);
    }
    else
    {
        func_ov005_022059f0()->unk_3c->func_020354a0();
        func_ov005_022059f0()->unk_3c->SetVisible(0);
    }

    return 0x81;
}

// func_ov005_0220654c
s32 sally::DI_SallyCancelYes::vfunc_1c(void)
{
    Proc_Release((struct Proc *)func_ov005_022059f0());
    func_ov005_022054b0(13);
    return 0x1041;
}

// func_ov005_0220656c
s32 sally::DI_SallyEndYes::vfunc_1c(void)
{
    Proc_Release((struct Proc *)func_ov005_022059f0());
    func_ov005_022054b0(9);
    return 0x1041;
}

// func_ov005_0220658c
void sally::SallyDialogYesNo::vfunc_a0(void)
{
    if (func_ov005_022059f0()->unk_40 != NULL)
    {
        func_ov005_022059f0()->unk_40->func_02035450();
        return;
    }

    func_ov005_022059f0()->unk_3c->func_02035450();

    return;
}

// func_ov005_022065c0
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

// func_ov005_022065f8
void sally::SallyCancelDialogYesNo::vfunc_c0(void)
{
    data_020efcc8->unk_b0->vfunc_28(0x10016, 0, 0);
    return;
}

// func_ov005_0220662c
void sally::SallyDialogYesNo::vfunc_c0(void)
{
    data_020efcc8->unk_b0->vfunc_28(0x1000a, 0, 0);
    return;
}
