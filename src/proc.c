#include "global.h"

#include "unknown_funcs.h"
#include "unknown_data.h"
#include "proc.h"

// TODO: Fix declaration; included via "hardware.hpp"
extern void * data_027e1268;

// .bss

extern struct Proc gProcArray[0x80];
extern struct Proc * gProcAllocList[0x80 + 1];
extern struct Proc * gProcTreeRootArray[14];
extern struct Unknown02190ce0 data_02190ce0;

#pragma force_active on

void Proc_Init(void)
{
    struct Proc * it = gProcArray;
    s32 i;

    for (i = 0; i < 0x80; i++, it++)
    {
        it->proc_funcTable = NULL;
        it->proc_script = NULL;
        it->proc_scrCur = NULL;
        it->proc_endCb = NULL;
        it->proc_idleCb = NULL;
        it->unk_14 = NULL;
        it->proc_parent = NULL;
        it->proc_child = NULL;
        it->proc_next = NULL;
        it->proc_prev = NULL;
        it->unk_28 = NULL;
        it->unk_2c = NULL;
        it->proc_sleepTime = 0;
        it->proc_mark = 0;
        it->proc_flags = 0x80;
        it->proc_lockCnt = 0;

        gProcAllocList[i] = it;
    }

    gProcAllocList[0x80] = NULL;
    data_02190ce0.unk_00 = gProcAllocList;

    for (i = 0; i < 14; i++)
    {
        gProcTreeRootArray[i] = NULL;
    }

    return;
}

ProcPtr Proc_Find(struct ProcCmd * script)
{
    struct Proc ** it;

    for (it = gProcAllocList; it < data_02190ce0.unk_00; it++)
    {
        struct Proc * other = *it;

        if (other->proc_script != script)
        {
            continue;
        }

        return other;
    }

    return NULL;
}

struct Proc * func_02018d40(struct ProcCmd * script)
{
    struct Proc ** it;

    for (it = gProcAllocList; it < data_02190ce0.unk_00; it++)
    {
        struct Proc * other = *it;

        if (other->unk_28 != data_027e1268)
        {
            continue;
        }

        if (other->proc_script != script)
        {
            continue;
        }

        return other;
    }

    return NULL;
}

struct Proc * func_02018d9c(struct ProcCmd * script, struct Proc * proc)
{
    struct Proc ** it;

    for (it = gProcAllocList; it < data_02190ce0.unk_00; it++)
    {
        struct Proc * other = *it;

        if (other == proc)
        {
            continue;
        }

        if (other->proc_lockCnt != 0)
        {
            continue;
        }

        if (other->proc_script != script)
        {
            continue;
        }

        return other;
    }

    return NULL;
}

struct Proc * func_02018df4(struct ProcCmd * script, struct Proc * proc)
{
    struct Proc ** it;

    for (it = gProcAllocList; it < data_02190ce0.unk_00; it++)
    {
        struct Proc * other = *it;

        if (other == proc)
        {
            continue;
        }

        if (other->proc_lockCnt == 0)
        {
            continue;
        }

        if (other->proc_script != script)
        {
            continue;
        }

        return other;
    }

    return NULL;
}

struct Proc * func_02018e4c(u32 mark)
{
    struct Proc ** it;

    for (it = gProcAllocList; it < data_02190ce0.unk_00; it++)
    {
        struct Proc * proc = *it;

        if (proc->proc_mark != mark)
        {
            continue;
        }

        return proc;
    }

    return NULL;
}

struct Proc * func_02018e90(struct ProcCmd * script, u32 mark)
{
    struct Proc ** it;

    for (it = gProcAllocList; it < data_02190ce0.unk_00; it++)
    {
        struct Proc * proc = *it;

        if (proc->proc_script != script)
        {
            continue;
        }

        if (proc->proc_mark != mark)
        {
            continue;
        }

        return proc;
    }

    return NULL;
}

void Proc_SetMark(struct Proc * proc, u32 mark)
{
    proc->proc_mark = mark;
    return;
}

void Proc_Goto(ProcPtr proc, s32 label, s32 unk)
{
    struct Proc * p = proc;
    struct ProcCmd * cmd = p->proc_script;

    if (cmd->opcode == 0)
    {
        return;
    }

    for (cmd = p->proc_script; cmd->opcode != 0; cmd++)
    {
        if (cmd->opcode == PROC_CMD_LABEL && cmd->dataImm == label)
        {
            p->proc_scrCur = cmd;
            p->proc_idleCb = NULL;

            if (unk != 0)
            {
                p->proc_flags |= 0x20;
            }

            return;
        }
    }

    return;
}

void Proc_GotoScript(struct Proc * proc, struct ProcCmd * script)
{
    proc->proc_script = script;
    proc->proc_scrCur = script;

    proc->proc_idleCb = NULL;

    return;
}

void Proc_SetEndFunc(struct Proc * proc, ProcFunc func)
{
    proc->proc_endCb = func;
    return;
}

void func_02018f54(struct Proc * proc, void * unk_14)
{
    proc->unk_14 = unk_14;
    return;
}

void * func_02018f5c(struct Proc * proc)
{
    return proc->unk_14;
}

void Proc_ForEach(struct ProcCmd * script, ProcFunc func)
{
    struct Proc * it = gProcArray;
    s32 i;

    for (i = 0; i < 0x80; i++, it++)
    {
        if (it->proc_script != script)
        {
            continue;
        }

        func(it);
    }

    return;
}

void func_02018fa4(struct ProcCmd * script, ProcFunc func)
{
    struct Proc * it = gProcArray;
    s32 i;

    for (i = 0; i < 0x80; i++, it++)
    {
        if (it->proc_script != script)
        {
            continue;
        }

        if (it->unk_28 != data_027e1268)
        {
            continue;
        }

        func(it);
    }

    return;
}

void Proc_BreakEach(struct ProcCmd * script)
{
    Proc_ForEach(script, (ProcFunc)Proc_Break); // Possible bug - mismatched function declaration
    return;
}

void func_0201900c(struct ProcCmd * script)
{
    func_02018fa4(script, (ProcFunc)Proc_Break); // Possible bug - mismatched function declaration
    return;
}

void Proc_EndEach(struct ProcCmd * script)
{
    Proc_ForEach(script, Proc_End);
    return;
}

void func_02019034(struct ProcCmd * script)
{
    func_02018fa4(script, Proc_End);
    return;
}

void Proc_EndEachMarked(u32 mark)
{
    struct Proc * it = gProcArray;
    s32 i;

    for (i = 0; i < 0x80; i++, it++)
    {
        if (it->proc_script == NULL)
        {
            continue;
        }

        if (it->proc_mark != mark)
        {
            continue;
        }

        Proc_End(it);
    }

    return;
}

void Proc_Lock(struct Proc * proc)
{
    proc->proc_lockCnt++;
    return;
}

void Proc_Release(struct Proc * proc)
{
    proc->proc_lockCnt--;
    return;
}

BOOL IsProcLocked(struct Proc * proc)
{
    return proc->proc_lockCnt != 0;
}

struct ProcCmd * func_020190c4(struct Proc * proc)
{
    return proc->proc_script;
}

struct Proc * func_020190cc(struct Proc * proc)
{
    if (IsRootProcess(proc->proc_parent))
    {
        return NULL;
    }

    return proc->proc_parent;
}

void func_020190ec(struct Proc * proc)
{
    if (IsRootProcess(proc->proc_parent))
    {
        return;
    }

    proc->proc_flags |= 2;
    ((struct Proc *)(proc->proc_parent))->proc_lockCnt++;

    return;
}

void func_02019124(struct Proc * proc)
{
    if (IsRootProcess(proc->proc_parent))
    {
        return;
    }

    if (!(proc->proc_flags & 2))
    {
        return;
    }

    proc->proc_flags &= ~2;
    ((struct Proc *)(proc->proc_parent))->proc_lockCnt--;

    return;
}

void func_02019164(struct Proc * proc)
{
    if (IsRootProcess(proc->proc_parent))
    {
        return;
    }

    Proc_End(proc->proc_parent);

    return;
}

struct Proc * Proc_GetChild(struct Proc * proc)
{
    return proc->proc_child;
}

BOOL func_02019190(struct Proc * proc, u32 flags)
{
    struct Proc ** it;

    for (it = gProcAllocList; it < data_02190ce0.unk_00; it++)
    {
        struct Proc * other = *it;

        if (other == proc)
        {
            continue;
        }

        if (other->proc_script != proc->proc_script)
        {
            continue;
        }

        if (flags & 1)
        {
            if (other->unk_28 != data_027e1268)
            {
                continue;
            }
        }

        if (!(flags & 2) || (other->proc_funcTable != NULL) && (other->proc_funcTable == proc->proc_funcTable))
        {
            Proc_End(proc);
            return FALSE;
        }
    }

    return TRUE;
}

BOOL func_02019230(struct Proc * proc, u32 flags)
{
    struct Proc ** it;

    for (it = gProcAllocList; it < data_02190ce0.unk_00; it++)
    {
        struct Proc * other = *it;

        if (other == proc)
        {
            continue;
        }

        if (other->proc_script != proc->proc_script)
        {
            continue;
        }

        if (flags & 1)
        {
            if (other->unk_28 != data_027e1268)
            {
                continue;
            }
        }

        if (!(flags & 2) || (other->proc_funcTable != NULL) && (other->proc_funcTable == proc->proc_funcTable))
        {
            Proc_End(other);
            break;
        }
    }

    return TRUE;
}

struct UnkProc_020ce710
{
    /* 00 */ PROC_HEADER
    /* 36 */ STRUCT_PAD(0x36, 0x38);
    /* 38 */ void (*unk_38)(void *);
    /* 3C */ STRUCT_PAD(0x3C, 0x58);
    /* 58 */ s16 unk_58;
};

void func_020192d0(struct UnkProc_020ce710 * proc)
{
    proc->unk_58--;

    if (proc->unk_58 > 0)
    {
        return;
    }

    Proc_End(proc);

    return;
}

void func_020192f4(struct UnkProc_020ce710 * proc)
{
    proc->unk_38(proc);
    Proc_End(proc);
    return;
}

void func_02019310(void * func, ProcPtr parent)
{
    struct UnkProc_020ce710 * proc = Proc_Start(ProcScr_020ce6f0, parent);
    proc->unk_38 = func;
    return;
}

void func_0201932c(struct UnkProc_020ce710 * proc)
{
    proc->unk_38(proc);
    return;
}

void func_0201933c(void * func, ProcPtr parent)
{
    struct UnkProc_020ce710 * proc = Proc_Start(ProcScr_020ce710, parent);
    proc->unk_38 = func;
    return;
}

BOOL ProcCmd_End(ProcPtr proc)
{
    Proc_End(proc);
    return FALSE;
}

BOOL func_02019368(ProcPtr proc)
{
    return FALSE;
}

BOOL func_02019370(ProcPtr proc)
{
    return TRUE;
}

BOOL func_02019378(ProcPtr proc)
{
    struct Proc * p = proc;
    p->proc_scrCur++;
    return TRUE;
}

BOOL ProcCmd_SetEndFunc(ProcPtr proc)
{
    struct Proc * p = proc;
    Proc_SetEndFunc(proc, p->proc_scrCur->dataPtr);
    p->proc_scrCur++;
    return TRUE;
}

BOOL func_020193b4(ProcPtr proc)
{
    struct Proc * p = proc;
    func_02018f54(proc, p->proc_scrCur->dataPtr);
    p->proc_scrCur++;
    return TRUE;
}

BOOL ProcCmd_Call(ProcPtr proc)
{
    struct Proc * p = proc;
    ProcFunc func = p->proc_scrCur->dataPtr;
    p->proc_scrCur++;

    func(proc);

    return TRUE;
}

BOOL ProcCmd_CallArg(ProcPtr proc)
{
    struct Proc * p = proc;
    s16 arg = p->proc_scrCur->dataImm;
    BOOL (*func)(ProcPtr, s16) = p->proc_scrCur->dataPtr;

    p->proc_scrCur++;
    func(proc, arg);

    return TRUE;
}

BOOL ProcCmd_While(ProcPtr proc)
{
    struct Proc * p = proc;
    BOOL (*func)(ProcPtr) = p->proc_scrCur->dataPtr;
    p->proc_scrCur++;

    if (func(proc))
    {
        p->proc_scrCur--;
        return FALSE;
    }

    return TRUE;
}

BOOL ProcCmd_WhileArg(ProcPtr proc)
{
    struct Proc * p = proc;
    s16 arg = p->proc_scrCur->dataImm;
    BOOL (*func)(ProcPtr, s16) = p->proc_scrCur->dataPtr;

    p->proc_scrCur++;

    if (func(proc, arg))
    {
        p->proc_scrCur--;
        return FALSE;
    }

    return TRUE;
}

void func_0201949c(void * arg_0, void * arg_1)
{
    struct Unknown_func_01ffb934_ret * cast_0;
    struct Unknown_func_01ffb934_ret * cast_1;

    cast_0 = arg_0;

    if (data_020ce6ec == cast_0->unk_6c)
    {
        data_02190ce0.unk_08 = data_027e1268;
        data_027e1268 = data_02190ce0.unk_04;
    }

    cast_1 = arg_1;

    if (data_020ce6ec == cast_1->unk_6c)
    {
        data_02190ce0.unk_04 = data_027e1268;
        data_027e1268 = data_02190ce0.unk_08;
    }

    return;
}

void func_020194fc(void * unused)
{
    data_020ce6ec = -1;
    func_020a36ac(NULL);
}

// TODO: Convert this file to *.cpp and #include "heap.hpp"
extern u8 gHeap[];
EC void _ZN4Heap4FreeEPv(void *, void *);
EC void * _ZN4Heap5AllocEm(void *, u32);

BOOL func_0201951c(ProcPtr proc)
{
    struct Proc * p = proc;
    void * (*func)(void *);
    struct Unknown_func_01ffb934_ret * unk;

    if (p->proc_flags & 0x40)
    {
        if (!func_020a3350(p->unk_2c))
        {
            return FALSE;
        }

        _ZN4Heap4FreeEPv(&gHeap, p->unk_2c);

        p->unk_2c = 0;
        p->proc_flags &= ~0x40;

        p->proc_scrCur++;

        return TRUE;
    }

    func = p->proc_scrCur->dataPtr;
    unk = _ZN4Heap5AllocEm(&gHeap, 0x10c0);
    func_020a3080(unk, func, proc, ((u8 *)unk) + 0x10c0, 0x1000, 0x13);

    func_020a374c(unk, func_020194fc);

    data_02190ce0.unk_08 = p->unk_28;
    data_020ce6ec = unk->unk_6c;

    func_020a36ac(func_0201949c);
    func_020a341c(unk);

    p->unk_2c = unk;
    p->proc_flags |= 0x40;

    return TRUE;
}

BOOL ProcCmd_Repeat(ProcPtr proc)
{
    struct Proc * p = proc;
    p->proc_idleCb = p->proc_scrCur->dataPtr;
    p->proc_scrCur++;
    return FALSE;
}

BOOL ProcCmd_WhileExists(ProcPtr proc)
{
    struct Proc * p = proc;
    if (Proc_Find(p->proc_scrCur->dataPtr) == NULL)
    {
        p->proc_scrCur++;
        return TRUE;
    }

    return FALSE;
}

BOOL ProcCmd_SpawnChild(ProcPtr proc)
{
    struct Proc * p = proc;
    Proc_Start(p->proc_scrCur->dataPtr, proc);
    p->proc_scrCur++;
    return TRUE;
}

BOOL ProcCmd_SpawnLockChild(ProcPtr proc)
{
    struct Proc * p = proc;
    Proc_StartBlocking(p->proc_scrCur->dataPtr, proc);
    p->proc_scrCur++;
    return FALSE;
}

BOOL ProcCmd_SpawnChildInTree(ProcPtr proc)
{
    struct Proc * p = proc;
    Proc_Start(p->proc_scrCur->dataPtr, (void *)(u32)p->proc_scrCur->dataImm);
    p->proc_scrCur++;
    return TRUE;
}

BOOL func_020196f8(ProcPtr proc)
{
    struct Proc * p = proc;
    if (p->proc_scrCur->dataImm != 0)
    {
        func_02019034(p->proc_scrCur->dataPtr);
    }
    else
    {
        Proc_EndEach(p->proc_scrCur->dataPtr);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL func_02019734(ProcPtr proc)
{
    struct Proc * p = proc;
    if (p->proc_scrCur->dataImm != 0)
    {
        func_0201900c(p->proc_scrCur->dataPtr);
    }
    else
    {
        Proc_BreakEach(p->proc_scrCur->dataPtr);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL ProcCmd_Goto(ProcPtr proc)
{
    struct Proc * p = proc;
    Proc_Goto(proc, p->proc_scrCur->dataImm, 0);
    p->proc_scrCur++;
    return TRUE;
}

BOOL ProcCmd_GotoIfYes(ProcPtr proc)
{
    struct Proc * p = proc;
    BOOL (*func)(ProcPtr) = p->proc_scrCur->dataPtr;

    if (func == NULL || func(proc))
    {
        Proc_Goto(proc, p->proc_scrCur->dataImm, 0);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL ProcCmd_GotoIfNo(ProcPtr proc)
{
    struct Proc * p = proc;
    BOOL (*func)(ProcPtr) = p->proc_scrCur->dataPtr;

    if (func == NULL || !func(proc))
    {
        Proc_Goto(proc, p->proc_scrCur->dataImm, 0);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL ProcCmd_Jump(ProcPtr proc)
{
    struct Proc * p = proc;
    Proc_GotoScript(proc, p->proc_scrCur->dataPtr);
    return TRUE;
}

void SleepRepeatFunc(ProcPtr proc)
{
    struct Proc * p = proc;
    p->proc_sleepTime--;

    if (p->proc_sleepTime != 0)
    {
        return;
    }

    Proc_Break(proc, 0);

    return;
}

BOOL ProcCmd_Sleep(ProcPtr proc)
{
    struct Proc * p = proc;
    if (p->proc_scrCur->dataImm != 0)
    {
        p->proc_sleepTime = p->proc_scrCur->dataImm;
        p->proc_idleCb = (void *)SleepRepeatFunc;
    }

    p->proc_scrCur++;

    return FALSE;
}

BOOL ProcCmd_Mark(ProcPtr proc)
{
    struct Proc * p = proc;
    p->proc_mark = p->proc_scrCur->dataImm;
    p->proc_scrCur++;
    return TRUE;
}

BOOL func_020198c4(ProcPtr proc)
{
    struct Proc * p = proc;
    if (!func_02019190(proc, p->proc_scrCur->dataImm))
    {
        return FALSE;
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL func_020198f8(ProcPtr proc)
{
    struct Proc * p = proc;
    if (!func_02019190(proc, p->proc_scrCur->dataImm))
    {
        return FALSE;
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL func_0201992c(ProcPtr proc)
{
    struct Proc * p = proc;
    func_02019230(proc, p->proc_scrCur->dataImm);
    p->proc_scrCur++;
    return TRUE;
}

BOOL func_02019954(ProcPtr proc)
{
    struct Proc * p = proc;
    p->proc_scrCur++;
    return TRUE;
}

BOOL func_02019968(ProcPtr proc)
{
    struct Proc * p = proc;
    u8 flag = ((u32)p->proc_scrCur->dataPtr) & 2 ? 1 : 0;

    if (!(((u32)p->proc_scrCur->dataPtr) & 1))
    {
        StartFadeIn_0201d9a0(proc, p->proc_scrCur->dataImm, flag);
    }
    else
    {
        StartBlockingFadeIn_0201da48(proc, p->proc_scrCur->dataImm, flag);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL func_020199b8(ProcPtr proc)
{
    struct Proc * p = proc;
    u8 flag = ((u32)p->proc_scrCur->dataPtr) & 2 ? 1 : 0;

    if (!(((u32)p->proc_scrCur->dataPtr) & 1))
    {
        StartFadeOut_0201d9f4(proc, p->proc_scrCur->dataImm, flag);
    }
    else
    {
        StartBlockingFadeOut_0201da98(proc, p->proc_scrCur->dataImm, flag);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL ProcCmd_FadeInFromBlack(ProcPtr proc)
{
    struct Proc * p = proc;
    u8 target = ((u32)p->proc_scrCur->dataPtr) & 2 ? 1 : 0;

    if (!(((u32)p->proc_scrCur->dataPtr) & 1))
    {
        StartFadeInFromBlack(proc, p->proc_scrCur->dataImm, target);
    }
    else
    {
        StartBlockingFadeInFromBlack(proc, p->proc_scrCur->dataImm, target);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL ProcCmd_FadeOutToBlack(ProcPtr proc)
{
    struct Proc * p = proc;
    u8 target = ((u32)p->proc_scrCur->dataPtr) & 2 ? 1 : 0;

    if (!(((u32)p->proc_scrCur->dataPtr) & 1))
    {
        StartFadeOutToBlack(proc, p->proc_scrCur->dataImm, target);
    }
    else
    {
        StartBlockingFadeOutToBlack(proc, p->proc_scrCur->dataImm, target);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL ProcCmd_FadeInFromWhite(ProcPtr proc)
{
    struct Proc * p = proc;
    u8 target = ((u32)p->proc_scrCur->dataPtr) & 2 ? 1 : 0;

    if (!(((u32)p->proc_scrCur->dataPtr) & 1))
    {
        StartFadeInFromWhite(proc, p->proc_scrCur->dataImm, target);
    }
    else
    {
        StartBlockingFadeInFromWhite(proc, p->proc_scrCur->dataImm, target);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL ProcCmd_FadeOutToWhite(ProcPtr proc)
{
    struct Proc * p = proc;
    u8 target = ((u32)p->proc_scrCur->dataPtr) & 2 ? 1 : 0;

    if (!(((u32)p->proc_scrCur->dataPtr) & 1))
    {
        StartFadeOutToWhite(proc, p->proc_scrCur->dataImm, target);
    }
    else
    {
        StartBlockingFadeOutToWhite(proc, p->proc_scrCur->dataImm, target);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL ProcCmd_Overlay(ProcPtr proc)
{
    struct Proc * p = proc;
    if (p->proc_scrCur->dataPtr != 0)
    {
        LoadOverlay(p->proc_scrCur->dataImm);
    }
    else
    {
        UnloadOverlay(p->proc_scrCur->dataImm);
    }

    p->proc_scrCur++;

    return TRUE;
}

BOOL func_02019b84(ProcPtr proc)
{
    struct Proc * p = proc;
    func_0200f28c(p->proc_scrCur->dataImm);
    p->proc_scrCur++;
    return TRUE;
}

void func_02019bac(ProcPtr proc)
{
    struct Proc * p = proc;
    p->proc_funcTable->unk_08(proc);
    return;
}

void func_02019bc0(ProcPtr proc)
{
    struct Proc * p = proc;
    p->proc_funcTable->unk_0C(proc);
    return;
}

#pragma force_active reset
