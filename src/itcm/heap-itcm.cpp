#include "global.h"

#include "heap.hpp"

#include "unknown_funcs.h"

void * Heap::AllocateAlignedFromFront(struct Block * block, u32 size, u32 alignment)
{
    u32 tmp = (((u32)(((u32)block + sizeof(struct Block))) + (alignment)-1) & -(alignment));
    block->offset = tmp - ((u32)block + sizeof(struct Block));
    size = ALIGN_UP_POW2(size, alignment);

    if ((s32)block->offset >= 0x14)
    {
        struct Block * newBlock = (struct Block *)((u8 *)block + block->offset);

        newBlock->prev = block;
        newBlock->next = block->next;
        newBlock->size = block->size - block->offset;
        newBlock->free = TRUE;
        newBlock->offset = 0;
        newBlock->remainder = 0;

        block->next = newBlock;
        block->size = block->size - (newBlock->size + sizeof(struct Block));
        block->offset = 0;

        if (newBlock->next != NULL)
        {
            newBlock->next->prev = block->next;
        }

        block = newBlock;
    }

    block->free = FALSE;
    block->size -= block->offset;

    if ((block->size - size) >= 0x14)
    {
        struct Block * newBlock = (struct Block *)((u8 *)block + sizeof(struct Block) + (block->offset + size));

        newBlock->prev = block;
        newBlock->next = block->next;
        newBlock->size = block->size - (size + sizeof(struct Block));
        newBlock->free = TRUE;
        newBlock->offset = 0;
        newBlock->remainder = 0;

        block->next = newBlock;
        block->size = block->size - (newBlock->size + sizeof(struct Block));

        if (newBlock->next != NULL)
        {
            newBlock->next->prev = block->next;
        }
    }

    block->remainder = block->size - size;
    return (void *)((u8 *)block + block->offset + sizeof(struct Block));
}

void * Heap::AllocateAlignedFromBack(struct Block * block, u32 size, u32 alignment)
{
    u32 r4;
    u32 r5;
    void * tail;

    size = (size + alignment - 1) & (-alignment);
    tail = (void *)block->size;
    tail = (void *)((u8 *)block + ((u32)tail + sizeof(struct Block)));
    r5 = ((u32)tail) - (((u32)tail) & (-alignment));

    if (r5 >= 0x14)
    {
        struct Block * newBlock = (struct Block *)((u8 *)tail - r5);

        newBlock->prev = block;
        newBlock->next = block->next;
        newBlock->size = r5 - sizeof(struct Block);
        newBlock->free = TRUE;
        newBlock->offset = 0;
        newBlock->remainder = 0;

        block->next = newBlock;
        block->size = block->size - (newBlock->size + sizeof(struct Block));

        if (newBlock->next != NULL)
        {
            newBlock->next->prev = block->next;
        }

        r5 = 0;
    }

    r4 = r5 + size;

    if ((block->size - r4) >= 0x14)
    {
        struct Block * newBlock =
            (struct Block *)((u8 *)block + (block->size + sizeof(struct Block)) - (r4 + sizeof(struct Block)));

        newBlock->prev = block;
        newBlock->next = block->next;
        newBlock->size = r4;
        newBlock->free = FALSE;
        newBlock->offset = 0;

        newBlock->remainder = newBlock->size - size;
        block->next = newBlock;

        block->next = newBlock;
        block->size -= newBlock->size + sizeof(struct Block);

        if (newBlock->next != NULL)
        {
            newBlock->next->prev = block->next;
        }

        return (void *)((u8 *)newBlock + newBlock->offset + sizeof(struct Block));
    }

    return this->AllocateAlignedFromFront(block, size, alignment);
}

void Heap::FreeAndCoalesce(struct Block * block)
{
    struct Block * prev = block->prev;
    struct Block * next = block->next;

    if (prev == NULL || prev->free == FALSE)
    {
        if (next == NULL || next->free == FALSE)
        {
            block->free = TRUE;

            block->size = block->size + block->offset;
            block->offset = 0;
            block->remainder = 0;
        }
        else
        {
            block->free = TRUE;
            block->next = next->next;

            if (block->next != NULL)
            {
                block->next->prev = block;
            }

            block->size += next->size + sizeof(struct Block);
            block->size += block->offset;
            block->offset = 0;
            block->remainder = 0;
        }
    }
    else
    {
        if (next == NULL || next->free == FALSE)
        {
            prev->next = next;

            if (next != NULL)
            {
                next->prev = block->prev;
            }

            prev->size += block->offset + (block->size + sizeof(struct Block));
        }
        else
        {
            u32 size;

            prev->next = next->next;

            if (prev->next != NULL)
                prev->next->prev = prev;

            size = (next->size + 0x20) + block->size;
            prev->size += (size + block->offset);
        }
    }

    return;
}

EC void * Heap::Alloc(u32 size)
{
    struct Block * it = this->head;
    struct Block * freeBlock = NULL;
    void * ret = NULL;
    s32 lock;

    size = (((u32)(size) + (4 - 1)) & ~(4 - 1));
    lock = func_020a4a38();

    for (; it != NULL; it = it->next)
    {
        if (it->free == TRUE && it->size >= size)
        {
            freeBlock = it;
            break;
        }
    }

    if (freeBlock != NULL)
    {
        ret = this->AllocateAlignedFromFront(freeBlock, size, 4);
    }

    func_020a4a4c(lock);

    return ret;
}

void * Heap::_01ffb9bc(u32 size)
{
    struct Block * it = this->head;
    struct Block * freeBlock = NULL;
    void * ret = NULL;
    s32 lock;

    size = (((u32)(size) + ((4) - 1)) & ~((4) - 1));
    lock = func_020a4a38();

    for (; it != NULL; it = it->next)
    {
        if (it->free == TRUE && it->size >= size)
        {
            freeBlock = it;
        }
    }

    if (freeBlock != NULL)
    {
        ret = this->AllocateAlignedFromBack(freeBlock, size, 4);
    }

    func_020a4a4c(lock);

    return ret;
}

void * Heap::_01ffba40(u32 size, u32 alignment)
{
    struct Block * it = this->head;
    struct Block * freeBlock = NULL;
    void * ret = NULL;
    s32 lock;

    size = (((u32)(size) + (alignment)-1) & -(alignment));
    lock = func_020a4a38();

    for (; it != NULL; it = it->next)
    {
        if (it->free == TRUE && it->size >= (size + ALIGN_PADDING_AFTER(it, alignment)))
        {
            freeBlock = it;
            break;
        }
    }

    if (freeBlock != NULL)
    {
        ret = this->AllocateAlignedFromFront(freeBlock, size, alignment);
    }

    func_020a4a4c(lock);

    return ret;
}

void * Heap::_01ffbaec(u32 size, u32 alignment)
{
    struct Block * it = this->head;
    struct Block * freeBlock = NULL;
    void * ret = NULL;
    s32 lock;

    size = (((u32)(size) + (alignment)-1) & -(alignment));
    lock = func_020a4a38();

    for (; it != NULL; it = it->next)
    {
        if (it->free == TRUE)
        {
            u32 tmp = it->size;
            u32 ref_size =
                (size +
                 (((u32)it + (tmp + sizeof(struct Block))) -
                  (((u32)it + (tmp + sizeof(struct Block))) & (-alignment))));

            if (tmp >= ref_size)
            {
                freeBlock = it;
            }
        }
    }

    if (freeBlock != NULL)
    {
        ret = this->AllocateAlignedFromBack(freeBlock, size, alignment);
    }

    func_020a4a4c(lock);

    return ret;
}

void Heap::Free(void * addr)
{
    struct Block * it = this->head;

    s32 lock = func_020a4a38();

    while (it != NULL)
    {
        if (it->free == FALSE)
        {
            void * ptr = (void *)((u8 *)it + sizeof(struct Block) + it->offset);

            if (ptr == addr)
            {
                this->FreeAndCoalesce(it);
                break;
            }
        }

        it = it->next;
    }

    func_020a4a4c(lock);

    return;
}
