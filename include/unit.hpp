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

enum
{
    US_ACTED = (1 << 0),

    US_DEAD = (1 << 3),

    US_ITEMS_TO_CONVOY = (1 << 7),

    US_NOT_PRESENT = (1 << 12),
    US_DANGER_ZONE_ACTIVE = (1 << 13),

    US_HOVERED = (1 << 17),

    US_EVENT_DEAD = (1 << 29), // Died as a "decoy" for Marth
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
    /* 0C */ s8 bases[UNIT_STAT_COUNT];
    /* 14 */ s8 growths[UNIT_STAT_COUNT];
    /* 1C */ u8 weaponLevels[8];
    /* 24 */ u32 attributes;
    /* 28 */ struct SupportData supports[5];
};

struct JobData
{
    /* 00 */ char * jid; // Identifier in database
    /* 04 */ char * mjid; // "Message JID" - string for class name
    /* 08 */ s8 bases[UNIT_STAT_COUNT];
    /* 10 */ s8 growths[UNIT_STAT_COUNT];
    /* 18 */ u8 unk_18[UNIT_STAT_COUNT]; // enemy growths
    /* 20 */ s8 caps[UNIT_STAT_COUNT];
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
    /* 1C */ s8 statBoost[UNIT_STAT_COUNT];
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
    char * unk_08[0];
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
    /* 6D */ s8 mov;
    /* 6E */ s8 xPos;
    /* 6F */ s8 yPos;
    /* 70 */ struct Item items[UNIT_ITEM_COUNT];
    u8 unk_84[6];
    /* 8A */ u8 unk_8a[5]; // Support points?
    /* 8F */ u8 alpha;
    u8 unk_90;
    u8 unk_91; // pure water duration
    u8 unk_92; // torch duration
    u8 unk_93; // imitate duration
    u8 unk_94;
    u8 unk_95;
    u8 unk_96;
    u8 unk_97;
    /* 98 */ s32 state1;
    /* 9C */ s32 state2;
    /* A0 */ struct Unit * unk_a0;
    struct Unit_unk_a4 * unk_a4;

    Unit() {};

    void Init(void); // _ZN4Unit4InitEv
    Unit * Copy(Unit *); // _ZN4Unit4CopyEPS_
    void Save(struct SaveBuffer *); // _ZN4Unit4SaveEP10SaveBuffer
    void Load(struct SaveBuffer *, s32); // _ZN4Unit4LoadEP10SaveBufferl
    void _0203b720(struct SaveBuffer *); // _ZN4Unit9_0203b720EP10SaveBuffer
    BOOL _0203ba20(struct SaveBuffer *); // _ZN4Unit9_0203ba20EP10SaveBuffer
    void _0203bcf4(void); // _ZN4Unit9_0203bcf4Ev
    void _0203bd34(s32 forceId, BOOL append); // _ZN4Unit9_0203bd34Ell
    Unit * _0203bdd0(u8); // _ZN4Unit9_0203bdd0Eh
    void _0203be30(Unit *); // _ZN4Unit9_0203be30EPS_
    void _0203bf68(void); // _ZN4Unit9_0203bf68Ev
    void _0203c068(Unit *); // _ZN4Unit9_0203c068EPS_
    void _0203c19c(void); // _ZN4Unit9_0203c19cEv
    char * _0203c284(void); // _ZN4Unit9_0203c284Ev
    // func_0203c378
    s32 GetMaxHp(void); // _ZN4Unit8GetMaxHpEv
    s32 GetStr(ItemData * item, BOOL); // _ZN4Unit6GetStrEP8ItemDatal
    s32 GetMag(ItemData * item, BOOL); // _ZN4Unit6GetMagEP8ItemDatal
    s32 GetSkl(ItemData * item, BOOL); // _ZN4Unit6GetSklEP8ItemDatal
    s32 GetSpd(ItemData * item, BOOL); // _ZN4Unit6GetSpdEP8ItemDatal
    s32 GetLuk(ItemData * item, BOOL); // _ZN4Unit6GetLukEP8ItemDatal
    s32 GetDef(ItemData * item, BOOL); // _ZN4Unit6GetDefEP8ItemDatal
    s32 GetRes(ItemData * item, BOOL); // _ZN4Unit6GetResEP8ItemDatal
    s32 GetStat(u32 statIdx, ItemData * item, BOOL); // _ZN4Unit7GetStatEmP8ItemDatal
    BOOL _0203c73c(s32); // _ZN4Unit9_0203c73cEl
    u32 _0203c75c(void); // _ZN4Unit9_0203c75cEv
    s32 GetMov(void); // _ZN4Unit6GetMovEv
    s32 _0203c790(void); // _ZN4Unit9_0203c790Ev
    s32 _0203c7ac(u32); // _ZN4Unit9_0203c7acEm
    s32 _0203c7e4(u32); // _ZN4Unit9_0203c7e4Em
    s32 CheckAttribute(u32 attr); // _ZN4Unit14CheckAttributeEm
    BOOL _0203c834(ItemData * item, s32); // _ZN4Unit9_0203c834EP8ItemDatal
    BOOL _0203cb6c(s32 slot, s32); // _ZN4Unit9_0203cb6cEll
    s32 GetEquippedWeaponSlot(void); // _ZN4Unit21GetEquippedWeaponSlotEv
    u64 _0203cbc4(u64 mask); // _ZN4Unit9_0203cbc4Ey
    u64 _0203cc1c(u64 mask); // _ZN4Unit9_0203cc1cEy
    void _0203cc94(s32 slot, s32); // _ZN4Unit9_0203cc94Ell
    BOOL _0203cd30(s32); // _ZN4Unit9_0203cd30El
    void _0203cdf0(s32 slot); // _ZN4Unit9_0203cdf0El
    void _0203ce08(s32 slot, BOOL); // _ZN4Unit9_0203ce08Ell
    void _0203ce6c(void); // _ZN4Unit9_0203ce6cEv
    BOOL _0203ce9c(s32, u32); // _ZN4Unit9_0203ce9cElm
    BOOL _0203cef8(ItemData * item, u32); // _ZN4Unit9_0203cef8EP8ItemDatam
    BOOL _0203cf20(Item * item); // _ZN4Unit9_0203cf20EP4Item
    void _0203cf68(void); // _ZN4Unit9_0203cf68Ev
    s32 _0203cff4(void); // _ZN4Unit9_0203cff4Ev
    s32 _0203d01c(void); // _ZN4Unit9_0203d01cEv
    s32 _0203d094(void); // _ZN4Unit9_0203d094Ev
    s32 _0203d10c(void); // _ZN4Unit9_0203d10cEv
    BOOL _0203d184(void); // _ZN4Unit9_0203d184Ev
    BOOL _0203d1bc(void); // _ZN4Unit9_0203d1bcEv
    BOOL _0203d1f4(void); // _ZN4Unit9_0203d1f4Ev
    s32 ComputeMight(ItemData * item, BOOL); // _ZN4Unit12ComputeMightEP8ItemDatal
    s32 _0203d294(s32 slot, BOOL); // _ZN4Unit9_0203d294Ell
    s32 _0203d2e4(ItemData * item); // _ZN4Unit9_0203d2e4EP8ItemData
    s32 ComputeHitRate(ItemData * item, BOOL); // _ZN4Unit14ComputeHitRateEP8ItemDatal
    s32 _0203d40c(s32 slot, BOOL); // _ZN4Unit9_0203d40cEll
    s32 _0203d45c(ItemData * item); // _ZN4Unit9_0203d45cEP8ItemData
    s32 ComputeCritRate(ItemData * item); // _ZN4Unit15ComputeCritRateEP8ItemData
    s32 _0203d554(s32 slot); // _ZN4Unit9_0203d554El
    s32 ComputeAttackSpeed(ItemData * item); // _ZN4Unit18ComputeAttackSpeedEP8ItemData
    s32 ComputeAvoid(ItemData * item); // _ZN4Unit12ComputeAvoidEP8ItemData
    s32 _0203d618(s32 slot); // _ZN4Unit9_0203d618El
    s32 _0203d660(ItemData * item); // _ZN4Unit9_0203d660EP8ItemData
    s32 _0203d670(s32 exp); // _ZN4Unit9_0203d670El
    void _0203d6dc(void); // _ZN4Unit9_0203d6dcEv
    void _0203d840(struct JobData * job, BOOL); // _ZN4Unit9_0203d840EP7JobDatal
    void _0203d874(void); // _ZN4Unit9_0203d874Ev
    BOOL _0203dad4(Unit * other); // _ZN4Unit9_0203dad4EPS_
    s32 _0203db28(void); // _ZN4Unit9_0203db28Ev
    s32 _0203db50(void); // _ZN4Unit9_0203db50Ev
    void _0203db78(void); // _ZN4Unit9_0203db78Ev
    void _0203db94(s32); // _ZN4Unit9_0203db94El
    static s32 _0203dbc0(void); // _ZN4Unit9_0203dbc0Ev
    s32 _0203dbd4(BOOL useMag, BOOL useRes); // _ZN4Unit9_0203dbd4Ell
    void _0203dd48(void); // _ZN4Unit9_0203dd48Ev
    void _0203de10(void); // _ZN4Unit9_0203de10Ev
    void _0203df18(void); // _ZN4Unit9_0203df18Ev

    inline void SetPos(s32 x, s32 y)
    {
        this->xPos = x;
        this->yPos = y;
    }

    inline u32 GetPersonAttr(void)
    {
        return this->pPersonData->attributes;
    }

    inline u32 GetJobAttr(void)
    {
        return this->pJobData->attributes;
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