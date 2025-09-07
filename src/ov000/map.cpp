#include "global.h"

#include <new>

#include "unit.h"
#include "unknown_data.h"
#include "unknown_funcs.h"

#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "state_manager.hpp"

extern struct UnkStruct_02196f0c * data_02196f0c;

class UnkStruct_021e334c
{
public:
    /* 00 */ STRUCT_PAD(0x00, 0x24);

    UnkStruct_021e334c(); // func_ov000_021b0f60
    ~UnkStruct_021e334c(); // func_ov000_021b1054
};

extern struct UnkStruct_021e334c * data_ov000_021e334c;

struct UnkStruct_021E3324_04_00
{
    /* 00 */ STRUCT_PAD(0x00, 0x14);
    /* 14 */ u16 unk_14;
    /* 16 */ u16 unk_16;
    /* 18 */ STRUCT_PAD(0x18, 0x24);
};

class UnkStruct_021E3324_04_04
{
public:
    /* 00 */ struct Unit * unk_00;
    /* 04 */ u32 unk_04;
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
    /* 000 */ STRUCT_PAD(0x000, 0x854);
    /* 854 */ s8 * unk_854;
};

struct UnkStruct_021E3324_04_0C
{
    /* 00 */ STRUCT_PAD(0x00, 0x28);
};

struct UnkStruct_021E3324_04_10
{
    /* 00 */ s8 unk_00[2];
    /* 02 */ s8 unk_02[2];
    /* 04 */ STRUCT_PAD(0x04, 0x08);
    /* 08 */ u8 unk_08;
    /* 09 */ u8 unk_09;
    /* 0A */ STRUCT_PAD(0x0A, 0x1A);
};

EC void func_ov000_021b9a1c(struct UnkStruct_021E3324_04_14 *);

class UnkStruct_021E3324_04_14_04
{
public:
    /* 00 */ STRUCT_PAD(0x00, 0x17);
    /* 17 */ u8 unk_17;
    /* 18 */ u8 unk_18;
};

class UnkStruct_021E3324_04_14
{
public:
    /* 00 */ u32 unk_00;
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

    UnkStruct_021E3324_04(); // func_ov000_021a2620
    ~UnkStruct_021E3324_04(); // func_ov000_021a26e8
};

extern struct UnkStruct_021974fc * data_021974fc;

EC struct UnkStruct_021E3324_04 * func_ov000_021a2620(struct UnkStruct_021E3324_04 *);
EC void func_ov000_021a276c(struct UnkStruct_021E3324_04 *, char *);

EC struct UnkStruct_021e334c * func_ov000_021b0f60(struct UnkStruct_021e334c *);
EC void func_ov000_021d4874(void);
EC void func_ov000_021a28cc(struct UnkStruct_021E3324_04 *);
EC void func_0204f080(struct UnkStruct_021974fc *);

EC void func_ov000_021a2918(struct UnkStruct_021E3324_04 *);
EC void func_ov000_021a2eb0(struct UnkBuf_Func_02049564 *, s32);
EC void func_ov000_021a29f4(struct UnkStruct_021E3324_04 *);

EC void func_ov000_021a4a7c(UnkStruct_021E3324_04_00 *);
EC void func_ov000_021a5318(UnkStruct_021E3324_04_0C *);
EC void func_ov000_021a68c0(UnkStruct_021E3324_04_10 *);
EC void func_ov000_021b9a10(UnkStruct_021E3324_04_14 *);
EC void func_ov000_021a37c4(void);

EC void func_ov000_021a3364(void);

extern u8 data_ov000_021e3320[];

EC void func_ov000_021baafc(u32, struct Unit *, BOOL);

EC void func_ov000_021d537c(void *);
EC void func_ov000_021a3364(void);
EC void func_ov000_021a340c(void);
EC void func_ov000_021a35a0(void);
EC void func_ov000_021a37c4(void);
EC void func_ov000_021a48b0(u32);
EC void func_ov000_021a52c8(void *, s16, s16, u32);
EC void func_ov000_021d4004(s8, s8);
EC void func_ov000_021d5528(void *, s32);
EC void func_02040094(struct UnkStruct_021E3324_04_1C *, s32);
EC void func_020401d8(struct UnkStruct_021E3324_04_1C *, u8);
EC void func_ov000_021a37c4(void);
EC void func_ov000_021babf4(u32);

extern struct Unknown_02197254 * data_02197254;

EC void func_ov000_021a36f8(struct Unit *, BOOL, BOOL);

EC void func_ov000_021a3974(u8 *, s32);
EC void func_ov000_021a3a30(u8 *, u32);

extern struct UnkStruct_021e3528 data_ov000_021e3528;

EC void func_ov000_021a3ad0(u8 *, s16, s16, s32);

extern struct Unit * data_021974f0;

EC BOOL func_ov000_021a4360(u32);

EC void func_0201775c(void *, void *, int, int);
EC void func_02017938(void *, void *, int, int, int);

EC void func_02017b40(void *, void *, int);

EC BOOL func_ov000_021adabc(struct Unit *, u32);

EC void func_ov000_021a6ab8(struct UnkStruct_021E3324_04_10 *, s32, s32);
EC void func_ov000_021a4e84(struct UnkStruct_021E3324_04_00 *, s32, s32, s32);

EC BOOL func_ov000_021a475c(void);
EC BOOL func_ov000_021a47ac(void);

extern struct UnkStruct_02196f0c * data_02196f0c;
extern struct UnkStruct_02196f10 * data_02196f10;

extern vu32 data_027e1264;

extern u8 data_ov000_021e3320[];

EC void func_ov000_021b9bec(struct UnkStruct_021E3324_04_14 *);

EC void func_ov000_021b9c3c(struct UnkStruct_021E3324_04_14 *);

EC void func_ov000_021a6e68(struct UnkStruct_021E3324_04_10 *);
EC void func_ov000_021b9bc4(struct UnkStruct_021E3324_04_14 *);
EC void func_ov000_021a5128(struct UnkStruct_021E3324_04_00 *);

EC void func_ov000_021b9bac(struct UnkStruct_021E3324_04_14 *);

EC void func_ov000_021d4094(void);
EC void func_ov000_021b9bec(struct UnkStruct_021E3324_04_14 *);
EC void func_ov000_021b1054(struct UnkStruct_021e334c *);
EC struct UnkStruct_021E3324_04 * func_ov000_021a26e8(struct UnkStruct_021E3324_04 *);
EC void func_ov000_021d492c(void);
EC void func_0204000c(void);

EC void func_ov000_021a8304(void);
EC void func_ov002_021f212c(void);

EC void func_ov002_021f2160(void);
EC void func_ov000_021a32c8(void);
EC void func_ov000_021a83d0(void);

extern char data_ov000_021db7dc[];

class ProcMapBegin : public ProcEx
{
public:
    ProcMapBegin()
    {
        this->proc_mark = PROC_MARK_6;
    }

    virtual ~ProcMapBegin();
    virtual void Init();
    virtual void Loop();
};

class ProcMapLow : public ProcEx
{
public:
    ProcMapLow()
    {
        this->proc_mark = PROC_MARK_6;
    }

    virtual ~ProcMapLow();
    virtual void Init();
    virtual void Loop();
};

class ProcMapDraw : public ProcEx
{
public:
    ProcMapDraw()
    {
        this->proc_mark = PROC_MARK_6;
    }

    virtual ~ProcMapDraw();
    virtual void Init();
    virtual void Loop();
};

class ProcMapEnd : public ProcEx
{
public:
    ProcMapEnd()
    {
        this->proc_mark = PROC_MARK_6;
    }

    virtual ~ProcMapEnd();
    virtual void Init();
    virtual void Loop();
};

// clang-format off

char * data_ov000_021db72c[] =
{
    "Null\0\0\0",
    "Link\0\0\0",
    "Cpu",
    "Human\0\0\0",
};

u32 data_ov000_021db73c[] =
{
    0,
    10,
    12,
    14,
    16,
    18,
    20,
    22,
};

u32 data_ov000_021db75c[] =
{
    0,
    11,
    13,
    15,
    17,
    19,
    21,
};

// clang-format on

EC void func_ov000_021a23e0(char * mapName)
{
    if (mapName == NULL)
    {
        mapName = GetBattleMapNameMaybe();
    }

    if (data_ov000_021e3324.unk_04 == NULL)
    {
        data_ov000_021e3324.unk_04 = new UnkStruct_021E3324_04;
    }

    func_ov000_021a276c(data_ov000_021e3324.unk_04, mapName);
    func_0204246c(mapName);

    if (data_ov000_021e334c == NULL)
    {
        data_ov000_021e334c = new UnkStruct_021e334c;
    }

    func_ov000_021d4874();
    func_ov000_021a28cc(data_ov000_021e3324.unk_04);

    if (data_021974fc != NULL)
    {
        func_0204f080(data_021974fc);
    }

    new (Proc_Start(ProcScr_020ce750, PROC_TREE_6)) ProcMapBegin();
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_A)) ProcMapLow();
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_B)) ProcMapDraw();
    new (Proc_Start(ProcScr_020ce750, PROC_TREE_C)) ProcMapEnd();

    return;
}

EC void func_ov000_021a2540(void * arg_0, s32 arg_1)
{
    if (arg_0 != 0)
    {
        func_ov000_021a2eb0((struct UnkBuf_Func_02049564 *)arg_0, arg_1);
    }
    else
    {
        func_ov000_021a2918(data_ov000_021e3324.unk_04);
    }

    func_ov000_021a29f4(data_ov000_021e3324.unk_04);

    return;
}

EC void func_ov000_021a2574(void)
{
    func_ov000_021a4718();
    func_ov000_021d4094();

    func_ov000_021b9bec(data_ov000_021e3324.unk_04->unk_14);

    Proc_EndEachMarked(PROC_MARK_6);

    if (data_ov000_021e334c != NULL)
    {
        delete data_ov000_021e334c;
    }
    data_ov000_021e334c = NULL;

    func_ov000_021d492c();
    func_020424ac();

    if (data_ov000_021e3324.unk_04 != NULL)
    {
        delete data_ov000_021e3324.unk_04;
    }
    data_ov000_021e3324.unk_04 = NULL;

    func_0204000c();

    data_02196f0c->unk_0c &= ~0x4;

    return;
}

// func_ov000_021a2620
UnkStruct_021E3324_04::UnkStruct_021E3324_04()
{
    func_ov000_021a8304();

    this->unk_00 = new UnkStruct_021E3324_04_00;
    this->unk_04 = new UnkStruct_021E3324_04_04;

    this->unk_08 = (UnkStruct_021E3324_04_08 *)func_02000c70();
    this->unk_0c = new struct UnkStruct_021E3324_04_0C;
    this->unk_10 = new struct UnkStruct_021E3324_04_10;

    this->unk_14 = new UnkStruct_021E3324_04_14;
    this->unk_18 = NULL;
    this->unk_1c = NULL;

    func_ov002_021f212c();
}

// func_ov000_021a26e8
UnkStruct_021E3324_04::~UnkStruct_021E3324_04()
{
    func_ov002_021f2160();

    if (this->unk_1c != NULL)
    {
        func_ov000_021a32c8();
    }

    if (this->unk_18 != NULL)
    {
        func_020379c0();
    }

    func_ov000_021a83d0();

    delete this->unk_00;
    delete this->unk_04;
    delete this->unk_0c;
    delete this->unk_10;

    delete this->unk_14;

    func_020377e8("Map");
    func_020379c0();
}

/* NONMATCHING: https://decomp.me/scratch/caqO6 */
EC void func_ov000_021a276c(struct UnkStruct_021E3324_04 * self, char * mapName)
{
    struct MapData * pMapData;
    s32 i;
    s16 x;
    s16 y;

    func_020a8f40("/map\0\0\0");

    pMapData = func_020379e0(mapName, 0);

    self->unk_20 = pMapData->unk_0c;
    self->unk_22 = pMapData->unk_0d;

    self->unk_24 = 1;
    self->unk_25 = 1;

    self->unk_26 = self->unk_20 - 1;
    self->unk_27 = self->unk_22 - 1;

    self->unk_eb8 = 0;

    for (i = 0; i < 4; i++)
    {
        self->unk_eb0[i] = -1;
        self->unk_eb4[i] = -1;
    }

    data_ov000_021e3324.unk_04->unk_828 = pMapData->unk_10;
    data_ov000_021e3324.unk_04->unk_82c = pMapData->unk_14;

    for (y = data_ov000_021e3324.unk_04->unk_25; y < data_ov000_021e3324.unk_04->unk_27; y++)
    {
        for (x = data_ov000_021e3324.unk_04->unk_24; x < data_ov000_021e3324.unk_04->unk_26; x++)
        {
            if (data_ov000_021e3324.unk_04->unk_82c[x | y << 5] != 0)
            {
                data_ov000_021e3324.unk_04->unk_82c[x | y << 5] |= 0x80;
            }
        }
    }

    func_020a8f40("/dispos");

    if (func_0201160c(mapName) != 0)
    {
        self->unk_18 = func_020379e0(mapName, 1);
    }

    func_ov000_021b95e8(data_ov000_021e3324.unk_04->unk_14);

    return;
}

EC void func_ov000_021a28cc(struct UnkStruct_021E3324_04 * self)
{
    func_ov000_021a4a7c(data_ov000_021e3324.unk_04->unk_00);
    func_ov000_021a5318(data_ov000_021e3324.unk_04->unk_0c);
    func_ov000_021a68c0(data_ov000_021e3324.unk_04->unk_10);
    func_ov000_021b9a10(data_ov000_021e3324.unk_04->unk_14);
    return;
}

EC void func_ov000_021a2918(struct UnkStruct_021E3324_04 * self)
{
    s32 i;

    if (func_ov000_021a478c() == 0)
    {
        for (i = 0; i < 2; i++)
        {
            if (i == 0)
            {
                data_ov000_021e3320[i] = 1;
            }
            else
            {
                data_ov000_021e3320[i] = 2;
            }
        }
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            if (i == func_02012478())
            {
                data_ov000_021e3320[i] = 1;
            }
            else
            {
                data_ov000_021e3320[i] = 3;
            }
        }
    }

    data_ov000_021e3324.unk_00->unk_01 = 0;

    for (i = 0; i < 2; i++)
    {
        if (data_ov000_021e3320[i] == 1)
        {
            data_ov000_021e3324.unk_00->unk_01 = i;
            break;
        }
    }

    func_ov000_021a3364();
    func_02000c7c(data_ov000_021e3324.unk_04->unk_08);
    func_ov000_021a37c4();
    func_ov000_021a340c();
    func_ov000_021a35a0();

    return;
}

EC void func_ov000_021a29f4(struct UnkStruct_021E3324_04 * self)
{
    struct Unit ** pUnitStack;
    struct Unit * it;
    s32 i;

    for (i = 0; i < 2; i++)
    {
        pUnitStack = func_02040c98(i);

        for (it = *pUnitStack; it != NULL; it = (struct Unit *)it->unk_3c)
        {
            func_ov000_021baafc(data_ov000_021e3324.unk_04->unk_14->unk_00, it, 1);
        }
    }

    return;
}

EC BOOL func_ov000_021a2a50(struct UnkStruct_021E3324_00 * self)
{
    BOOL flag;
    s32 i;

    self->phase++;

    if (self->phase == 2)
    {
        if ((self->unk_06 != 0) && (self->turn >= self->unk_06))
        {
            return FALSE;
        }

        self->phase = 0;
        self->turn++;

        if (self->turn > 999)
        {
            self->turn = 999;
        }
    }

    flag = FALSE;

    for (i = 0; i < 2; i++)
    {
        if (data_ov000_021e3320[i] == 1)
        {
            flag = TRUE;
            break;
        }
    }

    if ((!flag) || (data_ov000_021e3320[self->phase] == 1))
    {
        self->unk_01 = self->phase;
    }

    return TRUE;
}

/* NONMATCHING: https://decomp.me/scratch/NXh8g */
EC void func_ov000_021a2b08(struct UnkBuf_Func_02049564 * buf)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        buf->WriteByte(data_ov000_021e3320[i]);
    }

    buf->WriteByte(data_ov000_021e3324.unk_00->phase);
    buf->WriteByte(data_ov000_021e3324.unk_00->unk_01);
    buf->WriteShort(data_ov000_021e3324.unk_00->turn);
    buf->WriteShort(data_ov000_021e3324.unk_00->unk_06);
    buf->WriteWord(data_ov000_021e3324.unk_00->unk_08);
    buf->WriteWord(data_ov000_021e3324.unk_00->unk_0c);
    buf->WriteByte(data_ov000_021e3324.unk_00->unk_02);
    buf->WriteByte(data_ov000_021e3324.unk_00->unk_03);

    func_020a58b8(data_ov000_021e3324.unk_04->unk_db0, buf->unk_04, 0x80);
    buf->unk_04 += 0x80;
    func_020a58b8(data_ov000_021e3324.unk_04->unk_d30, buf->unk_04, 0x80);
    buf->unk_04 += 0x80;

    buf->WriteShort(data_ov000_021e3324.unk_04->unk_00->unk_14);
    buf->WriteShort(data_ov000_021e3324.unk_04->unk_00->unk_16);
    buf->WriteByte(data_ov000_021e3324.unk_04->unk_10->unk_08);
    buf->WriteByte(data_ov000_021e3324.unk_04->unk_10->unk_09);

    for (i = 0; i < 2; i++)
    {
        buf->WriteByte(data_ov000_021e3324.unk_04->unk_10->unk_00[i]);
        buf->WriteByte(data_ov000_021e3324.unk_04->unk_10->unk_02[i]);
    }

    for (i = 0; i < 4; i++)
    {
        buf->WriteByte(data_ov000_021e3324.unk_04->unk_eb0[i]);
        buf->WriteByte(data_ov000_021e3324.unk_04->unk_eb4[i]);
    }

    func_ov000_021d537c(buf);

    for (i = 0; i < 4; i++)
    {
        buf->WriteByte(data_ov000_021e3324.unk_00->unk_18[i]);
    }

    buf->WriteByte(data_ov000_021e3324.unk_00->unk_1c);

    return;
}

/* NONMATCHING: https://decomp.me/scratch/xLJJS */
EC void func_ov000_021a2eb0(struct UnkBuf_Func_02049564 * buf, s32 arg_1)
{
    s32 i;

    s32 word;

    s16 unk_14;
    s16 unk_16;

    for (i = 0; i < 2; i++)
    {
        data_ov000_021e3320[i] = buf->ReadByte();
    }

    data_ov000_021e3324.unk_00->phase = buf->ReadByte();
    data_ov000_021e3324.unk_00->unk_01 = buf->ReadByte();

    data_ov000_021e3324.unk_00->turn = buf->ReadShort();
    data_ov000_021e3324.unk_00->unk_06 = buf->ReadShort();

    word = buf->ReadWord();
    func_ov000_021a48b0(word);

    data_ov000_021e3324.unk_00->unk_0c = buf->ReadWord();

    data_ov000_021e3324.unk_00->unk_02 = buf->ReadByte();
    data_ov000_021e3324.unk_00->unk_03 = buf->ReadByte();

    func_ov000_021a37c4();

    func_020a58b8(buf->unk_04, data_ov000_021e3324.unk_04->unk_db0, 0x80);
    buf->unk_04 += 0x80;

    func_020a58b8(buf->unk_04, data_ov000_021e3324.unk_04->unk_d30, 0x80);
    buf->unk_04 += 0x80;

    unk_14 = buf->ReadShort();
    unk_16 = buf->ReadShort();
    data_ov000_021e3324.unk_04->unk_00->unk_14 = unk_14;
    data_ov000_021e3324.unk_04->unk_00->unk_16 = unk_16;

    func_ov000_021a52c8(
        data_ov000_021e3324.unk_04->unk_00, data_ov000_021e3324.unk_04->unk_00->unk_14,
        data_ov000_021e3324.unk_04->unk_00->unk_16, 0);

    func_ov000_021a6ab8(data_ov000_021e3324.unk_04->unk_10, buf->ReadByte(), buf->ReadByte());

    for (i = 0; i < 2; i++)
    {
        s32 tmp = buf->ReadByte();
        s32 tmp2 = buf->ReadByte();
        data_ov000_021e3324.unk_04->unk_10->unk_00[i] = tmp;
        data_ov000_021e3324.unk_04->unk_10->unk_02[i] = tmp2;
    }

    if (arg_1 >= 4)
    {
        for (i = 0; i < 4; i++)
        {
            s8 tmp = buf->ReadByte();
            s8 tmp2 = buf->ReadByte();
            if (tmp != -1)
            {
                func_ov000_021d4004(tmp, tmp2);
            }
        }
    }

    func_ov000_021d5528(buf, arg_1);
    func_ov000_021a3364();
    func_02000c7c(data_ov000_021e3324.unk_04->unk_08);
    func_ov000_021a340c();
    func_ov000_021a35a0();

    if (arg_1 < 3)
    {
        buf->unk_04 += 0x805;
    }

    if (arg_1 >= 1)
    {
        for (i = 0; i < 4; i++)
        {
            data_ov000_021e3324.unk_00->unk_18[i] = buf->ReadByte();
        }
    }

    if (arg_1 < 2)
    {
        return;
    }

    data_ov000_021e3324.unk_00->unk_1c = buf->ReadByte();

    return;
}

EC void func_ov000_021a323c(void)
{
    if (data_ov000_021e3324.unk_04->unk_1c != NULL)
    {
        return;
    }

    func_ov000_021a4718();

    data_ov000_021e3324.unk_04->unk_1c = new UnkStruct_021E3324_04_1C;

    func_02040094(data_ov000_021e3324.unk_04->unk_1c, -1);
    data_ov000_021e3324.unk_04->unk_1c->unk_04 = data_ov000_021e3324.unk_04->unk_1c->unk_00;

    return;
}

EC void func_ov000_021a32c8(void)
{
    if (data_ov000_021e3324.unk_04->unk_1c == NULL)
    {
        return;
    }

    func_ov000_021a4718();

    func_020401d8(data_ov000_021e3324.unk_04->unk_1c, -1);

    delete data_ov000_021e3324.unk_04->unk_1c;
    data_ov000_021e3324.unk_04->unk_1c = NULL;

    func_ov000_021a37c4();
    func_ov000_021a340c();
    func_ov000_021babf4(data_ov000_021e3324.unk_04->unk_14->unk_00);

    return;
}

EC void func_ov000_021a3364(void)
{
    s16 x;
    s16 y;

    for (y = 0; y < data_ov000_021e3324.unk_04->unk_22; y++)
    {
        for (x = 0; x < data_ov000_021e3324.unk_04->unk_20; x++)
        {
            u8 tile = data_ov000_021e3324.unk_04->unk_828[x | (y << 5)];
            data_ov000_021e3324.unk_04->unk_830[x | (y << 5)] = func_02038248(data_02197254->pTerrain[tile].unk_08);
        }
    }
}

EC void func_ov000_021a340c(void)
{
    struct Unit ** pUnitStack;
    s32 i;
    struct Unit * it;

    func_020a5734(0, data_ov000_021e3324.unk_04->unk_028, 0x400);
    func_020a5734(0, data_ov000_021e3324.unk_04->unk_428, 0x400);

    for (i = 0; i < 2; i++)
    {
        pUnitStack = func_02040c98(i);
        for (it = *pUnitStack; it != 0; it = (struct Unit *)(it->unk_3c))
        {
            func_ov000_021a3498(it, 0, -1, -1);
        }
    }

    return;
}

EC void func_ov000_021a3498(struct Unit * unit, BOOL arg_1, u32 x, u32 y)
{
    if (x == -1)
    {
        x = unit->xPos;
    }

    if (y == -1)
    {
        y = unit->yPos;
    }

    if (((unit->state2 & 0x21000) != 0) && (arg_1 == 0))
    {
        return;
    }

    if (!(unit->state2 & 0x20))
    {
        u32 pos = (x | (y << 5));
        if (((data_ov000_021e3324.unk_04->unk_d30[pos >> 3] & (1 << (pos & 7))) & 0xFF) || (unit->state2 & 0x4000) ||
            (((unit->unk_4c->unk_08 == data_ov000_021e3324.unk_00->unk_01) & 0xFF) != 0))
        {
            data_ov000_021e3324.unk_04->unk_028[x | y << 5] = unit->unk_68;
        }
    }

    data_ov000_021e3324.unk_04->unk_428[x | y << 5] = unit->unk_68;

    return;
}

/* NONMATCHING: https://decomp.me/scratch/kRxMD */
EC void func_ov000_021a354c(struct Unit * unit, s32 x, s32 y)
{
    if (x == -1)
    {
        x = unit->xPos;
    }

    if (y == -1)
    {
        y = unit->yPos;
    }

    if (data_ov000_021e3324.unk_04->unk_428[x | y << 5] == unit->unk_68)
    {
        data_ov000_021e3324.unk_04->unk_028[x | y << 5] = 0;
        data_ov000_021e3324.unk_04->unk_428[x | y << 5] = 0;
    }

    return;
}

static inline BOOL TestPhaseAndState(struct Unit * unit, u32 phase)
{
    if (unit->state2 & 0x21020)
    {
        return TRUE;
    }

    if (phase == unit->unk_4c->unk_08)
    {
        return TRUE;
    }

    return FALSE;
}

/* NONMATCHING: https://decomp.me/scratch/Aqu4T */
EC void func_ov000_021a35a0(void)
{
    struct Unit ** pUnitStack;
    struct Unit * it;
    s32 i;
    u32 phase = data_ov000_021e3324.unk_00->unk_01;

    func_020a5734(0, data_ov000_021e3324.unk_04->unk_c30, 0x80);
    func_020a5734(0, data_ov000_021e3324.unk_04->unk_cb0, 0x80);

    for (i = 0; i < 2; i++)
    {
        pUnitStack = func_02040c98(i);

        for (it = *pUnitStack; it != NULL; it = (struct Unit *)it->unk_3c)
        {
            if (!TestPhaseAndState(it, phase))
            {
                if ((data_ov000_021e3324.unk_04->unk_d30[(it->xPos | it->yPos << 5) >> 3] & (1 << (it->xPos & 7))) &
                    0xFF)
                {
                    continue;
                }

                if (!(it->state2 & 0x4000))
                {
                    continue;
                }

                if (data_ov000_021e3324.unk_00->unk_03 != 0)
                {
                    continue;
                }

                if (!(it->state2 & 0x2000))
                {
                    continue;
                }

                func_ov000_021a36f8(it, TRUE, FALSE);
            }
        }
    }

    data_ov000_021e3324.unk_04->unk_14->unk_04->unk_17 = 1;
    data_ov000_021e3324.unk_04->unk_eb8 = 0;

    return;
}

EC void func_ov000_021a36e0(void)
{
    data_ov000_021e3324.unk_04->unk_eb8 = 1;
    return;
}

EC void func_ov000_021a36f8(struct Unit * unit, BOOL arg_1, BOOL arg_2)
{
    if (arg_1 != 0)
    {
        func_01ff8d88(data_ov000_021e3324.unk_04->unk_08, unit, -1, 2, 1, 1);
    }

    func_01ff9758(data_ov000_021e3324.unk_04->unk_08, data_ov000_021e3324.unk_04->unk_c30);
    func_01ff976c(data_ov000_021e3324.unk_04->unk_08, data_ov000_021e3324.unk_04->unk_cb0);

    if (arg_2 != 0)
    {
        data_ov000_021e3324.unk_04->unk_14->unk_04->unk_17 = 1;
    }

    return;
}

EC void func_ov000_021a378c(void)
{
    func_0201db38((void *)func_ov000_021a35a0, 7, 0x12, 0x1000, 0);
    return;
}

EC BOOL func_ov000_021a37b4(void)
{
    return func_0201dc30(7);
}

EC void func_ov000_021a37c4(void)
{
    if (data_ov000_021e3324.unk_00->unk_02 == 0)
    {
        func_020a5824(data_ov000_021e3324.unk_04->unk_db0, 0xff, 0x80);
        func_020a5824(data_ov000_021e3324.unk_04->unk_d30, 0xff, 0x80);
        return;
    }

    func_020a5824(data_ov000_021e3324.unk_04->unk_db0, 0, 0x80);
    func_020a5824(data_ov000_021e3324.unk_04->unk_d30, 0, 0x80);

    if (data_02196f0c->unk_0c & 0x40)
    {
        func_ov000_021a3a30(data_ov000_021e3324.unk_04->unk_d30, data_ov000_021e3324.unk_00->unk_01);
    }
    else
    {
        func_ov000_021a3974(data_ov000_021e3324.unk_04->unk_d30, data_ov000_021e3324.unk_00->unk_01);
    }

    func_ov000_021a3974(data_ov000_021e3324.unk_04->unk_db0, data_ov000_021e3324.unk_00->phase);
    data_ov000_021e3324.unk_04->unk_14->unk_04->unk_18 = 1;

    return;
}

EC void func_ov000_021a38b4(void)
{
    if (data_ov000_021e3324.unk_00->unk_02 == 0)
    {
        func_020a5824(data_ov000_021e3324.unk_04->unk_d30, 0xff, 0x80);
        return;
    }

    func_020a5824(data_ov000_021e3324.unk_04->unk_d30, 0, 0x80);

    if (data_02196f0c->unk_0c & 0x40)
    {
        func_ov000_021a3a30(data_ov000_021e3324.unk_04->unk_d30, data_ov000_021e3324.unk_00->unk_01);
    }
    else
    {
        func_ov000_021a3974(data_ov000_021e3324.unk_04->unk_d30, data_ov000_021e3324.unk_00->unk_01);
    }

    func_ov000_021a3974(data_ov000_021e3324.unk_04->unk_db0, data_ov000_021e3324.unk_00->phase);
    data_ov000_021e3324.unk_04->unk_14->unk_04->unk_18 = 1;

    return;
}

EC void func_ov000_021a3974(u8 * arg_0, s32 arg_1)
{
    struct Unit ** pUnitStack;
    s32 i;
    struct Unit * it;

    if (data_ov000_021e3324.unk_00->unk_02 == 0)
    {
        return;
    }

    for (i = 0; i < 2; i++)
    {
        if (!((arg_1 == i) & 0xFF))
        {
            continue;
        }

        pUnitStack = func_02040c98(i);

        for (it = *pUnitStack; it != NULL; it = (struct Unit *)it->unk_3c)
        {
            if ((it->state2 & 0x21020) == 0)
            {
                func_ov000_021a3c20(arg_0, arg_1, it);
            }
        }
    }

    if (arg_0 == data_ov000_021e3324.unk_04->unk_d30)
    {
        data_ov000_021e3324.unk_04->unk_14->unk_04->unk_18 = 1;
        return;
    }

    return;
}

/* NONMATCHING: https://decomp.me/scratch/a3Clg */
EC void func_ov000_021a3c84(u8 * arg_0, s32 arg_1, s32 arg_2, s16 arg_3, s16 arg_4, s32 arg_5, s32 arg_6, u8 * arg_7)
{
    u8 tmp;
    s32 increment;

    if (data_ov000_021e3324.unk_00->unk_02 == 0)
    {
        return;
    }

    if (!((arg_2 == arg_1) & 0xFF))
    {
        return;
    }

    while ((tmp = *arg_7 & 0x80) == 0)
    {
        func_ov000_021a3ad0(arg_0, arg_3, arg_4, arg_5);

        switch (*arg_7)
        {
            case 1:
                increment = -1;
                break;
            case 2:
                increment = +1;
                break;
            default:
                increment = 0;
                break;
        }

        arg_3 += increment;

        switch (*arg_7)
        {
            case 4:
                increment = +1;
                break;
            case 8:
                increment = -1;
                break;
            default:
                increment = 0;
                break;
        }

        arg_4 += increment;

        arg_7++;
    }

    func_ov000_021a3ad0(arg_0, arg_3, arg_4, arg_6);

    return;
}

EC void func_ov000_021a3a30(u8 * arg_0, u32 arg_1)
{
    s8 * it;
    s32 i;
    s32 j;

    u32 r6;
    r6 = GetJobByJidStr("JID_LORD\0\0\0")->unk_2a;

    if (data_ov000_021e3324.unk_00->unk_02 == 0)
    {
        return;
    }

    i = 0;
    if (0 < data_ov000_021e3528.unk_2e)
    {
        it = data_ov000_021e3528.unk_00;
        j = 0;
        do
        {
            func_ov000_021a3ad0(arg_0, it[j], it[j + 1], r6);
            i++;
            j += 2;
        } while (i < data_ov000_021e3528.unk_2e);
    }

    if (arg_0 != data_ov000_021e3324.unk_04->unk_d30)
    {
        return;
    }

    data_ov000_021e3324.unk_04->unk_14->unk_04->unk_18 = 1;

    return;
}

EC void func_ov000_021a3ad0(u8 * arg_0, s16 x, s16 y, s32 range)
{
    s16 ix;
    s16 iy;
    s16 xMin;
    s16 yMin;
    s16 xMax;
    s16 yMax;

    if (data_ov000_021e3324.unk_00->unk_02 == 0)
    {
        return;
    }

    xMin = MAX(x - range, data_ov000_021e3324.unk_04->unk_24);
    yMin = MAX(y - range, data_ov000_021e3324.unk_04->unk_25);

    xMax = MIN(x + range, data_ov000_021e3324.unk_04->unk_26 - 1);
    yMax = MIN(y + range, data_ov000_021e3324.unk_04->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            s32 dy = ABS(y - iy);
            s32 dx = ABS(x - ix);

            if (dx + dy >= 0 && dx + dy <= range)
            {
                u32 pos = (ix | (iy << 5));
                arg_0[pos >> 3] |= (1 << (pos & 7));
            }
        }
    }

    if (arg_0 == data_ov000_021e3324.unk_04->unk_d30)
    {
        data_ov000_021e3324.unk_04->unk_14->unk_04->unk_18 = 1;
    }
}

EC void func_ov000_021a3c20(u8 * arg_0, s32 arg_1, struct Unit * unit)
{
    s32 y;
    s32 x;

    if (data_ov000_021e3324.unk_00->unk_02 == 0)
    {
        return;
    }

    if (!((unit->unk_4c->unk_08 == arg_1) & 0xFF))
    {
        return;
    }

    y = unit->yPos;
    x = unit->xPos;

    func_ov000_021a3ad0(arg_0, x, y, func_ov000_021a4854(unit));

    return;
}

EC BOOL func_ov000_021a3d7c(u32 faction)
{
    return (faction == data_ov000_021e3324.unk_00->unk_01) & 0xFF;
}

EC BOOL func_ov000_021a3da0(struct Unit * unit)
{
    return func_ov000_021a3d7c(unit->unk_4c->unk_08);
}

/* NONMATCHING: https://decomp.me/scratch/EKthD */
EC BOOL func_ov000_021a3db4(s16 x, s16 y, BOOL arg_2)
{
    s16 xMax;
    s16 xMin;
    s16 yMax;
    s16 yMin;
    s16 ix;
    s16 iy;

    xMin = MAX(x - 1, data_ov000_021e3324.unk_04->unk_24);
    yMin = MAX(y - 1, data_ov000_021e3324.unk_04->unk_25);

    xMax = MIN(x + 1, data_ov000_021e3324.unk_04->unk_26 - 1);
    yMax = MIN(y + 1, data_ov000_021e3324.unk_04->unk_27 - 1);

    for (iy = yMin; iy <= yMax; iy++)
    {
        for (ix = xMin; ix <= xMax; ix++)
        {
            s32 val = ABS(x - ix) + ABS(y - iy);

            if (val >= 1 && val <= 1)
            {
                if (arg_2)
                {
                    if (data_ov000_021e3324.unk_04->unk_08->unk_854[ix | (iy << 5)] != 0 &&
                        data_ov000_021e3324.unk_04->unk_028[ix | (iy << 5)] != 0)
                    {
                        continue;
                    }
                }

                if (data_ov000_021e3324.unk_04->unk_08->unk_854[ix | (iy << 5)] >= 0)
                {
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

/* NONMATCHING: https://decomp.me/scratch/fz686 */
EC void func_ov000_021a3ee4(struct Unit * unit, s32 arg_1)
{
    s32 i;
    struct Unit ** pUnitStack;
    struct PersonData * pPersonDataB;
    struct PersonData * pPersonDataA;
    struct Unit * it;

    func_020a5734(0, data_ov000_021e3324.unk_04->unk_e30, 0x80);

    if (func_ov000_021a47e4() != 0)
    {
        return;
    }

    for (i = 0; i < 2; i++)
    {
        pUnitStack = func_02040c98(i);
        for (it = *pUnitStack; it != NULL; it = (struct Unit *)it->unk_3c)
        {
            if (data_ov000_021e3324.unk_04->unk_db0[(it->xPos | it->yPos << 5) >> 3] & ((1 << it->xPos) & 7))
            {
                pPersonDataA = func_0203c378(it)->pPersonData;
                pPersonDataB = func_0203c378(unit)->pPersonData;

                if (!_ZN11EventCaller13func_02048610EPcS0_(pPersonDataA->unk_00, pPersonDataB->unk_00))
                {
                    continue;
                }

                if (!func_ov000_021a3db4(it->xPos, it->yPos, arg_1))
                {
                    continue;
                }

                data_ov000_021e3324.unk_04->unk_e30[(it->xPos | it->yPos << 5) >> 3] |= ((1 << it->xPos) & 7);
            }
        }
    }

    return;
}

static inline BOOL IsOutOfBounds(s32 x, s32 y)
{
    if (x < 0)
    {
        return TRUE;
    }

    if (y < 0)
    {
        return TRUE;
    }

    if (x >= data_ov000_021e3324.unk_04->unk_20)
    {
        return TRUE;
    }

    if (y >= data_ov000_021e3324.unk_04->unk_22)
    {
        return TRUE;
    }

    return FALSE;
}

EC void * func_ov000_021a418c(s32 arg_0)
{
    struct Unit * unit;

    if (data_ov000_021e3324.unk_04 == NULL)
    {
        return NULL;
    }

    if (arg_0 != 0)
    {
        unit = func_0203fff4(arg_0, 3);
    }
    else
    {
        unit = data_021974f0;
    }

    if (unit == NULL)
    {
        return NULL;
    }

    if (!IsOutOfBounds(unit->xPos, unit->yPos))
    {
        u8 tile = data_ov000_021e3324.unk_04->unk_828[unit->xPos | (unit->yPos << 5)];
        return data_02197254->pTerrain[tile].unk_04;
    }

    return NULL;
}

EC s32 func_ov000_021a4254(s32 arg_0)
{
    u32 unk;

    if (data_02196f24->unk_07 == 0)
    {
        return -1;
    }

    if (data_02196f0c->unk_0c & 0x40)
    {
        return 0x2f;
    }

    unk = 0;

    if (data_ov000_021e3324.unk_00->unk_02 != 0)
    {
        unk = 1;
    }

    if (data_02196f0c->unk_0c & 0x20)
    {
        if (data_ov000_021e3320[arg_0] == 1)
        {
            if (func_ov000_021a4360(arg_0))
            {
                unk = 2;
            }

            return data_ov000_021db73c[data_02196f0c->unk_00->unk_18[unk]];
        }

        return data_ov000_021db75c[data_02196f0c->unk_00->unk_18[unk]];
    }

    if (arg_0 == 0)
    {
        if (func_ov000_021a4360(arg_0))
        {
            unk = 2;
        }

        return data_ov000_021db73c[data_02196f0c->unk_00->unk_18[unk]];
    }

    return data_ov000_021db75c[data_02196f0c->unk_00->unk_18[unk]];
}

EC BOOL func_ov000_021a4360(u32 arg_0)
{
    struct Unit ** pUnitStack;
    struct Unit * it;
    s32 count = 0;
    s32 i;

    if ((data_02196f0c->unk_0c & 0x400) != 0)
    {
        return FALSE;
    }

    for (i = 0; i < 2; i++)
    {
        if ((arg_0 == i) & 0xFF)
        {
            continue;
        }

        pUnitStack = func_02040c98(i);
        for (it = *pUnitStack; it != NULL; it = (struct Unit *)it->unk_3c)
        {
            count++;
        }
    }

    return count <= 0;
}

EC void func_ov000_021a43e8(void)
{
    s32 iVar1 = func_ov000_021a4254(data_ov000_021e3324.unk_00->phase);

    data_020efcc8->unk_a8->vfunc_6c(0x7f);

    if (iVar1 == -1)
    {
        return;
    }

    if (data_020efcc8->unk_a8->vfunc_50())
    {
        if (_ZN11FlagManager9GetByNameEPc(data_02196f0c->unk_04, "gf_complete"))
        {
            func_02017b40(data_020efcc8->unk_a4, data_020efcc8->unk_a8, 0x10);
            return;
        }

        if ((data_020efcc8->unk_a4->vfunc_58() || (iVar1 != data_020efcc8->unk_a4->unk_08)))
        {
            func_02017938(data_020efcc8->unk_a4, data_020efcc8->unk_a8, 0x10, iVar1, 0);
        }
        else
        {
            func_0201775c(data_020efcc8->unk_a4, data_020efcc8->unk_a8, 0x10, 0x10);
        }

        return;
    }

    if (_ZN11FlagManager9GetByNameEPc(data_02196f0c->unk_04, "gf_complete"))
    {
        data_020efcc8->unk_a4->vfunc_38(0x10);
        return;
    }

    if (iVar1 != data_020efcc8->unk_a4->unk_08)
    {
        data_020efcc8->unk_a4->vfunc_3c(0x10, iVar1, 0);
    }
    else
    {
        if (data_020efcc8->unk_a4->vfunc_54())
        {
            data_020efcc8->unk_a4->vfunc_4c(0x10);
        }
    }

    return;
}

EC void func_ov000_021a45cc(struct Unit * unit, u32 arg_1)
{
    if (!_ZN11FlagManager9GetByNameEPc(data_02196f0c->unk_04, "gf_complete"))
    {
        if (func_ov000_021adabc(unit, 0) != 0)
        {
            if ((arg_1 == 0 || !func_ov000_021a98ec(unit->xPos, unit->yPos)))
            {
                if (data_020efcc8->unk_a8->vfunc_50() != 0)
                {
                    func_02017b40(data_020efcc8->unk_a4, data_020efcc8->unk_a8, 0x10);
                    return;
                }

                data_020efcc8->unk_a4->vfunc_38(0x10);

                return;
            }
        }
    }

    func_ov000_021a43e8();

    return;
}

EC void func_ov000_021a4694(void)
{
    func_ov000_021a45cc(data_ov000_021e3324.unk_04->unk_04->unk_00, 1);
    return;
}

EC void func_ov000_021a46b8(void)
{
    func_ov000_021a45cc(NULL, 0);
    return;
}

/* NONMATCHING: https://decomp.me/scratch/DvhHi */
EC void func_ov000_021a46cc(struct Unit * unit, u32 arg_1)
{
    func_ov000_021a6ab8(data_ov000_021e3324.unk_04->unk_10, unit->xPos, unit->yPos);
    func_ov000_021a4e84(data_ov000_021e3324.unk_04->unk_00, unit->xPos, unit->yPos, arg_1);
    return;
}

EC void func_ov000_021a4718(void)
{
    return;
}

EC BOOL func_ov000_021a471c(void)
{
    if (data_ov000_021e3324.unk_04 == 0)
    {
        return FALSE;
    }

    if (func_ov000_021a475c() != 0)
    {
        return TRUE;
    }

    return func_ov000_021a47ac() != 0;
}

EC BOOL func_ov000_021a475c(void)
{
    if (data_ov000_021e3324.unk_00->unk_0c == 0)
    {
        return FALSE;
    }

    if (data_ov000_021e3324.unk_00->unk_08 == 0)
    {
        return TRUE;
    }

    return FALSE;
}

EC BOOL func_ov000_021a478c(void)
{
    return (data_02196f0c->unk_0c & 0x20) != 0;
}

EC BOOL func_ov000_021a47ac(void)
{
    if (func_ov000_021a478c() == 0)
    {
        return FALSE;
    }

    if (func_02012298() != 0)
    {
        return TRUE;
    }

    return func_02012584() != 0;
}

EC BOOL func_ov000_021a47e4(void)
{
    return (data_02196f0c->unk_0c & 0x10000) != 0;
}

/* NONMATCHING: https://decomp.me/scratch/VvUaN */
EC BOOL func_ov000_021a4804(void)
{
    if (func_ov000_021a47e4() == 0)
    {
        return FALSE;
    }

    if (data_02196f10->unk_0b == 0)
    {
        return FALSE;
    }

    if (((data_02196f10->unk_00 != 0) & 0xFF) == 0)
    {
        return FALSE;
    }

    return TRUE;
}

EC s32 func_ov000_021a4854(struct Unit * unit)
{
    s32 range;
    s32 i;
    BOOL bVar1;
    struct UnkStruct_Func_02021410_Ret * iVar4;

    range = func_0203c790(unit);

    if (func_ov000_021a4804() != 0)
    {
        bVar1 = FALSE;

        for (i = 0; i < 2; i++)
        {
            iVar4 = func_02021410(i);

            if (iVar4->unk_756 == 0x11)
            {
                bVar1 = TRUE;
                break;
            }
        }

        if ((bVar1) && (range > 1))
        {
            range = 1;
        }
    }

    return range;
}

EC void func_ov000_021a48b0(u32 arg_0)
{
    data_ov000_021e3324.unk_00->unk_08 = arg_0;
    data_ov000_021e3324.unk_00->unk_10 = data_027e1264;
    return;
}

EC void func_ov000_021a48d8(void)
{
    s32 iVar1 = data_027e1264;
    s32 uVar3 = iVar1 - data_ov000_021e3324.unk_00->unk_10;

    if (data_ov000_021e3324.unk_00->unk_08 > uVar3)
    {
        data_ov000_021e3324.unk_00->unk_08 = data_ov000_021e3324.unk_00->unk_08 - uVar3;
    }
    else
    {
        data_ov000_021e3324.unk_00->unk_08 = 0;
    }

    data_ov000_021e3324.unk_00->unk_10 = iVar1;

    return;
}

EC BOOL func_ov000_021a491c(struct Unit * unit)
{
    if (func_ov000_021a478c() != 0)
    {
        return FALSE;
    }

    if (func_ov000_021a47e4() != 0)
    {
        return FALSE;
    }

    if (unit->unk_4c->unk_08 >= 2)
    {
        return TRUE;
    }

    return data_ov000_021e3320[unit->unk_4c->unk_08] == 1;
}

// func_ov000_021a4974
void ProcMapEnd::Init(void)
{
    func_ov000_021b9bec(data_ov000_021e3324.unk_04->unk_14);
    return;
}

// func_ov000_021a4990
void ProcMapDraw::Init(void)
{
    func_ov000_021b9c3c(data_ov000_021e3324.unk_04->unk_14);
    return;
}

// func_ov000_021a49ac
void ProcMapLow::Init(void)
{
    func_ov000_021a6e68(data_ov000_021e3324.unk_04->unk_10);
    func_ov000_021b9bc4(data_ov000_021e3324.unk_04->unk_14);
    func_ov000_021a5128(data_ov000_021e3324.unk_04->unk_00);

    if (data_ov000_021e3324.unk_04->unk_eb8 == 0)
    {
        return;
    }

    func_ov000_021a35a0();

    return;
}

// func_ov000_021a4a00
void ProcMapBegin::Init(void)
{
    func_ov000_021b9bac(data_ov000_021e3324.unk_04->unk_14);
    return;
}

// func_ov000_021a4a1c
// func_ov000_021a4a20
ProcMapBegin::~ProcMapBegin()
{
    return;
}

// func_ov000_021a4a34
// func_ov000_021a4a38
ProcMapLow::~ProcMapLow()
{
    return;
}

// func_ov000_021a4a4c
// func_ov000_021a4a50
ProcMapDraw::~ProcMapDraw()
{
    return;
}

// func_ov000_021a4a64
// func_ov000_021a4a68
ProcMapEnd::~ProcMapEnd()
{
    return;
}
