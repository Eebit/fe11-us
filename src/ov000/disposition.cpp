#include "global.h"

#include <new>

#include "database.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "unit.hpp"

#include "unknown_types.hpp"

struct DisposGroupProcessor;

class Disposition : public ProcEx
{
public:
    /* 38 */ DisposGroupProcessor * head;
    /* 3C */ DisposGroupProcessor * tail;
    /* 40 */ s32 unk_40;

    Disposition()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    virtual ~Disposition()
    {
    }

    virtual void Loop(void);

    void _021d9d7c(DisposGroupProcessor *);
    void _021d9da8(DisposGroupProcessor *);
    void _021db3c4(void);
};

struct SpawnState
{
    /* 00 */ u8 unitId;
    /* 01 */ u8 flags;
    /* 02 */ s8 xPos;
    /* 03 */ s8 yPos;

    SpawnState();
};

EC s32 func_020b6e2c(char *, char *);

struct DisposGroupProcessor
{
    /* 00 */ Disposition * proc;
    /* 04 */ DisposGroupProcessor * prev;
    /* 08 */ DisposGroupProcessor * next;
    /* 0C */ char * label;
    /* 10 */ struct DisposGroup * disposGroup;
    /* 14 */ struct Spawn * spawns;
    /* 18 */ struct SpawnState * spawnStates;
    /* 1C */ u16 unk_1c;
    /* 1E */ u16 unk_1e;
    /* 20 */ u32 flags;

    DisposGroupProcessor(Disposition * proc, char * label, u32 flags)
    {
        DisposGroup * group;

        this->spawnStates = NULL;
        this->flags = flags;
        this->label = label;
        this->proc = proc;
        proc->_021d9d7c(this);
        this->unk_1c = 0;

        group = static_cast<DisposGroup *>(gMapStateManager->unk_18);

        if (group == NULL)
        {
            delete this;
        }
        else
        {
            while (TRUE)
            {
                if (group->label == NULL)
                {
                    group = NULL;
                    break;
                }

                if (func_020b6e2c(label, group->label) == 0)
                {
                    break;
                }

                group++;
            }

            this->disposGroup = group;

            if (group == NULL)
            {
                delete this;
            }
            else
            {
                this->spawns = group->spawns;
                this->_021daac8();
            }
        }
    }

    ~DisposGroupProcessor()
    {
        this->_021d9e38();
        this->proc->_021d9da8(this);
    }

    void _021d9df0(void);
    void _021d9e38(void);
    Unit * _021d9e50(s32 pid, s32 faction);
    Unit * _021d9e7c(s32 faction);
    Unit * _021d9ebc(s32 index, BOOL param_3);
    BOOL _021da030(s32 x, s32 y);
    BOOL _021da088(s32 x, s32 y);
    void _021da0fc(s32 index);
    void _021da230(s32 index, s32 param_3);
    void _021da3c0(s32 index, s32 param_3);
    void _021da7e4(void);
    void _021da8f4(void);
    void _021daac8(void);
    void _021dab34(BOOL param_2, BOOL param_3);
    void _021dac48(void);
    void _021dad04(void);
    void _021db160(void);
    void _021db1f4(void);
};

struct TMP
{
    STRUCT_PAD(0x00, 0x54);
    u16 unk_54;
    STRUCT_PAD(0x56, 0x68);
    u32 unk_68;
};

EC struct TMP * func_ov000_021bb4c8(void *);
EC struct TMP * func_ov000_021bb210(void *, Unit *);

EC s32 GetPersonDBIndex(struct PersonData *);

EC void func_02039ff8(Unit *, Spawn *);

EC void func_01ff8204(void *, s8, s8, s32, s32, u16);

extern struct UnkStruct_02196f0c * data_02196f0c;

EC BOOL FindUnitByPidAndFaction(s32, s32);

EC BOOL IsLinkArena(void);

EC BOOL func_ov000_021bb5d4(void *, s32, s32);

EC void func_0204bf74(void);

struct UnkStruct_021e3528
{
    s8 unk_00[0x2e];
    s8 unk_2e;
    s8 unk_2f;
};

extern struct UnkStruct_021e3528 data_ov000_021e3528;

static inline BOOL BoundsCheck(s32 param_1, s32 param_2)
{
    if (param_1 < gMapStateManager->unk_24)
    {
        return TRUE;
    }
    else if (param_2 < gMapStateManager->unk_25)
    {
        return TRUE;
    }
    else if (param_1 >= gMapStateManager->unk_26)
    {
        return TRUE;
    }
    else if (param_2 >= gMapStateManager->unk_27)
    {
        return TRUE;
    }

    return FALSE;
}

EC BOOL func_ov000_021baafc(void *, Unit *, BOOL);

EC void func_ov000_021a3974(void *, s32);
EC void func_ov000_021a340c(void);
EC void func_ov000_021a35a0(void);

EC s32 IntSys_Div(s32, s32);

EC BOOL func_ov000_021baafc(void *, Unit *, BOOL);

EC s32 func_ov000_021bb518(void *);
EC s32 func_ov000_021bb560(void *);

EC void func_ov000_021bb944(void);

EC void func_02001ca0(void *, s8, s8, s8, s8);
EC void func_ov000_021bb734(void *, Unit *, BOOL);
EC void func_ov000_021bc2b8(void *, void *, s32);

EC BOOL func_020252fc(void);

EC BOOL func_ov000_021baafc(void *, Unit *, BOOL);

EC void func_ov000_021a340c(void);
EC void func_ov000_021a36e0(void);

void Spawn::_021d9adc(struct JobData * job)
{
    u32 flags;

    u8 uVar1 = gMapStateManager->unk_08->unk_0874;

    if (job == NULL)
    {
        job = &gFE11Database->pJob[this->jid];
    }

    flags = 2;

    if (gMapStateManager->tst(this->xLoad, this->yLoad) || gMapStateManager->tst(this->xFinal, this->yFinal))
    {
        flags |= 0x200;
    }

    gMapStateManager->unk_08->unk_0874 = this->faction;
    func_01ff8204(gMapStateManager->unk_08, this->xLoad, this->yLoad, job->unk_28, 100, flags);
    gMapStateManager->unk_08->unk_0874 = uVar1;

    return;
}

void Spawn::_021d9bb0(struct JobData * job, s32 x, s32 y, s32 flags)
{
    u8 uVar1 = gMapStateManager->unk_08->unk_0874;

    if (job == NULL)
    {
        job = &gFE11Database->pJob[this->jid];
    }

    if (gMapStateManager->tst(this->xLoad, this->yLoad) || gMapStateManager->tst(this->xFinal, this->yFinal))
    {
        flags |= 0x200;
    }

    gMapStateManager->unk_08->unk_0874 = this->faction;
    func_01ff8204(gMapStateManager->unk_08, x, y, job->unk_28, 100, flags);
    gMapStateManager->unk_08->unk_0874 = uVar1;

    return;
}

void Spawn::_021d9c94(Unit * unit)
{
    return this->_021d9ca8(unit, this->xLoad, this->yLoad);
}

void Spawn::_021d9ca8(Unit * unit, s32 x, s32 y)
{
    if (unit->force->id == 4)
    {
        func_02039ff8(unit, this);
    }

    if ((GetPersonDBIndex(unit->pPersonData) == this->GetPid()) && (this->flags & SPAWN_FLAG_UNK_3))
    {
        unit->state2 |= US_UNK_9;
    }

    unit->xPos = x;
    unit->yPos = y;

    unit->unk_69 = this - static_cast<DisposGroup *>(gMapStateManager->unk_18)->spawns;

    if (this->flags & SPAWN_FLAG_BOSS)
    {
        unit->state1 |= CA_BOSS;
    }
    else
    {
        unit->state1 &= ~CA_BOSS;
    }

    if (this->flags & SPAWN_FLAG_NO_MOVE)
    {
        unit->state1 |= CA_UNK_27;
    }
    else
    {
        unit->state1 &= ~CA_UNK_27;
    }

    unit->MoveToForce(this->faction, TRUE);

    return;
}

void Disposition::_021d9d7c(DisposGroupProcessor * processor)
{
    if (this->head == NULL)
    {
        this->head = processor;
    }
    else
    {
        this->tail->next = processor;
    }

    processor->prev = this->tail;
    processor->next = NULL;

    this->tail = processor;

    return;
}

void Disposition::_021d9da8(DisposGroupProcessor * processor)
{
    if (processor->prev == NULL)
    {
        this->head = processor->next;
    }
    else
    {
        processor->prev->next = processor->next;
    }

    if (processor->next == NULL)
    {
        this->tail = processor->prev;
    }
    else
    {
        processor->next->prev = processor->prev;
    }

    if (this->head == NULL && this->tail == NULL)
    {
        Proc_End(this);
    }

    return;
}

void DisposGroupProcessor::_021d9df0(void)
{
    this->spawnStates = new SpawnState[this->disposGroup->count];
    return;
}

SpawnState::SpawnState()
{
    this->unitId = 0;
    this->flags = 0;
}

void DisposGroupProcessor::_021d9e38(void)
{
    if (this->spawnStates != NULL)
    {
        delete[] this->spawnStates;
    }

    return;
}

Unit * DisposGroupProcessor::_021d9e50(s32 pid, s32 faction)
{
    if (!IsLinkArena())
    {
        faction = 0;
    }

    return Force::Get(faction + 2)->FindByPid(pid);
}

Unit * DisposGroupProcessor::_021d9e7c(s32 faction)
{
    Force * force;
    Unit * pUnit;

    if (!IsLinkArena())
    {
        faction = 0;
    }

    force = Force::Get(faction + 2);

    for (pUnit = force->head; pUnit != NULL; pUnit = pUnit->next)
    {
        if (!(pUnit->state2 & US_UNK_11))
        {
            break;
        }
    }

    return pUnit;
}

Unit * DisposGroupProcessor::_021d9ebc(s32 index, BOOL param_3)
{
    Force * force;
    Unit * unit;
    Spawn * spawn;
    SpawnState * state;

    spawn = this->spawns + index;
    state = this->spawnStates + index;

    if ((spawn->flags & (SPAWN_FLAG_UNK_1 | SPAWN_FLAG_UNK_2 | SPAWN_FLAG_UNK_3)) && (data_02196f0c->state & GAME_STATE_BATTLE_PREP))
    {
        return NULL;
    }

    if (state->flags & (SPAWN_STATE_UNK_0 | SPAWN_STATE_UNK_1))
    {
        return NULL;
    }

    if ((param_3 != 0) && (!(spawn->flags & (SPAWN_FLAG_UNK_2 | SPAWN_FLAG_UNK_3))))
    {
        return NULL;
    }

    if (Force::Get(spawn->faction)->Count() >= 50)
    {
        state->flags |= SPAWN_STATE_UNK_0;
        return NULL;
    }

    unit = NULL;

    if (spawn->flags & (SPAWN_FLAG_UNK_1 | SPAWN_FLAG_UNK_2 | SPAWN_FLAG_UNK_3))
    {
        if (param_3 != 0)
        {
            unit = this->_021d9e50(spawn->pid, spawn->faction);
        }
        else
        {
            unit = this->_021d9e7c(spawn->faction);

            if (unit == NULL)
            {
                state->flags |= SPAWN_STATE_UNK_0;
            }
        }
    }
    else
    {
        if (spawn->faction == 0)
        {
            unit = Force::Get(2)->FindByPid(spawn->pid);

            if ((unit == NULL) && FindUnitByPidAndFaction(spawn->pid, ~2))
            {
                state->flags |= SPAWN_STATE_UNK_0;
                return NULL;
            }
        }

        if (unit == NULL)
        {
            if ((spawn->flags & SPAWN_FLAG_UNK_7) || spawn->faction != 0)
            {
                force = Force::Get(4);
                unit = force->head;
            }
        }

        if (unit == NULL)
        {
            state->flags |= SPAWN_STATE_UNK_0;
        }
    }

    return unit;
}

BOOL DisposGroupProcessor::_021da030(s32 x, s32 y)
{
    s32 i;
    SpawnState * it = this->spawnStates;

    for (i = 0; i < this->disposGroup->count; i++, it++)
    {
        if (!(it->flags & SPAWN_STATE_UNK_1))
        {
            continue;
        }

        if (x == it->xPos && y == it->yPos)
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL DisposGroupProcessor::_021da088(s32 x, s32 y)
{
    DisposGroupProcessor * it;

    for (it = this->proc->head; it != NULL; it = it->next)
    {
        if (it->_021da030(x, y) != 0)
        {
            return TRUE;
        }
    }

    return func_ov000_021bb5d4(gMapStateManager->unk_14->unk_00, x, y) != 0;
}

void DisposGroupProcessor::_021da0fc(s32 index)
{
    Spawn * spawn;
    Unit * unit;
    s32 x;
    s32 y;

    spawn = this->spawns + index;

    if (!(spawn->flags & (SPAWN_FLAG_UNK_1 | SPAWN_FLAG_UNK_2 | SPAWN_FLAG_UNK_3)))
    {
        return;
    }

    // TODO: Possibly an inline? This specific order matches
    y = spawn->yLoad;
    x = spawn->xLoad;

    if (data_ov000_021e3528.unk_2f == 0)
    {
        data_ov000_021e3528.unk_00[data_ov000_021e3528.unk_2e * 2 + 0] = x;
        data_ov000_021e3528.unk_00[data_ov000_021e3528.unk_2e * 2 + 1] = y;
        data_ov000_021e3528.unk_2e++;
    }

    if ((spawn->flags & (SPAWN_FLAG_UNK_1 | SPAWN_FLAG_UNK_2 | SPAWN_FLAG_UNK_3)) &&
        (data_02196f0c->state & GAME_STATE_BATTLE_PREP))
    {
        return;
    }

    if ((!(spawn->flags & SPAWN_FLAG_UNK_7)) && (data_02196f0c->state & GAME_STATE_UNK_0))
    {
        return;
    }

    if (Force::Get(spawn->faction)->FindByPid(spawn->pid) != NULL)
    {
        return;
    }

    if (Force::Get(2)->FindByPid(spawn->pid) != NULL)
    {
        return;
    }

    if (Force::Get(3)->FindByPid(spawn->pid) != NULL)
    {
        return;
    }

    unit = Force::Get(4)->head;

    if (unit == NULL)
    {
        this->spawnStates->flags |= SPAWN_STATE_UNK_0;
        return;
    }

    unit->MoveToForce(spawn->faction + 2, TRUE);
    func_02039ff8(unit, spawn);

    return;
}

void DisposGroupProcessor::_021da230(s32 index, s32 param_3)
{
    Unit * unit;
    Spawn * spawn;
    SpawnState * state;
    BOOL bVar6;

    unit = this->_021d9ebc(index, param_3);

    if (unit == NULL)
    {
        return;
    }

    spawn = this->spawns + index;
    state = this->spawnStates + index;

    if (spawn->xFinal < 0)
    {
        bVar6 = true;
    }
    else if (spawn->yFinal < 0)
    {
        bVar6 = true;
    }
    else if (spawn->xFinal < gMapStateManager->unk_20)
    {
        if (spawn->yFinal >= gMapStateManager->unk_22)
        {
            bVar6 = true;
        }
        else
        {
            bVar6 = false;
        }
    }
    else
    {
        bVar6 = true;
    }

    if (bVar6)
    {
        state->flags |= SPAWN_STATE_UNK_0;
        return;
    }

    if ((gMapStateManager->unk_428[spawn->xFinal | spawn->yFinal << 5] == 0) &&
        (this->_021da088(spawn->xFinal, spawn->yFinal) == 0))
    {
        if (spawn->xLoad == spawn->xFinal && spawn->yLoad == spawn->yFinal)
        {
            state->xPos = spawn->xFinal;
            state->yPos = spawn->yFinal;
            state->flags |= SPAWN_STATE_UNK_1;
        }
        else
        {
            spawn->_021d9adc(unit->pJobData);

            if (gMapStateManager->unk_08->unk_0854[spawn->xFinal | spawn->yFinal << 5] >= 0)
            {
                state->xPos = spawn->xFinal;
                state->yPos = spawn->yFinal;
                state->flags |= SPAWN_STATE_UNK_1;
            }
            else
            {
                if (!(spawn->flags & SPAWN_FLAG_UNK_0))
                {
                    state->flags |= SPAWN_STATE_UNK_0;
                }

                return;
            }
        }

        if (!(spawn->flags & SPAWN_FLAG_UNK_0))
        {
            state->flags |= SPAWN_STATE_UNK_0;
        }

        return;
    }

    spawn->_021d9c94(unit);
    state->unitId = unit->unk_68;
    this->unk_1e++;

    return;
}

void DisposGroupProcessor::_021da3c0(s32 index, s32 param_3)
{
    Unit * unit;
    Spawn * spawn;
    SpawnState * state;
    u8 cVar8;
    u16 ix;
    u16 iy;
    BOOL bVar11;
    u32 iStack_3c;
    u32 uStack_38;

    unit = this->_021d9ebc(index, param_3);

    if (unit == NULL)
    {
        return;
    }

    spawn = this->spawns + index;
    uStack_38 = spawn->xLoad;
    state = this->spawnStates + index;
    iStack_3c = spawn->yLoad;

    if (spawn->xFinal < 0)
    {
        bVar11 = true;
    }
    else if (spawn->yFinal < 0)
    {
        bVar11 = true;
    }
    else if (spawn->xFinal < gMapStateManager->unk_20)
    {
        if (spawn->yFinal < gMapStateManager->unk_22)
        {
            bVar11 = false;
        }
        else
        {
            bVar11 = true;
        }
    }
    else
    {
        bVar11 = true;
    }

    if (bVar11)
    {
        state->flags |= SPAWN_STATE_UNK_0;
        return;
    }

    gMapStateManager->unk_08->unk_0854 = gMapStateManager->unk_08->unk_0c78;
    spawn->_021d9bb0(unit->pJobData, spawn->xFinal, spawn->yFinal, 0);
    gMapStateManager->unk_08->unk_0854 = gMapStateManager->unk_08->unk_0878;
    spawn->_021d9adc(unit->pJobData);
    cVar8 = 100;

    for (iy = 0; iy < gMapStateManager->unk_22; iy++)
    {
        for (ix = 0; ix < gMapStateManager->unk_20; ix++)
        {
            if (gMapStateManager->unk_08->unk_0878[ix | iy << 5] < 0)
            {
                continue;
            }

            if (gMapStateManager->unk_08->unk_0c78[ix | iy << 5] < 0)
            {
                continue;
            }

            if (gMapStateManager->unk_08->unk_0c78[ix | iy << 5] > cVar8)
            {
                continue;
            }

            if (gMapStateManager->unk_428[ix | iy << 5] != 0)
            {
                continue;
            }

            if (this->_021da088(ix, iy) == 0)
            {
                if (this->flags & GROUP_FLAG_UNK_3)
                {
                    if (BoundsCheck(ix, iy))
                    {
                        state->xPos = ix;
                        state->yPos = iy;
                        state->flags |= SPAWN_STATE_UNK_1;
                        cVar8 = gMapStateManager->unk_08->unk_0c78[ix | iy << 5];
                    }
                }
            }
        }
    }

    if (!(state->flags & SPAWN_STATE_UNK_1))
    {
        if (param_3 != 0)
        {
            return;
        }

        cVar8 = 100;

        for (iy = 0; iy < gMapStateManager->unk_22; iy++)
        {
            for (ix = 0; ix < gMapStateManager->unk_20; ix++)
            {
                if (gMapStateManager->unk_08->unk_0878[ix | iy << 5] < 0)
                {
                    continue;
                }

                if (gMapStateManager->unk_08->unk_0c78[ix | iy << 5] < 0)
                {
                    continue;
                }

                if (gMapStateManager->unk_08->unk_0c78[ix | iy << 5] > cVar8)
                {
                    continue;
                }

                if (gMapStateManager->unk_428[ix | iy << 5] != 0)
                {
                    continue;
                }

                if (this->_021da088(ix, iy) == 0)
                {
                    if (this->flags & GROUP_FLAG_UNK_3)
                    {
                        if (BoundsCheck(ix, iy))
                        {
                            state->xPos = ix;
                            state->yPos = iy;
                            state->flags |= SPAWN_STATE_UNK_1;
                            cVar8 = gMapStateManager->unk_08->unk_0c78[ix | iy << 5];
                            uStack_38 = ix;
                            iStack_3c = iy;
                        }
                    }
                }
            }
        }
    }

    if (!(state->flags & SPAWN_STATE_UNK_1))
    {
        state->flags |= SPAWN_STATE_UNK_0;
        return;
    }

    spawn->_021d9ca8(unit, uStack_38, iStack_3c);
    state->unitId = unit->unk_68;
    this->unk_1e++;

    return;
}

void DisposGroupProcessor::_021da7e4(void)
{
    s32 i;

    for (i = 0; i < this->disposGroup->count; i++)
    {
        this->_021da0fc(i);
    }

    for (i = 0; i < this->disposGroup->count; i++)
    {
        this->_021da230(i, 1);
    }

    for (i = 0; i < this->disposGroup->count; i++)
    {
        this->_021da3c0(i, 1);
    }

    for (i = 0; i < this->disposGroup->count; i++)
    {
        this->_021da230(i, 0);
    }

    for (i = 0; i < this->disposGroup->count; i++)
    {
        this->_021da3c0(i, 0);
    }

    return;
}

void DisposGroupProcessor::_021da8f4(void)
{
    SpawnState * it;
    s32 i;
    Unit * unit;

    it = this->spawnStates;

    this->unk_1e = 0;

    for (i = 0; i < this->disposGroup->count; i++, it++)
    {
        if (it->flags & SPAWN_STATE_UNK_1)
        {
            unit = GetUnit(it->unitId);

            if (this->flags & GROUP_FLAG_UNK_0)
            {
                func_ov000_021baafc(gMapStateManager->unk_14->unk_00, unit, 1);

                unit->SetPos(it->xPos, it->yPos);
                unit->alpha = 0x1f;

                if (gMapStateManager->tst(unit->xPos, unit->yPos))
                {
                    unit->state2 |= US_UNK_5;
                }
            }
            else
            {
                if (it->xPos == unit->xPos && it->yPos == unit->yPos)
                {
                    it->flags |= SPAWN_STATE_UNK_4;

                    if (gMapStateManager->tst(unit->xPos, unit->yPos))
                    {
                        unit->state2 |= US_UNK_5;
                    }
                }
                else
                {
                    unit->state2 |= US_NOT_PRESENT;
                    this->unk_1e++;
                }

                unit->alpha = 0;
            }
        }
    }

    if ((this->flags & GROUP_FLAG_UNK_1) || (this->flags & GROUP_FLAG_UNK_0))
    {
        func_ov000_021a3974(gMapStateManager->unk_db0, data_ov000_021e3324->phase);
        func_ov000_021a3974(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);
    }

    func_ov000_021a340c();

    if ((this->flags & GROUP_FLAG_UNK_1) && (!(this->flags & GROUP_FLAG_UNK_0)))
    {
        return;
    }

    func_ov000_021a35a0();

    return;
}

void DisposGroupProcessor::_021daac8(void)
{
    this->_021d9df0();
    this->_021da7e4();
    this->_021da8f4();

    if (!(this->flags & GROUP_FLAG_UNK_0))
    {
        return;
    }

    if (this->flags & GROUP_FLAG_UNK_1)
    {
        this->_021dab34(1, 0);
    }

    func_0204bf74();

    delete this;

    return;
}

void DisposGroupProcessor::_021dab34(BOOL param_2, BOOL param_3)
{
    s32 yCamera;
    s32 xCamera;

    SpawnState * it = this->spawnStates;
    s32 count = 0;
    s32 i = 0;
    s32 x = 0;
    s32 y = 0;

    for (; i < this->disposGroup->count; i++, it++)
    {
        if (!(it->flags & SPAWN_STATE_UNK_1))
        {
            continue;
        }

        if (!param_3 || ((gMapStateManager->unk_d30[((x | y << 5) >> 3)] & (1 << (x & 7))) & 0xFF))
        {
            count++;
            x += it->xPos;
            y += it->yPos;
        }
    }

    if (count == 0)
    {
        return;
    }

    xCamera = IntSys_Div(x, count);
    yCamera = IntSys_Div(y, count);

    if (!param_2)
    {
        gMapStateManager->camera->Scroll(xCamera, yCamera, 1, 0x20, 0);
        return;
    }

    gMapStateManager->camera->ScrollInstant(xCamera, yCamera, 1);

    return;
}

void DisposGroupProcessor::_021dac48(void)
{
    Unit * unit;
    SpawnState * it;
    s32 i;

    it = this->spawnStates;

    for (i = 0; i < this->disposGroup->count; i++, it++)
    {
        if (this->proc->unk_40 >= 1)
        {
            return;
        }

        if (!(it->flags & SPAWN_STATE_UNK_1))
        {
            continue;
        }

        unit = GetUnit(it->unitId);

        if (func_ov000_021baafc(gMapStateManager->unk_14->unk_00, unit, 0))
        {
            this->proc->unk_40++;
        }
    }

    return;
}

void DisposGroupProcessor::_021dad04(void)
{
    BOOL bVar3;
    BOOL bVar1;
    BOOL bVar4;
    s32 i;
    SpawnState * state;
    Spawn * spawn;
    s32 alpha;

    bVar3 = TRUE;
    bVar1 = FALSE;
    bVar4 = FALSE;

    if (this->unk_1c == 0)
    {
        return;
    }

    if (this->flags & GROUP_FLAG_UNK_1)
    {
        if (gMapStateManager->camera->IsMoving())
        {
            return;
        }

        this->flags &= ~GROUP_FLAG_UNK_1;

        func_ov000_021a3974(gMapStateManager->unk_db0, data_ov000_021e3324->phase);
        func_ov000_021a3974(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);

        func_ov000_021a340c();
        func_ov000_021a35a0();
    }

    if (this->unk_1e != 0)
    {
        if (this->unk_1e <= func_ov000_021bb518(gMapStateManager->unk_14->unk_00))
        {
            bVar1 = 1;
        }

        this->unk_1e = 0;
    }

    if (!func_ov000_021bb560(gMapStateManager->unk_14->unk_00))
    {
        this->unk_1e = 0;
        bVar1 = TRUE;
    }

    spawn = this->spawns;
    state = this->spawnStates;

    for (i = 0; i < this->disposGroup->count; i++, spawn++, state++)
    {
        Unit * unit;

        if (!(state->flags & SPAWN_STATE_UNK_1))
        {
            continue;
        }

        unit = GetUnit(state->unitId);

        if (state->flags & (SPAWN_STATE_UNK_3 | SPAWN_STATE_UNK_4))
        {
            alpha = unit->alpha;

            if (alpha < 0x1f)
            {
                alpha = alpha + 2;

                if (func_020252fc() != 0)
                {
                    alpha = alpha + 2;
                }

                if (alpha >= 0x1f)
                {
                    alpha = 0x1f;
                }

                unit->alpha = alpha;

                if (alpha != 0x1f)
                {
                    bVar3 = FALSE;
                }
            }
        }
        else
        {
            bVar3 = FALSE;

            if (bVar1)
            {
                struct TMP * iVar7 = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);

                if (iVar7 != NULL)
                {
                    state->flags |= SPAWN_STATE_UNK_3;
                    spawn->_021d9bb0(unit->pJobData, unit->xPos, unit->yPos, 2);
                    func_02001ca0(gMapStateManager->unk_08, unit->xPos, unit->yPos, state->xPos, state->yPos);
                    func_ov000_021bb734(iVar7, unit, 1);
                    iVar7->unk_68 = 0x1000;
                    func_ov000_021bc2b8(iVar7, gMapStateManager->unk_08, 0x800);
                }
            }
        }

        if (state->flags & SPAWN_STATE_UNK_3)
        {
            struct TMP * iVar7 = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);

            if ((iVar7 == NULL) || ((!(iVar7->unk_54 & 1) ? TRUE : FALSE) & 0xFF))
            {
                unit->state2 &= ~US_NOT_PRESENT;

                if (iVar7 != 0)
                {
                    func_ov000_021bb944();
                }

                state->flags &= ~SPAWN_STATE_UNK_3;
                state->flags |= SPAWN_STATE_UNK_4;

                if (gMapStateManager->tst(unit->xPos, unit->yPos))
                {
                    unit->state2 |= US_UNK_5;
                }

                bVar4 = TRUE;
            }
            else
            {
                bVar3 = FALSE;
            }
        }
    }

    if (bVar4)
    {
        func_ov000_021a3974(gMapStateManager->unk_db0, data_ov000_021e3324->phase);
        func_ov000_021a3974(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);
        func_ov000_021a340c();
        func_ov000_021a35a0();
    }

    if (bVar3)
    {
        func_0204bf74();
        delete this;
    }

    return;
}

void Disposition::Loop(void)
{
    DisposGroupProcessor * it;
    DisposGroupProcessor * next;

    this->unk_40 = 0;

    for (it = this->head; it != NULL; it = next)
    {
        next = it->next;
        it->_021dac48();
    }

    if (this->unk_40 == 0)
    {
        for (it = this->head; it != NULL; it = next)
        {
            next = it->next;
            if ((it->unk_1c == 0) && (it->flags & GROUP_FLAG_UNK_1))
            {
                it->_021dab34(0, ((it->flags & GROUP_FLAG_UNK_2) ? TRUE : FALSE) & 0xFF);
            }

            it->unk_1c = 1;
        }
    }

    for (it = this->head; it != NULL; it = next)
    {
        next = it->next;
        it->_021dad04();
    }

    return;
}

void DisposGroupProcessor::_021db160(void)
{
    SpawnState * it;
    s32 i;

    it = this->spawnStates;

    for (i = 0; i < this->disposGroup->count; i++, it++)
    {
        if (!(it->flags & SPAWN_STATE_UNK_1))
        {
            continue;
        }

        func_ov000_021baafc(gMapStateManager->unk_14->unk_00, GetUnit(it->unitId), 1);
    }

    return;
}

void DisposGroupProcessor::_021db1f4(void)
{
    SpawnState * it;
    s32 i;

    it = this->spawnStates;

    for (i = 0; i < this->disposGroup->count; i++, it++)
    {
        if (it->flags & SPAWN_STATE_UNK_1)
        {
            Unit * unit = GetUnit(it->unitId);

            if (it->flags & (SPAWN_STATE_UNK_3 | SPAWN_STATE_UNK_4))
            {
                if (unit->alpha < 0x1f)
                {
                    unit->alpha = 0x1f;
                }
            }
            else
            {
                unit->SetPos(it->xPos, it->yPos);
                unit->state2 &= ~US_NOT_PRESENT;
                unit->alpha = 0x1f;
                it->flags |= SPAWN_STATE_UNK_4;

                if (gMapStateManager->tst(unit->xPos, unit->yPos))
                {
                    unit->state2 |= US_UNK_5;
                }
            }

            if ((it->flags & SPAWN_STATE_UNK_3) && (func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit) != 0))
            {
                unit->state2 &= ~US_NOT_PRESENT;
                func_ov000_021bb944();
                it->flags &= ~SPAWN_STATE_UNK_3;
                it->flags |= SPAWN_STATE_UNK_4;

                if (gMapStateManager->tst(unit->xPos, unit->yPos))
                {
                    unit->state2 |= US_UNK_5;
                }
            }
        }
    }

    func_ov000_021a3974(gMapStateManager->unk_db0, data_ov000_021e3324->phase);
    func_ov000_021a3974(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);

    func_ov000_021a340c();
    func_ov000_021a36e0();

    delete this;

    return;
}

void Disposition::_021db3c4(void)
{
    DisposGroupProcessor * it;
    DisposGroupProcessor * next;

    for (it = this->head; it != NULL; it = next)
    {
        next = it->next;
        it->_021db160();
    }

    for (it = this->head; it != NULL; it = next)
    {
        next = it->next;

        if ((it->unk_1c == 0) && (it->flags & GROUP_FLAG_UNK_1))
        {
            it->_021dab34(1, (it->flags & GROUP_FLAG_UNK_2) & 0xff);
        }

        it->unk_1c = 1;
    }

    for (it = this->head; it != NULL; it = next)
    {
        next = it->next;
        it->_021db1f4();
    }

    func_0204bf74();

    return;
}

EC void Disposition_Loop(Disposition * proc)
{
    proc->Loop();
    return;
}

EC s32 func_ov000_021db48c(void)
{
    s32 count;
    s32 i;

    count = 0;

    for (i = 0; i < 2; i++)
    {
        Force * force = Force::Get(i);
        count += force->Count();
    }

    return count;
}

// clang-format off

struct ProcCmd ProcScr_Disposition[] =
{
    PROC_NAME,
    PROC_REPEAT(Disposition_Loop),
    PROC_END,
};

// clang-format on

EC BOOL StartDisposition(char * label, s32 flags)
{
    s32 count = func_ov000_021db48c();

    Disposition * proc = static_cast<Disposition *>(Proc_Find(ProcScr_Disposition));

    if (proc == NULL)
    {
        proc = new (Proc_Start(ProcScr_Disposition, PROC_TREE_9)) Disposition;
    }

    new DisposGroupProcessor(proc, label, flags);

    return count < func_ov000_021db48c();
}

EC BOOL IsDispositionActive(void)
{
    return Proc_Find(ProcScr_Disposition) != NULL;
}

EC void Disposition_021db624(void)
{
    Disposition * proc = static_cast<Disposition *>(Proc_Find(ProcScr_Disposition));

    if (proc != NULL)
    {
        proc->_021db3c4();
    }

    return;
}
