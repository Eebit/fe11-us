#ifndef UNIT_HPP
#define UNIT_HPP

#include "global.h"
#include "save.hpp"

EXTERN_C

class Unit;

struct PersonData
{
    char * unk_00; // pid string
    char * unk_04; // fid string
    char * unk_08;
    /* 0C */ s8 bases[8];
    s8 unk_14[8]; // growths
    /* 1C */ u8 enemyGrowths[8];
    u32 unk_24; // wlevels?
    STRUCT_PAD(0x28, 0x2C);
    u8 unk_2c[4]; // weapon locks?
    STRUCT_PAD(0x31, 0x50);
};

struct JobData
{
    char * unk_00; // jid string
    char * unk_04; // mjid string
    /* 08 */ s8 bases[8];
    s8 unk_10[8]; // growths
    u8 unk_18[8]; // enemy growths
    /* 20 */ s8 caps[8];
    u8 unk_28;
    /* 29 */ u8 mov;
    u8 unk_2a;
    u8 unk_2b;
    u8 weaponLevels[8];
    u8 unk_34; // reclass set
    s8 unk_35; // reclass line
    /* 36 */ u16 unitType;
    u32 attributes;
    STRUCT_PAD(0x3C, 0x40); // promoted from job
    /* 40 */ struct JobData * pPromoteJob; // promoted to job
    STRUCT_PAD(0x44, 0x48); // "MSJI" -> used for job intro
    char * unk_48; // "FID_P" -> generic portrait?
    u8 unk_4c; // moving map sprite speed?
    STRUCT_PAD(0x4D, 0x54);
    s8 unk_54; // moving map sprite base Y position?
    STRUCT_PAD(0x55, 0x5C);
};

struct ItemData
{
    /* 00 */ char * id; // iid string
    /* 04 */ char * pName; // miid string
    /* 08 */ char * pDescription; // mih string
    /* 0C */ u16 weaponIcon;
    /* 0E */ u16 price;
    /* 10 */ u8 type;
    /* 11 */ u8 unk_11;
    /* 12 */ u8 wpnLevel;
    /* 13 */ u8 wpnExp;
    /* 14 */ u8 uses;
    /* 15 */ u8 might;
    /* 16 */ u8 hit;
    /* 17 */ u8 critical;
    /* 18 */ u8 weight;
    /* 19 */ u8 minRange;
    /* 1A */ u8 maxRange;
    u8 unk_1b;
    s8 unk_1c[8];
    u64 attributes;
    STRUCT_PAD(0x2c, 0x3A);
    u8 unk_3a; // item difficulty adjustment
    u8 unk_3b;
};

struct Unit_unk_30
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
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

EXTERN_C_END

#endif // UNIT_HPP