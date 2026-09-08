#ifndef DISPOSITION_HPP
#define DISPOSITION_HPP

#include "global.h"

#include "unit.hpp"

enum
{
    GROUP_FLAG_UNK_0 = (1 << 0),
    GROUP_FLAG_UNK_1 = (1 << 1),
    GROUP_FLAG_UNK_2 = (1 << 2),
    GROUP_FLAG_UNK_3 = (1 << 3),
};

enum
{
    SPAWN_FLAG_UNK_0 = (1 << 0),
    SPAWN_FLAG_UNK_1 = (1 << 1),
    SPAWN_FLAG_UNK_2 = (1 << 2),
    SPAWN_FLAG_UNK_3 = (1 << 3),
    SPAWN_FLAG_UNK_4 = (1 << 4),
    SPAWN_FLAG_BOSS = (1 << 5),
    SPAWN_FLAG_NO_MOVE = (1 << 6),
    SPAWN_FLAG_UNK_7 = (1 << 7),
};

enum
{
    SPAWN_STATE_UNK_0 = (1 << 0),
    SPAWN_STATE_UNK_1 = (1 << 1),
    SPAWN_STATE_UNK_2 = (1 << 2),
    SPAWN_STATE_UNK_3 = (1 << 3),
    SPAWN_STATE_UNK_4 = (1 << 4),
};

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

    void _021d9adc(struct JobData * job);
    void _021d9bb0(struct JobData * job, s32 x, s32 y, s32 flags);
    void _021d9c94(Unit * unit);
    void _021d9ca8(Unit * unit, s32 x, s32 y);

    inline s32 GetPid(void)
    {
        return this->pid;
    }
};

struct DisposGroup
{
    /* 00 */ char * label;
    /* 04 */ struct Spawn * spawns;
    /* 08 */ s32 count;
};

#endif // DISPOSITION_HPP