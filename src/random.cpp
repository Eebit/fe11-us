#include "global.h"

struct RandomState
{
    /* 00 */ s32 unk_00; // unused??
    /* 04 */ u32 state;
};

extern struct RandomState gRandomSt;

struct UnkStruct_Func_020ac374
{
    /* 00 */ s32 unk_00;
    /* 04 */ s32 unk_04;
    /* 08 */ s32 unk_08;
    /* 0C */ s32 unk_0c;
};

struct UnkStruct_Func_020ac420
{
    /* 00 */ s32 unk_00;
    /* 04 */ s32 unk_04;
    /* 08 */ s32 unk_08;
};

EC s32 func_020ac374(struct UnkStruct_Func_020ac374 *);
EC s32 func_020ac420(struct UnkStruct_Func_020ac420 *);

EC void Random_Init(void)
{
    struct UnkStruct_Func_020ac374 a;
    struct UnkStruct_Func_020ac420 b;
    s32 state;

    if (func_020ac374(&a) == 0 && func_020ac420(&b) == 0)
    {
        state = a.unk_00 * 12 + a.unk_04;
        state = state * 30 + a.unk_08;
        state = state * 24 + b.unk_00;
        state = state * 60 + b.unk_04;
        state = state * 60 + b.unk_08;

        gRandomSt.state = state;

        return;
    }

    gRandomSt.state = 0x12345678;

    return;
}

EC void Random_SetState(u32 state)
{
    gRandomSt.state = state;
    return;
}

EC u32 Random_GetState(void)
{
    return gRandomSt.state;
}

EC u32 Random_Next(void)
{
    u32 rand = gRandomSt.state ^ (0x65AC9365 >> (gRandomSt.state & 3));
    gRandomSt.state = (rand >> 4) ^ (rand >> 3) ^ (rand << 3) ^ (rand << 4) ^ rand;
    return gRandomSt.state & 0x7FFFFFFF;
}

EC s32 IntSys_Mod(s32, s32);

EC s32 RollRN(s32 param_1, s32 param_2)
{
    return param_1 + IntSys_Mod(Random_Next() & 0x7fffffff, (param_2 - param_1) + 1);
}
