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
};

struct MapBattle_40
{
    /* 00 */ u8 unk_00;
    /* 01 */ u8 unk_01;
};

struct MapBattleEffectProc
{
    STRUCT_PAD(0x00, 0x38);
    /* 38 */ Anime * unk_38;
};

namespace onbat
{
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
    /* 3C */ s32 unk_3c;
    /* 40 */ s32 unk_40; // duration

    UnitSurprise(MoveUnit * moveUnit, s32 param_2, s32 duration)
    {
        this->proc_mark = PROC_MARK_8;
        this->pMu = moveUnit;
        this->unk_40 = duration;
        this->unk_3c = param_2;
    }

    virtual void Init(void)
    {
        this->unk_3c++;

        if (this->unk_3c < this->unk_40)
        {
            this->pMu->xPos = (this->unk_3c & 1) ? +2 : -2;
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
    /* 44 */ s32 unk_44;
    /* 48 */ s32 unk_48; // frame counter
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
        this->unk_44 = moveUnit->facing;

        moveUnit->SetFacingDirection(7);
        moveUnit->pMovingMapSprite->timer = 0;
        this->unk_4c = func_0203f650(moveUnit->pMovingMapSprite->jid, moveUnit->facing);
        this->unk_48 = 0;
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
        this->unk_44 = moveUnit->facing;

        moveUnit->SetFacingDirection(0);

        this->unk_48 = 0;
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
            this->pMu->facing = this->unk_44;

            if (this->pMu->unk_61 != 0)
            {
                this->pMu->unk_61 = 0;
                this->pMu->unk_60 = -1;
            }
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

} // namespace onbat

namespace onbat
{
class MapBattle : public ProcEx
{
public:
    /* 38 */ MapBattle_38 * unk_38;
    /* 3C */ MapBattle_3C * unk_3c;
    /* 40 */ MapBattle_40 * unk_40;
    /* 44 */ MoveUnit * unk_44[2];
    /* 4C */ MoveUnit * unk_4c[2];
    /* 54 */ ProcPtr unk_54[2];
    /* 5C */ u32 unk_5c; // frame counter within current round
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
    /* 04 */ MapBattle_40 unk_04[16];
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

EC void func_ov000_021ca974(onbat::UnitMove * self)
{
    self->pMu->pMovingMapSprite->timer += 2;
    return;
}

EC s32 Interpolate(s32, s32, s32, s32, s32);

EC void func_ov000_021ca98c(onbat::UnitMove * self)
{
    s16 x;
    s16 y;

    self->unk_44++;

    x = Interpolate(0, 0, self->x, self->unk_44, 8);
    y = Interpolate(0, 0, self->y, self->unk_44, 8);

    self->pMu->SetPos(x, y);

    if (self->unk_44 == 8)
    {
        self->unk_44 = 0;
        Proc_Break(self, FALSE);
    }

    return;
}

EC void func_ov000_021caa08(onbat::UnitMove * self)
{
    s16 x;
    s16 y;

    self->unk_44++;

    x = Interpolate(0, self->x, 0, self->unk_44, 8);
    y = Interpolate(0, self->y, 0, self->unk_44, 8);

    self->pMu->SetPos(x, y);

    if (self->unk_44 == 8)
    {
        self->unk_44 = 0;
        Proc_Break(self, FALSE);
    }

    return;
}

EC void func_ov002_021ef9e0(ProcPtr, struct Unit *);

EC void func_ov000_021caa84(onbat::ProcKiriDragonTransform * proc)
{
    func_ov002_021ef9e0(proc, proc->pUnit);
    return;
}

extern struct ProcCmd ProcScr_onbat_KiriDragonTransform[];

EC struct Proc * func_ov000_021d3674(char *, void *, s32, s32, ProcPtr, BOOL);

EC void func_ov000_021caa94(onbat::UnitTransform * self)
{
    struct Proc * fxProc;

    self->unk_48++;

    if (self->unk_52)
    {
        onbat::ProcKiriDragonTransform * proc = new (Proc_StartBlocking(ProcScr_onbat_KiriDragonTransform, self))
            onbat::ProcKiriDragonTransform(self->pUnit);
        Proc_Break(self, 0);
        return;
    }

    if (!self->unk_50 && self->unk_48 == 8)
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

    if (self->unk_48 == self->unk_4c - 1 && !self->unk_51)
    {
        self->pMu->flags |= 2;
        self->pMu->pMovingMapSprite->timer = 0;
        self->pMu->pMovingMapSprite->timer = self->unk_4c - 1;
    }

    if (self->unk_50 || self->unk_48 == 0x43)
    {
        if (!self->unk_51)
        {
            self->pMu->flags &= ~2;
            self->pMu->pMovingMapSprite->UpdateJid(GetJobDBIndex(self->pJobData));
            self->pMu->SetFacingDirection(self->unk_44);

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

EC void func_ov000_021cba08(onbat::MapBattle *);

EC void func_ov002_021ef134(ProcPtr, void *);

EC void func_ov000_021c8200(MapBattle_3C *, Unit *, Unit *, s32, s32, s32, s32);
EC void func_ov000_021c97ec(MapBattle_38 *);
EC Unit * func_ov000_021ca0b8(MapBattle_38 *);

EC void func_ov000_021cace4(onbat::MapBattle * param_1)
{
    s32 i;
    s32 x;
    s32 y;

    param_1->unk_3c = new MapBattle_3C();

    x = gActionSt->xDecision;
    y = gActionSt->yDecision;

    func_ov000_021c8200(param_1->unk_3c, GetUnit(gActionSt->unitId), GetUnit(gActionSt->unk_34), x, y, -1, 0);

    param_1->unk_38 = new MapBattle_38(param_1);
    func_ov000_021c97ec(param_1->unk_38);

    param_1->unk_40 = param_1->unk_38->unk_04;
    param_1->unk_5c = 0;
    param_1->unk_69 = 0;

    for (i = 0; i < 2; i++)
    {
        param_1->unk_54[i] = NULL;
    }

    param_1->unk_6a = 0;

    if (func_ov000_021ca0b8(param_1->unk_38) == data_021974fc->unk_00)
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

EC void func_ov000_021cae10(onbat::MapBattle * param_1)
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

    param_1->unk_6a = 1;

    param_1->unk_44[0] = gMapStateManager->unk_04->pMu;
    param_1->unk_3c->unk_00[1]->state2 |= US_HOVERED;

    param_1->unk_44[1] = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);
    func_ov000_021bb734(param_1->unk_44[1], param_1->unk_3c->unk_00[1], FALSE);

    param_1->unk_44[1]->pMovingMapSprite->timer = param_1->unk_44[0]->pMovingMapSprite->timer;

    if (param_1->unk_3c->unk_38[0] & 0x100)
    {
        i = 0;

        xMin = MAX(param_1->unk_3c->unk_00[1]->xPos - 1, gMapStateManager->unk_24);
        yMin = MAX(param_1->unk_3c->unk_00[1]->yPos - 1, gMapStateManager->unk_25);
        xMax = MIN(param_1->unk_3c->unk_00[1]->xPos + 1, gMapStateManager->unk_26 - 1);
        yMax = MIN(param_1->unk_3c->unk_00[1]->yPos + 1, gMapStateManager->unk_27 - 1);

        for (y = yMin; y <= yMax; y++)
        {
            for (x = xMin; x <= xMax; x++)
            {
                s32 dist = ABS(param_1->unk_3c->unk_00[1]->xPos - x) + ABS(param_1->unk_3c->unk_00[1]->yPos - y);

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

                if (unit->force->id != param_1->unk_3c->unk_00[0]->force->id)
                {
                    continue;
                }

                if (unit == param_1->unk_3c->unk_00[0])
                {
                    continue;
                }

                unit->state2 |= US_HOVERED;

                param_1->unk_4c[i] = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);
                func_ov000_021bb734(param_1->unk_4c[i], unit, FALSE);

                param_1->unk_4c[i]->pMovingMapSprite->timer++;

                i++;

                if (i >= 2)
                {
                    goto L_021cb13c;
                }
            }
        }
    }

L_021cb13c:
    defender = param_1->unk_3c->unk_00[1];
    attacker = param_1->unk_3c->unk_00[0];

    if (ABS(attacker->xPos - defender->xPos) >= ABS(attacker->yPos - defender->yPos))
    {
        if (attacker->xPos > defender->xPos)
        {
            param_1->unk_44[0]->SetFacingDirection(2);
            param_1->unk_44[1]->SetFacingDirection(3);
        }
        else
        {
            param_1->unk_44[0]->SetFacingDirection(3);
            param_1->unk_44[1]->SetFacingDirection(2);
        }
    }
    else
    {
        if (attacker->yPos > defender->yPos)
        {
            param_1->unk_44[0]->SetFacingDirection(5);
            param_1->unk_44[1]->SetFacingDirection(4);
        }
        else
        {
            param_1->unk_44[0]->SetFacingDirection(4);
            param_1->unk_44[1]->SetFacingDirection(5);
        }
    }

    if (param_1->unk_3c->unk_38[0] & 0x100)
    {
        for (i = 0; i < 2; i++)
        {
            defender = param_1->unk_3c->unk_00[1];

            if (ABS(param_1->unk_4c[i]->pUnit->xPos - defender->xPos) >=
                ABS(param_1->unk_4c[i]->pUnit->yPos - defender->yPos))
            {
                if (param_1->unk_4c[i]->pUnit->xPos > defender->xPos)
                {
                    param_1->unk_4c[i]->SetFacingDirection(2);
                }
                else
                {
                    param_1->unk_4c[i]->SetFacingDirection(3);
                }
            }
            else
            {
                if (param_1->unk_4c[i]->pUnit->yPos > defender->yPos)
                {
                    param_1->unk_4c[i]->SetFacingDirection(5);
                }
                else
                {
                    param_1->unk_4c[i]->SetFacingDirection(4);
                }
            }
        }
    }

    for (i = 0; i < 2; i++)
    {
        param_1->unk_64[i] = param_1->unk_3c->unk_00[i]->hp;
    }

    if (!func_ov000_021a8248())
    {
        return;
    }

    gMapStateManager->camera->ScrollInstant(param_1->unk_3c->unk_00[1]->xPos, param_1->unk_3c->unk_00[1]->yPos, 0);

    if (func_ov000_021ca8ac(param_1->unk_38) || func_ov000_021ca91c(param_1->unk_38))
    {
        func_ov000_021a820c();
    }

    return;
}

EC void func_ov000_021cb444(onbat::MapBattle * param_1)
{
    BOOL flag = FALSE;

    if (!func_ov000_021a8248())
    {
        if (func_ov000_021ca91c(param_1->unk_38))
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
                if (param_1->unk_3c->unk_00[0]->state2 & US_UNK_31 || param_1->unk_3c->unk_00[1]->state2 & US_UNK_31)
                {
                    flag = TRUE;
                }
            }
        }
    }

    if (flag)
    {
        Proc_Goto(param_1, 1, 0);
        param_1->unk_6b = 1;
    }
    else
    {
        Proc_Goto(param_1, 0, 0);
        param_1->unk_6b = 0;
    }
}

extern u8 data_ov000_021e3320[];

EC void func_ov000_021cb54c(onbat::MapBattle * param_1)
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
        weapon = param_1->unk_3c->weapon[i];

        if (weapon == GetItemByIidStr("IID_STARLIGHT") && (param_1->unk_3c->unk_36[i] != 0))
        {
            songId = BGM_BTL_STARLIGHT1;
            break;
        }
        else if (weapon == GetItemByIidStr("IID_MAFU") || weapon == GetItemByIidStr("IID_MAFU_FALSE"))
        {
            songId = BGM_BTL_MAFU1;
        }
    }

    if (songId == -1 && !(data_02196f0c->state & 0x20))
    {
        unit = NULL;

        for (i = 0; i < 2; i++)
        {
            if (param_1->unk_3c->unk_00[i]->force->id == 1)
            {
                unit = param_1->unk_3c->unk_00[i];
                break;
            }
        }

        if (unit != NULL)
        {
            if (unit->GetPersonData() == GetPersonByPidStr("PID_MEDIUTH"))
            {
                if (data_02196f0c->state & 0x100000)
                {
                    songId = BGM_BTL_BOSS3_2;
                }
                else
                {
                    data_02196f0c->state |= 0x100000;
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

EC void func_ov000_021cb738(onbat::MapBattle * param_1)
{
    func_ov000_021ca0e8(param_1->unk_38, param_1);
    return;
}

EC void func_ov000_021cb74c(onbat::MapBattle * param_1)
{
    func_ov000_021ca4a4(param_1->unk_38, param_1);
    return;
}

EC struct JobData * GetJInfoFromItem(struct ItemData *, struct Unit *);

extern struct ProcCmd ProcScr_onbat_UnitTransform[];

EC void func_ov000_021cb760(onbat::MapBattle * param_1)
{
    struct JobData * job;
    onbat::UnitTransform * proc;

    if (param_1->unk_3c->weapon[0] != NULL)
    {
        job = GetJInfoFromItem(param_1->unk_3c->weapon[0], param_1->unk_3c->unk_00[0]);

        if (job != param_1->unk_3c->unk_00[0]->pJobData)
        {
            proc = new (Proc_StartBlocking(ProcScr_onbat_UnitTransform, param_1))
                onbat::UnitTransform(param_1->unk_44[0], job);

            if (func_ov000_021a8248())
            {
                Proc_End(proc);
            }
        }
    }

    if (param_1->unk_3c->weapon[1] == NULL)
    {
        return;
    }

    job = GetJInfoFromItem(param_1->unk_3c->weapon[1], param_1->unk_3c->unk_00[1]);

    if (job == param_1->unk_3c->unk_00[1]->pJobData)
    {
        return;
    }

    param_1->unk_68 = param_1->unk_44[1]->facing;

    param_1->unk_44[1]->SetFacingDirection(0);

    return;
}

EC void func_ov000_021cb8a4(onbat::MapBattle * param_1)
{
    struct JobData * job;
    onbat::UnitTransform * proc;

    if (param_1->unk_3c->weapon[1] == NULL)
    {
        return;
    }

    job = GetJInfoFromItem(param_1->unk_3c->weapon[1], param_1->unk_3c->unk_00[1]);

    if (job == param_1->unk_3c->unk_00[1]->pJobData)
    {
        return;
    }

    param_1->unk_44[1]->SetFacingDirection(param_1->unk_68);

    proc = new (Proc_StartBlocking(ProcScr_onbat_UnitTransform, param_1)) onbat::UnitTransform(param_1->unk_44[1], job);

    if (func_ov000_021a8248())
    {
        Proc_End(proc);
    }

    return;
}

EC void func_ov000_021cb9b8(onbat::MapBattle * param_1)
{
    ItemData * weapon;
    JobData * job;
    s32 i;
    MoveUnit * moveUnit;

    for (i = 0; i < 2; i++)
    {
        weapon = param_1->unk_3c->weapon[i];

        if (weapon == NULL)
        {
            continue;
        }

        job = GetJInfoFromItem(weapon, param_1->unk_3c->unk_00[i]);
        moveUnit = param_1->unk_44[i];
        moveUnit->pMovingMapSprite->UpdateJid(GetJobDBIndex(job));
    }

    return;
}

EC void func_ov000_021cba08(onbat::MapBattle * param_1)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        MoveUnit * moveUnit = param_1->unk_44[i];
        moveUnit->pMovingMapSprite->UpdateJid(GetJobDBIndex(param_1->unk_3c->unk_00[i]->pJobData));
    }

    return;
}

EC void func_ov000_021cba48(onbat::MapBattle * param_1)
{
    if (func_ov000_021a8248())
    {
        Proc_Goto(param_1, 2, 0);
    }

    return;
}

EC void func_ov000_021cba70(onbat::MapBattle * param_1)
{
    Unit * unit = param_1->unk_3c->unk_00[1];

    gMapStateManager->camera->Scroll(unit->xPos, unit->yPos, 0, 0x20, 0);
    return;
}

EC s32 func_ov000_021d1ff8(struct Unit *, struct Unit *);
EC s32 func_ov000_021d1f8c(void);
EC s32 func_ov000_021d1f94(void);
EC ProcPtr func_ov000_021d1f30(ProcPtr, struct Unit *, s32, s32, s32);

EC void func_ov000_021cbab0(onbat::MapBattle * param_1)
{
    Unit * unit;
    s32 idx;
    s32 iVar1;

    iVar1 = func_ov000_021d1ff8(
        param_1->unk_38->unk_00->unk_00[param_1->unk_38->unk_32],
        param_1->unk_38->unk_00->unk_00[param_1->unk_38->unk_33]);

    idx = param_1->unk_38->unk_32;
    unit = param_1->unk_38->unk_00->unk_00[idx];
    param_1->unk_54[idx] = func_ov000_021d1f30(param_1, unit, func_ov000_021d1f8c(), iVar1, 1);

    idx = param_1->unk_38->unk_33;
    unit = param_1->unk_38->unk_00->unk_00[idx];
    param_1->unk_54[idx] = func_ov000_021d1f30(param_1, unit, func_ov000_021d1f94(), iVar1, 0);

    return;
}

EC void func_ov000_021cbb4c(onbat::MapBattle * param_1)
{
    func_ov002_021ef134(param_1, param_1->unk_38);
    return;
}

EC void func_ov000_021d1e38(ProcPtr, s32, u32);
EC void func_ov000_021ca798(MapBattle_38 *, ProcPtr);

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

EC void func_ov000_021cbb5c(onbat::MapBattle * param_1)
{
    func_ov000_021d1e38(
        param_1->unk_54[param_1->unk_38->unk_33], data_ov002_021faf8c.unk_01, data_ov002_021faf8c.unk_08 & 1);
    func_ov000_021d1e38(
        param_1->unk_54[param_1->unk_38->unk_32], data_ov002_021faf8c.unk_5d, data_ov002_021faf8c.unk_64 & 1);

    if (param_1->unk_69 == 0 && (u8)(data_ov002_021faf8c.unk_08 & 2))
    {
        func_ov000_021d3b00(param_1->unk_3c->unk_00[param_1->unk_38->unk_33], param_1, 1, 0);
        param_1->unk_69 = 1;
    }

    if (param_1->unk_69 != 0)
    {
        return;
    }

    // TODO: Inline?
    if (!(u8)(data_ov002_021faf8c.unk_64 & 2))
    {
        return;
    }

    func_ov000_021d3b00(param_1->unk_3c->unk_00[param_1->unk_38->unk_32], param_1, 1, 0);
    param_1->unk_69 = 1;

    return;
}

EC void func_ov000_021cbc44(onbat::MapBattle * param_1)
{
    s32 iVar1;

    for (iVar1 = 0; iVar1 < 2; iVar1++)
    {
        if (param_1->unk_54[iVar1] != NULL)
        {
            func_ov000_021d1e38(param_1->unk_54[iVar1], param_1->unk_38->unk_28[iVar1], 0);
        }
    }

    // TODO: Inline?
    if (!(u8)((data_ov002_021faf8c.unk_b9 & 2)))
    {
        func_ov000_021ca798(param_1->unk_38, param_1);
    }

    return;
}

EC void func_ov000_021cbcac(onbat::MapBattle * param_1)
{
    struct Unit * unit;

    if (param_1->unk_69 == 0)
    {
        unit = param_1->unk_3c->unk_00[param_1->unk_38->unk_33];

        if (func_ov000_021ca0b8(param_1->unk_38) == unit)
        {
            func_ov000_021d3b00(param_1->unk_3c->unk_00[param_1->unk_38->unk_33], param_1, 0, 1);
            param_1->unk_69 = 1;
        }
    }

    if (param_1->unk_69 != 0)
    {
        return;
    }

    unit = param_1->unk_3c->unk_00[param_1->unk_38->unk_32];

    if (func_ov000_021ca0b8(param_1->unk_38) != unit)
    {
        return;
    }

    func_ov000_021d3b00(param_1->unk_3c->unk_00[param_1->unk_38->unk_32], param_1, 0, 1);
    param_1->unk_69 = 1;

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
EC ProcPtr func_ov000_021d39a4(s32, ProcPtr);
EC void func_ov000_021d2c58(void *);

extern struct ProcCmd ProcScr_onbat_UnitMove[];
extern struct ProcCmd ProcScr_020ce750[];

EC void func_ov000_021cbd98(onbat::MapBattle * param_1)
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

    if (param_1->unk_5c == 0)
    {
        if (param_1->unk_40->unk_00 == 0)
        {
            Proc_EndEachMarked(PROC_MARK_8);
            Proc_Break(param_1, 0);
            return;
        }

        param_1->unk_66 = !(param_1->unk_40->unk_00 & 1);

        if (param_1->unk_40->unk_00 & 0x20)
        {
            param_1->unk_67 = param_1->unk_66;
        }
        else
        {
            param_1->unk_67 = (param_1->unk_66 + 1) & 1;
        }
    }

    param_1->unk_5c++;

    if (param_1->unk_5c == 1)
    {
        unit = param_1->unk_3c->unk_00[param_1->unk_67];
        pos = unit->xPos | (unit->yPos << 5);

        if ((gMapStateManager->unk_d30[pos >> 3] & (1 << (pos & 7))) & 0xFF)
        {
            gMapStateManager->camera->Scroll(unit->xPos, unit->yPos, 0, 0x20, 0);
        }
    }

    if (param_1->unk_5c == 20 && !(param_1->unk_40->unk_00 & 0x20))
    {
        xDelta =
            func_ov000_021cbd58(param_1->unk_3c->unk_00[param_1->unk_66], param_1->unk_3c->unk_00[param_1->unk_67]);
        yDelta =
            func_ov000_021cbd78(param_1->unk_3c->unk_00[param_1->unk_66], param_1->unk_3c->unk_00[param_1->unk_67]);

        step = tileSize >> 2;
        yOffset = yDelta * step;
        xOffset = xDelta * step;

        moveProc = new (Proc_Start(ProcScr_onbat_UnitMove, param_1))
            onbat::UnitMove(param_1->unk_44[param_1->unk_66], xOffset, yOffset);

        if (param_1->unk_40->unk_00 & 0x80)
        {
            for (i = 0; i < 2; i++)
            {
                xDelta = func_ov000_021cbd58(param_1->unk_4c[i]->pUnit, param_1->unk_3c->unk_00[param_1->unk_67]);
                yDelta = func_ov000_021cbd78(param_1->unk_4c[i]->pUnit, param_1->unk_3c->unk_00[param_1->unk_67]);

                yOffset = yDelta * step;
                xOffset = xDelta * step;

                moveProc = new (Proc_Start(ProcScr_onbat_UnitMove, param_1))
                    onbat::UnitMove(param_1->unk_4c[i], xOffset, yOffset);
            }
        }
    }

    if (param_1->unk_5c == 24)
    {
        func_ov000_021d1ec4(param_1->unk_54[param_1->unk_67], param_1->unk_40->unk_01, -1);

        if (param_1->unk_40->unk_01 != 0)
        {
            param_1->unk_44[param_1->unk_67]->pMovingMapSprite->StartFlash(12, 0x7fff);
        }
    }

    if (param_1->unk_5c == 24)
    {
        func_020a8f40("/onmap");

        effectName = NULL;
        silent = TRUE;

        if (param_1->unk_40->unk_00 & 0x20)
        {
            gSoundManager->unk_b0->vfunc_28(SE_MAP_HIT1, 0, 0);

            surpriseProc = new (Proc_Start(ProcScr_020ce750, param_1))
                onbat::UnitSurprise(param_1->unk_44[param_1->unk_67], 0, 24);

            Proc_SetMark((struct Proc *)surpriseProc, PROC_MARK_8);

            if (param_1->unk_40->unk_00 & 0x40)
            {
                silent = FALSE;
            }
        }
        else if (param_1->unk_40->unk_00 & 0x10)
        {
            effectName = "Miss";
        }
        else if (param_1->unk_40->unk_01 == 0)
        {
            effectName = "NoDamage";
        }
        else if (param_1->unk_40->unk_00 & 8)
        {
            effectName = "Critical";

            Proc_SetMark((struct Proc *)func_ov000_021d39a4(24, param_1), PROC_MARK_8);

            surpriseProc = new (Proc_Start(ProcScr_020ce750, param_1))
                onbat::UnitSurprise(param_1->unk_44[param_1->unk_67], 0, 24);

            Proc_SetMark((struct Proc *)surpriseProc, PROC_MARK_8);

            if (!(param_1->unk_40->unk_00 & 0x40))
            {
                gSoundManager->unk_b0->vfunc_28(SE_MAP_HIT1, 0, 0);
            }
        }
        else if (param_1->unk_40->unk_00 & 4)
        {
            effectName = "Hit";

            if (param_1->unk_40->unk_00 & 0x40)
            {
                silent = FALSE;
            }
        }

        if (effectName != NULL)
        {
            unit = param_1->unk_3c->unk_00[param_1->unk_67];

            fxProc = (MapBattleEffectProc *)func_ov000_021d3350(
                effectName, tileSize * unit->xPos + (tileSize >> 1), tileSize * unit->yPos + (tileSize >> 1), 0xc00, 0,
                11, 0, 1, 1);

            if (!silent)
            {
                fxProc->unk_38->SetFlag16(TRUE);
            }

            fxProc->unk_38->SetFlag32(FALSE);

            Proc_SetMark((struct Proc *)fxProc, PROC_MARK_8);

            unit = param_1->unk_3c->unk_00[param_1->unk_67];
            pos = unit->xPos | (unit->yPos << 5);

            if (!((gMapStateManager->unk_d30[pos >> 3] & (1 << (pos & 7))) & 0xFF))
            {
                func_ov000_021d2c58(fxProc);
            }
        }

        if (param_1->unk_40->unk_00 & 0x40)
        {
            gSoundManager->unk_b0->vfunc_28(SE_MAP_DAMAGE_LAST1, 0, 0);
        }
    }

    if (gKeySt->pressed & (KEY_BUTTON_START | KEY_BUTTON_B))
    {
        Proc_EndEachMarked(PROC_MARK_8);
        param_1->unk_5c = 0;
        Proc_Break(param_1, 0);
        return;
    }

    if (param_1->unk_5c == 64)
    {
        param_1->unk_5c = 0;
        param_1->unk_40++;
    }

    return;
}

EC void func_ov000_021cc368(onbat::MapBattle * param_1)
{
    Proc_Break(param_1, 1);
    return;
}

EC void func_ov000_021d1e9c(ProcPtr);

EC void func_ov000_021cc378(onbat::MapBattle * param_1)
{
    s32 i;
    u32 pos;
    Unit * unit;

    for (i = 0; i < 2; i++)
    {
        if (param_1->unk_54[i] != NULL)
        {
            func_ov000_021d1e9c(param_1->unk_54[i]);
            func_ov000_021d1e38(param_1->unk_54[i], param_1->unk_38->unk_28[i], 0);
        }
    }

    unit = func_ov000_021ca0b8(param_1->unk_38);

    if (unit != NULL)
    {
        pos = unit->xPos | (unit->yPos << 5);

        if ((gMapStateManager->unk_d30[pos >> 3] & (1 << (pos & 7))) & 0xFF)
        {
            gMapStateManager->camera->Scroll(unit->xPos, unit->yPos, 0, 0x20, 0);
        }
    }

    func_ov000_021ca798(param_1->unk_38, param_1);

    return;
}

EC void func_ov000_021cc438(onbat::MapBattle * param_1)
{
    if (func_ov000_021a8248())
    {
        func_ov000_021cba08(param_1);
        Proc_Goto(param_1, 3, 0);
    }

    return;
}

EC void func_ov000_021cc468(onbat::MapBattle * param_1)
{
    if (param_1->unk_38->unk_30[0] & 1)
    {
        func_ov000_021d3b00(param_1->unk_3c->unk_00[0], param_1, 1, 1);
    }

    if (!(param_1->unk_38->unk_30[1] & 1))
    {
        return;
    }

    func_ov000_021d3b00(param_1->unk_3c->unk_00[1], param_1, 1, 1);

    return;
}

EC void func_ov000_021cc4c4(onbat::MapBattle * param_1)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        if (param_1->unk_54[i] != NULL)
        {
            func_ov000_021d1ed4(param_1->unk_54[i]);
        }
    }

    return;
}

EC void func_ov000_021cc4f4(onbat::MapBattle * param_1)
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

    unit = param_1->unk_3c->unk_00[0];
    gMapStateManager->camera->Scroll(unit->xPos, unit->yPos, 0, 0x20, 0);

    return;
}

EC void func_ov000_021cc570(onbat::MapBattle * param_1)
{
    if (!gMapStateManager->camera->IsMoving())
    {
        Proc_Break(param_1, 1);
    }

    return;
}

EC void func_ov000_021c9b1c(MapBattle_38 *);
EC void func_ov000_021a340c(void);
EC void func_ov000_021c9f8c(MapBattle_38 *, u32);
EC void func_ov000_021cf59c(onbat::MapBattle *, MapBattle_38_24 *);
EC void func_ov000_021c90c8(MapBattle_38_24 *);

EC void func_ov000_021cc5a8(onbat::MapBattle * param_1)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        param_1->unk_3c->unk_00[i]->hp = param_1->unk_64[i];
    }

    func_ov000_021c9b1c(param_1->unk_38);

    param_1->unk_44[0]->SetFacingDirection(0);

    if (!(param_1->unk_38->unk_30[1] & 1))
    {
        param_1->unk_3c->unk_00[1]->state2 &= ~US_HOVERED;
    }

    func_ov000_021bb944(param_1->unk_44[1]);

    if (param_1->unk_3c->unk_38[0] & 0x100)
    {
        for (i = 0; i < 2; i++)
        {
            param_1->unk_4c[i]->pUnit->state2 &= ~US_HOVERED;
            func_ov000_021bb944(param_1->unk_4c[i]);
        }
    }

    func_ov000_021a340c();
    func_ov000_021c9f8c(param_1->unk_38, 0);

    if (param_1->unk_38->unk_24 == NULL)
    {
        return;
    }

    if (!func_ov000_021a8248())
    {
        func_ov000_021cf59c(param_1, param_1->unk_38->unk_24);
        return;
    }

    func_ov000_021c90c8(param_1->unk_38->unk_24);

    return;
}

EC void func_ov000_021cc6b8(onbat::MapBattle * param_1)
{
    if (func_ov000_021a8248())
    {
        Proc_Goto(param_1, 4, 0);
    }

    return;
}

EC void func_0203ce08(struct Unit *, s32, BOOL);
EC void func_ov000_021a820c(void);

EC void func_ov000_021c2c60(Unit *, Item *);
EC void func_ov000_021c2ab0(Unit *, Item *, void *);
EC void func_ov000_021c2dd0(Unit *, struct ItemData *, ProcPtr);

EC void func_ov000_021cc6e0(onbat::MapBattle * param_1)
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
        if (param_1->unk_38->unk_30[i] & 1)
        {
            dropper = param_1->unk_3c->unk_00[i];
            taker = param_1->unk_3c->unk_00[(i + 1) & 1];
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
        Proc_Goto(param_1, 5, 0);
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
            func_ov000_021c2ab0(taker, &item, param_1);
        }
    }

    func_01ffc3f4(param_1);

    return;
}

EC void func_ov000_021cc834(onbat::MapBattle * param_1)
{
    s32 i;
    u8 flags;

    for (i = 0; i < 2; i++)
    {
        flags = param_1->unk_38->unk_30[i];

        if (!(flags & 1) && (flags & 2))
        {
            func_ov000_021c2dd0(param_1->unk_3c->unk_00[i], param_1->unk_3c->weapon[i], param_1);
        }
    }

    return;
}

EC void func_ov000_021cc884(onbat::MapBattle * param_1)
{
    Unit * unit = param_1->unk_3c->unk_00[1];

    if (!(unit->state2 & US_DEAD))
    {
        return;
    }

    if (unit->force->id == 0)
    {
        unit->MoveToForce(3, TRUE);
        return;
    }

    unit->MoveToForce(4, TRUE);

    return;
}

EC void func_ov000_021cc8c8(onbat::MapBattle * param_1)
{
    if (param_1->unk_6b != 0)
    {
        Proc_Goto(param_1, 7, 0);
    }
    else
    {
        Proc_Goto(param_1, 6, 0);
    }

    return;
}

EC void func_ov000_021cc8f4(onbat::MapBattle * param_1)
{
    delete param_1->unk_38;
    delete param_1->unk_3c;

    return;
}

EC void func_ov000_021cc92c(onbat::MapBattle * param_1)
{
    if (!func_ov000_021a82c0())
    {
        Proc_Break(param_1, 1);
    }

    return;
}

EC void func_ov000_021cc950(onbat::MapBattle * proc)
{
    func_ov000_021cace4(proc);
    return;
}

EC void func_ov000_021cc95c(onbat::MapBattle * proc)
{
    func_ov000_021cae10(proc);
    return;
}

EC void func_ov000_021cc968(onbat::MapBattle * proc)
{
    func_ov000_021cb444(proc);
    return;
}

EC void func_ov000_021cc974(onbat::MapBattle * proc)
{
    func_ov000_021cb54c(proc);
    return;
}

EC void func_ov000_021cc980(onbat::MapBattle * proc)
{
    func_ov000_021cb738(proc);
    return;
}

EC void func_ov000_021cc98c(onbat::MapBattle * proc)
{
    func_ov000_021cb74c(proc);
    return;
}

EC void func_ov000_021cc998(onbat::MapBattle * proc)
{
    func_ov000_021cb760(proc);
    return;
}

EC void func_ov000_021cc9a4(onbat::MapBattle * proc)
{
    func_ov000_021cb8a4(proc);
    return;
}

EC void func_ov000_021cc9b0(onbat::MapBattle * proc)
{
    func_ov000_021cb9b8(proc);
    return;
}

EC void func_ov000_021cc9bc(onbat::MapBattle * proc)
{
    func_ov000_021cba08(proc);
    return;
}

EC void func_ov000_021cc9c8(onbat::MapBattle * proc)
{
    func_ov000_021cba48(proc);
    return;
}

EC void func_ov000_021cc9d4(onbat::MapBattle * proc)
{
    func_ov000_021cba70(proc);
    return;
}

EC void func_ov000_021cc9e0(onbat::MapBattle * proc)
{
    func_ov000_021cbab0(proc);
    return;
}

EC void func_ov000_021cc9ec(onbat::MapBattle * proc)
{
    func_ov000_021cbb4c(proc);
    return;
}

EC void func_ov000_021cc9f8(onbat::MapBattle * proc)
{
    func_ov000_021cbc44(proc);
    return;
}

EC void func_ov000_021cca04(onbat::MapBattle * proc)
{
    func_ov000_021cbcac(proc);
    return;
}

EC void func_ov000_021cca10(onbat::MapBattle * proc)
{
    func_ov000_021cbb5c(proc);
    return;
}

EC void func_ov000_021cca1c(onbat::MapBattle * proc)
{
    func_ov000_021cbd98(proc);
    return;
}

EC void func_ov000_021cca28(onbat::MapBattle * proc)
{
    func_ov000_021cc368(proc);
    return;
}

EC void func_ov000_021cca34(onbat::MapBattle * proc)
{
    func_ov000_021cc378(proc);
    return;
}

EC void func_ov000_021cca40(onbat::MapBattle * proc)
{
    func_ov000_021cc438(proc);
    return;
}

EC void func_ov000_021cca4c(onbat::MapBattle * proc)
{
    func_ov000_021cc468(proc);
    return;
}

EC void func_ov000_021cca58(onbat::MapBattle * proc)
{
    func_ov000_021cc4c4(proc);
    return;
}

EC void func_ov000_021cca64(onbat::MapBattle * proc)
{
    func_ov000_021cc4f4(proc);
    return;
}

EC void func_ov000_021cca70(onbat::MapBattle * proc)
{
    func_ov000_021cc570(proc);
    return;
}

EC void func_ov000_021cca7c(onbat::MapBattle * proc)
{
    func_ov000_021cc5a8(proc);
    return;
}

EC void func_ov000_021cca88(onbat::MapBattle * proc)
{
    func_ov000_021cc6b8(proc);
    return;
}

EC void func_ov000_021cca94(onbat::MapBattle * proc)
{
    func_ov000_021cc6e0(proc);
    return;
}

EC void func_ov000_021ccaa0(onbat::MapBattle * proc)
{
    func_ov000_021cc834(proc);
    return;
}

EC void func_ov000_021ccaac(onbat::MapBattle * proc)
{
    func_ov000_021cc884(proc);
    return;
}

EC void func_ov000_021ccab8(onbat::MapBattle * proc)
{
    func_ov000_021cc8c8(proc);
    return;
}

EC void func_ov000_021ccac4(onbat::MapBattle * proc)
{
    func_ov000_021cc8f4(proc);
    return;
}

extern struct ProcCmd ProcScr_MapBattle[];

EC void StartMapBattle(ProcPtr parent)
{
    new (Proc_StartBlocking(ProcScr_MapBattle, parent)) onbat::MapBattle();
}

EC MoveUnit * func_ov000_021bb210(void *, Unit *);

EC void func_ov000_021ccaf8(Unit * param_1, struct JobData * param_2, ProcPtr param_3)
{
    MoveUnit * pMVar1;
    BOOL bVar3 = 0;

    pMVar1 = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, param_1);

    if (pMVar1 == NULL)
    {
        param_1->state2 |= US_HOVERED;
        pMVar1 = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);
        func_ov000_021bb734(pMVar1, param_1, 0);
        bVar3 = 1;
    }

    new (Proc_StartBlocking(ProcScr_onbat_UnitTransform, param_3)) onbat::UnitTransform(pMVar1, param_2, bVar3);

    return;
}

EC BOOL func_ov000_021d9904(void);

EC BOOL func_ov000_021ccbdc(void)
{
    onbat::MapBattle * iVar2;

    if (func_ov000_021d9904())
    {
        return TRUE;
    }

    iVar2 = static_cast<onbat::MapBattle *>(Proc_Find(ProcScr_MapBattle));

    if (iVar2 != NULL)
    {
        return iVar2->unk_6a;
    }
    else
    {
        return FALSE;
    }
}

EC BOOL func_ov000_021ccc0c(void)
{
    onbat::MapBattle * iVar1 = static_cast<onbat::MapBattle *>(Proc_Find(ProcScr_MapBattle));

    if (iVar1 == NULL)
    {
        return FALSE;
    }

    if (iVar1->unk_3c->unk_38[0] & 0x100)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
