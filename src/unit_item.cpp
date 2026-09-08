#include "global.h"

#include "database.hpp"
#include "item.hpp"
#include "unit.hpp"

EC s32 GetItemDBIndex(struct ItemData *);
EC struct ItemData * GetItemByIidStr(char *);

struct ItemData * Item::GetData(void)
{
    return &gFE11Database->pItem[this->id];
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
    this->InitFromItemData(gFE11Database->pItem + iid);
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

BOOL Item::CanReduceUses(Unit * unit)
{
    ItemData * itemData = this->GetData();

    if (itemData->attributes & IA_INFINITE_DURABILITY)
    {
        return FALSE;
    }

    // Starsphere - if the unit is holding an item with this attribute, skip reducing uses
    if (unit != NULL && unit->GetItemAttributes(IA_NEGATE_DURABILITY_COST))
    {
        return FALSE;
    }

    return TRUE;
}

BOOL Item::ReduceUses(Unit * unit)
{
    if (!this->CanReduceUses(unit))
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
