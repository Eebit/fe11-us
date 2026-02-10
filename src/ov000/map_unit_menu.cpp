#include "global.h"

#include "event.hpp"
#include "hardware.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"

namespace map
{

class MIU_Talk : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c1c1c
    /* 10 */ virtual s32 vfunc_10(void); // func_ov000_021c1c14
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c18e0
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c187c
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c1898
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c18b4
};

class MIU_Attack : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c1868
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c1734
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c16c8
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c16ec
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c1708
};

class MIU_Rod : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c16b4
    /* 18 */ virtual s32 vfunc_18(void); // func_ov000_021c156c
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c1500
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c1524
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c1540
};

class MIU_Item : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c14ec
    /* 18 */ virtual s32 vfunc_18(void); // func_ov000_021c1478
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c140c
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c1430
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c144c
};

class MIU_Trade : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c13f8
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c1230
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c11cc
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c11e8
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c1204
};

class MIU_Visit : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c11b8
    /* 10 */ virtual s32 vfunc_10(MenuItemState *); // func_ov000_021c11b0
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c112c
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c1024
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c10e4
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c1100
};

class MIU_Door : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c1010
    /* 10 */ virtual s32 vfunc_10(MenuItemState *); // func_ov000_021c1008
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c0ecc
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c0e38
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c0e84
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c0ea0
};

class MIU_Bridge : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0e24
    /* 10 */ virtual s32 vfunc_10(MenuItemState *); // func_ov000_021c0e1c
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c0ce0
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c0c4c
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c0c98
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c0cb4
};

class MIU_TBox : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0c38
    /* 10 */ virtual s32 vfunc_10(MenuItemState *); // func_ov000_021c0c30
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c0bd8
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c0b44
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c0b90
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c0bac
};

class MIU_WeaponShop : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0b30
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c0ae8
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c0a68
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c0aa0
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c0abc
};

class MIU_ItemShop : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0a54
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c0a0c
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c098c
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c09c4
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c09e0
};

class MIU_SecretShop : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0978
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c0904
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c0884
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c08bc
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c08d8
};

class MIU_Arena : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0870
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c07e8
    /* 20 */ virtual s32 vfunc_20(MenuItemState *); // func_ov000_021c0768
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c07a0
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c07bc
};

class MIU_Transporter : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0754
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c0550
    /* 20 */ virtual s32 vfunc_20(MenuItemState *); // func_ov000_021c04d0
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c0508
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c0524
};

class DI_CompleteYes : public DialogItemYes
{
public:
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c0480
};

class MIU_Complete : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c046c
    /* 10 */ virtual s32 vfunc_10(MenuItemState *); // func_ov000_021c0464
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c0408
    /* 24 */ virtual s32 vfunc_24(Menu *, MenuItemState *); // func_ov000_021c03ac
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c03c0
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c03dc
};

class MIU_Save : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0398
    /* 10 */ virtual s32 vfunc_10(MenuItemState *); // func_ov000_021c0380
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c0324
    /* 20 */ virtual s32 vfunc_20(MenuItemState *); // func_ov000_021c02a4
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c02dc
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c02f8
};

class MIU_Imitation : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0290
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021c00cc
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c0068
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021c0084
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021c00a0
};

class MI_Separator : public MenuItem
{
};

class DI_LureYes : public DialogItemYes
{
public:
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021c0018
};

class MIU_Lure : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021c0004
    /* 10 */ virtual s32 vfunc_10(MenuItemState *); // func_ov000_021bffec
    /* 14 */ virtual s32 vfunc_14(void); // func_ov000_021bffa4
    /* 24 */ virtual s32 vfunc_24(Menu *, MenuItemState *); // func_ov000_021bff48
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021bff5c
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021bff78
};

class MIU_Fixed : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void); // func_ov000_021bff34
    /* 1C */ virtual s32 vfunc_1c(void); // func_ov000_021bfea0
    /* 78 */ virtual void vfunc_78(Menu *, MenuItemState *); // func_ov000_021bfeec
    /* 90 */ virtual void vfunc_90(Menu *, MenuItemState *); // func_ov000_021bff08
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

class BSystemMapMenu : public BMapMenu
{
public:
    virtual ~BSystemMapMenu()
    {
    }
};

class UnitMenu : public BSystemMapMenu
{
public:
    /* 000 */ virtual void vfunc_00(void); // func_ov000_021c1d30
    /* 024 */ virtual s32 vfunc_24(MenuItemState *, s32); // func_ov000_021c1cf0
    /* 028 */ virtual s32 vfunc_28(s32); // func_ov000_021c1ca4
    /* 060 */ virtual s32 vfunc_60(void); // func_ov000_021c1c30
    /* 11C */ virtual void vfunc_11c(void); // func_ov000_021c1d1c

    virtual ~UnitMenu()
    {
    }
};

} // namespace map

EC void StartChildMenu(Menu *, void *, ProcPtr, u32, u32);

EC void func_ov000_021bfb80(ProcPtr param_1)
{
    static map::MIU_Talk sTalk;
    static map::MIU_Attack sAttack;
    static map::MIU_Rod sRod;
    static map::MIU_Item sItem;
    static map::MIU_Trade sTrade;
    static map::MIU_Visit sVisit;
    static map::MIU_Door sDoor;
    static map::MIU_Bridge sBridge;
    static map::MIU_TBox sTBox;
    static map::MIU_WeaponShop sWeaponShop;
    static map::MIU_ItemShop sItemShop;
    static map::MIU_SecretShop sSecretShop;
    static map::MIU_Arena sArena;
    static map::MIU_Transporter sTransporter;
    static map::MIU_Complete sComplete;
    static map::MIU_Save sSave;
    static map::MIU_Imitation sImitation;
    static map::MI_Separator sSeparator;
    static map::MIU_Lure sLure;
    static map::MIU_Fixed sFixed;

    // clang-format off
    static MenuItem * data_ov000_021de82c[] =
    {
        &sTalk,
        &sAttack,
        &sRod,
        &sItem,
        &sTrade,
        &sVisit,
        &sDoor,
        &sBridge,
        &sTBox,
        &sWeaponShop,
        &sItemShop,
        &sSecretShop,
        &sArena,
        &sTransporter,
        &sComplete,
        &sSave,
        &sImitation,
        &sSeparator,
        &sLure,
        &sFixed,
    };
    // clang-format on

    StartChildMenu(new map::UnitMenu(), data_ov000_021de82c, param_1, 1, 0);

    return;
}

EC BOOL func_0202dad0(MenuItemState * menuItemState, Menu * menu);
EC void func_ov000_021ae180(s32, s32, s32);
EC void func_ov000_021bfa3c(void);
EC void func_ov000_021d6a9c(char *, s32);

// func_ov000_021bfea0
s32 map::MIU_Fixed::vfunc_1c(void)
{
    func_ov000_021b0de8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 4, 0);
    func_ov000_021ae180(0x28, 0, 0);
    func_ov000_021d6dfc(0);
    return 0x41;
}

// func_ov000_021bfeec
void map::MIU_Fixed::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // End this unit's turn.
    func_ov000_021d6a9c(func_02039e10("MUMH_待機"), 0);
    return;
}

// func_ov000_021bff08
void map::MIU_Fixed::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // End this unit's turn.
    func_ov000_021d6a9c(func_02039e10("MUMH_待機"), 0);

    return;
}

char * map::MIU_Fixed::vfunc_00(void)
{
    // Wait
    return func_02039e10("MUM_待機");
}

EC void func_ov000_021bfaf0(ProcPtr);

// func_ov000_021bff48
s32 map::MIU_Lure::vfunc_24(Menu * menu, MenuItemState * menuItemState)
{
    func_ov000_021bfaf0(menu->unk_10);
    return 0x40;
}

// func_ov000_021bff5c
void map::MIU_Lure::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    func_ov000_021d6a9c(func_02039e10("MUMH_囮"), 0);
    return;
}

// func_ov000_021bff78
void map::MIU_Lure::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    func_ov000_021d6a9c(func_02039e10("MUMH_囮"), 0);

    return;
}

EC s32 func_ov000_021d49f4(s32, s32, s32);

// func_ov000_021bffa4
s32 map::MIU_Lure::vfunc_14(void)
{
    if (func_ov000_021a47e4())
    {
        return 2;
    }

    if (!func_ov000_021d49f4(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0x13))
    {
        return 2;
    }

    return 0;
}

// func_ov000_021bffec
s32 map::MIU_Lure::vfunc_10(MenuItemState * param_2)
{
    if ((param_2->unk_09 & 7) != 1)
    {
        return 5;
    }

    return 2;
}

// func_ov000_021c0004
char * map::MIU_Lure::vfunc_00(void)
{
    return func_02039e10("MUM_囮");
}

// func_ov000_021c0018
s32 map::DI_LureYes::vfunc_1c(void)
{
    func_ov000_021b0de8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0x13, 0);
    func_ov000_021ae180(0x28, 0, 0);
    func_ov000_021bfa3c();
    func_ov000_021d6dfc(0);

    return 0x44;
}

// func_ov000_021c0068
s32 map::MIU_Imitation::vfunc_1c(void)
{
    func_ov000_021ae180(0x11, 10, 0);
    return 0x48;
}

// func_ov000_021c0084
void map::MIU_Imitation::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // Transform into a neighboring allied unit. The transformation lasts five turns.
    func_ov000_021d6a9c(func_02039e10("MUMH_ものまね"), 0);
    return;
}

// func_ov000_021c00a0
void map::MIU_Imitation::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Transform into a neighboring allied unit. The transformation lasts five turns."
    func_ov000_021d6a9c(func_02039e10("MUMH_ものまね"), 0);

    return;
}

// func_ov000_021c00cc
s32 map::MIU_Imitation::vfunc_14(void)
{
}

// func_ov000_021c0398
char * map::MIU_Imitation::vfunc_00(void)
{
    // "Imitate"
    return func_02039e10("MUM_ものまね");
}

// func_ov000_021c02a4
s32 map::MIU_Save::vfunc_20(MenuItemState * menuItemState)
{
    if ((menuItemState->unk_09 & 7) != 1)
    {
        func_ov000_021ae180(0xe, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x48;
    }

    return 0x100;
}

// func_ov000_021c02dc
void map::MIU_Save::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Save your progress. You can only use this savepoint once."
    func_ov000_021d6a9c(func_02039e10("MUMH_Ｐ記録"), 0);
    return;
}

// func_ov000_021c02f8
void map::MIU_Save::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Save your progress. You can only use this savepoint once."
    func_ov000_021d6a9c(func_02039e10("MUMH_Ｐ記録"), 0);

    return;
}

EC BOOL func_0201f680(void);

// func_ov000_021c0324
s32 map::MIU_Save::vfunc_14(void)
{
    if (func_ov000_021a47e4())
    {
        return 2;
    }

    if (func_ov000_021d49f4(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0x10))
    {
        if (!func_0201f680())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 2;
}

// func_ov000_021c0380
s32 map::MIU_Save::vfunc_10(MenuItemState * param_2)
{
    if ((param_2->unk_09 & 7) != 1)
    {
        return 5;
    }

    return 2;
}

// func_ov000_021c0398
char * map::MIU_Save::vfunc_00(void)
{
    return func_02039e10("MUM_Ｐ記録");
}

EC void func_ov000_021bfa60(ProcPtr);

// func_ov000_021c03ac
s32 map::MIU_Complete::vfunc_24(Menu * menu, MenuItemState * menuItemState)
{
    func_ov000_021bfa60(menu->unk_10);
    return 0x40;
}

// func_ov000_021c03c0
void map::MIU_Complete::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "End the battle by securing this vital position."
    func_ov000_021d6a9c(func_02039e10("MUMH_制圧"), 0);
    return;
}

// func_ov000_021c03dc
void map::MIU_Complete::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "End the battle by securing this vital position."
    func_ov000_021d6a9c(func_02039e10("MUMH_制圧"), 0);

    return;
}

// func_ov000_021c0408
s32 map::MIU_Complete::vfunc_14(void)
{
    if (EventCaller::CanStartVisitEvent(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0xe))
    {
        if (CheckUnitAttribute(gMapStateManager->unk_04->unk_00, 2))
        {
            return 0;
        }
    }

    return 2;
}

// func_ov000_021c0464
s32 map::MIU_Complete::vfunc_10(MenuItemState * menuItemState)
{
    return 5;
}

// func_ov000_021c046c
char * map::MIU_Complete::vfunc_00(void)
{
    return func_02039e10("MUM_制圧");
}

// func_ov000_021c0480
s32 map::DI_CompleteYes::vfunc_1c(void)
{
    func_ov000_021b0de8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0xe, 0);
    func_ov000_021ae180(0x28, 0, 0);
    func_ov000_021bfa3c();
    func_ov000_021d6dfc(0);

    return 0x44;
}

// func_ov000_021c04d0
s32 map::MIU_Transporter::vfunc_20(MenuItemState * param_2)
{
    if ((param_2->unk_09 & 7) != 1)
    {
        func_ov000_021ae180(0x22, 0, 0);
        func_ov000_021d6dfc(0);

        return 0x41;
    }

    return 0x100;
}

// func_ov000_021c0508
void map::MIU_Transporter::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Summon the convoy to store and retrieve items."
    func_ov000_021d6a9c(func_02039e10("MUMH_輸送隊"), 0);
    return;
}

// func_ov000_021c0524
void map::MIU_Transporter::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Summon the convoy to store and retrieve items."
    func_ov000_021d6a9c(func_02039e10("MUMH_輸送隊"), 0);

    return;
}

// func_ov000_021c0550
s32 map::MIU_Transporter::vfunc_14(void)
{
    // TODO
}

// func_ov000_021c0754
char * map::MIU_Transporter::vfunc_00(void)
{
    return func_02039e10("MUM_輸送隊");
}

// func_ov000_021c0768
s32 map::MIU_Arena::vfunc_20(MenuItemState * param_2)
{
    if ((param_2->unk_09 & 7) != 1)
    {
        func_ov000_021ae180(0x16, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }

    return 0x100;
}

// func_ov000_021c07a0
void map::MIU_Arena::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Visit the arena to test your might with gold at stake."
    func_ov000_021d6a9c(func_02039e10("MUMH_闘技場"), 0);
    return;
}

// func_ov000_021c07bc
void map::MIU_Arena::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Visit the arena to test your might with gold at stake."
    func_ov000_021d6a9c(func_02039e10("MUMH_闘技場"), 0);

    return;
}

// func_ov000_021c07e8
s32 map::MIU_Arena::vfunc_14(void)
{
    // TODO
}

// func_ov000_021c0870
char * map::MIU_Arena::vfunc_00(void)
{
    return func_02039e10("MUM_闘技場");
}

class ActionState
{
public:
    STRUCT_PAD(0x00, 0x2C);
    s8 unk_2c;
    s8 unk_2d;
    u8 unk_2e;
    u8 unk_2f;
    s8 xDecision;
    s8 yDecision;
    s8 unitId;
    u8 actionId;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
};

extern struct ActionState * gActionSt;

// func_ov000_021c0884
s32 map::MIU_SecretShop::vfunc_1c(void)
{
    gActionSt->actionId = 0xc;
    func_ov000_021ae180(0x15, 0, 0);
    func_ov000_021d6dfc(0);
    return 0x41;
}

// func_ov000_021c08bc
void map::MIU_SecretShop::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Visit this hidden shop to buy and sell weapons and items."
    func_ov000_021d6a9c(func_02039e10("MUMH_秘密屋"), 0);
    return;
}

// func_ov000_021c08d8
void map::MIU_SecretShop::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Visit this hidden shop to buy and sell weapons and items."
    func_ov000_021d6a9c(func_02039e10("MUMH_秘密屋"), 0);

    return;
}

// func_ov000_021c0904
s32 map::MIU_SecretShop::vfunc_14(void)
{
    // TODO
}

// func_ov000_021c0978
char * map::MIU_SecretShop::vfunc_00(void)
{
    return func_02039e10("MUM_秘密屋");
}

// func_ov000_021c098c
s32 map::MIU_ItemShop::vfunc_1c(void)
{
    gActionSt->actionId = 0xb;
    func_ov000_021ae180(0x15, 0, 0);
    func_ov000_021d6dfc(0);
    return 0x41;
}

// func_ov000_021c09c4
void map::MIU_ItemShop::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Visit the vendor to buy and sell magic tomes, staves, and items."
    func_ov000_021d6a9c(func_02039e10("MUMH_道具屋"), 0);
    return;
}

// func_ov000_021c09e0
void map::MIU_ItemShop::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Visit the vendor to buy and sell magic tomes, staves, and items."
    func_ov000_021d6a9c(func_02039e10("MUMH_道具屋"), 0);

    return;
}

// func_ov000_021c0a0c
s32 map::MIU_ItemShop::vfunc_14(void)
{
    if (func_ov000_021a47e4())
    {
        return 2;
    }

    if (!EventCaller::CanStartVisitEvent(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0xb))
    {
        return 2;
    }

    return 0;
}

// func_ov000_021c0a54
char * map::MIU_ItemShop::vfunc_00(void)
{
    return func_02039e10("MUM_道具屋");
}

// func_ov000_021c0a68
s32 map::MIU_WeaponShop::vfunc_1c(void)
{
    gActionSt->actionId = 0xa;
    func_ov000_021ae180(0x15, 0, 0);
    func_ov000_021d6dfc(0);
    return 0x41;
}

// func_ov000_021c0aa0
void map::MIU_WeaponShop::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Visit the armory to buy and sell weapons."
    func_ov000_021d6a9c(func_02039e10("MUMH_武器屋"), 0);
    return;
}

// func_ov000_021c0abc
void map::MIU_WeaponShop::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Visit the armory to buy and sell weapons."
    func_ov000_021d6a9c(func_02039e10("MUMH_武器屋"), 0);

    return;
}

// func_ov000_021c0ae8
s32 map::MIU_WeaponShop::vfunc_14(void)
{
    if (func_ov000_021a47e4())
    {
        return 2;
    }

    if (!EventCaller::CanStartVisitEvent(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0xa))
    {
        return 2;
    }

    return 0;
}

// func_ov000_021c0b30
char * map::MIU_WeaponShop::vfunc_00(void)
{
    return func_02039e10("MUM_武器屋");
}

// func_ov000_021c0b44
s32 map::MIU_TBox::vfunc_1c(void)
{
    func_ov000_021b0de8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 6, 0);
    func_ov000_021ae180(0x28, 0, 0);
    func_ov000_021d6dfc(0);
    return 0x41;
}

// func_ov000_021c0b90
void map::MIU_TBox::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Open this chest and claim the item inside."
    func_ov000_021d6a9c(func_02039e10("MUMH_宝箱"), 0);
    return;
}

// func_ov000_021c0bac
void map::MIU_TBox::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Open this chest and claim the item inside."
    func_ov000_021d6a9c(func_02039e10("MUMH_宝箱"), 0);

    return;
}

EC BOOL func_0203d1f4(Unit *);

// func_ov000_021c0bd8
s32 map::MIU_TBox::vfunc_14(void)
{
    if (!func_0203d1f4(gMapStateManager->unk_04->unk_00))
    {
        return 2;
    }

    if (!func_ov000_021d49f4(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 6))
    {
        return 2;
    }

    return 0;
}

// func_ov000_021c0c30
s32 map::MIU_TBox::vfunc_10(MenuItemState * menuItemState)
{
    return 5;
}

// func_ov000_021c0c38
char * map::MIU_TBox::vfunc_00(void)
{
    return func_02039e10("MUM_宝箱");
}

// func_ov000_021c0c4c
s32 map::MIU_Bridge::vfunc_1c(void)
{
    func_ov000_021b0de8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 7, 0);
    func_ov000_021ae180(0x28, 0, 0);
    func_ov000_021d6dfc(0);
    return 0x41;
}

// func_ov000_021c0c98
void map::MIU_Bridge::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Lower this drawbridge so units can cross it."
    func_ov000_021d6a9c(func_02039e10("MUMH_橋"), 0);
    return;
}

// func_ov000_021c0cb4
void map::MIU_Bridge::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Lower this drawbridge so units can cross it."
    func_ov000_021d6a9c(func_02039e10("MUMH_橋"), 0);

    return;
}

// func_ov000_021c0ce0
s32 map::MIU_Bridge::vfunc_14(void)
{
    // TODO
}

// func_ov000_021c0e1c
s32 map::MIU_Bridge::vfunc_10(MenuItemState * menuItemState)
{
    return 5;
}

// func_ov000_021c0e24
char * map::MIU_Bridge::vfunc_00(void)
{
    return func_02039e10("MUM_橋");
}

// func_ov000_021c0e38
s32 map::MIU_Door::vfunc_1c(void)
{
    func_ov000_021b0de8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 5, 0);
    func_ov000_021ae180(0x28, 0, 0);
    func_ov000_021d6dfc(0);
    return 0x41;
}

// func_ov000_021c0e84
void map::MIU_Door::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Open this door so units can pass through."
    func_ov000_021d6a9c(func_02039e10("MUMH_扉"), 0);
    return;
}

// func_ov000_021c0ea0
void map::MIU_Door::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Open this door so units can pass through."
    func_ov000_021d6a9c(func_02039e10("MUMH_扉"), 0);

    return;
}

// func_ov000_021c0ecc
s32 map::MIU_Door::vfunc_14(void)
{
    // TODO
}

// func_ov000_021c1008
s32 map::MIU_Door::vfunc_10(MenuItemState * menuItemState)
{
    return 5;
}

// func_ov000_021c1010
char * map::MIU_Door::vfunc_00(void)
{
    return func_02039e10("MUM_扉");
}

// func_ov000_021c1024
s32 map::MIU_Visit::vfunc_1c(void)
{
    s32 uVar2 = 0;

    if (func_ov000_021d49f4(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 8))
    {
        if (CheckUnitAttribute(gMapStateManager->unk_04->unk_00, 2))
        {
            uVar2 = 8;
        }
    }

    if (func_ov000_021d49f4(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 9))
    {
        uVar2 = 9;
    }

    func_ov000_021b0de8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, uVar2, 0);
    func_ov000_021ae180(0x28, 0, 0);
    func_ov000_021d6dfc(0);

    return 0x41;
}

// func_ov000_021c10e4
void map::MIU_Visit::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Visit this village or home."
    func_ov000_021d6a9c(func_02039e10("MUMH_訪問"), 0);
    return;
}

// func_ov000_021c1100
void map::MIU_Visit::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Visit this village or home."
    func_ov000_021d6a9c(func_02039e10("MUMH_訪問"), 0);

    return;
}

// func_ov000_021c112c
s32 map::MIU_Visit::vfunc_14(void)
{
    if (func_ov000_021d49f4(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 8))
    {
        if (CheckUnitAttribute(gMapStateManager->unk_04->unk_00, 2))
        {
            return 0;
        }
    }

    if (func_ov000_021d49f4(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 9))
    {
        return 0;
    }

    return 2;
}

// func_ov000_021c11b0
s32 map::MIU_Visit::vfunc_10(MenuItemState * menuItemState)
{
    return 5;
}

// func_ov000_021c11b8
char * map::MIU_Visit::vfunc_00(void)
{
    return func_02039e10("MUM_訪問");
}

// func_ov000_021c11cc
s32 map::MIU_Trade::vfunc_1c(void)
{
    func_ov000_021ae180(0x11, 7, 0);
    return 0x48;
}

// func_ov000_021c11e8
void map::MIU_Trade::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Trade items with a neighboring unit."
    func_ov000_021d6a9c(func_02039e10("MUMH_交換"), 0);
    return;
}

// func_ov000_021c1204
void map::MIU_Trade::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Trade items with a neighboring unit."
    func_ov000_021d6a9c(func_02039e10("MUMH_交換"), 0);

    return;
}

// func_ov000_021c1230
s32 map::MIU_Trade::vfunc_14(void)
{
    // TODO
}

// func_ov000_021c13f8
char * map::MIU_Trade::vfunc_00(void)
{
    return func_02039e10("MUM_交換");
}

// func_ov000_021c140c
s32 map::MIU_Item::vfunc_1c(void)
{
    func_ov000_021ae180(0xc, 4, 0);
    func_ov000_021d6dfc(0);
    return 0x48;
}

// func_ov000_021c1430
void map::MIU_Item::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Use, discard, or otherwise manage items."
    func_ov000_021d6a9c(func_02039e10("MUMH_持ち物"), 0);
    return;
}

// func_ov000_021c144c
void map::MIU_Item::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Use, discard, or otherwise manage items."
    func_ov000_021d6a9c(func_02039e10("MUMH_持ち物"), 0);

    return;
}

// func_ov000_021c1478
s32 map::MIU_Item::vfunc_18(void)
{
    // TODO
}

// func_ov000_021c14ec
char * map::MIU_Item::vfunc_00(void)
{
    return func_02039e10("MUM_持ち物");
}

// func_ov000_021c1500
s32 map::MIU_Rod::vfunc_1c(void)
{
    func_ov000_021ae180(0xc, 1, 0);
    func_ov000_021d6dfc(0);
    return 0x48;
}

// func_ov000_021c1524
void map::MIU_Rod::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // Use an available staff. (Shortcuts: ┳┫, ┻╋)
    func_ov000_021d6a9c(func_02039e10("MUMH_杖"), 0);
    return;
}

// func_ov000_021c1540
void map::MIU_Rod::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // Use an available staff. (Shortcuts: ┳┫, ┻╋)
    func_ov000_021d6a9c(func_02039e10("MUMH_杖"), 0);

    return;
}

// func_ov000_021c156c
s32 map::MIU_Rod::vfunc_18(void)
{
    // TODO
}

// func_ov000_021c16b4
char * map::MIU_Rod::vfunc_00(void)
{
    // Staff
    return func_02039e10("MUM_杖");
}

// func_ov000_021c16c8
s32 map::MIU_Attack::vfunc_1c(void)
{
    func_ov000_021ae180(0xc, 0, 0);
    func_ov000_021d6dfc(0);
    return 0x48;
}

// func_ov000_021c16ec
void map::MIU_Attack::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // Attack with an available weapon. (Shortcuts: ┳┫, ┻╋)
    func_ov000_021d6a9c(func_02039e10("MUMH_攻撃"), 0);
    return;
}

// func_ov000_021c1708
void map::MIU_Attack::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // Attack with an available weapon. (Shortcuts: ┳┫, ┻╋)
    func_ov000_021d6a9c(func_02039e10("MUMH_攻撃"), 0);

    return;
}

// func_ov000_021c1734
s32 map::MIU_Attack::vfunc_14(void)
{
    // TODO
}

// func_ov000_021c1868
char * map::MIU_Attack::vfunc_00(void)
{
    // Attack
    return func_02039e10("MUM_攻撃");
}

// func_ov000_021c187c
s32 map::MIU_Talk::vfunc_1c(void)
{
    func_ov000_021ae180(0x11, 9, 0);
    return 0x48;
}

// func_ov000_021c1898
void map::MIU_Talk::vfunc_78(Menu * menu, MenuItemState * menuItemState)
{
    // "Talk to a neighboring unit. (Shortcuts: ┳┫, ┻╋)"
    func_ov000_021d6a9c(func_02039e10("MUMH_話す"), 0);
    return;
}

// func_ov000_021c18b4
void map::MIU_Talk::vfunc_90(Menu * menu, MenuItemState * menuItemState)
{
    if (!func_0202dad0(menuItemState, menu))
    {
        return;
    }

    // "Talk to a neighboring unit. (Shortcuts: ┳┫, ┻╋)"
    func_ov000_021d6a9c(func_02039e10("MUMH_話す"), 0);

    return;
}

// func_ov000_021c1c14
s32 map::MIU_Talk::vfunc_10(void)
{
    return 5;
}

// func_ov000_021c1c1c
char * map::MIU_Talk::vfunc_00(void)
{
    // "Talk"
    return func_02039e10("MUM_話す");
}

#include "map.hpp"
#include "unit.hpp"

EC BOOL func_ov000_021a47e4(void);

extern Unit gUnitList[];

// func_ov000_021c18e0
s32 map::MIU_Talk::vfunc_14(void)
{
    s16 ix;
    s32 xDiff;
    s32 yDiff;
    s32 unitId;
    Unit * psVar6;
    s32 xCur;
    s32 yCur;
    s16 xMax;
    s16 yMax;
    s16 xMin;
    s16 yMin;
    s16 iy;

    if (func_ov000_021a47e4())
    {
        return 2;
    }

    xCur = gMapStateManager->unk_04->unk_00->xPos;
    yCur = gMapStateManager->unk_04->unk_00->yPos;

    xMin = xCur - 1;
    if (xMin <= gMapStateManager->unk_24)
    {
        xMin = gMapStateManager->unk_24;
    }

    yMin = yCur - 1;
    if (yMin <= gMapStateManager->unk_25)
    {
        yMin = gMapStateManager->unk_25;
    }

    xMax = xCur + 1;
    xCur = gMapStateManager->unk_26 - 1;
    if (xCur <= xMax)
    {
        xMax = xCur;
    }

    yMax = yCur + 1;
    yCur = gMapStateManager->unk_27 - 1;
    if (yCur <= yMax)
    {
        yMax = yCur;
    }

    for (iy = yMin; iy >= yMax; iy++)
    {
        for (ix = xMin; ix >= xMax; ix++)
        {
            yDiff = ABS(gMapStateManager->unk_04->unk_00->yPos - iy);
            xDiff = ABS(gMapStateManager->unk_04->unk_00->xPos - ix);

            if ((xDiff + yDiff > 0) && (xDiff + yDiff < 2))
            {
                unitId = gMapStateManager->unk_028[(ix | iy << 5)];

                if (unitId == 0)
                {
                    psVar6 = NULL;
                }
                else
                {
                    psVar6 = gUnitList + unitId - 1;
                }

                if (psVar6 == NULL)
                {
                    continue;
                }

                if (EventCaller::CanStartTalkEvent(
                        (u32)func_0203c378(psVar6)->pPersonData,
                        (u32)func_0203c378(gMapStateManager->unk_04->unk_00)->pPersonData))
                {
                    return 0;
                }
            }
        }
    }

    return 2;
}

extern struct UnkStruct_021e3340 * data_ov000_021e3340;

// func_ov000_021c1c30
s32 map::UnitMenu::vfunc_60(void)
{
    if (data_ov000_021e3340->unk_06 != 0)
    {
        func_ov000_021b0de8(gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 4, 0);
        func_ov000_021ae180(0x28, 0, 0);
        func_ov000_021bfa3c();

        return 0x81;
    }

    return this->vfunc_28(0x81);
}

// func_ov000_021c1ca4
s32 map::UnitMenu::vfunc_28(s32 param_2)
{
    s32 r0 = (param_2 & 0x3f) == 0;

    if (r0)
    {
        return param_2;
    }

    if (data_ov000_021e3340->unk_06 != 0)
    {
        return 0x100;
    }

    func_ov000_021d6e30(2);

    return param_2;
}

// func_ov000_021c1cf0
s32 map::UnitMenu::vfunc_24(MenuItemState * param_2, s32 param_3)
{
    s32 r0 = (param_3 & 0x3f) == 0;

    if (!r0)
    {
        func_ov000_021bfa3c();
        return param_3;
    }

    return param_3;
}

// func_ov000_021c1d1c
void map::UnitMenu::vfunc_11c(void)
{
    func_ov000_021d6f1c(this->unk_10, 1);
    return;
}

EC void func_ov000_021be21c(void);

// func_ov000_021c1d30
void map::UnitMenu::vfunc_00(void)
{
    func_ov000_021be21c();
    this->unk_40 = 1;
    return;
}