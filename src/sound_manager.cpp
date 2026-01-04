#include "global.h"

#include <new>

#include "hashtable.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"

#include "unknown_funcs.h"
#include "unknown_types.hpp"

EC void func_02097ff8(void);
EC void func_02015ec0(u32);

EC void func_02015bd0(void)
{
    data_020efcc8 = new UnkStruct_020efcc8;
    data_020efcc8->unk_a0 = 1;
    data_020efcc8->unk_a1 = 0x7f;
    data_020efcc8->unk_9c = 0;
    data_020efcc8->unk_94 = NULL;
    data_020efcc8->unk_98 = NULL;

    func_02097ff8();
    func_02015ec0(0);

    data_020efcc8->unk_a4 = new SoundHandle;
    data_020efcc8->unk_a4->vfunc_24();

    data_020efcc8->unk_a8 = new SoundHandle;
    data_020efcc8->unk_a8->vfunc_24();

    data_020efcc8->unk_ac = new SoundStrmHandle;
    data_020efcc8->unk_ac->vfunc_24();

    data_020efcc8->unk_b0 = new SoundSeHandle;
    data_020efcc8->unk_b0->vfunc_24();

    data_020efcc8->unk_b4 = new SoundSeHandle;
    data_020efcc8->unk_b4->vfunc_24();

    return;
}

EC void func_02015f58(void);
EC void * func_0209a1a8(void *, s32);

extern u8 data_020f0ce0[];
extern u8 data_0216dce0[];

EC void func_02015dc8(u32 param_1)
{
    func_02015f58();

    if (param_1 != 0)
    {
        data_020efcc8->unk_94 = func_0209a1a8(data_020f0ce0, 0xa0000);
        return;
    }

    data_020efcc8->unk_94 = func_0209a1a8(data_020f0ce0, 0x7d000);
    data_020efcc8->unk_98 = func_0209a1a8(data_0216dce0, 0x23000);

    return;
}

EC void func_0209a218(void *);

EC void func_02015e38(void)
{
    if (data_020efcc8->unk_94 != NULL)
    {
        func_0209a218(data_020efcc8->unk_94);
    }

    if (data_020efcc8->unk_98 != NULL)
    {
        func_0209a218(data_020efcc8->unk_98);
    }

    data_020efcc8->unk_94 = NULL;
    data_020efcc8->unk_98 = NULL;

    return;
}

EC BOOL func_0209a520(s32, void *);

EC void func_02015e8c(void)
{
    func_0209a520(0, data_020efcc8->unk_94);
    func_0209a520(1, data_020efcc8->unk_94);
    return;
}

EC void func_02015dc8(u32);
EC BOOL func_0201160c(char *);
EC void func_0209a170(s32);
EC void func_02099990(void *, char *, void *, s32);
EC void func_0209af64(void *);
EC u32 func_0209a354(void *);
EC void func_0209b288(s32, void *);

EC void func_02015ec0(u32 param_1)
{
    func_02015dc8(param_1);

    if (!func_0201160c("/sound/fe11_sound_all.sdat"))
    {
        data_020efcc8->unk_a0 = FALSE;
        return;
    }

    func_02099990(data_020efcc8, "/sound/fe11_sound_all.sdat", data_020efcc8->unk_94, 0);
    func_0209a170(0x1000);
    func_0209af64(data_020efcc8->unk_94);
    func_0209b288(10, data_020efcc8->unk_94);
    func_02015e8c();
    func_0209a354(data_020efcc8->unk_94);

    return;
}

EC void func_02015f58(void)
{
    func_02015e38();
    return;
}

struct UnkStruct_020cdc5c
{
    s32 unk_00;
    char * unk_04;
};

extern struct UnkStruct_020cdc5c data_020cdc5c[];

EC void func_02015f64(void)
{
    int i;

    for (i = 0; data_020cdc5c[i].unk_04 != NULL; i++)
    {
        HashTable::Put(data_020cdc5c[i].unk_04, &data_020cdc5c[i]);
    }

    return;
}

EC void func_02070570(s32);
EC void func_0207058c(s32);
EC void func_02098080(void);

struct UnkStruct_020efcd4
{
    STRUCT_PAD(0x0000, 0x1000);
    u8 unk_1000[0xc0];
    UnkStruct_020efcd4 * unk_10c0;
    SoundHandle * unk_10c4;
    u32 unk_10c8;
    u32 unk_10cc;
    u32 unk_10d0;
};

extern UnkStruct_020efcd4 * data_020efcd0;
extern UnkStruct_020efcd4 * data_020efcd4;

EC void func_02015fb4(void)
{
    if (data_020efcc8->unk_a0 != NULL)
    {
        func_02070570(4);

        if ((data_020efcd4 != NULL) ? TRUE : FALSE)
        {
            func_02098080();
        }

        func_0207058c(4);
    }

    return;
}

extern void * data_0219e298;
EC UnkStruct_020efcd4 * func_020a375c(void *);

EC void func_02016004(void)
{
    UnkStruct_020efcd4 * iVar1 = func_020a375c(data_0219e298);

    if (iVar1 == data_020efcd4)
    {
        data_020efcd0 = NULL;
        data_020efcd4 = NULL;
    }
    else
    {
        data_020efcd0 = iVar1->unk_10c0;
        func_020a341c(iVar1->unk_10c0->unk_1000);
    }

    delete iVar1;

    return;
}

EC void func_02016064(s32 arg_0)
{
    if (data_020efcc8->unk_98 == NULL)
    {
        return;
    }

    func_0209a520(arg_0, data_020efcc8->unk_98);
    func_0209a354(data_020efcc8->unk_98);

    return;
}

EC void func_020a3320(void *);

EC void func_02016098(s32 param_1)
{
    if (data_020efcd4 != 0)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    func_02016064(param_1);

    return;
}

EC void func_020a3080(void *, void *, void *, void *, s32, s32);
EC void func_020a3754(void *, void *);
EC void func_020a374c(void *, void (*)(void));
EC void func_020a341c(void *);

EC void func_02016188(UnkStruct_020efcd4 *);

EC void func_020160d4(u32 param_1)
{
    UnkStruct_020efcd4 * iVar1 = new UnkStruct_020efcd4();

    iVar1->unk_10c0 = 0;
    iVar1->unk_10c4 = NULL;
    iVar1->unk_10c8 = param_1;
    iVar1->unk_10cc = 0;
    iVar1->unk_10d0 = 0;

    func_020a3080(iVar1->unk_1000, (void *)func_02016188, iVar1, iVar1->unk_1000, 0x1000, 0x11);
    func_020a3754(iVar1->unk_1000, iVar1);
    func_020a374c(iVar1->unk_1000, func_02016004);

    if (data_020efcd4 == NULL)
    {
        data_020efcd0 = iVar1;
        data_020efcd4 = iVar1;
        func_020a341c(iVar1->unk_1000);
        return;
    }

    data_020efcd4->unk_10c0 = iVar1;
    data_020efcd4 = iVar1;

    return;
}

EC void func_02016188(UnkStruct_020efcd4 * param_1)
{
    func_02016064(param_1->unk_10c8);
    return;
}

EC u32 func_0201619c(char * param_1)
{
    u32 ret = (u32)HashTable::Get1(param_1);

    if (ret == NULL)
    {
        return -1;
    }

    return ret;
}

EC s32 func_0209a474(void *);
EC void * func_0209a3a0(void *, u32);

EC u32 func_020161b4(void)
{
    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (data_020efcc8->unk_98 != NULL)
    {
        return func_0209a474(data_020efcc8->unk_98);
    }

    return 0;
}

EC void func_02016200(u32 param_1)
{
    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (data_020efcc8->unk_98 != NULL)
    {
        func_0209a3a0(data_020efcc8->unk_98, param_1);
    }

    return;
}

EC BOOL func_02016304(s16);
EC BOOL func_020162ec(s16, s32);
EC BOOL func_0209b56c(void *);

EC BOOL func_02016250(s16 param_1)
{
    if (param_1 != 0x7fff)
    {
        if ((func_0209b56c(&data_020efcc8->unk_ac->unk_04) != 0) && (param_1 == data_020efcc8->unk_ac->unk_08))
        {
            return 1;
        }

        return 0;
    }

    if ((param_1 & 0xff) != 0)
    {
        return func_020162ec(param_1, -1);
    }

    return func_02016304(param_1);
}

EC BOOL func_020983d4(s32, s32);

EC BOOL func_020162ec(s16 arg_0, s32 arg_1)
{
    return func_020983d4(arg_0, arg_1) != 0;
}

EC BOOL func_02098380(s32);

EC BOOL func_02016304(s16 arg_0)
{
    return func_02098380(arg_0) != 0;
}

extern u32 data_020efce0;
EC void func_0209ca20(void *, u32, u32);
EC void func_0209ca74(void);
EC void func_0209ca9c(u32);

EC void func_0201631c(u32 param_1)
{
    if (data_020efcc8->unk_a0 != NULL && param_1 != data_020efcc8->unk_9c)
    {
        if (data_020efcd4 != NULL ? TRUE : FALSE)
        {
            func_020a3320(data_020efcd4->unk_1000);
        }

        if (data_020efcc8->unk_9c == 0)
        {
            func_0209ca20(&data_020efce0, 0x1000, param_1);
        }
        else if (param_1 == 0)
        {
            func_0209ca74();
        }
        else
        {
            func_0209ca9c(param_1);
        }

        data_020efcc8->unk_9c = param_1;
    }

    return;
}

// TODO: Is this an inline?
EC BOOL func_020163c0(void)
{
    return data_020efcd4 != NULL;
}

EC void func_020163dc(SoundWaitTo * param_1)
{
    param_1->Loop();
    return;
}

EC void func_020163f0(SoundWaitTo * param_1)
{
    if (param_1->unk_3c->vfunc_58())
    {
        return;
    }

    param_1->unk_38->unk_18 = 0;

    switch (param_1->unk_40)
    {
        case 0:
            param_1->unk_38->vfunc_30(param_1->unk_44, param_1->unk_48, 0);
            break;

        case 1:
            param_1->unk_38->vfunc_4c(param_1->unk_48);
            break;

        case 2:
            param_1->unk_38->vfunc_38(0);
            break;

        case 3:
            break;
    }

    Proc_End(param_1);

    return;
}

EC void func_020164ac(SoundWaitTo *);

extern struct ProcCmd data_020cbfd8[];

EC void func_02016490(void)
{
    Proc_ForEach(data_020cbfd8, (ProcFunc)func_020164ac);
}

EC void func_020164ac(SoundWaitTo * param_1)
{
    if (param_1->unk_38->unk_18 == 0)
    {
        return;
    }

    param_1->Loop();

    return;
}

EC void func_02098354(void *);

// func_020164d0
void SoundHandle::vfunc_24(void)
{
    func_02098354(&this->unk_04);

    this->unk_08 = -1;
    this->unk_0c = 0;

    return;
}

EC void func_0209a564(u32, u32, void *);
EC BOOL func_0209b000(void *, u32);
EC void func_020984c8(void *, u16, u32);

// func_020164f4
void SoundHandle::vfunc_00(u32 param_2, u32 param_3, u32 param_4)
{
    this->unk_0d = func_0209a474(data_020efcc8->unk_94);
    func_0209a564(param_2, 3, data_020efcc8->unk_94);
    this->unk_0e = func_0209a354(data_020efcc8->unk_94);
    func_0209a564(param_2, 4, data_020efcc8->unk_94);
    this->unk_0f = func_0209a354(data_020efcc8->unk_94);

    if ((func_0209b000(&this->unk_04, param_2) & 0xFF) && param_4 != 0)
    {
        func_020984c8(&this->unk_04, 0xffff, param_4);
    }

    if (param_3 != 0)
    {
        this->vfunc_14(0, 0);
        this->vfunc_14(this->unk_10, param_3);
        return;
    }

    this->vfunc_14(this->unk_10, 0);

    return;
}

// func_020165f4
void SoundHandle::vfunc_18(u32 param_2, u32 param_3, u32 param_4)
{
    u32 uVar2;

    if (this->unk_0c != 1 || param_2 != this->unk_08)
    {
        if (this->unk_18 != NULL)
        {
            uVar2 = func_020a4a38();
            Proc_End(this->unk_18);
            func_020a4a4c(uVar2);
        }
        if (this->unk_0c != 0)
        {
            this->vfunc_1c();
        }

        this->unk_08 = param_2;
        this->unk_0c = 1;
        this->vfunc_00(param_2, param_3, param_4);
    }

    return;
}

EC BOOL func_0209b048(void *, u32, u32);

// func_02016688
void SoundHandle::vfunc_04(u32 param_2, u32 param_3, u32 param_4, u32 param_5)
{
    if ((func_0209b048(&this->unk_04, param_2, param_3) & 0xFF) && param_5 != 0)
    {
        func_020984c8(&this->unk_04, 0xffff, param_5);
    }

    if (param_4 != 0)
    {
        this->vfunc_14(0, 0);
        this->vfunc_14(this->unk_10, param_4);
    }
    else
    {
        this->vfunc_14(this->unk_10, 0);
    }

    return;
}

extern struct UnkStruct_02196f24 * data_02196f24;

// func_0201670c
void SoundHandle::vfunc_28(u32 param_2, u32 param_3, u32 param_4)
{
    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (!data_02196f24->enableBgm)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (!this->vfunc_58() && this->unk_0c == 1 && param_2 == this->unk_08)
    {
        func_02070570(4);

        if (this->unk_18 != NULL)
        {
            Proc_End(this->unk_18);
        }

        if (this->unk_0c != 0)
        {
            this->vfunc_38(0);
        }

        this->vfunc_00(param_2, param_3, param_4);

        this->unk_08 = param_2;
        this->unk_0c = 1;

        func_0207058c(4);
    }

    return;
}

EC u32 func_0201619c(char *);

// func_02016804
void SoundHandle::vfunc_2c(char * param_2, u32 param_3, u32 param_4)
{
    u32 iVar1 = func_0201619c(param_2);

    if (iVar1 == -1)
    {
        return;
    }

    this->vfunc_28(iVar1, param_3, param_4);

    return;
}

EC void func_020169bc(UnkStruct_020efcd4 *);

// func_02016848
void SoundHandle::vfunc_30(u32 param_2, u32 param_3, u32 param_4)
{
    UnkStruct_020efcd4 * iVar2;

    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (!data_02196f24->enableBgm)
    {
        return;
    }

    if (!this->vfunc_58() && this->unk_0c == 1 && param_2 == this->unk_08)
    {
        func_02070570(4);

        if (!(data_020efcd4 != NULL ? TRUE : FALSE))
        {
            if (this->unk_18 != NULL)
            {
                Proc_End(this->unk_18);
            }

            if (this->unk_0c != 0)
            {
                this->vfunc_38(0);
            }
        }

        iVar2 = new UnkStruct_020efcd4();

        iVar2->unk_10c0 = 0;
        iVar2->unk_10c4 = this;
        iVar2->unk_10c8 = param_2;
        iVar2->unk_10cc = param_3;
        iVar2->unk_10d0 = param_4;

        func_020a3080(iVar2->unk_1000, (void *)func_020169bc, iVar2, iVar2->unk_1000, 0x1000, 0x11);
        func_020a3754(iVar2->unk_1000, iVar2);
        func_020a374c(iVar2->unk_1000, func_02016004);

        if (data_020efcd4 == NULL)
        {
            data_020efcd0 = iVar2;
            data_020efcd4 = iVar2;
            func_020a341c(iVar2->unk_1000);
        }
        else
        {
            data_020efcd4->unk_10c0 = iVar2;
            data_020efcd4 = iVar2;
        }

        func_0207058c(4);
    }

    return;
}

EC void func_020169bc(UnkStruct_020efcd4 * param_1)
{
    param_1->unk_10c4->vfunc_18(param_1->unk_10c8, param_1->unk_10cc, param_1->unk_10d0);
    return;
}

// func_020169e4
void SoundHandle::vfunc_34(char * arg_0, u32 arg_1, u32 arg_2)
{
    s32 iVar1 = func_0201619c(arg_0);

    if (iVar1 == -1)
    {
        return;
    }

    this->vfunc_30(iVar1, arg_1, arg_2);

    return;
}

EC void func_02098334(void *, u32);

// func_02016a28
void SoundHandle::vfunc_08(void)
{
    func_02098334(&this->unk_04, 0);
    this->unk_08 = -1;
    return;
}

extern struct ProcCmd ProcScr_020ce750[];

// func_02016a48
void SoundHandle::vfunc_38(s32 param_2)
{
    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_18 != NULL)
    {
        this->unk_18->unk_40 = 2;
        this->unk_18->unk_44 = 0;
        this->unk_18->unk_48 = 0;
        return;
    }

    if (this->unk_0c == 0)
    {
        return;
    }

    if (this->unk_0c == 2)
    {
        param_2 = 0;
    }

    if (this->vfunc_58())
    {
        this->unk_14->unk_3c = 0;
        this->unk_14->unk_48 = -1;

        if (param_2 == 0)
        {
            Proc_End(this->unk_14);
            return;
        }

        if (param_2 < this->unk_14->unk_40)
        {
            this->unk_14->unk_40 = param_2;
            this->vfunc_14(0, param_2);
        }

        return;
    }

    new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) SoundFade(this, param_2, -1, 0);

    return;
}

// func_02016ba0
void SoundHandle::vfunc_1c(void)
{
    u32 uVar1;
    s32 iVar2;
    SoundFade * pSVar3;

    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (this->unk_18 != NULL)
    {
        uVar1 = func_020a4a38();
        Proc_End(this->unk_18);
        func_020a4a4c(uVar1);
    }

    if (this->unk_0c == 0)
    {
        return;
    }

    if (this->vfunc_58())
    {
        this->unk_14->unk_3c = 0;

        uVar1 = func_020a4a38();

        Proc_End(this->unk_14);
        Proc_ForEach(data_020cbfd8, (ProcFunc)func_020164ac);

        func_020a4a4c(uVar1);

        return;
    }

    uVar1 = func_020a4a38();
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) SoundFade(this, 0, -1, 0);
    func_020a4a4c(uVar1);

    return;
}

// func_02016cb8
void SoundHandle::vfunc_3c(s32 param_2, u32 param_3, u32 param_4)
{
    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_18 != NULL)
    {
        Proc_End(this->unk_18);
    }

    if (this->unk_0c == 0)
    {
        this->vfunc_30(param_3, param_4, 0);
        return;
    }

    if (this->vfunc_58())
    {
        this->unk_14->unk_3c = 0;
        this->unk_14->unk_48 = param_3;
        this->unk_14->unk_44 = param_4;

        if (param_2 == 0)
        {
            Proc_End(this->unk_14);
            return;
        }

        if (param_2 < this->unk_14->unk_40)
        {
            this->unk_14->unk_40 = param_2;
            this->vfunc_14(0, param_2);
        }
    }
    else
    {
        new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) SoundFade(this, param_2, param_3, param_4);
    }

    return;
}

// func_02016e18
void SoundHandle::vfunc_40(u32 param_2, char * param_3, u32 param_4)
{
    u32 iVar1 = func_0201619c(param_3);

    if (iVar1 != -1)
    {
        this->vfunc_3c(param_2, iVar1, param_4);
    }
    else
    {
        this->vfunc_38(param_2);
    }

    return;
}

EC void func_02098344(void *, u32);

// func_02016e70
void SoundHandle::vfunc_0c(void)
{
    func_02098344(&this->unk_04, 1);
    return;
}

// func_02016e84
void SoundHandle::vfunc_44(s32 param_2)
{
    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_18 != NULL)
    {
        if (this->unk_18->unk_40 <= 1 ? TRUE : FALSE)
        {
            this->unk_18->unk_40 = 3;
            this->unk_18->unk_44 = 0;
            this->unk_18->unk_48 = 0;
        }

        Proc_End(this->unk_18);
    }

    if (this->unk_0c != 1)
    {
        return;
    }

    if (this->vfunc_58())
    {
        if (this->unk_14->unk_3c != 0)
        {
            this->unk_14->unk_3c = 2;
        }

        if (param_2 == 0)
        {
            Proc_End(this->unk_14);
            return;
        }

        if (param_2 < this->unk_14->unk_40)
        {
            this->unk_14->unk_40 = param_2;
            this->vfunc_14(0, param_2);

            return;
        }
    }
    else
    {
        new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) SoundFade(this, param_2, -1, 0);
    }

    return;
}

// func_02016ff4
void SoundHandle::vfunc_10(u32 param_2)
{
    this->unk_0e = func_0209a474(data_020efcc8->unk_94);
    func_0209a564(this->unk_08, 4, data_020efcc8->unk_94);

    this->unk_0f = func_0209a354(data_020efcc8->unk_94);
    func_02098344(&this->unk_04, 0);

    this->unk_0c = 1;

    if (param_2 != 0)
    {
        this->vfunc_14(0, 0);
        this->vfunc_14(this->unk_10, param_2);
    }
    else
    {
        this->vfunc_14(this->unk_10, 0);
    }

    return;
}

// func_020170a8
void SoundHandle::vfunc_20(u32 param_2)
{
    u32 uVar1;

    if (this->unk_18 != NULL)
    {
        uVar1 = func_020a4a38();
        Proc_End(this->unk_18);
        func_020a4a4c(uVar1);
    }

    if (this->unk_0c == 2)
    {
        this->vfunc_10(param_2);
    }

    return;
}

// func_020170fc
void SoundHandle::vfunc_48(u32 param_2)
{
    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_18 != NULL)
    {
        Proc_End(this->unk_18);
    }

    if (this->unk_0c == 2)
    {
        this->vfunc_10(param_2);
    }

    return;
}

EC void func_02017258(UnkStruct_020efcd4 *);

// func_02017164
void SoundHandle::vfunc_4c(s32 param_2)
{
    UnkStruct_020efcd4 * iVar1;

    if (!(data_020efcd4 != NULL ? TRUE : FALSE))
    {
        if (this->unk_18 != NULL)
        {
            Proc_End(this->unk_18);
        }

        if (this->unk_0c != 2)
        {
            return;
        }
    }

    iVar1 = new UnkStruct_020efcd4();

    iVar1->unk_10c0 = 0;
    iVar1->unk_10c4 = NULL;
    iVar1->unk_10c8 = (u32)this;
    iVar1->unk_10cc = 0;
    iVar1->unk_10d0 = 0;

    func_020a3080(iVar1->unk_1000, (void *)func_02017258, iVar1, iVar1->unk_1000, 0x1000, 0x11);
    func_020a3754(iVar1->unk_1000, iVar1);
    func_020a374c(iVar1->unk_1000, func_02016004);

    if (data_020efcd4 == NULL)
    {
        data_020efcd0 = iVar1;
        data_020efcd4 = iVar1;
        func_020a341c(iVar1->unk_1000);
        return;
    }

    data_020efcd4->unk_10c0 = iVar1;
    data_020efcd4 = iVar1;

    return;
}

EC void func_02017258(UnkStruct_020efcd4 * param_1)
{
    param_1->unk_10c4->vfunc_20(param_1->unk_10cc);
    return;
}

// func_02017278
BOOL SoundHandle::vfunc_50(void)
{
    return this->unk_0c == 1;
}

// func_0201728c
BOOL SoundHandle::vfunc_54(void)
{
    return this->unk_0c == 2;
}

// func_020172a0
BOOL SoundHandle::vfunc_58(void)
{
    if (this->unk_14 != NULL)
    {
        return TRUE;
    }

    if ((this->unk_18 != NULL) && (this->unk_18->unk_40 == 2 ? TRUE : FALSE))
    {
        return TRUE;
    }

    return FALSE;
}

// func_020172e0
BOOL SoundHandle::vfunc_5c(void)
{
    if ((this->unk_14 != NULL) && (this->unk_14->unk_3c == 0 ? TRUE : FALSE))
    {
        return TRUE;
    }

    if ((this->unk_18 != NULL) && (this->unk_18->unk_40 == 2 ? TRUE : FALSE))
    {
        return TRUE;
    }

    return FALSE;
}

// func_02017338
BOOL SoundHandle::vfunc_60(void)
{
    UnkStruct_020efcd4 * iVar2;
    BOOL uVar1;

    if ((this->unk_14 != NULL) && (this->unk_14->unk_48 != -1 ? TRUE : FALSE))
    {
        return TRUE;
    }

    if ((this->unk_18 != NULL) && (this->unk_18->unk_40 <= 1 ? TRUE : FALSE))
    {
        return TRUE;
    }

    if (!(data_020efcd4 != NULL ? TRUE : FALSE))
    {
        uVar1 = FALSE;
    }
    else if (this == data_020efcd0->unk_10c4)
    {
        uVar1 = TRUE;
    }
    else
    {
        for (iVar2 = data_020efcd0; iVar2 != NULL; iVar2 = iVar2->unk_10c0)
        {
            if (iVar2->unk_10c4 == this)
            {
                uVar1 = TRUE;
                break;
            }
        }
    }

    return uVar1 ? TRUE : FALSE;
}

EC void func_0209845c(void *, u32, u32);

// func_02017408
void SoundHandle::vfunc_14(u32 arg_0, u32 arg_1)
{
    func_0209845c(&this->unk_04, arg_0, arg_1);
    return;
}

// func_02017418
void SoundHandle::vfunc_64(u32 param_2, u32 unused)
{
    this->unk_10 = param_2;

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_0c == 1)
    {
        if (!this->vfunc_58())
        {
            this->vfunc_14(this->unk_10, param_2);
        }
    }

    return;
}

// func_02017494
void SoundHandle::vfunc_68(u32 param_2)
{
    this->unk_10 = 0x7f;

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (this->unk_0c == 1)
    {
        if (!this->vfunc_58())
        {
            this->vfunc_14(this->unk_10, param_2);
        }
    }

    return;
}

// func_02017510
void SoundHandle::vfunc_6c(u32 param_2)
{
    this->unk_10 = param_2;
    return;
}

EC void func_02017518(SoundHandle * param_1, SoundHandle * param_2, s32 param_3, s32 param_4, s32 param_5)
{
    SoundWaitTo * puVar2;
    SoundWaitTo * pSVar2;
    SoundFade * pSVar3;

    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (param_1->unk_18 != NULL)
    {
        if ((param_1->unk_18->unk_3c == param_2) && (param_2->vfunc_58()))
        {
            pSVar3 = param_2->unk_14;
            pSVar3->unk_3c = 0;
            pSVar3->unk_48 = -1;
            pSVar3->unk_44 = 0;

            if (pSVar3->unk_40 > param_3)
            {
                pSVar3->unk_40 = param_3;
                pSVar3->unk_38->vfunc_14(0, param_3);
            }

            if (param_3 <= 0)
            {
                Proc_End(pSVar3);
            }

            pSVar2 = param_1->unk_18;
            pSVar2->unk_40 = 0;
            pSVar2->unk_44 = param_4;
            pSVar2->unk_48 = param_5;

            return;
        }

        Proc_End(param_1->unk_18);
    }

    if (param_2->vfunc_58())
    {
        pSVar3 = param_2->unk_14;
        pSVar3->unk_3c = 0;
        pSVar3->unk_48 = -1;
        pSVar3->unk_44 = 0;

        if (pSVar3->unk_40 > param_3)
        {
            pSVar3->unk_40 = param_3;
            pSVar3->unk_38->vfunc_14(0, param_3);
        }

        if (param_3 <= 0)
        {
            Proc_End(pSVar3);
        }
    }
    else
    {
        param_2->vfunc_44(param_3);
    }

    new (Proc_Start(data_020cbfd8, PROC_TREE_5)) SoundWaitTo(param_1, param_2, param_4, param_5);

    return;
}

EC void func_0201775c(SoundHandle * param_1, SoundHandle * param_2, s32 param_3)
{
    s32 iVar1;
    SoundWaitTo * puVar2;
    SoundWaitTo * pSVar2;
    SoundFade * pSVar3;

    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (param_1->unk_18 != NULL)
    {
        if ((param_1->unk_18->unk_3c == param_2) && (param_2->vfunc_58()))
        {
            pSVar3 = param_2->unk_14;
            pSVar3->unk_3c = 0;
            pSVar3->unk_48 = -1;
            pSVar3->unk_44 = 0;

            if (pSVar3->unk_40 > param_3)
            {
                pSVar3->unk_40 = param_3;
                pSVar3->unk_38->vfunc_14(0, param_3);
            }

            if (param_3 <= 0)
            {
                Proc_End(pSVar3);
            }

            pSVar2 = param_1->unk_18;
            pSVar2->unk_40 = 0;
            pSVar2->unk_44 = -1;
            pSVar2->unk_48 = 0;

            return;
        }

        Proc_End(param_1->unk_18);
    }

    param_2->vfunc_38(param_3);

    new (Proc_Start(data_020cbfd8, PROC_TREE_5)) SoundWaitTo(param_1, param_2, -1, 0);

    return;
}

EC void func_02017938(SoundHandle * param_1, SoundHandle * param_2, u32 param_3, u32 param_4, u32 param_5)
{
    SoundWaitTo * pSVar2;
    SoundFade * pSVar3;

    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (param_2 == NULL || param_2 == param_1)
    {
        param_1->vfunc_38(param_3);
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (param_1->unk_18 != NULL)
    {
        if ((param_1->unk_18->unk_3c == param_2) && param_2->vfunc_58())
        {
            pSVar3 = param_2->unk_14;
            pSVar3->unk_3c = 0;
            pSVar3->unk_48 = -1;
            pSVar3->unk_44 = 0;

            if (pSVar3->unk_40 > param_3)
            {
                pSVar3->unk_40 = param_3;
                pSVar3->unk_38->vfunc_14(0, param_3);
            }

            if (param_3 <= 0)
            {
                Proc_End(pSVar3);
            }

            pSVar2 = param_1->unk_18;
            pSVar2->unk_40 = 0;
            pSVar2->unk_44 = param_4;
            pSVar2->unk_48 = param_5;

            return;
        }

        Proc_End(param_1->unk_18);
    }

    param_2->vfunc_38(param_3);

    new (Proc_Start(data_020cbfd8, PROC_TREE_5)) SoundWaitTo(param_1, param_2, param_4, param_5);

    return;
}

EC void func_02017b40(SoundHandle * param_1, SoundHandle * param_2, int param_3)
{
    SoundWaitTo * pSVar2;
    SoundFade * pSVar3;

    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if (param_2 == NULL || param_2 == param_1)
    {
        param_1->vfunc_38(param_3);
        return;
    }

    if (data_020efcd4 != NULL ? TRUE : FALSE)
    {
        func_020a3320(data_020efcd4->unk_1000);
    }

    if (param_1->unk_18 != NULL)
    {
        if ((param_1->unk_18->unk_3c == param_2) && param_2->vfunc_58())
        {
            pSVar3 = param_2->unk_14;
            pSVar3->unk_3c = 0;
            pSVar3->unk_48 = -1;
            pSVar3->unk_44 = 0;

            if (pSVar3->unk_40 > param_3)
            {
                pSVar3->unk_40 = param_3;
                pSVar3->unk_38->vfunc_14(0, param_3);
            }

            if (param_3 <= 0)
            {
                Proc_End(pSVar3);
            }

            pSVar2 = param_1->unk_18;
            pSVar2->unk_40 = 2;
            pSVar2->unk_44 = -1;
            pSVar2->unk_48 = 0;

            return;
        }

        Proc_End(param_1->unk_18);
    }

    param_2->vfunc_38(param_3);

    new (Proc_Start(data_020cbfd8, PROC_TREE_5)) SoundWaitTo(param_1, param_2, -1, 0);

    return;
}

EC void func_0209b548(void *);

// func_02017d44
void SoundStrmHandle::vfunc_24(void)
{
    func_0209b548(&this->unk_04);

    this->unk_08 = -1;

    this->unk_0d = this->unk_0e = this->unk_0f = -1;

    return;
}

EC void func_0209b4d0(void *, u16, u32);

// func_02017d70
void SoundStrmHandle::vfunc_00(u32 param_2, u32 param_3, u32 param_4)
{
    func_0209b4d0(&this->unk_04, param_2, 0);
    return;
}

EC void func_0209b4f8(void *, u32);

// func_02017d8c
void SoundStrmHandle::vfunc_08(void)
{
    func_0209b4f8(&this->unk_04, 0);
    this->unk_08 = -1;
    return;
}

EC void func_0209b514(void *, u32, u32);

// func_02017dac
void SoundStrmHandle::vfunc_14(u32 param_2, u32 param_3)
{
    func_0209b514(&this->unk_04, param_2, param_3);
    return;
}

// func_02017dbc
void SoundSeHandle::vfunc_24(void)
{
    SoundHandle::vfunc_24();

    this->unk_0f = -1;
    this->unk_0e = -1;
    this->unk_0d = -1;

    return;
}

EC void func_02018014(UnkStruct_020efcd4 *);

// func_02017ddc
void SoundSeHandle::vfunc_00(u32 param_2, u32 param_3, u32 param_4)
{
    UnkStruct_020efcd4 * iVar2;

    if ((((s32)param_2 >> 0x18) & 0xff))
    {
        if (data_020efcc8->unk_98 == 0)
        {
            return;
        }

        iVar2 = new UnkStruct_020efcd4();

        iVar2->unk_10c0 = 0;
        iVar2->unk_10c4 = this;
        iVar2->unk_10c8 = param_2;
        iVar2->unk_10cc = param_3;
        iVar2->unk_10d0 = param_4;

        func_020a3080(iVar2->unk_1000, (void *)func_02018014, iVar2, iVar2->unk_1000, 0x1000, 0x11);
        func_020a3754(iVar2->unk_1000, iVar2);
        func_020a374c(iVar2->unk_1000, func_02016004);

        if (data_020efcd4 == NULL)
        {
            data_020efcd0 = iVar2;
            data_020efcd4 = iVar2;
            func_020a341c(iVar2->unk_1000);
        }
        else
        {
            data_020efcd4->unk_10c0 = iVar2;
            data_020efcd4 = iVar2;
        }
    }
    else
    {
        if ((((s32)param_2 >> 0x10) & 0xff))
        {
            iVar2 = new UnkStruct_020efcd4();

            iVar2->unk_10c0 = 0;
            iVar2->unk_10c4 = this;
            iVar2->unk_10c8 = param_2;
            iVar2->unk_10cc = param_3;
            iVar2->unk_10d0 = param_4;

            func_020a3080(iVar2->unk_1000, (void *)func_02018014, iVar2, iVar2->unk_1000, 0x1000, 0x11);
            func_020a3754(iVar2->unk_1000, iVar2);
            func_020a374c(iVar2->unk_1000, func_02016004);

            if (data_020efcd4 == NULL)
            {
                data_020efcd0 = iVar2;
                data_020efcd4 = iVar2;
                func_020a341c(iVar2->unk_1000);
            }
            else
            {
                data_020efcd4->unk_10c0 = iVar2;
                data_020efcd4 = iVar2;
            }
        }
        else
        {
            if (data_020efcc8->unk_98 == 0)
            {
                return;
            }

            iVar2 = new UnkStruct_020efcd4();

            iVar2->unk_10c0 = 0;
            iVar2->unk_10c4 = this;
            iVar2->unk_10c8 = param_2;
            iVar2->unk_10cc = param_3;
            iVar2->unk_10d0 = param_4;

            func_020a3080(iVar2->unk_1000, (void *)func_02018014, iVar2, iVar2->unk_1000, 0x1000, 0x11);
            func_020a3754(iVar2->unk_1000, iVar2);
            func_020a374c(iVar2->unk_1000, func_02016004);

            if (data_020efcd4 == NULL)
            {
                data_020efcd0 = iVar2;
                data_020efcd4 = iVar2;
                func_020a341c(iVar2->unk_1000);
            }
            else
            {
                data_020efcd4->unk_10c0 = iVar2;
                data_020efcd4 = iVar2;
            }
        }
    }

    this->unk_0c = 1;

    return;
}

EC void func_020181e4(SoundHandle *, s32, u32, u32);

EC void func_02018014(UnkStruct_020efcd4 * param_1)
{
    func_020181e4(param_1->unk_10c4, param_1->unk_10c8, param_1->unk_10cc, param_1->unk_10d0);
    return;
}

// func_02018034
void SoundSeHandle::vfunc_18(u32 param_2, u32 param_3, u32 param_4)
{
    this->vfunc_04((((s32)param_2 >> 0x10) & 0xff) - 1, param_2 & 0xffff, param_3, param_4);
    return;
}

extern struct UnkStruct_02196f0c * data_02196f0c;

// func_0201806c
EC void SoundSeHandle::vfunc_28(u32 param_2, u32 param_3, u32 param_4)
{
    if (!data_020efcc8->unk_a0)
    {
        return;
    }

    if ((!data_02196f24->enableSoundEffects) && !(data_02196f0c->state & 0x2000000))
    {
        return;
    }

    func_02070570(4);
    this->vfunc_00(param_2, param_3, param_4);
    func_0207058c(4);

    return;
}

EC void func_020180f8(SoundTemporarySe * param_1)
{
    param_1->Loop();
    return;
}

extern BOOL data_020efccc;

// func_0201810c
void SoundTemporarySe::Loop(void)
{
    u32 puVar2;

    if (data_020efccc == 0)
    {
        if (this->unk_40 != -1)
        {
            if (func_020983d4(this->unk_40, this->unk_44))
            {
                return;
            }
        }
        else
        {
            if (func_02098380(this->unk_44))
            {
                return;
            }
        }
    }

    puVar2 = func_0209a474(data_020efcc8->unk_98);

    if (this->unk_3c == puVar2)
    {
        Proc_End(this);
    }

    return;
}

EC void func_02018184(void)
{
    data_020efccc = TRUE;
    Proc_ForEach(data_020cbff0, (ProcFunc)func_020180f8);
    data_020efccc = FALSE;

    return;
}

EC void func_020181bc(void)
{
    Proc_ForEach(data_020cbff0, (ProcFunc)func_020180f8);
    return;
}

EC void func_020181d8(void)
{
    func_020181bc();
    return;
}

EC void func_02018184(void);
EC BOOL func_0209a538(u32, void *);

EC void func_020181e4(SoundHandle * param_1, s32 param_2, u32 param_3, u32 param_4)
{
    u8 cVar1;
    s32 iVar2;
    u32 uVar3;
    u32 puVar4;
    u32 uVar5;

    uVar5 = (param_2 >> 0x18) & 0xff;
    iVar2 = func_0209a474(data_020efcc8->unk_98);

    if (uVar5 != 0)
    {
        cVar1 = func_0209a520(uVar5, data_020efcc8->unk_98);
    }
    else
    {
        cVar1 = func_0209a538(param_2, data_020efcc8->unk_98);
    }

    if (cVar1 == 0)
    {
        uVar3 = func_020a4a38();
        func_02018184();
        func_020a4a4c(uVar3);

        iVar2 = func_0209a474(data_020efcc8->unk_98);

        if (uVar5 != 0)
        {
            func_0209a520(uVar5, data_020efcc8->unk_98);
        }
        else
        {
            func_0209a538(param_2, data_020efcc8->unk_98);
        }
    }

    puVar4 = func_0209a354(data_020efcc8->unk_98);

    uVar3 = func_020a4a38();
    new (Proc_Start(data_020cbff0, PROC_TREE_5)) SoundTemporarySe(param_1, param_2, param_3, param_4, iVar2, puVar4);
    func_020a4a4c(uVar3);

    return;
}

EC void func_020183b4(s32 param_1, s32 param_2)
{
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_5)) VolumeDownPlayingSE(param_1, param_2);
    return;
}

EC void func_020184ac(SoundVolumeMoveVC * param_1)
{
    param_1->Loop();
    return;
}

// func_020184c0
void SoundVolumeMoveVC::Loop(void)
{
    s32 uVar2;
    s8 * pcVar3;

    this->unk_38++;

    uVar2 = Interpolate(0, this->unk_40, this->unk_44, this->unk_38, this->unk_3c);

    pcVar3 = data_020cc030;

    while (*pcVar3 != -1)
    {
        func_02098250(*pcVar3++, uVar2);
    }

    data_020efcc8->unk_a1 = uVar2;

    if (this->unk_38 == this->unk_3c)
    {
        Proc_End(this);
    }

    return;
}

extern struct ProcCmd data_020cc008[];

EC void func_02018550(u32 param_1, u32 param_2)
{
    s32 bVar1 = data_020efcc8->unk_a1;
    new (Proc_Start(data_020cc008, PROC_TREE_5)) SoundVolumeMoveVC(param_1, param_2, bVar1);
    return;
}

// func_020185b4 -> SoundVolumeMoveVC::~SoundVolumeMoveVC()

// func_0201861c -> SoundVolumeMoveVC::~SoundVolumeMoveVC()

// func_0201867c -> VolumeDownPlayingSE::~VolumeDownPlayingSE()

// func_02018774 -> VolumeDownPlayingSE::~VolumeDownPlayingSE()

// func_02018864 -> VolumeDownPlayingSE::Loop()

// func_020188ac -> SoundTemporarySe::~SoundTemporarySe()

// func_02018914 -> SoundTemporarySe::~SoundTemporarySe()

// func_02018974 -> SoundWaitTo::~SoundWaitTo()

// func_020189c8 -> SoundWaitTo::~SoundWaitTo()

// func_02018a14 -> SoundFade::~SoundFade()

// func_02018b2c -> SoundFade::~SoundFade()

// func_02018c3c -> SoundFade::Loop
