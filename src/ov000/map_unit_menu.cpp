#include "global.h"

#include "action.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"
#include "unit.hpp"

#include "unknown_types.hpp"

extern struct UnkStruct_02196f24 * data_02196f24;

EC s32 func_02039088(struct Unit * unit, int b, int c, int d, int e, u8 f, int g);
EC void func_01ff9420(MapStateManager_08 *, Unit *, s32, s32);
EC void func_01ff95a4(MapStateManager_08 *, Unit *, s32, s32);

EC s32 func_0203935c(Unit *, s32);
EC s32 func_02039400(s32, s32);
EC BOOL func_0201f680(void);

EC void func_ov000_021bfa60(ProcPtr);

EC void func_ov000_021bfaf0(ProcPtr);

EC BOOL func_ov000_021a47e4(void);
EC void func_ov000_021be21c(void);

EC s32 func_ov000_021d49f4(s32, s32, s32);

EC BOOL func_0202dad0(MenuItemState * menuItemState, Menu * menu);
EC void PlayerPhase_GotoLabel(s32, s32, s32);
EC void func_ov000_021bfa3c(void);
EC void StartSubtitleHelp(char *, s32);

extern struct UnkStruct_021e3340 * data_ov000_021e3340;

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
        TryShowTutCardForMenu(this->unk_10, 1);
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
                gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_WAIT, 0);
            PlayerPhase_GotoLabel(40, 0, 0);
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
        return GetText("MUM_話す");
    }

    /* 10 */ virtual s32 vfunc_10(void)
    {
        return MENU_COLOR_GREEN;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        s32 ux;
        s32 uy;
        s16 xMin;
        s16 yMin;
        s16 xMax;
        s16 yMax;
        s16 ix;
        s16 iy;
        Unit * unit;

        if (func_ov000_021a47e4())
        {
            return MENU_NOTSHOWN;
        }

        ux = gMapStateManager->unk_04->pUnit->xPos;
        uy = gMapStateManager->unk_04->pUnit->yPos;

        xMin = MAX(ux - 1, gMapStateManager->unk_24);
        yMin = MAX(uy - 1, gMapStateManager->unk_25);

        xMax = MIN(ux + 1, gMapStateManager->unk_26 - 1);
        yMax = MIN(uy + 1, gMapStateManager->unk_27 - 1);

        for (iy = yMin; iy <= yMax; iy++)
        {
            for (ix = xMin; ix <= xMax; ix++)
            {
                s32 xDiff;
                s32 yDiff;
                char * personA;
                char * personB;

                yDiff = ABS(gMapStateManager->unk_04->pUnit->yPos - iy);
                xDiff = ABS(gMapStateManager->unk_04->pUnit->xPos - ix);

                if ((xDiff + yDiff >= 1) && (xDiff + yDiff <= 1))
                {
                    unit = GetUnit(gMapStateManager->unk_028[(ix | iy << 5)]);

                    if (unit == NULL)
                    {
                        continue;
                    }

                    personB = func_0203c378(unit)->pPersonData->pid;
                    personA = func_0203c378(gMapStateManager->unk_04->pUnit)->pPersonData->pid;

                    if (EventCaller::CanStartTalkEvent((u32)personA, (u32)personB))
                    {
                        return MENU_ENABLED;
                    }
                }
            }
        }

        return MENU_NOTSHOWN;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Talk to a neighboring unit. (Shortcuts: ┳┫, ┻╋)"
        StartSubtitleHelp(GetText("MUMH_話す"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Talk to a neighboring unit. (Shortcuts: ┳┫, ┻╋)"
        StartSubtitleHelp(GetText("MUMH_話す"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(17, 9, 0);
        return MENU_ACTION_x40 | MENU_ACTION_x8;
    }
};

class MIU_Attack : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // Attack
        return GetText("MUM_攻撃");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        s32 unitId;
        Unit * unit;
        s16 ix;
        s16 iy;

        func_01ff9420(gMapStateManager->unk_08, gMapStateManager->unk_04->pUnit, -1, -1);

        for (iy = gMapStateManager->unk_25; iy < gMapStateManager->unk_27; iy++)
        {
            for (ix = gMapStateManager->unk_24; ix < gMapStateManager->unk_26; ix++)
            {
                s32 unk = gMapStateManager->unk_08->unk_0854[ix | (iy << 5)];

                if (unk < 0)
                {
                    continue;
                }

                unitId = gMapStateManager->unk_028[(ix | (iy << 5))];

                if (unitId != 0)
                {
                    unit = gUnitList + unitId - 1;
                }
                else
                {
                    unit = NULL;
                }

                if (unit == NULL)
                {
                    continue;
                }

                if (func_02039088(gMapStateManager->unk_04->pUnit, ix, iy, unk, 1, 0, -1) < 0)
                {
                    continue;
                }

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

        // Attack with an available weapon. (Shortcuts: ┳┫, ┻╋)
        StartSubtitleHelp(GetText("MUMH_攻撃"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // Attack with an available weapon. (Shortcuts: ┳┫, ┻╋)
        StartSubtitleHelp(GetText("MUMH_攻撃"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(12, 0, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x8;
    }
};

class MIU_Rod : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // Staff
        return GetText("MUM_杖");
    }

    /* 18 */ virtual s32 vfunc_18(void)
    {
        s16 ix;
        s16 iy;

        if (func_0203935c(gMapStateManager->unk_04->pUnit, -1) != -1)
        {
            return 0;
        }

        func_01ff95a4(gMapStateManager->unk_08, gMapStateManager->unk_04->pUnit, -1, -1);

        for (iy = gMapStateManager->unk_25; iy < gMapStateManager->unk_27; iy++)
        {
            for (ix = gMapStateManager->unk_24; ix < gMapStateManager->unk_26; ix++)
            {
                if (gMapStateManager->unk_08->unk_0854[ix | (iy << 5)] < 0)
                {
                    continue;
                }

                if (func_02039400(ix, iy) == 0)
                {
                    continue;
                }

                if (func_02039088(
                        gMapStateManager->unk_04->pUnit, ix, iy, gMapStateManager->unk_08->unk_0854[ix | (iy << 5)], 1,
                        0, -1) < 0)
                {
                    continue;
                }

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

        // Use an available staff. (Shortcuts: ┳┫, ┻╋)
        StartSubtitleHelp(GetText("MUMH_杖"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // Use an available staff. (Shortcuts: ┳┫, ┻╋)
        StartSubtitleHelp(GetText("MUMH_杖"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(12, 1, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x8;
    }
};

class MIU_Item : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_持ち物");
    }

    /* 18 */ virtual s32 vfunc_18(void)
    {
        if ((data_02196f24->enableTutorials != 0) && (((data_ov000_021e3324->unk_1c & 1) ? TRUE : FALSE) & 0xFF))
        {
            return 2;
        }

        if (!((gMapStateManager->unk_04->pUnit->items[0].id != 0 ? TRUE : FALSE) & 0xFF))
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

        // "Use, discard, or otherwise manage items."
        StartSubtitleHelp(GetText("MUMH_持ち物"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Use, discard, or otherwise manage items."
        StartSubtitleHelp(GetText("MUMH_持ち物"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(12, 4, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x8;
    }
};

class MIU_Trade : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_交換");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        s32 ux;
        s32 uy;
        s16 xMin;
        s16 yMin;
        s16 xMax;
        s16 yMax;
        s16 ix;
        s16 iy;
        s32 xDiff;
        s32 yDiff;
        s32 itemId;
        Unit * unit;

        if (data_ov000_021e3340->unk_06 & 1)
        {
            return MENU_NOTSHOWN;
        }

        itemId = (((gMapStateManager->unk_04->pUnit->items[0].id != 0) ? TRUE : FALSE) & 0xFF);

        ux = gMapStateManager->unk_04->pUnit->xPos;
        uy = gMapStateManager->unk_04->pUnit->yPos;

        xMin = MAX(ux - 1, gMapStateManager->unk_24);
        yMin = MAX(uy - 1, gMapStateManager->unk_25);

        xMax = MIN(ux + 1, gMapStateManager->unk_26 - 1);
        yMax = MIN(uy + 1, gMapStateManager->unk_27 - 1);

        for (iy = yMin; iy <= yMax; iy++)
        {
            for (ix = xMin; ix <= xMax; ix++)
            {
                yDiff = ABS(gMapStateManager->unk_04->pUnit->yPos - iy);
                xDiff = ABS(gMapStateManager->unk_04->pUnit->xPos - ix);

                if (xDiff + yDiff < 1)
                {
                    continue;
                }

                if (xDiff + yDiff > 1)
                {
                    continue;
                }

                unit = GetUnit(gMapStateManager->unk_028[(ix | iy << 5)]);

                if (unit == NULL)
                {
                    continue;
                }

                if (gMapStateManager->unk_04->pUnit->force->id != unit->force->id)
                {
                    continue;
                }

                if (!itemId && !(((unit->items[0].id != 0) ? TRUE : FALSE) & 0xFF))
                {
                    continue;
                }

                return MENU_ENABLED;
            }
        }

        return MENU_NOTSHOWN;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Trade items with a neighboring unit."
        StartSubtitleHelp(GetText("MUMH_交換"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Trade items with a neighboring unit."
        StartSubtitleHelp(GetText("MUMH_交換"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(17, 7, 0);
        return MENU_ACTION_x40 | MENU_ACTION_x8;
    }
};

class MIU_Visit : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_訪問");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return MENU_COLOR_GREEN;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021d49f4(gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, 8))
        {
            if (gMapStateManager->unk_04->pUnit->CheckAttribute(CA_UNK_1))
            {
                return MENU_ENABLED;
            }
        }

        if (func_ov000_021d49f4(gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, 9))
        {
            return MENU_ENABLED;
        }

        return MENU_NOTSHOWN;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Visit this village or home."
        StartSubtitleHelp(GetText("MUMH_訪問"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit this village or home."
        StartSubtitleHelp(GetText("MUMH_訪問"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        s32 actionId = ACTION_NONE;

        if (func_ov000_021d49f4(gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_VISIT_08))
        {
            if (gMapStateManager->unk_04->pUnit->CheckAttribute(CA_UNK_1))
            {
                actionId = ACTION_VISIT_08;
            }
        }

        if (func_ov000_021d49f4(gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_VISIT_09))
        {
            actionId = ACTION_VISIT_09;
        }

        func_ov000_021b0de8(gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, actionId, 0);
        PlayerPhase_GotoLabel(40, 0, 0);
        func_ov000_021d6dfc(0);

        return MENU_ACTION_x40 | MENU_ACTION_x1;
    }
};

class MIU_Door : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_扉");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return MENU_COLOR_GREEN;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        s16 xMax;
        s16 yMax;
        s16 xMin;
        s16 yMin;
        s16 ix;
        s16 iy;
        s32 ux;
        s32 uy;

        if (!gMapStateManager->unk_04->pUnit->_0203d184())
        {
            return MENU_NOTSHOWN;
        }

        ux = gMapStateManager->unk_04->pUnit->xPos;
        uy = gMapStateManager->unk_04->pUnit->yPos;

        xMin = MAX(ux - 1, gMapStateManager->unk_24);
        yMin = MAX(uy - 1, gMapStateManager->unk_25);

        xMax = MIN(ux + 1, gMapStateManager->unk_26 - 1);
        yMax = MIN(uy + 1, gMapStateManager->unk_27 - 1);

        for (iy = yMin; iy <= yMax; iy++)
        {
            for (ix = xMin; ix <= xMax; ix++)
            {
                s32 xDiff;
                s32 yDiff;

                yDiff = ABS(gMapStateManager->unk_04->pUnit->yPos - iy);
                xDiff = ABS(gMapStateManager->unk_04->pUnit->xPos - ix);

                if (xDiff + yDiff < 1)
                {
                    continue;
                }

                if (xDiff + yDiff > 1)
                {
                    continue;
                }

                if (!func_ov000_021d49f4(ix, iy, 5))
                {
                    continue;
                }

                return MENU_ENABLED;
            }
        }

        return MENU_NOTSHOWN;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Open this door so units can pass through."
        StartSubtitleHelp(GetText("MUMH_扉"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Open this door so units can pass through."
        StartSubtitleHelp(GetText("MUMH_扉"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_DOOR, 0);
        PlayerPhase_GotoLabel(40, 0, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x1;
    }
};

class MIU_Bridge : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_橋");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return MENU_COLOR_GREEN;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        s16 xMax;
        s16 yMax;
        s16 xMin;
        s16 yMin;
        s16 ix;
        s16 iy;
        s32 ux;
        s32 uy;

        if (!gMapStateManager->unk_04->pUnit->_0203d1bc())
        {
            return MENU_NOTSHOWN;
        }

        ux = gMapStateManager->unk_04->pUnit->xPos;
        uy = gMapStateManager->unk_04->pUnit->yPos;

        xMin = MAX(ux - 1, gMapStateManager->unk_24);
        yMin = MAX(uy - 1, gMapStateManager->unk_25);

        xMax = MIN(ux + 1, gMapStateManager->unk_26 - 1);
        yMax = MIN(uy + 1, gMapStateManager->unk_27 - 1);

        for (iy = yMin; iy <= yMax; iy++)
        {
            for (ix = xMin; ix <= xMax; ix++)
            {
                s32 xDiff;
                s32 yDiff;

                yDiff = ABS(gMapStateManager->unk_04->pUnit->yPos - iy);
                xDiff = ABS(gMapStateManager->unk_04->pUnit->xPos - ix);

                if (xDiff + yDiff < 0)
                {
                    continue;
                }

                if (xDiff + yDiff > 1)
                {
                    continue;
                }

                if (!func_ov000_021d49f4(ix, iy, 7))
                {
                    continue;
                }

                return MENU_ENABLED;
            }
        }

        return MENU_NOTSHOWN;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Lower this drawbridge so units can cross it."
        StartSubtitleHelp(GetText("MUMH_橋"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Lower this drawbridge so units can cross it."
        StartSubtitleHelp(GetText("MUMH_橋"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_BRIDGE, 0);
        PlayerPhase_GotoLabel(40, 0, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x1;
    }
};

class MIU_TBox : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Chest"
        return GetText("MUM_宝箱");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return MENU_COLOR_GREEN;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (!gMapStateManager->unk_04->pUnit->_0203d1f4())
        {
            return MENU_NOTSHOWN;
        }

        if (!func_ov000_021d49f4(
                gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_CHEST))
        {
            return MENU_NOTSHOWN;
        }

        return MENU_ENABLED;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Open this chest and claim the item inside."
        StartSubtitleHelp(GetText("MUMH_宝箱"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Open this chest and claim the item inside."
        StartSubtitleHelp(GetText("MUMH_宝箱"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_CHEST, 0);
        PlayerPhase_GotoLabel(40, 0, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x1;
    }
};

class MIU_WeaponShop : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Armory"
        return GetText("MUM_武器屋");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021a47e4())
        {
            return MENU_NOTSHOWN;
        }

        if (!EventCaller::CanStartVisitEvent(
                gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, 0xa))
        {
            return MENU_NOTSHOWN;
        }

        return MENU_ENABLED;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Visit the armory to buy and sell weapons."
        StartSubtitleHelp(GetText("MUMH_武器屋"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit the armory to buy and sell weapons."
        StartSubtitleHelp(GetText("MUMH_武器屋"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        gActionSt->actionId = ACTION_ARMORY;
        PlayerPhase_GotoLabel(21, 0, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x1;
    }
};

class MIU_ItemShop : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_道具屋");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021a47e4())
        {
            return MENU_NOTSHOWN;
        }

        if (!EventCaller::CanStartVisitEvent(
                gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, 0xb))
        {
            return MENU_NOTSHOWN;
        }

        return MENU_ENABLED;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Visit the vendor to buy and sell magic tomes, staves, and items."
        StartSubtitleHelp(GetText("MUMH_道具屋"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit the vendor to buy and sell magic tomes, staves, and items."
        StartSubtitleHelp(GetText("MUMH_道具屋"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        gActionSt->actionId = ACTION_VENDOR;
        PlayerPhase_GotoLabel(21, 0, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x1;
    }
};

class MIU_SecretShop : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_秘密屋");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021a47e4())
        {
            return 2;
        }

        if (EventCaller::CanStartVisitEvent(
                gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, 0xc))
        {

            if (gMapStateManager->unk_04->pUnit->GetItemAttributes(0x1000000) != 0)
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

        // "Visit this hidden shop to buy and sell weapons and items."
        StartSubtitleHelp(GetText("MUMH_秘密屋"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit this hidden shop to buy and sell weapons and items."
        StartSubtitleHelp(GetText("MUMH_秘密屋"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        gActionSt->actionId = ACTION_SECRET_SHOP;
        PlayerPhase_GotoLabel(21, 0, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x1;
    }
};

class MIU_Arena : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_闘技場");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        s32 i;

        if (func_ov000_021a47e4())
        {
            return 2;
        }

        if (gMapStateManager
                ->unk_828[gMapStateManager->unk_04->pUnit->xPos | gMapStateManager->unk_04->pUnit->yPos << 5] != 0x17)
        {
            return 2;
        }

        for (i = 0; i < 6; i++)
        {
            if (i == 5)
            {
                continue;
            }

            if (gMapStateManager->unk_04->pUnit->GetWeaponLevel(i))
            {
                return 0;
            }
        }

        return 1;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Visit the arena to test your might with gold at stake."
        StartSubtitleHelp(GetText("MUMH_闘技場"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Visit the arena to test your might with gold at stake."
        StartSubtitleHelp(GetText("MUMH_闘技場"), 0);
        return;
    }

    /* 20 */ virtual s32 vfunc_20(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            PlayerPhase_GotoLabel(22, 0, 0);
            func_ov000_021d6dfc(0);
            return MENU_ACTION_x40 | MENU_ACTION_x1;
        }

        return MENU_ACTION_x100;
    }
};

class MIU_Transporter : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_輸送隊");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        s16 xMax;
        s16 yMax;
        s16 xMin;
        s16 yMin;
        s16 iy;
        s16 ix;
        s32 ux;
        s32 uy;
        Unit * unit;

        if (func_ov000_021a47e4())
        {
            return MENU_NOTSHOWN;
        }

        if (data_02196f0c->state & 0x4000)
        {
            return MENU_NOTSHOWN;
        }

        if (data_ov000_021e3340->unk_06 & 0x10)
        {
            return MENU_NOTSHOWN;
        }

        if (gMapStateManager->unk_04->pUnit->CheckAttribute(CA_UNK_1))
        {
            return MENU_ENABLED;
        }

        ux = gMapStateManager->unk_04->pUnit->xPos;
        uy = gMapStateManager->unk_04->pUnit->yPos;

        xMin = MAX(ux - 1, gMapStateManager->unk_24);
        yMin = MAX(uy - 1, gMapStateManager->unk_25);

        xMax = MIN(ux + 1, gMapStateManager->unk_26 - 1);
        yMax = MIN(uy + 1, gMapStateManager->unk_27 - 1);

        for (iy = yMin; iy <= yMax; iy++)
        {
            for (ix = xMin; ix <= xMax; ix++)
            {
                s32 xDiff;
                s32 yDiff;

                yDiff = ABS(gMapStateManager->unk_04->pUnit->yPos - iy);
                xDiff = ABS(gMapStateManager->unk_04->pUnit->xPos - ix);

                if (xDiff + yDiff < 1)
                {
                    continue;
                }

                if (xDiff + yDiff > 1)
                {
                    continue;
                }

                unit = GetUnit(gMapStateManager->unk_028[(ix | iy << 5)]);

                if (unit == NULL)
                {
                    continue;
                }

                if (unit->force->id != gMapStateManager->unk_04->pUnit->force->id)
                {
                    continue;
                }

                if (!unit->CheckAttribute(CA_UNK_1))
                {
                    continue;
                }

                return MENU_ENABLED;
            }
        }

        return MENU_NOTSHOWN;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Summon the convoy to store and retrieve items."
        StartSubtitleHelp(GetText("MUMH_輸送隊"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Summon the convoy to store and retrieve items."
        StartSubtitleHelp(GetText("MUMH_輸送隊"), 0);
        return;
    }

    /* 20 */ virtual s32 vfunc_20(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            PlayerPhase_GotoLabel(34, 0, 0);
            func_ov000_021d6dfc(0);
            return MENU_ACTION_x40 | MENU_ACTION_x1;
        }

        return MENU_ACTION_x100;
    }
};

class DI_CompleteYes : public DialogItemYes
{
public:
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_SEIZE, 0);
        PlayerPhase_GotoLabel(40, 0, 0);
        func_ov000_021bfa3c();
        func_ov000_021d6dfc(0);

        return MENU_ACTION_x40 | MENU_ACTION_x4;
    }
};

class MIU_Complete : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Seize"
        return GetText("MUM_制圧");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        return MENU_COLOR_GREEN;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (EventCaller::CanStartVisitEvent(
                gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, 0xe))
        {
            if (gMapStateManager->unk_04->pUnit->CheckAttribute(CA_UNK_1))
            {
                return MENU_ENABLED;
            }
        }

        return MENU_NOTSHOWN;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "End the battle by securing this vital position."
        StartSubtitleHelp(GetText("MUMH_制圧"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "End the battle by securing this vital position."
        StartSubtitleHelp(GetText("MUMH_制圧"), 0);
        return;
    }

    /* 24 */ virtual s32 vfunc_24(Menu * menu, MenuItemState * menuItemState)
    {
        func_ov000_021bfa60(menu->unk_10);
        return MENU_ACTION_x40;
    }
};

class MIU_Save : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_Ｐ記録");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            return MENU_COLOR_GREEN;
        }

        return MENU_COLOR_GRAY;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021a47e4())
        {
            return MENU_NOTSHOWN;
        }

        if (func_ov000_021d49f4(gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, 0x10))
        {
            if (!func_0201f680())
            {
                return MENU_DISABLED;
            }
            else
            {
                return MENU_ENABLED;
            }
        }

        return MENU_NOTSHOWN;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Save your progress. You can only use this savepoint once."
        StartSubtitleHelp(GetText("MUMH_Ｐ記録"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // "Save your progress. You can only use this savepoint once."
        StartSubtitleHelp(GetText("MUMH_Ｐ記録"), 0);
        return;
    }

    /* 20 */ virtual s32 vfunc_20(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            PlayerPhase_GotoLabel(14, 0, 0);
            func_ov000_021d6dfc(0);
            return MENU_ACTION_x40 | MENU_ACTION_x8;
        }

        return MENU_ACTION_x100;
    }
};

class MIU_Imitation : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // "Imitate"
        return GetText("MUM_ものまね");
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        s16 xMax;
        s16 yMax;
        s16 xMin;
        s16 yMin;
        s16 iy;
        s16 ix;
        s32 ux;
        s32 uy;
        Unit * unit;

        if (gMapStateManager->unk_04->pUnit->state2 & 0x8000)
        {
            return MENU_NOTSHOWN;
        }

        if (!gMapStateManager->unk_04->pUnit->CheckAttribute(CA_FREELANCER))
        {
            return MENU_NOTSHOWN;
        }

        ux = gMapStateManager->unk_04->pUnit->xPos;
        uy = gMapStateManager->unk_04->pUnit->yPos;

        xMin = MAX(ux - 1, gMapStateManager->unk_24);
        yMin = MAX(uy - 1, gMapStateManager->unk_25);

        xMax = MIN(ux + 1, gMapStateManager->unk_26 - 1);
        yMax = MIN(uy + 1, gMapStateManager->unk_27 - 1);

        for (iy = yMin; iy <= yMax; iy++)
        {
            for (ix = xMin; ix <= xMax; ix++)
            {
                s32 xDiff;
                s32 yDiff;

                yDiff = ABS(gMapStateManager->unk_04->pUnit->yPos - iy);
                xDiff = ABS(gMapStateManager->unk_04->pUnit->xPos - ix);

                if (xDiff + yDiff < 1)
                {
                    continue;
                }

                if (xDiff + yDiff > 1)
                {
                    continue;
                }

                unit = GetUnit(gMapStateManager->unk_028[(ix | iy << 5)]);

                if (unit == NULL)
                {
                    continue;
                }

                if (unit->force->id != gMapStateManager->unk_04->pUnit->force->id)
                {
                    continue;
                }

                if (unit->CheckAttribute(CA_UNK_24))
                {
                    continue;
                }

                return MENU_ENABLED;
            }
        }

        return MENU_NOTSHOWN;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // "Transform into a neighboring allied unit. The transformation lasts five turns."
        StartSubtitleHelp(GetText("MUMH_ものまね"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // Transform into a neighboring allied unit. The transformation lasts five turns.
        StartSubtitleHelp(GetText("MUMH_ものまね"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        PlayerPhase_GotoLabel(17, 10, 0);
        return MENU_ACTION_x40 | MENU_ACTION_x8;
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
            gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_DECOY, 0);
        PlayerPhase_GotoLabel(40, 0, 0);
        func_ov000_021bfa3c();
        func_ov000_021d6dfc(0);

        return MENU_ACTION_x40 | MENU_ACTION_x4;
    }
};

class MIU_Lure : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        return GetText("MUM_囮");
    }

    /* 10 */ virtual s32 vfunc_10(MenuItemState * menuItemState)
    {
        if ((menuItemState->unk_09 & 7) != 1)
        {
            return MENU_COLOR_GREEN;
        }

        return MENU_COLOR_GRAY;
    }

    /* 14 */ virtual s32 vfunc_14(void)
    {
        if (func_ov000_021a47e4())
        {
            return MENU_NOTSHOWN;
        }

        if (!func_ov000_021d49f4(gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, 0x13))
        {
            return MENU_NOTSHOWN;
        }

        return MENU_ENABLED;
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        StartSubtitleHelp(GetText("MUMH_囮"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        StartSubtitleHelp(GetText("MUMH_囮"), 0);
        return;
    }

    /* 24 */ virtual s32 vfunc_24(Menu * menu, MenuItemState * menuItemState)
    {
        func_ov000_021bfaf0(menu->unk_10);
        return MENU_ACTION_x40;
    }
};

class MIU_Fixed : public MenuItem
{
public:
    /* 00 */ virtual char * vfunc_00(void)
    {
        // Wait
        return GetText("MUM_待機");
    }

    /* 90 */ virtual void vfunc_90(Menu * menu, MenuItemState * menuItemState)
    {
        if (!func_0202dad0(menuItemState, menu))
        {
            return;
        }

        // End this unit's turn.
        StartSubtitleHelp(GetText("MUMH_待機"), 0);

        return;
    }

    /* 78 */ virtual void vfunc_78(Menu * menu, MenuItemState * menuItemState)
    {
        // End this unit's turn.
        StartSubtitleHelp(GetText("MUMH_待機"), 0);
        return;
    }

    /* 1C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->pUnit->xPos, gMapStateManager->unk_04->pUnit->yPos, ACTION_WAIT, 0);
        PlayerPhase_GotoLabel(40, 0, 0);
        func_ov000_021d6dfc(0);
        return MENU_ACTION_x40 | MENU_ACTION_x1;
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
    func_020303bc(new map::BMapDialogYesNo(), GetText("MD_制圧"), data_ov000_021de5c8, proc, 1, 0);
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
    func_020303bc(new map::BMapDialogYesNo(), GetText("MD_囮"), data_ov000_021de5bc, proc, 1, 0);
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
