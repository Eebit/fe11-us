#ifndef MAP_OBJECT_HPP
#define MAP_OBJECT_HPP

#include "global.h"

struct UnkStruct_Func_ov000_021d4968_Ret
{
    /* 00 */ struct UnkStruct_Func_ov000_021d4968_Ret * unk_00;
    /* 04 */ s8 unk_04;
    /* 05 */ s8 unk_05;
    /* 06 */ u8 unk_06;
    /* 07 */ u8 unk_07;

    inline BOOL CheckUnk07()
    {
        return (this->unk_07 & 3) == 0;
    }
};

#endif // MAP_OBJECT_HPP
