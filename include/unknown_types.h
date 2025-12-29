#ifndef UNKNOWN_TYPES_H
#define UNKNOWN_TYPES_H

#include "global.h"
#include "types.h"

EXTERN_C

struct UnkStruct_Func_2000C7C {
    STRUCT_PAD(0x0000, 0x0854);

    /* 0854 */ s8 * unk_0854;
    /* 0858 */ void * unk_0858;
    /* 085C */ void * unk_085C;
    /* 0860 */ void * unk_0860;

    STRUCT_PAD(0x0864, 0x086E);

    /* 086E */ u8 unk_086E;
    /* 086F */ u8 unk_086F;
    /* 0870 */ u8 unk_0870;
    /* 0871 */ u8 unk_0871;
    /* 0872 */ u8 unk_0872;
    /* 0873 */ u8 unk_0873;
    /* 0874 */ u8 unk_0874;

    STRUCT_PAD(0x0875, 0x0878);

    /* 0878 */ s8 unk_0878[0x400];
    /* 0C78 */ s8 unk_0C78[0x400];
    /* 1078 */ s8 unk_1078[0x80];
    /* 10F8 */ s8 unk_10F8[0x80];
};

struct UnkStruct_02197254_20_08 {
	s8 * unk_00;
	s8 * unk_04;
};

struct UnkStruct_02197254_20 {
	STRUCT_PAD(0x00, 0x08);

	struct UnkStruct_02197254_20_08 unk_08[0x10]; // amt idk
};

struct UnkStruct_02197254 {
	STRUCT_PAD(0x00, 0x20);

	/* 00 */ struct UnkStruct_02197254_20 * unk_20;
};

struct UnkStruct_Func_2000D2C {
    /* 00 */ u8 unk_00[0x42];
    /* 42 */ s8 unk_42;
    /* 43 */ s8 unk_43;

    STRUCT_PAD(0x44, 0x46);

    /* 46 */ u8 unk_46;
    /* 47 */ u8 unk_47;
    /* 48 */ s8 unk_48;
};

struct Unknown_func_01ffb934_ret
{
    STRUCT_PAD(0x00, 0x6C);
    /* 6C */ u32 unk_6c;
};

struct TerrainData
{
    char * unk_00;
    s8 * unk_04;
    s8 * unk_08;
    s8 * unk_10;
};

struct UnkStruct_021e3528
{
    s8 unk_00[0x2e];
    s8 unk_2e;
    u8 unk_2f;
};

struct Unknown_020efcc8_unk_a8_unk_00
{
    STRUCT_PAD(0x00, 0x28);
    void (*unk_28)(void *, u32, u32, u32);
    STRUCT_PAD(0x2C, 0x38);
    void (*unk_38)(void *, u32);
    void (*unk_3c)(void *, u32, u32, u32);
    STRUCT_PAD(0x40, 0x4C);
    void (*unk_4c)(void *, s32);
    BOOL (*unk_50)(void *);
    BOOL (*unk_54)(void *);
    BOOL (*unk_58)(void *);
    STRUCT_PAD(0x5C, 0x6c);
    void (*unk_6c)(void *, u32);
};

struct Unknown_020efcc8_unk_a8
{
    struct Unknown_020efcc8_unk_a8_unk_00 * unk_00;
    STRUCT_PAD(0x04, 0x08);
    u32 unk_08;
};

struct Unknown_020efcc8
{
    STRUCT_PAD(0x00, 0xA4);
    struct Unknown_020efcc8_unk_a8 * unk_a4;
    struct Unknown_020efcc8_unk_a8 * unk_a8;
    void * unk_ac;
    struct Unknown_020efcc8_unk_a8 * unk_b0;
};

struct UnkStruct_Func_02021410_Ret
{
    STRUCT_PAD(0x000, 0x756);
    u8 unk_756;
};

struct UnkStruct_Func_020302e0_Arg
{
    void * unk_00;
    STRUCT_PAD(0x04, 0x5C);
};

struct VmMap_Common
{
    STRUCT_PAD(0x00, 0x04);
    u16 unk_04;
    u8 unk_06;
    u8 unk_07;
};

struct MapLayer_10
{
    u32 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0a;
    s16 unk_0c;
    s16 unk_0e;
    s16 unk_10;
    s16 unk_12;
};

struct MapLayer_14
{
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    s8 unk_03;
    s8 unk_04;
    s8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
};

struct MapLayer
{
    /* 00 */ u8 kind;
    /* 01 */ u8 alpha;
    /* 02 */ s8 unk_02;
    /* 03 */ s8 unk_03;
    /* 04 */ struct MapTexture * pTexture;
    /* 08 */ void * gfxCommandList; // pointer to a list of packed Gfx FIFO commands
    /* 0C */ s32 gfxCmdSize; // size of gfxCommandList
    /* 10 */ struct MapLayer_10 * unk_10;
    /* 14 */ struct MapLayer_14 * unk_14;
};

struct MapTexture
{
    /* 00 */ s32 imgOffset; // offset of where the texture image starts in the *.ta file?
    /* 04 */ s32 imgSize; // size of image data
    /* 08 */ u32 imgDst;
    /* 0C */ s32 palOffset; // offset of palette data
    /* 10 */ s32 palSize; // size of palette data
    /* 14 */ u32 palDst;
    /* 18 */ u16 * unk_18; // pointer to ?
    /* 1C */ s16 unk_1c; // width?
    /* 1E */ s16 unk_1e; // height?
    /* 20 */ u8 unk_20;
    /* 21 */ u8 unk_21;
    /* 22 */ u8 unk_22;
    /* 23 */ u8 unk_23;
    /* 24 */ u8 unk_24;
    /* 25 */ u8 unk_25;
    /* 26 */ u16 unk_26;
};

struct MapFile
{
    void * unk_00;
    /* 04 */ char * taFileName; // pointer to "*.ta" string
    /* 08 */ void * taFileData;
    /* 0C */ s8 tileWidth;
    /* 0D */ s8 tileHeight;
    /* 0E */ u8 layerCount;
    /* 0F */ u8 textureCount;
    /* 10 */ u8 * unk_10;
    /* 14 */ u8 * unk_14;
    /* 18 */ struct MapLayer * pLayers;
    /* 1C */ struct MapTexture * pTextures;
    u8 unk_20;
    u8 unk_21;
};

// Overlay 000:

struct UnkStruct_021e3340
{
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    STRUCT_PAD(0x03, 0x06);
    u8 unk_06;
    u8 unk_07;
};

struct UnkStruct_021e3508
{
    void * unk_00;
    u32 unk_04;
    void * unk_08;
    u32 unk_0c;
    void * unk_10;
    void * unk_14;
    u32 unk_18;
    u32 unk_1c;
};

// Overlay 002:

struct UnkStruct_021faf8c
{
    STRUCT_PAD(0x00, 0x08);
    u8 unk_08;
};

EXTERN_C_END

#endif // UNKNOWN_TYPES_H
