#include "global.h"

struct UnkStruct_021974e8_00
{
    void * unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    s16 unk_08;
    s16 unk_0a;
};

struct UnkStruct_021974e8_04_00
{
    void * unk_00;
    void * unk_04;
    void * unk_08;
    s32 unk_0c;
};

struct UnkStruct_021974e8_04
{
    struct UnkStruct_021974e8_04_00 * unk_00;
    s32 unk_04;
};

struct UnkStruct_021974e8
{
    struct UnkStruct_021974e8_00 * unk_00;
    struct UnkStruct_021974e8_04 * unk_04;
};

extern struct UnkStruct_021974e8 data_021974e8;

struct EventInfo
{
    /* 00 */ char unk_00[0xc]; // Length unknown?
    /* 0C */ s8 type;
    /* 0D */ STRUCT_PAD(0x0D, 0x14);
    /* 14 */ s16 args[6];
};

struct EventFuncInput
{
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    STRUCT_PAD(0x0C, 0x20);
};

typedef BOOL (*EventFunc)(struct EventInfo *, struct EventFuncInput *);

struct EventProc
{
    /* 00 */ PROC_HEADER
    /* 38 */ struct EventProc_unk_38 * unk_38;
    /* 3C */ int unk_3c;
    /* 40 */ EventFunc unk_40;
    /* 44 */ int unk_44;
    /* 48 */ int unk_48;
    /* 4C */ STRUCT_PAD(0x4C, 0x64);
    /* 64 */ u32 unk_64;
    /* 68 */ u8 unk_68;
};

extern u32 data_021974f0;

extern void * data_020d5e18[]; // func table?
extern void * __vt__9EventSkip[]; // func table?

extern struct ProcFuncTable ProcFuncTable_EventCaller;
extern struct ProcFuncTable ProcFuncTable_020d5e58;
extern struct ProcCmd ProcScr_EventCaller[];
extern struct ProcCmd ProcScr_020d5e88[];

extern struct UnkStruct_02196f0c * data_02196f0c;

void func_02047450(void)
{
    RegisterEventFunctions();
    return;
}

void func_0204745c(void)
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

static inline BOOL TRICERATOPS(s32 a)
{
    if (a == 4)
    {
        return TRUE;
    }

    return FALSE;
}

void func_020474a8(struct EventProc * proc)
{
    BOOL flag;

    if (data_021974e8.unk_00->unk_06 == 5)
    {
        flag = TRUE;
    }
    else if (data_021974e8.unk_00->unk_06 == 6)
    {
        flag = TRUE;
    }
    else if (data_021974e8.unk_00->unk_06 == 7)
    {
        flag = TRUE;
    }
    else if (data_021974e8.unk_00->unk_06 == 8)
    {
        flag = TRUE;
    }
    else
    {
        flag = FALSE;
    }

    if (!flag)
    {
        func_02035f20(&proc->unk_38);

        if ((proc->unk_44 ? TRUE : FALSE) != 0)
        {
            if (func_020357e8() == 6)
            {
                return;
            }
        }

        if (TRICERATOPS(data_021974e8.unk_00->unk_06))
        {
            if (func_ov000_021a8248() == 0)
            {
                struct UnkStruct_021974e8_00 * r = data_021974e8.unk_00;

                if (r->unk_06 == 2)
                {
                    r->unk_06 = 0;
                }

                if (r->unk_06 == 4)
                {
                    r->unk_06 = 5;
                }
            }
        }
        else
        {
            struct UnkStruct_021974e8_00 * r = data_021974e8.unk_00;

            if (r->unk_06 == 0 || (r->unk_06 == 2))
            {
                r->unk_06 = 1;
            }

            if (func_ov000_021a8248() != 0)
            {
                func_ov000_021a81d4();
            }
        }

        Proc_Break(proc, 0);
    }

    return;
}

void func_020475b0(ProcPtr proc)
{
    func_02049024(data_021974e8.unk_00, proc);
    return;
}

BOOL func_020475cc(struct EventInfo * arg_0, ProcPtr parent)
{
    struct EventProc * proc;
    struct UnkStruct_021974e8_00 * r6;

    proc = func_01ffc030(ProcScr_020d5e88, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_020d5e58;

        r6 = data_021974e8.unk_00;
        r6->unk_06 = 0;
        r6->unk_04 = func_0201bce4();
        r6->unk_05 = func_0201bcf4();
        r6->unk_08 = 0;
        r6->unk_07 = 0;

        if (func_ov000_021a8248() != 0)
        {
            data_021974e8.unk_00->unk_06 = 4;
            data_021974e8.unk_00->unk_04 = 0;
            data_021974e8.unk_00->unk_05 = 0;
        }

        func_02035c7c(&proc->unk_38, 0x20);
        func_02035e5c(&proc->unk_38, arg_0);
        func_02035f20(&proc->unk_38);

        if (func_020357e8() == 0)
        {
            Proc_End(proc);
        }
    }

    if (Proc_Find(ProcScr_020d5e88) == NULL)
    {
        return FALSE;
    }

    return TRUE;
}

void func_020476a0(void)
{
    struct UnkStruct_021974e8_00 * var_0 = func_02011574(0xc);

    if (var_0 != NULL)
    {
        var_0->unk_00 = data_020d5e18;
        var_0->unk_0a = 0;
        var_0->unk_00 = __vt__9EventSkip;
    }

    data_021974e8.unk_00 = var_0;

    var_0->unk_06 = 0;
    var_0->unk_04 = func_0201bce4();
    var_0->unk_05 = func_0201bcf4();
    var_0->unk_08 = 0;
    var_0->unk_07 = 0;

    return;
}

BOOL func_02047708(char * arg_0, ProcPtr parent)
{
    struct EventProc * proc;
    struct UnkStruct_021974e8_00 * r6;

    proc = func_01ffc030(ProcScr_020d5e88, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_020d5e58;

        r6 = data_021974e8.unk_00;
        r6->unk_06 = 0;
        r6->unk_04 = func_0201bce4();
        r6->unk_05 = func_0201bcf4();
        r6->unk_08 = 0;
        r6->unk_07 = 0;

        if (func_ov000_021a8248() != 0)
        {
            data_021974e8.unk_00->unk_06 = 4;
            data_021974e8.unk_00->unk_04 = 0;
            data_021974e8.unk_00->unk_05 = 0;
        }

        func_02035c7c(&proc->unk_38, 0x20);
        func_02035dc4(&proc->unk_38, arg_0);

        if (func_020357e8() == 0)
        {
            Proc_End(proc);
        }
    }

    if (Proc_Find(ProcScr_020d5e88) == NULL)
    {
        return FALSE;
    }

    return TRUE;
}

struct EventProc * func_020477d4(void)
{
    return Proc_Find(ProcScr_020d5e88);
}

void func_020477e8(void)
{
    if (data_021974e8.unk_00->unk_06 == 0)
    {
        data_021974e8.unk_00->unk_06 = 2;
    }

    return;
}

void func_02047808(void)
{
    struct UnkStruct_021974e8_00 * ptr = data_021974e8.unk_00;

    if (ptr->unk_06 == 2)
    {
        ptr->unk_06 = 0;
    }

    if (ptr->unk_06 == 4)
    {
        ptr->unk_06 = 5;
    }

    return;
}

void func_02047838(void)
{
    if (data_021974e8.unk_00->unk_06 == 1)
    {
        data_021974e8.unk_00->unk_06 = 0;
    }

    return;
}

void func_02047858(void)
{
    switch (data_021974e8.unk_00->unk_06)
    {
        case 0:
        case 2:
            data_021974e8.unk_00->unk_06 = 1;
    }

    return;
}

BOOL func_0204787c(void)
{
    if (data_021974e8.unk_00->unk_06 == 4)
    {
        return TRUE;
    }

    return FALSE;
}

BOOL func_0204789c(void)
{
    if (data_021974e8.unk_00->unk_06 == 4)
    {
        return FALSE;
    }

    if (data_021974e8.unk_00->unk_06 == 0)
    {
        return FALSE;
    }

    if (data_021974e8.unk_00->unk_06 == 1 ? TRUE : FALSE)
    {
        return FALSE;
    }

    return TRUE;
}

BOOL func_020478d4(void)
{
    return data_021974e8.unk_00->unk_06 == 1;
}

void func_020478f4(u32 arg_0)
{
    data_021974e8.unk_00->unk_04 = arg_0;
    return;
}

void func_02047908(u32 arg_0)
{
    data_021974e8.unk_00->unk_05 = arg_0;
    return;
}

void func_0204791c(struct EventProc * proc)
{
    for (proc->unk_38 = func_02035b98(proc->unk_38); proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
    {
        if (proc->unk_38->type != proc->unk_3c)
        {
            continue;
        }

        if (!proc->unk_40(proc->unk_38, (void *)&proc->unk_44))
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

BOOL func_02047990(void)
{
    if (Proc_Find(ProcScr_EventCaller) == NULL)
    {
        return TRUE;
    }

    return FALSE;
}

BOOL func_020479b0(void)
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

BOOL CheckEventTrigger(int type, EventFunc func, struct EventFuncInput * input)
{
    struct EventInfo * it;
    BOOL ret;

    for (it = func_02035b98(NULL); it != NULL; it = func_02035b98(it))
    {
        if (it->type != type)
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

int CountEventsByType(int arg_0)
{
    struct EventInfo * it;

    int count = 0;

    for (it = func_02035b98(NULL); it != NULL; it = func_02035b98(it))
    {
        if (it->type != arg_0)
        {
            continue;
        }

        count++;
    }

    return count;
}

BOOL CheckEventFlagMaybe(char * arg_0)
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

BOOL func_02047aec(char * pidStrA, char * pidStrB)
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

BOOL func_02047b3c(char * arg_0, char * arg_1)
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

BOOL CheckTurnEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * unused)
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

BOOL TryStartTurnEvent(ProcPtr parent)
{
    struct EventProc * proc;

    if (CheckEventTrigger(3, CheckTurnEventTrigger, NULL) == 0)
    {
        return FALSE;
    }

    proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_EventCaller;
        proc->unk_38 = NULL;
        proc->unk_3c = 3;
        proc->unk_40 = CheckTurnEventTrigger;
        proc->unk_64 = 0;
        proc->unk_68 = 0;
        proc->unk_38 = func_02035b98(proc->unk_38);

        for (; proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
        {
            if (proc->unk_38->type != proc->unk_3c)
            {
                continue;
            }

            if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
            {
                continue;
            }

            if (!func_020475cc(proc->unk_38, proc))
            {
                continue;
            }

            goto _exit;
        }

        Proc_End(proc);
    }

_exit:
    return TRUE;
}

BOOL func_02047ca4(ProcPtr parent)
{
    struct EventProc * proc;

    if (CheckEventTrigger(6, CheckTurnEventTrigger, NULL) == 0)
    {
        return FALSE;
    }

    proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_EventCaller;
        proc->unk_38 = NULL;
        proc->unk_3c = 6;
        proc->unk_40 = CheckTurnEventTrigger;
        proc->unk_64 = 0;
        proc->unk_68 = 0;
        proc->unk_38 = func_02035b98(proc->unk_38);

        for (; proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
        {
            if (proc->unk_38->type != proc->unk_3c)
            {
                continue;
            }

            if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
            {
                continue;
            }

            if (!func_020475cc(proc->unk_38, proc))
            {
                continue;
            }

            goto _exit;
        }

        Proc_End(proc);
    }

_exit:
    return TRUE;
}

BOOL CheckReinforcementEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * unused)
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

BOOL TryStartReinforcementEvent(ProcPtr parent)
{
    struct EventProc * proc;

    if (CheckEventTrigger(0x17, CheckReinforcementEventTrigger, NULL) == 0)
    {
        return FALSE;
    }

    proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_EventCaller;
        proc->unk_38 = NULL;
        proc->unk_3c = 0x17;
        proc->unk_40 = CheckReinforcementEventTrigger;
        proc->unk_64 = 0;
        proc->unk_68 = 0;
        proc->unk_38 = func_02035b98(proc->unk_38);

        for (; proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
        {
            if (proc->unk_38->type != proc->unk_3c)
            {
                continue;
            }

            if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
            {
                continue;
            }

            if (!func_020475cc(proc->unk_38, proc))
            {
                continue;
            }

            goto _exit;
        }

        Proc_End(proc);
    }

_exit:
    return TRUE;
}

BOOL CheckVisitEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
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

    if (CheckEventFlagMaybe((char *)GetEventStr(arg_0, arg_0->args[3])) == 0)
    {
        return FALSE;
    }

    return arg_0->args[2] & 0xff;
}

BOOL TryStartVisitEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3)
{
    struct EventProc * proc;
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;
    input.unk_08 = arg_3;

    if (CheckEventTrigger(5, CheckVisitEventTrigger, &input) == 0)
    {
        return FALSE;
    }

    proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_EventCaller;
        proc->unk_38 = NULL;
        proc->unk_3c = 5;
        proc->unk_40 = CheckVisitEventTrigger;
        func_020a5780(&input, &proc->unk_44, 0x20);
        proc->unk_64 = 0;
        proc->unk_68 = 0;
        proc->unk_38 = func_02035b98(proc->unk_38);

        for (; proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
        {
            if (proc->unk_38->type != proc->unk_3c)
            {
                continue;
            }

            if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
            {
                continue;
            }

            if (!func_020475cc(proc->unk_38, proc))
            {
                continue;
            }

            goto _exit;
        }

        Proc_End(proc);
    }

_exit:
    return TRUE;
}

BOOL func_02048078(u32 arg_0, u32 arg_1, u32 arg_2)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;
    input.unk_08 = arg_2;

    return CheckEventTrigger(5, CheckVisitEventTrigger, &input);
}

BOOL CheckAreaEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
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

BOOL TryStartAreaEvent(ProcPtr parent, u32 arg_1, u32 arg_2)
{
    struct EventProc * proc;
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;

    if (CheckEventTrigger(4, CheckAreaEventTrigger, &input) == 0)
    {
        return FALSE;
    }

    proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_EventCaller;
        proc->unk_38 = NULL;
        proc->unk_3c = 4;
        proc->unk_40 = CheckAreaEventTrigger;
        func_020a5780(&input, &proc->unk_44, 0x20);
        proc->unk_64 = 0;
        proc->unk_68 = 0;
        proc->unk_38 = func_02035b98(proc->unk_38);

        for (; proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
        {
            if (proc->unk_38->type != proc->unk_3c)
            {
                continue;
            }

            if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
            {
                continue;
            }

            if (!func_020475cc(proc->unk_38, proc))
            {
                continue;
            }

            goto _exit;
        }

        Proc_End(proc);
    }

_exit:
    return TRUE;
}

BOOL func_02048278(u32 arg_0, u32 arg_1)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;

    return CheckEventTrigger(4, CheckAreaEventTrigger, &input);
}

BOOL CheckTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    void * uVar2;
    void * uVar3;

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

BOOL TryStartTalkEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3)
{
    struct EventProc * proc;
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;

    if (CheckEventTrigger(8, CheckTalkEventTrigger, &input) == 0)
    {
        return FALSE;
    }

    proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_EventCaller;
        proc->unk_38 = NULL;
        proc->unk_3c = 8;
        proc->unk_40 = CheckTalkEventTrigger;
        func_020a5780(&input, &proc->unk_44, 0x20);
        if (arg_3 != 0)
        {
            proc->unk_64 = data_021974f0;
            data_021974f0 = arg_3;
            proc->unk_68 = 1;
        }
        else
        {
            proc->unk_64 = 0;
            proc->unk_68 = 0;
        }
        proc->unk_38 = func_02035b98(proc->unk_38);

        for (; proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
        {
            if (proc->unk_38->type != proc->unk_3c)
            {
                continue;
            }

            if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
            {
                continue;
            }

            if (!func_020475cc(proc->unk_38, proc))
            {
                continue;
            }

            goto _exit;
        }

        Proc_End(proc);
    }

_exit:
    return TRUE;
}

BOOL func_02048480(u32 arg_0, u32 arg_1)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;

    return CheckEventTrigger(8, CheckTalkEventTrigger, &input) & 0xFF;
}

void func_020484b0(void)
{
    char * pcVar2;
    char * pcVar4;
    struct UnkStruct_021974e8_04_00 * r7;
    struct UnkStruct_021974e8_04 * r8;
    struct EventInfo * r9;
    int sl;

    r8 = (struct UnkStruct_021974e8_04 *)func_02011574(8);

    if (r8 != NULL)
    {
        r8->unk_04 = CountEventsByType(8);

        if (r8->unk_04 == 0)
        {
            r8->unk_00 = NULL;
        }
        else
        {
            r8->unk_00 = func_020c3bfc(r8->unk_04, 0x10, 0, 0, 0);

            sl = 0;

            for (r9 = func_02035b98(NULL); r9 != NULL; r9 = func_02035b98(r9))
            {
                if (r9->type != 8)
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

                if (r9->args[2] != 0 ? TRUE : FALSE)
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

void func_020485d0(void)
{
    struct UnkStruct_021974e8_04 * r4;

    r4 = data_021974e8.unk_04;

    if (r4 != NULL)
    {
        if (r4->unk_00 != NULL)
        {
            func_020115bc(r4->unk_00);
        }

        func_020115a4(r4);
    }

    data_021974e8.unk_04 = NULL;

    return;
}

BOOL func_02048610(void * arg_0, void * arg_1)
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

        if (func_02047b3c(arg_0, r8->unk_00) && func_02047b3c(arg_1, r8->unk_04))
        {
            r5 = TRUE;
        }
        else if (r8->unk_0c != 0)
        {
            if (func_02047b3c(arg_0, r8->unk_04) && func_02047b3c(arg_1, r8->unk_00))
            {
                r5 = TRUE;
            }
        }

        if (r5 == 0)
        {
            r0 = FALSE;
        }
        else
        {
            if (CheckEventFlagMaybe(r8->unk_08) == 0)
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

BOOL func_020486f4(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    void * uVar2;
    void * uVar3;

    if (CheckEventFlagMaybe(GetEventStr(arg_0, arg_0->args[3])) == 0)
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

BOOL func_020487a4(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3)
{
    struct EventProc * proc;
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;

    if (CheckEventTrigger(0x15, func_020486f4, &input) == 0)
    {
        return FALSE;
    }

    proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_EventCaller;
        proc->unk_38 = NULL;
        proc->unk_3c = 0x15;
        proc->unk_40 = func_020486f4;
        func_020a5780(&input, &proc->unk_44, 0x20);
        if (arg_3 != 0)
        {
            proc->unk_64 = data_021974f0;
            data_021974f0 = arg_3;
            proc->unk_68 = 1;
        }
        else
        {
            proc->unk_64 = 0;
            proc->unk_68 = 0;
        }

        for (proc->unk_38 = func_02035b98(proc->unk_38); proc->unk_38 != NULL;
             proc->unk_38 = func_02035b98(proc->unk_38))
        {
            if (proc->unk_38->type != proc->unk_3c)
            {
                continue;
            }

            if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
            {
                continue;
            }

            if (!func_020475cc(proc->unk_38, proc))
            {
                continue;
            }

            goto _exit;
        }

        Proc_End(proc);
    }

_exit:
    return TRUE;
}

BOOL CheckBattleTalkEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    void * uVar2;
    void * uVar3;

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

BOOL TryStartBattleTalkEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3)
{
    struct EventProc * proc;
    struct EventFuncInput input;

    input.unk_00 = arg_1;
    input.unk_04 = arg_2;

    if (CheckEventTrigger(9, CheckBattleTalkEventTrigger, &input) == 0)
    {
        return FALSE;
    }

    proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

    if (proc != NULL)
    {
        proc->proc_funcTable = &ProcFuncTable_EventCaller;
        proc->unk_38 = NULL;
        proc->unk_3c = 9;
        proc->unk_40 = CheckBattleTalkEventTrigger;
        func_020a5780(&input, &proc->unk_44, 0x20);
        if (arg_3 != 0)
        {
            proc->unk_64 = data_021974f0;
            data_021974f0 = arg_3;
            proc->unk_68 = 1;
        }
        else
        {
            proc->unk_64 = 0;
            proc->unk_68 = 0;
        }
        proc->unk_38 = func_02035b98(proc->unk_38);

        for (; proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
        {
            if (proc->unk_38->type != proc->unk_3c)
            {
                continue;
            }

            if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
            {
                continue;
            }

            if (!func_020475cc(proc->unk_38, proc))
            {
                continue;
            }

            goto _exit;
        }

        Proc_End(proc);
    }

_exit:
    return TRUE;
}

BOOL func_02048aac(u32 arg_0, u32 arg_1)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;
    input.unk_04 = arg_1;

    return CheckEventTrigger(9, CheckBattleTalkEventTrigger, &input) & 0xFF;
}

BOOL CheckDeathEventTrigger(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
{
    if (!func_02047aec(GetEventStr(arg_0, arg_0->args[0]), (char *)arg_1->unk_00))
    {
        return FALSE;
    }

    return TRUE;
}

BOOL TryStartDeathEvent(ProcPtr parent, u32 arg_1, u32 arg_2)
{
    struct EventProc * proc;
    struct EventFuncInput input;

    if (arg_1 == 0)
    {
        return FALSE;
    }

    input.unk_00 = arg_1;

    if (CheckEventTrigger(0xb, CheckDeathEventTrigger, &input))
    {
        proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

        if (proc != NULL)
        {
            proc->proc_funcTable = &ProcFuncTable_EventCaller;
            proc->unk_38 = NULL;
            proc->unk_3c = 0xb;
            proc->unk_40 = CheckDeathEventTrigger;
            func_020a5780(&input, &proc->unk_44, 0x20);
            if (arg_2 != 0)
            {
                proc->unk_64 = data_021974f0;
                data_021974f0 = arg_2;
                proc->unk_68 = 1;
            }
            else
            {
                proc->unk_64 = 0;
                proc->unk_68 = 0;
            }
            proc->unk_38 = func_02035b98(proc->unk_38);

            for (; proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
            {
                if (proc->unk_38->type != proc->unk_3c)
                {
                    continue;
                }

                if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
                {
                    continue;
                }

                if (!func_020475cc(proc->unk_38, proc))
                {
                    continue;
                }

                goto _exit1;
            }

            Proc_End(proc);
        }
    _exit1:
        return TRUE;
    }
    else if (CheckEventTrigger(0xa, CheckDeathEventTrigger, &input))
    {
        proc = Proc_StartBlocking(ProcScr_EventCaller, parent);

        if (proc != NULL)
        {
            proc->proc_funcTable = &ProcFuncTable_EventCaller;
            proc->unk_38 = NULL;
            proc->unk_3c = 0xa;
            proc->unk_40 = CheckDeathEventTrigger;
            func_020a5780(&input, &proc->unk_44, 0x20);
            if (arg_2 != 0)
            {
                proc->unk_64 = data_021974f0;
                data_021974f0 = arg_2;
                proc->unk_68 = 1;
            }
            else
            {
                proc->unk_64 = 0;
                proc->unk_68 = 0;
            }
            proc->unk_38 = func_02035b98(proc->unk_38);

            for (; proc->unk_38 != NULL; proc->unk_38 = func_02035b98(proc->unk_38))
            {
                if (proc->unk_38->type != proc->unk_3c)
                {
                    continue;
                }

                if (!proc->unk_40(proc->unk_38, (struct EventFuncInput *)&proc->unk_44))
                {
                    continue;
                }

                if (!func_020475cc(proc->unk_38, proc))
                {
                    continue;
                }

                goto _exit2;
            }

            Proc_End(proc);
        }
    _exit2:
        return TRUE;
    }

    return FALSE;
}

BOOL func_02048d3c(int arg_0)
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

BOOL func_02048da0(struct EventInfo * arg_0, struct EventFuncInput * arg_1)
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

BOOL func_02048dd4(u32 arg_0)
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
        if (it->type != 0x16)
        {
            continue;
        }

        if (!func_02048da0(it, &input))
        {
            continue;
        }

        func_020475cc(it, PROC_TREE_9);
    }

    return 1;
}

BOOL func_02048e60(u32 arg_0)
{
    struct EventFuncInput input;

    input.unk_00 = arg_0;

    if (CheckEventTrigger(0x16, func_02048da0, &input) != 0)
    {
        return TRUE;
    }

    return FALSE;
}

void * func_02048e94(struct EventProc * proc)
{
    proc->proc_funcTable = &ProcFuncTable_EventCaller;

    if (proc->unk_68 != 0)
    {
        data_021974f0 = proc->unk_64;
    }

    func_020115a4(proc);

    return proc;
}

void * func_02048ed0(struct EventProc * proc)
{
    proc->proc_funcTable = &ProcFuncTable_EventCaller;

    if (proc->unk_68 != 0)
    {
        data_021974f0 = proc->unk_64;
    }

    return proc;
}
