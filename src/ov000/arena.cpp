#include "global.h"

#include <new>

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "database.hpp"
#include "hashtable.hpp"
#include "hardware.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"

EC void func_0200ac20(char *, ProcPtr, s32);
EC void func_02010f98(u16 *, s32, s32);
EC void func_02017518(void *, void *, s32, s32, s32);
EC void func_01ff9948(u8);
EC void func_0201177c(char *, u32);
EC void func_02011a70(char *, u32, u32, u32);
EC void func_02011a30(char *, u16 *, u32, u32);

class ArenaProc_unk_60
{
public:
    STRUCT_PAD(0x00, 0x40);

    ArenaProc_unk_60() {};
    ~ArenaProc_unk_60() {};
};

class ArenaProc_unk_5c_24
{
public:
    STRUCT_PAD(0x00, 0x24);

    ~ArenaProc_unk_5c_24() {};
};

class ArenaProc_unk_5c
{
public:
    struct ArenaProc_unk_60 * unk_00;
    STRUCT_PAD(0x04, 0x24);
    struct ArenaProc_unk_5c_24 * unk_24;
    STRUCT_PAD(0x28, 0x34);

    ArenaProc_unk_5c(ArenaProc_unk_60 * unk_60)
    {
        this->unk_00 = unk_60;
        this->unk_24 = NULL;
    }

    ~ArenaProc_unk_5c()
    {
        delete this->unk_24;
    }
};

struct ArenaProc
{
    PROC_HEADER
    struct Unit * unk_38;
    struct Unit * unk_3c;
    struct Item unk_40[1];
    STRUCT_PAD(0x44, 0x54);
    s32 unk_54;
    u8 unk_58;
    u8 unk_59;
    u8 unk_5a;
    u8 unk_5b;
    struct ArenaProc_unk_5c * unk_5c;
    struct ArenaProc_unk_60 * unk_60;
    s32 unk_64;
    u32 unk_68;
    s8 unk_6c;
    s8 unk_6d;
    s8 unk_6e;
};

class ArenaBGMCont : public ProcEx
{
public:
    ArenaBGMCont() {};

    virtual ~ArenaBGMCont() {};
};


EC void func_ov000_021d8ed4(struct ArenaProc * proc);
EC void func_ov000_021d9078(struct ArenaProc * proc);
EC void func_ov000_021d9120(struct ArenaProc * proc);
EC void func_ov000_021d9024(struct ArenaProc * proc);

namespace arena
{
class Arena : public ProcEx
{
public:
    /* 38 */ struct Unit * unk_38;
    /* 3C */ struct Unit * unk_3c;
    /* 40 */ struct Item unk_40[1];
    /* 44 */ STRUCT_PAD(0x44, 0x54);
    /* 54 */ s32 unk_54;
    /* 58 */ u8 unk_58;
    /* 59 */ u8 unk_59;
    /* 5A */ u8 unk_5a;
    /* 5B */ u8 unk_5b;
    /* 5C */ struct ArenaProc_unk_5c * unk_5c;
    /* 60 */ struct ArenaProc_unk_60 * unk_60;
    /* 64 */ s32 unk_64;
    /* 68 */ u32 unk_68;
    /* 6C */ s8 unk_6c;
    /* 6D */ s8 unk_6d;
    /* 6E */ s8 unk_6e;

    Arena(struct Unit * unit)
    {
        func_02039eac("shop");

        this->unk_38 = unit;
        this->unk_60 = NULL;
        this->unk_5c = 0;
        this->unk_5b = 0;

        func_ov000_021d8ed4((struct ArenaProc *)this);

        data_027e1268->unk_00->bldcnt.effect = 1;

        data_027e1268->unk_00->blend_coeff_a = 0xe;
        data_027e1268->unk_00->blend_coeff_b = 2;

        data_027e1268->unk_00->bldcnt.target1_bg0_on = 0;
        data_027e1268->unk_00->bldcnt.target1_bg1_on = 0;
        data_027e1268->unk_00->bldcnt.target1_bg2_on = 1;
        data_027e1268->unk_00->bldcnt.target1_bg3_on = 0;
        data_027e1268->unk_00->bldcnt.target1_obj_on = 0;
        data_027e1268->unk_00->bldcnt.target1_bd_on = 0;

        data_027e1268->unk_00->bldcnt.target2_bg0_on = 1;
        data_027e1268->unk_00->bldcnt.target2_bg1_on = 0;
        data_027e1268->unk_00->bldcnt.target2_bg2_on = 0;
        data_027e1268->unk_00->bldcnt.target2_bg3_on = 0;
        data_027e1268->unk_00->bldcnt.target2_obj_on = 0;
        data_027e1268->unk_00->bldcnt.target2_bd_on = 1;

        func_ov000_021a5810(gMapStateManager->unk_0c, 1);
        func_ov000_021d9078((struct ArenaProc *)this);
    }

    virtual ~Arena()
    {
        data_027e1268->unk_00->bldcnt.effect = 0;

        func_ov000_021a57e4(gMapStateManager->unk_0c, 1);
        func_ov000_021d9120((struct ArenaProc *)this);
        func_ov000_021d9024((struct ArenaProc *)this);

        delete this->unk_60;
        delete this->unk_5c;

        func_02039f00("shop", 0);
    }
};
}; // namespace arena

struct ArenaEnemy
{
    /* 00 */ u16 pid;
    /* 02 */ u8 jid;
    /* 03 */ u8 chance;
};

EC void func_ov000_021c8b28(struct ArenaProc_unk_60 *, struct Unit *, struct Unit *, s32);
EC void func_ov000_021c97ec(struct ArenaProc_unk_5c *);
EC void func_ov000_021c9b1c(struct ArenaProc_unk_5c *);
EC void func_ov000_021c9f8c(struct ArenaProc_unk_5c *, u32);
EC struct Unit * func_ov000_021ca0b8(struct ArenaProc_unk_5c *);
EC void * func_ov000_021cf59c(struct ArenaProc *);
EC void func_ov000_021d3b00(struct Unit *, struct ArenaProc *, s32, s32);
EC void func_ov002_021ef134(struct ArenaProc *, struct ArenaProc_unk_5c *);

EC struct ArenaEnemy * func_ov000_021d7c90(u32);
EC void func_ov000_021d7d98(struct ArenaProc * proc);
EC void func_ov000_021d7e1c(struct ArenaProc * proc);
EC void func_ov000_021d8014(struct ArenaProc * proc);
EC void func_ov000_021d8064(struct ArenaProc * proc);
EC void func_ov000_021d8104(struct ArenaProc * proc);
EC void func_ov000_021d8ed4(struct ArenaProc * proc);

EC void func_ov000_021d8604(struct ArenaProc * proc);
EC void func_ov000_021d882c(struct ArenaProc * proc, BOOL arg_1);

EC void func_ov000_021d915c(struct ArenaProc *);
EC void func_ov000_021d91a0(struct ArenaProc *);
EC void func_ov000_021d91e4(struct ArenaProc *);
EC void func_ov000_021d91f0(struct ArenaProc *);
EC void func_ov000_021d920c(struct ArenaProc *);
EC void func_ov000_021d9228(struct ArenaProc *);
EC void func_ov000_021d9244(struct ArenaProc *);
EC void func_ov000_021d9250(struct ArenaProc *);
EC void func_ov000_021d9310(struct ArenaProc *);
EC void func_ov000_021d932c(struct ArenaProc *);
EC void func_ov000_021d9348(struct ArenaProc *);
EC void func_ov000_021d9364(struct ArenaProc *);
EC void func_ov000_021d93d0(struct ArenaProc *);
EC void func_ov000_021d93ec(struct ArenaProc *);
EC void func_ov000_021d9408(struct ArenaProc *);
EC void func_ov000_021d9424(struct ArenaProc *);
EC void func_ov000_021d9440(struct ArenaProc *);
EC void func_ov000_021d945c(struct ArenaProc *);
EC void func_ov000_021d94f4(struct ArenaProc *);
EC void func_ov000_021d9478(struct ArenaProc *);
EC void func_ov000_021d9484(struct ArenaProc *);
EC void func_ov000_021d9490(struct ArenaProc *);
EC void func_ov000_021d949c(struct ArenaProc *);
EC void func_ov000_021d94ac(struct ArenaProc *);
EC void func_ov000_021d94b8(struct ArenaProc *);
EC void func_ov000_021d94c4(struct ArenaProc *);
EC void func_ov000_021d94d0(struct ArenaProc *);
EC void func_ov000_021d94dc(struct ArenaProc *);
EC void func_ov000_021d94e8(struct ArenaProc *);
EC void func_ov000_021d9500(struct ArenaProc *);
EC void func_ov000_021d9520(struct ArenaProc *);
EC void func_ov000_021d9538(struct ArenaProc *);
EC void func_ov000_021d95b0(struct ArenaProc *);
EC void func_ov000_021d95d8(void);

// clang-format off

struct ProcCmd data_ov000_021e2f38[] =
{
    PROC_NAME,
    PROC_NAME,

    PROC_SLEEP(0),

    PROC_CALL(func_0204b39c),
    PROC_WHILE(func_0204b1e0),

    PROC_CALL(func_ov000_021d915c),
    PROC_CALL(func_0204b3d4),
    PROC_CALL(func_0204ac18),
    PROC_CALL(func_ov000_021d91e4),
    PROC_CALL(func_ov000_021d91f0),

    // fallthrough

PROC_LABEL(3),
    PROC_CALL(func_ov000_021d920c),
    PROC_CALL(func_ov000_021d9228),
    PROC_CALL(func_ov000_021d9244),
    PROC_CALL(func_ov000_021d9250),
    PROC_CALL(func_ov000_021d9310),
    PROC_CALL(func_ov000_021d95d8),

    // fallthrough

PROC_LABEL(4),
    PROC_CALL(func_ov000_021d9478),

    // fallthrough

PROC_LABEL(5),
    PROC_CALL(func_ov000_021d9484),
    PROC_06(0, func_ov000_021d94ac),
    PROC_CALL(func_ov000_021d9490),
    PROC_06(0, NULL),
    PROC_CALL(func_ov000_021d949c),

    // fallthrough

PROC_LABEL(6),
    PROC_CALL(func_ov000_021d9538),
    PROC_SLEEP(1),

    PROC_CALL(func_ov000_021d94b8),
    PROC_CALL(func_ov000_021d9500),

    PROC_SLEEP(0),

    PROC_CALL(func_ov000_021d9520),
    PROC_CALL(func_ov000_021d9364),
    PROC_CALL(func_ov000_021d94c4),
    PROC_CALL(func_ov000_021d95b0),
    PROC_CALL(func_ov000_021d9440),
    PROC_CALL(func_ov000_021d94dc),
    PROC_CALL(func_ov000_021d94e8),

    PROC_02,

PROC_LABEL(7),
    PROC_CALL(func_ov000_021d93d0),
    PROC_CALL(func_ov000_021d9424),
    PROC_CALL(func_ov000_021d94d0),
    PROC_SLEEP(0),

    PROC_GOTO(10),

PROC_LABEL(8),
    PROC_CALL(func_ov000_021d9408),
    PROC_CALL(func_ov000_021d9424),
    PROC_CALL(func_ov000_021d94d0),
    PROC_SLEEP(0),

    PROC_GOTO(10),

PROC_LABEL(9),
    PROC_CALL(func_ov000_021d93ec),

    PROC_GOTO(10),

PROC_LABEL(0),
    PROC_CALL(func_ov000_021d932c),

    PROC_GOTO(10),

PROC_LABEL(1),
    PROC_CALL(func_ov000_021d9348),

    PROC_GOTO(10),

PROC_LABEL(2),
    PROC_CALL(func_ov000_021d945c),

    PROC_GOTO(10),

PROC_LABEL(10),
    PROC_CALL(func_ov000_021d94f4),
    PROC_CALL(func_ov000_021d95d8),
    PROC_CALL(func_ov000_021d91a0),

    PROC_CALL(func_0204aca8),
    PROC_CALL(func_0204b40c),
    PROC_CALL(func_0204b3b8),

    PROC_END
};

// clang-format on

static inline struct JobData * GetJobData()
{
    return gFE11Database->pJob;
}

static inline struct PersonData * GetPersonData()
{
    return gFE11Database->pPerson;
}

EC struct ArenaEnemy * func_ov000_021d7c90(u32 count)
{
    struct ArenaEnemy * arenaEnemy = static_cast<struct ArenaEnemy *>(HashTable::Get2("ArenaEnemy\0"));

    while (count > 0)
    {
        while (arenaEnemy->chance != 0)
        {
            arenaEnemy++;
        }

        arenaEnemy++;
        count--;
    }

    return arenaEnemy;
}

EC u8 * func_ov000_021d7cd8(u32 count)
{
    u8 * arenaWeapon = static_cast<u8 *>(HashTable::Get2("ArenaWeapon"));

    while (count > 0)
    {
        while (*arenaWeapon != 0)
        {
            arenaWeapon++;
        }

        arenaWeapon++;
        count--;
    }

    return arenaWeapon;
}

EC void func_ov000_021d7d1c(struct ArenaProc * proc)
{
    Force * pUnit;
    struct Unit * unit;

    func_ov000_021d8014(proc);

    pUnit = Force::Get(4);
    unit = pUnit->head;
    proc->unk_3c = unit;
    func_0203bd34(unit, 1, 1);

    func_ov000_021d7d98(proc);

    return;
}

EC void func_ov000_021d7d50(struct ArenaProc * proc)
{
    if ((proc->unk_38->state2 & 8) != 0)
    {
        data_021974fc->unk_00 = 0;
    }

    func_0203bd34(proc->unk_3c, 4, 1);
    func_ov000_021d8064(proc);

    return;
}

EC void func_ov000_021d7d98(struct ArenaProc * proc)
{
    func_ov000_021d7e1c(proc);
    func_ov000_021d8104(proc);
    func_ov000_021d8604(proc);
    return;
}

EC s32 func_ov000_021d7db8(struct ArenaProc * proc, struct Unit * unit, s32 arg_2)
{
    s32 wpnLevel;
    s32 bestWpnType;
    s32 bestWpnLevel;
    s32 i;

    bestWpnType = -1;
    bestWpnLevel = 0;

    for (i = 0; i < 6; i++)
    {
        if (i == 5)
        {
            continue;
        }

        if (arg_2 != 0)
        {
            wpnLevel = unit->pJobData->weaponLevels[i];
        }
        else
        {
            wpnLevel = func_0203c7ac(unit, i);
        }

        if (wpnLevel > bestWpnLevel)
        {
            bestWpnType = i;
            bestWpnLevel = wpnLevel;
        }
    }

    return bestWpnType;
}

EC void func_ov000_021d7e1c(struct ArenaProc * proc)
{
    s32 set;
    s32 rng;
    s32 iVar7;
    s32 level;
    struct ArenaEnemy * arenaEnemy;
    struct PersonData * pPersonData;
    struct JobData * pJobData;

    s32 bestWeaponType = func_ov000_021d7db8(proc, proc->unk_38, 0);

    BOOL isPromotedOrHighLevel = FALSE;

    if (CheckUnitAttribute(proc->unk_38, 0x800))
    {
        isPromotedOrHighLevel = TRUE;
    }
    else if (proc->unk_38->pJobData->pPromoteJob == NULL)
    {
        if ((s32)proc->unk_38->level >= 16)
        {
            isPromotedOrHighLevel = TRUE;
        }
    }

    if (isPromotedOrHighLevel)
    {
        if (CheckUnitAttribute(proc->unk_38, 0x400))
        {
            set = 7;
        }
        else
        {
            switch (bestWeaponType)
            {
                case 0:
                case 1:
                case 2:
                default:
                    set = 4;
                    break;

                case 3:
                    set = 5;
                    break;

                case 4:
                    set = 6;
                    break;
            }
        }
    }
    else
    {
        if (CheckUnitAttribute(proc->unk_38, 0x400) != 0)
        {
            set = 3;
        }
        else
        {
            switch (bestWeaponType)
            {
                case 0:
                case 1:
                case 2:
                default:
                    set = 0;
                    break;

                case 3:
                    set = 1;
                    break;

                case 4:
                    set = 2;
                    break;
            }
        }
    }

    arenaEnemy = func_ov000_021d7c90(set);
    rng = RollRN(0, 99);

    while (arenaEnemy->chance != 0)
    {
        if (rng < arenaEnemy->chance)
        {
            break;
        }

        arenaEnemy++;
    }

    pPersonData = GetPersonData() + arenaEnemy->pid;
    pJobData = GetJobData() + arenaEnemy->jid;

    level = proc->unk_38->level;

    if (CheckUnitAttribute(proc->unk_38, 0x800) != 0)
    {
        level += 15;
    }

    if ((pJobData->attributes & 0x800) != 0)
    {
        level -= 15;
    }

    level = level + RollRN(-4, 4);

    iVar7 = GetJobMaxLevel(pJobData);

    // TODO: Clamp macro
    level = (level > iVar7) ? iVar7 : (level >= 1) ? level : 1;

    func_0203a728(proc->unk_3c, pPersonData, pJobData, level);
    proc->unk_3c->state2 |= 0x1000;

    if (RollRN(0, 9) != 0)
    {
        proc->unk_5a = 0;
    }
    else
    {
        proc->unk_5a = 1;
    }

    proc->unk_6c = 0;
    proc->unk_6d = 0;
    proc->unk_6e = 0;

    return;
}

EC void func_ov000_021d8014(struct ArenaProc * proc)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        proc->unk_40[i] = &proc->unk_38->items[i];
        proc->unk_38->items[i].Clear();
    }

    return;
}

/* NONMATCHING: https://decomp.me/scratch/SlQqe */
EC void func_ov000_021d8064(struct ArenaProc * proc)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        proc->unk_38->items[i] = &proc->unk_40[i];
    }

    return;
}

EC u8 * func_ov000_021d80a4(struct ArenaProc * proc, struct Unit * unit, s32 arg_2)
{
    u32 uVar1;

    switch (func_ov000_021d7db8(proc, unit, arg_2))
    {
        case 0:
        default:
            uVar1 = 0;
            break;

        case 1:
            uVar1 = 1;
            break;

        case 2:
            uVar1 = 2;
            break;

        case 3:
            uVar1 = 3;
            break;

        case 4:
            if ((func_0201ffd0() & 1) != 0)
            {
                uVar1 = 4;
            }
            else
            {
                uVar1 = 5;
            }

            break;
    }

    return func_ov000_021d7cd8(uVar1);
}

/* NONMATCHING: https://decomp.me/scratch/BcOxD */
EC void func_ov000_021d8104(struct ArenaProc * proc)
{
    s32 r0;
    s32 r4;
    u8 * sp_04;
    u8 * r5;
    s32 r6;
    s32 r7;
    s32 r8;
    s32 fp;
    s32 r9;
    struct ItemData * item;
    s32 wpnLevel;
    s32 wpnType;

    sp_04 = func_ov000_021d80a4(proc, proc->unk_38, 0);
    r5 = func_ov000_021d80a4(proc, proc->unk_3c, 1);

    r6 = func_02038348(&gFE11Database->pItem[*sp_04]);
    r7 = func_02038348(&gFE11Database->pItem[*r5]);

    r8 = func_0203dbd4(proc->unk_38, r6, r7);

    for (r4 = 0; r4 < 10; r4++)
    {
        r0 = func_0203dbd4(proc->unk_3c, r7, r6);

        if (proc->unk_5a != 0)
        {
            if (r8 < r0)
            {
                if ((r8 * 115) / 100 < r0)
                {
                    func_0203de10(proc->unk_3c);
                    proc->unk_6c--;
                    continue;
                }
                else if ((r8 * 110) / 100 > r0)
                {
                    func_0203dd48(proc->unk_3c);
                    proc->unk_6c++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                func_0203dd48(proc->unk_3c);
                proc->unk_6c++;
                continue;
            }
        }
        else if (r8 < r0)
        {
            if ((r8 * 115) / 100 < r0)
            {
                func_0203de10(proc->unk_3c);
                proc->unk_6c--;
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (r8 > ((r0 * 110) / 100))
            {
                func_0203dd48(proc->unk_3c);
                proc->unk_6c++;
            }
            else
            {
                break;
            }
        }
    }

    item = &gFE11Database->pItem[*r5];
    wpnType = item->type;

    if (wpnType < 6)
    {
        if (func_0203c7ac(proc->unk_3c, wpnType) != 0)
        {
            wpnLevel = item->wpnLevel;
            if (wpnLevel > func_0203c7ac(proc->unk_3c, wpnType))
            {
                s32 idk = item->wpnLevel;
                idk -= func_0203c7ac(proc->unk_3c, wpnType);

                if (idk + proc->unk_3c->unk_84[wpnType] <= 0xFF)
                {
                    proc->unk_3c->unk_84[wpnType] += idk;
                }
                else
                {
                    proc->unk_3c->unk_84[wpnType] = 0xFF;
                }
            }
        }
    }

    for (r4 = 0; r4 < 5; r4++)
    {
        s32 playerAttack;
        s32 playerDefense;
        s32 opponentAttack;
        s32 opponentDefense;
        s32 playerMight;
        s32 opponentMight;

        if (r6 != 0)
        {
            playerMight = gFE11Database->pItem[*sp_04].might;
            playerAttack = GetUnitMag(proc->unk_38, NULL, TRUE);
            opponentDefense = GetUnitRes(proc->unk_3c, NULL, TRUE);
        }
        else
        {
            playerMight = gFE11Database->pItem[*sp_04].might;
            playerAttack = GetUnitStr(proc->unk_38, NULL, TRUE);
            opponentDefense = GetUnitDef(proc->unk_3c, NULL, TRUE);
        }

        playerMight = ((playerMight + playerAttack) - opponentDefense);

        if (r7 != 0)
        {
            opponentMight = gFE11Database->pItem[*r5].might;
            opponentAttack = GetUnitMag(proc->unk_3c, NULL, TRUE);
            playerDefense = GetUnitRes(proc->unk_38, NULL, TRUE);
        }
        else
        {
            opponentMight = gFE11Database->pItem[*r5].might;
            opponentAttack = GetUnitStr(proc->unk_3c, NULL, TRUE);
            playerDefense = GetUnitDef(proc->unk_38, NULL, TRUE);
        }

        opponentMight = ((opponentMight + opponentAttack) - playerDefense);

        if ((playerMight * 6) < GetUnitMaxHp(proc->unk_3c))
        {
            if (r6 != 0)
            {
                if (GetUnitRes(proc->unk_3c, 0, TRUE) > 0)
                {
                    proc->unk_3c->unk_50[7]--;
                    proc->unk_6e--;
                }
            }
            else
            {
                if (GetUnitDef(proc->unk_3c, 0, TRUE) > 0)
                {
                    proc->unk_3c->unk_50[6]--;
                    proc->unk_6e--;
                }
            }
        }

        if ((opponentMight * 6) < GetUnitMaxHp(proc->unk_38))
        {
            s32 idk;

            if (r7 != 0)
            {
                proc->unk_3c->unk_50[2]++;
            }
            else
            {
                proc->unk_3c->unk_50[1]++;
            }

            proc->unk_6d++;

            if (*(r5 + 1) != 0)
            {
                r5++;
            }

            item = &gFE11Database->pItem[*r5];
            wpnType = item->type;

            if (wpnType >= 6)
            {
                continue;
            }

            if (func_0203c7ac(proc->unk_3c, wpnType) == 0)
            {
                continue;
            }

            wpnLevel = item->wpnLevel;

            if (wpnLevel <= func_0203c7ac(proc->unk_3c, wpnType))
            {
                continue;
            }

            idk = item->wpnLevel;
            idk -= func_0203c7ac(proc->unk_3c, wpnType);

            if (idk + proc->unk_3c->unk_84[wpnType] <= 0xFF)
            {
                proc->unk_3c->unk_84[wpnType] += idk;
            }
            else
            {
                proc->unk_3c->unk_84[wpnType] = 0xFF;
            }
        }
    }

    proc->unk_38->items[0].InitFromIid(*sp_04);
    proc->unk_38->items[0].flags |= 0x10;

    proc->unk_3c->items[0].InitFromIid(*r5);
    proc->unk_3c->items[0].flags |= 0x10;

    return;
}

EC void func_ov000_021d8604(struct ArenaProc * proc)
{
    s32 iVar1;
    s32 iVar5;
    u32 uVar3;
    u32 uVar4;

    uVar3 = func_02038348(proc->unk_38->items[GetUnitEquippedWeaponSlot(proc->unk_38)].GetData());
    uVar4 = func_02038348(proc->unk_3c->items[GetUnitEquippedWeaponSlot(proc->unk_3c)].GetData());

    iVar1 = func_0203dbd4(proc->unk_3c, uVar4, uVar3);
    iVar5 = func_0203dbd4(proc->unk_38, uVar3, uVar4);

    iVar1 = (iVar1 - (iVar5 >> 1)) * 10;
    if (iVar1 < 0)
    {
        iVar1 = 0;
    }

    proc->unk_54 = iVar1 + 500;

    func_02039f40(0, proc->unk_54);

    return;
}

EC void func_ov000_021d8694(struct ArenaProc * proc)
{
    data_020efcc8->unk_a8->vfunc_3c(0x10, 9, 0);

    proc->unk_64 = 0;
    proc->unk_68 = 0;
    proc->unk_59 = 0;
    proc->unk_5b = 1;

    return;
}

EC void func_ov000_021d86e0(struct ArenaProc * proc)
{
    struct ArenaProc_unk_5c * unk_5c;
    u32 kind;

    proc->unk_38->items[0].uses = proc->unk_38->items[0].GetData()->uses;
    proc->unk_3c->items[0].uses = proc->unk_3c->items[0].GetData()->uses;

    kind = 1;
    if (proc->unk_38->items[0].GetData()->type == 3 || proc->unk_3c->items[0].GetData()->type == 3)
    {
        kind = 2;
    }

    proc->unk_60 = new ArenaProc_unk_60();

    func_ov000_021c8b28(proc->unk_60, proc->unk_38, proc->unk_3c, kind);

    proc->unk_5c = new ArenaProc_unk_5c(proc->unk_60);

    func_ov000_021c97ec(proc->unk_5c);

    proc->unk_64++;

    return;
}

EC void func_ov000_021d87a4(struct ArenaProc * proc)
{
    u8 tmp;

    if (((data_020ca61c->unk_00 & 2) != 0) || (func_ov000_021a5650(gMapStateManager->unk_0c, 0) != 0))
    {
        proc->unk_59 = 1;
    }

    // TODO: Most likely an inline
    tmp = (data_ov002_021faf8c.unk_08 & 2);

    if ((tmp & 0xFF) != 0)
    {
        func_ov000_021d3b00(proc->unk_38, proc, 0, 0);
    }

    return;
}

EC void func_ov000_021d881c(struct ArenaProc * proc)
{
    func_ov002_021ef134(proc, proc->unk_5c);
    return;
}

// TODO: FIXME - need to resolve the inline issue with "func_0203c378"

/* NONMATCHING: https://decomp.me/scratch/eLqmo */
EC void func_ov000_021d882c(struct ArenaProc * proc, BOOL arg_1)
{
    struct Unit * pUnit;
    s32 uVar6;
    struct ArenaProc_unk_5c * unk_5c;

    BOOL idk = 0;
    if (func_ov000_021ca0b8(proc->unk_5c) == NULL)
    {
        idk = 1;
    }

    func_ov000_021c9b1c(proc->unk_5c);

    if (!(proc->unk_59 == 0 && !idk) || (proc->unk_64 >= 6))
    {
        pUnit = func_0203c378(proc->unk_38);

        if (pUnit->unk_30.unk_00 < 9999)
        {
            pUnit->unk_30.unk_00++;
        }

        if (func_ov000_021ca0b8(proc->unk_5c) == proc->unk_3c)
        {
            func_ov000_021a5810(gMapStateManager->unk_0c, 0);
            Proc_Goto(proc, 6, 0);
            pUnit = func_0203c378(proc->unk_38);

            if (pUnit->unk_30.unk_02 < 9999)
            {
                pUnit->unk_30.unk_02++;
            }

            uVar6 = -2;
        }
        else
        {
            if (func_ov000_021ca0b8(proc->unk_5c) == proc->unk_38)
            {
                func_ov000_021a57e4(gMapStateManager->unk_0c, 0);
                Proc_Goto(proc, 7, 0);
                uVar6 = -1;
            }
            else if (proc->unk_59 != 0)
            {
                func_ov000_021a57e4(gMapStateManager->unk_0c, 0);
                Proc_Goto(proc, 8, 0);
                uVar6 = -1;
            }
            else
            {
                func_ov000_021a57e4(gMapStateManager->unk_0c, 0);
                Proc_Goto(proc, 9, 0);
                uVar6 = -1;
            }
        }

        if (data_02196f24->unk_07 != 0 && uVar6 != -2)
        {
            if (uVar6 != -1)
            {
                data_020efcc8->unk_a8->vfunc_3c(0x10, -2, 0);
            }
            else
            {
                data_020efcc8->unk_a8->vfunc_38(0x10);
            }
        }

        proc->unk_5b = 0;
    }
    else
    {
        delete proc->unk_60;
        delete proc->unk_5c;
    }
}

EC struct ArenaProc_unk_5c * func_ov000_021d8bbc(struct ArenaProc * proc)
{
    if ((proc->unk_59 != 0) || (proc->unk_64 >= 6))
    {
        return NULL;
    }

    func_ov000_021d882c(proc, TRUE);
    func_ov000_021d86e0(proc);

    return proc->unk_5c;
}

EC void * func_ov000_021d8bfc(struct ArenaProc * proc)
{
    func_ov000_021c9f8c(proc->unk_5c, proc->unk_68);

    if (proc->unk_5c->unk_24 == 0)
    {
        return proc->unk_5c;
    }

    return func_ov000_021cf59c(proc);
}

EC void func_ov000_021d8c2c(struct ArenaProc * proc)
{
    s32 iVar1 = proc->unk_54;
    iVar1 = (u32)data_02196f20->unk_190 + iVar1;

    if (iVar1 > 999999)
    {
        data_02196f20->unk_190 = 999999;
    }
    else
    {
        data_02196f20->unk_190 = iVar1;
    }

    func_ov000_021d8ed4(proc);

    data_020efcc8->unk_b0->vfunc_28(0x0A0A0000, 0, 0);

    return;
}

EC void func_ov000_021d8c90(struct ArenaProc * proc)
{
    s32 iVar1 = -proc->unk_54;
    iVar1 = (u32)data_02196f20->unk_190 + iVar1;

    if (iVar1 > 999999)
    {
        data_02196f20->unk_190 = 999999;
    }
    else
    {
        data_02196f20->unk_190 = iVar1;
    }

    func_ov000_021d8ed4(proc);

    return;
}

EC void func_ov000_021d8ccc(struct ArenaProc * proc)
{
    if (proc->unk_58 != 0)
    {
        delete proc->unk_60;
        delete proc->unk_5c;

        proc->unk_60 = NULL;
        proc->unk_5c = NULL;

        func_0203a94c(proc->unk_3c);
        func_ov000_021d7d98(proc);

        Proc_Goto(proc, 3, 0);
        return;
    }

    Proc_Goto(proc, 2, 0);

    return;
}

EC void func_ov000_021d8d4c(s32 arg_0)
{
    struct ArenaProc * proc = static_cast<ArenaProc *>(Proc_Find(data_ov000_021e2f38));
    proc->unk_58 = arg_0;
    return;
}

EC void func_ov000_021d8d68(struct ArenaProc * proc)
{
    u32 * puVar1;
    struct UnkStruct_Func_020302e0_Arg * puVar2;
    u32 uVar3;

    if ((data_ov000_021e3508->unk_0c & 1) == 0)
    {
        data_ov000_021e3508->unk_00 = __vt__11DI_ArenaYes;
        data_ov000_021e3508->unk_0c |= 1;
    }

    if ((data_ov000_021e3508->unk_18 & 1) == 0)
    {
        data_ov000_021e3508->unk_10 = __vt__10DI_ArenaNo;
        data_ov000_021e3508->unk_18 |= 1;
    }

    func_02039f40(0, proc->unk_54);

    puVar2 = (UnkStruct_Func_020302e0_Arg *)_Znwm(0x5c);

    if (puVar2 != NULL)
    {
        func_020302e0(puVar2);
        puVar2->unk_00 = data_ov000_021dcebc;
    }

    func_020303bc(puVar2, func_02039e10("MD_賭金"), data_ov000_021e2ca0, proc, 1, 0);

    return;
}

EC void func_ov000_021d8e28(struct ArenaProc * proc)
{
    u32 * puVar1;
    int iVar2;
    u32 * puVar3;
    struct UnkStruct_Func_020302e0_Arg * puVar4;
    u32 uVar5;

    if ((data_ov000_021e3508->unk_1c & 1) == 0)
    {
        data_ov000_021e3508->unk_14 = __vt__11DI_ArenaYes;
        data_ov000_021e3508->unk_1c |= 1;
    }

    if ((data_ov000_021e3508->unk_04 & 1) == 0)
    {
        data_ov000_021e3508->unk_08 = __vt__10DI_ArenaNo;
        data_ov000_021e3508->unk_04 |= 1;
    }

    // TODO: Probably not right type
    puVar4 = (UnkStruct_Func_020302e0_Arg *)_Znwm(0x5c);

    if (puVar4 != NULL)
    {
        func_020302e0(puVar4);
        puVar4->unk_00 = data_ov000_021dcebc;
    }

    func_020303bc(puVar4, func_02039e10("MD_再挑戦\0\0"), data_ov000_021e2cac, proc, 1, 0);

    return;
}

/* NONMATCHING: https://decomp.me/scratch/KlfJk */
EC void func_ov000_021d8ed4(struct ArenaProc * proc)
{
    u8 bVar1;
    u16 uVar2;
    struct VmMap_Common * pUVar3;
    u32 uVar4;
    int iVar5;
    u32 uVar6;
    int iVar7;
    int iVar8;

    pUVar3 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_Font\0"));
    uVar6 = pUVar3->unk_07;
    uVar2 = pUVar3->unk_04;
    bVar1 = pUVar3->unk_06;

    func_02010f98(data_027e1268->unk_20[uVar6] + 0xa8, 0xb, 2);

    iVar7 = func_020295ec(
        data_021970c4, func_02039e10("MD_MONEY\0\0\0"), data_027e1268->unk_0c[uVar6], data_027e1268->unk_20[uVar6],
        0x14, 2, uVar2, bVar1, 0, 0);
    iVar7 = uVar2 + iVar7;
    iVar8 = func_020295ec(
        data_021970c4, func_02039e10("MD_GOLD"), data_027e1268->unk_0c[uVar6], data_027e1268->unk_20[uVar6], 0x1e, 2,
        iVar7, bVar1, 0, 0);
    func_02029850(
        data_021970c4, data_02196f20->unk_190, data_027e1268->unk_0c[uVar6], data_027e1268->unk_20[uVar6], 0x1d, 2,
        iVar7 + iVar8, bVar1, 0);

    data_027e1268->unk_3e |= 1 << uVar6;

    return;
}

EC void func_ov000_021d9024(struct ArenaProc * proc)
{
    u8 bVar1;
    struct VmMap_Common * pUVar2 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_Font\0"));

    bVar1 = pUVar2->unk_07;
    func_02010f98(data_027e1268->unk_20[bVar1] + 0xa8, 0xb, 2);
    data_027e1268->unk_3e |= 1 << bVar1;

    return;
}

/* NONMATCHING: https://decomp.me/scratch/LWUIx */
EC void func_ov000_021d9078(struct ArenaProc * proc)
{
    u32 uVar4;
    u16 uVar2;
    u8 bVar1;
    struct VmMap_Common * pUVar4 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_BG2Free\0\0"));

    uVar4 = pUVar4->unk_07;
    uVar2 = pUVar4->unk_04;
    bVar1 = pUVar4->unk_06;

    func_020a8f40("/shop\0\0");

    func_0201177c("money.cg\0\0\0", ((u32)(data_027e1268->unk_0c[uVar4])) + uVar2 * 0x20);
    func_02011a70("money.cl\0\0\0", bVar1 * 0x20, 0, 0);
    func_02011a30("money.rect\0", data_027e1268->unk_20[uVar4] + 0x20, uVar2, bVar1);

    data_027e1268->unk_3e |= 1 << uVar4;

    return;
}

EC void func_ov000_021d9120(struct ArenaProc * proc)
{
    u8 bVar1;
    struct VmMap_Common * pUVar2 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_BG2Free\0\0"));
    bVar1 = pUVar2->unk_07;

    func_01ff9948(bVar1);
    data_027e1268->unk_3e |= 1 << bVar1;

    return;
}

EC void func_ov000_021d915c(struct ArenaProc * proc)
{
    if (data_02196f24->unk_07 == 0)
    {
        return;
    }

    func_02017518(data_020efcc8->unk_a8, data_020efcc8->unk_a4, 0x10, 0x34, 0x10);

    return;
}

EC void func_ov000_021d91a0(struct ArenaProc * unused)
{
    if (data_02196f24->unk_07 == 0)
    {
        return;
    }

    if ((data_ov000_021e3340->unk_06 & 8) != 0)
    {
        func_ov000_021a43e8();
        return;
    }

    func_ov000_021a4694();

    return;
}

EC void func_ov000_021d91e4(struct ArenaProc * proc)
{
    func_ov000_021d7d1c(proc);
    return;
}

EC void func_ov000_021d91f0(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_WELCOME", proc, 0);
    return;
}

EC void func_ov000_021d920c(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_PRICE\0\0", proc, 0);
    return;
}

EC void func_ov000_021d9228(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_CHALLENGE\0\0", proc, 0);
    return;
}

EC void func_ov000_021d9244(struct ArenaProc * proc)
{
    func_ov000_021d8d68(proc);
    return;
}

EC void func_ov000_021d9250(struct ArenaProc * proc)
{
    if (proc->unk_58 != 0)
    {
        if (data_02196f20->unk_190 < proc->unk_54)
        {
            Proc_Goto(proc, 1, 0);
            return;
        }

        data_ov000_021e3340->unk_06 |= 8;
        gMapStateManager->unk_04->unk_04->ClearValues();

        return;
    }

    if ((data_ov000_021e3340->unk_06 & 8) != 0)
    {
        Proc_Goto(proc, 2, 0);
        return;
    }

    Proc_Goto(proc, 0, 0);

    return;
}

EC void func_ov000_021d9310(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_BATTLE\0", proc, 0);
    return;
}

EC void func_ov000_021d932c(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_GETOUT\0", proc, 0);
    return;
}

EC void func_ov000_021d9348(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_POOR\0\0\0", proc, 0);
    return;
}

EC void func_ov000_021d9364(struct ArenaProc * proc)
{
    func_02039f40(0, proc->unk_54);
    func_0200ac20("M闘技場_WIN", proc, 0);

    if (data_02196f24->unk_07 == 0)
    {
        return;
    }

    data_020efcc8->unk_a8->vfunc_3c(0x10, 0x35, 0);

    return;
}

EC void func_ov000_021d93d0(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_LOSE\0\0\0", proc, 0);
    return;
}

EC void func_ov000_021d93ec(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_DRAW\0\0\0", proc, 0);
    return;
}

EC void func_ov000_021d9408(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_STOP\0\0\0", proc, 0);
    return;
}

EC void func_ov000_021d9424(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_FORFEIT", proc, 0);
    return;
}

EC void func_ov000_021d9440(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_RETRY\0\0", proc, 0);
    return;
}

EC void func_ov000_021d945c(struct ArenaProc * proc)
{
    func_0200ac20("M闘技場_BYE", proc, 0);
    return;
}

EC void func_ov000_021d9478(struct ArenaProc * proc)
{
    func_ov000_021d8694(proc);
    return;
}

EC void func_ov000_021d9484(struct ArenaProc * proc)
{
    func_ov000_021d86e0(proc);
    return;
}

EC void func_ov000_021d9490(struct ArenaProc * proc)
{
    func_ov000_021d881c(proc);
    return;
}

EC void func_ov000_021d949c(struct ArenaProc * proc)
{
    func_ov000_021d882c(proc, 0);
    return;
}

EC void func_ov000_021d94ac(struct ArenaProc * proc)
{
    func_ov000_021d87a4(proc);
    return;
}

EC void func_ov000_021d94b8(struct ArenaProc * proc)
{
    func_ov000_021d8bfc(proc);
    return;
}

EC void func_ov000_021d94c4(struct ArenaProc * proc)
{
    func_ov000_021d8c2c(proc);
    return;
}

EC void func_ov000_021d94d0(struct ArenaProc * proc)
{
    func_ov000_021d8c90(proc);
    return;
}

EC void func_ov000_021d94dc(struct ArenaProc * proc)
{
    func_ov000_021d8e28(proc);
    return;
}

EC void func_ov000_021d94e8(struct ArenaProc * proc)
{
    func_ov000_021d8ccc(proc);
    return;
}

EC void func_ov000_021d94f4(struct ArenaProc * proc)
{
    func_ov000_021d7d50(proc);
    return;
}

EC void func_ov000_021d9500(struct ArenaProc * unused)
{
    func_ov000_021a57e4(gMapStateManager->unk_0c, 0);
    return;
}

EC void func_ov000_021d9520(struct ArenaProc * proc)
{
    func_ov000_021d9078(proc);
    func_ov000_021d8ed4(proc);
    return;
}

EC void func_ov000_021d9538(struct ArenaProc * proc)
{
    func_ov000_021d9120(proc);
    func_ov000_021d9024(proc);
    return;
}

EC void func_ov000_021d9550(struct ArenaProc * proc)
{
    proc->proc_funcTable->unk_08(proc);
    return;
}

EC void func_ov000_021d9564(struct ArenaProc * proc)
{
    if (func_02016250(0x35))
    {
        return;
    }

    data_020efcc8->unk_a8->vfunc_28(0x34, 0, 0);

    Proc_End(proc);

    return;
}

extern struct ProcCmd data_ov000_021e2cb8[];

EC void func_ov000_021d95b0(struct ArenaProc * parent)
{
    new (Proc_Start(data_ov000_021e2cb8, parent)) ArenaBGMCont();
    return;
}

EC void func_ov000_021d95d8(void)
{
    Proc_EndEach(data_ov000_021e2cb8);
    return;
}

extern struct Unit * gUnitList;

class ActionState
{
public:
    STRUCT_PAD(0x00, 0x14);
    u32 unk_14;
    STRUCT_PAD(0x18, 0x2C);
    s8 unk_2c;
    s8 unk_2d;
    u8 unk_2e;
    u8 unk_2f;
    /* 30 */ s8 xDecision;
    /* 31 */ s8 yDecision;
    /* 32 */ u8 unitId; // "MindGetUnit" returns this
    /* 33 */ u8 actionId; // "MindGetMind" returns this
    u8 unk_34; // target unit ID?
    u8 unk_35;
    u8 unk_36;
    u8 unk_37; // item slot?

    void func_ov000_021b0eb4(struct Unit *);
};

extern ActionState * gActionSt;

struct Unknown_021e3320
{
    STRUCT_PAD(0x00, 0x08);
    u32 unk_08[1];
};

extern u8 data_ov000_021e3320[];

EC void func_ov000_021d95ec(ProcPtr parent)
{
    struct ArenaProc * proc;
    struct Unit * iVar4;

    if (gActionSt->unitId == 0)
    {
        iVar4 = NULL;
    }
    else
    {
        iVar4 = gUnitList + gActionSt->unitId - 1;
    }

    if (data_ov000_021e3320[iVar4->force->id] == 1)
    {
        data_021974fc->unk_00 = iVar4;
        func_0204b194(iVar4->xPos, iVar4->yPos);
    }

    new (Proc_StartBlocking(data_ov000_021e2f38, parent)) arena::Arena(gMapStateManager->unk_04->unk_00);

    return;
}

EC void func_ov000_021d98ec(void)
{
    func_ov000_021d8bbc(static_cast<struct ArenaProc *>(Proc_Find(data_ov000_021e2f38)));
    return;
}

EC u32 func_ov000_021d9904(void)
{
    struct ArenaProc * proc = static_cast<struct ArenaProc *>(Proc_Find(data_ov000_021e2f38));

    if (proc != NULL)
    {
        return proc->unk_5b;
    }

    return 0;
}

EC s32 func_ov000_021d9924(void)
{
    func_ov000_021d8d4c(0);
    return 0x81;
}

EC s32 func_ov000_021d9938(void)
{
    return 0;
}

EC s32 func_ov000_021d9940(void)
{
    func_ov000_021d8d4c(1);
    return 0x41;
}
