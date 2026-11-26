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

// extern ??? _ZTIN3map8BMapMenuE
// extern ??? _ZTIN3map14BMapScrollMenuE
// extern ??? _ZTIN3map15BMapDialogYesNoE
// extern ??? _ZTIN3map14BMapSystemMenuE
// extern ??? _ZTSN3map8BMapMenuE
// extern ??? _ZTSN3map14BMapScrollMenuE
// extern ??? _ZTSN3map14BMapSystemMenuE
// extern ??? _ZTSN3map15BMapDialogYesNoE
// extern ??? _ZTVN3map14BMapScrollMenuE
extern void * _ZTVN3map15BMapDialogYesNoE[];
// extern ??? _ZTVN3map8BMapMenuE
// extern ??? data_ov000_021dd134
// extern ??? data_ov000_021dd144
// extern ??? data_ov000_021dd154
// extern ??? data_ov000_021dd168
// extern ??? data_ov000_021dd17c
// extern ??? data_ov000_021dd18c
// EC ??? _ZN3map8BMapMenu8vfunc_00Ev
// EC ??? _ZN3map8BMapMenu8vfunc_08Ev
// EC ??? _ZN3map14BMapSystemMenu8vfunc_08Ev
// EC ??? _ZN3map8BMapMenu8vfunc_1cEv
// EC ??? _ZN3map15BMapDialogYesNo8vfunc_00Ev
// EC ??? _ZN3map14BMapScrollMenu8vfunc_10Ev
// EC ??? _ZN3map14BMapScrollMenuD0Ev
// EC ??? _ZN3map14BMapScrollMenuD1Ev
// EC ??? _ZN3map14BMapScrollMenu8vfunc_bcEv
// EC ??? _ZN3map14BMapScrollMenu8vfunc_acEv
// EC ??? _ZN3map15BMapDialogYesNo8vfunc_acEv
// EC ??? _ZN3map15BMapDialogYesNo8vfunc_a0Ev
// EC ??? _ZN3map8BMapMenu8vfunc_acEv
// EC ??? _ZN3map8BMapMenu8vfunc_a0Ev
// EC ??? _ZN3map8BMapMenuD0Ev
// EC ??? _ZN3map8BMapMenuD1Ev
// EC ??? _ZN3map15BMapDialogYesNoD1Ev
// EC ??? _ZN3map15BMapDialogYesNoD0Ev

#endif // MAP_MENU_BASE_HPP
