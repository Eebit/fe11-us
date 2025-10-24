#ifndef SAVE_HPP
#define SAVE_HPP

#include "global.h"

struct SaveBuffer
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
        u16 a = ReadByte();
        a |= (ReadByte() << 8);
        return a;
    }

    inline u32 ReadWord()
    {
        u16 a = ReadShort();
        u16 b = ReadShort();

        return a | b << 16;
    }

    inline void WriteByte(u8 byte)
    {
        *this->unk_04 = byte;
        this->unk_04++;
    }

    inline void WriteShort(u16 halfword)
    {
        WriteByte(halfword);
        WriteByte(halfword >> 8);
    }

    inline void WriteWord(u32 word)
    {
        WriteShort(word);
        WriteShort(word >> 16);
    }
};

#endif // SAVE_HPP