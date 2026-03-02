#include "global.h"

#include <new>

#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "action.hpp"
#include "database.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"

#include "constants/sounds.h"

enum
{

    L_PLAYERPHASE_END_PREP = 3,

    L_PLAYERPHASE_ACT = 12, // 0 attack, 1 staff, 4 item, 7 trade, 10 imitate

    L_PLAYERPHASE_SAVE_POINT = 14,

    L_PLAYERPHASE_TALK = 17,

    L_PLAYERPHASE_SHOP = 21,
    L_PLAYERPHASE_ARENA = 22,
    L_PLAYERPHASE_END_TURN = 23,

    L_PLAYERPHASE_END = 25,
    L_PLAYERPHASE_EXIT = 26,
    L_PLAYERPHASE_SUSPEND = 27,

    L_PLAYERPHASE_UNIT_LIST = 31,
    L_PLAYERPHASE_GUIDE = 32,
    L_PLAYERPHASE_CONFIG = 33,
    L_PLAYERPHASE_CONVOY = 34,

    L_PLAYERPHASE_SURRENDER = 38,

    L_PLAYERPHASE_40 = 40,
};

extern struct UnkStruct_021e3340 * data_ov000_021e3340;

extern struct ProcCmd data_ov000_021dbe58[];
extern struct ProcCmd ProcScr_map_ProcPL[];
extern struct ProcFuncTable data_ov000_021dbd94;

extern UnkStruct_021E3324 * data_ov000_021e3324;
extern MapStateManager * gMapStateManager;

extern struct KeyState * gKeySt;
extern struct UnkStruct_02196f20 * data_02196f20;
extern struct UnkStruct_02196f24 * data_02196f24;
extern struct UnkStruct_021974fc * data_021974fc;

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

extern struct UnkStruct_02196f10 * data_02196f10;

extern struct TouchState * gTouchSt;

extern vu32 data_027e1264;

namespace map
{

class ProcPL : public ProcEx
{
public:
    u32 unk_38;

    ProcPL()
    {
        data_ov000_021e332c.unk_00[4] = this;
        gMapStateManager->unk_14->unk_27 = 1;
    }

    // func_ov000_021b0964 d1
    // func_ov000_021b0904 d0
};

}; // namespace map

EC map::ProcPL * GetPlayerPhaseProc(void);
EC BOOL func_ov000_021ac0c0(void);
EC void func_ov000_021aa278(s32);

EC void func_ov000_021aa210(void)
{
    gMapStateManager->cursor->isVisible = TRUE;

    Proc_Goto(data_ov000_021e332c.unk_00[4], 4, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    func_ov000_021d6e30(0);
    gMapStateManager->inputHandler->SetButtonVisibility(0xf);

    return;
}

// #func_ov000_021aa278

// #func_ov000_021aaad8

// #func_ov000_021aad64

// #func_ov000_021ab180

// #func_ov000_021ab4f0

// #func_ov000_021ab768

EC void func_ov000_021abbc8(void)
{
    struct Unit * pUnitA;
    int unitId;
    s16 ix;
    s16 iy;

    unitId = gActionSt->unk_34;

    if (unitId != 0)
    {
        pUnitA = gUnitList + unitId - 1;
    }
    else
    {
        pUnitA = NULL;
    }

    func_02000d14(gMapStateManager->unk_08, -1);

    for (iy = gMapStateManager->unk_25; iy < gMapStateManager->unk_27; iy++)
    {
        for (ix = gMapStateManager->unk_24; ix < gMapStateManager->unk_26; ix++)
        {
            struct Unit * pUnitB;

            if (ix == gActionSt->xDecision && iy == gActionSt->yDecision)
            {
                continue;
            }

            if ((gMapStateManager->unk_82c[(ix | iy << 5)] & 0x80) != 0)
            {
                continue;
            }

            if ((gMapStateManager->unk_d30[((ix | iy << 5)) >> 3] & (1 << (ix & 7))) == 0)
            {
                continue;
            }

            unitId = gMapStateManager->unk_028[(ix | iy << 5)];

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
                    gFE11Database->pTerrain[gMapStateManager->unk_828[(ix | iy << 5)]].unk_08,
                    pUnitA->pJobData->unk_28) < 0)
            {
                continue;
            }

            gMapStateManager->unk_08->unk_0854[(ix | iy << 5)] = 0;
        }
    }

    return;
}

EC void func_ov000_021abd58(void)
{
    func_ov000_021abbc8();
    func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 0, 0, 7);
    gMapStateManager->unk_04->unk_08 = 2;
    return;
}

EC void func_ov000_021abd9c(void)
{
    gMapStateManager->inputHandler->_021a5d5c(2);

    if (func_ov000_021a471c() != 0)
    {
        func_ov000_021ac0c0();
        return;
    }

    if ((((gMapStateManager->inputHandler->keyPressed & 0x400) != 0) ||
         (gMapStateManager->inputHandler->_021a5650(2) != 0)) &&
        (func_ov000_021a9cac() != 0))
    {
        if (data_ov000_021e3324->unk_03 != 0)
        {
            data_ov000_021e3324->unk_03 = 0;
            gSoundManager->unk_b0->vfunc_28(SE_SYS_ENEMY_OFF1, 0, 0);
        }
        else
        {
            data_ov000_021e3324->unk_03 = 1;
            gSoundManager->unk_b0->vfunc_28(SE_SYS_ENEMY_ON1, 0, 0);
        }

        func_ov000_021a3498(gMapStateManager->unk_04->unk_00, 1, gActionSt->unk_2c, gActionSt->unk_2d);
        func_ov000_021a35a0();

        func_ov000_021a354c(gMapStateManager->unk_04->unk_00, gActionSt->unk_2c, gActionSt->unk_2d);
        func_ov000_021abbc8();
    }

    if (gMapStateManager->inputHandler->unk_21_0 != 0)
    {
        if (func_ov000_021abf30())
        {
            return;
        }
    }

    if (gMapStateManager->inputHandler->unk_21_4 == 0)
    {
        if (!gMapStateManager->inputHandler->_021a5650(0))
        {
            return;
        }
    }

    if (func_ov000_021ac0c0())
    {
        return;
    }
}

EC void func_ov000_021a72a8(void *);
EC BOOL func_02002038(void *, void *);

EC BOOL func_ov000_021abf30(void)
{
    u8 x = gMapStateManager->cursor->xTile;
    u8 y = gMapStateManager->cursor->yTile;

    if (gMapStateManager->unk_08->unk_0854[x | y << 5] >= 0)
    {
        gActionSt->unk_35 = x;
        gActionSt->unk_36 = y;

        gMapStateManager->cursor->isVisible = FALSE;

        func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

        gSoundManager->unk_b0->vfunc_28(SE_SYS_SELECT1, 0, 0);

        if (data_ov000_021e3340->unk_07 == 2)
        {
            gMapStateManager->unk_14->unk_04->unk_15 = 0;

            if (func_02002038(gMapStateManager->unk_08, gMapStateManager->unk_04->unk_00) != 0)
            {
                func_ov000_021b0de8(gMapStateManager->unk_08->unk_0042, gMapStateManager->unk_08->unk_0043, 0x17, 0);
            }

            func_ov000_021a72a8(gMapStateManager->unk_04);
        }

        func_ov000_021d6dfc(0);

        gMapStateManager->unk_04->unk_08 = 1;

        Proc_Goto(data_ov000_021e332c.unk_00[4], 40, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        return TRUE;
    }

    gSoundManager->unk_b0->vfunc_28(SE_SYS_MISS1, 0, 0);

    return FALSE;
}

EC BOOL func_ov000_021ac0c0(void)
{
    u32 uVar7;

    Proc_Goto(data_ov000_021e332c.unk_00[4], 18, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    gSoundManager->unk_b0->vfunc_28(SE_SYS_CANSEL1, 0, 0);

    if (data_ov000_021e3340->unk_05 == 1)
    {
        void * r9;
        struct Unit * r5;
        struct ItemData * r4;
        struct ItemData * r6_;
        int r7;
        int r8;
        int r6;
        int sp_00;

        r9 = gMapStateManager->unk_08;
        r5 = gMapStateManager->unk_04->unk_00;
        r4 = gMapStateManager->unk_04->unk_00->items[gActionSt->unk_37].GetData();
        r6_ = gMapStateManager->unk_04->unk_00->items[gActionSt->unk_37].GetData();
        r7 = gActionSt->yDecision;
        r8 = gActionSt->xDecision;
        r6 = r6_->minRange;
        sp_00 = GetItemMaxRange(r4, r5);

        func_01ff9300(r9, r8, r7, r6, sp_00);

        if (gMapStateManager->unk_14->unk_04->unk_10 != 0)
        {
            uVar7 = 2;
        }
        else
        {
            uVar7 = 1;
        }

        func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 0, uVar7, 2);
    }

    gMapStateManager->unk_04->unk_08 = 1;

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
    return (gMapStateManager->unk_d30[pos] & (1 << (unit->xPos & 7))) & 0xFF;
}

EC void func_ov000_021ac218(void)
{
    BOOL bVar5;
    struct Unit * pUnit;
    s32 x;
    s32 y;
    s32 uVar8;

    bVar5 = TRUE;
    pUnit = gMapStateManager->unk_04->unk_00;
    x = pUnit->xPos;
    y = pUnit->yPos;

    func_ov000_021a7284();

    gMapStateManager->unk_04[1].unk_00 = NULL;

    pUnit->state2 &= ~0x20000;

    if ((pUnit->state2 & 0x48) == 0)
    {
        pUnit->state2 |= 1;

        if ((data_ov000_021e3324->unk_02 != 0) && (func_ov000_021a3da0(pUnit) == 0))
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

    if (data_ov000_021e3324->unk_02 != 0)
    {
        if (data_ov000_021e3324->phase == pUnit->force->id)
        {
            void * sp_0c;
            s32 sp_08;
            int fp;
            s8 sp_00;
            int sp_04;
            int sp_10;

            sp_0c = gMapStateManager->unk_08;
            sp_08 = func_ov000_021a4854(pUnit);

            fp = pUnit->force->id;
            sp_10 = gActionSt->unk_2c;
            sp_04 = gActionSt->unk_2e;
            sp_00 = gActionSt->unk_2d;

            // FIXME: Function signature issues
            // func_ov000_021a3c84(
            //     gMapStateManager->unk_db0, data_ov000_021e3324->phase, fp, sp_00, sp_04, sp_08, sp_0c, sp_10);
            // func_ov000_021a3c84(
            //     gMapStateManager->unk_d30, data_ov000_021e3324->unk_01, fp, sp_00, sp_04, sp_08, sp_0c,
            //     sp_10);
        }
        else
        {
            func_ov000_021a3c20(gMapStateManager->unk_db0, uVar8, pUnit);
            func_ov000_021a3c20(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01, pUnit);
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

        if (pUnit->force->id == 0)
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

            if (pUnit->force->id != 0)
            {
                func_0203bd34(pUnit, 4, 1);
            }
        }
    }

    func_ov000_021a9a48();

    if (data_02196f0c->flagMgr->GetByName("gf_gameover"))
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 24, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        func_ov000_021a969c(9);

        return;
    }

    if (data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        pUnit->state2 &= ~2;

        Proc_Goto(data_ov000_021e332c.unk_00[4], 24, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        func_ov000_021a969c(8);

        return;
    }

    func_ov000_021a378c();
    gMapStateManager->camera->func_ov000_021a4cec(x, y, 0, 0x20, 0);
    gMapStateManager->cursor->SetPosImmediate((s16)x, (s16)y);

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
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ac644(void)
{
    if (func_ov000_021a478c() != 0)
    {
        func_ov000_021b0de8(0, 0, 0x1b, 0);
        func_02012b64(gActionSt, sizeof(ActionState));
    }

    func_ov000_021a9ce4();

    data_ov000_021e3324->unk_10 = data_027e1264;

    return;
}

EC void func_ov000_021ac6a0(void)
{
    func_ov000_021a48d8();

    if ((u8)data_ov000_021e3340->unk_01 != 0)
    {
        return;
    }

    if (func_020479b0() == 0)
    {
        if (func_02050474() == 0)
        {
            if ((gKeySt->pressed & KEY_BUTTON_R) != 0 || (gMapStateManager->inputHandler->_021a5650(1) != 0))
            {
                if (func_0204b1f8(0) != 0)
                {
                    if (func_0204b260(0) != 0)
                    {
                        gSoundManager->unk_b0->vfunc_28(SE_SYS_WINDOW_INFO2, 0, 0);
                    }
                }
                else
                {
                    if (func_0204ad38(0, 0, 0) != 0)
                    {
                        gSoundManager->unk_b0->vfunc_28(SE_SYS_WINDOW_INFO2, 0, 0);
                    }
                }
            }
        }
    }

    if (gMapStateManager->inputHandler->IsButtonVisible(0xff) == 0)
    {
        return;
    }

    if (gTouchSt->unk_12 != 0)
    {
        data_02196f20->unk_19a = 1;
        return;
    }

    if ((gKeySt->held & ~KEY_BUTTON_A) != 0)
    {
        data_02196f20->unk_19a = 0;
    }

    return;
}

EC BOOL func_ov000_021ac80c(void)
{
    if (data_ov000_021e3340->unk_01 != 0)
    {
        return TRUE;
    }

    if (data_ov000_021e3340->unk_08 != 0)
    {
        if (gMapStateManager->cursor->unk_0b == 2)
        {
            return TRUE;
        }

        data_ov000_021e3340->unk_08 = 0;
    }

    if (data_ov000_021e3340->unk_09 != 0)
    {
        if (gMapStateManager->camera->Check_18())
        {
            return TRUE;
        }

        data_ov000_021e3340->unk_09 = 0;
    }

    return FALSE;
}

EC void func_ov000_021ac8b4(void)
{
    Unit * pUnit;

    if (func_ov000_021ac80c() != 0)
    {
        return;
    }

    pUnit = GetUnit(gMapStateManager->unk_028[gMapStateManager->cursor->xTile | gMapStateManager->cursor->yTile << 5]);

    if (pUnit != NULL)
    {
        if (pUnit->force->id == data_ov000_021e3324->phase)
        {
            func_01ff8db8(gMapStateManager->unk_08, pUnit, -1, 6, 1, 1);
        }
        else
        {
            func_01ff8db8(gMapStateManager->unk_08, pUnit, -1, 2, 1, 1);
        }
    }

    gMapStateManager->cursor->isVisible = TRUE;
    gMapStateManager->inputHandler->SetButtonVisibility(0xf);

    if ((data_02196f0c->state & 0x40) != 0)
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 1, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
    }
    else
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 4, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        func_ov000_021d6e30(0);
    }

    return;
}

EC void func_ov000_021aca18(void)
{
    if (!(gMapStateManager->cursor->unk_0b != 2) ? TRUE : FALSE)
    {
        return;
    }

    func_ov000_021aa278(1);

    return;
}

EC void func_ov000_021aca50(void)
{
    gSoundManager->unk_b0->vfunc_28(SE_SYS_CANSEL1, 0, 0);

    Proc_Goto(data_ov000_021e332c.unk_00[4], L_PLAYERPHASE_END, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    func_ov005_022054b0(1);
    func_ov000_021d6dfc(0);

    return;
}

EC void func_ov000_021acac4(void)
{
    func_ov000_021aa1d0();
    func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

    gMapStateManager->unk_14->unk_04->unk_19 = 0;

    Proc_Goto(data_ov000_021e332c.unk_00[4], 24, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    func_ov005_022054b0(10);

    return;
}

EC void func_ov000_021acb34(void)
{
    if (func_ov000_021ac80c() != 0)
    {
        return;
    }

    if (!(gMapStateManager->cursor->unk_0b != 2) ? TRUE : FALSE)
    {
        return;
    }

    func_ov000_021aa278(0);

    return;
}

EC void func_ov000_021acb78(ProcPtr proc)
{
    func_ov000_021d6f1c(proc, 0);
    return;
}

EC void func_ov000_021acb88(void)
{
    if (func_ov000_021ac80c() != 0)
    {
        return;
    }

    if (!(gMapStateManager->cursor->unk_0b != 2) ? TRUE : FALSE)
    {
        return;
    }

    func_ov000_021ab768();
    return;
}

EC void func_ov000_021acbc8(void)
{
    func_ov000_021abd58();
    return;
}

EC void func_ov000_021acbd4(void)
{
    if (!(gMapStateManager->cursor->unk_0b != 2) ? TRUE : FALSE)
    {
        return;
    }

    func_ov000_021abd9c();
    return;
}

EC void func_ov000_021acc08(ProcPtr proc)
{
    if (gMapStateManager->unk_04->unk_04->Check_54())
    {
        Proc_Break(proc, 1);
    }

    return;
}

EC void func_ov000_021acc44(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 11, 1);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void func_ov000_021acc7c(ProcPtr proc)
{
    gMapStateManager->inputHandler->SetButtonVisibility(0x8b);
    StartMapMenu(proc);

    if (data_ov000_021e3340->Check_02())
    {
        gSoundManager->unk_b0->vfunc_28(SE_SYS_WINDOW_OPEN1, 0, 0);
    }

    return;
}

EC void func_ov000_021accfc(ProcPtr proc)
{
    gMapStateManager->inputHandler->SetButtonVisibility(0x8b);
    StartUnitMenu(proc);

    if (data_ov000_021e3340->Check_02())
    {
        gSoundManager->unk_b0->vfunc_28(SE_SYS_WINDOW_OPEN1, 0, 0);
    }

    func_ov000_021b799c(3, -1, -1);

    return;
}

EC void func_ov000_021acd8c(void)
{
    struct MapStateManager_14_04 * ptr;
    struct Unit * pUnit = gMapStateManager->unk_04->unk_00;

    func_ov000_021b79f8();

    gMapStateManager->cursor->SetPosImmediate(pUnit->xPos, pUnit->yPos);
    gMapStateManager->camera->func_ov000_021a4cec(pUnit->xPos, pUnit->yPos, 0, 0x20, 0);

    data_ov000_021e3340->unk_09 = 1;

    func_ov000_021bc540(gMapStateManager->unk_04->unk_04);
    func_01ff8d88(gMapStateManager->unk_08, pUnit, -1, 6, 1, 1);
    func_ov000_021a3ee4(pUnit, 1);

    gMapStateManager->cursor->isVisible = TRUE;

    func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 0, 0, 0);

    ptr = gMapStateManager->unk_14->unk_04;
    ptr->unk_14 = 1;
    ptr->unk_16 = 0;

    gMapStateManager->unk_14->unk_04->unk_15 = 1;

    func_ov000_021d3fa8();
    gMapStateManager->inputHandler->SetButtonVisibility(0x8f);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 6, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021acef4(ProcPtr proc)
{
    func_ov000_021c266c(proc, data_ov000_021e3340->unk_02, GetUnit(data_ov000_021e3340->unk_03));

    Proc_Goto(data_ov000_021e332c.unk_00[4], 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021acf64(ProcPtr proc)
{
    func_ov000_021c52fc(proc, GetUnit(data_ov000_021e3340->unk_02));

    Proc_Goto(data_ov000_021e332c.unk_00[4], 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021acfd0(ProcPtr proc)
{
    func_ov000_021d609c(proc);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ad00c(void)
{
    func_ov000_021c63f8();

    Proc_Goto(data_ov000_021e332c.unk_00[4], 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ad048(void)
{
    func_ov000_021b799c(data_ov000_021e3340->unk_02, data_ov000_021e3340->unk_03, -1);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ad098(void)
{
    func_ov000_021b799c(data_ov000_021e3340->unk_07, gActionSt->unk_37, gActionSt->unk_34);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ad0f4(ProcPtr param_1)
{
    struct Unit * psVar1;
    struct Unit * psVar7;
    char * uVar10;
    char * iVar3;

    data_021974fc->unk_00 = GetUnit(gActionSt->unitId);

    gMapStateManager->inputHandler->SetButtonVisibility(0);

    psVar1 = GetUnit(data_ov000_021e3340->unk_02);

    uVar10 = func_0203c378(psVar1)->pPersonData->unk_00;
    iVar3 = func_0203c378(gMapStateManager->unk_04->unk_00)->pPersonData->unk_00;

    EventCaller::TryStartTalkEvent(param_1, (u32)iVar3, (u32)uVar10, (u32)psVar7);

    data_ov000_021e3340->unk_06 |= 2;

    return;
}

EC void func_ov000_021ad388(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 11, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void func_ov000_021ad3c0(ProcPtr proc)
{
    gMapStateManager->unk_04->unk_04->ClearValues();

    func_0205633c();

    TryStartVisitEvent(
        proc, gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, gActionSt->actionId);

    if (gActionSt->actionId == ACTION_ARMORY)
    {
        func_02054870(gMapStateManager->unk_04->unk_00, proc);
        return;
    }

    if (gActionSt->actionId == ACTION_VENDOR)
    {
        func_02055224(gMapStateManager->unk_04->unk_00, proc);
        return;
    }

    func_02055ab0(gMapStateManager->unk_04->unk_00, proc);

    return;
}

EC void func_ov000_021ad49c(void)
{
    if (func_020563fc() != 0)
    {
        data_ov000_021e3340->unk_06 |= 4;
    }

    if ((data_ov000_021e3340->unk_06 & 4) != 0)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, gActionSt->actionId, 0);

        Proc_Goto(data_ov000_021e332c.unk_00[4], 40, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        return;
    }

    func_ov000_021bc5a8(gMapStateManager->unk_04->unk_04);

    Proc_Goto(data_ov000_021e332c.unk_00[4], 11, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ad580(ProcPtr proc)
{
    gMapStateManager->unk_04->unk_04->ClearValues();
    StartArena(proc);
    return;
}

EC void func_ov000_021ad5bc(void)
{
    if ((data_ov000_021e3340->unk_06 & 8) != 0)
    {
        func_ov000_021b0de8(
            gMapStateManager->unk_04->unk_00->xPos, gMapStateManager->unk_04->unk_00->yPos, ACTION_ARENA, 0);
        Proc_Goto(data_ov000_021e332c.unk_00[4], 40, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
    }
    else
    {
        func_ov000_021bc5a8(gMapStateManager->unk_04->unk_04);
        Proc_Goto(data_ov000_021e332c.unk_00[4], 11, 0);

        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
    }

    return;
}

EC void func_ov000_021ad674(ProcPtr proc)
{
    gMapStateManager->inputHandler->SetButtonVisibility(0);
    StartProcMind(proc);
    return;
}

EC void func_ov000_021ad6a0(map::ProcPL * proc)
{
    if (gMapStateManager->camera->Check_18())
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

EC void func_ov000_021ad6ec(map::ProcPL * proc)
{
    if (func_ov000_021a98ec(gActionSt->xDecision, gActionSt->yDecision) != 0)
    {
        func_ov000_021a98a4(proc, gActionSt->xDecision, gActionSt->yDecision, 1);
    }

    Proc_Break(proc, 1);

    return;
}

EC void func_ov000_021ad740(void)
{
    if (data_02196f0c->flagMgr->GetByName("gf_gameover"))
    {
        func_ov000_021a46b8();
        Proc_Goto(data_ov000_021e332c.unk_00[4], 24, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        func_ov000_021a969c(9);
        return;
    }

    if (data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        func_ov000_021a46b8();
        Proc_Goto(data_ov000_021e332c.unk_00[4], 24, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        func_ov000_021a969c(8);
        return;
    }

    if (gActionSt->actionId == ACTION_10)
    {
        func_ov000_021a43e8();
        Proc_Goto(data_ov000_021e332c.unk_00[4], 28, 1);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        return;
    }

    func_ov000_021a46b8();
    Proc_Goto(data_ov000_021e332c.unk_00[4], 35, 1);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ad884(map::ProcPL * proc)
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

EC void func_ov000_021ad8c4(map::ProcPL * proc)
{
    if (func_02014b20(proc, 1) != 0)
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 36, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        return;
    }

    Proc_Goto(data_ov000_021e332c.unk_00[4], 26, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

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

EC void func_ov000_021ad97c(ProcPtr proc)
{
    gMapStateManager->inputHandler->SetButtonVisibility(0);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 24, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    func_ov000_021a969c(10);

    return;
}

EC void func_ov000_021ad9d4(ProcPtr proc)
{
    gMapStateManager->inputHandler->SetButtonVisibility(0);
    func_ov000_021d604c(0x1b, proc);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 26, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void func_ov000_021ada34(ProcPtr proc)
{
    func_ov000_021d604c(0x1c, proc);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 35, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void func_ov000_021ada78(ProcPtr proc)
{
    func_ov000_021d604c(0x1d, proc);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 36, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC BOOL func_ov000_021adabc(s32 arg_0, s32 arg_1)
{
    if (GetPlayerPhaseProc() == NULL)
    {
        return FALSE;
    }

    if (data_02196f24->unk_03 == 0)
    {
        return FALSE;
    }

    if (arg_1 != 0 && func_ov000_021a98ec(gActionSt->xDecision, gActionSt->yDecision))
    {
        return FALSE;
    }

    if (!func_ov000_021a995c(arg_0, data_ov000_021e3324->phase))
    {
        return TRUE;
    }

    return FALSE;
}

EC void func_ov000_021adb48(void)
{
    if (func_ov000_021adabc(0, 0) == 0)
    {
        gMapStateManager->cursor->isVisible = TRUE;
        Proc_Goto(data_ov000_021e332c.unk_00[4], 4, 1);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        gMapStateManager->inputHandler->SetButtonVisibility(0xf);
        func_ov000_021d6e30(0);

        return;
    }

    Proc_Goto(data_ov000_021e332c.unk_00[4], 23, 1);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021adbf0(void)
{
    gMapStateManager->cursor->isVisible = TRUE;

    if (data_02196f0c->state & 0x40)
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 1, 1);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
    }
    else
    {
        Proc_Goto(data_ov000_021e332c.unk_00[4], 4, 1);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        func_ov000_021d6e30(0);
    }

    gMapStateManager->inputHandler->SetButtonVisibility(0xf);

    return;
}

EC void func_ov000_021adc98(u32 arg_0)
{
    func_0203fc88();

    data_021974fc->unk_00 = func_0203fcb8(1 << data_ov000_021e3324->phase);
    data_021974fc->unk_08 = 0;

    func_0204ae60(0, 1);
    func_0204ad38(1, 1, 1);
    func_0204eb24();
    func_02062a54(arg_0);

    gMapStateManager->inputHandler->SetButtonVisibility(0xf);

    return;
}

EC void func_ov000_021add1c(void)
{
    s32 unitId;
    struct Unit * pUnit;

    unitId = gMapStateManager->unk_028[gMapStateManager->cursor->xTile | gMapStateManager->cursor->yTile << 5];

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

    func_0204b194(gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile);
    func_0204ae9c(0, (pUnit != NULL) & 0xFF);
    func_0204eb24();

    return;
}

EC void func_ov000_021addb4(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 36, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void PlayerPhase_StartGuide(ProcPtr proc)
{
    StartGuideMenu(proc);
    Proc_Goto(data_ov000_021e332c.unk_00[4], 10, 0);
    data_ov000_021e3340->unk_02 = -1;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void func_ov000_021ade2c(void)
{
    func_02067510();
    gMapStateManager->inputHandler->SetButtonVisibility(0xf);
    return;
}

EC void func_ov000_021ade50(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 36, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void func_ov000_021ade88(ProcPtr proc)
{
    struct Unit * pUnit = gMapStateManager->unk_04->unk_00;

    data_021974fc->unk_00 = pUnit;
    data_021974fc->unk_08 = 0;

    func_0204ae60(0, 1);
    func_0204ad38(1, 1, 1);
    func_0204eb24();
    func_0205e138(pUnit, proc);

    return;
}

EC void func_ov000_021adeec(void)
{
    func_0204b194(gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile);
    func_0204ae9c(0, 0);
    func_0204eb24();
    return;
}

EC void func_ov000_021adf20(void)
{
    Proc_Goto(data_ov000_021e332c.unk_00[4], 11, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void func_ov000_021adf58(void)
{
    if ((func_ov000_021a478c() == 0) && (func_0204b1f8(0) == 0))
    {
        data_021974fc->unk_00 = 0;
        data_021974fc->unk_08 = 0;
        func_0204ae60(1, 0);
        func_0204ad38(2, 1, 0);
        func_0204eb24();
    }

    Proc_Goto(data_ov000_021e332c.unk_00[4], 24, 1);

    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    if (!func_ov000_021a478c())
    {
        func_ov000_021b0de8(0, 0, ACTION_END_TURN, 0);
        func_02012b64(gActionSt, sizeof(ActionState));
    }

    return;
}

EC void func_ov000_021ae018(void)
{
    if (func_ov000_021a478c())
    {
        func_ov000_021b0de8(0, 0, ACTION_SURRENDER, 0);
        func_02012b64(gActionSt, sizeof(ActionState));
    }

    Proc_Goto(data_ov000_021e332c.unk_00[4], 24, 0);

    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    data_02196f0c->flagMgr->SetByName("gf_gameover");

    func_ov000_021a969c(9);

    return;
}

EC void func_ov000_021ae0a8(ProcPtr proc)
{
    s32 phase;

    gMapStateManager->inputHandler->SetButtonVisibility(0);

    phase = data_ov000_021e3324->phase;

    gMapStateManager->cursor->SetUnk00And02(phase, gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile);

    Proc_End(proc);

    return;
}

EC void func_ov000_021ae104(ProcPtr proc)
{
    Proc_Goto(Proc_Find(data_ov000_021dbe58), 0, 0);
    Proc_End(proc);
    return;
}

EC ProcPtr func_ov000_021ae2c4(ProcPtr parent);

// clang-format off

struct ProcCmd ProcScr_map_ProcPL[] =
{
    PROC_NAME,
    PROC_NAME,
    PROC_SLEEP(0),

    PROC_CALL(func_ov000_021ac644),
    PROC_06(0, func_ov000_021ac6a0),

PROC_LABEL(0),
    PROC_REPEAT(func_ov000_021ac8b4),

PROC_LABEL(1),
    PROC_REPEAT(func_ov000_021aca18),

PROC_LABEL(2),
    PROC_CALL(func_ov000_021aca50),

PROC_LABEL(L_PLAYERPHASE_END_PREP),
    PROC_CALL(func_ov000_021acac4),

PROC_LABEL(4),
    PROC_REPEAT(func_ov000_021acb34),

PROC_LABEL(5),
    PROC_CALL(func_ov000_021acb78),

PROC_LABEL(6),
    PROC_REPEAT(func_ov000_021acb88),

PROC_LABEL(7),
    PROC_CALL(func_ov000_021acbc8),
    PROC_REPEAT(func_ov000_021acbd4),

PROC_LABEL(8),
    PROC_REPEAT(func_ov000_021acc08),
    PROC_CALL(func_ov000_021acc44),

PROC_LABEL(9),
    PROC_REPEAT(func_ov000_021ad6a0),
    PROC_CALL(func_ov000_021ad6ec),
    PROC_CALL(func_ov000_021ad740),

PROC_LABEL(10),
    PROC_CALL(func_ov000_021acc7c),
    PROC_CALL(func_ov000_021aa210),

PROC_LABEL(11),
    PROC_CALL(func_ov000_021accfc),
    PROC_CALL(func_ov000_021acd8c),

PROC_LABEL(L_PLAYERPHASE_ACT),
    PROC_CALL(func_ov000_021acef4),

PROC_LABEL(13),
    PROC_CALL(func_ov000_021acf64),

PROC_LABEL(L_PLAYERPHASE_SAVE_POINT),
    PROC_CALL(func_ov000_021acfd0),

PROC_LABEL(19),
    PROC_CALL(func_ov000_021ad00c),

PROC_LABEL(L_PLAYERPHASE_TALK),
    PROC_REPEAT(func_ov000_021ad048),

PROC_LABEL(18),
    PROC_REPEAT(func_ov000_021ad098),

PROC_LABEL(20),
    PROC_REPEAT(func_ov000_021acc08),
    PROC_CALL(func_ov000_021ad0f4),
    PROC_CALL(func_ov000_021a43e8),
    PROC_CALL(func_ov000_021ad388),

PROC_LABEL(L_PLAYERPHASE_SHOP),
    PROC_CALL(func_ov000_021ad3c0),
    PROC_CALL(func_ov000_021ad49c),

PROC_LABEL(L_PLAYERPHASE_ARENA),
    PROC_CALL(func_ov000_021ad580),
    PROC_CALL(func_ov000_021ad5bc),

PROC_LABEL(37),
    PROC_CALL(func_ov000_021ad884),
    PROC_CALL(func_ov000_021ad8c4),

PROC_LABEL(L_PLAYERPHASE_EXIT),
    PROC_CALL(func_ov000_021ad97c),

PROC_LABEL(L_PLAYERPHASE_SUSPEND),
    PROC_CALL(func_ov000_021ad9d4),

PROC_LABEL(28),
    PROC_CALL(func_ov000_021ada34),

PROC_LABEL(29),
    PROC_CALL(func_ov000_021ada78),

PROC_LABEL(L_PLAYERPHASE_UNIT_LIST),
    PROC_CALL(func_ov000_021ae2c4),
    PROC_CALL(func_ov000_021adc98),
    PROC_CALL(func_ov000_021add1c),
    PROC_CALL(func_ov000_021ae2f4),
    PROC_CALL(func_ov000_021addb4),

PROC_LABEL(L_PLAYERPHASE_GUIDE),
    PROC_CALL(PlayerPhase_StartGuide),

PROC_LABEL(L_PLAYERPHASE_CONFIG),
    PROC_CALL(func_ov000_021ae2c4),
    PROC_CALL(func_ov000_021ade2c),
    PROC_CALL(func_ov000_021ae2f4),
    PROC_CALL(func_ov000_021ade50),

PROC_LABEL(L_PLAYERPHASE_CONVOY),
    PROC_CALL(func_ov000_021ae2c4),
    PROC_CALL(func_ov000_021ade88),
    PROC_CALL(func_ov000_021adeec),
    PROC_CALL(func_ov000_021ae2f4),
    PROC_CALL(func_ov000_021adf20),

PROC_LABEL(35),
    PROC_CALL(func_ov000_021adb48),

PROC_LABEL(36),
    PROC_CALL(func_ov000_021adbf0),

PROC_LABEL(40),
    PROC_CALL(func_ov000_021ad674),
    PROC_CALL(func_ov000_021ac218),

PROC_LABEL(L_PLAYERPHASE_END_TURN),
    PROC_WHILE(func_0204b1e0),
    PROC_CALL(func_ov000_021adf58),

PROC_LABEL(L_PLAYERPHASE_SURRENDER),
    PROC_CALL(func_ov000_021ae018),

PROC_LABEL(39),
    { PROC_CMD_02, 0x0000, 0x00000000 },

PROC_LABEL(24),
    PROC_CALL(func_ov000_021ae0a8),

PROC_LABEL(L_PLAYERPHASE_END),
    PROC_CALL(func_ov000_021ae104),

    PROC_END
};

// clang-format on

EC void StartPlayerPhase(ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_map_ProcPL, parent)) map::ProcPL();
    return;
}

EC void PlayerPhase_GotoLabel(s32 label, s32 arg_1, s32 arg_2)
{
    Proc_Goto(GetPlayerPhaseProc(), label, 0);
    data_ov000_021e3340->unk_02 = arg_1;
    data_ov000_021e3340->unk_03 = arg_2;
    return;
}

EC map::ProcPL * GetPlayerPhaseProc(void)
{
    return static_cast<map::ProcPL *>(Proc_Find(ProcScr_map_ProcPL));
}

EC void func_ov000_021ae1d0(void)
{
    if (GetPlayerPhaseProc() == NULL)
    {
        return;
    }

    data_ov000_021e3340->unk_01++;

    return;
}

EC void func_ov000_021ae1fc(void)
{
    func_ov000_021b9960(gMapStateManager->unk_14);
    gMapStateManager->cursor->_021a6bd0();
    return;
}

EC void func_ov000_021ae228(void)
{
    func_ov000_021b9960(gMapStateManager->unk_14);
    func_ov000_021aa1d0();
    func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);
    gMapStateManager->cursor->_021a6bd0();
    return;
}

EC void func_ov000_021ae26c(void)
{
    func_ov000_021b95e8(gMapStateManager->unk_14);
    func_ov000_021b9978(gMapStateManager->unk_14);
    return;
}

EC void func_ov000_021ae298(void)
{
    if (GetPlayerPhaseProc() == NULL)
    {
        return;
    }

    data_ov000_021e3340->unk_01--;

    return;
}

extern struct ProcCmd data_ov000_021dbc24[];
extern struct ProcCmd data_ov000_021dbc4c[];

EC ProcPtr func_ov000_021ae2c4(ProcPtr parent)
{
    return func_01ffc030(data_ov000_021dbc24, parent);
}

EC ProcPtr func_ov000_021ae2dc(ProcPtr parent)
{
    return func_01ffc030(data_ov000_021dbc4c, parent);
}
