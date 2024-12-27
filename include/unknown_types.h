#ifndef UNKNOWN_TYPES_H
#define UNKNOWN_TYPES_H

#include "types.h"

struct Unknown_func_01ffb934_ret
{
    STRUCT_PAD(0x00, 0x6C);
    /* 6C */ u32 unk_6c;
};

// FE11 Database, in RAM
struct Unknown_02197254
{
    void * unk_00;
    void * unk_04;
    /* 08 */ struct PersonData * pPerson;
    /* 0C */ struct JobData * pJob;
    /* 10 */ struct ItemData * pItem;
    STRUCT_PAD(0x14, 0x2C);
    /* 2C */ u8 * pWeaponLevel;
};

#endif // UNKNOWN_TYPES_H
