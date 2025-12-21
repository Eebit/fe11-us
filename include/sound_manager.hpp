#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP

#include "global.h"

struct SoundHandle_Unk14
{
    STRUCT_PAD(0x00, 0x3C);
    u32 unk_3c;
};

struct SoundHandle_Unk18
{
    STRUCT_PAD(0x00, 0x40);
    u32 unk_40;
};

class SoundHandle
{
public:
    /* 00 (vtable) */
    s32 unk_04;
    s32 unk_08;
    u8 unk_0c;
    STRUCT_PAD(0x0D, 0x10);
    u8 unk_10;
    STRUCT_PAD(0x11, 0x14);
    struct SoundHandle_Unk14 * unk_14;
    struct SoundHandle_Unk18 * unk_18;

    SoundHandle()
    {
        this->unk_14 = 0;
        this->unk_18 = 0;
        this->unk_10 = 0x7f;
    }

    /* 00 */ virtual void vfunc_00(); // func_020164f4
    /* 04 */ virtual void vfunc_04(); // func_02016688
    /* 08 */ virtual void vfunc_08(); // func_02016a28
    /* 0C */ virtual void vfunc_0c(); // func_02016e70
    /* 10 */ virtual void vfunc_10(); // func_02016ff4
    /* 14 */ virtual void vfunc_14(u32, u32); // func_02017408
    /* 18 */ virtual void vfunc_18(); // func_020165f4
    /* 1C */ virtual void vfunc_1c(); // func_02016ba0
    /* 20 */ virtual void vfunc_20(); // func_020170a8
    /* 24 */ virtual void vfunc_24(); // func_020164d0
    /* 28 */ virtual void vfunc_28(u32, u32, u32); // func_0201670c
    /* 2C */ virtual void vfunc_2c(u32, u32, u32); // func_02016804
    /* 30 */ virtual void vfunc_30(u32, u32, u32); // func_02016848
    /* 34 */ virtual void vfunc_34(u32, u32, u32); // func_020169e4
    /* 38 */ virtual void vfunc_38(u32); // func_02016a48
    /* 3C */ virtual void vfunc_3c(u32, u32, u32); // func_02016cb8
    /* 40 */ virtual void vfunc_40(); // func_02016e18
    /* 44 */ virtual void vfunc_44(); // func_02016e84
    /* 48 */ virtual void vfunc_48(); // func_020170fc
    /* 4C */ virtual void vfunc_4c(s32); // func_02017164
    /* 50 */ virtual BOOL vfunc_50(); // func_02017278
    /* 54 */ virtual BOOL vfunc_54(); // func_0201728c
    /* 58 */ virtual BOOL vfunc_58(); // func_020172a0
    /* 5C */ virtual BOOL vfunc_5c(); // func_020172e0
    /* 60 */ virtual void vfunc_60(); // func_02017338
    /* 64 */ virtual void vfunc_64(u32, u32); // func_02017418
    /* 68 */ virtual void vfunc_68(u32); // func_02017494
    /* 6C */ virtual void vfunc_6c(u32); // func_02017510
};

class SoundStrmHandle : public SoundHandle
{
};

class SoundSeHandle : public SoundHandle
{
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
