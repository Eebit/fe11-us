#include "global.h"

struct UnkStruct_02196e04
{
    s32 unk_00;
    u32 unk_04;
};

extern struct UnkStruct_02196e04 data_02196e04;

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

EC void func_0201ff20(void)
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

        data_02196e04.unk_04 = state;

        return;
    }

    data_02196e04.unk_04 = 0x12345678;

    return;
}

EC void func_0201ffb0(u32 state)
{
    data_02196e04.unk_04 = state;
    return;
}

EC u32 func_0201ffc0(void)
{
    return data_02196e04.unk_04;
}

EC u32 func_0201ffd0(void)
{
    u32 rand = data_02196e04.unk_04 ^ (0x65AC9365 >> (data_02196e04.unk_04 & 3));
    data_02196e04.unk_04 = (rand >> 4) ^ (rand >> 3) ^ (rand << 3) ^ (rand << 4) ^ rand;
    return data_02196e04.unk_04 & 0x7FFFFFFF;
}

EC s32 IntSys_Mod(s32, s32);

EC s32 RollRN(s32 param_1, s32 param_2)
{
    return param_1 + IntSys_Mod(func_0201ffd0() & 0x7fffffff, (param_2 - param_1) + 1);
}
