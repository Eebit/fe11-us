#include "global.h"

#include "proc.h"
#include "unknown_funcs.h"
#include "unknown_data.h"

#include "unknown_types.hpp"
#include "database.hpp"
#include "event.hpp"
#include "hashtable.hpp"
#include "heap.hpp"
#include "map.hpp"
#include "sound_manager.hpp"
#include "state_manager.hpp"

EC void func_020210d0(struct MapData *, s32);

// TODO: Not actually data?
extern void data_ov010_02209e54(ProcPtr);

EC void func_020136bc(ProcPtr);
EC void func_0201fd44(ProcPtr);

EC void func_0204b1e0(ProcPtr);

EC void func_02021b00(void);
EC void func_02021b14(void);
EC void func_02021d70(void);
EC void func_02021dd4(void);
EC void func_02021e6c(void);
EC void func_02021f08(ProcPtr);
EC void func_02021f2c(ProcPtr);
EC void func_02021f5c(void);
EC void func_0202214c(ProcPtr);
EC void func_020221bc(void);
EC void func_020221e4(void);
EC void func_0202225c(void);
EC void func_02022324(void);
EC void func_02022364(ProcPtr);
EC void func_020223b4(void);
EC void func_020223cc(ProcPtr);
EC void func_02022414(void);
EC void func_02022458(void);
EC void func_02022480(void);
EC void func_020224a8(ProcPtr);
EC void func_020224d4(void);
EC void func_020224fc(void);
EC void func_0202254c(ProcPtr);
EC void func_02022564(void);
EC void func_02022588(void);
EC void func_0202272c(ProcPtr);
EC void func_02022814(void);
EC void func_0202284c(ProcPtr);
EC void func_020228ac(ProcPtr);
EC void func_020228ec(ProcPtr);
EC BOOL func_02022988(void);
EC void func_020229a8(void);
EC void func_020229f0(void);
EC BOOL func_02022b10(void);
EC BOOL func_02022b30(void);
EC BOOL func_02022b50(void);
EC void func_02022b70(ProcPtr);
EC void func_02022bb0(ProcPtr);
EC void func_02022c54(ProcPtr);
EC void func_02022c78(ProcPtr);
EC void func_02022cb0(ProcPtr);
EC void func_02022cdc(ProcPtr);
EC void func_02022db8(void);
EC void func_02022dc8(void);
EC void func_02022dfc(void);
EC void func_02022e14(void);
EC BOOL func_02022e34(void);
EC void func_02022e54(void);
EC BOOL func_02022eb8(void);
EC BOOL func_02022ed4(void);
EC BOOL func_02022ef4(void);

// clang-format off

struct ProcCmd ProcScr_GameCtrl[] =
{
    PROC_NAME,
    PROC_SLEEP(0),

    PROC_06(0, func_02021d70),
    PROC_CALL(func_020136bc),
    PROC_START_CHILD(data_020cec14),

    PROC_GOTO(1),

PROC_LABEL(1),
    PROC_START_CHILD_LOCKING(data_020ceba4),

    PROC_GOTO(3),

PROC_LABEL(2),
    PROC_START_CHILD_LOCKING(data_020ceb84),

    PROC_GOTO(3),

PROC_LABEL(3),
    PROC_WHILE_EXISTS(data_020cec14),
    PROC_CALL(func_02021b00),

    PROC_GOTO(4),

PROC_LABEL(4),
    PROC_REPEAT(func_02021f08),
    PROC_REPEAT(func_02021f2c),
    PROC_CALL(func_02021b14),
    PROC_CALL(func_0201fd44),
    PROC_START_CHILD_LOCKING(data_020cebc4),

    PROC_GOTO(2),

PROC_LABEL(5),
    PROC_CALL(func_02022cdc),

    PROC_GOTO(6),

PROC_LABEL(6),
    PROC_OVERLAY_LOAD(4),
    PROC_CALL(data_ov010_02209e54),
    PROC_OVERLAY_UNLOAD(4),

    // fallthrough

PROC_LABEL(7),
    PROC_REPEAT(func_02021f2c),
    PROC_CALL(func_02021dd4),
    PROC_CALL(func_02021f5c),
    PROC_CALL(func_0202214c),
    PROC_CALL(func_020221bc),
    PROC_CALL(func_020221e4),
    PROC_CALL(func_02022364),
    PROC_CALL(func_020223b4),
    PROC_OVERLAY_LOAD(5),
    PROC_CALL(func_ov005_022052d0),
    PROC_OVERLAY_UNLOAD(5),

    // fallthrough

PROC_LABEL(8),
    PROC_CALL(func_020223cc),
    PROC_CALL(func_02022414),
    PROC_CALL(func_02022458),

    // fallthrough

PROC_LABEL(9),
    PROC_CALL(func_ov000_021a9714),

    // fallthrough

PROC_LABEL(10),
    PROC_WHILE(func_0204b1e0),
    PROC_CALL(func_02022480),
    PROC_CALL(func_020224a8),
    PROC_CALL(func_02022414),
    PROC_CALL(func_020224d4),
    PROC_FADE_TO_BLACK(16, 1, TRUE),
    PROC_CALL(func_020224fc),

    // fallthrough

PROC_LABEL(11),
    PROC_CALL(func_0202254c),
    PROC_CALL(func_02022564),
    PROC_CALL(func_02022588),
    PROC_CALL(func_0202272c),
    PROC_CALL(func_02021e6c),
    PROC_START_CHILD_LOCKING(data_020cebec),

    PROC_GOTO(6),

PROC_LABEL(12),
    PROC_FADE_TO_BLACK(64, 1, TRUE),
    PROC_CALL(func_020224fc),
    PROC_CALL(func_0202254c),
    PROC_CALL(func_02022564),
    PROC_CALL(func_02021e6c),
    PROC_OVERLAY_LOAD(6),
    PROC_CALL(func_ov006_0221776c),
    PROC_OVERLAY_UNLOAD(6),
    PROC_CALL(func_02021b00),

    PROC_GOTO(2),

PROC_LABEL(13),
    PROC_OVERLAY_LOAD(9),
    PROC_CALL(func_02022db8),
    PROC_CALL(func_ov009_02206020),
    PROC_CALL(func_ov009_022065a0),
    PROC_CALL(func_ov009_02204e10),
    PROC_CALL(func_02022dc8),
    PROC_OVERLAY_UNLOAD(9),
    PROC_CALL(func_02021b00),

    PROC_GOTO(2),

PROC_LABEL(14),
    PROC_CALL(func_02022c54),
    PROC_CALL(func_02022cdc),
    PROC_CALL(func_02022324),

    PROC_GOTO(6),

PROC_LABEL(15),
    PROC_REPEAT(func_02021f2c),
    PROC_CALL(func_02022c78),
    PROC_CALL(func_02022cdc),
    PROC_CALL(func_020221e4),
    PROC_CALL(func_0202225c),
    PROC_FADE_FROM_BLACK(8, 1, TRUE),

    PROC_GOTO(9),

PROC_LABEL(16),
    PROC_REPEAT(func_02021f2c),
    PROC_CALL(func_02022cb0),
    PROC_CALL(func_02022cdc),
    PROC_CALL(func_020221e4),
    PROC_CALL(func_0202225c),
    PROC_FADE_FROM_BLACK(8, 1, TRUE),

    PROC_GOTO(9),

PROC_LABEL(39),
    PROC_WHILE(func_0204b1e0),
    PROC_FADE_TO_BLACK(32, 1, TRUE),
    PROC_CALL(func_020224fc),
    PROC_CALL(func_0202254c),
    PROC_CALL(func_02022564),
    PROC_CALL(func_02021e6c),
    PROC_CALL(func_02021b00),

    PROC_GOTO(2),

PROC_LABEL(17),
    PROC_OVERLAY_LOAD(6),
    PROC_CALL(func_ov006_02221aec),
    PROC_OVERLAY_UNLOAD(6),

    PROC_GOTO(4),

PROC_LABEL(18),
    PROC_OVERLAY_LOAD(6),
    PROC_CALL(func_ov006_022226cc),
    PROC_OVERLAY_UNLOAD(6),

    PROC_GOTO(4),

PROC_LABEL(21),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021f049c),
    PROC_25(2, 0),

    PROC_GOTO(4),

PROC_LABEL(26),
    PROC_OVERLAY_LOAD(11),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e4204),
    PROC_GOTO_IF_NO(func_02022ef4, 40),
    PROC_CALL(func_ov003_021f24e4),

    PROC_GOTO(40),

PROC_LABEL(19),
    PROC_OVERLAY_LOAD(11),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021fc0d4),
    PROC_25(2, 0),
    PROC_OVERLAY_UNLOAD(11),

    PROC_GOTO(4),

PROC_LABEL(20),
    PROC_25(1, 0),
    PROC_OVERLAY_LOAD(11),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e3610),
    PROC_25(2, 0),
    PROC_OVERLAY_UNLOAD(11),
    PROC_25(0, 0),

    PROC_GOTO(4),

PROC_LABEL(27),
    PROC_25(3, 0),
    PROC_OVERLAY_LOAD(7),
    PROC_CALL(func_ov007_02218284),
    PROC_OVERLAY_UNLOAD(7),
    PROC_25(2, 0),

    PROC_GOTO(4),

PROC_LABEL(28),
    PROC_OVERLAY_LOAD(7),
    PROC_CALL(func_ov007_0221ad60),
    PROC_OVERLAY_UNLOAD(7),

    PROC_GOTO(4),

PROC_LABEL(23),
    PROC_CALL(func_020229a8),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e4204),
    PROC_GOTO_IF_NO(func_02022ef4, 40),
    PROC_CALL(func_020228ac),
    PROC_GOTO_IF_NO(func_02022ef4, 40),
    PROC_CALL(func_ov003_021f9470),

    PROC_GOTO(40),

PROC_LABEL(24),
    PROC_OVERLAY_LOAD(11),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e4244),
    PROC_GOTO_IF_NO(func_02022ef4, 40),
    PROC_CALL(func_ov003_021f4a84),

    PROC_GOTO(40),

PROC_LABEL(25),
    PROC_OVERLAY_LOAD(11),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e4244),
    PROC_GOTO_IF_NO(func_02022ef4, 40),
    PROC_CALL(func_ov003_021f6ce8),

    PROC_GOTO(40),

PROC_LABEL(22),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021f31f0),
    PROC_25(2, 0),

    PROC_GOTO(4),

PROC_LABEL(40),
    PROC_CALL(func_ov003_021e4284),
    PROC_25(2, 0),
    PROC_CALL(func_02022814),

    PROC_GOTO(4),

PROC_LABEL(29),
    PROC_CALL(func_020229a8),
    PROC_25(3, 0),
    PROC_CALL(func_020228ec),
    PROC_GOTO_IF_YES(func_02022b30, 30),
    PROC_CALL(func_ov003_021e4204),
    PROC_GOTO_IF_NO(func_02022ef4, 40),

    // fallthrough

PROC_LABEL(30),
    PROC_CALL(func_ov003_021fb690),
    PROC_GOTO_IF_NO(func_02022e34, 40),
    PROC_GOTO_IF_YES(func_02022b30, 34),

    PROC_GOTO(32),

PROC_LABEL(31),
    PROC_CALL(func_ov003_021fb704),
    PROC_GOTO_IF_NO(func_02022e34, 40),
    PROC_GOTO_IF_YES(func_02022b30, 34),

    PROC_GOTO(32),

PROC_LABEL(32),
    PROC_CALL(func_02022e54),
    PROC_CALL(func_0202284c),
    PROC_GOTO_IF_YES(func_02022eb8, 40),
    PROC_GOTO_IF_NO(func_02022ef4, 31),
    PROC_GOTO_IF_YES(func_02022988, 33),
    PROC_CALL(func_ov003_021ebb8c),
    PROC_GOTO_IF_YES(func_02022ed4, 40),

    // fallthrough

PROC_LABEL(33),
    PROC_CALL(func_ov003_021e439c),
    PROC_GOTO_IF_YES(func_02022eb8, 40),

    PROC_GOTO(35),

PROC_LABEL(34),
    PROC_CALL(func_02022e54),
    PROC_CALL(func_ov003_021eb9b0),
    PROC_GOTO_IF_NO(func_02022e34, 31),
    PROC_CALL(func_02022e14),

    PROC_GOTO(35),

PROC_LABEL(35),
    PROC_25(2, 0),
    PROC_CALL(func_02021dd4),
    PROC_CALL(func_02021f5c),
    PROC_CALL(func_0202214c),
    PROC_CALL(func_020221bc),
    PROC_CALL(func_020221e4),
    PROC_FADE_FROM_BLACK(8, 1, TRUE),
    PROC_CALL(func_ov000_021a9714),
    PROC_CALL(func_020229f0),
    PROC_CALL(func_020224d4),
    PROC_CALL(func_02022b70),
    PROC_CALL(func_020224fc),
    PROC_CALL(func_0202254c),
    PROC_CALL(func_02022564),
    PROC_CALL(func_02021e6c),
    PROC_CALL(func_02022dfc),
    PROC_REPEAT(func_02021f08),
    PROC_25(3, 0),
    PROC_GOTO_IF_YES(func_02022b10, 40),
    PROC_GOTO_IF_NO(func_02022b50, 37),

    // fallthrough

PROC_LABEL(36),
    PROC_CALL(func_ov003_021ed664),

    PROC_GOTO(38),

PROC_LABEL(37),
    PROC_CALL(func_ov003_021edf2c),

    PROC_GOTO(38),

PROC_LABEL(38),
    PROC_CALL(func_02022bb0),

    PROC_GOTO(40),

    PROC_BLOCK,
    PROC_END,
};

// clang-format on

extern char * data_02196f14;

extern struct UnkStruct_021e3528 data_ov000_021e3528;

extern struct UnkStruct_021974fc * data_021974fc;

// extern struct Unknown_020efcc8 * gSoundManager;

struct UnkStruct_Func_02021410_Ret * func_02021410(u32);

extern u32 data_020efcb4;

extern struct Unit * gUnitList;

extern vu32 data_027e1264;

extern struct UnkStruct_02196f18 * data_02196f18;

extern struct UnkStruct_020e3ca0 * data_020e3ca0;

extern struct UnkStruct_02196f1c * data_02196f1c;

extern struct UnkStruct_02196f10 * data_02196f10;

extern struct UnkStruct_02196f0c * data_02196f0c;

extern struct UnkStruct_02196f20 * data_02196f20;

extern struct UnkStruct_02196f24 * data_02196f24;

// Forward declarations
EC void InitOnlineShopItemFlags(void);
EC void InitOnlineShopItemAmounts(void);
EC void func_02022f28(u32 label);

EC void func_020217b4(void)
{
    int random;

    LoadOverlay(0);
    LoadOverlay(2);

    HashTable::Init();
    func_02028c68();
    func_020355e4();

    random = RollRN(1, 4) * 4;
    gHeap.Alloc(random);

    if (gFE11Database == NULL)
    {
        gFE11Database = new FE11Database;
    }

    gFE11Database->Init();

    if (data_020e3ca0 == NULL)
    {
        data_020e3ca0 = new UnkStruct_020e3ca0;
    }

    func_02002058(data_020e3ca0);

    if (data_02196f0c == NULL)
    {
        data_02196f0c = new UnkStruct_02196f0c;
    }

    func_02021014();

    if (data_02196f10 == NULL)
    {
        data_02196f10 = new UnkStruct_02196f10;
    }

    func_020423fc();
    Event::func_020476a0();

    if (data_02196f24 == NULL)
    {
        data_02196f24 = new UnkStruct_02196f24;
    }

    func_02024c74();

    if (data_02196f20 == NULL)
    {
        data_02196f20 = new UnkStruct_02196f20;
    }

    func_02024d28();

    if (data_02196f1c == NULL)
    {
        data_02196f1c = new UnkStruct_02196f1c;
    }

    func_02024e70();

    if (data_02196f18 == NULL)
    {
        data_02196f18 = new UnkStruct_02196f18;
    }

    func_02024f34();
    func_0206ecbc();
    func_ov002_021e69ac();
    func_020076a8();
    func_02015f64();

    func_02039eac("system\0");
    func_02039eac("die");
    func_02039eac("tutorial\0\0\0");

    func_02042420("startup");

    InitUnits();
    InitConvoy();
    func_020411e8();

    return;
}

EC void func_020219a4(int param_1, int param_2)
{
    func_020210d0(data_02196f0c->pCurrentMap, param_1);
    func_02024c80();
    func_02024d8c();
    ResetAllForces();
    ClearConvoyItems();
    func_02041234();
    func_0200c888();

    if (param_1 == 0)
    {
        func_02003f88();
    }

    data_02196f0c->flagMgr->RegisterName("gf_canceled", FALSE);
    data_02196f0c->flagMgr->RegisterName("gf_gameover", FALSE);
    data_02196f0c->flagMgr->RegisterName("gf_complete", FALSE);
    data_02196f0c->flagMgr->RegisterName("gf_reserved2\0\0\0", FALSE);
    data_02196f0c->flagMgr->RegisterName("gf_reserved3\0\0\0", FALSE);
    data_02196f0c->flagMgr->RegisterName("gf_reserved4\0\0\0", FALSE);
    data_02196f0c->flagMgr->RegisterName("gf_reserved5\0\0\0", FALSE);
    data_02196f0c->flagMgr->RegisterName("gf_reserved6\0\0\0", FALSE);

    InitOnlineShopItemFlags();
    InitOnlineShopItemAmounts();
    func_020424b8("RegistGrobalFlags\0\0");

    if (param_2 != 0)
    {
        return;
    }

    data_02196f20->unk_198 = func_02025060();

    return;
}

EC void func_02021b00(void)
{
    func_020219a4(0, 0);
    return;
}

EC void func_02021b14(void)
{
    func_020219a4(1, 0);
    return;
}

EC void InitOnlineShopItemFlags(void)
{
    data_02196f0c->valueMgr->RegisterName("os_BraveSword\0\0", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_BraveLance\0\0", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_BraveAxe", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_BraveBow", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_Wato", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_MasterProof\0", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_LongBow\0", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_EmpyreadWhip", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_reserved1\0\0\0", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_reserved2\0\0\0", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_reserved3\0\0\0", FALSE);
    data_02196f0c->valueMgr->RegisterName("os_reserved4\0\0\0", FALSE);

    return;
}

EC void InitOnlineShopItemAmounts(void)
{
    data_02196f0c->valueMgr->SetByName("os_BraveSword\0\0", 3);
    data_02196f0c->valueMgr->SetByName("os_BraveLance\0\0", 3);
    data_02196f0c->valueMgr->SetByName("os_BraveAxe", 3);
    data_02196f0c->valueMgr->SetByName("os_BraveBow", 3);
    data_02196f0c->valueMgr->SetByName("os_Wato", 5);
    data_02196f0c->valueMgr->SetByName("os_MasterProof\0", 15);
    data_02196f0c->valueMgr->SetByName("os_LongBow\0", 5);
    data_02196f0c->valueMgr->SetByName("os_EmpyreadWhip", 3);
    return;
}

EC void func_02021d70(void)
{
    int r3;
    int lr;
    int r1;

    if (data_02196f0c->state & 0x2000000)
    {
        return;
    }

    lr = data_027e1264;
    r3 = lr - data_02196f20->unk_18c;

    r1 = 0x7fffffff;

    if ((u32)data_02196f20->unk_184 <= (0x7fffffff - r3))
    {
        data_02196f20->unk_184 = data_02196f20->unk_184 + r3;
    }
    else
    {
        data_02196f20->unk_184 = r1;
    }

    data_02196f20->unk_18c = lr;

    return;
}

EC void func_02021dd4(void)
{
    data_02196f14 = GetBattleMapNameMaybe();

    if (data_02196f14[0] == 'b' && data_02196f14[1] == 'm' && data_02196f14[2] == 'a' && data_02196f14[3] == 'p')
    {
        data_02196f14 += 4;
    }
    else
    {
        data_02196f14++;
    }

    if (func_02039e7c(data_02196f14))
    {
        func_02039eac(data_02196f14);
    }
    else
    {
        data_02196f14 = NULL;
    }

    func_02042460(GetBattleMapNameMaybe());
    func_020424b8("RegistLocalFlags\0\0\0");
    EventCaller::func_020484b0();

    return;
}

EC void func_02021e6c(void)
{
    EventCaller::func_020485d0();
    func_020424ac();
    
    data_02196f0c->flagMgr->RemoveAll();
    
    data_02196f0c->flagMgr->ClearByName("gf_complete");
    data_02196f0c->flagMgr->ClearByName("gf_gameover");

    data_02196f0c->valueMgr->RemoveAll();

    if (data_02196f14 == NULL)
    {
        return;
    }

    func_02039f00(data_02196f14, 0);
    data_02196f14 = NULL;

    return;
}

EC void func_02021f08(ProcPtr proc)
{
    if (func_0201f690())
    {
        return;
    }

    Proc_Break(proc, 1);

    return;
}

EC void func_02021f2c(ProcPtr proc)
{
    if (func_020020e0(data_020e3ca0))
    {
        return;
    }

    Proc_Break(proc, 1);

    return;
}

EC void func_02021f5c(void)
{
    int i;

    if (data_ov000_021e3324 == NULL)
    {
        data_ov000_021e3324 = new UnkStruct_021E3324;
    }

    for (i = 0; i < 0x2e; i++)
    {
        data_ov000_021e3528.unk_00[i] = -1;
    }

    data_ov000_021e3528.unk_2e = 0;
    data_ov000_021e3528.unk_2f = 0;

    if ((data_02196f0c->pCurrentMap->unk_0a != 0) && ((data_02196f0c->state & 1) != 0))
    {
        int n = Force::Get(0)->Count() + Force::Get(2)->Count();

        if (n < data_02196f0c->pCurrentMap->unk_0a)
        {
            int uVar4 = func_02041928();

            for (; n < data_02196f0c->pCurrentMap->unk_0a; n++)
            {
                Force * force = Force::Get(4);
                struct Unit * pUnit = force->head;

                if (pUnit == NULL)
                {
                    break;
                }

                func_0203bd34(pUnit, 2, 1);
                func_020421c4(pUnit, uVar4);

                data_02196f0c->state |= 0x20000;
            }
        }
    }

    if (data_02196f0c->state & 0x10000)
    {
        data_ov000_021e3324->unk_02 = data_02196f10->unk_09;
        data_ov000_021e3324->unk_0c = data_02196f10->unk_0c * 60;
        data_ov000_021e3324->unk_06 = data_02196f10->unk_0a;
    }

    return;
}

EC void func_0202214c(ProcPtr proc)
{
    Force * force;
    struct Unit * unit;

    Event::StartEventByName("MapBegin\0\0\0", proc);

    if (!(data_02196f0c->state & 0x10000))
    {
        return;
    }

    force = Force::Get(data_02196f10->unk_06);
    unit = force->head;

    if (unit == NULL)
    {
        return;
    }

    gMapStateManager->camera->func_ov000_021a4e84(unit->xPos, unit->yPos, 1);

    return;
}

EC void func_020221bc(void)
{
    data_ov000_021e3528.unk_2f = 1;
    data_02196f20->unk_188 = data_02196f20->unk_184;
    return;
}

EC void func_020221e4(void)
{
    if (data_021974fc == NULL)
    {
        data_021974fc = new UnkStruct_021974fc;
    }

    func_0204a9e0(data_02196f20->unk_19b);
    func_0204abe4();
    func_0204bbb4(0);

    if (!(((data_02196f20->unk_19c >= 0) ? TRUE : FALSE) & 0xFF))
    {
        return;
    }

    func_0205038c(data_02196f20->unk_19c, -1);

    return;
}

EC void func_0202225c(void)
{
    struct Unit * pUnit;
    int unitId;

    func_0204b790();

    unitId =
        gMapStateManager->unk_028[gMapStateManager->unk_10->unk_08 | gMapStateManager->unk_10->unk_09 << 5];

    if (unitId == 0)
    {
        pUnit = NULL;
    }
    else
    {
        pUnit = gUnitList + unitId - 1;
    }

    func_0204e1a4(pUnit, 0, 1);
    func_0204eab8(gMapStateManager->unk_10->unk_08, gMapStateManager->unk_10->unk_09, 0);
    func_0204f6d0();

    func_0204ad38(data_02196f20->unk_19b, 0, 0);

    if (!(((data_02196f20->unk_19c >= 0) ? TRUE : FALSE) & 0xFF))
    {
        return;
    }

    func_0205038c(data_02196f20->unk_19c, -1);

    return;
}

EC void func_02022324(void)
{
    data_02196f1c->unk_09 = data_02196f0c->unk_10;

    if (!(data_02196f0c->state & 0x40))
    {
        return;
    }

    func_02022f28(7);

    return;
}

EC void func_02022364(ProcPtr proc)
{
    if (data_02196f0c->state & 0x40)
    {
        return;
    }

    if (!HashTable::Get1("SallyTalk\0\0"))
    {
        return;
    }

    func_02039eac("suppliance\0");
    Event::StartEventByName("SallyTalk\0\0", proc);

    return;
}

EC void func_020223b4(void)
{
    func_02039f00("suppliance\0", 1);
    return;
}

EC void func_020223cc(ProcPtr proc)
{
    data_021974fc->unk_00 = 0;
    data_021974fc->unk_08 = 0;

    if (!HashTable::Get1("Opening"))
    {
        return;
    }

    Event::StartEventByName("Opening", proc);

    return;
}

EC void func_02022414(void)
{
    gSoundManager->unk_a4->vfunc_6c(0x7f);
    gSoundManager->unk_a8->vfunc_6c(0x7f);
    return;
}

EC void func_02022458(void)
{
    if (!(data_02196f0c->state & 0x800))
    {
        return;
    }

    func_02022f28(10);

    return;
}

EC void func_02022480(void)
{
    data_021974fc->unk_00 = 0;
    data_021974fc->unk_08 = 0;

    func_0203fc88();

    return;
}

EC void func_020224a8(ProcPtr proc)
{
    if (!HashTable::Get1("Ending\0"))
    {
        return;
    }

    Event::StartEventByName("Ending\0", proc);

    return;
}

EC void func_020224d4(void)
{
    gSoundManager->unk_a4->vfunc_38(0x10);
    return;
}

EC void func_020224fc(void)
{
    data_02196f20->unk_19b = data_021974fc->unk_10;
    data_02196f20->unk_19c = 0xff;

    func_0204ac00();

    delete data_021974fc;
    data_021974fc = NULL;

    return;
}

EC void func_0202254c(ProcPtr proc)
{
    Event::StartEventByName("MapEnd\0", proc);
    return;
}

EC void func_02022564(void)
{
    delete data_ov000_021e3324;
    data_ov000_021e3324 = NULL;
    return;
}

EC void func_02022588(void)
{
    struct Unit * pUnit;
    int i;

    if ((data_02196f0c->state & 0x00010020) != 0)
    {
        return;
    }

    func_02041458();

    for (i = 0, pUnit = gUnitList; i < 0x8c; i++, pUnit++)
    {
        if (pUnit->force->id == 4)
        {
            continue;
        }

        if (pUnit->force->id == 5)
        {
            continue;
        }

        if (pUnit->force->id != 3)
        {
            continue;
        }

        if ((pUnit->state2 & 0x40000) != 0)
        {
            func_0203c19c(pUnit);
        }

        pUnit->state2 &= ~0x100;

        if ((pUnit->state2 & 0x80) != 0)
        {
            int j;
            struct Item * pUnitItem;

            pUnit->state2 &= ~0x80;
            pUnit->unk_30.unk_04 = GetMapDBIndex(data_02196f0c->pCurrentMap);

            for (j = 0, pUnitItem = pUnit->items; j < 5; j++, pUnitItem++)
            {
                if (((pUnitItem->id == 0) ? TRUE : FALSE) & 0xFF)
                {
                    continue;
                }

                pUnitItem->flags &= ~0x30;

                AddItemToConvoy(pUnitItem);
                pUnitItem->Clear();
            }
        }

        if ((pUnit->state2 & 0x80000) != 0)
        {
            func_0203bd34(pUnit, 4, 1);
        }
    }

    Force::Get(2)->MoveAllUnitsTo(0, TRUE);

    while (TRUE)
    {
        Force * force;
        struct Unit * it;
        struct Unit * pUnit;

        force = Force::Get(0);
        pUnit = force->head;

        if (pUnit == NULL)
        {
            break;
        }

        for (it = pUnit->unk_3c; it != NULL; it = it->unk_3c)
        {
            s32 a = it->unk_95;
            s32 b = pUnit->unk_95;

            if (a < b)
            {
                pUnit = it;
            }
        }

        func_0203bd34(pUnit, 2, 1);
    }

    if (data_02196f0c->state & 0x800)
    {
        return;
    }

    func_0202511c();

    return;
}

EC void func_0202272c(ProcPtr proc)
{
    Event::StartEventByName("ChapterNext", proc);

    if (!(data_02196f0c->state & 1))
    {
        if (!(data_02196f0c->state & 0x800))
        {
            data_02196f0c->state |= 1;
        }

        data_02196f1c->unk_09 = 0;
    }

    data_02196f0c->state &= ~0x100;
    data_02196f0c->state &= ~0x200;
    data_02196f0c->state &= ~0x800;
    data_02196f0c->state &= ~0x1000;
    data_02196f0c->state &= ~0x400;
    data_02196f0c->state &= ~0x4000;
    data_02196f0c->state &= ~0x20000;
    data_02196f0c->state &= ~0x100000;

    data_02196f20->unk_194 = func_0201ffc0();

    return;
}

EC void func_02022814(void)
{
    if (IsOverlayLoaded(10))
    {
        UnloadOverlay(10);
    }

    if (IsOverlayLoaded(11))
    {
        UnloadOverlay(11);
    }

    return;
}

EC void func_0202284c(ProcPtr proc)
{
    switch (data_02196f10->unk_04)
    {
        case 0:
            func_ov003_021e42c8(proc, 0);
            break;

        case 1:
            func_ov003_021e4310(proc, 0);
            break;

        case 2:
            func_ov003_021e4354(proc, 0);
            break;

        case 3:
            func_02022f28(35);
            break;
    }

    return;
}

EC void func_020228ac(ProcPtr proc)
{
    switch (data_02196f10->unk_04)
    {
        case 0:
            func_ov003_021e42c8(proc, 1);
            break;

        case 2:
            func_ov003_021e4354(proc, 1);
            break;
    }

    return;
}

// TODO: Figure out the inline issues
inline BOOL _func_02022988(void)
{
    return data_02196f10->unk_04 == 1 ? TRUE : FALSE;
}

EC void func_020228ec(ProcPtr unused)
{
    if (data_02196f10->unk_04 != 3)
    {
        data_02196f0c->state |= 0x20;
    }

    data_02196f0c->state |= 0x10000;
    data_02196f0c->state |= 0x4000;
    data_02196f0c->state |= 1;

    if (_func_02022988())
    {
        func_0202118c();
        return;
    }

    func_02021178(0);

    return;
}

EC /* inline */ BOOL func_02022988(void)
{
    return _func_02022988();
}

EC void func_020229a8(void)
{
    switch (data_02196f10->unk_04)
    {
        case 0:
            LoadOverlay(10);
            break;

        case 1:
        case 2:
            LoadOverlay(11);
            break;

        case 3:
            break;

        default:
            break;
    }

    return;
}

inline BOOL _func_02022b10(void)
{
    return data_02196f10->unk_07 == 2 ? TRUE : FALSE;
}

inline BOOL _func_02022b30(void)
{
    return data_02196f10->unk_04 == 3 ? TRUE : FALSE;
}

inline BOOL _func_02022b50(void)
{
    return data_02196f10->unk_07 == 0 ? TRUE : FALSE;
}

EC void func_020229f0(void)
{
    int random;

    if (_func_02022b10())
    {
        return;
    }

    if (_func_02022b30())
    {
        return;
    }

    if (_func_02022b50())
    {
        random = RollRN(1, gFE11Database->pDBFE11Footer->unk_14 - 1);
        data_02196f10->unk_11 = random;
        data_02196f18->unk_000->SetById(random);

        if (data_02196f10->unk_0b != 0 && func_02021410(data_02196f10->unk_06)->unk_756 == 0x14)
        {
            random = RollRN(1, gFE11Database->pDBFE11Footer->unk_14 - 2);

            if (random >= data_02196f10->unk_11)
            {
                random += 1;
            }

            data_02196f10->unk_12 = random;

            data_02196f18->unk_000->SetById(random);
        }
    }

    func_02025344();
    func_0202454c(0x18, 0, 0);

    return;
}

// TODO: Figure out inlines

EC /* inline */ BOOL func_02022b10(void)
{
    return _func_02022b10();
}

EC /* inline */ BOOL func_02022b30(void)
{
    return _func_02022b30();
}

EC /* inline */ BOOL func_02022b50(void)
{
    return _func_02022b50();
}

EC void func_02022b70(ProcPtr proc)
{
    if (_func_02022b50())
    {
        StartBlockingFadeOutToWhite((struct Proc *)proc, 16, 1);
    }
    else
    {
        StartBlockingFadeOutToBlack((struct Proc *)proc, 16, 1);
    }

    return;
}

EC void func_02022bb0(ProcPtr proc)
{
    u32 var;

    if (!_func_02022b30())
    {
        if (data_02196f10->unk_08 != 0)
        {
            return;
        }

        func_020146a0();
        func_02012bbc();
        func_02012680(proc);

        var = data_02196f10->unk_04;
        func_02021b14();
        data_02196f10->unk_04 = var;

        func_020228ec(proc);
        func_02022f28(30);

        gSoundManager->unk_a4->vfunc_3c(0x10, 0x48, 0);
    }

    func_0201ffd0();

    return;
}

EC void func_02022c54(ProcPtr proc)
{
    func_020240a0(data_02196f0c->unk_10 + 0x0d, proc);
    return;
}

EC void func_02022c78(ProcPtr proc)
{
    func_020240a0(data_02196f0c->unk_10 + 0x10, proc);
    data_02196f0c->state |= 4;
    return;
}

EC void func_02022cb0(ProcPtr proc)
{
    func_020240a0(11, proc);
    data_02196f0c->state |= 4;
    return;
}

EC void func_02022cdc(ProcPtr proc)
{
    if (!func_0201f760(11))
    {
        return;
    }

    func_0202437c(proc);

    return;
}

EC void func_02022d00(ProcPtr proc)
{
    struct Unit * pUnit;
    int i;

    if (data_02196f0c->state & 0x2000)
    {
        for (i = 0, pUnit = gUnitList; i < 0x8c; i++, pUnit++)
        {
            if (pUnit->force->id == 4)
            {
                continue;
            }

            if (pUnit->force->id == 5)
            {
                continue;
            }

            if (!(pUnit->state2 & 0x40000))
            {
                continue;
            }

            func_0203c19c(pUnit);
        }

        data_02196f0c->state &= ~0x2000;
        func_02022f28(13);

        return;
    }

    if (data_02196f0c->state & 0x10000)
    {
        data_02196f0c->state &= ~0x10000;
        func_02022f28(54);

        return;
    }

    if (!(data_02196f0c->state & 0x80))
    {
        StartMainMenu_ProcMain(proc);
        return;
    }

    data_02196f0c->state &= ~0x80;

    return;
}

EC void func_02022db8(void)
{
    func_020ad244(4);
    return;
}

EC void func_02022dc8(void)
{
    func_020ad244(20);
    return;
}

EC void func_02022dd8(void)
{
    if (!func_0201f6a0())
    {
        return;
    }

    func_02039e10("MBackup_LoadError\0\0");
    func_0201f8a0();

    return;
}

EC void func_02022dfc(void)
{
    func_02021790(data_02196f10);
    return;
}

EC void func_02022e14(void)
{
    func_02021430(data_02196f10, 0, 0);
    return;
}

EC BOOL func_02022e34(void)
{
    return data_02196f0c->unk_14 == 1 ? TRUE : FALSE;
}

EC void func_02022e54(void)
{
    data_02196f10->unk_09 = 1;
    data_02196f10->unk_0c = 300;
    data_02196f10->unk_0a = 10;
    data_02196f10->unk_0b = 1;
    data_02196f10->unk_10 = 0;
    data_02196f10->unk_11 = 0;
    data_02196f10->unk_12 = 0;
    data_02196f10->unk_17 = 0;
    data_02196f10->unk_08 = 0;

    return;
}

EC BOOL func_02022eb8(void)
{
    return data_020efcb4 == 2 ? TRUE : FALSE;
}

EC BOOL func_02022ed4(void)
{
    return data_02196f0c->unk_14 == 2 ? TRUE : FALSE;
}

EC BOOL func_02022ef4(void)
{
    return data_020efcb4 == 1 ? TRUE : FALSE;
}

EC void StartGame(void)
{
    Proc_Start(ProcScr_GameCtrl, PROC_TREE_9);
    return;
}

EC void func_02022f28(u32 label)
{
    Proc_Goto(Proc_Find(ProcScr_GameCtrl), label, 0);
    return;
}
