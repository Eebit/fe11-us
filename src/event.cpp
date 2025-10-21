#include "global.h"

#include <new>

#include "unknown_funcs.h"
#include "unknown_data.h"
#include "unknown_types.hpp"

#include "hardware.hpp"
#include "map.hpp"
#include "sound_manager.hpp"

#include "event.hpp"

inline BOOL Skip::CheckSkipStateVarious(void)
{
    if (this->unk_06 == 5)
    {
        return TRUE;
    }
    else if (this->unk_06 == 6)
    {
        return TRUE;
    }
    else if (this->unk_06 == 7)
    {
        return TRUE;
    }
    else if (this->unk_06 == 8)
    {
        return TRUE;
    }

    return FALSE;
}

inline BOOL Skip::IsSkipState4(void)
{
    if (this->unk_06 == 4)
    {
        return TRUE;
    }

    return FALSE;
}

inline void Skip::SkipTransitionFrom2To0Or4To5(void)
{
    if (this->unk_06 == 2)
    {
        this->unk_06 = 0;
    }

    if (this->unk_06 == 4)
    {
        this->unk_06 = 5;
    }

    return;
}

inline void Skip::SkipTransition1To0(void)
{
    if (this->unk_06 == 1)
    {
        this->unk_06 = 0;
    }
}

inline void Skip::SkipTransition0Or2To1(void)
{
    if (this->unk_06 == 0 || this->unk_06 == 2)
    {
        this->unk_06 = 1;
    }

    return;
}

inline BOOL Skip::IsSkipState1(void)
{
    return this->unk_06 == 1 ? TRUE : FALSE;
}

void Event::func_0204745c(void)
{
    Proc_EndEachMarked(PROC_MARK_A);

    if (gMapStateManager != NULL)
    {
        gMapStateManager->camera->func_ov000_021a516c();
    }

    func_ov000_021db624();

    if (gMapStateManager != NULL)
    {
        func_ov000_021bb318(gMapStateManager->unk_14->unk_00);
    }

    return;
}

EC void Event_Loop(Event * proc)
{
    if (!data_021974e8.unk_00->CheckSkipStateVarious())
    {
        func_02035f20(&proc->unk_38);

        if ((proc->unk_44 ? TRUE : FALSE) != 0)
        {
            if (func_020357e8() == 6)
            {
                return;
            }
        }

        if (data_021974e8.unk_00->IsSkipState4())
        {
            if (func_ov000_021a8248() == 0)
            {
                data_021974e8.unk_00->SkipTransitionFrom2To0Or4To5();
            }
        }
        else
        {
            data_021974e8.unk_00->SkipTransition0Or2To1();

            if (func_ov000_021a8248() != 0)
            {
                func_ov000_021a81d4();
            }
        }

        Proc_Break(proc, 0);
    }

    return;
}

EC void Event_ProcCmd06(ProcPtr proc)
{
    data_021974e8.unk_00->func_02049024(proc);
    return;
}

BOOL Event::StartEventByInfo(struct EventInfo * arg_0, ProcPtr parent)
{
    new (func_01ffc030(ProcScr_Event, parent)) Event(arg_0);

    if (Proc_Find(ProcScr_Event) == NULL)
    {
        return FALSE;
    }

    return TRUE;
}

void Event::func_020476a0(void)
{
    data_021974e8.unk_00 = new EventSkip;
    data_021974e8.unk_00->Init();
    return;
}

BOOL Event::StartEventByName(char * arg_0, ProcPtr parent)
{
    new (func_01ffc030(ProcScr_Event, parent)) Event(arg_0);

    if (Proc_Find(ProcScr_Event) == NULL)
    {
        return FALSE;
    }

    return TRUE;
}

Event * Event::GetRunningEvent(void)
{
    return static_cast<Event *>(Proc_Find(ProcScr_Event));
}

void EventSkip::SkipTransitionFrom0To2(void)
{
    if (data_021974e8.unk_00->unk_06 == 0)
    {
        data_021974e8.unk_00->unk_06 = 2;
    }

    return;
}

void EventSkip::SkipTransitionFrom2To0Or4To5(void)
{
    data_021974e8.unk_00->SkipTransitionFrom2To0Or4To5();
    return;
}

void EventSkip::SkipTransition1To0(void)
{
    data_021974e8.unk_00->SkipTransition1To0();
    return;
}

void EventSkip::SkipTransition0Or2To1(void)
{
    data_021974e8.unk_00->SkipTransition0Or2To1();
    return;
}

BOOL EventSkip::IsSkipState4(void)
{
    return data_021974e8.unk_00->IsSkipState4();
}

BOOL EventSkip::func_0204789c(void)
{
    if (data_021974e8.unk_00->unk_06 == 4)
    {
        return FALSE;
    }

    if (data_021974e8.unk_00->unk_06 == 0)
    {
        return FALSE;
    }

    return data_021974e8.unk_00->IsSkipState1();
}

BOOL EventSkip::IsSkipState1(void)
{
    return data_021974e8.unk_00->IsSkipState1();
}

void EventSkip::SetUnk04(u32 arg_0)
{
    data_021974e8.unk_00->unk_04 = arg_0;
    return;
}

void EventSkip::SetUnk05(u32 arg_0)
{
    data_021974e8.unk_00->unk_05 = arg_0;
    return;
}

EC void EventCaller_Loop(EventCaller * proc)
{
    for (proc->unk_38 = func_02035b98(proc->unk_38); proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
    {
        if (proc->unk_38->kind != proc->unk_3c)
        {
            continue;
        }

        if (!proc->unk_40(proc->unk_38, &proc->unk_44))
        {
            continue;
        }

        if (Event::StartEventByInfo(proc->unk_38, proc))
        {
            return;
        }
    }

    Proc_End(proc);

    return;
}

BOOL EventCaller::func_02047990(void)
{
    if (Proc_Find(ProcScr_EventCaller) == NULL)
    {
        return TRUE;
    }

    return FALSE;
}

BOOL EventCaller::func_020479b0(void)
{
    if (Proc_Find(ProcScr_EventCaller) != NULL)
    {
        return TRUE;
    }

    if (Proc_Find(ProcScr_Event) != NULL)
    {
        return TRUE;
    }

    return FALSE;
}

BOOL EventCaller::CheckEventTrigger(s32 kind, EventFunc func, struct EventFuncInput * input)
{
    struct EventInfo * it;
    BOOL ret;

    for (it = func_02035b98(NULL); it != NULL; it = func_02035b98(it))
    {
        if (it->kind != kind)
        {
            continue;
        }

        ret = func(it, input);

        if (ret)
        {
            return ret;
        }
    }

    return FALSE;
}

s32 EventCaller::CountEventsByKind(s32 kind)
{
    struct EventInfo * it;

    s32 count = 0;

    for (it = func_02035b98(NULL); it != NULL; it = func_02035b98(it))
    {
        if (it->kind != kind)
        {
            continue;
        }

        count++;
    }

    return count;
}

BOOL EventCaller::CheckEventFlag(char * arg_0)
{
    s32 flag;

    if (arg_0 != NULL && *arg_0 != 0)
    {
        flag = data_02196f0c->flagMgr->FindIdByName(arg_0);

        if (flag >= 0)
        {
            if (data_02196f0c->flagMgr->GetById(flag))
            {
                return FALSE;
            }
        }
        else
        {
            if (func_020424b8(arg_0) == 0)
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

BOOL EventCaller::IsSamePerson(char * pidStrA, char * pidStrB)
{
    if (pidStrA == NULL || *pidStrA == 0)
    {
        return TRUE;
    }

    if (pidStrB == NULL || *pidStrB == 0)
    {
        return TRUE;
    }

    return GetPersonByPidStr(pidStrA) == GetPersonByPidStr(pidStrB);
}

BOOL EventCaller::func_02047b3c(char * arg_0, char * arg_1)
{
    if (arg_0 == NULL)
    {
        return TRUE;
    }

    if (arg_1 == NULL)
    {
        return TRUE;
    }

    return arg_0 == arg_1;
}

BOOL EventCaller::CheckTurnEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * unused)
{
    if ((arg_0->args[2] >= 0) && (arg_0->args[2] != data_ov000_021e3324->phase))
    {
        return FALSE;
    }

    if (arg_0->args[0] == 0)
    {
        return TRUE;
    }

    if (arg_0->args[0] > data_ov000_021e3324->turn)
    {
        return FALSE;
    }

    if (arg_0->args[1] < data_ov000_021e3324->turn)
    {
        return FALSE;
    }

    return TRUE;
}

BOOL EventCaller::TryStartTurnEvent(ProcPtr parent)
{
    if (!CheckEventTrigger(EVENT_KIND_03, CheckTurnEventTrigger, NULL))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_03, CheckTurnEventTrigger);
    return TRUE;
}

BOOL EventCaller::TryStartTurnEventAlt(ProcPtr parent)
{
    if (!CheckEventTrigger(EVENT_KIND_06, CheckTurnEventTrigger, NULL))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_06, CheckTurnEventTrigger);
    return TRUE;
}

BOOL EventCaller::CheckReinforcementEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * unused)
{
    if (arg_0->args[2] >= 0)
    {
        if (data_02196f20->unk_199 != 0)
        {
            if (arg_0->args[2] != data_ov000_021e3324->phase)
            {
                return FALSE;
            }
        }
        else if (data_ov000_021e3324->phase != 0)
        {
            return FALSE;
        }
    }

    if (arg_0->args[0] == 0)
    {
        return TRUE;
    }

    if (arg_0->args[0] > data_ov000_021e3324->turn)
    {
        return FALSE;
    }

    if (arg_0->args[1] < data_ov000_021e3324->turn)
    {
        return FALSE;
    }

    return TRUE;
}

BOOL EventCaller::TryStartReinforcementEvent(ProcPtr parent)
{
    if (!CheckEventTrigger(EVENT_KIND_17, CheckReinforcementEventTrigger, NULL))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_17, CheckReinforcementEventTrigger);
    return TRUE;
}

BOOL EventCaller::CheckVisitEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    if ((s32)arg_1->unk_00 >= 0)
    {
        if (arg_1->unk_00 != arg_0->args[0])
        {
            return FALSE;
        }
    }

    if ((s32)arg_1->unk_04 >= 0)
    {
        if (arg_1->unk_04 != arg_0->args[1])
        {
            return FALSE;
        }
    }

    if (arg_1->unk_08 != 0 && arg_1->unk_08 != arg_0->args[2])
    {
        return FALSE;
    }

    if (!CheckEventFlag(GetEventStr(arg_0, arg_0->args[3])))
    {
        return FALSE;
    }

    return arg_0->args[2] & 0xff;
}

BOOL EventCaller::TryStartVisitEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3)
{
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;
    input.unk_08 = arg_3;

    if (!CheckEventTrigger(EVENT_KIND_05, CheckVisitEventTrigger, &input))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_05, CheckVisitEventTrigger, &input);
    return TRUE;
}

BOOL EventCaller::CanStartVisitEvent(u32 arg_0, u32 arg_1, u32 arg_2)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;
    input.unk_08 = arg_2;

    return CheckEventTrigger(EVENT_KIND_05, CheckVisitEventTrigger, &input);
}

BOOL EventCaller::CheckAreaEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    int unk_14;
    int unk_16;
    int unk_18;
    int unk_1a;

    unk_14 = arg_0->args[0];
    unk_16 = arg_0->args[1];
    unk_18 = arg_0->args[2];
    unk_1a = arg_0->args[3];

    if (unk_18 <= 0)
    {
        unk_18 = (gMapStateManager->unk_20 - 1) - unk_18;
    }

    if (unk_1a <= 0)
    {
        unk_1a = (gMapStateManager->unk_22 - 1) - unk_1a;
    }

    if (unk_14 > (s32)arg_1->unk_00)
    {
        return FALSE;
    }

    if (unk_18 < (s32)arg_1->unk_00)
    {
        return FALSE;
    }

    if (unk_16 > (s32)arg_1->unk_04)
    {
        return FALSE;
    }

    if (unk_1a < (s32)arg_1->unk_04)
    {
        return FALSE;
    }

    if ((arg_0->args[4] >= 0) && (arg_0->args[4] != data_ov000_021e3324->phase))
    {
        return FALSE;
    }

    if (!CheckEventFlag(GetEventStr(arg_0, arg_0->args[5])))
    {
        return FALSE;
    }

    return TRUE;
}

BOOL EventCaller::TryStartAreaEvent(ProcPtr parent, u32 arg_1, u32 arg_2)
{
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;

    if (!CheckEventTrigger(EVENT_KIND_04, CheckAreaEventTrigger, &input))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_04, CheckAreaEventTrigger, &input);
    return TRUE;
}

BOOL EventCaller::CanStartAreaEvent(u32 arg_0, u32 arg_1)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;

    return CheckEventTrigger(EVENT_KIND_04, CheckAreaEventTrigger, &input);
}

BOOL EventCaller::CheckTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    char * pidStrA;
    char * pidStrB;

    if (!CheckEventFlag(GetEventStr(arg_0, arg_0->args[3])))
    {
        return FALSE;
    }

    pidStrA = GetEventStr(arg_0, arg_0->args[0]);
    pidStrB = GetEventStr(arg_0, arg_0->args[1]);

    if (IsSamePerson(pidStrA, (char *)arg_1->unk_00) && IsSamePerson(pidStrB, (char *)arg_1->unk_04))
    {
        return TRUE;
    }

    if (arg_0->args[2] != 0)
    {
        if (IsSamePerson(pidStrB, (char *)arg_1->unk_00) && IsSamePerson(pidStrA, (char *)arg_1->unk_04))
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL EventCaller::TryStartTalkEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3)
{
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;

    if (CheckEventTrigger(EVENT_KIND_08, CheckTalkEventTrigger, &input) == 0)
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_08, CheckTalkEventTrigger, &input, arg_3);
    return TRUE;
}

BOOL EventCaller::CanStartTalkEvent(u32 arg_0, u32 arg_1)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;

    return CheckEventTrigger(EVENT_KIND_08, CheckTalkEventTrigger, &input) & 0xFF;
}

void EventCaller::func_020484b0(void)
{
    char * pidStrA;
    char * pidStrB;
    struct UnkStruct_021974e8_04_00 * r7;
    struct UnkStruct_021974e8_04 * r8;
    struct EventInfo * r9;
    int sl;

    r8 = new UnkStruct_021974e8_04;

    if (r8 != NULL)
    {
        r8->unk_04 = CountEventsByKind(EVENT_KIND_08);

        if (r8->unk_04 == 0)
        {
            r8->unk_00 = NULL;
        }
        else
        {
            r8->unk_00 = new UnkStruct_021974e8_04_00[r8->unk_04];

            sl = 0;

            for (r9 = func_02035b98(NULL); r9 != NULL; r9 = func_02035b98(r9))
            {
                if (r9->kind != EVENT_KIND_08)
                {
                    continue;
                }

                r7 = r8->unk_00 + sl;

                pidStrA = GetEventStr(r9, r9->args[0]);
                pidStrB = GetEventStr(r9, r9->args[1]);

                if (pidStrA != NULL && *pidStrA != 0)
                {
                    r7->unk_00 = GetPersonByPidStr(pidStrA);
                }
                else
                {
                    r7->unk_00 = 0;
                }

                if (pidStrB != NULL && *pidStrB != 0)
                {
                    r7->unk_04 = GetPersonByPidStr(pidStrB);
                }
                else
                {
                    r7->unk_04 = 0;
                }

                if (r9->args[2] != 0)
                {
                    r7->unk_0c = TRUE;
                }
                else
                {
                    r7->unk_0c = FALSE;
                }

                r7->unk_08 = GetEventStr(r9, r9->args[3]);
                sl++;
            }
        }
    }

    data_021974e8.unk_04 = r8;

    return;
}

void EventCaller::func_020485d0(void)
{
    struct UnkStruct_021974e8_04 * r4 = data_021974e8.unk_04;

    if (r4)
    {
        if (r4->unk_00)
        {
            delete[] r4->unk_00;
        }

        delete r4;
    }

    data_021974e8.unk_04 = NULL;

    return;
}

BOOL EventCaller::func_02048610(char * arg_0, char * arg_1)
{
    struct UnkStruct_021974e8_04 * pUVar2;
    BOOL r5;
    struct UnkStruct_021974e8_04_00 * r8;
    int i;

    pUVar2 = data_021974e8.unk_04;

    for (i = 0; i < pUVar2->unk_04; i++)
    {
        BOOL r0;
        r8 = pUVar2->unk_00 + i;

        r5 = FALSE;

        if (func_02047b3c(arg_0, static_cast<char *>(r8->unk_00)) &&
            func_02047b3c(arg_1, static_cast<char *>(r8->unk_04)))
        {
            r5 = TRUE;
        }
        else if (r8->unk_0c != 0)
        {
            if (func_02047b3c(arg_0, static_cast<char *>(r8->unk_04)) &&
                func_02047b3c(arg_1, static_cast<char *>(r8->unk_00)))
            {
                r5 = TRUE;
            }
        }

        if (!r5)
        {
            r0 = FALSE;
        }
        else
        {
            if (!CheckEventFlag(static_cast<char *>(r8->unk_08)))
            {
                r0 = FALSE;
            }
            else
            {
                r0 = TRUE;
            }
        }

        if (r0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL EventCaller::func_020486f4(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    char * pidStrA;
    char * pidStrB;

    if (!CheckEventFlag(GetEventStr(arg_0, arg_0->args[3])))
    {
        return FALSE;
    }

    pidStrA = GetEventStr(arg_0, arg_0->args[0]);
    pidStrB = GetEventStr(arg_0, arg_0->args[1]);

    if ((IsSamePerson(pidStrA, (char *)arg_1->unk_00) != 0) && (IsSamePerson(pidStrB, (char *)arg_1->unk_04) != 0))
    {
        return TRUE;
    }

    if (arg_0->args[2] != 0)
    {
        if (IsSamePerson(pidStrB, (char *)arg_1->unk_00) && IsSamePerson(pidStrA, (char *)arg_1->unk_04))
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL EventCaller::func_020487a4(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3)
{
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;

    if (!CheckEventTrigger(EVENT_KIND_15, func_020486f4, &input))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_15, func_020486f4, &input, arg_3);
    return TRUE;
}

BOOL EventCaller::CheckBattleTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    char * pidStrA;
    char * pidStrB;

    if (!CheckEventFlag(GetEventStr(arg_0, arg_0->args[3])))
    {
        return FALSE;
    }

    pidStrA = GetEventStr(arg_0, arg_0->args[0]);
    pidStrB = GetEventStr(arg_0, arg_0->args[1]);

    if (IsSamePerson(pidStrA, (char *)arg_1->unk_00) && IsSamePerson(pidStrB, (char *)arg_1->unk_04))
    {
        return TRUE;
    }

    if (arg_0->args[2] != 0)
    {
        if (IsSamePerson(pidStrB, (char *)arg_1->unk_00) && IsSamePerson(pidStrA, (char *)arg_1->unk_04))
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL EventCaller::TryStartBattleTalkEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3)
{
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;

    if (!CheckEventTrigger(EVENT_KIND_09, CheckBattleTalkEventTrigger, &input))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_09, CheckBattleTalkEventTrigger, &input, arg_3);
    return TRUE;
}

BOOL EventCaller::CanStartBattleTalkEvent(u32 arg_0, u32 arg_1)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;

    return CheckEventTrigger(EVENT_KIND_09, CheckBattleTalkEventTrigger, &input) & 0xFF;
}

BOOL EventCaller::CheckDeathEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    if (!IsSamePerson(GetEventStr(arg_0, arg_0->args[0]), (char *)arg_1->unk_00))
    {
        return FALSE;
    }

    return TRUE;
}

BOOL EventCaller::TryStartDeathEvent(ProcPtr parent, u32 arg_1, u32 arg_2)
{
    struct EventFuncInput input;

    if (arg_1 == 0)
    {
        return FALSE;
    }

    input.unk_00 = arg_1;

    if (CheckEventTrigger(EVENT_KIND_0B, CheckDeathEventTrigger, &input))
    {
        new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_0B, CheckDeathEventTrigger, &input, arg_2);
        return TRUE;
    }
    else if (CheckEventTrigger(EVENT_KIND_0A, CheckDeathEventTrigger, &input))
    {
        new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(EVENT_KIND_0A, CheckDeathEventTrigger, &input, arg_2);
        return TRUE;
    }

    return FALSE;
}

BOOL EventCaller::CanStartDeathEvent(u32 arg_0)
{
    struct EventFuncInput input;

    if (arg_0 == 0)
    {
        return FALSE;
    }

    input.unk_00 = arg_0;

    if (CheckEventTrigger(EVENT_KIND_0B, CheckDeathEventTrigger, &input))
    {
        return TRUE;
    }

    if (CheckEventTrigger(EVENT_KIND_0A, CheckDeathEventTrigger, &input))
    {
        return TRUE;
    }

    return FALSE;
}

BOOL EventCaller::func_02048da0(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    if (arg_1->unk_00 != arg_0->args[0])
    {
        return FALSE;
    }

    if (!CheckEventFlag(GetEventStr(arg_0, arg_0->args[1])))
    {
        return FALSE;
    }

    return TRUE;
}

BOOL EventCaller::func_02048dd4(u32 arg_0)
{
    struct EventInfo * it;
    struct EventFuncInput input;

    input.unk_00 = arg_0;

    if (!CheckEventTrigger(EVENT_KIND_16, func_02048da0, &input))
    {
        return FALSE;
    }

    for (it = func_02035b98(NULL); it != NULL; it = func_02035b98(it))
    {
        if (it->kind != EVENT_KIND_16)
        {
            continue;
        }

        if (!func_02048da0(it, &input))
        {
            continue;
        }

        Event::StartEventByInfo(it, PROC_TREE_9);
    }

    return TRUE;
}

BOOL EventCaller::func_02048e60(u32 arg_0)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;

    if (CheckEventTrigger(EVENT_KIND_16, func_02048da0, &input) != 0)
    {
        return TRUE;
    }

    return FALSE;
}

inline void EventCaller::RestoreUnk64()
{
    if (this->unk_68 != 0)
    {
        data_021974f0 = this->unk_64;
    }
}

EventCaller::~EventCaller()
{
    this->RestoreUnk64();
}

Event::~Event()
{
    func_02035ccc(&this->unk_38);
    func_ov000_021a4718();

    data_021974e8.unk_00->Init();
}

// func_02048fb0
BOOL EventSkip::vfunc_00()
{
    if (func_0204a66c())
    {
        return FALSE;
    }

    return data_020ca61c->unk_00 & 8 ? TRUE : FALSE;
}

// func_02048fe4
BOOL Skip::vfunc_00()
{
    return data_020ca61c->unk_00 & 8 ? TRUE : FALSE;
}

// func_02049004
void EventSkip::vfunc_08()
{
    Event::func_0204745c();
}

// func_02049010
BOOL EventSkip::vfunc_04()
{
    return FALSE;
}

// func_02049018
void Skip::vfunc_08()
{
    return;
}

// func_0204901c
BOOL Skip::vfunc_04()
{
    return FALSE;
}

void Skip::func_02049024(ProcPtr proc)
{
    AbstCtrl_04 * temp_r9;
    s32 var_r9;

    if ((this->unk_06 == 0) && (this->vfunc_00() != 0))
    {
        this->unk_06 = 2U;
    }

    if (this->IsSkipState4() || this->CheckSkipStateVarious())
    {
        if (this->unk_08 < this->unk_0a)
        {
            this->unk_08++;
        }
    }

    do
    {
        var_r9 = 0;

        switch (this->unk_06)
        {
            default:
                break;

            case 2:
                if ((IsFadeActive() == 0) && (this->vfunc_04() == 0))
                {
                    this->unk_04 = func_0201bce4();
                    this->unk_05 = func_0201bcf4();
                    StartBlockingFadeOut((struct Proc *)proc, 8, 1);
                    Proc_Lock((struct Proc *)proc);
                    this->unk_06 = 3U;
                    var_r9 = 1;
                }

                break;

            case 3:
                if (IsFadeActive() == 0)
                {
                    Proc_Release((struct Proc *)proc);
                    this->vfunc_08();
                    this->unk_06 = 4U;
                }

                break;

            case 5:
            case 6:
                if (this->unk_08 < this->unk_0a)
                {
                    if (this->unk_07 == 0)
                    {
                        Proc_Lock((struct Proc *)proc);
                        this->unk_07 = 1U;
                    }
                }
                else
                {
                    if (this->unk_07 != 0)
                    {
                        Proc_Release((struct Proc *)proc);
                        this->unk_07 = 0U;
                    }

                    if (this->unk_04 == 0)
                    {
                        if (func_0201bd6c() == 0)
                        {
                            StartBlockingFadeIn((struct Proc *)proc, 8, 0);
                        }
                        else
                        {
                            StartBlockingFadeIn_0201d900((struct Proc *)proc, 8, 0);
                        }
                    }

                    if (this->unk_05 == 0)
                    {
                        temp_r9 = data_027e1268;
                        data_027e1268 = data_027e0004;

                        if (func_0201bd6c() == 0)
                        {
                            StartBlockingFadeIn((struct Proc *)proc, 8, 0);
                        }
                        else
                        {
                            StartBlockingFadeIn_0201d900((struct Proc *)proc, 8, 0);
                        }

                        data_027e1268 = temp_r9;
                    }

                    Proc_Lock((struct Proc *)proc);

                    var_r9 = 1;

                    this->unk_06 = (this->unk_06 == 6) ? 8 : 7;
                }

                break;

            case 7:
            case 8:
                if (IsFadeActive() == 0)
                {
                    Proc_Release((struct Proc *)proc);

                    if (this->unk_06 == 8)
                    {
                        this->unk_06 = 1U;
                    }
                    else
                    {
                        this->unk_06 = 0U;
                    }
                }

                break;
        }
    } while (var_r9 != 0);
}

// clang-format off

struct ProcCmd ProcScr_EventCaller[] =
{
    PROC_NAME,
    PROC_NAME,
    PROC_REPEAT(EventCaller_Loop),
    PROC_END,
};

struct ProcCmd ProcScr_Event[] =
{
    PROC_NAME,
    PROC_NAME,
    PROC_06(0x0000, Event_ProcCmd06),
    PROC_REPEAT(Event_Loop),
    PROC_END,
};

// clang-format on
