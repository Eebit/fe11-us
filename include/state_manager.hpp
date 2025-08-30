#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include "types.h"

struct UnkBuf_Func_02049564
{
    u32 unk_00;
    u8 * unk_04;

    inline u8 ReadByte()
    {
        u8 tmp = *unk_04;
        unk_04++;
        return tmp;
    }

    inline u16 ReadShort()
    {
        u8 a = ReadByte();
        u8 b = ReadByte();
        return a | b << 8;
    }

    inline u32 ReadWord()
    {
        u16 a = ReadShort();
        u16 b = ReadShort();

        return a | b << 16;
    }

    void inline WriteByte(u8 byte)
    {
        *this->unk_04 = byte;
        this->unk_04++;
    }

    void inline WriteShort(u16 halfword)
    {
        WriteByte(halfword);
        WriteByte(halfword >> 8);
    }

    void inline WriteWord(u32 word)
    {
        WriteShort(word);
        WriteShort(word >> 16);
    }
};

class FlagManager
{
public:
    /* 00 (vtable) */
    /* 04 */ char ** unk_04;
    /* 08 */ u8 * unk_08;
    /* 0C */ u32 unk_0c;

    /* 00 */ virtual void ClearById(u32);
    /* 04 */ virtual void ClearByName(char *);
    /* 08 */ virtual ~FlagManager();

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
    void func_02049564(struct UnkBuf_Func_02049564 *);
    void func_0204961c(struct UnkBuf_Func_02049564 *);
    void func_02049824(struct UnkBuf_Func_02049564 *, s32);
};

class ValueManager : public FlagManager
{
public:
    /* 00 */ virtual void ClearById(u32);
    /* 04 */ virtual void ClearByName(char *);
    /* 08 */ virtual ~ValueManager();

    s32 GetById(s32);
    s32 GetByName(char *);
    void SetById(s32, s32);
    void SetByName(char *, s32);
    void func_02049a9c(struct UnkBuf_Func_02049564 *);
    void func_02049b90(struct UnkBuf_Func_02049564 *);
    void func_02049dc8(struct UnkBuf_Func_02049564 *, s32);
};

#endif // STATE_MANAGER_HPP
