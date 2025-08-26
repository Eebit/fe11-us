#ifndef EVENT_HPP
#define EVENT_HPP

#include "proc_ex.hpp"
#include "unknown_funcs.h"

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

    /* 00 */ virtual BOOL vfunc_00();
    /* 04 */ virtual BOOL vfunc_04();
    /* 08 */ virtual void vfunc_08();

    void func_02049024(ProcPtr proc);

    inline void Init()
    {
        this->unk_06 = 0;
        this->unk_04 = func_0201bce4();
        this->unk_05 = func_0201bcf4();
        this->unk_08 = 0;
        this->unk_07 = 0;
    };

    inline BOOL CheckSkipStateVarious(void);

    inline void SkipTransitionFrom2To0Or4To5(void);
    inline void SkipTransition1To0(void);
    inline void SkipTransition0Or2To1(void);
    inline BOOL IsSkipState4(void);
    inline BOOL IsSkipState1(void);
};

class EventSkip : public Skip
{
public:
    /* 00 */ virtual BOOL vfunc_00();
    /* 04 */ virtual BOOL vfunc_04();
    /* 08 */ virtual void vfunc_08();

    static void SkipTransitionFrom0To2(void);
    static void SkipTransitionFrom2To0Or4To5(void);
    static void SkipTransition1To0(void);
    static void SkipTransition0Or2To1(void);
    static BOOL IsSkipState4(void);
    static BOOL func_0204789c(void);
    static BOOL IsSkipState1(void);
    static void SetUnk04(u32 arg_0);
    static void SetUnk05(u32 arg_0);
};

struct UnkStruct_021974e8_04_00
{
    /* 00 */ void * unk_00;
    /* 04 */ void * unk_04;
    /* 08 */ void * unk_08;
    /* 0C */ s32 unk_0c;

    UnkStruct_021974e8_04_00() {};
};

// TODO: This is possibly just a C++ vector class; needs investigation
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

extern "C"
{
    extern struct ProcCmd ProcScr_EventCaller[];
    extern struct ProcCmd ProcScr_Event[];
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
    static BOOL StartEventByInfo(struct EventInfo * arg_0, ProcPtr parent);
    static void func_020476a0(void);
    static BOOL StartEventByName(char * arg_0, ProcPtr parent);
    static Event * GetRunningEvent(void);
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

            if (!Event::StartEventByInfo(this->unk_38, this))
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

            if (!Event::StartEventByInfo(this->unk_38, this))
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

            if (!Event::StartEventByInfo(this->unk_38, this))
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
    static BOOL CheckEventFlag(char * arg_0);
    static BOOL IsSamePerson(char * pidStrA, char * pidStrB);
    static BOOL func_02047b3c(char * arg_0, char * arg_1);
    static BOOL CheckTurnEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * unused);
    static BOOL TryStartTurnEvent(ProcPtr parent);
    static BOOL TryStartTurnEventAlt(ProcPtr parent);
    static BOOL CheckReinforcementEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * unused);
    static BOOL TryStartReinforcementEvent(ProcPtr parent);
    static BOOL CheckVisitEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartVisitEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3);
    static BOOL CanStartVisitEvent(u32 arg_0, u32 arg_1, u32 arg_2);
    static BOOL CheckAreaEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartAreaEvent(ProcPtr parent, u32 arg_1, u32 arg_2);
    static BOOL CanStartAreaEvent(u32 arg_0, u32 arg_1);
    static BOOL CheckTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartTalkEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3);
    static BOOL CanStartTalkEvent(u32 arg_0, u32 arg_1);
    static void func_020484b0(void);
    static void func_020485d0(void);
    static BOOL func_02048610(char * arg_0, char * arg_1);
    static BOOL func_020486f4(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL func_020487a4(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3);
    static BOOL CheckBattleTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartBattleTalkEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3);
    static BOOL CanStartBattleTalkEvent(u32 arg_0, u32 arg_1);
    static BOOL CheckDeathEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL TryStartDeathEvent(ProcPtr parent, u32 arg_1, u32 arg_2);
    static BOOL CanStartDeathEvent(u32 arg_0);
    static BOOL func_02048da0(struct EventInfo * arg_0, struct EventFuncInput * arg_1);
    static BOOL func_02048dd4(u32 arg_0);
    static BOOL func_02048e60(u32 arg_0);
};

extern struct UnkStruct_02196f0c * data_02196f0c;

#endif // EVENT_HPP