#include "global.h"

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "save.hpp"

#include "unit.hpp"

EC void func_0203a94c(struct Unit * unit)
{
    s32 i;
    s32 j;

    unit->pPersonData = NULL;
    unit->pJobData = NULL;

    for (i = 0; i < 8; i++)
    {
        unit->unk_50[i] = 0;
    }

    for (i = 0; i < 8; i++)
    {
        unit->unk_58[i] = 0;
    }

    unit->unk_69 = 0xff;

    unit->level = 1;
    unit->exp = 0;
    unit->hp = 0;
    unit->xPos = 0;
    unit->yPos = 0;

    unit->unk_6d = 0;

    for (j = 0; j < 5; j++)
    {
        func_0203e02c(&unit->items[j]);
    }

    for (i = 0; i < 6; i++)
    {
        unit->unk_84[i] = 0;
    }

    for (i = 0; i < 5; i++)
    {
        unit->unk_8a[i] = 0;
    }

    unit->alpha = 31;

    unit->unk_90 = 0;
    unit->unk_91 = 0;
    unit->unk_92 = 0;
    unit->unk_93 = 0;
    unit->unk_94 = 0;
    unit->unk_95 = 0;
    unit->unk_96 = 0;

    unit->state1 = 0;
    unit->state2 = 0;

    unit->unk_a0 = NULL;
    unit->unk_a4 = 0;

    func_0203df18(unit);
    func_0203df78(&unit->unk_30);

    return;
}

EC struct Unit * func_0203aa4c(struct Unit * dst, struct Unit * src)
{
    u8 bVar1;
    s16 * psVar2;
    s32 iVar3;
    s16 * psVar4;
    s32 i;

    dst->pPersonData = src->pPersonData;
    dst->pJobData = src->pJobData;

    for (i = 0; i < 8; i++)
    {
        dst->unk_50[i] = src->unk_50[i];
    }

    for (i = 0; i < 8; i++)
    {
        dst->unk_58[i] = src->unk_58[i];
    }

    dst->unk_69 = src->unk_69;
    i = 0;

    dst->level = src->level;
    dst->exp = src->exp;
    dst->hp = src->hp;
    dst->unk_6d = src->unk_6d;

    dst->xPos = src->xPos;
    dst->yPos = src->yPos;

    for (i = 0; i < 5; i++)
    {
        func_0203e040(&dst->items[i], &src->items[i]);
    }

    for (i = 0; i < 6; i++)
    {
        dst->unk_84[i] = src->unk_84[i];
    }

    for (i = 0; i < 5; i++)
    {
        dst->unk_8a[i] = src->unk_8a[i];
    }

    dst->alpha = src->alpha;

    dst->unk_90 = src->unk_90;
    dst->unk_91 = src->unk_91;
    dst->unk_92 = src->unk_92;
    dst->unk_93 = src->unk_93;
    dst->unk_94 = src->unk_94;
    dst->unk_95 = src->unk_95;
    dst->unk_96 = src->unk_96;

    dst->state1 = src->state1;
    dst->state2 = src->state2;

    dst->unk_a0 = src->unk_a0;
    dst->unk_a4 = src->unk_a4;

    dst->unk_00 |= src->unk_00;

    dst->unk_05 = src->unk_05;
    dst->unk_04 = src->unk_04;
    dst->unk_08 = src->unk_08;
    dst->unk_0a = src->unk_0a;
    dst->unk_07 = src->unk_07;
    dst->unk_06 = src->unk_06;

    for (i = 0; i < 4; i++)
    {
        dst->unk_0c[i] = src->unk_0c[i];
    }

    psVar2 = src->unk_10;
    psVar4 = dst->unk_10;
    for (i = 0; i < 0x10; i++)
    {
        *psVar4++ = *psVar2++;
    }

    dst->unk_30 = src->unk_30;
    dst->unk_32 = src->unk_32;
    dst->unk_34 = src->unk_34;

    return dst;
}

EC s32 GetPersonDBIndex(struct PersonData *);
EC s32 GetJobDBIndex(struct JobData *);
EC void func_020a58b8(void *, void *, s32);

EC void SaveItem(struct Item *, struct SaveBuffer *);
EC void LoadItem(struct Item *, struct SaveBuffer *, s32);

extern struct Unit * gUnitList;

EC void SaveUnit(struct Unit * unit, struct SaveBuffer * buf)
{
    s32 i;
    s16 * c;

    buf->WriteShort(GetPersonDBIndex(unit->pPersonData));
    buf->WriteShort(GetJobDBIndex(unit->pJobData));

    func_020a58b8(unit->unk_50, buf->unk_04, sizeof(unit->unk_50));
    buf->unk_04 += sizeof(unit->unk_50);

    func_020a58b8(unit->unk_58, buf->unk_04, sizeof(unit->unk_58));
    buf->unk_04 += sizeof(unit->unk_58);

    buf->WriteByte(unit->unk_69);
    buf->WriteByte(unit->level);
    buf->WriteByte(unit->exp);
    buf->WriteByte(unit->hp);
    buf->WriteByte(unit->unk_6d);
    buf->WriteByte(unit->xPos);
    buf->WriteByte(unit->yPos);

    for (i = 0; i < 5; i++)
    {
        SaveItem(&unit->items[i], buf);
    }

    for (i = 0; i < 6; i++)
    {
        buf->WriteByte(unit->unk_84[i]);
    }

    for (i = 0; i < 5; i++)
    {
        buf->WriteByte(unit->unk_8a[i]);
    }

    buf->WriteByte(unit->alpha);
    buf->WriteByte(unit->unk_90);
    buf->WriteByte(unit->unk_91);
    buf->WriteByte(unit->unk_92);
    buf->WriteByte(unit->unk_93);
    buf->WriteByte(unit->unk_94);
    buf->WriteByte(unit->unk_96);
    buf->WriteWord(unit->state1);
    buf->WriteWord(unit->state2);

    if (unit->unk_a0 != NULL)
    {
        buf->WriteByte(unit->unk_a0->unk_68);
    }
    else
    {
        buf->WriteByte(0);
    }

    if (unit->unk_a4 != 0)
    {
        buf->WriteShort(unit->unk_a4->unk_04);
    }
    else
    {
        buf->WriteShort(-1);
    }

    if (unit->force->id == 1)
    {
        buf->WriteShort(unit->unk_00);
        buf->WriteByte(unit->unk_05);
        buf->WriteByte(unit->unk_04);
        buf->WriteByte(unit->unk_08);
        buf->WriteShort(unit->unk_0a);
        buf->WriteByte(unit->unk_07);
        buf->WriteByte(unit->unk_06);

        for (i = 0; i < 4; i++)
        {
            buf->WriteByte(unit->unk_0c[i]);
        }

        for (i = 0, c = unit->unk_10; i < 16; i++, c++)
        {
            buf->WriteShort(*c);
        }

        buf->WriteByte(unit->unk_02);
        buf->WriteByte(unit->unk_03);
    }
    else
    {
        buf->WriteShort(unit->unk_30);
        buf->WriteShort(unit->unk_32);
        buf->WriteShort(unit->unk_34);
    }

    return;
}

EC void LoadUnit(struct Unit * unit, struct SaveBuffer * buf, s32 param_3)
{
    s32 i;
    s32 x;
    s32 y;
    s32 unk;
    u32 unk2;
    s16 * c;

    unit->pPersonData = data_02197254->pPerson + buf->ReadShort();
    unit->pJobData = data_02197254->pJob + buf->ReadShort();

    func_020a58b8(buf->unk_04, unit->unk_50, sizeof(unit->unk_50));
    buf->unk_04 += sizeof(unit->unk_50);

    func_020a58b8(buf->unk_04, unit->unk_58, sizeof(unit->unk_58));
    buf->unk_04 += sizeof(unit->unk_58);

    unit->unk_69 = buf->ReadByte();
    unit->level = buf->ReadByte();
    unit->exp = buf->ReadByte();
    unit->hp = buf->ReadByte();
    unit->unk_6d = buf->ReadByte();

    x = buf->ReadByte();
    y = buf->ReadByte();
    unit->xPos = x;
    unit->yPos = y;

    for (i = 0; i < 5; i++)
    {
        LoadItem(&unit->items[i], buf, param_3);
    }

    for (i = 0; i < 6; i++)
    {
        unit->unk_84[i] = buf->ReadByte();
    }

    for (i = 0; i < 5; i++)
    {
        unit->unk_8a[i] = buf->ReadByte();
    }

    unit->alpha = buf->ReadByte();
    unit->unk_90 = buf->ReadByte();
    unit->unk_91 = buf->ReadByte();
    unit->unk_92 = buf->ReadByte();
    unit->unk_93 = buf->ReadByte();
    unit->unk_94 = buf->ReadByte();

    if (param_3 >= 2)
    {
        unit->unk_96 = buf->ReadByte();
    }

    unit->state1 = buf->ReadWord();
    unit->state2 = buf->ReadWord();

    if ((param_3 < 5) && func_0203b714(unit, 0x10000))
    {
        unit->state2 &= ~0x10000;
        unit->state1 |= 0x20000000;
    }

    unk = buf->ReadByte();

    if (unk != 0)
    {
        struct Unit * unk_a0;

        if (unk == 0)
        {
            unk_a0 = NULL;
        }
        else
        {
            unk_a0 = gUnitList + unk - 1;
        }

        unit->unk_a0 = unk_a0;
    }
    else
    {
        unit->unk_a0 = NULL;
    }

    unk2 = buf->ReadShort();
    unit->unk_a4 = (unk2 != 0xffff) ? data_02197254->unk_38[unk2] : NULL;

    if (unit->force->id == 1)
    {
        unit->unk_00 = buf->ReadShort();
        unit->unk_05 = buf->ReadByte();
        unit->unk_04 = buf->ReadByte();
        unit->unk_08 = buf->ReadByte();
        unit->unk_0a = buf->ReadShort();
        unit->unk_07 = buf->ReadByte();
        unit->unk_06 = buf->ReadByte();

        for (i = 0; i < 4; i++)
        {
            unit->unk_0c[i] = buf->ReadByte();
        }

        for (i = 0, c = unit->unk_10; i < 16; i++, c++)
        {
            *c = buf->ReadShort();
        }

        if (param_3 >= 1)
        {
            s32 unk_02 = buf->ReadByte();
            s32 unk_03 = buf->ReadByte();
            unit->unk_02 = unk_02;
            unit->unk_03 = unk_03;
        }
    }
    else
    {
        unit->unk_30 = buf->ReadShort();
        unit->unk_32 = buf->ReadShort();
        unit->unk_34 = buf->ReadShort();
    }

    return;
}

// #func_0203b720

// #func_0203ba20

EC void func_0203bcf4(struct Unit * unit)
{
    u32 prevState = unit->state2;

    unit->state2 &= 0xFFFD91BE;
    unit->unk_91 = 0;
    unit->unk_92 = 0;
    unit->unk_93 = 0;
    unit->unk_a4 = 0;

    if ((unit->state2 & 0x8000) == 0)
    {
        return;
    }

    func_0203bf68(unit, unit->state2, 0, prevState);

    return;
}

EC void func_0203bd34(struct Unit * unit, s32 factionId, BOOL append)
{
    if (((unit->force->id < 2) && (factionId >= 2)) && (factionId != 5))
    {
        unit->xPos = 0xff;
        unit->yPos = 0xff;
        unit->hp = GetUnitMaxHp(unit);
        unit->alpha = 0x1f;
        func_0203bcf4(unit);
    }

    unit->force->Remove(unit);

    if (factionId == 4)
    {
        func_0203a94c(unit);
    }

    if (!append)
    {
        Force::Get(factionId)->InsertHead(unit);
        return;
    }
    else
    {
        Force::Get(factionId)->InsertTail(unit);
        return;
    }
}

EC struct Unit * func_0203bdd0(struct Unit * unit, u8 arg_1)
{
    s32 i;
    Force * force;

    if (unit->unk_3c != NULL)
    {
        return unit->unk_3c;
    }

    for (i = unit->force->id + 1; i < 6; i++)
    {
        if ((arg_1 & (1 << i)) == 0)
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

EC void func_0203be30(struct Unit * arg_0, struct Unit * arg_1)
{
    Force * force;
    s32 i;
    s32 hp;
    struct Unit * pUVar5;

    force = Force::Get(4);
    pUVar5 = force->head;

    func_0203bd34(pUVar5, 5, 1);

    func_0203aa4c(pUVar5, arg_0);
    func_0203aa4c(arg_0, arg_1);

    arg_0->xPos = pUVar5->xPos;
    arg_0->yPos = pUVar5->yPos;

    hp = pUVar5->hp;
    arg_0->hp = hp;

    if (hp >= GetUnitMaxHp(arg_0))
    {
        arg_0->hp = GetUnitMaxHp(arg_0);
    }

    arg_0->exp = pUVar5->exp;
    arg_0->state2 = pUVar5->state2;
    arg_0->unk_90 = pUVar5->unk_90;
    arg_0->unk_91 = pUVar5->unk_91;
    arg_0->unk_92 = pUVar5->unk_92;
    arg_0->unk_94 = pUVar5->unk_94;
    arg_0->unk_a4 = pUVar5->unk_a4;

    for (i = 0; i < 5; i++)
    {
        struct Item * src = &arg_1->items[i];
        struct Item * dst = &arg_0->items[i];
        func_0203e040(dst, src);

        if (!(dst->unk_03 & 0x10))
        {
            continue;
        }

        if (func_0203cb6c(arg_0, i, 0))
        {
            continue;
        }

        dst->unk_03 &= ~0x10;
    }

    arg_0->state1 &= 0xFFFFEFFD;
    arg_0->unk_a0 = pUVar5;
    arg_0->state2 |= 0x8000;
    arg_0->unk_93 = 5;

    return;
}

EC void func_0203bf68(struct Unit * srcUnit, u32 arg_1, u32 arg_2, u32 arg_3)
{
    s32 i;
    s32 hp;

    struct Unit * dstUnit = srcUnit->unk_a0;

    dstUnit->xPos = srcUnit->xPos;
    dstUnit->yPos = srcUnit->yPos;

    hp = srcUnit->hp;
    dstUnit->hp = hp;

    if (hp > GetUnitMaxHp(dstUnit))
    {
        dstUnit->hp = GetUnitMaxHp(dstUnit);
    }

    dstUnit->exp = srcUnit->exp;

    dstUnit->state2 = srcUnit->state2;

    dstUnit->unk_90 = srcUnit->unk_90;
    dstUnit->unk_91 = srcUnit->unk_91;
    dstUnit->unk_92 = srcUnit->unk_92;
    dstUnit->unk_94 = srcUnit->unk_94;
    dstUnit->unk_a4 = srcUnit->unk_a4;

    for (i = 0; i < 5; i++)
    {
        struct Item * src = srcUnit->items + i;
        struct Item * dst = dstUnit->items + i;

        func_0203e040(dst, src);

        if (!(dst->unk_03 & 0x10))
        {
            continue;
        }

        if (func_0203cb6c(dstUnit, i, 0))
        {
            continue;
        }

        dst->unk_03 &= ~0x10;
    }

    func_0203aa4c(srcUnit, dstUnit);

    srcUnit->state2 &= ~0x8000;

    func_0203bd34(dstUnit, 4, 1);

    return;
}

EC void func_0203c068(struct Unit * arg_0, struct Unit * arg_1)
{
    s32 i;

    Force * force = Force::Get(4);
    struct Unit * pUVar7 = force->head;

    func_0203bd34(pUVar7, 5, 1);

    func_0203aa4c(pUVar7, arg_0);
    func_0203aa4c(arg_0, arg_1);

    arg_0->xPos = pUVar7->xPos;
    arg_0->yPos = pUVar7->yPos;

    arg_0->hp = GetUnitMaxHp(arg_0);
    arg_0->exp = pUVar7->exp;

    arg_0->state2 = pUVar7->state2;
    arg_0->unk_90 = pUVar7->unk_90;
    arg_0->unk_91 = pUVar7->unk_91;
    arg_0->unk_92 = pUVar7->unk_92;
    arg_0->unk_94 = pUVar7->unk_94;
    arg_0->unk_a4 = pUVar7->unk_a4;

    for (i = 0; i < 5; i++)
    {
        struct Item * pUVar9 = arg_0->items + i;
        struct Item * pUVar8 = pUVar7->items + i;

        func_0203e040(pUVar9, pUVar8);

        if (!(pUVar9->unk_03 & 0x10))
        {
            continue;
        }

        if (func_0203cb6c(arg_0, i, 0))
        {
            continue;
        }

        pUVar9->unk_03 &= ~0x10;
    }

    arg_0->state1 &= 0xFFFFEFFD;
    arg_0->state1 |= CheckUnitAttribute(pUVar7, 0x00001002);

    arg_0->unk_a0 = pUVar7;
    arg_0->state2 |= 0x40000;

    return;
}

EC void func_0203c19c(struct Unit * srcUnit)
{
    s32 i;

    struct Unit * dstUnit = srcUnit->unk_a0;

    dstUnit->xPos = srcUnit->xPos;
    dstUnit->yPos = srcUnit->yPos;

    dstUnit->hp = GetUnitMaxHp(dstUnit);
    dstUnit->exp = srcUnit->exp;

    dstUnit->state2 = srcUnit->state2;

    dstUnit->unk_90 = srcUnit->unk_90;
    dstUnit->unk_91 = srcUnit->unk_91;
    dstUnit->unk_92 = srcUnit->unk_92;
    dstUnit->unk_94 = srcUnit->unk_94;

    dstUnit->unk_a4 = srcUnit->unk_a4;

    for (i = 0; i < 5; i++)
    {
        struct Item * src = srcUnit->items + i;
        struct Item * dst = dstUnit->items + i;

        func_0203e040(dst, src);

        if (!(dst->unk_03 & 0x10))
        {
            continue;
        }

        if (func_0203cb6c(dstUnit, i, 0))
        {
            continue;
        }

        dst->unk_03 &= ~0x10;
    }

    func_0203aa4c(srcUnit, dstUnit);

    srcUnit->state2 &= ~0x40000;

    func_0203bd34(dstUnit, 4, 1);

    return;
}

EC void func_0203c284(struct Unit * unit)
{
    unit = func_0203c378(unit);

    if ((unit->state2 & 0x80000) != 0)
    {
        func_020423e4(unit->unk_96);
        return;
    }

    func_02037eb8(unit->pPersonData);
    return;
}

// #func_0203c378

EC s32 GetUnitMaxHp(struct Unit * unit)
{
    struct JobData * job = unit->pJobData;
    s32 hp;

    hp = unit->pPersonData->bases[0] + job->bases[0];
    hp += unit->unk_50[0];

    if (hp >= job->caps[0])
    {
        hp = job->caps[0];
    }

    return hp;
}

EC s32 GetUnitStr(struct Unit * unit, struct ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 str;

    if (item == NULL)
    {
        job = unit->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, unit);
    }

    str = unit->pPersonData->bases[1] + job->bases[1];
    str += unit->unk_50[1];

    if (str < 0)
    {
        str = 0;
    }

    if (str >= job->caps[1])
    {
        str = job->caps[1];
    }

    return str;
}

EC s32 GetUnitMag(struct Unit * unit, struct ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 mag;

    if (item == NULL)
    {
        job = unit->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, unit);
    }

    mag = unit->pPersonData->bases[2] + job->bases[2];
    mag += unit->unk_50[2];

    if (mag < 0)
    {
        mag = 0;
    }

    if (mag >= job->caps[2])
    {
        mag = job->caps[2];
    }

    return mag;
}

EC s32 GetUnitSkl(struct Unit * unit, struct ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 skl;

    if (item == NULL)
    {
        job = unit->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, unit);
    }

    skl = unit->pPersonData->bases[3] + job->bases[3];
    skl += unit->unk_50[3];

    if (skl < 0)
    {
        skl = 0;
    }

    if (skl >= job->caps[3])
    {
        skl = job->caps[3];
    }

    return skl;
}

EC s32 GetUnitSpd(struct Unit * unit, struct ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 spd;

    if (item == NULL)
    {
        job = unit->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, unit);
    }

    spd = unit->pPersonData->bases[4] + job->bases[4];
    spd += unit->unk_50[4];

    if (spd < 0)
    {
        spd = 0;
    }

    if (spd >= job->caps[4])
    {
        spd = job->caps[4];
    }

    return spd;
}

EC s32 GetUnitLuk(struct Unit * unit, struct ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 luk;

    if (item == NULL)
    {
        job = unit->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, unit);
    }

    luk = unit->pPersonData->bases[5] + job->bases[5];
    luk += unit->unk_50[5];

    if (luk < 0)
    {
        luk = 0;
    }

    if (luk >= job->caps[5])
    {
        luk = job->caps[5];
    }

    return luk;
}

EC s32 GetUnitDef(struct Unit * unit, struct ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 def;

    if (item == NULL)
    {
        job = unit->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, unit);
    }

    def = unit->pPersonData->bases[6] + job->bases[6];
    def += unit->unk_50[6];

    if (def < 0)
    {
        def = 0;
    }

    if (def >= job->caps[6])
    {
        def = job->caps[6];
    }

    return def;
}

EC s32 GetUnitRes(struct Unit * unit, struct ItemData * item, BOOL arg_2)
{
    struct JobData * job;
    s32 res;

    if (item == NULL)
    {
        job = unit->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, unit);
    }

    res = unit->pPersonData->bases[7] + job->bases[7];
    res += unit->unk_50[7];

    if (res < 0)
    {
        res = 0;
    }

    if (arg_2 != 0)
    {
        res += unit->unk_91;
    }

    if (res >= job->caps[7])
    {
        res = job->caps[7];
    }

    return res;
}

EC s32 GetUnitStat(struct Unit * unit, u32 arg_1, struct ItemData * item, s32 arg_3)
{
    struct JobData * job;
    s32 stat;

    if (item == NULL)
    {
        job = unit->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, unit);
    }

    stat = unit->pPersonData->bases[arg_1] + job->bases[arg_1];
    stat += unit->unk_50[arg_1];

    if (stat < 0)
    {
        stat = 0;
    }

    if ((arg_3 != 0) && (arg_1 == 7))
    {
        stat += unit->unk_91;
    }

    if (stat >= job->caps[arg_1])
    {
        stat = job->caps[arg_1];
    }

    return stat;
}

EC BOOL func_0203c73c(struct Unit * unit, s32 arg_1)
{
    if ((arg_1 == 7) && (unit->unk_91 != 0))
    {
        return TRUE;
    }

    return FALSE;
}

EC u32 func_0203c75c(struct Unit * unit)
{
    u32 base = unit->pPersonData->bases[7] + unit->pJobData->bases[7];
    return base + unit->unk_50[7];
}

EC s32 func_0203c77c(struct Unit * unit)
{
    return unit->pJobData->mov + unit->unk_6d;
}

EC s32 func_0203c790(struct Unit * unit)
{
    return unit->pJobData->unk_2a + (((unit->unk_92 + 1) & ~1) >> 1);
}

EC s32 func_0203c7ac(struct Unit * unit, u32 arg_1)
{
    u32 uVar1 = unit->pJobData->weaponLevels[arg_1];

    if (uVar1 != 0)
    {
        return uVar1 + unit->pPersonData->enemyGrowths[arg_1] + unit->unk_84[arg_1];
    }

    return 0;
}

EC s32 func_0203c7e4(struct Unit * unit, u32 arg_1)
{
    if (unit->pJobData->weaponLevels[arg_1] != 0)
    {
        return unit->pJobData->weaponLevels[arg_1] + unit->pPersonData->enemyGrowths[arg_1];
    }

    return 0;
}

static inline u32 PersonUnk24(struct Unit * unit)
{
    return unit->pPersonData->unk_24;
}

static inline u32 JobUnk38(struct Unit * unit)
{
    return unit->pJobData->attributes;
}

EC s32 CheckUnitAttribute(struct Unit * unit, u32 attribute)
{
    return (unit->state1 & attribute) | (PersonUnk24(unit) & attribute) | (JobUnk38(unit) & attribute);
}

EC BOOL func_0203c834(struct Unit * unit, struct ItemData * item, s32 arg_2)
{
    s32 itemType = item->type;

    if (arg_2 == 0 && itemType == 5)
    {
        return FALSE;
    }

    if (itemType == 6)
    {
        if (!(unit->pJobData->unitType & 0x40))
        {
            return FALSE;
        }
    }
    else if (itemType == 7)
    {
        if (!(unit->pJobData->unitType & 8))
        {
            return FALSE;
        }
    }
    else
    {
        if (itemType >= 6)
        {
            return FALSE;
        }

        if (((item->attributes & 0x1000000000000) && CheckUnitAttribute(unit, 0x100)) ||
            ((item->attributes & 0x2000000000000) && CheckUnitAttribute(unit, 0x80)))
        {
            s32 wlvl = data_02197254->pWeaponLevel[4];
            if (wlvl > func_0203c7ac(unit, itemType))
            {
                return FALSE;
            }
        }
        else
        {
            s32 wlvl = item->wpnLevel;
            if (wlvl > func_0203c7ac(unit, itemType))
            {
                return FALSE;
            }
        }
    }

    if ((item->attributes & 0x0FFC000000000000))
    {
        if ((item->attributes & 0x4000000000000) && !CheckUnitAttribute(unit, 2))
        {
            return FALSE;
        }

        if ((item->attributes & 0x8000000000000) && !CheckUnitAttribute(unit, 4))
        {
            return FALSE;
        }

        if ((item->attributes & 0x10000000000000) && !CheckUnitAttribute(unit, 8))
        {
            return FALSE;
        }

        if ((item->attributes & 0x20000000000000) && !CheckUnitAttribute(unit, 0x20))
        {
            return FALSE;
        }

        if ((item->attributes & 0x40000000000000) && !CheckUnitAttribute(unit, 0x40))
        {
            return FALSE;
        }

        if ((item->attributes & 0x80000000000000) && !CheckUnitAttribute(unit, 0x10))
        {
            return FALSE;
        }

        if ((item->attributes & 0x100000000000000) && !CheckUnitAttribute(unit, 0x200))
        {
            return FALSE;
        }

        if ((item->attributes & 0x200000000000000) && !(unit->pJobData->unitType & 0x80))
        {
            return FALSE;
        }

        if ((item->attributes & 0x400000000000000) && CheckUnitAttribute(unit, 1))
        {
            return FALSE;
        }

        if ((item->attributes & 0x800000000000000) && !CheckUnitAttribute(unit, 1))
        {
            return FALSE;
        }
    }

    return TRUE;
}

EC BOOL func_0203cb6c(struct Unit * unit, s32 slot, s32 arg_2)
{
    return func_0203c834(unit, GetItemData(unit->items + slot), arg_2);
}

EC s32 GetUnitEquippedWeaponSlot(struct Unit * unit)
{
    s32 i;
    struct Item * item = unit->items;

    for (i = 0; i < 5; i++, item++)
    {
        if (!(item->unk_03 & 0x10))
        {
            continue;
        }

        return i;
    }

    return -1;
}

EC u64 func_0203cbc4(struct Unit * unit, u64 arg_1)
{
    struct ItemData * item;
    u64 ret;
    s32 i;
    struct Item * it;

    ret = 0;

    it = unit->items;

    for (i = 0; i < 5; i++, it++)
    {
        item = GetItemData(it);
        ret |= item->attributes & arg_1;
    }

    return ret;
}

EC u64 func_0203cc1c(struct Unit * unit, u64 arg_1)
{
    struct ItemData * item;
    u64 uVar2;
    s32 i;
    struct Item * it;

    uVar2 = 0;

    it = unit->items;

    for (i = 0; i < 5; i++, it++)
    {
        if (!func_0203cb6c(unit, i, 0))
        {
            continue;
        }

        item = GetItemData(it);
        uVar2 |= item->attributes & arg_1;
    }

    return uVar2;
}

EC void func_0203cc94(struct Unit * unit, s32 slot, s32 arg_2)
{
    struct Item tmp;

    struct Item * it = unit->items + slot;

    func_0203e040(&tmp, it);

    if (slot >= arg_2)
    {
        for (; slot > arg_2; slot--, it--)
        {
            func_0203e040(it, &unit->items[slot - 1]);
        }
    }
    else if (slot < arg_2)
    {
        for (; slot < arg_2; slot++, it++)
        {
            func_0203e040(it, &unit->items[slot + 1]);
        }
    }

    func_0203e040(unit->items + arg_2, &tmp);

    return;
}

EC BOOL func_0203cd30(struct Unit * unit, s32 arg_1)
{
    s32 slot;
    s32 i;

    if (arg_1 == -1)
    {
        for (i = 0; i < 5; i++)
        {
            if (!func_0203cb6c(unit, i, 0))
            {
                continue;
            }

            func_0203cd30(unit, i);
            return 1;
        }

        return 0;
    }

    if (!func_0203cb6c(unit, arg_1, 0))
    {
        return 0;
    }

    slot = GetUnitEquippedWeaponSlot(unit);

    if (slot != -1)
    {
        struct Item * item = unit->items + slot;
        item->unk_03 &= ~0x10;
    }

    func_0203cc94(unit, arg_1, 0);
    unit->items[0].unk_03 |= 0x10;

    return 1;
}

EC void func_0203cdf0(struct Unit * unit, s32 slot)
{
    struct Item * item = unit->items + slot;
    item->unk_03 &= ~0x10;
    return;
}

EC void func_0203ce08(struct Unit * unit, s32 slot, BOOL arg_2)
{
    if (arg_2)
    {
        for (; slot < 4; slot++)
        {
            func_0203e040(&unit->items[slot], &unit->items[slot + 1]);
        }

        // Required to match, even though it's duplicated below
        func_0203e02c(unit->items + slot);
        return;
    }

    func_0203e02c(unit->items + slot);
    return;
}

EC void func_0203ce6c(struct Unit * unit)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        func_0203ce08(unit, i, FALSE);
    }

    return;
}

EC BOOL func_0203ce9c(struct Unit * unit, s32 arg_1, u32 arg_2)
{
    s32 i;
    struct Item * item = unit->items;

    for (i = 0; i < 5; i++, item++)
    {
        if (item->id == 0)
        {
            break;
        }
    }

    if (i != 5)
    {
        item = unit->items + i;
        func_0203e008(item, arg_1);
        item->unk_03 |= arg_2;
        return TRUE;
    }

    return FALSE;
}

EC BOOL func_0203cef8(struct Unit * unit, struct ItemData * item, BOOL arg_2)
{
    return func_0203ce9c(unit, func_02037ffc(item), arg_2);
}

EC BOOL func_0203cf20(struct Unit * unit, struct Item * item)
{
    s32 i;
    struct Item * it = unit->items;

    for (i = 0; i < 5; i++, it++)
    {
        if (it->id == 0)
        {
            break;
        }
    }

    if (i != 5)
    {
        func_0203e040(&unit->items[i], item);
        return TRUE;
    }

    return FALSE;
}

EC void func_0203cf68(struct Unit * unit)
{
    s32 j;
    s32 i;
    struct Item * unitItems = unit->items;

    while (1)
    {
        struct Item * it = unitItems;
        for (i = 0; i < 5; i++, it++)
        {
            if (it->id == 0)
            {
                break;
            }
        }

        if (i == 5)
        {
            return;
        }

        for (j = i + 1; j < 5; j++)
        {
            it = unitItems + j;

            if (it->id != 0)
            {
                break;
            }
        }

        if (j == 5)
        {
            return;
        }

        func_0203e040(unitItems + i, unitItems + j);
        func_0203e02c(unitItems + j);
    }
}

EC s32 func_0203cff4(struct Unit * unit)
{
    s32 i;
    struct Item * it = unit->items;

    for (i = 0; i < 5; i++, it++)
    {
        if (it->id == 0)
        {
            break;
        }
    }

    return i;
}

EC s32 func_0203d01c(struct Unit * unit)
{
    s32 i;
    s32 ret;
    struct Item * it;

    ret = -1;

    it = unit->items;

    for (i = 0; i < 5; i++, it++)
    {
        struct ItemData * item = GetItemData(it);

        if (ret != -1 && !(item->attributes & 0x8000000))
        {
            continue;
        }

        if (!func_02038e80(item, unit))
        {
            continue;
        }

        ret = i;
    }

    return ret;
}

EC s32 func_0203d094(struct Unit * unit)
{
    s32 i;
    s32 found;
    struct Item * it;

    found = -1;

    it = unit->items;

    for (i = 0; i < 5; i++, it++)
    {
        struct ItemData * item = GetItemData(it);

        if (found != -1 && !(item->attributes & 0x8000000))
        {
            continue;
        }

        if (!func_02038edc(item, unit))
        {
            continue;
        }

        found = i;
    }

    return found;
}

EC s32 func_0203d10c(struct Unit * unit)
{
    s32 i;
    s32 found;
    struct Item * it;

    found = -1;

    it = unit->items;

    for (i = 0; i < 5; i++, it++)
    {
        struct ItemData * item = GetItemData(it);

        if (found != -1 && !(item->attributes & 0x8000000))
        {
            continue;
        }

        if (!func_02038f38(item, unit))
        {
            continue;
        }

        found = i;
    }

    return found;
}

EC BOOL func_0203d184(struct Unit * unit)
{
    if (CheckUnitAttribute(unit, 0x400))
    {
        return TRUE;
    }

    return func_0203d01c(unit) != -1;
}

EC BOOL func_0203d1bc(struct Unit * unit)
{
    if (CheckUnitAttribute(unit, 0x400))
    {
        return TRUE;
    }

    return func_0203d094(unit) != -1;
}

EC BOOL func_0203d1f4(struct Unit * unit)
{
    if (CheckUnitAttribute(unit, 0x400))
    {
        return TRUE;
    }

    return func_0203d10c(unit) != -1;
}

EC s32 ComputeMight(struct Unit * unit, struct ItemData * item, BOOL arg_2)
{
    s32 might;

    if (item == NULL)
    {
        return 0;
    }

    might = item->might;

    if (!func_02038348(item))
    {
        s32 str = GetUnitStr(unit, item, TRUE);
        might += str;
    }
    else
    {
        s32 mag = GetUnitMag(unit, item, TRUE);
        might += mag;
    }

    if (arg_2)
    {
        might += func_0203d2e4(unit, item);
    }

    return might;
}

EC s32 func_0203d294(struct Unit * unit, s32 slot, BOOL arg_2)
{
    if (slot == -1)
    {
        slot = GetUnitEquippedWeaponSlot(unit);
    }

    if (slot != -1)
    {
        return ComputeMight(unit, GetItemData(unit->items + slot), arg_2);
    }

    return 0;
}

// #func_0203d2e4

EC s32 ComputeHitRate(struct Unit * unit, struct ItemData * item, BOOL arg_2)
{
    s32 hit;

    if (item == NULL)
    {
        return 0;
    }

    hit = item->hit;
    hit += GetUnitSkl(unit, item, TRUE);
    hit += (GetUnitLuk(unit, item, TRUE) >> 1);

    if (arg_2 != 0)
    {
        hit += func_0203d45c(unit, item);
    }

    if (CheckUnitAttribute(unit, 0x30000) != 0)
    {
        if (CheckUnitAttribute(unit, 0x10000) != 0) // Sniper attr
        {
            hit += 5;
        }

        if (CheckUnitAttribute(unit, 0x20000) != 0) // Swordmaster attr
        {
            hit += 10;
        }
    }

    return hit;
}

EC s32 func_0203d40c(struct Unit * unit, s32 slot, BOOL arg_2)
{
    if (slot == -1)
    {
        slot = GetUnitEquippedWeaponSlot(unit);
    }

    if (slot != -1)
    {
        return ComputeHitRate(unit, GetItemData(unit->items + slot), arg_2);
    }

    return 0;
}

// #func_0203d45c

EC s32 ComputeCritRate(struct Unit * unit, struct ItemData * item)
{
    s32 critical;

    if (item == NULL)
    {
        return 0;
    }

    critical = item->critical;
    critical += GetUnitSkl(unit, item, 1) >> 1;

    if (CheckUnitAttribute(unit, 0xc0000) != 0)
    {
        if (CheckUnitAttribute(unit, 0x40000) != 0) // Sniper attr
        {
            critical += 5;
        }

        if (CheckUnitAttribute(unit, 0x80000) != 0) // Berserker attr
        {
            critical += 10;
        }
    }

    return critical;
}

EC s32 func_0203d554(struct Unit * unit, s32 slot)
{
    if (slot == -1)
    {
        slot = GetUnitEquippedWeaponSlot(unit);
    }

    if (slot != -1)
    {
        return ComputeCritRate(unit, GetItemData(unit->items + slot));
    }

    return 0;
}

EC s32 ComputeAttackSpeed(struct Unit * unit, struct ItemData * item)
{
    s32 attackSpeed;
    s32 weight;

    if (item == NULL)
    {
        weight = 0;
    }
    else
    {
        weight = item->weight;
    }

    attackSpeed = GetUnitStr(unit, item, TRUE);
    attackSpeed -= weight;

    if (attackSpeed > 0)
    {
        attackSpeed = 0;
    }

    attackSpeed += GetUnitSpd(unit, item, TRUE);

    if (attackSpeed < 0)
    {
        attackSpeed = 0;
    }

    return attackSpeed;
}

EC s32 ComputeAvoid(struct Unit * unit, struct ItemData * item)
{
    s32 attackSpeed = ComputeAttackSpeed(unit, item);
    return attackSpeed + (GetUnitLuk(unit, item, TRUE) >> 1);
}

EC s32 func_0203d618(struct Unit * unit, s32 arg_1)
{
    struct ItemData * item;

    if (arg_1 == -1)
    {
        arg_1 = GetUnitEquippedWeaponSlot(unit);
    }

    if (arg_1 == -1)
    {
        item = NULL;
    }
    else
    {
        item = GetItemData(unit->items + arg_1);
    }

    return ComputeAvoid(unit, item);
}

EC s32 func_0203d660(struct Unit * unit, struct ItemData * item)
{
    return GetUnitLuk(unit, item, TRUE);
}

EC s32 func_0203d670(struct Unit * unit, s32 exp)
{
    s32 level = unit->level;

    if (exp >= 100)
    {
        exp = 100;
    }

    if (level >= GetJobMaxLevel(unit->pJobData))
    {
        exp = 0;
    }
    else if (exp + unit->exp >= 100)
    {
        level = unit->level;
        if (level + 1 >= GetJobMaxLevel(unit->pJobData))
        {
            exp = (exp < 100 - unit->exp) ? exp : 100 - unit->exp;
        }
    }

    return exp;
}

EC void func_0203d6dc(struct Unit * unit)
{
    u8 bVar1;
    s32 iVar2;
    s32 iVar3;
    s32 iVar4;
    s32 i;
    s32 iVar6;

    unit->level++;

    for (i = 0; i < 8; i++)
    {
        iVar3 = 0;
        if (unit->unk_50[i] * 100 < unit->unk_58[i])
        {
            iVar3 = IntSys_Div(unit->unk_58[i] + unit->unk_50[i] * 100, 10);
        }

        iVar4 = unit->pPersonData->unk_14[i] + unit->pJobData->unk_10[i] - iVar3;
        iVar6 = unit->unk_50[i];
        iVar3 = iVar6;

        if (iVar4 > 99)
        {
            bVar1 = unit->pJobData->caps[i];
            iVar4 -= 100;
            iVar2 = GetUnitStat(unit, i, NULL, 0);
            if (iVar2 < bVar1)
            {
                iVar3 = iVar6 + 1;
            }
        }

        unit->unk_50[i] = iVar3;

        if ((func_0203dbc0() < iVar4) && GetUnitStat(unit, i, NULL, 0) < unit->pJobData->caps[i])
        {
            iVar3 += 1;
        }

        unit->unk_50[i] = iVar3;

        if ((iVar6 < iVar3) || (GetUnitStat(unit, i, NULL, 0) < unit->pJobData->caps[i]))
        {
            iVar3 = unit->pPersonData->unk_14[i] + unit->pJobData->unk_10[i];

            if (iVar3 < 1)
            {
                iVar3 = 0;
            }

            unit->unk_58[i] += iVar3;
        }
    }

    return;
}

EC void func_0203d840(struct Unit * unit, struct JobData * job, BOOL arg_2)
{
    if (job == NULL)
    {
        job = unit->pJobData->pPromoteJob;
    }

    unit->level = 1;
    unit->exp = 0;
    unit->pJobData = job;

    if (arg_2 != 0)
    {
        unit->state1 |= 0x20000000;
    }

    return;
}

// #func_0203d874

// #func_0203dad4

// #func_0203db28

// #func_0203db50

// #func_0203db78

// #func_0203db94

// #func_0203dbc0

// #func_0203dbd4

// #func_0203dd48

EC void func_0203de10(struct Unit * unit)
{
    s32 iVar3;
    s32 iVar4;
    s32 i;

    for (i = 0; i < 8; i++)
    {
        iVar4 = (unit->pPersonData->unk_14[i] + unit->pJobData->unk_10[i]) >> 1;
        iVar3 = unit->unk_50[i];

        if (iVar4 >= 100)
        {
            iVar4 -= 100;

            if (GetUnitStat(unit, i, NULL, 0) < unit->pJobData->caps[i])
            {
                iVar3 -= 1;
            }
        }

        unit->unk_50[i] = iVar3;

        if ((func_0203dbc0() < iVar4) && GetUnitStat(unit, i, NULL, 0) < unit->pJobData->caps[i])
        {
            iVar3 -= 1;
        }

        iVar4 = iVar3 + unit->pPersonData->bases[i] + unit->pJobData->bases[i];

        if (i == 0)
        {
            if (iVar4 < 0x10)
            {
                iVar3 += 0x10 - iVar4;
            }
        }
        else if (iVar4 < 0)
        {
            iVar3 -= iVar4;
        }

        unit->unk_50[i] = iVar3;
    }

    unit->hp = GetUnitMaxHp(unit);

    return;
}

EC void func_0203df18(struct Unit * unit)
{
    s32 i;

    unit->unk_00 = 0;
    unit->unk_04 = 0;
    unit->unk_05 = 0;
    unit->unk_06 = 0;
    unit->unk_07 = 0;
    unit->unk_08 = 0;
    unit->unk_0a = 0;

    unit->unk_02 = -1;
    unit->unk_03 = -1;

    for (i = 0; i < 4; i++)
    {
        unit->unk_0c[i] = 0;
    }

    for (i = 0; i < 0x10; i++)
    {
        unit->unk_10[i] = -1;
    }

    return;
}
