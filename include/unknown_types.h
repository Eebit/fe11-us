#ifndef UNKNOWN_TYPES_H
#define UNKNOWN_TYPES_H

#include "global.h"
#include "types.h"

EXTERN_C

struct Unknown_027e1268_unk_00 {
    STRUCT_PAD(0x00, 0x12);
    u16 unk_12_0 : 1;
    u16 unk_12_1 : 1;
    u16 unk_12_2 : 1;
    u16 unk_12_3 : 1;
    u16 unk_12_4 : 1;
    u16 unk_12_5 : 1;
    u16 unk_12_67 : 2;

    u16 unk_12_8 : 1;
    u16 unk_12_9 : 1;
    u16 unk_12_A : 1;
    u16 unk_12_B : 1;
    u16 unk_12_C : 1;
    u16 unk_12_D : 1;
    STRUCT_PAD(0x14, 0x51);
    u8 unk_51;
    u8 unk_52;
};

struct Unknown_027e1268
{
    struct Unknown_027e1268_unk_00 * volatile unk_00;
    STRUCT_PAD(0x04, 0x0C);
    u32 unk_0c[1];
    STRUCT_PAD(0x10, 0x20);
    u32 unk_20[1];
    STRUCT_PAD(0x24, 0x3E);
    u8 unk_3e;
};

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

struct UnkStruct_021E3328_00_14
{
    STRUCT_PAD(0x00, 0x27);
    u8 unk_27;
};

struct UnkStruct_021E3328_00
{
    STRUCT_PAD(0x00, 0x14);
    struct UnkStruct_021E3328_00_14 * unk_14;
    u8 unk_18;
};

struct UnkStruct_021E3328_00_04_04
{
    STRUCT_PAD(0x00, 0x54);
    u16 unk_54;
    STRUCT_PAD(0x56, 0x5f);
    s8 unk_5f;
    s8 unk_60;
    u8 unk_61;
};

struct UnkStruct_021E3328_00_04
{
    /* 00 */ struct Unit * unk_00;
    struct UnkStruct_021E3328_00_04_04 * unk_04;
    u32 unk_08;
};

struct UnkStruct_021E3328_0c
{
// +0x10 contains last touch coords
// +0x14 contains current touch coords
// +0x18 contains key handlers
    STRUCT_PAD(0x00, 0x1C);
    u16 unk_1c;
    STRUCT_PAD(0x1E, 0x20);
    u8 unk_20;
    u8 unk_21_0 : 2;
    u8 unk_21_2 : 1;
    u8 unk_21_3 : 1;
    u8 unk_21_4 : 2;
    u8 unk_21_6 : 1;
    u8 unk_21_7 : 1;
    u8 unk_21_8 : 1;
};

struct UnkStruct_021E3328_10
{
    u8 unk_00[2];
    u8 unk_02[2];
    STRUCT_PAD(0x04, 0x08); // shorts, cursor real pos?
    u8 unk_08; // map x?
    u8 unk_09; // map y?
    u8 unk_0a;
    u8 unk_0b;
};

struct UnkStruct_021E3328_14_04
{
    STRUCT_PAD(0x00, 0x10);
    u8 unk_10;
    STRUCT_PAD(0x11, 0x14);
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    STRUCT_PAD(0x17, 0x19);
    u8 unk_19;
};

struct UnkStruct_021E3328_14
{
    void * unk_00;
    struct UnkStruct_021E3328_14_04 * unk_04;
    STRUCT_PAD(0x08, 0x27);
    u8 unk_27;
};

struct UnkStruct_021E3328 {
    /* 00 */ struct UnkStruct_021E3328_00 * unk_00;
    /* 04 */ struct UnkStruct_021E3328_00_04 * unk_04;
    /* 08 */ struct UnkStruct_Func_2000C7C * unk_08;
    struct UnkStruct_021E3328_0c * unk_0c;
    struct UnkStruct_021E3328_10 * unk_10;
    struct UnkStruct_021E3328_14 * unk_14;
    STRUCT_PAD(0x18, 0x20);

    /* 20 */ u16 unk_20;
    /* 22 */ u16 unk_22;
    /* 24 */ u8 unk_24;
    /* 25 */ u8 unk_25;
    /* 26 */ u8 unk_26;
    /* 27 */ u8 unk_27;
    /* 28 */ u8 unk_28[0x80]; // idk

	STRUCT_PAD(0xA8, 0x828);

	/* 0828 */ u8 * unk_828; // idk
    u8 * unk_82c;
    STRUCT_PAD(0x830, 0xD30);
    u8 unk_d30[0x80];
    u8 unk_db0[0x80];
};

struct UnkStruct_021E3324_00
{
    /* 00 */ u8 phase;
    /* 01 */ u8 unk_01;
    /* 02 */ u8 unk_02;
    /* 03 */ u8 unk_03;
    /* 04 */ u16 turn;
    /* 06 */ u16 unk_06;
    /* 08 */ u32 unk_08;
    /* 0C */ u32 unk_0c;
    /* 10 */ u32 unk_10;
    /* 14 */ u8 unk_14;
    /* 15 */ u8 unk_15;
    /* 16 */ u8 unk_16;
    /* 17 */ u8 unk_17;
    /* 18 */ u8 unk_18[4];
    /* 1C */ u8 unk_1c;
};

struct UnkStruct_021E3324
{
    struct UnkStruct_021E3324_00 * unk_00;
    struct UnkStruct_021E3324_04 * unk_04;
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

// FE11 Database, in RAM
struct Unknown_02197254
{
    void * unk_00;
    void * unk_04;
    /* 08 */ struct PersonData * pPerson;
    /* 0C */ struct JobData * pJob;
    /* 10 */ struct ItemData * pItem;
    STRUCT_PAD(0x14, 0x20);
    /* 20 */ struct TerrainData * pTerrain;
    STRUCT_PAD(0x24, 0x2C);
    /* 2C */ u8 * pWeaponLevel;
    STRUCT_PAD(0x30, 0x48);
    /* 48 */ struct DBFE11Footer * pDBFE11Footer;
};

struct UnkStruct_021e3528
{
    s8 unk_00[0x2e];
    s8 unk_2e;
    u8 unk_2f;
};

struct UnkStruct_021974fc
{
    struct Unit * unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8 unk_10;
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

struct UnkStruct_02196f18
{
    u32 unk_00;
};

struct UnkStruct_020e3ca0
{
    STRUCT_PAD(0x00, 0x24);
};

struct UnkStruct_02196f1c
{
    STRUCT_PAD(0x00, 0x09);
    u8 unk_09;
};

struct UnkStruct_02196f10
{
    u32 unk_00;
    s8 unk_04;
    u8 unk_05;
    u8 unk_06;
    s8 unk_07;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0a;
    u8 unk_0b;
    u32 unk_0c;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    STRUCT_PAD(0x13, 0x17);
    u8 unk_17;
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

struct UnkStruct_02196f0c
{
    struct UnkStruct_02196f0c_00 * unk_00;
    struct UnkStruct_02196f0c_04 * unk_04;
    struct UnkStruct_02196f0c_08 * unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
};

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
};

struct UnkStruct_02196f24
{
    STRUCT_PAD(0x00, 0x03);
    u8 unk_03;
    STRUCT_PAD(0x04, 0x07);
    u8 unk_07;
    STRUCT_PAD(0x08, 0x10);
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
