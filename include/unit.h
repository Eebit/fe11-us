#ifndef UNIT_H
#define UNIT_H

#include "global.h"

EXTERN_C

struct PersonData
{
    char * unk_00;
    STRUCT_PAD(0x04, 0x0C);
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
    STRUCT_PAD(0x00, 0x08);
    /* 08 */ s8 bases[8];
    s8 unk_10[8];
    u8 unk_18[8];
    /* 20 */ s8 caps[8];
    u8 unk_28;
    /* 29 */ u8 mov;
    u8 unk_2a;
    u8 unk_2b;
    u8 weaponLevels[5];
    STRUCT_PAD(0x31, 0x36);
    /* 36 */ u16 unitType;
    u32 attributes;
    STRUCT_PAD(0x3C, 0x40);
    /* 40 */ struct JobData * pPromoteJob;
    STRUCT_PAD(0x44, 0x5C);
};

struct ItemData
{
    /* 00 */ char * id;
    /* 04 */ char * pName;
    /* 08 */ char * pDescription;
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

struct Item
{
    u16 id;
    u8 unk_02;
    u8 unk_03;
};

struct Unit_unk_4c
{
    STRUCT_PAD(0x00, 0x08);
    s32 unk_08;
};

struct Unit
{
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
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
    STRUCT_PAD(0x36, 0x3C);
    /* 3C */ struct Unit * unk_3c;
    /* 40 */ struct PersonData * pPersonData;
    /* 44 */ struct JobData * pJobData;
    STRUCT_PAD(0x48, 0x4C);
    struct Unit_unk_4c * unk_4c;
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
    u32 unk_a4;
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

#endif // UNIT_H