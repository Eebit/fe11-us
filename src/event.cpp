#include "global.h"

#include <new>

#include "proc_ex.hpp"
#include "unknown_funcs.h"
#include "unknown_data.h"

enum EventKind
{
    EVENT_KIND_00 = 0x00,
    EVENT_KIND_01 = 0x01,
    EVENT_KIND_02 = 0x02,
    EVENT_KIND_03 = 0x03, // turn?
    EVENT_KIND_04 = 0x04, // area
    EVENT_KIND_05 = 0x05, // visit
    EVENT_KIND_06 = 0x06, // turn also?
    EVENT_KIND_07 = 0x07,
    EVENT_KIND_08 = 0x08, // talk
    EVENT_KIND_09 = 0x09, // battle talk
    EVENT_KIND_0A = 0x0A, // death?
    EVENT_KIND_0B = 0x0B, // death?
    EVENT_KIND_0C = 0x0C,
    EVENT_KIND_0D = 0x0D,
    EVENT_KIND_0E = 0x0E,
    EVENT_KIND_0F = 0x0F,
    EVENT_KIND_10 = 0x10,
    EVENT_KIND_11 = 0x11,
    EVENT_KIND_12 = 0x12,
    EVENT_KIND_13 = 0x13,
    EVENT_KIND_14 = 0x14,
    EVENT_KIND_15 = 0x15,
    EVENT_KIND_16 = 0x16,
    EVENT_KIND_17 = 0x17, // reinforcements
};

class Skip
{
public:
    /* 00 (vtable) */
    /* 04 */ u8 unk_04;
    /* 05 */ u8 unk_05;
    /* 06 */ u8 unk_06;
    /* 07 */ u8 unk_07;
    /* 08 */ u16 unk_08;
    /* 0A */ u16 unk_0a;

    Skip()
    {
        this->unk_0a = 0;
    }

    virtual BOOL func_02048fe4();
    virtual BOOL func_0204901c();
    virtual void func_02049018();

    void func_02049024(ProcPtr proc);

    inline void Init()
    {
        this->unk_06 = 0;
        this->unk_04 = func_0201bce4();
        this->unk_05 = func_0201bcf4();
        this->unk_08 = 0;
        this->unk_07 = 0;
    };

    inline BOOL CheckSkipState(void);

    inline void func_02047808(void);
    inline void func_02047838(void);
    inline void func_02047858(void);
    inline BOOL func_0204787c(void);
    inline BOOL func_020478d4(void);
};

class EventSkip : public Skip
{
public:
    virtual BOOL func_02048fe4(); // func_02048fb0
    virtual BOOL func_0204901c(); // func_02049010
    virtual void func_02049018(); // func_02049004

    static void func_020477e8(void);
    static void func_02047808(void);
    static void func_02047838(void);
    static void func_02047858(void);
    static BOOL func_0204787c(void);
    static BOOL func_0204789c(void);
    static BOOL func_020478d4(void);
    static void func_020478f4(u32 arg_0);
    static void func_02047908(u32 arg_0);
};

struct UnkStruct_021974e8_04_00
{
    /* 00 */ void * unk_00;
    /* 04 */ void * unk_04;
    /* 08 */ void * unk_08;
    /* 0C */ s32 unk_0c;

    UnkStruct_021974e8_04_00() {};
};

struct UnkStruct_021974e8_04
{
    /* 00 */ struct UnkStruct_021974e8_04_00 * unk_00;
    /* 04 */ s32 unk_04;
};

struct UnkStruct_021974e8
{
    /* 00 */ Skip * unk_00;
    /* 04 */ struct UnkStruct_021974e8_04 * unk_04;
};

extern struct UnkStruct_021974e8 data_021974e8;

struct EventInfo
{
    /* 00 */ char * unk_00;
    /* 04 */ void * unk_04;
    /* 08 */ void * unk_08;
    /* 0C */ s8 kind;
    /* 0D */ STRUCT_PAD(0x0D, 0x14);
    /* 14 */ s16 args[6];
};

struct EventFuncInput
{
    /* 00 */ u32 unk_00;
    /* 04 */ u32 unk_04;
    /* 08 */ u32 unk_08;
    /* 0C */ STRUCT_PAD(0x0C, 0x20);
};

typedef BOOL (*EventFunc)(struct EventInfo *, struct EventFuncInput *);

EC struct EventInfo * func_02035b98(void *);
EC BOOL func_020475cc(struct EventInfo * arg_0, ProcPtr parent);
EC void func_020a5780(void *, void *, s32);

extern "C"
{
    extern struct ProcCmd ProcScr_EventCaller[];
    extern struct ProcCmd ProcScr_020d5e88[];
    extern u32 data_021974f0;
}

class Event : public ProcEx
{
public:
    /* 38 */ int unk_38;
    /* 3C */ STRUCT_PAD(0x3C, 0x44);
    /* 44 */ int unk_44;

    Event(char * arg_0)
    {
        data_021974e8.unk_00->Init();

        if (func_ov000_021a8248() != 0)
        {
            data_021974e8.unk_00->unk_06 = 4;
            data_021974e8.unk_00->unk_04 = 0;
            data_021974e8.unk_00->unk_05 = 0;
        }

        func_02035c7c(&this->unk_38, 0x20);
        func_02035dc4(&this->unk_38, arg_0);

        if (func_020357e8() == 0)
        {
            Proc_End(this);
        }
    };

    Event(struct EventInfo * arg_0)
    {
        data_021974e8.unk_00->Init();

        if (func_ov000_021a8248() != 0)
        {
            data_021974e8.unk_00->unk_06 = 4;
            data_021974e8.unk_00->unk_04 = 0;
            data_021974e8.unk_00->unk_05 = 0;
        }

        func_02035c7c(&this->unk_38, 0x20);
        func_02035e5c(&this->unk_38, arg_0);
        func_02035f20(&this->unk_38);

        if (func_020357e8() == 0)
        {
            Proc_End(this);
        }
    };

    virtual ~Event();

    static void func_0204745c(void);
    static BOOL func_020475cc(struct EventInfo * arg_0, ProcPtr parent);
    static void func_020476a0(void);
    static BOOL func_02047708(char * arg_0, ProcPtr parent);
    static Event * func_020477d4(void);
};

class EventCaller : public ProcEx
{
public:
    /* 38 */ struct EventInfo * unk_38;
    /* 3C */ int unk_3c;
    /* 40 */ EventFunc unk_40;
    /* 44 */ EventFuncInput unk_44;
    /* 64 */ u32 unk_64;
    /* 68 */ u8 unk_68;

    EventCaller(s32 kind, EventFunc func)
    {
        this->unk_38 = 0;
        this->unk_3c = kind;
        this->unk_40 = func;
        this->unk_64 = 0;
        this->unk_68 = 0;

        this->unk_38 = func_02035b98(this->unk_38);

        for (; this->unk_38 != NULL; this->unk_38 = func_02035b98(this->unk_38))
        {
            if (this->unk_38->kind != this->unk_3c)
            {
                continue;
            }

            if (!this->unk_40(this->unk_38, &this->unk_44))
            {
                continue;
            }

            if (!func_020475cc(this->unk_38, this))
            {
                continue;
            }

            return;
        }

        Proc_End(this);
    }

    EventCaller(s32 kind, EventFunc func, EventFuncInput * input)
    {
        this->unk_38 = 0;
        this->unk_3c = kind;
        this->unk_40 = func;
        func_020a5780(input, &this->unk_44, 0x20);
        this->unk_64 = 0;
        this->unk_68 = 0;

        this->unk_38 = func_02035b98(this->unk_38);

        for (; this->unk_38 != NULL; this->unk_38 = func_02035b98(this->unk_38))
        {
            if (this->unk_38->kind != this->unk_3c)
            {
                continue;
            }

            if (!this->unk_40(this->unk_38, &this->unk_44))
            {
                continue;
            }

            if (!func_020475cc(this->unk_38, this))
            {
                continue;
            }

            return;
        }

        Proc_End(this);
    }

    EventCaller(s32 kind, EventFunc func, EventFuncInput * input, BOOL arg_2)
    {
        this->unk_38 = 0;
        this->unk_3c = kind;
        this->unk_40 = func;
        func_020a5780(input, &this->unk_44, 0x20);
        if (arg_2 != 0)
        {
            this->unk_64 = data_021974f0;
            data_021974f0 = arg_2;
            this->unk_68 = 1;
        }
        else
        {
            this->unk_64 = 0;
            this->unk_68 = 0;
        }

        this->unk_38 = func_02035b98(this->unk_38);

        for (; this->unk_38 != NULL; this->unk_38 = func_02035b98(this->unk_38))
        {
            if (this->unk_38->kind != this->unk_3c)
            {
                continue;
            }

            if (!this->unk_40(this->unk_38, &this->unk_44))
            {
                continue;
            }

            if (!func_020475cc(this->unk_38, this))
            {
                continue;
            }

            return;
        }

        Proc_End(this);
    };

    virtual ~EventCaller();

    inline void RestoreUnk64();

    static BOOL func_02047990(void);
    static BOOL func_020479b0(void);
    static BOOL CheckEventTrigger(s32 type, EventFunc func, struct EventFuncInput * input);
    static s32 CountEventsByKind(s32 arg_0);
    static BOOL CheckEventFlagMaybe(char * arg_0);
    static BOOL func_02047aec(char * pidStrA, char * pidStrB);
    static BOOL func_02047b3c(char * arg_0, char * arg_1);
    static BOOL CheckTurnEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * unused);
    static BOOL TryStartTurnEvent(ProcPtr parent);
    static BOOL func_02047ca4(ProcPtr parent);
    static BOOL CheckReinforcementEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * unused);
    static BOOL TryStartReinforcementEvent(ProcPtr parent);
    static BOOL CheckVisitEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartVisitEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3);
    static BOOL func_02048078(u32 arg_0, u32 arg_1, u32 arg_2);
    static BOOL CheckAreaEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartAreaEvent(ProcPtr parent, u32 arg_1, u32 arg_2);
    static BOOL func_02048278(u32 arg_0, u32 arg_1);
    static BOOL CheckTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartTalkEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3);
    static BOOL func_02048480(u32 arg_0, u32 arg_1);
    static void func_020484b0(void);
    static void func_020485d0(void);
    static BOOL func_02048610(char * arg_0, char * arg_1);
    static BOOL func_020486f4(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL func_020487a4(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3);
    static BOOL CheckBattleTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartBattleTalkEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3);
    static BOOL func_02048aac(u32 arg_0, u32 arg_1);
    static BOOL CheckDeathEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartDeathEvent(ProcPtr parent, u32 arg_1, u32 arg_2);
    static BOOL func_02048d3c(int arg_0);
    static BOOL func_02048da0(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL func_02048dd4(u32 arg_0);
    static BOOL func_02048e60(u32 arg_0);
};

extern "C"
{
    extern u32 data_021974f0;
}

extern struct UnkStruct_02196f0c * data_02196f0c;

inline BOOL Skip::CheckSkipState(void)
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

inline BOOL Skip::func_0204787c(void)
{
    if (this->unk_06 == 4)
    {
        return TRUE;
    }

    return FALSE;
}

inline void Skip::func_02047808(void)
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

inline void Skip::func_02047838(void)
{
    if (this->unk_06 == 1)
    {
        this->unk_06 = 0;
    }
}

inline void Skip::func_02047858(void)
{
    if (this->unk_06 == 0 || this->unk_06 == 2)
    {
        this->unk_06 = 1;
    }

    return;
}

inline BOOL Skip::func_020478d4(void)
{
    return this->unk_06 == 1 ? TRUE : FALSE;
}

void Event::func_0204745c(void)
{
    Proc_EndEachMarked(PROC_MARK_A);

    if (data_ov000_021e3328 != NULL)
    {
        func_ov000_021a516c((s32)data_ov000_021e3328->unk_00);
    }

    func_ov000_021db624();

    if (data_ov000_021e3328 != NULL)
    {
        func_ov000_021bb318(data_ov000_021e3328->unk_14->unk_00);
    }

    return;
}

EC void func_020474a8(Event * proc)
{
    if (!data_021974e8.unk_00->CheckSkipState())
    {
        func_02035f20(&proc->unk_38);

        if ((proc->unk_44 ? TRUE : FALSE) != 0)
        {
            if (func_020357e8() == 6)
            {
                return;
            }
        }

        if (data_021974e8.unk_00->func_0204787c())
        {
            if (func_ov000_021a8248() == 0)
            {
                data_021974e8.unk_00->func_02047808();
            }
        }
        else
        {
            data_021974e8.unk_00->func_02047858();

            if (func_ov000_021a8248() != 0)
            {
                func_ov000_021a81d4();
            }
        }

        Proc_Break(proc, 0);
    }

    return;
}

EC void func_020475b0(ProcPtr proc)
{
    data_021974e8.unk_00->func_02049024(proc);
    return;
}

BOOL Event::func_020475cc(struct EventInfo * arg_0, ProcPtr parent)
{
    new (func_01ffc030(ProcScr_020d5e88, parent)) Event(arg_0);

    if (Proc_Find(ProcScr_020d5e88) == NULL)
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

BOOL Event::func_02047708(char * arg_0, ProcPtr parent)
{
    new (func_01ffc030(ProcScr_020d5e88, parent)) Event(arg_0);

    if (Proc_Find(ProcScr_020d5e88) == NULL)
    {
        return FALSE;
    }

    return TRUE;
}

Event * Event::func_020477d4(void)
{
    return static_cast<Event *>(Proc_Find(ProcScr_020d5e88));
}

void EventSkip::func_020477e8(void)
{
    if (data_021974e8.unk_00->unk_06 == 0)
    {
        data_021974e8.unk_00->unk_06 = 2;
    }

    return;
}

void EventSkip::func_02047808(void)
{
    data_021974e8.unk_00->func_02047808();
    return;
}

void EventSkip::func_02047838(void)
{
    data_021974e8.unk_00->func_02047838();
    return;
}

void EventSkip::func_02047858(void)
{
    data_021974e8.unk_00->func_02047858();
    return;
}

BOOL EventSkip::func_0204787c(void)
{
    return data_021974e8.unk_00->func_0204787c();
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

    return data_021974e8.unk_00->func_020478d4();
}

BOOL EventSkip::func_020478d4(void)
{
    return data_021974e8.unk_00->func_020478d4();
}

void EventSkip::func_020478f4(u32 arg_0)
{
    data_021974e8.unk_00->unk_04 = arg_0;
    return;
}

void EventSkip::func_02047908(u32 arg_0)
{
    data_021974e8.unk_00->unk_05 = arg_0;
    return;
}

EC void func_0204791c(EventCaller * proc)
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

        if (func_020475cc(proc->unk_38, proc))
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

    if (Proc_Find(ProcScr_020d5e88) != NULL)
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

BOOL EventCaller::CheckEventFlagMaybe(char * arg_0)
{
    s32 iVar2;

    if (arg_0 != NULL && *arg_0 != 0)
    {
        iVar2 = func_020492f4(data_02196f0c->unk_04, arg_0);

        if (iVar2 >= 0)
        {
            if (func_02049350(data_02196f0c->unk_04, iVar2))
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

BOOL EventCaller::func_02047aec(char * pidStrA, char * pidStrB)
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
    if ((arg_0->args[2] >= 0) && (arg_0->args[2] != data_ov000_021e3324.unk_00->phase))
    {
        return FALSE;
    }

    if (arg_0->args[0] == 0)
    {
        return TRUE;
    }

    if (arg_0->args[0] > data_ov000_021e3324.unk_00->turn)
    {
        return FALSE;
    }

    if (arg_0->args[1] < data_ov000_021e3324.unk_00->turn)
    {
        return FALSE;
    }

    return TRUE;
}

BOOL EventCaller::TryStartTurnEvent(ProcPtr parent)
{
    if (!CheckEventTrigger(3, CheckTurnEventTrigger, NULL))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(3, CheckTurnEventTrigger);
    return TRUE;
}

BOOL EventCaller::func_02047ca4(ProcPtr parent)
{
    if (!CheckEventTrigger(6, CheckTurnEventTrigger, NULL))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(6, CheckTurnEventTrigger);
    return TRUE;
}

BOOL EventCaller::CheckReinforcementEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * unused)
{
    if (arg_0->args[2] >= 0)
    {
        if (data_02196f20->unk_199 != 0)
        {
            if (arg_0->args[2] != data_ov000_021e3324.unk_00->phase)
            {
                return FALSE;
            }
        }
        else if (data_ov000_021e3324.unk_00->phase != 0)
        {
            return FALSE;
        }
    }

    if (arg_0->args[0] == 0)
    {
        return TRUE;
    }

    if (arg_0->args[0] > data_ov000_021e3324.unk_00->turn)
    {
        return FALSE;
    }

    if (arg_0->args[1] < data_ov000_021e3324.unk_00->turn)
    {
        return FALSE;
    }

    return TRUE;
}

BOOL EventCaller::TryStartReinforcementEvent(ProcPtr parent)
{
    if (!CheckEventTrigger(0x17, CheckReinforcementEventTrigger, NULL))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(0x17, CheckReinforcementEventTrigger);
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

    if (!CheckEventFlagMaybe(GetEventStr(arg_0, arg_0->args[3])))
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

    if (!CheckEventTrigger(5, CheckVisitEventTrigger, &input))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(5, CheckVisitEventTrigger, &input);
    return TRUE;
}

BOOL EventCaller::func_02048078(u32 arg_0, u32 arg_1, u32 arg_2)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;
    input.unk_08 = arg_2;

    return CheckEventTrigger(5, CheckVisitEventTrigger, &input);
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
        unk_18 = (data_ov000_021e3328->unk_20 - 1) - unk_18;
    }

    if (unk_1a <= 0)
    {
        unk_1a = (data_ov000_021e3328->unk_22 - 1) - unk_1a;
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

    if ((arg_0->args[4] >= 0) && (arg_0->args[4] != data_ov000_021e3324.unk_00->phase))
    {
        return FALSE;
    }

    if (!CheckEventFlagMaybe(GetEventStr(arg_0, arg_0->args[5])))
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

    if (!CheckEventTrigger(4, CheckAreaEventTrigger, &input))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(4, CheckAreaEventTrigger, &input);
    return TRUE;
}

BOOL EventCaller::func_02048278(u32 arg_0, u32 arg_1)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;

    return CheckEventTrigger(4, CheckAreaEventTrigger, &input);
}

BOOL EventCaller::CheckTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    char * uVar2;
    char * uVar3;

    if (!CheckEventFlagMaybe(GetEventStr(arg_0, arg_0->args[3])))
    {
        return FALSE;
    }

    uVar2 = GetEventStr(arg_0, arg_0->args[0]);
    uVar3 = GetEventStr(arg_0, arg_0->args[1]);

    if ((func_02047aec(uVar2, (char *)arg_1->unk_00) != 0) && (func_02047aec(uVar3, (char *)arg_1->unk_04) != 0))
    {
        return TRUE;
    }

    if (arg_0->args[2] != 0)
    {
        if (((func_02047aec(uVar3, (char *)arg_1->unk_00) != 0)) && (func_02047aec(uVar2, (char *)arg_1->unk_04) != 0))
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

    if (CheckEventTrigger(8, CheckTalkEventTrigger, &input) == 0)
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(8, CheckTalkEventTrigger, &input, arg_3);
    return TRUE;
}

BOOL EventCaller::func_02048480(u32 arg_0, u32 arg_1)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;

    return CheckEventTrigger(8, CheckTalkEventTrigger, &input) & 0xFF;
}

void EventCaller::func_020484b0(void)
{
    char * pcVar2;
    char * pcVar4;
    struct UnkStruct_021974e8_04_00 * r7;
    struct UnkStruct_021974e8_04 * r8;
    struct EventInfo * r9;
    int sl;

    r8 = new UnkStruct_021974e8_04;

    if (r8 != NULL)
    {
        r8->unk_04 = CountEventsByKind(8);

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
                if (r9->kind != 8)
                {
                    continue;
                }

                r7 = r8->unk_00 + sl;

                pcVar2 = GetEventStr(r9, r9->args[0]);
                pcVar4 = GetEventStr(r9, r9->args[1]);

                if (pcVar2 != NULL && *pcVar2 != 0)
                {
                    r7->unk_00 = GetPersonByPidStr(pcVar2);
                }
                else
                {
                    r7->unk_00 = 0;
                }

                if (pcVar4 != NULL && *pcVar4 != 0)
                {
                    r7->unk_04 = GetPersonByPidStr(pcVar4);
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
            if (!CheckEventFlagMaybe(static_cast<char *>(r8->unk_08)))
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
    char * uVar2;
    char * uVar3;

    if (!CheckEventFlagMaybe(GetEventStr(arg_0, arg_0->args[3])))
    {
        return FALSE;
    }

    uVar2 = GetEventStr(arg_0, arg_0->args[0]);
    uVar3 = GetEventStr(arg_0, arg_0->args[1]);

    if ((func_02047aec(uVar2, (char *)arg_1->unk_00) != 0) && (func_02047aec(uVar3, (char *)arg_1->unk_04) != 0))
    {
        return TRUE;
    }

    if (arg_0->args[2] != 0)
    {
        if (func_02047aec(uVar3, (char *)arg_1->unk_00) && func_02047aec(uVar2, (char *)arg_1->unk_04))
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

    if (!CheckEventTrigger(0x15, func_020486f4, &input))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(0x15, func_020486f4, &input, arg_3);
    return TRUE;
}

BOOL EventCaller::CheckBattleTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    char * uVar2;
    char * uVar3;

    if (!CheckEventFlagMaybe(GetEventStr(arg_0, arg_0->args[3])))
    {
        return FALSE;
    }

    uVar2 = GetEventStr(arg_0, arg_0->args[0]);
    uVar3 = GetEventStr(arg_0, arg_0->args[1]);

    if ((func_02047aec(uVar2, (char *)arg_1->unk_00) != 0) && (func_02047aec(uVar3, (char *)arg_1->unk_04) != 0))
    {
        return TRUE;
    }

    if (arg_0->args[2] != 0)
    {
        if ((func_02047aec(uVar3, (char *)arg_1->unk_00) != 0) && (func_02047aec(uVar2, (char *)arg_1->unk_04) != 0))
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

    if (!CheckEventTrigger(9, CheckBattleTalkEventTrigger, &input))
    {
        return FALSE;
    }

    new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(9, CheckBattleTalkEventTrigger, &input, arg_3);
    return TRUE;
}

BOOL EventCaller::func_02048aac(u32 arg_0, u32 arg_1)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;

    return CheckEventTrigger(9, CheckBattleTalkEventTrigger, &input) & 0xFF;
}

BOOL EventCaller::CheckDeathEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    if (!func_02047aec(GetEventStr(arg_0, arg_0->args[0]), (char *)arg_1->unk_00))
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

    if (CheckEventTrigger(0xb, CheckDeathEventTrigger, &input))
    {
        new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(0xb, CheckDeathEventTrigger, &input, arg_2);
        return TRUE;
    }
    else if (CheckEventTrigger(0xa, CheckDeathEventTrigger, &input))
    {
        new (Proc_StartBlocking(ProcScr_EventCaller, parent)) EventCaller(0xa, CheckDeathEventTrigger, &input, arg_2);
        return TRUE;
    }

    return FALSE;
}

BOOL EventCaller::func_02048d3c(int arg_0)
{
    struct EventFuncInput input;

    if (arg_0 == 0)
    {
        return FALSE;
    }

    input.unk_00 = arg_0;

    if (CheckEventTrigger(0xb, CheckDeathEventTrigger, &input))
    {
        return TRUE;
    }

    if (CheckEventTrigger(0xa, CheckDeathEventTrigger, &input))
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

    if (!CheckEventFlagMaybe(GetEventStr(arg_0, arg_0->args[1])))
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

    if (!CheckEventTrigger(0x16, func_02048da0, &input))
    {
        return FALSE;
    }

    for (it = func_02035b98(NULL); it != NULL; it = func_02035b98(it))
    {
        if (it->kind != 0x16)
        {
            continue;
        }

        if (!func_02048da0(it, &input))
        {
            continue;
        }

        func_020475cc(it, PROC_TREE_9);
    }

    return TRUE;
}

BOOL EventCaller::func_02048e60(u32 arg_0)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;

    if (CheckEventTrigger(0x16, func_02048da0, &input) != 0)
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

EC void func_02035ccc(void *);
EC void func_ov000_021a4718(void);
EC BOOL func_0204a66c(void);

Event::~Event()
{
    func_02035ccc(&this->unk_38);
    func_ov000_021a4718();

    data_021974e8.unk_00->Init();
}

// func_02048fe4
BOOL Skip::func_02048fe4()
{
    return data_020ca61c->unk_00 & 8 ? TRUE : FALSE;
}

// func_02049018
void Skip::func_02049018()
{
    return;
}

// func_0204901c
BOOL Skip::func_0204901c()
{
    return FALSE;
}

// func_02048fb0
BOOL EventSkip::func_02048fe4()
{
    if (func_0204a66c())
    {
        return FALSE;
    }

    return data_020ca61c->unk_00 & 8 ? TRUE : FALSE;
}

// func_02049010
void EventSkip::func_02049018()
{
    Event::func_0204745c();
}

// func_02049004
BOOL EventSkip::func_0204901c()
{
    return FALSE;
}

EC BOOL func_0201bd6c();
EC BOOL func_0201dae8();
extern Unknown_027e1268 * data_027e0004;

void Skip::func_02049024(ProcPtr proc)
{
    Unknown_027e1268 * temp_r9;
    s32 var_r9;

    if ((this->unk_06 == 0) && (this->func_02048fe4() != 0))
    {
        this->unk_06 = 2U;
    }

    if (this->func_0204787c() || this->CheckSkipState())
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
                if ((func_0201dae8() == 0) && (this->func_0204901c() == 0))
                {
                    this->unk_04 = func_0201bce4();
                    this->unk_05 = func_0201bcf4();
                    func_0201d814((struct Proc *)proc, 8, 1);
                    Proc_Lock((struct Proc *)proc);
                    this->unk_06 = 3U;
                    var_r9 = 1;
                }

                break;

            case 3:
                if (func_0201dae8() == 0)
                {
                    Proc_Release((struct Proc *)proc);
                    this->func_02049018();
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
                            func_0201d7c8((struct Proc *)proc, 8, 0);
                        }
                        else
                        {
                            func_0201d900((struct Proc *)proc, 8, 0);
                        }
                    }

                    if (this->unk_05 == 0)
                    {
                        temp_r9 = data_027e1268;
                        data_027e1268 = data_027e0004;

                        if (func_0201bd6c() == 0)
                        {
                            func_0201d7c8((struct Proc *)proc, 8, 0);
                        }
                        else
                        {
                            func_0201d900((struct Proc *)proc, 8, 0);
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
                if (func_0201dae8() == 0)
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
    PROC_REPEAT(func_0204791c),
    PROC_END,
};

struct ProcCmd ProcScr_020d5e88[] =
{
    PROC_NAME,
    PROC_NAME,
    PROC_06(0x0000, func_020475b0),
    PROC_REPEAT(func_020474a8),
    PROC_END,
};

// clang-format on
