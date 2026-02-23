#include "global.h"

#include <new>

#include "button.hpp"
#include "hardware.hpp"
#include "hashtable.hpp"
#include "map.hpp"
#include "menu.hpp"

#include "unknown_funcs.h"
#include "unknown_types.hpp"

extern struct UnkStruct_021974fc * data_021974fc;
extern struct UnkStruct_02196f24 * data_02196f24;
extern struct UnkStruct_02196f0c * data_02196f0c;

namespace map
{
class Button_Main : public Button
{
public:
    Button_Main()
    {
        this->unk_58 = 1;
    }

    virtual ~Button_Main();

    virtual void vfunc_0c(void);
    virtual BOOL vfunc_18(void);
};

class Button_Common : public Button
{
public:
    Button_Common()
    {
        this->unk_58 = 1;
    }

    virtual ~Button_Common();

    virtual void vfunc_0c(void);
    virtual BOOL vfunc_18(void);
};
} // namespace map

// func_ov000_021a5318
void MapStateManager_0C::_021a5318(void)
{
    s32 i;

    this->unk_18 = 0;
    this->unk_1a = 0;
    this->unk_1c = 0;
    this->unk_1e = 0;
    this->unk_1f = 0;
    this->unk_20 = 0;
    this->unk_23 = 0;
    this->unk_21_0 = 0;
    this->unk_21_2 = 0;
    this->unk_21_4 = 0;
    this->unk_21_6 = 0;
    this->unk_24 = 0;
    this->unk_25 = 0;
    this->unk_26 = 0;
    this->unk_22 = 0;

    for (i = 0; i < 4; i++)
    {
        this->unk_00[i] = NULL;
    }

    return;
}

extern struct ProcCmd ProcScr_020ce750[];

// func_ov000_021a5388
void MapStateManager_0C::_021a5388(void)
{
    struct VmMap_Common * iVar1 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_Common"));

    this->unk_00[0] = new (Proc_Start(ProcScr_020ce750, PROC_TREE_6)) map::Button_Main;

    this->unk_00[0]->func_02034838(BUTTON_KIND_A_MENU, iVar1->unk_04, iVar1->unk_06, 0, 2);
    this->unk_00[0]->proc_mark = PROC_MARK_6;
    this->unk_00[0]->SetPosition(112, 0);
    this->unk_00[0]->func_020354bc(0);
    this->unk_00[0]->SetVisible(TRUE);

    this->unk_00[1] = new (Proc_Start(ProcScr_020ce750, PROC_TREE_6)) map::Button_Common;

    this->unk_00[1]->func_02034838(BUTTON_KIND_R_CHANGE, iVar1->unk_04 + 0x18, iVar1->unk_06, 0, 2);
    this->unk_00[1]->proc_mark = PROC_MARK_6;
    this->unk_00[1]->SetPosition(200, 0);
    this->unk_00[1]->func_020354bc(0);
    this->unk_00[1]->SetVisible(TRUE);

    this->unk_00[2] = new (Proc_Start(ProcScr_020ce750, PROC_TREE_6)) map::Button_Common;

    this->unk_00[2]->func_02034838(BUTTON_KIND_X_DANGER, iVar1->unk_04 + 0x24, iVar1->unk_06, 0, 2);
    this->unk_00[2]->proc_mark = PROC_MARK_6;
    this->unk_00[2]->SetPosition(156, 0);
    this->unk_00[2]->func_020354bc(0);
    this->unk_00[2]->SetVisible(TRUE);

    if ((data_02196f0c->state & 0x40) != 0)
    {
        this->unk_00[3] = new (Proc_Start(ProcScr_020ce750, PROC_TREE_6)) map::Button_Common;

        this->unk_00[3]->func_02034838(BUTTON_KIND_START_START, iVar1->unk_04 + 0x30, iVar1->unk_06, 0, 2);
        this->unk_00[3]->proc_mark = PROC_MARK_6;
        this->unk_00[3]->SetPosition(68, 0);
        this->unk_00[3]->func_020354bc(0);
        this->unk_00[3]->SetVisible(TRUE);
    }

    return;
}

// func_ov000_021a561c
void MapStateManager_0C::_021a561c(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (this->unk_00[i] != NULL)
        {
            Proc_End(this->unk_00[i]);
            this->unk_00[i] = NULL;
        }
    }

    return;
}

// func_ov000_021a5650
BOOL MapStateManager_0C::_021a5650(s32 param_2)
{
    if (data_02196f24->controlSettings == 0)
    {
        return FALSE;
    }

    if (this->unk_00[param_2] != NULL)
    {
        return this->unk_00[param_2]->func_02035450();
    }

    return FALSE;
}

EC s32 func_02034f74(s32);
EC void func_02034930(s32, s32, s32);

// func_ov000_021a5688
void MapStateManager_0C::_021a5688(void)
{
    VmMap_Common * iVar1;
    s32 iVar2;
    s32 uVar3;

    iVar1 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_Button"));
    uVar3 = iVar1->unk_04;

    if (data_02196f0c->state & 0x40)
    {
        func_02034930(4, uVar3, iVar1->unk_06);
        iVar2 = func_02034f74(4);
    }
    else
    {
        func_02034930(0, uVar3, iVar1->unk_06);
        iVar2 = func_02034f74(0);
    }

    func_02034930(1, uVar3 + iVar2, -1);

    iVar2 = uVar3 + iVar2 + func_02034f74(1);
    func_02034930(2, iVar2, -1);

    iVar2 = iVar2 + func_02034f74(2);
    func_02034930(0xb, iVar2, -1);

    uVar3 = func_02034f74(0xb);

    if (!(data_02196f0c->state & 0x40))
    {
        return;
    }

    func_02034930(3, iVar2 + uVar3, -1);
    func_02034f74(3);

    return;
}

// func_ov000_021a5768
BOOL MapStateManager_0C::_021a5768(u8 param_2)
{
    return this->unk_22 & param_2;
}

// func_ov000_021a5774
void MapStateManager_0C::_021a5774(s32 param_2)
{
    s32 i;

    this->unk_22 = param_2;

    for (i = 0; i < 4; i++)
    {
        if (this->unk_00[i] != NULL)
        {
            if ((param_2 & (1 << i)) != 0)
            {
                this->unk_00[i]->func_020354a0();
                this->unk_00[i]->SetVisible(FALSE);
            }
            else
            {
                this->unk_00[i]->func_020354bc(0);
                this->unk_00[i]->SetVisible(TRUE);
            }
        }
    }

    return;
}

// func_ov000_021a57e4
void MapStateManager_0C::_021a57e4(s32 i)
{
    if (this->unk_00[i] == NULL)
    {
        return;
    }

    this->unk_00[i]->func_020354a0();
    this->unk_00[i]->SetVisible(FALSE);

    return;
}

// func_ov000_021a5810
void MapStateManager_0C::_021a5810(s32 i)
{
    if (this->unk_00[i] == NULL)
    {
        return;
    }

    this->unk_00[i]->func_020354bc(0);
    this->unk_00[i]->SetVisible(TRUE);

    return;
}

// func_ov000_021a5840
void MapStateManager_0C::_021a5840(s32 i)
{
    if (this->unk_00[i] == NULL)
    {
        return;
    }

    this->unk_00[i]->func_020354bc(0);

    return;
}

extern KeyState * gKeySt;
extern TouchState * gTouchSt;

// func_ov000_021a585c
void MapStateManager_0C::_021a585c(s32 param_2)
{
    struct Vec3 auStack_18;

    if (data_02196f24->controlSettings == 0)
    {
        return;
    }

    if ((gTouchSt->unk_12 == 0) && !(gTouchSt->unk_15 != 0))
    {
        this->unk_14 = -1;
        this->unk_16 = -1;

        return;
    }

    if (param_2 != 0)
    {
        gMapStateManager->camera->func_ov000_021a5228(gTouchSt->unk_00, gTouchSt->unk_02, &auStack_18);

        this->unk_10 = auStack_18.x;
        this->unk_12 = auStack_18.y;

        if (gTouchSt->unk_14 != 0)
        {
            this->unk_14 = this->unk_10;
            this->unk_16 = this->unk_12;
        }
    }
    else
    {
        this->unk_10 = gMapStateManager->cursor->xTile;
        this->unk_12 = gMapStateManager->cursor->yTile;
    }

    this->unk_1e = 1;

    return;
}

static inline BOOL BoundsCheck(s32 x, s32 y)
{
    if (x < gMapStateManager->unk_24)
    {
        return TRUE;
    }
    else if (y < gMapStateManager->unk_25)
    {
        return TRUE;
    }
    else if (x >= gMapStateManager->unk_26)
    {
        return TRUE;
    }
    else if (y >= gMapStateManager->unk_27)
    {
        return TRUE;
    }

    return FALSE;
}

EC BOOL func_ov000_021a5954(s32 x, s32 y)
{
    if (BoundsCheck(x, y))
    {
        return FALSE;
    }

    if (gMapStateManager->unk_08->unk_0854[x | y << 5] < 0)
    {
        return FALSE;
    }

    return TRUE;
}

EC BOOL func_020015e4(MapStateManager_08 *, s32, s32, s32);

EC BOOL func_ov000_021a59cc(s32 x, s32 y)
{
    if (BoundsCheck(x, y))
    {
        return FALSE;
    }

    if (func_020015e4(gMapStateManager->unk_08, x, y, 0) != 0)
    {
        return TRUE;
    }

    if (gMapStateManager->unk_08->unk_0854[x | y << 5] < 0)
    {
        if (func_020015e4(gMapStateManager->unk_08, x, y, 1) != 0)
        {
            return TRUE;
        }

        if (func_020015e4(gMapStateManager->unk_08, x, y, 2) != 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

extern struct Unit * gUnitList;

extern struct UnkStruct_021e3528 data_ov000_021e3528;

// func_ov000_021a5abc
BOOL MapStateManager_0C::_021a5abc(s32 x, s32 y, BOOL param_4)
{
    s32 uVar1;
    s32 uVar2;
    s32 unitId;
    Unit * pUnit;
    s32 i;
    BOOL bVar6;
    s32 pos;

    if (BoundsCheck(x, y))
    {
        return FALSE;
    }

    pos = x | y << 5;

    if (param_4 == 0)
    {
        uVar2 = this->unk_16;
        uVar1 = this->unk_14;
        unitId = gMapStateManager->unk_028[uVar1 | uVar2 << 5];

        if (unitId == 0)
        {
            pUnit = NULL;
        }
        else
        {
            pUnit = gUnitList + unitId - 1;
        }

        if (pUnit != NULL)
        {
            if (unitId == 0)
            {
                pUnit = NULL;
            }
            else
            {
                pUnit = gUnitList + unitId - 1;
            }

            if ((pUnit->state2 & 1) != 0)
            {
                return FALSE;
            }

            return x == uVar1 && y == uVar2;
        }

        if (((data_02196f0c->state & 0x40) != 0) && (x == uVar1 && y == uVar2))
        {
            for (i = 0; i < data_ov000_021e3528.unk_2e; i++)
            {
                if (x == data_ov000_021e3528.unk_00[i * 2 + 0] && y == data_ov000_021e3528.unk_00[i * 2 + 1])
                {
                    bVar6 = TRUE;
                    break;
                }
            }

            if (bVar6)
            {
                return TRUE;
            }
        }

        return FALSE;
    }
    else
    {
        if (x == this->unk_14 && y == this->unk_16)
        {
            if (gMapStateManager->unk_08->unk_0854[pos] >= 0)
            {
                return TRUE;
            }

            if ((param_4 == 1) && (func_ov000_021a59cc(x, y) != 0))
            {
                return TRUE;
            }
        }

        return FALSE;
    }

    return FALSE;
}

class UnkStruct_021e3348
{
public:
    u8 unk_000[1];
    STRUCT_PAD(0x001, 0x118);
    ItemData * unk_118;
    Button * unk_11c[2];
    u8 unk_124;
    s8 unk_125;
    u8 unk_126;
    u8 unk_127;
    s8 unk_128;
    s8 unk_129;
    s8 unk_12a;
    s8 unk_12b;
    u8 unk_12c;
    s8 unk_12d;
    u8 unk_12e;
    STRUCT_PAD(0x12F, 0x130);
};

extern UnkStruct_021e3348 * data_ov000_021e3348;

EC BOOL func_ov000_021b6264(void *, s32, s32);

// func_ov000_021a5c80
BOOL MapStateManager_0C::_021a5c80(s32 param_2, s32 param_3)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (this->unk_00[i] == NULL)
        {
            continue;
        }

        if (!this->unk_00[i]->func_020353b8())
        {
            continue;
        }

        if (this->unk_00[i]->func_020353e0(param_2, param_3))
        {
            return TRUE;
        }
    }

    if (data_ov000_021e3348 != NULL)
    {
        if (func_ov000_021b6264(data_ov000_021e3348, param_2, param_3))
        {
            return TRUE;
        }
    }

    return FALSE;
}

// func_ov000_021a5d08
void MapStateManager_0C::_021a5d08(void)
{
    this->unk_18 = 0;
    this->unk_1a = 0;
    this->unk_1c = 0;
    this->unk_1e = 0;
    this->unk_20 = 0;
    this->unk_23 = 0;
    this->unk_21_0 = 0;
    this->unk_21_2 = 0;
    this->unk_21_4 = 0;
    this->unk_21_6 = 0;
    this->unk_24 = 0;
    this->unk_25 = 0;
    this->unk_26 = 0;

    return;
}

EC BOOL func_ov000_021a63cc(MapStateManager_0C *, s32, s32);

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

// func_ov000_021a5d5c
void MapStateManager_0C::_021a5d5c(s32 param_2)
{
    struct Unit * pUnit;
    s32 unitId;
    s32 unaff_r4;
    s32 uVar7;
    s32 uVar8;
    s32 uVar10;
    s32 uVar11;
    s32 uVar12;
    BOOL bVar13;

    uVar7 = gMapStateManager->cursor->xTile;
    uVar8 = gMapStateManager->cursor->yTile;

    this->unk_18 = 0;
    this->unk_1a = 0;
    this->unk_1c = 0;
    this->unk_1e = 0;
    this->unk_21_0 = 0;
    this->unk_21_4 = 0;
    this->unk_21_2 = 0;
    this->unk_21_6 = 0;
    this->unk_24 = 0;
    this->unk_26 = 0;

    if (gTouchSt->unk_12 != 0 || gTouchSt->unk_15 != 0)
    {
        if (this->_021a5c80(gTouchSt->unk_00, gTouchSt->unk_02) == 0)
        {
            this->unk_25 = 1;
        }
    }

    this->_021a585c(this->unk_25);

    if (this->unk_1e != 0)
    {
        this->unk_1f = 2;

        uVar7 = this->unk_10;

        if (this->unk_10 < gMapStateManager->unk_24)
        {
            uVar7 = gMapStateManager->unk_24;
        }

        uVar8 = this->unk_12;

        if (this->unk_12 < gMapStateManager->unk_25)
        {
            uVar8 = gMapStateManager->unk_25;
        }

        if (uVar7 >= gMapStateManager->unk_26)
        {
            uVar7 = gMapStateManager->unk_26 - 1;
        }

        if (uVar8 >= gMapStateManager->unk_27)
        {
            uVar8 = gMapStateManager->unk_27 - 1;
        }

        if (this->unk_25 != 0)
        {
            gMapStateManager->camera->func_ov000_021a4c30(gTouchSt->unk_00, gTouchSt->unk_02);
            if (gMapStateManager->camera->func_ov000_021a4f4c())
            {
                this->unk_26 = 1;
            }
        }
        else
        {
            pUnit = 0;
        }

        if (gTouchSt->unk_14 != 0)
        {
            if ((pUnit == 0 && unaff_r4 == 0) && (this->_021a5abc(this->unk_10, this->unk_12, param_2) != 0))
            {
                this->unk_21_2 = 1;
                this->unk_23 = 1;
            }

            this->unk_20 = 2;
        }
        else
        {
            if (gTouchSt->unk_15 != 0)
            {
                if (((this->unk_20 & 6) == 0) || !((gTouchSt->unk_10 < 0x1e) ? TRUE : FALSE))
                {
                    bVar13 = FALSE;
                }
                else
                {
                    bVar13 = TRUE;
                }

                if (bVar13)
                {
                    this->unk_20 = 8;

                    if (pUnit != 0)
                    {
                        this->unk_23 = 0;
                    }

                    if (this->unk_23 != 0)
                    {
                        if (this->_021a5abc(this->unk_10, this->unk_12, param_2) != 0)
                        {
                            this->unk_21_0 = 1;
                        }

                        this->unk_23 = 0;
                    }
                }
                else
                {
                    this->unk_20 = 0;
                }

                this->unk_25 = 0;
            }
            else
            {
                this->unk_20 = 4;

                if (pUnit != 0)
                {
                    this->unk_23 = 0;
                }

                if ((this->unk_23 != 0) && (this->_021a5abc(this->unk_10, this->unk_12, param_2) == 0))
                {
                    this->unk_23 = 0;
                }
            }
        }
    }
    else
    {
        if (gKeySt->held != 0)
        {
            this->unk_20 = 0;
            this->unk_25 = 0;
            this->unk_23 = 0;

            this->unk_18 = gKeySt->held;
            this->unk_1a = gKeySt->repeated;
            this->unk_1c = gKeySt->pressed;

            if ((gKeySt->pressed == 0) && ((gKeySt->held & KEY_BUTTON_Y) != 0))
            {
                this->unk_24 = 1;
            }

            unitId = uVar7;
            uVar12 = uVar8;

            if (((gKeySt->repeated & KEY_DPAD_ANY) != 0) ||
                (this->unk_24 != 0 && ((gKeySt->held & KEY_DPAD_ANY) != 0) && ((gKeySt->repeatClock & 1) == 0)))
            {
                this->unk_1f = 1;

                uVar10 = uVar7;

                if (((gKeySt->held & KEY_DPAD_LEFT) != 0) && (uVar10 < gMapStateManager->unk_24))
                {
                    uVar10--;
                }

                if (((gKeySt->held & KEY_DPAD_RIGHT) != 0) && (uVar10 < (gMapStateManager->unk_26 - 1)))
                {
                    uVar10++;
                }

                uVar11 = uVar8;

                if (((gKeySt->held & KEY_DPAD_UP) != 0) && (uVar11 < gMapStateManager->unk_25))
                {
                    uVar11--;
                }

                if (((gKeySt->held & KEY_DPAD_DOWN) != 0) && (uVar11 < (gMapStateManager->unk_27 - 1)))
                {
                    uVar11++;
                }

                unitId = uVar10;
                uVar12 = uVar11;

                if ((param_2 != 0) && (gKeySt->pressed == 0) &&
                    (func_ov000_021a5954(uVar7, uVar8) == 0 ||
                     (func_ov000_021a5954(uVar10, uVar11) != 0 || (func_ov000_021a59cc(uVar10, uVar11) != 0))) &&
                    (func_ov000_021a59cc(uVar7, uVar8) != 0) && (func_ov000_021a59cc(uVar10, uVar11) == 0))
                {
                    unitId = uVar7;
                    uVar12 = uVar8;
                }
            }

            if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
            {
                this->unk_21_0 = 1;
                this->unk_21_2 = 1;
            }

            uVar7 = unitId;
            uVar8 = uVar12;

            if ((gKeySt->pressed & 2) != 0)
            {
                this->unk_21_4 = 1;
                this->unk_21_6 = 1;
            }
        }
        else
        {
            this->unk_20 = 0;
            this->unk_25 = 0;
            this->unk_23 = 0;
        }
    }

    gMapStateManager->cursor->SetPos((s16)uVar7, (s16)uVar8, 1);

    if (gMapStateManager->cursor->changed == 0)
    {
        return;
    }

    unitId = gMapStateManager->unk_028[uVar7 | uVar8 << 5];

    if (unitId == 0)
    {
        pUnit = 0;
    }
    else
    {
        pUnit = gUnitList + unitId - 1;
    }

    if ((pUnit == 0) && (gMapStateManager->unk_04->unk_00 != 0))
    {
        if (uVar7 != pUnit->xPos || uVar8 != pUnit->yPos)
        {
            pUnit = 0;
        }
    }

    if (pUnit != 0)
    {
        func_0204e1a4(pUnit, 2, 1);
    }
    else
    {
        if ((gMapStateManager->unk_04->unk_08 == 1) && (gMapStateManager->unk_04->unk_00 != data_021974fc->unk_00))
        {
            func_0204e1a4(gMapStateManager->unk_04->unk_00, 2, 1);
        }
        else if (gMapStateManager->unk_04->unk_08 == 2)
        {
            unitId = data_ov000_021e3344->unk_34;

            if (unitId == 0)
            {
                pUnit = 0;
            }
            else
            {
                pUnit = gUnitList + unitId - 1;
            }

            if (pUnit != data_021974fc->unk_00)
            {
                if (unitId == 0)
                {
                    pUnit = 0;
                }
                else
                {
                    pUnit = gUnitList + unitId - 1;
                }

                func_0204e1a4(pUnit, 2, 1);
            }
        }
    }

    func_0204eab8(uVar7, uVar8, 2);

    return;
}

EC Menu * func_0202ffb4(ProcPtr proc);

// func_ov000_021a63cc
BOOL MapStateManager_0C::_021a63cc(s32 arg1, s32 arg2)
{
    s32 temp_r2;
    s32 temp_r3;

    Menu * menu = func_0202ffb4(NULL);

    if (menu == NULL)
    {
        return FALSE;
    }

    temp_r3 = menu->unk_34;

    if (arg1 < (temp_r3 * 8))
    {
        return FALSE;
    }

    temp_r2 = menu->unk_35;

    if (arg2 < (temp_r2 * 8))
    {
        return FALSE;
    }

    if (arg1 >= ((temp_r3 + menu->unk_36) * 8))
    {
        return FALSE;
    }

    if (arg2 >= ((temp_r2 + menu->unk_37) * 8))
    {
        return FALSE;
    }

    return TRUE;
}

EC s32 func_ov000_021b60e8(void *, s32, s32, s32);

EC s32 func_ov000_021b615c(void);
EC void PlayerPhase_GotoLabel(s32, s32, s32);

// func_ov000_021a6438
void MapStateManager_0C::_021a6438(void)
{
    s32 var_r0_2;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r4;

    this->unk_18 = 0;
    this->unk_1a = 0;
    this->unk_1c = 0;
    this->unk_1e = 0;

    var_r4 = -1;

    this->unk_21_0 = 0;
    this->unk_21_4 = 0;

    this->unk_26 = 0;

    if ((gTouchSt->unk_12 != 0) || (gTouchSt->unk_15 != 0))
    {
        var_r6 = func_ov000_021a63cc(this, gTouchSt->unk_00, gTouchSt->unk_02);
        var_r7 = this->_021a5c80(gTouchSt->unk_00, gTouchSt->unk_02);

        if ((var_r6 == 0) && (var_r7 == 0))
        {
            this->unk_25 = 1;
        }
    }

    this->_021a585c(this->unk_25);

    if (this->unk_1e != 0)
    {
        this->unk_1f = 2;

        var_r4 = -1;

        if ((var_r6 == 0) && (this->unk_25 != 0))
        {
            var_r5 = gMapStateManager->camera->func_ov000_021a4c30(gTouchSt->unk_00, gTouchSt->unk_02);

            if (gMapStateManager->camera->func_ov000_021a4f4c() != 0)
            {
                this->unk_26 = 1;
            }
        }
        else
        {
            var_r5 = 0;
        }

        if ((var_r5 == 0) && (var_r6 == 0))
        {
            var_r4 = func_ov000_021b60e8(data_ov000_021e3348, this->unk_10, this->unk_12, 0);

            if ((func_0202ffb4(NULL) != 0) && (gTouchSt->unk_14 == 0) && (var_r4 != 0x7F))
            {
                var_r4 = -1;
            }
        }

        if (gTouchSt->unk_14 != 0)
        {
            if ((var_r5 == 0) && (var_r7 == 0))
            {
                if (var_r4 != -1)
                {
                    this->unk_23 = 1;
                }
            }

            this->unk_20 = 2;
        }
        else if (gTouchSt->unk_15 != 0)
        {
            if (this->unk_20 & 6)
            {
                if ((gTouchSt->unk_10 < 30) ? TRUE : FALSE)
                {
                    var_r0_2 = 1;
                }
                else
                {
                    goto block_36;
                }
            }
            else
            {
            block_36:
                var_r0_2 = 0;
            }

            if (var_r0_2 != 0)
            {
                this->unk_20 = 8U;

                if (var_r5 != 0)
                {
                    this->unk_23 = 0;
                }

                if (this->unk_23 != 0)
                {
                    if ((var_r4 != -1) && (var_r4 == this->unk_27))
                    {
                        this->unk_21_0 = 1;
                    }

                    this->unk_23 = 0;
                }
            }
            else
            {
                this->unk_20 = 0;
            }

            this->unk_25 = 0;
        }
        else
        {
            this->unk_20 = 4;

            if (var_r5 != 0)
            {
                this->unk_23 = 0;
            }

            if ((this->unk_23 != 0) && (var_r4 == -1))
            {
                if (var_r4 != this->unk_27)
                {
                    this->unk_23 = 0;
                }
            }
        }
    }
    else if (gKeySt->held & ~0)
    {
        this->unk_20 = 0;
        this->unk_25 = 0;

        this->unk_18 = gKeySt->held & ~0;
        this->unk_1a = gKeySt->repeated & ~0;
        this->unk_1c = gKeySt->pressed & ~0;

        if (gKeySt->held & KEY_DPAD_ANY)
        {
            this->unk_1f = 1;
        }

        if (gKeySt->pressed & KEY_BUTTON_A)
        {
            this->unk_21_0 = 1;
        }

        if (gKeySt->pressed & KEY_BUTTON_B)
        {
            this->unk_21_2 = 1;
        }

        if (gKeySt->pressed & (KEY_BUTTON_X | KEY_BUTTON_Y))
        {
            if (!(((data_ov000_021e3348->unk_125 != -1) ? TRUE : FALSE) & 0xFF))
            {
                var_r4 = func_ov000_021b615c();
                if (var_r4 != -1)
                {
                    PlayerPhase_GotoLabel(39, 0, 0);
                }
            }
        }
    }
    else
    {
        this->unk_20 = 0;
        this->unk_25 = 0;
    }

    this->unk_27 = var_r4;

    return;
}

// func_ov000_021a6800
BOOL MapStateManager_0C::_021a6800(void)
{
    if ((gMapStateManager->cursor->isVisible || data_ov000_021e3348 != 0) && (gMapStateManager->unk_0c->unk_1e != 0) &&
        (!((gMapStateManager->unk_0c->unk_20 != 8 ? FALSE : TRUE) & 0xFF)))
    {
        if ((this->unk_26 == 0) && (this->_021a5c80(gTouchSt->unk_00, gTouchSt->unk_02) != 0))
        {
            return FALSE;
        }

        if (func_ov000_021a63cc(this, gTouchSt->unk_00, gTouchSt->unk_02))
        {
            return FALSE;
        }

        return TRUE;
    }

    return FALSE;
}
