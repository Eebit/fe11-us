#include "global.h"

#include "unknown_data.h"
#include "unknown_types.hpp"
#include "unknown_funcs.h"
#include "unit.h"

#include "map.hpp"

#define GetPos(x, y) ((x) | ((y) << 5))

EC void main(void)
{
    func_0200ef04();
    func_0200f028();
    StartGame();
    func_020ad244(0x14);

    while (TRUE)
        func_0200f04c();
}

EC void * func_02000c70(void)
{
    return &data_027e00e0;
}

EC void func_02000c7c(struct UnkStruct_021E3324_04_08 * buf)
{
    buf->unk_086e = data_ov000_021e3328->unk_20;
    buf->unk_086f = data_ov000_021e3328->unk_22;
    buf->unk_0870 = data_ov000_021e3328->unk_24;
    buf->unk_0871 = data_ov000_021e3328->unk_25;
    buf->unk_0872 = data_ov000_021e3328->unk_26;
    buf->unk_0873 = data_ov000_021e3328->unk_27;
    buf->unk_0874 = data_ov000_021e3324->phase;

    buf->unk_0854 = buf->unk_0878;
    buf->unk_0858 = buf->unk_1078;
    buf->unk_085c = buf->unk_10f8;
    buf->unk_0860 = data_ov000_021e3328->unk_028;
}

EC void func_02000d14(struct UnkStruct_021E3324_04_08 * buf, s32 a)
{
    func_020a5824(buf->unk_0854, a & 0xFF, 0x400);
}

EC void func_02000d2c(struct UnkStruct_Func_2000D2C * buf, s32 a, s32 b)
{
    s32 tmp1, tmp2;
    struct Unit * unit = data_ov000_021e3328->unk_04->unk_00;

    tmp1 = func_0203c77c(unit);
    if (CheckUnitAttribute(unit, 0x8000000))
        tmp1 = 0;

    tmp2 = func_02001770(buf, a, b);
    if (tmp2 >= 0)
    {
        func_02001bac(buf, tmp2);
        return;
    }

    if ((ABS(a - buf->unk_42) + ABS(b - buf->unk_43)) == 1)
    {
        s32 tmp_r0 = func_020016e8(buf, unit, a, b);

        if ((buf->unk_47 + tmp_r0) <= tmp1)
        {
            s32 tmp_r2 = buf->unk_42;
            s32 tmp_r3 = buf->unk_43;

            if (buf->unk_42 < (s8)a)
                tmp_r2 = 2;
            else if (buf->unk_42 > (s8)a)
                tmp_r2 = 1;
            else if (buf->unk_43 < (s8)b)
                tmp_r2 = 4;
            else if (tmp_r3 > (s8)b)
                tmp_r2 = 8;
            else
                tmp_r2 = 0x80;

            buf->unk_00[buf->unk_46] = tmp_r2;
            buf->unk_42 = a;
            buf->unk_43 = b;
            buf->unk_47 += tmp_r0;
            buf->unk_46++;
            return;
        }
    }

    data_ov000_021e3328->unk_08->unk_0854 = data_ov000_021e3328->unk_08->unk_0c78;

    func_01ff8000(
        data_ov000_021e3328->unk_08,
        buf->unk_42,
        buf->unk_43,
        unit->pJobData->unk_28,
        tmp1 - buf->unk_47,
        0xA
    );

    if (data_ov000_021e3328->unk_08->unk_0854[GetPos(a, b)] >= 0)
    {
        func_02001820(buf, a, b, 1);
        data_ov000_021e3328->unk_08->unk_0854 = data_ov000_021e3328->unk_08->unk_0878;
    }
    else
    {
        data_ov000_021e3328->unk_08->unk_0854 = data_ov000_021e3328->unk_08->unk_0878;
        buf->unk_47 = 0;
        buf->unk_46 = 0;
        func_02001820(buf, a, b, 1);
    }
}

EC BOOL func_02000f18(struct UnkStruct_Func_2000D2C * buf, s32 a, s32 b, s32 c)
{
    s32 tmp4;
    struct Unit * unit = data_ov000_021e3328->unk_04->unk_00;

    if (data_ov000_021e3328->unk_028[GetPos(buf->unk_42, buf->unk_43)] != 0)
        return FALSE;

    tmp4 = ABS(a - buf->unk_42) + ABS(b - buf->unk_43);

    if (c == 2)
    {
        if (tmp4 != 1)
            return FALSE;

        buf->unk_48 = -1;
    }
    else
    {
        s32 ret = func_02039088(unit, buf->unk_42, buf->unk_43, tmp4, c == 0, c == 1, -1);

        if (ret < 0)
            return FALSE;

        buf->unk_48 = ret;
    }

    return TRUE;
}

EC s32 func_02000fec(struct UnkStruct_Func_2000D2C * buf, s32 a, s32 b)
{
    s32 tmp_r4 = 0;
    s32 ret = func_02001770(buf, a, b);
    s32 terrainId;

    if (ret >= 0)
    {
        tmp_r4 += 0x40000000;
        tmp_r4 += ret << 16;
    }
    else
    {
        struct UnkStruct_021E3324_04_08 * r2 = data_ov000_021e3328->unk_08;
        s8 * unk_0c78 = r2->unk_0c78;

        // The temp variable seems to be required
        s8 * tmp_r0 = &unk_0c78[GetPos(a, b)];

        if (unk_0c78[GetPos(a, b)] >= 0)
        {
            tmp_r4 += 0x20000000;
            tmp_r4 += (0x80 - *tmp_r0) << 16;
        }
        else
        {
            tmp_r4 += (0x80 - r2->unk_0854[GetPos(a, b)]) << 16;
        }
    }

    // The temp variable seems to be required
    terrainId = data_ov000_021e3328->unk_828[GetPos(a, b)];

    tmp_r4 += (data_02197254->pTerrain[terrainId].unk_08[0] << 8);
    tmp_r4 += (data_02197254->pTerrain[data_ov000_021e3328->unk_828[GetPos(a, b)]].unk_08[1] << 4);
    tmp_r4 += (data_02197254->pTerrain[data_ov000_021e3328->unk_828[GetPos(a, b)]].unk_08[2]);

    return tmp_r4;
}
