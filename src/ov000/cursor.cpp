#include "global.h"

#include "map.hpp"
#include "sound_manager.hpp"

#include "unknown_funcs.h"

#include "constants/sounds.h"

EC void func_ov000_021a68c0(MapStateManager_10 * param_1)
{
    int i;

    for (i = 0; i < 2; i++)
    {
        param_1->unk_00[i] = -1;
        param_1->unk_02[i] = -1;
    }

    param_1->unk_04 = 0;
    param_1->unk_06 = 0;
    param_1->unk_08 = 0;
    param_1->unk_09 = 0;
    param_1->unk_0a = 0;
    param_1->unk_0c = 1;
    param_1->unk_0b = 1;
    param_1->unk_0d = 0;
    param_1->unk_0e = 0;

    return;
}

EC void func_ov000_021a6910(MapStateManager_10 * param_1, s32 param_2, s32 param_3, s32 param_4)
{
    if (param_2 == param_1->unk_08 && param_3 == param_1->unk_09)
    {
        param_1->unk_0c = 0;
        return;
    }

    param_1->unk_08 = param_2;
    param_1->unk_09 = param_3;

    param_1->unk_0c = 1;

    if (param_4 != 0 && param_1->unk_0a != 0)
    {
        if (param_1->unk_0d == 0)
        {
            gSoundManager->unk_b0->vfunc_28(SE_SYS_CURSOL_MAP1, 0, 0);
            param_1->unk_0d = 2;
        }
    }

    return;
}

EC void func_ov000_021a6994(MapStateManager_10 * param_1, s32 param_2, s32 param_3, s32 param_4, u8 param_5)
{
    int iVar2;
    int iVar3;

    func_ov000_021a6910(param_1, param_2, param_3, param_5);

    if (param_1->unk_0c != 0)
    {
        param_1->unk_0b = 2;

        if (gMapStateManager->camera->func_ov000_021a4f7c(param_2, param_3, 0))
        {
            gMapStateManager->camera->func_ov000_021a4cec(param_2, param_3, 0, param_4 != 0 ? 8 : 0x10, 0);
        }

        param_1->unk_12 = param_1->unk_04;
        param_1->unk_14 = param_1->unk_06;
        param_1->unk_0b = 2;

        iVar2 = param_1->unk_08 * GetTileSize() - param_1->unk_04;
        iVar3 = param_1->unk_09 * GetTileSize() - param_1->unk_06;

        if (iVar2 < 0)
        {
            iVar2 = -iVar2;
        }

        if (iVar3 < 0)
        {
            iVar3 = -iVar3;
        }

        param_1->unk_16 = IntSys_Div(IntSys_Sqrt(iVar2 * iVar2 + iVar3 * iVar3), gMapStateManager->camera->unk_12);

        if (param_1->unk_16 > 4)
        {
            param_1->unk_16 = 4;
        }

        param_1->unk_18 = 0;
    }

    return;
}

EC void func_ov000_021a6ab8(MapStateManager_10 * param_1, s16 arg_1, s16 arg_2)
{
    func_ov000_021a6910(param_1, arg_1, arg_2, 1);

    param_1->unk_04 = param_1->unk_08 * GetTileSize();
    param_1->unk_06 = param_1->unk_09 * GetTileSize();

    return;
}

EC void func_ov000_021a6aec(MapStateManager_10 * param_1)
{
    s32 x = gMapStateManager->camera->unk_00;
    s32 y = gMapStateManager->camera->unk_04;

    func_ov000_021a6ab8(param_1, IntSys_Div(x + 0x80, GetTileSize()), IntSys_Div(y + 0x60, GetTileSize()));

    return;
}

EC void func_ov000_021a6b4c(MapStateManager_10 * arg0, s32 arg1, s32 arg2)
{
    s32 diff;
    s32 var_r4 = gMapStateManager->camera->unk_12;

    if (gMapStateManager->unk_0c->unk_24 != 0)
    {
        var_r4 *= 2;
    }

    diff = arg1 - arg0->unk_04;
    if (diff > var_r4)
    {
        arg0->unk_04 += var_r4;
    }
    else if (diff < -var_r4)
    {
        arg0->unk_04 -= var_r4;
    }
    else
    {
        arg0->unk_04 = arg1;
    }

    diff = arg2 - arg0->unk_06;
    if (diff > var_r4)
    {
        arg0->unk_06 += var_r4;
    }
    else if (diff < -var_r4)
    {
        arg0->unk_06 -= var_r4;
    }
    else
    {
        arg0->unk_06 = arg2;
    }

    return;
}

EC void func_ov000_021a6bd0(MapStateManager_10 * arg0)
{
    arg0->unk_04 = arg0->unk_08 * GetTileSize();
    arg0->unk_06 = arg0->unk_09 * GetTileSize();

    if ((gMapStateManager->unk_0c->unk_1f == 1 ? TRUE : FALSE) == 0)
    {
        return;
    }

    gMapStateManager->camera->func_ov000_021a4ba0(arg0->unk_04, arg0->unk_06, 0);
}

EC void func_ov000_021a6c38(MapStateManager_10 * arg0)
{
    s32 temp_r4;
    s32 temp_r6;

    temp_r4 = arg0->unk_08 * GetTileSize();
    temp_r6 = arg0->unk_09 * GetTileSize();

    if (gMapStateManager->unk_0c->unk_1e != 0)
    {
        temp_r4 = arg0->unk_08 * GetTileSize();
        temp_r6 = arg0->unk_09 * GetTileSize();

        if (ABS(temp_r4 - arg0->unk_04) <= GetTileSize() && ABS(temp_r6 - arg0->unk_06) <= GetTileSize())
        {
            func_ov000_021a6b4c(arg0, temp_r4, temp_r6);
            return;
        }

        arg0->unk_04 = arg0->unk_08 * GetTileSize();
        arg0->unk_06 = arg0->unk_09 * GetTileSize();

        return;
    }

    func_ov000_021a6b4c(arg0, temp_r4, temp_r6);

    if (arg0->unk_0a == 0)
    {
        return;
    }

    if (((gMapStateManager->unk_0c->unk_1f == 1) ? TRUE : FALSE) == 0)
    {
        return;
    }

    gMapStateManager->camera->func_ov000_021a4ba0(arg0->unk_04, arg0->unk_06, 0);

    return;
}

struct UnkStruct_02196f20
{
    STRUCT_PAD(0x000, 0x184);
    s32 unk_184;
    u32 unk_188;
    u32 unk_18c;
    s32 unk_190;
    u32 unk_194;
    u8 unk_198;
    u8 unk_199;
    u8 unk_19a;
    u8 unk_19b;
    s8 unk_19c;
    STRUCT_PAD(0x19D, 0x1A4);
};
extern struct UnkStruct_02196f20 * data_02196f20;

EC void func_ov000_021a6d48(MapStateManager_10 * param_1)
{
    if (param_1->unk_16 != 0)
    {
        param_1->unk_18++;

        if (param_1->unk_16 < 4)
        {
            param_1->unk_04 =
                Interpolate(0, param_1->unk_12, param_1->unk_08 * GetTileSize(), param_1->unk_18, param_1->unk_16);
            param_1->unk_06 =
                Interpolate(0, param_1->unk_14, param_1->unk_09 * GetTileSize(), param_1->unk_18, param_1->unk_16);
        }
        else
        {
            param_1->unk_04 =
                Interpolate(4, param_1->unk_12, param_1->unk_08 * GetTileSize(), param_1->unk_18, param_1->unk_16);
            param_1->unk_06 =
                Interpolate(4, param_1->unk_14, param_1->unk_09 * GetTileSize(), param_1->unk_18, param_1->unk_16);
        }

        if (param_1->unk_18 == param_1->unk_16)
        {
            param_1->unk_18 = 0;
            param_1->unk_16 = 0;
        }
    }

    if (param_1->unk_16 == 0 && !(gMapStateManager->camera->unk_18 < 2 ? FALSE : TRUE))
    {
        param_1->unk_0b = 1;
    }

    return;
}

EC void func_ov000_021a6e68(MapStateManager_10 * param_1)
{
    switch (param_1->unk_0b)
    {
        case 1:
            func_ov000_021a6c38(param_1);
            break;

        case 2:
            func_ov000_021a6d48(param_1);
            break;
    }

    if (param_1->unk_0d != 0)
    {
        param_1->unk_0d--;
    }

    return;
}

EC BOOL func_ov000_021a6ea8(MapStateManager_10 * param_1, s32 param_2)
{
    s32 iVar3;

    s32 idk = (param_1->unk_08 * GetTileSize() + (GetTileSize() >> 1));

    if (param_2 != 0)
    {
        iVar3 = gMapStateManager->camera->unk_14;
    }
    else
    {
        iVar3 = gMapStateManager->camera->unk_00;
    }

    if ((idk - iVar3) < 0x80)
    {
        return TRUE;
    }

    return FALSE;
}
