#ifndef HEAP_HPP
#define HEAP_HPP

#include "global.h"

#define ALIGN_UP(n, a) (((u32)(n) + ((a) - 1)) & ~((a) - 1))
#define ALIGN_UP_POW2(n, a) (((u32)(n) + (a) - 1) & -(a))
#define ALIGN_PADDING_AFTER(poin, a) (ALIGN_UP_POW2((u32)(poin) + sizeof(*(poin)), a) - ((u32)(poin) + sizeof(*(poin))))

struct Block
{
    /* 00 */ struct Block * prev;
    /* 04 */ struct Block * next;
    /* 08 */ u32 size;
    /* 0C */ u16 offset;
    /* 0E */ u8 free;
    /* 0F */ u8 remainder;
};

class Heap
{
public:
    /* 00 */ struct Block * head;

    // Non-ITCM
    static void Init(void);

    void Init(struct Block * block, s32 size);
    s32 SizeOf(void *);
    u32 GetLargestFreeSize(void);

    // ITCM
    void * AllocateAlignedFromFront(struct Block * block, u32 size, u32 alignment);
    void * AllocateAlignedFromBack(struct Block *, u32 size, u32 alignment);
    void FreeAndCoalesce(struct Block * block);
    void * Alloc(u32 size);
    void * _01ffb9bc(u32 size);
    void * _01ffba40(u32 size, u32 alignment);
    void * _01ffbaec(u32 size, u32 alignment);
    void Free(void * addr);
};

extern struct Heap gHeap;

#endif // HEAP_HPP