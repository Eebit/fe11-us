#include "global.h"

#include "save.hpp"
#include "unit.hpp"

EC void func_020410bc(s32);
EC void func_020a58b8(void *, void *, s32);

extern Item * data_021974e0;

EC void func_02040eec(void)
{
    if (data_021974e0 == NULL)
    {
        data_021974e0 = new Item[200];
    }

    return;
}

EC void func_02040f28(void)
{
    s32 i;

    for (i = 0; i < 200; i++)
    {
        data_021974e0[i].Clear();
    }

    return;
}

EC void func_02040f5c(struct Item * item)
{
    s32 value;
    Item * it;
    s32 i;
    s32 bestIdx;
    s32 bestValue;

    for (i = 0, it = data_021974e0; i < 200; i++, it++)
    {
        if (!((it->id == 0 ? TRUE : FALSE) & 0xFF))
        {
            continue;
        }

        data_021974e0[i] = item;
        it = &data_021974e0[i];
        it->flags &= ~0x30;

        return;
    }

    bestIdx = -1;
    bestValue = 0x7fffffff;

    for (i = 0; i < 200; i++)
    {
        struct Item * it = &data_021974e0[i];
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
            value *= data_021974e0[i].uses;
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

    func_020410bc(bestIdx);

    data_021974e0[199] = item;
    data_021974e0[199].flags &= ~0x30;

    return;
}

EC void func_020410a0(struct ItemData * itemData)
{
    struct Item item;

    item.InitFromItemData(itemData);
    func_02040f5c(&item);

    return;
}

EC void func_020410bc(s32 param_1)
{
    s32 i;

    for (i = param_1; i < 199; i++)
    {
        data_021974e0[i] = &data_021974e0[i + 1];
    }

    data_021974e0[i].Clear();

    return;
}

EC s32 func_02041110(void)
{
    s32 i;
    s32 count;
    struct Item * item;

    for (i = 0, item = data_021974e0; i < 200; i++, item++)
    {
        if (((item->id == 0 ? TRUE : FALSE) & 0xFF))
        {
            continue;
        }

        count++;
    }

    return count;
}

EC void func_0204115c(SaveBuffer * save)
{
    func_020a58b8(data_021974e0, save->unk_04, sizeof(Item) * 200);
    save->unk_04 += sizeof(Item) * 200;

    return;
}

EC void func_0204118c(SaveBuffer * save, s32 param_2)
{
    if (param_2 <= 0)
    {
        func_020a58b8(save->unk_04, data_021974e0, sizeof(Item) * 100);
        save->unk_04 += sizeof(Item) * 100;
    }
    else
    {
        func_020a58b8(save->unk_04, data_021974e0, sizeof(Item) * 200);
        save->unk_04 += sizeof(Item) * 200;
    }

    return;
}
