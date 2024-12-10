#include "global.h"

#include "proc.h"

// TODO: "nds/io_reg.h"
#define REG_IME (*(vu16 *)(0x04000208))

extern void * func_020a4a38(void);
extern void func_020a4a4c(void *);

extern u8 data_027e1258;
extern u8 data_027e125c;

BOOL (* const data_01ffbbf8[])(struct Proc *) =
{
    [PROC_CMD_END] = ProcCmd_End,
    [PROC_CMD_01] = ProcCmd_End,
    [PROC_CMD_02] = func_02019368,
    [PROC_CMD_03] = func_02019370,
    [PROC_CMD_04] = func_02019378,
    [PROC_CMD_ONEND] = ProcCmd_SetEndFunc,
    [PROC_CMD_06] = func_020193b4,
    [PROC_CMD_CALL] = ProcCmd_Call,
    [PROC_CMD_CALL_ARG] = ProcCmd_CallArg,
    [PROC_CMD_09] = ProcCmd_While,
    [PROC_CMD_0A] = ProcCmd_WhileArg,
    [PROC_CMD_0B] = func_0201951c,
    [PROC_CMD_0C] = ProcCmd_Repeat,
    [PROC_CMD_0D] = ProcCmd_WhileExists,
    [PROC_CMD_START_CHILD] = ProcCmd_SpawnChild,
    [PROC_CMD_START_CHILD_BLOCKING] = ProcCmd_SpawnLockChild,
    [PROC_CMD_START_IN_TREE] = ProcCmd_SpawnChildInTree,
    [PROC_CMD_11] = func_020196f8,
    [PROC_CMD_12] = func_02019734,
    [PROC_CMD_LABEL] = func_02019954,
    [PROC_CMD_GOTO] = ProcCmd_Goto,
    [PROC_CMD_GOTO_IF_YES] = ProcCmd_GotoIfYes,
    [PROC_CMD_GOTO_IF_NO] = ProcCmd_GotoIfNo,
    [PROC_CMD_JUMP] = ProcCmd_Jump,
    [PROC_CMD_SLEEP] = ProcCmd_Sleep,
    [PROC_CMD_MARK] = ProcCmd_Mark,
    [PROC_CMD_1A] = func_020198c4,
    [PROC_CMD_1B] = func_020198f8,
    [PROC_CMD_1C] = func_0201992c,
    [PROC_CMD_NOP_1D] = func_02019954,
    [PROC_CMD_1E] = func_02019968,
    [PROC_CMD_1F] = func_020199b8,
    [PROC_CMD_20] = func_02019a08,
    [PROC_CMD_21] = func_02019a58,
    [PROC_CMD_22] = func_02019aa8,
    [PROC_CMD_23] = func_02019af8,
    [PROC_CMD_OVERLAY] = ProcCmd_Overlay,
    [PROC_CMD_25] = func_02019b84,
};

struct Proc * func_01ffbc90(u32 treeNum)
{
    return gProcTreeRootArray[treeNum];
}

BOOL func_01ffbca0(struct Proc * proc)
{
    return (u32)proc < 14;
}

void func_01ffbcb0(struct Proc * proc)
{
    if (proc->proc_script == NULL)
    {
        return;
    }

    if (proc->proc_lockCnt != 0)
    {
        return;
    }

    if (proc->proc_idleCb != NULL)
    {
        return;
    }

    while (data_01ffbbf8[proc->proc_scrCur->opcode](proc))
    {
        if (proc->proc_script == NULL)
        {
            return;
        }

        if (proc->proc_lockCnt != 0)
        {
            return;
        }

        if (proc->proc_idleCb != NULL)
        {
            return;
        }
    }

    return;
}

struct Proc * func_01ffbd3c(void)
{
    void * var_0 = func_020a4a38();

    struct Proc ** pAllocHead = data_02190ce0.unk_00;
    struct Proc * proc = *pAllocHead;

    if (proc->proc_flags & 0x10)
    {
        struct Proc ** pAllocHeadBkp = pAllocHead;
        struct Proc * it;

        do
        {
            pAllocHeadBkp++;
            it = *pAllocHeadBkp;
        } while (it->proc_flags & 0x10);

        *pAllocHead = it;
        *pAllocHeadBkp = proc;
        proc = *data_02190ce0.unk_00;
    }

    data_02190ce0.unk_00++;

    func_020a4a4c(var_0);

    return proc;
}

void func_01ffbda4(struct Proc * proc)
{
    struct Proc ** pAllocHead;
    struct Proc * procHead;

    void * var_0 = func_020a4a38();

    data_02190ce0.unk_00--;
    procHead = *data_02190ce0.unk_00;
    pAllocHead = data_02190ce0.unk_00;

    if (procHead != proc)
    {
        do
        {
            pAllocHead--;
        } while (*pAllocHead != proc);

        *pAllocHead = procHead;
        *data_02190ce0.unk_00 = proc;
    }

    func_020a4a4c(var_0);

    return;
}

void func_01ffbdf4(struct Proc * proc, s32 treeNum)
{
    struct Proc ** root = gProcTreeRootArray + treeNum;

    if ((*root) != NULL)
    {
        (*root)->proc_next = proc;
        proc->proc_prev = (*root);
    }

    proc->proc_parent = (struct Proc *)treeNum;
    (*root) = proc;

    return;
}

void func_01ffbe1c(struct Proc * proc, struct Proc * parent)
{
    if (parent->proc_child != NULL)
    {
        parent->proc_child->proc_next = proc;
        proc->proc_prev = parent->proc_child;
    }

    parent->proc_child = proc;
    proc->proc_parent = parent;

    return;
}

void func_01ffbe3c(struct Proc * proc)
{
    if (proc->proc_next != NULL)
    {
        proc->proc_next->proc_prev = proc->proc_prev;
    }

    if (proc->proc_prev != NULL)
    {
        proc->proc_prev->proc_next = proc->proc_next;
    }

    if (!func_01ffbca0(proc->proc_parent))
    {
        if (proc->proc_parent->proc_child == proc)
        {
            proc->proc_parent->proc_child = proc->proc_prev;
        }
    }
    else
    {
        struct Proc ** root = gProcTreeRootArray + (s32)proc->proc_parent;

        if ((*root) == proc)
        {
            (*root) = proc->proc_prev;
        }
    }

    proc->proc_next = NULL;
    proc->proc_prev = NULL;

    return;
}

struct Proc * func_01ffbeb4(struct ProcCmd * script, struct Proc * parent, void * arg_2)
{
    void * tmp;

    struct Proc * proc = func_01ffbd3c();

    proc->proc_script = script;
    proc->proc_scrCur = script;
    proc->proc_endCb = NULL;
    proc->proc_idleCb = NULL;
    proc->unk_14 = NULL;
    proc->proc_parent = NULL;
    proc->proc_child = NULL;
    proc->proc_next = NULL;
    proc->proc_prev = NULL;
    proc->unk_28 = arg_2;
    proc->unk_2c = NULL;
    proc->proc_sleepTime = 0;
    proc->proc_mark = 0;
    proc->proc_lockCnt = 0;
    proc->proc_flags = 0xc;

    if (func_01ffbca0(parent))
    {
        if (parent == NULL)
        {
            parent = (void *)9;
        }

        func_01ffbdf4(proc, (s32)parent);
    }
    else
    {
        func_01ffbe1c(proc, parent);
    }

    tmp = data_027e1268;
    data_027e1268 = arg_2;

    func_01ffbcb0(proc);

    data_027e1268 = tmp;

    proc->proc_flags &= ~4;

    return proc;
}

struct Proc * func_01ffbf78(struct ProcCmd * script, struct Proc * parent)
{
    return func_01ffbeb4(script, parent, data_027e1268);
}

struct Proc * func_01ffbf90(struct ProcCmd * script, struct Proc * parent)
{
    void * var_0 = func_020a4a38();

    struct Proc * proc = func_01ffbf78(script, parent);
    proc->proc_flags |= 4;

    func_020a4a4c(var_0);

    return proc;
}

void func_01ffbfd0(struct Proc * proc)
{
    proc->proc_flags &= ~4;
    return;
}

struct Proc * func_01ffbfe0(struct ProcCmd * script, struct Proc * parent, void * arg_2)
{
    struct Proc * proc = func_01ffbeb4(script, parent, arg_2);

    if (proc->proc_script != NULL)
    {
        proc->proc_flags |= 2;
        proc->proc_parent->proc_lockCnt++;

        return proc;
    }

    return NULL;
}

struct Proc * func_01ffc018(struct ProcCmd * script, struct Proc * parent)
{
    return func_01ffbfe0(script, parent, data_027e1268);
}

struct Proc * func_01ffc030(struct ProcCmd * script, struct Proc * parent)
{
    if (parent == 0)
    {
        parent = (void *)9;
    }

    if (func_01ffbca0(parent))
    {
        return func_01ffbf78(script, parent);
    }

    return func_01ffc018(script, parent);
}

void func_01ffc068(struct Proc * proc)
{
    if (proc->proc_prev != NULL)
    {
        func_01ffc068(proc->proc_prev);
    }

    if (proc->proc_child != NULL)
    {
        func_01ffc068(proc->proc_child);
    }

    proc->proc_flags |= 1;

    return;
}

void func_01ffc0a0(struct Proc * proc)
{
    if (proc->proc_prev != NULL)
    {
        func_01ffc0a0(proc->proc_prev);
    }

    if (proc->proc_child != NULL)
    {
        func_01ffc0a0(proc->proc_child);
    }

    if (proc->proc_flags & 0x80)
    {
        return;
    }

    proc->proc_flags |= 0x80;

    func_01ffbda4(proc);

    return;
}

void func_01ffc0e8(struct Proc * proc)
{
    if (proc->proc_prev != NULL)
    {
        func_01ffc0e8(proc->proc_prev);
    }

    if (proc->proc_child != NULL)
    {
        func_01ffc0e8(proc->proc_child);
    }

    if (proc->proc_endCb != NULL)
    {
        proc->proc_endCb(proc);
    }

    if (proc->proc_funcTable != NULL)
    {
        proc->proc_funcTable->unk_00(proc);
    }

    proc->proc_funcTable = NULL;
    proc->proc_script = NULL;
    proc->proc_scrCur = NULL;
    proc->proc_idleCb = NULL;
    proc->unk_14 = NULL;

    if (!(proc->proc_flags & 2))
    {
        return;
    }

    proc->proc_parent->proc_lockCnt--;

    return;
}

void func_01ffc174(struct Proc * proc)
{
    u16 _bkp;
    u16 ime;

    if (proc == NULL)
    {
        return;
    }

    ime = REG_IME;
    REG_IME = 0;

    if ((proc->proc_script == NULL) || (proc->proc_flags & 1))
    {
        _bkp = REG_IME;
        REG_IME = ime;
        return;
    }

    func_01ffbe3c(proc);
    func_01ffc068(proc);

    _bkp = REG_IME;
    REG_IME = ime;

    func_01ffc0e8(proc);
    func_01ffc0a0(proc);

    return;
}

void func_01ffc1e8(struct Proc * proc)
{
    void * tmp;

    if (proc == NULL)
    {
        return;
    }

    proc->proc_flags |= 0x10;

    if (proc->proc_prev != NULL)
    {
        func_01ffc1e8(proc->proc_prev);
    }

    proc->proc_flags &= ~0x10;

    if (proc->proc_flags & 8)
    {
        if (data_027e125c != 0 && data_027e1258 != 0)
        {
            goto _01ffc2d4;
        }

        proc->proc_flags &= ~8;
    }

    if ((proc->proc_lockCnt == 0) && (!(proc->proc_flags & 4)))
    {
        tmp = data_027e1268;
        data_027e1268 = proc->unk_28;

        do
        {
            proc->proc_flags &= ~0x20;

            if (proc->proc_idleCb == NULL)
            {
                func_01ffbcb0(proc);
            }

            if (proc->proc_idleCb != NULL)
            {
                proc->proc_idleCb(proc);
            }
        } while (proc->proc_flags & 0x20);

        proc->proc_flags &= ~0x20;

        data_027e1268 = tmp;

        if (proc->proc_flags & 1)
        {
            return;
        }
    }

_01ffc2d4:
    if (proc->proc_child != NULL)
    {
        func_01ffc1e8(proc->proc_child);
    }

    return;
}

void func_01ffc2f4(struct Proc * proc)
{
    void * unk;

    if (proc == NULL)
    {
        return;
    }

    proc->proc_flags |= 0x10;

    if (proc->proc_prev != NULL)
    {
        func_01ffc2f4(proc->proc_prev);
    }

    proc->proc_flags &= ~0x10;

    if (!(proc->proc_flags & 8) && !(proc->proc_flags & 4) && (proc->unk_14 != NULL))
    {
        unk = data_027e1268;
        data_027e1268 = proc->unk_28;

        proc->unk_14(proc);

        data_027e1268 = unk;

        if (proc->proc_flags & 1)
        {
            return;
        }
    }

    if (proc->proc_child != NULL)
    {
        func_01ffc2f4(proc->proc_child);
    }

    return;
}

void func_01ffc390(u32 treeNum)
{
    func_01ffc1e8(func_01ffbc90(treeNum));
    func_01ffc2f4(func_01ffbc90(treeNum));
    return;
}

void func_01ffc3b0(struct Proc * proc, s32 arg_1)
{
    if (proc->proc_idleCb != NULL)
    {
        proc->proc_idleCb = NULL;
    }
    else
    {
        if ((proc->proc_scrCur != NULL) && (proc->proc_scrCur->opcode == PROC_CMD_02))
        {
            proc->proc_scrCur++;
        }
    }

    if (arg_1 != 0)
    {
        proc->proc_flags |= 0x20;
    }

    return;
}

void func_01ffc3f4(struct Proc * proc)
{
    proc->proc_scrCur--;
    return;
}
