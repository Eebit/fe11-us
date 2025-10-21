#include "global.h"

#include <new>

#include "hardware.hpp"
#include "proc_ex.hpp"

EC s32 Interpolate(s32, s32, s32, s32, s32);

enum
{
    FADE_KIND_0 = 0,
    FADE_KIND_1 = 1,
    FADE_KIND_2 = 2,
    FADE_KIND_3 = 3,
    FADE_KIND_4 = 4,
};

enum
{
    FADE_TARGET_CURRENT = 0,
    FADE_TARGET_BOTH = 1,
    FADE_TARGET_MAIN = 2,
    FADE_TARGET_SUB = 3,
};

class ProcFade : public ProcEx
{
public:
    /* 38 */ u32 kind;
    /* 3C */ u16 timer;
    /* 3E */ u16 duration;
    /* 40 */ u32 target;

    ProcFade(u32 kind, u32 duration, u32 target)
    {
        this->kind = kind;
        this->timer = 0;
        this->duration = duration;
        this->target = target;
    }

    virtual ~ProcFade() {};
};

EC void func_0201bc80(s32);
EC void func_0201bd44(s32);

extern u8 data_02194b28[];
extern u8 data_02194b2a[];

EC void func_0201bc28(void)
{
    func_0201bc80(1);
    func_0201bd44(0);
    return;
}

EC void func_0201bc40(s32 param_1)
{
    s32 idx;

    if ((data_027e1268 == data_027e0000 ? TRUE : FALSE) != TRUE)
    {
        idx = 1;
    }
    else
    {
        idx = 0;
    }

    data_02194b28[idx] = param_1;

    return;
}

EC void func_0201bc80(s32 param_1)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        data_02194b28[i] = param_1;
    }

    return;
}

EC s32 func_0201bca4(void)
{
    s32 idx;

    if ((data_027e1268 == data_027e0000 ? TRUE : FALSE) != TRUE)
    {
        idx = 1;
    }
    else
    {
        idx = 0;
    }

    return data_02194b28[idx];
}

EC s32 func_0201bce4(void)
{
    return data_02194b28[0];
}

EC s32 func_0201bcf4(void)
{
    return data_02194b28[1];
}

EC void func_0201bd04(s32 param_1)
{
    s32 idx;

    if ((data_027e1268 == data_027e0000 ? TRUE : FALSE) != TRUE)
    {
        idx = 1;
    }
    else
    {
        idx = 0;
    }

    data_02194b2a[idx] = param_1;

    return;
}

EC void func_0201bd44(s32 param_1)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        data_02194b28[i + 2] = param_1;
    }

    return;
}

EC s32 func_0201bd6c(void)
{
    s32 idx;

    if ((data_027e1268 == data_027e0000 ? TRUE : FALSE) != TRUE)
    {
        idx = 1;
    }
    else
    {
        idx = 0;
    }

    return data_02194b2a[idx];
}

EC BOOL func_0201bdac(ProcFade * proc)
{
    if (proc->target == FADE_TARGET_CURRENT)
    {
        if (func_0201bca4() == 0)
        {
            Proc_End(proc);
            return FALSE;
        }

        func_0201bc40(0);

        proc->target = FADE_TARGET_CURRENT;
    }
    else
    {
        if (func_0201bce4() == 0)
        {
            if (func_0201bcf4() == 0)
            {
                Proc_End(proc);
                return 0;
            }

            proc->target = FADE_TARGET_SUB;
        }
        else
        {
            if (func_0201bcf4() == 0)
            {
                proc->target = FADE_TARGET_MAIN;
            }
            else
            {
                proc->target = FADE_TARGET_BOTH;
            }
        }

        func_0201bc80(0);
    }

    return TRUE;
}

EC BOOL func_0201be4c(ProcFade * proc)
{
    if (proc->target == FADE_TARGET_CURRENT)
    {
        if (func_0201bca4() == 1)
        {
            Proc_End(proc);
            return FALSE;
        }

        func_0201bc40(1);

        proc->target = FADE_TARGET_CURRENT;
    }
    else
    {
        if (func_0201bce4() == 1)
        {
            if (func_0201bcf4() == 1)
            {
                Proc_End(proc);
                return FALSE;
            }

            proc->target = FADE_TARGET_SUB;
        }
        else
        {
            if (func_0201bcf4() == 1)
            {
                proc->target = FADE_TARGET_MAIN;
            }
            else
            {
                proc->target = FADE_TARGET_BOTH;
            }
        }

        func_0201bc80(1);
    }

    return TRUE;
}

EC void func_0201beec(void)
{
    data_027e1268->unk_00->dispcnt.win0_on = 1;
    data_027e1268->unk_00->winincnt.win0_enableBg0 = 0;
    data_027e1268->unk_00->winincnt.win0_enableBg1 = 0;
    data_027e1268->unk_00->winincnt.win0_enableBg2 = 0;
    data_027e1268->unk_00->winincnt.win0_enableBg3 = 0;
    data_027e1268->unk_00->winincnt.win0_enableObj = 0;

    data_027e1268->unk_00->dispcnt.win1_on = 1;
    data_027e1268->unk_00->winincnt.win1_enableBg0 = 0;
    data_027e1268->unk_00->winincnt.win1_enableBg1 = 0;
    data_027e1268->unk_00->winincnt.win1_enableBg2 = 0;
    data_027e1268->unk_00->winincnt.win1_enableBg3 = 0;
    data_027e1268->unk_00->winincnt.win1_enableObj = 0;

    data_027e1268->unk_00->winoutcnt.wout_enableBg0 = 1;
    data_027e1268->unk_00->winoutcnt.wout_enableBg1 = 1;
    data_027e1268->unk_00->winoutcnt.wout_enableBg2 = 1;
    data_027e1268->unk_00->winoutcnt.wout_enableBg3 = 1;
    data_027e1268->unk_00->winoutcnt.wout_enableObj = 1;
    data_027e1268->unk_00->winoutcnt.wout_enableBlend = 1;

    return;
}

EC void func_0201c184(void)
{
    data_027e1268->unk_00->unk_48 = 0;
    data_027e1268->unk_00->unk_4a = 0;
    data_027e1268->unk_00->unk_49 = 0xff;
    data_027e1268->unk_00->unk_4b = 0xc0;

    data_027e1268->unk_00->unk_4c = 1;
    data_027e1268->unk_00->unk_4e = 0;
    data_027e1268->unk_00->unk_4d = 0;
    data_027e1268->unk_00->unk_4f = 0xc0;

    return;
}

EC void func_0201c204(void)
{
    func_0201bc40(1);
    func_0201bd04(0);
    data_027e1268->unk_00->unk_50 = -0x10;
    return;
}

EC void func_0201c234(void)
{
    func_0201bc40(1);
    func_0201bd04(1);
    data_027e1268->unk_00->unk_50 = 0x10;
    return;
}

EC void func_0201c264(void)
{
    func_0201beec();
    func_0201c184();
    data_027e1268->unk_00->unk_50 = 0;
    return;
}

EC void func_0201c28c(void)
{
    func_0201bc40(1);
    func_0201bd04(0);
    data_027e1268->unk_00->unk_50 = 0;

    data_027e1268->unk_00->bldcnt.effect = 3;
    data_027e1268->unk_00->blend_coeff_a = 0;
    data_027e1268->unk_00->blend_coeff_b = 0;
    data_027e1268->unk_00->blend_y = 0x10;

    data_027e1268->unk_00->bldcnt.target1_bg0_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bg1_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bg2_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bg3_on = 1;
    data_027e1268->unk_00->bldcnt.target1_obj_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bd_on = 1;

    return;
}

EC void func_0201c3f0(void)
{
    func_0201bc40(1);
    func_0201bd04(1);
    data_027e1268->unk_00->unk_50 = 0;

    data_027e1268->unk_00->bldcnt.effect = 2;
    data_027e1268->unk_00->blend_coeff_a = 0;
    data_027e1268->unk_00->blend_coeff_b = 0;
    data_027e1268->unk_00->blend_y = 0x10;

    data_027e1268->unk_00->bldcnt.target1_bg0_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bg1_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bg2_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bg3_on = 1;
    data_027e1268->unk_00->bldcnt.target1_obj_on = 1;
    data_027e1268->unk_00->bldcnt.target1_bd_on = 1;

    return;
}

EC void func_0201c554(s32 arg0, s32 arg1)
{
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 != 0)
    {
        var_r0--;
    }

    data_027e1268->unk_00->unk_48 = var_r0;
    data_027e1268->unk_00->unk_4a = 0;
    data_027e1268->unk_00->unk_49 = 0;
    data_027e1268->unk_00->unk_4b = 0xc0 - arg1;

    data_027e1268->unk_00->unk_4c = 0;
    data_027e1268->unk_00->unk_4e = arg1;
    data_027e1268->unk_00->unk_4d = 0x100 - var_r0;
    data_027e1268->unk_00->unk_4f = 0xC0;

    return;
}

EC void func_0201c5dc(s32 arg0, s32 arg1)
{
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 >= 0x100)
    {
        var_r0--;
    }

    data_027e1268->unk_00->unk_48 = 0;
    data_027e1268->unk_00->unk_4a = 0;
    data_027e1268->unk_00->unk_49 = var_r0;
    data_027e1268->unk_00->unk_4b = arg1;

    data_027e1268->unk_00->unk_4c = 0x100 - var_r0;
    data_027e1268->unk_00->unk_4e = 0xC0 - arg1;
    data_027e1268->unk_00->unk_4d = 0;
    data_027e1268->unk_00->unk_4f = 0xC0;

    return;
}

EC void func_0201c664(ProcFade * proc)
{
    AbstCtrl_04 * temp_r4;

    if (func_0201bdac(proc) == 0)
    {
        return;
    }

    if (proc->duration == 0)
    {
        proc->duration = 1;
    }

    proc->timer = 0;

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_MAIN:
            temp_r4 = data_027e1268;
            data_027e1268 = data_027e0000;

            switch (proc->kind)
            {
                case FADE_KIND_0:
                    func_0201c204();
                    break;

                case FADE_KIND_1:
                    func_0201c234();
                    break;

                case FADE_KIND_2:
                    func_0201c28c();
                    break;

                case FADE_KIND_3:
                    func_0201c3f0();
                    break;

                case FADE_KIND_4:
                    func_0201c264();
                    break;
            }

            if (proc->kind != FADE_KIND_4)
            {
                func_0201bc40(0);

                data_027e1268->unk_00->dispcnt.win0_on = 0;
                data_027e1268->unk_00->dispcnt.win1_on = 0;
            }

            data_027e1268 = temp_r4;
    }

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_SUB:
            temp_r4 = data_027e1268;
            data_027e1268 = data_027e0004;
            switch (proc->kind)
            {
                case FADE_KIND_0:
                    func_0201c204();
                    break;

                case FADE_KIND_1:
                    func_0201c234();
                    break;

                case FADE_KIND_2:
                    func_0201c28c();
                    break;

                case FADE_KIND_3:
                    func_0201c3f0();
                    break;

                case FADE_KIND_4:
                    func_0201c264();
                    break;
            }

            if (proc->kind != FADE_KIND_4)
            {
                func_0201bc40(0);

                data_027e1268->unk_00->dispcnt.win0_on = 0;
                data_027e1268->unk_00->dispcnt.win1_on = 0;
            }

            data_027e1268 = temp_r4;
    }

    return;
}

EC void func_0201c8a0(ProcFade * proc)
{
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    AbstCtrl_04 * temp_r7;

    proc->timer++;

    if (proc->kind != FADE_KIND_4)
    {
        var_r4 = Interpolate(0, 0x10, 0, proc->timer, proc->duration);
    }
    else
    {
        var_r5 = Interpolate(0, 0, 0x100, proc->timer, proc->duration);
        var_r6 = Interpolate(0, 0, 0xC0, proc->timer, proc->duration);
    }

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_MAIN:
            temp_r7 = data_027e1268;
            data_027e1268 = data_027e0000;

            switch (proc->kind)
            {
                case FADE_KIND_0:
                    data_027e0000->unk_00->unk_50 = (0 - var_r4);
                    break;

                case FADE_KIND_1:
                    data_027e0000->unk_00->unk_50 = var_r4;
                    break;

                case FADE_KIND_2:
                case FADE_KIND_3:
                    data_027e0000->unk_00->blend_y = var_r4;
                    break;

                case FADE_KIND_4:
                    func_0201c554(var_r5, var_r6);
                    break;
            }

            data_027e1268 = temp_r7;
    }

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_SUB:
            temp_r7 = data_027e1268;
            data_027e1268 = data_027e0004;

            switch (proc->kind)
            {
                case FADE_KIND_0:
                    data_027e0004->unk_00->unk_50 = (0 - var_r4);
                    break;

                case FADE_KIND_1:
                    data_027e0004->unk_00->unk_50 = var_r4;
                    break;

                case FADE_KIND_2:
                case FADE_KIND_3:
                    data_027e0004->unk_00->blend_y = var_r4;
                    break;

                case FADE_KIND_4:
                    func_0201c554(var_r5, var_r6);
                    break;
            }

            data_027e1268 = temp_r7;
    }

    if (proc->timer < proc->duration)
    {
        return;
    }

    switch (proc->kind)
    {
        case FADE_KIND_2:
        case FADE_KIND_3:
            switch (proc->target)
            {
                case FADE_TARGET_CURRENT:
                    data_027e1268->unk_00->bldcnt.effect = 0;
                    break;

                case FADE_TARGET_BOTH:
                    data_027e0008->bldcnt.effect = 0;
                    data_027e000c->bldcnt.effect = 0;
                    break;

                case FADE_TARGET_MAIN:
                    data_027e0008->bldcnt.effect = 0;
                    break;

                case FADE_TARGET_SUB:
                    data_027e000c->bldcnt.effect = 0;
                    break;
            }

            break;

        case FADE_KIND_4:
            switch (proc->target)
            {
                case FADE_TARGET_CURRENT:
                    data_027e1268->unk_00->dispcnt.win0_on = 0;
                    data_027e1268->unk_00->dispcnt.win1_on = 0;

                    break;

                case FADE_TARGET_BOTH:
                    data_027e0008->dispcnt.win0_on = 0;
                    data_027e0008->dispcnt.win1_on = 0;

                    data_027e000c->dispcnt.win0_on = 0;
                    data_027e000c->dispcnt.win1_on = 0;

                    break;

                case FADE_TARGET_MAIN:
                    data_027e0008->dispcnt.win0_on = 0;
                    data_027e0008->dispcnt.win1_on = 0;

                    break;

                case FADE_TARGET_SUB:
                    data_027e000c->dispcnt.win0_on = 0;
                    data_027e000c->dispcnt.win1_on = 0;

                    break;
            }

            break;
    }

    Proc_Break(proc, 0);

    return;
}

EC void func_0201cc84(ProcFade * proc)
{
    AbstCtrl_04 * temp_r4;

    if (func_0201be4c(proc) == 0)
    {
        return;
    }

    if (proc->duration == 0)
    {
        proc->duration = 1;
    }

    proc->timer = 0;

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_MAIN:
            temp_r4 = data_027e1268;
            data_027e1268 = data_027e0000;

            switch (proc->kind)
            {
                case FADE_KIND_0:
                    data_027e0000->unk_00->unk_50 = 0;
                    func_0201bd04(0);

                    break;

                case FADE_KIND_1:
                    data_027e0000->unk_00->unk_50 = 0;
                    func_0201bd04(1);

                    break;

                case FADE_KIND_2:
                    data_027e0000->unk_00->bldcnt.effect = 3;
                    data_027e1268->unk_00->blend_y = 0;

                    data_027e1268->unk_00->bldcnt.target1_bg0_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg1_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg2_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg3_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_obj_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bd_on = 1;

                    func_0201bd04(0);

                    break;

                case FADE_KIND_3:
                    data_027e0000->unk_00->bldcnt.effect = 2;
                    data_027e1268->unk_00->blend_y = 0;

                    data_027e1268->unk_00->bldcnt.target1_bg0_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg1_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg2_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg3_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_obj_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bd_on = 1;

                    func_0201bd04(1);

                    break;

                case FADE_KIND_4:
                    func_0201beec();
                    func_0201bd04(0);
                    data_027e1268->unk_00->unk_48 = 0;
                    data_027e1268->unk_00->unk_4a = 0;
                    data_027e1268->unk_00->unk_49 = 0;
                    data_027e1268->unk_00->unk_4b = 0;

                    data_027e1268->unk_00->unk_4c = 0;
                    data_027e1268->unk_00->unk_4e = 0;
                    data_027e1268->unk_00->unk_4d = 0;
                    data_027e1268->unk_00->unk_4f = 0;

                    break;
            }

            data_027e1268 = temp_r4;
    }

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_SUB:
            temp_r4 = data_027e1268;
            data_027e1268 = data_027e0004;

            switch (proc->kind)
            {
                case FADE_KIND_0:
                    data_027e0004->unk_00->unk_50 = 0;
                    func_0201bd04(0);

                    break;

                case FADE_KIND_1:
                    data_027e0004->unk_00->unk_50 = 0;
                    func_0201bd04(1);

                    break;

                case FADE_KIND_2:
                    data_027e0004->unk_00->bldcnt.effect = 3;
                    data_027e1268->unk_00->blend_y = 0;

                    data_027e1268->unk_00->bldcnt.target1_bg0_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg1_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg2_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg3_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_obj_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bd_on = 1;

                    func_0201bd04(0);
                    break;

                case FADE_KIND_3:
                    data_027e0004->unk_00->bldcnt.effect = 2;
                    data_027e1268->unk_00->blend_y = 0;

                    data_027e1268->unk_00->bldcnt.target1_bg0_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg1_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg2_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bg3_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_obj_on = 1;
                    data_027e1268->unk_00->bldcnt.target1_bd_on = 1;

                    func_0201bd04(1);

                    break;

                case FADE_KIND_4:
                    func_0201beec();
                    func_0201bd04(0);

                    data_027e1268->unk_00->unk_48 = 0;
                    data_027e1268->unk_00->unk_4a = 0;
                    data_027e1268->unk_00->unk_49 = 0;
                    data_027e1268->unk_00->unk_4b = 0;

                    data_027e1268->unk_00->unk_4c = 0;
                    data_027e1268->unk_00->unk_4e = 0;
                    data_027e1268->unk_00->unk_4d = 0;
                    data_027e1268->unk_00->unk_4f = 0;

                    break;
            }

            data_027e1268 = temp_r4;
    }
}

EC void func_0201d370(ProcFade * proc)
{
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    AbstCtrl_04 * temp_r8;

    proc->timer++;

    if (proc->kind != 4)
    {
        var_r5 = Interpolate(0, 0, 0x10, proc->timer, proc->duration);
    }
    else
    {
        var_r6 = Interpolate(0, 0, 0x100, proc->timer, proc->duration);
        var_r7 = Interpolate(0, 0, 0xC0, proc->timer, proc->duration);
    }

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_MAIN:
            temp_r8 = data_027e1268;
            data_027e1268 = data_027e0000;

            switch (proc->kind)
            {
                case FADE_KIND_0:
                    data_027e0000->unk_00->unk_50 = 0 - var_r5;
                    break;

                case FADE_KIND_1:
                    data_027e0000->unk_00->unk_50 = var_r5;
                    break;

                case FADE_KIND_2:
                case FADE_KIND_3:
                    data_027e0000->unk_00->blend_y = var_r5;
                    break;

                case FADE_KIND_4:
                    func_0201c5dc(var_r6, var_r7);
                    break;
            }

            data_027e1268 = temp_r8;
    }

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_SUB:
            temp_r8 = data_027e1268;
            data_027e1268 = data_027e0004;

            switch (proc->kind)
            {
                case FADE_KIND_0:
                    data_027e0004->unk_00->unk_50 = 0 - var_r5;
                    break;

                case FADE_KIND_1:
                    data_027e0004->unk_00->unk_50 = var_r5;
                    break;

                case FADE_KIND_2:
                case FADE_KIND_3:
                    data_027e0004->unk_00->blend_y = var_r5;
                    break;

                case FADE_KIND_4:
                    func_0201c5dc(var_r6, var_r7);
                    break;
            }

            data_027e1268 = temp_r8;
    }

    if (proc->timer < proc->duration)
    {
        return;
    }

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_MAIN:
            temp_r8 = data_027e1268;
            data_027e1268 = data_027e0000;

            switch (proc->kind)
            {
                case FADE_KIND_0:
                case FADE_KIND_2:
                    func_0201c204();
                    break;

                case FADE_KIND_1:
                case FADE_KIND_3:
                    func_0201c234();
                    break;
            }

            switch (proc->kind)
            {
                case FADE_KIND_2:
                case FADE_KIND_3:
                    data_027e1268->unk_00->bldcnt.effect = 0;
            }

            data_027e1268 = temp_r8;
    }

    switch (proc->target)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || proc->target != FADE_TARGET_CURRENT)
            {
                break;
            }

            // fallthrough

        case FADE_TARGET_BOTH:
        case FADE_TARGET_SUB:
            temp_r8 = data_027e1268;
            data_027e1268 = data_027e0004;

            switch (proc->kind)
            {
                case FADE_KIND_0:
                case FADE_KIND_2:
                    func_0201c204();
                    break;

                case FADE_KIND_1:
                case FADE_KIND_3:
                    func_0201c234();
                    break;
            }

            switch (proc->kind)
            {
                case FADE_KIND_2:
                case FADE_KIND_3:
                    data_027e1268->unk_00->bldcnt.effect = 0;
            }

            data_027e1268 = temp_r8;
    }

    Proc_Break(proc, 0);

    return;
}

EC void ProcFadeIn_Loop(ProcFade * proc)
{
    func_0201c8a0(proc);
    return;
}

EC void ProcFadeIn_Init(ProcFade * proc)
{
    func_0201c664(proc);
    return;
}

EC void ProcFadeOut_Loop(ProcFade * proc)
{
    func_0201d370(proc);
    return;
}

EC void ProcFadeOut_Init(ProcFade * proc)
{
    func_0201cc84(proc);
    return;
}

// clang-format off

struct ProcCmd ProcScr_FadeOut[] =
{
    PROC_NAME,
    PROC_SLEEP(0),
    PROC_CALL(ProcFadeOut_Init),
    PROC_REPEAT(ProcFadeOut_Loop),
    PROC_END,
};

struct ProcCmd ProcScr_FadeIn[] =
{
    PROC_NAME,
    PROC_SLEEP(0),
    PROC_CALL(ProcFadeIn_Init),
    PROC_REPEAT(ProcFadeIn_Loop),
    PROC_END,
};

// clang-format on

EC void StartFadeIn(ProcEx * parent, u32 duration, u32 target)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_9);
    }

    new (Proc_Start(ProcScr_FadeIn, parent)) ProcFade(FADE_KIND_0, duration, target);

    return;
}

EC void StartFadeOut(ProcEx * parent, u32 duration, u32 target)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_9);
    }

    new (Proc_Start(ProcScr_FadeOut, parent)) ProcFade(FADE_KIND_0, duration, target);

    return;
}

EC void StartBlockingFadeIn(ProcEx * parent, u32 duration, u32 target)
{
    new (Proc_StartBlocking(ProcScr_FadeIn, parent)) ProcFade(FADE_KIND_0, duration, target);

    return;
}

EC void StartBlockingFadeOut(ProcEx * parent, u32 duration, u32 target)
{
    new (Proc_StartBlocking(ProcScr_FadeOut, parent)) ProcFade(FADE_KIND_0, duration, target);

    return;
}

EC void StartFadeIn_0201d860(ProcEx * parent, u32 duration, u32 target)
{
    new (Proc_Start(ProcScr_FadeIn, parent)) ProcFade(FADE_KIND_1, duration, target);

    return;
}

EC void StartFadeOut_0201d8b0(ProcEx * parent, u32 duration, u32 target)
{
    new (Proc_Start(ProcScr_FadeOut, parent)) ProcFade(FADE_KIND_1, duration, target);

    return;
}

EC void StartBlockingFadeIn_0201d900(ProcEx * parent, u32 duration, u32 target)
{
    new (Proc_StartBlocking(ProcScr_FadeIn, parent)) ProcFade(FADE_KIND_1, duration, target);

    return;
}

EC void StartBlockingFadeOut_0201d950(ProcEx * parent, u32 duration, u32 target)
{
    new (Proc_StartBlocking(ProcScr_FadeOut, parent)) ProcFade(FADE_KIND_1, duration, target);

    return;
}

EC void StartFadeIn_0201d9a0(ProcEx * parent, u32 duration, u32 target)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_9);
    }

    new (Proc_Start(ProcScr_FadeIn, parent)) ProcFade(FADE_KIND_4, duration, target);

    return;
}

EC void StartFadeOut_0201d9f4(ProcEx * parent, u32 duration, u32 target)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_9);
    }

    new (Proc_Start(ProcScr_FadeOut, parent)) ProcFade(FADE_KIND_4, duration, target);

    return;
}

EC void StartBlockingFadeIn_0201da48(ProcEx * parent, u32 duration, u32 target)
{
    new (Proc_StartBlocking(ProcScr_FadeIn, parent)) ProcFade(FADE_KIND_4, duration, target);

    return;
}

EC void StartBlockingFadeOut_0201da98(ProcEx * parent, u32 duration, u32 target)
{
    new (Proc_StartBlocking(ProcScr_FadeOut, parent)) ProcFade(FADE_KIND_4, duration, target);

    return;
}

EC BOOL IsFadeActive(void)
{
    if (Proc_Find(ProcScr_FadeIn) != NULL)
    {
        return TRUE;
    }

    if (Proc_Find(ProcScr_FadeOut) != NULL)
    {
        return TRUE;
    }

    return FALSE;
}
