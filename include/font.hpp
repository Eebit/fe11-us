#ifndef FONT_HPP
#define FONT_HPP

#include "global.h"
#include "proc.h"

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

extern char * data_020d39e0;
extern struct ProcCmd ProcScr_020d39e4[];
// extern ??? data_020d39fc
extern char data_020d3a1c[][2];
// extern ??? data_020d3ae0
// extern ??? data_020d3ae8
// extern ??? data_020d3af4
// extern ??? data_020d3af8
extern char data_020d3afc[];
extern char data_020d3b00[];
extern char data_020d3b04[];
extern char data_020d3b08[];
// extern ??? data_021970bc
// extern ??? data_021970c0
extern struct Font * data_021970c4;
extern u16 ** data_021970cc;

EC void func_02028c68(void);
// EC ??? func_02028d00
// EC ??? func_02028d1c
EC void func_02028d30(struct Font * out, s32 index);
// EC ??? func_02028d60
// EC ??? func_02028df8
// EC ??? func_02028e14
// EC ??? func_02028e24
// EC ??? func_02028e44
// EC ??? func_02028e58
// EC ??? func_02028e60
// EC ??? func_02028e7c
// EC ??? func_02028f48
// EC ??? func_02029034
// EC ??? func_020290f4
// EC ??? func_0202915c
// EC ??? func_02029254
// EC ??? func_02029418
// EC ??? func_02029480
// EC ??? func_0202957c
EC s32 func_020295ec(struct Font *, char *, void *, void *, u32, u32, u32, u32, u32, u32);
EC s32 func_0202972c(struct Font *, char *, void *, u16 *, u32, u32, u32, u32, u32, u8, u8);
EC s32 func_02029850(struct Font *, s32, void *, u16 *, u32, u32, u32, u32, u32);
EC void func_02029a1c(struct Font *, u32, void *, void *, u32, u32, u32, u32);
// EC ??? func_02029ae8
// EC ??? func_02029ee0
// EC ??? func_0202a1e0
// EC ??? func_0202a208
// EC ??? func_0202a30c
// EC ??? func_0202a470
EC void func_0202a4dc(s32, s32);
// EC ??? func_0202a504
// EC ??? func_0202a53c
EC ProcPtr func_0202a564(s32);
EC void func_0202a5a8(ProcPtr);
// EC ??? func_0202a5cc

#endif // FONT_HPP
