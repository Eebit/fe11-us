#include "global.h"

#include "hardware.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "map_menu_base.hpp"
#include "menu.hpp"

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.h"
#include "unknown_types.hpp"

void map::BMapMenu::vfunc_00(void)
{
    VmMap_Common * vmMap;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_FontMenu"));
    this->unk_2c = vmMap->unk_07;
    this->unk_14 = vmMap->unk_04;
    this->unk_18 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Window"));
    this->unk_30 = vmMap->unk_07;
    this->unk_1c = vmMap->unk_04;
    this->unk_20 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_MenuCursor"));
    this->unk_24 = vmMap->unk_04;
    this->unk_28 = vmMap->unk_06;

    this->unk_41 = 1;
    this->unk_42 = 2;

    if (data_02196f24->controlSettings == 0)
    {
        this->unk_44 = 0;
    }

    if (this->unk_04 != NULL)
    {
        return;
    }

    gpActiveScreenSt->dispIo->bldcnt.effect = 1;
    gpActiveScreenSt->dispIo->blend_coeff_a = 14;
    gpActiveScreenSt->dispIo->blend_coeff_b = 2;

    gpActiveScreenSt->dispIo->bldcnt.target1_bg0_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target1_bg1_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target1_bg2_on = 1;
    gpActiveScreenSt->dispIo->bldcnt.target1_bg3_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target1_obj_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target1_bd_on = 0;

    gpActiveScreenSt->dispIo->bldcnt.target2_bg0_on = 1;
    gpActiveScreenSt->dispIo->bldcnt.target2_bg1_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target2_bg2_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target2_bg3_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target2_obj_on = 0;
    gpActiveScreenSt->dispIo->bldcnt.target2_bd_on = 1;

    return;
}

void map::BMapMenu::vfunc_08(void)
{
    MenuItemState * menuItemState = this->unk_0c;
    s32 max = 0;
    s32 i = 0;
    s32 j;
    s32 w;

    while (i < this->unk_3a)
    {
        menuItemState->unk_04 = 1;

        w = menuItemState->unk_00->vfunc_c8(menuItemState);

        if (w <= max)
        {
            w = max;
        }

        max = w;
        i++;
        menuItemState++;
    }

    if (this->unk_36 == -1)
    {
        this->unk_36 = max + 2;
    }

    if (this->unk_36 < 6)
    {
        this->unk_36 = 6;
    }

    for (j = 0, menuItemState = this->unk_0c; j < this->unk_3a; j++, menuItemState++)
    {
        menuItemState->unk_06 = this->unk_36 - 2;
    }

    return;
}

void map::BMapSystemMenu::vfunc_08(void)
{
    MenuItemState * menuItemState = this->unk_0c;
    s32 max = 0;
    s32 i = 0;
    s32 j;
    s32 w;

    while (i < this->unk_3a)
    {
        menuItemState->unk_04 = 1;

        w = menuItemState->unk_00->vfunc_c8(menuItemState);

        if (w <= max)
        {
            w = max;
        }

        max = w;
        i++;
        menuItemState++;
    }

    if (this->unk_36 == -1)
    {
        this->unk_36 = max + 2;
    }

    if (this->unk_36 < 8)
    {
        this->unk_36 = 8;
    }

    for (j = 0, menuItemState = this->unk_0c; j < this->unk_3a; j++, menuItemState++)
    {
        menuItemState->unk_06 = this->unk_36 - 2;
    }

    return;
}

void map::BMapMenu::vfunc_1c(void)
{
    s32 y;

    Menu::vfunc_10();

    if (this->unk_35 == -1)
    {
        y = (u32)(24 - ((this->unk_37 + 1) & ~1)) >> 1;

        if (y < 3)
        {
            this->unk_35 = 3;
        }
    }
    else
    {
        if (this->unk_35 < 3)
        {
            this->unk_35 = 3;
        }
    }

    Menu::vfunc_14();

    if (data_02196f24->unk_0d != 0)
    {
        if (this->unk_35 + this->unk_37 > 22)
        {
            this->unk_35 = 22 - this->unk_37;
        }
    }
    else
    {
        if (this->unk_35 + this->unk_37 > 24)
        {
            this->unk_35 = 24 - this->unk_37;
        }
    }

    Menu::vfunc_18();

    return;
}

void map::BMapDialogYesNo::vfunc_00(void)
{
    VmMap_Common * vmMap;

    this->unk_48 = 1;
    this->unk_40 = 1;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_DialogFont"));
    this->unk_14 = vmMap->unk_04;
    this->unk_18 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Dialog"));
    this->unk_30 = vmMap->unk_07;
    this->unk_1c = vmMap->unk_04;
    this->unk_20 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_MenuCursor"));
    this->unk_24 = vmMap->unk_04;
    this->unk_28 = vmMap->unk_06;

    if (data_02196f24->controlSettings == 0)
    {
        this->unk_44 = 0;
    }

    return;
}

void map::BMapScrollMenu::vfunc_10(void)
{
    VmMap_Common * vmMap;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_FontMenu"));
    this->unk_44 = vmMap->unk_07;
    this->unk_24 = vmMap->unk_04;
    this->unk_28 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Window"));
    this->unk_48 = vmMap->unk_07;
    this->unk_2c = vmMap->unk_04;
    this->unk_30 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_MenuCursor"));
    this->unk_34 = vmMap->unk_04;
    this->unk_38 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_OBJFree2"));
    this->unk_3c = vmMap->unk_04;
    this->unk_40 = vmMap->unk_06;

    this->unk_56 = 1;
    this->unk_57 = 2;

    if (data_02196f24->controlSettings == 0)
    {
        this->unk_7f = 0;
    }

    this->unk_4d = 4;

    return;
}

s32 map::BMapScrollMenu::vfunc_bc(void)
{
    return func_ov000_021a471c() != 0;
}

BOOL map::BMapScrollMenu::vfunc_ac(void)
{
    return gMapStateManager->inputHandler->_021a5650(0) != 0;
}

s32 map::BMapDialogYesNo::vfunc_ac(void)
{
    return func_ov000_021a471c() != 0;
}

BOOL map::BMapDialogYesNo::vfunc_a0(void)
{
    return gMapStateManager->inputHandler->_021a5650(0) != 0;
}

s32 map::BMapMenu::vfunc_ac(void)
{
    return func_ov000_021a471c() != 0;
}

BOOL map::BMapMenu::vfunc_a0(void)
{
    return gMapStateManager->inputHandler->_021a5650(0) != 0;
}
