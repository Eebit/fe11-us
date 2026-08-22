#include "global.h"

#include <new>

#include "hardware.hpp"
#include "hashtable.hpp"
#include "heap.hpp"
#include "proc_ex.hpp"

extern AbstCtrl * data_02197718;
extern BGCtrl * data_0219771c;

struct FaceInfo
{
    /* 00 */ char * fid; // "face ID"? lookup key
    /* 04 */ char * mpid; // localized name string
    /* 08 */ char * faceFile; // face filename in "/f/" directory
    /* 0C */ char * sfImgFile; // face graphic filename in "/sf/" directory
    /* 10 */ char * sfPalFile; // face palette filename in "/sf/" directory
    /* 14 */ u8 unk_14[5][2]; // mouth frames
    /* 1E */ u8 unk_1e[2][2]; // blink frames; +0x1e and +0x1f are midblink frame, +0x20 and +0x21 are for closed frame
    /* 22 */ STRUCT_PAD(0x22, 0x24);
};

struct Face
{
    /* 00 */ struct FaceInfo * pInfo;
    /* 04 */ s32 unk_04;
    /* 08 */ s32 unk_08;
    /* 0C */ union
    {
        u32 unk_0c;
        struct
        {
            u32 unk_0c_0 : 2;
            u32 unk_0c_2 : 1;
            u32 unk_0c_3 : 1; // is smiling
            u32 unk_0c_4_5 : 2;
            u32 unk_0c_6_7 : 2;
            u32 unk_0c_8_9 : 2;
            u32 unk_0c_a : 22;
        };
    };
    /* 10 */ s16 xBase;
    /* 12 */ s16 yBase;
    /* 14 */ u8 unk_14;
    /* 15 */ s8 unk_15;
    /* 16 */ s8 unk_16;
    /* 17 */ s8 unk_17;
    /* 18 */ s8 unk_18;
    /* 19 */ STRUCT_PAD(0x19, 0x1C);
    /* 1C */ s32 unk_1c;
    /* 20 */ s32 unk_20;
    /* 24 */ s32 unk_24;

    Face() {};

    BOOL HasFaceInfo()
    {
        return this->pInfo != NULL;
    }

    u32 GetPaletteIndex(void)
    {
        return this->unk_08 + (this->unk_17 >> 1);
    }

    BOOL CheckUnk15(void)
    {
        return (this->unk_15 != 0 && this->unk_15 != 0x10) ? TRUE : FALSE;
    }
};

class FaceHandle : public ProcEx
{
public:
    /* 38 */ struct Face * unk_38;

    FaceHandle(); // func_020087ac

    // func_020087f4
    // func_02008828
    virtual ~FaceHandle();
};

extern FaceHandle * data_020e3d40;

EC void * func_02012144(char *);
EC void func_02037890(void *);

// InitFaceInfo
EC void func_020076a8(void)
{
    // Check if the Face Info has already been loaded
    if (HashTable::Get1("FID_MARS") != NULL)
    {
        return;
    }

    // Load the **uncompressed** "/f/face.bin" file and cache in the hash table
    func_02037890(func_02012144("/f/face.bin"));

    return;
}

EC char * GetText(void *);

EC char * func_020076d4(char * key)
{
    struct FaceInfo * faceInfo = static_cast<struct FaceInfo *>(HashTable::Get1(key));

    if (faceInfo == NULL)
    {
        return key;
    }

    return GetText(faceInfo->mpid);
}

extern u16 data_020ca0f8[];

EC u16 * func_020076f8(void)
{
    return data_020ca0f8;
}

EC char * func_02007704(struct Face * self)
{
    if (self->pInfo != NULL)
    {
        return self->pInfo->fid;
    }

    return NULL;
}

EC char * func_02007718(struct Face * self)
{
    if (self->pInfo == NULL)
    {
        return NULL;
    }

    return GetText(self->pInfo->mpid);
}

// data_020ca0c4 => left facing?
// data_020ca0de => right facing? (hflip enabled)
extern u16 data_020ca0c4[];
extern u16 data_020ca0de[];

// Get the sprite for either left- or right-facing face graphic
EC u16 * func_02007738(struct Face * self)
{
    if (self->unk_0c_2 == 1)
    {
        return data_020ca0de;
    }
    else
    {
        return data_020ca0c4;
    }
}

EC s32 func_0200775c(struct Face * self, s32 param_2, s32 param_3)
{
    if (self->unk_0c_2 == 1)
    {
        param_2 = (0x80 - param_2) - param_3;
    }

    return param_2;
}

EC void func_0200777c(struct Face * self, s32 param_2, s32 param_3)
{
    self->pInfo = NULL;
    self->unk_04 = param_2;
    self->unk_08 = param_3;
    self->unk_0c = 0;
    self->yBase = 0;
    self->xBase = 0;
    self->unk_14 = 0;
    self->unk_16 = 0;
    self->unk_15 = 0;
    self->unk_17 = 8;
    self->unk_18 = 8;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;

    return;
}

EC void func_02007874(struct Face *, char *, s32, s32);

EC void func_020077b8(struct Face * self, char * arg1, s32 arg2, u32 arg3, u8 arg4)
{
    u32 var_r2_2;

    if (arg4 != 0)
    {
        switch (arg2)
        {
            case 1:
                arg2 = 0;
                break;

            case 0:
                arg2 = 1;
                break;
        }
    }

    switch (arg2)
    {
        case 0:
            var_r2_2 = 0x40;
            self->unk_0c_2 = arg3 == 0 ? 1 : 0;

            break;

        case 1:
            var_r2_2 = 0xC0;
            self->unk_0c_2 = arg3 == 0 ? 0 : 1;

            break;

        default:
            var_r2_2 = 0x80;
            self->unk_0c_2 = arg3 == 0 ? 1 : 0;

            break;
    }

    func_02007874(self, arg1, var_r2_2, 0x87);

    return;
}

EC void func_02007ca8(struct Face *, char *);

EC void func_02007874(struct Face * self, char * param_2, s32 param_3, s32 param_4)
{
    self->xBase = param_3;
    self->yBase = param_4;
    self->unk_17 = 8;
    self->unk_18 = 8;
    self->unk_14 = 10;

    func_02007ca8(self, param_2);

    switch (self->unk_0c_8_9)
    {
        case 1:
        case 3:
            self->unk_15 = 0x10;
            self->unk_16 = 0;
            return;

        case 0:
            self->unk_15 = 0;
            self->unk_16 = 0;
            return;

        case 2:
            self->unk_15 = 0;
            self->unk_16 = 2;
            return;
    }

    return;
}

EC void func_02007e78(struct Face *);
EC void func_02008150(struct Face *);
EC void func_02008454(struct Face *);
EC void func_02008780(struct Face *);
EC void func_02007c94(struct Face *);

struct UnkStruct_02197798
{
    ScreenState * unk_00;
    DispIo * unk_04;
    BGCtrl unk_08[4];
    ObjCtrl unk_68;

    void SetBlendEffect(s32 effect)
    {
        DispIo * disp = this->unk_00->dispIo;
        disp->bldcnt.effect = effect;
    }

    void SetBlendCoeffs(s32 a)
    {
        this->unk_00->dispIo->blend_coeff_a = a;
        this->unk_00->dispIo->blend_coeff_b = 16 - a;
    }
};
EC struct UnkStruct_02197798 * func_0206ecb0(void);

EC void func_020078fc(struct Face * self)
{
    char cVar1;
    struct UnkStruct_02197798 * puVar2;

    if (!self->HasFaceInfo())
    {
        return;
    }

    if (self->unk_18 < self->unk_17)
    {
        self->unk_17--;
    }

    if (self->unk_18 > self->unk_17)
    {
        self->unk_17++;
    }

    cVar1 = self->unk_15;

    puVar2 = func_0206ecb0();

    if ((puVar2->unk_00->dispIo->unk_50 == -0x10 || puVar2->unk_00->dispIo->unk_50 == 0x10))
    {
        if (self->unk_16 < 0)
        {
            self->unk_15 = 0xff;
        }
        else if (self->unk_16 > 0)
        {
            self->unk_15 = 0x10;
        }
    }
    else
    {
        self->unk_15 += self->unk_16;
    }

    if (self->unk_15 < 0)
    {
        func_02007c94(self);
        return;
    }

    if (self->unk_15 > 0x10)
    {
        self->unk_15 = 0x10;
    }

    if (self->unk_15 < 0)
    {
        self->unk_15 = 0;
    }

    if ((cVar1 == 0 || cVar1 == 0x10) && (self->unk_15 > 0) && (self->unk_15 < 0x10))
    {
        func_02008454(self);
    }

    if ((self->unk_15 == 0 || self->unk_15 == 0x10) && (cVar1 > 0) && (cVar1 < 0x10))
    {
        func_02008780(self);
    }

    func_02007e78(self);
    func_02008150(self);

    return;
}

static inline u32 OAM2_PAL(s32 idx)
{
    return (idx & 0xf) << 0xc;
}

static inline u32 OAM2_CHR(s32 i)
{
    return i & 0x3FF;
}

static inline u32 OAM2_LAYER(s32 l)
{
    return (l & 3) * 0x400;
}

EC s32 IsAddressInVramRange(s32);
EC void func_02007efc(struct Face *); // Draw blink overlay
EC void func_020081f8(struct Face *); // Draw mouth overlay
EC void SetBldTargetA_Maybe(void *, s32, s32, s32, s32, s32, s32);
EC void SetBldTargetB_Maybe(void *, s32, s32, s32, s32, s32, s32);
EC void func_01ffc404(u16, u16, u16, void *, s32);

static inline void PutSpriteActiveScreen(u16 xOam1, u16 yOam0, u16 oam2, u16 * sprite, u8 temp_r4)
{
    ScreenState * saved = gpActiveScreenSt;
    gpActiveScreenSt = IsAddressInVramRange(data_02197718->unk_04->objVram) ? gpMainScreenSt : gpSubScreenSt;
    func_01ffc404(xOam1, yOam0, oam2, sprite, temp_r4);
    gpActiveScreenSt = saved;
}

// Put the current face graphic
EC void func_02007a3c(struct Face * self)
{
    BOOL fading;
    s32 x;
    s32 y;
    s32 sp;
    u16 * spr;

    if (!self->HasFaceInfo())
    {
        return;
    }

    fading = self->HasFaceInfo() && self->CheckUnk15();

    if (fading)
    {
        func_0206ecb0()->SetBlendEffect(1);
        func_0206ecb0()->SetBlendCoeffs(self->unk_15);

        SetBldTargetA_Maybe(func_0206ecb0(), 0, 0, 0, 1, 0, -1);
        SetBldTargetB_Maybe(func_0206ecb0(), 1, 1, 1, 0, 1, -1);
    }

    if (self->unk_15 < 0x10)
    {
        return;
    }

    spr = func_02007738(self);
    y = self->yBase;
    x = self->xBase;
    sp = self->unk_14;

    PutSpriteActiveScreen(
        x & 0x1ff, (y & 0xff) | 0x2000, OAM2_LAYER(1) | OAM2_PAL(self->GetPaletteIndex()) | OAM2_CHR(self->unk_04 / 2),
        spr, sp);

    func_02007efc(self);
    func_020081f8(self);

    return;
}

EC void func_02007c18(struct Face * self)
{
    if (!self->HasFaceInfo())
    {
        return;
    }

    switch (self->unk_0c_8_9)
    {
        case 1:
            self->unk_15 = 0xff;
            self->unk_16 = 0;
            return;

        case 0:
            self->unk_15 = 0xff;
            self->unk_16 = 0;
            return;

        case 2:
        case 3:
            self->unk_16 = 0xfe;
            self->unk_14 = 10;
            return;
    }

    return;
}

EC void func_02007c94(struct Face * self)
{
    self->pInfo = NULL;
    self->unk_15 = self->unk_16 = 0;
    return;
}

EC void func_02012180(char *); // Change Directory wrapper?
EC void * func_02012164(char *); // Load Compressed File wrapper
EC void func_020a5780(void *, void *, s32);

EC void func_0206ebd4(void *, s32);

EC void func_0206ee78(AbstCtrl *, void *, s32, s32);
EC void func_0206ea7c(void *, void *, s32, s32, s32, s32, s32, s32);

EC void func_02007ca8(struct Face * self, char * fidStr)
{
    u8 * temp_r0_3;
    u8 * temp_r0_2;

    self->pInfo = static_cast<struct FaceInfo *>(HashTable::Get1(fidStr));

    if (self->pInfo == NULL)
    {
        self->pInfo = static_cast<struct FaceInfo *>(HashTable::Get1("FID_DUMMY"));
    }

    func_02012180("/f");

    temp_r0_2 = (u8 *)func_02012164(self->pInfo->faceFile);
    if (temp_r0_2 == NULL)
    {
        return;
    }

    // register the actual graphics to vram probably
    func_0206ee78(data_02197718, temp_r0_2 + 0x200, self->unk_04 << 6, 0x6400);

    temp_r0_3 = static_cast<u8 *>(gHeap._01ffb9bc(0xA00));

    // copy the palette to a buffer
    func_020a5780(temp_r0_2, temp_r0_3, 0x200);

    // compute some variations on the palette to the buffer
    func_0206ea7c(temp_r0_3, temp_r0_3 + 0x200, 0x80, 0, 0, 0, 0, 0xF);
    func_0206ea7c(temp_r0_3, temp_r0_3 + 0x400, 0x80, 0, 0, 0, 0, 0xD);
    func_0206ea7c(temp_r0_3, temp_r0_3 + 0x600, 0x80, 0, 0, 0, 0, 0xB);
    func_0206ea7c(temp_r0_3, temp_r0_3 + 0x800, 0x80, 0, 0, 0, 0, 0xA);

    if (self->unk_0c_0 != 0)
    {
        func_0206ebd4(temp_r0_3, 0x280);
    }

    data_02197718->vfunc_10((s32)temp_r0_3, 0, self->unk_08 << 9, 0xA00, 0);
    data_0219771c->vfunc_10((s32)temp_r0_3, 0, self->unk_08 << 9, 0xA00, 1);

    gHeap.Free(temp_r0_2);

    return;
}

EC s32 RollRN(s32, s32);

EC void func_02007e78(struct Face * self)
{
    switch (self->unk_0c_4_5)
    {
        case 2:
            self->unk_1c = 0xb;
            break;

        case 3:
            self->unk_1c = 7;
            return;

        case 1:
            if (self->unk_1c == 4)
            {
                return;
            }

            if (self->unk_1c > 9)
            {
                self->unk_1c = 9;
            }

            break;
    }

    if (--self->unk_1c >= 0)
    {
        return;
    }

    self->unk_1c = RollRN(120, 180);

    return;
}

extern u16 data_027e0048[];

EC void func_02007efc(struct Face * self)
{
    switch (self->unk_1c)
    {
        case 1:
        case 2:
        case 3:
        case 7:
        case 8:
        case 9:
        {
            s32 x;
            s32 y;
            s32 attr;
            s32 hFlip;
            s32 tmp;

            x = (self->xBase - 64);
            x += func_0200775c(self, self->pInfo->unk_1e[0][0], 64);
            y = self->pInfo->unk_1e[0][1];
            y += (self->yBase - 127);
            attr = OAM2_LAYER(1) | OAM2_PAL(self->GetPaletteIndex()) | OAM2_CHR((self->unk_04 + 0x150) / 2);

            if (self->unk_0c_2 == 1)
            {
                hFlip = 0x1000;
            }
            else
            {
                hFlip = 0;
            }

            tmp = self->unk_14 - 1;

            PutSpriteActiveScreen((x & 0x1ff) | hFlip, (y & 0xff) | 0x2000, attr, data_027e0048, tmp);
            return;
        }

        case 4:
        case 5:
        case 6:
        {
            s32 x;
            s32 attr;
            s32 y;
            s32 hFlip;
            s32 tmp;

            x = (self->xBase - 64);
            x += func_0200775c(self, self->pInfo->unk_1e[1][0], 64);
            y = self->pInfo->unk_1e[1][1];
            y += (self->yBase - 127);
            attr = OAM2_LAYER(1) | OAM2_PAL(self->GetPaletteIndex()) | OAM2_CHR((self->unk_04 + 0x170) / 2);

            if (self->unk_0c_2 == 1)
            {
                hFlip = 0x1000;
            }
            else
            {
                hFlip = 0;
            }

            tmp = self->unk_14 - 1;

            PutSpriteActiveScreen((x & 0x1ff) | hFlip, (y & 0xff) | 0x2000, attr, data_027e0048, tmp);
            return;
        }
    }

    return;
}

EC u32 func_0201ffd0(void);

EC void func_02008150(struct Face * self)
{
    switch (self->unk_0c_4_5)
    {
        case 2:
            if (self->unk_20 == 2)
            {
                return;
            }

            if (self->unk_24 > 3)
            {
                self->unk_24 = 3;
            }

            break;

        case 3:
            self->unk_20 = 3;
            return;

        case 0:
            if (self->unk_20 == 0)
            {
                return;
            }

            if (self->unk_24 > 3)
            {
                self->unk_24 = 3;
            }

            break;
    }

    if (--self->unk_24 >= 0)
    {
        return;
    }

    self->unk_24 = (func_0201ffd0() & 7) + 1;
    self->unk_20 = (self->unk_20 + 1) & 3;

    return;
}

EC void func_020082c0(struct Face *, s32, s32, s32);

// func_020081f8 => Draw mouth frame
EC void func_020081f8(struct Face * self)
{
    u32 temp_r1;

    if (self->unk_0c_3 == 1)
    {
        temp_r1 = 4;
    }
    else
    {
        temp_r1 = 0;
    }

    switch (self->unk_20 + temp_r1)
    {
        case 0:
            // Closed, neutral mouth; nothing to do
            break;

        case 1:
        case 3:
            func_020082c0(self, self->pInfo->unk_14[0][0], self->pInfo->unk_14[0][1], self->unk_04 + 0x100);
            return;

        case 2:
            func_020082c0(self, self->pInfo->unk_14[1][0], self->pInfo->unk_14[1][1], self->unk_04 + 0x110);
            return;

        case 4:
            func_020082c0(self, self->pInfo->unk_14[2][0], self->pInfo->unk_14[2][1], self->unk_04 + 0x120);
            return;

        case 5:
        case 7:
            func_020082c0(self, self->pInfo->unk_14[3][0], self->pInfo->unk_14[3][1], self->unk_04 + 0x130);
            return;

        case 6:
            func_020082c0(self, self->pInfo->unk_14[4][0], self->pInfo->unk_14[4][1], self->unk_04 + 0x140);
            return;
    }
}

extern u16 data_027e0028[];

void func_020082c0(struct Face * arg0, s32 x, s32 y, s32 arg3)
{
    s32 temp_r5;
    s32 temp_ip;
    s32 xOam1;
    s32 yOam0;
    s32 oam2;
    s32 temp_r4;
    s32 hFlip;

    temp_r5 = arg0->xBase - 64;
    xOam1 = temp_r5 + func_0200775c(arg0, x, 32);
    temp_ip = (arg0->yBase - 127);
    yOam0 = y + temp_ip;
    oam2 = OAM2_LAYER(1) | OAM2_PAL(arg0->GetPaletteIndex()) | OAM2_CHR(arg3 / 2);

    if (arg0->unk_0c_2 == 1)
    {
        hFlip = 0x1000;
    }
    else
    {
        hFlip = 0;
    }

    temp_r4 = arg0->unk_14 - 1;

    PutSpriteActiveScreen((xOam1 & 0x1FF) | hFlip, (yOam0 & 0xff) | 0x2000, oam2, data_027e0028, temp_r4);
}

EC void func_020083d0(u16 * tm, u32 tile)
{
    s32 y;
    s32 x;

    for (y = 0; y < 8; y++)
    {
        for (x = 0; x < 8; x++)
        {
            tm[y * 0x20 + x] = tile++;
        }
    }
}

EC void func_02008414(u16 * tm, u32 tile)
{
    s32 y;
    s32 x;

    for (y = 0; y < 8; y++)
    {
        for (x = 7; x >= 0; x--)
        {
            tm[y * 0x20 + x] = tile++;
        }
    }
}

EC void func_020083d0(u16 *, u32);
EC void func_02008414(u16 *, u32);
EC void func_0206f0fc(AbstCtrl *, s32, s32, s32, s32);
EC void func_0206f4e0(AbstCtrl *, u8);
EC void func_0206f580(AbstCtrl *, s32);

EC void func_02008454(struct Face * self)
{
    s16 var_r2;
    s32 x;
    s32 y;

    func_0206f0fc(data_0219771c, 0, 1, 0x1E, 0);
    func_0206f4e0(data_0219771c, 1);

    var_r2 = 0;
    if (data_0219771c->unk_12 != 0)
    {
        var_r2 = data_0219771c->unk_16;
    }

    data_0219771c->unk_04->dispIo->unk_38[data_0219771c->unk_10] = var_r2;
    data_0219771c->unk_04->dispIo->unk_40[data_0219771c->unk_10] = 0;

    func_0206ee78(data_0219771c, (void *)(data_02197718->vfunc_00() + (self->unk_04 << 6)), 0x4000, 0x4000);
    func_0206f580(data_0219771c, 0);

    x = (self->xBase / 8) - 8;
    y = ((self->yBase + 1) / 8) - 16;

    if (self->unk_0c_2 == 1)
    {
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + (y << 5)],
            OAM2_PAL(self->GetPaletteIndex()) + 0x500);
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + (y << 5)],
            OAM2_PAL(self->GetPaletteIndex()) + 0x540);
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + ((y + 8) << 5)],
            OAM2_PAL(self->GetPaletteIndex()) + 0x580);
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + ((y + 8) << 5)],
            OAM2_PAL(self->GetPaletteIndex()) + 0x5C0);
    }
    else
    {
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + (y << 5)],
            OAM2_PAL(self->GetPaletteIndex()) + 0x100);
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + (y << 5)],
            OAM2_PAL(self->GetPaletteIndex()) + 0x140);
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + ((y + 8) << 5)],
            OAM2_PAL(self->GetPaletteIndex()) + 0x180);
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + ((y + 8) << 5)],
            OAM2_PAL(self->GetPaletteIndex()) + 0x1C0);
    }

    data_0219771c->unk_04->unk_3e |= (1 << data_0219771c->unk_10);
}

EC void func_0206f580(AbstCtrl *, s32);

EC void func_02008780(struct Face * unused)
{
    func_0206f580(data_0219771c, 0);
    func_0206f4e0(data_0219771c, 0);
    return;
}

EC void func_02008864(FaceHandle *);

// func_020087ac
FaceHandle::FaceHandle()
{
    this->unk_38 = new Face[3];
    func_02008864(this);
}

// func_020087f4
// func_02008828
FaceHandle::~FaceHandle()
{
    if (this->unk_38 != NULL)
    {
        delete[] this->unk_38;
        this->unk_38 = NULL;
    }
}

EC void func_02008864(FaceHandle * self)
{
    func_0200777c(&self->unk_38[0], 0, 0);
    func_0200777c(&self->unk_38[1], 400, 5);
    func_0200777c(&self->unk_38[2], 0, 0);
    return;
}

EC void func_020088a8(FaceHandle * self)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        func_020078fc(&self->unk_38[i]);
    }

    return;
}

EC void func_020088d8(FaceHandle * self)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        func_02007a3c(&self->unk_38[i]);
    }

    return;
}

EC BOOL func_02008908(FaceHandle * self)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        struct Face * it = &self->unk_38[i];
        BOOL fading = FALSE;

        if (it->HasFaceInfo() && it->CheckUnk15())
        {
            fading = TRUE;
        }

        if (fading)
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC void func_02008984(FaceHandle * proc)
{
    proc->Init();
    return;
}

EC void func_02008998(FaceHandle * proc)
{
    proc->Loop();
    return;
}

extern struct ProcCmd data_020ca0ac[];

EC void func_020089ac(ProcPtr parent)
{
    if (parent != NULL)
    {
        data_020e3d40 = new (Proc_Start(data_020ca0ac, parent)) FaceHandle();
    }
    else
    {
        data_020e3d40 = new (Proc_Start(data_020ca0ac, PROC_TREE_9)) FaceHandle();
    }

    return;
}

EC void func_02008a04(void)
{
    Proc_EndEach(data_020ca0ac);
    data_020e3d40 = NULL;
    return;
}
