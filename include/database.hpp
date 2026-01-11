#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "global.h"

struct MapData
{
    char * unk_00; // pointer to "bmap_###" or "arena_###" identifier
    char * unk_04; // pointer to MCT_### string id
    STRUCT_PAD(0x08, 0x0A);
    s8 unk_0a; // max allowed units?
    STRUCT_PAD(0x0B, 0x0C);
    u8 unk_0c[12]; // max allowed per class
    u8 unk_18[2]; // bgm indexes
};

struct UnkData
{
    char * unk_00;
    STRUCT_PAD(0x04, 0x09);
    u8 unk_09;
};

struct TerrainCostData
{
    s32 size;
    s8 * unk_04;
};

struct CharmData
{
    STRUCT_PAD(0x00, 0x04);
    char * unk_04;
};

struct DBFE11Footer
{
    s32 pidTableLength;
    s32 jidTableLength;
    s32 iidTableLength;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
};

class FE11Database
{
public:
    /* 00 */ void * unk_00;
    /* 04 */ void * unk_04;
    /* 08 */ struct PersonData * pPerson;
    /* 0C */ struct JobData * pJob;
    /* 10 */ struct ItemData * pItem;
    /* 14 */ void * unk_14;
    /* 18 */ void * unk_18;
    /* 1C */ void * unk_1c;
    /* 20 */ struct TerrainData * pTerrain;
    /* 24 */ void * unk_24;
    /* 28 */ void * unk_28;
    /* 2C */ u8 * pWeaponLevel;
    /* 30 */ void * unk_30;
    /* 34 */ void * unk_34;
    /* 38 */ struct Unit_unk_a4 * unk_38;
    /* 3C */ void * unk_3c;
    /* 40 */ void * unk_40;
    /* 44 */ void * unk_44;
    /* 48 */ struct DBFE11Footer * pDBFE11Footer;

    void Init(void);
};

extern struct FE11Database * gFE11Database;

EC s32 GetMapDBIndex(struct MapData * pMap);

#endif // DATABASE_HPP