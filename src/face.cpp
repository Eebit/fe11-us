#include "global.h"

#include <new>

#include "hardware.hpp"
#include "hashtable.hpp"
#include "heap.hpp"
#include "oam.h"
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
    /* 14 */ u8 mouthFrames[5][2];
    /* 1E */ u8 eyeFrames[2][2]; //  +0x1e and +0x1f are midblink frame, +0x20 and +0x21 are for closed frame
    /* 22 */ STRUCT_PAD(0x22, 0x24);
};

struct Face
{
    /* 00 */ struct FaceInfo * pInfo;
    /* 04 */ s32 chrBase;
    /* 08 */ s32 palBase;
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
    /* 1C */ s32 blinkCnt;
    /* 20 */ s32 mouthState;
    /* 24 */ s32 mouthCnt;

    Face() {};

    inline BOOL HasFaceInfo()
    {
        return this->pInfo != NULL;
    }

    inline u32 GetPaletteIndex(void)
    {
        return this->palBase + (this->unk_17 >> 1);
    }

    inline BOOL CheckUnk15(void)
    {
        return (this->alpha != 0 && this->alpha != 0x10) ? TRUE : FALSE;
    }

    char * GetFid(void);
    char * GetName(void);
    u16 * GetSprite(void);
    s32 GetX(s32, s32);
    void Init(s32, s32);
    void _020077b8(char *, s32, s32, u8);
    void _02007874(char *, s32, s32);
    void Update(void);
    void Draw(void);
    void Hide(void);
    void Clear(void);
    void LoadGfx(char * fidStr);
    void UpdateBlink(void);
    void DrawBlink(void);
    void UpdateMouth(void);
    void DrawMouth(void);
    void DrawMouthExt(s32 x, s32 y, s32);
    void _02008454(void);
    void _02008780(void);
};

class FaceHandle : public ProcEx
{
public:
    /* 38 */ struct Face * faces;

    FaceHandle();

    virtual ~FaceHandle();

    void InitFaces(void);
    void UpdateFaces(void);
    void DrawFaces(void);
    BOOL _02008908(void);
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

// clang-format off

u16 Sprite_HudSmallFace[] =
{
    OAM0_Y(+0) | OAM0_256COLORS | OAM0_SHAPE_64x64, OAM1_X(+0) | OAM1_SIZE_64x64, OAM2_CHR(0),
    OAM0_Y(+64) | OAM0_256COLORS | OAM0_SHAPE_32x8, OAM1_X(+0) | OAM1_SIZE_32x8, OAM2_CHR(128),
    OAM0_Y(+64) | OAM0_256COLORS | OAM0_SHAPE_32x8, OAM1_X(+32) | OAM1_SIZE_32x8, OAM2_CHR(136),
    OAM0_Y(+0) | OAM0_256COLORS | OAM0_SHAPE_8x32, OAM1_X(+64) | OAM1_SIZE_8x32, OAM2_CHR(144),
    OAM0_Y(+32) | OAM0_256COLORS | OAM0_SHAPE_8x32, OAM1_X(+64) | OAM1_SIZE_8x32, OAM2_CHR(152),
    OAM0_Y(+64) | OAM0_256COLORS | OAM0_SHAPE_8x8, OAM1_X(+64) | OAM1_SIZE_8x8, OAM2_CHR(160),
    -1,
};

// clang-format on

EC u16 * GetSmallFaceSprite(void)
{
    return Sprite_HudSmallFace;
}

char * Face::GetFid(void)
{
    if (this->pInfo != NULL)
    {
        return this->pInfo->fid;
    }

    return NULL;
}

char * Face::GetName(void)
{
    if (this->pInfo == NULL)
    {
        return NULL;
    }

    return GetText(this->pInfo->mpid);
}

// clang-format off

u16 Sprite_Face[] =
{
    OAM0_Y(-127) | OAM0_256COLORS | OAM0_SHAPE_64x64, OAM1_X(-64) | OAM1_SIZE_64x64, OAM2_CHR(0),
    OAM0_Y(-127) | OAM0_256COLORS | OAM0_SHAPE_64x64, OAM1_X(+0) | OAM1_SIZE_64x64, OAM2_CHR(128),
    OAM0_Y(-63) | OAM0_256COLORS | OAM0_SHAPE_64x64, OAM1_X(-64) | OAM1_SIZE_64x64, OAM2_CHR(256),
    OAM0_Y(-63) | OAM0_256COLORS | OAM0_SHAPE_64x64, OAM1_X(+0) | OAM1_SIZE_64x64, OAM2_CHR(384),
    -1,
};

u16 Sprite_FaceFlipped[] =
{
    OAM0_Y(-127) | OAM0_256COLORS | OAM0_SHAPE_64x64, OAM1_X(+0) | OAM1_HFLIP | OAM1_SIZE_64x64, OAM2_CHR(0),
    OAM0_Y(-127) | OAM0_256COLORS | OAM0_SHAPE_64x64, OAM1_X(-64) | OAM1_HFLIP | OAM1_SIZE_64x64, OAM2_CHR(128),
    OAM0_Y(-63) | OAM0_256COLORS | OAM0_SHAPE_64x64, OAM1_X(+0) | OAM1_HFLIP | OAM1_SIZE_64x64, OAM2_CHR(256),
    OAM0_Y(-63) | OAM0_256COLORS | OAM0_SHAPE_64x64, OAM1_X(-64) | OAM1_HFLIP | OAM1_SIZE_64x64, OAM2_CHR(384),
    -1,
};

// clang-format on

u16 * Face::GetSprite(void)
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

s32 Face::GetX(s32 xBase, s32 xOffs)
{
    if (this->isFlipped == 1)
    {
        xBase = (0x80 - xBase) - xOffs;
    }

    return xBase;
}

void Face::Init(s32 chr, s32 pal)
{
    this->pInfo = NULL;
    this->chrBase = chr;
    this->palBase = pal;
    this->flags = 0;
    this->yBase = 0;
    this->xBase = 0;
    this->unk_14 = 0;
    this->unk_16 = 0;
    this->alpha = 0;
    this->unk_17 = 8;
    this->unk_18 = 8;
    this->blinkCnt = 0;
    this->mouthState = 0;
    this->mouthCnt = 0;

    return;
}

void Face::_020077b8(char * fidStr, s32 slotMaybe, s32 arg3, u8 arg4)
{
    u32 x;

    if (arg4 != 0)
    {
        switch (slotMaybe)
        {
            case 1:
                slotMaybe = 0;
                break;

            case 0:
                slotMaybe = 1;
                break;
        }
    }

    switch (slotMaybe)
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

void Face::_02007874(char * fidStr, s32 x, s32 y)
{
    this->xBase = x;
    this->yBase = y;
    this->unk_17 = 8;
    this->unk_18 = 8;
    this->unk_14 = 10;

    this->LoadGfx(fidStr);

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

void Face::Update(void)
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
        this->Clear();
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

    this->UpdateBlink();
    this->UpdateMouth();

    return;
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
void Face::Draw(void)
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

    spr = this->GetSprite();
    y = this->yBase;
    x = this->xBase;
    sp = this->unk_14;

    PutSpriteActiveScreen(
        OAM1_X(x), OAM0_Y(y) | OAM0_256COLORS, GetOam2Layer(1) | GetOam2Pal(this->GetPaletteIndex()) | GetOam2Chr(this->chrBase / 2),
        spr, sp);

    this->DrawBlink();
    this->DrawMouth();

    return;
}

void Face::Hide(void)
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

void Face::Clear(void)
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

void Face::LoadGfx(char * fidStr)
{
    u8 * palBuf;
    u8 * faceFile;

    this->pInfo = static_cast<struct FaceInfo *>(HashTable::Get1(fidStr));

    if (this->pInfo == NULL)
    {
        this->pInfo = static_cast<struct FaceInfo *>(HashTable::Get1("FID_DUMMY"));
    }

    func_02012180("/f");

    faceFile = static_cast<u8 *>(func_02012164(this->pInfo->faceFile));
    if (faceFile == NULL)
    {
        return;
    }

    // register the actual graphics to vram probably
    func_0206ee78(data_02197718, faceFile + 0x200, this->chrBase << 6, 0x6400);

    palBuf = static_cast<u8 *>(gHeap._01ffb9bc(0xA00));

    // copy the palette to a buffer
    func_020a5780(faceFile, palBuf, 0x200);

    // compute some variations on the palette to the buffer
    func_0206ea7c(palBuf, palBuf + 0x200, 0x80, 0, 0, 0, 0, 0xF);
    func_0206ea7c(palBuf, palBuf + 0x400, 0x80, 0, 0, 0, 0, 0xD);
    func_0206ea7c(palBuf, palBuf + 0x600, 0x80, 0, 0, 0, 0, 0xB);
    func_0206ea7c(palBuf, palBuf + 0x800, 0x80, 0, 0, 0, 0, 0xA);

    if (this->unk_0c_0 != 0)
    {
        func_0206ebd4(palBuf, 0x280);
    }

    data_02197718->vfunc_10((s32)palBuf, 0, this->palBase << 9, 0xA00, 0);
    data_0219771c->vfunc_10((s32)palBuf, 0, this->palBase << 9, 0xA00, 1);

    gHeap.Free(faceFile);

    return;
}

EC s32 RollRN(s32, s32);

void Face::UpdateBlink(void)
{
    switch (this->unk_0c_4_5)
    {
        case 2:
            this->blinkCnt = 11;
            break;

        case 3:
            this->blinkCnt = 7;
            return;

        case 1:
            if (this->blinkCnt == 4)
            {
                return;
            }

            if (this->blinkCnt > 9)
            {
                this->blinkCnt = 9;
            }

            break;
    }

    if (--this->blinkCnt >= 0)
    {
        return;
    }

    this->blinkCnt = RollRN(120, 180);

    return;
}

extern u16 data_027e0048[];

void Face::DrawBlink(void)
{
    switch (this->blinkCnt)
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
            x += this->GetX(this->pInfo->eyeFrames[0][0], 64);
            y = this->pInfo->eyeFrames[0][1];
            y += (this->yBase - 127);
            attr = GetOam2Layer(1) | GetOam2Pal(this->GetPaletteIndex()) | GetOam2Chr((this->chrBase + 0x150) / 2);

            if (this->isFlipped == 1)
            {
                hFlip = OAM1_HFLIP;
            }
            else
            {
                hFlip = 0;
            }

            tmp = this->unk_14 - 1;

            PutSpriteActiveScreen(OAM1_X(x) | hFlip, OAM0_Y(y) | OAM0_256COLORS, attr, data_027e0048, tmp);
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
            x += this->GetX(this->pInfo->eyeFrames[1][0], 64);
            y = this->pInfo->eyeFrames[1][1];
            y += (this->yBase - 127);
            attr = GetOam2Layer(1) | GetOam2Pal(this->GetPaletteIndex()) | GetOam2Chr((this->chrBase + 0x170) / 2);

            if (this->isFlipped == 1)
            {
                hFlip = OAM1_HFLIP;
            }
            else
            {
                hFlip = 0;
            }

            tmp = this->unk_14 - 1;

            PutSpriteActiveScreen(OAM1_X(x) | hFlip, OAM0_Y(y) | OAM0_256COLORS, attr, data_027e0048, tmp);
            return;
        }
    }

    return;
}

EC u32 func_0201ffd0(void);

void Face::UpdateMouth(void)
{
    switch (this->unk_0c_4_5)
    {
        case 2:
            if (this->mouthState == 2)
            {
                return;
            }

            if (this->mouthCnt > 3)
            {
                this->mouthCnt = 3;
            }

            break;

        case 3:
            this->mouthState = 3;
            return;

        case 0:
            if (this->mouthState == 0)
            {
                return;
            }

            if (this->mouthCnt > 3)
            {
                this->mouthCnt = 3;
            }

            break;
    }

    if (--this->mouthCnt >= 0)
    {
        return;
    }

    this->mouthCnt = (func_0201ffd0() & 7) + 1;
    this->mouthState = (this->mouthState + 1) & 3;

    return;
}

void Face::DrawMouth(void)
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

    switch (this->mouthState + temp_r1)
    {
        case 0:
            // Closed, neutral mouth; nothing to do
            break;

        case 1:
        case 3:
            this->DrawMouthExt(this->pInfo->mouthFrames[0][0], this->pInfo->mouthFrames[0][1], this->chrBase + 0x100);
            return;

        case 2:
            this->DrawMouthExt(this->pInfo->mouthFrames[1][0], this->pInfo->mouthFrames[1][1], this->chrBase + 0x110);
            return;

        case 4:
            this->DrawMouthExt(this->pInfo->mouthFrames[2][0], this->pInfo->mouthFrames[2][1], this->chrBase + 0x120);
            return;

        case 5:
        case 7:
            this->DrawMouthExt(this->pInfo->mouthFrames[3][0], this->pInfo->mouthFrames[3][1], this->chrBase + 0x130);
            return;

        case 6:
            this->DrawMouthExt(this->pInfo->mouthFrames[4][0], this->pInfo->mouthFrames[4][1], this->chrBase + 0x140);
            return;
    }
}

extern u16 data_027e0028[];

void Face::DrawMouthExt(s32 x, s32 y, s32 arg3)
{
    s32 temp_r5;
    s32 temp_ip;
    s32 xOam1;
    s32 yOam0;
    s32 oam2;
    s32 temp_r4;
    s32 hFlip;

    temp_r5 = this->xBase - 64;
    xOam1 = temp_r5 + this->GetX(x, 32);
    temp_ip = (this->yBase - 127);
    yOam0 = y + temp_ip;
    oam2 = GetOam2Layer(1) | GetOam2Pal(this->GetPaletteIndex()) | GetOam2Chr(arg3 / 2);

    if (this->isFlipped == 1)
    {
        hFlip = OAM1_HFLIP;
    }
    else
    {
        hFlip = 0;
    }

    temp_r4 = this->unk_14 - 1;

    PutSpriteActiveScreen(OAM1_X(xOam1) | hFlip, OAM0_Y(yOam0) | OAM0_256COLORS, oam2, data_027e0028, temp_r4);

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

void Face::_02008454(void)
{
    s16 var_r2;
    s32 x;
    s32 y;

    func_0206f0fc(data_0219771c, 0, 1, 30, 0);
    func_0206f4e0(data_0219771c, 1);

    var_r2 = 0;
    if (data_0219771c->unk_12 != 0)
    {
        var_r2 = data_0219771c->unk_16;
    }

    data_0219771c->unk_04->dispIo->unk_38[data_0219771c->unk_10] = var_r2;
    data_0219771c->unk_04->dispIo->unk_40[data_0219771c->unk_10] = 0;

    func_0206ee78(data_0219771c, (void *)(data_02197718->vfunc_00() + (this->chrBase << 6)), 0x4000, 0x4000);
    func_0206f580(data_0219771c, 0);

    x = (this->xBase / 8) - 8;
    y = ((this->yBase + 1) / 8) - 16;

    if (this->isFlipped == 1)
    {
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + (y << 5)],
            GetOam2Pal(this->GetPaletteIndex()) + 0x500);
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + (y << 5)],
            GetOam2Pal(this->GetPaletteIndex()) + 0x540);
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + ((y + 8) << 5)],
            GetOam2Pal(this->GetPaletteIndex()) + 0x580);
        func_02008414(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + ((y + 8) << 5)],
            GetOam2Pal(this->GetPaletteIndex()) + 0x5C0);
    }
    else
    {
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + (y << 5)],
            GetOam2Pal(this->GetPaletteIndex()) + 0x100);
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + (y << 5)],
            GetOam2Pal(this->GetPaletteIndex()) + 0x140);
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + ((y + 8) << 5)],
            GetOam2Pal(this->GetPaletteIndex()) + 0x180);
        func_020083d0(
            &data_0219771c->unk_04->tilemap[data_0219771c->unk_10][x + 8 + ((y + 8) << 5)],
            GetOam2Pal(this->GetPaletteIndex()) + 0x1C0);
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

FaceHandle::FaceHandle()
{
    this->faces = new Face[3];
    this->InitFaces();
}

FaceHandle::~FaceHandle()
{
    if (this->faces != NULL)
    {
        delete[] this->faces;
        this->faces = NULL;
    }
}

void FaceHandle::InitFaces(void)
{
    this->faces[0].Init(0, 0);
    this->faces[1].Init(400, 5);
    this->faces[2].Init(0, 0);
    return;
}

void FaceHandle::UpdateFaces(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        this->faces[i].Update();
    }

    return;
}

void FaceHandle::DrawFaces(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        this->faces[i].Draw();
    }

    return;
}

BOOL FaceHandle::_02008908(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        struct Face * it = &this->faces[i];
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

EC void FaceHandle_02008984(FaceHandle * proc)
{
    proc->Init();
    return;
}

EC void FaceHandle_02008998(FaceHandle * proc)
{
    proc->Loop();
    return;
}

// clang-format off

struct ProcCmd ProcScr_FaceHandle[] =
{
    PROC_06(0, FaceHandle_02008998),
    PROC_REPEAT(FaceHandle_02008984),
    PROC_END
};

// clang-format on

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
