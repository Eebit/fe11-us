#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP

#include "global.h"

#include "proc_ex.hpp"

class SoundFade;
class SoundWaitTo;

class SoundHandle
{
public:
    /* 00 (vtable) */
    s32 unk_04;
    s32 unk_08;
    u8 unk_0c;
    u8 unk_0d;
    u8 unk_0e;
    u8 unk_0f;
    u8 unk_10;
    STRUCT_PAD(0x11, 0x14);
    SoundFade * unk_14;
    SoundWaitTo * unk_18;

    SoundHandle()
    {
        this->unk_14 = 0;
        this->unk_18 = 0;
        this->unk_10 = 0x7f;
    }

    /* 00 */ virtual void vfunc_00(u32, u32, u32); // func_020164f4
    /* 04 */ virtual void vfunc_04(u32, u32, u32, u32); // func_02016688
    /* 08 */ virtual void vfunc_08(void); // func_02016a28
    /* 0C */ virtual void vfunc_0c(void); // func_02016e70
    /* 10 */ virtual void vfunc_10(u32); // func_02016ff4
    /* 14 */ virtual void vfunc_14(u32, u32); // func_02017408
    /* 18 */ virtual void vfunc_18(u32, u32, u32); // func_020165f4
    /* 1C */ virtual void vfunc_1c(void); // func_02016ba0
    /* 20 */ virtual void vfunc_20(u32); // func_020170a8
    /* 24 */ virtual void vfunc_24(void); // func_020164d0
    /* 28 */ virtual void vfunc_28(u32, u32, u32); // func_0201670c
    /* 2C */ virtual void vfunc_2c(char *, u32, u32); // func_02016804
    /* 30 */ virtual void vfunc_30(u32, u32, u32); // func_02016848
    /* 34 */ virtual void vfunc_34(char *, u32, u32); // func_020169e4
    /* 38 */ virtual void vfunc_38(s32); // func_02016a48
    /* 3C */ virtual void vfunc_3c(s32, u32, u32); // func_02016cb8
    /* 40 */ virtual void vfunc_40(u32, char *, u32); // func_02016e18
    /* 44 */ virtual void vfunc_44(s32); // func_02016e84
    /* 48 */ virtual void vfunc_48(u32); // func_020170fc
    /* 4C */ virtual void vfunc_4c(s32); // func_02017164
    /* 50 */ virtual BOOL vfunc_50(void); // func_02017278
    /* 54 */ virtual BOOL vfunc_54(void); // func_0201728c
    /* 58 */ virtual BOOL vfunc_58(void); // func_020172a0
    /* 5C */ virtual BOOL vfunc_5c(void); // func_020172e0
    /* 60 */ virtual BOOL vfunc_60(void); // func_02017338
    /* 64 */ virtual void vfunc_64(u32, u32); // func_02017418
    /* 68 */ virtual void vfunc_68(u32); // func_02017494
    /* 6C */ virtual void vfunc_6c(u32); // func_02017510
};

class SoundStrmHandle : public SoundHandle
{
public:
    /* 00 */ virtual void vfunc_00(u32, u32, u32); // func_02017d70
    /* 08 */ virtual void vfunc_08(void); // func_02017d8c
    /* 14 */ virtual void vfunc_14(u32, u32); // func_02017dac
    /* 24 */ virtual void vfunc_24(void); // func_02017d44
};

class SoundSeHandle : public SoundHandle
{
public:
    /* 00 */ virtual void vfunc_00(u32, u32, u32); // func_02017ddc
    /* 18 */ virtual void vfunc_18(u32, u32, u32); // func_02018034
    /* 24 */ virtual void vfunc_24(void); // func_02017dbc
    /* 28 */ virtual void vfunc_28(u32, u32, u32); // func_0201806c
};

class UnkStruct_020efcc8
{
public:
    STRUCT_PAD(0x00, 0x94);
    void * unk_94;
    void * unk_98;
    u32 unk_9c;
    u8 unk_a0;
    u8 unk_a1;
    STRUCT_PAD(0xA2, 0xA4);
    SoundHandle * unk_a4;
    SoundHandle * unk_a8;
    SoundStrmHandle * unk_ac;
    SoundSeHandle * unk_b0;
    SoundSeHandle * unk_b4;
};

extern UnkStruct_020efcc8 * data_020efcc8;

EC void func_02016490(void);
EC void func_020181d8(void);
EC s32 func_0209a474(void *);
EC void * func_0209a3a0(void *, u32);

class SoundFade : public ProcEx
{
public:
    SoundHandle * unk_38;
    u32 unk_3c;
    s32 unk_40;
    u32 unk_44;
    u32 unk_48;

    SoundFade(SoundHandle * param_1, s32 param_2, u32 param_3, u32 param_4)
    {
        this->unk_38 = param_1;
        this->unk_3c = 0;
        this->unk_40 = param_2;
        this->unk_48 = param_3;
        this->unk_44 = param_4;

        param_1->unk_14 = this;

        param_1->vfunc_14(0, param_2);

        if (param_2 <= 0)
        {
            Proc_End(this);
        }
    }

    virtual ~SoundFade()
    {
        this->unk_38->unk_14 = NULL;

        if (this->unk_38->unk_0c != 0)
        {
            if (this->unk_3c == 0)
            {
                this->unk_38->vfunc_08();

                if (this->unk_38->unk_0d != 0xFF)
                {
                    func_0209a3a0(data_020efcc8->unk_94, this->unk_38->unk_0d);
                }

                this->unk_38->unk_0c = 0;
            }
            else
            {
                this->unk_38->vfunc_0c();

                if (this->unk_38->unk_0e != 0xFF)
                {
                    func_0209a3a0(data_020efcc8->unk_94, this->unk_38->unk_0e);
                }

                this->unk_38->unk_0c = 2;
            }

            if (this->unk_38->unk_0f != 0xFF)
            {
                this->unk_38->unk_0f = func_0209a474(data_020efcc8->unk_94);
            }
        }

        func_020181d8();
        func_02016490();

        if (this->unk_48 != -1)
        {
            this->unk_38->vfunc_30(this->unk_48, this->unk_44, 0);
        }
    }

    virtual void Loop(void)
    {
        this->unk_40--;

        if (this->unk_40 >= 0)
        {
            return;
        }

        Proc_End(this);

        return;
    }
};

class SoundWaitTo : public ProcEx
{
public:
    SoundHandle * unk_38;
    SoundHandle * unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;

    SoundWaitTo(SoundHandle * param_1, SoundHandle * param_2, u32 param_4, u32 param_5)
    {
        this->unk_38 = param_1;
        this->unk_3c = param_2;
        this->unk_40 = 0;
        this->unk_44 = param_4;
        this->unk_48 = param_5;

        param_1->unk_18 = this;

        if (!param_2->vfunc_58())
        {
            this->unk_38->unk_18 = NULL;

            switch (this->unk_40)
            {
                case 0:
                    this->unk_38->vfunc_30(this->unk_44, this->unk_48, 0);
                    break;

                case 1:
                    this->unk_38->vfunc_4c(this->unk_48);
                    break;

                case 2:
                    this->unk_38->vfunc_38(0);
                    break;

                case 3:
                    break;
            }

            Proc_End(this);
        }
    }

    virtual ~SoundWaitTo()
    {
        if (this->unk_3c->vfunc_58())
        {
            Proc_End(this->unk_3c->unk_14);
        }

        this->unk_38->unk_18 = NULL;
    }
};

extern struct ProcCmd data_020cbff0[];

class SoundTemporarySe;

EC void func_020180f8(SoundTemporarySe *);
EC BOOL func_0209b000(void *, u32);
EC BOOL func_0209b048(void *, u32, u32);
EC void func_020984c8(void *, u16, u32);
EC void func_0209845c(void *, u32, u32);

class SoundTemporarySe : public ProcEx
{
public:
    s32 unk_38;
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;

    SoundTemporarySe(SoundHandle * param_1, s32 param_2, u32 param_3, u32 param_4, u32 iVar2, u32 puVar4)
    {
        u8 cVar1;

        this->unk_40 = ((param_2 >> 0x10) & 0xff) - 1;
        this->unk_44 = param_2 & 0xffff;
        this->unk_48 = param_4;
        this->unk_38 = iVar2;
        this->unk_3c = puVar4;

        if (this->unk_40 != -1)
        {
            cVar1 = func_0209b048(&param_1->unk_04, this->unk_40, this->unk_44);
        }
        else
        {
            cVar1 = func_0209b000(&param_1->unk_04, this->unk_44);
        }

        if (cVar1 != 0 && this->unk_48 != 0)
        {
            func_020984c8(&param_1->unk_04, 0xffff, this->unk_48);
        }

        if (param_3 != 0)
        {
            func_0209845c(&param_1->unk_04, 0, 0);
            func_0209845c(&param_1->unk_04, 0x7f, param_3);
        }
        else
        {
            func_0209845c(&param_1->unk_04, 0x7f, 0);
        }
    }

    virtual ~SoundTemporarySe()
    {
        s32 val = func_0209a474(data_020efcc8->unk_98);
        if (val > this->unk_38)
        {
            func_0209a3a0(data_020efcc8->unk_98, this->unk_38);
            Proc_ForEach(data_020cbff0, (ProcFunc)func_020180f8);
        }
    }

    virtual void Loop(void);
};

EC BOOL func_020983d4(s32, s32);
EC BOOL func_02098380(s32);

class VolumeDownPlayingSE : public ProcEx
{
public:
    u32 unk_38;
    u32 unk_3c;
    u8 unk_40;
    u8 unk_41;

    VolumeDownPlayingSE(s32 param_1, s32 param_2)
    {
        this->unk_38 = ((param_1 >> 0x10) & 0xff) - 1;
        this->unk_3c = param_1 & 0xffff;
        this->unk_40 = 0;
        this->unk_41 = 0;

        func_02019230((struct Proc *)this, 2);

        if (data_020efcc8->unk_a4->vfunc_50())
        {
            data_020efcc8->unk_a4->vfunc_64(param_2, 8);
            this->unk_40 = 1;
        }

        if (data_020efcc8->unk_a8->vfunc_50())
        {
            data_020efcc8->unk_a8->vfunc_64(param_2, 8);
            this->unk_41 = 1;
        }
    }

    virtual ~VolumeDownPlayingSE()
    {
        if (this->unk_40 != 0)
        {
            if (data_020efcc8->unk_a4->vfunc_50())
            {
                data_020efcc8->unk_a4->vfunc_68(8);
            }
            else
            {
                data_020efcc8->unk_a4->vfunc_6c(0x7f);
            }
        }

        if (this->unk_41 != 0)
        {
            if (data_020efcc8->unk_a8->vfunc_50())
            {
                data_020efcc8->unk_a8->vfunc_68(8);
            }
            else
            {
                data_020efcc8->unk_a8->vfunc_6c(0x7f);
            }
        }
    }

    virtual void Loop(void)
    {
        if (this->unk_38 != -1)
        {
            if (func_020983d4(this->unk_38, this->unk_3c) != 0)
            {
                return;
            }
        }
        else
        {
            if (func_02098380(this->unk_3c) != 0)
            {
                return;
            }
        }

        Proc_End(this);

        return;
    }
};

extern s8 data_020cc030[];
EC void func_02098250(s32, s32);

class SoundVolumeMoveVC : public ProcEx
{
public:
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;

    SoundVolumeMoveVC(s32 param_1, s32 param_2, s32 bVar1)
    {
        this->unk_40 = bVar1;
        this->unk_44 = param_1;
        this->unk_38 = 0;
        this->unk_3c = param_2;

        if (param_2 < 0)
        {
            Proc_End(this);
        }
    }

    virtual ~SoundVolumeMoveVC()
    {
        s8 * it = data_020cc030;
        s32 uVar2 = this->unk_44;

        while (*it != -1)
        {
            func_02098250(*it++, uVar2);
        }

        data_020efcc8->unk_a1 = uVar2;
    }

    virtual void Loop(void);
};

#endif // SOUND_MANAGER_HPP
