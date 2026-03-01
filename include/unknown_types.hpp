#ifndef UNKNOWN_TYPES_HPP
#define UNKNOWN_TYPES_HPP

#include "global.h"

#include "database.hpp"
#include "map.hpp"
#include "state_manager.hpp"
#include "unit.hpp"

struct UnkStruct_02196f0c
{
    /* 00 */ struct MapData * pCurrentMap;
    /* 04 */ FlagManager * flagMgr;
    /* 08 */ ValueManager * valueMgr;
    /* 0C */ u32 state;
    /* 10 */ u32 unk_10;
    /* 14 */ u32 unk_14;
};

struct UnkStruct_021974fc
{
    struct Unit * unk_00; // active unit
    u32 unk_04; // ??
    u32 unk_08; // terrain
    u32 unk_0c;
    u8 unk_10; // top screen hud mode (1 = stat screen; 2 = minimap)
    u8 unk_11;
    u8 unk_12;
    STRUCT_PAD(0x13, 0x1C);
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
    /* 04 */ u8 controlSettings;
    STRUCT_PAD(0x05, 0x07);
    /* 07 */ u8 enableBgm;
    /* 08 */ u8 enableSoundEffects;
    STRUCT_PAD(0x09, 0x0C);
    /* 0C */ u8 enableTutorials;
    /* 0D */ u8 unk_0d;
    STRUCT_PAD(0x0E, 0x10);
};

struct UnkStruct_02196f20
{
    STRUCT_PAD(0x000, 0x180);
    /* 180 */ FlagManager * flagMgr;
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
    s8 unk_19d;
    STRUCT_PAD(0x19E, 0x1A4);
};

struct UnkStruct_02196f1c
{
    STRUCT_PAD(0x00, 0x09);
    u8 unk_09;
    u8 unk_0a;
    u8 unk_0b;
    STRUCT_PAD(0x0C, 0x10);
};

class UnkStruct_021e3340
{
public:
    u8 unk_00;
    s8 unk_01;
    s8 unk_02;
    u8 unk_03;
    s8 unk_04;
    s8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;

    inline BOOL Check_02()
    {
        return this->unk_02 != -1;
    }
};

#endif // UNKNOWN_TYPES_HPP
