#include "global.h"

#include <new>

#include "action.hpp"
#include "anime.hpp"
#include "hardware.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

EC BOOL func_0201f680(void);
EC void func_0202a6a8(s32, s32);
EC void func_02051324(s32, s32, s32, s32, s32, s32);

EC void func_0202b4b0(void *, s32);
EC void func_020512f8(s32, s32, s32);

// FIXME
EC void * __func_0201177c(char *, u32);


EC void func_ov000_021d5fbc(ProcPtr parent);
EC void PlayerPhase_GotoLabel(s32 label, s32 arg_1, s32 arg_2);

class SaveMenuItem : public MenuItem
{
public:
    virtual s32 vfunc_d8(void);
    virtual s32 vfunc_dc(void);
    virtual s32 vfunc_e0(void);
    virtual void vfunc_e4(/* ? */);
    virtual void vfunc_e8(MenuItemState *, s32, s32, s32);
    virtual void vfunc_ec(s32);
    virtual s32 vfunc_f0(void);
    virtual s32 vfunc_f4(void);
};

namespace mapsave
{

class MapSave : public ProcEx
{
public:
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;

    MapSave(s32 param_1)
    {
        this->unk_38 = param_1;
        this->unk_3c = 0;
        this->unk_40 = gMapStateManager->unk_14->unk_25;
    }

    // func_ov000_021d673c
    // func_ov000_021d6740
    virtual ~MapSave()
    {
    }
};

class PointSaveMenu : public Menu
{
public:
    Anime * unk_50;

    PointSaveMenu()
    {
        this->unk_50 = NULL;
    }

    // func_ov000_021d6460
    /* 000 */ virtual void vfunc_00(void)
    {
        VmMap_Common * iVar1;
        s32 iVar3;
        u32 * uVar4;
        s32 iVar5;

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_FontMenu"));
        this->unk_2c = iVar1->unk_07;
        this->unk_14 = iVar1->unk_04;
        this->unk_18 = iVar1->unk_06;

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_OBJFree"));
        this->unk_24 = iVar1->unk_04 + 0x80;
        this->unk_28 = iVar1->unk_06;

        func_0202b4b0((void *)gpActiveScreenSt->objVram, this->unk_24);
        func_020512f8(0, this->unk_24 + 0x10, this->unk_28 + 1);

        this->unk_41 = 1;
        this->unk_42 = 2;

        if (data_02196f24->controlSettings == 0)
        {
            this->unk_44 = 0;
        }

        func_020a8f40("/mm");

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_FontMenuSub"));
        func_0201177c("gradefont.cg", (u32)((u16 *)(gpActiveScreenSt->bgTiles[iVar1->unk_07]) + iVar1->unk_04 * 0x20));

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Window"));
        func_02011a70("gradefont.cl", (iVar1->unk_06 + 7) * 0x20, 0, 0);

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Window"));
        this->unk_20 = iVar1->unk_06;

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_BG2Free"));
        this->unk_30 = iVar1->unk_07;
        this->unk_1c = iVar1->unk_04;

        func_0201177c("savemenu.cg", (u32)((u16 *)(gpActiveScreenSt->bgTiles[iVar1->unk_07]) + iVar1->unk_04 * 0x20));

        iVar3 = this->vfunc_138();

        // FIXME
        uVar4 = (u32 *)__func_0201177c("savemenu_point.sc", iVar3);

        func_0201177c("savemenu_time.sc", (u32)iVar3 + ((u32)uVar4 & ~1));
        func_02011a70("savemenu.cl", this->unk_20 << 5, 0, 0);
        func_02010d98((void *)iVar3, 0x600, (s16)this->unk_1c, (s16)this->unk_20);

        iVar3 = this->unk_28;
        iVar5 = this->unk_24 + 0x30;

        func_0201177c("playtime.cg", gpActiveScreenSt->objVram + iVar5 * 0x20);
        func_02011a70("playtime.cl", (iVar3 + 0x12) * 0x20, 0, 0);

        this->unk_50 = StartAnimByName(
            "playtime.anm", 0, 0x80, 0x60,
            iVar3 + 2 | (this->unk_41 << 0xc) | (iVar5 >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14 & 0x3ff),
            this->unk_42, NULL);

        if (this->unk_50->interpreter != NULL)
        {
            this->unk_50->interpreter->SetVisible(1);
        }

        if (this->unk_50->interpreter != NULL)
        {
            this->unk_50->interpreter->SetLoopingEnabled(1);
        }

        this->unk_35 = 8;

        return;
    }

    // func_ov000_021d6400
    /* 114 */ virtual void vfunc_114(void)
    {
        AnimeInterpreter * pAVar1;

        func_02051324(0x40, 0x24, this->unk_24 + 0x10, this->unk_28 + 1, this->unk_41, this->unk_42);

        pAVar1 = this->unk_50->interpreter;

        if (pAVar1 != NULL)
        {
            this->unk_50->interpreter->DrawInternal(0x80, 0x60);
        }

        return;
    }

    // func_ov000_021d63d4
    /* 0A0 */ virtual BOOL vfunc_a0(void)
    {
        return gMapStateManager->inputHandler->_021a5650(0) != 0;
    }

    // func_ov000_021d639c
    /* 0B8 */ virtual void vfunc_b8(s32 param_2)
    {
        gMapStateManager->unk_14->unk_25 = Interpolate(0, 0, -16, param_2, 4);
        return;
    }

    // func_ov000_021d6350
    /* 028 */ virtual s32 vfunc_28(s32 arg0)
    {
        if (!(((arg0 & 0x3f) == 0) ? TRUE : FALSE))
        {
            PlayerPhase_GotoLabel(11, -1, 0);
            gMapStateManager->unk_14->unk_25 = 0;
            return 0x88;
        }

        return arg0;
    }

    /* 130 */ // func_ov000_021d62f8
    /* 134 */ // func_ov000_021d6298
    virtual ~PointSaveMenu()
    {
        VmMap_Common * iVar1;

        if (this->unk_50 != NULL)
        {
            Proc_End(this->unk_50);
        }

        iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Window"));
        func_0202a6a8(iVar1->unk_06, data_ov000_021e3324->unk_01);
    }

    // virtual s32 vfunc_138(void);
};

class DI_PointSaveYes : public DialogItemYes
{
public:
    // func_ov000_021d6238
    /* 1C */ virtual s32 vfunc_1c(void)
    {
        if (func_0201f680())
        {
            func_ov000_021b0de8(
                gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, 0x10,
                gActionSt->unk_37);
            PlayerPhase_GotoLabel(0x28, 0, 0);

            return 0x60;
        }

        return 0x100;
    }
};

class MapPointSaveMenuItem : public SaveMenuItem
{
public:
    // func_ov000_021d6230
    /* D8 */ virtual s32 vfunc_d8(void)
    {
        return 0x10;
    }

    // func_ov000_021d6218
    /* DC */ virtual s32 vfunc_dc(void)
    {
        VmMap_Common * iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_FontMenuSub"));
        return iVar1->unk_04;
    }

    // func_ov000_021d61fc
    /* E0 */ virtual s32 vfunc_e0(void)
    {
        VmMap_Common * iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Window"));
        return iVar1->unk_06 + 7;
    }

    // func_ov000_021d61b8
    /* 74 */ virtual void vfunc_74(MenuItemState * menuItemState)
    {
        VmMap_Common * iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_FontMenuHelp"));
        this->vfunc_e8(menuItemState, iVar1->unk_07, iVar1->unk_04, iVar1->unk_06);
        return;
    }

    // func_ov000_021d6188
    /* 80 */ virtual void vfunc_80(MenuItemState * menuItemState)
    {
        VmMap_Common * iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_FontMenuHelp"));
        this->vfunc_ec(iVar1->unk_07);

        return;
    }

    // func_ov000_021d6148
    /* 24 */ virtual s32 vfunc_24(Menu * menu, MenuItemState * menuItemState)
    {
        if (func_0201f680())
        {
            gActionSt->unk_37 = menuItemState->unk_08;
            func_ov000_021d5fbc(menu->unk_10);

            return 0x40;
        }

        return 0x100;
    }

    // func_ov000_021d6130
    /* F0 */ virtual s32 vfunc_f0(void)
    {
        VmMap_Common * iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_BG2Free"));
        return iVar1->unk_07;
    }

    // func_ov000_021d6118
    /* F4 */ virtual s32 vfunc_f4(void)
    {
        VmMap_Common * iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Window"));
        return iVar1->unk_06;
    }
};

} // namespace mapsave

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

} // namespace map

EC void func_020303bc(Dialog *, char *, void *, ProcPtr, s32, s32);
EC void func_01ff9948(s32);

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

EC u32 func_02028e7c(UnkStruct_021970c4 *, char *, s32);
EC s32 func_020290f4(struct UnkStruct_021970c4 *, char *);

EC void func_ov000_021d59d0(mapsave::MapSave * param_1)
{
    s32 cVar2;

    if (param_1->unk_3c == 0)
    {
        VmMap_Common * iVar3 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Font"));

        func_020295ec(
            data_021970c4, func_02039e10("MNT_SAVE"), gpActiveScreenSt->bgTiles[iVar3->unk_07],
            gpActiveScreenSt->tilemap[iVar3->unk_07],
            0x100 - (func_02028e7c(data_021970c4, func_02039e10("MNT_SAVE"), 0) + 7 & ~7) >> 4,
            0xc - func_020290f4(data_021970c4, func_02039e10("MNT_SAVE")), iVar3->unk_04, iVar3->unk_06, 0, 0);

        gpActiveScreenSt->unk_3e |= 1 << iVar3->unk_07;

        gpActiveScreenSt->dispIo->bldcnt.effect = 1;

        gpActiveScreenSt->dispIo->blend_coeff_a = 0;
        gpActiveScreenSt->dispIo->blend_coeff_b = 16;

        gpActiveScreenSt->dispIo->bldcnt.target1_bg0_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_bg1_on = 1;
        gpActiveScreenSt->dispIo->bldcnt.target1_bg2_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_bg3_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_obj_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_bd_on = 0;

        gpActiveScreenSt->dispIo->bldcnt.target2_bg0_on = 1;
        gpActiveScreenSt->dispIo->bldcnt.target2_bg1_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_bg2_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_bg3_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_obj_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_bd_on = 0;
    }

    param_1->unk_3c++;

    gMapStateManager->unk_14->unk_25 = Interpolate(0, param_1->unk_40, -16, param_1->unk_3c, 4);

    cVar2 = Interpolate(0, -param_1->unk_40 >> 1, 0x10, param_1->unk_3c, 4);

    gpActiveScreenSt->dispIo->blend_coeff_a = cVar2;
    gpActiveScreenSt->dispIo->blend_coeff_b = 16 - cVar2;

    if (param_1->unk_3c == 4)
    {
        param_1->unk_3c = 0;
        Proc_Break(param_1, 1);
    }

    return;
}

EC void func_ov000_021d4cb4(s32, s32);

EC void func_ov000_021d5d70(mapsave::MapSave * param_1)
{
    gpActiveScreenSt->dispIo->bldcnt.effect = 0;

    if (param_1->unk_38 == 0x1c)
    {
        func_ov000_021d4cb4(func_ov000_021d4968(gActionSt->xDecision, gActionSt->yDecision, 0x10), 0);
    }

    return;
}

EC s32 func_0204b250(void);
EC void func_02023988(s32, ProcPtr);

extern struct UnkStruct_02196f1c * data_02196f1c;

EC void func_ov000_021d5dd4(mapsave::MapSave * param_1)
{
    s32 iVar2;

    switch (param_1->unk_38)
    {
        case 0x1c:
            iVar2 = gActionSt->unk_37 + 16;
            break;

        case 0x1b:
            iVar2 = 11;
            break;

        case 0x1d:
            iVar2 = 10;
            break;

        default:
            return;
    }

    data_02196f20->unk_19b = data_021974fc->unk_10;
    data_02196f20->unk_19c = func_0204b250();

    if (param_1->unk_38 == 0x1c)
    {
        data_02196f1c->unk_0a = gActionSt->unk_37;
        data_02196f1c->unk_0b = 0;
    }

    func_02023988(iVar2, param_1);

    return;
}

EC void func_ov000_021d5e94(mapsave::MapSave * unused)
{
    VmMap_Common * iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Font"));

    func_01ff9948(iVar1->unk_07);
    gpActiveScreenSt->unk_3e |= (1 << iVar1->unk_07);

    gSoundManager->unk_b0->vfunc_28(0x1000e, 0, 0);

    return;
}

EC void func_ov000_021d5f00(mapsave::MapSave * param_1)
{
    param_1->unk_3c++;

    if (param_1->unk_38 != 0x1b)
    {
        gMapStateManager->unk_14->unk_25 = Interpolate(0, -16, 0, param_1->unk_3c, 4);
    }

    if (param_1->unk_3c == 4)
    {
        param_1->unk_3c = 0;
        Proc_Break(param_1, 1);
    }

    return;
}

EC void func_ov000_021d5f80(mapsave::MapSave * proc)
{
    func_ov000_021d59d0(proc);
    return;
}

EC void func_ov000_021d5f8c(mapsave::MapSave * proc)
{
    func_ov000_021d5d70(proc);
    return;
}

EC void func_ov000_021d5f98(mapsave::MapSave * proc)
{
    func_ov000_021d5dd4(proc);
    return;
}

EC void func_ov000_021d5fa4(mapsave::MapSave * proc)
{
    func_ov000_021d5e94(proc);
    return;
}

EC void func_ov000_021d5fb0(mapsave::MapSave * proc)
{
    func_ov000_021d5f00(proc);
    return;
}

EC void func_ov000_021d5fbc(ProcPtr parent)
{
    static mapsave::DI_PointSaveYes sPointSaveYes;

    // clang-format off
    static DialogItem * data_ov000_021e2574[] =
    {
        &sPointSaveYes,
    };
    // clang-format on

    // "Save here?\nPrevious data will be overwritten."
    func_020303bc(new map::BMapDialogYesNo(), func_02039e10("MD_セーブ"), data_ov000_021e2574, parent, 1, 0);

    return;
}

extern struct ProcCmd data_ov000_021e27b0[];

// StartMapSaveMaybe
EC void func_ov000_021d604c(s32 param_1, ProcPtr parent)
{
    new (Proc_StartBlocking(data_ov000_021e27b0, parent)) mapsave::MapSave(param_1);

    return;
}

EC void StartChildMenu(Menu *, void *, ProcPtr, u32, u32);

EC void func_ov000_021d609c(ProcPtr parent)
{
    static mapsave::MapPointSaveMenuItem sMapPointSaveMenuItem;

    // clang-format off
    static MenuItem * data_ov000_21e2580[] =
    {
        &sMapPointSaveMenuItem,
    };
    // clang-format on

    StartChildMenu(new mapsave::PointSaveMenu(), data_ov000_21e2580, parent, 1, 0);

    return;
}
