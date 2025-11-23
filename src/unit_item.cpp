#include "global.h"

#include "unknown_data.h"
#include "unknown_types.hpp"

#include "unit.hpp"

EC s32 func_02037ffc(struct ItemData *);
EC struct ItemData * func_02037c68(char *);
EC void func_0203e02c(struct Item *);
EC u64 func_0203cbc4(Unit *, u64);

EC struct ItemData * GetItemData(struct Item * param_1)
{
    return &data_02197254->pItem[param_1->id];
}

EC void func_0203dfac(struct Item * param_1, struct ItemData * itemData)
{
    param_1->id = func_02037ffc(itemData);
    param_1->unk_02 = itemData->uses;
    param_1->unk_03 = 0;
    return;
}

EC void func_0203dfd8(struct Item * param_1, char * iidStr)
{
    if (iidStr != NULL)
    {
        func_0203dfac(param_1, func_02037c68(iidStr));
    }
    else
    {
        func_0203e02c(param_1);
    }

    return;
}

EC void func_0203e008(struct Item * param_1, s32 iid)
{
    func_0203dfac(param_1, data_02197254->pItem + iid);
    return;
}

EC void func_0203e02c(struct Item * param_1)
{
    param_1->id = 0;
    param_1->unk_02 = 0;
    param_1->unk_03 = 0;
    return;
}

EC void func_0203e040(struct Item * param_1, struct Item * param_2)
{
    param_1->id = param_2->id;
    param_1->unk_02 = param_2->unk_02;
    param_1->unk_03 = param_2->unk_03;
    return;
}

EC BOOL func_0203e05c(struct Item * param_1, struct Item * param_2)
{
    if (param_1->id != param_2->id)
    {
        return FALSE;
    }

    if (param_1->unk_02 != param_2->unk_02)
    {
        return FALSE;
    }

    if (param_1->unk_03 != param_2->unk_03)
    {
        return FALSE;
    }

    return TRUE;
}

EC BOOL func_0203e09c(struct Item * param_1, struct Unit * unit)
{
    struct ItemData * itemData = GetItemData(param_1);

    if ((itemData->attributes & 0x8000000) != 0)
    {
        return 0;
    }

    if (unit != NULL)
    {
        if (func_0203cbc4(unit, 0x10000000) != 0)
        {
            return 0;
        }
    }

    return 1;
}

EC BOOL func_0203e0f8(struct Item * param_1, struct Unit * unit)
{
    if (!func_0203e09c(param_1, unit))
    {
        return FALSE;
    }

    param_1->unk_02--;

    if (param_1->unk_02 == 0)
    {
        return 1;
    }

    return 0;
}

EC void SaveItem(struct Item * param_1, SaveBuffer * save)
{
    save->WriteShort(param_1->id);
    save->WriteByte(param_1->unk_02);
    save->WriteByte(param_1->unk_03);

    return;
}

EC void LoadItem(struct Item * param_1, SaveBuffer * save, s32 param_3)
{
    param_1->id = save->ReadShort();

    if (param_3 < 3 && param_1->id >= 0x67)
    {
        param_1->id += 0x21;
    }

    if (param_3 < 4 && param_1->id >= 0x88)
    {
        param_1->id += 0xb;
    }

    if (param_3 < 6)
    {
        if (param_1->id >= 0x93)
        {
            param_1->id -= 0x2c;
        }
        else if (param_1->id >= 0x67)
        {
            param_1->id = 0;
        }
    }

    param_1->unk_02 = save->ReadByte();
    param_1->unk_03 = save->ReadByte();

    return;
}
