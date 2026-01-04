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

#endif // SOUND_MANAGER_HPP
