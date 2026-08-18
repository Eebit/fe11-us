#ifndef DISPOSITION_HPP
#define DISPOSITION_HPP

#include "global.h"

struct SpawnItem
{
    /* 00 */ u8 unk_00; // id
    /* 01 */ u8 unk_01; // flags, &1 is droppable
};

struct Spawn
{
    /* 00 */ u16 pid;
    /* 02 */ u16 jid;
    /* 04 */ s8 xLoad;
    /* 05 */ s8 yLoad;
    /* 06 */ s8 xFinal;
    /* 07 */ s8 yFinal;
    /* 08 */ u8 faction;
    /* 09 */ u8 unk_09;
    /* 0A */ u8 startingLevel;
    /* 0B */ u8 unk_0b;
    /* 0C */ s32 unk_0c;
    /* 10 */ struct SpawnItem unk_10[5];
    /* 1A */ STRUCT_PAD(0x1A, 0x1C);
    /* 1C */ s8 unk_1c[8];
    /* 24 */ u16 flags;
    /* 26 */ u16 unk_26;
    /* 28 */ s32 unk_28[4]; // AI pointers
    /* 38 */ s32 unk_38[4];
    /* 48 */ u8 unk_48;
    /* 49 */ u8 unk_49;
    /* 4A */ u16 unk_4a;
    /* 4C */ u8 unk_4c;
    /* 4D */ u8 unk_4d;
    /* 4E */ STRUCT_PAD(0x4e, 0x50);

    void func_ov000_021d9adc(struct JobData * job);
    void func_ov000_021d9bb0(struct JobData * job, s32 x, s32 y, s32 flags);
    void func_ov000_021d9c94(struct Unit * unit);
    void func_ov000_021d9ca8(struct Unit * unit, s8 x, s8 y);
};

struct DisposGroup
{
    /* 00 */ char * label;
    /* 04 */ struct Spawn * spawns;
    /* 08 */ s32 count;
};

#endif // DISPOSITION_HPP