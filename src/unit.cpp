#include "global.h"

#include "unknown_funcs.h"

#include "database.hpp"
#include "item.hpp"
#include "map.hpp"
#include "save.hpp"

#include "unit.hpp"

EC void func_0203df78(struct Unit_unk_30 *);

void Unit::Init(void)
{
    s32 i;
    s32 j;

    this->pPersonData = NULL;
    this->pJobData = NULL;

    for (i = 0; i < 8; i++)
    {
        this->unk_50[i] = 0;
    }

    for (i = 0; i < 8; i++)
    {
        this->unk_58[i] = 0;
    }

    this->unk_69 = 0xff;

    this->level = 1;
    this->exp = 0;
    this->hp = 0;
    this->SetPos(0, 0);

    this->mov = 0;

    for (j = 0; j < UNIT_ITEM_COUNT; j++)
    {
        this->items[j].Clear();
    }

    for (i = 0; i < 6; i++)
    {
        this->unk_84[i] = 0;
    }

    for (i = 0; i < 5; i++)
    {
        this->unk_8a[i] = 0;
    }

    this->alpha = 31;

    this->unk_90 = 0;
    this->unk_91 = 0;
    this->unk_92 = 0;
    this->unk_93 = 0;
    this->unk_94 = 0;
    this->unk_95 = 0;
    this->unk_96 = 0;

    this->state1 = 0;
    this->state2 = 0;

    this->unk_a0 = NULL;
    this->unk_a4 = 0;

    this->_0203df18();
    func_0203df78(&this->unk_30);

    return;
}

Unit * Unit::Copy(Unit * src)
{
    s16 * psVar2;
    s16 * psVar4;
    s32 i;
    s32 j;

    this->pPersonData = src->pPersonData;
    this->pJobData = src->pJobData;

    for (i = 0; i < 8; i++)
    {
        this->unk_50[i] = src->unk_50[i];
    }

    for (i = 0; i < 8; i++)
    {
        this->unk_58[i] = src->unk_58[i];
    }

    this->unk_69 = src->unk_69;
    i = 0;

    this->level = src->level;
    this->exp = src->exp;
    this->hp = src->hp;
    this->mov = src->mov;

    this->SetPos(src->xPos, src->yPos);

    for (j = 0; j < UNIT_ITEM_COUNT; j++)
    {
        this->items[j] = &src->items[j];
    }

    for (i = 0; i < 6; i++)
    {
        this->unk_84[i] = src->unk_84[i];
    }

    for (i = 0; i < 5; i++)
    {
        this->unk_8a[i] = src->unk_8a[i];
    }

    this->alpha = src->alpha;

    this->unk_90 = src->unk_90;
    this->unk_91 = src->unk_91;
    this->unk_92 = src->unk_92;
    this->unk_93 = src->unk_93;
    this->unk_94 = src->unk_94;
    this->unk_95 = src->unk_95;
    this->unk_96 = src->unk_96;

    this->state1 = src->state1;
    this->state2 = src->state2;

    this->unk_a0 = src->unk_a0;
    this->unk_a4 = src->unk_a4;

    this->unk_00 |= src->unk_00;

    this->unk_05 = src->unk_05;
    this->unk_04 = src->unk_04;
    this->unk_08 = src->unk_08;
    this->unk_0a = src->unk_0a;
    this->unk_07 = src->unk_07;
    this->unk_06 = src->unk_06;

    for (i = 0; i < 4; i++)
    {
        this->unk_0c[i] = src->unk_0c[i];
    }

    psVar2 = src->unk_10;
    psVar4 = this->unk_10;
    for (i = 0; i < 0x10; i++)
    {
        *psVar4++ = *psVar2++;
    }

    this->unk_30.unk_00 = src->unk_30.unk_00;
    this->unk_30.unk_02 = src->unk_30.unk_02;
    this->unk_30.unk_04 = src->unk_30.unk_04;

    return this;
}

EC s32 GetPersonDBIndex(struct PersonData *);
EC s32 GetJobDBIndex(struct JobData *);
EC void func_020a58b8(void *, void *, s32);

extern struct Unit * gUnitList;

void Unit::Save(struct SaveBuffer * buf)
{
    s32 i;
    s16 * c;

    buf->WriteShort(GetPersonDBIndex(this->pPersonData));
    buf->WriteShort(GetJobDBIndex(this->pJobData));

    func_020a58b8(this->unk_50, buf->unk_04, sizeof(this->unk_50));
    buf->unk_04 += sizeof(this->unk_50);

    func_020a58b8(this->unk_58, buf->unk_04, sizeof(this->unk_58));
    buf->unk_04 += sizeof(this->unk_58);

    buf->WriteByte(this->unk_69);
    buf->WriteByte(this->level);
    buf->WriteByte(this->exp);
    buf->WriteByte(this->hp);
    buf->WriteByte(this->mov);
    buf->WriteByte(this->xPos);
    buf->WriteByte(this->yPos);

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        this->items[i].Save(buf);
    }

    for (i = 0; i < 6; i++)
    {
        buf->WriteByte(this->unk_84[i]);
    }

    for (i = 0; i < 5; i++)
    {
        buf->WriteByte(this->unk_8a[i]);
    }

    buf->WriteByte(this->alpha);
    buf->WriteByte(this->unk_90);
    buf->WriteByte(this->unk_91);
    buf->WriteByte(this->unk_92);
    buf->WriteByte(this->unk_93);
    buf->WriteByte(this->unk_94);
    buf->WriteByte(this->unk_96);
    buf->WriteWord(this->state1);
    buf->WriteWord(this->state2);

    if (this->unk_a0 != NULL)
    {
        buf->WriteByte(this->unk_a0->unk_68);
    }
    else
    {
        buf->WriteByte(0);
    }

    if (this->unk_a4 != 0)
    {
        buf->WriteShort(this->unk_a4->unk_04);
    }
    else
    {
        buf->WriteShort(-1);
    }

    if (this->force->id == 1)
    {
        buf->WriteShort(this->unk_00);
        buf->WriteByte(this->unk_05);
        buf->WriteByte(this->unk_04);
        buf->WriteByte(this->unk_08);
        buf->WriteShort(this->unk_0a);
        buf->WriteByte(this->unk_07);
        buf->WriteByte(this->unk_06);

        for (i = 0; i < 4; i++)
        {
            buf->WriteByte(this->unk_0c[i]);
        }

        for (i = 0, c = this->unk_10; i < 16; i++, c++)
        {
            buf->WriteShort(*c);
        }

        buf->WriteByte(this->unk_02);
        buf->WriteByte(this->unk_03);
    }
    else
    {
        buf->WriteShort(this->unk_30.unk_00);
        buf->WriteShort(this->unk_30.unk_02);
        buf->WriteShort(this->unk_30.unk_04);
    }

    return;
}

void Unit::Load(struct SaveBuffer * buf, s32 param_3)
{
    s32 i;
    s32 x;
    s32 y;
    s32 unk;
    u32 unk2;
    s16 * c;

    this->pPersonData = gFE11Database->pPerson + buf->ReadShort();
    this->pJobData = gFE11Database->pJob + buf->ReadShort();

    func_020a58b8(buf->unk_04, this->unk_50, sizeof(this->unk_50));
    buf->unk_04 += sizeof(this->unk_50);

    func_020a58b8(buf->unk_04, this->unk_58, sizeof(this->unk_58));
    buf->unk_04 += sizeof(this->unk_58);

    this->unk_69 = buf->ReadByte();
    this->level = buf->ReadByte();
    this->exp = buf->ReadByte();
    this->hp = buf->ReadByte();
    this->mov = buf->ReadByte();

    x = buf->ReadByte();
    y = buf->ReadByte();
    this->SetPos(x, y);

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        this->items[i].Load(buf, param_3);
    }

    for (i = 0; i < 6; i++)
    {
        this->unk_84[i] = buf->ReadByte();
    }

    for (i = 0; i < 5; i++)
    {
        this->unk_8a[i] = buf->ReadByte();
    }

    this->alpha = buf->ReadByte();
    this->unk_90 = buf->ReadByte();
    this->unk_91 = buf->ReadByte();
    this->unk_92 = buf->ReadByte();
    this->unk_93 = buf->ReadByte();
    this->unk_94 = buf->ReadByte();

    if (param_3 >= 2)
    {
        this->unk_96 = buf->ReadByte();
    }

    this->state1 = buf->ReadWord();
    this->state2 = buf->ReadWord();

    if ((param_3 < 5) && func_0203b714(this, 0x10000))
    {
        this->state2 &= ~0x10000;
        this->state1 |= 0x20000000;
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

        this->unk_a0 = unk_a0;
    }
    else
    {
        this->unk_a0 = NULL;
    }

    unk2 = buf->ReadShort();
    this->unk_a4 = (unk2 != 0xffff) ? &gFE11Database->unk_38[unk2] : NULL;

    if (this->force->id == 1)
    {
        this->unk_00 = buf->ReadShort();
        this->unk_05 = buf->ReadByte();
        this->unk_04 = buf->ReadByte();
        this->unk_08 = buf->ReadByte();
        this->unk_0a = buf->ReadShort();
        this->unk_07 = buf->ReadByte();
        this->unk_06 = buf->ReadByte();

        for (i = 0; i < 4; i++)
        {
            this->unk_0c[i] = buf->ReadByte();
        }

        for (i = 0, c = this->unk_10; i < 16; i++, c++)
        {
            *c = buf->ReadShort();
        }

        if (param_3 >= 1)
        {
            s32 unk_02 = buf->ReadByte();
            s32 unk_03 = buf->ReadByte();
            this->unk_02 = unk_02;
            this->unk_03 = unk_03;
        }
    }
    else
    {
        this->unk_30.unk_00 = buf->ReadShort();
        this->unk_30.unk_02 = buf->ReadShort();
        this->unk_30.unk_04 = buf->ReadShort();
    }

    return;
}

void Unit::_0203b720(struct SaveBuffer * buf)
{
    s32 startPos;
    s32 endPos;
    s32 sum;
    s32 i;

    startPos = (u32)buf->unk_04 - buf->unk_00;
    buf->WriteByte(1);

    if (this->pPersonData != NULL)
    {
        buf->WriteShort(GetPersonDBIndex(this->pPersonData));
    }
    else
    {
        buf->WriteShort(0xffff);
    }

    if (this->pJobData != NULL)
    {
        buf->WriteShort(GetJobDBIndex(this->pJobData));
    }
    else
    {
        buf->WriteShort(0xffff);
    }

    func_020a58b8(this->unk_50, buf->unk_04, sizeof(this->unk_50));
    buf->unk_04 += sizeof(this->unk_50);

    func_020a58b8(this->unk_58, buf->unk_04, sizeof(this->unk_58));
    buf->unk_04 += sizeof(this->unk_58);

    buf->WriteByte(this->level);
    buf->WriteByte(this->exp);
    buf->WriteByte(this->hp);
    buf->WriteByte(this->mov);
    buf->WriteByte(this->force->id);

    for (i = 0; i < 6; i++)
    {
        buf->WriteByte(this->unk_84[i]);
    }

    buf->WriteWord(this->state1);
    buf->WriteWord(this->state2);

    endPos = (u32)buf->unk_04 - buf->unk_00;

    sum = 0;

    for (i = startPos; i < endPos; i++)
    {
        sum += ((u8 *)(buf->unk_00))[i];
    }

    buf->WriteWord(sum);

    return;
}

BOOL Unit::_0203ba20(struct SaveBuffer * buf)
{
    s32 startPos;
    s32 endPos;
    s32 storedSum;
    s32 sum;
    s32 i;
    s32 type;
    u16 idx;

    startPos = (u32)buf->unk_04 - buf->unk_00;
    type = buf->ReadByte();

    idx = buf->ReadShort();

    if (idx == 0xffff)
    {
        this->pPersonData = NULL;
    }
    else
    {
        this->pPersonData = &gFE11Database->pPerson[idx];
    }

    idx = buf->ReadShort();

    if (idx == 0xffff)
    {
        this->pJobData = NULL;
    }
    else
    {
        this->pJobData = &gFE11Database->pJob[idx];
    }

    func_020a58b8(buf->unk_04, this->unk_50, sizeof(this->unk_50));
    buf->unk_04 += sizeof(this->unk_50);

    func_020a58b8(buf->unk_04, this->unk_58, sizeof(this->unk_58));
    buf->unk_04 += sizeof(this->unk_58);

    this->level = buf->ReadByte();
    this->exp = buf->ReadByte();
    this->hp = buf->ReadByte();
    this->mov = buf->ReadByte();

    this->force = Force::Get(buf->ReadByte());

    for (i = 0; i < 6; i++)
    {
        this->unk_84[i] = buf->ReadByte();
    }

    this->state1 = buf->ReadWord();
    this->state2 = buf->ReadWord();

    if ((type < 5) && (this->state2 & 0x10000))
    {
        this->state2 &= ~0x10000;
        this->state1 |= 0x20000000;
    }

    if (type >= 1)
    {
        endPos = (u32)buf->unk_04 - buf->unk_00;
        storedSum = buf->ReadWord();

        sum = 0;

        for (i = startPos; i < endPos; i++)
        {
            sum += ((u8 *)(buf->unk_00))[i];
        }

        if (storedSum != sum)
        {
            return FALSE;
        }
    }

    return TRUE;
}

void Unit::_0203bcf4(void)
{
    this->state2 &= 0xFFFD91BE;
    this->unk_91 = 0;
    this->unk_92 = 0;
    this->unk_93 = 0;
    this->unk_a4 = 0;

    if ((this->state2 & 0x8000) == 0)
    {
        return;
    }

    this->_0203bf68();

    return;
}

void Unit::MoveToForce(s32 factionId, BOOL append)
{
    if (((this->force->id < 2) && (factionId >= 2)) && (factionId != 5))
    {
        this->SetPos(0xff, 0xff);
        this->hp = this->GetMaxHp();
        this->alpha = 0x1f;
        this->_0203bcf4();
    }

    this->force->Remove(this);

    if (factionId == 4)
    {
        this->Init();
    }

    if (!append)
    {
        Force::Get(factionId)->InsertHead(this);
        return;
    }
    else
    {
        Force::Get(factionId)->InsertTail(this);
        return;
    }
}

Unit * Unit::_0203bdd0(u8 arg_1)
{
    s32 i;
    Force * force;

    if (this->unk_3c != NULL)
    {
        return this->unk_3c;
    }

    for (i = this->force->id + 1; i < 6; i++)
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

EC void Unit::_0203be30(struct Unit * arg_1)
{
    s32 i;
    s32 hp;
    struct Unit * pUVar5;

    pUVar5 = Force::Get(4)->head;

    pUVar5->MoveToForce(5, TRUE);

    pUVar5->Copy(this);
    this->Copy(arg_1);

    this->SetPos(pUVar5->xPos, pUVar5->yPos);

    hp = pUVar5->hp;
    this->hp = hp;

    if (hp > this->GetMaxHp())
    {
        this->hp = this->GetMaxHp();
    }

    this->exp = pUVar5->exp;
    this->state2 = pUVar5->state2;
    this->unk_90 = pUVar5->unk_90;
    this->unk_91 = pUVar5->unk_91;
    this->unk_92 = pUVar5->unk_92;
    this->unk_94 = pUVar5->unk_94;
    this->unk_a4 = pUVar5->unk_a4;

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        struct Item * dst;
        this->items[i] = &pUVar5->items[i];
        dst = &this->items[i];

        if (!(dst->flags & 0x10))
        {
            continue;
        }

        if (this->CanEquip(i, 0))
        {
            continue;
        }

        dst->flags &= ~0x10;
    }

    this->state1 &= ~0x1002;
    this->unk_a0 = pUVar5;
    this->state2 |= 0x8000;
    this->unk_93 = 5;

    return;
}

void Unit::_0203bf68(void)
{
    struct Unit * dstUnit;
    s32 i;
    s32 hp;

    dstUnit = this->unk_a0;

    dstUnit->SetPos(this->xPos, this->yPos);

    hp = this->hp;
    dstUnit->hp = hp;

    if (hp > dstUnit->GetMaxHp())
    {
        dstUnit->hp = dstUnit->GetMaxHp();
    }

    dstUnit->exp = this->exp;

    dstUnit->state2 = this->state2;

    dstUnit->unk_90 = this->unk_90;
    dstUnit->unk_91 = this->unk_91;
    dstUnit->unk_92 = this->unk_92;
    dstUnit->unk_94 = this->unk_94;
    dstUnit->unk_a4 = this->unk_a4;

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        struct Item * dst;
        dstUnit->items[i] = &this->items[i];

        dst = &dstUnit->items[i];

        if (!(dst->flags & ITEM_FLAG_EQUIPPED))
        {
            continue;
        }

        if (dstUnit->CanEquip(i, 0))
        {
            continue;
        }

        dst->flags &= ~ITEM_FLAG_EQUIPPED;
    }

    this->Copy(dstUnit);

    this->state2 &= ~0x8000;

    dstUnit->MoveToForce(4, TRUE);

    return;
}

void Unit::_0203c068(struct Unit * arg_1)
{
    s32 i;

    struct Unit * pUVar7 = Force::Get(4)->head;

    pUVar7->MoveToForce(5, TRUE);

    pUVar7->Copy(this);
    this->Copy(arg_1);

    this->SetPos(pUVar7->xPos, pUVar7->yPos);

    this->hp = this->GetMaxHp();
    this->exp = pUVar7->exp;

    this->state2 = pUVar7->state2;
    this->unk_90 = pUVar7->unk_90;
    this->unk_91 = pUVar7->unk_91;
    this->unk_92 = pUVar7->unk_92;
    this->unk_94 = pUVar7->unk_94;
    this->unk_a4 = pUVar7->unk_a4;

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        struct Item * pUVar9;
        this->items[i] = &pUVar7->items[i];
        pUVar9 = &this->items[i];

        if (!(pUVar9->flags & ITEM_FLAG_EQUIPPED))
        {
            continue;
        }

        if (this->CanEquip(i, 0))
        {
            continue;
        }

        pUVar9->flags &= ~ITEM_FLAG_EQUIPPED;
    }

    this->state1 &= ~(CA_UNK_1 | CA_BOSS);
    this->state1 |= pUVar7->CheckAttribute(CA_UNK_1 | CA_BOSS);

    this->unk_a0 = pUVar7;
    this->state2 |= 0x40000;

    return;
}

void Unit::_0203c19c(void)
{
    struct Unit * dstUnit;
    s32 i;

    dstUnit = this->unk_a0;

    dstUnit->SetPos(this->xPos, this->yPos);

    dstUnit->hp = dstUnit->GetMaxHp();
    dstUnit->exp = this->exp;

    dstUnit->state2 = this->state2;

    dstUnit->unk_90 = this->unk_90;
    dstUnit->unk_91 = this->unk_91;
    dstUnit->unk_92 = this->unk_92;
    dstUnit->unk_94 = this->unk_94;

    dstUnit->unk_a4 = this->unk_a4;

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        struct Item * dst;
        dstUnit->items[i] = &this->items[i];

        dst = &dstUnit->items[i];

        if (!(dst->flags & ITEM_FLAG_EQUIPPED))
        {
            continue;
        }

        if (dstUnit->CanEquip(i, 0))
        {
            continue;
        }

        dst->flags &= ~ITEM_FLAG_EQUIPPED;
    }

    this->Copy(dstUnit);

    this->state2 &= ~0x40000;

    dstUnit->MoveToForce(4, TRUE);

    return;
}

char * Unit::_0203c284(void)
{
    Unit * unit = func_0203c378(this);

    if ((unit->state2 & 0x80000) != 0)
    {
        return func_020423e4(unit->unk_96);
    }

    return func_02037eb8(unit->pPersonData);
}

// #func_0203c378

s32 Unit::GetMaxHp(void)
{
    struct JobData * job = this->pJobData;
    s32 hp;

    hp = this->pPersonData->bases[UNIT_STAT_HP] + job->bases[UNIT_STAT_HP];
    hp += this->unk_50[UNIT_STAT_HP];

    if (hp >= job->caps[UNIT_STAT_HP])
    {
        hp = job->caps[UNIT_STAT_HP];
    }

    return hp;
}

s32 Unit::GetStr(ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 str;

    if (item == NULL)
    {
        job = this->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, this);
    }

    str = this->pPersonData->bases[UNIT_STAT_STR] + job->bases[UNIT_STAT_STR];
    str += this->unk_50[UNIT_STAT_STR];

    if (str < 0)
    {
        str = 0;
    }

    if (str >= job->caps[UNIT_STAT_STR])
    {
        str = job->caps[UNIT_STAT_STR];
    }

    return str;
}

s32 Unit::GetMag(ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 mag;

    if (item == NULL)
    {
        job = this->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, this);
    }

    mag = this->pPersonData->bases[UNIT_STAT_MAG] + job->bases[UNIT_STAT_MAG];
    mag += this->unk_50[UNIT_STAT_MAG];

    if (mag < 0)
    {
        mag = 0;
    }

    if (mag >= job->caps[UNIT_STAT_MAG])
    {
        mag = job->caps[UNIT_STAT_MAG];
    }

    return mag;
}

s32 Unit::GetSkl(ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 skl;

    if (item == NULL)
    {
        job = this->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, this);
    }

    skl = this->pPersonData->bases[UNIT_STAT_SKL] + job->bases[UNIT_STAT_SKL];
    skl += this->unk_50[UNIT_STAT_SKL];

    if (skl < 0)
    {
        skl = 0;
    }

    if (skl >= job->caps[UNIT_STAT_SKL])
    {
        skl = job->caps[UNIT_STAT_SKL];
    }

    return skl;
}

s32 Unit::GetSpd(ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 spd;

    if (item == NULL)
    {
        job = this->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, this);
    }

    spd = this->pPersonData->bases[UNIT_STAT_SPD] + job->bases[UNIT_STAT_SPD];
    spd += this->unk_50[UNIT_STAT_SPD];

    if (spd < 0)
    {
        spd = 0;
    }

    if (spd >= job->caps[UNIT_STAT_SPD])
    {
        spd = job->caps[UNIT_STAT_SPD];
    }

    return spd;
}

s32 Unit::GetLuk(ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 luk;

    if (item == NULL)
    {
        job = this->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, this);
    }

    luk = this->pPersonData->bases[UNIT_STAT_LUK] + job->bases[UNIT_STAT_LUK];
    luk += this->unk_50[UNIT_STAT_LUK];

    if (luk < 0)
    {
        luk = 0;
    }

    if (luk >= job->caps[UNIT_STAT_LUK])
    {
        luk = job->caps[UNIT_STAT_LUK];
    }

    return luk;
}

s32 Unit::GetDef(ItemData * item, BOOL unused)
{
    struct JobData * job;
    s32 def;

    if (item == NULL)
    {
        job = this->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, this);
    }

    def = this->pPersonData->bases[UNIT_STAT_DEF] + job->bases[UNIT_STAT_DEF];
    def += this->unk_50[UNIT_STAT_DEF];

    if (def < 0)
    {
        def = 0;
    }

    if (def >= job->caps[UNIT_STAT_DEF])
    {
        def = job->caps[UNIT_STAT_DEF];
    }

    return def;
}

s32 Unit::GetRes(ItemData * item, BOOL arg_2)
{
    struct JobData * job;
    s32 res;

    if (item == NULL)
    {
        job = this->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, this);
    }

    res = this->pPersonData->bases[UNIT_STAT_RES] + job->bases[UNIT_STAT_RES];
    res += this->unk_50[UNIT_STAT_RES];

    if (res < 0)
    {
        res = 0;
    }

    if (arg_2 != 0)
    {
        res += this->unk_91;
    }

    if (res >= job->caps[UNIT_STAT_RES])
    {
        res = job->caps[UNIT_STAT_RES];
    }

    return res;
}

s32 Unit::GetStat(u32 statIdx, ItemData * item, s32 arg_3)
{
    struct JobData * job;
    s32 stat;

    if (item == NULL)
    {
        job = this->pJobData;
    }
    else
    {
        job = GetJInfoFromItem(item, this);
    }

    stat = this->pPersonData->bases[statIdx] + job->bases[statIdx];
    stat += this->unk_50[statIdx];

    if (stat < 0)
    {
        stat = 0;
    }

    if ((arg_3 != 0) && (statIdx == UNIT_STAT_RES))
    {
        stat += this->unk_91;
    }

    if (stat >= job->caps[statIdx])
    {
        stat = job->caps[statIdx];
    }

    return stat;
}

BOOL Unit::_0203c73c(s32 arg_1)
{
    if ((arg_1 == UNIT_STAT_RES) && (this->unk_91 != 0))
    {
        return TRUE;
    }

    return FALSE;
}

u32 Unit::_0203c75c(void)
{
    u32 base = this->pPersonData->bases[UNIT_STAT_RES] + this->pJobData->bases[UNIT_STAT_RES];
    return base + this->unk_50[UNIT_STAT_RES];
}

s32 Unit::GetMov(void)
{
    return this->pJobData->mov + this->mov;
}

s32 Unit::_0203c790(void)
{
    return this->pJobData->unk_2a + (((this->unk_92 + 1) & ~1) >> 1);
}

s32 Unit::GetWeaponLevel(u32 type)
{
    u32 uVar1 = this->pJobData->weaponLevels[type];

    if (uVar1 != 0)
    {
        return uVar1 + this->pPersonData->weaponLevels[type] + this->unk_84[type];
    }

    return 0;
}

s32 Unit::GetBaseWeaponLevel(u32 arg_1)
{
    if (this->pJobData->weaponLevels[arg_1] != 0)
    {
        return this->pJobData->weaponLevels[arg_1] + this->pPersonData->weaponLevels[arg_1];
    }

    return 0;
}

s32 Unit::CheckAttribute(u32 attribute)
{
    return (this->state1 & attribute) | (this->GetPersonAttr() & attribute) | (this->GetJobAttr() & attribute);
}

BOOL Unit::CanEquip(ItemData * item, s32 arg_2)
{
    s32 itemType = item->type;

    if (arg_2 == 0 && itemType == ITYPE_STAFF)
    {
        return FALSE;
    }

    if (itemType == ITYPE_DRAGONSTONE)
    {
        if (!(this->pJobData->unitType & 0x40))
        {
            return FALSE;
        }
    }
    else if (itemType == ITYPE_BALLISTA)
    {
        if (!(this->pJobData->unitType & 8))
        {
            return FALSE;
        }
    }
    else
    {
        if (itemType >= ITYPE_DRAGONSTONE)
        {
            return FALSE;
        }

        if (((item->attributes & IA_AURA_WLVL) && this->CheckAttribute(CA_UNK_8)) ||
            ((item->attributes & IA_EXCALIBUR_WLVL) && this->CheckAttribute(CA_UNK_7)))
        {
            s32 wlvl = gFE11Database->pWeaponLevel[4];
            if (wlvl > this->GetWeaponLevel(itemType))
            {
                return FALSE;
            }
        }
        else
        {
            s32 wlvl = item->wpnLevel;
            if (wlvl > this->GetWeaponLevel(itemType))
            {
                return FALSE;
            }
        }
    }

    if (item->attributes &
        (IA_UNK_50 | IA_MARTH_LOCK | IA_PRINCESS_LOCK | IA_CAEDA_LOCK | IA_LENA_LOCK | IA_UNK_55 | IA_UNK_56 |
         IA_LONGBOW | IA_EXCALIBUR_LOCK | IA_AURA_LOCK))
    {
        if ((item->attributes & IA_UNK_50) && !this->CheckAttribute(CA_UNK_1))
        {
            return FALSE;
        }

        if ((item->attributes & IA_MARTH_LOCK) && !this->CheckAttribute(CA_LORD))
        {
            return FALSE;
        }

        if ((item->attributes & IA_PRINCESS_LOCK) && !this->CheckAttribute(CA_PRINCESS))
        {
            return FALSE;
        }

        if ((item->attributes & IA_CAEDA_LOCK) && !this->CheckAttribute(CA_UNK_5))
        {
            return FALSE;
        }

        if ((item->attributes & IA_LENA_LOCK) && !this->CheckAttribute(CA_UNK_6))
        {
            return FALSE;
        }

        if ((item->attributes & IA_UNK_55) && !this->CheckAttribute(CA_UNK_4))
        {
            return FALSE;
        }

        if ((item->attributes & IA_UNK_56) && !this->CheckAttribute(CA_UNK_9))
        {
            return FALSE;
        }

        if ((item->attributes & IA_LONGBOW) && !(this->pJobData->unitType & 0x80))
        {
            return FALSE;
        }

        if ((item->attributes & IA_EXCALIBUR_LOCK) && this->CheckAttribute(CA_FEMALE))
        {
            return FALSE;
        }

        if ((item->attributes & IA_AURA_LOCK) && !this->CheckAttribute(CA_FEMALE))
        {
            return FALSE;
        }
    }

    return TRUE;
}

BOOL Unit::CanEquip(s32 slot, s32 arg_2)
{
    return this->CanEquip(this->items[slot].GetData(), arg_2);
}

s32 Unit::GetEquippedWeaponSlot(void)
{
    s32 i;
    struct Item * item = this->items;

    for (i = 0; i < UNIT_ITEM_COUNT; i++, item++)
    {
        if (!(item->flags & ITEM_FLAG_EQUIPPED))
        {
            continue;
        }

        return i;
    }

    return -1;
}

u64 Unit::GetItemAttributes(u64 mask)
{
    struct ItemData * item;
    u64 ret;
    s32 i;
    struct Item * it;

    ret = 0;

    it = this->items;

    for (i = 0; i < UNIT_ITEM_COUNT; i++, it++)
    {
        item = it->GetData();
        ret |= item->attributes & mask;
    }

    return ret;
}

u64 Unit::GetEquippableItemAttributes(u64 mask)
{
    struct ItemData * item;
    u64 ret;
    s32 i;
    struct Item * it;

    ret = 0;

    it = this->items;

    for (i = 0; i < UNIT_ITEM_COUNT; i++, it++)
    {
        if (!this->CanEquip(i, 0))
        {
            continue;
        }

        item = it->GetData();
        ret |= item->attributes & mask;
    }

    return ret;
}

void Unit::MoveItem(s32 from, s32 to)
{
    struct Item tmp;

    tmp = &this->items[from];

    if (from >= to)
    {
        for (; from > to; from--)
        {
            this->items[from] = &this->items[from - 1];
        }
    }
    else if (from < to)
    {
        for (; from < to; from++)
        {
            this->items[from] = &this->items[from + 1];
        }
    }

    this->items[to] = &tmp;

    return;
}

BOOL Unit::EquipItem(s32 slot)
{
    s32 equippedSlot;
    s32 i;

    if (slot == -1)
    {
        for (i = 0; i < UNIT_ITEM_COUNT; i++)
        {
            if (!this->CanEquip(i, 0))
            {
                continue;
            }

            this->EquipItem(i);
            return TRUE;
        }

        return FALSE;
    }

    if (!this->CanEquip(slot, 0))
    {
        return FALSE;
    }

    equippedSlot = this->GetEquippedWeaponSlot();

    if (equippedSlot != -1)
    {
        struct Item * item = this->items + equippedSlot;
        item->flags &= ~ITEM_FLAG_EQUIPPED;
    }

    this->MoveItem(slot, 0);
    this->items[0].flags |= ITEM_FLAG_EQUIPPED;

    return TRUE;
}

void Unit::UnequipItem(s32 slot)
{
    struct Item * item = this->items + slot;
    item->flags &= ~ITEM_FLAG_EQUIPPED;
    return;
}

void Unit::ClearItemAtSlot(s32 slot, BOOL shiftDown)
{
    if (shiftDown)
    {
        for (; slot < UNIT_ITEM_COUNT - 1; slot++)
        {
            this->items[slot] = &this->items[slot + 1];
        }

        // Required to match, even though it's duplicated below
        this->items[slot].Clear();
        return;
    }

    this->items[slot].Clear();

    return;
}

void Unit::ClearItems(void)
{
    s32 i;

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        this->ClearItemAtSlot(i, FALSE);
    }

    return;
}

BOOL Unit::AddItem(s32 iid, u32 flags)
{
    s32 i;
    struct Item * item = this->items;

    for (i = 0; i < UNIT_ITEM_COUNT; i++, item++)
    {
        if (item->id == 0)
        {
            break;
        }
    }

    if (i != UNIT_ITEM_COUNT)
    {
        item = this->items + i;
        item->InitFromIid(iid);
        item->flags |= flags;
        return TRUE;
    }

    return FALSE;
}

BOOL Unit::AddItem(ItemData * item, u32 flags)
{
    return this->AddItem(GetItemDBIndex(item), flags);
}

BOOL Unit::AddItem(Item * item)
{
    s32 i;
    struct Item * it = this->items;

    for (i = 0; i < UNIT_ITEM_COUNT; i++, it++)
    {
        if (it->id == 0)
        {
            break;
        }
    }

    if (i != UNIT_ITEM_COUNT)
    {
        this->items[i] = item;
        return TRUE;
    }

    return FALSE;
}

void Unit::CompactItems(void)
{
    s32 j;
    s32 i;
    struct Item * unitItems = this->items;

    while (TRUE)
    {
        struct Item * it = unitItems;
        for (i = 0; i < UNIT_ITEM_COUNT; i++, it++)
        {
            if (it->id == 0)
            {
                break;
            }
        }

        if (i == UNIT_ITEM_COUNT)
        {
            return;
        }

        for (j = i + 1; j < UNIT_ITEM_COUNT; j++)
        {
            it = unitItems + j;

            if (it->id != 0)
            {
                break;
            }
        }

        if (j == UNIT_ITEM_COUNT)
        {
            return;
        }

        unitItems[i] = &unitItems[j];
        unitItems[j].Clear();
    }
}

s32 Unit::GetItemCount(void)
{
    s32 i;
    struct Item * it = this->items;

    for (i = 0; i < UNIT_ITEM_COUNT; i++, it++)
    {
        if (it->id == 0)
        {
            break;
        }
    }

    return i;
}

s32 Unit::_0203d01c(void)
{
    s32 i;
    s32 ret;
    struct Item * it;

    ret = -1;

    it = this->items;

    for (i = 0; i < UNIT_ITEM_COUNT; i++, it++)
    {
        struct ItemData * item = it->GetData();

        if (ret != -1 && !(item->attributes & IA_UNK_27))
        {
            continue;
        }

        if (!func_02038e80(item, this))
        {
            continue;
        }

        ret = i;
    }

    return ret;
}

s32 Unit::_0203d094(void)
{
    s32 i;
    s32 found;
    struct Item * it;

    found = -1;

    it = this->items;

    for (i = 0; i < UNIT_ITEM_COUNT; i++, it++)
    {
        struct ItemData * item = it->GetData();

        if (found != -1 && !(item->attributes & IA_UNK_27))
        {
            continue;
        }

        if (!func_02038edc(item, this))
        {
            continue;
        }

        found = i;
    }

    return found;
}

s32 Unit::_0203d10c(void)
{
    s32 i;
    s32 found;
    struct Item * it;

    found = -1;

    it = this->items;

    for (i = 0; i < UNIT_ITEM_COUNT; i++, it++)
    {
        struct ItemData * item = it->GetData();

        if (found != -1 && !(item->attributes & IA_UNK_27))
        {
            continue;
        }

        if (!func_02038f38(item, this))
        {
            continue;
        }

        found = i;
    }

    return found;
}

BOOL Unit::_0203d184(void)
{
    if (this->CheckAttribute(CA_UNK_10))
    {
        return TRUE;
    }

    return this->_0203d01c() != -1;
}

BOOL Unit::_0203d1bc(void)
{
    if (this->CheckAttribute(CA_UNK_10))
    {
        return TRUE;
    }

    return this->_0203d094() != -1;
}

BOOL Unit::_0203d1f4(void)
{
    if (this->CheckAttribute(CA_UNK_10))
    {
        return TRUE;
    }

    return this->_0203d10c() != -1;
}

s32 Unit::ComputeMight(ItemData * item, BOOL arg_2)
{
    s32 might;

    if (item == NULL)
    {
        return 0;
    }

    might = item->might;

    if (!func_02038348(item))
    {
        s32 str = this->GetStr(item, TRUE);
        might += str;
    }
    else
    {
        s32 mag = this->GetMag(item, TRUE);
        might += mag;
    }

    if (arg_2)
    {
        might += this->_0203d2e4(item);
    }

    return might;
}

s32 Unit::ComputeMight(s32 slot, BOOL arg_2)
{
    if (slot == -1)
    {
        slot = this->GetEquippedWeaponSlot();
    }

    if (slot != -1)
    {
        return this->ComputeMight(this->items[slot].GetData(), arg_2);
    }

    return 0;
}

struct WeaponBonus
{
    s8 unk_00; // type?
    STRUCT_PAD(0x01, 0x02);
    s8 unk_02[0x0A];
};

s32 Unit::_0203d2e4(ItemData * item)
{
    struct WeaponBonus * row;
    s32 type;
    s32 wlvl;
    u8 * levels;
    s32 rank;

    if (item == NULL)
    {
        return 0;
    }

    type = item->type;

    if (type >= ITYPE_DRAGONSTONE)
    {
        return 0;
    }

    for (row = (struct WeaponBonus *)gFE11Database->unk_30; row->unk_00 != -1; row++)
    {
        if (row->unk_00 == type)
        {
            break;
        }
    }

    wlvl = this->GetWeaponLevel(type);
    levels = gFE11Database->pWeaponLevel;

    for (rank = 0; rank < 5; rank++)
    {
        if (wlvl >= levels[rank])
        {
            break;
        }
    }

    return row->unk_02[rank];
}

s32 Unit::ComputeHitRate(ItemData * item, BOOL arg_2)
{
    s32 hit;

    if (item == NULL)
    {
        return 0;
    }

    hit = item->hit;
    hit += this->GetSkl(item, TRUE);
    hit += (this->GetLuk(item, TRUE) >> 1);

    if (arg_2 != 0)
    {
        hit += this->_0203d45c(item);
    }

    if (this->CheckAttribute(CA_UNK_16 | CA_UNK_17))
    {
        if (this->CheckAttribute(CA_UNK_16)) // Sniper attr
        {
            hit += 5;
        }

        if (this->CheckAttribute(CA_UNK_17)) // Swordmaster attr
        {
            hit += 10;
        }
    }

    return hit;
}

s32 Unit::ComputeHitRate(s32 slot, BOOL arg_2)
{
    if (slot == -1)
    {
        slot = this->GetEquippedWeaponSlot();
    }

    if (slot != -1)
    {
        return this->ComputeHitRate(this->items[slot].GetData(), arg_2);
    }

    return 0;
}

s32 Unit::_0203d45c(ItemData * item)
{
    struct WeaponBonus * row;
    s32 type;
    s32 wlvl;
    u8 * levels;
    s32 rank;

    if (item == NULL)
    {
        return 0;
    }

    type = item->type;

    if (type >= ITYPE_DRAGONSTONE)
    {
        return 0;
    }

    for (row = (struct WeaponBonus *)gFE11Database->unk_30; row->unk_00 != -1; row++)
    {
        if (row->unk_00 == type)
        {
            break;
        }
    }

    wlvl = this->GetWeaponLevel(type);
    levels = gFE11Database->pWeaponLevel;

    for (rank = 0; rank < 5; rank++)
    {
        if (wlvl >= levels[rank])
        {
            break;
        }
    }

    return row->unk_02[rank];
}

s32 Unit::ComputeCritRate(ItemData * item)
{
    s32 critical;

    if (item == NULL)
    {
        return 0;
    }

    critical = item->critical;
    critical += this->GetSkl(item, 1) >> 1;

    if (this->CheckAttribute(CA_UNK_18 | CA_UNK_19))
    {
        if (this->CheckAttribute(CA_UNK_18)) // Sniper attr
        {
            critical += 5;
        }

        if (this->CheckAttribute(CA_UNK_19)) // Berserker attr
        {
            critical += 10;
        }
    }

    return critical;
}

s32 Unit::ComputeCritRate(s32 slot)
{
    if (slot == -1)
    {
        slot = this->GetEquippedWeaponSlot();
    }

    if (slot != -1)
    {
        return this->ComputeCritRate(this->items[slot].GetData());
    }

    return 0;
}

s32 Unit::ComputeAttackSpeed(ItemData * item)
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

    attackSpeed = this->GetStr(item, TRUE);
    attackSpeed -= weight;

    if (attackSpeed > 0)
    {
        attackSpeed = 0;
    }

    attackSpeed += this->GetSpd(item, TRUE);

    if (attackSpeed < 0)
    {
        attackSpeed = 0;
    }

    return attackSpeed;
}

s32 Unit::ComputeAvoid(ItemData * item)
{
    s32 attackSpeed = this->ComputeAttackSpeed(item);
    return attackSpeed + (this->GetLuk(item, TRUE) >> 1);
}

s32 Unit::ComputeAvoid(s32 slot)
{
    struct ItemData * item;

    if (slot == -1)
    {
        slot = this->GetEquippedWeaponSlot();
    }

    if (slot == -1)
    {
        item = NULL;
    }
    else
    {
        item = this->items[slot].GetData();
    }

    return this->ComputeAvoid(item);
}

s32 Unit::_0203d660(ItemData * item)
{
    return this->GetLuk(item, TRUE);
}

s32 Unit::GainExp(s32 exp)
{
    s32 level = this->level;

    if (exp >= 100)
    {
        exp = 100;
    }

    if (level >= GetJobMaxLevel(this->pJobData))
    {
        exp = 0;
    }
    else if (exp + this->exp >= 100)
    {
        level = this->level;
        if (level + 1 >= GetJobMaxLevel(this->pJobData))
        {
            exp = (exp < 100 - this->exp) ? exp : 100 - this->exp;
        }
    }

    return exp;
}

void Unit::LevelUp(void)
{
    u8 bVar1;
    s32 iVar2;
    s32 iVar3;
    s32 iVar4;
    s32 i;
    s32 iVar6;

    this->level++;

    for (i = 0; i < 8; i++)
    {
        iVar3 = 0;
        if (this->unk_50[i] * 100 < this->unk_58[i])
        {
            iVar3 = IntSys_Div(this->unk_58[i] + this->unk_50[i] * 100, 10);
        }

        iVar4 = this->pPersonData->growths[i] + this->pJobData->growths[i] - iVar3;
        iVar6 = this->unk_50[i];
        iVar3 = iVar6;

        if (iVar4 > 99)
        {
            bVar1 = this->pJobData->caps[i];
            iVar4 -= 100;
            iVar2 = this->GetStat(i, NULL, 0);
            if (iVar2 < bVar1)
            {
                iVar3 = iVar6 + 1;
            }
        }

        this->unk_50[i] = iVar3;

        if ((this->_0203dbc0() < iVar4) && this->GetStat(i, NULL, 0) < this->pJobData->caps[i])
        {
            iVar3 += 1;
        }

        this->unk_50[i] = iVar3;

        if ((iVar6 < iVar3) || (this->GetStat(i, NULL, 0) < this->pJobData->caps[i]))
        {
            iVar3 = this->pPersonData->growths[i] + this->pJobData->growths[i];

            if (iVar3 < 1)
            {
                iVar3 = 0;
            }

            this->unk_58[i] += iVar3;
        }
    }

    return;
}

void Unit::ChangeJob(struct JobData * job, BOOL arg_2)
{
    if (job == NULL)
    {
        job = this->pJobData->pPromoteToJob;
    }

    this->level = 1;
    this->exp = 0;
    this->pJobData = job;

    if (arg_2 != 0)
    {
        this->state1 |= 0x20000000;
    }

    return;
}

void Unit::_0203d874(void)
{
    struct Unit * supporterUnit;
    struct SupportData * support;
    s32 rank;
    s32 points;
    s32 i;

    for (i = 0; i < 5; i++)
    {
        support = &this->pPersonData->supports[i];

        if (support->supporter == NULL)
        {
            continue;
        }

        supporterUnit = this->force->func_02040d68(support->supporter);

        if (supporterUnit == NULL)
        {
            continue;
        }

        points = func_0203c378(this)->unk_8a[i];

        if (points >= support->pointsA)
        {
            rank = 3;
        }
        else if (points >= support->pointsB)
        {
            rank = 2;
        }
        else if (points >= support->pointsC)
        {
            rank = 1;
        }
        else
        {
            rank = 0;
        }

        if (rank == 3 ? TRUE : FALSE)
        {
            continue;
        }

        func_0203c378(this)->unk_8a[i]++;
    }

    return;
}

BOOL Unit::_0203dad4(Unit * other)
{
    char ** pidStr;
    struct Unit_unk_a4 * unk_a4 = this->unk_a4;

    if (unk_a4 == NULL)
    {
        return FALSE;
    }

    for (pidStr = unk_a4->unk_08; *pidStr != NULL; pidStr++)
    {
        struct PersonData * pPersonData = other->pPersonData;

        if (pPersonData == GetPersonByPidStr(*pidStr))
        {
            return TRUE;
        }
    }

    return FALSE;
}

s32 Unit::GetSpawnX(void)
{
    return gMapStateManager->unk_18->spawns[this->unk_69].xFinal;
}

s32 Unit::GetSpawnY(void)
{
    return gMapStateManager->unk_18->spawns[this->unk_69].yFinal;
}

EC void func_0204003c(struct Unit *);

void Unit::_0203db78(void)
{
    if (this->unk_05 == 0)
    {
        this->unk_05 = 1;
    }

    func_0204003c(this);

    return;
}

void Unit::_0203db94(s32 arg_1)
{
    u16 flags = this->unk_00;

    if (arg_1 == 0)
    {
        if (!(flags & 0x1000))
        {
            return;
        }
    }
    else
    {
        if (!(flags & 0x2000))
        {
            return;
        }
    }

    this->_0203db78();

    return;
}

s32 Unit::_0203dbc0(void)
{
    return RollRN(0, 99);
}

s32 Unit::_0203dbd4(BOOL useMag, BOOL useRes)
{
    s32 sum;
    s32 stat;

    sum = this->GetMaxHp();

    if (useMag)
    {
        stat = this->GetMag(NULL, TRUE);
    }
    else
    {
        stat = this->GetStr(NULL, TRUE);
    }

    sum += stat * 3;

    sum += this->GetSkl(NULL, TRUE);
    sum += this->GetSpd(NULL, TRUE) * 2;
    sum += this->GetLuk(NULL, TRUE);

    if (useRes)
    {
        stat = this->GetRes(NULL, TRUE);
    }
    else
    {
        stat = this->GetDef(NULL, TRUE);
    }

    sum += stat * 2;

    if (this->pJobData == GetJobByJidStr("JID_SWORDMASTER") || this->pJobData == GetJobByJidStr("JID_SWORDMASTER_F"))
    {
        sum += this->GetSkl(NULL, TRUE);
    }

    if (this->pJobData == GetJobByJidStr("JID_SNIPER") || this->pJobData == GetJobByJidStr("JID_SNIPER_F"))
    {
        sum += (this->GetStr(NULL, TRUE) + this->GetSkl(NULL, TRUE)) >> 1;
    }

    if (this->pJobData == GetJobByJidStr("JID_BERSERKER"))
    {
        sum += this->GetStr(NULL, TRUE);
    }

    return sum;
}

void Unit::_0203dd48(void)
{
    s32 iVar3;
    s32 iVar4;
    s32 cap;
    s32 i;

    for (i = 0; i < UNIT_STAT_COUNT; i++)
    {
        iVar4 = (this->pPersonData->growths[i] + this->pJobData->growths[i]) >> 1;
        iVar3 = this->unk_50[i];

        if (iVar4 >= 100)
        {
            cap = this->pJobData->caps[i];
            iVar4 -= 100;

            if (this->GetStat(i, NULL, FALSE) < cap)
            {
                iVar3++;
            }
        }

        this->unk_50[i] = iVar3;

        if (this->_0203dbc0() < iVar4)
        {
            cap = this->pJobData->caps[i];

            if (this->GetStat(i, NULL, FALSE) < cap)
            {
                iVar3++;
            }
        }

        this->unk_50[i] = iVar3;
    }

    this->hp = this->GetMaxHp();

    return;
}

void Unit::_0203de10(void)
{
    s32 iVar3;
    s32 iVar4;
    s32 i;

    for (i = 0; i < 8; i++)
    {
        iVar4 = (this->pPersonData->growths[i] + this->pJobData->growths[i]) >> 1;
        iVar3 = this->unk_50[i];

        if (iVar4 >= 100)
        {
            iVar4 -= 100;

            if (this->GetStat(i, NULL, 0) < this->pJobData->caps[i])
            {
                iVar3 -= 1;
            }
        }

        this->unk_50[i] = iVar3;

        if ((this->_0203dbc0() < iVar4) && this->GetStat(i, NULL, 0) < this->pJobData->caps[i])
        {
            iVar3 -= 1;
        }

        iVar4 = iVar3 + this->pPersonData->bases[i] + this->pJobData->bases[i];

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

        this->unk_50[i] = iVar3;
    }

    this->hp = this->GetMaxHp();

    return;
}

void Unit::_0203df18(void)
{
    s32 i;

    this->unk_00 = 0;
    this->unk_04 = 0;
    this->unk_05 = 0;
    this->unk_06 = 0;
    this->unk_07 = 0;
    this->unk_08 = 0;
    this->unk_0a = 0;

    this->unk_02 = -1;
    this->unk_03 = -1;

    for (i = 0; i < 4; i++)
    {
        this->unk_0c[i] = 0;
    }

    for (i = 0; i < 0x10; i++)
    {
        this->unk_10[i] = -1;
    }

    return;
}

EC void func_0203df78(struct Unit_unk_30 * param_1)
{
    param_1->unk_00 = 0;
    param_1->unk_02 = 0;
    param_1->unk_04 = 0;
    return;
}
