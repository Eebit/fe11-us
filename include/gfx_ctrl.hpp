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

// extern ??? _ZTS7ObjCtrl
// extern ??? _ZTI7ObjCtrl
// extern ??? _ZTV6BGCtrl
// extern ??? _ZTV7ObjCtrl
// extern ??? gfxEngineA
// extern ??? gfxEngineB

EC struct UnkStruct_02197798 * func_0206eca4(void);
EC struct UnkStruct_02197798 * func_0206ecb0(void);
EC void func_0206ecbc(void);
EC void func_0206ee78(struct AbstCtrl *, void *, s32, s32);
EC void func_0206eeb0(struct AbstCtrl *, u32, u32);
EC void func_0206eee0(struct AbstCtrl *, s32, s32, s32);
EC void func_0206ef14(struct AbstCtrl *, u32, u32, u32, u32);
EC u32 func_0206ef60(struct AbstCtrl *, s32);
EC void func_0206ef9c(struct AbstCtrl *, s32, s32, s32, s32, s32);
EC void func_0206f0fc(struct AbstCtrl *, s32, s32, s32, s32);
EC void func_0206f218(struct AbstCtrl *, s32, s32, s32, s32);
EC void func_0206f33c(struct AbstCtrl *, s32, s32, s32, s32);
EC void func_0206f470(struct BGCtrl *, BOOL);
EC void func_0206f4a0(struct BGCtrl *, s32);
EC void func_0206f4e0(struct BGCtrl *, u8);
EC void func_0206f580(struct AbstCtrl *, s32);
EC void func_0206f5d0(struct AbstCtrl *, u16 *, s32, s32, s32, s32, s32);
EC void func_0206f718(struct AbstCtrl *, u16 *, s32, s32, s32, s32, s32);
EC void func_0206f7cc(struct BGCtrl *, s32, s32, s32, s32, u16);
EC void func_0206f8a0(struct AbstCtrl *, s32, s32, s32, s32, u16);
EC s32 func_0206f97c(struct BGCtrl *);
// EC ??? func_0206f9ec
// EC ??? func_0206fa74
EC void func_0206fafc(struct AbstCtrl *, s32, s32, s32, s32, s32, s32, s32);
EC void func_0206fc44(struct AbstCtrl *, s32);
// EC ??? func_0206fd38
// EC ??? func_0206fda8
EC void func_0206fe18(struct AbstCtrl *, s32);
EC void func_0206fe20(struct AbstCtrl *, s32, s32);
EC void func_0206fe48(struct AbstCtrl *, s32);
EC void SetDispEnable_Maybe(struct UnkStruct_02197798 *, s32, s32, s32, s32, s32); // SetDispEnable
EC void SetBgPriority_Maybe(struct UnkStruct_02197798 *, s32, s32, s32, s32); // SetBgPriority
EC void SetBldTargetA_Maybe(struct UnkStruct_02197798 *, s32, s32, s32, s32, s32, s32); // SetBldTargetA
EC void SetBldTargetB_Maybe(struct UnkStruct_02197798 *, s32, s32, s32, s32, s32, s32); // SetBldTargetB
EC void func_02070148(struct UnkStruct_02197798 *, s32);
// EC ??? func_0207020c
// EC ??? __sinit_020c50f0

#endif // GFX_CTRL_HPP
