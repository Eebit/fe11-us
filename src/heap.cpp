#include "global.h"

#include <new>

struct Block
{
    /* 00 */ struct Block * prev;
    /* 04 */ struct Block * next;
    /* 08 */ u32 size;
    /* 0C */ u16 offset;
    /* 0E */ u8 free;
    /* 0F */ u8 remainder;
};

struct Heap
{
    /* 00 */ struct Block * head;
};

EC s32 func_020a4a38();
EC void func_020a4a4c(s32);
EC s32 func_020a3fbc(s32);
EC s32 func_020a3fd0(s32);

EC void * func_01ffb934(struct Heap *, u32);
EC void func_01ffbb90(struct Heap *, void *);

EC void func_02011498(struct Heap *, struct Block *, s32);

extern struct Heap data_027e1b9c;

EC void func_02011458(void)
{
    s32 r5 = func_020a3fd0(0);
    s32 r4 = func_020a3fbc(0);
    func_02011498(&data_027e1b9c, (struct Block *)func_020a3fd0(0), r4 + 1 - r5);
    return;
}

EC void func_02011498(struct Heap * self, struct Block * block, s32 size)
{
    self->head = block;
    block->prev = NULL;
    self->head->next = NULL;
    self->head->size = (size - 0x10) & ~3;
    self->head->free = 1;
    self->head->offset = 0;
    self->head->remainder = 0;
    return;
}

EC s32 func_020114dc(struct Heap * heap, void * arg1)
{
    struct Block * block = heap->head;
    s32 lock = func_020a4a38();
    s32 size;

    for (; block != NULL; block = block->next)
    {
        if (block->free)
        {
            continue;
        }

        if (((u8 *)block + 0x10 + block->offset) != arg1)
        {
            continue;
        }

        size = block->size - block->remainder;
        break;
    }

    func_020a4a4c(lock);
    return size;
}

EC u32 func_0201153c(struct Heap * heap)
{
    struct Block * block;

    u32 size = 0;

    for (block = heap->head; block != NULL; block = block->next)
    {
        if (block->free != 1)
        {
            continue;
        }

        if (size <= block->size)
        {
            size = block->size;
        }
    }

    return size;
}

void * operator new(size_t size)
{
    return func_01ffb934(&data_027e1b9c, size);
}

void * operator new[](size_t size)
{
    return func_01ffb934(&data_027e1b9c, size);
}

void operator delete(void * ptr)
{
    func_01ffbb90(&data_027e1b9c, ptr);
    return;
}

void operator delete[](void * ptr)
{
    func_01ffbb90(&data_027e1b9c, ptr);
    return;
}
