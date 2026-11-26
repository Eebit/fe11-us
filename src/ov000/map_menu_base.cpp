#include "global.h"

#include "hardware.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"

#include "unknown_funcs.h"
#include "unknown_types.h"
#include "unknown_types.hpp"

extern struct UnkStruct_02196f24 * data_02196f24;

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
    virtual void vfunc_10(/* ? */); // func_02003f84
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
    virtual void vfunc_ac(/* ? */); // func_02003e90
    virtual void vfunc_b0(/* ? */); // func_02003e88
    virtual void vfunc_b4(/* ? */); // func_02003e80
    virtual void vfunc_b8(/* ? */); // func_02003e78
    virtual void vfunc_bc(/* ? */); // func_02003e70
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

static inline void ResetBlendEffect(void)
{
    gpActiveScreenSt->dispIo->bldcnt.effect = 0;
}

namespace map
{
class BMapMenu : public Menu
{
public:
    /* 000 */ virtual void vfunc_00(void);
    /* 008 */ virtual void vfunc_08(void);
    /* 01C */ virtual void vfunc_1c(void);
    /* 0A0 */ virtual BOOL vfunc_a0(void);
    /* 0AC */ virtual s32 vfunc_ac(void);

    virtual ~BMapMenu();
};

class BMapSystemMenu : public BMapMenu
{
public:
    /* 008 */ virtual void vfunc_08(void);

    virtual ~BMapSystemMenu()
    {
    }
};

class BMapScrollMenu : public menu::ScrollMenu
{
public:
    virtual ~BMapScrollMenu();
};

class BMapDialogYesNo : public DialogYesNo
{
public:
    /* 000 */ virtual void vfunc_00(void);
    /* 0A0 */ virtual BOOL vfunc_a0(void);
    /* 0AC */ virtual s32 vfunc_ac(void);

    virtual ~BMapDialogYesNo()
    {
    }
};
} // namespace map

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
    s32 i = max;
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
    s32 i = max;
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
    struct VmMap_Common * vmMap;

    this->unk_48 = 1;
    this->unk_40 = 1;

    vmMap = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_DialogFont"));
    this->unk_14 = vmMap->unk_04;
    this->unk_18 = vmMap->unk_06;

    vmMap = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_Dialog"));
    this->unk_30 = vmMap->unk_07;
    this->unk_1c = vmMap->unk_04;
    this->unk_20 = vmMap->unk_06;

    vmMap = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_MenuCursor"));
    this->unk_24 = vmMap->unk_04;
    this->unk_28 = vmMap->unk_06;

    if (data_02196f24->controlSettings == 0)
    {
        this->unk_44 = 0;
    }

    return;
}

EC void func_ov000_021be768(map::BMapScrollMenu * self)
{
    VmMap_Common * vmMap;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_FontMenu"));
    self->unk_44 = vmMap->unk_07;
    self->unk_24 = vmMap->unk_04;
    self->unk_28 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Window"));
    self->unk_48 = vmMap->unk_07;
    self->unk_2c = vmMap->unk_04;
    self->unk_30 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_MenuCursor"));
    self->unk_34 = vmMap->unk_04;
    self->unk_38 = vmMap->unk_06;

    vmMap = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_OBJFree2"));
    self->unk_3c = vmMap->unk_04;
    self->unk_40 = vmMap->unk_06;

    self->unk_56 = 1;
    self->unk_57 = 2;

    if (data_02196f24->controlSettings == 0)
    {
        self->unk_7f = 0;
    }

    self->unk_4d = 4;

    return;
}

map::BMapScrollMenu::~BMapScrollMenu()
{
    ResetBlendEffect();
}

EC BOOL func_ov000_021be8d8(void)
{
    return func_ov000_021a471c() != 0;
}

EC BOOL func_ov000_021be8f0(void)
{
    return gMapStateManager->inputHandler->_021a5650(0) != 0;
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

map::BMapMenu::~BMapMenu()
{
    if (this->unk_04 == NULL)
    {
        ResetBlendEffect();
    }
}
s32 map::BMapDialogYesNo::vfunc_ac(void)
{
    return func_ov000_021a471c() != 0;
}
