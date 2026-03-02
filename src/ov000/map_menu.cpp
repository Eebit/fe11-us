#include "global.h"

#include "hardware.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "sound_manager.hpp"

#include "constants/sounds.h"

#include "unknown_funcs.h"
#include "unknown_types.hpp"

struct UnkStruct_021970c4
{
    void * unk_00;
    void * unk_04;
    void * unk_08;
    void * unk_0c;
    void * unk_10;
    void * unk_14;
};

extern struct UnkStruct_021970c4 * data_021970c4;
extern struct UnkStruct_021970c4 * data_021970cc;

extern struct UnkStruct_02196f24 * data_02196f24;

extern struct UnkStruct_02196f20 * data_02196f20;

extern struct UnkStruct_02196f10 * data_02196f10;

EC void func_0202b260(void *, s32, s32, s32, s32);
EC BOOL func_0201f680(void);
EC BOOL func_0202dad0(MenuItemState * menuItemState, Menu * menu);

EC void func_ov000_021be21c(void);
EC void func_ov000_021beaf4(ProcPtr);
EC void func_ov000_021beb94(ProcPtr);
EC void func_ov000_021d6a9c(char *, s32);
EC void PlayerPhase_GotoLabel(s32, s32, s32);

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

namespace map
{

class BMapDialogYesNo : public DialogYesNo
{
public:
    /* 000 */ virtual void vfunc_00(void); // func_ov000_021be6d8
    /* 0A0 */ virtual BOOL vfunc_a0(void); // func_ov000_021be934
    /* 0AC */ virtual s32 vfunc_ac(void); // func_ov000_021be91c
    /* 130 */ virtual void vfunc_130(/* ? */); // func_ov000_021bea74
    /* 134 */ virtual void vfunc_134(/* ? */); // func_ov000_021beab0
};

class BMapMenu : public Menu
{
public:
    /* 008 */ virtual void vfunc_08(void); // func_ov000_021be588
    /* 01C */ virtual void vfunc_1c(void); // func_ov000_021be640
    /* 0A0 */ virtual BOOL vfunc_a0(void); // func_ov000_021be978
    /* 0AC */ virtual s32 vfunc_ac(void); // func_ov000_021be960

    virtual ~BMapMenu()
    {
        if (this->unk_04 == NULL)
        {
            gpActiveScreenSt->dispIo->bldcnt.effect = 0;
        }
    }
};

class MI_Separator : public MenuItem
{
public:
    // func_ov000_021bf8b4
    /* C4 */ virtual u32 vfunc_c4(void)
    {
        return 0;
    }

    // func_ov000_021bf8ac
    /* CC */ virtual u32 vfunc_cc(void)
    {
        return 1;
    }

    // func_ov000_021bf8a4
    /* 14 */ virtual s32 vfunc_14(void)
    {
        return 3;
    }
};

class BSystemMapMenu : public BMapMenu
{
public:
    virtual ~BSystemMapMenu()
    {
    }
};

class MapMenu : public BSystemMapMenu
{
public:
    // func_ov000_021bf88c
    /* 000 */ virtual void vfunc_00(void)
    {
        func_ov000_021be21c();
        this->unk_40 = 1;
        return;
    }

    // func_ov000_021bf7e8
    /* 0E8 */ virtual void vfunc_e8(void)
    {
        s32 var_r2;
        int iVar1;

        Menu::vfunc_e8();

        iVar1 = this->vfunc_d4(10);

        if (data_02196f24->unk_0d != 0)
        {
            var_r2 = 0x11;
        }
        else
        {
            var_r2 = 0x13;
        }

        if (iVar1 < 2)
        {
            func_0202b260(gpActiveScreenSt->tilemap[this->unk_30], (5 - (iVar1 >> 1)) + 0x16, var_r2, 4, 0);
        }

        return;
    }

    // func_ov000_021bf75c
    /* 0EC */ virtual void vfunc_ec(void)
    {
        s32 r3;
        s32 r1;

        Menu::vfunc_ec();

        r3 = this->vfunc_d4(10);
        r1 = 0x16;

        if (r3 >= 2)
        {
            return;
        }

        func_0202b260(
            gpActiveScreenSt->tilemap[this->unk_30], (5 - (r3 >> 1)) + r1, data_02196f24->unk_0d ? 0x11 : 0x13, 4, 0);

        return;
    }

    // func_ov000_021bf5d4
    /* 0D8 */ virtual void vfunc_d8(void)
    {
        s32 uVar2;
        s32 uVar3;
        s32 iVar5;
        VmMap_Common * iVar5_;
        int iVar7;
        struct Unit * pUnit;
        int iVar10;

        Menu::vfunc_d8();

        iVar5_ = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_FontMenuSub"));
        uVar3 = iVar5_->unk_04;
        uVar2 = iVar5_->unk_06;

        iVar5 = 0;

        if (data_02196f24->unk_0d)
        {
            iVar7 = 0x11;
        }
        else
        {
            iVar7 = 0x13;
        }

        iVar7++;

        for (pUnit = Force::Get(data_ov000_021e3324->phase)->head; pUnit != NULL; pUnit = pUnit->unk_3c)
        {
            if (pUnit->state2 & 0xe1)
            {
                continue;
            }

            iVar5++;
        }

        if (iVar5 != 0)
        {
            data_021970c4->unk_08 = data_021970cc->unk_14;
        }
        else
        {
            data_021970c4->unk_08 = data_021970cc->unk_08;
        }

        // "Free Units"
        iVar10 = func_020295ec(
            data_021970c4, func_02039e10("MMMINFO_未行動"), gpActiveScreenSt->bgTiles[this->unk_2c],
            gpActiveScreenSt->tilemap[this->unk_2c], 0x17, iVar7, uVar3, uVar2, 0, 0);

        if (iVar5 != 0)
        {
            data_021970c4->unk_08 = data_021970cc->unk_04;
        }

        func_02029850(
            data_021970c4, iVar5, gpActiveScreenSt->bgTiles[this->unk_2c], gpActiveScreenSt->tilemap[this->unk_2c],
            0x1e, iVar7, uVar3 + iVar10, uVar2, 0);

        data_021970c4->unk_08 = data_021970cc->unk_04;

        return;
    }

    // func_ov000_021bf57c
    /* 0DC */ virtual void vfunc_dc(void)
    {
        s32 iVar1;

        Menu::vfunc_dc();

        if (data_02196f24->unk_0d)
        {
            iVar1 = 0x11;
        }
        else
        {
            iVar1 = 0x13;
        }

        func_02010f98(gpActiveScreenSt->tilemap[this->unk_2c] + 0x16 + iVar1 * 0x20, 10, 4);

        return;
    }

    // func_ov000_021bf574
    /* 024 */ virtual s32 vfunc_24(MenuItemState * menuItemState, s32 arg1)
    {
        return arg1;
    }

    // func_ov000_021bf544
    /* 028 */ virtual s32 vfunc_28(s32 arg0)
    {
        if (!((arg0 & 0x3f) == 0 ? TRUE : FALSE))
        {
            func_ov000_021d6e30(0);
            return arg0;
        }

        return arg0;
    }

    // d1 func_ov000_021bf4e0
    // d0 func_ov000_021bf474
    virtual ~MapMenu()
    {
    }
};

class MIM_UnitList : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Units"
        return func_02039e10("MMM_部隊");
    }

    // func_ov000_021bf458
    /* 14 */ virtual s32 vfunc_14(void)
    {
        return 0;
    }

    // func_ov000_021bf42c
    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (func_0202dad0(menuItemState, menu))
        {
            // "Display a list of your units."
            func_ov000_021d6a9c(func_02039e10("MMMH_部隊"), 0);
        }

        return;
    }

    // func_ov000_021bf410
    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Display a list of your units."
        func_ov000_021d6a9c(func_02039e10("MMMH_部隊"), 0);
        return;
    }

    // func_ov000_021bf3ec
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(31, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class MIM_TutList : public MenuItem
{
public:
    // func_ov000_021bf3d8
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Guide"
        return func_02039e10("MMM_指南");
    }

    // func_ov000_021bf3a0
    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021a47e4())
        {
            return MENU_NOTSHOWN;
        }

        if (!data_02196f20->flagMgr->func_02049438())
        {
            return MENU_NOTSHOWN;
        }

        return MENU_ENABLED;
    }

    // func_ov000_021bf374
    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (func_0202dad0(menuItemState, menu))
        {
            // "Review tutorials on how the game is played."
            func_ov000_021d6a9c(func_02039e10("MMMH_指南"), 0);
        }

        return;
    }

    // func_ov000_021bf358
    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Review tutorials on how the game is played."
        func_ov000_021d6a9c(func_02039e10("MMMH_指南"), 0);
        return;
    }

    // func_ov000_021bf334
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(32, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class MIM_Config : public MenuItem
{
public:
    // func_ov000_021bf320
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Options"
        return func_02039e10("MMM_降参");
    }

    // func_ov000_021bf308
    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021a47e4())
        {
            return MENU_NOTSHOWN;
        }

        return MENU_ENABLED;
    }

    // func_ov000_021bf2dc
    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (func_0202dad0(menuItemState, menu))
        {
            // "Adjust game options."
            func_ov000_021d6a9c(func_02039e10("MMMH_環境"), 0);
        }

        return;
    }

    // func_ov000_021bf2c0
    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Adjust game options."
        func_ov000_021d6a9c(func_02039e10("MMMH_環境"), 0);
        return;
    }

    // func_ov000_021bf29c
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(33, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class TemporarySaveDialogYesNo : public BMapDialogYesNo
{
public:
    // func_ov000_021bf264
    /* B8 */ virtual void vfunc_b8(s32 param_2)
    {
        gMapStateManager->unk_14->unk_25 = Interpolate(0, 0, -16, param_2, 4);
        return;
    }
};

class DI_TemporarySave : public DialogItemYes
{
public:
    // func_ov000_021bf208
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021d6dfc(0);

        if (func_ov000_021a47e4())
        {
            PlayerPhase_GotoLabel(26, 0, 0);
            data_02196f10->unk_07 = 2;
            return 0x44;
        }
        else
        {
            PlayerPhase_GotoLabel(27, 0, 0);
            GameCtrl_GotoLabel(39);
            return 0x60;
        }
    }
};

class MIM_TemporarySave : public MenuItem
{
public:
    // func_ov000_021bf1d8
    /* 00 */ virtual char * vfunc_00(void)
    {
        if (func_ov000_021a47e4())
        {
            // "Exit"
            return func_02039e10("MMM_練習終了");
        }
        else
        {
            // "Suspend"
            return func_02039e10("MMM_中断");
        }
    }

    // func_ov000_021bf1c0
    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            return 5;
        }

        return 2;
    }

    // func_ov000_021bf184
    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021a478c())
        {
            return MENU_NOTSHOWN;
        }

        if (func_ov000_021a47e4() || func_0201f680())
        {
            return MENU_ENABLED;
        }

        return MENU_DISABLED;
    }

    // func_ov000_021bf148
    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        char * str;

        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        if (func_ov000_021a47e4())
        {
            // "Exit this practice session."
            str = "MMMH_練習終了";
        }
        else
        {
            // "Suspend the game."
            str = "MMMH_中断";
        }

        func_ov000_021d6a9c(func_02039e10(str), 0);

        return;
    }

    // func_ov000_021bf11c
    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        char * str;

        if (func_ov000_021a47e4())
        {
            // "Exit this practice session."
            str = "MMMH_練習終了";
        }
        else
        {
            // "Suspend the game."
            str = "MMMH_中断";
        }

        func_ov000_021d6a9c(func_02039e10(str), 0);

        return;
    }

    // func_ov000_021bf0f4
    /* 24 */ virtual s32 vfunc_24(Menu * menu, MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            func_ov000_021beaf4(menu->unk_10);
            return 0x40;
        }

        return 0x100;
    }
};

class SurrenderDialogYesNo : public BMapDialogYesNo
{
public:
    // func_ov000_021bf0bc
    /* 0B8 */ virtual void vfunc_b8(s32 arg0)
    {
        gMapStateManager->unk_14->unk_25 = Interpolate(0, 0, -16, arg0, 4);
        return;
    }

    // virtual ~SurrenderDialogYesNo()
    // // func_ov000_021bf93c
    // // func_ov000_021bf978
    // virtual ~SurrenderDialogYesNo()
    // {
    // }
};

class DI_Surrender : public DialogItemYes
{
public:
    // func_ov000_021bf084
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021d6dfc(0);
        PlayerPhase_GotoLabel(38, 0, 0);
        data_02196f10->unk_07 = 1;
        return 0x44;
    }
};

class MIM_Surrender : public MenuItem
{
public:
    // func_ov000_021bf070
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Surrender"
        return func_02039e10("MMM_降参");
    }

    // func_ov000_021bf058
    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            return 5;
        }

        return 2;
    }

    // func_ov000_021bf040
    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021a478c())
        {
            return MENU_ENABLED;
        }

        return MENU_NOTSHOWN;
    }

    // func_ov000_021bf014
    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (func_0202dad0(menuItemState, menu))
        {
            // "Surrender and end wireless play."
            func_ov000_021d6a9c(func_02039e10("MMMH_降参"), 0);
        }

        return;
    }

    // func_ov000_021beff8
    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Surrender and end wireless play."
        func_ov000_021d6a9c(func_02039e10("MMMH_降参"), 0);
        return;
    }

    // func_ov000_021befd0
    /* 24 */ virtual s32 vfunc_24(Menu * menu, MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            func_ov000_021beb94(menu->unk_10);
            return 0x40;
        }

        return 0x100;
    }
};

class MIM_TurnEnd : public MenuItem
{
public:
    // func_ov000_021befbc
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "End"
        return func_02039e10("MMM_終了");
    }

    // func_ov000_021bef90
    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (func_0202dad0(menuItemState, menu))
        {
            // "End the player phase. The enemy will move next."
            func_ov000_021d6a9c(func_02039e10("MMMH_終了"), 0);
        }

        return;
    }

    // func_ov000_021bef74
    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "End the player phase. The enemy will move next."
        func_ov000_021d6a9c(func_02039e10("MMMH_終了"), 0);
        return;
    }

    // func_ov000_021bef50
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(23, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

} // namespace map

class BMapSallyEndYesNo : public DialogYesNo
{
public:
    // func_ov000_021bef1c
    /* 0C0 */ virtual void vfunc_c0(void)
    {
        gSoundManager->unk_b0->vfunc_28(SE_SYS_START1, 0, 0);
        return;
    }
};

class BMapSallyEndYes : public DialogItemNo
{
public:
    // func_ov000_021bef00
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(3, 0, 0);
        return 0x41;
    }
};

class BMapSallyEndNo : public DialogItemNo
{
public:
    // func_ov000_021bee60
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        gMapStateManager->inputHandler->HideButton(3);

        if (!((data_ov005_02217560->unk_00 != -1 ? TRUE : FALSE) & 0xff))
        {
            gMapStateManager->inputHandler->SetButtonVisibility(0xf);
        }
        else
        {
            gMapStateManager->inputHandler->SetButtonVisibility(0x8f);
        }

        gMapStateManager->cursor->isVisible = TRUE;

        // "Select two units to have them trade starting positions."
        func_ov000_021d6a9c(func_02039e10("MSH_位置変更"), 0);

        return 0x81;
    }
};

EC void StartChildMenu(Menu *, void *, ProcPtr, u32, u32);
EC void func_020303bc(Dialog *, char *, void *, ProcPtr, s32, s32);

EC void func_ov000_021bec24(ProcPtr param_1)
{
    static map::MIM_UnitList sUnitList;
    static map::MIM_TutList sTutList;
    static map::MIM_Config sConfig;
    static map::MIM_TemporarySave sTemporarySave;
    static map::MIM_Surrender sSurrender;
    static map::MI_Separator sSeparator;
    static map::MIM_TurnEnd sTurnEnd;

    // clang-format off
    static MenuItem * data_ov000_021dd268[] =
    {
        &sUnitList,
        &sTutList,
        &sConfig,
        &sTemporarySave,
        &sSurrender,
        &sSeparator,
        &sTurnEnd,
    };
    // clang-format on

    StartChildMenu(new map::MapMenu(), data_ov000_021dd268, param_1, 1, 0);

    return;
}

EC void func_ov000_021beaf4(ProcPtr param_1)
{
    static map::DI_TemporarySave sTemporarySave;

    // clang-format off
    static DialogItem * data_ov000_021dd25c[] =
    {
        &sTemporarySave,
    };
    // clang-format on

    func_020303bc(
        new map::TemporarySaveDialogYesNo(), func_02039e10((char *)(func_ov000_021a47e4() ? "MD_中断" : "MD_練習終了")),
        data_ov000_021dd25c, param_1, 1, 0);

    return;
}

EC void func_ov000_021beb94(ProcPtr param_1)
{
    static map::DI_Surrender sSurrender;

    // clang-format off
    static DialogItem * data_ov000_021dd244[] =
    {
        &sSurrender,
    };
    // clang-format on

    func_020303bc(new map::SurrenderDialogYesNo(), func_02039e10("MD_降参"), data_ov000_021dd244, param_1, 1, 0);

    return;
}

EC void func_ov000_021bed70(ProcPtr param_1)
{
    gMapStateManager->cursor->isVisible = FALSE;

    gMapStateManager->inputHandler->SetButtonVisibility(0x8b);
    gMapStateManager->inputHandler->ShowButton(3);

    static BMapSallyEndYes sSallyEndYes;
    static BMapSallyEndNo sSallyEndNo;

    // clang-format off
    static MenuItem * data_ov000_021dd250[] =
    {
        &sSallyEndYes,
        &sSallyEndNo,
    };
    // clang-format on

    // "Conclude preparations?"
    func_020303bc(new BMapSallyEndYesNo(), func_02039e10("MD_進撃終了"), data_ov000_021dd250, param_1, 1, 0);

    return;
}

// ~TemporarySaveDialogYesNo

// func_ov000_021bf93c
// func_ov000_021bf978
// ~SurrenderDialogYesNo()

// func_ov000_021bf9bc
// func_ov000_021bf9f8
// ~BMapSallyEndYesNo

EC void func_ov000_021bfa3c(void)
{
    func_ov000_021b79f8();
    func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);
    return;
}
