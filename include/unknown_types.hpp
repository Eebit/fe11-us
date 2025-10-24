#ifndef UNKNOWN_TYPES_HPP
#define UNKNOWN_TYPES_HPP

#include "global.h"

#include "unit.h"

#include "map.hpp"
#include "state_manager.hpp"

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
    STRUCT_PAD(0x30, 0x38);
    /* 38 */ struct Unit_unk_a4 ** unk_38;
    STRUCT_PAD(0x3C, 0x48);
    /* 48 */ struct DBFE11Footer * pDBFE11Footer;
};

struct UnkStruct_02196f0c
{
    /* 00 */ struct UnkStruct_02196f0c_00 * unk_00;
    /* 04 */ FlagManager * flagMgr;
    /* 08 */ ValueManager * valueMgr;
    /* 0C */ u32 state;
    /* 10 */ u32 unk_10;
    /* 14 */ u32 unk_14;
};

struct UnkStruct_021974fc
{
    struct Unit * unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8 unk_10;
    STRUCT_PAD(0x11, 0x1C);
};

struct UnkStruct_02196f18
{
    FlagManager * unk_000;
    STRUCT_PAD(0x004, 0x600);
};

struct UnkStruct_020e3ca0
{
    STRUCT_PAD(0x00, 0x14);
};

class UnkStruct_02196f10
{
public:
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

    UnkStruct_02196f10()
    {
        this->unk_00 = 0;
        this->unk_06 = 0;
    }
};

struct UnkStruct_02196f24
{
    STRUCT_PAD(0x00, 0x03);
    u8 unk_03;
    STRUCT_PAD(0x04, 0x07);
    u8 unk_07;
    STRUCT_PAD(0x08, 0x10);
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
    STRUCT_PAD(0x19D, 0x1A4);
};

struct UnkStruct_02196f1c
{
    STRUCT_PAD(0x00, 0x09);
    u8 unk_09;
    STRUCT_PAD(0x0A, 0x10);
};

#endif // UNKNOWN_TYPES_HPP
