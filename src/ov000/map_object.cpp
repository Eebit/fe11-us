#include "global.h"

#include <new>

#include "anime.hpp"
#include "database.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "save.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"
#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.h"

#include "constants/sounds.h"

EC void * func_ov000_021d3350(char *, s32, s32, s32, s32, ProcPtr, s32, s32, s32);
extern vu32 gElapsedFrames;

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

struct UnkStruct_Func_ov000_021d51c8
{
    /* 00 */ STRUCT_PAD(0x00, 0x08);
    /* 08 */ s32 unk_08;
    /* 0C */ STRUCT_PAD(0x0C, 0x10);
    /* 10 */ s16 unk_10;
};

s32 data_ov000_021e24c0 = 1;
struct UnkStruct_Func_ov000_021d4968_Ret * data_ov000_021e34e8;

class ProcRoofOpen : ProcEx
{
public:
    /* 38 */ s32 unk_38;
    /* 3C */ s32 unk_3c;

    ProcRoofOpen(s32 id);

    virtual ~ProcRoofOpen();
    virtual void Loop(void);
};

class ProcVillageCollapse : public ProcEx
{
public:
    /* 38 */ s32 unk_38;
    /* 3C */ s32 unk_3c;
    /* 40 */ u8 unk_40;

    ProcVillageCollapse(s32 tt);

    virtual ~ProcVillageCollapse();
    virtual void Loop(void);
};

inline ProcVillageCollapse::ProcVillageCollapse(s32 tt)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * obj = (struct UnkStruct_Func_ov000_021d4968_Ret *)tt;
    s32 size;

    this->unk_38 = tt;

    size = GetTileSize();
    func_ov000_021d3350("VillageCollapse", size * obj->unk_04 + (size >> 1), size * obj->unk_05, 0, 0, this, 0, 1, 1);

    this->unk_3c = 0;
    this->unk_40 = FALSE;
}

static inline u8 TestFlag(u8 * arr, u32 i)
{
    return (arr[i / 8] & (1 << (i & 7)));
}

static inline void SetRoofUnitAlpha(s32 id, u8 alpha)
{
    struct Unit * unit;
    s32 i;

    for (i = 0; i < 2; i++)
    {
        for (unit = Force::Get(i)->head; unit != NULL; unit = unit->next)
        {
            if (id == (gMapStateManager->unk_82c[unit->xPos | unit->yPos << 5] & 0x7f))
            {
                unit->alpha = alpha;
            }
        }
    }
}

inline void SetRoofLayerAlpha(s32 id, s32 alpha)
{
    struct MapFile * map = static_cast<struct MapFile *>(HashTable::Get1("Map"));

    Map_SetLayerAlphaById(map, id - 1, alpha);
}

inline ProcRoofOpen::ProcRoofOpen(s32 id)
{
    this->unk_38 = id;
    this->unk_3c = 0;

    SetRoofLayerAlpha(id, 0x1f);
    SetRoofUnitAlpha(id, 0);

    gSoundManager->unk_b0->vfunc_28(SE_MAP_AREA_OPEN1, 0, 0);
}

struct UnkStruct_Func_ov000_021d4e44_Map
{
    /* 00 */ STRUCT_PAD(0x00, 0x28);
    /* 28 */ void * unk_28;
};

EC void func_ov000_021d4804(s32 x, s32 y, s32 kind, s32 flags)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * tt;
    struct UnkStruct_Func_ov000_021d4968_Ret * it;

    tt = new UnkStruct_Func_ov000_021d4968_Ret;
    tt->unk_04 = x;
    tt->unk_05 = y;
    tt->unk_06 = kind;
    tt->unk_07 = flags;
    tt->unk_00 = NULL;

    if (data_ov000_021e34e8 == NULL)
    {
        data_ov000_021e34e8 = tt;
        return;
    }

    for (it = data_ov000_021e34e8; it->unk_00 != NULL; it = it->unk_00)
    {
    }

    it->unk_00 = tt;

    return;
}

EC void func_ov000_021d4874(void)
{
    struct EventInfo * it;

    for (it = func_02035b98(NULL); it != NULL; it = func_02035b98(it))
    {
        if (it->kind == EVENT_KIND_05)
        {
            switch (it->args[2])
            {
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 14:
                case 16:
                case 18:
                case 19:
                    func_ov000_021d4804(it->args[0], it->args[1], it->args[2], 0);
                    break;
            }
        }
    }

    data_ov000_021e24c0 = 1;

    return;
}

EC void func_ov000_021d492c(void)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * it;
    struct UnkStruct_Func_ov000_021d4968_Ret * next;

    for (it = data_ov000_021e34e8; it != NULL; it = next)
    {
        next = it->unk_00;
        delete it;
    }

    data_ov000_021e34e8 = NULL;

    return;
}

EC s32 func_ov000_021d4968(s32 x, s32 y, s32 kind)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * it;

    for (it = data_ov000_021e34e8; it != NULL; it = it->unk_00)
    {
        if (kind != 0 && it->unk_06 != kind)
        {
            continue;
        }

        if (it->unk_04 == x && it->unk_05 == y)
        {
            return (s32)it;
        }
    }

    return 0;
}

EC struct UnkStruct_Func_ov000_021d4968_Ret *
func_ov000_021d49b8(struct UnkStruct_Func_ov000_021d4968_Ret * prev, s32 kind)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * it;

    for (it = prev == NULL ? data_ov000_021e34e8 : prev->unk_00; it != NULL; it = it->unk_00)
    {
        if (kind != 0 && it->unk_06 != kind)
        {
            continue;
        }

        return it;
    }

    return NULL;
}

EC BOOL func_ov000_021d49f4(s32 x, s32 y, s32 kind)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * tt;

    tt = (struct UnkStruct_Func_ov000_021d4968_Ret *)func_ov000_021d4968(x, y, kind);

    if (tt == NULL)
    {
        return FALSE;
    }

    return tt->CheckUnk07();
}

EC s32 func_ov000_021d4a1c(void)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * it;
    s32 count = 0;

    for (it = data_ov000_021e34e8; it != NULL; it = it->unk_00)
    {
        count++;
    }

    return count;
}

EC void func_ov000_021d4a48(struct UnkStruct_Func_ov000_021d4968_Ret * self, s32 alpha)
{
    struct MapFile * map = static_cast<struct MapFile *>(HashTable::Get1("Map"));

    if (map == NULL)
    {
        return;
    }

    Map_SetLayerAlphaAt(map, self->unk_04, self->unk_05, alpha);

    return;
}

EC void func_ov000_021d4a7c(struct UnkStruct_Func_ov000_021d4968_Ret * self)
{
    u8 tile = gMapStateManager->unk_828[self->unk_04 | self->unk_05 << 5];

    switch (self->unk_06)
    {
        case 8:
            if (self->unk_07 & 2)
            {
                tile = 0x28;
                func_ov000_021d4a48(self, 2);
            }
            else if (self->unk_07 & 1)
            {
                tile = 0x27;
                func_ov000_021d4a48(self, 1);
            }
            else
            {
                tile = 3;
                func_ov000_021d4a48(self, 0);
            }
            break;

        case 5:
            if (self->unk_07 & 1)
            {
                tile = 0xe;
                func_ov000_021d4a48(self, 1);
            }
            else
            {
                tile = 0x1b;
                func_ov000_021d4a48(self, 0);
            }
            break;

        case 6:
            if (self->unk_07 & 1)
            {
                func_ov000_021d4a48(self, 1);
            }
            else
            {
                func_ov000_021d4a48(self, 0);
            }
            break;

        case 7:
            if (self->unk_07 & 1)
            {
                tile = 0xc;
                func_ov000_021d4a48(self, 1);
            }
            else
            {
                tile = 0x1c;
                func_ov000_021d4a48(self, 0);
            }
            break;
    }

    gMapStateManager->unk_828[self->unk_04 | self->unk_05 << 5] = tile;
    gMapStateManager->unk_830[self->unk_04 | self->unk_05 << 5] =
        GetTerrainCategoryDBIndex(gFE11Database->pTerrain[tile].unk_08);

    return;
}

EC void func_ov000_021d4bec(s32 tt, struct Event * ev)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * self = (struct UnkStruct_Func_ov000_021d4968_Ret *)tt;

    if (ev != NULL)
    {
        switch (self->unk_06)
        {
            case 5:
                gSoundManager->unk_b0->vfunc_28(SE_MAP_DOOR_OPEN1, 0, 0);
                break;

            case 6:
                gSoundManager->unk_b0->vfunc_28(SE_MAP_KEY_OPEN1, 0, 0);
                break;

            case 7:
                gSoundManager->unk_b0->vfunc_28(SE_MAP_BRIDGE1, 0, 0);
                break;
        }
    }

    self->unk_07 = 0;
    func_ov000_021d4a7c(self);

    return;
}

EC void func_ov000_021d4cb4(s32 tt, struct Event * ev)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * self = (struct UnkStruct_Func_ov000_021d4968_Ret *)tt;

    if (ev != NULL)
    {
        switch (self->unk_06)
        {
            case 5:
                gSoundManager->unk_b0->vfunc_28(SE_MAP_DOOR_OPEN1, 0, 0);
                break;

            case 6:
                gSoundManager->unk_b0->vfunc_28(SE_MAP_KEY_OPEN1, 0, 0);
                break;

            case 7:
                gSoundManager->unk_b0->vfunc_28(SE_MAP_BRIDGE1, 0, 0);
                break;
        }
    }

    self->unk_07 = 0;
    self->unk_07 |= 1;
    func_ov000_021d4a7c(self);

    return;
}

EC void func_ov000_021d4d80(s32 tt, ProcPtr parent, BOOL arg)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * self = (struct UnkStruct_Func_ov000_021d4968_Ret *)tt;
    ProcVillageCollapse * proc;

    if (parent != NULL && self->unk_06 == 8)
    {
        proc = new (Proc_StartBlocking(ProcScr_020ce750, parent)) ProcVillageCollapse(tt);

        if (arg)
        {
            proc->proc_mark = PROC_MARK_B;
        }

        return;
    }

    self->unk_07 = 0;
    self->unk_07 |= 2;
    func_ov000_021d4a7c(self);

    return;
}

EC void func_ov000_021d4e44(s32 id, struct Event * ev)
{
    struct UnkStruct_Func_ov000_021d4e44_Map * map;
    s32 vram;
    void * buf;
    struct Unit * unit;
    s16 x;
    s16 y;

    if (id == 0)
    {
        return;
    }

    map = static_cast<struct UnkStruct_Func_ov000_021d4e44_Map *>(HashTable::Get1("Map"));
    buf = func_02020c18(map->unk_28);
    vram = gpSubScreenSt->objVram;

    for (y = (s32)gMapStateManager->unk_25; y < gMapStateManager->unk_27; y++)
    {
        for (x = (s32)gMapStateManager->unk_24; x < gMapStateManager->unk_26; x++)
        {
            if (id == (gMapStateManager->unk_82c[x | y << 5] & 0x7f))
            {
                gMapStateManager->unk_82c[x | y << 5] &= 0x7f;

                unit = GetUnit(gMapStateManager->unk_428[x | y << 5]);

                if (unit != NULL)
                {
                    unit->state2 &= ~US_UNK_5;
                    func_ov000_021a3498(unit, FALSE, -1, -1);
                }

                func_0204ed4c(buf, (void *)(vram + 0x1000), x, y);
            }
        }
    }

    gHeap.Free(buf);

    if (ev != NULL)
    {
        new (Proc_StartBlocking(ProcScr_020ce750, ev)) ProcRoofOpen(id);
    }
    else
    {
        SetRoofLayerAlpha(id, 0);
    }

    return;
}

EC void func_ov000_021d5084(s32 state)
{
    struct MapFile * map = static_cast<struct MapFile *>(HashTable::Get1("Map"));

    if (map == NULL)
    {
        return;
    }

    Map_SetAllKind3LayersAlpha(map, state == 0 ? 1 : (state == 1 ? 0 : 2));

    data_ov000_021e24c0 = state;

    return;
}

EC void func_ov000_021d50cc(void)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * it;
    Anime * anime;
    s32 alpha;
    s32 mapAlpha;
    s32 size;
    Vec3 pos;

    it = data_ov000_021e34e8;
    anime = gMapStateManager->unk_14->unk_1c;

    if (anime == NULL)
    {
        return;
    }

    alpha = anime->interpreter != NULL ? anime->interpreter->alpha : 0x1f;
    mapAlpha = data_ov000_021e3324->unk_14;

    if (mapAlpha == 0)
    {
        return;
    }

    if (mapAlpha < alpha)
    {
        if (anime->interpreter != NULL)
        {
            anime->interpreter->SetAlpha(mapAlpha);
        }
    }

    size = GetTileSize();

    for (; it != NULL; it = it->unk_00)
    {
        if (it->unk_06 == 14)
        {
            gMapStateManager->camera->_021a51b8(it->unk_04, it->unk_05, &pos);
            anime->DrawInternal(pos.x + (size >> 1), pos.y + (size >> 1));
        }
    }

    if (anime->interpreter != NULL)
    {
        anime->interpreter->SetAlpha(alpha);
    }

    return;
}

EC void func_ov000_021d51c8(void)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * it;
    s32 size;
    s32 value;
    struct UnkStruct_Func_ov000_021d51c8 * psave;
    Anime * anime;
    s32 mapAlpha;
    s32 offset;
    s32 alpha;
    s32 frame;
    Vec3 pos;

    it = data_ov000_021e34e8;
    anime = gMapStateManager->unk_14->unk_20;

    if (anime == NULL)
    {
        return;
    }

    alpha = anime->interpreter != NULL ? anime->interpreter->alpha : 0x1f;
    mapAlpha = data_ov000_021e3324->unk_15;

    if (mapAlpha == 0)
    {
        return;
    }

    if (mapAlpha < alpha)
    {
        if (anime->interpreter != NULL)
        {
            anime->interpreter->SetAlpha(mapAlpha);
        }
    }

    size = GetTileSize();
    psave = static_cast<struct UnkStruct_Func_ov000_021d51c8 *>(HashTable::Get2("VmMap_PSave"));

    frame = (gElapsedFrames >> 2) & 0xf;

    if (frame > 7)
    {
        frame = 15 - frame;
    }

    offset = frame * 8;

    anime->func_0201a078(offset + psave->unk_08);

    value = psave->unk_10;

    for (; it != NULL; it = it->unk_00)
    {
        if (it->unk_06 == 16 && it->CheckUnk07())
        {
            if (gMapStateManager->camera->_021a51b8(it->unk_04, it->unk_05, &pos))
            {
                func_0206e5f4(psave, mapAlpha);
                func_0206e608(psave, 0, offset, 0, 0);
                func_0206d27c(pos.x, pos.y, value, size, size);
            }

            anime->DrawInternal(pos.x + (size >> 1), pos.y + (size >> 1));
        }
    }

    if (anime->interpreter != NULL)
    {
        anime->interpreter->SetAlpha(alpha);
    }

    return;
}

EC void func_ov000_021d537c(struct SaveBuffer * buf)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * it;
    s16 x;
    s16 y;
    u8 tile;
    u8 flags[0x10];

    buf->WriteShort(func_ov000_021d4a1c());

    for (it = data_ov000_021e34e8; it != NULL; it = it->unk_00)
    {
        buf->WriteByte(it->unk_04);
        buf->WriteByte(it->unk_05);
        buf->WriteByte(it->unk_06);
        buf->WriteByte(it->unk_07);
    }

    func_020a5824(flags, 0, sizeof(flags));

    for (y = (s32)gMapStateManager->unk_25; y < gMapStateManager->unk_27; y++)
    {
        for (x = (s32)gMapStateManager->unk_24; x < gMapStateManager->unk_26; x++)
        {
            tile = gMapStateManager->unk_82c[x | y << 5];

            if (tile != 0 && !(u8)(tile & 0x80))
            {
                tile &= 0x7f;
                flags[(u32)tile >> 3] |= 1 << (tile & 7);
            }
        }
    }

    func_020a58b8(flags, buf->unk_04, sizeof(flags));
    buf->unk_04 += sizeof(flags);

    buf->WriteByte(data_ov000_021e24c0);

    return;
}

EC void func_ov000_021d5528(struct SaveBuffer * buf, s32 unused)
{
    struct UnkStruct_Func_ov000_021d4968_Ret * tt;
    s32 i;
    s32 count;
    s16 x;
    s16 y;
    u8 tile;
    u8 flags[0x10];

    count = buf->ReadShort();

    for (i = 0; i < count; i++)
    {
        u8 xTile = buf->ReadByte();
        u8 yTile = buf->ReadByte();
        u8 kind = buf->ReadByte();
        u8 state = buf->ReadByte();

        tt = (struct UnkStruct_Func_ov000_021d4968_Ret *)func_ov000_021d4968(xTile, yTile, kind);

        if (tt != NULL)
        {
            tt->unk_07 = state;
            func_ov000_021d4a7c(tt);
        }
    }

    func_020a58b8(buf->unk_04, flags, sizeof(flags));
    buf->unk_04 += sizeof(flags);

    for (y = (s32)gMapStateManager->unk_25; y < gMapStateManager->unk_27; y++)
    {
        for (x = (s32)gMapStateManager->unk_24; x < gMapStateManager->unk_26; x++)
        {
            tile = gMapStateManager->unk_82c[x | y << 5];

            if (tile != 0)
            {
                tile &= 0x7f;

                if (TestFlag(flags, tile))
                {
                    gMapStateManager->unk_82c[x | y << 5] = tile;
                }
            }
        }
    }

    for (i = 0; i < 0x80; i++)
    {
        if (TestFlag(flags, i))
        {
            SetRoofLayerAlpha(i, 0);
        }
    }

    func_ov000_021d5084(buf->ReadByte());

    return;
}

ProcRoofOpen::~ProcRoofOpen()
{
    SetRoofLayerAlpha(this->unk_38, 0);
    SetRoofUnitAlpha(this->unk_38, 0x1F);
}

void ProcRoofOpen::Loop(void)
{
    s32 alpha;

    this->unk_3c++;
    alpha = Interpolate(0, 31, 0, this->unk_3c, 32);
    SetRoofLayerAlpha(this->unk_38, alpha);
    SetRoofUnitAlpha(this->unk_38, 31 - alpha);

    if (this->unk_3c == 32)
    {
        Proc_End(this);
    }

    return;
}

ProcVillageCollapse::~ProcVillageCollapse()
{
    if (this->unk_40 == 0)
    {
        func_ov000_021d4d80(this->unk_38, NULL, FALSE);
    }
}

void ProcVillageCollapse::Loop(void)
{
    this->unk_3c++;

    if (this->unk_3c == 10)
    {
        func_ov000_021d4d80(this->unk_38, NULL, FALSE);
        this->unk_40 = TRUE;
    }

    if (this->unk_40 && Proc_GetChild((struct Proc *)this) == NULL)
    {
        Proc_End(this);
    }

    return;
}
