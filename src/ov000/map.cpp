#include "global.h"

#include "unknown_funcs.h"

#define GFX_FIFO_MATRIX_MODE *(vu32 *)(0x04000440)
#define GFX_FIFO_MATRIX_IDENTITY *(vu32 *)(0x04000454)
#define GFX_FIFO_MATRIX_TRANSLATE *(vu32 *)(0x04000470)
#define GFX_FIFO_POLYGON_ATTR *(vu32 *)(0x040004A4)
#define GFX_FIFO_TEXTURE_PARAM *(vu32 *)(0x040004A8)
#define GFX_FIFO_TEXTURE_PALETTE *(vu32 *)(0x040004AC)

extern u8 data_027e1b9c[];

struct UnkStruct_021e34fc
{
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
};

extern struct UnkStruct_021e34fc data_ov000_021e34fc;

extern s16 data_020c53b0[]; // gSinLut?
extern vu32 gClock;

EC void func_ov000_021d7acc(MapFile *);
EC void func_ov000_021d7afc(MapFile *);

EC void func_ov000_021d708c(MapFile * map, s32 param_2)
{
    s32 i;
    MapTexture * texture;
    u8 * mapTextureFile;

    data_ov000_021e34fc.unk_08 = 0;
    data_ov000_021e34fc.unk_00 = 0;

    func_ov000_021d7acc(map);

    for (i = 0; i < map->unk_0f; i++)
    {
        mapTextureFile = (u8 *)map->unk_08;

        texture = &map->unk_1c[i];

        texture->unk_08 = data_ov000_021e34fc.unk_08;
        data_ov000_021e34fc.unk_08 += texture->unk_04;

        texture->unk_14 = data_ov000_021e34fc.unk_00;
        data_ov000_021e34fc.unk_00 += texture->unk_10;

        if (param_2 != 0)
        {
            func_0206eae0(
                mapTextureFile + texture->unk_0c, mapTextureFile + texture->unk_0c, param_2 + 16, texture->unk_10 / 4);
        }

        func_0201fe14(mapTextureFile + texture->unk_00, texture->unk_08, texture->unk_04);
        func_0201fec0(mapTextureFile + texture->unk_0c, texture->unk_14, texture->unk_10);

        if ((texture->unk_26 & 1) != 0)
        {
            texture->unk_18 = static_cast<u16 *>(func_01ffb934(data_027e1b9c, texture->unk_10));
            func_020a5780(mapTextureFile + texture->unk_0c, texture->unk_18, texture->unk_10);
        }
    }

    func_ov000_021d7afc(map);

    return;
}

EC void func_ov000_021d71ac(MapFile * map)
{
    s32 i;

    for (i = 0; i < map->unk_0f; i++)
    {
        MapTexture * texture = &map->unk_1c[i];

        if (texture->unk_18 != NULL)
        {
            func_01ffbb90(data_027e1b9c, texture->unk_18);
            texture->unk_18 = NULL;
        }
    }

    if (map->unk_08 != NULL)
    {
        func_ov000_021d7afc(map);
    }

    data_ov000_021e34fc.unk_08 = 0;
    data_ov000_021e34fc.unk_00 = 0;

    return;
}

static inline s16 sin(u16 aAngle)
{
    return data_020c53b0[((aAngle) >> 4) + 0];
}

static inline s16 cos(u16 aAngle)
{
    return data_020c53b0[((aAngle) >> 4) + 1];
}

static inline void SetPolygonAttr(u32 id, u32 alpha)
{
    // https://www.problemkaputt.de/gbatek.htm#ds3dpolygonattributes
    GFX_FIFO_POLYGON_ATTR =
        (0xc0) | 
        (id << 0x18) |
        (alpha << 0x10);
}

static inline void SetTexturePalette(u32 address, u32 format)
{
    // div8 (lsr 3) for 4-colour
    // div16 (lsr 4) for anything else
    GFX_FIFO_TEXTURE_PALETTE = address >> (4 - ((format == 2) ? 1 : 0));
}

static inline void MatrixTranslate(u32 x, u32 y, u32 z)
{
    GFX_FIFO_MATRIX_TRANSLATE = x;
    GFX_FIFO_MATRIX_TRANSLATE = y;
    GFX_FIFO_MATRIX_TRANSLATE = z;
}

// NONMATCHING: https://decomp.me/scratch/04U8Z
EC void func_ov000_021d7234(MapFile * map)
{
    s32 i;
    s32 j;
    u16 temp_tiles[0x20];

    GFX_FIFO_MATRIX_MODE = 3;
    data_ov000_021e34fc.unk_04 = 1;

    for (i = map->unk_0e - 1; i >= 0; i--)
    {
        s32 alpha;
        struct MapTexture * texture;
        struct MapLayer_10 * layer_10;
        struct MapLayer_14 * layer_14;

        struct MapLayer * layer = &map->unk_18[i];

        switch (layer->unk_00)
        {
            case 0:
                alpha = layer->unk_01;
                if (alpha == 0)
                {
                    goto _844;
                }

                texture = layer->unk_04;
                GFX_FIFO_MATRIX_IDENTITY = 0;

                if ((texture->unk_26 & 2) && alpha == 31)
                {
                    SetPolygonAttr(0, 31);
                }
                else
                {
                    SetPolygonAttr(data_ov000_021e34fc.unk_04++, alpha);
                }

                GFX_FIFO_TEXTURE_PARAM = 
                    (texture->unk_08 >> 3) |
                    (texture->unk_20 << 0x1a) |
                    0x40000000 |
                    (texture->unk_21 << 0x14) |
                    (texture->unk_22 << 0x17) |
                    (texture->unk_23 << 0x10) |
                    (texture->unk_24 << 0x12) |
                    (texture->unk_25 << 0x1d);

                if (texture->unk_10 != 0)
                {
                    SetTexturePalette(texture->unk_14, texture->unk_20);
                }

                layer_10 = layer->unk_10;

                if (layer_10 != NULL)
                {
                    texture = layer->unk_04;

                    switch (layer_10->unk_00)
                    {
                        case 1:
                        {
                            s32 a = layer_10->unk_0e * cos((0x10000 / layer_10->unk_0c) * gClock);
                            s32 x = (((layer_10->unk_04 * gClock) + (a * 0x10)));
                            s32 b = layer_10->unk_12 * sin((0x10000 / layer_10->unk_10) * gClock);
                            s32 y = (((layer_10->unk_08 * gClock) + (b * 0x10)));
                            MatrixTranslate(
                                x & ((texture->unk_1c << 0x10) - 1),
                                y & ((texture->unk_1e << 0x10) - 1),
                                0
                            );
                            break;
                        }

                        case 2:
                        {
                            s32 temp_r0_8 = (gClock % (layer_10->unk_0a * layer_10->unk_08)) / layer_10->unk_0a;
                            s32 temp_r0_9 = texture->unk_1c / layer_10->unk_04;
                            MatrixTranslate(
                                (layer_10->unk_04 << 0x10) * (temp_r0_8 % temp_r0_9),
                                (layer_10->unk_06 << 0x10) * (temp_r0_8 / temp_r0_9),
                                0
                            );
                            break;
                        }
                    }
                }

                break;

            case 3:
                texture = layer->unk_04;

                GFX_FIFO_MATRIX_IDENTITY = 0;

                if (!(texture->unk_26 & 2))
                {
                    SetPolygonAttr(0, 31);
                }
                else
                {
                    SetPolygonAttr(data_ov000_021e34fc.unk_04++, 31);
                }

                GFX_FIFO_TEXTURE_PARAM = 
                    ((texture->unk_08 >> 3) | 
                    (texture->unk_20 << 0x1A) |
                     0x40000000 | 
                     (texture->unk_21 << 0x14) | 
                     (texture->unk_22 << 0x17) | 
                     (texture->unk_23 << 0x10) | 
                     (texture->unk_24 << 0x12) | 
                     (texture->unk_25 << 0x1D));

                if (texture->unk_10 != 0)
                {
                    SetTexturePalette(texture->unk_14, texture->unk_20);
                }

                layer_10 = layer->unk_10;

                if (layer_10 != NULL)
                {
                    texture = layer->unk_04;

                    switch (layer_10->unk_00)
                    {
                        case 1:
                        {
                            s32 a = layer_10->unk_0e * cos((0x10000 / layer_10->unk_0c) * gClock);
                            s32 x = (((layer_10->unk_04 * gClock) + (a * 0x10)));
                            s32 b = layer_10->unk_12 * sin((0x10000 / layer_10->unk_10) * gClock);
                            s32 y = (((layer_10->unk_08 * gClock) + (b * 0x10)));
                            MatrixTranslate(
                                x & ((texture->unk_1c << 0x10) - 1),
                                y & ((texture->unk_1e << 0x10) - 1),
                                0
                            );
                            break;
                        }
                        case 2:
                        {
                            s32 temp_r0_8 = (gClock % (layer_10->unk_0a * layer_10->unk_08)) / layer_10->unk_0a;
                            s32 temp_r0_9 = texture->unk_1c / layer_10->unk_04;
                            MatrixTranslate(
                                (layer_10->unk_04 << 0x10) * (temp_r0_8 % temp_r0_9),
                                (layer_10->unk_06 << 0x10) * (temp_r0_8 / temp_r0_9),
                                0
                            );
                            break;
                        }
                    }
                }

                MatrixTranslate(
                    0,
                    layer->unk_01 << 0x13,
                    0
                );

                break;

            case 1:
                texture = layer->unk_04;

                GFX_FIFO_MATRIX_IDENTITY = 0;

                if (!(texture->unk_26 & 2))
                {
                    SetPolygonAttr(0, 31);
                }
                else
                {
                    SetPolygonAttr(data_ov000_021e34fc.unk_04++, 31);
                }

                GFX_FIFO_TEXTURE_PARAM = 
                    ((texture->unk_08 >> 3) | 
                     (texture->unk_20 << 0x1A) |
                     0x40000000 | 
                     (texture->unk_21 << 0x14) | 
                     (texture->unk_22 << 0x17) | 
                     (texture->unk_23 << 0x10) | 
                     (texture->unk_24 << 0x12) | 
                     (texture->unk_25 << 0x1D));

                if (texture->unk_10 != 0)
                {
                    SetTexturePalette(texture->unk_14, texture->unk_20);
                }

                MatrixTranslate(
                    0,
                    layer->unk_01 * 0x48000,
                    0
                );

                break;

            case 2:
                alpha = layer->unk_01;
                if (alpha == 0)
                {
                    goto _844;
                }

                texture = layer->unk_04;

                GFX_FIFO_MATRIX_IDENTITY = 0;

                if ((texture->unk_26 & 2) && (alpha == 31))
                {
                    SetPolygonAttr(0, 31);
                }
                else
                {
                    SetPolygonAttr(data_ov000_021e34fc.unk_04++, alpha);
                }

                GFX_FIFO_TEXTURE_PARAM = 
                    ((texture->unk_08 >> 3) | 
                     (texture->unk_20 << 0x1A) |
                     0x40000000 | 
                     (texture->unk_21 << 0x14) | 
                     (texture->unk_22 << 0x17) | 
                     (texture->unk_23 << 0x10) | 
                     (texture->unk_24 << 0x12) | 
                     (texture->unk_25 << 0x1D));

                if (texture->unk_10 != 0)
                {
                    SetTexturePalette(texture->unk_14, texture->unk_20);
                }

                break;
        }

        layer_14 = layer->unk_14;

        if (layer_14 != NULL)
        {
            texture = layer->unk_04;

            layer_14->unk_04--;

            if (layer_14->unk_04 <= 0) {
                layer_14->unk_04 = layer_14->unk_03;

                switch (layer_14->unk_00)
                {
                    case 1:
                        if (layer_14->unk_02 <= 0x20)
                        {
                            s32 unk_02 = layer_14->unk_02;
                            s32 unk_01 = layer_14->unk_01;
                            if ((u32)((unk_02 + unk_01) * 2) <= func_020114dc(data_027e1b9c, texture->unk_18))
                            {
                                for (j = 0; j < unk_02; j++)
                                {
                                    temp_tiles[j] = texture->unk_18[j + unk_01];
                                }

                                for (j = 0; j < layer_14->unk_02; j++)
                                {
                                    texture->unk_18[layer_14->unk_01 + j] = temp_tiles[(layer_14->unk_05 + (j + layer_14->unk_02)) % layer_14->unk_02];
                                }

                                func_020205a4((u8 *)texture->unk_18 + (layer_14->unk_01 * 2), texture->unk_14 + (layer_14->unk_01 * 2), layer_14->unk_02 * 2, 0);
                            }
                        }
                        break;

                    case 2:
                    {
                        s32 var_r0_2;

                        layer_14->unk_08++;

                        if (layer_14->unk_09 != 0)
                        {
                            s32 temp_r8 = layer_14->unk_07 - 1;
                            s32 temp_r9_2 = temp_r8 * 2;
                            s32 temp_r1_2 = layer_14->unk_08 % temp_r9_2;
                            var_r0_2 = temp_r1_2 & 0xff;
                            layer_14->unk_08 = temp_r1_2;
                            if (var_r0_2 >= temp_r8)
                            {
                                var_r0_2 = temp_r9_2 - var_r0_2;
                            }
                        }
                        else
                        {
                            s32 temp_r1_3 = layer_14->unk_08 % layer_14->unk_07;
                            layer_14->unk_08 = temp_r1_3;
                            var_r0_2 = temp_r1_3 & 0xff;
                        }

                        func_020a56d4((u8 *)texture->unk_18 + (((var_r0_2 * layer_14->unk_05) + layer_14->unk_06) * 2), (u8 *)texture->unk_18 + (layer_14->unk_01 * 2), layer_14->unk_02 * 2);
                        func_020205a4((u8 *)texture->unk_18 + (layer_14->unk_01 * 2), texture->unk_14 + (layer_14->unk_01 * 2), layer_14->unk_02 * 2, 0);

                        break;
                    }
                }
            }
        }

        func_01ffcc3c(3, (s32)layer->unk_08, layer->unk_0c);
    }

_844:
    GFX_FIFO_MATRIX_IDENTITY = 0;
    GFX_FIFO_MATRIX_MODE = 1;

    return;
}

EC void func_ov000_021d7acc(MapFile * map)
{
    if (map->unk_08 != NULL)
    {
        return;
    }

    func_02012180("/map");
    map->unk_08 = func_02012164(map->unk_04);

    return;
}

EC void func_ov000_021d7afc(MapFile * map)
{
    if (map->unk_08 == NULL)
    {
        return;
    }

    func_01ffbb90(data_027e1b9c, map->unk_08);
    map->unk_08 = NULL;

    return;
}

EC u32 func_ov000_021d7b28(void)
{
    return data_ov000_021e34fc.unk_08;
}

EC u32 func_ov000_021d7b38(void)
{
    return data_ov000_021e34fc.unk_00;
}

extern u16 * data_ov000_021e2c54[];

// Get minimap sprite def
EC u16 * func_ov000_021d7b48(MapFile * map)
{
    u32 idx = 0;

    if (map->unk_20 > 8)
    {
        idx += 1;
    }

    if (map->unk_21 > 8)
    {
        idx += 2;
    }

    return data_ov000_021e2c54[idx];
}

EC MapLayer * func_ov000_021d7b74(MapFile * map, s32 arg1, s32 arg2, s32 arg3)
{
    s32 i;

    for (i = 0; i < map->unk_0e; i++)
    {
        if (arg2 == map->unk_18[i].unk_02 && arg3 == map->unk_18[i].unk_03 && arg1 == map->unk_18[i].unk_00)
        {
            return &map->unk_18[i];
        }
    }

    return NULL;
}

EC BOOL func_ov000_021d7bd8(MapFile * map, s32 param_2, s32 param_3, s32 alpha)
{
    MapLayer * layer = func_ov000_021d7b74(map, 1, param_2, param_3);

    if (layer == NULL)
    {
        return FALSE;
    }

    layer->unk_01 = alpha;

    return TRUE;
}

EC void func_ov000_021d7c08(MapFile * map, s32 alpha)
{
    s32 i;

    for (i = 0; i < map->unk_0e; i++)
    {
        if (map->unk_18[i].unk_00 != 3)
        {
            continue;
        }

        map->unk_18[i].unk_01 = alpha;
    }

    return;
}

EC void func_ov000_021d7c50(MapFile * map, s32 layerIdx, s32 alpha)
{
    if (layerIdx >= map->unk_0e)
    {
        return;
    }

    if (map->unk_18[layerIdx].unk_00 == 1)
    {
        return;
    }

    if (alpha > 31)
    {
        alpha = 31;
    }

    if (alpha < 0)
    {
        alpha = 0;
    }

    map->unk_18[layerIdx].unk_01 = alpha;

    return;
}
