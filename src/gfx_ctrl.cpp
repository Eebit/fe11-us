#include "global.h"

#include "hardware.hpp"
#include "unknown_funcs.h"

extern AbstCtrl * data_021976f8[10];

struct UnkStruct_02197798
{
    ScreenState * unk_00;
    DispIo * unk_04;
    BGCtrl unk_08[4];
    ObjCtrl unk_68;
};

struct UnkStruct_027e12f4
{
    /* 000 */ STRUCT_PAD(0x000, 0x200);
    /* 200 */ u16 unk_200[0x100];
};

struct UnkStruct_Func_0209dba4_Ret
{
    /* 00 */ s32 unk_00;
    /* 04 */ s32 unk_04;
    /* 08 */ s32 unk_08;
    /* 0C */ s32 unk_0c;
};

UnkStruct_02197798 gfxEngineA;
UnkStruct_02197798 gfxEngineB;

extern const s16 data_020c53b0[];

static inline s16 sin(u16 angle)
{
    return data_020c53b0[(angle >> 4) * 2];
}

static inline s16 cos(u16 angle)
{
    return data_020c53b0[(angle >> 4) * 2 + 1];
}

static inline void InitGfxEngine(UnkStruct_02197798 * engine, ScreenState * screenSt)
{
    s32 i;

    engine->unk_00 = screenSt;
    engine->unk_04 = engine->unk_00->dispIo;

    for (i = 0; i < 4; i++)
    {
        engine->unk_08[i].unk_04 = engine->unk_00;
        engine->unk_08[i].unk_08 = IsAddressInVramRange(engine->unk_08[i].unk_04->objVram);
        engine->unk_08[i].unk_10 = i;
        engine->unk_08[i].unk_0c = &engine->unk_08[i].unk_04->dispIo->bgcnt[i];
    }

    engine->unk_68.unk_04 = engine->unk_00;
    engine->unk_68.unk_08 = IsAddressInVramRange(engine->unk_68.unk_04->objVram);

    return;
}

EC UnkStruct_02197798 * func_0206eca4(void)
{
    return &gfxEngineA;
}

EC UnkStruct_02197798 * func_0206ecb0(void)
{
    return &gfxEngineB;
}

EC void func_0206ecbc(void)
{
    if (data_021976f8[6] != NULL)
    {
        return;
    }

    InitGfxEngine(func_0206eca4(), gpMainScreenSt);
    InitGfxEngine(func_0206ecb0(), gpSubScreenSt);

    data_021976f8[6] = &func_0206eca4()->unk_08[0];
    data_021976f8[5] = &func_0206eca4()->unk_08[1];
    data_021976f8[7] = &func_0206eca4()->unk_08[2];
    data_021976f8[4] = &func_0206eca4()->unk_08[3];
    data_021976f8[1] = &func_0206eca4()->unk_68;
    data_021976f8[2] = &func_0206ecb0()->unk_08[0];
    data_021976f8[3] = &func_0206ecb0()->unk_08[1];
    data_021976f8[0] = &func_0206ecb0()->unk_08[2];
    data_021976f8[9] = &func_0206ecb0()->unk_08[3];
    data_021976f8[8] = &func_0206ecb0()->unk_68;

    return;
}

EC void func_0206ee78(struct AbstCtrl * self, void * src, s32 offset, s32 size)
{
    s32 dst;

    if (src != NULL)
    {
        dst = self->vfunc_00();
        dst += offset;
        func_020a5780(src, (void *)dst, size);
    }

    return;
}

EC void func_0206eeb0(struct AbstCtrl * self, u32 src, u32 offset)
{
    u8 * vram;

    if (src != 0)
    {
        vram = (u8 *)self->vfunc_00();
        Decompress((void const *)src, vram + offset);
    }

    return;
}

EC void func_0206eee0(struct AbstCtrl * self, s32 value, s32 offset, s32 size)
{
    s32 dst;

    dst = self->vfunc_00();
    dst += offset;
    func_020a5734(value, (void *)dst, size);

    return;
}

EC void func_0206ef14(struct AbstCtrl * self, u32 src, u32 srcOffset, u32 dstOffset, u32 size)
{
    if (src != 0)
    {
        func_020a5780((void *)(src + srcOffset), (void *)(dstOffset + self->vfunc_04()), size);
        self->unk_04->unk_3e |= 0x10;
    }

    return;
}

EC u32 func_0206ef60(struct AbstCtrl * self, s32 block)
{
    u32 offset;

    offset = (block << 14) + (self->unk_04->dispIo->dispcnt.unk_02_bit_4 << 16);

    return offset + (IsAddressInVramRange(self->unk_04->objVram) ? 0x6000000 : 0x6200000);
}

EC void func_0206ef9c(struct AbstCtrl * self, s32 screenSize, s32 colorMode, s32 screenBase, s32 charBase, s32 overflowMode)
{
    BGCtrl * bg = static_cast<BGCtrl *>(self);

    if ((u16)(s16)(bg->unk_10 - 2) <= 1)
    {
        func_0206f0fc(self, screenSize, colorMode, screenBase, charBase);
        return;
    }

    bg->unk_0c->screenSize = screenSize;
    bg->unk_0c->colorMode = colorMode;
    bg->unk_0c->screenBaseBlock = screenBase;
    bg->unk_0c->charBaseBlock = charBase;
    bg->unk_0c->areaOverflowMode = overflowMode;
    bg->unk_0c->mosaic = 0;

    bg->unk_04->bgTiles[bg->unk_10] = (void *)func_0206ef60(self, charBase);

    switch (screenSize)
    {
        case 0:
        case 2:
            bg->unk_16 = 0x100;
            break;

        case 1:
        case 3:
            bg->unk_16 = 0x200;
            break;
    }

    bg->unk_14 = bg->unk_16 / 8 - 1;
    bg->unk_16 -= 0x100;

    return;
}

EC void func_0206f0fc(struct AbstCtrl * self, s32 screenSize, s32 colorMode, s32 screenBase, s32 charBase)
{
    BGCtrl * bg = static_cast<BGCtrl *>(self);

    bg->unk_0c->screenSize = screenSize;
    bg->unk_0c->colorMode = colorMode;
    bg->unk_0c->screenBaseBlock = screenBase;
    bg->unk_0c->charBaseBlock = charBase;
    bg->unk_0c->areaOverflowMode = 0;
    bg->unk_0c->mosaic = 0;

    bg->unk_04->bgTiles[bg->unk_10] = (void *)func_0206ef60(self, charBase);

    switch (screenSize)
    {
        case 0:
        case 2:
            bg->unk_16 = 0x100;
            break;

        case 1:
        case 3:
            bg->unk_16 = 0x100;
            break;
    }

    bg->unk_14 = bg->unk_16 / 8 - 1;
    bg->unk_16 -= 0x100;

    return;
}

EC void func_0206f218(struct AbstCtrl * self, s32 screenSize, s32 unused, s32 screenBase, s32 charBase)
{
    BGCtrl * bg = static_cast<BGCtrl *>(self);

    bg->unk_0c->screenSize = screenSize;
    bg->unk_0c->colorMode = 0;
    bg->unk_0c->screenBaseBlock = screenBase;
    bg->unk_0c->charBaseBlock = charBase;
    bg->unk_0c->areaOverflowMode = 0;
    bg->unk_0c->mosaic = 0;

    bg->unk_04->bgTiles[bg->unk_10] = (void *)func_0206ef60(self, charBase);

    switch (screenSize)
    {
        case 0:
            bg->unk_16 = 0x80;
            break;

        case 1:
            bg->unk_16 = 0x100;
            break;

        case 2:
            bg->unk_16 = 0x200;
            break;

        case 3:
            bg->unk_16 = 0x400;
            break;
    }

    bg->unk_14 = bg->unk_16 / 8 - 1;
    bg->unk_16 -= 0x100;

    return;
}

EC void func_0206f33c(struct AbstCtrl * self, s32 screenSize, s32 overflowMode, s32 screenBase, s32 charBase)
{
    BGCtrl * bg = static_cast<BGCtrl *>(self);

    bg->unk_0c->screenSize = screenSize;
    bg->unk_0c->colorMode = 0;
    bg->unk_0c->screenBaseBlock = screenBase;
    bg->unk_0c->charBaseBlock = charBase;
    bg->unk_0c->areaOverflowMode = overflowMode;
    bg->unk_0c->mosaic = 0;

    bg->unk_04->bgTiles[bg->unk_10] = (void *)func_0206ef60(self, charBase);

    switch (screenSize)
    {
        case 0:
            bg->unk_16 = 0x80;
            break;

        case 1:
            bg->unk_16 = 0x100;
            break;

        case 2:
            bg->unk_16 = 0x200;
            break;

        case 3:
            bg->unk_16 = 0x400;
            break;
    }

    bg->unk_14 = bg->unk_16 / 8 - 1;
    bg->unk_16 -= 0x100;

    return;
}

EC void func_0206f470(struct BGCtrl * self, BOOL colorMode)
{
    self->unk_0c->colorMode = colorMode ? TRUE : FALSE;

    return;
}

EC void func_0206f4a0(struct BGCtrl * self, s32 block)
{
    self->unk_0c->charBaseBlock = block;
    self->unk_04->bgTiles[self->unk_10] = (void *)func_0206ef60(self, block);

    return;
}

EC void func_0206f4e0(struct BGCtrl * self, u8 enable)
{
    struct DispIo * dispIo;

    switch (self->unk_10)
    {
        case 0:
        {
            dispIo = self->unk_04->dispIo;
            dispIo->dispcnt.bg0_on = enable;
            break;
        }

        case 1:
        {
            dispIo = self->unk_04->dispIo;
            dispIo->dispcnt.bg1_on = enable;
            break;
        }

        case 2:
        {
            dispIo = self->unk_04->dispIo;
            dispIo->dispcnt.bg2_on = enable;
            break;
        }

        case 3:
        {
            dispIo = self->unk_04->dispIo;
            dispIo->dispcnt.bg3_on = enable;
            break;
        }
    }

    return;
}

EC void func_0206f580(struct AbstCtrl * self, s32 value)
{
    BGCtrl * bg = static_cast<BGCtrl *>(self);
    s32 size;
    u16 * dst;

    size = (bg->unk_14 + 1) << 6;
    dst = bg->vfunc_08();
    func_020a5734(value, dst, size);

    bg->unk_04->unk_3e |= 1 << bg->unk_10;

    return;
}

EC void func_0206f5d0(struct AbstCtrl * self, u16 * src, s32 x, s32 y, s32 width, s32 height, s32 tileOffset)
{
    BGCtrl * bg = static_cast<BGCtrl *>(self);
    u16 * map;
    s32 i;
    s32 j;
    s32 col;
    u8 flip;
    s32 tile;

    if (bg->unk_12 == 0 && tileOffset == 0 && width == 0x20 && x == 0)
    {
        func_020a5780(src + y * 0x20, bg->vfunc_08(), width * height * 2);
        bg->unk_04->unk_3e |= 1 << bg->unk_10;
        return;
    }

    map = bg->vfunc_08();
    flip = bg->unk_12;

    for (i = y; i < y + height; i++)
    {
        for (j = x; j < x + width; j++)
        {
            col = bg->unk_12 ? bg->unk_14 - j : j;
            tile = (*src++ + tileOffset) ^ (flip << 10);

            if (col & 0x20)
            {
                map[(i & 0x1F) * 0x20 + (col & 0x1F) + 0x400] = tile;
            }
            else
            {
                map[i * 0x20 + col] = tile;
            }
        }
    }

    bg->unk_04->unk_3e |= 1 << bg->unk_10;

    return;
}

EC void func_0206f718(struct AbstCtrl * self, u16 * src, s32 x, s32 y, s32 width, s32 height, s32 tileOffset)
{
    BGCtrl * bg = static_cast<BGCtrl *>(self);
    u16 * map;
    s32 i;
    s32 j;
    u8 flip;

    flip = bg->unk_12;
    map = bg->vfunc_08();

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            map[(i + y) * 0x20 + x + j] = (src[i * 0x20 + j] + tileOffset) ^ (flip << 10);
        }
    }

    bg->unk_04->unk_3e |= 1 << bg->unk_10;

    return;
}

EC void func_0206f7cc(struct BGCtrl * self, s32 x, s32 y, s32 width, s32 height, u16 tile)
{
    s32 i;
    s32 j;
    s32 col;
    u16 * map;
    u8 flip;

    flip = self->unk_12;
    map = self->vfunc_08();

    for (i = y; i < y + height; i++)
    {
        for (j = x; j < x + width; j++)
        {
            col = self->unk_12 ? self->unk_14 - j : j;

            if (col & 0x20)
            {
                map[(i & 0x1F) * 0x20 + (col & 0x1F) + 0x400] = tile ^ (flip << 10);
            }
            else
            {
                map[i * 0x20 + col] = tile ^ (flip << 10);
            }
        }
    }

    self->unk_04->unk_3e |= 1 << self->unk_10;

    return;
}

EC void func_0206f8a0(struct AbstCtrl * self, s32 x, s32 y, s32 width, s32 height, u16 tile)
{
    BGCtrl * bg = static_cast<BGCtrl *>(self);
    s32 i;
    s32 j;
    s32 col;
    u16 * map;
    u8 flip;

    flip = bg->unk_12;
    map = bg->vfunc_08();

    for (i = y; i < y + height; i++)
    {
        for (j = x; j < x + width; j++)
        {
            col = bg->unk_12 ? bg->unk_14 - j : j;

            if (col & 0x20)
            {
                map[(i & 0x1F) * 0x20 + (col & 0x1F) + 0x400] = tile++ ^ (flip << 10);
            }
            else
            {
                map[i * 0x20 + col] = tile++ ^ (flip << 10);
            }
        }
    }

    bg->unk_04->unk_3e |= 1 << bg->unk_10;

    return;
}

EC s32 func_0206f97c(struct BGCtrl * self)
{
    switch (self->unk_10)
    {
        case 0:
            return self->unk_0c->areaOverflowMode ? 0x4000 : 0;

        case 1:
            return self->unk_0c->areaOverflowMode ? 0x6000 : 0x2000;

        case 2:
            return 0x4000;

        case 3:
            return 0x6000;
    }

    return -1;
}

void BGCtrl::vfunc_0c(s32 src, s32 srcOffset, s32 dstOffset, s32 size)
{
    u32 length = size;

    func_020a3d8c(src, length);

    if (IsAddressInVramRange(this->unk_04->objVram))
    {
        func_020a1ca4();
        func_020a1d44(src + srcOffset, dstOffset + func_0206f97c(this), length);
        func_020a1db4();
    }
    else
    {
        func_020a1ef4();
        func_020a1f0c(src + srcOffset, dstOffset + func_0206f97c(this), length);
        func_020a1f70();
    }

    return;
}

void BGCtrl::vfunc_10(s32 src, s32 srcOffset, s32 dstOffset, s32 size, u8 param_5)
{
    ScreenState * activeSt;

    activeSt = gpActiveScreenSt;
    gpActiveScreenSt = IsAddressInVramRange(this->unk_04->objVram) ? gpMainScreenSt : gpSubScreenSt;

    func_020206ac(src + srcOffset, 0, dstOffset + func_0206f97c(this), size, param_5);

    gpActiveScreenSt = activeSt;

    return;
}

EC void func_0206fafc(struct AbstCtrl * self, s32 centerX, s32 centerY, s32 x, s32 y, s32 scaleX, s32 scaleY,
                      s32 angle)
{
    BGCtrl * bg = static_cast<BGCtrl *>(self);
    UnkStruct_Func_0209dba4_Ret scale;
    UnkStruct_Func_0209dba4_Ret rotation;
    BgAffineDstData * dst;
    s32 dx;
    s32 dy;

    func_0209dba4(&scale, scaleX, scaleY);
    func_0209dbb0(&rotation, sin(angle), cos(angle));
    func_0209dbbc(&scale, &rotation, &scale);

    switch (bg->unk_10 + bg->unk_08 * 4)
    {
        case 2:
        case 6:
            dst = &bg->unk_04->dispIo->bg2affin;
            break;

        case 3:
        case 7:
            dst = &bg->unk_04->dispIo->bg3affin;
            break;

        default:
            return;
    }

    dx = scale.unk_00 * (x - centerX) + scale.unk_04 * (y - centerY) + (centerX << 12);
    dy = scale.unk_08 * (x - centerX) + scale.unk_0c * (y - centerY) + (centerY << 12);

    dst->pa = scale.unk_00 >> 4;
    dst->pb = scale.unk_04 >> 4;
    dst->pc = scale.unk_08 >> 4;
    dst->pd = scale.unk_0c >> 4;
    dst->dx = dx >> 4;
    dst->dy = dy >> 4;

    return;
}

EC void func_0206fc44(struct AbstCtrl * self, s32 mode)
{
    struct DispIo * dispIo = self->unk_04->dispIo;

    switch (mode)
    {
        case 0:
            dispIo->dispcnt.bit_12 = 0;
            dispIo->dispcnt.bit_13_14 = 0;
            break;

        case 0x10:
            dispIo->dispcnt.bit_12 = 1;
            dispIo->dispcnt.bit_13_14 = 0;
            break;

        case 0x100010:
            dispIo->dispcnt.bit_12 = 1;
            dispIo->dispcnt.bit_13_14 = 1;
            break;

        case 0x200010:
            dispIo->dispcnt.bit_12 = 1;
            dispIo->dispcnt.bit_13_14 = 2;
            break;

        case 0x300010:
            dispIo->dispcnt.bit_12 = 1;
            dispIo->dispcnt.bit_13_14 = 3;
            break;
    }

    return;
}

void ObjCtrl::vfunc_0c(s32 src, s32 srcOffset, s32 dstOffset, s32 size)
{
    u32 data = src;
    u32 length = size;

    func_020a3d8c(data, length);

    if (IsAddressInVramRange(this->unk_04->objVram))
    {
        func_020a1dfc();
        func_020a1e44(data + srcOffset, dstOffset, length);
        func_020a1eb0();
    }
    else
    {
        func_020a1fb0();
        func_020a1fc8(data + srcOffset, dstOffset, length);
        func_020a202c();
    }

    return;
}

void ObjCtrl::vfunc_10(s32 src, s32 srcOffset, s32 dstOffset, s32 size, u8 param_5)
{
    ScreenState * activeSt;

    activeSt = gpActiveScreenSt;
    gpActiveScreenSt = IsAddressInVramRange(this->unk_04->objVram) ? gpMainScreenSt : gpSubScreenSt;

    func_0202079c(src + srcOffset, 0, dstOffset, size, param_5);

    gpActiveScreenSt = activeSt;

    return;
}

EC void func_0206fe18(struct AbstCtrl * self, s32 value)
{
    static_cast<ObjCtrl *>(self)->unk_0c = value;
    return;
}

EC void func_0206fe20(struct AbstCtrl * self, s32 src, s32 size)
{
    func_0206ee78(self, (void *)src, static_cast<ObjCtrl *>(self)->unk_0c, size);
    static_cast<ObjCtrl *>(self)->unk_0c += size;
    return;
}

EC void func_0206fe48(struct AbstCtrl * self, s32 size)
{
    func_0206eee0(self, 0, static_cast<ObjCtrl *>(self)->unk_0c, size);
    static_cast<ObjCtrl *>(self)->unk_0c += size;
    return;
}

EC void SetDispEnable_Maybe(struct UnkStruct_02197798 * gfx, s32 bg0, s32 bg1, s32 bg2, s32 bg3, s32 obj)
{
    gfx->unk_04->dispcnt.bg0_on = bg0;
    gfx->unk_04->dispcnt.bg1_on = bg1;
    gfx->unk_04->dispcnt.bg2_on = bg2;
    gfx->unk_04->dispcnt.bg3_on = bg3;
    gfx->unk_04->dispcnt.obj_on = obj;

    return;
}

EC void SetBgPriority_Maybe(struct UnkStruct_02197798 * gfx, s32 bg0, s32 bg1, s32 bg2, s32 bg3)
{
    gfx->unk_08[0].unk_0c->priority = bg0;
    gfx->unk_08[1].unk_0c->priority = bg1;
    gfx->unk_08[2].unk_0c->priority = bg2;
    gfx->unk_08[3].unk_0c->priority = bg3;

    return;
}

EC void SetBldTargetA_Maybe(struct UnkStruct_02197798 * gfx, s32 bg0, s32 bg1, s32 bg2, s32 bg3, s32 obj, s32 bd)
{
    DispIo * dispIo;

    dispIo = gfx->unk_00->dispIo;

    dispIo->bldcnt.target1_bg0_on = bg0;
    dispIo->bldcnt.target1_bg1_on = bg1;
    dispIo->bldcnt.target1_bg2_on = bg2;
    dispIo->bldcnt.target1_bg3_on = bg3;
    dispIo->bldcnt.target1_obj_on = obj;

    if (bd >= 0)
    {
        dispIo->bldcnt.target1_bd_on = bd;
    }

    return;
}

EC void SetBldTargetB_Maybe(struct UnkStruct_02197798 * gfx, s32 bg0, s32 bg1, s32 bg2, s32 bg3, s32 obj, s32 bd)
{
    DispIo * dispIo;

    dispIo = gfx->unk_00->dispIo;

    dispIo->bldcnt.target2_bg0_on = bg0;
    dispIo->bldcnt.target2_bg1_on = bg1;
    dispIo->bldcnt.target2_bg2_on = bg2;
    dispIo->bldcnt.target2_bg3_on = bg3;
    dispIo->bldcnt.target2_obj_on = obj;

    if (bd >= 0)
    {
        dispIo->bldcnt.target2_bd_on = bd;
    }

    return;
}

EC void func_02070148(struct UnkStruct_02197798 * engine, s32 brightness)
{
    ScreenState * activeSt;
    u8 enable;
    u8 isPositive;

    engine->unk_00->dispIo->unk_50 = brightness;

    if (brightness == 0 || brightness == 16 || brightness == -16)
    {
        enable = brightness != 0 ? TRUE : FALSE;
        isPositive = brightness > 0 ? TRUE : FALSE;

        if (IsAddressInVramRange(engine->unk_00->objVram))
        {
            activeSt = gpActiveScreenSt;
            gpActiveScreenSt = gpMainScreenSt;
            func_0201bc40(enable);
            func_0201bd04(isPositive);
            gpActiveScreenSt = activeSt;
        }
        else
        {
            activeSt = gpActiveScreenSt;
            gpActiveScreenSt = gpSubScreenSt;
            func_0201bc40(enable);
            func_0201bd04(isPositive);
            gpActiveScreenSt = activeSt;
        }
    }

    return;
}

s32 ObjCtrl::vfunc_04(void)
{
    UnkStruct_027e12f4 * buffer = static_cast<UnkStruct_027e12f4 *>(this->unk_04->unk_30);

    return (s32) buffer->unk_200;
}

