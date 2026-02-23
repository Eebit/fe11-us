#include "global.h"

#include <new>

#include "unit.hpp"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "database.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "save.hpp"
#include "sound_manager.hpp"
#include "state_manager.hpp"

#include "constants/sounds.h"

extern struct ProcCmd ProcScr_020ce750[];
extern struct UnkStruct_02196f0c * data_02196f0c;
extern struct UnkStruct_02196f24 * data_02196f24;
extern struct UnkStruct_021974fc * data_021974fc;

EC void func_ov000_021d4874(void);
EC void func_0204f080(struct UnkStruct_021974fc *);

EC void func_ov000_021a2eb0(struct SaveBuffer *, s32);

EC void func_ov000_021b9a10(MapStateManager_14 *);
EC void func_ov000_021a37c4(void);

EC void func_ov000_021a3364(void);

extern u8 data_ov000_021e3320[];

EC void func_ov000_021baafc(void *, struct Unit *, BOOL);

EC void func_ov000_021d537c(void *);
EC void func_ov000_021a3364(void);
EC void func_ov000_021a340c(void);
EC void func_ov000_021a35a0(void);
EC void func_ov000_021a37c4(void);
EC void func_ov000_021a48b0(u32);
EC void func_ov000_021d4004(s8, s8);
EC void func_ov000_021d5528(void *, s32);
EC void func_02040094(struct MapStateManager_1C *, s32);
EC void func_020401d8(struct MapStateManager_1C *, u8);
EC void func_ov000_021a37c4(void);
EC void func_ov000_021babf4(void *);

EC void func_ov000_021a36f8(struct Unit *, BOOL, BOOL);

EC void func_ov000_021a3974(u8 *, s32);
EC void func_ov000_021a3a30(u8 *, u32);

extern struct UnkStruct_021e3528 data_ov000_021e3528;

EC void func_ov000_021a3ad0(u8 *, s16, s16, s32);

extern struct Unit * data_021974f0;

EC BOOL AreAllEnemiesDefeated(u32);

EC void StartSoundWaitTo_0201775c(void *, void *, int, int);
EC void StartSoundWaitTo_02017938(void *, void *, int, int, int);

EC void StartSoundWaitTo_02017b40(void *, void *, int);

EC BOOL func_ov000_021adabc(struct Unit *, u32);

EC BOOL func_ov000_021a475c(void);
EC BOOL func_ov000_021a47ac(void);

extern struct UnkStruct_02196f0c * data_02196f0c;
extern struct UnkStruct_02196f10 * data_02196f10;

extern vu32 data_027e1264;

extern u8 data_ov000_021e3320[];

EC void func_ov000_021b9bec(struct MapStateManager_14 *);

EC void func_ov000_021b9c3c(struct MapStateManager_14 *);

EC void func_ov000_021b9bc4(struct MapStateManager_14 *);

EC void func_ov000_021b9bac(struct MapStateManager_14 *);

EC void func_ov000_021d4094(void);
EC void func_ov000_021b9bec(struct MapStateManager_14 *);
EC void func_ov000_021d492c(void);
EC void func_0204000c(void);

EC void func_ov000_021a8304(void);
EC void func_ov002_021f212c(void);

EC void func_ov002_021f2160(void);
EC void func_ov000_021a32c8(void);
EC void func_ov000_021a83d0(void);

extern char data_ov000_021db7dc[];

class ProcMapBegin : public ProcEx
{
public:
    ProcMapBegin()
    {
        this->proc_mark = PROC_MARK_6;
    }

    virtual ~ProcMapBegin();
    virtual void Init();
    virtual void Loop();
};

class ProcMapLow : public ProcEx
{
public:
    ProcMapLow()
    {
        this->proc_mark = PROC_MARK_6;
    }

    virtual ~ProcMapLow();
    virtual void Init();
    virtual void Loop();
};

class ProcMapDraw : public ProcEx
{
public:
    ProcMapDraw()
    {
        this->proc_mark = PROC_MARK_6;
    }

    virtual ~ProcMapDraw();
    virtual void Init();
    virtual void Loop();
};

class ProcMapEnd : public ProcEx
{
public:
    ProcMapEnd()
    {
        this->proc_mark = PROC_MARK_6;
    }

    virtual ~ProcMapEnd();
    virtual void Init();
    virtual void Loop();
};

// clang-format off

char * data_ov000_021db72c[] =
{
    "Null\0\0\0",
    "Link\0\0\0",
    "Cpu",
    "Human\0\0\0",
};

u32 gPlMapMusicLut[] =
{
    0x0,
    BGM_MAP_PL1, // "Footsteps of Fate"
    BGM_MAP_PL2, // "The Time to Act"
    BGM_MAP_PL3, // "For Liberty"
    BGM_MAP_PL4, // "A Hero's Destiny"
    BGM_MAP_PL5, // "Showdown in Dolhr Keep"
    BGM_MAP_PL6, // "Into the Darkness"
    BGM_MAP_PL7, // "On the Path to Victory"
};

u32 gCpMapMusicLut[] =
{
    0,
    BGM_MAP_CP1, // "Blade of Treachery"
    BGM_MAP_CP2, // "Onset"
    BGM_MAP_CP3, // "A Mighty Host Appears"
    BGM_MAP_CP4, // "The Shadow Lengthens"
    BGM_MAP_CP5, // "Last Revels"
    BGM_MAP_CP6, // "Looming Danger"
};

// clang-format on

UnkStruct_021E3324 * data_ov000_021e3324 = NULL;
MapStateManager * gMapStateManager = NULL;

EC void func_ov000_021a23e0(char * mapName)
{
    if (mapName == NULL)
    {
        mapName = GetBattleMapNameMaybe();
    }

    if (gMapStateManager == NULL)
    {
        gMapStateManager = new MapStateManager;
    }

    gMapStateManager->func_ov000_021a276c(mapName);
    func_0204246c(mapName);

    if (data_ov000_021e334c == NULL)
    {
        data_ov000_021e334c = new UnkStruct_021e334c;
    }

    func_ov000_021d4874();
    gMapStateManager->func_ov000_021a28cc();

    if (data_021974fc != NULL)
    {
        func_0204f080(data_021974fc);
    }

    new (Proc_Start(ProcScr_020ce750, PROC_TREE_6)) ProcMapBegin();
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_A)) ProcMapLow();
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_B)) ProcMapDraw();
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_C)) ProcMapEnd();

    return;
}

EC void func_ov000_021a2540(void * arg_0, s32 arg_1)
{
    if (arg_0 != 0)
    {
        func_ov000_021a2eb0((struct SaveBuffer *)arg_0, arg_1);
    }
    else
    {
        gMapStateManager->func_ov000_021a2918();
    }

    gMapStateManager->func_ov000_021a29f4();

    return;
}

EC void func_ov000_021a2574(void)
{
    func_ov000_021a4718();
    func_ov000_021d4094();

    func_ov000_021b9bec(gMapStateManager->unk_14);

    Proc_EndEachMarked(PROC_MARK_6);

    if (data_ov000_021e334c != NULL)
    {
        delete data_ov000_021e334c;
    }
    data_ov000_021e334c = NULL;

    func_ov000_021d492c();
    func_020424ac();

    if (gMapStateManager != NULL)
    {
        delete gMapStateManager;
    }
    gMapStateManager = NULL;

    func_0204000c();

    data_02196f0c->state &= ~0x4;

    return;
}

MapStateManager::MapStateManager()
{
    func_ov000_021a8304();

    this->camera = new Camera;
    this->unk_04 = new MapStateManager_04;

    this->unk_08 = (MapStateManager_08 *)func_02000c70();
    this->inputHandler = new InputHandler;
    this->cursor = new Cursor;

    this->unk_14 = new MapStateManager_14;
    this->unk_18 = NULL;
    this->unk_1c = NULL;

    func_ov002_021f212c();
}

MapStateManager::~MapStateManager()
{
    func_ov002_021f2160();

    if (this->unk_1c != NULL)
    {
        func_ov000_021a32c8();
    }

    if (this->unk_18 != NULL)
    {
        func_020379c0();
    }

    func_ov000_021a83d0();

    delete this->camera;
    delete this->unk_04;
    delete this->inputHandler;
    delete this->cursor;

    delete this->unk_14;

    HashTable::Get1("Map");
    func_020379c0();
}

/* NONMATCHING: https://decomp.me/scratch/caqO6 */
void MapStateManager::func_ov000_021a276c(char * mapName)
{
    struct MapFile * pMapFile;
    s32 i;
    s16 x;
    s16 y;

    func_020a8f40("/map\0\0\0");

    pMapFile = LoadFileAndCache(mapName, 0);

    this->unk_20 = pMapFile->tileWidth;
    this->unk_22 = pMapFile->tileHeight;

    this->unk_24 = 1;
    this->unk_25 = 1;

    this->unk_26 = this->unk_20 - 1;
    this->unk_27 = this->unk_22 - 1;

    this->unk_eb8 = 0;

    for (i = 0; i < 4; i++)
    {
        this->unk_eb0[i] = -1;
        this->unk_eb4[i] = -1;
    }

    gMapStateManager->unk_828 = pMapFile->unk_10;
    gMapStateManager->unk_82c = pMapFile->unk_14;

    for (y = gMapStateManager->unk_25; y < gMapStateManager->unk_27; y++)
    {
        for (x = gMapStateManager->unk_24; x < gMapStateManager->unk_26; x++)
        {
            if (gMapStateManager->unk_82c[x | y << 5] != 0)
            {
                gMapStateManager->unk_82c[x | y << 5] |= 0x80;
            }
        }
    }

    func_020a8f40("/dispos");

    if (FileExists(mapName) != 0)
    {
        this->unk_18 = LoadFileAndCache(mapName, 1);
    }

    func_ov000_021b95e8(gMapStateManager->unk_14);

    return;
}

void MapStateManager::func_ov000_021a28cc(void)
{
    gMapStateManager->camera->func_ov000_021a4a7c();
    gMapStateManager->inputHandler->_021a5318();
    gMapStateManager->cursor->Init();
    func_ov000_021b9a10(gMapStateManager->unk_14);
    return;
}

void MapStateManager::func_ov000_021a2918(void)
{
    s32 i;

    if (func_ov000_021a478c() == 0)
    {
        for (i = 0; i < 2; i++)
        {
            if (i == 0)
            {
                data_ov000_021e3320[i] = 1;
            }
            else
            {
                data_ov000_021e3320[i] = 2;
            }
        }
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            if (i == func_02012478())
            {
                data_ov000_021e3320[i] = 1;
            }
            else
            {
                data_ov000_021e3320[i] = 3;
            }
        }
    }

    data_ov000_021e3324->unk_01 = 0;

    for (i = 0; i < 2; i++)
    {
        if (data_ov000_021e3320[i] == 1)
        {
            data_ov000_021e3324->unk_01 = i;
            break;
        }
    }

    func_ov000_021a3364();
    func_02000c7c(gMapStateManager->unk_08);
    func_ov000_021a37c4();
    func_ov000_021a340c();
    func_ov000_021a35a0();

    return;
}

void MapStateManager::func_ov000_021a29f4(void)
{
    Force * force;
    struct Unit * it;
    s32 i;

    for (i = 0; i < 2; i++)
    {
        force = Force::Get(i);

        for (it = force->head; it != NULL; it = it->unk_3c)
        {
            func_ov000_021baafc(gMapStateManager->unk_14->unk_00, it, 1);
        }
    }

    return;
}

EC BOOL func_ov000_021a2a50(struct UnkStruct_021E3324 * self)
{
    BOOL flag;
    s32 i;

    self->phase++;

    if (self->phase == 2)
    {
        if ((self->unk_06 != 0) && (self->turn >= self->unk_06))
        {
            return FALSE;
        }

        self->phase = 0;
        self->turn++;

        if (self->turn > 999)
        {
            self->turn = 999;
        }
    }

    flag = FALSE;

    for (i = 0; i < 2; i++)
    {
        if (data_ov000_021e3320[i] == 1)
        {
            flag = TRUE;
            break;
        }
    }

    if ((!flag) || (data_ov000_021e3320[self->phase] == 1))
    {
        self->unk_01 = self->phase;
    }

    return TRUE;
}

/* NONMATCHING: https://decomp.me/scratch/NXh8g */
EC void func_ov000_021a2b08(struct SaveBuffer * buf)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        buf->WriteByte(data_ov000_021e3320[i]);
    }

    buf->WriteByte(data_ov000_021e3324->phase);
    buf->WriteByte(data_ov000_021e3324->unk_01);
    buf->WriteShort(data_ov000_021e3324->turn);
    buf->WriteShort(data_ov000_021e3324->unk_06);
    buf->WriteWord(data_ov000_021e3324->unk_08);
    buf->WriteWord(data_ov000_021e3324->unk_0c);
    buf->WriteByte(data_ov000_021e3324->unk_02);
    buf->WriteByte(data_ov000_021e3324->unk_03);

    func_020a58b8(gMapStateManager->unk_db0, buf->unk_04, 0x80);
    buf->unk_04 += 0x80;
    func_020a58b8(gMapStateManager->unk_d30, buf->unk_04, 0x80);
    buf->unk_04 += 0x80;

    buf->WriteShort(gMapStateManager->camera->unk_14);
    buf->WriteShort(gMapStateManager->camera->unk_16);
    buf->WriteByte(gMapStateManager->cursor->xTile);
    buf->WriteByte(gMapStateManager->cursor->yTile);

    for (i = 0; i < 2; i++)
    {
        buf->WriteByte(gMapStateManager->cursor->unk_00[i]);
        buf->WriteByte(gMapStateManager->cursor->unk_02[i]);
    }

    for (i = 0; i < 4; i++)
    {
        buf->WriteByte(gMapStateManager->unk_eb0[i]);
        buf->WriteByte(gMapStateManager->unk_eb4[i]);
    }

    func_ov000_021d537c(buf);

    for (i = 0; i < 4; i++)
    {
        buf->WriteByte(data_ov000_021e3324->unk_18[i]);
    }

    buf->WriteByte(data_ov000_021e3324->unk_1c);

    return;
}

/* NONMATCHING: https://decomp.me/scratch/xLJJS */
EC void func_ov000_021a2eb0(struct SaveBuffer * buf, s32 arg_1)
{
    s32 i;

    s32 word;

    s16 unk_14;
    s16 unk_16;

    for (i = 0; i < 2; i++)
    {
        data_ov000_021e3320[i] = buf->ReadByte();
    }

    data_ov000_021e3324->phase = buf->ReadByte();
    data_ov000_021e3324->unk_01 = buf->ReadByte();

    data_ov000_021e3324->turn = buf->ReadShort();
    data_ov000_021e3324->unk_06 = buf->ReadShort();

    word = buf->ReadWord();
    func_ov000_021a48b0(word);

    data_ov000_021e3324->unk_0c = buf->ReadWord();

    data_ov000_021e3324->unk_02 = buf->ReadByte();
    data_ov000_021e3324->unk_03 = buf->ReadByte();

    func_ov000_021a37c4();

    func_020a58b8(buf->unk_04, gMapStateManager->unk_db0, 0x80);
    buf->unk_04 += 0x80;

    func_020a58b8(buf->unk_04, gMapStateManager->unk_d30, 0x80);
    buf->unk_04 += 0x80;

    unk_14 = buf->ReadShort();
    unk_16 = buf->ReadShort();
    gMapStateManager->camera->unk_14 = unk_14;
    gMapStateManager->camera->unk_16 = unk_16;

    gMapStateManager->camera->func_ov000_021a52c8(
        gMapStateManager->camera->unk_14, gMapStateManager->camera->unk_16, 0);

    gMapStateManager->cursor->SetPosImmediate(buf->ReadByte(), buf->ReadByte());

    for (i = 0; i < 2; i++)
    {
        s32 tmp = buf->ReadByte();
        s32 tmp2 = buf->ReadByte();
        gMapStateManager->cursor->unk_00[i] = tmp;
        gMapStateManager->cursor->unk_02[i] = tmp2;
    }

    if (arg_1 >= 4)
    {
        for (i = 0; i < 4; i++)
        {
            s8 tmp = buf->ReadByte();
            s8 tmp2 = buf->ReadByte();
            if (tmp != -1)
            {
                func_ov000_021d4004(tmp, tmp2);
            }
        }
    }

    func_ov000_021d5528(buf, arg_1);
    func_ov000_021a3364();
    func_02000c7c(gMapStateManager->unk_08);
    func_ov000_021a340c();
    func_ov000_021a35a0();

    if (arg_1 < 3)
    {
        buf->unk_04 += 0x805;
    }

    if (arg_1 >= 1)
    {
        for (i = 0; i < 4; i++)
        {
            data_ov000_021e3324->unk_18[i] = buf->ReadByte();
        }
    }

    if (arg_1 < 2)
    {
        return;
    }

    data_ov000_021e3324->unk_1c = buf->ReadByte();

    return;
}

EC void func_ov000_021a323c(void)
{
    if (gMapStateManager->unk_1c != NULL)
    {
        return;
    }

    func_ov000_021a4718();

    gMapStateManager->unk_1c = new MapStateManager_1C;

    func_02040094(gMapStateManager->unk_1c, -1);
    gMapStateManager->unk_1c->unk_04 = gMapStateManager->unk_1c->unk_00;

    return;
}

EC void func_ov000_021a32c8(void)
{
    if (gMapStateManager->unk_1c == NULL)
    {
        return;
    }

    func_ov000_021a4718();

    func_020401d8(gMapStateManager->unk_1c, -1);

    delete gMapStateManager->unk_1c;
    gMapStateManager->unk_1c = NULL;

    func_ov000_021a37c4();
    func_ov000_021a340c();
    func_ov000_021babf4(gMapStateManager->unk_14->unk_00);

    return;
}

EC void func_ov000_021a3364(void)
{
    s16 x;
    s16 y;

    for (y = 0; y < gMapStateManager->unk_22; y++)
    {
        for (x = 0; x < gMapStateManager->unk_20; x++)
        {
            u8 tile = gMapStateManager->unk_828[x | (y << 5)];
            gMapStateManager->unk_830[x | (y << 5)] = GetTerrainCategoryDBIndex(gFE11Database->pTerrain[tile].unk_08);
        }
    }
}

EC void func_ov000_021a340c(void)
{
    Force * force;
    s32 i;
    struct Unit * it;

    func_020a5734(0, gMapStateManager->unk_028, 0x400);
    func_020a5734(0, gMapStateManager->unk_428, 0x400);

    for (i = 0; i < 2; i++)
    {
        force = Force::Get(i);
        for (it = force->head; it != 0; it = it->unk_3c)
        {
            func_ov000_021a3498(it, 0, -1, -1);
        }
    }

    return;
}

EC void func_ov000_021a3498(struct Unit * unit, BOOL arg_1, u32 x, u32 y)
{
    if (x == -1)
    {
        x = unit->xPos;
    }

    if (y == -1)
    {
        y = unit->yPos;
    }

    if (((unit->state2 & 0x21000) != 0) && (arg_1 == 0))
    {
        return;
    }

    if (!(unit->state2 & 0x20))
    {
        u32 pos = (x | (y << 5));
        if (((gMapStateManager->unk_d30[pos >> 3] & (1 << (pos & 7))) & 0xFF) || (unit->state2 & 0x4000) ||
            (((unit->force->id == data_ov000_021e3324->unk_01) & 0xFF) != 0))
        {
            gMapStateManager->unk_028[x | y << 5] = unit->unk_68;
        }
    }

    gMapStateManager->unk_428[x | y << 5] = unit->unk_68;

    return;
}

/* NONMATCHING: https://decomp.me/scratch/kRxMD */
EC void func_ov000_021a354c(struct Unit * unit, s32 x, s32 y)
{
    if (x == -1)
    {
        x = unit->xPos;
    }

    if (y == -1)
    {
        y = unit->yPos;
    }

    if (gMapStateManager->unk_428[x | y << 5] == unit->unk_68)
    {
        gMapStateManager->unk_028[x | y << 5] = 0;
        gMapStateManager->unk_428[x | y << 5] = 0;
    }

    return;
}

static inline BOOL TestPhaseAndState(struct Unit * unit, u32 phase)
{
    if (unit->state2 & 0x21020)
    {
        return TRUE;
    }

    if (phase == unit->force->id)
    {
        return TRUE;
    }

    return FALSE;
}

/* NONMATCHING: https://decomp.me/scratch/Aqu4T */
EC void func_ov000_021a35a0(void)
{
    Force * force;
    struct Unit * it;
    s32 i;
    u32 phase = data_ov000_021e3324->unk_01;

    func_020a5734(0, gMapStateManager->unk_c30, 0x80);
    func_020a5734(0, gMapStateManager->unk_cb0, 0x80);

    for (i = 0; i < 2; i++)
    {
        force = Force::Get(i);

        for (it = force->head; it != NULL; it = it->unk_3c)
        {
            if (!TestPhaseAndState(it, phase))
            {
                if ((gMapStateManager->unk_d30[(it->xPos | it->yPos << 5) >> 3] & (1 << (it->xPos & 7))) &
                    0xFF)
                {
                    continue;
                }

                if (!(it->state2 & 0x4000))
                {
                    continue;
                }

                if (data_ov000_021e3324->unk_03 != 0)
                {
                    continue;
                }

                if (!(it->state2 & 0x2000))
                {
                    continue;
                }

                func_ov000_021a36f8(it, TRUE, FALSE);
            }
        }
    }

    gMapStateManager->unk_14->unk_04->unk_17 = 1;
    gMapStateManager->unk_eb8 = 0;

    return;
}

EC void func_ov000_021a36e0(void)
{
    gMapStateManager->unk_eb8 = 1;
    return;
}

EC void func_ov000_021a36f8(struct Unit * unit, BOOL arg_1, BOOL arg_2)
{
    if (arg_1 != 0)
    {
        func_01ff8d88(gMapStateManager->unk_08, unit, -1, 2, 1, 1);
    }

    func_01ff9758(gMapStateManager->unk_08, gMapStateManager->unk_c30);
    func_01ff976c(gMapStateManager->unk_08, gMapStateManager->unk_cb0);

    if (arg_2 != 0)
    {
        gMapStateManager->unk_14->unk_04->unk_17 = 1;
    }

    return;
}

EC void func_ov000_021a378c(void)
{
    func_0201db38((void *)func_ov000_021a35a0, 7, 0x12, 0x1000, 0);
    return;
}

EC BOOL func_ov000_021a37b4(void)
{
    return func_0201dc30(7);
}

EC void func_ov000_021a37c4(void)
{
    if (data_ov000_021e3324->unk_02 == 0)
    {
        func_020a5824(gMapStateManager->unk_db0, 0xff, 0x80);
        func_020a5824(gMapStateManager->unk_d30, 0xff, 0x80);
        return;
    }

    func_020a5824(gMapStateManager->unk_db0, 0, 0x80);
    func_020a5824(gMapStateManager->unk_d30, 0, 0x80);

    if (data_02196f0c->state & 0x40)
    {
        func_ov000_021a3a30(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);
    }
    else
    {
        func_ov000_021a3974(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);
    }

    func_ov000_021a3974(gMapStateManager->unk_db0, data_ov000_021e3324->phase);
    gMapStateManager->unk_14->unk_04->unk_18 = 1;

    return;
}

EC void func_ov000_021a38b4(void)
{
    if (data_ov000_021e3324->unk_02 == 0)
    {
        func_020a5824(gMapStateManager->unk_d30, 0xff, 0x80);
        return;
    }

    func_020a5824(gMapStateManager->unk_d30, 0, 0x80);

    if (data_02196f0c->state & 0x40)
    {
        func_ov000_021a3a30(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);
    }
    else
    {
        func_ov000_021a3974(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);
    }

    func_ov000_021a3974(gMapStateManager->unk_db0, data_ov000_021e3324->phase);
    gMapStateManager->unk_14->unk_04->unk_18 = 1;

    return;
}

EC void func_ov000_021a3974(u8 * arg_0, s32 arg_1)
{
    Force * force;
    s32 i;
    struct Unit * it;

    if (data_ov000_021e3324->unk_02 == 0)
    {
        return;
    }

    for (i = 0; i < 2; i++)
    {
        if (!((arg_1 == i) & 0xFF))
        {
            continue;
        }

        force = Force::Get(i);

        for (it = force->head; it != NULL; it = it->unk_3c)
        {
            if ((it->state2 & 0x21020) == 0)
            {
                func_ov000_021a3c20(arg_0, arg_1, it);
            }
        }
    }

    if (arg_0 == gMapStateManager->unk_d30)
    {
        gMapStateManager->unk_14->unk_04->unk_18 = 1;
        return;
    }

    return;
}

/* NONMATCHING: https://decomp.me/scratch/a3Clg */
EC void func_ov000_021a3c84(u8 * arg_0, s32 arg_1, s32 arg_2, s16 arg_3, s16 arg_4, s32 arg_5, s32 arg_6, u8 * arg_7)
{
    u8 tmp;
    s32 increment;

    if (data_ov000_021e3324->unk_02 == 0)
    {
        return;
    }

    if (!((arg_2 == arg_1) & 0xFF))
    {
        return;
    }

    while ((tmp = *arg_7 & 0x80) == 0)
    {
        func_ov000_021a3ad0(arg_0, arg_3, arg_4, arg_5);

        switch (*arg_7)
        {
            case 1:
                increment = -1;
                break;
            case 2:
                increment = +1;
                break;
            default:
                increment = 0;
                break;
        }

        arg_3 += increment;

        switch (*arg_7)
        {
            case 4:
                increment = +1;
                break;
            case 8:
                increment = -1;
                break;
            default:
                increment = 0;
                break;
        }

        arg_4 += increment;

        arg_7++;
    }

    func_ov000_021a3ad0(arg_0, arg_3, arg_4, arg_6);

    return;
}

EC void func_ov000_021a3a30(u8 * arg_0, u32 arg_1)
{
    s8 * it;
    s32 i;
    s32 j;

    u32 r6;
    r6 = GetJobByJidStr("JID_LORD\0\0\0")->unk_2a;

    if (data_ov000_021e3324->unk_02 == 0)
    {
        return;
    }

    i = 0;
    if (0 < data_ov000_021e3528.unk_2e)
    {
        it = data_ov000_021e3528.unk_00;
        j = 0;
        do
        {
            func_ov000_021a3ad0(arg_0, it[j], it[j + 1], r6);
            i++;
            j += 2;
        } while (i < data_ov000_021e3528.unk_2e);
    }

    if (arg_0 != gMapStateManager->unk_d30)
    {
        return;
    }

    gMapStateManager->unk_14->unk_04->unk_18 = 1;

    return;
}

EC void func_ov000_021a3ad0(u8 * arg_0, s16 x, s16 y, s32 range)
{
    s16 ix;
    s16 iy;
    s16 xMin;
    s16 yMin;
    s16 xMax;
    s16 yMax;

    if (data_ov000_021e3324->unk_02 == 0)
    {
        return;
    }

    xMin = MAX(x - range, gMapStateManager->unk_24);
    yMin = MAX(y - range, gMapStateManager->unk_25);

    xMax = MIN(x + range, gMapStateManager->unk_26 - 1);
    yMax = MIN(y + range, gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            s32 dy = ABS(y - iy);
            s32 dx = ABS(x - ix);

            if (dx + dy >= 0 && dx + dy <= range)
            {
                u32 pos = (ix | (iy << 5));
                arg_0[pos >> 3] |= (1 << (pos & 7));
            }
        }
    }

    if (arg_0 == gMapStateManager->unk_d30)
    {
        gMapStateManager->unk_14->unk_04->unk_18 = 1;
    }
}

EC void func_ov000_021a3c20(u8 * arg_0, s32 arg_1, struct Unit * unit)
{
    s32 y;
    s32 x;

    if (data_ov000_021e3324->unk_02 == 0)
    {
        return;
    }

    if (!((unit->force->id == arg_1) & 0xFF))
    {
        return;
    }

    y = unit->yPos;
    x = unit->xPos;

    func_ov000_021a3ad0(arg_0, x, y, func_ov000_021a4854(unit));

    return;
}

EC BOOL func_ov000_021a3d7c(u32 faction)
{
    return (faction == data_ov000_021e3324->unk_01) & 0xFF;
}

EC BOOL func_ov000_021a3da0(struct Unit * unit)
{
    return func_ov000_021a3d7c(unit->force->id);
}

/* NONMATCHING: https://decomp.me/scratch/EKthD */
EC BOOL func_ov000_021a3db4(s16 x, s16 y, BOOL arg_2)
{
    s16 xMax;
    s16 xMin;
    s16 yMax;
    s16 yMin;
    s16 ix;
    s16 iy;

    xMin = MAX(x - 1, gMapStateManager->unk_24);
    yMin = MAX(y - 1, gMapStateManager->unk_25);

    xMax = MIN(x + 1, gMapStateManager->unk_26 - 1);
    yMax = MIN(y + 1, gMapStateManager->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            s32 val = ABS(x - ix) + ABS(y - iy);

            if (val >= 1 && val <= 1)
            {
                if (arg_2)
                {
                    if (gMapStateManager->unk_08->unk_0854[ix | (iy << 5)] != 0 &&
                        gMapStateManager->unk_028[ix | (iy << 5)] != 0)
                    {
                        continue;
                    }
                }

                if (gMapStateManager->unk_08->unk_0854[ix | (iy << 5)] >= 0)
                {
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

/* NONMATCHING: https://decomp.me/scratch/fz686 */
EC void func_ov000_021a3ee4(struct Unit * unit, s32 arg_1)
{
    s32 i;
    Force * force;
    struct PersonData * pPersonDataB;
    struct PersonData * pPersonDataA;
    struct Unit * it;

    func_020a5734(0, gMapStateManager->unk_e30, 0x80);

    if (func_ov000_021a47e4() != 0)
    {
        return;
    }

    for (i = 0; i < 2; i++)
    {
        force = Force::Get(i);
        for (it = force->head; it != NULL; it = it->unk_3c)
        {
            if (gMapStateManager->unk_db0[(it->xPos | it->yPos << 5) >> 3] & ((1 << it->xPos) & 7))
            {
                pPersonDataA = func_0203c378(it)->pPersonData;
                pPersonDataB = func_0203c378(unit)->pPersonData;

                if (!_ZN11EventCaller13func_02048610EPcS0_(pPersonDataA->unk_00, pPersonDataB->unk_00))
                {
                    continue;
                }

                if (!func_ov000_021a3db4(it->xPos, it->yPos, arg_1))
                {
                    continue;
                }

                gMapStateManager->unk_e30[(it->xPos | it->yPos << 5) >> 3] |= ((1 << it->xPos) & 7);
            }
        }
    }

    return;
}

static inline BOOL IsOutOfBounds(s32 x, s32 y)
{
    if (x < 0)
    {
        return TRUE;
    }

    if (y < 0)
    {
        return TRUE;
    }

    if (x >= gMapStateManager->unk_20)
    {
        return TRUE;
    }

    if (y >= gMapStateManager->unk_22)
    {
        return TRUE;
    }

    return FALSE;
}

EC void * func_ov000_021a418c(s32 arg_0)
{
    struct Unit * unit;

    if (gMapStateManager == NULL)
    {
        return NULL;
    }

    if (arg_0 != 0)
    {
        unit = func_0203fff4(arg_0, 3);
    }
    else
    {
        unit = data_021974f0;
    }

    if (unit == NULL)
    {
        return NULL;
    }

    if (!IsOutOfBounds(unit->xPos, unit->yPos))
    {
        u8 tile = gMapStateManager->unk_828[unit->xPos | (unit->yPos << 5)];
        return gFE11Database->pTerrain[tile].unk_04;
    }

    return NULL;
}

EC s32 GetMapBgmId(s32 factionId)
{
    u32 idx;

    if (!data_02196f24->enableBgm)
    {
        return -1;
    }

    if (data_02196f0c->state & 0x40)
    {
        return BGM_SYS_SINGEKI1;
    }

    idx = 0;

    if (data_ov000_021e3324->unk_02 != 0)
    {
        idx = 1;
    }

    if (data_02196f0c->state & 0x20)
    {
        if (data_ov000_021e3320[factionId] == 1)
        {
            if (AreAllEnemiesDefeated(factionId))
            {
                idx = 2;
            }

            return gPlMapMusicLut[data_02196f0c->pCurrentMap->unk_18[idx]];
        }

        return gCpMapMusicLut[data_02196f0c->pCurrentMap->unk_18[idx]];
    }

    if (factionId == 0)
    {
        if (AreAllEnemiesDefeated(factionId))
        {
            idx = 2;
        }

        return gPlMapMusicLut[data_02196f0c->pCurrentMap->unk_18[idx]];
    }

    return gCpMapMusicLut[data_02196f0c->pCurrentMap->unk_18[idx]];
}

EC BOOL AreAllEnemiesDefeated(u32 factionId)
{
    struct Unit * it;
    s32 count = 0;
    s32 i;

    if ((data_02196f0c->state & 0x400) != 0)
    {
        return FALSE;
    }

    for (i = 0; i < 2; i++)
    {
        if ((factionId == i) & 0xFF)
        {
            continue;
        }

        for (it = Force::Get(i)->head; it != NULL; it = it->unk_3c)
        {
            count++;
        }
    }

    return count <= 0;
}

EC void func_ov000_021a43e8(void)
{
    s32 bgmId = GetMapBgmId(data_ov000_021e3324->phase);

    gSoundManager->unk_a8->vfunc_6c(0x7f);

    if (bgmId == -1)
    {
        return;
    }

    if (gSoundManager->unk_a8->vfunc_50())
    {
        if (data_02196f0c->flagMgr->GetByName("gf_complete"))
        {
            StartSoundWaitTo_02017b40(gSoundManager->unk_a4, gSoundManager->unk_a8, 0x10);
            return;
        }

        if ((gSoundManager->unk_a4->vfunc_58() || (bgmId != gSoundManager->unk_a4->unk_08)))
        {
            StartSoundWaitTo_02017938(gSoundManager->unk_a4, gSoundManager->unk_a8, 0x10, bgmId, 0);
        }
        else
        {
            StartSoundWaitTo_0201775c(gSoundManager->unk_a4, gSoundManager->unk_a8, 0x10, 0x10);
        }

        return;
    }

    if (data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        gSoundManager->unk_a4->vfunc_38(0x10);
        return;
    }

    if (bgmId != gSoundManager->unk_a4->unk_08)
    {
        gSoundManager->unk_a4->vfunc_3c(0x10, bgmId, 0);
    }
    else
    {
        if (gSoundManager->unk_a4->vfunc_54())
        {
            gSoundManager->unk_a4->vfunc_4c(0x10);
        }
    }

    return;
}

EC void func_ov000_021a45cc(struct Unit * unit, u32 arg_1)
{
    if (!data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        if (func_ov000_021adabc(unit, 0) != 0)
        {
            if ((arg_1 == 0 || !func_ov000_021a98ec(unit->xPos, unit->yPos)))
            {
                if (gSoundManager->unk_a8->vfunc_50() != 0)
                {
                    StartSoundWaitTo_02017b40(gSoundManager->unk_a4, gSoundManager->unk_a8, 0x10);
                    return;
                }

                gSoundManager->unk_a4->vfunc_38(0x10);

                return;
            }
        }
    }

    func_ov000_021a43e8();

    return;
}

EC void func_ov000_021a4694(void)
{
    func_ov000_021a45cc(gMapStateManager->unk_04->unk_00, 1);
    return;
}

EC void func_ov000_021a46b8(void)
{
    func_ov000_021a45cc(NULL, 0);
    return;
}

/* NONMATCHING: https://decomp.me/scratch/DvhHi */
EC void func_ov000_021a46cc(struct Unit * unit, u32 arg_1)
{
    gMapStateManager->cursor->SetPosImmediate(unit->xPos, unit->yPos);
    gMapStateManager->camera->func_ov000_021a4e84(unit->xPos, unit->yPos, arg_1);
    return;
}

EC void func_ov000_021a4718(void)
{
    return;
}

EC BOOL func_ov000_021a471c(void)
{
    if (gMapStateManager == 0)
    {
        return FALSE;
    }

    if (func_ov000_021a475c() != 0)
    {
        return TRUE;
    }

    return func_ov000_021a47ac() != 0;
}

EC BOOL func_ov000_021a475c(void)
{
    if (data_ov000_021e3324->unk_0c == 0)
    {
        return FALSE;
    }

    if (data_ov000_021e3324->unk_08 == 0)
    {
        return TRUE;
    }

    return FALSE;
}

EC BOOL func_ov000_021a478c(void)
{
    return (data_02196f0c->state & 0x20) != 0;
}

EC BOOL func_ov000_021a47ac(void)
{
    if (func_ov000_021a478c() == 0)
    {
        return FALSE;
    }

    if (func_02012298() != 0)
    {
        return TRUE;
    }

    return func_02012584() != 0;
}

EC BOOL func_ov000_021a47e4(void)
{
    return (data_02196f0c->state & 0x10000) != 0;
}

/* NONMATCHING: https://decomp.me/scratch/VvUaN */
EC BOOL func_ov000_021a4804(void)
{
    if (func_ov000_021a47e4() == 0)
    {
        return FALSE;
    }

    if (data_02196f10->unk_0b == 0)
    {
        return FALSE;
    }

    if (((data_02196f10->unk_00 != 0) & 0xFF) == 0)
    {
        return FALSE;
    }

    return TRUE;
}

EC s32 func_ov000_021a4854(struct Unit * unit)
{
    s32 range;
    s32 i;
    BOOL bVar1;
    struct UnkStruct_Func_02021410_Ret * iVar4;

    range = func_0203c790(unit);

    if (func_ov000_021a4804() != 0)
    {
        bVar1 = FALSE;

        for (i = 0; i < 2; i++)
        {
            iVar4 = func_02021410(i);

            if (iVar4->unk_756 == 0x11)
            {
                bVar1 = TRUE;
                break;
            }
        }

        if ((bVar1) && (range > 1))
        {
            range = 1;
        }
    }

    return range;
}

EC void func_ov000_021a48b0(u32 arg_0)
{
    data_ov000_021e3324->unk_08 = arg_0;
    data_ov000_021e3324->unk_10 = data_027e1264;
    return;
}

EC void func_ov000_021a48d8(void)
{
    s32 iVar1 = data_027e1264;
    s32 uVar3 = iVar1 - data_ov000_021e3324->unk_10;

    if (data_ov000_021e3324->unk_08 > uVar3)
    {
        data_ov000_021e3324->unk_08 = data_ov000_021e3324->unk_08 - uVar3;
    }
    else
    {
        data_ov000_021e3324->unk_08 = 0;
    }

    data_ov000_021e3324->unk_10 = iVar1;

    return;
}

EC BOOL func_ov000_021a491c(struct Unit * unit)
{
    if (func_ov000_021a478c() != 0)
    {
        return FALSE;
    }

    if (func_ov000_021a47e4() != 0)
    {
        return FALSE;
    }

    if (unit->force->id >= 2)
    {
        return TRUE;
    }

    return data_ov000_021e3320[unit->force->id] == 1;
}

void ProcMapEnd::Init(void)
{
    func_ov000_021b9bec(gMapStateManager->unk_14);
    return;
}

void ProcMapDraw::Init(void)
{
    func_ov000_021b9c3c(gMapStateManager->unk_14);
    return;
}

void ProcMapLow::Init(void)
{
    gMapStateManager->cursor->Update();
    func_ov000_021b9bc4(gMapStateManager->unk_14);
    gMapStateManager->camera->func_ov000_021a5128();

    if (gMapStateManager->unk_eb8 == 0)
    {
        return;
    }

    func_ov000_021a35a0();

    return;
}

void ProcMapBegin::Init(void)
{
    func_ov000_021b9bac(gMapStateManager->unk_14);
    return;
}

ProcMapBegin::~ProcMapBegin()
{
    return;
}

ProcMapLow::~ProcMapLow()
{
    return;
}

ProcMapDraw::~ProcMapDraw()
{
    return;
}

ProcMapEnd::~ProcMapEnd()
{
    return;
}
