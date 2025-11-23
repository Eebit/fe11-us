#include "global.h"

#include "save.hpp"
#include "unit.hpp"

// FE11 Database, in RAM
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

struct UnkStruct_02196f10_00_348
{
    /* 00 */ STRUCT_PAD(0x00, 0x20);
    /* 20 */ u16 unk_20;
    /* 22 */ STRUCT_PAD(0x22, 0x24);
    /* 24 */ s8 unk_24;
    /* 25 */ s8 unk_25;
    /* 26 */ s8 unk_26;
    /* 27 */ s8 unk_27;
};

struct UnkStruct_02196f10_00
{
    /* 000 */ struct Unit unk_000[5];
    /* 348 */ struct UnkStruct_02196f10_00_348 unk_348[0x19];
    /* 730 */ u8 unk_730[0x24];
    /* 754 */ u8 unk_754;
    /* 755 */ u8 unk_755;
    /* 756 */ u8 unk_756;
    /* 757 */ u8 unk_757;
};

EC void func_020a5824(void *, s32, s32);

EC struct PersonData * GetPersonByPidStr(char *);
EC void SaveUnit(struct Unit *, struct SaveBuffer *);
EC void func_0203bd34(struct Unit * unit, s32 arg_1, s32 arg_2);
EC void LoadUnit(struct Unit * unit, struct SaveBuffer * buf, s32 param_3);

EC void func_0203aa4c(struct Unit *, struct Unit *);
EC void func_020a58b8(void *, void *, u32);

EC struct ItemData * GetItemData(struct Item *);

struct DBFE11Footer
{
    u32 pidTableLength;
    u32 jidTableLength;
    u32 iidTableLength;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
};

EC s32 func_02037ffc(struct ItemData *);

extern struct UnkStruct_02196f10_00_348 data_021974e4[];

EC u16 func_02041294(u16, struct UnkStruct_02196f10_00_348 *, s8, s8, s32, s32, s32, s32); /* extern */
EC s32 IntSys_Div(s32, s32);
EC s32 GetJobMaxLevel(struct JobData *);
EC BOOL CheckUnitAttribute(struct Unit *, s32);
EC BOOL func_0203c7ac(struct Unit *, s32);
EC s32 GetUnitMaxHp(struct Unit *);
EC void func_0203d6dc(struct Unit *);
EC void func_0203d840(struct Unit *, s32, s32);

EC void func_02041590(UnkStruct_02196f10_00_348 *, SaveBuffer *);

EC s32 func_02022f4c(void);
EC s32 func_02022f54(void);

EC void func_0203bd34(struct Unit * unit, s32 arg_1, s32 arg_2);

// fwd decl

EC void func_02041644(UnkStruct_02196f10_00_348 *, SaveBuffer *, s32);

EC void func_02039fdc(struct Unit *, s32);

struct Unit * gUnitList = NULL;
struct Force * data_021974dc = NULL;

EC void func_0203fafc(void)
{
    if (gUnitList == NULL)
    {
        gUnitList = new Unit[0x8c];
    }

    if (data_021974dc == NULL)
    {
        data_021974dc = new Force[6];
    }

    return;
}

EC void func_0203fb68(void)
{
    s32 i;

    for (i = 0; i < 6; i++)
    {
        data_021974dc[i].Init(i);
    }

    for (i = 0; i < 0x8c; i++)
    {
        func_02039fdc(&gUnitList[i], i + 1);
        data_021974dc[4].InsertTail(&gUnitList[i]);
    }

    return;
}

EC struct Unit * func_0203fbe0(s32 factionId)
{
    Force * force;
    s32 i;

    for (i = 0; i < 6; i++)
    {
        if (!(factionId & (1 << i)))
        {
            continue;
        }

        force = Force::Get(i);

        if (force->head != NULL)
        {
            return force->head;
        }
    }

    return NULL;
}

EC u32 func_0203fc20(u32 param_1, u32 param_2, u32 param_3)
{
    struct Unit * it;
    s32 i;

    for (i = 0; i < 3; i++)
    {
        for (it = data_021974dc[i].head; it != NULL; it = it->unk_3c)
        {
            if (param_2 != 0)
            {
                if (!(it->state2 & param_2))
                {
                    continue;
                }
            }

            if (it->state2 & param_3)
            {
                continue;
            }

            it->unk_95 = param_1;
            param_1++;
        }
    }

    return param_1;
}

EC u32 func_0203fc88(void)
{
    return func_0203fc20(func_0203fc20(func_0203fc20(0, 0x200, 0x800), 0, 0xa00), 0x800, 0);
}

EC struct Unit * func_0203fcb8(s32 factionId)
{
    struct Unit * unit = NULL;
    s32 max = 0x8c;
    s32 i;
    struct Unit * it;

    for (i = 0, it = gUnitList; i < 0x8c; i++, it++)
    {
        if (!(factionId & (1 << it->force->id)))
        {
            continue;
        }

        if (max >= it->unk_95)
        {
            unit = it;
            max = it->unk_95;
        }
    }

    return unit;
}

EC struct Unit * func_0203fd10(struct PersonData * person, u32 factionId)
{
    s32 i;
    struct Unit * it;

    for (i = 0, it = gUnitList; i < 0x8c; i++, it++)
    {
        if (!(factionId & (1 << it->force->id)))
        {
            continue;
        }

        if (it->pPersonData != person)
        {
            continue;
        }

        return it;
    }

    return NULL;
}

EC struct Unit * func_0203fd60(u32 pid, u32 factionId)
{
    return func_0203fd10(data_02197254->pPerson + pid, factionId);
}

EC struct Unit * func_0203fd84(struct PersonData * person)
{
    s32 i;

    for (i = 0; i < 0x8c; i++)
    {
        struct Unit * tmp;
        struct Unit * unit = &gUnitList[i];

        tmp = func_0203c378(unit);

        if (tmp->pPersonData != person)
        {
            continue;
        }

        return unit;
    }

    return NULL;
}

EC struct Unit * func_0203feac(char * pidStr)
{
    return func_0203fd84(GetPersonByPidStr(pidStr));
}

EC struct Unit * func_0203febc(struct PersonData * person, u32 factionId)
{
    s32 i;
    struct Unit * it;

    for (i = 0; i < 0x8c; i++)
    {
        struct Unit * tmp;
        it = &gUnitList[i];

        if (!(factionId & (1 << it->force->id)))
        {
            continue;
        }

        tmp = func_0203c378(it);

        if (tmp->pPersonData != person)
        {
            continue;
        }

        return it;
    }

    return NULL;
}

EC struct Unit * func_0203fff4(char * pidStr, u32 param_2)
{
    return func_0203febc(GetPersonByPidStr(pidStr), param_2);
}

EC void func_0204000c(void)
{
    Force::Get(0)->MoveAllUnitsTo(2, 0);
    Force::Get(1)->MoveAllUnitsTo(4, 1);
    return;
}

EC void func_0204003c(struct Unit * unit)
{
    struct Unit * it;

    if (unit->unk_04 == 0)
    {
        return;
    }

    if ((unit->unk_00 & 0x10) == 0)
    {
        return;
    }

    for (it = unit->force->head; it != NULL; it = it->unk_3c)
    {
        if (it == unit)
        {
            continue;
        }

        if (it->unk_04 == unit->unk_04 && it->unk_05 == 0)
        {
            it->unk_05 = 1;
        }
    }

    return;
}

EC void func_02040094(SaveBuffer * save, u32 faction)
{
    Force * force;
    struct Unit * unit;
    int count;
    s32 i;
    s32 bVar7;

    i = 0;
    bVar7 = 1;

    for (i = 0; i < 6; i++)
    {
        if (i == 4)
        {
            continue;
        }

        if (!(faction & (1 << i)))
        {
            continue;
        }

        force = data_021974dc + i;

        if (force->Count() == 0)
        {
            continue;
        }

        for (unit = force->head; unit != NULL; unit = unit->unk_3c)
        {
            unit->unk_68 = bVar7;
            bVar7++;
        }
    }

    for (i = 0; i < 6; i++)
    {
        if (i == 4)
        {
            continue;
        }

        if (!(faction & (1 << i)))
        {
            continue;
        }

        force = data_021974dc + i;

        count = force->Count();

        if (count == 0)
        {
            continue;
        }

        save->WriteByte(i);
        save->WriteByte(count);

        for (unit = force->head; unit != NULL; unit = unit->unk_3c)
        {
            SaveUnit(unit, save);
        }
    }

    save->WriteByte(0xff);

    for (i = 0; i < 0x8c; i++)
    {
        gUnitList[i].unk_68 = i + 1;
    }

    return;
}

EC void func_020401d8(SaveBuffer * save, u32 faction)
{
    Force * force;
    s32 i;

    func_0203fb68();

    force = data_021974dc;

    while (TRUE)
    {
        s32 count;
        s32 uVar4 = save->ReadByte();

        if (uVar4 == 0xFF)
        {
            break;
        }

        count = save->ReadByte();

        for (i = 0; i < count; i++)
        {
            struct Unit * unit = force[4].head;
            func_0203bd34(unit, uVar4, 1);
            LoadUnit(unit, save, faction);
        }
    }

    return;
}

EC void func_0204026c(struct UnkStruct_02196f10_00 * arg0, u32 arg1)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        func_02039fdc(&arg0->unk_000[i], i);
        arg0->unk_000[i].force = Force::Get(4);
    }

    for (i = 0; i < 0x19; i++)
    {
        arg0->unk_348[i].unk_20 = 0;
    }

    func_020a5824(arg0->unk_730, 0, 0x24);

    arg0->unk_755 = arg1;
    arg0->unk_754 = 1;
    arg0->unk_756 = 0;
    arg0->unk_757 = 0;

    return;
}

EC struct UnkStruct_02196f10_00 *
func_020402f8(struct UnkStruct_02196f10_00 * arg0, struct UnkStruct_02196f10_00 * arg1)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        func_0203aa4c(&arg0->unk_000[i], &arg1->unk_000[i]);
        arg0->unk_000[i].force = arg1->unk_000[i].force;
    }

    for (i = 0; i < 0x19; i++)
    {
        func_020a58b8(&arg1->unk_348[i], &arg0->unk_348[i], 0x28);
    }

    func_020a58b8(arg1->unk_730, arg0->unk_730, 0x24);

    arg0->unk_754 = arg1->unk_754;
    arg0->unk_756 = arg1->unk_756;

    return arg0;
}

EC void func_02040394(struct UnkStruct_02196f10_00 * arg0)
{
    s32 sp4;
    s32 var_r6;
    s32 var_r7;
    struct ItemData * temp_r0_2;
    struct Unit * var_r11;

    func_0204026c(arg0, arg0->unk_755);

    for (var_r11 = Force::Get(0)->head; var_r11 != NULL; var_r11 = var_r11->unk_3c)
    {
        var_r6 = 0;

        for (sp4 = 0; sp4 < 5; sp4++)
        {
            struct Unit * unit = &arg0->unk_000[sp4];
            func_0203aa4c(&arg0->unk_000[sp4], func_0203c378(unit));

            unit->force = Force::Get(0);
            unit->unk_90 = 0;

            for (var_r7 = 0; var_r7 < 5; var_r7++)
            {
                struct Item * item = &unit->items[var_r7];
                temp_r0_2 = GetItemData(item);

                if (!(temp_r0_2->attributes & 0x80000000))
                {
                    continue;
                }

                func_020a58b8(
                    &data_021974e4[func_02037ffc(temp_r0_2) - data_02197254->pDBFE11Footer->iidTableLength],
                    &arg0->unk_348[var_r7], 0x28);
                item->id = data_02197254->pDBFE11Footer->iidTableLength + var_r6;
                var_r6++;
            }
        }
    }

    return;
}

EC void func_02040594(struct UnkStruct_02196f10_00 * arg0, s32 arg1)
{
    s32 temp_r6;
    s32 i;
    s32 j;
    s32 temp_r0_3;
    struct Force * force;
    struct Unit * unit;
    struct Item * var_r9;

    temp_r6 = data_02197254->pDBFE11Footer->iidTableLength;

    for (i = 0; i < 5; i++)
    {
        if (arg0->unk_000[i].force->id == 4)
        {
            continue;
        }

        for (j = 0; j < 5; j++)
        {
            var_r9 = arg0->unk_000[i].items + j;
            if (var_r9->id >= temp_r6)
            {
                temp_r0_3 = var_r9->id - temp_r6;
                var_r9->id = func_02041294(
                    arg0->unk_348[temp_r0_3].unk_20, &arg0->unk_348[temp_r0_3], arg0->unk_348[temp_r0_3].unk_24,
                    arg0->unk_348[temp_r0_3].unk_25, arg0->unk_348[temp_r0_3].unk_26, arg0->unk_348[temp_r0_3].unk_27,
                    0, 0);
            }
        }
    }

    force = Force::Get(4);
    for (i = 0; i < 5; i++)
    {
        if (arg0->unk_000[i].force->id == 4)
        {
            continue;
        }

        unit = force->head;
        func_0203bd34(unit, arg1, 1);
        func_0203aa4c(unit, &arg0->unk_000[i]);
        unit->unk_90 = 0;
    }

    return;
}

EC u32 func_020406bc(struct Unit * unit, u32 param_2)
{
    s32 uVar1;
    s32 level;
    s32 i;

    uVar1 = 0;

    for (i = 0; i < 5; i++, unit++)
    {
        if (unit->force->id == 4)
        {
            continue;
        }

        level = unit->level;

        if ((unit->pJobData->attributes & 0x800) != 0)
        {
            level += param_2;
        }

        if (level > uVar1)
        {
            uVar1 = level;
        }
    }

    return uVar1;
}

EC u32 func_0204070c(struct Unit * unit)
{
    return func_020406bc(unit, 15);
}

EC s32 func_0204071c(struct Unit * unit)
{
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;
    s32 level;
    s32 i;

    iVar1 = func_020406bc(unit, 20);
    iVar2 = 0;
    iVar3 = 0;

    for (i = 0; i < 5; i++, unit++)
    {
        if (unit->force->id == 4)
        {
            continue;
        }

        level = unit->level;

        iVar2++;

        if ((unit->pJobData->attributes & 0x800) != 0)
        {
            level += 20;
        }

        if (level < (iVar1 >> 1))
        {
            level = (iVar1 >> 1);
        }

        iVar3 += level;
    }

    return IntSys_Div(iVar3, iVar2);
}

static inline s32 min(s32 a, s32 b)
{
    if (a < b)
    {
        return a;
    }

    return b;
}

EC void func_0204078c(struct Unit * unit, s32 expInput)
{
    s32 exp;
    s32 level;
    s32 t;
    s32 loops;
    s32 adjusted;
    s32 levelFactor;
    s32 expToApply;
    struct Unit * cur;
    s32 j;
    s32 i;

    exp = min(expInput - func_0204071c(unit), 0);

    levelFactor = func_020406bc(unit, 20);

    for (i = 0; i < 5; i++, unit++)
    {
        cur = unit;

        if (cur->force->id == 4)
        {
            continue;
        }

        level = cur->level;

        if (cur->pJobData->attributes & 0x800)
        {
            level += 20;
        }

        adjusted = min((levelFactor >> 1) - level, 0);

        expToApply = exp + adjusted;

        for (loops = 0; loops < expToApply; loops++)
        {
            if (cur->level >= GetJobMaxLevel(cur->pJobData))
            {
                if (cur->pJobData->pPromoteJob == NULL)
                {
                    break;
                }

                if (CheckUnitAttribute(cur, 0x800000))
                {
                    break;
                }

                func_0203d840(cur, 0, 0);
            }
            else
            {
                func_0203d6dc(cur);
            }

            cur->hp = GetUnitMaxHp(cur);
            cur->exp = 0;
        }

        cur->unk_50[0] += (s8)IntSys_Div(expToApply, 3);
        cur->hp = GetUnitMaxHp(cur);

        if (func_0203c7ac(cur, 4) || func_0203c7ac(cur, 5))
        {
            cur->unk_50[2] += (s8)IntSys_Div(expToApply, 3);
        }
        else
        {
            cur->unk_50[1] += (s8)IntSys_Div(expToApply, 3);
        }

        cur->unk_50[3] += (s8)IntSys_Div(expToApply, 6);
        cur->unk_50[4] += (s8)IntSys_Div(expToApply, 6);
        cur->unk_50[5] += (s8)IntSys_Div(expToApply, 6);
        cur->unk_50[6] += (s8)IntSys_Div(expToApply, 6);

        t = expToApply * 7;

        for (j = 0; j < 6; j++)
        {
            if (cur->unk_84[j] + t <= 0xFF)
            {
                cur->unk_84[j] = cur->unk_84[j] + t;
            }
            else
            {
                cur->unk_84[j] = 0xFF;
            }
        }
    }
}

EC void func_020409d0(struct UnkStruct_02196f10_00 * arg0, SaveBuffer * arg1)
{
    s32 i;

    arg1->WriteByte(1);
    arg1->WriteByte(func_02022f4c());

    for (i = 0; i < 5; i++)
    {
        struct Unit * var_r5 = &arg0->unk_000[i];
        SaveUnit(var_r5, arg1);
        arg1->WriteByte(var_r5->force->id);
    }

    arg1->WriteByte(func_02022f54());

    for (i = 0; i < 0x19; i++)
    {
        func_02041590(&arg0->unk_348[i], arg1);
    }

    func_020a58b8(arg0->unk_730, arg1->unk_04, 0x24);
    arg1->unk_04 += 0x24;

    arg1->WriteByte(arg0->unk_756);

    return;
}

EC void func_02040abc(struct UnkStruct_02196f10_00 * arg0, SaveBuffer * save)
{
    s32 i;
    s32 temp_r5;
    s32 temp_r6;
    s32 var_r4_2;

    temp_r5 = save->ReadByte();

    func_0204026c(arg0, arg0->unk_755);
    temp_r6 = save->ReadByte();

    for (i = 0; i < 5; i++)
    {
        LoadUnit(&arg0->unk_000[i], save, temp_r6);
        arg0->unk_000[i].force = Force::Get(save->ReadByte());
    }

    var_r4_2 = 0;
    if (temp_r5 >= 1)
    {
        var_r4_2 = save->ReadByte();
    }

    for (i = 0; i < 0x19; i++)
    {
        func_02041644(&arg0->unk_348[i], save, var_r4_2);
    }

    if (temp_r5 >= 1)
    {
        func_020a58b8(save->unk_04, arg0->unk_730, 0x24);
        save->unk_04 += 0x24;
    }
    else
    {
        func_020a58b8(save->unk_04, arg0->unk_730, 0x14);
        save->unk_04 += 0x14;
    }

    arg0->unk_756 = save->ReadByte();
    arg0->unk_754 = 0;
}

void Force::Init(s32 factionId)
{
    this->head = NULL;
    this->tail = NULL;
    this->id = factionId;
    return;
}

void Force::InsertHead(Unit * unit)
{
    Unit * head;

    unit->force = this;
    head = this->head;

    if (head == NULL)
    {
        this->head = unit;
        this->tail = unit;
    }
    else
    {
        head->unk_38 = unit;
        unit->unk_3c = head;
        this->head = unit;
    }

    return;
}

void Force::InsertTail(Unit * unit)
{
    Unit * tail;

    unit->force = this;
    tail = this->tail;

    if (tail == NULL)
    {
        this->head = unit;
    }
    else
    {
        tail->unk_3c = unit;
        unit->unk_38 = tail;
    }

    this->tail = unit;

    return;
}

void Force::Remove(Unit * unit)
{
    if (unit->unk_3c != NULL)
    {
        unit->unk_3c->unk_38 = unit->unk_38;
    }
    else
    {
        this->tail = unit->unk_38;

        if (this->tail != NULL)
        {
            this->tail->unk_3c = NULL;
        }
    }

    if (unit->unk_38 != NULL)
    {
        unit->unk_38->unk_3c = unit->unk_3c;
    }
    else
    {
        this->head = unit->unk_3c;

        if (this->head != NULL)
        {
            this->head->unk_38 = NULL;
        }
    }

    unit->unk_38 = NULL;
    unit->unk_3c = NULL;

    return;
}

s32 Force::Count(void)
{
    struct Unit * it;
    s32 count = 0;

    for (it = this->head; it != NULL; it = it->unk_3c)
    {
        count++;
    }

    return count;
}

Force * Force::Get(s32 factionId)
{
    return data_021974dc + factionId;
}

void Force::MoveAllUnitsTo(s32 factionId, BOOL append)
{
    Unit * next;
    Unit * it;

    if (!append)
    {
        for (it = this->tail; it != NULL; it = next)
        {
            next = it->unk_38;
            func_0203bd34(it, factionId, append);
        }
    }
    else
    {
        for (it = this->head; it != NULL; it = next)
        {
            next = it->unk_3c;
            func_0203bd34(it, factionId, append);
        }
    }

    return;
}

Unit * Force::FindByPerson(struct PersonData * person)
{
    Unit * it;

    for (it = this->head; it != NULL; it = it->unk_3c)
    {
        if (it->pPersonData != person)
        {
            continue;
        }

        return it;
    }

    return NULL;
}

Unit * Force::FindByPid(s32 pid)
{
    return this->FindByPerson(data_02197254->pPerson + pid);
}

Unit * Force::func_02040d68(struct PersonData * person)
{
    Unit * it;

    for (it = this->head; it != NULL; it = it->unk_3c)
    {
        if (func_0203c378(it)->pPersonData != person)
        {
            continue;
        }

        return it;
    }

    return NULL;
}

Unit * Force::FindByPidStr(char * pidStr)
{
    return this->func_02040d68(GetPersonByPidStr(pidStr));
}

Unit * Force::FindByAttribute(u32 attr)
{
    Unit * it;

    for (it = this->head; it != NULL; it = it->unk_3c)
    {
        if (!CheckUnitAttribute(it, attr))
        {
            continue;
        }

        return it;
    }

    return NULL;
}
