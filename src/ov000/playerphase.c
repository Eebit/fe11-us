#include "global.h"

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unit.h"

extern struct ProcCmd data_ov000_021dbe58[];
extern struct ProcCmd data_ov000_021dc190[];
extern struct ProcFuncTable data_ov000_021dbd94;

struct UnkStruct_021e332c_14
{
    u8 unk_00;
    s8 unk_01;
    s8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
};

struct UnkStruct_021e332c
{
    ProcPtr unk_00[5];
    struct UnkStruct_021e332c_14 * unk_14;
};

extern struct UnkStruct_021e332c data_ov000_021e332c;

extern struct UnkStruct_02196f0c * data_02196f0c;

struct UnkStruct_021e3344
{
    STRUCT_PAD(0x00, 0x2C);
    s8 unk_2c;
    s8 unk_2d;
    u8 unk_2e;
    u8 unk_2f;
    s8 unk_30;
    s8 unk_31;
    s8 unk_32;
    u8 unk_33;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
};

extern struct UnkStruct_021e3344 * data_ov000_021e3344;

extern struct Unit * gUnitList;

struct PlayerPhaseProc
{
    PROC_HEADER
    u32 unk_38;
};

extern struct UnkStruct_02196f10 * data_02196f10;

struct UnkStruct_020ca620
{
    STRUCT_PAD(0x00, 0x12);
    u8 unk_12;
};

extern struct UnkStruct_020ca620 * data_020ca620;

extern vu32 data_027e1264;

struct PlayerPhaseProc * func_ov000_021ae1bc(void);
BOOL func_ov000_021a6ab8(void *, s16, s16);
BOOL func_ov000_021ac0c0(void);
void func_ov000_021aa278(s32);

static inline BOOL UNK_18_CHECK()
{
    return (data_ov000_021e3328->unk_00->unk_18 >= 2) ? TRUE : FALSE;
}

void func_ov000_021aa210(void)
{
    data_ov000_021e3328->unk_10->unk_0a = 1;

    Proc_Goto(data_ov000_021e332c.unk_00[4], 4, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    func_ov000_021d6e30(0);
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0xf);

    return;
}

// #func_ov000_021aa278

// #func_ov000_021aaad8

// #func_ov000_021aad64

// #func_ov000_021ab180

// #func_ov000_021ab4f0

// #func_ov000_021ab768

void func_ov000_021abbc8(void)
{
    struct Unit * pUnitA;
    int unitId;
    s16 ix;
    s16 iy;

    unitId = data_ov000_021e3344->unk_34;

    if (unitId != 0)
    {
        pUnitA = gUnitList + unitId - 1;
    }
    else
    {
        pUnitA = NULL;
    }

    func_02000d14(data_ov000_021e3328->unk_08, -1);

    for (iy = data_ov000_021e3328->unk_25; iy < data_ov000_021e3328->unk_27; iy++)
    {
        for (ix = data_ov000_021e3328->unk_24; ix < data_ov000_021e3328->unk_26; ix++)
        {
            struct Unit * pUnitB;

            if (ix == data_ov000_021e3344->unk_30 && iy == data_ov000_021e3344->unk_31)
            {
                continue;
            }

            if ((data_ov000_021e3328->unk_82c[(ix | iy << 5)] & 0x80) != 0)
            {
                continue;
            }

            if ((data_ov000_021e3328->unk_d30[((ix | iy << 5)) >> 3] & (1 << (ix & 7))) == 0)
            {
                continue;
            }

            unitId = data_ov000_021e3328->unk_28[(ix | iy << 5)];

            if (unitId != 0)
            {
                pUnitB = gUnitList + unitId - 1;
            }
            else
            {
                pUnitB = NULL;
            }

            if (pUnitB != NULL)
            {
                continue;
            }

            if (func_0203826c(
                    data_02197254->pTerrain[data_ov000_021e3328->unk_828[(ix | iy << 5)]].unk_08,
                    pUnitA->pJobData->unk_28) < 0)
            {
                continue;
            }

            data_ov000_021e3328->unk_08->unk_0854[(ix | iy << 5)] = 0;
        }
    }

    return;
}

void func_ov000_021abd58(void)
{
    func_ov000_021abbc8();
    func_ov000_021bc994(data_ov000_021e3328->unk_14->unk_04, 0, 0, 7);
    data_ov000_021e3328->unk_04->unk_08 = 2;
    return;
}

void func_ov000_021abd9c(void)
{
    func_ov000_021a5d5c(data_ov000_021e3328->unk_0c, 2);

    if (func_ov000_021a471c() != 0)
    {
        func_ov000_021ac0c0();
        return;
    }

    if ((((data_ov000_021e3328->unk_0c->unk_1c & 0x400) != 0) ||
         (func_ov000_021a5650(data_ov000_021e3328->unk_0c, 2) != 0)) &&
        (func_ov000_021a9cac() != 0))
    {
        if (data_ov000_021e3324.unk_00->unk_03 != '\0')
        {
            data_ov000_021e3324.unk_00->unk_03 = 0;
            data_020efcc8->unk_b0->unk_00->unk_28(data_020efcc8->unk_b0, 0x0001001C, 0, 0);
        }
        else
        {
            data_ov000_021e3324.unk_00->unk_03 = 1;
            data_020efcc8->unk_b0->unk_00->unk_28(data_020efcc8->unk_b0, 0x0001001B, 0, 0);
        }

        func_ov000_021a3498(
            data_ov000_021e3328->unk_04->unk_00, 1, data_ov000_021e3344->unk_2c, data_ov000_021e3344->unk_2d);
        func_ov000_021a35a0();

        func_ov000_021a354c(
            data_ov000_021e3328->unk_04->unk_00, data_ov000_021e3344->unk_2c, data_ov000_021e3344->unk_2d);
        func_ov000_021abbc8();
    }

    if (data_ov000_021e3328->unk_0c->unk_21_0 != 0)
    {
        if (func_ov000_021abf30())
        {
            return;
        }
    }

    if (data_ov000_021e3328->unk_0c->unk_21_4 == 0)
    {
        if (!func_ov000_021a5650(data_ov000_021e3328->unk_0c, 0))
        {
            return;
        }
    }

    if (func_ov000_021ac0c0())
    {
        return;
    }
}

// #func_ov000_021abf30

BOOL func_ov000_021ac0c0(void)
{
    u32 uVar7;

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x12, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    data_020efcc8->unk_b0->unk_00->unk_28(data_020efcc8->unk_b0, 0x00010017, 0, 0);

    if (data_ov000_021e332c.unk_14->unk_05 == 1)
    {
        void * r9;
        struct Unit * r5;
        struct ItemData * r4;
        struct ItemData * r6_;
        int r7;
        int r8;
        int r6;
        int sp_00;

        r9 = data_ov000_021e3328->unk_08;
        r5 = data_ov000_021e3328->unk_04->unk_00;
        r4 = GetItemData(data_ov000_021e3328->unk_04->unk_00->items + data_ov000_021e3344->unk_37);
        r6_ = GetItemData(data_ov000_021e3328->unk_04->unk_00->items + data_ov000_021e3344->unk_37);
        r7 = data_ov000_021e3344->unk_31;
        r8 = data_ov000_021e3344->unk_30;
        r6 = r6_->minRange;
        sp_00 = GetItemMaxRange(r4, r5);

        func_01ff9300(r9, r8, r7, r6, sp_00);

        if (data_ov000_021e3328->unk_14->unk_04->unk_10 != 0)
        {
            uVar7 = 2;
        }
        else
        {
            uVar7 = 1;
        }

        func_ov000_021bc994(data_ov000_021e3328->unk_14->unk_04, 0, uVar7, 2);
    }

    data_ov000_021e3328->unk_04->unk_08 = 1;

    return 1;
}

static inline BOOL TEMP(struct Unit * unit)
{
    u32 pos;

    if (func_ov000_021a3da0(unit) != 0)
    {
        return TRUE;
    }

    pos = (unit->xPos | unit->yPos << 5) >> 3;
    return (data_ov000_021e3328->unk_d30[pos] & (1 << (unit->xPos & 7))) & 0xFF;
}

void func_ov000_021ac218(void)
{
    BOOL bVar5;
    struct Unit * pUnit;
    s32 x;
    s32 y;
    s32 uVar8;

    bVar5 = TRUE;
    pUnit = data_ov000_021e3328->unk_04->unk_00;
    x = pUnit->xPos;
    y = pUnit->yPos;

    func_ov000_021a7284();

    data_ov000_021e3328->unk_04[1].unk_00 = NULL;

    pUnit->state2 &= 0xfffdffff;

    if ((pUnit->state2 & 0x48) == 0)
    {
        pUnit->state2 |= 1;

        if ((data_ov000_021e3324.unk_00->unk_02 != 0) && (func_ov000_021a3da0(pUnit) == 0))
        {
            if (TEMP(pUnit) != 0)
            {
                pUnit->state2 |= 0x4000;
            }
        }
    }
    else
    {
        pUnit->state2 |= 0x1000;
    }

    if (data_ov000_021e3324.unk_00->unk_02 != 0)
    {
        if (data_ov000_021e3324.unk_00->phase == pUnit->unk_4c->unk_08)
        {
            void * sp_0c;
            s32 sp_08;
            int fp;
            s8 sp_00;
            int sp_04;
            int sp_10;

            sp_0c = data_ov000_021e3328->unk_08;
            sp_08 = func_ov000_021a4854(pUnit);

            fp = pUnit->unk_4c->unk_08;
            sp_10 = data_ov000_021e3344->unk_2c;
            sp_04 = data_ov000_021e3344->unk_2e;
            sp_00 = data_ov000_021e3344->unk_2d;

            func_ov000_021a3c84(
                data_ov000_021e3328->unk_db0, data_ov000_021e3324.unk_00->phase, fp, sp_00, sp_04, sp_08, sp_0c, sp_10);
            func_ov000_021a3c84(
                data_ov000_021e3328->unk_d30, data_ov000_021e3324.unk_00->unk_01, fp, sp_00, sp_04, sp_08, sp_0c,
                sp_10);
        }
        else
        {
            func_ov000_021a3c20(data_ov000_021e3328->unk_db0, uVar8, pUnit);
            func_ov000_021a3c20(data_ov000_021e3328->unk_d30, data_ov000_021e3324.unk_00->unk_01, pUnit);
        }

        if (func_ov000_021a3da0(pUnit) == 0)
        {
            func_ov000_021a38b4();
        }

        func_ov000_021a340c();
    }
    else
    {
        if ((pUnit->state2 & 0x48) == 0)
        {
            func_ov000_021a3498(pUnit, 0, -1, -1);
        }
    }

    if ((pUnit->state2 & 8) != 0)
    {
        bVar5 = FALSE;

        if (pUnit->unk_4c->unk_08 == 0)
        {
            func_0203bd34(pUnit, 3, 1);
        }
        else
        {
            func_0203bd34(pUnit, 4, 1);
        }
    }
    else
    {
        if ((pUnit->state2 & 0x40) != 0)
        {
            bVar5 = FALSE;

            if (pUnit->unk_4c->unk_08 != 0)
            {
                func_0203bd34(pUnit, 4, 1);
            }
        }
    }

    func_ov000_021a9a48();

    if (func_02049370(data_02196f0c->unk_04, "gf_gameover") != 0)
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 0x18, 0);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;

        func_ov000_021a969c(9);

        return;
    }

    if (func_02049370(data_02196f0c->unk_04, "gf_complete") != 0)
    {
        pUnit->state2 &= 0xfffffffe;

        Proc_Goto(data_ov000_021e332c.unk_00[4], 0x18, 0);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;

        func_ov000_021a969c(8);

        return;
    }

    func_ov000_021a378c();
    func_ov000_021a4cec(data_ov000_021e3328->unk_00, x, y, 0, 0x20, 0);
    func_ov000_021a6ab8(data_ov000_021e3328->unk_10, (s16)x, (s16)y);

    if (bVar5)
    {
        func_0204e1a4(pUnit, 0, 1);
    }
    else
    {
        func_0204e1a4(NULL, 0, 1);
    }

    func_0204eab8(x, y, 0);
    func_0204bbb4(0);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 9, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

void func_ov000_021ac644(void)
{
    if (func_ov000_021a478c() != 0)
    {
        func_ov000_021b0de8(0, 0, 0x1b, 0);
        func_02012b64(data_ov000_021e3344, 0x38);
    }

    func_ov000_021a9ce4();

    data_ov000_021e3324.unk_00->unk_10 = data_027e1264;

    return;
}

void func_ov000_021ac6a0(void)
{
    func_ov000_021a48d8();

    if ((u8)data_ov000_021e332c.unk_14->unk_01 != 0)
    {
        return;
    }

    if ((func_020479b0() == 0))
    {
        if (func_02050474() == 0)
        {
            if ((data_020ca61c->unk_00 & 0x100) != 0 || (func_ov000_021a5650(data_ov000_021e3328->unk_0c, 1) != 0))
            {
                if (func_0204b1f8(0) != 0)
                {
                    if (func_0204b260(0) != 0)
                    {
                        data_020efcc8->unk_b0->unk_00->unk_28(data_020efcc8->unk_b0, 0x00010018, 0, 0);
                    }
                }
                else
                {
                    if (func_0204ad38(0, 0, 0) != 0)
                    {
                        data_020efcc8->unk_b0->unk_00->unk_28(data_020efcc8->unk_b0, 0x00010018, 0, 0);
                    }
                }
            }
        }
    }

    if (func_ov000_021a5768(data_ov000_021e3328->unk_0c, -1) == 0)
    {
        return;
    }

    if (data_020ca620->unk_12 != 0)
    {
        data_02196f20->unk_19a = 1;
        return;
    }

    if ((data_020ca61c->unk_04 & ~1) != 0)
    {
        data_02196f20->unk_19a = 0;
    }

    return;
}

BOOL func_ov000_021ac80c(void)
{
    if (data_ov000_021e332c.unk_14->unk_01 != 0)
    {
        return TRUE;
    }

    if (data_ov000_021e332c.unk_14->unk_08 != 0)
    {
        if (data_ov000_021e3328->unk_10->unk_0b == 2)
        {
            return TRUE;
        }

        data_ov000_021e332c.unk_14->unk_08 = 0;
    }

    if (data_ov000_021e332c.unk_14->unk_09 != 0)
    {
        if (UNK_18_CHECK())
        {
            return TRUE;
        }

        data_ov000_021e332c.unk_14->unk_09 = 0;
    }

    return 0;
}

void func_ov000_021ac8b4(void)
{
    int unitId;
    struct Unit * pUnit;

    if (func_ov000_021ac80c() != 0)
    {
        return;
    }

    unitId = data_ov000_021e3328->unk_28[data_ov000_021e3328->unk_10->unk_08 | data_ov000_021e3328->unk_10->unk_09 << 5];

    if (unitId != 0)
    {
        pUnit = gUnitList + unitId - 1;
    }
    else
    {
        pUnit = NULL;
    }

    if (pUnit != NULL)
    {
        if (pUnit->unk_4c->unk_08 == data_ov000_021e3324.unk_00->phase)
        {
            func_01ff8db8(data_ov000_021e3328->unk_08, pUnit, -1, 6, 1, 1);
        }
        else
        {
            func_01ff8db8(data_ov000_021e3328->unk_08, pUnit, -1, 2, 1, 1);
        }
    }

    data_ov000_021e3328->unk_10->unk_0a = 1;
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0xf);

    if ((data_02196f0c->unk_0c & 0x40) != 0)
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 1, 0);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;

        return;
    }

    Proc_Goto(data_ov000_021e332c.unk_00[4], 4, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    func_ov000_021d6e30(0);

    return;
}

void func_ov000_021aca18(void)
{
    if (data_ov000_021e3328->unk_10->unk_0b == 2)
    {
        return;
    }

    func_ov000_021aa278(1);
    return;
}

void func_ov000_021aca50(void)
{
    data_020efcc8->unk_b0->unk_00->unk_28(data_020efcc8->unk_b0, 0x10017, 0, 0);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x19, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    func_ov005_022054b0(1);
    func_ov000_021d6dfc(0);

    return;
}

void func_ov000_021acac4(void)
{
    func_ov000_021aa1d0();
    func_ov000_021bc9e4(data_ov000_021e3328->unk_14->unk_04);

    data_ov000_021e3328->unk_14->unk_04->unk_19 = 0;

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x18, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    func_ov005_022054b0(10);

    return;
}

void func_ov000_021acb34(void)
{
    if (func_ov000_021ac80c() != 0)
    {
        return;
    }

    if (data_ov000_021e3328->unk_10->unk_0b != 2)
    {
        return;
    }

    func_ov000_021aa278(0);
    return;
}

void func_ov000_021acb78(ProcPtr proc)
{
    func_ov000_021d6f1c(proc, 0);
    return;
}

void func_ov000_021acb88(void)
{
    if (func_ov000_021ac80c() != 0)
    {
        return;
    }

    if (data_ov000_021e3328->unk_10->unk_0b != 2)
    {
        return;
    }

    func_ov000_021ab768();
    return;
}

void func_ov000_021acbc8(void)
{
    func_ov000_021abd58();
    return;
}

void func_ov000_021acbd4(void)
{
    if (data_ov000_021e3328->unk_10->unk_0b != 2)
    {
        return;
    }

    func_ov000_021abd9c();
    return;
}

static inline BOOL CHECK_54()
{
    return (data_ov000_021e3328->unk_04->unk_04->unk_54 & 1);
}

void func_ov000_021acc08(ProcPtr proc)
{
    if ((!CHECK_54() ? TRUE : FALSE) & 0xFF)
    {
        Proc_Break(proc, 1);
    }

    return;
}

void func_ov000_021acc44(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 11, 1);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

static inline BOOL CHECK_02(void)
{
    return (data_ov000_021e332c.unk_14->unk_02 != -1) ? TRUE : FALSE;
}

void func_ov000_021acc7c(ProcPtr proc)
{
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0x8b);
    func_ov000_021bec24(proc);

    if (CHECK_02())
    {
        data_020efcc8->unk_b0->unk_00->unk_28(data_020efcc8->unk_b0, 0x00010003, 0, 0);
    }

    return;
}

void func_ov000_021accfc(ProcPtr proc)
{
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0x8b);
    func_ov000_021bfb80(proc);

    if (CHECK_02())
    {
        data_020efcc8->unk_b0->unk_00->unk_28(data_020efcc8->unk_b0, 0x00010003, 0, 0);
    }

    func_ov000_021b799c(3, -1, -1);

    return;
}

void func_ov000_021acd8c(void)
{
    struct UnkStruct_021E3328_14_04 * ptr;
    struct Unit * pUnit = data_ov000_021e3328->unk_04->unk_00;

    func_ov000_021b79f8();

    func_ov000_021a6ab8(data_ov000_021e3328->unk_10, pUnit->xPos, pUnit->yPos);
    func_ov000_021a4cec(data_ov000_021e3328->unk_00, pUnit->xPos, pUnit->yPos, 0, 0x20, 0);

    data_ov000_021e332c.unk_14->unk_09 = 1;

    func_ov000_021bc540(data_ov000_021e3328->unk_04->unk_04);
    func_01ff8d88(data_ov000_021e3328->unk_08, pUnit, -1, 6, 1, 1);
    func_ov000_021a3ee4(pUnit, 1);

    data_ov000_021e3328->unk_10->unk_0a = 1;

    func_ov000_021bc994(data_ov000_021e3328->unk_14->unk_04, 0, 0, 0);

    ptr = data_ov000_021e3328->unk_14->unk_04;
    ptr->unk_14 = 1;
    ptr->unk_16 = 0;

    data_ov000_021e3328->unk_14->unk_04->unk_15 = 1;

    func_ov000_021d3fa8();
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0x8f);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 6, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

void func_ov000_021acef4(ProcPtr proc)
{
    struct Unit * pUnit;
    u8 unitId = data_ov000_021e332c.unk_14->unk_03;

    if (unitId != 0)
    {
        pUnit = gUnitList + unitId - 1;
    }
    else
    {
        pUnit = NULL;
    }

    func_ov000_021c266c(proc, data_ov000_021e332c.unk_14->unk_02, pUnit);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x27, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

void func_ov000_021acf64(ProcPtr proc)
{
    struct Unit * pUnit;
    u8 unitId = data_ov000_021e332c.unk_14->unk_02;

    if (unitId != 0)
    {
        pUnit = gUnitList + unitId - 1;
    }
    else
    {
        pUnit = NULL;
    }

    func_ov000_021c52fc(proc, pUnit);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x27, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

void func_ov000_021acfd0(void)
{
    func_ov000_021d609c();

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x27, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

void func_ov000_021ad00c(void)
{
    func_ov000_021c63f8();

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x27, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

void func_ov000_021ad048(void)
{
    func_ov000_021b799c(data_ov000_021e332c.unk_14->unk_02, data_ov000_021e332c.unk_14->unk_03, -1);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x27, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

void func_ov000_021ad098(void)
{
    func_ov000_021b799c(data_ov000_021e332c.unk_14->unk_07, data_ov000_021e3344->unk_37, data_ov000_021e3344->unk_34);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x27, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

// #func_ov000_021ad0f4

void func_ov000_021ad388(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0xb, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

void func_ov000_021ad3c0(ProcPtr proc)
{
    struct UnkStruct_021E3328_00_04_04 * ptr;

    ptr = data_ov000_021e3328->unk_04->unk_04;
    ptr->unk_5f = 0;

    if (ptr->unk_61 != 0)
    {
        ptr->unk_61 = 0;
        ptr->unk_60 = -1;
    }

    func_0205633c();

    TryStartVisitEvent(
        proc, data_ov000_021e3328->unk_04->unk_00->xPos, data_ov000_021e3328->unk_04->unk_00->yPos,
        data_ov000_021e3344->unk_33);

    if (data_ov000_021e3344->unk_33 == 0xa)
    {
        func_02054870(data_ov000_021e3328->unk_04->unk_00, proc);
        return;
    }

    if (data_ov000_021e3344->unk_33 == 0xb)
    {
        func_02055224(data_ov000_021e3328->unk_04->unk_00, proc);
        return;
    }

    func_02055ab0(data_ov000_021e3328->unk_04->unk_00, proc);

    return;
}

void func_ov000_021ad49c(void)
{
    if (func_020563fc() != 0)
    {
        data_ov000_021e332c.unk_14->unk_06 |= 4;
    }

    if ((data_ov000_021e332c.unk_14->unk_06 & 4) != 0)
    {
        func_ov000_021b0de8(
            data_ov000_021e3328->unk_04->unk_00->xPos, data_ov000_021e3328->unk_04->unk_00->yPos,
            data_ov000_021e3344->unk_33, 0);

        Proc_Goto(data_ov000_021e332c.unk_00[4], 0x28, 0);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;
        return;
    }

    func_ov000_021bc5a8(data_ov000_021e3328->unk_04->unk_04);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0xb, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

void func_ov000_021ad580(ProcPtr proc)
{
    struct UnkStruct_021E3328_00_04_04 * ptr = data_ov000_021e3328->unk_04->unk_04;

    ptr->unk_5f = 0;

    if (ptr->unk_61 != 0)
    {
        ptr->unk_61 = 0;
        ptr->unk_60 = -1;
    }

    func_ov000_021d95ec(proc);

    return;
}

void func_ov000_021ad5bc(void)
{
    if ((data_ov000_021e332c.unk_14->unk_06 & 8) != 0)
    {
        func_ov000_021b0de8(
            data_ov000_021e3328->unk_04->unk_00->xPos, data_ov000_021e3328->unk_04->unk_00->yPos, 0xd, 0);
        Proc_Goto(data_ov000_021e332c.unk_00[4], 0x28, 0);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;
        return;
    }

    func_ov000_021bc5a8(data_ov000_021e3328->unk_04->unk_04);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0xb, 0);

    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

void func_ov000_021ad674(ProcPtr proc)
{
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0);
    func_ov000_021b06d4(proc);
    return;
}

void func_ov000_021ad6a0(struct PlayerPhaseProc * proc)
{
    if (UNK_18_CHECK())
    {
        return;
    }

    if (func_ov000_021a37b4() != 0)
    {
        return;
    }

    Proc_Break(proc, 1);

    return;
}

void func_ov000_021ad6ec(struct PlayerPhaseProc * proc)
{
    if (func_ov000_021a98ec(data_ov000_021e3344->unk_30, data_ov000_021e3344->unk_31) != 0)
    {
        func_ov000_021a98a4(proc, data_ov000_021e3344->unk_30, data_ov000_021e3344->unk_31, 1);
    }

    Proc_Break(proc, 1);

    return;
}

void func_ov000_021ad740(void)
{
    if (func_02049370(data_02196f0c->unk_04, "gf_gameover") != 0)
    {
        func_ov000_021a46b8();
        Proc_Goto(data_ov000_021e332c.unk_00[4], 0x18, 0);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;
        func_ov000_021a969c(9);
        return;
    }

    if (func_02049370(data_02196f0c->unk_04, "gf_complete") != 0)
    {
        func_ov000_021a46b8();
        Proc_Goto(data_ov000_021e332c.unk_00[4], 0x18, 0);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;
        func_ov000_021a969c(8);
        return;
    }

    if (data_ov000_021e3344->unk_33 == 0x10)
    {
        func_ov000_021a43e8();
        Proc_Goto(data_ov000_021e332c.unk_00[4], 0x1c, 1);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;
        return;
    }

    func_ov000_021a46b8();
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x23, 1);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

void func_ov000_021ad884(struct PlayerPhaseProc * proc)
{
    if (func_02012298() != 0)
    {
        proc->unk_38 = 0;
        return;
    }

    if (func_02012190() == 2)
    {
        func_ov011_022069b8(0, &proc->unk_38, proc);
        return;
    }

    proc->unk_38 = 0;

    return;
}

void func_ov000_021ad8c4(struct PlayerPhaseProc * proc)
{
    if (func_02014b20(proc, 1) != 0)
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 0x24, 0);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;
        return;
    }

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x1a, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    if (proc->unk_38 != 0)
    {
        data_02196f10->unk_07 = 0;
    }
    else
    {
        data_02196f10->unk_07 = 1;
    }

    data_02196f10->unk_08 = 1;

    return;
}

void func_ov000_021ad97c(ProcPtr proc)
{
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x18, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    func_ov000_021a969c(10);

    return;
}

void func_ov000_021ad9d4(ProcPtr proc)
{
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0);
    func_ov000_021d604c(0x1b, proc);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x1a, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

void func_ov000_021ada34(ProcPtr proc)
{
    func_ov000_021d604c(0x1c, proc);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x23, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

void func_ov000_021ada78(ProcPtr proc)
{
    func_ov000_021d604c(0x1d, proc);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x24, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

BOOL func_ov000_021adabc(int arg_0, int arg_1)
{
    if (func_ov000_021ae1bc() == 0)
    {
        return FALSE;
    }

    if (data_02196f24->unk_03 == 0)
    {
        return FALSE;
    }

    if (arg_1 != 0 && func_ov000_021a98ec(data_ov000_021e3344->unk_30, data_ov000_021e3344->unk_31))
    {
        return FALSE;
    }

    if (!func_ov000_021a995c(arg_0, data_ov000_021e3324.unk_00->phase))
    {
        return TRUE;
    }

    return FALSE;
}

void func_ov000_021adb48(void)
{
    if (func_ov000_021adabc(0, 0) == 0)
    {
        data_ov000_021e3328->unk_10->unk_0a = 1;
        Proc_Goto(data_ov000_021e332c.unk_00[4], 4, 1);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;

        func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0xf);
        func_ov000_021d6e30(0);

        return;
    }

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x17, 1);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    return;
}

void func_ov000_021adbf0(void)
{
    data_ov000_021e3328->unk_10->unk_0a = 1;

    if (data_02196f0c->unk_0c & 0x40)
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 1, 1);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;
    }
    else
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 4, 1);
        data_ov000_021e332c.unk_14->unk_02 = 0;
        data_ov000_021e332c.unk_14->unk_03 = 0;
        func_ov000_021d6e30(0);
    }

    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0xf);

    return;
}

void func_ov000_021adc98(u32 arg_0)
{
    func_0203fc88();

    data_021974fc->unk_00 = func_0203fcb8(1 << data_ov000_021e3324.unk_00->phase);
    data_021974fc->unk_08 = 0;

    func_0204ae60(0, 1);
    func_0204ad38(1, 1, 1);
    func_0204eb24();
    func_02062a54(arg_0);

    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0xf);

    return;
}

void func_ov000_021add1c(void)
{
    int unitId;
    struct Unit * pUnit;

    unitId = data_ov000_021e3328->unk_28[data_ov000_021e3328->unk_10->unk_08 | data_ov000_021e3328->unk_10->unk_09 << 5];

    if (unitId != 0)
    {
        pUnit = gUnitList + unitId - 1;
    }
    else
    {
        pUnit = NULL;
    }

    if (pUnit != NULL)
    {
        data_021974fc->unk_00 = pUnit;
    }

    func_0204b194(data_ov000_021e3328->unk_10->unk_08, data_ov000_021e3328->unk_10->unk_09);
    func_0204ae9c(0, (pUnit != NULL) & 0xFF ? TRUE : FALSE);
    func_0204eb24();
    return;
}

void func_ov000_021addb4(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x24, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

void func_ov000_021addec(void)
{
    func_ov000_021c669c();
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0xa, 0);
    data_ov000_021e332c.unk_14->unk_02 = -1;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

void func_ov000_021ade2c(void)
{
    func_02067510();
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0xf);
    return;
}

void func_ov000_021ade50(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x24, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

void func_ov000_021ade88(ProcPtr proc)
{
    struct Unit * pUnit = data_ov000_021e3328->unk_04->unk_00;

    data_021974fc->unk_00 = pUnit;
    data_021974fc->unk_08 = 0;

    func_0204ae60(0, 1);
    func_0204ad38(1, 1, 1);
    func_0204eb24();
    func_0205e138(pUnit, proc);
    return;
}

void func_ov000_021adeec(void)
{
    func_0204b194(data_ov000_021e3328->unk_10->unk_08, data_ov000_021e3328->unk_10->unk_09);
    func_0204ae9c(0, 0);
    func_0204eb24();
    return;
}

void func_ov000_021adf20(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 0xb, 0);
    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;
    return;
}

void func_ov000_021adf58(void)
{
    if ((func_ov000_021a478c() == 0) && (func_0204b1f8(0) == 0))
    {
        data_021974fc->unk_00 = 0;
        data_021974fc->unk_08 = 0;
        func_0204ae60(1, 0);
        func_0204ad38(2, 1, 0);
        func_0204eb24();
    }

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x18, 1);

    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    if (func_ov000_021a478c() == 0)
    {
        return;
    }

    func_ov000_021b0de8(0, 0, 0x16, 0);
    func_02012b64(data_ov000_021e3344, 0x38);

    return;
}

void func_ov000_021ae018(void)
{
    if (func_ov000_021a478c() != 0)
    {
        func_ov000_021b0de8(0, 0, 0x18, 0);
        func_02012b64(data_ov000_021e3344, 0x38);
    }

    Proc_Goto(data_ov000_021e332c.unk_00[4], 0x18, 0);

    data_ov000_021e332c.unk_14->unk_02 = 0;
    data_ov000_021e332c.unk_14->unk_03 = 0;

    func_020493b8(data_02196f0c->unk_04, "gf_gameover");

    func_ov000_021a969c(9);

    return;
}

void func_ov000_021ae0a8(ProcPtr proc)
{
    struct UnkStruct_021E3328_10 * ptr;
    s32 phase;
    u32 r12;
    u32 r2;
    func_ov000_021a5774(data_ov000_021e3328->unk_0c, 0);

    phase = data_ov000_021e3324.unk_00->phase;

    ptr = data_ov000_021e3328->unk_10;
    r12 = ptr->unk_09;
    r2 = ptr->unk_08;

    ptr->unk_00[phase] = r12;
    ptr->unk_02[phase] = r2;

    Proc_End(proc);

    return;
}

void func_ov000_021ae104(ProcPtr proc)
{
    Proc_Goto(Proc_Find(data_ov000_021dbe58), 0, 0);
    Proc_End(proc);
    return;
}

void func_ov000_021ae130(ProcPtr parent)
{
    struct Proc * proc = Proc_StartBlocking(data_ov000_021dc190, parent);

    if (proc == NULL)
    {
        return;
    }

    proc->proc_funcTable = &data_ov000_021dbd94;

    data_ov000_021e332c.unk_00[4] = proc;
    data_ov000_021e3328->unk_14->unk_27 = 1;

    return;
}

void func_ov000_021ae180(int label, int arg_1, int arg_2)
{
    Proc_Goto(func_ov000_021ae1bc(), label, 0);
    data_ov000_021e332c.unk_14->unk_02 = arg_1;
    data_ov000_021e332c.unk_14->unk_03 = arg_2;
    return;
}

struct PlayerPhaseProc * func_ov000_021ae1bc(void)
{
    return Proc_Find(data_ov000_021dc190);
}

void func_ov000_021ae1d0(void)
{
    if (func_ov000_021ae1bc() == NULL)
    {
        return;
    }

    data_ov000_021e332c.unk_14->unk_01++;

    return;
}

void func_ov000_021ae1fc(void)
{
    func_ov000_021b9960(data_ov000_021e3328->unk_14);
    func_ov000_021a6bd0(data_ov000_021e3328->unk_10);
    return;
}

void func_ov000_021ae228(void)
{
    func_ov000_021b9960(data_ov000_021e3328->unk_14);
    func_ov000_021aa1d0();
    func_ov000_021bc9e4(data_ov000_021e3328->unk_14->unk_04);
    func_ov000_021a6bd0(data_ov000_021e3328->unk_10);
    return;
}

void func_ov000_021ae26c(void)
{
    func_ov000_021b95e8(data_ov000_021e3328->unk_14);
    func_ov000_021b9978(data_ov000_021e3328->unk_14);
    return;
}

void func_ov000_021ae298(void)
{
    if (func_ov000_021ae1bc() == NULL)
    {
        return;
    }

    data_ov000_021e332c.unk_14->unk_01--;

    return;
}

extern struct ProcCmd data_ov000_021dbc24[];
extern struct ProcCmd data_ov000_021dbc4c[];

ProcPtr func_ov000_021ae2c4(ProcPtr parent)
{
    return func_01ffc030(data_ov000_021dbc24, parent);
}

ProcPtr func_ov000_021ae2dc(ProcPtr parent)
{
    return func_01ffc030(data_ov000_021dbc4c, parent);
}
