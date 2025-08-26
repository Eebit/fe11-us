#ifndef PROC_EX_HPP
#define PROC_EX_HPP

#include "proc.h"

class ProcEx
{
public:
    // /* 00 */ vtable;
    /* 04 */ struct ProcCmd * proc_script;
    /* 08 */ struct ProcCmd * proc_scrCur;
    /* 0C */ ProcFunc proc_endCb;
    /* 10 */ ProcFunc proc_idleCb;
    /* 14 */ ProcFunc unk_14;
    /* 18 */ ProcPtr proc_parent;
    /* 1C */ ProcPtr proc_child;
    /* 20 */ ProcPtr proc_next;
    /* 24 */ ProcPtr proc_prev;
    /* 28 */ void * unk_28;
    /* 2C */ void * unk_2c;
    /* 30 */ s16 proc_sleepTime;
    /* 32 */ u16 proc_flags;
    /* 34 */ u8 proc_mark;
    /* 35 */ u8 proc_lockCnt;

    virtual void Init();
    virtual void Loop();
};

void ProcEx::Init()
{
    return;
}

void ProcEx::Loop()
{
    return;
}

#endif // PROC_EX_HPP