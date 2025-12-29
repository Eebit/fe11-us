#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include "heap.hpp"
#include "save.hpp"
#include "types.h"

class FlagManager
{
public:
    /* 00 (vtable) */
    /* 04 */ char ** unk_04;
    /* 08 */ u8 * unk_08;
    /* 0C */ u32 unk_0c;

    /* 00 */ virtual void ClearById(u32);
    /* 04 */ virtual void ClearByName(char *);
    /* 08 */ virtual ~FlagManager()
    {
        if (this->unk_04 != NULL)
        {
            gHeap.Free(this->unk_04);
        }
        else
        {
            gHeap.Free(this->unk_08);
        }
    };

    void func_020492a0(void);
    s32 FindIdByName(char *);
    BOOL GetById(u32);
    BOOL GetByName(char *);
    void SetById(u32);
    void SetByName(char *);
    BOOL func_02049438(void);
    void func_0204947c(void);
    void RegisterName(char *, BOOL);
    void RemoveById(u32);
    void RemoveAll(void);
    void SaveFlags(struct SaveBuffer *);
    void LoadFlags(struct SaveBuffer *);
    void LoadFlags(struct SaveBuffer *, s32);
};

class ValueManager : public FlagManager
{
public:
    /* 00 */ virtual void ClearById(u32);
    /* 04 */ virtual void ClearByName(char *);
    /* 08 */ virtual ~ValueManager() {};

    s32 GetById(s32);
    s32 GetByName(char *);
    void SetById(s32, s32);
    void SetByName(char *, s32);
    void SaveValues(struct SaveBuffer *);
    void LoadValues(struct SaveBuffer *);
    void LoadValues(struct SaveBuffer *, s32);
};

#endif // STATE_MANAGER_HPP
