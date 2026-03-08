#include "global.h"

#include <new>

#include "database.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "hashtable.hpp"
#include "heap.hpp"
#include "map.hpp"
#include "proc_ex.hpp"

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

class ProcTutCardShowForMenu : public ProcEx
{
public:
    s32 unk_38;

    ProcTutCardShowForMenu(s32 param_2)
    {
        this->unk_38 = param_2;
    }

    virtual ~ProcTutCardShowForMenu()
    {
    }

    // _ZN22ProcTutCardShowForMenu4InitEv
    virtual void Init(void);
};

class ProcLineHelp : public ProcEx
{
public:
    char * unk_38;
    char * unk_3c;
    void * unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    u8 unk_64;

    ProcLineHelp()
    {
        VmMap_Common * iVar3;

        this->unk_38 = NULL;
        this->unk_3c = NULL;
        this->unk_40 = NULL;
        this->unk_4c = 0;
        this->unk_44 = 0;
        this->unk_48 = 0;
        this->unk_50 = 0x40;
        this->unk_54 = 0;
        this->unk_64 = 1;

        iVar3 = static_cast<VmMap_Common *>(HashTable::Get2("VmMap_LineHelp"));

        this->unk_60 = this->unk_58 = iVar3->unk_04;
        this->unk_5c = iVar3->unk_06;
    }

    virtual ~ProcLineHelp()
    {
        gMapStateManager->unk_14->unk_29 = 0;

        if (this->unk_40 != NULL)
        {
            gHeap.Free(this->unk_40);
        }
    }

    virtual void Init(void);
    virtual void Loop(void);
};

struct UnkStruct_021970c4
{
    void * unk_00;
    void * unk_04;
    void * unk_08;
};

extern struct UnkStruct_021970c4 * data_021970c4;

EC s32 func_02028e7c(struct UnkStruct_021970c4 *, void *, s32);
EC s32 func_02029ae8(struct UnkStruct_021970c4 *, void *, void *, s32, s32, s32, s32);

EC char * func_020b6d18(char *, char *, s32);

EC void LineHelp_ov000_021d6810(ProcLineHelp * proc)
{
    proc->Init();
    return;
}

void ProcLineHelp::Init(void)
{
    if (this->unk_64 != 0)
    {
        if (this->unk_54 < 0x10)
        {
            this->unk_54 += 4;
        }

        this->unk_50--;

        if (this->unk_50 < -(this->unk_44 + 0x40))
        {
            this->unk_50 += (this->unk_44 + 0x40);
        }
    }
    else
    {
        if (this->unk_54 > 0)
        {
            this->unk_54 -= 4;
        }
        else
        {
            Proc_End(this);
            return;
        }
    }

    gMapStateManager->unk_14->unk_29 = this->unk_54;

    return;
}

EC void LineHelp_ov000_021d68a8(ProcLineHelp * proc)
{
    proc->Loop();
    return;
}

extern u16 data_027e0010[];

void ProcLineHelp::Loop(void)
{
    s32 uVar1;
    s32 iVar2;
    s32 iVar3;

    if (this->unk_44 == 0)
    {
        return;
    }

    iVar2 = 0;

    for (uVar1 = this->unk_50; uVar1 <= -0x40;)
    {
        if (iVar2 == this->unk_4c)
        {
            uVar1 = uVar1 + (0x40 - (this->unk_4c * 0x20 - this->unk_44));
            iVar2 = 0;
        }
        else
        {
            uVar1 = uVar1 + 0x20;
            iVar2 = iVar2 + 1;
        }
    }

    if (this->unk_40 != 0)
    {
        if (this->unk_58 == this->unk_60)
        {
            this->unk_58 = this->unk_58 + 0x60;
        }
        else
        {
            this->unk_58 = this->unk_60;
        }
    }

    for (iVar3 = 0; uVar1 < 0x100;)
    {
        if (iVar2 == this->unk_4c)
        {
            iVar2 = 0;
            uVar1 = uVar1 + (0x40 - (this->unk_4c * 0x20 - this->unk_44));
        }
        else
        {
            if (iVar2 < this->unk_44)
            {
                if (this->unk_40 == 0)
                {
                    func_01ffc404(
                        uVar1 & 0x1ff, 0xc0 - this->unk_54 & 0xff,
                        (this->unk_5c << 0x1c) >> 0x10 | 0xc00 |
                            (this->unk_58 + iVar2 * 8) >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14 & 0x3ff,
                        data_027e0010, 0);
                }
                else
                {
                    func_020a5780(
                        (u8 *)this->unk_40 + iVar2 * 0x100,
                        (u8 *)gpActiveScreenSt->objVram + (this->unk_58 + iVar3) * 0x20, 0x100);
                    func_01ffc404(
                        uVar1 & 0x1ff, 0xc0 - this->unk_54 & 0xff,
                        (this->unk_5c << 0x1c) >> 0x10 | 0xc00 |
                            (this->unk_58 + iVar3) >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14 & 0x3ff,
                        data_027e0010, 0);
                    iVar3 = iVar3 + 8;
                }
            }
            uVar1 = uVar1 + 0x20;
            iVar2 = iVar2 + 1;
        }
    }

    return;
}

// clang-format off

struct ProcCmd ProcScr_LineHelp[] =
{
    PROC_NAME,
    PROC_NAME,
    PROC_SLEEP(0),

    PROC_06(0, LineHelp_ov000_021d68a8),
    PROC_REPEAT(LineHelp_ov000_021d6810),

    PROC_END
};

// clang-format on

EC void StartSubtitleHelp(char * param_1, char * param_2)
{
    char * buf;
    char * pcVar4;
    s32 iVar6;
    ProcLineHelp * proc;

    if (data_02196f24->unk_0d == 0)
    {
        return;
    }

    proc = static_cast<ProcLineHelp *>(Proc_Find(ProcScr_LineHelp));

    if (proc == NULL)
    {
        proc = new (Proc_Start(ProcScr_LineHelp, PROC_TREE_A)) ProcLineHelp();
    }

    if (param_1 != NULL && proc->unk_38 != NULL && func_020b6e2c(param_1, proc->unk_38) == 0)
    {
        if (param_2 != NULL && proc->unk_3c != NULL && func_020b6e2c(param_2, proc->unk_3c) == 0)
        {
            return;
        }
    }

    if (proc->unk_40 != NULL)
    {
        gHeap.Free(proc->unk_40);
        proc->unk_40 = 0;
    }

    proc->unk_38 = param_1;
    proc->unk_3c = param_2;

    iVar6 = proc->unk_50;

    if (proc->unk_4c != 0)
    {
        while (iVar6 < 0)
        {
            if (proc->unk_48 != 0)
            {
                iVar6 += (proc->unk_44 - proc->unk_48);
                if (iVar6 >= 0)
                    break;
                iVar6 += proc->unk_48 + 0x40;
            }
            else
            {
                iVar6 += proc->unk_44 + 0x40;
            }
        }
    }
    else
    {
        iVar6 = 0x40;
    }

    if (param_1 != NULL)
    {
        proc->unk_44 = func_02028e7c(data_021970c4, param_1, 0) + 7 & ~7;

        if (param_2 == NULL)
        {
            proc->unk_48 = 0;
        }
        else
        {
            proc->unk_48 = func_02028e7c(data_021970c4, param_2, 0) + 7 & ~7;
        }

        buf = param_1;

        if (proc->unk_48 != 0)
        {
            proc->unk_44 = proc->unk_44 + proc->unk_48 + 0x40;

            buf = static_cast<char *>(gHeap.Alloc(0x400));
            pcVar4 = func_020b6d18(buf, param_1, 0x400);
            func_020a5824(buf + (s32)pcVar4, 0x20, 8);
            func_020b6d18(buf + (s32)(pcVar4 + 8), param_2, 0x400 - (s32)(pcVar4 + 8));
        }

        if (proc->unk_44 >> 3 > 0x30)
        {
            proc->unk_40 = gHeap.Alloc(((proc->unk_44 >> 2) + 7 & ~7) << 5);
            proc->unk_4c = func_02029ae8(data_021970c4, buf, proc->unk_40, 0, 0, 0, 0);
        }
        else
        {
            if (proc->unk_58 == proc->unk_60)
            {
                proc->unk_58 = proc->unk_58 + 0x60;
            }
            else
            {
                proc->unk_58 = proc->unk_60;
            }

            proc->unk_4c = func_02029ae8(data_021970c4, buf, (void *)gpActiveScreenSt->objVram, proc->unk_58, 0, 0, 0);
        }

        if (proc->unk_48 != NULL)
        {
            gHeap.Free(buf);
        }

        proc->unk_4c >>= 3;
    }
    else
    {
        proc->unk_4c = 0;
        proc->unk_44 = 0;
        proc->unk_48 = 0;
    }

    if (proc->unk_4c != 0)
    {
        while (iVar6 >= 0)
        {
            iVar6 -= (proc->unk_44 + 0x40);
        }
    }

    proc->unk_50 = iVar6;
    proc->unk_64 = 1;

    return;
}

EC void func_ov000_021d6dfc(u32 param_1)
{
    ProcLineHelp * proc = static_cast<ProcLineHelp *>(Proc_Find(ProcScr_LineHelp));

    if (proc == NULL)
    {
        return;
    }

    if (param_1 != 0)
    {
        Proc_End(proc);
    }
    else
    {
        proc->unk_64 = 0;
    }

    return;
}

EC BOOL func_ov000_021d6ed4(void);

EC void func_ov000_021d6e30(u32 param_1)
{
    struct TutHelpData * tutHelp;

    if (data_02196f24->enableTutorials && data_02196f24->unk_0d)
    {
        if (data_ov000_021e3324->unk_18[param_1] != 0)
        {
            func_ov000_021d6dfc(0);
        }

        return;
    }

    if (func_ov000_021d6ed4())
    {
        param_1++;
    }

    tutHelp = &gFE11Database->unk_40[data_ov000_021e3324->unk_18[param_1]];

    StartSubtitleHelp(func_02039e10(tutHelp->unk_00), func_02039e10(tutHelp->unk_04));

    return;
}

EC BOOL func_ov000_021d6ed4(void)
{
    if (data_02196f24->controlSettings == 0)
    {
        return FALSE;
    }

    if (data_02196f24->controlSettings == 2)
    {
        return TRUE;
    }

    return data_02196f20->unk_19a != 0;
}

EC void TryShowTutCardForMenu(ProcPtr parent, u32 param_2)
{
    if (EventCaller::func_02048e60(param_2) == 0)
    {
        return;
    }

    if (func_0204b1e0())
    {
        new (Proc_StartBlocking(ProcScr_020ce750, parent)) ProcTutCardShowForMenu(param_2);
    }
    else
    {
        EventCaller::func_02048dd4(param_2);
    }

    return;
}

EC s32 func_ov000_021d6f7c(s32 param_1)
{
    s32 ret = IntSys_Div((param_1 - 0x80) * 2, 3);

    if (ret > 0x7f)
    {
        return 0x7f;
    }

    if (ret < -0x80)
    {
        return -0x80;
    }

    return ret;
}

void ProcTutCardShowForMenu::Init(void)
{
    if (func_0204b1e0())
    {
        return;
    }

    EventCaller::func_02048dd4(this->unk_38);

    Proc_End(this);

    return;
}
