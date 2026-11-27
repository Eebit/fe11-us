#ifndef MAP_OBJECT_HPP
#define MAP_OBJECT_HPP

#include "global.h"
#include "proc.h"

struct Event;
struct SaveBuffer;

enum
{
    MAP_OBJECT_KIND_DOOR = 0x05,
    MAP_OBJECT_KIND_CHEST = 0x06,
    MAP_OBJECT_KIND_DRAWBRIDGE = 0x07,
    MAP_OBJECT_KIND_VILLAGE = 0x08,
    MAP_OBJECT_KIND_09 = 0x09,
    MAP_OBJECT_KIND_SEIZE = 0x0E,
    MAP_OBJECT_KIND_SAVE_POINT = 0x10,
    MAP_OBJECT_KIND_12 = 0x12,
    MAP_OBJECT_KIND_DECOY = 0x13,
};

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

    void SetAlpha(s32 alpha);
    void Refresh(void);
    void _021d4bec(struct Event * ev);
    void _021d4cb4(struct Event * ev);
    void StartVillageCollapse(ProcPtr parent, BOOL arg);
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
extern MapObject * gMapObjects;

EC void AddMapObject(s32, s32, s32, s32);
EC void func_ov000_021d4874(void);
EC void FreeMapObjects(void);
EC MapObject * FindMapObject(s32, s32, s32);
EC MapObject * FindNextMapObject(MapObject *, s32);
EC BOOL func_ov000_021d49f4(s32, s32, s32);
EC s32 CountMapObjects(void);
EC void OpenRoof(s32, struct Event *);
EC void func_ov000_021d5084(s32);
EC void func_ov000_021d50cc(void);
EC void func_ov000_021d51c8(void);
EC void SaveMapObjects(struct SaveBuffer *);
EC void LoadMapObjects(struct SaveBuffer *, s32);
// EC ??? _ZN12ProcRoofOpenD0Ev
// EC ??? _ZN12ProcRoofOpenD1Ev
// EC ??? _ZN12ProcRoofOpen4LoopEv
// EC ??? _ZN19ProcVillageCollapseD0Ev
// EC ??? _ZN19ProcVillageCollapseD1Ev
// EC ??? _ZN19ProcVillageCollapse4LoopEv

#endif // MAP_OBJECT_HPP
