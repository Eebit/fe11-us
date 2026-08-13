#include "global.h"

#include <new>

#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "action.hpp"
#include "anime.hpp"
#include "database.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"

#include "constants/sounds.h"

enum
{

    L_PLAYERPHASE_END_PREP = 3,

    L_PLAYERPHASE_WARP = 7,

    L_PLAYERPHASE_ACT = 12, // 0 attack, 1 staff, 4 item, 7 trade, 10 imitate
    L_PLAYERPHASE_TRADE = 13,
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

struct UnkStruct_021e332c
{
    STRUCT_PAD(0x00, 0x04);
};

class CpSkip : public Skip
{
public:
    CpSkip(s32 a) : Skip(a)
    {
    }

    u8 Get06() const
    {
        return this->unk_06;
    };

    BOOL Check06__()
    {
        if (this->unk_06 == 4)
        {
            return FALSE;
        }
        else if (this->unk_06 == 0)
        {
            return FALSE;
        }
        else if (this->unk_06 == 1)
        {
            return FALSE;
        }

        return TRUE;
    }

    BOOL Check06_State4()
    {
        return this->unk_06 == 4;
    }

    BOOL Check06(s32 state)
    {
        return this->unk_06 == state;
    }

    BOOL Check06_Other()
    {
        return (this->unk_06 == 0) || (this->unk_06 == 2);
    }
};

struct UnkStruct_021e332c * data_ov000_021e332c; // sizeof = 4
ProcPtr data_ov000_021e3330;
CpSkip * data_ov000_021e3334; // CpSkip
ProcPtr data_ov000_021e3338;
ProcPtr data_ov000_021e333c; // ProcPL
struct UnkStruct_021e3340 * data_ov000_021e3340;
// 0x021e3344 // gActionSt

extern struct UnkStruct_02196f0c * data_02196f0c;

extern struct UnkStruct_02196f10 * data_02196f10;

extern struct TouchState * gTouchSt;

extern vu32 gElapsedFrames;

namespace map
{

class ProcPL : public ProcEx
{
public:
    u32 unk_38;

    ProcPL()
    {
        data_ov000_021e333c = this;
        gMapStateManager->unk_14->unk_27 = 1;
    }

    virtual ~ProcPL()
    {
        gMapStateManager->inputHandler->_021a5d08();
        gMapStateManager->unk_14->unk_27 = 0;
        data_ov000_021e3340->unk_06 = 0;
        data_ov000_021e333c = NULL;
    }

    // func_ov000_021b0964 d1
    // func_ov000_021b0904 d0
};

}; // namespace map

class ProcSeq : public ProcEx
{
public:
    s32 unk_38;

    ProcSeq()
    {
        this->unk_38 = 0;
    }

    virtual ~ProcSeq()
    {
    }
};

class TurnRegenerateExec : public ProcEx
{
public:
    Unit * unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;

    TurnRegenerateExec()
    {
        this->unk_38 = Force::Get(data_ov000_021e3324->phase)->head;
        this->unk_3c = 0;
    }

    // func_ov000_021b0d70
    // func_ov000_021b0d74
    virtual ~TurnRegenerateExec()
    {
    }
};

EC void func_ov000_021a81d4(void)
{
    data_ov000_021e3334->Init();
    return;
}

EC void func_ov000_021a820c(void)
{
    func_ov000_021a35a0();

    if (data_ov000_021e3334->unk_06 == 0 || data_ov000_021e3334->unk_06 == 2)
    {
        data_ov000_021e3334->unk_06 = 1;
    }

    if (data_ov000_021e3334->unk_06 == 4)
    {
        data_ov000_021e3334->unk_06 = 6;
    }

    return;
}

EC BOOL func_ov000_021a8248(void)
{
    if (data_ov000_021e3334 == NULL)
    {
        return FALSE;
    }

    return data_ov000_021e3334->IsSkipState4();
}

EC BOOL func_ov000_021a8274(void)
{
    if (data_ov000_021e3334 == NULL)
    {
        return FALSE;
    }

    if (data_ov000_021e3334->unk_06 == 4)
    {
        return TRUE;
    }

    if (data_ov000_021e3334->unk_06 == 5 || data_ov000_021e3334->unk_06 == 6)
    {
        if (data_ov000_021e3334->unk_07 != 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL func_ov000_021a82c0(void)
{
    if (data_ov000_021e3334 == NULL)
    {
        return FALSE;
    }

    if (data_ov000_021e3334->unk_06 == 4)
    {
        return FALSE;
    }

    if (data_ov000_021e3334->unk_06 == 0)
    {
        return FALSE;
    }

    return data_ov000_021e3334->IsSkipState1();
}

EC void func_ov000_021a8304(void)
{
    if (gActionSt == NULL)
    {
        gActionSt = new ActionState();
    }

    if (data_ov000_021e332c == NULL)
    {
        data_ov000_021e332c = new UnkStruct_021e332c();
    }

    if (data_ov000_021e3340 == NULL)
    {
        data_ov000_021e3340 = new UnkStruct_021e3340();
    }

    data_ov000_021e3334 = new CpSkip(0x12);
    data_ov000_021e3334->Init();

    return;
}

EC void func_ov000_021a83d0(void)
{
    delete gActionSt;
    gActionSt = NULL;

    delete data_ov000_021e332c;
    data_ov000_021e332c = NULL;

    delete data_ov000_021e3340;
    data_ov000_021e3340 = NULL;

    delete data_ov000_021e3334;
    data_ov000_021e3334 = NULL;

    return;
}

EC void func_ov000_021a8438(ProcSeq * unused)
{
    gMapStateManager->inputHandler->_021a5688();
    gMapStateManager->inputHandler->CreateButtons();
    return;
}

EC void func_ov000_021a8464(void)
{
    gMapStateManager->inputHandler->DestroyButtons();
    return;
}

extern u8 data_ov000_021e3320[];

struct UnkStruct_ov000_021a8480_Anim
{
    STRUCT_PAD(0x00, 0x3C);
    AnimeInterpreter * unk_3c;
};

class UnkStruct_ov000_021a8480_Proc : public ProcEx
{
public:
    UnkStruct_ov000_021a8480_Anim * unk_38;
};

EC void * func_ov000_021d3350(char *, s32, s32, s32, s32, ProcPtr, s32, s32, s32);
EC struct UnkStruct_Func_02021410_Ret * func_02021410(u32);

EC void func_ov000_021a8480(ProcPtr param_1)
{
    UnkStruct_ov000_021a8480_Proc * proc;
    AnimeInterpreter * interp;
    BOOL flag = FALSE;
    char * name;

    if (!func_ov000_021a47e4())
    {
        return;
    }

    if (!((data_02196f10->unk_00 != 0 ? TRUE : FALSE) & 0xFF) || data_02196f10->unk_0b == 0)
    {
        return;
    }

    if (func_02021410(1)->unk_756 != 0)
    {
        proc = (UnkStruct_ov000_021a8480_Proc *)func_ov000_021d3350(
            "CardLeft", 0x80, 0x60, 0, 0, param_1, 1, 0, 1);

        interp = proc->unk_38->unk_3c;

        if (interp != NULL)
        {
            interp->SetAffineId(1);
        }

        flag = TRUE;

        name = const_cast<char *>((data_ov000_021e3320[0] == 1) ? "EnemycardFontLeft" : "PlayercardFontLeft");

        func_ov000_021d3350(name, 0x80, 0x60, 0, 0, param_1, flag, 0, flag);
    }

    if (func_02021410(0)->unk_756 == 0)
    {
        return;
    }

    proc =
        (UnkStruct_ov000_021a8480_Proc *)func_ov000_021d3350("CardRight", 0x80, 0x60, 0, 0, param_1, 1, 0, 1);

    interp = proc->unk_38->unk_3c;

    if (interp != NULL)
    {
        interp->SetAffineId(2);
    }

    if (flag)
    {
        interp = proc->unk_38->unk_3c;

        if (interp != NULL)
        {
            interp->SetFlag16(1);
        }
    }

    name = const_cast<char *>((data_ov000_021e3320[0] == 1) ? "PlayercardFontRight" : "EnemycardFontRight");

    proc = (UnkStruct_ov000_021a8480_Proc *)func_ov000_021d3350(name, 0x80, 0x60, 0, 0, param_1, 1, 0, 1);

    if (!flag)
    {
        return;
    }

    interp = proc->unk_38->unk_3c;

    if (interp != NULL)
    {
        interp->SetFlag16(1);
    }

    return;
}

EC void func_ov000_021a8650(void)
{
    s32 iVar3;
    Unit * psVar5;

    if (!func_ov000_021a47e4())
    {
        return;
    }

    if (!((data_02196f10->unk_00 != 0 ? TRUE : FALSE) & 0xFF) || data_02196f10->unk_0b == 0)
    {
        return;
    }

    for (iVar3 = 0; iVar3 < 2; iVar3++)
    {
        switch (func_02021410(iVar3)->unk_756)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 0xc:
                for (psVar5 = Force::Get(iVar3)->head; psVar5 != NULL; psVar5 = psVar5->unk_3c)
                {
                    switch (func_02021410(iVar3)->unk_756)
                    {
                        case 1:
                            psVar5->unk_50[1]++;
                            break;
                        case 2:
                            psVar5->unk_50[2]++;
                            break;
                        case 3:
                            psVar5->unk_50[3]++;
                            break;
                        case 4:
                            psVar5->unk_50[4]++;
                            break;
                        case 5:
                            psVar5->unk_50[6]++;
                            break;
                        case 6:
                            psVar5->unk_50[7]++;
                            break;
                        case 0xc:
                            if ((psVar5->pJobData->unitType & 4) != 0)
                            {
                                psVar5->unk_6d++;
                            }
                    }
                }
                break;

            case 0xd:
            case 0x12:
                for (psVar5 = Force::Get((iVar3 + 1) & 1)->head; psVar5 != NULL; psVar5 = psVar5->unk_3c)
                {
                    switch (func_02021410(iVar3)->unk_756)
                    {
                        case 0x12:
                            psVar5->hp = psVar5->hp - IntSys_Div(psVar5->hp * 20, 100);
                            break;

                        case 0xd:
                            if ((psVar5->pJobData->unitType & 0x20) != 0)
                            {
                                psVar5->unk_6d--;
                            }

                            break;
                    }
                }
        }
    }
}

EC void func_ov000_021a48b0(u32 arg_0);
EC void func_ov000_021b9660(MapStateManager_14 *, u32);
EC void func_ov000_021baafc(MapStateManager_14_00 *, Unit *, BOOL);

EC void func_ov000_021a8868(void)
{
    Unit * psVar1;
    s32 iVar2;

    func_02000c7c(gMapStateManager->unk_08);
    func_ov000_021b9660(gMapStateManager->unk_14, data_ov000_021e3324->unk_01);

    for (psVar1 = Force::Get(data_ov000_021e3324->phase)->head; psVar1 != NULL; psVar1 = psVar1->unk_3c)
    {
        if (psVar1->unk_91 != 0)
        {
            psVar1->unk_91--;
        }

        if (psVar1->unk_92 != 0)
        {
            psVar1->unk_92--;
        }

        if (psVar1->unk_93 != 0)
        {
            psVar1->unk_93--;
        }

        if (((psVar1->state2 & 0x8000) != 0) && (psVar1->unk_93 == 0))
        {
            func_0203bf68(psVar1);
            func_ov000_021baafc(gMapStateManager->unk_14->unk_00, psVar1, FALSE);
        }
    }

    for (iVar2 = 0; iVar2 < 2; iVar2++)
    {
        for (psVar1 = Force::Get(iVar2)->head; psVar1 != NULL; psVar1 = psVar1->unk_3c)
        {
            psVar1->state2 &= 0xffffbfff;
        }
    }

    if (data_ov000_021e3324->unk_02 != 0)
    {
        func_ov000_021a37c4();
        func_ov000_021a340c();
        func_ov000_021a35a0();
    }

    func_ov000_021a48b0(data_ov000_021e3324->unk_0c);
    func_0204bbb4(0);

    return;
}

extern u8 data_ov000_021e3320[];

EC void func_ov000_021a89b0(ProcPtr param_1)
{
    if (data_ov000_021e3320[data_ov000_021e3324->phase] == 1)
    {
        return;
    }

    if (Force::Get(data_ov000_021e3324->phase)->Count() == 0)
    {
        Proc_Goto(param_1, 7, 0);
    }

    return;
}

EC void func_ov000_021a8a00(s32 param_1, s32 param_2)
{
    s32 iVar1;
    s32 iVar2;
    Unit * psVar3;

    if (data_ov000_021e3320[param_1] == 1)
    {
        if (data_02196f24->autoCursorEnabled != 0 || gMapStateManager->cursor->unk_00[param_1] == -1)
        {
            if (!func_ov000_021a47e4())
            {
                psVar3 = Force::Get(param_1)->FindByAttribute(2);
            }
            else
            {
                psVar3 = NULL;
            }

            if (psVar3 == NULL)
            {
                psVar3 = Force::Get(param_1)->head;
            }

            if (psVar3 != NULL)
            {
                gMapStateManager->cursor->SetPosImmediate(psVar3->xPos, psVar3->yPos);

                if (param_2 == 0)
                {
                    gMapStateManager->camera->Scroll(
                        gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile, 0, 0, 0);
                    return;
                }

                gMapStateManager->camera->ScrollInstant(
                    gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile, 1);

                return;
            }
        }
        else
        {
            gMapStateManager->cursor->SetPosImmediate(
                gMapStateManager->cursor->unk_00[param_1], gMapStateManager->cursor->unk_02[param_1]);

            if (param_2 == 0)
            {
                gMapStateManager->camera->Scroll(
                    gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile, 0, 0, 0);
                return;
            }

            gMapStateManager->camera->ScrollInstant(
                gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile, 1);

            return;
        }

        gMapStateManager->cursor->CenterOnCamera();

        return;
    }

    if (data_ov000_021e3320[param_1] != 3)
    {
        return;
    }

    iVar1 = -1;

    for (iVar2 = 0; iVar2 < 2; iVar2++)
    {
        if (data_ov000_021e3320[iVar2] == 1)
        {
            break;
        }
    }

    if (iVar1 == -1)
    {
        return;
    }

    if (gMapStateManager->cursor->unk_00[iVar1] == -1)
    {
        func_ov000_021a8a00(iVar1, 0);
        return;
    }

    gMapStateManager->cursor->SetPosImmediate(
        gMapStateManager->cursor->unk_00[iVar1], gMapStateManager->cursor->unk_02[iVar1]);

    if (param_2 == 0)
    {
        gMapStateManager->camera->Scroll(gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile, 0, 0, 0);
        return;
    }

    gMapStateManager->camera->ScrollInstant(gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile, 1);

    return;
}

EC void func_ov000_021a8c7c(void)
{
    func_ov000_021a8a00(data_ov000_021e3324->phase, 0);
    return;
}

EC void * func_ov000_021d3350(char *, s32, s32, s32, s32, ProcPtr, s32, s32, s32);

EC void func_ov000_021a8c9c(ProcPtr param_1)
{
    if (func_ov000_021a478c())
    {
        if (data_ov000_021e3324->phase != 0)
        {
            if (data_ov000_021e3324->phase != 1)
            {
                if (data_ov000_021e3320[1] != 1)
                {
                    func_ov000_021d3350("EnemyPhaseBlue", 0x80, 0x60, 0, 0, param_1, 1, 0, 1);
                    return;
                }
                else
                {
                    func_ov000_021d3350("PlayerPhaseRed", 0x80, 0x60, 0, 0, param_1, 1, 0, 1);
                }
            }
        }
        else
        {
            if (data_ov000_021e3320[0] == 1)
            {
                func_ov000_021d3350("PlayerPhase", 0x80, 0x60, 0, 0, param_1, 1, 0, 1);
                return;
            }
            else
            {
                func_ov000_021d3350("EnemyPhaseBlue", 0x80, 0x60, 0, 0, param_1, 1, 0, 1);
                return;
            }
        }
    }
    else
    {
        if (data_ov000_021e3324->phase != 0)
        {
            func_ov000_021d3350("PlayerPhase", 0x80, 0x60, 0, 0, param_1, 1, 0, 1);
            return;
        }

        if (data_ov000_021e3324->phase == 1)
        {
            func_ov000_021d3350("EnemyPhaseBlue", 0x80, 0x60, 0, 0, param_1, 1, 0, 1);
            return;
        }
    }
    return;
}

EC s32 GetMapBgmId(s32);

EC void func_ov000_021a8e34(ProcSeq * unused)
{
    s32 iVar1 = GetMapBgmId(data_ov000_021e3324->phase);

    if (iVar1 != -1)
    {
        gSoundManager->unk_a4->vfunc_30(iVar1, 0, 0);
    }

    return;
}

EC void func_ov000_021a8e84(void)
{
    if (gSoundManager->unk_a4->vfunc_58())
    {
        return;
    }

    if (gSoundManager->unk_a8->vfunc_58())
    {
        return;
    }

    gSoundManager->unk_a4->vfunc_38(0x20);

    return;
}

EC void func_ov000_021a8eec(ProcPtr param_1)
{
    if (!data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        gSoundManager->unk_a4->vfunc_38(0x20);
    }

    return;
}

extern struct ProcCmd ProcScr_020ce750[];

EC void func_ov000_021a8f38(ProcPtr param_1)
{
    new (Proc_StartBlocking(ProcScr_020ce750, param_1)) TurnRegenerateExec();
    return;
}

extern u8 data_ov000_021e3320[];

EC void func_ov000_021a8f88(void)
{
    switch (data_ov000_021e3320[data_ov000_021e3324->phase])
    {
        case 0:
            func_ov000_021a969c(7);
            return;

        case 1:
            func_ov000_021a969c(4);
            return;

        case 2:
            func_ov000_021a969c(5);
            return;

        case 3:
            func_ov000_021a969c(6);
            return;

        default:
            return;
    }
}

EC void func_ov000_021a8ff4(void)
{
    Unit * psVar2;

    if (data_ov000_021e3324->unk_02 != 0)
    {
        for (psVar2 = Force::Get(data_ov000_021e3324->phase)->head; psVar2 != NULL; psVar2 = psVar2->unk_3c)
        {
            psVar2->state2 &= 0xffffbfff;
        }

        func_ov000_021a340c();
    }

    return;
}

EC void func_ov000_021a9044(ProcSeq * param_1)
{
    s32 cVar1;

    param_1->unk_38++;

    cVar1 = Interpolate(0, 0x10, 0, param_1->unk_38, 4);

    gMapStateManager->unk_14->unk_00->unk_08 = func_0202025c(0x2108, 0x7fff, cVar1, 0x10 - cVar1);
    gMapStateManager->unk_14->unk_00->unk_0a = func_0202025c(0x84c, 0x211f, cVar1, 0x10 - cVar1);

    if (param_1->unk_38 == 4)
    {
        gMapStateManager->unk_14->unk_00->unk_08 = 0x2108;
        gMapStateManager->unk_14->unk_00->unk_0a = 0x84c;

        param_1->unk_38 = 0;

        Proc_Break(param_1, 1);
    }

    return;
}

extern s32 data_ov000_021e24c0;
EC BOOL func_ov000_021a2a50(struct UnkStruct_021E3324 * self);

EC void func_ov000_021a9138(void)
{
    Unit * psVar3;

    for (psVar3 = Force::Get(data_ov000_021e3324->phase)->head; psVar3 != NULL; psVar3 = psVar3->unk_3c)
    {
        psVar3->state2 &= ~1;
    }

    if (func_ov000_021a2a50(data_ov000_021e3324))
    {
        return;
    }

    if (func_ov000_021a47e4())
    {
        if ((data_ov000_021e24c0 >= 0) && (data_ov000_021e24c0 < 2) && (data_ov000_021e3320[data_ov000_021e24c0] != 1))
        {
            data_02196f0c->flagMgr->SetByName("gf_complete");
            func_ov000_021a969c(8);
            return;
        }
        else
        {
            data_02196f0c->flagMgr->SetByName("gf_gameover");
            func_ov000_021a969c(9);

            return;
        }
    }
    else
    {
        data_02196f0c->flagMgr->SetByName("gf_gameover");
        func_ov000_021a969c(9);
        return;
    }
}

EC void func_ov000_021a9230(ProcSeq * param_1)
{
    s32 cVar1;

    param_1->unk_38++;

    if (param_1->unk_38 <= 8)
    {
        cVar1 = Interpolate(0, 0x10, 0, param_1->unk_38, 8);

        gMapStateManager->unk_14->unk_00->unk_08 = func_0202025c(0x2108, 0x7fff, cVar1, 0x10 - cVar1);
        gMapStateManager->unk_14->unk_00->unk_0a = func_0202025c(0x84c, 0x7fff, cVar1, 0x10 - cVar1);
        gMapStateManager->unk_14->unk_04->unk_1a = Interpolate(0, 0x1f, 0, param_1->unk_38, 8);
    }
    if (param_1->unk_38 == 0x10)
    {
        gMapStateManager->unk_14->unk_00->unk_08 = 0x2108;
        gMapStateManager->unk_14->unk_00->unk_0a = 0x84c;
        gMapStateManager->unk_14->unk_04->unk_1a = 0x1f;

        param_1->unk_38 = 0;

        Proc_Break(param_1, TRUE);
    }

    return;
}

class ProcArenaSync : public ProcEx
{
public:
    ProcArenaSync()
    {
    }

    // func_ov000_021b0d88
    // func_ov000_021b0d8c
    virtual ~ProcArenaSync()
    {
    }
};

EC void func_02014ad0(void);

EC void func_ov000_021a936c(void)
{
    func_02014ad0();
    return;
}

EC void func_020127c4(s32, ProcPtr);

EC void func_ov000_021a9378(ProcPtr param_1)
{
    func_020127c4(0x574d5356, param_1);
    return;
}

EC Dialog * func_02014834(ProcPtr param_1, char * param_2, s32 param_3, s32 param_4, u8 param_5, s32 param_6);

EC void func_ov000_021a9390(ProcPtr param_1)
{
    func_02014834(param_1, GetText("MLink_ArenaSync"), 3, 0, 1, 1);
    return;
}

EC void func_0203bcf4(Unit *);
EC void func_0203d874(Unit *);

extern struct ProcCmd data_ov000_021dbc74[]; // ProcScr_ProcArenaSync

EC void func_ov000_021a93d0(ProcPtr param_1)
{
    s32 iVar1;
    Unit * psVar5;

    if (!func_ov000_021a47e4())
    {
        for (iVar1 = 0; iVar1 < 2; iVar1++)
        {
            for (psVar5 = Force::Get(iVar1)->head; psVar5 != NULL; psVar5 = psVar5->unk_3c)
            {
                func_0203bcf4(psVar5);
                func_ov000_021baafc(gMapStateManager->unk_14->unk_00, psVar5, 0);
                func_0203d874(psVar5);
            }
        }

        gMapStateManager->cursor->isVisible = FALSE;
        func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

        data_ov000_021e3324->unk_03 = 0;

        func_ov000_021a35a0();

        data_02196f20->unk_1a1 = data_ov000_021e3324->turn;

        return;
    }

    if (data_02196f10->unk_17 != 0)
    {
        func_02014834(param_1, GetText("MLink_OpponentSurrender"), 1, 1, 1, 1);

        if (func_ov000_021a478c())
        {
            func_020127c4(0x574d5356, param_1);
        }
    }
    else
    {
        if (func_ov000_021a478c())
        {
            new (Proc_StartBlocking(data_ov000_021dbc74, param_1)) ProcArenaSync();
        }
    }

    data_02196f10->unk_07 = 0;

    return;
}

EC void func_ov000_021a9550(ProcPtr param_1)
{
    if (!func_ov000_021a47e4())
    {
        GameCtrl_GotoLabel(0xc);
        return;
    }

    if (func_ov000_021a478c())
    {
        new (Proc_StartBlocking(data_ov000_021dbc74, param_1)) ProcArenaSync();
    }

    data_02196f10->unk_07 = 1;

    return;
}

class SallyPosChangeHelpFirst : public ProcEx
{
public:
    s32 unk_38;

    SallyPosChangeHelpFirst()
    {
        this->unk_38 = 4;
    }

    // func_ov000_021b0da0
    // func_ov000_021b0da4
    virtual ~SallyPosChangeHelpFirst()
    {
    }
};

EC void func_ov000_021a95b4(ProcPtr param_1)
{
    gMapStateManager->cursor->isVisible = TRUE;
    gMapStateManager->inputHandler->SetButtonVisibility(0xf);
    gMapStateManager->inputHandler->_021a5840(0);
    gMapStateManager->inputHandler->_021a5840(1);
    gMapStateManager->inputHandler->_021a5840(3);

    new (Proc_Start(ProcScr_020ce750, param_1)) SallyPosChangeHelpFirst();

    return;
}

EC void func_ov000_021a9650(void)
{
    gMapStateManager->inputHandler->SetButtonVisibility(0xf);
    return;
}

EC void func_ov000_021a9670(void)
{
    gMapStateManager->cursor->isVisible = FALSE;
    gMapStateManager->inputHandler->SetButtonVisibility(0);
    return;
}

extern struct ProcCmd data_ov000_021dc028[];

EC void func_ov000_021a969c(s32 param_1)
{
    Proc_Goto(Proc_Find(data_ov000_021dc028), param_1, 0);
    return;
}

EC void func_ov000_021a32c8(void);

extern struct ProcCmd data_ov000_021dbe58[];

EC void StartProcSeq(ProcPtr param_1)
{
    if (gMapStateManager->unk_1c != NULL)
    {
        func_ov000_021a32c8();
    }

    new (Proc_StartBlocking(data_ov000_021dbe58, param_1)) ProcSeq();

    return;
}

EC void func_ov000_021a8438(ProcSeq *);
EC void func_ov000_021a8e34(ProcSeq *);

EC void func_ov000_021a9714(ProcPtr param_1)
{
    ProcSeq * puVar1;

    if (gMapStateManager->unk_1c != NULL)
    {
        func_ov000_021a32c8();
    }

    puVar1 = new (Proc_StartBlocking(data_ov000_021dc028, param_1)) ProcSeq();

    if (data_02196f0c->state & 4)
    {
        func_ov000_021a969c(3);
        func_ov000_021a8438(puVar1);
        func_ov000_021b9660(gMapStateManager->unk_14, data_ov000_021e3324->unk_01);
        func_ov000_021a8e34(puVar1);
    }

    return;
}

class EventFixed : public ProcEx
{
public:
    u32 unk_38;
    u32 unk_3c;
    u32 unk_40;

    EventFixed(s32 param_2, s32 param_3, s32 param_4)
    {
        this->unk_38 = param_2;
        this->unk_3c = param_3;
        this->unk_40 = param_4;
    }

    // func_ov000_021b0db8
    // func_ov000_021b0dbc
    virtual ~EventFixed()
    {
    }
};

EC void func_ov000_021a97b8(EventFixed * param_1)
{
    EventCaller::TryStartAreaEvent(param_1, param_1->unk_38, param_1->unk_3c);
    return;
}

EC s32 func_ov000_021d49f4(s32, s32, s32);

EC void func_ov000_021a97cc(EventFixed * param_1)
{
    if (gActionSt->actionId != 0x13)
    {
        return;
    }

    if (func_ov000_021d49f4(gActionSt->xDecision, gActionSt->yDecision, 0x13))
    {
        EventCaller::TryStartVisitEvent(param_1, gActionSt->xDecision, gActionSt->yDecision, 0x13);
    }

    return;
}

EC void func_ov000_021a9824(EventFixed * param_1)
{
    if ((param_1->unk_40 & 1) != 0)
    {
        gMapStateManager->camera->Scroll(param_1->unk_38, param_1->unk_3c, 0, 0x20, 0);
        return;
    }
    return;
}

EC void func_ov000_021a9870(EventFixed * param_1)
{
    if (!gMapStateManager->camera->IsMoving())
    {
        Proc_End(param_1);
    }

    return;
}

extern struct ProcCmd data_ov000_021dbcac[];

EC void func_ov000_021a98a4(ProcPtr param_1, s32 param_2, s32 param_3, s32 param_4)
{
    new (Proc_StartBlocking(data_ov000_021dbcac, param_1)) EventFixed(param_2, param_3, param_4);
    return;
}

EC void func_ov000_021a7214(void *, Unit *, s32);

class MotionDispDelay : public ProcEx
{
public:
    Unit * unk_38;
    s32 unk_3c;

    MotionDispDelay(Unit * param_1, s32 param_2)
    {
        this->unk_38 = param_1;
        this->unk_3c = param_2;
    }

    // func_ov000_021b086c
    // func_ov000_021b08bc
    virtual ~MotionDispDelay()
    {
        this->unk_38->state2 |= 0x20000;
        func_ov000_021a7214(gMapStateManager->unk_04, this->unk_38, 1);
    }
};

EC BOOL func_ov000_021a98ec(s32 param_1, s32 param_2)
{
    if (EventCaller::CanStartAreaEvent(param_1, param_2))
    {
        return TRUE;
    }

    if (gActionSt->actionId == ACTION_DECOY && func_ov000_021d49f4(param_1, param_2, ACTION_DECOY) &&
        EventCaller::CanStartVisitEvent(param_1, param_2, ACTION_DECOY))
    {
        return TRUE;
    }

    return FALSE;
}

EC struct Unit * func_ov000_021a995c(struct Unit * unit, s32 forceId)
{
    BOOL flag;
    struct Unit * cur;

    if (unit == NULL)
    {
        cur = Force::Get(forceId)->head;
        flag = TRUE;
    }
    else
    {
        flag = (forceId == unit->force->id);
        forceId = unit->force->id;

        if (unit->unk_3c != NULL)
        {
            cur = unit->unk_3c;
        }
        else
        {
            cur = Force::Get(forceId)->head;
        }

        if (cur == unit)
        {
            return NULL;
        }
    }

    if (cur == NULL)
    {
        return NULL;
    }

    for (;;)
    {
        if (flag)
        {
            if ((cur->state2 & 0xe1) == 0)
            {
                return cur;
            }
        }
        else
        {
            if (cur->unk_68 == gMapStateManager->unk_028[cur->xPos | cur->yPos << 5])
            {
                return cur;
            }
        }

        cur = cur->unk_3c;

        if (unit == NULL && cur == NULL)
        {
            return NULL;
        }

        if (cur == NULL)
        {
            cur = Force::Get(forceId)->head;
        }

        if (cur == unit)
        {
            return NULL;
        }
    }
}

EC void func_ov000_021a9a48(void)
{
    s32 iVar1;
    Unit * psVar2;
    s32 iVar3;
    s32 i;

    if (!func_ov000_021a47e4())
    {
        if ((data_02196f0c->pCurrentMap->_pad_0x08[0] & 2) != 0)
        {
            iVar1 = 0;

            for (i = 0; i < 2; i++)
            {
                if ((i == 0 ? TRUE : FALSE) & 0xFF)
                {
                    continue;
                }

                for (psVar2 = Force::Get(i)->head; psVar2 != NULL; psVar2 = psVar2->unk_3c)
                {
                    iVar1++;
                }
            }

            if (iVar1 == 0)
            {
                data_02196f0c->flagMgr->SetByName("gf_complete");
            }
        }

        if ((data_02196f0c->pCurrentMap->_pad_0x08[0] & 4) == 0)
        {
            return;
        }

        iVar1 = 0;

        for (i = 0; i < 2; i++)
        {
            if ((i == 0 ? TRUE : FALSE) & 0xFF)
            {
                continue;
            }

            for (psVar2 = Force::Get(i)->head; psVar2 != NULL; psVar2 = psVar2->unk_3c)
            {
                if (CheckUnitAttribute(psVar2, 0x1000))
                {
                    iVar1++;
                }
            }
        }

        if (iVar1 == 0)
        {
            data_02196f0c->flagMgr->SetByName("gf_complete");
            return;
        }

        return;
    }

    iVar1 = -1;

    for (i = 0; i < 2; i++)
    {
        if (data_ov000_021e3320[i] == 1)
        {
            iVar1 = i;
            break;
        }
    }

    if (iVar1 == -1)
    {
        return;
    }

    iVar3 = 0;

    for (i = 0; i < 2; i++)
    {
        if ((iVar3 == i ? TRUE : FALSE) & 0xff)
        {
            continue;
        }

        for (psVar2 = Force::Get(i)->head; psVar2 != NULL; psVar2 = psVar2->unk_3c)
        {
            iVar3++;
        }
    }

    if (iVar3 == 0)
    {
        data_02196f0c->flagMgr->SetByName("gf_complete");
    }

    for (i = 0; i < 2; i++)
    {
        if (!((i == iVar1 ? TRUE : FALSE) & 0xFF))
        {
            continue;
        }

        for (psVar2 = Force::Get(i)->head; psVar2 != NULL; psVar2 = psVar2->unk_3c)
        {
            iVar3++;
        }
    }

    if (iVar1 == 0)
    {
        data_02196f0c->flagMgr->SetByName("gf_gameover");
    }

    return;
}

EC BOOL func_ov000_021a9cac(void)
{
    return Force::Get(data_ov000_021e3324->phase != 1)->Count() != 0;
}

EC void func_ov000_021a9ce4(void)
{
    s32 x;
    s32 y;
    Unit * psVar2;

    data_ov000_021e3340->unk_01 = 0;
    data_ov000_021e3340->unk_08 = 0;
    data_ov000_021e3340->unk_09 = 0;
    data_ov000_021e3340->unk_06 = 0;

    x = gMapStateManager->cursor->xTile;
    y = gMapStateManager->cursor->yTile;
    psVar2 = GetUnit(gMapStateManager->unk_028[x | y << 5]);

    data_021974fc->unk_00 = psVar2;

    func_0204b194(x, y);

    if (func_0204ae9c(1, 1) == 0)
    {
        func_0204e1a4(psVar2, 0, 1);
    }

    func_0204eb24();

    return;
}

EC void func_ov000_021a9d98(Unit * unit)
{
    struct MapStateManager_08 * pMsm08;

    gActionSt->unk_2c = unit->xPos;
    gActionSt->unk_2d = unit->yPos;
    gActionSt->unk_2e = func_ov000_021a4854(unit);
    gActionSt->unitId = unit->unk_68;

    if (func_ov000_021a478c())
    {
        gActionSt->func_ov000_021b0eb4(unit);
    }

    func_01ff8d88(gMapStateManager->unk_08, unit, -1, 6, 1, 1);
    func_ov000_021a3ee4(unit, 1);

    unit->state2 |= 0x20000;

    func_ov000_021a354c(unit, -1, -1);
    func_ov000_021a7214(gMapStateManager->unk_04, unit, 0);

    gMapStateManager->unk_04->unk_08 = 1;
    data_021974f0 = (u32)unit;

    pMsm08 = gMapStateManager->unk_08;

    pMsm08->unk_0044 = unit->xPos;
    pMsm08->unk_0042 = pMsm08->unk_0044;
    pMsm08->unk_0040 = pMsm08->unk_0044;
    pMsm08->unk_0045 = unit->yPos;
    pMsm08->unk_0043 = pMsm08->unk_0045;
    pMsm08->unk_0041 = pMsm08->unk_0045;
    pMsm08->unk_0046 = 0;
    pMsm08->unk_0047 = 0;
    pMsm08->unk_0000 = 0x80;

    func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 0, 0, 0);

    gMapStateManager->unk_14->unk_04->SetUnk14Unk16(1, 0);
    gMapStateManager->unk_14->unk_04->unk_15 = 1;

    func_ov000_021d3fa8();

    data_ov000_021e3340->unk_06 = 0;
    Proc_Goto(data_ov000_021e333c, 5, 0);

    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    gMapStateManager->inputHandler->SetButtonVisibility(0x8f);

    gSoundManager->unk_b0->vfunc_28(0x10016, 0, 0);

    func_ov000_021d6e30(2);

    return;
}

EC void func_ov000_021d3fac(void);

EC void func_ov000_021a9f98(void)
{
    struct Unit * psVar2;

    struct Unit * iVar3 = gMapStateManager->unk_04->unk_00;

    if (func_ov000_021a478c() && (gActionSt->func_ov000_021b0f1c(iVar3) == 0))
    {
        gActionSt->actionId = ACTION_NONE;
        psVar2 = GetUnit(gActionSt->unitId);
        gActionSt->func_ov000_021b0eb4(psVar2);
        func_02012b64(gActionSt, 0x38);
    }

    func_ov000_021a7284();
    gMapStateManager->unk_04->unk_08 = 0;
    iVar3->state2 &= 0xfffdffff;

    func_ov000_021a3498(iVar3, 0, -1, -1);

    func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);
    gMapStateManager->unk_14->unk_04->unk_15 = 0;

    func_ov000_021d3fac();

    gMapStateManager->cursor->SetPosAnimated(iVar3->xPos, iVar3->yPos, 0, 0);
    gMapStateManager->cursor->changed = FALSE;

    Proc_Goto(data_ov000_021e333c, 4, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    func_ov000_021d6e30(0);

    gMapStateManager->inputHandler->SetButtonVisibility(0xf);

    func_0204e1a4(iVar3, 0, 1);
    func_0204eab8(iVar3->xPos, iVar3->yPos, 0);

    gSoundManager->unk_b0->vfunc_28(0x10017, 0, 0);

    return;
}

EC void func_ov000_021aa164(MotionDispDelay * param_1)
{
    if (param_1->unk_3c <= 0)
    {
        Proc_End(param_1);
    }

    param_1->unk_3c--;

    return;
}

extern struct ProcCmd data_ov000_021dbbe4[]; // ProcScr_MotionDispDelay

EC void func_ov000_021aa18c(Unit * param_1)
{
    new (Proc_Start(data_ov000_021dbbe4, data_ov000_021e333c)) MotionDispDelay(param_1, 4);
    return;
}

EC void func_ov000_021aa1d0(void)
{
    Unit * unit;

    Proc_EndEach(data_ov000_021dbbe4);

    unit = gMapStateManager->unk_04->unk_00;
    if (unit != NULL)
    {
        func_ov000_021a7284();
        unit->state2 &= 0xfffdffff;
    }

    return;
}

EC map::ProcPL * GetPlayerPhaseProc(void);
EC BOOL func_ov000_021ac0c0(void);
EC void func_ov000_021aa278(s32);

EC void func_ov000_021aa210(void)
{
    gMapStateManager->cursor->isVisible = TRUE;

    Proc_Goto(data_ov000_021e333c, 4, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    func_ov000_021d6e30(0);
    gMapStateManager->inputHandler->SetButtonVisibility(0xf);

    return;
}

EC BOOL func_ov000_021a475c(void);
EC BOOL func_ov000_021a47ac(void);
EC void func_ov000_021aa18c(Unit *);
EC void PlayerPhase_GotoLabel(s32 label, s32 arg_1, s32 arg_2);
EC void StartChoice_EndPreparations(ProcPtr);
EC BOOL func_ov000_021aaad8(s32, s32, s32);
EC BOOL func_ov000_021aad64(s32, s32, s32);
EC BOOL func_ov000_021ab180(s32, s32, s32);
EC s32 func_02012410(void);
EC BOOL func_020146c4(s32);
EC BOOL func_ov000_021ab4f0(s32, s32, s32, s32);

EC void func_ov000_021aa278(s32 param)
{
    s32 x;
    s32 y;
    s32 unitId;
    Unit * pUnit;

    u32 flag = 0;

    gMapStateManager->inputHandler->_021a5d5c(0);

    x = gMapStateManager->cursor->xTile;
    y = gMapStateManager->cursor->yTile;

    if (gMapStateManager->cursor->changed != 0)
    {
        if ((gMapStateManager->unk_14->unk_04->unk_10 != 0) && (gMapStateManager->unk_14->unk_04->unk_13 > 0))
        {
            flag = 2;
        }

        func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);
        func_ov000_021aa1d0();
    }

    if ((gMapStateManager->unk_14->unk_04->unk_10 == 0) && (gMapStateManager->cursor->changed != 0))
    {
        pUnit = GetUnit(gMapStateManager->unk_028[x | y << 5]);

        if (pUnit != NULL)
        {
            if (pUnit->force->id == data_ov000_021e3324->phase)
            {
                if ((pUnit->state2 & 1) == 0)
                {
                    func_01ff8db8(gMapStateManager->unk_08, pUnit, -1, 6, 1, 1);
                    func_ov000_021a3ee4(pUnit, 1);

                    func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 1, flag & 0xff, 0);

                    gMapStateManager->unk_14->unk_04->SetUnk14Unk16(4, 0);

                    func_ov000_021aa18c(pUnit);
                }
            }
            else
            {
                func_01ff8db8(gMapStateManager->unk_08, pUnit, -1, 2, 1, 1);

                if (CheckUnitAttribute(pUnit, 0x8000000) != 0)
                {
                    gMapStateManager->unk_08->unk_0854[pUnit->xPos | pUnit->yPos << 5] = -1;
                }

                func_020a5734(0, gMapStateManager->unk_e30, 0x80);

                func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 1, flag & 0xff, 0);

                gMapStateManager->unk_14->unk_04->SetUnk14Unk16(4, 0);
            }
        }
        else
        {
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);
        }
    }

    if (func_ov000_021a47ac() != 0)
    {
        func_ov000_021aa1d0();

        gMapStateManager->cursor->isVisible = FALSE;

        func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

        gMapStateManager->inputHandler->SetButtonVisibility(0);
        func_ov000_021d6dfc(0);

        Proc_Goto(data_ov000_021e333c, 37, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        return;
    }

    if (func_ov000_021a475c() != 0)
    {
        func_ov000_021aa1d0();

        gMapStateManager->cursor->isVisible = FALSE;

        func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

        gSoundManager->unk_b0->vfunc_28(SE_SYS_CANSEL1, 0, 0);

        PlayerPhase_GotoLabel(L_PLAYERPHASE_END_TURN, 0, 0);

        func_ov000_021d6dfc(0);

        return;
    }

    if (gMapStateManager->inputHandler->unk_21_2 != 0)
    {
        if (func_ov000_021aaad8(x, y, param) != 0)
        {
            return;
        }
    }

    if (gMapStateManager->inputHandler->unk_21_0 != 0)
    {
        if (func_ov000_021aad64(x, y, param) != 0)
        {
            return;
        }
    }

    if (gMapStateManager->inputHandler->unk_21_4 != 0)
    {
        if (func_ov000_021ab180(x, y, param) != 0)
        {
            return;
        }
    }

    if ((gMapStateManager->inputHandler->_021a5650(0) != 0) ||
        ((gMapStateManager->inputHandler->keyPressed & KEY_BUTTON_SELECT) != 0))
    {
        if (func_ov000_021ab4f0(x, y, param, gMapStateManager->inputHandler->IsKeyPressed(KEY_BUTTON_SELECT)))
        {
            return;
        }
    }

    if ((((gMapStateManager->inputHandler->keyPressed & KEY_BUTTON_X) != 0) ||
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

        func_ov000_021a35a0();

        unitId = gMapStateManager->unk_028[x | y << 5];

        if (GetUnit(unitId) != NULL)
        {
            func_01ff8db8(gMapStateManager->unk_08, GetUnit(unitId), -1, 2, 1, 1);
        }
    }

    if (param != 0)
    {
        if ((gMapStateManager->inputHandler->_021a5650(3) != 0) ||
            ((gMapStateManager->inputHandler->keyPressed & KEY_BUTTON_START) != 0))
        {
            gSoundManager->unk_b0->vfunc_28(SE_SYS_WINDOW_OPEN1, 0, 0);

            func_ov000_021d6dfc(0);

            StartChoice_EndPreparations(data_ov000_021e333c);

            return;
        }
    }

    if ((gMapStateManager->inputHandler->keyRepeated & 0x200) == 0)
    {
        return;
    }

    if ((func_ov000_021a478c() != 0) && (func_020146c4(func_02012410()) != 0) &&
        (func_020146c4((func_02012410() + 1) & 1) != 0))
    {
        return;
    }

    pUnit = func_ov000_021a995c(GetUnit(gMapStateManager->unk_028[x | y << 5]), data_ov000_021e3324->phase);

    if (pUnit == NULL)
    {
        return;
    }

    if ((gMapStateManager->unk_14->unk_04->unk_10 != 0) && (gMapStateManager->unk_14->unk_04->unk_13 > 0))
    {
        flag = 2;
    }

    func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);
    func_ov000_021aa1d0();

    gMapStateManager->cursor->SetPosAnimated(pUnit->xPos, pUnit->yPos, 0, 0);

    gSoundManager->unk_b0->vfunc_28(SE_SYS_WINDOW_INFO1, 0, 0);

    if (pUnit->force->id == data_ov000_021e3324->phase)
    {
        func_01ff8db8(gMapStateManager->unk_08, pUnit, -1, 6, 1, 1);
        func_ov000_021a3ee4(pUnit, 1);
        func_ov000_021aa18c(pUnit);
    }
    else
    {
        func_01ff8db8(gMapStateManager->unk_08, pUnit, -1, 2, 1, 1);

        if (CheckUnitAttribute(pUnit, 0x8000000) != 0)
        {
            gMapStateManager->unk_08->unk_0854[pUnit->xPos | pUnit->yPos << 5] = -1;
        }

        func_020a5734(0, gMapStateManager->unk_e30, 0x80);
    }

    func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 1, flag & 0xff, 0);

    gMapStateManager->unk_14->unk_04->SetUnk14Unk16(4, 0);

    func_0204e1a4(pUnit, 2, 1);
    func_0204eab8(pUnit->xPos, pUnit->yPos, 2);

    return;
}

EC void func_ov000_021a9d98(struct Unit *);
extern struct UnkStruct_021e3528 data_ov000_021e3528;

class UnkStruct_02217560
{
public:
    u32 unk_00;
    u32 unk_04;
};

extern UnkStruct_02217560 * data_ov005_02217560;

EC void func_ov000_021a7a90(u32, u32, s32, s32, ProcPtr);

EC BOOL func_ov000_021aaad8(s32 x, s32 y, s32 param_3)
{
    s32 i;
    BOOL found;

    struct Unit * pUnit = GetUnit(gMapStateManager->unk_028[x | y << 5]);

    if (param_3 != 0)
    {
        found = FALSE;

        for (i = 0; i < data_ov000_021e3528.unk_2e; i++)
        {
            if (x == data_ov000_021e3528.unk_00[i * 2 + 0] && y == data_ov000_021e3528.unk_00[i * 2 + 1])
            {
                found = TRUE;
                break;
            }
        }

        if (found)
        {
            if ((x != data_ov005_02217560->unk_00) || (y != data_ov005_02217560->unk_04))
            {
                if (((pUnit == NULL) || ((pUnit->state2 & 0x400) != 0)) &&
                    !(((data_ov005_02217560->unk_00 != -1) ? TRUE : FALSE) & 0xFF))
                {
                    data_ov005_02217560->unk_00 = x;
                    data_ov005_02217560->unk_04 = y;

                    gSoundManager->unk_b0->vfunc_28(SE_SYS_SELECT1, 0, 0);

                    gMapStateManager->inputHandler->SetButtonVisibility(0x8f);
                }
                else
                {
                    func_ov000_021aa1d0();
                    func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

                    func_ov000_021a7a90(
                        data_ov005_02217560->unk_00, data_ov005_02217560->unk_04, x, y, data_ov000_021e333c);

                    data_ov005_02217560->unk_00 = -1;
                    data_ov005_02217560->unk_04 = -1;

                    gMapStateManager->inputHandler->SetButtonVisibility(0xf);
                }
            }

            gMapStateManager->inputHandler->SetValues(0, 0, 0);

            return TRUE;
        }
        else
        {
            gSoundManager->unk_b0->vfunc_28(SE_SYS_MISS1, 0, 0);
        }
    }

    if (pUnit == NULL)
    {
        return FALSE;
    }

    if ((pUnit->force->id == data_ov000_021e3324->phase) && (param_3 == 0))
    {
        if ((pUnit->state2 & 1) == 0)
        {
            func_ov000_021aa1d0();
            func_ov000_021a9d98(pUnit);

            gMapStateManager->inputHandler->SetValues(0, 0, 0);
            return TRUE;
        }
    }

    return FALSE;
}

EC void func_ov000_021a36f8(struct Unit *, BOOL, BOOL);

EC BOOL func_ov000_021aad64(s32 x, s32 y, s32 param)
{
    struct Unit * pUnit;
    s32 i;
    BOOL found;

    pUnit = GetUnit(gMapStateManager->unk_028[x | y << 5]);

    if ((param != 0) && (gMapStateManager->inputHandler->unk_1e == 0))
    {
        found = FALSE;

        for (i = 0; i < data_ov000_021e3528.unk_2e; i++)
        {
            if (x == data_ov000_021e3528.unk_00[i * 2 + 0] && y == data_ov000_021e3528.unk_00[i * 2 + 1])
            {
                found = TRUE;
                break;
            }
        }

        if (found)
        {
            if ((((x == data_ov005_02217560->unk_00) && (y == data_ov005_02217560->unk_04))) ||
                ((pUnit != NULL) && ((pUnit->state2 & 0x400) != 0)))
            {
                if ((data_ov005_02217560->unk_00 != -1 ? TRUE : FALSE) & 0xff)
                {
                    data_ov005_02217560->unk_00 = x;
                    data_ov005_02217560->unk_04 = y;

                    gSoundManager->unk_b0->vfunc_28(SE_SYS_SELECT1, 0, 0);

                    gMapStateManager->inputHandler->SetButtonVisibility(0x8f);
                }
                else
                {
                    func_ov000_021aa1d0();
                    func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

                    func_ov000_021a7a90(
                        data_ov005_02217560->unk_00, data_ov005_02217560->unk_04, x, y, data_ov000_021e333c);

                    data_ov005_02217560->unk_00 = -1;
                    data_ov005_02217560->unk_04 = -1;

                    gMapStateManager->inputHandler->SetButtonVisibility(0xf);
                }

                return TRUE;
            }
        }
    }

    if (pUnit == NULL)
    {
        if (param == 0)
        {
            func_ov000_021aa1d0();
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            gMapStateManager->cursor->isVisible = FALSE;

            Proc_Goto(data_ov000_021e333c, 10, 0);
            data_ov000_021e3340->unk_02 = 0;
            data_ov000_021e3340->unk_03 = 0;

            return TRUE;
        }

        return FALSE;
    }

    if (pUnit->force->id == data_ov000_021e3324->phase)
    {
        if ((pUnit->state2 & 1) == 0)
        {
            return FALSE;
        }

        if (gMapStateManager->inputHandler->unk_1e != 0)
        {
            return FALSE;
        }

        if (param != 0)
        {
            gMapStateManager->inputHandler->_021a5840(0);
            gMapStateManager->inputHandler->_021a5840(1);
            gMapStateManager->inputHandler->_021a5840(3);

            Proc_Goto(data_ov000_021e333c, 2, 0);
        }
        else
        {
            func_ov000_021aa1d0();
            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            gMapStateManager->cursor->isVisible = FALSE;

            Proc_Goto(data_ov000_021e333c, 10, 0);
        }

        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        return TRUE;
    }

    if (!((data_ov000_021e3324->phase == pUnit->force->id ? TRUE : FALSE) & 0xff))
    {
        if ((pUnit->state2 & 0x2000) == 0)
        {
            pUnit->state2 |= 0x2000;

            gSoundManager->unk_b0->vfunc_28(SE_SYS_ENEMY_ON1, 0, 0);

            if (data_ov000_021e3324->unk_03 == 0)
            {
                func_ov000_021a36f8(pUnit, 0, 1);
            }
        }
        else
        {
            pUnit->state2 &= ~0x2000;

            gSoundManager->unk_b0->vfunc_28(SE_SYS_ENEMY_OFF1, 0, 0);

            if (data_ov000_021e3324->unk_03 == 0)
            {
                func_ov000_021a35a0();
                func_01ff8db8(gMapStateManager->unk_08, pUnit, -1, 2, 1, 1);
            }
        }
    }

    return FALSE;
}

EC BOOL func_ov000_021ab180(s32 x, s32 y, s32 param_3)
{
    Unit * pUnit = GetUnit(gMapStateManager->unk_028[x | y << 5]);

    if (pUnit == NULL)
    {
        if (param_3 != 0)
        {
            if ((data_ov005_02217560->unk_00 != -1 ? TRUE : FALSE) & 0xff)
            {
                data_ov005_02217560->unk_00 = -1;
                data_ov005_02217560->unk_04 = -1;

                gSoundManager->unk_b0->vfunc_28(SE_SYS_CANSEL1, 0, 0);

                gMapStateManager->inputHandler->SetButtonVisibility(0xf);
            }
            else
            {
                gMapStateManager->cursor->isVisible = FALSE;

                Proc_Goto(data_ov000_021e333c, 2, 0);
            }

            data_ov000_021e3340->unk_02 = 0;
            data_ov000_021e3340->unk_03 = 0;

            return TRUE;
        }
    }
    else if ((data_ov000_021e3324->phase == pUnit->force->id ? TRUE : FALSE) & 0xff)
    {
        if (param_3 != 0)
        {
            if ((data_ov005_02217560->unk_00 != -1 ? TRUE : FALSE) & 0xff)
            {
                data_ov005_02217560->unk_00 = -1;
                data_ov005_02217560->unk_04 = -1;

                gSoundManager->unk_b0->vfunc_28(SE_SYS_CANSEL1, 0, 0);

                gMapStateManager->inputHandler->SetButtonVisibility(0xf);
            }
            else
            {
                gMapStateManager->cursor->isVisible = FALSE;

                Proc_Goto(data_ov000_021e333c, 2, 0);
            }

            data_ov000_021e3340->unk_02 = 0;
            data_ov000_021e3340->unk_03 = 0;

            return TRUE;
        }
    }
    else if ((pUnit->state2 & 0x2000) != 0)
    {
        pUnit->state2 &= ~0x2000;

        gSoundManager->unk_b0->vfunc_28(SE_SYS_ENEMY_OFF1, 0, 0);

        if (data_ov000_021e3324->unk_03 == 0)
        {
            func_ov000_021a35a0();
            func_01ff8db8(gMapStateManager->unk_08, pUnit, -1, 2, 1, 1);
        }
    }
    else
    {
        BOOL changed;
        s32 forceId;
        struct Unit * it;

        changed = FALSE;

        for (forceId = 0; forceId < 2; forceId++)
        {
            if (((data_ov000_021e3324->phase == forceId) ? TRUE : FALSE) & 0xff)
            {
                continue;
            }

            for (it = Force::Get(forceId)->head; it != NULL; it = it->unk_3c)
            {
                if ((it->state2 & 0x2000) != 0)
                {
                    it->state2 &= ~0x2000;
                    changed = TRUE;
                }
            }
        }

        if (changed)
        {
            gSoundManager->unk_b0->vfunc_28(SE_SYS_ENEMY_OFF1, 0, 0);
        }

        if (data_ov000_021e3324->unk_03 == 0)
        {
            func_ov000_021a35a0();
            func_01ff8db8(gMapStateManager->unk_08, pUnit, -1, 2, 1, 1);
        }
    }

    return FALSE;
}

EC BOOL func_ov000_021ab4f0(s32 x, s32 y, s32 arg2, s32 arg3)
{
    struct Unit * pUnit;

    if (arg3 != 0)
    {
        pUnit = GetUnit(gMapStateManager->unk_028[(x | y << 5)]);

        if (pUnit != NULL)
        {
            if ((pUnit->items[0].id != 0 ? TRUE : FALSE) & 0xff)
            {
                func_ov000_021aa1d0();

                gMapStateManager->unk_04->unk_00 = pUnit;

                PlayerPhase_GotoLabel(L_PLAYERPHASE_ACT, 6, 0);

                func_ov000_021d6dfc(0);

                gMapStateManager->inputHandler->SetButtonVisibility(0x83);

                gSoundManager->unk_b0->vfunc_28(SE_SYS_WINDOW_OPEN1, 0, 0);
            }
            else
            {
                gSoundManager->unk_b0->vfunc_28(SE_SYS_MISS1, 0, 0);
            }

            return TRUE;
        }
    }

    if (arg2 != 0)
    {
        if (arg3 == 0)
        {
            if (!((data_ov005_02217560->unk_00 != -1 ? TRUE : FALSE) & 0xFF))
            {
                gMapStateManager->inputHandler->_021a5840(0);
                gMapStateManager->inputHandler->_021a5840(1);
                gMapStateManager->inputHandler->_021a5840(3);

                Proc_Goto(data_ov000_021e333c, 2, 0);
                data_ov000_021e3340->unk_02 = 0;
                data_ov000_021e3340->unk_03 = 0;

                return TRUE;
            }

            data_ov005_02217560->unk_00 = -1;
            data_ov005_02217560->unk_04 = -1;

            gMapStateManager->inputHandler->SetButtonVisibility(0xf);

            gSoundManager->unk_b0->vfunc_28(SE_SYS_CANSEL1, 0, 0);

            return TRUE;
        }
    }
    else if (arg3 == 0)
    {
        func_ov000_021aa1d0();
        func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

        gMapStateManager->cursor->isVisible = FALSE;

        Proc_Goto(data_ov000_021e333c, 10, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        return TRUE;
    }

    return FALSE;
}

EC void func_ov000_021a72a8(void *);
EC BOOL func_02002038(void *, void *);
EC BOOL func_020015f8(struct MapStateManager_08 *, s32, s32);
EC BOOL func_020015b4(struct MapStateManager_08 *, s32, s32, s32);
EC void func_ov000_021a9f98(void);

EC void func_ov000_021ab768(void)
{
    struct Unit * pUnit;
    u8 x;
    u8 y;

    gMapStateManager->inputHandler->_021a5d5c(1);

    func_020015f8(gMapStateManager->unk_08, gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile);

    if (func_ov000_021a471c() != 0)
    {
        func_ov000_021a9f98();
        return;
    }

    if ((((gMapStateManager->inputHandler->keyPressed & KEY_BUTTON_X) != 0) ||
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

        func_ov000_021a3498(gMapStateManager->unk_04->unk_00, 1, -1, -1);
        func_ov000_021a35a0();

        func_ov000_021a354c(gMapStateManager->unk_04->unk_00, -1, -1);

        func_01ff8d88(gMapStateManager->unk_08, gMapStateManager->unk_04->unk_00, -1, 2, 1, 1);
    }

    if (gMapStateManager->inputHandler->unk_21_0 != 0)
    {
        x = gMapStateManager->cursor->xTile;
        y = gMapStateManager->cursor->yTile;

        pUnit = GetUnit(gMapStateManager->unk_028[x | y << 5]);

        if (pUnit == NULL && gMapStateManager->unk_08->unk_0854[x | y << 5] >= 0)
        {
            gMapStateManager->cursor->isVisible = FALSE;

            func_ov000_021bc9e4(gMapStateManager->unk_14->unk_04);

            gMapStateManager->unk_14->unk_04->unk_15 = 0;

            if (func_02002038(gMapStateManager->unk_08, gMapStateManager->unk_04->unk_00) != 0)
            {
                func_ov000_021b0de8(gMapStateManager->unk_08->unk_0042, gMapStateManager->unk_08->unk_0043, 0x17, 0);

                Proc_Goto(data_ov000_021e333c, L_PLAYERPHASE_40, 0);
            }
            else
            {
                Proc_Goto(data_ov000_021e333c, 8, 0);
            }

            data_ov000_021e3340->unk_02 = 0;
            data_ov000_021e3340->unk_03 = 0;

            if ((x != gMapStateManager->unk_04->unk_00->xPos) || (y != gMapStateManager->unk_04->unk_00->yPos))
            {
                gMapStateManager->inputHandler->SetButtonVisibility(0);
            }

            func_ov000_021a72a8(gMapStateManager->unk_04);
            func_ov000_021d3fac();

            gSoundManager->unk_b0->vfunc_28(SE_SYS_SELECT1, 0, 0);

            return;
        }

        if ((func_020015b4(gMapStateManager->unk_08, x, y, 2) != 0) ||
            (func_020015b4(gMapStateManager->unk_08, x, y, 0) != 0) ||
            (func_020015b4(gMapStateManager->unk_08, x, y, 1) != 0))
        {
            Proc_Goto(data_ov000_021e333c, L_PLAYERPHASE_TALK, 0);

            data_ov000_021e3340->unk_02 = 2;
            data_ov000_021e3340->unk_03 = gMapStateManager->unk_08->unk_0048;
            data_ov000_021e3340->unk_04 = x;
            data_ov000_021e3340->unk_05 = y;

            func_ov000_021d3fac();

            gMapStateManager->inputHandler->SetButtonVisibility(0x8b);

            gSoundManager->unk_b0->vfunc_28(SE_SYS_SELECT1, 0, 0);

            return;
        }

        gSoundManager->unk_b0->vfunc_28(SE_SYS_MISS1, 0, 0);

        return;
    }

    if ((gMapStateManager->inputHandler->unk_21_4 != 0) || (gMapStateManager->inputHandler->_021a5650(0) != 0))
    {
        func_ov000_021a9f98();
    }

    return;
}

EC void func_ov000_021abbc8(void)
{
    struct Unit * pUnitA;
    s16 ix;
    s16 iy;

    pUnitA = GetUnit(gActionSt->unk_34);

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

            pUnitB = GetUnit(gMapStateManager->unk_028[(ix | iy << 5)]);

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

    if ((((gMapStateManager->inputHandler->keyPressed & KEY_BUTTON_X) != 0) ||
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

        Proc_Goto(data_ov000_021e333c, 40, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        return TRUE;
    }

    gSoundManager->unk_b0->vfunc_28(SE_SYS_MISS1, 0, 0);

    return FALSE;
}

EC BOOL func_ov000_021ac0c0(void)
{
    Proc_Goto(data_ov000_021e333c, 18, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    gSoundManager->unk_b0->vfunc_28(SE_SYS_CANSEL1, 0, 0);

    if (data_ov000_021e3340->unk_07 == 1)
    {
        struct Unit * r5;
        struct ItemData * r4;
        struct ItemData * r6_;
        int r6;
        int r7;
        int r8;
        struct MapStateManager_08 * r9;
        int sp_00;
        u32 uVar7;

        r5 = gMapStateManager->unk_04->unk_00;
        r4 = gMapStateManager->unk_04->unk_00->items[gActionSt->unk_37].GetData();
        r6_ = gMapStateManager->unk_04->unk_00->items[gActionSt->unk_37].GetData();
        r6 = r6_->minRange;
        r7 = gActionSt->yDecision;
        r8 = gActionSt->xDecision;
        r9 = gMapStateManager->unk_08;
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

        func_ov000_021bc994(gMapStateManager->unk_14->unk_04, 0, uVar7 & 0xff, 2);
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

    gMapStateManager->unk_04->unk_08 = 0;

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

            func_ov000_021a3c84(
                gMapStateManager->unk_db0, data_ov000_021e3324->phase, fp, sp_10, sp_00, sp_04, sp_08, (u8 *)sp_0c);
            func_ov000_021a3c84(
                gMapStateManager->unk_d30, data_ov000_021e3324->unk_01, fp, sp_10, sp_00, sp_04, sp_08, (u8 *)sp_0c);
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
        Proc_Goto(data_ov000_021e333c, 24, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        func_ov000_021a969c(9);

        return;
    }

    if (data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        pUnit->state2 &= ~1;

        Proc_Goto(data_ov000_021e333c, 24, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        func_ov000_021a969c(8);

        return;
    }

    func_ov000_021a378c();
    gMapStateManager->camera->Scroll(x, y, 0, 0x20, 0);
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

    Proc_Goto(data_ov000_021e333c, 9, 0);
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

    data_ov000_021e3324->unk_10 = gElapsedFrames;

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
        if (gMapStateManager->camera->IsMoving())
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
        Proc_Goto(data_ov000_021e333c, 1, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
    }
    else
    {
        Proc_Goto(data_ov000_021e333c, 4, 0);
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

    Proc_Goto(data_ov000_021e333c, L_PLAYERPHASE_END, 0);
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

    Proc_Goto(data_ov000_021e333c, 24, 0);
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
    TryShowTutCardForMenu(proc, 0);
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
    Proc_Goto(data_ov000_021e333c, 11, 1);
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

    StartTargetSelect(3, -1, -1);

    return;
}

EC void func_ov000_021acd8c(void)
{
    struct MapStateManager_14_04 * ptr;
    struct Unit * pUnit = gMapStateManager->unk_04->unk_00;

    EndTargetSelect();

    gMapStateManager->cursor->SetPosImmediate(pUnit->xPos, pUnit->yPos);
    gMapStateManager->camera->Scroll(pUnit->xPos, pUnit->yPos, 0, 0x20, 0);

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

    Proc_Goto(data_ov000_021e333c, 6, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021acef4(ProcPtr proc)
{
    func_ov000_021c266c(proc, (s8)data_ov000_021e3340->unk_02, GetUnit(data_ov000_021e3340->unk_03));

    Proc_Goto(data_ov000_021e333c, 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void PlayerPhase_StartTrade(ProcPtr proc)
{
    StartTradeMenu(proc, GetUnit(data_ov000_021e3340->unk_02));

    Proc_Goto(data_ov000_021e333c, 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void PlayerPhase_StartSavePointMenu(ProcPtr proc)
{
    StartMapSave_PointSaveMenu(proc);

    Proc_Goto(data_ov000_021e333c, 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ad00c(void)
{
    func_ov000_021c63f8();

    Proc_Goto(data_ov000_021e333c, 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ad048(void)
{
    StartTargetSelect(data_ov000_021e3340->unk_02, data_ov000_021e3340->unk_03, -1);

    Proc_Goto(data_ov000_021e333c, 39, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021ad098(void)
{
    StartTargetSelect(data_ov000_021e3340->unk_07, gActionSt->unk_37, gActionSt->unk_34);

    Proc_Goto(data_ov000_021e333c, 39, 0);
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

    psVar7 = GetUnit(data_ov000_021e3340->unk_02);
    psVar1 = GetUnit(data_ov000_021e3340->unk_02);

    uVar10 = func_0203c378(psVar1)->pPersonData->pid;
    iVar3 = func_0203c378(gMapStateManager->unk_04->unk_00)->pPersonData->pid;

    EventCaller::TryStartTalkEvent(param_1, (u32)iVar3, (u32)uVar10, (u32)psVar7);

    data_ov000_021e3340->unk_06 |= 2;

    return;
}

EC void func_ov000_021ad388(void)
{
    Proc_Goto(data_ov000_021e333c, 11, 0);
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

        Proc_Goto(data_ov000_021e333c, 40, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        return;
    }

    func_ov000_021bc5a8(gMapStateManager->unk_04->unk_04);

    Proc_Goto(data_ov000_021e333c, 11, 0);
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
        Proc_Goto(data_ov000_021e333c, 40, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
    }
    else
    {
        func_ov000_021bc5a8(gMapStateManager->unk_04->unk_04);
        Proc_Goto(data_ov000_021e333c, 11, 0);

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
    if (gMapStateManager->camera->IsMoving())
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
        Proc_Goto(data_ov000_021e333c, 24, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        func_ov000_021a969c(9);
        return;
    }

    if (data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        func_ov000_021a46b8();
        Proc_Goto(data_ov000_021e333c, 24, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        func_ov000_021a969c(8);
        return;
    }

    if (gActionSt->actionId == ACTION_10)
    {
        func_ov000_021a43e8();
        Proc_Goto(data_ov000_021e333c, 28, 1);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        return;
    }

    func_ov000_021a46b8();
    Proc_Goto(data_ov000_021e333c, 35, 1);
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
        Proc_Goto(data_ov000_021e333c, 36, 0);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
        return;
    }

    Proc_Goto(data_ov000_021e333c, 26, 0);
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
    Proc_Goto(data_ov000_021e333c, 24, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    func_ov000_021a969c(10);

    return;
}

EC void func_ov000_021ad9d4(ProcPtr proc)
{
    gMapStateManager->inputHandler->SetButtonVisibility(0);
    StartMapSave(0x1b, proc);
    Proc_Goto(data_ov000_021e333c, 26, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void func_ov000_021ada34(ProcPtr proc)
{
    StartMapSave(0x1c, proc);
    Proc_Goto(data_ov000_021e333c, 35, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void func_ov000_021ada78(ProcPtr proc)
{
    StartMapSave(0x1d, proc);
    Proc_Goto(data_ov000_021e333c, 36, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC BOOL func_ov000_021adabc(struct Unit * arg_0, s32 arg_1)
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
        Proc_Goto(data_ov000_021e333c, 4, 1);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;

        gMapStateManager->inputHandler->SetButtonVisibility(0xf);
        func_ov000_021d6e30(0);

        return;
    }

    Proc_Goto(data_ov000_021e333c, 23, 1);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;

    return;
}

EC void func_ov000_021adbf0(void)
{
    gMapStateManager->cursor->isVisible = TRUE;

    if (data_02196f0c->state & 0x40)
    {
        Proc_Goto(data_ov000_021e333c, 1, 1);
        data_ov000_021e3340->unk_02 = 0;
        data_ov000_021e3340->unk_03 = 0;
    }
    else
    {
        Proc_Goto(data_ov000_021e333c, 4, 1);
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
    Unit * pUnit =
        GetUnit(gMapStateManager->unk_028[gMapStateManager->cursor->xTile | gMapStateManager->cursor->yTile << 5]);

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
    Proc_Goto(data_ov000_021e333c, 36, 0);
    data_ov000_021e3340->unk_02 = 0;
    data_ov000_021e3340->unk_03 = 0;
    return;
}

EC void PlayerPhase_StartGuide(ProcPtr proc)
{
    StartGuideMenu(proc);
    Proc_Goto(data_ov000_021e333c, 10, 0);
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
    Proc_Goto(data_ov000_021e333c, 36, 0);
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
    Proc_Goto(data_ov000_021e333c, 11, 0);
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

    Proc_Goto(data_ov000_021e333c, 24, 1);

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

    Proc_Goto(data_ov000_021e333c, 24, 0);

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

PROC_LABEL(L_PLAYERPHASE_WARP),
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

PROC_LABEL(L_PLAYERPHASE_TRADE),
    PROC_CALL(PlayerPhase_StartTrade),

PROC_LABEL(L_PLAYERPHASE_SAVE_POINT),
    PROC_CALL(PlayerPhase_StartSavePointMenu),

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
extern struct ProcCmd data_ov000_021dbc04[];
extern struct ProcCmd data_ov000_021dbbcc[];

EC ProcPtr func_ov000_021ae2c4(ProcPtr parent)
{
    return func_01ffc030(data_ov000_021dbc24, parent);
}

EC ProcPtr func_ov000_021ae2dc(ProcPtr parent)
{
    return func_01ffc030(data_ov000_021dbc4c, parent);
}

EC ProcPtr func_ov000_021ae2f4(ProcPtr param_1)
{
    return func_01ffc030(data_ov000_021dbc04, param_1);
}

EC ProcPtr func_ov000_021ae30c(ProcPtr param_1)
{
    return func_01ffc030(data_ov000_021dbbcc, param_1);
}

EC void func_ov000_021ae324(Unit * param_1)
{
    param_1->state2 |= 0x20000;
    func_ov000_021a354c(param_1, -1, -1);
    func_ov000_021a7214(gMapStateManager->unk_04, param_1, 0);
    return;
}

EC void func_ov002_021f2244(void);

namespace map
{

class ProcCP : public ProcEx
{
public:
    ProcCP()
    {
        data_ov000_021e3338 = this;
        func_ov002_021f2244();

        data_ov000_021e3334->Init();
    }

    // func_ov000_021b07bc
    // func_ov000_021b0760
    virtual ~ProcCP()
    {
        data_ov000_021e3334->Init();
        data_ov000_021e3338 = NULL;
    }
};

} // namespace map

EC void func_ov000_021ae364(void)
{
    struct Unit * unit = gMapStateManager->unk_04->unk_00;

    func_ov000_021a7284();

    unit->state2 &= ~0x20000;

    if ((unit->state2 & 0x48) == 0)
    {
        if (unit->force->id == data_ov000_021e3324->phase)
        {
            unit->state2 |= 1;
        }

        if ((data_ov000_021e3324->unk_02 != 0) && (func_ov000_021a3da0(unit) == 0))
        {
            if (TEMP(unit) != 0)
            {
                unit->state2 |= 0x4000;
            }
        }
    }
    else
    {
        unit->state2 |= 0x1000;
    }

    if (data_ov000_021e3324->unk_02 != 0)
    {
        if (data_ov000_021e3324->phase == unit->force->id)
        {
            void * sp_0c;
            s32 sp_08;
            int fp;
            s8 sp_00;
            int sp_04;
            int sp_10;

            sp_0c = gMapStateManager->unk_08;
            sp_08 = func_ov000_021a4854(unit);

            fp = unit->force->id;
            sp_10 = gActionSt->unk_2c;
            sp_04 = gActionSt->unk_2e;
            sp_00 = gActionSt->unk_2d;

            func_ov000_021a3c84(
                gMapStateManager->unk_db0, data_ov000_021e3324->phase, fp, sp_10, sp_00, sp_04, sp_08, (u8 *)sp_0c);
            func_ov000_021a3c84(
                gMapStateManager->unk_d30, data_ov000_021e3324->unk_01, fp, sp_10, sp_00, sp_04, sp_08, (u8 *)sp_0c);
        }
        else
        {
            func_ov000_021a3c20(gMapStateManager->unk_db0, data_ov000_021e3324->phase, unit);
            func_ov000_021a3c20(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01, unit);
        }

        if (func_ov000_021a3da0(unit) == 0)
        {
            func_ov000_021a38b4();
        }

        func_ov000_021a340c();
    }
    else
    {
        if ((unit->state2 & 0x48) == 0)
        {
            func_ov000_021a3498(unit, 0, -1, -1);
        }
    }

    if ((unit->state2 & 8) != 0)
    {
        if (unit->force->id == 0)
        {
            func_0203bd34(unit, 3, 1);
        }
        else
        {
            func_0203bd34(unit, 4, 1);
        }
    }
    else
    {
        if ((unit->state2 & 0x40) != 0 && unit->force->id != 0)
        {
            func_0203bd34(unit, 4, 1);
        }
    }

    func_ov000_021a9a48();

    if (data_02196f0c->flagMgr->GetByName("gf_gameover"))
    {
        Proc_Goto(data_ov000_021e3338, 5, 0);
        func_ov000_021a969c(9);
        return;
    }

    if (data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        Proc_Goto(data_ov000_021e3338, 5, 0);
        func_ov000_021a969c(8);
        return;
    }

    if (!data_ov000_021e3334->IsSkipState4())
    {
        func_ov000_021a378c();
    }

    func_0204bbb4(0);

    Proc_Goto(data_ov000_021e3338, 3, 0);

    return;
}

EC void func_ov000_021ae6c0(ProcPtr param_1)
{
    data_ov000_021e3334->func_02049024(param_1);
    return;
}

EC void func_ov000_021f225c(void);

EC void func_ov000_021ae6dc(void)
{
    if ((data_ov000_021e3334->Check06(4)) && (data_02196f24->unk_05 == 2 && data_ov000_021e3334->Check06(0) == '\0'))
    {
        data_ov000_021e3334->unk_06 = 2;
    }

    func_ov000_021f225c();

    return;
}

EC BOOL func_ov002_021f22b4(void);

EC void func_ov000_021ae72c(void)
{
    if (func_ov002_021f22b4())
    {
        return;
    }

    if (gActionSt->actionId == 0x16)
    {
        Proc_Goto(data_ov000_021e3338, 5, 0);

        if (func_ov000_021a478c())
        {
            func_ov000_021b0de8(0, 0, 0x16, 0);
            func_02012b64(gActionSt, 0x38);
        }

        return;
    }

    Proc_Goto(data_ov000_021e3338, 1, 0);

    return;
}

EC void func_ov000_021a734c(void *);
EC void func_ov000_021a72cc(void *);

EC void func_ov000_021ae7b4(ProcPtr param_1)
{
    Unit * psVar2;

    if (gMapStateManager->camera->IsMoving())
    {
        return;
    }

    psVar2 = GetUnit(gActionSt->unitId);

    func_ov000_021ae324(psVar2);
    data_021974f0 = (u32)psVar2;

    if (func_02002038(gMapStateManager->unk_08, gMapStateManager->unk_04->unk_00))
    {
        func_ov000_021b0de8(gMapStateManager->unk_08->unk_0042, gMapStateManager->unk_08->unk_0043, 0x17, 0);
    }

    if (data_ov000_021e3334->Check06(4) || (data_02196f24->unk_05 == 1))
    {
        func_ov000_021a734c(gMapStateManager->unk_04);
    }
    else
    {
        func_ov000_021a72cc(gMapStateManager->unk_04);
    }

    StartProcMind(param_1);

    return;
}

EC void func_ov000_021ae8d8(ProcPtr param_1)
{
    if (!func_ov000_021a37b4())
    {
        Proc_Break(param_1, 1);
    }

    return;
}

EC void func_ov000_021ae8fc(ProcPtr param_1)
{
    BOOL bVar2;

    bVar2 = 0;

    if (func_ov000_021a98ec(gActionSt->xDecision, gActionSt->yDecision) == 0)
    {
        bVar2 = 1;
    }

    if (bVar2)
    {
        func_ov000_021a98a4(param_1, gActionSt->xDecision, gActionSt->yDecision, bVar2);
    }

    Proc_Break(param_1, bVar2);

    return;
}

EC void func_ov000_021ae958(ProcPtr param_1)
{
    if (data_02196f0c->flagMgr->GetByName("gf_gameover"))
    {
        Proc_Goto(data_ov000_021e3338, 5, 0);
        func_ov000_021a969c(9);
        return;
    }

    if (data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        Proc_Goto(data_ov000_021e3338, 5, 0);
        func_ov000_021a969c(8);
        return;
    }

    Proc_Goto(data_ov000_021e3338, 0, 1);

    return;
}

EC void func_ov000_021ae9fc(map::ProcCP * proc)
{
    if (data_ov000_021e3334->unk_06 == 4)
    {
        func_ov000_021a35a0();
        func_ov000_021a8a00(0, 1);

        data_ov000_021e3334->SkipTransitionFrom2To0Or4To5();
    }
    else
    {
        Proc_End(proc);
    }

    return;
}

extern struct ProcCmd data_ov000_021dbed0[];

/*
struct ProcCmd data_ov000_021dbed0[] = {
    PROC_NAME,
    PROC_NAME,
    PROC_SLEEP(0),
    PROC_06(0, func_ov000_021ae6c0),
PROC_LABEL(0),
    PROC_CALL(func_ov000_021ae6dc),
    PROC_REPEAT(func_ov000_021ae72c),
PROC_LABEL(1),
    PROC_CALL(func_ov000_021ae7b4),
    PROC_CALL(func_ov000_021ae364),
PROC_LABEL(3),
    PROC_REPEAT(func_ov000_021ae8d8),
    PROC_REPEAT(func_ov000_021ae8fc),
    PROC_CALL(func_ov000_021a46b8),
    PROC_CALL(func_ov000_021ae958),
PROC_LABEL(5),
    PROC_CALL(func_ov000_021ae9fc),
    PROC_SLEEP(0),
    PROC_END
};
// End of script at 0x021DBF68
*/

EC void func_ov000_021aea68(ProcPtr param_1)
{
    Unit * pUnit;
    s32 iVar3;

    if (data_ov000_021e3320[data_ov000_021e3324->phase] == 1)
    {
        iVar3 = 0;

        for (pUnit = Force::Get(data_ov000_021e3324->phase)->head; pUnit != NULL; pUnit = pUnit->unk_3c)
        {
            if (pUnit->state2 & 0xe1)
            {
                continue;
            }

            if (pUnit->unk_90 == 0)
            {
                continue;
            }

            iVar3++;
        }

        if (iVar3 == 0)
        {
            if (func_ov000_021a478c())
            {
                func_ov000_021b0de8(0, 0, 0x16, 0);
                func_02012b64(gActionSt, sizeof(ActionState));
                return;
            }

            return;
        }
    }

    new (Proc_StartBlocking(data_ov000_021dbed0, param_1)) map::ProcCP();

    return;
}

EC void func_ov000_021aeb70(Unit * param_1)
{
    param_1->state2 |= 0x20000;
    func_ov000_021a354c(param_1, -1, -1);
    func_ov000_021a7214(gMapStateManager->unk_04, param_1, 0);
    return;
}

namespace map
{
class ProcLink : public ProcEx
{
public:
    u32 unk_38;
    u32 unk_3c;
    u32 unk_40;

    ProcLink()
    {
        data_ov000_021e3330 = this;
        gMapStateManager->unk_14->unk_28 = 1;
        this->unk_3c = 0;
        this->unk_40 = 0;
    }

    virtual ~ProcLink()
    {
        gMapStateManager->inputHandler->_021a5d08();
        gMapStateManager->unk_14->unk_27 = 0;
        gMapStateManager->unk_14->unk_28 = 0;
        data_ov000_021e3330 = NULL;
    }
};
} // namespace map

EC void func_ov000_021af19c(map::ProcLink * param_1)
{
    gMapStateManager->cursor->isVisible = TRUE;
    param_1->unk_3c = 1;
    return;
}

EC void func_ov000_021aefac(void)
{
    s32 x = gMapStateManager->cursor->xTile;
    s32 y = gMapStateManager->cursor->yTile;
    Unit * psVar2 = GetUnit(gMapStateManager->unk_028[x | y << 5]);

    if (psVar2 != NULL)
    {
        data_021974fc->unk_00 = psVar2;
    }

    func_0204b194(x, y);

    if (!func_0204ae9c(1, 1) && (psVar2 != NULL))
    {
        func_0204e1a4(psVar2, 0, 1);
    }

    func_0204eb24();

    return;
}

EC void func_ov000_021af044(map::ProcLink * param_1)
{
    if (param_1->unk_40 != 0)
    {
        func_ov000_021a48d8();
    }

    if (gMapStateManager->unk_14->unk_24)
    {
        return;
    }

    if (!func_02050474() && ((gKeySt->pressed & KEY_BUTTON_R) != 0 || (gMapStateManager->inputHandler->_021a5650(1))))
    {
        if (func_0204b1f8(0))
        {
            func_0204b260(0);
            gSoundManager->unk_b0->vfunc_28(0x10018, 0, 0);
        }
        else
        {
            if (func_0204ad38(0, 0, 0))
            {
                gSoundManager->unk_b0->vfunc_28(0x10018, 0, 0);
            }
        }
    }

    if (param_1->unk_3c == 0)
    {
        return;
    }

    if (gTouchSt->unk_12 != 0)
    {
        data_02196f20->unk_19a = 1;
        return;
    }

    if ((gKeySt->held & ~1) == 0)
    {
        return;
    }

    data_02196f20->unk_19a = 0;

    return;
}

EC BOOL func_02012b8c(s32, void *);
EC void func_0201ffb0(s32);

EC void func_ov000_021af1bc(map::ProcLink * param_1)
{
    if (func_ov000_021a47ac())
    {
        gMapStateManager->cursor->isVisible = 0;
        param_1->unk_3c = 0;
        gMapStateManager->inputHandler->SetButtonVisibility(0);
        Proc_Goto(data_ov000_021e3330, 5, 0);
        return;
    }

    gMapStateManager->inputHandler->_021a5d5c(0);

    if (!func_02012b8c(data_ov000_021e3324->phase, gActionSt))
    {
        return;
    }

    if (gActionSt->actionId == 0x1b)
    {
        gMapStateManager->unk_14->unk_27 = 1;
        param_1->unk_40 = 1;
        data_ov000_021e3324->unk_10 = gElapsedFrames;
        return;
    }
    else if (gActionSt->actionId == 0x16)
    {
        gMapStateManager->cursor->isVisible = 0;
        param_1->unk_3c = 0;
        Proc_Goto(data_ov000_021e3330, 7, 0);
        return;
    }
    else if (gActionSt->actionId == 0x18)
    {
        gMapStateManager->cursor->isVisible = 0;
        param_1->unk_3c = 0;
        Proc_Goto(data_ov000_021e3330, 7, 0);
        data_02196f10->unk_17 = 1;
        data_02196f0c->flagMgr->SetByName("gf_complete");
        func_ov000_021a969c(8);
        return;
    }

    gActionSt->func_ov000_021b0ee8(GetUnit(gActionSt->unitId));

    if (gActionSt->actionId != 0)
    {
        gMapStateManager->cursor->isVisible = 0;
        param_1->unk_3c = 0;
        Proc_Goto(data_ov000_021e3330, 1, 0);
        func_0201ffb0(gActionSt->unk_14);
        func_020a58b8(gActionSt, gMapStateManager->unk_08, 0x14);
        return;
    }

    return;
}

EC void func_ov000_021aeb70(Unit *);
EC void func_ov000_021a72cc(void *);

EC void func_ov000_021af3cc(ProcPtr param_1)
{
    Unit * psVar2;

    if (gMapStateManager->camera->IsMoving())
    {
        return;
    }

    psVar2 = GetUnit(gActionSt->unitId);

    func_ov000_021aeb70(psVar2);
    data_021974f0 = (u32)psVar2;

    if (func_02002038(gMapStateManager->unk_08, gMapStateManager->unk_04->unk_00))
    {
        func_ov000_021b0de8(gMapStateManager->unk_08->unk_0042, gMapStateManager->unk_08->unk_0043, 0x17, 0);
    }

    func_ov000_021a72cc(gMapStateManager->unk_04);
    StartProcMind(param_1);

    return;
}

EC void func_ov000_021aebb0(void)
{
    BOOL bVar5;
    struct Unit * pUnit;
    s32 x;
    s32 y;

    bVar5 = TRUE;
    pUnit = gMapStateManager->unk_04->unk_00;
    x = pUnit->xPos;
    y = pUnit->yPos;

    func_ov000_021a7284();

    pUnit->state2 &= ~0x20000;

    if ((pUnit->state2 & 0x48) == 0)
    {
        if (pUnit->force->id == data_ov000_021e3324->phase)
        {
            pUnit->state2 |= 1;
        }

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

            func_ov000_021a3c84(
                gMapStateManager->unk_db0, data_ov000_021e3324->phase, fp, sp_10, sp_00, sp_04, sp_08, (u8 *)sp_0c);
            func_ov000_021a3c84(
                gMapStateManager->unk_d30, data_ov000_021e3324->unk_01, fp, sp_10, sp_00, sp_04, sp_08, (u8 *)sp_0c);
        }
        else
        {
            func_ov000_021a3c20(gMapStateManager->unk_db0, data_ov000_021e3324->phase, pUnit);
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
        Proc_Goto(data_ov000_021e3330, 7, 0);
        func_ov000_021a969c(9);
        return;
    }

    if (data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        Proc_Goto(data_ov000_021e3330, 7, 0);
        func_ov000_021a969c(8);
        return;
    }

    func_ov000_021a378c();

    if (gMapStateManager->unk_d30[(x | y << 5) >> 3] & (1 << (x & 7)))
    {
        gMapStateManager->camera->Scroll(x, y, 0, 0x20, 0);
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
    }

    func_0204bbb4(0);

    Proc_Goto(data_ov000_021e3330, 3, 0);

    return;
}

EC void func_ov000_021af4a0(map::ProcLink * param_1)
{
    if (gMapStateManager->camera->IsMoving())
    {
        return;
    }

    if (func_ov000_021a37b4())
    {
        return;
    }

    Proc_Break(param_1, 1);

    return;
}

EC void func_ov000_021af4ec(map::ProcLink * param_1)
{
    BOOL bVar2 = func_ov000_021a98ec(gActionSt->xDecision, gActionSt->yDecision);

    if (!bVar2)
    {
        func_ov000_021a98a4(param_1, gActionSt->xDecision, gActionSt->yDecision, bVar2);
    }

    Proc_Break(param_1, bVar2);

    return;
}

EC void func_ov000_021af548(map::ProcLink * param_1)
{
    if (data_02196f0c->flagMgr->GetByName("gf_gameover"))
    {
        Proc_Goto(data_ov000_021e3330, 7, 0);
        func_ov000_021a969c(9);
        return;
    }

    if (data_02196f0c->flagMgr->GetByName("gf_complete"))
    {
        Proc_Goto(data_ov000_021e3330, 7, 0);
        func_ov000_021a969c(8);
        return;
    }

    Proc_Goto(data_ov000_021e3330, 0, 1);

    return;
}

EC void func_ov000_021af5ec(map::ProcLink * param_1)
{
    if (func_02012298())
    {
        param_1->unk_38 = 0;
        return;
    }

    if (func_02012190() == 2)
    {
        func_ov011_022069b8(0, &param_1->unk_38, param_1);
    }
    else
    {
        param_1->unk_38 = 0;
    }

    return;
}

EC void func_ov000_021af62c(map::ProcLink * param_1)
{
    if (func_02014b20(param_1, 1))
    {
        Proc_Goto(data_ov000_021e3330, 0, 0);
    }
    else
    {
        Proc_Goto(data_ov000_021e3330, 6, 0);
        data_02196f10->unk_07 = !!param_1->unk_38;
        data_02196f10->unk_08 = 1;
    }

    return;
}

EC void func_ov000_021af6ac(void)
{
    Proc_Goto(data_ov000_021e3330, 7, 0);
    func_ov000_021a969c(10);
    return;
}

EC void func_ov000_021af6d4(ProcPtr param_1)
{
    s32 iVar3;
    s32 iVar2 = -1;

    for (iVar3 = 0; iVar3 < 2; iVar3++)
    {
        if (data_ov000_021e3320[iVar3] == 1)
        {
            iVar2 = iVar3;
            break;
        }
    }

    if (iVar2 != -1)
    {
        gMapStateManager->cursor->SetUnk00And02(
            iVar2, gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile);
    }

    Proc_End(param_1);

    return;
}

extern struct ProcCmd data_ov000_021dbf68[]; // ProcScr_ProcLink

EC void func_ov000_021af740(ProcPtr param_1)
{
    new (Proc_StartBlocking(data_ov000_021dbf68, param_1)) map::ProcLink();
    return;
}

EC void ProcMind_ov000_021af79c(ProcEx * proc)
{
    map::ProcPL * playerPhaseProc;
    struct Unit * unit;

    playerPhaseProc = dynamic_cast<map::ProcPL *>((ProcEx *)func_020190cc((struct Proc *)proc));

    if (func_ov000_021a478c() != 0 && data_ov000_021e3320[data_ov000_021e3324->phase] != 3)
    {
        if ((playerPhaseProc != NULL) && (data_ov000_021e3340->unk_06 & 1))
        {
            struct ActionState * tempAction = new ActionState;
            tempAction->unitId = gActionSt->unk_2f;
            tempAction->actionId = 0;

            if (gActionSt->unk_2f != 0)
            {
                unit = gUnitList + gActionSt->unk_2f - 1;
            }
            else
            {
                unit = 0;
            }

            tempAction->func_ov000_021b0eb4(unit);
            func_02012b64(tempAction, sizeof(ActionState));
            delete tempAction;
        }

        gActionSt->unk_14 = func_0201ffc0();

        if (gActionSt->unitId == 0)
        {
            unit = NULL;
        }
        else
        {
            unit = gUnitList + gActionSt->unitId - 1;
        }

        gActionSt->func_ov000_021b0eb4(unit);
        func_020a58b8(gMapStateManager->unk_08, gActionSt, 0x14);
        func_02012b64(gActionSt, sizeof(ActionState));
    }

    if (playerPhaseProc == NULL)
    {
        return;
    }

    if (gActionSt->unitId == 0)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + gActionSt->unitId - 1;
    }

    data_021974fc->unk_00 = unit;
    func_0204b194(unit->xPos, unit->yPos);

    return;
}

EC void ProcMind_ov000_021af944(ProcEx * param_1)
{
    if (!((!(gMapStateManager->unk_04->unk_04->unk_54 & 1) ? TRUE : FALSE) & 0xFF))
    {
        return;
    }

    if (data_ov000_021e3334->Check06__())
    {
        return;
    }

    Proc_Break(param_1, 1);

    return;
}

EC void ProcMind_ov000_021af9bc(ProcEx * proc)
{
    s16 xLo;
    s16 xHi;
    char * pidStrA;
    char * pidStrB;
    s16 ix;
    s16 iy;
    s16 yLo;
    s16 yHi;
    s32 iVar3;

    struct Unit * iVar4;
    struct Unit * iVar5;
    struct Unit * unit;

    switch (gActionSt->actionId)
    {
        case ACTION_NONE:
            break;

        case ACTION_FIGHT:
            if (!data_ov000_021e3334->Check06(4))
            {
                if ((data_ov000_021e3334->unk_06 == 0) || data_ov000_021e3334->Get06() == 2)
                {
                    data_ov000_021e3334->unk_06 = 1;
                }
            }

            StartMapBattle(proc);

            Proc_Goto(proc, 1, 0);

            break;

        case ACTION_STAFF:
            if (!data_ov000_021e3334->Check06_State4())
            {
                if ((data_ov000_021e3334->unk_06 == 0) || data_ov000_021e3334->Get06() == 2)
                {
                    data_ov000_021e3334->unk_06 = 1;
                }
            }

            StartMapRod(proc);

            Proc_Goto(proc, 1, 0);

            break;

        case 3:
            if (!data_ov000_021e3334->Check06_State4())
            {
                if ((data_ov000_021e3334->unk_06 == 0) || data_ov000_021e3334->Get06() == 2)
                {
                    data_ov000_021e3334->unk_06 = 1;
                }
            }

            StartMapItem(proc);

            Proc_Goto(proc, 1, 0);

            break;

        case ACTION_ARMORY:
        case ACTION_VENDOR:
        case ACTION_SECRET_SHOP:
        case ACTION_ARENA:
            Proc_Goto(proc, 1, 0);

            break;

        case ACTION_VISIT_08:
        case ACTION_VISIT_09:
        case ACTION_SEIZE:
            if (!data_ov000_021e3334->Check06_State4())
            {
                if ((data_ov000_021e3334->unk_06 == 0) || data_ov000_021e3334->Get06() == 2)
                {
                    data_ov000_021e3334->unk_06 = 1;
                }
            }

            EventCaller::TryStartVisitEvent(proc, gActionSt->xDecision, gActionSt->yDecision, gActionSt->actionId);

            if (EventCaller::func_020479b0() != 0)
            {
                gMapStateManager->unk_04->unk_04->ClearValues();
            }

            Proc_Goto(proc, 0, 0);

            break;

        case ACTION_ESCAPE:
            if (gActionSt->unitId != 0)
            {
                iVar4 = gUnitList + gActionSt->unitId - 1;
            }
            else
            {
                iVar4 = 0;
            }

            iVar4->state2 |= 0x40;

            if (!data_ov000_021e3334->Check06_State4())
            {
                StartMapUnitEscapeEffect(proc);
            }

            Proc_Goto(proc, 1, 0);

            break;

        case ACTION_IMITATION:
            StartMapImitation();
            Proc_Goto(proc, 1, 0);
            break;

        case 0x15:
        {
            s32 uVar2 = func_ov000_021d4968(gActionSt->xDecision, gActionSt->yDecision, 8);

            if (!data_ov000_021e3334->Check06_State4())
            {
                func_ov000_021d4d80(uVar2, proc, 1);
            }
            else
            {
                func_ov000_021d4d80(uVar2, 0, 0);
            }

            Proc_Goto(proc, 1, 0);

            break;
        }

        case ACTION_DOOR:
            if (!data_ov000_021e3334->Check06_State4())
            {
                if ((data_ov000_021e3334->unk_06 == 0) || data_ov000_021e3334->Get06() == 2)
                {
                    data_ov000_021e3334->unk_06 = 1;
                }
            }

            if (!CheckUnitAttribute(gMapStateManager->unk_04->unk_00, CA_UNK_10))
            {
                iVar3 = func_0203d01c(gMapStateManager->unk_04->unk_00);
                if (gMapStateManager->unk_04->unk_00->items[iVar3].func_0203e0f8(NULL) != 0)
                {
                    func_0203ce08(gMapStateManager->unk_04->unk_00, iVar3, 1);
                }
            }

            xLo = MAX(gActionSt->xDecision - 1, gMapStateManager->unk_24);
            yLo = MAX(gActionSt->yDecision - 1, gMapStateManager->unk_25);
            xHi = MIN(gActionSt->xDecision + 1, gMapStateManager->unk_26 - 1);
            yHi = MIN(gActionSt->yDecision + 1, gMapStateManager->unk_27 - 1);

            for (iy = yLo; iy <= yHi; iy++)
            {
                for (ix = xLo; ix <= xHi; ix++)
                {
                    s32 dy = ABS(gActionSt->yDecision - iy);
                    s32 dx = ABS(gActionSt->xDecision - ix);
                    if ((dx + dy >= 1) && (dx + dy <= 1))
                    {
                        EventCaller::TryStartVisitEvent(proc, ix, iy, gActionSt->actionId);
                    }
                }
            }

            if (EventCaller::func_020479b0() != 0)
            {
                gMapStateManager->unk_04->unk_04->ClearValues();
            }

            Proc_Goto(proc, 1, 0);

            break;

        case ACTION_BRIDGE:
            if (!data_ov000_021e3334->Check06_State4())
            {
                if ((data_ov000_021e3334->unk_06 == 0) || data_ov000_021e3334->Get06() == 2)
                {
                    data_ov000_021e3334->unk_06 = 1;
                }
            }

            if (!CheckUnitAttribute(gMapStateManager->unk_04->unk_00, CA_UNK_10))
            {
                iVar3 = func_0203d094(gMapStateManager->unk_04->unk_00);
                if (gMapStateManager->unk_04->unk_00->items[iVar3].func_0203e0f8(NULL) != 0)
                {
                    func_0203ce08(gMapStateManager->unk_04->unk_00, iVar3, 1);
                }
            }

            xLo = MAX(gActionSt->xDecision - 1, gMapStateManager->unk_24);
            yLo = MAX(gActionSt->yDecision - 1, gMapStateManager->unk_25);
            xHi = MIN(gActionSt->xDecision + 1, gMapStateManager->unk_26 - 1);
            yHi = MIN(gActionSt->yDecision + 1, gMapStateManager->unk_27 - 1);

            for (iy = yLo; iy <= yHi; iy++)
            {
                for (ix = xLo; ix <= xHi; ix++)
                {
                    s32 dy = ABS(gActionSt->yDecision - iy);
                    s32 dx = ABS(gActionSt->xDecision - ix);
                    if ((dx + dy >= 0) && (dx + dy <= 1))
                    {
                        EventCaller::TryStartVisitEvent(proc, ix, iy, gActionSt->actionId);
                    }
                }
            }

            if (EventCaller::func_020479b0() != 0)
            {
                gMapStateManager->unk_04->unk_04->ClearValues();
            }

            Proc_Goto(proc, 1, 0);

            break;

        case ACTION_CHEST:
            if (!data_ov000_021e3334->Check06_State4())
            {
                if ((data_ov000_021e3334->unk_06 == 0) || data_ov000_021e3334->Get06() == 2)
                {
                    data_ov000_021e3334->unk_06 = 1;
                }
            }

            if (!CheckUnitAttribute(gMapStateManager->unk_04->unk_00, CA_UNK_10))
            {
                iVar3 = func_0203d10c(gMapStateManager->unk_04->unk_00);
                if (gMapStateManager->unk_04->unk_00->items[iVar3].func_0203e0f8(NULL) != 0)
                {
                    func_0203ce08(gMapStateManager->unk_04->unk_00, iVar3, 1);
                }
            }

            EventCaller::TryStartVisitEvent(proc, gActionSt->xDecision, gActionSt->yDecision, gActionSt->actionId);

            if (EventCaller::func_020479b0() != 0)
            {
                gMapStateManager->unk_04->unk_04->ClearValues();
            }

            Proc_Goto(proc, 1, 0);

            break;

        case 0x17:
            if (gActionSt->unitId != 0)
            {
                iVar4 = gUnitList + gActionSt->unitId - 1;
            }
            else
            {
                iVar4 = 0;
            }

            func_ov000_021d3674("Encount", iVar4, 0, 0, proc, 1);

            Proc_Goto(proc, 1, 0);

            break;

        case ACTION_TALK:
            if (!data_ov000_021e3334->Check06_State4())
            {
                if ((data_ov000_021e3334->unk_06 == 0) || data_ov000_021e3334->Get06() == 2)
                {
                    data_ov000_021e3334->unk_06 = 1;
                }
            }

            if (gActionSt->unk_34 != 0)
            {
                iVar4 = gUnitList + gActionSt->unk_34 - 1;
            }
            else
            {
                iVar4 = 0;
            }

            if (gActionSt->unk_34 != 0)
            {
                unit = gUnitList + gActionSt->unk_34 - 1;
            }
            else
            {
                unit = 0;
            }

            pidStrA = func_0203c378(iVar4)->pPersonData->pid;

            if (gActionSt->unitId != 0)
            {
                iVar5 = gUnitList + gActionSt->unitId - 1;
            }
            else
            {
                iVar5 = 0;
            }

            pidStrB = func_0203c378(iVar5)->pPersonData->pid;

            EventCaller::TryStartTalkEvent(proc, (u32)pidStrB, (u32)pidStrA, (u32)unit);

            Proc_Goto(proc, 1, 0);

            break;

        case ACTION_10:
            Proc_Goto(proc, 1, 0);
            break;

        case ACTION_DECOY:
            Proc_Goto(proc, 1, 0);
            break;

        case ACTION_WAIT:
            Proc_Goto(proc, 1, 0);
            break;
    }

    return;
}

EC void ProcMind_ov000_021b0510(void)
{
    gSoundManager->unk_a4->vfunc_68(8);
    return;
}

extern s32 data_ov000_021e24c0;

EC void ProcMind_ov000_021b0538(ProcPtr proc)
{
    struct Unit * unit;
    s32 uVar4;

    if (gActionSt->unitId != 0)
    {
        unit = gUnitList + gActionSt->unitId - 1;
    }
    else
    {
        unit = NULL;
    }

    if ((unit->state2 & 0x48) != 0)
    {
        return;
    }

    if (EventCaller::CanStartVisitEvent(gActionSt->xDecision, gActionSt->yDecision, 0x12) == 0)
    {
        return;
    }

    uVar4 = data_ov000_021e24c0;

    if (!data_ov000_021e3334->Check06_State4())
    {
        if ((data_ov000_021e3334->unk_06 == 0) || data_ov000_021e3334->Get06() == 2)
        {
            data_ov000_021e3334->unk_06 = 1;
        }
    }

    EventCaller::TryStartVisitEvent(proc, gActionSt->xDecision, gActionSt->yDecision, 0x12);

    if (EventCaller::func_020479b0() != 0)
    {
        gMapStateManager->unk_04->unk_04->ClearValues();
    }

    if (uVar4 == data_ov000_021e24c0)
    {
        return;
    }

    if (data_ov000_021e3320[data_ov000_021e3324->phase] == 1)
    {
        uVar4 = FF_COMMUNI_FLAG1;
    }
    else
    {
        uVar4 = FF_COMMUNI_FLAG2;
    }

    gSoundManager->unk_b0->vfunc_28(uVar4, 0, 0);
    StartVolumeDownPlayingSE(uVar4, 0x20);

    return;
}

EC void ProcMind_ov000_021b06ac(ProcPtr proc)
{
    if (data_ov000_021e3334->unk_06 == 1)
    {
        data_ov000_021e3334->unk_06 = 0;
    }

    Proc_End(proc);

    return;
}

// clang-format off

struct ProcCmd ProcScr_ProcMind[] =
{
    PROC_NAME,
    PROC_NAME,

    PROC_SLEEP(0),
    PROC_CALL(ProcMind_ov000_021af79c),
    PROC_REPEAT(ProcMind_ov000_021af944),
    PROC_CALL(ProcMind_ov000_021af9bc),

PROC_LABEL(0),
    PROC_CALL(ProcMind_ov000_021b0510),

    // fallthrough

PROC_LABEL(1),
    PROC_CALL(ProcMind_ov000_021b0538),
    PROC_CALL(ProcMind_ov000_021b06ac),

    PROC_END,
};

// clang-format on

class ProcMind : public ProcEx
{
    // func_ov000_021b0dd0
    // func_ov000_021b0dd4
    virtual ~ProcMind()
    {
    }
};

EC void StartProcMind(ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_ProcMind, parent)) ProcMind;

    return;
}

EC void StartSubtitleHelp(char *, ProcPtr);

// SallyPosChangeHelpFirst::vfunc_08
EC void func_ov000_021b09bc(SallyPosChangeHelpFirst * param_1)
{
    param_1->unk_38--;

    if (param_1->unk_38 != 0)
    {
        return;
    }

    StartSubtitleHelp(GetText("MSH_位置変更"), 0);
    Proc_End(param_1);

    return;
}

// func_ov000_021b09f4 -> TurnRegenerateExec::vfunc_08

EC BOOL func_ov000_021a4804(void);
EC s32 func_020381d8(struct TerrainData *, s32);
EC void func_ov000_021cec00(TurnRegenerateExec *, struct Unit *, char *, s32);

EC void func_ov000_021b09f4(TurnRegenerateExec * param_1)
{
    s32 healType = 0;

    if (func_ov000_021a4804())
    {
        if (func_02021410(data_ov000_021e3324->phase)->unk_756 == 0x13)
        {
            healType = 2;
        }
    }

    switch (param_1->unk_3c)
    {
        case 0:
        {
            struct Unit * unit = param_1->unk_38;

            if (unit != NULL)
            {
                do
                {
                    s32 terrainId = gMapStateManager->unk_828[unit->xPos | unit->yPos << 5];
                    struct TerrainData * terrain = &gFE11Database->pTerrain[terrainId];

                    if ((healType == 0) && (terrain->unk_08[3] == 0))
                    {
                        param_1->unk_38 = unit->unk_3c;
                        unit = param_1->unk_38;
                        continue;
                    }

                    if (unit->hp == GetUnitMaxHp(unit))
                    {
                        param_1->unk_38 = unit->unk_3c;
                        unit = param_1->unk_38;
                        continue;
                    }

                    if (!TEMP(unit))
                    {
                        unit->hp = unit->hp + func_020381d8(terrain, healType);
                        param_1->unk_38 = unit->unk_3c;
                        unit = param_1->unk_38;
                        continue;
                    }

                    gMapStateManager->camera->Scroll(unit->xPos, unit->yPos, 0, 0x20, 0);
                    data_ov000_021e3340->unk_09 = 1;
                    param_1->unk_3c++;

                    break;
                } while (unit != NULL);
            }

            if (param_1->unk_38 != NULL)
            {
                goto case_1;
            }

            func_020190cc((struct Proc *)param_1);
            func_ov000_021a8c7c();

            param_1->unk_3c = 10;

            if (!gMapStateManager->camera->IsMoving())
            {
                Proc_End(param_1);
            }

            return;
        }

        case 1:
        case_1:
        {
            struct Unit * unit;
            s32 terrainId;
            struct TerrainData * terrain;

            if (gMapStateManager->camera->IsMoving())
            {
                return;
            }

            unit = param_1->unk_38;
            terrainId = gMapStateManager->unk_828[unit->xPos | unit->yPos << 5];
            terrain = &gFE11Database->pTerrain[terrainId];

            param_1->unk_40 = unit->hp;
            param_1->unk_44 = func_020381d8(terrain, healType);

            func_ov000_021cec00(param_1, unit, "HealTerrain", param_1->unk_44);

            param_1->unk_3c++;

            return;
        }

        case 2:
        {
            struct Unit * unit = param_1->unk_38;

            unit->hp = param_1->unk_40 + param_1->unk_44;

            param_1->unk_38 = unit->unk_3c;
            param_1->unk_3c = 0;

            return;
        }

        case 10:
            if (!gMapStateManager->camera->IsMoving())
            {
                Proc_End(param_1);
            }

            return;

        default:
            return;
    }
}

EC void func_ov000_021bb2c0(void *);

// CpSkip::vfunc_0c
EC void func_ov000_021b0d20(void)
{
    Proc_EndEachMarked(0xb);
    gMapStateManager->camera->StopScroll();
    func_ov000_021bb2c0(gMapStateManager->unk_14->unk_00);
    return;
}
