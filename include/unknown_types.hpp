#ifndef UNKNOWN_TYPES_HPP
#define UNKNOWN_TYPES_HPP

#include "global.h"

#include "database.hpp"
#include "map.hpp"
#include "state_manager.hpp"
#include "unit.hpp"

enum
{
    GAME_STATE_UNK_0 = (1 << 0),
    GAME_STATE_UNK_1 = (1 << 1),
    GAME_STATE_UNK_2 = (1 << 2),
    GAME_STATE_UNK_3 = (1 << 3),
    GAME_STATE_UNK_4 = (1 << 4), // & 0x10 -> in prep
    GAME_STATE_UNK_5 = (1 << 5), // & 0x20 -> in multiplayer
    GAME_STATE_UNK_6 = (1 << 6), // in prep???
    GAME_STATE_UNK_7 = (1 << 7),
    GAME_STATE_UNK_8 = (1 << 8),
    GAME_STATE_UNK_9 = (1 << 9),
    GAME_STATE_UNK_10 = (1 << 10),
    GAME_STATE_UNK_11 = (1 << 11),
    GAME_STATE_UNK_12 = (1 << 12),
    GAME_STATE_UNK_13 = (1 << 13),
    GAME_STATE_SUPPLY_OFF = (1 << 14), // Set by event function "TransporterOff"
    GAME_STATE_UNK_15 = (1 << 15),
    GAME_STATE_UNK_16 = (1 << 16),
    GAME_STATE_UNK_17 = (1 << 17),
    GAME_STATE_UNK_18 = (1 << 18),
    GAME_STATE_UNK_19 = (1 << 19),
    GAME_STATE_UNK_20 = (1 << 20), // possibly "has fought medius"
    GAME_STATE_UNK_21 = (1 << 21),
    GAME_STATE_UNK_22 = (1 << 22),
    GAME_STATE_UNK_23 = (1 << 23),
    GAME_STATE_UNK_24 = (1 << 24),
    GAME_STATE_UNK_25 = (1 << 25),
};

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

enum
{
    WIRELESS_MODE_LOCAL = 0,
    WIRELESS_MODE_WFC_PLAY_ANYONE = 1,
    WIRELESS_MODE_WFC_PLAY_FRIEND = 2,
    WIRELESS_MODE_PRACTICE = 3,
};

struct WirelessSettings_00_348
{
    /* 00 */ STRUCT_PAD(0x00, 0x20);
    /* 20 */ u16 unk_20;
    /* 22 */ STRUCT_PAD(0x22, 0x24);
    /* 24 */ s8 unk_24;
    /* 25 */ s8 unk_25;
    /* 26 */ s8 unk_26;
    /* 27 */ s8 unk_27;
};

struct WirelessSettings_00
{
    /* 000 */ Unit unk_000[5];
    /* 348 */ struct WirelessSettings_00_348 unk_348[0x19];
    /* 730 */ u8 unk_730[0x24];
    /* 754 */ u8 unk_754;
    /* 755 */ u8 unk_755;
    /* 756 */ u8 unk_756;
    /* 757 */ u8 unk_757;
};

class WirelessSettings
{
public:
    /* 00 */ WirelessSettings_00 * unk_00;
    /* 04 */ s8 mode;
    /* 05 */ u8 unk_05;
    /* 06 */ u8 unk_06; // faction?
    /* 07 */ s8 unk_07;
    /* 08 */ u8 unk_08;
    /* 09 */ u8 fogActive;
    /* 0A */ u8 turnLimit;
    /* 0B */ u8 unk_0b;
    /* 0C */ u32 timeLimit; // in seconds
    /* 10 */ u8 cardsAllowed;
    /* 11 */ u8 unk_11;
    /* 12 */ u8 unk_12;
    /* 13 */ STRUCT_PAD(0x13, 0x17);
    /* 17 */ u8 unk_17;

    WirelessSettings()
    {
        this->unk_00 = NULL;
        this->unk_06 = 0;
    }

    inline u8 CheckUnk00(void)
    {
        return (this->unk_00 != NULL) & 0xFF;
    }

    inline BOOL IsWifiPlayAnyoneMode(void)
    {
        return this->mode == WIRELESS_MODE_WFC_PLAY_ANYONE;
    }

    inline BOOL IsPracticeMode(void)
    {
        return this->mode == WIRELESS_MODE_PRACTICE;
    }

    inline BOOL _02022b50(void)
    {
        return this->unk_07 == 0;
    }

    inline BOOL _02022b10(void)
    {
        return this->unk_07 == 2;
    }
};

struct UnkStruct_02196f24
{
    /* 00 */ u8 gameSpeed;
    /* 01 */ u8 messageSpeed;
    /* 02 */ u8 autoCursorEnabled;
    /* 03 */ u8 unk_03;
    /* 04 */ u8 controlSettings;
    /* 05 */ u8 unk_05;
    /* 06 */ u8 animations;
    /* 07 */ u8 enableBgm;
    /* 08 */ u8 enableSoundEffects;
    /* 09 */ u8 gridThickness;
    /* 0A */ s8 mapBrightness;
    /* 0B */ u8 soundChannels;
    /* 0C */ u8 enableTutorials;
    /* 0D */ u8 unk_0d;
    /* 0E */ u8 unk_0e;
    STRUCT_PAD(0x0F, 0x10);
};

struct UnkStruct_02196f20
{
    STRUCT_PAD(0x000, 0x180);
    /* 180 */ FlagManager * flagMgr;
    s32 unk_184;
    u32 unk_188;
    u32 unk_18c;
    s32 unk_190; // gold
    u32 unk_194;
    u8 unk_198;
    u8 unk_199;
    u8 unk_19a;
    u8 unk_19b;
    s8 unk_19c;
    s8 unk_19d;
    STRUCT_PAD(0x19E, 0x1A1);
    u8 unk_1a1;
    STRUCT_PAD(0x1A2, 0x1A4);
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
    u8 unk_02;
    u8 unk_03;
    s8 unk_04;
    s8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
    STRUCT_PAD(0x0A, 0x0C);

    inline BOOL Check_02()
    {
        return this->unk_02 != -1;
    }
};

#endif // UNKNOWN_TYPES_HPP
