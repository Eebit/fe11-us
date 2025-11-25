#include "global.h"

#include "save.hpp"
#include "unit.hpp"

EC void ConvoyRemoveItemAtIndex(s32);
EC void func_020a58b8(void *, void *, s32);

extern Item * gConvoy;

EC void InitConvoy(void)
{
    if (gConvoy == NULL)
    {
        gConvoy = new Item[200];
    }

    return;
}

EC void ClearConvoyItems(void)
{
    s32 i;

    for (i = 0; i < 200; i++)
    {
        gConvoy[i].Clear();
    }

    return;
}

EC void AddItemToConvoy(Item * item)
{
    s32 value;
    Item * it;
    s32 i;
    s32 bestIdx;
    s32 bestValue;

    for (i = 0, it = gConvoy; i < 200; i++, it++)
    {
        if (!((it->id == 0 ? TRUE : FALSE) & 0xFF))
        {
            continue;
        }

        gConvoy[i] = item;
        it = &gConvoy[i];
        it->flags &= ~0x30;

        return;
    }

    // If full, replace the item with the lowest value...?

    bestIdx = -1;
    bestValue = 0x7fffffff;

    for (i = 0; i < 200; i++)
    {
        struct Item * it = &gConvoy[i];
        struct ItemData * itemData = it->GetData();

        if (itemData->attributes & 0x2000000)
        {
            continue;
        }

        value = itemData->price;

        if (value == 0)
        {
            continue;
        }

        if (itemData->uses != 0)
        {
            value *= gConvoy[i].uses;
        }

        if (bestValue >= value)
        {
            bestIdx = i;
            bestValue = value;
        }
    }

    if (bestIdx == -1)
    {
        return;
    }

    ConvoyRemoveItemAtIndex(bestIdx);

    gConvoy[199] = item;
    gConvoy[199].flags &= ~0x30;

    return;
}

EC void AddNewItemToConvoy(struct ItemData * itemData)
{
    struct Item item;

    item.InitFromItemData(itemData);
    AddItemToConvoy(&item);

    return;
}

EC void ConvoyRemoveItemAtIndex(s32 index)
{
    s32 i;

    for (i = index; i < 199; i++)
    {
        gConvoy[i] = &gConvoy[i + 1];
    }

    gConvoy[i].Clear();

    return;
}

EC s32 CountConvoyItems(void)
{
    s32 i;
    s32 count;
    struct Item * item;

    for (i = 0, item = gConvoy; i < 200; i++, item++)
    {
        if (((item->id == 0 ? TRUE : FALSE) & 0xFF))
        {
            continue;
        }

        count++;
    }

    return count;
}

EC void SaveConvoy(SaveBuffer * save)
{
    func_020a58b8(gConvoy, save->unk_04, sizeof(Item) * 200);
    save->unk_04 += sizeof(Item) * 200;

    return;
}

EC void LoadConvoy(SaveBuffer * save, s32 param_2)
{
    if (param_2 <= 0)
    {
        func_020a58b8(save->unk_04, gConvoy, sizeof(Item) * 100);
        save->unk_04 += sizeof(Item) * 100;
    }
    else
    {
        func_020a58b8(save->unk_04, gConvoy, sizeof(Item) * 200);
        save->unk_04 += sizeof(Item) * 200;
    }

    return;
}
