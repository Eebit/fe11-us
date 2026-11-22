#include "global.h"

#include "action.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "map.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"
#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "constants/sounds.h"

EC void StartSoundWaitTo_02017518(void *, void *, s32, s32, s32);
EC void StartSoundWaitTo_02017b40(SoundHandle *, SoundHandle *, s32);
EC void func_ov000_021baafc(void *, Unit *, BOOL);
EC struct Proc * func_ov000_021ccaf8(Unit *, struct JobData *, ProcPtr);
EC struct Proc * StartMapEffectQuake(s32, ProcPtr, s32);
EC struct Proc * func_ov000_021d3b00(Unit *, ProcPtr, s32, s32);
EC void func_ov000_021d4004(s32, s32);
EC void func_ov000_021d4cb4(s32, Event *);

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

    void func_0203f8a0(s32 arg1);
};

struct CpuSeqData
{
    /* 00 */ STRUCT_PAD(0x00, 0x04);
    /* 04 */ u8 unk_04;
};

struct UnkStruct_Func_ov000_021d4968_Ret
{
    /* 00 */ STRUCT_PAD(0x00, 0x07);
    /* 07 */ u8 unk_07;
};

EC s16 func_020424f4(EventEngine * self, s32 index)
{
    return self->unk_08->args[index];
}

EC BOOL FlagRegistGrobal(EventEngine * unused, char * name)
{
    data_02196f0c->flagMgr->RegisterName(name, FALSE);
    return FALSE;
}

EC BOOL FlagRegist(EventEngine * unused, char * name)
{
    data_02196f0c->flagMgr->RegisterName(name, TRUE);
    return FALSE;
}

EC BOOL FlagGet(EventEngine * unused, char * name)
{
    return data_02196f0c->flagMgr->GetByName(name);
}

EC BOOL FlagSet(EventEngine * unused, char * name)
{
    data_02196f0c->flagMgr->SetByName(name);
    return FALSE;
}

EC BOOL FlagClr(EventEngine * unused, char * name)
{
    data_02196f0c->flagMgr->ClearByName(name);
    return FALSE;
}

EC BOOL ValueRegistGrobal(EventEngine * unused, char * name)
{
    data_02196f0c->valueMgr->RegisterName(name, FALSE);
    return FALSE;
}

EC BOOL ValueRegist(EventEngine * unused, char * name)
{
    data_02196f0c->valueMgr->RegisterName(name, TRUE);
    return FALSE;
}

EC s32 ValueGet(EventEngine * unused, char * name)
{
    return data_02196f0c->valueMgr->GetByName(name);
}

EC BOOL ValueSet(EventEngine * unused, char * name, s32 value)
{
    data_02196f0c->valueMgr->SetByName(name, value);
    return FALSE;
}

EC void Random_02042634(void)
{
    Random_Next();
    return;
}

EC s32 RandomMinMax(EventEngine * unused, s32 min, s32 max)
{
    return RollRN(min, max);
}

EC BOOL SkipExec(EventEngine * self)
{
    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    EventSkip::SkipTransitionFrom0To2();
    self->unk_1c = 1;
    return TRUE;
}

EC BOOL SkipEscape(EventEngine * self)
{
    if (!EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    EventSkip::SkipTransitionFrom2To0Or4To5();
    self->unk_1c = 1;
    return TRUE;
}

EC BOOL SkipEnable(void)
{
    EventSkip::SkipTransition1To0();
    return TRUE;
}

EC BOOL func_020426b4(void)
{
    EventSkip::SkipTransition1To0();
    return TRUE;
}

EC BOOL IsSkip(void)
{
    return EventSkip::IsSkipState4();
}

EC BOOL IsSkipDisable(void)
{
    return EventSkip::IsSkipState1() != 0;
}

EC BOOL IsSkipCpu(void)
{
    if (EventSkip::IsSkipState4() && func_ov000_021a8248() != 0)
    {
        return TRUE;
    }

    return FALSE;
}

EC BOOL SkipGameMap(void)
{
    data_02196f0c->state |= GAME_STATE_UNK_11;
    return FALSE;
}

EC BOOL SkipSaveMenu(void)
{
    data_02196f0c->state |= GAME_STATE_UNK_7;
    return FALSE;
}

EC BOOL JumpToEnding(void)
{
    data_02196f0c->state |= GAME_STATE_UNK_13;
    return FALSE;
}

EC BOOL FadeIn(EventEngine * unused, s32 arg)
{
    EventSkip::SetUnk04(0);

    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    if (!func_0201bd6c())
    {
        StartFadeInFromBlack(NULL, arg, 0);
    }
    else
    {
        StartFadeInFromWhite(NULL, arg, 0);
    }

    return FALSE;
}

EC BOOL FadeInSub(EventEngine * unused, s32 arg)
{
    ScreenState * prev;

    EventSkip::SetUnk05(0);

    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    prev = gpActiveScreenSt;
    gpActiveScreenSt = gpSubScreenSt;

    if (!func_0201bd6c())
    {
        StartFadeInFromBlack(NULL, arg, 0);
    }
    else
    {
        StartFadeInFromWhite(NULL, arg, 0);
    }

    gpActiveScreenSt = prev;
    return FALSE;
}

EC BOOL FadeInDual(EventEngine * unused, s32 arg)
{
    ScreenState * prev;
    s32 i;

    EventSkip::SetUnk04(0);
    EventSkip::SetUnk05(0);

    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    prev = gpActiveScreenSt;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            gpActiveScreenSt = gpMainScreenSt;
        }
        else
        {
            gpActiveScreenSt = gpSubScreenSt;
        }

        if (!func_0201bd6c())
        {
            StartFadeInFromBlack(NULL, arg, 0);
        }
        else
        {
            StartFadeInFromWhite(NULL, arg, 0);
        }
    }

    gpActiveScreenSt = prev;
    return FALSE;
}

EC BOOL FadeOut(EventEngine * unused, u32 frames)
{
    EventSkip::SetUnk04(TRUE);

    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    StartFadeOutToBlack(NULL, (u16)frames, 0);
    return FALSE;
}

EC BOOL FadeOutSub(EventEngine * unused, u32 frames)
{
    ScreenState * prev;

    EventSkip::SetUnk05(TRUE);

    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    prev = gpActiveScreenSt;
    gpActiveScreenSt = gpSubScreenSt;
    StartFadeOutToBlack(NULL, (u16)frames, 0);
    gpActiveScreenSt = prev;
    return FALSE;
}

EC BOOL FadeOutDual(EventEngine * unused, u32 frames)
{
    EventSkip::SetUnk04(TRUE);
    EventSkip::SetUnk05(TRUE);

    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    StartFadeOutToBlack(NULL, (u16)frames, 1);
    return FALSE;
}

EC BOOL FadeOutWhite(EventEngine * unused, u32 frames)
{
    EventSkip::SetUnk04(TRUE);

    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    StartFadeOutToWhite(NULL, (u16)frames, 0);
    return FALSE;
}

EC BOOL FadeOutWhiteSub(EventEngine * unused, u32 frames)
{
    ScreenState * prev;

    EventSkip::SetUnk05(TRUE);

    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    prev = gpActiveScreenSt;
    gpActiveScreenSt = gpSubScreenSt;
    StartFadeOutToWhite(NULL, (u16)frames, 0);
    gpActiveScreenSt = prev;
    return FALSE;
}

EC BOOL FadeOutWhiteDual(EventEngine * unused, u32 frames)
{
    EventSkip::SetUnk04(TRUE);
    EventSkip::SetUnk05(TRUE);

    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    StartFadeOutToWhite(NULL, (u16)frames, 1);
    return FALSE;
}

EC void IsFade(void)
{
    IsFadeActive();
    return;
}

EC s32 SoundIsAsync(void)
{
    return func_020163c0();
}

EC BOOL BGMPlay(EventEngine * unused, s32 arg)
{
    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    if (gSoundManager->unk_a8->vfunc_50())
    {
        gSoundManager->unk_a8->vfunc_38(0);
    }

    gSoundManager->unk_a4->vfunc_30(arg, 0, 0);
    return FALSE;
}

EC BOOL BGMPlayF(EventEngine * unused, s32 arg, s32 arg2)
{
    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    if (gSoundManager->unk_a8->vfunc_50())
    {
        gSoundManager->unk_a8->vfunc_38(0);
    }

    gSoundManager->unk_a4->vfunc_30(arg, arg2, 0);
    return FALSE;
}

EC BOOL BGMStop(EventEngine * unused, s32 arg)
{
    if (gSoundManager->unk_a8->vfunc_50())
    {
        StartSoundWaitTo_02017b40(gSoundManager->unk_a4, gSoundManager->unk_a8, arg);
        gSoundManager->unk_a8->vfunc_6c(0x7f);
        gSoundManager->unk_a4->vfunc_6c(0x7f);
    }
    else
    {
        gSoundManager->unk_a4->vfunc_38(arg);
        gSoundManager->unk_a4->vfunc_6c(0x7f);
    }

    return FALSE;
}

EC BOOL BGMPausePlay(EventEngine * unused, s32 bgmId)
{
    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    if (!(gSoundManager->unk_a4->vfunc_50() || gSoundManager->unk_a4->vfunc_54()) || gSoundManager->unk_a4->vfunc_5c())
    {
        return FALSE;
    }

    if (gSoundManager->unk_a8->vfunc_50() && !gSoundManager->unk_a8->vfunc_58())
    {
        if (bgmId == gSoundManager->unk_a8->unk_08)
        {
            return FALSE;
        }
    }

    if (gSoundManager->unk_a8->vfunc_50())
    {
        if (gSoundManager->unk_a4->vfunc_60())
        {
            gSoundManager->unk_a4->vfunc_44(0);
        }
        gSoundManager->unk_a8->vfunc_3c(0x10, bgmId, 0);
    }
    else
    {
        StartSoundWaitTo_02017518(gSoundManager->unk_a8, gSoundManager->unk_a4, 0x10, bgmId, 0);
    }

    return FALSE;
}

EC BOOL BGMPausePlayF(EventEngine * unused, s32 arg, s32 arg2)
{
    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    if (gSoundManager->unk_a8->vfunc_50() && !gSoundManager->unk_a8->vfunc_58())
    {
        if (arg == gSoundManager->unk_a8->unk_08)
        {
            return FALSE;
        }
    }

    if (gSoundManager->unk_a8->vfunc_50())
    {
        if (gSoundManager->unk_a4->vfunc_60())
        {
            gSoundManager->unk_a4->vfunc_44(0);
        }
        gSoundManager->unk_a8->vfunc_3c(0x10, arg, arg2);
    }
    else
    {
        StartSoundWaitTo_02017518(gSoundManager->unk_a8, gSoundManager->unk_a4, 0x10, arg, arg2);
    }

    return FALSE;
}

EC BOOL BGMPauseStop(EventEngine * unused, s32 arg)
{
    gSoundManager->unk_a8->vfunc_38(arg);
    gSoundManager->unk_a8->vfunc_6c(0x7f);
    return FALSE;
}

EC BOOL BGMPlayPause(EventEngine * self, s32 id)
{
    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    if (id < 0 || id == data_ov000_021e3324->phase)
    {
        MapBattle_021a43e8();
        return FALSE;
    }
    return BGMPausePlay(self, GetMapBgmId(id));
}

EC BOOL _BGMVolume(EventEngine * unused, s32 vol)
{
    if (EventSkip::IsSkipState4())
    {
        if (vol == 0x7f)
        {
            gSoundManager->unk_a4->vfunc_64(vol, 0);
        }
        else
        {
            gSoundManager->unk_a4->vfunc_6c(vol);
        }
        return FALSE;
    }
    gSoundManager->unk_a4->vfunc_64(vol, 8);
    return FALSE;
}

EC BOOL _BGMVolumeF(EventEngine * unused, s32 vol, s32 frames)
{
    if (EventSkip::IsSkipState4())
    {
        if (vol == 0x7f)
        {
            gSoundManager->unk_a4->vfunc_64(vol, 0);
        }
        else
        {
            gSoundManager->unk_a4->vfunc_6c(vol);
        }
        return FALSE;
    }

    gSoundManager->unk_a4->vfunc_64(vol, frames);
    return FALSE;
}

EC BOOL _BGMBtlVolume(EventEngine * unused, s32 vol)
{
    if (EventSkip::IsSkipState4())
    {
        gSoundManager->unk_a8->vfunc_6c(vol);
        return FALSE;
    }

    gSoundManager->unk_a8->vfunc_64(vol, 8);
    return FALSE;
}

EC BOOL _BGMBtlVolumeF(EventEngine * unused, s32 vol, s32 frames)
{
    if (EventSkip::IsSkipState4())
    {
        gSoundManager->unk_a8->vfunc_6c(vol);
        return FALSE;
    }

    gSoundManager->unk_a8->vfunc_64(vol, frames);
    return FALSE;
}

EC BOOL BGMIsFade(void)
{
    if (gSoundManager->unk_a4->vfunc_58())
    {
        return TRUE;
    }

    return gSoundManager->unk_a8->vfunc_58() != 0;
}

EC BOOL SEPlay(EventEngine * unused, s32 arg)
{
    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    gSoundManager->unk_b0->vfunc_28(arg, 0, 0);
    return FALSE;
}

EC BOOL LoopSEPlay(EventEngine * unused, s32 arg)
{
    if (EventSkip::IsSkipState4())
    {
        return FALSE;
    }

    gSoundManager->unk_b4->vfunc_28(arg, 0, 0);
    return FALSE;
}

EC BOOL LoopSEStop(EventEngine * unused, s32 arg)
{
    gSoundManager->unk_b4->vfunc_38(arg);
    return FALSE;
}

EC BOOL SEIsPlay(EventEngine * unused, s16 arg)
{
    return func_02016250(arg);
}

EC BOOL MapLoad(void)
{
    func_ov000_021a23e0(NULL);
    func_ov000_021a2540(NULL, 0);
    return FALSE;
}

EC BOOL MapLoadD(EventEngine * unused, char * arg)
{
    func_ov000_021a23e0(arg);
    func_ov000_021a2540(NULL, 0);
    return FALSE;
}

EC BOOL MapFree(EventEngine * unused)
{
    func_ov000_021a2574();
    return FALSE;
}

EC BOOL Dispos_02043358(EventEngine * unused, char * label)
{
    if (EventSkip::IsSkipState4())
    {
        return StartDisposition(label, 1);
    }

    return StartDisposition(label, 0);
}

EC BOOL DisposPlayArea(EventEngine * unused, char * label)
{
    if (EventSkip::IsSkipState4())
    {
        return StartDisposition(label, 9);
    }

    return StartDisposition(label, 8);
}

EC BOOL DisposMoment(EventEngine * unused, char * label)
{
    return StartDisposition(label, 1);
}

EC BOOL DisposWithScroll(EventEngine * unused, char * label)
{
    if (EventSkip::IsSkipState4())
    {
        return StartDisposition(label, 3);
    }

    return StartDisposition(label, 2);
}

EC BOOL DisposWithScrollView(EventEngine * unused, char * label)
{
    if (EventSkip::IsSkipState4())
    {
        return StartDisposition(label, 7);
    }

    return StartDisposition(label, 6);
}

EC BOOL DisposPlayAreaWithScrollView(EventEngine * unused, char * label)
{
    if (EventSkip::IsSkipState4())
    {
        return StartDisposition(label, 15);
    }

    return StartDisposition(label, 14);
}

EC BOOL IsDispos(void)
{
    return IsDispositionActive();
}

EC BOOL SetChapter(EventEngine * unused, s32 chapter)
{
    func_02021134(chapter);
    return FALSE;
}

EC BOOL AddChapter(void)
{
    s32 idx = GetMapDBIndex(data_02196f0c->pCurrentMap) + 1;

    if (idx == gFE11Database->pDBFE11Footer->mapIdLength)
    {
        idx = 0;
    }

    func_02021150(idx);
    return FALSE;
}

EC BOOL Scroll_020434c0(EventEngine * unused, s32 x, s32 y)
{
    if (EventSkip::IsSkipState4())
    {
        gMapStateManager->camera->ScrollInstant(x, y, 0);
        return TRUE;
    }

    gMapStateManager->camera->Scroll(x, y, 0, 0x20, 1);
    return TRUE;
}

EC BOOL ScrollEx_0204353c(EventEngine * unused, s32 x, s32 y, s32 a, s32 b)
{
    if (EventSkip::IsSkipState4())
    {
        gMapStateManager->camera->ScrollInstant(x, y, 0);
        return TRUE;
    }

    gMapStateManager->camera->ScrollEx(x, y, 0, a, b, 1);
    return TRUE;
}

EC BOOL ScrollMoment(EventEngine * unused, s32 x, s32 y)
{
    gMapStateManager->camera->ScrollInstant(x, y, 0);
    return TRUE;
}

EC BOOL ScrollCenter(EventEngine * unused, s32 x, s32 y)
{
    if (EventSkip::IsSkipState4())
    {
        gMapStateManager->camera->ScrollInstant(x, y, 1);
        return TRUE;
    }

    gMapStateManager->camera->Scroll(x, y, 1, 0x20, 1);
    return TRUE;
}

EC BOOL ScrollCenterEx(EventEngine * unused, s32 x, s32 y, s32 a, s32 b)
{
    if (EventSkip::IsSkipState4())
    {
        gMapStateManager->camera->ScrollInstant(x, y, 1);
        return TRUE;
    }

    gMapStateManager->camera->ScrollEx(x, y, 1, a, b, 1);
    return TRUE;
}

EC BOOL ScrollCenterMoment(EventEngine * unused, s32 x, s32 y)
{
    gMapStateManager->camera->ScrollInstant(x, y, 1);
    return TRUE;
}

EC BOOL IsScroll(void)
{
    return gMapStateManager->camera->state >= 2;
}

EC void IsAccel(void)
{
    func_020252fc();
    return;
}

EC u16 MapGetW(void)
{
    return gMapStateManager->width;
}

EC u16 MapGetH(void)
{
    return gMapStateManager->height;
}

EC u8 UnitGetByPID(EventEngine * unused, char * pid)
{
    struct Unit * unit = FindUnitByPidStrAndFaction(pid);

    if (unit != NULL)
    {
        return unit->unk_68;
    }

    return 0;
}

EC u8 UnitSafetyGetByPID(EventEngine * unused, char * pid)
{
    struct Unit * unit = FindUnitByPidStrAndFaction(pid);

    if (unit != NULL)
    {
        return unit->unk_68;
    }

    return 0;
}

EC s32 UnitGetByPos(EventEngine * unused, s32 x, s32 y)
{
    struct Unit * unit;
    s32 id = gMapStateManager->unk_428[x | y << 5];

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    return unit->unk_68;
}

EC s32 UnitSafetyGetByPos(EventEngine * unused, s32 x, s32 y)
{
    struct Unit * unit;
    s32 id = gMapStateManager->unk_428[x | y << 5];

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    return unit->unk_68;
}

EC s32 UnitGetHero(void)
{
    Unit * unit = Force::Get(0)->FindByAttribute(2);

    if (unit == NULL)
    {
        unit = Force::Get(2)->FindByAttribute(2);
    }

    if (unit == NULL)
    {
        return 0;
    }

    return unit->unk_68;
}

EC s32 UnitGetNext(EventEngine * unused, s32 id)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    unit = unit->next;

    if (unit != NULL)
    {
        return unit->unk_68;
    }

    return 0;
}

EC s32 UnitGetX(EventEngine * unused, s32 id)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    return unit->xPos;
}

EC s32 UnitGetY(EventEngine * unused, s32 id)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    return unit->yPos;
}

EC s32 UnitGetForce(EventEngine * unused, s32 id)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    return unit->force->id;
}

#pragma inline_depth(5)
EC BOOL UnitCheckPID(EventEngine * unused, s32 id, char * pid)
{
    struct Unit * unit;
    struct PersonData * person;

    unit = GetUnit(id);

    if (unit == NULL)
    {
        return FALSE;
    }

    person = func_0203c378(unit)->GetPersonData();

    return person == GetPersonByPidStr(pid);
}
EC BOOL UnitCheckJID(EventEngine * unused, s32 id, char * jid)
{
    struct Unit * unit;
    struct JobData * job;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    job = unit->pJobData;

    return job == GetJobByJidStr(jid);
}

EC BOOL UnitCheckItem(EventEngine * unused, s32 id, char * iidStr)
{
    struct Unit * unit;
    struct ItemData * itemData;
    s32 i;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    itemData = GetItemByIidStr(iidStr);

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        if (unit->items[i].GetData() == itemData)
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL UnitCheckDead(EventEngine * unused, s32 id)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return TRUE;
    }

    return (unit->state2 & US_DEAD) != 0;
}

EC BOOL UnitSetItemAdd(EventEngine * unused, s32 id, char * iidStr, s32 flag)
{
    struct Unit * unit;
    struct ItemData * itemData;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    itemData = GetItemByIidStr(iidStr);
    unit->AddItem(itemData, flag ? ITEM_FLAG_DROPPABLE : 0);
    unit->EquipItem(-1);
    return FALSE;
}

EC BOOL UnitSetItemPutOff(EventEngine * unused, s32 unitId, char * iid)
{
    Unit * unit = GetUnit(unitId);
    ItemData * item;
    s32 i;

    if (unit == NULL)
    {
        return FALSE;
    }

    item = GetItemByIidStr(iid);

    for (i = 0; i < UNIT_ITEM_COUNT; i++)
    {
        if (unit->items[i].GetData() == item)
        {
            unit->ClearItemAtSlot(i, TRUE);
            unit->CompactItems();
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL UnitSetItemPutOffAll(EventEngine * unused, s32 unitId)
{
    Unit * unit = GetUnit(unitId);

    if (unit == NULL)
    {
        return FALSE;
    }

    unit->ClearItems();
    return FALSE;
}

EC BOOL UnitSetPID(EventEngine * unused, s32 unitId, char * pid)
{
    Unit * unit = GetUnit(unitId);

    if (unit == NULL)
    {
        return FALSE;
    }

    unit->pPersonData = GetPersonByPidStr(pid);
    return TRUE;
}

EC BOOL UnitSetPos(EventEngine * unused, s32 id, s32 x, s32 y)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    if (unit->force->id >= 2)
    {
        return 0;
    }

    func_ov000_021a354c(unit, -1, -1);
    unit->xPos = x;
    unit->yPos = y;
    func_ov000_021a3498(unit, 0, -1, -1);
    func_ov000_021a36e0();

    return 1;
}

EC BOOL UnitMovePosEx(EventEngine * unused, s32 id, s32 x, s32 y, s32 flags)
{
    struct Unit * unit;
    MoveUnit * mu;
    u8 prev;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    if (unit->force->id >= 2)
    {
        return 0;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (mu != NULL)
    {
        func_ov000_021bb8ac(mu, 1);
    }

    prev = gMapStateManager->unk_08->unk_0874;
    gMapStateManager->unk_08->unk_0874 = unit->force->id;
    func_01ff8258(gMapStateManager->unk_08, unit->xPos, unit->yPos, unit->pJobData->unk_28, 100, 2);
    gMapStateManager->unk_08->unk_0874 = prev;

    if (gMapStateManager->unk_08->unk_0854[(u32)x | (u32)y << 5] < 0)
    {
        return 0;
    }

    if (gMapStateManager->unk_428[x | y << 5] != 0 || func_ov000_021bb5d4(gMapStateManager->unk_14->unk_00, x, y) != 0)
    {
        s32 dist = 100;
        s32 best;
        s32 by;
        s16 ix, iy;

        gMapStateManager->unk_08->unk_0854 = gMapStateManager->unk_08->unk_0c78;
        func_01ff8000(gMapStateManager->unk_08, x, y, unit->pJobData->unk_28, dist, 0);

        best = dist;
        x = best - 101;
        gMapStateManager->unk_08->unk_0854 = gMapStateManager->unk_08->unk_0878;

        for (iy = 0; iy < gMapStateManager->height; iy++)
        {
            for (ix = 0; ix < gMapStateManager->width; ix++)
            {
                s32 v = gMapStateManager->unk_08->unk_0878[ix | iy << 5];

                if (v >= 0 && (v = gMapStateManager->unk_08->unk_0c78[ix | iy << 5]) >= 0 && v < best &&
                    gMapStateManager->unk_428[ix | iy << 5] == 0 &&
                    func_ov000_021bb5d4(gMapStateManager->unk_14->unk_00, ix, iy) == 0)
                {
                    x = ix;
                    by = iy;
                    best = gMapStateManager->unk_08->unk_0c78[ix | iy << 5];
                }
            }
        }

        y = by;
    }

    func_02001ca0(gMapStateManager->unk_08, unit->xPos, unit->yPos, x, y);

    flags |= 0x40;
    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (mu == NULL)
    {
        mu = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);
        if (mu == NULL)
        {
            return 0;
        }
        func_ov000_021bb734(mu, unit, 1);
        unit->state2 |= US_NOT_PRESENT;
        mu->unk_68 = 0x1000;
        flags |= 0x8;
        func_ov000_021a354c(unit, -1, -1);
    }

    if (EventSkip::IsSkipState4())
    {
        func_ov000_021bc42c(mu, gMapStateManager->unk_08, flags);
        func_ov000_021a36e0();
    }
    else
    {
        func_ov000_021bc2b8(mu, gMapStateManager->unk_08, flags);
    }

    return 1;
}

EC BOOL UnitMoveRouteEx(EventEngine * unused, s32 id, s32 arg, s32 flags)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (mu != NULL)
    {
        func_ov000_021bb8ac(mu, 1);
    }

    func_02001cd0(gMapStateManager->unk_08, unit->xPos, unit->yPos, arg);

    flags |= 0x40;
    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (mu == NULL)
    {
        mu = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);
        if (mu == NULL)
        {
            return 0;
        }
        func_ov000_021bb734(mu, unit, 1);
        unit->state2 |= US_NOT_PRESENT;
        mu->unk_68 = 0x1000;
        flags |= 0x8;
    }

    if (EventSkip::IsSkipState4())
    {
        func_ov000_021bc42c(mu, gMapStateManager->unk_08, flags);
        func_ov000_021a36e0();
    }
    else
    {
        func_ov000_021bc2b8(mu, gMapStateManager->unk_08, flags);
    }

    return 1;
}

EC s32 UnitIsMove(void)
{
    return func_ov000_021bb248(gMapStateManager->unk_14->unk_00);
}

EC BOOL UnitIsMoveID(EventEngine * unused, s32 id)
{
    struct Unit * unit;
    MoveUnit * mu;
    u8 hasUnit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    hasUnit = (mu->pUnit != NULL) ? TRUE : FALSE;

    if (hasUnit == FALSE)
    {
        return 0;
    }

    switch (mu->CheckFlag1())
    {
        case FALSE:
            break;
        default:
            return FALSE;
    }

    return TRUE;
}

EC BOOL UnitMoveDelete(EventEngine * unused)
{
    func_ov000_021bb318(gMapStateManager->unk_14->unk_00);
    return TRUE;
}

EC BOOL UnitMoveDeleteID(EventEngine * unused, s32 id)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (mu)
    {
        func_ov000_021bb944(mu);
    }

    return TRUE;
}

EC BOOL UnitTransfer(EventEngine * unused, s32 id, s32 forceId)
{
    struct Unit * unit;
    MoveUnit * mu;
    s32 prevForce;
    s32 i;
    Item * item;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    prevForce = unit->force->id;

    if (gMapStateManager != NULL && prevForce < 2)
    {
        func_ov000_021bab40(gMapStateManager->unk_14->unk_00, unit);
    }

    if (forceId >= 2)
    {
        mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
        if (mu)
        {
            func_ov000_021bb944(mu);
        }
        func_ov000_021a354c(unit, -1, -1);
    }

    unit->MoveToForce(forceId, TRUE);
    unit->state2 &= ~(US_DANGER_ZONE_ACTIVE | US_UNK_14);

    item = unit->items;
    for (i = 0; i < UNIT_ITEM_COUNT; i++, item++)
    {
        item->flags &= ~ITEM_FLAG_DROPPABLE;
    }

    if (forceId < 2)
    {
        if (gMapStateManager != NULL)
        {
            BOOL skip = EventSkip::IsSkipState4() ? TRUE : FALSE;
            func_ov000_021baafc(gMapStateManager->unk_14->unk_00, unit, (u8)skip);
        }
    }
    else
    {
        if (unit == data_021974fc->unk_00)
        {
            data_021974fc->unk_00 = NULL;
        }
    }

    if (gMapStateManager != NULL && (prevForce < 2 || forceId < 2))
    {
        if (data_ov000_021e3324->fogActive != 0)
        {
            func_ov000_021a3c20(gMapStateManager->unk_db0, data_ov000_021e3324->phase, unit);
            func_ov000_021a3c20(gMapStateManager->unk_d30, data_ov000_021e3324->unk_01, unit);
            func_ov000_021a340c();
        }
        func_ov000_021a36e0();
    }

    return TRUE;
}

EC void func_0204453c(struct Unit * unit, s32 forceId)
{
    MoveUnit * mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (mu)
    {
        func_ov000_021bb944(mu);
    }

    if (gMapStateManager != NULL && unit->force->id < 2)
    {
        func_ov000_021bab40(gMapStateManager->unk_14->unk_00, unit);
    }

    if (unit->force->id < 2)
    {
        func_0204bf74();
    }

    func_ov000_021a354c(unit, -1, -1);
    unit->MoveToForce(forceId, TRUE);

    if (unit == data_021974fc->unk_00)
    {
        data_021974fc->unk_00 = NULL;
    }

    func_ov000_021a36e0();
}

EC BOOL UnitRemove(EventEngine * unused, s32 unitId)
{
    Unit * unit = GetUnit(unitId);
    s32 mode;

    if (unit == NULL)
    {
        return FALSE;
    }

    if (unit->force->id == 1)
    {
        mode = 4;
    }
    else if (unit->state2 & US_DEAD)
    {
        mode = 3;
    }
    else
    {
        mode = 2;
    }

    func_0204453c(unit, mode);
    return TRUE;
}

EC BOOL UnitRemoveMustErase(EventEngine * unused, s32 unitId)
{
    Unit * unit = GetUnit(unitId);

    if (unit == NULL)
    {
        return FALSE;
    }

    func_0204453c(unit, 4);
    return TRUE;
}

EC BOOL UnitSetDontAttack(EventEngine * unused, s32 unitId, char * str)
{
    Unit * unit = GetUnit(unitId);
    Unit_unk_a4 * res;

    if (unit == NULL)
    {
        return FALSE;
    }

    if (str != NULL && *str == 0)
    {
        str = NULL;
    }

    res = NULL;
    if (str != NULL)
    {
        res = (Unit_unk_a4 *)func_02037c9c(str);
    }

    unit->unk_a4 = res;
    return TRUE;
}

EC BOOL UnitSetDontMove(EventEngine * unused, s32 id, s32 flag)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    if (flag)
    {
        unit->state1 |= CA_UNK_27;
    }
    else
    {
        unit->state1 &= ~CA_UNK_27;
    }

    return TRUE;
}

EC BOOL UnitSetDontPosChange(EventEngine * unused, s32 id)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    unit->state2 |= US_UNK_10;
    return TRUE;
}

EC BOOL UnitSetFaceChange(EventEngine * unused, s32 id, s32 flag)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    if (flag)
    {
        unit->state1 |= CA_UNK_26;
    }
    else
    {
        unit->state1 &= ~CA_UNK_26;
    }

    return TRUE;
}

EC BOOL UnitSetAlpha(EventEngine * unused, s32 id, s32 alpha)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    if (alpha < 0 || alpha > 0x1f)
    {
        return 0;
    }

    unit->alpha = alpha;
    return 1;
}

EC BOOL UnitMoveAlpha(EventEngine * unused, s32 id, s32 a, s32 b, s32 c)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    if (a < 0 || a > 0x1f || b < 0 || b > 0x1f)
    {
        return 0;
    }

    if (EventSkip::IsSkipState4())
    {
        unit->alpha = b;
        return 1;
    }

    Proc_SetMark(StartMapEffectUnitAlpha(unit, a, b, c, PROC_TREE_9, 0), PROC_MARK_A);
    return 1;
}

EC BOOL UnitSetBelong(EventEngine * unused, s32 id, s32 belong)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    unit->belong = belong;
    return 1;
}

EC BOOL UnitSetDead(EventEngine * unused, s32 unitId)
{
    Unit * unit = GetUnit(unitId);

    if (unit == NULL)
    {
        return FALSE;
    }

    unit->state2 |= (US_DEAD | US_ITEMS_TO_CONVOY);
    return TRUE;
}

// FE11U = 0x02044974
EC BOOL SetUnitEventDead(EventEngine * unused, s32 unitId)
{
    struct Unit * unit;

    if (!unitId)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + unitId - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    unit->state2 |= (US_DEAD | US_ITEMS_TO_CONVOY | US_EVENT_DEAD);
    return TRUE;
}
EC BOOL UnitEffectDead(EventEngine * unused, s32 unitId)
{
    Unit * unit = GetUnit(unitId);

    if (unit == NULL)
    {
        return FALSE;
    }

    if (EventSkip::IsSkipState4())
    {
        unit->alpha = 0;
        return TRUE;
    }

    Proc_SetMark(func_ov000_021d3b00(unit, PROC_TREE_9, 0, 1), PROC_MARK_A);
    return TRUE;
}

EC void UnitIsEffectDead(void)
{
    IsMapEffectUnitAlphaActive();
    return;
}

EC BOOL UnitEffectWarpEscape(EventEngine * unused, s32 id)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    if (EventSkip::IsSkipState4())
    {
        unit->alpha = 0;
        return TRUE;
    }

    Proc_SetMark(func_ov000_021d3bfc(unit, PROC_TREE_9, 0), PROC_MARK_A);
    return TRUE;
}

EC BOOL UnitEffectWarpAppearance(EventEngine * unused, s32 id)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    if (EventSkip::IsSkipState4())
    {
        unit->alpha = 31;
        return TRUE;
    }

    Proc_SetMark(func_ov000_021d3cec(unit, PROC_TREE_9, 0), PROC_MARK_A);
    return TRUE;
}

EC s32 UnitIsEffectWarp(void)
{
    return func_ov000_021d3dfc();
}

EC BOOL UnitDragonTransform(EventEngine * self, s32 unitId, char * jid)
{
    Unit * unit = GetUnit(unitId);
    JobData * job = GetJobByJidStr(jid);

    if (unit == NULL)
    {
        return FALSE;
    }

    if (EventSkip::IsSkipState4())
    {
        func_ov000_021bab40(gMapStateManager->unk_14->unk_00, unit);
        unit->pJobData = job;
        unit->state2 &= ~US_UNK_30;
        func_ov000_021baafc(gMapStateManager->unk_14->unk_00, unit, 0);
        return FALSE;
    }

    Proc_SetMark(func_ov000_021ccaf8(unit, job, Event::GetRunningEvent()), PROC_MARK_A);
    self->unk_1c = 1;
    return FALSE;
}

EC BOOL MotionBegin(EventEngine * unused, s32 id)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    if (func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit) != NULL)
    {
        return TRUE;
    }

    mu = func_ov000_021bb4c8(gMapStateManager->unk_14->unk_00);
    if (mu == NULL)
    {
        return FALSE;
    }

    if (unit->force->id >= 2)
    {
        return FALSE;
    }

    func_ov000_021bb734(mu, unit, TRUE);

    mu->flags |= 0x2000;
    unit->state2 |= US_NOT_PRESENT;
    mu->unk_68 = 0x1000;
    mu->SetFacingDirection(0);

    func_ov000_021a354c(unit, -1, -1);

    return TRUE;
}

EC BOOL MotionSetAction(EventEngine * unused, s32 id, s32 action)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (!mu)
    {
        return FALSE;
    }

    mu->SetFacingDirection(action);

    switch (action)
    {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
            break;
        default:
            mu->pMovingMapSprite->timer = 0;
            break;
    }

    return TRUE;
}

EC BOOL MotionSetActionOnce(EventEngine * unused, s32 id, s32 dir)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (mu == NULL)
    {
        return FALSE;
    }

    if (EventSkip::IsSkipState4())
    {
        return TRUE;
    }

    mu->prevFacing = mu->facing;
    mu->facing = dir;
    mu->pMovingMapSprite->timer = 0;
    mu->flags |= 0x200;

    return TRUE;
}

EC BOOL MotionIsActionOnce(EventEngine * unused, s32 id)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);

    if (mu == NULL)
    {
        return 0;
    }

    return ((mu->flags & 0x200) != 0) & 0xFF;
}

EC BOOL MotionSetLoopOut(EventEngine * unused, s32 id, s32 dir)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);

    if (mu == NULL)
    {
        return 0;
    }

    if (EventSkip::IsSkipState4())
    {
        mu->facing = 0;

        if (mu->unk_61 != 0)
        {
            mu->unk_61 = 0;
            mu->unk_60 = -1;
        }

        return 1;
    }

    mu->unk_61 = gFE11Database->pJob[GetJobDBIndex(mu->pUnit->pJobData)].unk_4c;
    mu->unk_60 = GetAnimFrameCount(mu->facing) - 1;

    return 1;
}

EC BOOL MotionSetStasis(EventEngine * unused, s32 id, s32 on)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);

    if (mu == NULL)
    {
        return 0;
    }

    if (on != 0)
    {
        mu->flags |= 2;
        mu->pMovingMapSprite->timer = 0;
    }
    else
    {
        mu->flags &= ~2;
    }

    return 1;
}

EC BOOL MotionSetMoveSpeed(EventEngine * unused, s32 id, s32 speed)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (!mu)
    {
        return EventSkip::IsSkipState4() ? TRUE : FALSE;
    }

    if (!(mu->flags & 1) || mu->unk_5d == 0)
    {
        mu->unk_64 = speed;
    }

    return TRUE;
}

EC BOOL MotionSetMotionSpeed(EventEngine * unused, s32 id, s32 speed)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (!mu)
    {
        return EventSkip::IsSkipState4() ? TRUE : FALSE;
    }

    mu->pMovingMapSprite->func_0203f8a0(speed);
    return TRUE;
}

EC BOOL MotionSetFootStepRate(EventEngine * unused, s32 id, s32 rate)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (!mu)
    {
        return EventSkip::IsSkipState4() ? TRUE : FALSE;
    }

    mu->unk_66 = rate;
    return TRUE;
}

EC BOOL MotionEnd(EventEngine * unused, s32 id)
{
    struct Unit * unit;
    MoveUnit * mu;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return FALSE;
    }

    mu = func_ov000_021bb210(gMapStateManager->unk_14->unk_00, unit);
    if (mu == NULL)
    {
        return EventSkip::IsSkipState4() ? TRUE : FALSE;
    }

    func_ov000_021bb944(mu);
    return TRUE;
}

EC BOOL UnitStackPush(void)
{
    EventSkip::SkipTransition1To0();
    return TRUE;
}

EC BOOL UnitStackPop(void)
{
    EventSkip::SkipTransition1To0();
    return TRUE;
}

EC BOOL ForceUnitGetByPID(EventEngine * unused, s32 force, char * pid)
{
    Unit * unit = Force::Get(force)->FindByPidStr(pid);

    if (unit != NULL)
    {
        return unit->unk_68;
    }

    return FALSE;
}

EC BOOL ForceUnitSafetyGetByPID(EventEngine * unused, s32 force, char * pid)
{
    Unit * unit = Force::Get(force)->FindByPidStr(pid);

    if (unit != NULL)
    {
        return unit->unk_68;
    }

    return FALSE;
}

EC u8 ForceUnitGetFirst(EventEngine * unused, s32 force)
{
    Unit * unit = Force::Get(force)->head;

    if (unit != NULL)
    {
        return unit->unk_68;
    }

    return 0;
}

EC s32 ForceGetCount(EventEngine * unused, s32 force)
{
    return Force::Get(force)->Count();
}

EC BOOL TransporterCheckItem(EventEngine * unused, char * iid)
{
    ItemData * item = GetItemByIidStr(iid);
    s32 i;

    for (i = 0; i < 200; i++)
    {
        if (gConvoy[i].GetData() == item)
        {
            return TRUE;
        }
    }

    return FALSE;
}

EC BOOL TransporterOff(EventEngine * unused, s32 flag)
{
    if (flag)
    {
        data_02196f0c->state |= GAME_STATE_SUPPLY_OFF;
    }
    else
    {
        data_02196f0c->state &= ~GAME_STATE_SUPPLY_OFF;
    }

    return FALSE;
}

EC BOOL _ItemGet(EventEngine * self, s32 unitId, char * iidStr)
{
    Unit * unit = GetUnit(unitId);

    if (unit == NULL)
    {
        return FALSE;
    }

    if (func_ov000_021a8248() && unit->force->id != 0)
    {
        func_ov000_021c2ca0(unit, GetItemDBIndex(GetItemByIidStr(iidStr)));
    }
    else
    {
        s32 idx = GetItemDBIndex(GetItemByIidStr(iidStr));
        func_ov000_021c2c38(unit, idx, Event::GetRunningEvent());
        self->unk_1c = 1;
    }

    return FALSE;
}

EC s32 _MoneyGet(EventEngine * self, s32 amount)
{
    func_ov000_021c2cc8(amount, Event::GetRunningEvent());
    self->unk_1c = 1;
    return 0;
}

EC s32 MoneyGetSilent(EventEngine * unused, s32 amount)
{
    if (data_02196f20->unk_190 + amount > 999999)
    {
        data_02196f20->unk_190 = 999999;
    }
    else
    {
        data_02196f20->unk_190 += amount;
    }
    return 0;
}

EC BOOL Goods_02045418(EventEngine * unused, char * iid)
{
    func_020563a8(GetItemByIidStr(iid), 0);
    return 0;
}

EC s32 GoodsLimit(EventEngine * unused, char * iidStr, s32 count)
{
    func_020563a8(GetItemByIidStr(iidStr), count);
    return 0;
}

EC BOOL SetInvisible(EventEngine * unused, s32 flag)
{
    data_ov000_021e3324->fogActive = flag;

    if (gMapStateManager != NULL)
    {
        func_ov000_021a37c4();
        func_ov000_021a340c();
        func_ov000_021a35a0();
    }

    return TRUE;
}

EC u32 IsInvisible(void)
{
    return data_ov000_021e3324->fogActive;
}

EC BOOL IsInvisiblePlay(void)
{
    return (data_02196f0c->state & GAME_STATE_UNK_4) != 0;
}

EC BOOL SetLimitTime(EventEngine * unused, s32 time)
{
    data_ov000_021e3324->timeLimit = time * 60;
    return FALSE;
}

EC BOOL SetLimitTurn(EventEngine * unused, s32 turn)
{
    data_ov000_021e3324->turnLimit = turn;
    return 0;
}

EC BOOL SetArena(EventEngine * unused, s32 flag)
{
    if (flag)
    {
        data_02196f0c->state |= GAME_STATE_LINK_ARENA;
    }
    else
    {
        data_02196f0c->state &= ~GAME_STATE_LINK_ARENA;
    }

    return FALSE;
}

EC s32 MindGetUnit(void)
{
    return gActionSt->unitId;
}

EC u32 MindGetMind(void)
{
    return gActionSt->actionId;
}

EC s32 MindGetX(void)
{
    return gActionSt->xDecision;
}

EC s32 MindGetY(void)
{
    return gActionSt->yDecision;
}

EC u32 MindGetPhase(void)
{
    return data_ov000_021e3324->phase;
}

EC BOOL _TTEnable(EventEngine * self, s32 x, s32 y, s32 arg)
{
    s32 tt;
    Event * ev;

    tt = func_ov000_021d4968(x, y, arg);
    if (!tt)
    {
        return FALSE;
    }

    if (EventSkip::IsSkipState4())
    {
        ev = NULL;
    }
    else
    {
        ev = Event::GetRunningEvent();
    }

    if (IsFadeActive() == 0)
    {
        if (func_0201bce4() == 1)
        {
            ev = NULL;
        }
    }

    func_ov000_021d4bec(tt, ev);

    if (gMapStateManager->unk_04->pUnit == NULL && (arg == 5 || arg == 7))
    {
        func_ov000_021a36e0();
    }

    if (ev != NULL && ev->proc_lockCnt != 0)
    {
        self->unk_1c = 1;
    }

    return FALSE;
}

EC BOOL _TTDone(EventEngine * self, s32 x, s32 y, s32 arg)
{
    s32 tt;
    Event * ev;
    s16 ix;
    s16 iy;
    s16 xMin;
    s16 yMin;
    s16 xMax;
    s16 yMax;
    s32 row;

    tt = func_ov000_021d4968(x, y, arg);
    if (!tt)
    {
        return FALSE;
    }

    if (EventSkip::IsSkipState4())
    {
        ev = NULL;
    }
    else
    {
        ev = Event::GetRunningEvent();
    }

    if (IsFadeActive() == 0)
    {
        if (func_0201bce4() == 1)
        {
            ev = NULL;
        }
    }

    func_ov000_021d4cb4(tt, ev);

    if (arg == 5)
    {
        xMin = MAX(x - 1, gMapStateManager->unk_24);
        yMin = MAX(y - 1, gMapStateManager->unk_25);
        xMax = MIN(x + 1, gMapStateManager->unk_26 - 1);
        yMax = MIN(y + 1, gMapStateManager->unk_27 - 1);

        for (iy = yMin; iy <= yMax; iy++)
        {
            row = iy << 5;
            for (ix = xMin; ix <= xMax; ix++)
            {
                s32 dy = (y - iy) < 0 ? -(y - iy) : (y - iy);
                s32 dx = ABS(x - ix);

                if (dx + dy >= 1 && dx + dy <= 1)
                {
                    u8 v = gMapStateManager->unk_82c[ix | row];

                    if ((u8)(v & 0x80))
                    {
                        func_ov000_021d4e44(v & 0x7f, ev);
                    }
                }
            }
        }
    }

    if (gMapStateManager->unk_04->pUnit == NULL)
    {
        if (arg == 5 || arg == 7)
        {
            func_ov000_021a36e0();
        }
    }

    if (ev != NULL && ev->proc_lockCnt != 0)
    {
        self->unk_1c = 1;
    }

    return FALSE;
}

EC BOOL _TTDestroy(EventEngine * self, s32 x, s32 y, s32 arg)
{
    s32 tt = func_ov000_021d4968(x, y, arg);
    Event * ev;

    if (!tt)
    {
        return FALSE;
    }

    if (EventSkip::IsSkipState4())
    {
        ev = NULL;
    }
    else
    {
        ev = Event::GetRunningEvent();
    }

    if (IsFadeActive() == 0)
    {
        if (func_0201bce4() == 1)
        {
            ev = NULL;
        }
    }

    func_ov000_021d4d80(tt, ev, FALSE);

    if (ev != NULL && ev->proc_lockCnt != 0)
    {
        self->unk_1c = 1;
    }

    return FALSE;
}

EC BOOL TTIsEnable(EventEngine * unused, s32 x, s32 y, s32 arg)
{
    UnkStruct_Func_ov000_021d4968_Ret * tt = (UnkStruct_Func_ov000_021d4968_Ret *)func_ov000_021d4968(x, y, arg);

    if (!tt)
    {
        return FALSE;
    }

    if (tt->unk_07 & 3)
    {
        return FALSE;
    }

    return TRUE;
}

EC BOOL _RoofOpen(EventEngine * self, s32 x, s32 y)
{
    Event * ev;
    u8 tile;

    if (EventSkip::IsSkipState4())
    {
        ev = NULL;
    }
    else
    {
        ev = Event::GetRunningEvent();
    }

    if (IsFadeActive() == 0)
    {
        if (func_0201bce4() == 1)
        {
            ev = NULL;
        }
    }

    tile = gMapStateManager->unk_82c[x | y << 5];

    if ((u8)(tile & 0x80))
    {
        func_ov000_021d4e44(tile & 0x7f, ev);
    }
    else
    {
        return FALSE;
    }

    if (gMapStateManager->unk_04->pUnit == NULL)
    {
        func_ov000_021a36e0();
    }

    if (ev != NULL && ev->proc_lockCnt != 0)
    {
        self->unk_1c = 1;
    }

    return FALSE;
}

EC BOOL CastleSet(EventEngine * unused, s32 chapter)
{
    func_ov000_021d5084(chapter);
    return FALSE;
}

EC BOOL CastleClr(void)
{
    func_ov000_021d5084(-1);
    return FALSE;
}

EC void func_020459e4(s32 a, s32 * b, s32 * c)
{
    *b = a ? 0x1f : 0;
    *c = 0x10;

    if (!EventSkip::IsSkipState4())
    {
        if (IsFadeActive())
        {
            return;
        }

        if (func_0201bce4() != 1)
        {
            return;
        }
    }

    *c = 0;
}

EC BOOL BaseEffectShow(EventEngine * unused, s32 arg)
{
    s32 x;
    s32 y;
    struct Proc * proc;

    func_020459e4(arg, &x, &y);
    proc = func_ov000_021d4168(x, y, 0);
    if (proc)
    {
        Proc_SetMark(proc, PROC_MARK_A);
    }
    return FALSE;
}

EC BOOL PointSaveShow(EventEngine * unused, s32 arg)
{
    s32 x;
    s32 y;
    struct Proc * proc;

    func_020459e4(arg, &x, &y);
    proc = func_ov000_021d420c(x, y, 0);
    if (proc)
    {
        Proc_SetMark(proc, PROC_MARK_A);
    }
    return FALSE;
}

EC BOOL HpGaugeShow(EventEngine * unused, s32 arg)
{
    s32 x;
    s32 y;
    struct Proc * proc;

    func_020459e4(arg, &x, &y);
    proc = func_ov000_021d42b0(x, y, 0);
    if (proc)
    {
        Proc_SetMark(proc, PROC_MARK_A);
    }
    return FALSE;
}

EC BOOL BattleIsKiribat(void)
{
    return func_ov002_021ef17c() != 0;
}

EC void BattleIsTriangle(void)
{
    func_ov000_021ccc0c();
    return;
}

EC BOOL Quake_02045b24(EventEngine * unused, s32 arg)
{
    if (EventSkip::IsSkipState4() && arg != -1)
    {
        return TRUE;
    }

    struct Proc * proc = StartMapEffectQuake(arg, PROC_TREE_9, 0);

    if (arg != -1)
    {
        Proc_SetMark(proc, PROC_MARK_A);
    }

    return TRUE;
}

EC BOOL QuakeEnd(void)
{
    EventSkip::SkipTransition1To0();
    return TRUE;
}

EC BOOL CpuSetSeq(EventEngine * unused, s32 id, s32 idx, s32 seq, s32 arg)
{
    struct Unit * unit;
    CpuSeqData * data;
    s32 i;
    s32 val;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    data = func_02002180(seq);

    if (data == NULL)
    {
        return 0;
    }

    unit->unk_0c[idx] = data->unk_04;
    val = arg;

    for (i = 0; i < 4; i++)
    {
        val = func_0200218c(&unit->unk_10[idx * 4 + i], val);
    }

    return 1;
}

EC BOOL CpuSetActive(EventEngine * unused, s32 id, s32 active)
{
    struct Unit * unit;

    if (!id)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + id - 1;
    }

    if (!unit)
    {
        return 0;
    }

    unit->unk_05 = active;
    return 1;
}

EC BOOL TalkEvent(EventEngine * self, char * arg)
{
    func_0204a5d8(arg, Event::GetRunningEvent(), 0, 0);
    self->unk_1c = 1;
    return 0;
}

EC BOOL TalkEventPict(EventEngine * self, char * arg, s32 arg2)
{
    func_0204a620(arg, arg2, Event::GetRunningEvent(), 0);
    self->unk_1c = 1;
    return 0;
}

EC BOOL TalkEventBright(EventEngine * self, char * arg, s32 arg2)
{
    func_0204a5d8(arg, Event::GetRunningEvent(), 0, arg2);
    self->unk_1c = 1;
    return 0;
}

EC BOOL TalkEventFadeOut(EventEngine * self, char * arg)
{
    func_0204a5d8(arg, Event::GetRunningEvent(), 1, 0);
    self->unk_1c = 1;
    return 0;
}

EC BOOL TalkEventBrightFadeOut(EventEngine * self, char * arg, s32 b)
{
    func_0204a5d8(arg, Event::GetRunningEvent(), 1, b);
    self->unk_1c = 1;
    return 0;
}

EC BOOL _PictSet(EventEngine * unused, s32 arg)
{
    func_0204a944(arg, 0);
    return FALSE;
}

EC BOOL RecollectionSet(EventEngine * unused, s32 flagId)
{
    data_02196f1c->flagMgr->SetById(flagId);
    return FALSE;
}

EC BOOL SubInfoClear(void)
{
    data_021974fc->unk_00 = NULL;
    data_021974fc->unk_08 = 0;

    if (((data_020d6254 >= 0) ? TRUE : FALSE) & 0xFF)
    {
        if ((data_021974fc != NULL ? data_021974fc->unk_12 : 0) & 0xFF)
        {
            func_0204ac64();
        }
        else
        {
            StartProcTutCardMaybe(-1, -1);
        }
    }
    else
    {
        if (!((data_021974fc != NULL ? data_021974fc->unk_11 : 0) & 0xFF))
        {
            func_0204e2d0(1);
            func_0204eb24();
            func_0204bbb4(0);
        }
    }

    return FALSE;
}

EC BOOL _TutCardSet(EventEngine * self, s32 arg)
{
    if (data_02196f24->enableTutorials != 0)
    {
        if (StartProcTutCardMaybe(arg, 1) != 0 && !EventSkip::IsSkipState4())
        {
            gSoundManager->unk_b0->vfunc_28(SE_SYS_TUTORIAL1, 0, 0);
        }
    }

    data_02196f20->flagMgr->SetById(arg);

    if (EventCaller::func_02047990() == 0)
    {
        self->unk_1c = 1;
    }

    return FALSE;
}

EC BOOL _TutCardSetKeyTouch(EventEngine * self, s32 a, s32 b)
{
    data_02196f20->flagMgr->SetById(a);
    data_02196f20->flagMgr->SetById(b);
    if (!func_ov000_021d6ed4())
    {
        b = a;
    }
    return _TutCardSet(self, b);
}

EC BOOL _TutCardClr(EventEngine * self)
{
    if (func_0204b1f8(0))
    {
        if (data_ov000_021e3320[data_ov000_021e3324->phase] == 2)
        {
            func_0204ae60(1, 0);
            func_0204b260(2);
        }
        else
        {
            func_0204b260(0);
        }
    }
    if (!EventCaller::func_02047990())
    {
        self->unk_1c = 1;
    }
    return FALSE;
}

EC BOOL TutFlagSet(EventEngine * unused, s32 id)
{
    data_02196f20->flagMgr->SetById(id);
    return FALSE;
}

EC BOOL TutFlagGet(EventEngine * unused, s32 id)
{
    return data_02196f20->flagMgr->GetById(id) ? TRUE : FALSE;
}

EC BOOL TutFlagSetAll(void)
{
    s32 i;

    for (i = 0; i < 0x22; i++)
    {
        data_02196f20->flagMgr->SetById(i);
    }

    return FALSE;
}

EC BOOL _TutIsBusy(void)
{
    if (EventCaller::func_02047990())
    {
        return FALSE;
    }
    return IsProcTutCardActive();
}

EC BOOL TutHelpSet(EventEngine * unused, s32 idx, s32 val)
{
    u8 v = val;
    u32 j = (idx << 1) + 1;
    u32 k = idx << 1;
    data_ov000_021e3324->unk_18[k] = v;
    data_ov000_021e3324->unk_18[j] = v;
    return FALSE;
}

EC BOOL TutHelpSetKeyTouch(EventEngine * unused, s32 idx, u8 key, u8 touch)
{
    u32 j = (idx << 1) + 1;
    data_ov000_021e3324->unk_18[idx << 1] = key;
    data_ov000_021e3324->unk_18[j] = touch;
    return FALSE;
}

EC u8 IsTutorial(void)
{
    return data_02196f24->enableTutorials;
}

EC BOOL CursorPut(EventEngine * unused, s32 x, s32 y)
{
    func_ov000_021d4004(x, y);
    return FALSE;
}

EC BOOL CursorDelete(EventEngine * unused)
{
    func_ov000_021d4094();
    return FALSE;
}

EC BOOL MenuHide(EventEngine * unused, s32 bit)
{
    data_ov000_021e3324->unk_1c |= 1 << bit;
    return FALSE;
}

EC BOOL MenuShow(EventEngine * unused, s32 bit)
{
    data_ov000_021e3324->unk_1c &= (-1 ^ (1 << bit));
    return FALSE;
}

EC BOOL DangerAllSet(EventEngine * unused, s32 value)
{
    data_ov000_021e3324->unk_03 = value;
    func_ov000_021a36e0();
    return 0;
}

EC BOOL IsReplenish(void)
{
    return (data_02196f0c->state & GAME_STATE_UNK_17) != 0;
}

EC BOOL _Dialog_02046168(EventEngine * self, char * arg)
{
    func_02014834(Event::GetRunningEvent(), GetText(arg), 1, 1, 0, 1);
    self->unk_1c = 1;
    return FALSE;
}

EC BOOL IncRound(EventEngine * self)
{
    func_0202518c(self);
    return FALSE;
}

EC BOOL LeaveScriptFadeIn(void)
{
    data_02196f0c->state |= GAME_STATE_UNK_8;
    return FALSE;
}

EC BOOL LeaveScriptScroll(void)
{
    data_02196f0c->state |= GAME_STATE_UNK_9;
    return FALSE;
}

EC BOOL NearVictoryOff(EventEngine * unused, s32 flag)
{
    if (flag)
    {
        data_02196f0c->state |= GAME_STATE_UNK_10;
    }
    else
    {
        data_02196f0c->state &= ~GAME_STATE_UNK_10;
    }
    return FALSE;
}

EC void RegisterEventFunctions(void)
{
    func_02035c08("Arg", (void *)func_020424f4, 1);
    func_02035c08("FlagRegistGrobal", (void *)FlagRegistGrobal, 1);
    func_02035c08("FlagRegist", (void *)FlagRegist, 1);
    func_02035c08("FlagGet", (void *)FlagGet, 1);
    func_02035c08("FlagSet", (void *)FlagSet, 1);
    func_02035c08("FlagClr", (void *)FlagClr, 1);
    func_02035c08("ValueRegistGrobal", (void *)ValueRegistGrobal, 1);
    func_02035c08("ValueRegist", (void *)ValueRegist, 1);
    func_02035c08("ValueGet", (void *)ValueGet, 1);
    func_02035c08("ValueSet", (void *)ValueSet, 2);
    func_02035c08("Random", (void *)Random_02042634, 0);
    func_02035c08("RandomMinMax", (void *)RandomMinMax, 2);
    func_02035c08("SkipExec", (void *)SkipExec, 0);
    func_02035c08("SkipEscape", (void *)SkipEscape, 0);
    func_02035c08("SkipEnable", (void *)SkipEnable, 0);
    func_02035c08("_SkipDisable", (void *)func_020426b4, 0);
    func_02035c08("IsSkip", (void *)IsSkip, 0);
    func_02035c08("IsSkipDisable", (void *)IsSkipDisable, 0);
    func_02035c08("IsSkipCpu", (void *)IsSkipCpu, 0);
    func_02035c08("SkipGameMap", (void *)SkipGameMap, 0);
    func_02035c08("SkipSaveMenu", (void *)SkipSaveMenu, 0);
    func_02035c08("JumpToEnding", (void *)JumpToEnding, 0);
    func_02035c08("FadeIn", (void *)FadeIn, 1);
    func_02035c08("FadeInSub", (void *)FadeInSub, 1);
    func_02035c08("FadeInDual", (void *)FadeInDual, 1);
    func_02035c08("FadeOut", (void *)FadeOut, 1);
    func_02035c08("FadeOutSub", (void *)FadeOutSub, 1);
    func_02035c08("FadeOutDual", (void *)FadeOutDual, 1);
    func_02035c08("FadeOutWhite", (void *)FadeOutWhite, 1);
    func_02035c08("FadeOutWhiteSub", (void *)FadeOutWhiteSub, 1);
    func_02035c08("FadeOutWhiteDual", (void *)FadeOutWhiteDual, 1);
    func_02035c08("IsFade", (void *)IsFade, 0);
    func_02035c08("SoundIsAsync", (void *)SoundIsAsync, 0);
    func_02035c08("BGMPlay", (void *)BGMPlay, 1);
    func_02035c08("BGMPlayF", (void *)BGMPlayF, 2);
    func_02035c08("BGMStop", (void *)BGMStop, 1);
    func_02035c08("BGMPausePlay", (void *)BGMPausePlay, 1);
    func_02035c08("BGMPausePlayF", (void *)BGMPausePlayF, 2);
    func_02035c08("BGMPauseStop", (void *)BGMPauseStop, 1);
    func_02035c08("BGMPlayPause", (void *)BGMPlayPause, 1);
    func_02035c08("_BGMVolume", (void *)_BGMVolume, 1);
    func_02035c08("_BGMVolumeF", (void *)_BGMVolumeF, 2);
    func_02035c08("_BGMBtlVolume", (void *)_BGMBtlVolume, 1);
    func_02035c08("_BGMBtlVolumeF", (void *)_BGMBtlVolumeF, 2);
    func_02035c08("BGMIsFade", (void *)BGMIsFade, 0);
    func_02035c08("SEPlay", (void *)SEPlay, 1);
    func_02035c08("LoopSEPlay", (void *)LoopSEPlay, 1);
    func_02035c08("LoopSEStop", (void *)LoopSEStop, 1);
    func_02035c08("SEIsPlay", (void *)SEIsPlay, 1);
    func_02035c08("MapLoad", (void *)MapLoad, 0);
    func_02035c08("MapLoadD", (void *)MapLoadD, 1);
    func_02035c08("MapFree", (void *)MapFree, 0);
    func_02035c08("Dispos", (void *)Dispos_02043358, 1);
    func_02035c08("DisposPlayArea", (void *)DisposPlayArea, 1);
    func_02035c08("DisposMoment", (void *)DisposMoment, 1);
    func_02035c08("IsDispos", (void *)IsDispos, 0);
    func_02035c08("DisposWithScroll", (void *)DisposWithScroll, 1);
    func_02035c08("DisposWithScrollView", (void *)DisposWithScrollView, 1);
    func_02035c08("DisposPlayAreaWithScrollView", (void *)DisposPlayAreaWithScrollView, 1);
    func_02035c08("SetChapter", (void *)SetChapter, 1);
    func_02035c08("AddChapter", (void *)AddChapter, 0);
    func_02035c08("Scroll", (void *)Scroll_020434c0, 2);
    func_02035c08("ScrollEx", (void *)ScrollEx_0204353c, 4);
    func_02035c08("ScrollMoment", (void *)ScrollMoment, 2);
    func_02035c08("ScrollCenter", (void *)ScrollCenter, 2);
    func_02035c08("ScrollCenterEx", (void *)ScrollCenterEx, 3);
    func_02035c08("ScrollCenterMoment", (void *)ScrollCenterMoment, 2);
    func_02035c08("IsScroll", (void *)IsScroll, 0);
    func_02035c08("IsAccel", (void *)IsAccel, 0);
    func_02035c08("MapGetW", (void *)MapGetW, 0);
    func_02035c08("MapGetH", (void *)MapGetH, 0);
    func_02035c08("UnitGetByPID", (void *)UnitGetByPID, 1);
    func_02035c08("UnitSafetyGetByPID", (void *)UnitSafetyGetByPID, 1);
    func_02035c08("UnitGetByPos", (void *)UnitGetByPos, 2);
    func_02035c08("UnitSafetyGetByPos", (void *)UnitSafetyGetByPos, 2);
    func_02035c08("UnitGetHero", (void *)UnitGetHero, 0);
    func_02035c08("UnitGetNext", (void *)UnitGetNext, 1);
    func_02035c08("UnitGetX", (void *)UnitGetX, 1);
    func_02035c08("UnitGetY", (void *)UnitGetY, 1);
    func_02035c08("UnitGetForce", (void *)UnitGetForce, 1);
    func_02035c08("UnitCheckPID", (void *)UnitCheckPID, 2);
    func_02035c08("UnitCheckJID", (void *)UnitCheckJID, 2);
    func_02035c08("UnitCheckItem", (void *)UnitCheckItem, 2);
    func_02035c08("UnitCheckDead", (void *)UnitCheckDead, 1);
    func_02035c08("UnitSetItemAdd", (void *)UnitSetItemAdd, 3);
    func_02035c08("UnitSetItemPutOff", (void *)UnitSetItemPutOff, 2);
    func_02035c08("UnitSetItemPutOffAll", (void *)UnitSetItemPutOffAll, 1);
    func_02035c08("UnitSetPID", (void *)UnitSetPID, 2);
    func_02035c08("UnitSetPos", (void *)UnitSetPos, 3);
    func_02035c08("UnitMovePosEx", (void *)UnitMovePosEx, 4);
    func_02035c08("UnitMoveRouteEx", (void *)UnitMoveRouteEx, 3);
    func_02035c08("UnitIsMove", (void *)UnitIsMove, 0);
    func_02035c08("UnitIsMoveID", (void *)UnitIsMoveID, 1);
    func_02035c08("UnitMoveDelete", (void *)UnitMoveDelete, 0);
    func_02035c08("UnitMoveDeleteID", (void *)UnitMoveDeleteID, 1);
    func_02035c08("UnitTransfer", (void *)UnitTransfer, 2);
    func_02035c08("UnitRemove", (void *)UnitRemove, 1);
    func_02035c08("UnitRemoveMustErase", (void *)UnitRemoveMustErase, 1);
    func_02035c08("UnitSetDontAttack", (void *)UnitSetDontAttack, 2);
    func_02035c08("UnitSetDontMove", (void *)UnitSetDontMove, 2);
    func_02035c08("UnitSetDontPosChange", (void *)UnitSetDontPosChange, 1);
    func_02035c08("UnitSetFaceChange", (void *)UnitSetFaceChange, 2);
    func_02035c08("UnitSetAlpha", (void *)UnitSetAlpha, 2);
    func_02035c08("UnitMoveAlpha", (void *)UnitMoveAlpha, 4);
    func_02035c08("UnitSetBelong", (void *)UnitSetBelong, 2);
    func_02035c08("UnitSetDead", (void *)UnitSetDead, 1);
    func_02035c08("SetUnitEventDead", (void *)SetUnitEventDead, 1);
    func_02035c08("UnitEffectDead", (void *)UnitEffectDead, 1);
    func_02035c08("UnitIsEffectDead", (void *)UnitIsEffectDead, 0);
    func_02035c08("UnitEffectWarpEscape", (void *)UnitEffectWarpEscape, 1);
    func_02035c08("UnitEffectWarpAppearance", (void *)UnitEffectWarpAppearance, 1);
    func_02035c08("UnitIsEffectWarp", (void *)UnitIsEffectWarp, 0);
    func_02035c08("UnitDragonTransform", (void *)UnitDragonTransform, 2);
    func_02035c08("MotionBegin", (void *)MotionBegin, 1);
    func_02035c08("MotionSetAction", (void *)MotionSetAction, 2);
    func_02035c08("MotionSetActionOnce", (void *)MotionSetActionOnce, 2);
    func_02035c08("MotionIsActionOnce", (void *)MotionIsActionOnce, 1);
    func_02035c08("MotionSetLoopOut", (void *)MotionSetLoopOut, 1);
    func_02035c08("MotionSetStasis", (void *)MotionSetStasis, 2);
    func_02035c08("MotionSetMoveSpeed", (void *)MotionSetMoveSpeed, 2);
    func_02035c08("MotionSetMotionSpeed", (void *)MotionSetMotionSpeed, 2);
    func_02035c08("MotionSetFootStepRate", (void *)MotionSetFootStepRate, 2);
    func_02035c08("MotionEnd", (void *)MotionEnd, 1);
    func_02035c08("UnitStackPush", (void *)UnitStackPush, 0);
    func_02035c08("UnitStackPop", (void *)UnitStackPop, 0);
    func_02035c08("ForceUnitGetByPID", (void *)ForceUnitGetByPID, 2);
    func_02035c08("ForceUnitSafetyGetByPID", (void *)ForceUnitSafetyGetByPID, 2);
    func_02035c08("ForceUnitGetFirst", (void *)ForceUnitGetFirst, 1);
    func_02035c08("ForceGetCount", (void *)ForceGetCount, 1);
    func_02035c08("TransporterCheckItem", (void *)TransporterCheckItem, 1);
    func_02035c08("TransporterOff", (void *)TransporterOff, 1);
    func_02035c08("_ItemGet", (void *)_ItemGet, 2);
    func_02035c08("_MoneyGet", (void *)_MoneyGet, 1);
    func_02035c08("MoneyGetSilent", (void *)MoneyGetSilent, 1);
    func_02035c08("Goods", (void *)Goods_02045418, 1);
    func_02035c08("GoodsLimit", (void *)GoodsLimit, 2);
    func_02035c08("SetInvisible", (void *)SetInvisible, 1);
    func_02035c08("IsInvisible", (void *)IsInvisible, 0);
    func_02035c08("IsInvisiblePlay", (void *)IsInvisiblePlay, 0);
    func_02035c08("SetLimitTime", (void *)SetLimitTime, 1);
    func_02035c08("SetLimitTurn", (void *)SetLimitTurn, 1);
    func_02035c08("SetArena", (void *)SetArena, 1);
    func_02035c08("MindGetUnit", (void *)MindGetUnit, 0);
    func_02035c08("MindGetMind", (void *)MindGetMind, 0);
    func_02035c08("MindGetX", (void *)MindGetX, 0);
    func_02035c08("MindGetY", (void *)MindGetY, 0);
    func_02035c08("MindGetPhase", (void *)MindGetPhase, 0);
    func_02035c08("_TTEnable", (void *)_TTEnable, 3);
    func_02035c08("_TTDone", (void *)_TTDone, 3);
    func_02035c08("_TTDestroy", (void *)_TTDestroy, 3);
    func_02035c08("TTIsEnable", (void *)TTIsEnable, 3);
    func_02035c08("_RoofOpen", (void *)_RoofOpen, 2);
    func_02035c08("CastleSet", (void *)CastleSet, 1);
    func_02035c08("CastleClr", (void *)CastleClr, 0);
    func_02035c08("BaseEffectShow", (void *)BaseEffectShow, 1);
    func_02035c08("PointSaveShow", (void *)PointSaveShow, 1);
    func_02035c08("HpGaugeShow", (void *)HpGaugeShow, 1);
    func_02035c08("BattleIsKiribat", (void *)BattleIsKiribat, 0);
    func_02035c08("BattleIsTriangle", (void *)BattleIsTriangle, 0);
    func_02035c08("Quake", (void *)Quake_02045b24, 1);
    func_02035c08("QuakeEnd", (void *)QuakeEnd, 0);
    func_02035c08("CpuSetSeq", (void *)CpuSetSeq, 4);
    func_02035c08("CpuSetActive", (void *)CpuSetActive, 2);
    func_02035c08("TalkEvent", (void *)TalkEvent, 1);
    func_02035c08("TalkEventPict", (void *)TalkEventPict, 2);
    func_02035c08("TalkEventBright", (void *)TalkEventBright, 2);
    func_02035c08("TalkEventFadeOut", (void *)TalkEventFadeOut, 1);
    func_02035c08("TalkEventBrightFadeOut", (void *)TalkEventBrightFadeOut, 2);
    func_02035c08("_PictSet", (void *)_PictSet, 1);
    func_02035c08("RecollectionSet", (void *)RecollectionSet, 1);
    func_02035c08("SubInfoClear", (void *)SubInfoClear, 0);
    func_02035c08("_TutCardSet", (void *)_TutCardSet, 1);
    func_02035c08("_TutCardSetKeyTouch", (void *)_TutCardSetKeyTouch, 2);
    func_02035c08("_TutCardClr", (void *)_TutCardClr, 0);
    func_02035c08("TutFlagSet", (void *)TutFlagSet, 1);
    func_02035c08("TutFlagGet", (void *)TutFlagGet, 1);
    func_02035c08("TutFlagSetAll", (void *)TutFlagSetAll, 0);
    func_02035c08("_TutIsBusy", (void *)_TutIsBusy, 0);
    func_02035c08("TutHelpSet", (void *)TutHelpSet, 2);
    func_02035c08("TutHelpSetKeyTouch", (void *)TutHelpSetKeyTouch, 3);
    func_02035c08("IsTutorial", (void *)IsTutorial, 0);
    func_02035c08("CursorPut", (void *)CursorPut, 2);
    func_02035c08("CursorDelete", (void *)CursorDelete, 0);
    func_02035c08("MenuHide", (void *)MenuHide, 1);
    func_02035c08("MenuShow", (void *)MenuShow, 1);
    func_02035c08("DangerAllSet", (void *)DangerAllSet, 1);
    func_02035c08("IsReplenish", (void *)IsReplenish, 0);
    func_02035c08("_Dialog", (void *)_Dialog_02046168, 1);
    func_02035c08("IncRound", (void *)IncRound, 0);
    func_02035c08("LeaveScriptFadeIn", (void *)LeaveScriptFadeIn, 0);
    func_02035c08("LeaveScriptScroll", (void *)LeaveScriptScroll, 0);
    func_02035c08("NearVictoryOff", (void *)NearVictoryOff, 1);
}

EC void func_02047450(void)
{
    RegisterEventFunctions();
    return;
}
