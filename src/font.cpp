#include "global.h"

#include "hardware.hpp"

#include "unknown_data.h"
#include "unknown_funcs.h"

struct UnkStruct_Func_02028d60_Ret
{
    /* 00 */ u8 unk_00;
    /* 01 */ u8 unk_01;
    STRUCT_PAD(0x02, 0x04);
    /* 04 */ u8 unk_04[32];
};

struct UnkStruct_021970c4
{
    UnkStruct_021970c4(s32 index);

    /* 00 */ struct UnkStruct_Func_02028d60_Ret ** unk_00;
    /* 04 */ s32 unk_04;
    /* 08 */ u16 * unk_08;
};

struct UnkStruct_021970bc
{
    /* 00 */ struct UnkStruct_Func_02028d60_Ret ** unk_00;
    STRUCT_PAD(0x04, 0x08);
    /* 08 */ struct UnkStruct_021970c4 * unk_08;
    /* 0C */ u16 * unk_0c;
    /* 10 */ u16 ** unk_10;
};

extern struct UnkStruct_021970bc data_021970bc;
extern const s32 data_021970c0[];

EC void func_02028d30(struct UnkStruct_021970c4 * out, s32 index);

inline UnkStruct_021970c4::UnkStruct_021970c4(s32 index)
{
    func_02028d30(this, index);
}

static inline void DrawFontSprite(s32 x, s32 y, u32 attr, s32 tile, u32 pal, u32 prio)
{
    func_01ffc404(
        x & 0x1ff, y & 0xff,
        attr | ((pal & 0xf) << 12) | ((tile >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14) & 0x3ff), Sprite_32x16,
        prio & 0xff);
}

EC void func_02028c68(void)
{
    func_020a8f40("/fonts");
    data_021970bc.unk_00 = static_cast<struct UnkStruct_Func_02028d60_Ret **>(LoadFileAndCache("sys_wars", 1));
    data_021970bc.unk_10 = static_cast<u16 **>(LoadFileAndCache("bit", 1));
    data_021970bc.unk_0c = static_cast<u16 *>(LoadUncompressedFile("pal", 0));

    if (data_021970bc.unk_08 == NULL)
    {
        data_021970bc.unk_08 = new UnkStruct_021970c4(0);
    }
    else
    {
        func_02028d30(data_021970bc.unk_08, 0);
    }
    return;
}

EC BOOL func_02028d00(char chr)
{
    if (chr & 0x80)
    {
        return TRUE;
    }

    return chr == 26;
}

EC char * func_02028d1c(s32 chr)
{
    return data_020d3a1c[chr - ' '];
}

EC void func_02028d30(struct UnkStruct_021970c4 * out, s32 index)
{
    out->unk_00 = data_021970bc.unk_00;
    out->unk_04 = data_021970c0[index];
    out->unk_08 = data_021970bc.unk_10[1];
    return;
}

EC struct UnkStruct_Func_02028d60_Ret * func_02028d60(struct UnkStruct_021970c4 * self, char * str)
{
    struct UnkStruct_Func_02028d60_Ret * node;
    u8 hi;
    u8 lo;

    if (func_02028d00(*str))
    {
        hi = str[0];
        lo = str[1];
    }
    else
    {
        if (*str < ' ')
        {
            return NULL;
        }
        lo = *str;
        hi = 0;
    }

    do
    {
        node = self->unk_00[lo - ' '];
        while (node != NULL && node->unk_01 != 0)
        {
            if (node->unk_00 == hi)
            {
                break;
            }
            node++;
        }
        if (node == NULL || node->unk_01 == 0)
        {
            node = NULL;
            hi = 0;
            lo = '?';
        }
    } while (node == NULL);

    return node;
}

EC s32 func_02028df8(struct UnkStruct_021970c4 * unused, char * str)
{
    if (func_02028d00(*str))
    {
        return 2;
    }

    return 1;
}

EC u8 func_02028e14(struct UnkStruct_021970c4 * self, char * str)
{
    return func_02028d60(self, str)->unk_01;
}

EC BOOL func_02028e24(char chr)
{
    u8 c;

    c = chr;
    if (c == 26)
    {
        return FALSE;
    }

    return c < (u8)' ';
}

EC s32 func_02028e44(struct UnkStruct_021970c4 * unused, char * str)
{
    if (*str == 31)
    {
        return 2;
    }

    return 1;
}

EC s32 func_02028e58(struct UnkStruct_021970c4 * unused1, char * unused2)
{
    return 0;
}

EC BOOL func_02028e60(struct UnkStruct_021970c4 * unused, char * str)
{
    switch (*str)
    {
        case '\n':
            return TRUE;
        default:
            return FALSE;
    }
}

EC s32 func_02028e7c(struct UnkStruct_021970c4 * self, char * str, s32 tabbed)
{
    s32 width;
    s32 maxWidth;

    width = 0;
    maxWidth = 0;
    while (*str != 0)
    {
        if (func_02028e24(*str))
        {
            width += func_02028e58(self, str);
            if (func_02028e60(self, str))
            {
                if (tabbed)
                {
                    width = (width + 7) & ~7;
                }
                else
                {
                    if (width <= maxWidth)
                    {
                        width = maxWidth;
                    }
                    maxWidth = width;
                    width = 0;
                }
            }
            str += func_02028e44(self, str);
        }
        else
        {
            width += func_02028e14(self, str);
            width += self->unk_04;
            str += func_02028df8(self, str);
        }
    }

    if (width <= maxWidth)
    {
        width = maxWidth;
    }
    return width - self->unk_04;
}

EC s32 func_02028f48(struct UnkStruct_021970c4 * self, char * str, s32 lines)
{
    s32 width;

    width = 0;
    while (lines != 0 && *str != 0)
    {
        if (func_02028e24(*str))
        {
            if (func_02028e60(self, str))
            {
                lines--;
            }

            str += func_02028e44(self, str);
        }
        else
        {
            str += func_02028df8(self, str);
        }
    }

    while (*str != 0)
    {
        if (func_02028e24(*str))
        {
            width += func_02028e58(self, str);
            if (func_02028e60(self, str))
            {
                break;
            }

            str += func_02028e44(self, str);
        }
        else
        {
            width += func_02028e14(self, str);
            width += self->unk_04;
            str += func_02028df8(self, str);
        }
    }

    return width - self->unk_04;
}

EC s32 func_02029034(struct UnkStruct_021970c4 * self, char * str, s32 lines)
{
    char * start;

    while (lines != 0 && *str != 0)
    {
        if (func_02028e24(*str))
        {
            if (func_02028e60(self, str))
            {
                lines--;
            }

            str += func_02028e44(self, str);
        }
        else
        {
            str += func_02028df8(self, str);
        }
    }

    start = str;
    while (*str != 0)
    {
        if (func_02028e24(*str))
        {
            if (func_02028e60(self, str))
            {
                break;
            }

            str += func_02028e44(self, str);
        }
        else
        {
            str += func_02028df8(self, str);
        }
    }

    return str - start;
}

EC s32 func_020290f4(struct UnkStruct_021970c4 * self, char * str)
{
    s32 count;

    count = 1;
    while (*str != 0)
    {
        if (func_02028e24(*str))
        {
            if (func_02028e60(self, str))
            {
                count++;
            }

            str += func_02028e44(self, str);
        }
        else
        {
            str += func_02028df8(self, str);
        }
    }

    return count;
}

EC void func_0202915c(struct UnkStruct_021970c4 * self, char * str, u32 * out, s32 shift, s32 mode)
{
    struct UnkStruct_Func_02028d60_Ret * glyph;
    u8 * data;
    u32 mask;
    s32 rows;
    s32 lead;
    s32 bits;
    s32 i;
    u32 lo;
    u32 hi;
    u64 value;

    glyph = func_02028d60(self, str);

    if (mode == 0)
    {
        mask = (1 << (shift * 4)) - 1;
    }
    else if (mode > 0)
    {
        lead = self->unk_04;
        if (lead >= 0)
        {
            lead = 0;
        }
        mask = (1 << ((shift - lead) * 4)) - 1;
    }
    else
    {
        mask = 0;
    }

    rows = glyph->unk_01 + shift;
    data = glyph->unk_04;
    bits = shift * 4;

    for (i = 0; i < 16; i++)
    {
        lo = self->unk_08[data[0]];
        hi = self->unk_08[data[1]];
        value = lo | ((u64)hi << 16);
        data += 2;

        out[0] = (out[0] & mask) | (u32)(value << bits);
        if (((rows - 1) & 0xF8) != 0)
        {
            out[16] = (u32)(value >> (32 - bits));
        }
        out++;
    }

    return;
}

EC void
func_02029254(struct UnkStruct_021970c4 * self, char * str, u32 * out, s32 shift, s32 mode, s32 col, s32 blockWidth)
{
    struct UnkStruct_Func_02028d60_Ret * glyph;
    u8 * data;
    u32 mask;
    s32 rows;
    s32 lead;
    s32 stride;
    s32 bits;
    s32 i;
    u32 lo;
    u32 hi;
    u64 value;

    glyph = func_02028d60(self, str);

    if (mode == 0)
    {
        mask = (1 << (shift * 4)) - 1;
    }
    else if (mode > 0)
    {
        lead = self->unk_04;
        if (lead >= 0)
        {
            lead = 0;
        }
        mask = (1 << ((shift - lead) * 4)) - 1;
    }
    else
    {
        mask = 0;
    }

    rows = glyph->unk_01 + shift;
    data = glyph->unk_04;
    bits = shift * 4;
    if (col + 1 < blockWidth)
    {
        stride = 8;
    }
    else
    {
        stride = ((blockWidth << 5) >> 2) + 8;
    }

    for (i = 0; i < 8; i++)
    {
        lo = self->unk_08[*data++];
        hi = self->unk_08[*data++];
        value = lo | ((u64)hi << 16);

        out[0] = (mask & out[0]) | (u32)(value << bits);
        if (((rows - 1) & 0xF8) != 0)
        {
            out[stride] = (u32)(value >> (32 - bits));
        }
        out++;
    }

    out = out - i + ((blockWidth << 5) >> 2);

    for (; i < 16; i++)
    {
        lo = self->unk_08[*data++];
        hi = self->unk_08[*data++];
        value = lo | ((u64)hi << 16);

        out[0] = (mask & out[0]) | (u32)(value << bits);
        if (((rows - 1) & 0xF8) != 0)
        {
            out[stride] = (u32)(value >> (32 - bits));
        }
        out++;
    }

    return;
}

EC void func_02029418(struct UnkStruct_021970c4 * self, s32 chr, u32 * out)
{
    struct UnkStruct_Func_02028d60_Ret * glyph;
    u8 * data;
    s32 i;

    glyph = func_02028d60(self, func_02028d1c((char)(chr + '0')));
    data = glyph->unk_04;

    for (i = 0; i < 16; i++)
    {
        u32 lo = self->unk_08[data[0]];
        u32 hi = self->unk_08[data[1]];
        data += 2;
        *out++ = lo | (hi << 16);
    }

    return;
}

EC void func_02029480(struct UnkStruct_021970c4 * self, char * str, u32 * out, s32 x, s32 flag)
{
    if (*str == 0)
    {
        return;
    }

    do
    {
        if (func_02028e24(*str))
        {
            x += func_02028e58(self, str);
            if (func_02028e60(self, str))
            {
                flag = 0;
                x = (x + 7) & ~7;
            }
            else if (*str == 31)
            {
                self->unk_08 = data_021970bc.unk_10[str[1]];
            }
            str += func_02028e44(self, str);
        }
        else
        {
            func_0202915c(self, str, out, x, flag);
            flag = 1;
            x += func_02028e14(self, str);
            x += self->unk_04;
            str += func_02028df8(self, str);
        }
        out += (x >> 3) * 16;
        x &= 7;
    } while (*str != 0);
    return;
}

EC void func_0202957c(u16 * dst, s32 x, s32 y, u32 tile, u32 pal, s32 count)
{
    s32 i;
    s32 row;
    s32 nextRow;
    u16 * top;
    u16 * bottom;

    for (i = 0; i < count; i++)
    {
        row = y * 0x20;
        nextRow = (y + 1) * 0x20;
        top = dst + x + row;
        bottom = dst + x + nextRow;
        top[i] = (tile & 0x3ff) | ((pal & 0xf) << 12);
        bottom[i] = ((tile + 1) & 0x3ff) | ((pal & 0xf) << 12);
        tile += 2;
    }

    return;
}

EC s32 func_020295ec(
    struct UnkStruct_021970c4 * self, char * str, void * out, void * dst, u32 x, u32 y, u32 tile, u32 pal, u32 offset,
    u32 flag)
{
    u32 tx;
    s32 col;
    s32 px;

    col = (s32)offset >> 3;
    px = offset & 7;
    tile += col * 2;
    func_02029480(self, str, static_cast<u32 *>(out) + tile * 8, px, flag);
    x += col;

    while (*str != 0)
    {
        if (func_02028e24(*str))
        {
            px += func_02028e58(self, str);
            if (func_02028e60(self, str))
            {
                tx = (px + 7) & ~7;
                func_0202957c(static_cast<u16 *>(dst), x, y, tile, pal, tx >> 3);
                px = 0;
                tile += tx >> 2;
                y += 2;
            }
            str += func_02028e44(self, str);
        }
        else
        {
            px += func_02028e14(self, str);
            px += self->unk_04;
            str += func_02028df8(self, str);
        }
    }

    tx = (px - self->unk_04 + 7) & ~7;
    func_0202957c(static_cast<u16 *>(dst), x, y, tile, pal, tx >> 3);
    return tx >> 2;
}

EC s32 func_0202972c(
    struct UnkStruct_021970c4 * self, char * str, void * out, u16 * dst, u32 x, u32 y, u32 tile, u32 pal, u32 width,
    u8 center, u8 clear)
{
    u32 * dstTiles;
    s32 textWidth;
    s32 total;
    s32 col;
    s32 offset;
    u32 end;

    dstTiles = static_cast<u32 *>(out);
    offset = width;
    textWidth = func_02028f48(self, str, 0);
    total = offset;
    offset -= textWidth;
    offset >>= 1;
    col = offset >> 3;
    x += col;

    if (center != 0 && col != 0)
    {
        if (clear != 0)
        {
            func_020a5734(0, dstTiles + tile * 8, col * 64);
        }
        tile += col * 2;
    }
    offset &= 7;

    func_02029480(self, str, dstTiles + tile * 8, offset, -1);
    end = (textWidth + offset + 7) & ~7;
    func_0202957c(dst, x, y, tile, pal, end >> 3);

    if (center != 0)
    {
        if (clear != 0)
        {
            func_020a5734(0, dstTiles + (tile + (end >> 2)) * 8, ((((total + 7) & ~7) - end) >> 3) * 64);
        }
        return (u32)((total + 7) & ~7) >> 2;
    }

    return end >> 2;
}

EC s32 func_02029850(
    struct UnkStruct_021970c4 * self, s32 num, void * out, u16 * dst, u32 x, u32 y, u32 tile, u32 pal, u32 count)
{
    BOOL neg;
    s32 offset;
    s32 digit;
    s32 top;
    s32 bottom;
    s32 attr;
    u32 n;

    n = 0;
    neg = FALSE;
    if (num < 0)
    {
        neg = TRUE;
        num = -num;
    }

    top = y * 0x20;
    attr = (pal & 0xF) << 12;
    bottom = (y + 1) * 0x20;

    do
    {
        digit = IntSys_Mod(num, 10);
        num = IntSys_Div(num, 10);
        offset = tile * 32;
        func_02029418(self, digit, (u32 *)(static_cast<u8 *>(out) + offset));
        dst[top + x] = (tile & 0x3FF) | attr;
        dst[bottom + x] = ((tile + 1) & 0x3FF) | attr;
        x--;
        count -= 1;
        tile += 2;
        ++n;
    } while (num);

    while ((s32)count > 0)
    {
        offset = tile * 32;
        func_02029418(self, 0, (u32 *)(static_cast<u8 *>(out) + offset));
        dst[top + x] = (tile & 0x3FF) | attr;
        dst[bottom + x] = ((tile + 1) & 0x3FF) | attr;
        x--;
        count -= 1;
        tile += 2;
        n++;
    }

    if (neg)
    {
        func_020295ec(self, data_020d3afc, out, dst, x, y, tile, pal, 0, 0);
        ++n;
    }

    return n * 2;
}

EC void
func_02029a1c(struct UnkStruct_021970c4 * self, u32 value, void * out, void * dst, u32 x, u32 y, u32 tile, u32 pal)
{
    if (value == 10)
    {
        func_020295ec(self, data_020d3b00, out, dst, x, y, tile, pal, 0, 0);
        return;
    }

    if (value == 11)
    {
        func_020295ec(self, data_020d3b04, out, dst, x, y, tile, pal, 0, 0);
        return;
    }

    func_02029850(self, value, out, static_cast<u16 *>(dst), x, y, tile, pal, 0);
    return;
}

EC s32 func_02029ae8(struct UnkStruct_021970c4 * self, char * str, u8 * dst, s32 y, s32 x, s32 width, s32 centered)
{
    s32 flag;
    s32 tiles;
    s32 col;
    s32 lines;
    u32 ux;
    u32 q;
    s32 n;
    s32 rem;
    s32 size;
    s32 alignedWidth;

    flag = 0;
    tiles = 0;
    col = 0;
    lines = 1;

    if (centered != 0)
    {
        x += ((width * 8 - x) - func_02028f48(self, str, 0)) >> 1;
    }
    if (x != 0)
    {
        n = x >> 3;
        q = IntSys_Div(n, 4);
        func_020a5734(0, dst + y * 32, (n + q * 8 - q * 4) * 32);
        func_020a5734(0, dst + y * 32 + (q * 8 + 4) * 32, n * 32 - q * 4);
        dst += ((n & ~3) + (x >> 3)) * 32;
        col = (x >> 3) - (n & ~3);
        tiles += x >> 3;
        x &= 7;
        flag = -1;
    }
    alignedWidth = (width + 3) & ~3;
    dst += y * 32;

    while (*str != 0)
    {
        if (func_02028e24(*str))
        {
            x += func_02028e58(self, str);
            if (func_02028e60(self, str))
            {
                n = ((u32)(x - self->unk_04 + 7) & ~7) >> 3;
                size = col + n;
                col = n;
                dst += col * 32;
                if (size != 0)
                {
                    size = (4 - size) * 32;
                    func_020a5734(0, dst, size);
                    func_020a5734(0, dst + 128, size);
                    dst += size + 128;
                }
                tiles = (tiles + col + 3) & ~3;
                col = 0;
                flag = 0;
                x = 0;
                lines++;
                if (alignedWidth != 0)
                {
                    rem = IntSys_Mod(tiles, alignedWidth);
                    if (rem != 0)
                    {
                        func_020a5734(0, dst, (alignedWidth - rem) * 64);
                        dst += (alignedWidth - rem) * 64;
                        tiles += alignedWidth - rem;
                    }
                    if (centered != 0)
                    {
                        x += (width * 8 - func_02028f48(self, str + func_02028e44(self, str), 0)) >> 1;
                    }
                    if (x != 0)
                    {
                        n = x >> 3;
                        q = IntSys_Div(n, 4);
                        func_020a5734(0, dst, (n + q * 8 - q * 4) * 32);
                        func_020a5734(0, dst + (q * 8 + 4) * 32, n * 32 - q * 4);
                        dst += ((n & ~3) + (x >> 3)) * 32;
                        col = (x >> 3) - (n & ~3);
                        tiles += x >> 3;
                        x &= 7;
                        flag = -1;
                    }
                }
            }
            str += func_02028e44(self, str);
        }
        else
        {
            func_02029254(self, str, (u32 *)dst, x, flag, col, 4);
            flag = 1;
            x += func_02028e14(self, str);
            x += self->unk_04;
            str += func_02028df8(self, str);
        }

        dst += (x >> 3) * 32;
        tiles += x >> 3;
        col += x >> 3;
        x &= 7;
        if (col >= 4)
        {
            dst += (4 - col) * 32 + 128;
            col -= 4;
            dst += col * 32;
        }
    }

    ux = (x - self->unk_04 + 7) & ~7;
    dst += (ux >> 3) * 32;
    tiles += ux >> 3;
    col += ux >> 3;
    if (col != 0)
    {
        size = (4 - col) * 32;
        func_020a5734(0, dst, size);
        func_020a5734(0, dst + 128, size);
    }
    if (alignedWidth != 0)
    {
        if (col != 0)
        {
            dst += (4 - col) * 32 + 128;
        }
        rem = IntSys_Mod(tiles, alignedWidth);
        if (rem != 0)
        {
            func_020a5734(0, dst, (alignedWidth - rem) * 64);
            tiles += alignedWidth - rem;
        }
    }
    return (alignedWidth != 0 ? alignedWidth * lines : (tiles + 3) & ~3) * 2;
}

EC void func_02029ee0(
    struct UnkStruct_021970c4 * self, char * str, s32 x, s32 y, u32 attr, s32 tile, u32 pal, u32 prio, s32 width)
{
    s32 baseX;
    s32 lines;
    s32 line;
    s32 col;
    s32 px;
    s32 flag;
    s32 i;

    baseX = x;
    col = 0;
    px = 0;
    flag = 0;

    if (width != 0)
    {
        lines = func_020290f4(data_021970bc.unk_08, str);
        width = (width + 3) & ~3;
        for (line = 0; line < lines; line++)
        {
            for (i = 0; i < (width * 8) >> 5; i++)
            {
                prio = (s32)prio;
                DrawFontSprite(x, y, attr, tile, pal, prio);
                x += 32;
                tile += 8;
            }
            x = baseX;
            y += 16;
        }

        return;
    }

    DrawFontSprite(x, y, attr, tile, pal, prio);

    while (*str != 0)
    {
        if (func_02028e24(*str))
        {
            px += func_02028e58(self, str);
            if (func_02028e60(self, str))
            {
                col = 0;
                y += 16;
                x = baseX;
                tile += 8;
                flag = 1;
                px = 0;
            }
            str += func_02028e44(self, str);
        }
        else
        {
            px += func_02028e14(self, str);
            px += self->unk_04;
            str += func_02028df8(self, str);
        }

        col += px >> 3;
        px &= 7;
        if (col >= 4)
        {
            col -= 4;
            x += 32;
            tile += 8;
            if (*str != 0 || col != 0 || px != 0)
            {
                flag = 1;
            }
        }

        if (flag != 0)
        {
            prio = (s32)prio;
            DrawFontSprite(x, y, attr, tile, pal, prio);
            flag = 0;
        }
    }

    return;
}

EC void func_0202a1e0(struct UnkStruct_021970c4 * self, u32 * out, s32 index)
{
    func_02029480(self, data_020d39e0, out + index * 8, 0, 0);
    return;
}

EC void func_0202a208(struct UnkStruct_021970c4 * self, char * str, u16 * dst, s32 x, s32 y, u32 tile, u32 pal)
{
    char * table;
    char * glyph;
    s32 row;
    s32 nextRow;
    u16 * top;
    u16 * bottom;

    table = data_020d39e0;
    if (func_02028d00(*str))
    {
        glyph = str;
        str += 2;
    }
    else
    {
        glyph = func_02028d1c(*str++);
    }

    while (*table != 0)
    {
        if (*table == glyph[0] && table[1] == glyph[1])
        {
            break;
        }
        table += 2;
    }

    row = y * 0x20;
    nextRow = (y + 1) * 0x20;
    top = dst + x + row;
    bottom = dst + x + nextRow;
    top[0] = ((table + tile - data_020d39e0) & 0x3ff) | ((pal & 0xf) << 12);
    bottom[0] = ((table + tile - data_020d39e0 + 1) & 0x3ff) | ((pal & 0xf) << 12);

    if (*str != 0)
    {
        func_0202a208(self, str, dst, x + 1, y, tile, pal);
    }
    return;
}

EC void
func_0202a30c(struct UnkStruct_021970c4 * self, s32 value, u16 * dst, s32 x, s32 y, u32 tile, u32 pal, s32 count)
{
    BOOL isNegative = FALSE;
    s32 row0;
    s32 row1;
    s32 digit;
    u32 attr;

    if (value < 0)
    {
        isNegative = TRUE;
        value = -value;
    }

    row0 = y * 0x20;
    attr = (pal & 0xF) << 12;
    row1 = (y + 1) * 0x20;

    do
    {
        digit = IntSys_Mod(value, 10);
        value = IntSys_Div(value, 10);
        dst[row0 + x] = ((tile + digit * 2) & 0x3FF) | attr;
        dst[row1 + x] = ((tile + digit * 2 + 1) & 0x3FF) | attr;
        x--;
        count--;
    } while (value != 0);

    while (count > 0)
    {
        dst[row0 + x] = (tile & 0x3FF) | attr;
        dst[row1 + x] = ((tile + 1) & 0x3FF) | attr;
        count--;
        x--;
    }

    if (isNegative)
    {
        func_0202a208(self, data_020d3afc, dst, x, y, tile, pal);
    }
    return;
}

EC void func_0202a470(struct UnkStruct_021970c4 * self, s32 chr, u16 * dst, s32 x, s32 y, u32 tile, u32 pal)
{
    if (chr == 100)
    {
        func_0202a208(self, data_020d3b08, dst, x - 1, y, tile, pal);
        return;
    }

    func_0202a30c(self, chr, dst, x, y, tile, pal, 0);
    return;
}

EC void func_0202a4dc(s32 dst, s32 src)
{
    func_01ff9998(data_021970bc.unk_0c + src * 16, dst * 32, 32);
    return;
}

EC void func_0202a504(s32 dst, s32 row, s32 src)
{
    u16 * pal = data_021970bc.unk_0c;
    s32 idx = (row - 1) * 3 + 1;

    pal += src * 16;
    func_01ff9a34(pal + idx, dst * 32 + 2, 6);
    return;
}

EC void func_0202a53c(s32 dst, s32 src)
{
    func_01ff9a00(data_021970bc.unk_0c + src * 16, dst * 32, 32);
    return;
}
