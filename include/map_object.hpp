#ifndef MAP_OBJECT_HPP
#define MAP_OBJECT_HPP

#include "global.h"
#include "proc.h"

struct Event;
struct SaveBuffer;

class MapObject
{
public:
    /* 00 */ MapObject * next;
    /* 04 */ s8 x;
    /* 05 */ s8 y;
    /* 06 */ u8 kind;
    /* 07 */ u8 flags;

    inline BOOL IsEnabled()
    {
        return (this->flags & 3) == 0;
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
extern MapObject * data_ov000_021e34e8;

EC void func_ov000_021d4804(s32, s32, s32, s32);
EC void func_ov000_021d4874(void);
EC void func_ov000_021d492c(void);
EC s32 func_ov000_021d4968(s32, s32, s32);
EC MapObject * func_ov000_021d49b8(MapObject *, s32);
EC BOOL func_ov000_021d49f4(s32, s32, s32);
EC s32 func_ov000_021d4a1c(void);
EC void func_ov000_021d4a48(MapObject *, s32);
EC void func_ov000_021d4a7c(MapObject *);
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
