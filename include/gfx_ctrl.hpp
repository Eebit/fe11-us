#ifndef GFX_CTRL_HPP
#define GFX_CTRL_HPP

#include "global.h"

#include "hardware.hpp"

struct UnkStruct_02197798
{
    ScreenState * unk_00;
    DispIo * unk_04;
    BGCtrl unk_08[4];
    ObjCtrl unk_68;

    void SetBlendEffect(s32 effect)
    {
        DispIo * disp = this->unk_00->dispIo;
        disp->bldcnt.effect = effect;
    }

    void SetBlendCoeffs(s32 a)
    {
        this->unk_00->dispIo->blend_coeff_a = a;
        this->unk_00->dispIo->blend_coeff_b = 16 - a;
    }
};

#endif // GFX_CTRL_HPP
