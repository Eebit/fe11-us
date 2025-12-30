#include "global.h"

#include <new>

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "hardware.hpp"
#include "map.hpp"
#include "proc_ex.hpp"

class UnitFlash : public ProcEx
{
public:
    /* 38 */ u32 unk_38;
    /* 3C */ u16 * unk_3c;
    /* 40 */ u16 * unk_40;
    /* 44 */ u32 timer;
    /* 48 */ s32 duration;
    /* 4C */ u16 color;

    UnitFlash(s32 duration, s32 color, s32 jid, s32 arg3, s32 arg4)
    {
        SetSpriteDirectoryForJob(jid, 0);
        this->unk_3c = static_cast<u16 *>(gHeap.Alloc(0x40));
        func_020116a0("palette", this->unk_3c, 0x40, arg3 * 0x40);
        this->unk_40 = static_cast<u16 *>(gHeap.Alloc(0x40));
        this->unk_38 = arg4;
        this->duration = duration;
        this->color = color; // colour?
        this->timer = 0;

        if (duration == 0)
        {
            Proc_End(this);
        }
    }

    virtual void Loop()
    {
        s32 lerp;
        s32 timer;
        s32 i;
        s32 max;

        timer = ++this->timer;
        max = this->duration >> 1;

        if (timer < max)
        {
            lerp = Interpolate(0, 0, 0x10, timer, max);
        }
        else
        {
            lerp = Interpolate(0, 0x10, 0, timer - max, this->duration - max);
        }

        for (i = 0; i < 0x20; i++)
        {
            this->unk_40[i] = func_0202025c(this->unk_3c[i], this->color, 0x10 - lerp, lerp);
        }

        func_020205a4(this->unk_40, this->unk_38, 0x40, (this->timer == this->duration) & 0xff);

        if (this->timer == this->duration)
        {
            Proc_Break(this, 0);
        }

        return;
    }

    virtual ~UnitFlash()
    {
        if (this->timer == this->duration)
        {
            gHeap.Free(this->unk_3c);
        }
        else
        {
            func_020205a4(this->unk_3c, this->unk_38, 0x40, 1);
            gHeap.Free(this->unk_40);
        }
    }
};

struct IdleMapSprite
{
    /* 00 */ u32 imgAddr;
    /* 04 */ u16 palAddr;
    /* 06 */ u16 size;

    IdleMapSprite();

    BOOL IsLoaded(void);
    void Set(u32 imgAddr, u32 palAddr, s32 size);
};

class IdleMapSpriteMgr
{
public:
    /* 00 */ IdleMapSprite * sprites;
    /* 04 */ s32 imgAddrBase;
    /* 08 */ s32 palAddrBase;
    /* 0C */ s32 unk_0c;
    /* 10 */ s32 count;
    /* 14 */ u64 imgSlotFlags;
    /* 1C */ u64 palSlotFlags;

    IdleMapSpriteMgr(s32, s32, s32);
    ~IdleMapSpriteMgr();

    IdleMapSprite * GetSpriteFor(s32 index);
    s32 ReserveImgBlocks(s32 size);
    s32 ReservePalBlocks(s32 size);
    void ClearImgBlocks(u32 addr, s32 size);
    void ClearPalBlocks(u32 addr, s32 size);
    BOOL LoadSprite(s32 jid, s32 arg2, s32 arg3, u8 arg4);
    void UnloadSprite(s32 jid);

    void Init(void);
    void DrawSprite(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
};

struct MovingMapSprite
{
    /* 00 */ void * frames[6];
    /* 18 */ u32 imgAddr;
    /* 1C */ u32 palAddr;
    /* 20 */ u16 jid;
    /* 22 */ u8 unk_22;
    /* 23 */ u8 unk_23;
    /* 24 */ s8 animId;
    /* 25 */ s8 frame;
    /* 26 */ s8 prevAnimId;
    /* 27 */ s8 prevFrame;
    /* 28 */ u32 timer;

    MovingMapSprite(s32, s32, s32, s32);
    ~MovingMapSprite();

    s32 DrawSpriteExt(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    void DrawSprite(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    void StartFlash(s32 arg1, s32 arg2);
    s32 func_0203f6a0(void);
    void UpdateJid(s32 arg1);
    void func_0203f8a0(s32 arg1);
    void Free(void);
};

#define GFX_FIFO_POLYGONS_BEGIN *(vu32 *)(0x04000500)
#define GFX_FIFO_POLYGONS_END *(vu32 *)(0x04000504)
#define GFX_FIFO_VERTEX_TEXCOORD *(vu32 *)(0x04000488)
#define GFX_FIFO_VERTEX_16 *(vu32 *)(0x0400048c)
#define GFX_FIFO_VERTEX_XY *(vu32 *)(0x04000494)

extern vu32 data_027e1264;

extern const u8 data_020c515c[];

extern u16 data_027e0028[];

EC void SetSpriteDirectoryForJob(s32 jid, BOOL isMovingMapSprite)
{
    struct JobData * job;

    if (!isMovingMapSprite)
    {
        func_020a8f40("/2");
    }
    else
    {
        func_020a8f40("/3");
    }

    job = gFE11Database->pJob + jid;

    func_020a8f40(job->unk_00 + 4);

    return;
}

EC s32 GetTileSize_(void)
{
    if (gMapStateManager != NULL)
    {
        return GetTileSize();
    }

    return 0x18;
}

// TODO: I am assuming this is included here from an inline somewhere
EC s32 GetTileSize(void)
{
    return 0x18;
}

BOOL IdleMapSprite::IsLoaded(void)
{
    return this->imgAddr != -1;
}

void IdleMapSprite::Set(u32 imgAddr, u32 palAddr, s32 size)
{
    this->imgAddr = imgAddr;
    this->palAddr = palAddr;
    this->size = size;
    return;
}

IdleMapSprite::IdleMapSprite(void)
{
    this->imgAddr = -1;
    this->palAddr = -1;
}

IdleMapSpriteMgr::IdleMapSpriteMgr(s32 count, s32 imgAddrBase, s32 palAddrBase)
{
    this->sprites = new IdleMapSprite[count];
    this->imgAddrBase = imgAddrBase;
    this->palAddrBase = palAddrBase;
    this->count = count;
    this->imgSlotFlags = 0;
    this->palSlotFlags = 0;
}

IdleMapSpriteMgr::~IdleMapSpriteMgr()
{
    delete[] this->sprites;
}

IdleMapSprite * IdleMapSpriteMgr::GetSpriteFor(s32 index)
{
    return this->sprites + index;
}

s32 IdleMapSpriteMgr::ReserveImgBlocks(s32 size)
{
    s32 i;
    s32 numBlocks;

    numBlocks = IntSys_Div(size, 0x1000) + (IntSys_Mod(size, 0x1000) != 0 ? 1 : 0);

    for (i = 0; i < 0x40; i++)
    {
        s32 j;

        if (this->imgSlotFlags & (1ull << i))
        {
            continue;
        }

        for (j = i; j < i + numBlocks; j++)
        {
            if (j == 0x40)
            {
                break;
            }

            if (this->imgSlotFlags & (1ull << j))
            {
                break;
            }
        }

        if (j == i + numBlocks)
        {
            for (j = i; j < i + numBlocks; j++)
            {
                this->imgSlotFlags |= (1ull << j);
            }

            return this->imgAddrBase + (i * 0x1000);
        }
    }

    return 0;
}

s32 IdleMapSpriteMgr::ReservePalBlocks(s32 size)
{
    s32 i;
    s32 numBlocks;

    numBlocks = IntSys_Div(size, 0x40) + (IntSys_Mod(size, 0x40) != 0 ? 1 : 0);

    for (i = 0; i < 0x40; i++)
    {
        s32 j;

        if (this->palSlotFlags & (1ull << i))
        {
            continue;
        }

        for (j = i; j < i + numBlocks; j++)
        {
            if (j == 0x40)
            {
                break;
            }

            if (this->palSlotFlags & (1ull << j))
            {
                break;
            }
        }

        if (j == i + numBlocks)
        {
            for (j = i; j < i + numBlocks; j++)
            {
                this->palSlotFlags |= (1ull << j);
            }

            return this->palAddrBase + (i * 0x40);
        }
    }

    return 0;
}

void IdleMapSpriteMgr::ClearImgBlocks(u32 addr, s32 size)
{
    s32 i;
    s32 start;
    s32 numBlocks;

    start = IntSys_Div(addr - this->imgAddrBase, 0x1000);
    numBlocks = IntSys_Div(size, 0x1000) + (IntSys_Mod(size, 0x1000) != 0 ? 1 : 0);

    for (i = start; i < start + numBlocks; i++)
    {
        this->imgSlotFlags &= ~(1ull << i);
    }

    return;
}

void IdleMapSpriteMgr::ClearPalBlocks(u32 addr, s32 size)
{
    s32 i;
    s32 start;
    s32 numBlocks;

    start = IntSys_Div(addr - this->palAddrBase, 0x40);
    numBlocks = IntSys_Div(size, 0x40) + (IntSys_Mod(size, 0x40) != 0 ? 1 : 0);

    for (i = start; i < start + numBlocks; i++)
    {
        this->palSlotFlags &= ~(1ull << i);
    }

    return;
}

BOOL IdleMapSpriteMgr::LoadSprite(s32 jid, s32 arg2, s32 arg3, u8 arg4)
{
    void * filePtr[4];
    s32 size[4];
    s32 imgDst[4];
    char str[8];
    char * it;
    s32 totalSize;
    s32 i;
    s32 len;
    s32 palSize;
    s32 palDst;

    IdleMapSprite * handle = this->GetSpriteFor(jid);

    if ((arg4 == 0) && (handle->IsLoaded()))
    {
        return FALSE;
    }

    SetSpriteDirectoryForJob(jid, FALSE);

    totalSize = 0;
    func_020b6c98(str, "idle");
    len = func_020b6de0(str);

    for (i = 0, it = str + len; i < 4; i++)
    {
        it[0] = IntSys_Div(i, 10) + '0';
        it[1] = IntSys_Mod(i, 10) + '0';
        it[2] = '\0';

        filePtr[i] = func_02011920(str, 0);
        size[i] = gHeap.SizeOf(filePtr[i]);
        totalSize += size[i];
    }

    if (arg4 == 0)
    {
        imgDst[0] = this->ReserveImgBlocks(totalSize);
    }
    else
    {
        imgDst[0] = handle->imgAddr;
    }

    for (i = 1; i < 4; i++)
    {
        imgDst[i] = imgDst[i - 1] + size[i - 1];
    }

    if (arg3 != 0)
    {
        for (i = 0; i < 4; i++)
        {
            LoadTextureImage(filePtr[i], imgDst[i], size[i]);
            gHeap.Free(filePtr[i]);
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            func_02020488(filePtr[i], imgDst[i], size[i], 1);
        }
    }

    filePtr[0] = func_02011854("palette", 0);
    palSize = gHeap.SizeOf(filePtr[0]);

    if (arg4 == 0)
    {
        palDst = this->ReservePalBlocks(palSize);
    }
    else
    {
        palDst = handle->palAddr;
    }

    if (arg3 != 0)
    {
        LoadTexturePalette((u16 *)filePtr[0], palDst, palSize);
        gHeap.Free(filePtr[0]);
    }
    else
    {
        func_020205a4((u16 *)filePtr[0], palDst, palSize, 1);
    }

    handle->Set(imgDst[0], palDst, totalSize);

    return TRUE;
}

void IdleMapSpriteMgr::UnloadSprite(s32 jid)
{
    s32 imgAddr;
    s32 palAddr;
    s32 imgSize;

    IdleMapSprite * handle = this->GetSpriteFor(jid);

    imgSize = handle->size;
    imgAddr = handle->imgAddr;
    palAddr = handle->palAddr;

    handle->Set(-1, -1, 0);

    this->ClearImgBlocks(imgAddr, imgSize);
    this->ClearPalBlocks(palAddr, 0x80);

    return;
}

EC s32 func_0203e9d4(s32 jid, s32 unused, char * arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    char str[12];
    char * it;
    void * uVar3;
    s32 len;
    s32 iVar4;
    s32 ret;
    s32 end;
    s32 i;

    SetSpriteDirectoryForJob(jid, FALSE);

    ret = 0;

    func_020b6c98(str, arg2);
    len = func_020b6de0(str);

    end = arg3 + arg4;

    for (i = arg3, it = str + len; i < end; i++)
    {
        it[0] = IntSys_Div(i, 10) + '0';
        it[1] = IntSys_Mod(i, 10) + '0';
        it[2] = '\0';

        uVar3 = func_02011920(str, 0);
        iVar4 = gHeap.SizeOf(uVar3);

        if (arg6 != 0)
        {
            LoadTextureImage(uVar3, arg5, iVar4);
            gHeap.Free(uVar3);
        }
        else
        {
            func_02020488(uVar3, arg5, iVar4, 1);
        }

        arg5 += iVar4;
        ret += iVar4;
    }

    return ret;
}

EC s32 func_0203eacc(s32 jid, s32 arg1, s32 palDst, s32 arg3)
{
    u16 * palSrc;

    if (arg1 >= 2)
    {
        arg1 = 0;
    }

    SetSpriteDirectoryForJob(jid, 0);

    palSrc = static_cast<u16 *>(gHeap.Alloc(0x40));

    func_020116a0("palette", palSrc, 0x40, arg1 * 0x40);

    if (arg3 != 0)
    {
        LoadTexturePalette(palSrc, palDst, 0x40);
        gHeap.Free(palSrc);
    }
    else
    {
        func_020205a4(palSrc, palDst, 0x40, 1);
    }

    return 0x40;
}

EC void func_0203eb50(s32 jid)
{
    SetSpriteDirectoryForJob(jid, TRUE);
}

EC void func_0203eb60(s32 jid, s32 unused, s32 arg2, s32 arg3)
{
    if (arg3 != 0)
    {
        SetSpriteDirectoryForJob(jid, TRUE);
    }

    func_0201177c("idle", arg2);

    return;
}

EC void func_0203eb8c(s32 jid, s32 unused, s32 arg2, s32 arg3)
{
    void * uVar1;

    if (arg3 != 0)
    {
        SetSpriteDirectoryForJob(jid, TRUE);
    }

    uVar1 = func_02011920("idle", 0);
    func_020203e0(uVar1, arg2, gHeap.SizeOf(uVar1), 1);

    return;
}

EC void func_0203ebe0(s32 jid, s32 unused, void * arg2, s32 arg3)
{
    if (arg3 != 0)
    {
        SetSpriteDirectoryForJob(jid, TRUE);
    }

    func_02011ee4(func_02011d78, "idle", arg2, 0, 0);

    return;
}

EC void func_0203ec24(s32 jid, s32 arg1, u16 * arg2, s32 arg3)
{
    if (arg3 != 0)
    {
        SetSpriteDirectoryForJob(jid, TRUE);
    }

    if (arg1 >= 2)
    {
        arg1 = 0;
    }

    func_020116a0("palette", arg2, 0xc0, arg1 * 0xc0);

    return;
}

EC void func_0203ec64(s32 jid, s32 arg1, u16 * arg2, s32 arg3)
{
    if (arg3 != 0)
    {
        SetSpriteDirectoryForJob(jid, TRUE);
    }

    if (arg1 >= 2)
    {
        arg1 = 0;
    }

    func_02011ee4(func_02011d5c, "palette", arg2, 0xc0, arg1 * 0xc0);

    return;
}

void IdleMapSpriteMgr::Init(void)
{
    s32 i;

    for (i = 0; i < this->count; i++)
    {
        this->GetSpriteFor(i)->Set(-1, -1, 0);
    }

    this->imgSlotFlags = 0;
    this->palSlotFlags = 0;

    return;
}

void IdleMapSpriteMgr::DrawSprite(s32 jid, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 x = arg3;
    s32 y = arg4;

    IdleMapSprite * handle = this->GetSpriteFor(jid);

    if (!handle->IsLoaded())
    {
        return;
    }

    x = x + ((GetTileSize_() - 0x20) >> 1);
    y = y + (GetTileSize_() - 0x20);

    if (x + 0x20 < 0)
    {
        return;
    }

    if (y + 0x20 < 0)
    {
        return;
    }

    if (x >= 0x100)
    {
        return;
    }

    if (y >= 0xc0)
    {
        return;
    }

    func_0206cf30(
        1, 0x20, 0x20, (u32)(handle->imgAddr + (this->unk_0c * 0x400)), (u32)(handle->palAddr + (arg2 * 0x40)), 0, 0);
    func_0206d2ac(x, y, arg5, 0x20, 0x20, arg2 & 1, 0);

    return;
}

EC void func_0203ede8(s32 jid, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, u32 arg6)
{
    s32 cVar1 = gFE11Database->pJob[jid].unk_54;

    if (arg1 >= 2)
    {
        arg1 = 0;
    }

    func_0206cf30(1, 0x20, 0x20, arg5, arg6, 0, 0);
    func_0206d2ac(arg2, arg3 + cVar1, arg4, 0x20, 0x20, arg1 & 1, 0);

    return;
}

EC void func_0203ee78(s32 jid, s32 arg1, s32 x, s32 y, s32 arg4, s32 palId, s32 arg6)
{
    s32 uVar1;
    s32 iVar2;
    s32 isFlipped;
    s32 yOam0;

    isFlipped = 0;
    yOam0 = gFE11Database->pJob[jid].unk_54 + y;

    if (arg1 >= 2)
    {
        arg1 = 0;
    }

    if ((arg1 & 1) != 0)
    {
        isFlipped = 0x1000;
    }

    uVar1 = IntSys_Div(data_027e1264, 10);
    iVar2 = IntSys_Mod(uVar1, 6);

    func_01ffc404(
        (x & 0x1ff) | isFlipped, (yOam0 & 0xff) | 0x2000,
        (arg4 + data_020c515c[iVar2] * 0x20) >> (gpActiveScreenSt->dispIo->dispcnt.unk_02_bit_0 & 0x3ff) |
            (palId << 0xc),
        data_027e0028, arg6);

    return;
}

MovingMapSprite::MovingMapSprite(s32 jid, s32 arg2, s32 arg3, s32 arg4)
{
    s32 i;
    u16 * buf;

    if (arg2 >= 2)
    {
        arg2 = 0;
    }

    this->jid = jid;
    this->unk_22 = arg2;
    this->imgAddr = arg3;
    this->palAddr = arg4;
    this->unk_23 = 0;
    this->prevAnimId = -1;
    this->prevFrame = -1;
    this->frame = -1;
    this->timer = 0;

    SetSpriteDirectoryForJob(jid, 0);

    buf = static_cast<u16 *>(gHeap.Alloc(0x40));
    func_020116a0("palette", buf, 0x40, arg2 * 0x40);
    func_020205a4(buf, arg4, 0x40, 1);

    for (i = 0; i < 6; i++)
    {
        this->frames[i] = NULL;
    }
}

MovingMapSprite::~MovingMapSprite(void)
{
    this->Free();
}

EC u32 func_0203f030(s32 param_1)
{
    switch (param_1)
    {
        case 1:
            return 2;

        case 2:
            return 3;

        case 4:
            return 4;

        case 8:
            return 5;
    }

    return -1;
}

EC void
func_0203f088(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9)
{
    u16 temp_r0;
    u16 temp_r10;
    u16 temp_r1;
    u16 temp_r4;

    temp_r1 = (u16)(s16)(arg7 * 0x10);
    temp_r0 = (u16)(s16)(arg6 * 0x10);
    temp_r4 = (u16)(s16)(arg9 * 0x10);
    temp_r10 = (u16)(s16)(arg8 * 0x10);

    GFX_FIFO_POLYGONS_BEGIN = 1;

    GFX_FIFO_VERTEX_TEXCOORD = temp_r0 | (temp_r1 << 0x10);
    GFX_FIFO_VERTEX_16 = (u16)arg0 | ((u16)arg1 << 0x10);
    GFX_FIFO_VERTEX_16 = (s32)(u16)arg2;

    GFX_FIFO_VERTEX_TEXCOORD = temp_r0 | (temp_r4 << 0x10);
    GFX_FIFO_VERTEX_16 = (u16)arg0 | ((u16)(s16)(arg1 + arg5) << 0x10);
    GFX_FIFO_VERTEX_16 = (s32)(u16)arg3;

    GFX_FIFO_VERTEX_TEXCOORD = temp_r10 | (temp_r4 << 0x10);

    GFX_FIFO_VERTEX_XY = (s32)((u16)(s16)(arg0 + arg4) | ((u16)(s16)(arg1 + arg5) << 0x10));

    GFX_FIFO_VERTEX_TEXCOORD = temp_r10 | (temp_r1 << 0x10);
    GFX_FIFO_VERTEX_16 = (u16)(s16)(arg0 + arg4) | ((u16)arg1 << 0x10);
    GFX_FIFO_VERTEX_16 = (s32)(u16)arg2;

    GFX_FIFO_POLYGONS_END = 0;

    return;
}

EC void func_0203f1bc(
    s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA,
    s32 argB)
{
    if ((argA != 0) && (argB != 0))
    {
        func_0203f088(arg0, arg1, arg2, arg3, arg4, arg5, arg8 - 1, arg9 - 1, arg6 - 1, arg7 - 1);
        return;
    }

    if (argA != 0)
    {
        func_0203f088(arg0, arg1, arg2, arg3, arg4, arg5, arg8 - 1, arg7, arg6 - 1, arg9);
        return;
    }

    if (argB != 0)
    {
        func_0203f088(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg9 - 1, arg8, arg7 - 1);
        return;
    }

    func_0203f088(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    return;
}

EC void func_0203f2a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    func_0203f1bc(arg0, arg1, arg2, arg3, arg4, arg5, 0, 0, arg4, arg5, arg6, arg7);
    return;
}

s32 MovingMapSprite::DrawSpriteExt(s32 x, s32 y, s32 arg3, s32 arg4, s32 animId, s32 frame)
{
    char str[32];
    char * it;
    struct JobData * pJob;
    s32 len;

    s32 x_ = x;
    s32 y_ = y;

    s32 ret = 0;

    if (animId != -1)
    {
        this->animId = animId;
    }

    if (frame != -1)
    {
        this->frame = frame;
    }
    else
    {
        this->frame = func_0203f6d0(this->jid, this->animId, this->timer, this->unk_23, 0);
    }

    if ((this->animId != this->prevAnimId) || (this->frame != this->prevFrame))
    {
        if (this->animId != this->prevAnimId)
        {
            this->Free();
        }

        if (this->frame != this->prevFrame)
        {
            ret = 1;
        }

        if (this->frames[this->frame] == NULL)
        {
            str[0] = '/';
            str[1] = '3';
            str[2] = '/';

            pJob = gFE11Database->pJob + this->jid;
            it = str;
            func_020b6c98(it + 3, pJob->unk_00 + 4);

            it = str + 3;
            it[func_020b6de0(pJob->unk_00 + 4)] = '/';

            if (this->unk_22 & 1)
            {
                func_020b6c98(it + 1, GetAnimName(func_0203f864(this->animId)));
            }
            else
            {
                func_020b6c98(it + 1, GetAnimName(this->animId));
            }

            len = func_020b6de0(str);
            it = str + len;

            it[0] = IntSys_Div(this->frame, 10) + '0';
            it[1] = IntSys_Mod(this->frame, 10) + '0';
            it[2] = '\0';

            this->frames[this->frame] = func_02011920(str, 0);
        }

        func_02020488(this->frames[this->frame], this->imgAddr, gHeap.SizeOf(this->frames[this->frame]), 0);
        this->prevFrame = this->frame;
        this->prevAnimId = this->animId;
    }

    x_ = x_ + ((GetTileSize_() - 0x20) >> 1);
    y_ = y_ + (GetTileSize_() - 0x20) + this->animId + gFE11Database->pJob[this->jid].unk_54;

    if (((x_ + 0x20) < 0) || ((y_ + 0x20) < 0) || (x_ >= 0x100) || (y_ >= 0xC0))
    {
        return ret;
    }

    func_0206cf30(1, 0x20, 0x20, this->imgAddr, this->palAddr, 0, 0);
    func_0203f2a0(x_, y_, arg3, arg4, 0x20, 0x20, this->unk_22 & 1, 0);

    return ret;
}

void MovingMapSprite::DrawSprite(s32 x, s32 y, s32 arg3, s32 animId, s32 frame)
{
    this->DrawSpriteExt(x, y, arg3, arg3, animId, frame);
    return;
}

void MovingMapSprite::StartFlash(s32 duration, s32 color)
{
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_B)) UnitFlash(duration, color, this->jid, this->unk_22, this->palAddr);
}

EC s32 func_0203f650(s32 jid, s32 animId)
{
    switch (animId)
    {
        case 0:
        case 1:
            return 60;

        case 6:
            return 0;

        default:
            return gFE11Database->pJob[jid].unk_4c * 6;
    }
}

s32 MovingMapSprite::func_0203f6a0(void)
{
    s32 iVar1 = func_0203f650(this->jid, this->animId);

    if (iVar1 != 0)
    {
        return IntSys_Div(this->timer & ~0x80000000, iVar1);
    }

    return 0;
}

EC s32 func_0203f6d0(s32 jid, s32 animId, s32 time, s32 arg3, u8 arg4)
{
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_r3;

    switch (animId)
    {
        case 0:
            if (arg4 != 0)
            {
                var_r3 = IntSys_Mod(IntSys_Div(time, 10), 6);
                return data_020c515c[var_r3];
            }
            else
            {
                var_r3 = IntSys_Mod(IntSys_Div(data_027e1264, 10), 6);
                return data_020c515c[var_r3];
            }

        case 1:
            var_r3 = IntSys_Mod(IntSys_Div(time, 10), 6);
            return data_020c515c[var_r3];

        case 6:
            if (arg3 == 0)
            {
                arg3 = gFE11Database->pJob[jid].unk_4c;
            }

            temp_r0 = IntSys_Div(time & ~0x80000000, arg3);

            if (arg4 != 0)
            {
                temp_r0_2 = IntSys_Mod(temp_r0, 0xC);

                if (temp_r0_2 == 0xB)
                {
                    return 5;
                }

                if (temp_r0_2 < 2)
                {
                    return temp_r0_2;
                }

                return IntSys_Mod(temp_r0_2 - 2, 3) + 2;
            }

            if (temp_r0 < 2)
            {
                return temp_r0;
            }

            return IntSys_Mod(temp_r0 - 2, 3) + 2;

        default:
            if (arg3 == 0)
            {
                arg3 = gFE11Database->pJob[jid].unk_4c;
            }

            return IntSys_Mod(IntSys_Div(time & ~0x80000000, arg3), 6);
    }
}

EC void MovingMapSprite::UpdateJid(s32 jid)
{
    if (jid == this->jid)
    {
        return;
    }

    this->jid = jid;
    this->prevFrame = -1;

    func_0203eacc(jid, this->unk_22, this->palAddr, 0);

    this->Free();

    return;
}

EC s32 func_0203f864(s32 animId)
{
    switch (animId)
    {
        case 2:
            return 3;

        case 3:
            return 2;
    }
}

// clang-format off

char * gAnimNameLut[] =
{
    "idle",
    "active",
    "left",
    "right",
    "down",
    "up",
    "staff",
    "change",
};

// clang-format on

EC char * GetAnimName(s32 animId)
{
    return gAnimNameLut[animId];
}

// clang-format off

u8 gMovingSpriteFrameCountLut[] =
{
    4,
    4,
    6,
    6,
    6,
    6,
    6,
    6,
};

// clang-format on

EC u8 GetAnimFrameCount(s32 animId)
{
    return gMovingSpriteFrameCountLut[animId];
}

void MovingMapSprite::func_0203f8a0(s32 arg1)
{
    s32 cVar2 = this->unk_23;

    if (cVar2 == 0)
    {
        cVar2 = gFE11Database->pJob[this->jid].unk_4c;
    }

    this->unk_23 = arg1;

    if (arg1 == 0)
    {
        arg1 = gFE11Database->pJob[this->jid].unk_4c;
    }

    this->timer = IntSys_Div(this->timer * arg1, cVar2);

    return;
}

void MovingMapSprite::Free(void)
{
    s32 i;

    for (i = 0; i < 6; i++)
    {
        if (this->frames[i] != NULL)
        {
            gHeap.Free(this->frames[i]);
            this->frames[i] = NULL;
        }
    }

    return;
}
