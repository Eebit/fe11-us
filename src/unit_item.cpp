#include "global.h"

#include "unknown_data.h"
#include "unknown_types.hpp"

#include "unit.hpp"

EC s32 GetItemDBIndex(struct ItemData *);
EC struct ItemData * GetItemByIidStr(char *);
EC u64 func_0203cbc4(Unit *, u64);

struct ItemData * Item::GetData(void)
{
    return &data_02197254->pItem[this->id];
}

void Item::InitFromItemData(struct ItemData * itemData)
{
    this->id = GetItemDBIndex(itemData);
    this->uses = itemData->uses;
    this->flags = 0;
    return;
}

void Item::InitFromIidStr(char * iidStr)
{
    if (iidStr != NULL)
    {
        this->InitFromItemData(GetItemByIidStr(iidStr));
    }
    else
    {
        this->Clear();
    }

    return;
}

void Item::InitFromIid(s32 iid)
{
    this->InitFromItemData(data_02197254->pItem + iid);
    return;
}

void Item::Clear(void)
{
    this->id = 0;
    this->uses = 0;
    this->flags = 0;
    return;
}

Item * Item::operator=(struct Item * other)
{
    this->id = other->id;
    this->uses = other->uses;
    this->flags = other->flags;
    return this;
}

BOOL Item::operator==(struct Item * other)
{
    if (this->id != other->id)
    {
        return FALSE;
    }

    if (this->uses != other->uses)
    {
        return FALSE;
    }

    if (this->flags != other->flags)
    {
        return FALSE;
    }

    return TRUE;
}

BOOL Item::func_0203e09c(struct Unit * unit)
{
    struct ItemData * itemData = this->GetData();

    if ((itemData->attributes & 0x8000000) != 0)
    {
        return FALSE;
    }

    if (unit != NULL)
    {
        if (func_0203cbc4(unit, 0x10000000) != 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}

BOOL Item::func_0203e0f8(struct Unit * unit)
{
    if (!this->func_0203e09c(unit))
    {
        return FALSE;
    }

    this->uses--;

    if (this->uses == 0)
    {
        return TRUE;
    }

    return FALSE;
}

void Item::Save(SaveBuffer * save)
{
    save->WriteShort(this->id);
    save->WriteByte(this->uses);
    save->WriteByte(this->flags);

    return;
}

void Item::Load(SaveBuffer * save, s32 param_3)
{
    this->id = save->ReadShort();

    if (param_3 < 3 && this->id >= 0x67)
    {
        this->id += 0x21;
    }

    if (param_3 < 4 && this->id >= 0x88)
    {
        this->id += 0xb;
    }

    if (param_3 < 6)
    {
        if (this->id >= 0x93)
        {
            this->id -= 0x2c;
        }
        else if (this->id >= 0x67)
        {
            this->id = 0;
        }
    }

    this->uses = save->ReadByte();
    this->flags = save->ReadByte();

    return;
}
