#include "global.h"

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "hardware.hpp"
#include "map.hpp"

#include <new>

#include "proc_ex.hpp"

class UnitFlash : public ProcEx
{
public:
    /* 38 */ u32 unk_38;
    /* 3C */ u16 * unk_3c;
    /* 40 */ u16 * unk_40;
    /* 44 */ u32 unk_44;
    /* 48 */ s32 unk_48;
    /* 4C */ u16 unk_4c;

    UnitFlash(s32 duration, s32 arg1, s32 jid, s32 arg3, s32 arg4)
    {
        func_0203e220(jid, 0);
        this->unk_3c = static_cast<u16 *>(gHeap.Alloc(0x40));
        func_020116a0("palette", this->unk_3c, 0x40, arg3 * 0x40);
        this->unk_40 = static_cast<u16 *>(gHeap.Alloc(0x40));
        this->unk_38 = arg4;
        this->unk_48 = duration;
        this->unk_4c = arg1; // colour?
        this->unk_44 = 0;

        if (duration == 0)
        {
            Proc_End(this);
        }
    }

    // #func_0203fa1c
    virtual void Loop()
    {
        s32 lerp;
        s32 timer;
        s32 i;
        s32 max;

        timer = ++this->unk_44;
        max = this->unk_48 >> 1;

        if (timer < max)
        {
            lerp = Interpolate(0, 0, 0x10, timer, max);
        }
        else
        {
            lerp = Interpolate(0, 0x10, 0, timer - max, this->unk_48 - max);
        }

        for (i = 0; i < 0x20; i++)
        {
            this->unk_40[i] = func_0202025c(this->unk_3c[i], this->unk_4c, 0x10 - lerp, lerp);
        }

        func_020205a4(this->unk_40, this->unk_38, 0x40, (this->unk_44 == this->unk_48) & 0xff);

        if (this->unk_44 == this->unk_48)
        {
            Proc_Break(this, 0);
        }

        return;
    }

    // #func_0203f954 - d0
    // #func_0203f9bc - d1
    virtual ~UnitFlash()
    {
        if (this->unk_44 == this->unk_48)
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
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;

    IdleMapSprite(); // func_0203e2c8
};

class IdleMapSpriteMgr
{
public:
    IdleMapSprite * unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    u64 unk_14;
    u64 unk_1c;

    IdleMapSpriteMgr(s32, s32, s32); // func_0203e2dc
    ~IdleMapSpriteMgr(); // func_0203e334
};

struct MovingMapSprite
{
    void * unk_00[6];
    u32 unk_18;
    u32 unk_1c;
    /* 20 */ u16 jid;
    u8 unk_22;
    u8 unk_23;
    s8 unk_24;
    s8 unk_25;
    s8 unk_26;
    s8 unk_27;
    u32 unk_28; // clock

    MovingMapSprite(s32, s32, s32, s32); // func_0203ef6c
    ~MovingMapSprite(); // func_0203f01c
};

#define GFX_FIFO_POLYGONS_BEGIN *(vu32 *)(0x04000500)
#define GFX_FIFO_POLYGONS_END *(vu32 *)(0x04000504)
#define GFX_FIFO_VERTEX_TEXCOORD *(vu32 *)(0x04000488)
#define GFX_FIFO_VERTEX_16 *(vu32 *)(0x0400048c)
#define GFX_FIFO_VERTEX_XY *(vu32 *)(0x04000494)

extern vu32 data_027e1264;

extern const u8 data_020c515c[];

extern u16 data_027e0028[];

EC void func_0203f914(MovingMapSprite *);

EC void func_0203e220(s32 jid, BOOL param_2)
{
    struct JobData * job;

    if (param_2 == 0)
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

EC s32 func_0203e274(void)
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

EC BOOL func_0203e2a0(IdleMapSprite * self)
{
    return self->unk_00 != -1;
}

EC void func_0203e2b8(IdleMapSprite * self, u32 param_2, u32 param_3, s32 param_4)
{
    self->unk_00 = param_2;
    self->unk_04 = param_3;
    self->unk_06 = param_4;
    return;
}

// func_0203e2c8
IdleMapSprite::IdleMapSprite(void)
{
    this->unk_00 = -1;
    this->unk_04 = -1;
}

// func_0203e2dc
IdleMapSpriteMgr::IdleMapSpriteMgr(s32 count, s32 param_3, s32 param_4)
{
    this->unk_00 = new IdleMapSprite[count];
    this->unk_04 = param_3;
    this->unk_08 = param_4;
    this->unk_10 = count;
    this->unk_14 = 0;
    this->unk_1c = 0;
}

// func_0203e334
IdleMapSpriteMgr::~IdleMapSpriteMgr()
{
    delete[] this->unk_00;
}

EC IdleMapSprite * func_0203e34c(IdleMapSpriteMgr * self, s32 index)
{
    return self->unk_00 + index;
}

EC s32 func_0203e358(IdleMapSpriteMgr * self, s32 size)
{
    s32 i;
    s32 numBlocks;

    numBlocks = IntSys_Div(size, 0x1000) + (func_02020874(size, 0x1000) != 0 ? 1 : 0);

    for (i = 0; i < 0x40; i++)
    {
        s32 j;

        if (self->unk_14 & (1ull << i))
        {
            continue;
        }

        for (j = i; j < i + numBlocks; j++)
        {
            if (j == 0x40)
            {
                break;
            }

            if (self->unk_14 & (1ull << j))
            {
                break;
            }
        }

        if (j == i + numBlocks)
        {
            for (j = i; j < i + numBlocks; j++)
            {
                self->unk_14 |= (1ull << j);
            }

            return self->unk_04 + (i * 0x1000);
        }
    }

    return 0;
}

EC s32 func_0203e498(IdleMapSpriteMgr * self, s32 size)
{
    s32 i;
    s32 numBlocks;

    numBlocks = IntSys_Div(size, 0x40) + (func_02020874(size, 0x40) != 0 ? 1 : 0);

    for (i = 0; i < 0x40; i++)
    {
        s32 j;

        if (self->unk_1c & (1ull << i))
        {
            continue;
        }

        for (j = i; j < i + numBlocks; j++)
        {
            if (j == 0x40)
            {
                break;
            }

            if (self->unk_1c & (1ull << j))
            {
                break;
            }
        }

        if (j == i + numBlocks)
        {
            for (j = i; j < i + numBlocks; j++)
            {
                self->unk_1c |= (1ull << j);
            }

            return self->unk_08 + (i * 0x40);
        }
    }

    return 0;
}

EC void func_0203e5d8(IdleMapSpriteMgr * self, s32 addr, s32 size)
{
    s32 i;
    s32 start;
    s32 numBlocks;

    start = IntSys_Div(addr - self->unk_04, 0x1000);
    numBlocks = IntSys_Div(size, 0x1000) + (func_02020874(size, 0x1000) != 0 ? 1 : 0);

    for (i = start; i < start + numBlocks; i++)
    {
        self->unk_14 &= ~(1ull << i);
    }

    return;
}

EC void func_0203e680(IdleMapSpriteMgr * self, s32 addr, s32 size)
{
    s32 i;
    s32 start;
    s32 numBlocks;

    start = IntSys_Div(addr - self->unk_08, 0x40);
    numBlocks = IntSys_Div(size, 0x40) + (func_02020874(size, 0x40) != 0 ? 1 : 0);

    for (i = start; i < start + numBlocks; i++)
    {
        self->unk_1c &= ~(1ull << i);
    }

    return;
}

EC BOOL func_0203e728(IdleMapSpriteMgr * self, s32 jid, s32 param_3, s32 param_4, u8 param_5)
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

    IdleMapSprite * handle = func_0203e34c(self, jid);

    if ((param_5 == 0) && (func_0203e2a0(handle)))
    {
        return FALSE;
    }

    func_0203e220(jid, 0);

    totalSize = 0;
    func_020b6c98(str, "idle");
    len = func_020b6de0(str);

    for (i = 0, it = str + len; i < 4; i++)
    {
        it[0] = IntSys_Div(i, 10) + '0';
        it[1] = func_02020874(i, 10) + '0';
        it[2] = '\0';

        filePtr[i] = func_02011920(str, 0);
        size[i] = gHeap.SizeOf(filePtr[i]);
        totalSize += size[i];
    }

    if (param_5 == 0)
    {
        imgDst[0] = func_0203e358(self, totalSize);
    }
    else
    {
        imgDst[0] = handle->unk_00;
    }

    for (i = 1; i < 4; i++)
    {
        imgDst[i] = imgDst[i - 1] + size[i - 1];
    }

    if (param_4 != 0)
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

    if (param_5 == 0)
    {
        palDst = func_0203e498(self, palSize);
    }
    else
    {
        palDst = handle->unk_04;
    }

    if (param_4 != 0)
    {
        LoadTexturePalette((u16 *)filePtr[0], palDst, palSize);
        gHeap.Free(filePtr[0]);
    }
    else
    {
        func_020205a4((u16 *)filePtr[0], palDst, palSize, 1);
    }

    func_0203e2b8(handle, imgDst[0], palDst, totalSize);

    return TRUE;
}

EC void func_0203e988(IdleMapSpriteMgr * self, s32 param_2)
{
    s32 imgAddr;
    s32 palAddr;
    s32 imgSize;

    IdleMapSprite * handle = func_0203e34c(self, param_2);

    imgSize = handle->unk_06;
    imgAddr = handle->unk_00;
    palAddr = handle->unk_04;

    func_0203e2b8(handle, -1, -1, 0);

    func_0203e5d8(self, imgAddr, imgSize);
    func_0203e680(self, palAddr, 0x80);

    return;
}

EC s32 func_0203e9d4(s32 jid, s32 param_2, char * param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7)
{
    char str[12];
    char * it;
    void * uVar3;
    s32 len;
    s32 iVar4;
    s32 iVar5;
    s32 end;
    s32 i;

    func_0203e220(jid, 0);

    iVar5 = 0;

    func_020b6c98(str, param_3);
    len = func_020b6de0(str);

    end = param_4 + param_5;

    for (i = param_4, it = str + len; i < end; i++)
    {
        it[0] = IntSys_Div(i, 10) + '0';
        it[1] = func_02020874(i, 10) + '0';
        it[2] = '\0';

        uVar3 = func_02011920(str, 0);
        iVar4 = gHeap.SizeOf(uVar3);

        if (param_7 != 0)
        {
            LoadTextureImage(uVar3, param_6, iVar4);
            gHeap.Free(uVar3);
        }
        else
        {
            func_02020488(uVar3, param_6, iVar4, 1);
        }

        param_6 += iVar4;
        iVar5 += iVar4;
    }

    return iVar5;
}

EC s32 func_0203eacc(s32 param_1, s32 param_2, s32 palDst, s32 param_4)
{
    u16 * palSrc;

    if (param_2 >= 2)
    {
        param_2 = 0;
    }

    func_0203e220(param_1, 0);

    palSrc = static_cast<u16 *>(gHeap.Alloc(0x40));

    func_020116a0("palette", palSrc, 0x40, param_2 * 0x40);

    if (param_4 != 0)
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
    func_0203e220(jid, 1);
}

EC void func_0203eb60(s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    if (param_4 != 0)
    {
        func_0203e220(param_1, 1);
    }

    func_0201177c("idle", param_3);

    return;
}

EC void func_0203eb8c(s32 jid, s32 param_2, s32 param_3, s32 param_4)
{
    void * uVar1;

    if (param_4 != 0)
    {
        func_0203e220(jid, 1);
    }

    uVar1 = func_02011920("idle", 0);
    func_020203e0(uVar1, param_3, gHeap.SizeOf(uVar1), 1);

    return;
}

EC void func_0203ebe0(s32 jid, s32 param_2, void * param_3, s32 param_4)
{
    if (param_4 != 0)
    {
        func_0203e220(jid, 1);
    }

    func_02011ee4(func_02011d78, "idle", param_3, 0, 0);

    return;
}

EC void func_0203ec24(s32 jid, s32 param_2, u16 * param_3, s32 param_4)
{
    if (param_4 != 0)
    {
        func_0203e220(jid, 1);
    }

    if (param_2 >= 2)
    {
        param_2 = 0;
    }

    func_020116a0("palette", param_3, 0xc0, param_2 * 0xc0);

    return;
}

EC void func_0203ec64(s32 jid, s32 param_2, u16 * param_3, s32 param_4)
{
    if (param_4 != 0)
    {
        func_0203e220(jid, 1);
    }

    if (param_2 >= 2)
    {
        param_2 = 0;
    }

    func_02011ee4(func_02011d5c, "palette", param_3, 0xc0, param_2 * 0xc0);

    return;
}

EC void func_0203ecb0(IdleMapSpriteMgr * self)
{
    s32 i;

    for (i = 0; i < self->unk_10; i++)
    {
        func_0203e2b8(func_0203e34c(self, i), -1, -1, 0);
    }

    self->unk_14 = 0;
    self->unk_1c = 0;

    return;
}

EC void func_0203ed14(IdleMapSpriteMgr * self, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 x = arg3;
    s32 y = arg4;

    IdleMapSprite * handle = func_0203e34c(self, arg1);

    if (func_0203e2a0(handle) == 0)
    {
        return;
    }

    x = x + ((func_0203e274() - 0x20) >> 1);
    y = y + (func_0203e274() - 0x20);

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
        1, 0x20, 0x20, (u32)(handle->unk_00 + (self->unk_0c * 0x400)), (u32)(handle->unk_04 + (arg2 * 0x40)), 0, 0);
    func_0206d2ac(x, y, arg5, 0x20, 0x20, arg2 & 1, 0);

    return;
}

EC void func_0203ede8(s32 jid, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, u32 param_7)
{
    s32 cVar1 = gFE11Database->pJob[jid].unk_54;

    if (param_2 >= 2)
    {
        param_2 = 0;
    }

    func_0206cf30(1, 0x20, 0x20, param_6, param_7, 0, 0);
    func_0206d2ac(param_3, param_4 + cVar1, param_5, 0x20, 0x20, param_2 & 1, 0);

    return;
}

EC void func_0203ee78(s32 jid, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7)
{
    int uVar1;
    int iVar2;
    int uVar3;
    int uVar4;

    uVar3 = 0;
    uVar4 = gFE11Database->pJob[jid].unk_54 + param_4;

    if (param_2 >= 2)
    {
        param_2 = 0;
    }

    if ((param_2 & 1) != 0)
    {
        uVar3 = 0x1000;
    }

    uVar1 = IntSys_Div(data_027e1264, 10);
    iVar2 = func_02020874(uVar1, 6);

    func_01ffc404(
        (param_3 & 0x1ff) | uVar3, (uVar4 & 0xff) | 0x2000,
        (param_5 + data_020c515c[iVar2] * 0x20) >> (gpActiveScreenSt->dispIo->dispcnt.unk_02_bit_0 & 0x3ff) |
            (param_6 << 0xc),
        data_027e0028, param_7);

    return;
}

// #func_0203ef6c
MovingMapSprite::MovingMapSprite(s32 jid, s32 param_3, s32 param_4, s32 param_5)
{
    s32 i;
    u16 * buf;

    if (param_3 >= 2)
    {
        param_3 = 0;
    }

    this->jid = jid;
    this->unk_22 = param_3;
    this->unk_18 = param_4;
    this->unk_1c = param_5;
    this->unk_23 = 0;
    this->unk_26 = -1;
    this->unk_27 = -1;
    this->unk_25 = -1;
    this->unk_28 = 0;

    func_0203e220(jid, 0);

    buf = static_cast<u16 *>(gHeap.Alloc(0x40));
    func_020116a0("palette", buf, 0x40, param_3 * 0x40);
    func_020205a4(buf, param_5, 0x40, 1);

    for (i = 0; i < 6; i++)
    {
        this->unk_00[i] = NULL;
    }
}

// func_0203f01c
MovingMapSprite::~MovingMapSprite(void)
{
    func_0203f914(this);
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

EC s32 func_0203f2e8(struct MovingMapSprite * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    char str[32];
    char * it;
    struct JobData * pJob;
    s32 len;

    s32 x = arg1;
    s32 y = arg2;

    s32 ret = 0;

    if (arg5 != -1)
    {
        arg0->unk_24 = arg5;
    }

    if (arg6 != -1)
    {
        arg0->unk_25 = arg6;
    }
    else
    {
        arg0->unk_25 = func_0203f6d0(arg0->jid, arg0->unk_24, arg0->unk_28, arg0->unk_23, 0);
    }

    if ((arg0->unk_24 != arg0->unk_26) || (arg0->unk_25 != arg0->unk_27))
    {
        if (arg0->unk_24 != arg0->unk_26)
        {
            func_0203f914(arg0);
        }

        if (arg0->unk_25 != arg0->unk_27)
        {
            ret = 1;
        }

        if (arg0->unk_00[arg0->unk_25] == NULL)
        {
            str[0] = '/';
            str[1] = '3';
            str[2] = '/';

            pJob = gFE11Database->pJob + arg0->jid;
            it = str;
            func_020b6c98(it + 3, pJob->unk_00 + 4);

            it = str + 3;
            it[func_020b6de0(pJob->unk_00 + 4)] = '/';

            if (arg0->unk_22 & 1)
            {
                func_020b6c98(it + 1, func_0203f880(func_0203f864(arg0->unk_24)));
            }
            else
            {
                func_020b6c98(it + 1, func_0203f880(arg0->unk_24));
            }

            len = func_020b6de0(str);
            it = str + len;

            it[0] = IntSys_Div(arg0->unk_25, 10) + '0';
            it[1] = func_02020874(arg0->unk_25, 10) + '0';
            it[2] = '\0';

            arg0->unk_00[arg0->unk_25] = func_02011920(str, 0);
        }

        func_02020488(arg0->unk_00[arg0->unk_25], arg0->unk_18, gHeap.SizeOf(arg0->unk_00[arg0->unk_25]), 0);
        arg0->unk_27 = arg0->unk_25;
        arg0->unk_26 = arg0->unk_24;
    }

    x = x + ((func_0203e274() - 0x20) >> 1);
    y = y + (func_0203e274() - 0x20) + arg0->unk_24 + gFE11Database->pJob[arg0->jid].unk_54;

    if (((x + 0x20) < 0) || ((y + 0x20) < 0) || (x >= 0x100) || (y >= 0xC0))
    {
        return ret;
    }

    func_0206cf30(1, 0x20, 0x20, arg0->unk_18, arg0->unk_1c, 0, 0);
    func_0203f2a0(x, y, arg3, arg4, 0x20, 0x20, arg0->unk_22 & 1, 0);

    return ret;
}

EC void func_0203f580(MovingMapSprite * param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    func_0203f2e8(param_1, param_2, param_3, param_4, param_4, param_5, param_6);
    return;
}

EC void func_0203f5a4(MovingMapSprite * param_1, s32 param_2, s32 param_3)
{
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_B))
        UnitFlash(param_2, param_3, param_1->jid, param_1->unk_22, param_1->unk_1c);
}

EC s32 func_0203f650(s32 jid, s32 param_2)
{
    switch (param_2)
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

EC s32 func_0203f6a0(MovingMapSprite * self)
{
    s32 iVar1 = func_0203f650(self->jid, self->unk_24);

    if (iVar1 != 0)
    {
        return IntSys_Div(self->unk_28 & ~0x80000000, iVar1);
    }

    return 0;
}

EC s32 func_0203f6d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4)
{
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_r3;

    switch (arg1)
    {
        case 0:
            if (arg4 != 0)
            {
                var_r3 = func_02020874(IntSys_Div(arg2, 10), 6);
                return data_020c515c[var_r3];
            }
            else
            {
                var_r3 = func_02020874(IntSys_Div(data_027e1264, 10), 6);
                return data_020c515c[var_r3];
            }

        case 1:
            var_r3 = func_02020874(IntSys_Div(arg2, 10), 6);
            return data_020c515c[var_r3];

        case 6:
            if (arg3 == 0)
            {
                arg3 = gFE11Database->pJob[arg0].unk_4c;
            }

            temp_r0 = IntSys_Div(arg2 & ~0x80000000, arg3);

            if (arg4 != 0)
            {
                temp_r0_2 = func_02020874(temp_r0, 0xC);

                if (temp_r0_2 == 0xB)
                {
                    return 5;
                }

                if (temp_r0_2 < 2)
                {
                    return temp_r0_2;
                }

                return func_02020874(temp_r0_2 - 2, 3) + 2;
            }

            if (temp_r0 < 2)
            {
                return temp_r0;
            }

            return func_02020874(temp_r0 - 2, 3) + 2;

        default:
            if (arg3 == 0)
            {
                arg3 = gFE11Database->pJob[arg0].unk_4c;
            }

            return func_02020874(IntSys_Div(arg2 & ~0x80000000, arg3), 6);
    }
}

EC void func_0203f824(MovingMapSprite * self, s32 param_2)
{
    if (param_2 == self->jid)
    {
        return;
    }

    self->jid = param_2;
    self->unk_27 = -1;

    func_0203eacc(param_2, self->unk_22, self->unk_1c, 0);

    func_0203f914(self);

    return;
}

EC s32 func_0203f864(s32 param_1)
{
    switch (param_1)
    {
        case 2:
            return 3;

        case 3:
            return 2;
    }
}

// clang-format off

char * data_020d4cc0[] =
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

EC char * func_0203f880(s32 param_1)
{
    return data_020d4cc0[param_1];
}

// clang-format off

u8 data_020d4c88[] =
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

EC u8 func_0203f890(s32 param_1)
{
    return data_020d4c88[param_1];
}

EC void func_0203f8a0(MovingMapSprite * param_1, s32 param_2)
{
    s32 cVar2 = param_1->unk_23;

    if (cVar2 == 0)
    {
        cVar2 = gFE11Database->pJob[param_1->jid].unk_4c;
    }

    param_1->unk_23 = param_2;

    if (param_2 == 0)
    {
        param_2 = gFE11Database->pJob[param_1->jid].unk_4c;
    }

    param_1->unk_28 = IntSys_Div(param_1->unk_28 * param_2, cVar2);

    return;
}

EC void func_0203f914(MovingMapSprite * self)
{
    s32 i;

    for (i = 0; i < 6; i++)
    {
        if (self->unk_00[i] != NULL)
        {
            gHeap.Free(self->unk_00[i]);
            self->unk_00[i] = NULL;
        }
    }

    return;
}
