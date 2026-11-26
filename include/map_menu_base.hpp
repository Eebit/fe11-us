#ifndef MAP_MENU_BASE_HPP
#define MAP_MENU_BASE_HPP

#include "global.h"

#include "hardware.hpp"
#include "menu.hpp"

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

    virtual ~BMapMenu()
    {
        if (this->unk_04 == NULL)
        {
            ResetBlendEffect();
        }
    }
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
    /* 010 */ virtual void vfunc_10(void);
    /* 0AC */ virtual BOOL vfunc_ac(void);
    /* 0BC */ virtual s32 vfunc_bc(void);

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
        ResetBlendEffect();
    }
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

#endif // MAP_MENU_BASE_HPP
