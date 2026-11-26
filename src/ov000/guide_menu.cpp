#include "global.h"

#include "database.hpp"
#include "font.hpp"
#include "hardware.hpp"
#include "map.hpp"
#include "menu.hpp"

#include "unknown_funcs.h"
#include "unknown_types.hpp"

extern struct UnkStruct_02196f20 * data_02196f20;

EC BOOL _IsProcTutCardActive(void);
EC BOOL func_02050304(s32);

EC s32 func_020295ec(struct Font *, char *, void *, void *, u32, u32, u32, u32, u32, u32);

namespace menu
{
class ScrollMenuItem
{
public:
    virtual char * vfunc_00(s32); // func_020340d8
    virtual s32 vfunc_04(void); // func_0205b454
    virtual s32 vfunc_08(void); // func_0205b464
    virtual void vfunc_0c(/* ? */); // func_0205b45c
    virtual void vfunc_10(s32, s32, s32, s32, s32, s32, s32); // func_02034054
    virtual void vfunc_14(/* ? */); // func_0205b46c
    virtual void vfunc_18(/* ? */); // func_02031cc4
    virtual s32 vfunc_1c(s32, s32); // func_0205ae94
    virtual s32 vfunc_20(s32); // func_02031d24
    virtual s32 vfunc_24(s32, s32); // func_02031d0c
    virtual s32 vfunc_28(s32); // func_02031dcc
    virtual s32 vfunc_2c(s32, s32); // func_02031db4
    virtual void vfunc_30(/* ? */); // func_02031d6c
    virtual void vfunc_34(/* ? */); // func_0205af88
    virtual void vfunc_38(/* ? */); // func_0203127c
    virtual void vfunc_3c(/* ? */); // func_0205af00
    virtual void vfunc_40(/* ? */); // func_020311ec
    virtual void vfunc_44(/* ? */); // func_020327fc
    virtual s32 vfunc_48(s32); // func_0205aef8
    virtual s32 vfunc_4c(s32, s32); // func_020340e0
};
} // namespace menu

namespace map
{
class BMapScrollMenu : public menu::ScrollMenu
{
public:
    // 10 func_ov000_021be768
    // AC func_ov000_021be8f0
    // BC func_ov000_021be8d8

    BMapScrollMenu()
    {
        gpActiveScreenSt->dispIo->bldcnt.effect = 1;

        gpActiveScreenSt->dispIo->blend_coeff_a = 0xe;
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
    }

    virtual ~BMapScrollMenu()
    {
        gpActiveScreenSt->dispIo->bldcnt.effect = 0;
    }
};
} // namespace map

class TutListMenu : public map::BMapScrollMenu
{
public:
    /* 4C */ virtual void vfunc_4c(s32 param_2)
    {
        gMapStateManager->unk_14->unk_25 = Interpolate(0, 0, -16, param_2, 4);
        return;
    }

    // d1 func_ov000_021c6be4
    // d0 func_ov000_021c6c38
};

class TutListMenuItem : public menu::ScrollMenuItem
{
public:
    /* 08 */ virtual s32 vfunc_08(void)
    {
        return 0x10;
    }

    /* 04 */ virtual s32 vfunc_04(void)
    {
        return this->vfunc_08() << 1;
    }

    /* 00 */ virtual char * vfunc_00(s32 param_2)
    {
        return GetText(gFE11Database->unk_3c[param_2].unk_00);
    }

    /* 10 */ virtual void vfunc_10(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
    {
        char * str = this->vfunc_00(arg1);

        if (str == NULL)
        {
            return;
        }

        func_020295ec(
            data_021970c4, str, gpActiveScreenSt->bgTiles[arg2], (void *)arg3, arg4 + 1, arg5, arg6, arg7, 0, 0);

        return;
    }

    /* 48 */ virtual s32 vfunc_48(s32 arg1)
    {
        if (!data_02196f20->flagMgr->GetById(arg1))
        {
            return MENU_NOTSHOWN;
        }

        return MENU_ENABLED;
    }

    /* 1C */ virtual s32 vfunc_1c(s32 param_2, s32 param_3)
    {
        if (_IsProcTutCardActive())
        {
            return 0;
        }

        if (func_02050304(param_3))
        {
            return 0;
        }

        StartProcTutCardMaybe(param_3, -1);

        return 0x40;
    }
};

EC void func_02031594(menu::ScrollMenu *, menu::ScrollMenuItem **, s32, s32, s32, ProcPtr, s32);

EC void StartGuideMenu(ProcPtr parent)
{
    static TutListMenuItem sTutListMenuItem;

    // clang-format off
    static menu::ScrollMenuItem * sGuideMenuItems[] =
    {
        &sTutListMenuItem,
    };
    // clang-format on

    func_02031594(new TutListMenu(), sGuideMenuItems, 0x22, 1, 8, parent, 1);

    return;
}
