#include "global.h"

#include <new>

#include "hardware.hpp"
#include "proc_ex.hpp"

class ProcFade : public ProcEx
{
public:
    /* 38 */ u32 unk_38;
    /* 3C */ u16 unk_3c;
    /* 3E */ u16 unk_3e;
    /* 40 */ u32 unk_40;

    ProcFade(u32 param_1, u32 param_2, u32 param_3)
    {
        this->unk_38 = param_1;
        this->unk_3c = 0;
        this->unk_3e = param_2;
        this->unk_40 = param_3;
    }

    virtual ~ProcFade() {};
};

EC void func_0201bc80(s32);
EC void func_0201bd44(s32);

EC s32 Interpolate(s32, s32, s32, s32, s32);

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

EC BOOL func_0201bdac(ProcFade * param_1)
{
    if (param_1->unk_40 == 0)
    {
        if (func_0201bca4() == 0)
        {
            Proc_End(param_1);
            return 0;
        }

        func_0201bc40(0);

        param_1->unk_40 = 0;
    }
    else
    {
        if (func_0201bce4() == 0)
        {
            if (func_0201bcf4() == 0)
            {
                Proc_End(param_1);
                return 0;
            }

            param_1->unk_40 = 3;
        }
        else
        {
            if (func_0201bcf4() == 0)
            {
                param_1->unk_40 = 2;
            }
            else
            {
                param_1->unk_40 = 1;
            }
        }

        func_0201bc80(0);
    }

    return 1;
}

EC BOOL func_0201be4c(ProcFade * param_1)
{
    if (param_1->unk_40 == 0)
    {
        if (func_0201bca4() == 1)
        {
            Proc_End(param_1);
            return 0;
        }

        func_0201bc40(1);

        param_1->unk_40 = 0;
    }
    else
    {
        if (func_0201bce4() == 1)
        {
            if (func_0201bcf4() == 1)
            {
                Proc_End(param_1);
                return 0;
            }

            param_1->unk_40 = 3;
        }
        else
        {
            if (func_0201bcf4() == 1)
            {
                param_1->unk_40 = 2;
            }
            else
            {
                param_1->unk_40 = 1;
            }
        }

        func_0201bc80(1);
    }

    return 1;
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

EC void func_0201c664(ProcFade * arg0)
{
    AbstCtrl_04 * temp_r4;

    if (func_0201bdac(arg0) == 0)
    {
        return;
    }

    if (arg0->unk_3e == 0)
    {
        arg0->unk_3e = 1U;
    }

    arg0->unk_3c = 0;

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 2:
            temp_r4 = data_027e1268;
            data_027e1268 = data_027e0000;

            switch (arg0->unk_38)
            {
                case 0:
                    func_0201c204();
                    break;

                case 1:
                    func_0201c234();
                    break;

                case 2:
                    func_0201c28c();
                    break;

                case 3:
                    func_0201c3f0();
                    break;

                case 4:
                    func_0201c264();
                    break;
            }

            if (arg0->unk_38 != 4)
            {
                func_0201bc40(0);

                data_027e1268->unk_00->dispcnt.win0_on = 0;
                data_027e1268->unk_00->dispcnt.win1_on = 0;
            }

            data_027e1268 = temp_r4;
    }

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 3:
            temp_r4 = data_027e1268;
            data_027e1268 = data_027e0004;
            switch (arg0->unk_38)
            {
                case 0:
                    func_0201c204();
                    break;

                case 1:
                    func_0201c234();
                    break;

                case 2:
                    func_0201c28c();
                    break;

                case 3:
                    func_0201c3f0();
                    break;

                case 4:
                    func_0201c264();
                    break;
            }

            if (arg0->unk_38 != 4)
            {
                func_0201bc40(0);

                data_027e1268->unk_00->dispcnt.win0_on = 0;
                data_027e1268->unk_00->dispcnt.win1_on = 0;
            }

            data_027e1268 = temp_r4;
    }

    return;
}

EC void func_0201c8a0(ProcFade * arg0)
{
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    AbstCtrl_04 * temp_r7;

    arg0->unk_3c++;

    if (arg0->unk_38 != 4)
    {
        var_r4 = Interpolate(0, 0x10, 0, arg0->unk_3c, arg0->unk_3e);
    }
    else
    {
        var_r5 = Interpolate(0, 0, 0x100, arg0->unk_3c, arg0->unk_3e);
        var_r6 = Interpolate(0, 0, 0xC0, arg0->unk_3c, arg0->unk_3e);
    }

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 2:
            temp_r7 = data_027e1268;
            data_027e1268 = data_027e0000;
            switch (arg0->unk_38)
            {
                case 0:
                    data_027e0000->unk_00->unk_50 = (0 - var_r4);
                    break;

                case 1:
                    data_027e0000->unk_00->unk_50 = var_r4;
                    break;

                case 2:
                case 3:
                    data_027e0000->unk_00->blend_y = var_r4;
                    break;

                case 4:
                    func_0201c554(var_r5, var_r6);
                    break;
            }
            data_027e1268 = temp_r7;
    }

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 3:
            temp_r7 = data_027e1268;
            data_027e1268 = data_027e0004;

            switch (arg0->unk_38)
            {
                case 0:
                    data_027e0004->unk_00->unk_50 = (0 - var_r4);
                    break;

                case 1:
                    data_027e0004->unk_00->unk_50 = var_r4;
                    break;

                case 2:
                case 3:
                    data_027e0004->unk_00->blend_y = var_r4;
                    break;

                case 4:
                    func_0201c554(var_r5, var_r6);
                    break;
            }

            data_027e1268 = temp_r7;
    }

    if (arg0->unk_3c < arg0->unk_3e)
    {
        return;
    }

    switch (arg0->unk_38)
    {
        case 2:
        case 3:
            switch (arg0->unk_40)
            {
                case 0:
                    data_027e1268->unk_00->bldcnt.effect = 0;
                    break;

                case 1:
                    data_027e0008->bldcnt.effect = 0;
                    data_027e000c->bldcnt.effect = 0;
                    break;

                case 2:
                    data_027e0008->bldcnt.effect = 0;
                    break;

                case 3:
                    data_027e000c->bldcnt.effect = 0;
                    break;
            }

            break;

        case 4:
            switch (arg0->unk_40)
            {
                case 0:
                    data_027e1268->unk_00->dispcnt.win0_on = 0;
                    data_027e1268->unk_00->dispcnt.win1_on = 0;

                    break;

                case 1:
                    data_027e0008->dispcnt.win0_on = 0;
                    data_027e0008->dispcnt.win1_on = 0;

                    data_027e000c->dispcnt.win0_on = 0;
                    data_027e000c->dispcnt.win1_on = 0;

                    break;

                case 2:
                    data_027e0008->dispcnt.win0_on = 0;
                    data_027e0008->dispcnt.win1_on = 0;

                    break;

                case 3:
                    data_027e000c->dispcnt.win0_on = 0;
                    data_027e000c->dispcnt.win1_on = 0;

                    break;
            }

            break;
    }

    Proc_Break(arg0, 0);

    return;
}

EC void func_0201cc84(ProcFade * arg0)
{
    AbstCtrl_04 * temp_r4;

    if (func_0201be4c(arg0) == 0)
    {
        return;
    }

    if (arg0->unk_3e == 0)
    {
        arg0->unk_3e = 1;
    }

    arg0->unk_3c = 0;

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 2:
            temp_r4 = data_027e1268;
            data_027e1268 = data_027e0000;

            switch (arg0->unk_38)
            {
                case 0:
                    data_027e0000->unk_00->unk_50 = 0;
                    func_0201bd04(0);

                    break;

                case 1:
                    data_027e0000->unk_00->unk_50 = 0;
                    func_0201bd04(1);

                    break;

                case 2:
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

                case 3:
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

                case 4:
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

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 3:
            temp_r4 = data_027e1268;
            data_027e1268 = data_027e0004;

            switch (arg0->unk_38)
            {
                case 0:
                    data_027e0004->unk_00->unk_50 = 0;
                    func_0201bd04(0);

                    break;

                case 1:
                    data_027e0004->unk_00->unk_50 = 0;
                    func_0201bd04(1);

                    break;

                case 2:
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

                case 3:
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

                case 4:
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

EC void func_0201d370(ProcFade * arg0)
{
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    AbstCtrl_04 * temp_r8;

    arg0->unk_3c++;

    if (arg0->unk_38 != 4)
    {
        var_r5 = Interpolate(0, 0, 0x10, arg0->unk_3c, arg0->unk_3e);
    }
    else
    {
        var_r6 = Interpolate(0, 0, 0x100, arg0->unk_3c, arg0->unk_3e);
        var_r7 = Interpolate(0, 0, 0xC0, arg0->unk_3c, arg0->unk_3e);
    }

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 2:
            temp_r8 = data_027e1268;
            data_027e1268 = data_027e0000;

            switch (arg0->unk_38)
            {
                case 0:
                    data_027e0000->unk_00->unk_50 = 0 - var_r5;
                    break;

                case 1:
                    data_027e0000->unk_00->unk_50 = var_r5;
                    break;

                case 2:
                case 3:
                    data_027e0000->unk_00->blend_y = var_r5;
                    break;

                case 4:
                    func_0201c5dc(var_r6, var_r7);
                    break;
            }

            data_027e1268 = temp_r8;
    }

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 3:
            temp_r8 = data_027e1268;
            data_027e1268 = data_027e0004;

            switch (arg0->unk_38)
            {
                case 0:
                    data_027e0004->unk_00->unk_50 = 0 - var_r5;
                    break;

                case 1:
                    data_027e0004->unk_00->unk_50 = var_r5;
                    break;

                case 2:
                case 3:
                    data_027e0004->unk_00->blend_y = var_r5;
                    break;

                case 4:
                    func_0201c5dc(var_r6, var_r7);
                    break;
            }
            data_027e1268 = temp_r8;
    }

    if (arg0->unk_3c < arg0->unk_3e)
    {
        return;
    }

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0000 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 2:
            temp_r8 = data_027e1268;
            data_027e1268 = data_027e0000;

            switch (arg0->unk_38)
            {
                case 0:
                case 2:
                    func_0201c204();
                    break;

                case 1:
                case 3:
                    func_0201c234();
                    break;
            }

            switch (arg0->unk_38)
            {
                case 2:
                case 3:
                    data_027e1268->unk_00->bldcnt.effect = 0;
            }

            data_027e1268 = temp_r8;
    }

    switch (arg0->unk_40)
    {
        default:
            if (!(data_027e1268 == data_027e0004 ? TRUE : FALSE) || arg0->unk_40 != 0)
            {
                break;
            }

            // fallthrough

        case 1:
        case 3:
            temp_r8 = data_027e1268;
            data_027e1268 = data_027e0004;

            switch (arg0->unk_38)
            {
                case 0:
                case 2:
                    func_0201c204();
                    break;

                case 1:
                case 3:
                    func_0201c234();
                    break;
            }

            switch (arg0->unk_38)
            {
                case 2:
                case 3:
                    data_027e1268->unk_00->bldcnt.effect = 0;
            }

            data_027e1268 = temp_r8;
    }

    Proc_Break(arg0, 0);

    return;
}

EC void func_0201d6f8(ProcFade * proc)
{
    func_0201c8a0(proc);
    return;
}

EC void func_0201d704(ProcFade * proc)
{
    func_0201c664(proc);
    return;
}

EC void func_0201d710(ProcFade * proc)
{
    func_0201d370(proc);
    return;
}

EC void func_0201d71c(ProcFade * proc)
{
    func_0201cc84(proc);
    return;
}

// clang-format off

struct ProcCmd data_020ce924[] =
{
    PROC_NAME,
    PROC_SLEEP(0),
    PROC_CALL(func_0201d71c),
    PROC_REPEAT(func_0201d710),
    PROC_END,
};

struct ProcCmd data_020ce94c[] =
{
    PROC_NAME,
    PROC_SLEEP(0),
    PROC_CALL(func_0201d704),
    PROC_REPEAT(func_0201d6f8),
    PROC_END,
};

// clang-format on

EC void func_0201d728(ProcEx * parent, u32 param_2, u32 param_3)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_9);
    }

    new (Proc_Start(data_020ce94c, parent)) ProcFade(0, param_2, param_3);

    return;
}

EC void func_0201d778(ProcEx * parent, u32 param_2, u32 param_3)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_9);
    }

    new (Proc_Start(data_020ce924, parent)) ProcFade(0, param_2, param_3);

    return;
}

EC void func_0201d7c8(ProcEx * parent, u32 param_2, u32 param_3)
{
    new (Proc_StartBlocking(data_020ce94c, parent)) ProcFade(0, param_2, param_3);

    return;
}

EC void func_0201d814(ProcEx * parent, u32 param_2, u32 param_3)
{
    new (Proc_StartBlocking(data_020ce924, parent)) ProcFade(0, param_2, param_3);

    return;
}

EC void func_0201d860(ProcEx * parent, u32 param_2, u32 param_3)
{
    new (Proc_Start(data_020ce94c, parent)) ProcFade(1, param_2, param_3);

    return;
}

EC void func_0201d8b0(ProcEx * parent, u32 param_2, u32 param_3)
{
    new (Proc_Start(data_020ce924, parent)) ProcFade(1, param_2, param_3);

    return;
}

EC void func_0201d900(ProcEx * parent, u32 param_2, u32 param_3)
{
    new (Proc_StartBlocking(data_020ce94c, parent)) ProcFade(1, param_2, param_3);

    return;
}

EC void func_0201d950(ProcEx * parent, u32 param_2, u32 param_3)
{
    new (Proc_StartBlocking(data_020ce924, parent)) ProcFade(1, param_2, param_3);

    return;
}

EC void func_0201d9a0(ProcEx * parent, u32 param_2, u32 param_3)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_9);
    }

    new (Proc_Start(data_020ce94c, parent)) ProcFade(4, param_2, param_3);

    return;
}

EC void func_0201d9f4(ProcEx * parent, u32 param_2, u32 param_3)
{
    if (parent == NULL)
    {
        parent = static_cast<ProcEx *>(PROC_TREE_9);
    }

    new (Proc_Start(data_020ce924, parent)) ProcFade(4, param_2, param_3);

    return;
}

EC void func_0201da48(ProcEx * parent, u32 param_2, u32 param_3)
{
    new (Proc_StartBlocking(data_020ce94c, parent)) ProcFade(4, param_2, param_3);

    return;
}

EC void func_0201da98(ProcEx * parent, u32 param_2, u32 param_3)
{
    new (Proc_StartBlocking(data_020ce924, parent)) ProcFade(4, param_2, param_3);

    return;
}

EC BOOL func_0201dae8(void)
{
    if (Proc_Find(data_020ce94c) != NULL)
    {
        return TRUE;
    }

    if (Proc_Find(data_020ce924) != NULL)
    {
        return TRUE;
    }

    return FALSE;
}
