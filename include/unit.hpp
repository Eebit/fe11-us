#ifndef UNIT_HPP
#define UNIT_HPP

#include "global.h"
#include "save.hpp"

EXTERN_C

#define UNIT_ITEM_COUNT 5

enum
{
    UNIT_STAT_HP = 0,
    UNIT_STAT_STR = 1,
    UNIT_STAT_MAG = 2,
    UNIT_STAT_SKL = 3,
    UNIT_STAT_SPD = 4,
    UNIT_STAT_LUK = 5,
    UNIT_STAT_DEF = 6,
    UNIT_STAT_RES = 7,

    UNIT_STAT_COUNT = 8,
};

enum
{
    CA_FEMALE = (1 << 0),
    CA_UNK_1 = (1 << 1),
    CA_LORD = (1 << 2),
    CA_PRINCESS = (1 << 3), // Caeda, Maria, Minerva, Elise
    CA_UNK_4 = (1 << 4), // Medius?
    CA_UNK_5 = (1 << 5), // Caeda?
    CA_UNK_6 = (1 << 6), // Lena?
    CA_UNK_7 = (1 << 7), // Merric; used for Excalibur Weapon Level check
    CA_UNK_8 = (1 << 8), // Linde; used for Aura Weapon Level check
    CA_UNK_9 = (1 << 9), // Tiki, Nagi
    CA_UNK_10 = (1 << 10), // Thief attribute? Something for unlocking
    CA_PROMOTED = (1 << 11),
    CA_UNK_12 = (1 << 12),

    CA_FREELANCER = (1 << 15),
    CA_UNK_16 = (1 << 16), // Sniper hit rate boost
    CA_UNK_17 = (1 << 17), // Swordmaster hit rate boost
    CA_UNK_18 = (1 << 18), // Sniper crit boost
    CA_UNK_19 = (1 << 19), // Berserker crit boost
    CA_UNK_20 = (1 << 20), // Thief ?
    CA_CANNOT_ATTACK = (1 << 21), // Curate/Sister
    CA_UNK_22 = (1 << 22), // Ballistician, dragon classes
    CA_UNK_23 = (1 << 23),
    CA_UNK_24 = (1 << 24), // Manakete, dragon classes
    CA_TRIATTACK = (1 << 25), // Whitewing sisters
    CA_UNK_26 = (1 << 26),
    CA_UNK_27 = (1 << 27),
    CA_UNK_28 = (1 << 28), // ? Medius, all arena opponents
    CA_UNK_29 = (1 << 29),
};

class Unit;
struct PersonData;

struct SupportData
{
    /* 00 */ struct PersonData * supporter;
    /* 04 */ u8 startingPoints;
    /* 05 */ u8 pointsC;
    /* 06 */ u8 pointsB;
    /* 07 */ u8 pointsA;
};

struct PersonData
{
    /* 00 */ char * pid; // Identifier in database
    /* 04 */ char * fid; // Identifier in face.bin
    /* 08 */ char * mpid; // "Message PID" - string for character; used for generics
    /* 0C */ s8 bases[8];
    /* 14 */ s8 growths[8];
    /* 1C */ u8 weaponLevels[8];
    /* 24 */ u32 attributes;
    STRUCT_PAD(0x28, 0x2C);
    u8 unk_2c[4]; // weapon locks?
    STRUCT_PAD(0x31, 0x50);
};

struct JobData
{
    /* 00 */ char * jid; // Identifier in database
    /* 04 */ char * mjid; // "Message JID" - string for class name
    /* 08 */ s8 bases[8];
    /* 10 */ s8 unk_10[8]; // growths
    /* 18 */ u8 unk_18[8]; // enemy growths
    /* 20 */ s8 caps[8];
    /* 28 */ u8 unk_28;
    /* 29 */ u8 mov;
    /* 2A */ u8 unk_2a;
    /* 2B */ u8 unk_2b;
    /* 2C */ u8 weaponLevels[8];
    /* 34 */ u8 unk_34; // reclass set
    /* 35 */ s8 unk_35; // reclass line
    /* 36 */ u16 unitType;
    /* 38 */ u32 attributes;
    /* 3C */ struct JobData * pPromoteFromJob;
    /* 40 */ struct JobData * pPromoteToJob;
    /* 44 */ char * msji; // "Message String Job Intro" - string for description on class reel
    /* 48 */ char * unk_48; // "FID_P" -> generic portrait?
    /* 4C */ u8 unk_4c; // moving map sprite speed?
    STRUCT_PAD(0x4D, 0x54);
    /* 54 */ s8 unk_54; // moving map sprite base Y position?
    STRUCT_PAD(0x55, 0x5C);
};

struct ItemData
{
    /* 00 */ char * iid; // Identifier in database
    /* 04 */ char * miid; // "Message IID" - string for item name
    /* 08 */ char * mih; // "Message Info Help" - string for description
    /* 0C */ u16 weaponIcon;
    /* 0E */ u16 price;
    /* 10 */ u8 type;
    /* 11 */ u8 effect;
    /* 12 */ u8 wpnLevel;
    /* 13 */ u8 wpnExp;
    /* 14 */ u8 uses;
    /* 15 */ u8 might;
    /* 16 */ u8 hit;
    /* 17 */ u8 critical;
    /* 18 */ u8 weight;
    /* 19 */ u8 minRange;
    /* 1A */ u8 maxRange;
    /* 1B */ u8 movBoost;
    /* 1C */ s8 statBoost[8];
    /* 24 */ u64 attributes;
    STRUCT_PAD(0x2C, 0x30);
    /* 30 */ char * mapAnimFile;
    /* 34 */ char * battleAnimFile;
    STRUCT_PAD(0x38, 0x3A);
    /* 3A */ u8 unk_3a; // item difficulty adjustment
    /* 3B */ u8 unk_3b;
};

struct Unit_unk_30
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
};

enum
{
    ITEM_FLAG_EQUIPPED = (1 << 4),
};

class Item
{
public:
    /* 00 */ u16 id;
    /* 02 */ u8 uses;
    /* 03 */ u8 flags;

    Item() {};

    struct ItemData * GetData(void);

    void InitFromItemData(ItemData *);
    void InitFromIidStr(char *);
    void InitFromIid(s32);
    void Clear(void);

    Item * operator=(Item *);
    BOOL operator==(Item *);

    BOOL func_0203e09c(Unit *);
    BOOL func_0203e0f8(Unit *);

    void Save(SaveBuffer *);
    void Load(SaveBuffer *, s32);
};

class Force
{
public:
    /* 00 */ struct Unit * head;
    /* 04 */ struct Unit * tail;
    /* 08 */ s32 id;

    Force() {};

    void Init(s32 factionId);
    void InsertHead(Unit * unit);
    void InsertTail(Unit * unit);
    void Remove(Unit * unit);
    s32 Count(void);

    static Force * Get(s32);

    void MoveAllUnitsTo(s32 dstFactionId, BOOL append);
    Unit * FindByPerson(struct PersonData *);
    Unit * FindByPid(s32 pid);
    Unit * func_02040d68(struct PersonData *);
    Unit * FindByPidStr(char * pidStr);
    Unit * FindByAttribute(u32 attr);
};

struct Unit_unk_a4
{
    char * unk_00;
    u16 unk_04;
};

class Unit
{
public:
    u16 unk_00;
    s8 unk_02;
    s8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u16 unk_0a;
    u8 unk_0c[4];
    s16 unk_10[0x10];
    /* 30 */ struct Unit_unk_30 unk_30;
    STRUCT_PAD(0x36, 0x38);
    /* 38 */ struct Unit * unk_38;
    /* 3C */ struct Unit * unk_3c;
    /* 40 */ struct PersonData * pPersonData;
    /* 44 */ struct JobData * pJobData;
    STRUCT_PAD(0x48, 0x4C);
    /* 4C */ Force * force;
    s8 unk_50[8];
    s16 unk_58[8];
    u8 unk_68;
    u8 unk_69;
    /* 6A */ u8 level;
    /* 6B */ u8 exp;
    /* 6C */ s8 hp;
    s8 unk_6d;
    /* 6E */ s8 xPos;
    /* 6F */ s8 yPos;
    /* 70 */ struct Item items[5];
    u8 unk_84[6];
    u8 unk_8a[5];
    /* 8F */ u8 alpha;
    u8 unk_90;
    u8 unk_91;
    u8 unk_92;
    u8 unk_93;
    u8 unk_94;
    u8 unk_95;
    u8 unk_96;
    u8 unk_97;
    /* 98 */ s32 state1;
    /* 9C */ s32 state2;
    /* A0 */ struct Unit * unk_a0;
    struct Unit_unk_a4 * unk_a4;

    Unit() {};

    inline void SetPos(s32 x, s32 y)
    {
        this->xPos = x;
        this->yPos = y;
    }

    inline void SetJob(struct JobData * job)
    {
        this->pJobData = job;
        this->state2 &= ~0x40000000;
    }
};

inline BOOL func_0203b714(struct Unit * unit, s32 state)
{
    return unit->state2 & state;
}

inline struct Unit * func_0203c378(struct Unit * unit)
{
    BOOL m = (unit->unk_a0 && func_0203b714(unit, 0x48000));

    return m ? func_0203c378(unit->unk_a0) : unit;
}

extern Unit * gUnitList;

inline Unit * GetUnit(s32 unitId)
{
    if (unitId != 0)
    {
        return gUnitList + unitId - 1;
    }
    else
    {
        return NULL;
    }
}

EXTERN_C_END

#endif // UNIT_HPP