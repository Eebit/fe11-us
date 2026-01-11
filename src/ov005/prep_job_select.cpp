#include "global.h"

#include <new>

#include "button.hpp"
#include "hardware.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"

#include "unknown_funcs.h"
#include "unknown_types.hpp"

class UnkStruct_02217560
{
public:
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    STRUCT_PAD(0x0C, 0x10);
    u8 unk_10;
    u8 unk_11;
    STRUCT_PAD(0x12, 0x14);
    Unit * unk_14;
    STRUCT_PAD(0x18, 0x20);
    u32 unk_20;

    UnkStruct_02217560()
    {
        this->unk_00 = -1;
        this->unk_04 = -1;
        this->unk_10 = 0;
        this->unk_11 = 0;
        this->unk_20 = -1;
    }
};

extern UnkStruct_02217560 * data_ov005_02217560;

extern struct UnkStruct_02196f0c * data_02196f0c;

struct UnkStruct_021970c4
{
    void * unk_00;
    void * unk_04;
    void * unk_08;
};

extern struct UnkStruct_021970c4 * data_021970c4;
extern struct UnkStruct_021970c4 * data_021970cc;

extern struct KeyState * gKeySt;

EC void func_ov002_021f0960(void *, Unit *);

EC void func_01ff9948(s32);
EC s32 func_02034f74(s32 kind);
EC void * func_ov002_021f2040(Unit *, s32, s32, s32, s32, ProcPtr);

EC struct Unit * func_0203bdd0(struct Unit * unit, u8 arg_1);
EC s32 func_020295ec(struct UnkStruct_021970c4 *, char *, void *, void *, u32, u32, u32, u32, u32, u32);
EC void func_02029a1c(struct UnkStruct_021970c4 *, u32, void *, void *, u32, u32, u32, u32);
EC void func_020113d0(u16 *, u16, s32);
EC void func_0202972c(struct UnkStruct_021970c4 *, char *, void *, u16 *, u32, u32, u32, u32, u32, u32, u32);
EC char * func_02037fc8(struct JobData * pJob);
EC void func_0203a94c(struct Unit * unit);
EC struct Unit * func_0203aa4c(struct Unit * dst, struct Unit * src);
EC struct Unit * GetLeaderUnitForFaction(s32 factionId);

EC void func_0202a4dc(s32, s32);
EC void func_02035694(u8 *, s32, s32);
EC void func_02035700(s32);

// EC void func_ov005_02204c20(ProcEx *, s32);

EC BOOL func_0203cd30(struct Unit * unit, s32 arg_1);

EC void func_020512cc(void *, s32, s32, s32);

namespace sally
{

class JobSConst
{
};

class JobS : public ProcEx, public JobSConst
{
public:
    /* 38 */ struct JobData ** unk_38;
    /* 3C */ Unit * unk_3c;
    /* 40 */ Unit * unk_40;
    /* 44 */ s32 unk_44;
    /* 48 */ void * unk_48; // battle anim pointer
    /* 4C */ s32 unk_4c;
    /* 50 */ u8 unk_50[12];
    /* 5C */ Button * unk_5c;
    /* 60 */ Button * unk_60;
    /* 64 */ Button * unk_64;
    /* 68 */ Button * unk_68;

    JobS(Unit * sp1C)
    {
        Unit * var_r10;
        Anime * temp_r0_7;
        s32 temp_r4;
        ScreenState * temp_r4_3;
        s32 unk_35;
        s32 j;
        s32 i;
        s32 r7;

        this->unk_38 = static_cast<struct JobData **>(gHeap.Alloc(0x20));
        this->unk_3c = sp1C;
        this->unk_44 = -1;

        for (i = 0; i < 12; i++)
        {
            this->unk_50[i] = 0;
        }

        for (var_r10 = GetLeaderUnitForFaction(5); var_r10 != NULL; var_r10 = func_0203bdd0(var_r10, 5))
        {
            if (func_0203c378(var_r10)->pJobData->unk_35 >= 0)
            {
                this->unk_50[func_0203c378(var_r10)->pJobData->unk_35]++;
            }
        }

        r7 = this->unk_3c->pJobData->unk_34;

        this->unk_4c = 0;
        this->unk_44 = -1;

        for (j = 0; j < gFE11Database->pDBFE11Footer->jidTableLength; j++)
        {
            struct JobData * job = &gFE11Database->pJob[j];

            if (r7 != job->unk_34)
            {
                continue;
            }

            if (!CheckUnitAttribute(this->unk_3c, 0x20000000) && job == GetJobByJidStr("JID_FALCONKNIGHT_F"))
            {
                continue;
            }

            if (CheckUnitAttribute(this->unk_3c, 0x20000000) && job == GetJobByJidStr("JID_DRAGONKNIGHT_F"))
            {
                continue;
            }

            this->unk_38[this->unk_4c] = job;

            if (job == this->unk_3c->pJobData)
            {
                this->unk_44 = this->unk_4c;
            }

            this->unk_4c++;
        }

        if (this->unk_44 == -1)
        {
            this->unk_44 = 0;
        }

        this->unk_40 = static_cast<Unit *>(gHeap.Alloc(sizeof(Unit)));
        func_0203a94c(this->unk_40);
        func_0203aa4c(this->unk_40, sp1C);
        this->unk_40->force = sp1C->force;

        func_ov005_02204c20(this, 1);

        gpActiveScreenSt->dispIo->dispcnt.bit_12 = 1;
        gpActiveScreenSt->dispIo->dispcnt.bit_13_14 = 2;

        func_0202a4dc(0, 0);

        for (i = 1; i < 12; i++)
        {
            func_02035694((u8 *)gpActiveScreenSt->bgTiles[1] + ((i * 4) << 5), i + 0x19, 1);
        }

        func_02035700(8);

        func_020a8f40("/jobslide");

        func_0201177c("jobslide.cg", (u32)gpActiveScreenSt->bgTiles[2]);
        func_0201177c("jobslide.sc", (u32)gpActiveScreenSt->tilemap[2]);
        func_02011a70("jobslide.cl", 0x20, 0, 0);

        func_02010d98(gpActiveScreenSt->tilemap[2], 0x600, 0, 1);

        gpActiveScreenSt->unk_3e |= 4;

        func_0201177c("arrow.cg", (u32)((u8 *)gpActiveScreenSt->bgTiles[4] + 0x6800));
        func_02011a70("arrow.cl", 0x2A0, 0, 0);

        temp_r0_7 = StartAnimByName(
            "arrow.anm", 0, 0x80, 0xA8, ((0x340 >> gpActiveScreenSt->dispIo->dispcnt.bit_13_14) & 0x3FF) | 0x5000, 0,
            this);
        if (temp_r0_7->interpreter != NULL)
        {
            temp_r0_7->interpreter->SetLoopingEnabled(1);
        }

        temp_r4 = 0x300;

        this->unk_5c = StartButton(this, 6, temp_r4, 0, 2);
        this->unk_5c->SetPosition(0x70, 0x78);
        this->unk_5c->func_020354bc(0);

        temp_r4 += func_02034f74(6);
        this->unk_60 = StartButton(this, 1, temp_r4, 0, 2);
        this->unk_60->SetPosition(0x70, 0);
        this->unk_60->func_020354bc(0);

        temp_r4 += func_02034f74(6);
        this->unk_64 = StartButton(this, 12, temp_r4, 2, 0x12);
        this->unk_64->SetPosition(0x30, 0x7C);
        this->unk_64->func_020354bc(0);

        temp_r4 += func_02034f74(12);
        this->unk_68 = StartButton(this, 13, temp_r4, 2, 0x12);
        this->unk_68->SetPosition(0xB0, 0x7C);
        this->unk_68->func_020354bc(0);

        func_02034f74(0xD);

        func_020512cc(this, 1, 0x328, 4);

        this->unk_48 = func_ov002_021f2040(sp1C, 0, 1, 0x80, 0x60, this);

        temp_r4_3 = gpActiveScreenSt;
        gpActiveScreenSt = gpSubScreenSt;

        func_020a8f40("/window");

        func_0201177c("levelupobjex4.cg", (u32)((u8 *)gpActiveScreenSt->bgTiles[4] + 0xB580));
        func_02011a70("levelupobj.cl", 0x340, 0, 0);

        gpActiveScreenSt = temp_r4_3;

        func_01ff9948(1);

        func_0202972c(
            data_021970c4, func_02037fc8(this->unk_3c->pJobData), gpActiveScreenSt->bgTiles[1],
            gpActiveScreenSt->tilemap[1], 5, 0x14, 0x31, 0, 0x38, 1, 0);

        if (!this->check())
        {
            data_021970c4->unk_08 = data_021970cc->unk_08;
        }

        func_0202972c(
            data_021970c4, func_02037fc8(this->unk_40->pJobData), gpActiveScreenSt->bgTiles[1],
            gpActiveScreenSt->tilemap[1], 0x14, 0x14, 0x3F, 0, 0x38, 1, 0);
        data_021970c4->unk_08 = data_021970cc->unk_04;

        unk_35 = this->unk_38[this->unk_44]->unk_35;

        func_020113d0(gpActiveScreenSt->tilemap[1] + 0x98, ((unk_35 * 4) + 1), 8);

        if (this->unk_3c->state2 & 0x40000)
        {
            func_020295ec(
                data_021970c4, "−", gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1A, 4, 0x4D, 0, 0, 0);
        }
        else
        {
            func_02029a1c(
                data_021970c4, this->unk_50[unk_35], gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1A,
                4, 0x4D, 0);
        }

        func_020295ec(
            data_021970c4, "／", gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1B, 4, 0x51, 0, 0, 0);

        if (this->unk_3c->state2 & 0x40000)
        {
            func_020295ec(
                data_021970c4, "−", gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1C, 4, 0x53, 0, 0, 0);
        }
        else
        {
            func_02029a1c(
                data_021970c4, data_02196f0c->pCurrentMap->unk_0c[unk_35], gpActiveScreenSt->bgTiles[1],
                gpActiveScreenSt->tilemap[1], 0x1C, 4, 0x53, 0);
        }

        gpActiveScreenSt->unk_3e |= 2;
    }

    // func_ov005_0220fb2c
    virtual void Init(void)
    {
        s32 unk_35;
        s32 wpnSlot;

        if ((gKeySt->repeated & KEY_DPAD_LEFT) || this->unk_64->func_02035450())
        {
            if (this->unk_44 == 0)
            {
                this->unk_44 = this->unk_4c - 1;
            }
            else
            {
                this->unk_44--;
            }

            gSoundManager->unk_b0->vfunc_28(0x1001d, 0, 0);

            this->unk_40->SetJob(this->unk_38[this->unk_44]);
            this->unk_40->hp = GetUnitMaxHp(this->unk_40);

            func_ov002_021f0960(this->unk_48, this->unk_40);

            func_0204e1a4(this->unk_40, 0, 1);

            func_01ff9948(1);

            func_0202972c(
                data_021970c4, func_02037fc8(this->unk_3c->pJobData), gpActiveScreenSt->bgTiles[1],
                gpActiveScreenSt->tilemap[1], 5, 0x14, 0x31, 0, 0x38, 1, 0);

            if (!this->check())
            {
                data_021970c4->unk_08 = data_021970cc->unk_08;
            }

            func_0202972c(
                data_021970c4, func_02037fc8(this->unk_40->pJobData), gpActiveScreenSt->bgTiles[1],
                gpActiveScreenSt->tilemap[1], 0x14, 0x14, 0x3F, 0, 0x38, 1, 0);

            data_021970c4->unk_08 = data_021970cc->unk_04;

            unk_35 = this->unk_38[this->unk_44]->unk_35;
            func_020113d0(((u16 *)gpActiveScreenSt->tilemap[1]) + 0x98, unk_35 * 4 + 1, 8);

            if (this->unk_3c->state2 & 0x40000)
            {
                func_020295ec(
                    data_021970c4, "−", gpActiveScreenSt->bgTiles[2], gpActiveScreenSt->tilemap[1], 0x1A, 4, 0x4D, 0, 0,
                    0);
            }
            else
            {
                func_02029a1c(
                    data_021970c4, this->unk_50[unk_35], gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1],
                    0x1A, 4, 0x4D, 0);
            }

            func_020295ec(
                data_021970c4, "／", gpActiveScreenSt->bgTiles[2], gpActiveScreenSt->tilemap[1], 0x1B, 4, 0x51, 0, 0,
                0);

            if (this->unk_3c->state2 & 0x40000)
            {
                func_020295ec(
                    data_021970c4, "−", gpActiveScreenSt->bgTiles[2], gpActiveScreenSt->tilemap[1], 0x1C, 4, 0x53, 0, 0,
                    0);
            }
            else
            {
                func_02029a1c(
                    data_021970c4, data_02196f0c->pCurrentMap->unk_0c[unk_35], gpActiveScreenSt->bgTiles[2],
                    gpActiveScreenSt->tilemap[1], 0x1C, 4, 0x53, 0);
            }

            gpActiveScreenSt->unk_3e |= 2;

            return;
        }

        if ((gKeySt->repeated & KEY_DPAD_RIGHT) || this->unk_68->func_02035450())
        {
            if (this->unk_44 < this->unk_4c - 1)
            {
                this->unk_44++;
            }
            else
            {
                this->unk_44 = 0;
            }

            gSoundManager->unk_b0->vfunc_28(0x1001d, 0, 0);

            this->unk_40->SetJob(this->unk_38[this->unk_44]);
            this->unk_40->hp = GetUnitMaxHp(this->unk_40);

            func_ov002_021f0960(this->unk_48, this->unk_40);

            func_0204e1a4(this->unk_40, 0, 1);

            func_01ff9948(1);

            func_0202972c(
                data_021970c4, func_02037fc8(this->unk_3c->pJobData), gpActiveScreenSt->bgTiles[1],
                gpActiveScreenSt->tilemap[1], 5, 0x14, 0x31, 0, 0x38, 1, 0);

            if (!this->check())
            {
                data_021970c4->unk_08 = data_021970cc->unk_08;
            }

            func_0202972c(
                data_021970c4, func_02037fc8(this->unk_40->pJobData), gpActiveScreenSt->bgTiles[1],
                gpActiveScreenSt->tilemap[1], 0x14, 0x14, 0x3F, 0, 0x38, 1, 0);

            data_021970c4->unk_08 = data_021970cc->unk_04;

            unk_35 = this->unk_38[this->unk_44]->unk_35;
            func_020113d0(((u16 *)gpActiveScreenSt->tilemap[1]) + 0x98, unk_35 * 4 + 1, 8);

            if (this->unk_3c->state2 & 0x40000)
            {
                func_020295ec(
                    data_021970c4, "−", gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1A, 4, 0x4D, 0, 0,
                    0);
            }
            else
            {
                func_02029a1c(
                    data_021970c4, this->unk_50[unk_35], gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1],
                    0x1A, 4, 0x4D, 0);
            }

            func_020295ec(
                data_021970c4, "／", gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1B, 4, 0x51, 0, 0,
                0);

            if (this->unk_3c->state2 & 0x40000)
            {
                func_020295ec(
                    data_021970c4, "−", gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1C, 4, 0x53, 0, 0,
                    0);
            }
            else
            {
                func_02029a1c(
                    data_021970c4, data_02196f0c->pCurrentMap->unk_0c[unk_35], gpActiveScreenSt->bgTiles[1],
                    gpActiveScreenSt->tilemap[1], 0x1C, 4, 0x53, 0);
            }

            gpActiveScreenSt->unk_3e |= 2;

            return;
        }

        if ((gKeySt->pressed & KEY_BUTTON_A) || this->unk_5c->func_02035450())
        {
            if (this->check())
            {
                gSoundManager->unk_b0->vfunc_28(0x10016, 0, 0);

                unk_35 = this->unk_3c->pJobData->unk_35;
                this->unk_50[unk_35]--;

                unk_35 = this->unk_38[this->unk_44]->unk_35;
                this->unk_50[unk_35]++;

                this->unk_3c->SetJob(this->unk_38[this->unk_44]);
                this->unk_3c->hp = GetUnitMaxHp(this->unk_3c);

                wpnSlot = GetUnitEquippedWeaponSlot(this->unk_3c);
                if (wpnSlot != -1)
                {
                    Item * item = &this->unk_3c->items[wpnSlot];
                    item->flags &= ~0x10;
                }

                func_0203cd30(this->unk_3c, -1);
                func_0203aa4c(this->unk_40, this->unk_3c);

                this->unk_40->SetJob(this->unk_38[this->unk_44]);
                this->unk_40->hp = GetUnitMaxHp(this->unk_40);

                func_ov002_021f0960(this->unk_48, this->unk_40);

                func_0204e1a4(this->unk_40, 0, 1);
                func_01ff9948(1);

                func_0202972c(
                    data_021970c4, func_02037fc8(this->unk_3c->pJobData), gpActiveScreenSt->bgTiles[1],
                    gpActiveScreenSt->tilemap[1], 5, 0x14, 0x31, 0, 0x38, 1, 0);

                if (!this->check())
                {
                    data_021970c4->unk_08 = data_021970cc->unk_08;
                }

                func_0202972c(
                    data_021970c4, func_02037fc8(this->unk_40->pJobData), gpActiveScreenSt->bgTiles[1],
                    gpActiveScreenSt->tilemap[1], 0x14, 0x14, 0x3F, 0, 0x38, 1, 0);
                data_021970c4->unk_08 = data_021970cc->unk_04;

                unk_35 = this->unk_38[this->unk_44]->unk_35;
                func_020113d0(((u16 *)gpActiveScreenSt->tilemap[1]) + 0x98, unk_35 * 4 + 1, 8);

                if (this->unk_3c->state2 & 0x40000)
                {
                    func_020295ec(
                        data_021970c4, "−", gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1A, 4, 0x4D,
                        0, 0, 0);
                }
                else
                {
                    func_02029a1c(
                        data_021970c4, this->unk_50[unk_35], gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1],
                        0x1A, 4, 0x4D, 0);
                }

                func_020295ec(
                    data_021970c4, "／", gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1B, 4, 0x51, 0,
                    0, 0);

                if (this->unk_3c->state2 & 0x40000)
                {
                    func_020295ec(
                        data_021970c4, "−", gpActiveScreenSt->bgTiles[1], gpActiveScreenSt->tilemap[1], 0x1C, 4, 0x53,
                        0, 0, 0);
                }
                else
                {
                    func_02029a1c(
                        data_021970c4, data_02196f0c->pCurrentMap->unk_0c[unk_35], gpActiveScreenSt->bgTiles[1],
                        gpActiveScreenSt->tilemap[1], 0x1C, 4, 0x53, 0);
                }

                gpActiveScreenSt->unk_3e |= 2;

                return;
            }
            else
            {
                gSoundManager->unk_b0->vfunc_28(0x10002, 0, 0);
                return;
            }
        }

        if ((gKeySt->pressed & KEY_BUTTON_B) || this->unk_60->func_02035450())
        {
            gSoundManager->unk_b0->vfunc_28(0x10017, 0, 0);

            Proc_Break(this, 1);

            return;
        }
    }

    // func_ov005_022108d8
    virtual void Loop(void)
    {
        // TODO
    }

    BOOL check(void)
    {
        if (this->unk_3c->pJobData == this->unk_38[this->unk_44])
        {
            return FALSE;
        }
        else if (this->unk_3c->state2 & 0x40000)
        {
            return TRUE;
        }
        else
        {
            s32 count = this->unk_50[this->unk_38[this->unk_44]->unk_35];
            s32 max = data_02196f0c->pCurrentMap->unk_0c[this->unk_38[this->unk_44]->unk_35];
            if (count < max)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }

    // func_ov005_0221184c
    // func_ov005_0221188c
    virtual ~JobS()
    {
        gHeap.Free(this->unk_40);
        gHeap.Free(this->unk_38);
    }
};

} // namespace sally

EC void func_ov005_0220fa58(sally::JobS * proc)
{
    s32 target = 0;

    if (data_02196f0c->state & 0x80000)
    {
        target = 1;
    }

    StartBlockingFadeInFromBlack((struct Proc *)proc, 8, target);
    return;
}

EC void func_ov005_0220fa84(sally::JobS * proc)
{
    s32 target = 0;

    if (data_02196f0c->state & 0x80000)
    {
        target = 1;
    }

    StartBlockingFadeOutToBlack((struct Proc *)proc, 8, target);
    return;
}

EC void func_ov005_0220fab0(sally::JobS * proc)
{
    func_0204e1a4(proc->unk_3c, 0, 1);

    func_02018f54((struct Proc *)proc, 0);

    data_ov005_02217560->unk_10 = 0;

    proc->unk_5c->func_020354bc(0);
    proc->unk_60->func_020354bc(0);
    proc->unk_64->func_020354bc(0);
    proc->unk_68->func_020354bc(0);

    return;
}

EC void func_ov005_0220fb18(sally::JobS * proc)
{
    proc->Init();
}

// func_ov005_0220fb2c
// void sally::JobS::Init(void)

EC void func_ov005_022108c4(sally::JobS * proc)
{
    proc->Loop();
}

// func_ov005_022108d8
// void sally::JobS::Loop(void)
// {
// }

EC void func_ov005_02210898(sally::JobS * proc)
{
    proc->unk_5c->func_020354a0();
    proc->unk_60->func_020354a0();
    proc->unk_64->func_020354a0();
    proc->unk_68->func_020354a0();
    return;
}

extern struct ProcCmd data_ov005_022171f0[];

void StartSally_JobS(ProcPtr arg0)
{
    new (Proc_StartBlocking(data_ov005_022171f0, arg0)) sally::JobS(data_ov005_02217560->unk_14);
}
