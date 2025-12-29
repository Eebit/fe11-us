#include "global.h"

#include <new>

#include "heap.hpp"

#include "unknown_funcs.h"

extern struct Heap gHeap;

void Heap::Init(void)
{
    s32 r5 = func_020a3fd0(0);
    s32 r4 = func_020a3fbc(0);
    gHeap.Init((struct Block *)func_020a3fd0(0), r4 + 1 - r5);
    return;
}

void Heap::Init(struct Block * block, s32 size)
{
    this->head = block;
    block->prev = NULL;
    this->head->next = NULL;
    this->head->size = (size - 0x10) & ~3;
    this->head->free = 1;
    this->head->offset = 0;
    this->head->remainder = 0;
    return;
}

s32 Heap::SizeOf(void * addr)
{
    struct Block * block = this->head;
    s32 lock = func_020a4a38();
    s32 size;

    for (; block != NULL; block = block->next)
    {
        if (block->free)
        {
            continue;
        }

        if (((u8 *)block + 0x10 + block->offset) != addr)
        {
            continue;
        }

        size = block->size - block->remainder;
        break;
    }

    func_020a4a4c(lock);

    return size;
}

u32 Heap::GetLargestFreeSize(void)
{
    struct Block * block;

    u32 size = 0;

    for (block = this->head; block != NULL; block = block->next)
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
    return gHeap.Alloc(size);
}

void * operator new[](size_t size)
{
    return gHeap.Alloc(size);
}

void operator delete(void * ptr)
{
    gHeap.Free(ptr);
    return;
}

void operator delete[](void * ptr)
{
    gHeap.Free(ptr);
    return;
}
