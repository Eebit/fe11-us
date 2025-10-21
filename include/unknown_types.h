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
    s8 * unk_00;
    s8 * unk_04;
    s8 * unk_08;
    s8 * unk_10;
};

struct DBFE11Footer
{
    u32 pidTableLength;
    u32 jidTableLength;
    u32 iidTableLength;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
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

struct UnkStruct_02196f0c_00
{
    STRUCT_PAD(0x00, 0x0A);
    s8 unk_0a;
    STRUCT_PAD(0x0B, 0x18);
    u8 unk_18[2];
};

struct UnkStruct_02196f0c_04_00
{
    void (*unk_00)(void *, s32);
    void (*unk_04)(void *, char *);
};

struct UnkStruct_02196f0c_04
{
    struct UnkStruct_02196f0c_04_00 * unk_00;
    char ** unk_04;
    u8 * unk_08;
    u32 unk_0c;
};

struct UnkStruct_02196f0c_08
{
    struct UnkStruct_02196f0c_04_00 * unk_00;
    char ** unk_04;
    s32 * unk_08;
    u32 unk_0c;
};

struct UnkStruct_020ca61c
{
    u16 unk_00;
    STRUCT_PAD(0x02, 0x04);
    u16 unk_04;
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

struct MapData
{
    /* 00 */ STRUCT_PAD(0x00, 0x0C);
    /* 0C */ s8 unk_0c;
    /* 0D */ s8 unk_0d;
    /* 0E */ STRUCT_PAD(0x0E, 0x10);
    /* 10 */ u8 * unk_10;
    /* 14 */ u8 * unk_14;
};

// Overlay 000:

struct UnkStruct_021e3340
{
    STRUCT_PAD(0x00, 0x06);
    u8 unk_06;
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
