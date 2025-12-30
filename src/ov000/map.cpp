#include "global.h"

#include "heap.hpp"
#include "oam.h"
#include "unknown_funcs.h"

#define GFX_FIFO_MATRIX_MODE *(vu32 *)(0x04000440)
#define GFX_FIFO_MATRIX_IDENTITY *(vu32 *)(0x04000454)
#define GFX_FIFO_MATRIX_TRANSLATE *(vu32 *)(0x04000470)
#define GFX_FIFO_POLYGON_ATTR *(vu32 *)(0x040004A4)
#define GFX_FIFO_TEXTURE_PARAM *(vu32 *)(0x040004A8)
#define GFX_FIFO_TEXTURE_PALETTE *(vu32 *)(0x040004AC)

struct MapRenderState
{
    u32 unk_00;
    /* 04 */ u32 nextPolygonId;
    u32 unk_08;
};

extern struct MapRenderState gMapRenderState;

extern s16 data_020c53b0[]; // gSinLut?
extern vu32 gClock;

EC void Map_LoadTAFile(MapFile *);
EC void Map_UnloadTAFile(MapFile *);

EC void Map_LoadTextures(MapFile * map, s32 brightness)
{
    s32 i;
    MapTexture * texture;
    u8 * mapTextureFile;

    gMapRenderState.unk_08 = 0;
    gMapRenderState.unk_00 = 0;

    Map_LoadTAFile(map);

    for (i = 0; i < map->textureCount; i++)
    {
        mapTextureFile = (u8 *)map->taFileData;

        texture = &map->pTextures[i];

        texture->imgDst = gMapRenderState.unk_08;
        gMapRenderState.unk_08 += texture->imgSize;

        texture->palDst = gMapRenderState.unk_00;
        gMapRenderState.unk_00 += texture->palSize;

        if (brightness != 0)
        {
            AdjustPaletteBrightness(
                mapTextureFile + texture->palOffset, mapTextureFile + texture->palOffset, brightness + 16, texture->palSize / 4);
        }

        LoadTextureImage(mapTextureFile + texture->imgOffset, texture->imgDst, texture->imgSize);
        LoadTexturePalette(mapTextureFile + texture->palOffset, texture->palDst, texture->palSize);

        if ((texture->unk_26 & 1) != 0)
        {
            texture->unk_18 = static_cast<u16 *>(gHeap.Alloc(texture->palSize));
            func_020a5780(mapTextureFile + texture->palOffset, texture->unk_18, texture->palSize);
        }
    }

    Map_UnloadTAFile(map);

    return;
}

EC void Map_UnloadTextures(MapFile * map)
{
    s32 i;

    for (i = 0; i < map->textureCount; i++)
    {
        MapTexture * texture = &map->pTextures[i];

        if (texture->unk_18 != NULL)
        {
            gHeap.Free(texture->unk_18);
            texture->unk_18 = NULL;
        }
    }

    if (map->taFileData != NULL)
    {
        Map_UnloadTAFile(map);
    }

    gMapRenderState.unk_08 = 0;
    gMapRenderState.unk_00 = 0;

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
    GFX_FIFO_POLYGON_ATTR = (0xc0) | (id << 0x18) | (alpha << 0x10);
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
EC void Map_RenderLayers(MapFile * map)
{
    s32 i;
    s32 j;
    u16 temp_tiles[0x20];

    GFX_FIFO_MATRIX_MODE = 3;
    gMapRenderState.nextPolygonId = 1;

    for (i = map->layerCount - 1; i >= 0; i--)
    {
        s32 alpha;
        struct MapTexture * texture;
        struct MapLayer_10 * layer_10;
        struct MapLayer_14 * layer_14;

        struct MapLayer * layer = &map->pLayers[i];

        switch (layer->kind)
        {
            case 0:
                alpha = layer->alpha;
                if (alpha == 0)
                {
                    goto _844;
                }

                texture = layer->pTexture;
                GFX_FIFO_MATRIX_IDENTITY = 0;

                if ((texture->unk_26 & 2) && alpha == 31)
                {
                    SetPolygonAttr(0, 31);
                }
                else
                {
                    SetPolygonAttr(gMapRenderState.nextPolygonId++, alpha);
                }

                GFX_FIFO_TEXTURE_PARAM = (texture->imgDst >> 3) | (texture->unk_20 << 0x1a) | 0x40000000 |
                    (texture->unk_21 << 0x14) | (texture->unk_22 << 0x17) | (texture->unk_23 << 0x10) |
                    (texture->unk_24 << 0x12) | (texture->unk_25 << 0x1d);

                if (texture->palSize != 0)
                {
                    SetTexturePalette(texture->palDst, texture->unk_20);
                }

                layer_10 = layer->unk_10;

                if (layer_10 != NULL)
                {
                    texture = layer->pTexture;

                    switch (layer_10->unk_00)
                    {
                        case 1:
                        {
                            s32 a = layer_10->unk_0e * cos((0x10000 / layer_10->unk_0c) * gClock);
                            s32 x = (((layer_10->unk_04 * gClock) + (a * 0x10)));
                            s32 b = layer_10->unk_12 * sin((0x10000 / layer_10->unk_10) * gClock);
                            s32 y = (((layer_10->unk_08 * gClock) + (b * 0x10)));
                            MatrixTranslate(
                                x & ((texture->unk_1c << 0x10) - 1), y & ((texture->unk_1e << 0x10) - 1), 0);
                            break;
                        }

                        case 2:
                        {
                            s32 temp_r0_8 = (gClock % (layer_10->unk_0a * layer_10->unk_08)) / layer_10->unk_0a;
                            s32 temp_r0_9 = texture->unk_1c / layer_10->unk_04;
                            MatrixTranslate(
                                (layer_10->unk_04 << 0x10) * (temp_r0_8 % temp_r0_9),
                                (layer_10->unk_06 << 0x10) * (temp_r0_8 / temp_r0_9), 0);
                            break;
                        }
                    }
                }

                break;

            case 3:
                texture = layer->pTexture;

                GFX_FIFO_MATRIX_IDENTITY = 0;

                if (!(texture->unk_26 & 2))
                {
                    SetPolygonAttr(0, 31);
                }
                else
                {
                    SetPolygonAttr(gMapRenderState.nextPolygonId++, 31);
                }

                GFX_FIFO_TEXTURE_PARAM =
                    ((texture->imgDst >> 3) | (texture->unk_20 << 0x1A) | 0x40000000 | (texture->unk_21 << 0x14) |
                     (texture->unk_22 << 0x17) | (texture->unk_23 << 0x10) | (texture->unk_24 << 0x12) |
                     (texture->unk_25 << 0x1D));

                if (texture->palSize != 0)
                {
                    SetTexturePalette(texture->palDst, texture->unk_20);
                }

                layer_10 = layer->unk_10;

                if (layer_10 != NULL)
                {
                    texture = layer->pTexture;

                    switch (layer_10->unk_00)
                    {
                        case 1:
                        {
                            s32 a = layer_10->unk_0e * cos((0x10000 / layer_10->unk_0c) * gClock);
                            s32 x = (((layer_10->unk_04 * gClock) + (a * 0x10)));
                            s32 b = layer_10->unk_12 * sin((0x10000 / layer_10->unk_10) * gClock);
                            s32 y = (((layer_10->unk_08 * gClock) + (b * 0x10)));
                            MatrixTranslate(
                                x & ((texture->unk_1c << 0x10) - 1), y & ((texture->unk_1e << 0x10) - 1), 0);
                            break;
                        }
                        case 2:
                        {
                            s32 temp_r0_8 = (gClock % (layer_10->unk_0a * layer_10->unk_08)) / layer_10->unk_0a;
                            s32 temp_r0_9 = texture->unk_1c / layer_10->unk_04;
                            MatrixTranslate(
                                (layer_10->unk_04 << 0x10) * (temp_r0_8 % temp_r0_9),
                                (layer_10->unk_06 << 0x10) * (temp_r0_8 / temp_r0_9), 0);
                            break;
                        }
                    }
                }

                MatrixTranslate(0, layer->alpha << 0x13, 0);

                break;

            case 1:
                texture = layer->pTexture;

                GFX_FIFO_MATRIX_IDENTITY = 0;

                if (!(texture->unk_26 & 2))
                {
                    SetPolygonAttr(0, 31);
                }
                else
                {
                    SetPolygonAttr(gMapRenderState.nextPolygonId++, 31);
                }

                GFX_FIFO_TEXTURE_PARAM =
                    ((texture->imgDst >> 3) | (texture->unk_20 << 0x1A) | 0x40000000 | (texture->unk_21 << 0x14) |
                     (texture->unk_22 << 0x17) | (texture->unk_23 << 0x10) | (texture->unk_24 << 0x12) |
                     (texture->unk_25 << 0x1D));

                if (texture->palSize != 0)
                {
                    SetTexturePalette(texture->palDst, texture->unk_20);
                }

                MatrixTranslate(0, layer->alpha * 0x48000, 0);

                break;

            case 2:
                alpha = layer->alpha;
                if (alpha == 0)
                {
                    goto _844;
                }

                texture = layer->pTexture;

                GFX_FIFO_MATRIX_IDENTITY = 0;

                if ((texture->unk_26 & 2) && (alpha == 31))
                {
                    SetPolygonAttr(0, 31);
                }
                else
                {
                    SetPolygonAttr(gMapRenderState.nextPolygonId++, alpha);
                }

                GFX_FIFO_TEXTURE_PARAM =
                    ((texture->imgDst >> 3) | (texture->unk_20 << 0x1A) | 0x40000000 | (texture->unk_21 << 0x14) |
                     (texture->unk_22 << 0x17) | (texture->unk_23 << 0x10) | (texture->unk_24 << 0x12) |
                     (texture->unk_25 << 0x1D));

                if (texture->palSize != 0)
                {
                    SetTexturePalette(texture->palDst, texture->unk_20);
                }

                break;
        }

        layer_14 = layer->unk_14;

        if (layer_14 != NULL)
        {
            texture = layer->pTexture;

            layer_14->unk_04--;

            if (layer_14->unk_04 <= 0)
            {
                layer_14->unk_04 = layer_14->unk_03;

                switch (layer_14->unk_00)
                {
                    case 1:
                        if (layer_14->unk_02 <= 0x20)
                        {
                            s32 unk_02 = layer_14->unk_02;
                            s32 unk_01 = layer_14->unk_01;
                            if ((u32)((unk_02 + unk_01) * 2) <= gHeap.SizeOf(texture->unk_18))
                            {
                                for (j = 0; j < unk_02; j++)
                                {
                                    temp_tiles[j] = texture->unk_18[j + unk_01];
                                }

                                for (j = 0; j < layer_14->unk_02; j++)
                                {
                                    texture->unk_18[layer_14->unk_01 + j] =
                                        temp_tiles[(layer_14->unk_05 + (j + layer_14->unk_02)) % layer_14->unk_02];
                                }

                                func_020205a4(
                                    (u16 *)texture->unk_18 + (layer_14->unk_01 * 2),
                                    texture->palDst + (layer_14->unk_01 * 2), layer_14->unk_02 * 2, 0);
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

                        func_020a56d4(
                            (u8 *)texture->unk_18 + (((var_r0_2 * layer_14->unk_05) + layer_14->unk_06) * 2),
                            (u8 *)texture->unk_18 + (layer_14->unk_01 * 2), layer_14->unk_02 * 2);
                        func_020205a4(
                            (u16 *)texture->unk_18 + (layer_14->unk_01 * 2), texture->palDst + (layer_14->unk_01 * 2),
                            layer_14->unk_02 * 2, 0);

                        break;
                    }
                }
            }
        }

        func_01ffcc3c(3, (s32)layer->gfxCommandList, layer->gfxCmdSize);
    }

_844:
    GFX_FIFO_MATRIX_IDENTITY = 0;
    GFX_FIFO_MATRIX_MODE = 1;

    return;
}

EC void Map_LoadTAFile(MapFile * map)
{
    if (map->taFileData != NULL)
    {
        return;
    }

    func_02012180("/map");
    map->taFileData = func_02012164(map->taFileName);

    return;
}

EC void Map_UnloadTAFile(MapFile * map)
{
    if (map->taFileData == NULL)
    {
        return;
    }

    gHeap.Free(map->taFileData);
    map->taFileData = NULL;

    return;
}

EC u32 MapRenderState_GetUnk08(void)
{
    return gMapRenderState.unk_08;
}

EC u32 MapRenderState_GetUnk00(void)
{
    return gMapRenderState.unk_00;
}

// clang-format off

u16 Sprite_Minimap_021e2c30[] =
{
    OAM0_SHAPE_64x64 + OAM0_256COLORS, OAM1_SIZE_64x64, 0,
    -1,
};

u16 Sprite_Minimap_021e2c46[] =
{
    OAM0_SHAPE_64x64 + OAM0_256COLORS, OAM1_SIZE_64x64, 0,
    OAM0_SHAPE_64x64 + OAM0_256COLORS, OAM1_SIZE_64x64 + OAM1_X(+64), OAM2_CHR(0x80),
    -1,
};

u16 Sprite_Minimap_021e2c38[] =
{
    OAM0_SHAPE_64x64 + OAM0_256COLORS, OAM1_SIZE_64x64, 0,
    OAM0_SHAPE_64x64 + OAM0_Y(+64) + OAM0_256COLORS, OAM1_SIZE_64x64, OAM2_CHR(0x100),
    -1,
};

u16 Sprite_Minimap_021e2c64[] =
{
    OAM0_SHAPE_64x64 + OAM0_256COLORS, OAM1_SIZE_64x64, 0,
    OAM0_SHAPE_64x64 + OAM0_256COLORS, OAM1_SIZE_64x64 + OAM1_X(+64), OAM2_CHR(0x80),
    OAM0_SHAPE_64x64 + OAM0_Y(+64) + OAM0_256COLORS, OAM1_SIZE_64x64, OAM2_CHR(0x100),
    OAM0_SHAPE_64x64 + OAM0_Y(+64) + OAM0_256COLORS, OAM1_SIZE_64x64 + OAM1_X(+64), OAM2_CHR(0x180),
    -1,
};

u16 * SpriteLut_Minimap[] =
{
    Sprite_Minimap_021e2c30,
    Sprite_Minimap_021e2c46,
    Sprite_Minimap_021e2c38,
    Sprite_Minimap_021e2c64,
};

// clang-format on

EC u16 * Map_GetMinimapSprite(MapFile * map)
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

    return SpriteLut_Minimap[idx];
}

EC MapLayer * Map_FindLayer(MapFile * map, s32 arg1, s32 arg2, s32 arg3)
{
    s32 i;

    for (i = 0; i < map->layerCount; i++)
    {
        if (arg2 == map->pLayers[i].unk_02 && arg3 == map->pLayers[i].unk_03 && arg1 == map->pLayers[i].kind)
        {
            return &map->pLayers[i];
        }
    }

    return NULL;
}

EC BOOL Map_SetLayerAlphaAt(MapFile * map, s32 param_2, s32 param_3, s32 alpha)
{
    MapLayer * layer = Map_FindLayer(map, 1, param_2, param_3);

    if (layer == NULL)
    {
        return FALSE;
    }

    layer->alpha = alpha;

    return TRUE;
}

EC void Map_SetAllKind3LayersAlpha(MapFile * map, s32 alpha)
{
    s32 i;

    for (i = 0; i < map->layerCount; i++)
    {
        if (map->pLayers[i].kind != 3)
        {
            continue;
        }

        map->pLayers[i].alpha = alpha;
    }

    return;
}

EC void Map_SetLayerAlphaById(MapFile * map, s32 layerIdx, s32 alpha)
{
    if (layerIdx >= map->layerCount)
    {
        return;
    }

    if (map->pLayers[layerIdx].kind == 1)
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

    map->pLayers[layerIdx].alpha = alpha;

    return;
}
