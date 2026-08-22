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
        u32 flags;
        struct
        {
            u32 unk_0c_0 : 2;
            u32 isFlipped : 1;
            u32 isSmiling : 1;
            u32 unk_0c_4_5 : 2;
            u32 unk_0c_6_7 : 2;
            u32 unk_0c_8_9 : 2;
            u32 unk_0c_a : 22;
        };
    };
    /* 10 */ s16 xBase;
    /* 12 */ s16 yBase;
    /* 14 */ u8 unk_14;
    /* 15 */ s8 alpha;
    /* 16 */ s8 unk_16;
    /* 17 */ s8 unk_17;
    /* 18 */ s8 unk_18;
    /* 19 */ STRUCT_PAD(0x19, 0x1C);
    /* 1C */ s32 unk_1c;
    /* 20 */ s32 unk_20;
    /* 24 */ s32 unk_24;

    Face() {};

    inline BOOL HasFaceInfo()
    {
        return this->pInfo != NULL;
    }

    inline u32 GetPaletteIndex(void)
    {
        return this->unk_08 + (this->unk_17 >> 1);
    }

    inline BOOL CheckUnk15(void)
    {
        return (this->alpha != 0 && this->alpha != 0x10) ? TRUE : FALSE;
    }

    char * GetFid(void); // _ZN4Face6GetFidEv
    char * GetName(void); // _ZN4Face7GetNameEv
    u16 * _02007738(void); // _ZN4Face9_02007738Ev
    s32 _0200775c(s32, s32); // _ZN4Face9_0200775cEll
    void Init(s32, s32); // _ZN4Face4InitEll
    void _020077b8(char *, s32, s32, u8); // _ZN4Face9_020077b8EPcllh
    void _02007874(char *, s32, s32); // _ZN4Face9_02007874EPcll
    void _020078fc(void); // _ZN4Face9_020078fcEv
    void _02007a3c(void); // _ZN4Face9_02007a3cEv
    void _02007c18(void); // _ZN4Face9_02007c18Ev
    void _02007c94(void); // _ZN4Face9_02007c94Ev
    void _02007ca8(char * fidStr); // _ZN4Face9_02007ca8EPc
    void _02007e78(void); // _ZN4Face9_02007e78Ev
    void _02007efc(void); // _ZN4Face9_02007efcEv
    void _02008150(void); // _ZN4Face9_02008150Ev
    void _020081f8(void); // _ZN4Face9_020081f8Ev
    void _020082c0(s32 x, s32 y, s32); // _ZN4Face9_020082c0Elll
    void _02008454(void); // _ZN4Face9_02008454Ev
    void _02008780(void); // _ZN4Face9_02008780Ev
};

class FaceHandle : public ProcEx
{
public:
    /* 38 */ struct Face * unk_38;

    FaceHandle(); // _ZN10FaceHandleC1Ev

    // _ZN10FaceHandleD1Ev
    // _ZN10FaceHandleD0Ev
    virtual ~FaceHandle();

    void _02008864(void); // _ZN10FaceHandle9_02008864Ev
    void _020088a8(void); // _ZN10FaceHandle9_020088a8Ev
    void _020088d8(void); // _ZN10FaceHandle9_020088d8Ev
    BOOL _02008908(void); // _ZN10FaceHandle9_02008908Ev
};

extern FaceHandle * gFaceHandle;

EC void * func_02012144(char *);
EC void func_02037890(void *);

EC void InitFaceInfo(void)
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

EC char * GetLocalizedName(char * key)
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

// _ZN4Face6GetFidEv
char * Face::GetFid(void)
{
    if (this->pInfo != NULL)
    {
        return this->pInfo->fid;
    }

    return NULL;
}

// _ZN4Face7GetNameEv
char * Face::GetName(void)
{
    if (this->pInfo == NULL)
    {
        return NULL;
    }

    return GetText(this->pInfo->mpid);
}

extern u16 Sprite_Face[];
extern u16 Sprite_FaceFlipped[];

// Get the sprite for either left- or right-facing face graphic
// _ZN4Face9_02007738Ev
u16 * Face::_02007738(void)
{
    if (this->isFlipped == 1)
    {
        return Sprite_FaceFlipped;
    }
    else
    {
        return Sprite_Face;
    }
}

// _ZN4Face9_0200775cEll
s32 Face::_0200775c(s32 param_2, s32 param_3)
{
    if (this->isFlipped == 1)
    {
        param_2 = (0x80 - param_2) - param_3;
    }

    return param_2;
}

// _ZN4Face4InitEll
void Face::Init(s32 param_2, s32 param_3)
{
    this->pInfo = NULL;
    this->unk_04 = param_2;
    this->unk_08 = param_3;
    this->flags = 0;
    this->yBase = 0;
    this->xBase = 0;
    this->unk_14 = 0;
    this->unk_16 = 0;
    this->alpha = 0;
    this->unk_17 = 8;
    this->unk_18 = 8;
    this->unk_1c = 0;
    this->unk_20 = 0;
    this->unk_24 = 0;

    return;
}

// _ZN4Face9_020077b8EPcllh
void Face::_020077b8(char * fidStr, s32 arg2, s32 arg3, u8 arg4)
{
    u32 x;

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
            x = 64;
            this->isFlipped = arg3 == 0 ? 1 : 0;

            break;

        case 1:
            x = 192;
            this->isFlipped = arg3 != 0 ? 0 : 1;

            break;

        default:
            x = 128;
            this->isFlipped = arg3 == 0 ? 1 : 0;

            break;
    }

    this->_02007874(fidStr, x, 135);

    return;
}

// _ZN4Face9_02007874EPcll
void Face::_02007874(char * fidStr, s32 x, s32 y)
{
    this->xBase = x;
    this->yBase = y;
    this->unk_17 = 8;
    this->unk_18 = 8;
    this->unk_14 = 10;

    this->_02007ca8(fidStr);

    switch (this->unk_0c_8_9)
    {
        case 1:
        case 3:
            this->alpha = 0x10;
            this->unk_16 = 0;
            return;

        case 0:
            this->alpha = 0;
            this->unk_16 = 0;
            return;

        case 2:
            this->alpha = 0;
            this->unk_16 = 2;
            return;
    }

    return;
}

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

// _ZN4Face9_020078fcEv
void Face::_020078fc(void)
{
    u8 alpha;
    struct UnkStruct_02197798 * puVar2;

    if (!this->HasFaceInfo())
    {
        return;
    }

    if (this->unk_18 < this->unk_17)
    {
        this->unk_17--;
    }

    if (this->unk_18 > this->unk_17)
    {
        this->unk_17++;
    }

    alpha = this->alpha;

    puVar2 = func_0206ecb0();

    if ((puVar2->unk_00->dispIo->unk_50 == -0x10 || puVar2->unk_00->dispIo->unk_50 == 0x10))
    {
        if (this->unk_16 < 0)
        {
            this->alpha = 0xff;
        }
        else if (this->unk_16 > 0)
        {
            this->alpha = 0x10;
        }
    }
    else
    {
        this->alpha += this->unk_16;
    }

    if (this->alpha < 0)
    {
        this->_02007c94();
        return;
    }

    if (this->alpha > 0x10)
    {
        this->alpha = 0x10;
    }

    if (this->alpha < 0)
    {
        this->alpha = 0;
    }

    if ((alpha == 0 || alpha == 0x10) && (this->alpha > 0) && (this->alpha < 0x10))
    {
        this->_02008454();
    }

    if ((this->alpha == 0 || this->alpha == 0x10) && (alpha > 0) && (alpha < 0x10))
    {
        this->_02008780();
    }

    this->_02007e78();
    this->_02008150();

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
// _ZN4Face9_02007a3cEv
void Face::_02007a3c(void)
{
    BOOL fading;
    s32 x;
    s32 y;
    s32 sp;
    u16 * spr;

    if (!this->HasFaceInfo())
    {
        return;
    }

    fading = this->HasFaceInfo() && this->CheckUnk15();

    if (fading)
    {
        func_0206ecb0()->SetBlendEffect(1);
        func_0206ecb0()->SetBlendCoeffs(this->alpha);

        SetBldTargetA_Maybe(func_0206ecb0(), 0, 0, 0, 1, 0, -1);
        SetBldTargetB_Maybe(func_0206ecb0(), 1, 1, 1, 0, 1, -1);
    }

    if (this->alpha < 0x10)
    {
        return;
    }

    spr = this->_02007738();
    y = this->yBase;
    x = this->xBase;
    sp = this->unk_14;

    PutSpriteActiveScreen(
        x & 0x1ff, (y & 0xff) | 0x2000, OAM2_LAYER(1) | OAM2_PAL(this->GetPaletteIndex()) | OAM2_CHR(this->unk_04 / 2),
        spr, sp);

    this->_02007efc();
    this->_020081f8();

    return;
}

// _ZN4Face9_02007c18Ev
void Face::_02007c18(void)
{
    if (!this->HasFaceInfo())
    {
        return;
    }

    switch (this->unk_0c_8_9)
    {
        case 1:
            this->alpha = 0xff;
            this->unk_16 = 0;
            return;

        case 0:
            this->alpha = 0xff;
            this->unk_16 = 0;
            return;

        case 2:
        case 3:
            this->unk_16 = 0xfe;
            this->unk_14 = 10;
            return;
    }

    return;
}

// _ZN4Face9_02007c94Ev
void Face::_02007c94(void)
{
    this->pInfo = NULL;
    this->alpha = this->unk_16 = 0;
    return;
}

EC void func_02012180(char *); // Change Directory wrapper?
EC void * func_02012164(char *); // Load Compressed File wrapper
EC void func_020a5780(void *, void *, s32);

EC void func_0206ebd4(void *, s32);

EC void func_0206ee78(AbstCtrl *, void *, s32, s32);
EC void func_0206ea7c(void *, void *, s32, s32, s32, s32, s32, s32);

// _ZN4Face9_02007ca8EPc
void Face::_02007ca8(char * fidStr)
{
    u8 * temp_r0_3;
    u8 * temp_r0_2;

    this->pInfo = static_cast<struct FaceInfo *>(HashTable::Get1(fidStr));

    if (this->pInfo == NULL)
    {
        this->pInfo = static_cast<struct FaceInfo *>(HashTable::Get1("FID_DUMMY"));
    }

    func_02012180("/f");

    temp_r0_2 = (u8 *)func_02012164(this->pInfo->faceFile);
    if (temp_r0_2 == NULL)
    {
        return;
    }

    // register the actual graphics to vram probably
    func_0206ee78(data_02197718, temp_r0_2 + 0x200, this->unk_04 << 6, 0x6400);

    temp_r0_3 = static_cast<u8 *>(gHeap._01ffb9bc(0xA00));

    // copy the palette to a buffer
    func_020a5780(temp_r0_2, temp_r0_3, 0x200);

    // compute some variations on the palette to the buffer
    func_0206ea7c(temp_r0_3, temp_r0_3 + 0x200, 0x80, 0, 0, 0, 0, 0xF);
    func_0206ea7c(temp_r0_3, temp_r0_3 + 0x400, 0x80, 0, 0, 0, 0, 0xD);
    func_0206ea7c(temp_r0_3, temp_r0_3 + 0x600, 0x80, 0, 0, 0, 0, 0xB);
    func_0206ea7c(temp_r0_3, temp_r0_3 + 0x800, 0x80, 0, 0, 0, 0, 0xA);

    if (this->unk_0c_0 != 0)
    {
        func_0206ebd4(temp_r0_3, 0x280);
    }

    data_02197718->vfunc_10((s32)temp_r0_3, 0, this->unk_08 << 9, 0xA00, 0);
    data_0219771c->vfunc_10((s32)temp_r0_3, 0, this->unk_08 << 9, 0xA00, 1);

    gHeap.Free(temp_r0_2);

    return;
}

EC s32 RollRN(s32, s32);

// _ZN4Face9_02007e78Ev
void Face::_02007e78(void)
{
    switch (this->unk_0c_4_5)
    {
        case 2:
            this->unk_1c = 0xb;
            break;

        case 3:
            this->unk_1c = 7;
            return;

        case 1:
            if (this->unk_1c == 4)
            {
                return;
            }

            if (this->unk_1c > 9)
            {
                this->unk_1c = 9;
            }

            break;
    }

    if (--this->unk_1c >= 0)
    {
        return;
    }

    this->unk_1c = RollRN(120, 180);

    return;
}

extern u16 data_027e0048[];

// _ZN4Face9_02007efcEv
void Face::_02007efc(void)
{
    switch (this->unk_1c)
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

            x = (this->xBase - 64);
            x += this->_0200775c(this->pInfo->unk_1e[0][0], 64);
            y = this->pInfo->unk_1e[0][1];
            y += (this->yBase - 127);
            attr = OAM2_LAYER(1) | OAM2_PAL(this->GetPaletteIndex()) | OAM2_CHR((this->unk_04 + 0x150) / 2);

            if (this->isFlipped == 1)
            {
                hFlip = 0x1000;
            }
            else
            {
                hFlip = 0;
            }

            tmp = this->unk_14 - 1;

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

            x = (this->xBase - 64);
            x += this->_0200775c(this->pInfo->unk_1e[1][0], 64);
            y = this->pInfo->unk_1e[1][1];
            y += (this->yBase - 127);
            attr = OAM2_LAYER(1) | OAM2_PAL(this->GetPaletteIndex()) | OAM2_CHR((this->unk_04 + 0x170) / 2);

            if (this->isFlipped == 1)
            {
                hFlip = 0x1000;
            }
            else
            {
                hFlip = 0;
            }

            tmp = this->unk_14 - 1;

            PutSpriteActiveScreen((x & 0x1ff) | hFlip, (y & 0xff) | 0x2000, attr, data_027e0048, tmp);
            return;
        }
    }

    return;
}

EC u32 func_0201ffd0(void);

// _ZN4Face9_02008150Ev
void Face::_02008150(void)
{
    switch (this->unk_0c_4_5)
    {
        case 2:
            if (this->unk_20 == 2)
            {
                return;
            }

            if (this->unk_24 > 3)
            {
                this->unk_24 = 3;
            }

            break;

        case 3:
            this->unk_20 = 3;
            return;

        case 0:
            if (this->unk_20 == 0)
            {
                return;
            }

            if (this->unk_24 > 3)
            {
                this->unk_24 = 3;
            }

            break;
    }

    if (--this->unk_24 >= 0)
    {
        return;
    }

    this->unk_24 = (func_0201ffd0() & 7) + 1;
    this->unk_20 = (this->unk_20 + 1) & 3;

    return;
}

// _ZN4Face9_020081f8Ev => Draw mouth frame
// _ZN4Face9_020081f8Ev
void Face::_020081f8(void)
{
    u32 temp_r1;

    if (this->isSmiling == 1)
    {
        temp_r1 = 4;
    }
    else
    {
        temp_r1 = 0;
    }

    switch (this->unk_20 + temp_r1)
    {
        case 0:
            // Closed, neutral mouth; nothing to do
            break;

        case 1:
        case 3:
            this->_020082c0(this->pInfo->unk_14[0][0], this->pInfo->unk_14[0][1], this->unk_04 + 0x100);
            return;

        case 2:
            this->_020082c0(this->pInfo->unk_14[1][0], this->pInfo->unk_14[1][1], this->unk_04 + 0x110);
            return;

        case 4:
            this->_020082c0(this->pInfo->unk_14[2][0], this->pInfo->unk_14[2][1], this->unk_04 + 0x120);
            return;

        case 5:
        case 7:
            this->_020082c0(this->pInfo->unk_14[3][0], this->pInfo->unk_14[3][1], this->unk_04 + 0x130);
            return;

        case 6:
            this->_020082c0(this->pInfo->unk_14[4][0], this->pInfo->unk_14[4][1], this->unk_04 + 0x140);
            return;
    }
}

extern u16 data_027e0028[];

// _ZN4Face9_020082c0Elll
void Face::_020082c0(s32 x, s32 y, s32 arg3)
{
    s32 temp_r5;
    s32 temp_ip;
    s32 xOam1;
    s32 yOam0;
    s32 oam2;
    s32 temp_r4;
    s32 hFlip;

    temp_r5 = this->xBase - 64;
    xOam1 = temp_r5 + this->_0200775c(x, 32);
    temp_ip = (this->yBase - 127);
    yOam0 = y + temp_ip;
    oam2 = OAM2_LAYER(1) | OAM2_PAL(this->GetPaletteIndex()) | OAM2_CHR(arg3 / 2);

    if (this->isFlipped == 1)
    {
        hFlip = 0x1000;
    }
    else
    {
        hFlip = 0;
    }

    temp_r4 = this->unk_14 - 1;

    PutSpriteActiveScreen((xOam1 & 0x1FF) | hFlip, (yOam0 & 0xff) | 0x2000, oam2, data_027e0028, temp_r4);

    return;
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

// _ZN4Face9_02008454Ev
void Face::_02008454(void)
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

    func_0206ee78(data_0219771c, (void *)(data_02197718->vfunc_00() + (this->unk_04 << 6)), 0x4000, 0x4000);
    func_0206f580(data_0219771c, 0);

    x = (this->xBase / 8) - 8;
    y = ((this->yBase + 1) / 8) - 16;

    if (this->isFlipped == 1)
    {
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + (y << 5)],
            OAM2_PAL(this->GetPaletteIndex()) + 0x500);
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + (y << 5)],
            OAM2_PAL(this->GetPaletteIndex()) + 0x540);
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + ((y + 8) << 5)],
            OAM2_PAL(this->GetPaletteIndex()) + 0x580);
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + ((y + 8) << 5)],
            OAM2_PAL(this->GetPaletteIndex()) + 0x5C0);
    }
    else
    {
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + (y << 5)],
            OAM2_PAL(this->GetPaletteIndex()) + 0x100);
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + (y << 5)],
            OAM2_PAL(this->GetPaletteIndex()) + 0x140);
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + ((y + 8) << 5)],
            OAM2_PAL(this->GetPaletteIndex()) + 0x180);
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + ((y + 8) << 5)],
            OAM2_PAL(this->GetPaletteIndex()) + 0x1C0);
    }

    data_0219771c->unk_04->unk_3e |= (1 << data_0219771c->unk_10);

    return;
}

EC void func_0206f580(AbstCtrl *, s32);

void Face::_02008780(void)
{
    func_0206f580(data_0219771c, 0);
    func_0206f4e0(data_0219771c, 0);
    return;
}

// _ZN10FaceHandleC1Ev
FaceHandle::FaceHandle()
{
    this->unk_38 = new Face[3];
    this->_02008864();
}

// _ZN10FaceHandleD1Ev
// _ZN10FaceHandleD0Ev
FaceHandle::~FaceHandle()
{
    if (this->unk_38 != NULL)
    {
        delete[] this->unk_38;
        this->unk_38 = NULL;
    }
}

// _ZN10FaceHandle9_02008864Ev
void FaceHandle::_02008864(void)
{
    this->unk_38[0].Init(0, 0);
    this->unk_38[1].Init(400, 5);
    this->unk_38[2].Init(0, 0);
    return;
}

// _ZN10FaceHandle9_020088a8Ev
void FaceHandle::_020088a8(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        this->unk_38[i]._020078fc();
    }

    return;
}

// _ZN10FaceHandle9_020088d8Ev
void FaceHandle::_020088d8(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        this->unk_38[i]._02007a3c();
    }

    return;
}

// _ZN10FaceHandle9_02008908Ev
BOOL FaceHandle::_02008908(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        struct Face * it = &this->unk_38[i];
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

extern struct ProcCmd ProcScr_FaceHandle[];

EC void StartFaceHandle(ProcPtr parent)
{
    if (parent != NULL)
    {
        gFaceHandle = new (Proc_Start(ProcScr_FaceHandle, parent)) FaceHandle();
    }
    else
    {
        gFaceHandle = new (Proc_Start(ProcScr_FaceHandle, PROC_TREE_9)) FaceHandle();
    }

    return;
}

EC void EndFaceHandle(void)
{
    Proc_EndEach(ProcScr_FaceHandle);
    gFaceHandle = NULL;
    return;
}
