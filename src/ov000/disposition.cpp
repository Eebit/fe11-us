#include "global.h"

#include <new>

#include "map.hpp"
#include "proc_ex.hpp"
#include "unit.h"

struct astruct_27;

class Disposition : public ProcEx
{
public:
    /* 38 */ astruct_27 * unk_38;
    /* 3C */ astruct_27 * unk_3c;
    /* 40 */ s32 unk_40;

    Disposition()
    {
        this->unk_38 = NULL;
        this->unk_3c = NULL;
    }

    virtual ~Disposition()
    {
    }
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
    /* 06 */ s8 unk_06;
    /* 07 */ s8 unk_07;
    /* 08 */ u8 unk_08;
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
};

// DisposGroup
struct DisposGroup
{
    /* 00 */ char * unk_00; // label
    /* 04 */ struct Spawn * unk_04; // spawns
    /* 08 */ s32 unk_08; // count
};

struct astruct_27_18
{
    /* 00 */ u8 unk_00;
    /* 01 */ u8 unk_01;
    /* 02 */ s8 unk_02;
    /* 03 */ s8 unk_03;

    astruct_27_18();
};

EC void func_ov000_021d9d7c(Disposition *, astruct_27 *);
EC void func_ov000_021d9e38(astruct_27 *);
EC void func_ov000_021daac8(astruct_27 *);
EC void func_ov000_021d9da8(Disposition *, astruct_27 *);

EC s32 func_020b6e2c(char *, char *);

struct astruct_27
{
    /* 00 */ Disposition * unk_00;
    /* 04 */ astruct_27 * unk_04;
    /* 08 */ astruct_27 * unk_08;
    /* 0C */ char * unk_0c;
    /* 10 */ struct DisposGroup * unk_10;
    /* 14 */ struct Spawn * unk_14;
    /* 18 */ struct astruct_27_18 * unk_18;
    /* 1C */ u16 unk_1c;
    /* 1E */ u16 unk_1e;
    /* 20 */ u32 unk_20;

    astruct_27(Disposition * proc, char * label, u32 param_2)
    {
        DisposGroup * group;

        this->unk_18 = 0;
        this->unk_20 = param_2;
        this->unk_0c = label;
        this->unk_00 = proc;
        func_ov000_021d9d7c(proc, this);
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
                if (group->unk_00 == NULL)
                {
                    group = NULL;
                    break;
                }

                if (func_020b6e2c(label, group->unk_00) == 0)
                {
                    break;
                }

                group++;
            }

            this->unk_10 = group;

            if (group == NULL)
            {
                delete this;
            }
            else
            {
                this->unk_14 = group->unk_04;
                func_ov000_021daac8(this);
            }
        }
    }

    ~astruct_27()
    {
        func_ov000_021d9e38(this);
        func_ov000_021d9da8(this->unk_00, this);
    }
};

struct TMP
{
    STRUCT_PAD(0x00, 0x54);
    u16 unk_54;
    STRUCT_PAD(0x56, 0x68);
    u32 unk_68;
};

EC struct TMP * func_ov000_021bb4c8(void *);
EC struct TMP * func_ov000_021bb210(void *, struct Unit *);

EC s32 GetPersonDBIndex(struct PersonData *);

EC void func_02039ff8(struct Unit *, Spawn *);
EC void func_0203bd34(struct Unit *, s32, s32);

struct Unknown_02197254
{
    void * unk_00;
    void * unk_04;
    /* 08 */ struct PersonData * pPerson;
    /* 0C */ struct JobData * pJob;
    /* 10 */ struct ItemData * pItem;
    STRUCT_PAD(0x14, 0x20);
    /* 20 */ struct TerrainData * pTerrain;
    STRUCT_PAD(0x24, 0x2C);
    /* 2C */ u8 * pWeaponLevel;
    STRUCT_PAD(0x30, 0x38);
    /* 38 */ struct Unit_unk_a4 ** unk_38;
    STRUCT_PAD(0x3C, 0x48);
    /* 48 */ struct DBFE11Footer * pDBFE11Footer;
};

extern struct Unknown_02197254 * data_02197254; // FE11 database

EC void func_01ff8204(void *, s8, s8, s32, s32, u16);

struct UnkStruct_02196f0c
{
    /* 00 */ struct UnkStruct_02196f0c_00 * unk_00;
    /* 04 */ void * flagMgr;
    /* 08 */ void * valueMgr;
    /* 0C */ u32 state;
    /* 10 */ u32 unk_10;
    /* 14 */ u32 unk_14;
};

extern struct UnkStruct_02196f0c * data_02196f0c;

EC struct Unit ** func_02040c98(s32);
EC s32 func_02040c74(struct Unit **);
EC struct Unit * func_02040d44(struct Unit **, s32);
EC BOOL func_0203fd60(s32, s32);

EC BOOL func_ov000_021a47e4(void);

EC struct Unit * func_ov000_021d9e50(astruct_27 *, s32, s32);

EC BOOL func_ov000_021bb5d4(void *, s32, s32);
EC void func_ov000_021dab34(astruct_27 *, BOOL, BOOL);

EC void func_ov000_021db160(astruct_27 *);
EC void func_ov000_021da8f4(astruct_27 *);
EC void func_ov000_021db1f4(astruct_27 *);

EC void func_0204bf74(void);

EC void func_ov000_021da0fc(astruct_27 *, s32);
EC void func_ov000_021da3c0(astruct_27 *, s32, s32);

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

extern struct Unit gUnitList[];

EC BOOL func_ov000_021baafc(void *, struct Unit *, BOOL);

EC void func_ov000_021a3974(void *, s32);
EC void func_ov000_021a340c(void);
EC void func_ov000_021a35a0(void);

EC s32 IntSys_Div(s32, s32);

EC BOOL func_ov000_021baafc(void *, struct Unit *, BOOL);

EC s32 func_ov000_021bb518(void *);
EC s32 func_ov000_021bb560(void *);

EC void func_ov000_021bb944(void);

EC void func_02001ca0(void *, s8, s8, s8, s8);
EC void func_ov000_021bb734(void *, struct Unit *, BOOL);
EC void func_ov000_021bc2b8(void *, void *, s32);

EC BOOL func_020252fc(void);

EC BOOL func_ov000_021baafc(void *, struct Unit *, BOOL);

EC void func_ov000_021bb944(void);
EC void func_ov000_021a340c(void);
EC void func_ov000_021a36e0(void);

EC struct Unit ** func_02040c98(s32);
EC s32 func_02040c74(struct Unit **);

EC void func_ov000_021d9ca8(Spawn *, struct Unit *, s8, s8);

static inline struct Unit * GetUnit(s32 id)
{
    if (id == 0)
    {
        return NULL;
    }
    else
    {
        return gUnitList + id - 1;
    }
}

EC void func_ov000_021d9adc(Spawn * spawn, struct JobData * job)
{
    u32 flags;

    u8 uVar1 = gMapStateManager->unk_08->unk_0874;

    if (job == NULL)
    {
        job = &data_02197254->pJob[spawn->jid];
    }

    flags = 2;

    if (gMapStateManager->tst(spawn->xLoad, spawn->yLoad) || gMapStateManager->tst(spawn->unk_06, spawn->unk_07))
    {
        flags |= 0x200;
    }

    gMapStateManager->unk_08->unk_0874 = spawn->unk_08;
    func_01ff8204(gMapStateManager->unk_08, spawn->xLoad, spawn->yLoad, job->unk_28, 100, flags);
    gMapStateManager->unk_08->unk_0874 = uVar1;

    return;
}

EC void func_ov000_021d9bb0(Spawn * spawn, struct JobData * job, s32 x, s32 y, s32 flags)
{
    u8 uVar1 = gMapStateManager->unk_08->unk_0874;

    if (job == NULL)
    {
        job = &data_02197254->pJob[spawn->jid];
    }

    if (gMapStateManager->tst(spawn->xLoad, spawn->yLoad) || gMapStateManager->tst(spawn->unk_06, spawn->unk_07))
    {
        flags |= 0x200;
    }

    gMapStateManager->unk_08->unk_0874 = spawn->unk_08;
    func_01ff8204(gMapStateManager->unk_08, x, y, job->unk_28, 100, flags);
    gMapStateManager->unk_08->unk_0874 = uVar1;

    return;
}

EC void func_ov000_021d9c94(Spawn * spawn, struct Unit * unit)
{
    return func_ov000_021d9ca8(spawn, unit, spawn->xLoad, spawn->yLoad);
}

EC void func_ov000_021d9ca8(Spawn * spawn, struct Unit * unit, s8 x, s8 y)
{
    if (unit->unk_4c->unk_08 == 4)
    {
        func_02039ff8(unit, spawn);
    }

    if ((GetPersonDBIndex(unit->pPersonData) == spawn->pid) && ((spawn->flags & 8) != 0))
    {
        unit->state2 |= 0x200;
    }

    unit->xPos = x;
    unit->yPos = y;

    unit->unk_69 = spawn - static_cast<DisposGroup *>(gMapStateManager->unk_18)->unk_04;

    if ((spawn->flags & 0x20) != 0)
    {
        unit->state1 |= 0x1000;
    }
    else
    {
        unit->state1 &= ~0x1000;
    }

    if ((spawn->flags & 0x40) != 0)
    {
        unit->state1 |= 0x8000000;
    }
    else
    {
        unit->state1 &= ~0x8000000;
    }

    func_0203bd34(unit, spawn->unk_08, 1);

    return;
}

EC void func_ov000_021d9d7c(Disposition * self, astruct_27 * param_2)
{
    if (self->unk_38 == NULL)
    {
        self->unk_38 = param_2;
    }
    else
    {
        self->unk_3c->unk_08 = param_2;
    }

    param_2->unk_04 = self->unk_3c;
    param_2->unk_08 = NULL;

    self->unk_3c = param_2;

    return;
}

EC void func_ov000_021d9da8(Disposition * self, astruct_27 * param_2)
{
    if (param_2->unk_04 == NULL)
    {
        self->unk_38 = param_2->unk_08;
    }
    else
    {
        param_2->unk_04->unk_08 = param_2->unk_08;
    }

    if (param_2->unk_08 == NULL)
    {
        self->unk_3c = param_2->unk_04;
    }
    else
    {
        param_2->unk_08->unk_04 = param_2->unk_04;
    }

    if (self->unk_38 == NULL && self->unk_3c == NULL)
    {
        Proc_End(self);
    }

    return;
}

EC void func_ov000_021d9df0(astruct_27 * self)
{
    self->unk_18 = new astruct_27_18[self->unk_10->unk_08];
    return;
}

// func_ov000_021d9e28
astruct_27_18::astruct_27_18()
{
    this->unk_00 = 0;
    this->unk_01 = 0;
}

EC void func_ov000_021d9e38(astruct_27 * self)
{
    if (self->unk_18 != NULL)
    {
        delete[] self->unk_18;
    }

    return;
}

EC struct Unit * func_ov000_021d9e50(astruct_27 * param_1, s32 param_2, s32 param_3)
{
    if (func_ov000_021a47e4() == 0)
    {
        param_3 = 0;
    }

    return func_02040d44(func_02040c98(param_3 + 2), param_2);
}

EC struct Unit * func_ov000_021d9e7c(astruct_27 * param_1, s32 param_2)
{
    struct Unit ** puVar3;
    struct Unit * pUnit;

    if (func_ov000_021a47e4() == 0)
    {
        param_2 = 0;
    }

    puVar3 = func_02040c98(param_2 + 2);

    for (pUnit = *puVar3; pUnit != NULL; pUnit = pUnit->unk_3c)
    {
        if (!(pUnit->state2 & 0x800))
        {
            break;
        }
    }

    return pUnit;
}

EC struct Unit * func_ov000_021d9ebc(astruct_27 * self, s32 param_2, BOOL param_3)
{
    struct Unit ** pUnitStack;
    struct Unit * unit;
    Spawn * spawn;
    astruct_27_18 * paVar2;

    spawn = self->unk_14 + param_2;
    paVar2 = self->unk_18 + param_2;

    if (((spawn->flags & 0xe) != 0) && ((data_02196f0c->state & 0x40) != 0))
    {
        return NULL;
    }

    if ((paVar2->unk_01 & 3) != 0)
    {
        return NULL;
    }

    if ((param_3 != 0) && ((spawn->flags & 0xc) == 0))
    {
        return NULL;
    }

    if (func_02040c74(func_02040c98(spawn->unk_08)) >= 0x32)
    {
        paVar2->unk_01 |= 1;
        return NULL;
    }

    unit = NULL;

    if ((spawn->flags & 0xe) != 0)
    {
        if (param_3 != 0)
        {
            unit = func_ov000_021d9e50(self, spawn->pid, spawn->unk_08);
        }
        else
        {
            unit = func_ov000_021d9e7c(self, spawn->unk_08);

            if (unit == NULL)
            {
                paVar2->unk_01 |= 1;
            }
        }
    }
    else
    {
        if (spawn->unk_08 == 0)
        {
            unit = func_02040d44(func_02040c98(2), spawn->pid);

            if ((unit == NULL) && func_0203fd60(spawn->pid, ~2))
            {
                paVar2->unk_01 |= 1;
                return NULL;
            }
        }

        if (unit == NULL)
        {
            if ((spawn->flags & 0x80) || spawn->unk_08 != 0)
            {
                pUnitStack = func_02040c98(4);
                unit = *pUnitStack;
            }
        }

        if (unit == NULL)
        {
            paVar2->unk_01 |= 1;
        }
    }

    return unit;
}

EC BOOL func_ov000_021da030(astruct_27 * self, s32 param_2, s32 param_3)
{
    s32 i;
    astruct_27_18 * it = self->unk_18;

    for (i = 0; i < self->unk_10->unk_08; i++, it++)
    {
        if (!(it->unk_01 & 2))
        {
            continue;
        }

        if (param_2 == it->unk_02 && param_3 == it->unk_03)
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL func_ov000_021da088(astruct_27 * self, s32 param_2, s32 param_3)
{
    astruct_27 * it;

    for (it = self->unk_00->unk_38; it != NULL; it = it->unk_08)
    {
        if (func_ov000_021da030(it, param_2, param_3) != 0)
        {
            return TRUE;
        }
    }

    return func_ov000_021bb5d4(gMapStateManager->unk_14->unk_00, param_2, param_3) != 0;
}

EC void func_ov000_021da0fc(astruct_27 * self, s32 index)
{
    struct Unit ** pUnitStack;
    Spawn * spawn;
    struct Unit * unit;

    spawn = self->unk_14 + index;

    if ((spawn->flags & 0xe) == 0)
    {
        return;
    }

    if (data_ov000_021e3528.unk_2f == 0)
    {
        data_ov000_021e3528.unk_00[data_ov000_021e3528.unk_2e * 2 + 0] = spawn->xLoad;
        data_ov000_021e3528.unk_00[data_ov000_021e3528.unk_2e * 2 + 1] = spawn->yLoad;
        data_ov000_021e3528.unk_2e++;
    }

    if (((spawn->flags & 0xe) != 0) && ((data_02196f0c->state & 0x40) != 0))
    {
        return;
    }

    if (((spawn->flags & 0x80) == 0) && ((data_02196f0c->state & 1) != 0))
    {
        return;
    }

    if (func_02040d44(func_02040c98(spawn->unk_08), spawn->pid) != 0)
    {
        return;
    }

    if (func_02040d44(func_02040c98(2), spawn->pid) != 0)
    {
        return;
    }

    if (func_02040d44(func_02040c98(3), spawn->pid) != 0)
    {
        return;
    }

    pUnitStack = func_02040c98(4);
    unit = *pUnitStack;

    if (unit == NULL)
    {
        self->unk_18->unk_01 |= 1;
        return;
    }

    func_0203bd34(unit, spawn->unk_08 + 2, 1);
    func_02039ff8(unit, spawn);

    return;
}

EC void func_ov000_021da230(astruct_27 * self, s32 index, s32 param_3)
{
    struct Unit * unit;
    Spawn * spawn;
    astruct_27_18 * paVar7;
    BOOL bVar6;

    unit = func_ov000_021d9ebc(self, index, param_3);

    if (unit == NULL)
    {
        return;
    }

    spawn = self->unk_14 + index;
    paVar7 = self->unk_18 + index;

    if (spawn->unk_06 < 0)
    {
        bVar6 = true;
    }
    else if (spawn->unk_07 < 0)
    {
        bVar6 = true;
    }
    else if (spawn->unk_06 < gMapStateManager->unk_20)
    {
        if (spawn->unk_07 >= gMapStateManager->unk_22)
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
        paVar7->unk_01 |= 1;
        return;
    }

    if ((gMapStateManager->unk_428[spawn->unk_06 | spawn->unk_07 << 5] == 0) &&
        (func_ov000_021da088(self, spawn->unk_06, spawn->unk_07) == 0))
    {
        if (spawn->xLoad == spawn->unk_06 && spawn->yLoad == spawn->unk_07)
        {
            paVar7->unk_02 = spawn->unk_06;
            paVar7->unk_03 = spawn->unk_07;
            paVar7->unk_01 |= 2;
        }
        else
        {
            func_ov000_021d9adc(spawn, unit->pJobData);

            if (gMapStateManager->unk_08->unk_0854[spawn->unk_06 | spawn->unk_07 << 5] >= 0)
            {
                paVar7->unk_02 = spawn->unk_06;
                paVar7->unk_03 = spawn->unk_07;
                paVar7->unk_01 |= 2;
            }
            else
            {
                if ((spawn->flags & 1) == 0)
                {
                    paVar7->unk_01 |= 1;
                }

                return;
            }
        }

        if ((spawn->flags & 1) == 0)
        {
            paVar7->unk_01 |= 1;
        }

        return;
    }

    func_ov000_021d9c94(spawn, unit);
    paVar7->unk_00 = unit->unk_68;
    self->unk_1e++;

    return;
}

EC void func_ov000_021da3c0(astruct_27 * self, s32 index, s32 param_3)
{
    struct Unit * unit;
    Spawn * spawn;
    u16 ix;
    astruct_27_18 * paVar6;
    u8 cVar9;
    u8 cVar8;
    s32 iVar9;
    u16 iy;
    BOOL bVar11;
    u32 iStack_3c;
    u32 uStack_38;

    unit = func_ov000_021d9ebc(self, index, param_3);

    if (unit == NULL)
    {
        return;
    }

    spawn = self->unk_14 + index;
    uStack_38 = spawn->xLoad;
    paVar6 = self->unk_18 + index;
    iStack_3c = spawn->yLoad;

    if (spawn->unk_06 < 0)
    {
        bVar11 = true;
    }
    else if (spawn->unk_07 < 0)
    {
        bVar11 = true;
    }
    else if (spawn->unk_06 < gMapStateManager->unk_20)
    {
        if (spawn->unk_07 < gMapStateManager->unk_22)
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
        paVar6->unk_01 |= 1;
        return;
    }

    gMapStateManager->unk_08->unk_0854 = gMapStateManager->unk_08->unk_0c78;
    func_ov000_021d9bb0(spawn, unit->pJobData, spawn->unk_06, spawn->unk_07, 0);
    gMapStateManager->unk_08->unk_0854 = gMapStateManager->unk_08->unk_0878;
    func_ov000_021d9adc(spawn, unit->pJobData);
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

            if (func_ov000_021da088(self, ix, iVar9) == 0)
            {
                if ((self->unk_20 & 8) != 0)
                {
                    if (BoundsCheck(ix, iy))
                    {
                        paVar6->unk_02 = ix;
                        paVar6->unk_03 = iy;
                        paVar6->unk_01 |= 2;
                        cVar8 = gMapStateManager->unk_08->unk_0c78[ix | iy << 5];
                    }
                }
            }
        }
    }

    if ((paVar6->unk_01 & 2) == 0)
    {
        if (param_3 != 0)
        {
            return;
        }

        cVar9 = 100;

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

                if (func_ov000_021da088(self, ix, iVar9) == 0)
                {
                    if ((self->unk_20 & 8) != 0)
                    {
                        if (BoundsCheck(ix, iy))
                        {
                            paVar6->unk_02 = ix;
                            paVar6->unk_03 = iy;
                            paVar6->unk_01 |= 2;
                            cVar8 = gMapStateManager->unk_08->unk_0c78[ix | iy << 5];
                            uStack_38 = ix;
                            iStack_3c = iy;
                        }
                    }
                }
            }
        }
    }

    if ((paVar6->unk_01 & 2) == 0)
    {
        paVar6->unk_01 |= 1;
        return;
    }

    func_ov000_021d9ca8(spawn, unit, uStack_38, iStack_3c);
    paVar6->unk_00 = unit->unk_68;
    self->unk_1e++;

    return;
}

EC void func_ov000_021da7e4(astruct_27 * self)
{
    s32 i;

    for (i = 0; i < self->unk_10->unk_08; i++)
    {
        func_ov000_021da0fc(self, i);
    }

    for (i = 0; i < self->unk_10->unk_08; i++)
    {
        func_ov000_021da230(self, i, 1);
    }

    for (i = 0; i < self->unk_10->unk_08; i++)
    {
        func_ov000_021da3c0(self, i, 1);
    }

    for (i = 0; i < self->unk_10->unk_08; i++)
    {
        func_ov000_021da230(self, i, 0);
    }

    for (i = 0; i < self->unk_10->unk_08; i++)
    {
        func_ov000_021da3c0(self, i, 0);
    }

    return;
}

EC void func_ov000_021da8f4(astruct_27 * self)
{
    u32 yTmp;
    astruct_27_18 * paVar3;
    s32 i;
    struct Unit * unit;

    paVar3 = self->unk_18;

    self->unk_1e = 0;

    for (i = 0; i < self->unk_10->unk_08; i++, paVar3++)
    {
        if ((paVar3->unk_01 & 2) != 0)
        {
            if (paVar3->unk_00 != 0)
            {
                unit = gUnitList + paVar3->unk_00 - 1;
            }
            else
            {
                unit = NULL;
            }

            if ((self->unk_20 & 1) != 0)
            {
                func_ov000_021baafc(gMapStateManager->unk_14->unk_00, unit, 1);

                yTmp = paVar3->unk_03;
                unit->xPos = paVar3->unk_02;
                unit->yPos = yTmp;
                unit->alpha = 0x1f;

                if (gMapStateManager->tst(unit->xPos, unit->yPos))
                {
                    unit->state2 |= 0x20;
                }
            }
            else
            {
                if (paVar3->unk_02 == unit->xPos && paVar3->unk_03 == unit->yPos)
                {
                    paVar3->unk_01 |= 0x10;

                    if (gMapStateManager->tst(unit->xPos, unit->yPos))
                    {
                        unit->state2 |= 0x20;
                    }
                }
                else
                {
                    unit->state2 |= 0x1000;
                    self->unk_1e++;
                }

                unit->alpha = 0;
            }
        }
    }

    if (((self->unk_20 & 2) == 0) || ((self->unk_20 & 1) != 0))
    {
        func_ov000_021a3974(gMapStateManager->unk_db0, data_ov000_021e3324->phase);
        func_ov000_021a3974(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);
    }

    func_ov000_021a340c();

    if (((self->unk_20 & 2) != 0) && ((self->unk_20 & 1) == 0))
    {
        return;
    }

    func_ov000_021a35a0();

    return;
}

EC void func_ov000_021daac8(astruct_27 * self)
{
    func_ov000_021d9df0(self);
    func_ov000_021da7e4(self);
    func_ov000_021da8f4(self);

    if ((self->unk_20 & 1) == 0)
    {
        return;
    }

    if ((self->unk_20 & 2) != 0)
    {
        func_ov000_021dab34(self, 1, 0);
    }

    func_0204bf74();

    delete self;

    return;
}

EC void func_ov000_021dab34(astruct_27 * self, BOOL param_2, BOOL param_3)
{
    s32 uVar2;
    s32 uVar1;

    astruct_27_18 * it = self->unk_18;
    s32 iVar7 = 0;
    s32 i = 0;
    s32 x = 0;
    s32 y = 0;

    for (; i < self->unk_10->unk_08; i++, it++)
    {
        if (!(it->unk_01 & 2))
        {
            continue;
        }

        if (!param_3 || ((gMapStateManager->unk_d30[((x | y << 5) >> 3)] & (1 << (x & 7))) & 0xFF))
        {
            iVar7++;
            x += it->unk_02;
            y += it->unk_03;
        }
    }

    if (iVar7 == 0)
    {
        return;
    }

    uVar1 = IntSys_Div(x, iVar7);
    uVar2 = IntSys_Div(y, iVar7);

    if (!param_2)
    {
        gMapStateManager->camera->func_ov000_021a4cec(uVar1, uVar2, 1, 0x20, 0);
        return;
    }

    gMapStateManager->camera->func_ov000_021a4e84(uVar1, uVar2, 1);

    return;
}

EC void func_ov000_021dac48(astruct_27 * self)
{
    struct Unit * unit;
    astruct_27_18 * it;
    s32 i;

    it = self->unk_18;

    for (i = 0; i < self->unk_10->unk_08; i++, it++)
    {
        if (self->unk_00->unk_40 >= 1)
        {
            return;
        }

        if (!(it->unk_01 & 2))
        {
            continue;
        }

        if (it->unk_00 != 0)
        {
            unit = gUnitList + it->unk_00 - 1;
        }
        else
        {
            unit = NULL;
        }

        if (func_ov000_021baafc(gMapStateManager->unk_14->unk_00, unit, 0))
        {
            self->unk_00->unk_40++;
        }
    }

    return;
}

EC void func_ov000_021dad04(astruct_27 * self)
{
    BOOL bVar3;
    BOOL bVar1;
    BOOL bVar4;
    s32 i;
    astruct_27_18 * paVar10;
    Spawn * spawn;
    s32 uVar8;

    bVar3 = TRUE;
    bVar1 = FALSE;
    bVar4 = FALSE;

    if (self->unk_1c == 0)
    {
        return;
    }

    if ((self->unk_20 & 2) != 0)
    {
        if (gMapStateManager->camera->unk_18 >= 2 ? TRUE : FALSE)
        {
            return;
        }

        self->unk_20 &= ~2;

        func_ov000_021a3974(gMapStateManager->unk_db0, data_ov000_021e3324->phase);
        func_ov000_021a3974(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);

        func_ov000_021a340c();
        func_ov000_021a35a0();
    }

    if (self->unk_1e != 0)
    {
        if (self->unk_1e <= func_ov000_021bb518(gMapStateManager->unk_14->unk_00))
        {
            bVar1 = 1;
        }
        self->unk_1e = 0;
    }

    if (!func_ov000_021bb560(gMapStateManager->unk_14->unk_00))
    {
        self->unk_1e = 0;
        bVar1 = TRUE;
    }

    spawn = self->unk_14;
    paVar10 = self->unk_18;

    for (i = 0; i < self->unk_10->unk_08; i++, spawn++, paVar10++)
    {
        struct Unit * unit;

        if (!(paVar10->unk_01 & 2))
        {
            continue;
        }

        if (paVar10->unk_00 != 0)
        {
            unit = gUnitList + paVar10->unk_00 - 1;
        }
        else
        {
            unit = NULL;
        }

        if ((paVar10->unk_01 & 0x18))
        {
            uVar8 = unit->alpha;

            if (uVar8 < 0x1f)
            {
                uVar8 = uVar8 + 2;

                if (func_020252fc() != 0)
                {
                    uVar8 = uVar8 + 2;
                }

                if (uVar8 >= 0x1f)
                {
                    uVar8 = 0x1f;
                }

                unit->alpha = uVar8;

                if (uVar8 != 0x1f)
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
                    paVar10->unk_01 |= 8;
                    func_ov000_021d9bb0(spawn, unit->pJobData, unit->xPos, unit->yPos, 2);
                    func_02001ca0(gMapStateManager->unk_08, unit->xPos, unit->yPos, paVar10->unk_02, paVar10->unk_03);
                    func_ov000_021bb734(iVar7, unit, 1);
                    iVar7->unk_68 = 0x1000;
                    func_ov000_021bc2b8(iVar7, gMapStateManager->unk_08, 0x800);
                }
            }
        }

        if ((paVar10->unk_01 & 8) != 0)
        {
            struct TMP * iVar7 = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);

            if ((iVar7 == NULL) || ((!(iVar7->unk_54 & 1) ? TRUE : FALSE) & 0xFF))
            {
                unit->state2 &= 0xffffefff;

                if (iVar7 != 0)
                {
                    func_ov000_021bb944();
                }

                paVar10->unk_01 &= ~8;
                paVar10->unk_01 |= 0x10;

                if (gMapStateManager->tst(unit->xPos, unit->yPos))
                {
                    unit->state2 |= 0x20;
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
        delete self;
    }

    return;
}

// TODO: virtual function
EC void func_ov000_021db09c(Disposition * self)
{
    astruct_27 * it;
    astruct_27 * next;

    self->unk_40 = 0;

    for (it = self->unk_38; it != NULL; it = next)
    {
        next = it->unk_08;
        func_ov000_021dac48(it);
    }

    if (self->unk_40 == 0)
    {
        for (it = self->unk_38; it != NULL; it = next)
        {
            next = it->unk_08;
            if ((it->unk_1c == 0) && ((it->unk_20 & 2) != 0))
            {
                func_ov000_021dab34(it, 0, ((it->unk_20 & 4) ? TRUE : FALSE) & 0xFF);
            }

            it->unk_1c = 1;
        }
    }

    for (it = self->unk_38; it != NULL; it = next)
    {
        next = it->unk_08;
        func_ov000_021dad04(it);
    }

    return;
}

EC void func_ov000_021db160(astruct_27 * self)
{
    astruct_27_18 * it;
    s32 i;

    it = self->unk_18;

    for (i = 0; i < self->unk_10->unk_08; i++, it++)
    {
        if (!(it->unk_01 & 2))
        {
            continue;
        }

        func_ov000_021baafc(gMapStateManager->unk_14->unk_00, GetUnit(it->unk_00), 1);
    }

    return;
}

EC void func_ov000_021db1f4(astruct_27 * self)
{
    astruct_27_18 * it;
    s32 i;

    it = self->unk_18;

    for (i = 0; i < self->unk_10->unk_08; i++, it++)
    {
        if ((it->unk_01 & 2) != 0)
        {
            struct Unit * unit;

            if (it->unk_00 != 0)
            {
                unit = gUnitList + it->unk_00 - 1;
            }
            else
            {
                unit = NULL;
            }

            if ((it->unk_01 & 0x18) != 0)
            {
                if (unit->alpha < 0x1f)
                {
                    unit->alpha = 0x1f;
                }
            }
            else
            {
                u32 yTmp = it->unk_03;
                unit->xPos = it->unk_02;
                unit->yPos = yTmp;

                unit->state2 &= ~0x1000;
                unit->alpha = 0x1f;
                it->unk_01 |= 0x10;

                if (gMapStateManager->tst(unit->xPos, unit->yPos))
                {
                    unit->state2 |= 0x20;
                }
            }

            if (((it->unk_01 & 8) != 0) && (func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit) != 0))
            {
                unit->state2 &= ~0x1000;
                func_ov000_021bb944();
                it->unk_01 &= ~8;
                it->unk_01 |= 0x10;

                if (gMapStateManager->tst(unit->xPos, unit->yPos))
                {
                    unit->state2 |= 0x20;
                }
            }
        }
    }

    func_ov000_021a3974(gMapStateManager->unk_db0, data_ov000_021e3324->phase);
    func_ov000_021a3974(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01);

    func_ov000_021a340c();
    func_ov000_021a36e0();

    delete self;

    return;
}

EC void func_ov000_021db3c4(Disposition * self)
{
    astruct_27 * it;
    astruct_27 * next;

    for (it = self->unk_38; it != NULL; it = next)
    {
        next = it->unk_08;
        func_ov000_021db160(it);
    }

    for (it = self->unk_38; it != NULL; it = next)
    {
        next = it->unk_08;

        if ((it->unk_1c == 0) && ((it->unk_20 & 2) != 0))
        {
            func_ov000_021dab34(it, 1, ((it->unk_20 & 4) != 0) & 0xff);
        }

        it->unk_1c = 1;
    }

    for (it = self->unk_38; it != NULL; it = next)
    {
        next = it->unk_08;
        func_ov000_021db1f4(it);
    }

    func_0204bf74();

    return;
}

EC void func_ov000_021db478(Disposition * proc)
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
        struct Unit ** pUnitStack = func_02040c98(i);
        count += func_02040c74(pUnitStack);
    }

    return count;
}

extern struct ProcCmd data_ov000_021e32f8[];

EC BOOL func_ov000_021db4bc(char * label, s32 param_2)
{
    astruct_27 * puVar3;

    s32 count = func_ov000_021db48c();

    Disposition * proc = static_cast<Disposition *>(Proc_Find(data_ov000_021e32f8));

    if (proc == NULL)
    {
        proc = new (Proc_Start(data_ov000_021e32f8, PROC_TREE_9)) Disposition;
    }

    puVar3 = new astruct_27(proc, label, param_2);

    return count < func_ov000_021db48c();
}

EC BOOL func_ov000_021db604(void)
{
    return Proc_Find(data_ov000_021e32f8) != NULL;
}

EC void func_ov000_021db624(void)
{
    Disposition * proc = static_cast<Disposition *>(Proc_Find(data_ov000_021e32f8));

    if (proc != NULL)
    {
        func_ov000_021db3c4(proc);
    }

    return;
}
