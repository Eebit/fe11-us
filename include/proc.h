#ifndef PROC_H
#define PROC_H

#include "types.h"

enum
{
    PROC_CMD_END = 0x00,
    PROC_CMD_01 = 0x01,
    PROC_CMD_02 = 0x02,
    PROC_CMD_03 = 0x03,
    PROC_CMD_04 = 0x04,
    PROC_CMD_ONEND = 0x05,
    PROC_CMD_06 = 0x06,
    PROC_CMD_CALL = 0x07,
    PROC_CMD_CALL_ARG = 0x08,
    PROC_CMD_09 = 0x09,
    PROC_CMD_0A = 0x0A,
    PROC_CMD_0B = 0x0B,
    PROC_CMD_0C = 0x0C,
    PROC_CMD_0D = 0x0D,
    PROC_CMD_START_CHILD = 0x0E,
    PROC_CMD_START_CHILD_BLOCKING = 0x0F,
    PROC_CMD_START_IN_TREE = 0x10,
    PROC_CMD_11 = 0x11,
    PROC_CMD_12 = 0x12,
    PROC_CMD_LABEL = 0x13,
    PROC_CMD_GOTO = 0x14,
    PROC_CMD_GOTO_IF_YES = 0x15,
    PROC_CMD_GOTO_IF_NO = 0x16,
    PROC_CMD_JUMP = 0x17,
    PROC_CMD_SLEEP = 0x18,
    PROC_CMD_MARK = 0x19,
    PROC_CMD_1A = 0x1A,
    PROC_CMD_1B = 0x1B,
    PROC_CMD_1C = 0x1C,
    PROC_CMD_NOP_1D = 0x1D, // maybe PROC_CMD_NAME?
    PROC_CMD_1E = 0x1E,
    PROC_CMD_1F = 0x1F,
    PROC_CMD_20 = 0x20,
    PROC_CMD_21 = 0x21,
    PROC_CMD_22 = 0x22,
    PROC_CMD_23 = 0x23,
    PROC_CMD_OVERLAY = 0x24,
    PROC_CMD_25 = 0x25,
};

struct ProcCmd
{
    /* 00 */ s16 opcode;
    /* 02 */ s16 dataImm;
    /* 04 */ void * dataPtr;
};

struct Proc;

typedef void (*ProcFunc)(struct Proc *);

struct ProcFuncTable
{
    /* 00 */ ProcFunc unk_00; // End Callback?
    /* 04 */ ProcFunc unk_04; // ?
    /* 08 */ ProcFunc unk_08; // Init?
    /* 0C */ ProcFunc unk_0C; // Main Loop?
};

struct Proc
{
    /* 00 */ struct ProcFuncTable * proc_funcTable;
    /* 04 */ struct ProcCmd * proc_script;
    /* 08 */ struct ProcCmd * proc_scrCur;
    /* 0C */ ProcFunc proc_endCb;
    /* 10 */ ProcFunc proc_idleCb;
    /* 14 */ ProcFunc unk_14;
    /* 18 */ struct Proc * proc_parent;
    /* 1C */ struct Proc * proc_child;
    /* 20 */ struct Proc * proc_next;
    /* 24 */ struct Proc * proc_prev;
    /* 28 */ void * unk_28; // maybe child?
    /* 2C */ void * unk_2c;
    /* 30 */ s16 proc_sleepTime;
    /* 32 */ u16 proc_flags;
    /* 34 */ u8 proc_mark;
    /* 35 */ u8 proc_lockCnt;
    STRUCT_PAD(0x36, 0x38);
    /* 38 */ void (*unk_38)(void *);
    STRUCT_PAD(0x3C, 0x58);
    /* 58 */ s16 unk_58;
    STRUCT_PAD(0x5A, 0x78);
};

struct Unknown02190ce0
{
    /* 00 */ struct Proc ** unk_00;
    /* 04 */ void * unk_04;
    /* 08 */ void * unk_08;
};

extern BOOL ProcCmd_End(struct Proc *);
extern BOOL func_02019368(struct Proc *);
extern BOOL func_02019370(struct Proc *);
extern BOOL func_02019378(struct Proc *);
extern BOOL ProcCmd_SetEndFunc(struct Proc *);
extern BOOL func_020193b4(struct Proc *);
extern BOOL ProcCmd_Call(struct Proc *);
extern BOOL ProcCmd_CallArg(struct Proc *);
extern BOOL ProcCmd_While(struct Proc *);
extern BOOL ProcCmd_WhileArg(struct Proc *);
extern BOOL func_0201951c(struct Proc *);
extern BOOL ProcCmd_Repeat(struct Proc *);
extern BOOL ProcCmd_WhileExists(struct Proc *);
extern BOOL ProcCmd_SpawnChild(struct Proc *);
extern BOOL ProcCmd_SpawnLockChild(struct Proc *);
extern BOOL ProcCmd_SpawnChildInTree(struct Proc *);
extern BOOL func_020196f8(struct Proc *);
extern BOOL func_02019734(struct Proc *);
extern BOOL func_02019954(struct Proc *);
extern BOOL ProcCmd_Goto(struct Proc *);
extern BOOL ProcCmd_GotoIfYes(struct Proc *);
extern BOOL ProcCmd_GotoIfNo(struct Proc *);
extern BOOL ProcCmd_Jump(struct Proc *);
extern BOOL ProcCmd_Sleep(struct Proc *);
extern BOOL ProcCmd_Mark(struct Proc *);
extern BOOL func_020198c4(struct Proc *);
extern BOOL func_020198f8(struct Proc *);
extern BOOL func_0201992c(struct Proc *);
extern BOOL func_02019954(struct Proc *);
extern BOOL func_02019968(struct Proc *);
extern BOOL func_020199b8(struct Proc *);
extern BOOL func_02019a08(struct Proc *);
extern BOOL func_02019a58(struct Proc *);
extern BOOL func_02019aa8(struct Proc *);
extern BOOL func_02019af8(struct Proc *);
extern BOOL ProcCmd_Overlay(struct Proc *);
extern BOOL func_02019b84(struct Proc *);

extern struct Proc gProcArray[0x80];
extern struct Proc * gProcAllocList[0x80 + 1];
extern struct Proc * gProcTreeRootArray[14];
extern struct Unknown02190ce0 data_02190ce0;

#endif // PROC_H
