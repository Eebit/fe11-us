#include "global.h"

#include <new>

#include "action.hpp"
#include "anime.hpp"
#include "hardware.hpp"
#include "item.hpp"
#include "map.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"

#include "constants/sounds.h"

#include "unknown_types.hpp"

extern struct UnkStruct_021974fc * data_021974fc;
extern struct UnkStruct_02196f24 * data_02196f24;
extern struct UnkStruct_02196f0c * data_02196f0c;
extern struct KeyState * gKeySt;

EC struct PersonData * GetPersonByPidStr(char *);
EC struct ItemData * GetItemByIidStr(char *);
EC s32 GetJobDBIndex(struct JobData *);
EC void StartSoundWaitTo_02017518(void *, void *, s32, s32, s32);

struct MovingMapSprite
{
    /* 00 */ void * frames[6];
    /* 18 */ u32 imgAddr;
    /* 1C */ u32 palAddr;
    /* 20 */ u16 jid;
    /* 22 */ u8 unk_22;
    /* 23 */ u8 unk_23;
    /* 24 */ s8 animId;
    /* 25 */ s8 frame;
    /* 26 */ s8 prevAnimId;
    /* 27 */ s8 prevFrame;
    /* 28 */ u32 timer;

    MovingMapSprite(s32, s32, s32, s32);
    ~MovingMapSprite();

    s32 DrawSpriteExt(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    void DrawSprite(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    void StartFlash(s32 arg1, s32 arg2);
    s32 func_0203f6a0(void);
    void UpdateJid(s32 arg1);
    void func_0203f8a0(s32 arg1);
    void Free(void);
};

class MapBattle_38;
class MapBattle_3C;

enum
{
    ROUND_FLAG_END = 0,
    ROUND_FLAG_HIT = 1,
    ROUND_FLAG_2 = 2,
    ROUND_FLAG_4 = 4,
    ROUND_FLAG_CRITICAL = 8,
    ROUND_FLAG_MISS = 0x10,
    ROUND_FLAG_x20 = 0x20,
    ROUND_FLAG_LAST = 0x40,
    ROUND_FLAG_x80 = 0x80,
};

struct BattleRound
{
    /* 00 */ u8 flags;
    /* 01 */ u8 damage;
};

struct MapBattleEffectProc
{
    STRUCT_PAD(0x00, 0x38);
    /* 38 */ Anime * unk_38;
};

namespace onbat
{
class MapBattle : public ProcEx
{
public:
    /* 38 */ MapBattle_38 * unk_38;
    /* 3C */ MapBattle_3C * unk_3c;
    /* 40 */ BattleRound * pRound;
    /* 44 */ MoveUnit * unk_44[2];
    /* 4C */ MoveUnit * unk_4c[2];
    /* 54 */ ProcPtr unk_54[2];
    /* 5C */ u32 timer; // frame counter within current round
    STRUCT_PAD(0x60, 0x64);
    /* 64 */ u8 unk_64[2]; // saved HP per combatant
    /* 66 */ u8 unk_66; // attacker index
    /* 67 */ u8 unk_67; // defender index
    /* 68 */ u8 unk_68;
    /* 69 */ u8 unk_69;
    /* 6A */ u8 unk_6a;
    /* 6B */ u8 unk_6b;

    virtual ~MapBattle()
    {
    }

    void _021cace4(void); // _ZN5onbat9MapBattle9_021cace4Ev
    void _021cae10(void); // _ZN5onbat9MapBattle9_021cae10Ev
    void SetupAnims(void); // _ZN5onbat9MapBattle10SetupAnimsEv
    void SetupBgm(void); // _ZN5onbat9MapBattle8SetupBgmEv
    void _021cb738(void); // _ZN5onbat9MapBattle9_021cb738Ev
    void _021cb74c(void); // _ZN5onbat9MapBattle9_021cb74cEv
    void HandleTransformAttacker(void); // _ZN5onbat9MapBattle23HandleTransformAttackerEv
    void HandleTransformDefender(void); // _ZN5onbat9MapBattle23HandleTransformDefenderEv
    void _021cb9b8(void); // _ZN5onbat9MapBattle9_021cb9b8Ev
    void _021cba08(void); // _ZN5onbat9MapBattle9_021cba08Ev
    void _021cba48(void); // _ZN5onbat9MapBattle9_021cba48Ev
    void _021cba70(void); // _ZN5onbat9MapBattle9_021cba70Ev
    void _021cbab0(void); // _ZN5onbat9MapBattle9_021cbab0Ev
    void _021cbb4c(void); // _ZN5onbat9MapBattle9_021cbb4cEv
    void _021cbb5c(void); // _ZN5onbat9MapBattle9_021cbb5cEv
    void _021cbc44(void); // _ZN5onbat9MapBattle9_021cbc44Ev
    void _021cbcac(void); // _ZN5onbat9MapBattle9_021cbcacEv
    void Unwind(void); // _ZN5onbat9MapBattle6UnwindEv
    void _021cc368(void); // _ZN5onbat9MapBattle9_021cc368Ev
    void _021cc378(void); // _ZN5onbat9MapBattle9_021cc378Ev
    void _021cc438(void); // _ZN5onbat9MapBattle9_021cc438Ev
    void _021cc468(void); // _ZN5onbat9MapBattle9_021cc468Ev
    void _021cc4c4(void); // _ZN5onbat9MapBattle9_021cc4c4Ev
    void _021cc4f4(void); // _ZN5onbat9MapBattle9_021cc4f4Ev
    void WaitForCamera(void); // _ZN5onbat9MapBattle13WaitForCameraEv
    void _021cc5a8(void); // _ZN5onbat9MapBattle9_021cc5a8Ev
    void _021cc6b8(void); // _ZN5onbat9MapBattle9_021cc6b8Ev
    void HandleItemDrop(void); // _ZN5onbat9MapBattle14HandleItemDropEv
    void HandleWeaponBreak(void); // _ZN5onbat9MapBattle17HandleWeaponBreakEv
    void HandleDeath(void); // _ZN5onbat9MapBattle11HandleDeathEv
    void _021cc8c8(void); // _ZN5onbat9MapBattle9_021cc8c8Ev
    void End(void); // _ZN5onbat9MapBattle3EndEv
};

class ProcKiriDragonTransform : public ProcEx
{
public:
    /* 38 */ Unit * pUnit;

    ProcKiriDragonTransform(Unit * unit)
    {
        this->pUnit = unit;
    }

    virtual ~ProcKiriDragonTransform()
    {
    }
};

class UnitMove : public ProcEx
{
public:
    /* 38 */ MoveUnit * pMu;
    /* 3C */ s32 x;
    /* 40 */ s32 y;
    /* 44 */ s32 unk_44;

    UnitMove(MoveUnit * moveUnit, s32 xOffset, s32 yOffset)
    {
        this->proc_mark = PROC_MARK_8;
        this->pMu = moveUnit;
        this->x = xOffset;
        this->y = yOffset;
        this->unk_44 = 0;

        moveUnit->flags |= 4;
    }

    virtual ~UnitMove()
    {
        this->pMu->xPos = 0;
        this->pMu->yPos = 0;
        this->pMu->flags &= ~4;
    }
};

class UnitSurprise : public ProcEx
{
public:
    /* 38 */ MoveUnit * pMu;
    /* 3C */ s32 timer;
    /* 40 */ s32 duration;

    UnitSurprise(MoveUnit * moveUnit, s32 startTime, s32 duration)
    {
        this->proc_mark = PROC_MARK_8;
        this->pMu = moveUnit;
        this->duration = duration;
        this->timer = startTime;
    }

    virtual void Init(void)
    {
        this->timer++;

        if (this->timer < this->duration)
        {
            this->pMu->xPos = (this->timer & 1) ? +2 : -2;
            this->pMu->yPos = 0;
            return;
        }

        Proc_End(this);

        return;
    }

    virtual ~UnitSurprise()
    {
        this->pMu->xPos = 0;
        this->pMu->yPos = 0;
    }
};
} // namespace onbat

EC s32 func_0203f650(s32 jid, s32 animId);

EC void func_ov000_021d2c20(ProcPtr, BOOL);
EC void func_ov000_021bab40(void *, Unit *);
EC void func_ov000_021baafc(void *, Unit *, BOOL);
EC void func_ov000_021bb944(MoveUnit *);

namespace onbat
{
class UnitTransform : public ProcEx
{
public:
    /* 38 */ MoveUnit * pMu;
    /* 3C */ Unit * pUnit;
    /* 40 */ struct JobData * pJobData;
    /* 44 */ s32 savedFacing;
    /* 48 */ s32 timer; // frame counter
    /* 4C */ s32 unk_4c; // animation length
    /* 50 */ u8 unk_50;
    /* 51 */ u8 unk_51;
    /* 52 */ u8 unk_52;
    /* 53 */ u8 unk_53;

    UnitTransform(MoveUnit * moveUnit, struct JobData * job)
    {
        this->pMu = moveUnit;
        this->pJobData = job;
        this->pUnit = moveUnit->pUnit;
        this->savedFacing = moveUnit->facing;

        moveUnit->SetFacingDirection(7);
        moveUnit->pMovingMapSprite->timer = 0;
        this->unk_4c = func_0203f650(moveUnit->pMovingMapSprite->jid, moveUnit->facing);
        this->timer = 0;
        this->unk_50 = 0;
        this->unk_51 = 0;
        this->unk_52 = 0;
        this->unk_53 = 0;
    }

    UnitTransform(MoveUnit * moveUnit, struct JobData * job, BOOL bVar2)
    {
        this->pMu = moveUnit;
        this->pJobData = job;
        this->pUnit = moveUnit->pUnit;
        this->savedFacing = moveUnit->facing;

        moveUnit->SetFacingDirection(0);

        this->timer = 0;
        this->unk_50 = 0;
        this->unk_51 = 0;
        this->unk_52 = 1;
        this->unk_53 = bVar2;
    }

    virtual ~UnitTransform()
    {
        if (!this->unk_51)
        {
            this->pMu->flags &= ~2;
            this->pMu->pMovingMapSprite->UpdateJid(GetJobDBIndex(this->pJobData));
            this->pMu->SetFacingDirection(this->savedFacing);
        }

        this->unk_51 = 1;

        if (this->unk_52)
        {
            func_ov000_021bab40(gMapStateManager->unk_14->unk_00, this->pUnit);
            this->pUnit->pJobData = this->pJobData;
            this->pUnit->state2 &= ~US_UNK_30;
            func_ov000_021baafc(gMapStateManager->unk_14->unk_00, this->pUnit, FALSE);
        }

        Proc_EndEachMarked(PROC_MARK_8);

        if (this->unk_53)
        {
            this->pMu->pUnit->state2 &= ~US_HOVERED;
            func_ov000_021bb944(this->pMu);
        }
    }
};

} // namespace onbat

class MapBattle_3C
{
public:
    /* 00 */ Unit * unk_00[2];
    /* 08 */ ItemData * weapon[2];
    STRUCT_PAD(0x10, 0x36);
    /* 36 */ u8 unk_36[2];
    /* 38 */ u16 unk_38[2];
    STRUCT_PAD(0x3C, 0x40);
};

struct MapBattle_38_24
{
};

class MapBattle_38
{
public:
    /* 00 */ MapBattle_3C * unk_00;
    /* 04 */ BattleRound unk_04[16];
    /* 24 */ MapBattle_38_24 * unk_24;
    /* 28 */ u8 unk_28[2];
    STRUCT_PAD(0x2A, 0x30);
    /* 30 */ u8 unk_30[2];
    /* 32 */ u8 unk_32; // attacker
    /* 33 */ u8 unk_33; // defender

    MapBattle_38(onbat::MapBattle * param_1)
    {
        this->unk_00 = param_1->unk_3c;
        this->unk_24 = NULL;
    }

    ~MapBattle_38()
    {
        if (this->unk_24 != NULL)
        {
            delete this->unk_24;
        }
    }
};

EC void UnitMove_021ca974(onbat::UnitMove * proc)
{
    proc->pMu->pMovingMapSprite->timer += 2;
    return;
}

EC s32 Interpolate(s32, s32, s32, s32, s32);

EC void UnitMove_021ca98c(onbat::UnitMove * proc)
{
    s16 x;
    s16 y;

    proc->unk_44++;

    x = Interpolate(0, 0, proc->x, proc->unk_44, 8);
    y = Interpolate(0, 0, proc->y, proc->unk_44, 8);

    proc->pMu->SetPos(x, y);

    if (proc->unk_44 == 8)
    {
        proc->unk_44 = 0;
        Proc_Break(proc, FALSE);
    }

    return;
}

EC void UnitMove_021caa08(onbat::UnitMove * proc)
{
    s16 x;
    s16 y;

    proc->unk_44++;

    x = Interpolate(0, proc->x, 0, proc->unk_44, 8);
    y = Interpolate(0, proc->y, 0, proc->unk_44, 8);

    proc->pMu->SetPos(x, y);

    if (proc->unk_44 == 8)
    {
        proc->unk_44 = 0;
        Proc_Break(proc, FALSE);
    }

    return;
}

EC void func_ov002_021ef9e0(ProcPtr, struct Unit *);

EC void KiriDragonTransform_021caa84(onbat::ProcKiriDragonTransform * proc)
{
    func_ov002_021ef9e0(proc, proc->pUnit);
    return;
}

EC void func_0204b39c(/* ? */);
EC void _IsProcTutCardActive(/* ? */);
EC void func_0204b444(/* ? */);
EC void func_0204ac18(/* ? */);
EC void func_0204aca8(/* ? */);
EC void func_0204b47c(/* ? */);
EC void func_0204b3b8(/* ? */);

// clang-format off

struct ProcCmd ProcScr_onbat_KiriDragonTransform[] =
{
    PROC_NAME,
    PROC_SLEEP(0),

    PROC_CALL(func_0204b39c),

    PROC_WHILE(_IsProcTutCardActive),

    PROC_CALL(func_0204b444),
    PROC_CALL(func_0204ac18),

    PROC_CALL(KiriDragonTransform_021caa84),

    PROC_CALL(func_0204aca8),
    PROC_CALL(func_0204b47c),
    PROC_CALL(func_0204b3b8),

    PROC_END
};

// clang-format on

EC struct Proc * func_ov000_021d3674(char *, void *, s32, s32, ProcPtr, BOOL);

EC void UnitTransform_Loop(onbat::UnitTransform * self)
{
    struct Proc * fxProc;

    self->timer++;

    if (self->unk_52)
    {
        onbat::ProcKiriDragonTransform * proc = new (Proc_StartBlocking(ProcScr_onbat_KiriDragonTransform, self))
            onbat::ProcKiriDragonTransform(self->pUnit);
        Proc_Break(self, 0);
        return;
    }

    if (!self->unk_50 && self->timer == 8)
    {
        fxProc = func_ov000_021d3674("TransformDragon", self->pUnit, 0, 0, PROC_TREE_B, FALSE);
        Proc_SetMark(fxProc, PROC_MARK_8);

        if (self->pUnit->force->id & 1)
        {
            func_ov000_021d2c20(fxProc, 1);
        }
    }

    if (!self->unk_52)
    {
        if (gKeySt->pressed & (KEY_BUTTON_START | KEY_BUTTON_B))
        {
            self->unk_50 = 1;
        }
    }

    if (self->timer == self->unk_4c - 1 && !self->unk_51)
    {
        self->pMu->flags |= 2;
        self->pMu->pMovingMapSprite->timer = 0;
        self->pMu->pMovingMapSprite->timer = self->unk_4c - 1;
    }

    if (self->unk_50 || self->timer == 67)
    {
        if (!self->unk_51)
        {
            self->pMu->flags &= ~2;
            self->pMu->pMovingMapSprite->UpdateJid(GetJobDBIndex(self->pJobData));
            self->pMu->SetFacingDirection(self->savedFacing);

            self->unk_51 = 1;

            if (self->unk_52)
            {
                func_ov000_021bab40(gMapStateManager->unk_14->unk_00, self->pUnit);
                self->pUnit->pJobData = self->pJobData;
                self->pUnit->state2 &= ~US_UNK_30;
                func_ov000_021baafc(gMapStateManager->unk_14->unk_00, self->pUnit, FALSE);
            }
        }
    }

    if (!self->unk_51)
    {
        return;
    }

    if (self->unk_50 || func_02018e4c(PROC_MARK_8) == NULL)
    {
        Proc_End(self);
    }

    return;
}

EC void func_ov000_021d1ed4(ProcPtr);
EC BOOL func_ov000_021a82c0(void);
EC BOOL func_ov000_021a8248(void);
EC BOOL func_ov000_021a478c(void);

EC void func_ov002_021ef134(ProcPtr, void *);

EC void func_ov000_021c8200(MapBattle_3C *, Unit *, Unit *, s32, s32, s32, s32);
EC void func_ov000_021c97ec(MapBattle_38 *);
EC Unit * func_ov000_021ca0b8(MapBattle_38 *);

void onbat::MapBattle::_021cace4(void)
{
    s32 i;
    s32 x;
    s32 y;

    this->unk_3c = new MapBattle_3C();

    x = gActionSt->xDecision;
    y = gActionSt->yDecision;

    func_ov000_021c8200(this->unk_3c, GetUnit(gActionSt->unitId), GetUnit(gActionSt->unk_34), x, y, -1, 0);

    this->unk_38 = new MapBattle_38(this);
    func_ov000_021c97ec(this->unk_38);

    this->pRound = this->unk_38->unk_04;
    this->timer = 0;
    this->unk_69 = 0;

    for (i = 0; i < 2; i++)
    {
        this->unk_54[i] = NULL;
    }

    this->unk_6a = 0;

    if (func_ov000_021ca0b8(this->unk_38) == data_021974fc->unk_00)
    {
        data_021974fc->unk_00 = NULL;
    }

    return;
}

EC BOOL func_ov000_021ca91c(MapBattle_38 *);
EC s32 func_02012410(void);
EC BOOL func_020146c4(s32);

EC MoveUnit * func_ov000_021bb4c8(void *);
EC void func_ov000_021bb734(MoveUnit *, Unit *, BOOL);
EC BOOL func_ov000_021ca8ac(MapBattle_38 *);
EC void func_ov000_021a820c(void);

void onbat::MapBattle::_021cae10(void)
{
    s32 i;
    s16 x;
    s16 y;
    s16 xMin;
    s16 yMin;
    s16 xMax;
    s16 yMax;
    Unit * unit;
    Unit * attacker;
    Unit * defender;

    this->unk_6a = 1;

    this->unk_44[0] = gMapStateManager->unk_04->pMu;
    this->unk_3c->unk_00[1]->state2 |= US_HOVERED;

    this->unk_44[1] = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);
    func_ov000_021bb734(this->unk_44[1], this->unk_3c->unk_00[1], FALSE);

    this->unk_44[1]->pMovingMapSprite->timer = this->unk_44[0]->pMovingMapSprite->timer;

    if (this->unk_3c->unk_38[0] & 0x100)
    {
        i = 0;

        xMin = MAX(this->unk_3c->unk_00[1]->xPos - 1, gMapStateManager->unk_24);
        yMin = MAX(this->unk_3c->unk_00[1]->yPos - 1, gMapStateManager->unk_25);
        xMax = MIN(this->unk_3c->unk_00[1]->xPos + 1, gMapStateManager->unk_26 - 1);
        yMax = MIN(this->unk_3c->unk_00[1]->yPos + 1, gMapStateManager->unk_27 - 1);

        for (y = yMin; y <= yMax; y++)
        {
            for (x = xMin; x <= xMax; x++)
            {
                s32 dist = ABS(this->unk_3c->unk_00[1]->xPos - x) + ABS(this->unk_3c->unk_00[1]->yPos - y);

                if (dist < 1 || dist > 1)
                {
                    continue;
                }

                unit = GetUnit(gMapStateManager->unk_028[x | y << 5]);

                if (unit == NULL)
                {
                    continue;
                }

                if (!func_0203c378(unit)->CheckAttribute(CA_TRIATTACK))
                {
                    continue;
                }

                if (unit->force->id != this->unk_3c->unk_00[0]->force->id)
                {
                    continue;
                }

                if (unit == this->unk_3c->unk_00[0])
                {
                    continue;
                }

                unit->state2 |= US_HOVERED;

                this->unk_4c[i] = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);
                func_ov000_021bb734(this->unk_4c[i], unit, FALSE);

                this->unk_4c[i]->pMovingMapSprite->timer++;

                i++;

                if (i >= 2)
                {
                    goto L_021cb13c;
                }
            }
        }
    }

L_021cb13c:
    defender = this->unk_3c->unk_00[1];
    attacker = this->unk_3c->unk_00[0];

    if (ABS(attacker->xPos - defender->xPos) >= ABS(attacker->yPos - defender->yPos))
    {
        if (attacker->xPos > defender->xPos)
        {
            this->unk_44[0]->SetFacingDirection(2);
            this->unk_44[1]->SetFacingDirection(3);
        }
        else
        {
            this->unk_44[0]->SetFacingDirection(3);
            this->unk_44[1]->SetFacingDirection(2);
        }
    }
    else
    {
        if (attacker->yPos > defender->yPos)
        {
            this->unk_44[0]->SetFacingDirection(5);
            this->unk_44[1]->SetFacingDirection(4);
        }
        else
        {
            this->unk_44[0]->SetFacingDirection(4);
            this->unk_44[1]->SetFacingDirection(5);
        }
    }

    if (this->unk_3c->unk_38[0] & 0x100)
    {
        for (i = 0; i < 2; i++)
        {
            defender = this->unk_3c->unk_00[1];

            if (ABS(this->unk_4c[i]->pUnit->xPos - defender->xPos) >=
                ABS(this->unk_4c[i]->pUnit->yPos - defender->yPos))
            {
                if (this->unk_4c[i]->pUnit->xPos > defender->xPos)
                {
                    this->unk_4c[i]->SetFacingDirection(2);
                }
                else
                {
                    this->unk_4c[i]->SetFacingDirection(3);
                }
            }
            else
            {
                if (this->unk_4c[i]->pUnit->yPos > defender->yPos)
                {
                    this->unk_4c[i]->SetFacingDirection(5);
                }
                else
                {
                    this->unk_4c[i]->SetFacingDirection(4);
                }
            }
        }
    }

    for (i = 0; i < 2; i++)
    {
        this->unk_64[i] = this->unk_3c->unk_00[i]->hp;
    }

    if (!func_ov000_021a8248())
    {
        return;
    }

    gMapStateManager->camera->ScrollInstant(this->unk_3c->unk_00[1]->xPos, this->unk_3c->unk_00[1]->yPos, 0);

    if (func_ov000_021ca8ac(this->unk_38) || func_ov000_021ca91c(this->unk_38))
    {
        func_ov000_021a820c();
    }

    return;
}

void onbat::MapBattle::SetupAnims(void)
{
    BOOL flag = FALSE;

    if (!func_ov000_021a8248())
    {
        if (func_ov000_021ca91c(this->unk_38))
        {
            flag = TRUE;
        }
        else if ((gKeySt->held & KEY_BUTTON_L) && (!func_ov000_021a478c() || !func_020146c4(func_02012410())))
        {
            if (data_02196f24->animations != 1)
            {
                flag = TRUE;
            }
            else
            {
                flag = FALSE;
            }
        }
        else
        {
            u8 mode = data_02196f24->animations;

            if (mode == 1)
            {
                flag = TRUE;
            }
            else if (mode == 2)
            {
                if (this->unk_3c->unk_00[0]->state2 & US_UNK_31 || this->unk_3c->unk_00[1]->state2 & US_UNK_31)
                {
                    flag = TRUE;
                }
            }
        }
    }

    if (flag)
    {
        Proc_Goto(this, 1, 0);
        this->unk_6b = 1;
    }
    else
    {
        Proc_Goto(this, 0, 0);
        this->unk_6b = 0;
    }
}

extern u8 data_ov000_021e3320[];

void onbat::MapBattle::SetupBgm(void)
{
    struct ItemData * weapon;
    s32 songId = -1;
    Unit * unit;
    s32 i;

    if (!data_02196f24->enableBgm)
    {
        return;
    }

    for (i = 0; i < 2; i++)
    {
        weapon = this->unk_3c->weapon[i];

        if (weapon == GetItemByIidStr("IID_STARLIGHT") && (this->unk_3c->unk_36[i] != 0))
        {
            songId = BGM_BTL_STARLIGHT1;
            break;
        }
        else if (weapon == GetItemByIidStr("IID_MAFU") || weapon == GetItemByIidStr("IID_MAFU_FALSE"))
        {
            songId = BGM_BTL_MAFU1;
        }
    }

    if (songId == -1 && !(data_02196f0c->state & GAME_STATE_UNK_5))
    {
        unit = NULL;

        for (i = 0; i < 2; i++)
        {
            if (this->unk_3c->unk_00[i]->force->id == 1)
            {
                unit = this->unk_3c->unk_00[i];
                break;
            }
        }

        if (unit != NULL)
        {
            if (unit->GetPersonData() == GetPersonByPidStr("PID_MEDIUTH"))
            {
                if (data_02196f0c->state & GAME_STATE_UNK_20)
                {
                    songId = BGM_BTL_BOSS3_2;
                }
                else
                {
                    data_02196f0c->state |= GAME_STATE_UNK_20;
                    songId = BGM_BTL_BOSS3;
                }
            }
            else if (
                unit->GetPersonData() == GetPersonByPidStr("PID_CAMUS") ||
                unit->GetPersonData() == GetPersonByPidStr("PID_MISHEIL"))
            {
                songId = BGM_BTL_BOSS2;
            }
            else if (unit->CheckAttribute(CA_BOSS))
            {
                songId = BGM_BTL_BOSS1;
            }
        }
    }

    if (songId == -1)
    {
        songId = (data_ov000_021e3320[data_ov000_021e3324->phase] == 1) ? BGM_BTL_PL1 : BGM_BTL_CP1;
    }

    StartSoundWaitTo_02017518(gSoundManager->unk_a8, gSoundManager->unk_a4, 0x10, songId, 0x10);

    return;
}

EC void func_ov000_021ca0e8(MapBattle_38 *, onbat::MapBattle *);
EC void func_ov000_021ca4a4(MapBattle_38 *, onbat::MapBattle *);

void onbat::MapBattle::_021cb738(void)
{
    func_ov000_021ca0e8(this->unk_38, this);
    return;
}

void onbat::MapBattle::_021cb74c(void)
{
    func_ov000_021ca4a4(this->unk_38, this);
    return;
}

EC struct JobData * GetJInfoFromItem(struct ItemData *, struct Unit *);

// clang-format off

struct ProcCmd ProcScr_onbat_UnitTransform[] =
{
    PROC_NAME,
    PROC_SLEEP(0),
    PROC_REPEAT(UnitTransform_Loop),
    PROC_END
};

// clang-format on

void onbat::MapBattle::HandleTransformAttacker(void)
{
    struct JobData * job;
    onbat::UnitTransform * proc;

    if (this->unk_3c->weapon[0] != NULL)
    {
        job = GetJInfoFromItem(this->unk_3c->weapon[0], this->unk_3c->unk_00[0]);

        if (job != this->unk_3c->unk_00[0]->pJobData)
        {
            proc =
                new (Proc_StartBlocking(ProcScr_onbat_UnitTransform, this)) onbat::UnitTransform(this->unk_44[0], job);

            if (func_ov000_021a8248())
            {
                Proc_End(proc);
            }
        }
    }

    if (this->unk_3c->weapon[1] == NULL)
    {
        return;
    }

    job = GetJInfoFromItem(this->unk_3c->weapon[1], this->unk_3c->unk_00[1]);

    if (job == this->unk_3c->unk_00[1]->pJobData)
    {
        return;
    }

    this->unk_68 = this->unk_44[1]->facing;

    this->unk_44[1]->SetFacingDirection(0);

    return;
}

void onbat::MapBattle::HandleTransformDefender(void)
{
    struct JobData * job;
    onbat::UnitTransform * proc;

    if (this->unk_3c->weapon[1] == NULL)
    {
        return;
    }

    job = GetJInfoFromItem(this->unk_3c->weapon[1], this->unk_3c->unk_00[1]);

    if (job == this->unk_3c->unk_00[1]->pJobData)
    {
        return;
    }

    this->unk_44[1]->SetFacingDirection(this->unk_68);

    proc = new (Proc_StartBlocking(ProcScr_onbat_UnitTransform, this)) onbat::UnitTransform(this->unk_44[1], job);

    if (func_ov000_021a8248())
    {
        Proc_End(proc);
    }

    return;
}

void onbat::MapBattle::_021cb9b8(void)
{
    ItemData * weapon;
    JobData * job;
    s32 i;
    MoveUnit * moveUnit;

    for (i = 0; i < 2; i++)
    {
        weapon = this->unk_3c->weapon[i];

        if (weapon == NULL)
        {
            continue;
        }

        job = GetJInfoFromItem(weapon, this->unk_3c->unk_00[i]);
        moveUnit = this->unk_44[i];
        moveUnit->pMovingMapSprite->UpdateJid(GetJobDBIndex(job));
    }

    return;
}

void onbat::MapBattle::_021cba08(void)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        MoveUnit * moveUnit = this->unk_44[i];
        moveUnit->pMovingMapSprite->UpdateJid(GetJobDBIndex(this->unk_3c->unk_00[i]->pJobData));
    }

    return;
}

void onbat::MapBattle::_021cba48(void)
{
    if (func_ov000_021a8248())
    {
        Proc_Goto(this, 2, 0);
    }

    return;
}

void onbat::MapBattle::_021cba70(void)
{
    Unit * unit = this->unk_3c->unk_00[1];

    gMapStateManager->camera->Scroll(unit->xPos, unit->yPos, 0, 0x20, 0);
    return;
}

EC s32 func_ov000_021d1ff8(struct Unit *, struct Unit *);
EC s32 func_ov000_021d1f8c(void);
EC s32 func_ov000_021d1f94(void);
EC ProcPtr StartMapHpGauge(ProcPtr, struct Unit *, s32, s32, s32);

void onbat::MapBattle::_021cbab0(void)
{
    Unit * unit;
    s32 idx;
    s32 iVar1;

    iVar1 = func_ov000_021d1ff8(
        this->unk_38->unk_00->unk_00[this->unk_38->unk_32], this->unk_38->unk_00->unk_00[this->unk_38->unk_33]);

    idx = this->unk_38->unk_32;
    unit = this->unk_38->unk_00->unk_00[idx];
    this->unk_54[idx] = StartMapHpGauge(this, unit, func_ov000_021d1f8c(), iVar1, 1);

    idx = this->unk_38->unk_33;
    unit = this->unk_38->unk_00->unk_00[idx];
    this->unk_54[idx] = StartMapHpGauge(this, unit, func_ov000_021d1f94(), iVar1, 0);

    return;
}

void onbat::MapBattle::_021cbb4c(void)
{
    func_ov002_021ef134(this, this->unk_38);
    return;
}

EC void func_ov000_021d1e38(ProcPtr, s32, u32);
EC void Battle_TryStartDeathEvent(MapBattle_38 *, ProcPtr);

struct UnkStruct_021faf8c
{
    STRUCT_PAD(0x00, 0x01);
    /* 01 */ s8 unk_01;
    STRUCT_PAD(0x02, 0x08);
    /* 08 */ u8 unk_08;
    STRUCT_PAD(0x09, 0x5D);
    /* 5D */ s8 unk_5d;
    STRUCT_PAD(0x5E, 0x64);
    /* 64 */ u8 unk_64;
    STRUCT_PAD(0x65, 0xB9);
    /* B9 */ u8 unk_b9;
};

extern struct UnkStruct_021faf8c data_ov002_021faf8c;

EC void func_ov000_021d3b00(struct Unit *, onbat::MapBattle *, s32, s32);

void onbat::MapBattle::_021cbb5c(void)
{
    func_ov000_021d1e38(this->unk_54[this->unk_38->unk_33], data_ov002_021faf8c.unk_01, data_ov002_021faf8c.unk_08 & 1);
    func_ov000_021d1e38(this->unk_54[this->unk_38->unk_32], data_ov002_021faf8c.unk_5d, data_ov002_021faf8c.unk_64 & 1);

    if (this->unk_69 == 0 && (u8)(data_ov002_021faf8c.unk_08 & 2))
    {
        func_ov000_021d3b00(this->unk_3c->unk_00[this->unk_38->unk_33], this, 1, 0);
        this->unk_69 = 1;
    }

    if (this->unk_69 != 0)
    {
        return;
    }

    // TODO: Inline?
    if (!(u8)(data_ov002_021faf8c.unk_64 & 2))
    {
        return;
    }

    func_ov000_021d3b00(this->unk_3c->unk_00[this->unk_38->unk_32], this, 1, 0);
    this->unk_69 = 1;

    return;
}

void onbat::MapBattle::_021cbc44(void)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        if (this->unk_54[i] != NULL)
        {
            func_ov000_021d1e38(this->unk_54[i], this->unk_38->unk_28[i], 0);
        }
    }

    // TODO: Inline?
    if (!(u8)((data_ov002_021faf8c.unk_b9 & 2)))
    {
        Battle_TryStartDeathEvent(this->unk_38, this);
    }

    return;
}

void onbat::MapBattle::_021cbcac(void)
{
    Unit * unit;

    if (this->unk_69 == 0)
    {
        unit = this->unk_3c->unk_00[this->unk_38->unk_33];

        if (func_ov000_021ca0b8(this->unk_38) == unit)
        {
            func_ov000_021d3b00(this->unk_3c->unk_00[this->unk_38->unk_33], this, 0, 1);
            this->unk_69 = 1;
        }
    }

    if (this->unk_69 != 0)
    {
        return;
    }

    unit = this->unk_3c->unk_00[this->unk_38->unk_32];

    if (func_ov000_021ca0b8(this->unk_38) != unit)
    {
        return;
    }

    func_ov000_021d3b00(this->unk_3c->unk_00[this->unk_38->unk_32], this, 0, 1);
    this->unk_69 = 1;

    return;
}

EC s32 func_ov000_021cbd58(Unit * param_1, Unit * param_2)
{
    if (param_1->xPos > param_2->xPos)
    {
        return -1;
    }
    else if (param_1->xPos < param_2->xPos)
    {
        return +1;
    }

    return 0;
}

EC s32 func_ov000_021cbd78(Unit * param_1, Unit * param_2)
{
    if (param_1->yPos > param_2->yPos)
    {
        return -1;
    }
    else if (param_1->yPos < param_2->yPos)
    {
        return +1;
    }

    return 0;
}

EC s32 GetTileSize(void);
EC void func_020a8f40(char *);
EC void func_ov000_021d1ec4(ProcPtr, s32, s32);
EC void * func_ov000_021d3350(char *, s32, s32, s32, s32, s32, s32, s32, s32);
EC ProcPtr StartMapEffectQuake(s32, ProcPtr);
EC void func_ov000_021d2c58(void *);

// clang-format off

struct ProcCmd ProcScr_onbat_UnitMove[] =
{
    PROC_NAME,
    PROC_SLEEP(0),
    PROC_06(0, UnitMove_021ca974),
    PROC_REPEAT(UnitMove_021ca98c),
    PROC_SLEEP(8),
    PROC_REPEAT(UnitMove_021caa08),
    PROC_END
};

// clang-format on

extern struct ProcCmd ProcScr_020ce750[];

void onbat::MapBattle::Unwind(void)
{
    s32 tileSize;
    s32 step;
    s32 i;
    u32 pos;
    s32 xDelta;
    s32 yDelta;
    s32 xOffset;
    s32 yOffset;
    Unit * unit;
    onbat::UnitMove * moveProc;
    onbat::UnitSurprise * surpriseProc;
    MapBattleEffectProc * fxProc;
    char * effectName;
    BOOL silent;

    tileSize = GetTileSize();

    if (this->timer == 0)
    {
        if (this->pRound->flags == ROUND_FLAG_END)
        {
            Proc_EndEachMarked(PROC_MARK_8);
            Proc_Break(this, 0);
            return;
        }

        this->unk_66 = !(this->pRound->flags & ROUND_FLAG_HIT);

        if (this->pRound->flags & ROUND_FLAG_x20)
        {
            this->unk_67 = this->unk_66;
        }
        else
        {
            this->unk_67 = (this->unk_66 + 1) & 1;
        }
    }

    this->timer++;

    if (this->timer == 1)
    {
        unit = this->unk_3c->unk_00[this->unk_67];
        pos = unit->xPos | (unit->yPos << 5);

        if ((gMapStateManager->unk_d30[pos >> 3] & (1 << (pos & 7))) & 0xFF)
        {
            gMapStateManager->camera->Scroll(unit->xPos, unit->yPos, 0, 0x20, 0);
        }
    }

    if (this->timer == 20 && !(this->pRound->flags & ROUND_FLAG_x20))
    {
        xDelta = func_ov000_021cbd58(this->unk_3c->unk_00[this->unk_66], this->unk_3c->unk_00[this->unk_67]);
        yDelta = func_ov000_021cbd78(this->unk_3c->unk_00[this->unk_66], this->unk_3c->unk_00[this->unk_67]);

        step = tileSize >> 2;
        yOffset = yDelta * step;
        xOffset = xDelta * step;

        moveProc = new (Proc_Start(ProcScr_onbat_UnitMove, this))
            onbat::UnitMove(this->unk_44[this->unk_66], xOffset, yOffset);

        if (this->pRound->flags & ROUND_FLAG_x80)
        {
            for (i = 0; i < 2; i++)
            {
                xDelta = func_ov000_021cbd58(this->unk_4c[i]->pUnit, this->unk_3c->unk_00[this->unk_67]);
                yDelta = func_ov000_021cbd78(this->unk_4c[i]->pUnit, this->unk_3c->unk_00[this->unk_67]);

                yOffset = yDelta * step;
                xOffset = xDelta * step;

                moveProc =
                    new (Proc_Start(ProcScr_onbat_UnitMove, this)) onbat::UnitMove(this->unk_4c[i], xOffset, yOffset);
            }
        }
    }

    if (this->timer == 24)
    {
        func_ov000_021d1ec4(this->unk_54[this->unk_67], this->pRound->damage, -1);

        if (this->pRound->damage != 0)
        {
            this->unk_44[this->unk_67]->pMovingMapSprite->StartFlash(12, 0x7fff);
        }
    }

    if (this->timer == 24)
    {
        func_020a8f40("/onmap");

        effectName = NULL;
        silent = TRUE;

        if (this->pRound->flags & ROUND_FLAG_x20)
        {
            gSoundManager->unk_b0->vfunc_28(SE_MAP_HIT1, 0, 0);

            surpriseProc =
                new (Proc_Start(ProcScr_020ce750, this)) onbat::UnitSurprise(this->unk_44[this->unk_67], 0, 24);

            Proc_SetMark((struct Proc *)surpriseProc, PROC_MARK_8);

            if (this->pRound->flags & ROUND_FLAG_LAST)
            {
                silent = FALSE;
            }
        }
        else if (this->pRound->flags & ROUND_FLAG_MISS)
        {
            effectName = "Miss";
        }
        else if (this->pRound->damage == 0)
        {
            effectName = "NoDamage";
        }
        else if (this->pRound->flags & ROUND_FLAG_CRITICAL)
        {
            effectName = "Critical";

            Proc_SetMark((struct Proc *)StartMapEffectQuake(24, this), PROC_MARK_8);

            surpriseProc =
                new (Proc_Start(ProcScr_020ce750, this)) onbat::UnitSurprise(this->unk_44[this->unk_67], 0, 24);

            Proc_SetMark((struct Proc *)surpriseProc, PROC_MARK_8);

            if (!(this->pRound->flags & ROUND_FLAG_LAST))
            {
                gSoundManager->unk_b0->vfunc_28(SE_MAP_HIT1, 0, 0);
            }
        }
        else if (this->pRound->flags & ROUND_FLAG_4)
        {
            effectName = "Hit";

            if (this->pRound->flags & ROUND_FLAG_LAST)
            {
                silent = FALSE;
            }
        }

        if (effectName != NULL)
        {
            unit = this->unk_3c->unk_00[this->unk_67];

            fxProc = (MapBattleEffectProc *)func_ov000_021d3350(
                effectName, tileSize * unit->xPos + (tileSize >> 1), tileSize * unit->yPos + (tileSize >> 1), 0xc00, 0,
                11, 0, 1, 1);

            if (!silent)
            {
                fxProc->unk_38->SetFlag16(TRUE);
            }

            fxProc->unk_38->SetFlag32(FALSE);

            Proc_SetMark((struct Proc *)fxProc, PROC_MARK_8);

            unit = this->unk_3c->unk_00[this->unk_67];
            pos = unit->xPos | (unit->yPos << 5);

            if (!((gMapStateManager->unk_d30[pos >> 3] & (1 << (pos & 7))) & 0xFF))
            {
                func_ov000_021d2c58(fxProc);
            }
        }

        if (this->pRound->flags & ROUND_FLAG_LAST)
        {
            gSoundManager->unk_b0->vfunc_28(SE_MAP_DAMAGE_LAST1, 0, 0);
        }
    }

    if (gKeySt->pressed & (KEY_BUTTON_START | KEY_BUTTON_B))
    {
        Proc_EndEachMarked(PROC_MARK_8);
        this->timer = 0;
        Proc_Break(this, 0);
        return;
    }

    if (this->timer == 64)
    {
        this->timer = 0;
        this->pRound++;
    }

    return;
}

void onbat::MapBattle::_021cc368(void)
{
    Proc_Break(this, 1);
    return;
}

EC void func_ov000_021d1e9c(ProcPtr);

void onbat::MapBattle::_021cc378(void)
{
    s32 i;
    u32 pos;
    Unit * unit;

    for (i = 0; i < 2; i++)
    {
        if (this->unk_54[i] != NULL)
        {
            func_ov000_021d1e9c(this->unk_54[i]);
            func_ov000_021d1e38(this->unk_54[i], this->unk_38->unk_28[i], 0);
        }
    }

    unit = func_ov000_021ca0b8(this->unk_38);

    if (unit != NULL)
    {
        pos = unit->xPos | (unit->yPos << 5);

        if ((gMapStateManager->unk_d30[pos >> 3] & (1 << (pos & 7))) & 0xFF)
        {
            gMapStateManager->camera->Scroll(unit->xPos, unit->yPos, 0, 0x20, 0);
        }
    }

    Battle_TryStartDeathEvent(this->unk_38, this);

    return;
}

void onbat::MapBattle::_021cc438(void)
{
    if (func_ov000_021a8248())
    {
        this->_021cba08();
        Proc_Goto(this, 3, 0);
    }

    return;
}

void onbat::MapBattle::_021cc468(void)
{
    if (this->unk_38->unk_30[0] & 1)
    {
        func_ov000_021d3b00(this->unk_3c->unk_00[0], this, 1, 1);
    }

    if (!(this->unk_38->unk_30[1] & 1))
    {
        return;
    }

    func_ov000_021d3b00(this->unk_3c->unk_00[1], this, 1, 1);

    return;
}

void onbat::MapBattle::_021cc4c4(void)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        if (this->unk_54[i] != NULL)
        {
            func_ov000_021d1ed4(this->unk_54[i]);
        }
    }

    return;
}

void onbat::MapBattle::_021cc4f4(void)
{
    Unit * unit;

    if (func_ov000_021a8248())
    {
        return;
    }

    if (data_ov000_021e3320[data_ov000_021e3324->phase] != 1)
    {
        return;
    }

    unit = this->unk_3c->unk_00[0];
    gMapStateManager->camera->Scroll(unit->xPos, unit->yPos, 0, 0x20, 0);

    return;
}

void onbat::MapBattle::WaitForCamera(void)
{
    if (!gMapStateManager->camera->IsMoving())
    {
        Proc_Break(this, TRUE);
    }

    return;
}

EC void func_ov000_021c9b1c(MapBattle_38 *);
EC void func_ov000_021a340c(void);
EC void func_ov000_021c9f8c(MapBattle_38 *, u32);
EC void func_ov000_021cf59c(onbat::MapBattle *, MapBattle_38_24 *);
EC void func_ov000_021c90c8(MapBattle_38_24 *);

void onbat::MapBattle::_021cc5a8(void)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        this->unk_3c->unk_00[i]->hp = this->unk_64[i];
    }

    func_ov000_021c9b1c(this->unk_38);

    this->unk_44[0]->SetFacingDirection(0);

    if (!(this->unk_38->unk_30[1] & 1))
    {
        this->unk_3c->unk_00[1]->state2 &= ~US_HOVERED;
    }

    func_ov000_021bb944(this->unk_44[1]);

    if (this->unk_3c->unk_38[0] & 0x100)
    {
        for (i = 0; i < 2; i++)
        {
            this->unk_4c[i]->pUnit->state2 &= ~US_HOVERED;
            func_ov000_021bb944(this->unk_4c[i]);
        }
    }

    func_ov000_021a340c();
    func_ov000_021c9f8c(this->unk_38, 0);

    if (this->unk_38->unk_24 == NULL)
    {
        return;
    }

    if (!func_ov000_021a8248())
    {
        func_ov000_021cf59c(this, this->unk_38->unk_24);
        return;
    }

    func_ov000_021c90c8(this->unk_38->unk_24);

    return;
}

void onbat::MapBattle::_021cc6b8(void)
{
    if (func_ov000_021a8248())
    {
        Proc_Goto(this, 4, 0);
    }

    return;
}

EC void func_0203ce08(struct Unit *, s32, BOOL);
EC void func_ov000_021a820c(void);

EC void func_ov000_021c2c60(Unit *, Item *);
EC void func_ov000_021c2ab0(Unit *, Item *, void *);
EC void StartWeaponBrokePopupMaybe(Unit *, struct ItemData *, ProcPtr);

void onbat::MapBattle::HandleItemDrop(void)
{
    s32 i;
    Unit * dropper;
    Unit * taker;
    s32 slot;
    Item * it;
    struct ItemData * itemData;

    dropper = NULL;

    for (i = 0; i < 2; i++)
    {
        if (this->unk_38->unk_30[i] & 1)
        {
            dropper = this->unk_3c->unk_00[i];
            taker = this->unk_3c->unk_00[(i + 1) & 1];
            break;
        }
    }

    if (dropper == NULL)
    {
        return;
    }

    it = dropper->items;

    for (slot = 0; slot < UNIT_ITEM_COUNT; slot++, it++)
    {
        if (it->flags & ITEM_FLAG_DROPPABLE)
        {
            break;
        }
    }

    if (slot == UNIT_ITEM_COUNT)
    {
        return;
    }

    if (func_ov000_021a8248() && ((taker->items[4].id != 0 ? TRUE : FALSE) & 0xff))
    {
        dropper->alpha = 0;
        func_ov000_021a820c();
        Proc_Goto(this, 5, 0);
        return;
    }

    {
        Item item = dropper->items[slot];

        item.flags &= ~(ITEM_FLAG_EQUIPPED | ITEM_FLAG_DROPPABLE);

        itemData = item.GetData();

        if (itemData->attributes & IA_UNK_32)
        {
            item.InitFromIidStr("IID_STEELSWORD");
        }

        dropper->ClearItemAtSlot(slot, TRUE);

        if (func_ov000_021a8248())
        {
            func_ov000_021c2c60(taker, &item);
        }
        else
        {
            func_ov000_021c2ab0(taker, &item, this);
        }
    }

    func_01ffc3f4(this);

    return;
}

void onbat::MapBattle::HandleWeaponBreak(void)
{
    s32 i;
    u8 flags;

    for (i = 0; i < 2; i++)
    {
        flags = this->unk_38->unk_30[i];

        if (!(flags & 1) && (flags & 2))
        {
            StartWeaponBrokePopupMaybe(this->unk_3c->unk_00[i], this->unk_3c->weapon[i], this);
        }
    }

    return;
}

void onbat::MapBattle::HandleDeath(void)
{
    Unit * unit = this->unk_3c->unk_00[1];

    if (!(unit->state2 & US_DEAD))
    {
        return;
    }

    if (unit->force->id == 0)
    {
        unit->MoveToForce(3, TRUE);
    }
    else
    {
        unit->MoveToForce(4, TRUE);
    }

    return;
}

void onbat::MapBattle::_021cc8c8(void)
{
    if (this->unk_6b != 0)
    {
        Proc_Goto(this, 7, 0);
    }
    else
    {
        Proc_Goto(this, 6, 0);
    }

    return;
}

void onbat::MapBattle::End(void)
{
    delete this->unk_38;
    delete this->unk_3c;

    return;
}

EC void MapBattle_021cc92c(onbat::MapBattle * param_1)
{
    if (!func_ov000_021a82c0())
    {
        Proc_Break(param_1, 1);
    }

    return;
}

EC void MapBattle_021cc950(onbat::MapBattle * proc)
{
    proc->_021cace4();
    return;
}

EC void MapBattle_021cc95c(onbat::MapBattle * proc)
{
    proc->_021cae10();
    return;
}

EC void MapBattle_SetupAnims(onbat::MapBattle * proc)
{
    proc->SetupAnims();
    return;
}

EC void MapBattle_SetupBgm(onbat::MapBattle * proc)
{
    proc->SetupBgm();
    return;
}

EC void MapBattle_021cc980(onbat::MapBattle * proc)
{
    proc->_021cb738();
    return;
}

EC void MapBattle_021cc98c(onbat::MapBattle * proc)
{
    proc->_021cb74c();
    return;
}

EC void MapBattle_HandleTransformAttacker(onbat::MapBattle * proc)
{
    proc->HandleTransformAttacker();
    return;
}

EC void MapBattle_HandleTransformDefender(onbat::MapBattle * proc)
{
    proc->HandleTransformDefender();
    return;
}

EC void MapBattle_021cc9b0(onbat::MapBattle * proc)
{
    proc->_021cb9b8();
    return;
}

EC void MapBattle_021cc9bc(onbat::MapBattle * proc)
{
    proc->_021cba08();
    return;
}

EC void MapBattle_021cc9c8(onbat::MapBattle * proc)
{
    proc->_021cba48();
    return;
}

EC void MapBattle_021cc9d4(onbat::MapBattle * proc)
{
    proc->_021cba70();
    return;
}

EC void MapBattle_021cc9e0(onbat::MapBattle * proc)
{
    proc->_021cbab0();
    return;
}

EC void MapBattle_021cc9ec(onbat::MapBattle * proc)
{
    proc->_021cbb4c();
    return;
}

EC void MapBattle_021cc9f8(onbat::MapBattle * proc)
{
    proc->_021cbc44();
    return;
}

EC void MapBattle_021cca04(onbat::MapBattle * proc)
{
    proc->_021cbcac();
    return;
}

EC void MapBattle_021cca10(onbat::MapBattle * proc)
{
    proc->_021cbb5c();
    return;
}

EC void MapBattle_021cca1c(onbat::MapBattle * proc)
{
    proc->Unwind();
    return;
}

EC void MapBattle_021cca28(onbat::MapBattle * proc)
{
    proc->_021cc368();
    return;
}

EC void MapBattle_021cca34(onbat::MapBattle * proc)
{
    proc->_021cc378();
    return;
}

EC void MapBattle_021cca40(onbat::MapBattle * proc)
{
    proc->_021cc438();
    return;
}

EC void MapBattle_021cca4c(onbat::MapBattle * proc)
{
    proc->_021cc468();
    return;
}

EC void MapBattle_021cca58(onbat::MapBattle * proc)
{
    proc->_021cc4c4();
    return;
}

EC void MapBattle_021cca64(onbat::MapBattle * proc)
{
    proc->_021cc4f4();
    return;
}

EC void MapBattle_WaitForCamera(onbat::MapBattle * proc)
{
    proc->WaitForCamera();
    return;
}

EC void MapBattle_021cca7c(onbat::MapBattle * proc)
{
    proc->_021cc5a8();
    return;
}

EC void MapBattle_021cca88(onbat::MapBattle * proc)
{
    proc->_021cc6b8();
    return;
}

EC void MapBattle_HandleItemDrop(onbat::MapBattle * proc)
{
    proc->HandleItemDrop();
    return;
}

EC void MapBattle_HandleWeaponBreak(onbat::MapBattle * proc)
{
    proc->HandleWeaponBreak();
    return;
}

EC void MapBattle_HandleDeath(onbat::MapBattle * proc)
{
    proc->HandleDeath();
    return;
}

EC void func_ov000_021ccab8(onbat::MapBattle * proc)
{
    proc->_021cc8c8();
    return;
}

EC void MapBattle_OnEnd(onbat::MapBattle * proc)
{
    proc->End();
    return;
}

EC void MapBattle_021a43e8(/* ? */);
EC void IsMapEffectUnitAlphaActive(/* ? */);
EC void func_ov000_021a4694(/* ? */);

EC void func_0204b39c(/* ? */);
EC void _IsProcTutCardActive(/* ? */);
EC void func_0204b444(/* ? */);
EC void func_0204ac18(/* ? */);
EC void func_0204aca8(/* ? */);
EC void func_0204b47c(/* ? */);
EC void func_0204b3b8(/* ? */);

// clang-format off

struct ProcCmd ProcScr_MapBattle[] =
{
    PROC_NAME,
    PROC_NAME,

    PROC_ONEND(MapBattle_OnEnd),

    PROC_CALL(MapBattle_021cc950),
    PROC_SLEEP(0),

    PROC_CALL(MapBattle_021cc980),
    PROC_CALL(MapBattle_021a43e8),
    PROC_SLEEP(0),

    PROC_CALL(MapBattle_021cc95c),
    PROC_SLEEP(0),

    PROC_REPEAT(MapBattle_021cc92c),
    PROC_CALL(MapBattle_SetupAnims),

PROC_LABEL(0),
    PROC_CALL(MapBattle_021cc98c),
    PROC_CALL(MapBattle_021a43e8),
    PROC_CALL(MapBattle_HandleTransformAttacker),
    PROC_CALL(MapBattle_HandleTransformDefender),
    PROC_CALL(MapBattle_021cc9c8),
    PROC_CALL(MapBattle_021cc9d4),
    PROC_CALL(MapBattle_021cc9e0),
    PROC_SLEEP(4),

    PROC_REPEAT(MapBattle_021cca1c),
    PROC_REPEAT(MapBattle_021cca28),

    // fallthrough

PROC_LABEL(2),
    PROC_CALL(MapBattle_021cca34),
    PROC_CALL(MapBattle_021cca40),
    PROC_CALL(MapBattle_021cca4c),
    PROC_CALL(MapBattle_021cca58),
    PROC_SLEEP(4),

    PROC_CALL(MapBattle_021cc9bc),

    PROC_GOTO(3),

PROC_LABEL(1),
    PROC_CALL(MapBattle_021cc9b0),
    PROC_CALL(MapBattle_021cc9d4),

    PROC_REPEAT(MapBattle_WaitForCamera),

    PROC_CALL(MapBattle_021cc9e0),

    PROC_CALL(func_0204b39c),

    PROC_WHILE(_IsProcTutCardActive),

    PROC_CALL(func_0204b444),
    PROC_CALL(func_0204ac18),

    PROC_CALL(MapBattle_SetupBgm),

    PROC_06(0, MapBattle_021cca10),
    PROC_CALL(MapBattle_021cc9ec),
    PROC_06(0, NULL),

    PROC_CALL(MapBattle_021cc9f8),
    PROC_CALL(MapBattle_021cca04),

    PROC_0B(func_0204aca8),

    PROC_CALL(MapBattle_021cca58),
    PROC_SLEEP(4),

    PROC_WHILE(IsMapEffectUnitAlphaActive),

    PROC_CALL(MapBattle_021cc9bc),

    PROC_GOTO(3),

PROC_LABEL(3),
    PROC_CALL(MapBattle_021cca64),
    PROC_CALL(MapBattle_021cca7c),
    PROC_CALL(MapBattle_021cca88),

    // fallthrough

PROC_LABEL(4),
    PROC_CALL(MapBattle_HandleItemDrop),
    PROC_CALL(MapBattle_HandleWeaponBreak),
    PROC_CALL(MapBattle_HandleDeath),
    PROC_CALL(func_ov000_021a4694),

    PROC_REPEAT(MapBattle_WaitForCamera),

    PROC_CALL(func_ov000_021ccab8),

    // fallthrough

PROC_LABEL(5),
    PROC_REPEAT(MapBattle_021cc92c),

    PROC_GOTO(4),

PROC_LABEL(6),
    PROC_01,

PROC_LABEL(7),
    PROC_CALL(func_0204b47c),
    PROC_CALL(func_0204b3b8),

    PROC_END
};

// clang-format on

EC void StartMapBattle(ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_MapBattle, parent)) onbat::MapBattle();
}

EC MoveUnit * func_ov000_021bb210(void *, Unit *);

EC void func_ov000_021ccaf8(Unit * pUnit, struct JobData * pJobData, ProcPtr parent)
{
    MoveUnit * pMu;
    BOOL bVar3 = FALSE;

    pMu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, pUnit);

    if (pMu == NULL)
    {
        pUnit->state2 |= US_HOVERED;
        pMu = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);
        func_ov000_021bb734(pMu, pUnit, 0);
        bVar3 = TRUE;
    }

    new (Proc_StartBlocking(ProcScr_onbat_UnitTransform, parent)) onbat::UnitTransform(pMu, pJobData, bVar3);

    return;
}

EC BOOL func_ov000_021d9904(void);

EC BOOL func_ov000_021ccbdc(void)
{
    onbat::MapBattle * pMapBattle;

    if (func_ov000_021d9904())
    {
        return TRUE;
    }

    pMapBattle = static_cast<onbat::MapBattle *>(Proc_Find(ProcScr_MapBattle));

    if (pMapBattle != NULL)
    {
        return pMapBattle->unk_6a;
    }
    else
    {
        return FALSE;
    }
}

EC BOOL func_ov000_021ccc0c(void)
{
    onbat::MapBattle * pMapBattle = static_cast<onbat::MapBattle *>(Proc_Find(ProcScr_MapBattle));

    if (pMapBattle == NULL)
    {
        return FALSE;
    }

    if (pMapBattle->unk_3c->unk_38[0] & 0x100)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
