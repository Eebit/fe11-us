#include "global.h"

#include <new>

#include "unknown_data.h"
#include "unknown_funcs.h"
#include "unknown_types.hpp"

#include "constants/sounds.h"

#include "database.hpp"
#include "hardware.hpp"
#include "hashtable.hpp"
#include "menu.hpp"
#include "proc_ex.hpp"
#include "sound_manager.hpp"
#include "unit.hpp"

namespace arena
{
class Arena;
};

extern struct UnkStruct_021970c4 * data_021970c4;

EC void func_0200ac20(char *, ProcPtr, s32);
EC void StartSoundWaitTo_02017518(void *, void *, s32, s32, s32);
EC void func_01ff9948(u8);
EC void func_02011a30(char *, u16 *, u32, u32);

EC void func_020303bc(DialogYesNo *, char *, void *, ProcPtr, s32, s32);

class ArenaProc_unk_60
{
public:
    STRUCT_PAD(0x00, 0x40);

    ArenaProc_unk_60() {};
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

    virtual void Loop(); // func_ov000_021d9564
    virtual ~ArenaBGMCont() {};
};

namespace arena
{
class Arena : public ProcEx
{
public:
    /* 38 */ Unit * unk_38;
    /* 3C */ Unit * unk_3c;
    /* 40 */ Item unk_40[5];
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

    Arena(Unit * unit)
    {
        func_02039eac("shop");

        this->unk_38 = unit;
        this->unk_60 = NULL;
        this->unk_5c = 0;
        this->unk_5b = 0;

        this->_021d8ed4();

        gpActiveScreenSt->dispIo->bldcnt.effect = 1;

        gpActiveScreenSt->dispIo->blend_coeff_a = 0xe;
        gpActiveScreenSt->dispIo->blend_coeff_b = 2;

        gpActiveScreenSt->dispIo->bldcnt.target1_bg0_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_bg1_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_bg2_on = 1;
        gpActiveScreenSt->dispIo->bldcnt.target1_bg3_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_obj_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target1_bd_on = 0;

        gpActiveScreenSt->dispIo->bldcnt.target2_bg0_on = 1;
        gpActiveScreenSt->dispIo->bldcnt.target2_bg1_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_bg2_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_bg3_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_obj_on = 0;
        gpActiveScreenSt->dispIo->bldcnt.target2_bd_on = 1;

        func_ov000_021a5810(gMapStateManager->unk_0c, 1);
        this->_021d9078();
    }

    virtual ~Arena()
    {
        gpActiveScreenSt->dispIo->bldcnt.effect = 0;

        func_ov000_021a57e4(gMapStateManager->unk_0c, 1);
        this->_021d9120();
        this->_021d9024();

        delete this->unk_60;
        delete this->unk_5c;

        func_02039f00("shop", 0);
    }

    void _021d7d1c(void); // func_ov000_021d7d1c
    void _021d7d50(void); // func_ov000_021d7d50
    void _021d7d98(void); // func_ov000_021d7d98
    s32 _021d7db8(Unit *, s32); // func_ov000_021d7db8
    void _021d7e1c(void); // func_ov000_021d7e1c
    void _021d8014(void); // func_ov000_021d8014
    void _021d8064(void); // func_ov000_021d8064
    u8 * _021d80a4(Unit *, s32); // func_ov000_021d80a4
    void _021d8104(void); // func_ov000_021d8104
    void _021d8604(void); // func_ov000_021d8604
    void _021d8694(void); // func_ov000_021d8694
    void _021d86e0(void); // func_ov000_021d86e0
    void _021d87a4(void); // func_ov000_021d87a4
    void _021d881c(void); // func_ov000_021d881c
    void _021d882c(BOOL); // func_ov000_021d882c
    ArenaProc_unk_5c * _021d8bbc(void); // func_ov000_021d8bbc
    void * _021d8bfc(void); // func_ov000_021d8bfc
    void _021d8c2c(void); // func_ov000_021d8c2c
    void _021d8c90(void); // func_ov000_021d8c90
    void _021d8ccc(void); // func_ov000_021d8ccc

    static void _021d8d4c(s32); // func_ov000_021d8d4c

    void _021d8d68(void); // func_ov000_021d8d68
    void _021d8e28(void); // func_ov000_021d8e28
    void _021d8ed4(void); // func_ov000_021d8ed4
    void _021d9024(void); // func_ov000_021d9024
    void _021d9078(void); // func_ov000_021d9078
    void _021d9120(void); // func_ov000_021d9120
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
EC void * func_ov000_021cf59c(arena::Arena *);
EC void func_ov000_021d3b00(struct Unit *, arena::Arena *, s32, s32);
EC void func_ov002_021ef134(arena::Arena *, struct ArenaProc_unk_5c *);

EC struct ArenaEnemy * func_ov000_021d7c90(u32);

EC void func_ov000_021d915c(arena::Arena *);
EC void func_ov000_021d91a0(arena::Arena *);
EC void func_ov000_021d91e4(arena::Arena *);
EC void func_ov000_021d91f0(arena::Arena *);
EC void func_ov000_021d920c(arena::Arena *);
EC void func_ov000_021d9228(arena::Arena *);
EC void func_ov000_021d9244(arena::Arena *);
EC void func_ov000_021d9250(arena::Arena *);
EC void func_ov000_021d9310(arena::Arena *);
EC void func_ov000_021d932c(arena::Arena *);
EC void func_ov000_021d9348(arena::Arena *);
EC void func_ov000_021d9364(arena::Arena *);
EC void func_ov000_021d93d0(arena::Arena *);
EC void func_ov000_021d93ec(arena::Arena *);
EC void func_ov000_021d9408(arena::Arena *);
EC void func_ov000_021d9424(arena::Arena *);
EC void func_ov000_021d9440(arena::Arena *);
EC void func_ov000_021d945c(arena::Arena *);
EC void func_ov000_021d94f4(arena::Arena *);
EC void func_ov000_021d9478(arena::Arena *);
EC void func_ov000_021d9484(arena::Arena *);
EC void func_ov000_021d9490(arena::Arena *);
EC void func_ov000_021d949c(arena::Arena *);
EC void func_ov000_021d94ac(arena::Arena *);
EC void func_ov000_021d94b8(arena::Arena *);
EC void func_ov000_021d94c4(arena::Arena *);
EC void func_ov000_021d94d0(arena::Arena *);
EC void func_ov000_021d94dc(arena::Arena *);
EC void func_ov000_021d94e8(arena::Arena *);
EC void func_ov000_021d9500(arena::Arena *);
EC void func_ov000_021d9520(arena::Arena *);
EC void func_ov000_021d9538(arena::Arena *);
EC void func_ov000_021d95b0(arena::Arena *);
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
    struct ArenaEnemy * arenaEnemy = static_cast<struct ArenaEnemy *>(HashTable::Get2("ArenaEnemy"));

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

void arena::Arena::_021d7d1c(void)
{
    this->_021d8014();

    this->unk_3c = Force::Get(4)->head;
    func_0203bd34(this->unk_3c, 1, 1);

    this->_021d7d98();

    return;
}

void arena::Arena::_021d7d50(void)
{
    if ((this->unk_38->state2 & 8) != 0)
    {
        data_021974fc->unk_00 = 0;
    }

    func_0203bd34(this->unk_3c, 4, 1);
    this->_021d8064();

    return;
}

void arena::Arena::_021d7d98(void)
{
    this->_021d7e1c();
    this->_021d8104();
    this->_021d8604();
    return;
}

s32 arena::Arena::_021d7db8(Unit * unit, s32 arg_2)
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

void arena::Arena::_021d7e1c(void)
{
    s32 set;
    s32 rng;
    s32 iVar7;
    s32 level;
    struct ArenaEnemy * arenaEnemy;
    struct PersonData * pPersonData;
    struct JobData * pJobData;

    s32 bestWeaponType = this->_021d7db8(this->unk_38, 0);

    BOOL isPromotedOrHighLevel = FALSE;

    if (CheckUnitAttribute(this->unk_38, 0x800))
    {
        isPromotedOrHighLevel = TRUE;
    }
    else if (this->unk_38->pJobData->pPromoteJob == NULL)
    {
        if ((s32)this->unk_38->level >= 16)
        {
            isPromotedOrHighLevel = TRUE;
        }
    }

    if (isPromotedOrHighLevel)
    {
        if (CheckUnitAttribute(this->unk_38, 0x400))
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
        if (CheckUnitAttribute(this->unk_38, 0x400) != 0)
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

    level = this->unk_38->level;

    if (CheckUnitAttribute(this->unk_38, 0x800) != 0)
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

    func_0203a728(this->unk_3c, pPersonData, pJobData, level);
    this->unk_3c->state2 |= 0x1000;

    if (RollRN(0, 9) != 0)
    {
        this->unk_5a = 0;
    }
    else
    {
        this->unk_5a = 1;
    }

    this->unk_6c = 0;
    this->unk_6d = 0;
    this->unk_6e = 0;

    return;
}

void arena::Arena::_021d8014(void)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        this->unk_40[i] = &this->unk_38->items[i];
        this->unk_38->items[i].Clear();
    }

    return;
}

/* NONMATCHING: https://decomp.me/scratch/SlQqe */
void arena::Arena::_021d8064(void)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        this->unk_38->items[i] = &this->unk_40[i];
    }

    return;
}

u8 * arena::Arena::_021d80a4(Unit * unit, s32 arg_2)
{
    u32 uVar1;

    switch (this->_021d7db8(unit, arg_2))
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
void arena::Arena::_021d8104(void)
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

    sp_04 = this->_021d80a4(this->unk_38, 0);
    r5 = this->_021d80a4(this->unk_3c, 1);

    r6 = func_02038348(&gFE11Database->pItem[*sp_04]);
    r7 = func_02038348(&gFE11Database->pItem[*r5]);

    r8 = func_0203dbd4(this->unk_38, r6, r7);

    for (r4 = 0; r4 < 10; r4++)
    {
        r0 = func_0203dbd4(this->unk_3c, r7, r6);

        if (this->unk_5a != 0)
        {
            if (r8 < r0)
            {
                if ((r8 * 115) / 100 < r0)
                {
                    func_0203de10(this->unk_3c);
                    this->unk_6c--;
                    continue;
                }
                else if ((r8 * 110) / 100 > r0)
                {
                    func_0203dd48(this->unk_3c);
                    this->unk_6c++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                func_0203dd48(this->unk_3c);
                this->unk_6c++;
                continue;
            }
        }
        else if (r8 < r0)
        {
            if ((r8 * 115) / 100 < r0)
            {
                func_0203de10(this->unk_3c);
                this->unk_6c--;
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
                func_0203dd48(this->unk_3c);
                this->unk_6c++;
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
        if (func_0203c7ac(this->unk_3c, wpnType) != 0)
        {
            wpnLevel = item->wpnLevel;
            if (wpnLevel > func_0203c7ac(this->unk_3c, wpnType))
            {
                s32 idk = item->wpnLevel;
                idk -= func_0203c7ac(this->unk_3c, wpnType);

                if (idk + this->unk_3c->unk_84[wpnType] <= 0xFF)
                {
                    this->unk_3c->unk_84[wpnType] += idk;
                }
                else
                {
                    this->unk_3c->unk_84[wpnType] = 0xFF;
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
            playerAttack = GetUnitMag(this->unk_38, NULL, TRUE);
            opponentDefense = GetUnitRes(this->unk_3c, NULL, TRUE);
        }
        else
        {
            playerMight = gFE11Database->pItem[*sp_04].might;
            playerAttack = GetUnitStr(this->unk_38, NULL, TRUE);
            opponentDefense = GetUnitDef(this->unk_3c, NULL, TRUE);
        }

        playerMight = ((playerMight + playerAttack) - opponentDefense);

        if (r7 != 0)
        {
            opponentMight = gFE11Database->pItem[*r5].might;
            opponentAttack = GetUnitMag(this->unk_3c, NULL, TRUE);
            playerDefense = GetUnitRes(this->unk_38, NULL, TRUE);
        }
        else
        {
            opponentMight = gFE11Database->pItem[*r5].might;
            opponentAttack = GetUnitStr(this->unk_3c, NULL, TRUE);
            playerDefense = GetUnitDef(this->unk_38, NULL, TRUE);
        }

        opponentMight = ((opponentMight + opponentAttack) - playerDefense);

        if ((playerMight * 6) < GetUnitMaxHp(this->unk_3c))
        {
            if (r6 != 0)
            {
                if (GetUnitRes(this->unk_3c, 0, TRUE) > 0)
                {
                    this->unk_3c->unk_50[7]--;
                    this->unk_6e--;
                }
            }
            else
            {
                if (GetUnitDef(this->unk_3c, 0, TRUE) > 0)
                {
                    this->unk_3c->unk_50[6]--;
                    this->unk_6e--;
                }
            }
        }

        if ((opponentMight * 6) < GetUnitMaxHp(this->unk_38))
        {
            s32 idk;

            if (r7 != 0)
            {
                this->unk_3c->unk_50[2]++;
            }
            else
            {
                this->unk_3c->unk_50[1]++;
            }

            this->unk_6d++;

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

            if (func_0203c7ac(this->unk_3c, wpnType) == 0)
            {
                continue;
            }

            wpnLevel = item->wpnLevel;

            if (wpnLevel <= func_0203c7ac(this->unk_3c, wpnType))
            {
                continue;
            }

            idk = item->wpnLevel;
            idk -= func_0203c7ac(this->unk_3c, wpnType);

            if (idk + this->unk_3c->unk_84[wpnType] <= 0xFF)
            {
                this->unk_3c->unk_84[wpnType] += idk;
            }
            else
            {
                this->unk_3c->unk_84[wpnType] = 0xFF;
            }
        }
    }

    this->unk_38->items[0].InitFromIid(*sp_04);
    this->unk_38->items[0].flags |= 0x10;

    this->unk_3c->items[0].InitFromIid(*r5);
    this->unk_3c->items[0].flags |= 0x10;

    return;
}

void arena::Arena::_021d8604(void)
{
    s32 iVar1;
    s32 iVar5;
    u32 uVar3;
    u32 uVar4;

    uVar3 = func_02038348(this->unk_38->items[GetUnitEquippedWeaponSlot(this->unk_38)].GetData());
    uVar4 = func_02038348(this->unk_3c->items[GetUnitEquippedWeaponSlot(this->unk_3c)].GetData());

    iVar1 = func_0203dbd4(this->unk_3c, uVar4, uVar3);
    iVar5 = func_0203dbd4(this->unk_38, uVar3, uVar4);

    iVar1 = (iVar1 - (iVar5 >> 1)) * 10;
    if (iVar1 < 0)
    {
        iVar1 = 0;
    }

    this->unk_54 = iVar1 + 500;

    func_02039f40(0, this->unk_54);

    return;
}

void arena::Arena::_021d8694(void)
{
    gSoundManager->unk_a8->vfunc_3c(0x10, 9, 0);

    this->unk_64 = 0;
    this->unk_68 = 0;
    this->unk_59 = 0;
    this->unk_5b = 1;

    return;
}

void arena::Arena::_021d86e0(void)
{
    u32 kind;

    this->unk_38->items[0].uses = this->unk_38->items[0].GetData()->uses;
    this->unk_3c->items[0].uses = this->unk_3c->items[0].GetData()->uses;

    kind = 1;
    if (this->unk_38->items[0].GetData()->type == 3 || this->unk_3c->items[0].GetData()->type == 3)
    {
        kind = 2;
    }

    this->unk_60 = new ArenaProc_unk_60();

    func_ov000_021c8b28(this->unk_60, this->unk_38, this->unk_3c, kind);

    this->unk_5c = new ArenaProc_unk_5c(this->unk_60);

    func_ov000_021c97ec(this->unk_5c);

    this->unk_64++;

    return;
}

void arena::Arena::_021d87a4(void)
{
    u8 tmp;

    if ((gKeySt->pressed & KEY_BUTTON_B) || (func_ov000_021a5650(gMapStateManager->unk_0c, 0) != 0))
    {
        this->unk_59 = 1;
    }

    // TODO: Most likely an inline
    tmp = (data_ov002_021faf8c.unk_08 & 2);

    if ((tmp & 0xFF) != 0)
    {
        func_ov000_021d3b00(this->unk_38, this, 0, 0);
    }

    return;
}

void arena::Arena::_021d881c(void)
{
    func_ov002_021ef134(this, this->unk_5c);
    return;
}

void arena::Arena::_021d882c(BOOL arg_1)
{
    struct Unit * pUnit;
    s32 uVar6;

    BOOL idk = 0;
    if (func_ov000_021ca0b8(this->unk_5c) != NULL)
    {
        idk = 1;
    }

    func_ov000_021c9b1c(this->unk_5c);

    if (!(this->unk_59 == 0 && !idk) || (this->unk_64 >= 6))
    {
        pUnit = func_0203c378(this->unk_38);

        if (pUnit->unk_30.unk_00 < 9999)
        {
            pUnit->unk_30.unk_00++;
        }

        if (func_ov000_021ca0b8(this->unk_5c) == this->unk_3c)
        {
            func_ov000_021a5810(gMapStateManager->unk_0c, 0);
            Proc_Goto(this, 6, 0);
            pUnit = func_0203c378(this->unk_38);

            if (pUnit->unk_30.unk_02 < 9999)
            {
                pUnit->unk_30.unk_02++;
            }

            uVar6 = -2;
        }
        else
        {
            if (func_ov000_021ca0b8(this->unk_5c) == this->unk_38)
            {
                func_ov000_021a57e4(gMapStateManager->unk_0c, 0);
                Proc_Goto(this, 7, 0);
                uVar6 = -1;
            }
            else if (this->unk_59 != 0)
            {
                func_ov000_021a57e4(gMapStateManager->unk_0c, 0);
                Proc_Goto(this, 8, 0);
                uVar6 = -1;
            }
            else
            {
                func_ov000_021a57e4(gMapStateManager->unk_0c, 0);
                Proc_Goto(this, 9, 0);
                uVar6 = -1;
            }
        }

        if (data_02196f24->enableBgm && uVar6 != -2)
        {
            if (uVar6 != -1)
            {
                gSoundManager->unk_a8->vfunc_3c(0x10, uVar6, 0);
            }
            else
            {
                gSoundManager->unk_a8->vfunc_38(0x10);
            }
        }

        this->unk_5b = 0;
    }
    else
    {
        delete this->unk_60;
        delete this->unk_5c;
    }
}

struct ArenaProc_unk_5c * arena::Arena::_021d8bbc(void)
{
    if ((this->unk_59 != 0) || (this->unk_64 >= 6))
    {
        return NULL;
    }

    this->_021d882c(TRUE);
    this->_021d86e0();

    return this->unk_5c;
}

void * arena::Arena::_021d8bfc(void)
{
    func_ov000_021c9f8c(this->unk_5c, this->unk_68);

    if (this->unk_5c->unk_24 == 0)
    {
        return this->unk_5c;
    }

    return func_ov000_021cf59c(this);
}

void arena::Arena::_021d8c2c(void)
{
    s32 iVar1 = this->unk_54;
    iVar1 = (u32)data_02196f20->unk_190 + iVar1;

    if (iVar1 > 999999)
    {
        data_02196f20->unk_190 = 999999;
    }
    else
    {
        data_02196f20->unk_190 = iVar1;
    }

    this->_021d8ed4();

    gSoundManager->unk_b0->vfunc_28(SE_MAP_MONEY1, 0, 0);

    return;
}

void arena::Arena::_021d8c90(void)
{
    s32 iVar1 = -this->unk_54;
    iVar1 = (u32)data_02196f20->unk_190 + iVar1;

    if (iVar1 > 999999)
    {
        data_02196f20->unk_190 = 999999;
    }
    else
    {
        data_02196f20->unk_190 = iVar1;
    }

    this->_021d8ed4();

    return;
}

void arena::Arena::_021d8ccc(void)
{
    if (this->unk_58 != 0)
    {
        delete this->unk_60;
        delete this->unk_5c;

        this->unk_60 = NULL;
        this->unk_5c = NULL;

        func_0203a94c(this->unk_3c);
        this->_021d7d98();

        Proc_Goto(this, 3, 0);
        return;
    }

    Proc_Goto(this, 2, 0);

    return;
}

EC void func_ov000_021d8d4c(s32 arg_0)
{
    arena::Arena * proc = static_cast<arena::Arena *>(Proc_Find(data_ov000_021e2f38));
    proc->unk_58 = arg_0;
    return;
}

namespace map
{
class BMapDialogYesNo : public DialogYesNo
{
public:
    /* 000 */ virtual void vfunc_00(void); // func_ov000_021be6d8
    /* 0A0 */ virtual BOOL vfunc_a0(void); // func_ov000_021be934
    /* 0AC */ virtual s32 vfunc_ac(void); // func_ov000_021be91c
    /* 130 */ virtual void vfunc_130(/* ? */); // func_ov000_021bea74
    /* 134 */ virtual void vfunc_134(/* ? */); // func_ov000_021beab0
};

} // namespace map

class DI_ArenaYes : public DialogItemYes
{
public:
    // func_ov000_021d9940
    /* 01C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021d8d4c(1);
        return 0x41;
    }
};

class DI_ArenaNo : public DialogItemNo
{
public:
    // func_ov000_021d9938
    /* 014 */ virtual s32 vfunc_14(void)
    {
        return 0;
    }

    // func_ov000_021d9924
    /* 01C */ virtual s32 vfunc_1c(void)
    {
        func_ov000_021d8d4c(0);
        return 0x81;
    }
};

void arena::Arena::_021d8d68(void)
{
    DialogYesNo * dialog;

    static DI_ArenaYes sArenaYes;
    static DI_ArenaNo sArenaNo;

    // clang-format off
    static DialogItem * data_ov000_021e2ca0[] =
    {
        &sArenaYes,
        &sArenaNo,
    };
    // clang-format on

    func_02039f40(0, this->unk_54);

    dialog = new map::BMapDialogYesNo();

    func_020303bc(dialog, func_02039e10("MD_賭金"), data_ov000_021e2ca0, this, 1, 0);

    return;
}

void arena::Arena::_021d8e28(void)
{
    DialogYesNo * dialog;

    static DI_ArenaYes sArenaYes;
    static DI_ArenaNo sArenaNo;

    // clang-format off
    static DialogItem * data_ov000_021e2cac[] =
    {
        &sArenaYes,
        &sArenaNo,
    };
    // clang-format on

    dialog = new map::BMapDialogYesNo();

    func_020303bc(dialog, func_02039e10("MD_再挑戦"), data_ov000_021e2cac, this, 1, 0);

    return;
}

/* NONMATCHING: https://decomp.me/scratch/KlfJk */
void arena::Arena::_021d8ed4(void)
{
    u32 uVar2;
    u32 bVar1;
    struct VmMap_Common * pUVar3;
    u32 bg;

    pUVar3 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_Font"));
    bg = pUVar3->unk_07;
    uVar2 = pUVar3->unk_04;
    bVar1 = pUVar3->unk_06;

    func_02010f98(gpActiveScreenSt->tilemap[bg] + 0x54, 0xb, 2);

    uVar2 += func_020295ec(
        data_021970c4, func_02039e10("MD_MONEY"), gpActiveScreenSt->bgTiles[bg], gpActiveScreenSt->tilemap[bg],
        0x14, 2, uVar2, bVar1, 0, 0);
    uVar2 += func_020295ec(
        data_021970c4, func_02039e10("MD_GOLD"), gpActiveScreenSt->bgTiles[bg], gpActiveScreenSt->tilemap[bg],
        0x1e, 2, uVar2, bVar1, 0, 0);
    func_02029850(
        data_021970c4, data_02196f20->unk_190, gpActiveScreenSt->bgTiles[bg], gpActiveScreenSt->tilemap[bg], 0x1d,
        2, uVar2, bVar1, 0);

    gpActiveScreenSt->unk_3e |= 1 << bg;

    return;
}

void arena::Arena::_021d9024(void)
{
    u8 bVar1;
    struct VmMap_Common * pUVar2 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_Font"));

    bVar1 = pUVar2->unk_07;
    func_02010f98(gpActiveScreenSt->tilemap[bVar1] + 0xa8, 0xb, 2);
    gpActiveScreenSt->unk_3e |= 1 << bVar1;

    return;
}

/* NONMATCHING: https://decomp.me/scratch/LWUIx */
void arena::Arena::_021d9078(void)
{
    u32 uVar4;
    u16 uVar2;
    u8 bVar1;
    struct VmMap_Common * pUVar4 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_BG2Free"));

    uVar4 = pUVar4->unk_07;
    uVar2 = pUVar4->unk_04;
    bVar1 = pUVar4->unk_06;

    func_020a8f40("/shop");

    func_0201177c("money.cg", ((u32)(gpActiveScreenSt->bgTiles[uVar4])) + uVar2 * 0x20);
    func_02011a70("money.cl", bVar1 * 0x20, 0, 0);
    func_02011a30("money.rect", gpActiveScreenSt->tilemap[uVar4] + 0x10, uVar2, bVar1);

    gpActiveScreenSt->unk_3e |= 1 << uVar4;

    return;
}

void arena::Arena::_021d9120(void)
{
    u8 bVar1;
    struct VmMap_Common * pUVar2 = static_cast<struct VmMap_Common *>(HashTable::Get2("VmMap_BG2Free"));
    bVar1 = pUVar2->unk_07;

    func_01ff9948(bVar1);
    gpActiveScreenSt->unk_3e |= 1 << bVar1;

    return;
}

EC void func_ov000_021d915c(arena::Arena * proc)
{
    if (!data_02196f24->enableBgm)
    {
        return;
    }

    StartSoundWaitTo_02017518(gSoundManager->unk_a8, gSoundManager->unk_a4, 0x10, 0x34, 0x10);

    return;
}

EC void func_ov000_021d91a0(arena::Arena * unused)
{
    if (!data_02196f24->enableBgm)
    {
        return;
    }

    if ((data_ov000_021e3340->unk_06 & 8) != 0)
    {
        func_ov000_021a43e8();
    }
    else
    {
        func_ov000_021a4694();
    }

    return;
}

EC void func_ov000_021d91e4(arena::Arena * proc)
{
    proc->_021d7d1c();
    return;
}

EC void func_ov000_021d91f0(arena::Arena * proc)
{
    func_0200ac20("M闘技場_WELCOME", proc, 0);
    return;
}

EC void func_ov000_021d920c(arena::Arena * proc)
{
    func_0200ac20("M闘技場_PRICE", proc, 0);
    return;
}

EC void func_ov000_021d9228(arena::Arena * proc)
{
    func_0200ac20("M闘技場_CHALLENGE", proc, 0);
    return;
}

EC void func_ov000_021d9244(arena::Arena * proc)
{
    proc->_021d8d68();
    return;
}

EC void func_ov000_021d9250(arena::Arena * proc)
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

EC void func_ov000_021d9310(arena::Arena * proc)
{
    func_0200ac20("M闘技場_BATTLE", proc, 0);
    return;
}

EC void func_ov000_021d932c(arena::Arena * proc)
{
    func_0200ac20("M闘技場_GETOUT", proc, 0);
    return;
}

EC void func_ov000_021d9348(arena::Arena * proc)
{
    func_0200ac20("M闘技場_POOR", proc, 0);
    return;
}

EC void func_ov000_021d9364(arena::Arena * proc)
{
    func_02039f40(0, proc->unk_54);
    func_0200ac20("M闘技場_WIN", proc, 0);

    if (data_02196f24->enableBgm == 0)
    {
        return;
    }

    gSoundManager->unk_a8->vfunc_3c(0x10, 0x35, 0);

    return;
}

EC void func_ov000_021d93d0(arena::Arena * proc)
{
    func_0200ac20("M闘技場_LOSE", proc, 0);
    return;
}

EC void func_ov000_021d93ec(arena::Arena * proc)
{
    func_0200ac20("M闘技場_DRAW", proc, 0);
    return;
}

EC void func_ov000_021d9408(arena::Arena * proc)
{
    func_0200ac20("M闘技場_STOP", proc, 0);
    return;
}

EC void func_ov000_021d9424(arena::Arena * proc)
{
    func_0200ac20("M闘技場_FORFEIT", proc, 0);
    return;
}

EC void func_ov000_021d9440(arena::Arena * proc)
{
    func_0200ac20("M闘技場_RETRY", proc, 0);
    return;
}

EC void func_ov000_021d945c(arena::Arena * proc)
{
    func_0200ac20("M闘技場_BYE", proc, 0);
    return;
}

EC void func_ov000_021d9478(arena::Arena * proc)
{
    proc->_021d8694();
    return;
}

EC void func_ov000_021d9484(arena::Arena * proc)
{
    proc->_021d86e0();
    return;
}

EC void func_ov000_021d9490(arena::Arena * proc)
{
    proc->_021d881c();
    return;
}

EC void func_ov000_021d949c(arena::Arena * proc)
{
    proc->_021d882c(0);
    return;
}

EC void func_ov000_021d94ac(arena::Arena * proc)
{
    proc->_021d87a4();
    return;
}

EC void func_ov000_021d94b8(arena::Arena * proc)
{
    proc->_021d8bfc();
    return;
}

EC void func_ov000_021d94c4(arena::Arena * proc)
{
    proc->_021d8c2c();
    return;
}

EC void func_ov000_021d94d0(arena::Arena * proc)
{
    proc->_021d8c90();
    return;
}

EC void func_ov000_021d94dc(arena::Arena * proc)
{
    proc->_021d8e28();
    return;
}

EC void func_ov000_021d94e8(arena::Arena * proc)
{
    proc->_021d8ccc();
    return;
}

EC void func_ov000_021d94f4(arena::Arena * proc)
{
    proc->_021d7d50();
    return;
}

EC void func_ov000_021d9500(arena::Arena * unused)
{
    func_ov000_021a57e4(gMapStateManager->unk_0c, 0);
    return;
}

EC void func_ov000_021d9520(arena::Arena * proc)
{
    proc->_021d9078();
    proc->_021d8ed4();
    return;
}

EC void func_ov000_021d9538(arena::Arena * proc)
{
    proc->_021d9120();
    proc->_021d9024();
    return;
}

EC void func_ov000_021d9550(ArenaBGMCont * proc)
{
    proc->Loop();
    return;
}

// func_ov000_021d9564
void ArenaBGMCont::Loop(void)
{
    if (func_02016250(0x35))
    {
        return;
    }

    gSoundManager->unk_a8->vfunc_28(BGM_SYS_TOUGIJOU1, 0, 0);

    Proc_End(this);

    return;
}

extern struct ProcCmd data_ov000_021e2cb8[];

EC void func_ov000_021d95b0(arena::Arena * parent)
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
    struct Unit * unit;

    if (gActionSt->unitId == 0)
    {
        unit = NULL;
    }
    else
    {
        unit = gUnitList + gActionSt->unitId - 1;
    }

    if (data_ov000_021e3320[unit->force->id] == 1)
    {
        data_021974fc->unk_00 = unit;
        func_0204b194(unit->xPos, unit->yPos);
    }

    new (Proc_StartBlocking(data_ov000_021e2f38, parent)) arena::Arena(gMapStateManager->unk_04->unk_00);

    return;
}

EC void func_ov000_021d98ec(void)
{
    arena::Arena * arena = static_cast<arena::Arena *>(Proc_Find(data_ov000_021e2f38));
    arena->_021d8bbc();
    return;
}

EC u32 func_ov000_021d9904(void)
{
    arena::Arena * proc = static_cast<arena::Arena *>(Proc_Find(data_ov000_021e2f38));

    if (proc != NULL)
    {
        return proc->unk_5b;
    }

    return 0;
}
