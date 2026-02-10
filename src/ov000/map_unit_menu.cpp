#include "global.h"

#include "action.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"
#include "unit.hpp"

EC BOOL func_0201f680(void);

EC BOOL func_0203d1f4(Unit *);

EC void func_ov000_021bfa60(ProcPtr);

EC void func_ov000_021bfaf0(ProcPtr);

EC BOOL func_ov000_021a47e4(void);
EC void func_ov000_021be21c(void);

EC s32 func_ov000_021d49f4(s32, s32, s32);

EC BOOL func_0202dad0(MenuItemState * menuItemState, Menu * menu);
EC void func_ov000_021ae180(s32, s32, s32);
EC void func_ov000_021bfa3c(void);
EC void func_ov000_021d6a9c(char *, s32);

extern struct UnkStruct_021e3340 * data_ov000_021e3340;

extern Unit gUnitList[];

namespace map
{

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
    virtual ~UnitMenu()
    {
    }

    /* 000 */ virtual void vfunc_00(void)
    {
        func_ov000_021be21c();
        this->unk_40 = 1;
        return;
    }

    /* 11C */ virtual void vfunc_11c(void)
    {
        func_ov000_021d6f1c(this->unk_10, 1);
        return;
    }

    /* 024 */ virtual s32 vfunc_24(MenuItemState * menuItemState, s32 param_3)
    {
        s32 r0 = (param_3 & 0x3f) == 0;

        if (!r0)
        {
            func_ov000_021bfa3c();
            return param_3;
        }

        return param_3;
    }

    /* 028 */ virtual s32 vfunc_28(s32 param_2)
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

    /* 060 */ virtual s32 vfunc_60(void)
    {
        if (data_ov000_021e3340->unk_06 != 0)
        {
            func_ov000_021b0de8(
                gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, ACTION_WAIT, 0);
            func_ov000_021ae180(0x28, 0, 0);
            func_ov000_021bfa3c();

            return 0x81;
        }

        return this->vfunc_28(0x81);
    }
};

class MIU_Talk : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Talk"
        return func_02039e10("MUM_話す");
    }

    /* 10 */ virtual s32 vfunc_10(void)
    {
        return 5;
    }

    /* 14 */ virtual s32 vfunc_14(void)
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

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Talk to a neighboring unit. (Shortcuts: ┳┫, ┻╋)"
        func_ov000_021d6a9c(func_02039e10("MUMH_話す"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Talk to a neighboring unit. (Shortcuts: ┳┫, ┻╋)"
        func_ov000_021d6a9c(func_02039e10("MUMH_話す"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021ae180(0x11, 9, 0);
        return 0x48;
    }
};

class MIU_Attack : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // Attack
        return func_02039e10("MUM_攻撃");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // Attack with an available weapon. (Shortcuts: ┳┫, ┻╋)
        func_ov000_021d6a9c(func_02039e10("MUMH_攻撃"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // Attack with an available weapon. (Shortcuts: ┳┫, ┻╋)
        func_ov000_021d6a9c(func_02039e10("MUMH_攻撃"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021ae180(0xc, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x48;
    }
};

class MIU_Rod : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // Staff
        return func_02039e10("MUM_杖");
    }

    /* 18 */ virtual s32 vfunc_18(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // Use an available staff. (Shortcuts: ┳┫, ┻╋)
        func_ov000_021d6a9c(func_02039e10("MUMH_杖"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // Use an available staff. (Shortcuts: ┳┫, ┻╋)
        func_ov000_021d6a9c(func_02039e10("MUMH_杖"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021ae180(0xc, 1, 0);
        func_ov000_021d6dfc(0);
        return 0x48;
    }
};

class MIU_Item : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_持ち物");
    }

    /* 18 */ virtual s32 vfunc_18(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Use, discard, or otherwise manage items."
        func_ov000_021d6a9c(func_02039e10("MUMH_持ち物"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Use, discard, or otherwise manage items."
        func_ov000_021d6a9c(func_02039e10("MUMH_持ち物"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021ae180(0xc, 4, 0);
        func_ov000_021d6dfc(0);
        return 0x48;
    }
};

class MIU_Trade : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_交換");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Trade items with a neighboring unit."
        func_ov000_021d6a9c(func_02039e10("MUMH_交換"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Trade items with a neighboring unit."
        func_ov000_021d6a9c(func_02039e10("MUMH_交換"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021ae180(0x11, 7, 0);
        return 0x48;
    }
};

class MIU_Visit : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_訪問");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return 5;
    }

    /* 14 */ virtual s32 vfunc_14(void)
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

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Visit this village or home."
        func_ov000_021d6a9c(func_02039e10("MUMH_訪問"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit this village or home."
        func_ov000_021d6a9c(func_02039e10("MUMH_訪問"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
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
};

class MIU_Door : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_扉");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return 5;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Open this door so units can pass through."
        func_ov000_021d6a9c(func_02039e10("MUMH_扉"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Open this door so units can pass through."
        func_ov000_021d6a9c(func_02039e10("MUMH_扉"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, ACTION_DOOR, 0);
        func_ov000_021ae180(0x28, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class MIU_Bridge : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_橋");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return 5;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Lower this drawbridge so units can cross it."
        func_ov000_021d6a9c(func_02039e10("MUMH_橋"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Lower this drawbridge so units can cross it."
        func_ov000_021d6a9c(func_02039e10("MUMH_橋"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, ACTION_BRIDGE, 0);
        func_ov000_021ae180(0x28, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class MIU_TBox : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Chest"
        return func_02039e10("MUM_宝箱");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return 5;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (!func_0203d1f4(gMapStateManager->unk_04->unk_00))
        {
            return 2;
        }

        if (!func_ov000_021d49f4(
                gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, ACTION_CHEST))
        {
            return 2;
        }

        return 0;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Open this chest and claim the item inside."
        func_ov000_021d6a9c(func_02039e10("MUMH_宝箱"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Open this chest and claim the item inside."
        func_ov000_021d6a9c(func_02039e10("MUMH_宝箱"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, ACTION_CHEST, 0);
        func_ov000_021ae180(0x28, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class MIU_WeaponShop : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_武器屋");
    }

    /* 14 */ virtual s32 vfunc_14(void)
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

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Visit the armory to buy and sell weapons."
        func_ov000_021d6a9c(func_02039e10("MUMH_武器屋"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit the armory to buy and sell weapons."
        func_ov000_021d6a9c(func_02039e10("MUMH_武器屋"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        gActionSt->actionId = 0xa;
        func_ov000_021ae180(0x15, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class MIU_ItemShop : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_道具屋");
    }

    /* 14 */ virtual s32 vfunc_14(void)
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

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Visit the vendor to buy and sell magic tomes, staves, and items."
        func_ov000_021d6a9c(func_02039e10("MUMH_道具屋"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit the vendor to buy and sell magic tomes, staves, and items."
        func_ov000_021d6a9c(func_02039e10("MUMH_道具屋"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        gActionSt->actionId = 0xb;
        func_ov000_021ae180(0x15, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class MIU_SecretShop : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_秘密屋");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Visit this hidden shop to buy and sell weapons and items."
        func_ov000_021d6a9c(func_02039e10("MUMH_秘密屋"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit this hidden shop to buy and sell weapons and items."
        func_ov000_021d6a9c(func_02039e10("MUMH_秘密屋"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        gActionSt->actionId = 0xc;
        func_ov000_021ae180(0x15, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class MIU_Arena : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_闘技場");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Visit the arena to test your might with gold at stake."
        func_ov000_021d6a9c(func_02039e10("MUMH_闘技場"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit the arena to test your might with gold at stake."
        func_ov000_021d6a9c(func_02039e10("MUMH_闘技場"), 0);
        return;
    }

    /* 20 */ virtual s32 vfunc_20(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            func_ov000_021ae180(0x16, 0, 0);
            func_ov000_021d6dfc(0);
            return 0x41;
        }

        return 0x100;
    }
};

class MIU_Transporter : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_輸送隊");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Summon the convoy to store and retrieve items."
        func_ov000_021d6a9c(func_02039e10("MUMH_輸送隊"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Summon the convoy to store and retrieve items."
        func_ov000_021d6a9c(func_02039e10("MUMH_輸送隊"), 0);
        return;
    }

    /* 20 */ virtual s32 vfunc_20(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            func_ov000_021ae180(0x22, 0, 0);
            func_ov000_021d6dfc(0);

            return 0x41;
        }

        return 0x100;
    }
};

class DI_CompleteYes : public DialogItemYes
{
public:
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, ACTION_SEIZE, 0);
        func_ov000_021ae180(0x28, 0, 0);
        func_ov000_021bfa3c();
        func_ov000_021d6dfc(0);

        return 0x44;
    }
};

class MIU_Complete : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Seize"
        return func_02039e10("MUM_制圧");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return 5;
    }

    /* 14 */ virtual s32 vfunc_14(void)
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

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "End the battle by securing this vital position."
        func_ov000_021d6a9c(func_02039e10("MUMH_制圧"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "End the battle by securing this vital position."
        func_ov000_021d6a9c(func_02039e10("MUMH_制圧"), 0);
        return;
    }

    /* 24 */ virtual s32 vfunc_24(Menu * menu, MenuItemState * menuItemState)
    {
        func_ov000_021bfa60(menu->unk_10);
        return 0x40;
    }
};

class MIU_Save : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_Ｐ記録");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            return 5;
        }

        return 2;
    }

    /* 14 */ virtual s32 vfunc_14(void)
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

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Save your progress. You can only use this savepoint once."
        func_ov000_021d6a9c(func_02039e10("MUMH_Ｐ記録"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Save your progress. You can only use this savepoint once."
        func_ov000_021d6a9c(func_02039e10("MUMH_Ｐ記録"), 0);
        return;
    }

    /* 20 */ virtual s32 vfunc_20(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            func_ov000_021ae180(0xe, 0, 0);
            func_ov000_021d6dfc(0);
            return 0x48;
        }

        return 0x100;
    }
};

class MIU_Imitation : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Imitate"
        return func_02039e10("MUM_ものまね");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        // TODO
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Transform into a neighboring allied unit. The transformation lasts five turns."
        func_ov000_021d6a9c(func_02039e10("MUMH_ものまね"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // Transform into a neighboring allied unit. The transformation lasts five turns.
        func_ov000_021d6a9c(func_02039e10("MUMH_ものまね"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021ae180(0x11, 10, 0);
        return 0x48;
    }
};

class MI_Separator : public MenuItem
{
};

class DI_LureYes : public DialogItemYes
{
public:
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, ACTION_DECOY, 0);
        func_ov000_021ae180(0x28, 0, 0);
        func_ov000_021bfa3c();
        func_ov000_021d6dfc(0);

        return 0x44;
    }
};

class MIU_Lure : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return func_02039e10("MUM_囮");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            return 5;
        }

        return 2;
    }

    /* 14 */ virtual s32 vfunc_14(void)
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

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        func_ov000_021d6a9c(func_02039e10("MUMH_囮"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        func_ov000_021d6a9c(func_02039e10("MUMH_囮"), 0);
        return;
    }

    /* 24 */ virtual s32 vfunc_24(Menu * menu, MenuItemState * menuItemState)
    {
        func_ov000_021bfaf0(menu->unk_10);
        return 0x40;
    }
};

class MIU_Fixed : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // Wait
        return func_02039e10("MUM_待機");
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // End this unit's turn.
        func_ov000_021d6a9c(func_02039e10("MUMH_待機"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // End this unit's turn.
        func_ov000_021d6a9c(func_02039e10("MUMH_待機"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, ACTION_WAIT, 0);
        func_ov000_021ae180(0x28, 0, 0);
        func_ov000_021d6dfc(0);
        return 0x41;
    }
};

class BMapDialogYesNo : public DialogYesNo
{
public:
    /* 000 */ virtual void vfunc_00(void); // func_ov000_021be6d8
    /* 0A0 */ virtual BOOL vfunc_a0(void); // func_ov000_021be934
    /* 0AC */ virtual s32 vfunc_ac(void); // func_ov000_021be91c
    /* 130 */ virtual void vfunc_130(/* ? */); // func_ov000_021bea74
    /* 134 */ virtual void vfunc_134(/* ? */); // func_ov000_021beab0
};

} // namespace map

EC void StartChildMenu(Menu *, void *, ProcPtr, u32, u32);
EC void func_020303bc(Dialog *, char *, void *, ProcPtr, s32, s32);

EC void func_ov000_021bfa60(ProcPtr proc)
{
    static map::DI_CompleteYes sCompleteYes;

    // clang-format off
    static MenuItem * data_ov000_021de5c8[] =
    {
        &sCompleteYes,
    };
    // clang-format on

    // "Proceed to the next chapter?"
    func_020303bc(new map::BMapDialogYesNo(), func_02039e10("MD_制圧"), data_ov000_021de5c8, proc, 1, 0);
    return;
}

EC void func_ov000_021bfaf0(ProcPtr proc)
{
    static map::DI_LureYes sLureYes;

    // clang-format off
    static MenuItem * data_ov000_021de5bc[] =
    {
        &sLureYes,
    };
    // clang-format on

    // "Make this unit a decoy?"
    func_020303bc(new map::BMapDialogYesNo(), func_02039e10("MD_囮"), data_ov000_021de5bc, proc, 1, 0);
    return;
}

EC void StartUnitMenu(ProcPtr proc)
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

    StartChildMenu(new map::UnitMenu(), data_ov000_021de82c, proc, 1, 0);

    return;
}
