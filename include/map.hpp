#ifndef MAP_HPP
#define MAP_HPP

#include "global.h"

class UnkStruct_021e334c
{
public:
    /* 00 */ STRUCT_PAD(0x00, 0x24);

    UnkStruct_021e334c();
    ~UnkStruct_021e334c();
};

extern struct UnkStruct_021e334c * data_ov000_021e334c;

class UnkStruct_021E3324_00
{
public:
    /* 00 */ u8 phase;
    /* 01 */ u8 unk_01;
    /* 02 */ u8 unk_02;
    /* 03 */ u8 unk_03;
    /* 04 */ u16 turn;
    /* 06 */ u16 unk_06;
    /* 08 */ u32 unk_08;
    /* 0C */ u32 unk_0c;
    /* 10 */ u32 unk_10;
    /* 14 */ u8 unk_14;
    /* 15 */ u8 unk_15;
    /* 16 */ u8 unk_16;
    /* 17 */ u8 unk_17;
    /* 18 */ u8 unk_18[4];
    /* 1C */ u8 unk_1c;

    UnkStruct_021E3324_00()
    {
            s32 j;

            this->phase = 0;
            this->unk_01 = 0;
            this->turn = 1;
            this->unk_06 = 0;
            this->unk_08 = 0;
            this->unk_0c = 0;
            this->unk_02 = 0;
            this->unk_03 = 0;
            this->unk_14 = 0x1f;
            this->unk_15 = 0x1f;
            this->unk_16 = 0x1f;

            for (j = 0; j < 4; j++)
            {
                this->unk_18[j] = 0;
            }

            this->unk_1c = 0;
    }
};

struct UnkStruct_021E3324_04_00
{
    /* 00 */ STRUCT_PAD(0x00, 0x14);
    /* 14 */ u16 unk_14;
    /* 16 */ u16 unk_16;
    /* 18 */ u8 unk_18;
    /* 18 */ STRUCT_PAD(0x19, 0x24);
};

class UnkStruct_021E3324_04_04_04
{
public:
    STRUCT_PAD(0x00, 0x54);
    u16 unk_54;
    STRUCT_PAD(0x56, 0x5f);
    s8 unk_5f;
    s8 unk_60;
    u8 unk_61;

    void ClearValues()
    {
        this->unk_5f = 0;

        if (this->unk_61 != 0)
        {
            this->unk_61 = 0;
            this->unk_60 = -1;
        }
    }
};

class UnkStruct_021E3324_04_04
{
public:
    /* 00 */ struct Unit * unk_00;
    /* 04 */ struct UnkStruct_021E3324_04_04_04 * unk_04;
    /* 08 */ u32 unk_08;

    UnkStruct_021E3324_04_04()
    {
        this->unk_00 = 0;
        this->unk_04 = 0;
        this->unk_08 = 0;
    }
};

struct UnkStruct_021E3324_04_08
{
    STRUCT_PAD(0x0000, 0x0854);

    /* 0854 */ s8 * unk_0854;
    /* 0858 */ void * unk_0858;
    /* 085C */ void * unk_085c;
    /* 0860 */ void * unk_0860;

    STRUCT_PAD(0x0864, 0x086E);

    /* 086E */ u8 unk_086e;
    /* 086F */ u8 unk_086f;
    /* 0870 */ u8 unk_0870;
    /* 0871 */ u8 unk_0871;
    /* 0872 */ u8 unk_0872;
    /* 0873 */ u8 unk_0873;
    /* 0874 */ u8 unk_0874;

    STRUCT_PAD(0x0875, 0x0878);

    /* 0878 */ s8 unk_0878[0x400];
    /* 0C78 */ s8 unk_0c78[0x400];
    /* 1078 */ s8 unk_1078[0x80];
    /* 10F8 */ s8 unk_10f8[0x80];
};

struct UnkStruct_021E3324_04_0C
{
// +0x10 contains last touch coords
// +0x14 contains current touch coords
// +0x18 contains key handlers
    STRUCT_PAD(0x00, 0x1C);
    u16 unk_1c;
    STRUCT_PAD(0x1E, 0x20);
    u8 unk_20;
    u8 unk_21_0 : 2;
    u8 unk_21_2 : 1;
    u8 unk_21_3 : 1;
    u8 unk_21_4 : 2;
    u8 unk_21_6 : 1;
    u8 unk_21_7 : 1;
    u8 unk_21_8 : 1;
    STRUCT_PAD(0x22, 0x28);
};

class UnkStruct_021E3324_04_10
{
public:
    /* 00 */ s8 unk_00[2];
    /* 02 */ s8 unk_02[2];
    /* 04 */ STRUCT_PAD(0x04, 0x08);
    /* 08 */ u8 unk_08;
    /* 09 */ u8 unk_09;
    u8 unk_0a;
    u8 unk_0b;
    /* 0A */ STRUCT_PAD(0x0C, 0x1A);

    void SetUnk00And02(u8 phase, u8 r12, u8 r2)
    {
        this->unk_00[phase] = r12;
        this->unk_02[phase] = r2;
    }
};

EC void func_ov000_021b9a1c(struct UnkStruct_021E3324_04_14 *);

class UnkStruct_021E3324_04_14_04
{
public:
    STRUCT_PAD(0x00, 0x10);
    u8 unk_10;
    STRUCT_PAD(0x11, 0x14);
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    /* 17 */ u8 unk_17;
    /* 18 */ u8 unk_18;
    u8 unk_19;
};

class UnkStruct_021E3324_04_14
{
public:
    /* 00 */ void * unk_00;
    /* 04 */ UnkStruct_021E3324_04_14_04 * unk_04;
    /* 08 */ u32 unk_08;
    /* 0C */ u32 unk_0c;
    /* 10 */ u32 unk_10;
    /* 14 */ u32 unk_14;
    /* 18 */ u32 unk_18;
    /* 1C */ u32 unk_1c;
    /* 20 */ u32 unk_20;
    /* 24 */ u8 unk_24;
    /* 25 */ u8 unk_25;
    /* 26 */ u8 unk_26;
    /* 27 */ u8 unk_27;
    /* 28 */ u8 unk_28;
    /* 29 */ u8 unk_29;
    /* 2A */ u8 unk_2a;
    /* 2B */ u8 unk_2b;
    /* 2C */ u32 unk_2c;

    UnkStruct_021E3324_04_14()
    {
        this->unk_00 = 0;
        this->unk_04 = 0;
        this->unk_08 = 0;
        this->unk_0c = 0;
        this->unk_10 = 0;
        this->unk_14 = 0;
        this->unk_18 = 0;
        this->unk_1c = 0;
        this->unk_20 = 0;
        this->unk_25 = 0;
        this->unk_26 = 0;
        this->unk_29 = 0;
        this->unk_27 = 0;
        this->unk_28 = 0;
        this->unk_2c = 0;
    }

    ~UnkStruct_021E3324_04_14()
    {
        func_ov000_021b9a1c(this);
    }
};

extern u8 data_027e1b9c[];
EC void * func_01ffb934(void *, s32);
EC void func_01ffbb90(void *, void *);

class UnkStruct_021E3324_04_1C
{
public:
    /* 00 */ void * unk_00;
    /* 04 */ void * unk_04;
    /* 08 */ u32 unk_08;
    /* 0C */ u8 unk_0c;

    UnkStruct_021E3324_04_1C()
    {
        void * ret = func_01ffb934(data_027e1b9c, 0x4000);
        this->unk_04 = ret;
        this->unk_00 = ret;
        this->unk_08 = 0x4000;
        this->unk_0c = 1;
    }

    ~UnkStruct_021E3324_04_1C()
    {
        if (this->unk_0c != 0)
        {
            func_01ffbb90(data_027e1b9c, this->unk_00);
        }
    }
};

class UnkStruct_021E3324_04
{
public:
    /* 000 */ struct UnkStruct_021E3324_04_00 * unk_00;
    /* 004 */ struct UnkStruct_021E3324_04_04 * unk_04;
    /* 008 */ struct UnkStruct_021E3324_04_08 * unk_08;
    /* 00C */ struct UnkStruct_021E3324_04_0C * unk_0c;
    /* 010 */ struct UnkStruct_021E3324_04_10 * unk_10;
    /* 014 */ struct UnkStruct_021E3324_04_14 * unk_14;
    /* 018 */ void * unk_18;
    /* 01C */ struct UnkStruct_021E3324_04_1C * unk_1c;
    /* 020 */ u16 unk_20;
    /* 022 */ u16 unk_22;
    /* 024 */ u8 unk_24;
    /* 025 */ u8 unk_25;
    /* 026 */ u8 unk_26;
    /* 027 */ u8 unk_27;
    /* 028 */ u8 unk_028[0x400];
    /* 428 */ u8 unk_428[0x400];
    /* 828 */ u8 * unk_828;
    /* 82C */ u8 * unk_82c;
    /* 830 */ u8 unk_830[0x400];
    /* C30 */ u8 unk_c30[0x80];
    /* CB0 */ u8 unk_cb0[0x80];
    /* D30 */ u8 unk_d30[0x80];
    /* DB0 */ u8 unk_db0[0x80];
    /* E30 */ u8 unk_e30[0x80];
    /* EB0 */ s8 unk_eb0[4];
    /* EB4 */ s8 unk_eb4[4];
    /* EB8 */ u8 unk_eb8;
    /* EB9 */ STRUCT_PAD(0xEB9, 0xEBC);

    UnkStruct_021E3324_04();
    ~UnkStruct_021E3324_04();

    void func_ov000_021a276c(char *);
    void func_ov000_021a28cc();
    void func_ov000_021a2918();
    void func_ov000_021a29f4();
};

extern UnkStruct_021E3324_00 * data_ov000_021e3324;
extern UnkStruct_021E3324_04 * data_ov000_021e3328;

#endif // MAP_HPP
