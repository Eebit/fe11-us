#ifndef FONT_HPP
#define FONT_HPP

#include "global.h"

struct Glyph
{
    /* 00 */ u8 sjisByte1;
    /* 01 */ u8 width;
    STRUCT_PAD(0x02, 0x04);
    /* 04 */ u8 bitmap[32];
};

struct Font
{
    /* 00 */ Glyph ** glyphs;
    /* 04 */ s32 spacing;
    /* 08 */ u16 * colorTable;

    Font(s32 index);
};

extern struct Font * data_021970c4;
extern u16 ** data_021970cc;

#endif // FONT_HPP
