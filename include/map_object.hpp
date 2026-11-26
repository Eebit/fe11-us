#ifndef MAP_OBJECT_HPP
#define MAP_OBJECT_HPP

#include "global.h"
#include "proc.h"

struct Event;
struct SaveBuffer;

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

extern s32 data_ov000_021e24c0;
// extern ??? data_ov000_021e24c4
// extern ??? _ZTI19ProcVillageCollapse
// extern ??? _ZTS12ProcRoofOpen
// extern ??? data_ov000_021e24e4
// extern ??? _ZTS19ProcVillageCollapse
// extern ??? _ZTV12ProcRoofOpen
// extern ??? _ZTI12ProcRoofOpen
// extern ??? _ZTV19ProcVillageCollapse
// extern ??? data_ov000_021e2554
// extern ??? data_ov000_021e2558
extern struct UnkStruct_Func_ov000_021d4968_Ret * data_ov000_021e34e8;

EC void func_ov000_021d4804(s32, s32, s32, s32);
EC void func_ov000_021d4874(void);
EC void func_ov000_021d492c(void);
EC s32 func_ov000_021d4968(s32, s32, s32);
EC struct UnkStruct_Func_ov000_021d4968_Ret * func_ov000_021d49b8(struct UnkStruct_Func_ov000_021d4968_Ret *, s32);
EC BOOL func_ov000_021d49f4(s32, s32, s32);
EC s32 func_ov000_021d4a1c(void);
EC void func_ov000_021d4a48(struct UnkStruct_Func_ov000_021d4968_Ret *, s32);
EC void func_ov000_021d4a7c(struct UnkStruct_Func_ov000_021d4968_Ret *);
EC void func_ov000_021d4bec(s32, struct Event *);
EC void func_ov000_021d4cb4(s32, struct Event *);
EC void func_ov000_021d4d80(s32, ProcPtr, BOOL);
EC void func_ov000_021d4e44(s32, struct Event *);
EC void func_ov000_021d5084(s32);
EC void func_ov000_021d50cc(void);
EC void func_ov000_021d51c8(void);
EC void func_ov000_021d537c(struct SaveBuffer *);
EC void func_ov000_021d5528(struct SaveBuffer *, s32);
// EC ??? _ZN12ProcRoofOpenD0Ev
// EC ??? _ZN12ProcRoofOpenD1Ev
// EC ??? _ZN12ProcRoofOpen4LoopEv
// EC ??? _ZN19ProcVillageCollapseD0Ev
// EC ??? _ZN19ProcVillageCollapseD1Ev
// EC ??? _ZN19ProcVillageCollapse4LoopEv

#endif // MAP_OBJECT_HPP
