#include "global.h"

#include "proc.h"
#include "unknown_funcs.h"
#include "unknown_data.h"

#include "unknown_types.hpp"
#include "database.hpp"
#include "event.hpp"
#include "hardware.hpp"
#include "hashtable.hpp"
#include "heap.hpp"
#include "map.hpp"
#include "sound_manager.hpp"
#include "state_manager.hpp"

enum
{
    L_GAMECTRL_1 = 1,
    L_GAMECTRL_2 = 2,
    L_GAMECTRL_3 = 3,
    L_GAMECTRL_MAIN_MENU = 4,
    L_GAMECTRL_5 = 5,
    L_GAMECTRL_WORLD_MAP = 6,
    L_GAMECTRL_7 = 7,
    L_GAMECTRL_8 = 8,
    L_GAMECTRL_9 = 9,
    L_GAMECTRL_10 = 10,
    L_GAMECTRL_11 = 11,
    L_GAMECTRL_12 = 12,
    L_GAMECTRL_13 = 13,
    L_GAMECTRL_14 = 14,
    L_GAMECTRL_15 = 15,
    L_GAMECTRL_16 = 16,
    L_GAMECTRL_17 = 17,
    L_GAMECTRL_18 = 18,
    L_GAMECTRL_19 = 19,
    L_GAMECTRL_20 = 20,
    L_GAMECTRL_21 = 21,
    L_GAMECTRL_22 = 22,
    L_GAMECTRL_23 = 23,
    L_GAMECTRL_24 = 24,
    L_GAMECTRL_25 = 25,
    L_GAMECTRL_26 = 26,
    L_GAMECTRL_27 = 27,
    L_GAMECTRL_28 = 28,
    L_GAMECTRL_29 = 29,
    L_GAMECTRL_30 = 30,
    L_GAMECTRL_31 = 31,
    L_GAMECTRL_32 = 32,
    L_GAMECTRL_33 = 33,
    L_GAMECTRL_34 = 34,
    L_GAMECTRL_MULTIPLAYER_PRACTICE = 35,
    L_GAMECTRL_36 = 36,
    L_GAMECTRL_37 = 37,
    L_GAMECTRL_38 = 38,
    L_GAMECTRL_39 = 39,
    L_GAMECTRL_40 = 40,

    L_GAMECTRL_54 = 54,
};

EC void func_020210d0(struct MapData *, s32);

EC void func_ov004_02209e54(ProcPtr);

EC void func_020136bc(ProcPtr);
EC void func_0201fd44(ProcPtr);

EC BOOL _IsProcTutCardActive(void);

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
EC BOOL GameCtrl_IsWirelessPracticeMode(void);
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

    PROC_GOTO(L_GAMECTRL_1),

PROC_LABEL(L_GAMECTRL_1),
    PROC_START_CHILD_LOCKING(data_020ceba4),

    PROC_GOTO(L_GAMECTRL_3),

PROC_LABEL(L_GAMECTRL_2),
    PROC_START_CHILD_LOCKING(data_020ceb84),

    PROC_GOTO(L_GAMECTRL_3),

PROC_LABEL(L_GAMECTRL_3),
    PROC_WHILE_EXISTS(data_020cec14),
    PROC_CALL(func_02021b00),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_MAIN_MENU),
    PROC_REPEAT(func_02021f08),
    PROC_REPEAT(func_02021f2c),
    PROC_CALL(func_02021b14),
    PROC_CALL(func_0201fd44),
    PROC_START_CHILD_LOCKING(data_020cebc4),

    PROC_GOTO(L_GAMECTRL_2),

PROC_LABEL(L_GAMECTRL_5),
    PROC_CALL(func_02022cdc),

    PROC_GOTO(L_GAMECTRL_WORLD_MAP),

PROC_LABEL(L_GAMECTRL_WORLD_MAP),
    PROC_OVERLAY_LOAD(OVERLAY_ID_4),
    PROC_CALL(func_ov004_02209e54),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_4),

    // fallthrough

PROC_LABEL(L_GAMECTRL_7),
    PROC_REPEAT(func_02021f2c),
    PROC_CALL(func_02021dd4),
    PROC_CALL(func_02021f5c),
    PROC_CALL(func_0202214c),
    PROC_CALL(func_020221bc),
    PROC_CALL(func_020221e4),
    PROC_CALL(func_02022364),
    PROC_CALL(func_020223b4),
    PROC_OVERLAY_LOAD(OVERLAY_ID_5),
    PROC_CALL(func_ov005_022052d0),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_5),

    // fallthrough

PROC_LABEL(L_GAMECTRL_8),
    PROC_CALL(func_020223cc),
    PROC_CALL(func_02022414),
    PROC_CALL(func_02022458),

    // fallthrough

PROC_LABEL(L_GAMECTRL_9),
    PROC_CALL(func_ov000_021a9714),

    // fallthrough

PROC_LABEL(L_GAMECTRL_10),
    PROC_WHILE(_IsProcTutCardActive),
    PROC_CALL(func_02022480),
    PROC_CALL(func_020224a8),
    PROC_CALL(func_02022414),
    PROC_CALL(func_020224d4),
    PROC_FADE_TO_BLACK(16, 1, TRUE),
    PROC_CALL(func_020224fc),

    // fallthrough

PROC_LABEL(L_GAMECTRL_11),
    PROC_CALL(func_0202254c),
    PROC_CALL(func_02022564),
    PROC_CALL(func_02022588),
    PROC_CALL(func_0202272c),
    PROC_CALL(func_02021e6c),
    PROC_START_CHILD_LOCKING(data_020cebec),

    PROC_GOTO(L_GAMECTRL_WORLD_MAP),

PROC_LABEL(L_GAMECTRL_12),
    PROC_FADE_TO_BLACK(64, 1, TRUE),
    PROC_CALL(func_020224fc),
    PROC_CALL(func_0202254c),
    PROC_CALL(func_02022564),
    PROC_CALL(func_02021e6c),
    PROC_OVERLAY_LOAD(OVERLAY_ID_6),
    PROC_CALL(func_ov006_0221776c),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_6),
    PROC_CALL(func_02021b00),

    PROC_GOTO(L_GAMECTRL_2),

PROC_LABEL(L_GAMECTRL_13),
    PROC_OVERLAY_LOAD(OVERLAY_ID_9),
    PROC_CALL(func_02022db8),
    PROC_CALL(func_ov009_02206020),
    PROC_CALL(func_ov009_022065a0),
    PROC_CALL(func_ov009_02204e10),
    PROC_CALL(func_02022dc8),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_9),
    PROC_CALL(func_02021b00),

    PROC_GOTO(L_GAMECTRL_2),

PROC_LABEL(L_GAMECTRL_14),
    PROC_CALL(func_02022c54),
    PROC_CALL(func_02022cdc),
    PROC_CALL(func_02022324),

    PROC_GOTO(L_GAMECTRL_WORLD_MAP),

PROC_LABEL(L_GAMECTRL_15),
    PROC_REPEAT(func_02021f2c),
    PROC_CALL(func_02022c78),
    PROC_CALL(func_02022cdc),
    PROC_CALL(func_020221e4),
    PROC_CALL(func_0202225c),
    PROC_FADE_FROM_BLACK(8, 1, TRUE),

    PROC_GOTO(L_GAMECTRL_9),

PROC_LABEL(L_GAMECTRL_16),
    PROC_REPEAT(func_02021f2c),
    PROC_CALL(func_02022cb0),
    PROC_CALL(func_02022cdc),
    PROC_CALL(func_020221e4),
    PROC_CALL(func_0202225c),
    PROC_FADE_FROM_BLACK(8, 1, TRUE),

    PROC_GOTO(L_GAMECTRL_9),

PROC_LABEL(L_GAMECTRL_39),
    PROC_WHILE(_IsProcTutCardActive),
    PROC_FADE_TO_BLACK(32, 1, TRUE),
    PROC_CALL(func_020224fc),
    PROC_CALL(func_0202254c),
    PROC_CALL(func_02022564),
    PROC_CALL(func_02021e6c),
    PROC_CALL(func_02021b00),

    PROC_GOTO(L_GAMECTRL_2),

PROC_LABEL(L_GAMECTRL_17),
    PROC_OVERLAY_LOAD(OVERLAY_ID_6),
    PROC_CALL(func_ov006_02221aec),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_6),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_18),
    PROC_OVERLAY_LOAD(OVERLAY_ID_6),
    PROC_CALL(func_ov006_022226cc),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_6),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_21),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021f049c),
    PROC_25(2, 0),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_26),
    PROC_OVERLAY_LOAD(OVERLAY_ID_B),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e4204),
    PROC_GOTO_IF_NO(func_02022ef4, L_GAMECTRL_40),
    PROC_CALL(func_ov003_021f24e4),

    PROC_GOTO(L_GAMECTRL_40),

PROC_LABEL(L_GAMECTRL_19),
    PROC_OVERLAY_LOAD(OVERLAY_ID_B),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021fc0d4),
    PROC_25(2, 0),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_B),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_20),
    PROC_25(1, 0),
    PROC_OVERLAY_LOAD(OVERLAY_ID_B),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e3610),
    PROC_25(2, 0),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_B),
    PROC_25(0, 0),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_27),
    PROC_25(3, 0),
    PROC_OVERLAY_LOAD(OVERLAY_ID_7),
    PROC_CALL(func_ov007_02218284),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_7),
    PROC_25(2, 0),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_28),
    PROC_OVERLAY_LOAD(OVERLAY_ID_7),
    PROC_CALL(func_ov007_0221ad60),
    PROC_OVERLAY_UNLOAD(OVERLAY_ID_7),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_23),
    PROC_CALL(func_020229a8),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e4204),
    PROC_GOTO_IF_NO(func_02022ef4, L_GAMECTRL_40),
    PROC_CALL(func_020228ac),
    PROC_GOTO_IF_NO(func_02022ef4, L_GAMECTRL_40),
    PROC_CALL(func_ov003_021f9470),

    PROC_GOTO(L_GAMECTRL_40),

PROC_LABEL(L_GAMECTRL_24),
    PROC_OVERLAY_LOAD(OVERLAY_ID_B),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e4244),
    PROC_GOTO_IF_NO(func_02022ef4, L_GAMECTRL_40),
    PROC_CALL(func_ov003_021f4a84),

    PROC_GOTO(L_GAMECTRL_40),

PROC_LABEL(L_GAMECTRL_25),
    PROC_OVERLAY_LOAD(OVERLAY_ID_B),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021e4244),
    PROC_GOTO_IF_NO(func_02022ef4, L_GAMECTRL_40),
    PROC_CALL(func_ov003_021f6ce8),

    PROC_GOTO(L_GAMECTRL_40),

PROC_LABEL(L_GAMECTRL_22),
    PROC_25(3, 0),
    PROC_CALL(func_ov003_021f31f0),
    PROC_25(2, 0),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_40),
    PROC_CALL(func_ov003_021e4284),
    PROC_25(2, 0),
    PROC_CALL(func_02022814),

    PROC_GOTO(L_GAMECTRL_MAIN_MENU),

PROC_LABEL(L_GAMECTRL_29),
    PROC_CALL(func_020229a8),
    PROC_25(3, 0),
    PROC_CALL(func_020228ec),
    PROC_GOTO_IF_YES(GameCtrl_IsWirelessPracticeMode, L_GAMECTRL_30),
    PROC_CALL(func_ov003_021e4204),
    PROC_GOTO_IF_NO(func_02022ef4, L_GAMECTRL_40),

    // fallthrough

PROC_LABEL(L_GAMECTRL_30),
    PROC_CALL(func_ov003_021fb690),
    PROC_GOTO_IF_NO(func_02022e34, L_GAMECTRL_40),
    PROC_GOTO_IF_YES(GameCtrl_IsWirelessPracticeMode, L_GAMECTRL_34),

    PROC_GOTO(L_GAMECTRL_32),

PROC_LABEL(L_GAMECTRL_31),
    PROC_CALL(func_ov003_021fb704),
    PROC_GOTO_IF_NO(func_02022e34, L_GAMECTRL_40),
    PROC_GOTO_IF_YES(GameCtrl_IsWirelessPracticeMode, L_GAMECTRL_34),

    PROC_GOTO(L_GAMECTRL_32),

PROC_LABEL(L_GAMECTRL_32),
    PROC_CALL(func_02022e54),
    PROC_CALL(func_0202284c),
    PROC_GOTO_IF_YES(func_02022eb8, L_GAMECTRL_40),
    PROC_GOTO_IF_NO(func_02022ef4, L_GAMECTRL_31),
    PROC_GOTO_IF_YES(func_02022988, L_GAMECTRL_33),
    PROC_CALL(func_ov003_021ebb8c),
    PROC_GOTO_IF_YES(func_02022ed4, L_GAMECTRL_40),

    // fallthrough

PROC_LABEL(L_GAMECTRL_33),
    PROC_CALL(func_ov003_021e439c),
    PROC_GOTO_IF_YES(func_02022eb8, L_GAMECTRL_40),

    PROC_GOTO(L_GAMECTRL_MULTIPLAYER_PRACTICE),

PROC_LABEL(L_GAMECTRL_34),
    PROC_CALL(func_02022e54),
    PROC_CALL(func_ov003_021eb9b0),
    PROC_GOTO_IF_NO(func_02022e34, L_GAMECTRL_31),
    PROC_CALL(func_02022e14),

    PROC_GOTO(L_GAMECTRL_MULTIPLAYER_PRACTICE),

PROC_LABEL(L_GAMECTRL_MULTIPLAYER_PRACTICE),
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
    PROC_GOTO_IF_YES(func_02022b10, L_GAMECTRL_40),
    PROC_GOTO_IF_NO(func_02022b50, L_GAMECTRL_37),

    // fallthrough

PROC_LABEL(L_GAMECTRL_36),
    PROC_CALL(func_ov003_021ed664),

    PROC_GOTO(L_GAMECTRL_38),

PROC_LABEL(L_GAMECTRL_37),
    PROC_CALL(func_ov003_021edf2c),

    PROC_GOTO(L_GAMECTRL_38),

PROC_LABEL(L_GAMECTRL_38),
    PROC_CALL(func_02022bb0),

    PROC_GOTO(L_GAMECTRL_40),

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

extern vu32 gElapsedFrames;

extern struct UnkStruct_02196f18 * data_02196f18;

extern struct UnkStruct_020e3ca0 * data_020e3ca0;

extern struct UnkStruct_02196f1c * data_02196f1c;

extern struct WirelessSettings * gWirelessSettings;

extern struct UnkStruct_02196f0c * data_02196f0c;

extern struct UnkStruct_02196f20 * data_02196f20;

extern struct UnkStruct_02196f24 * data_02196f24;

// Forward declarations
EC void InitOnlineShopItemFlags(void);
EC void InitOnlineShopItemAmounts(void);
EC void GameCtrl_GotoLabel(u32 label);

EC void func_020217b4(void)
{
    int random;

    LoadOverlay(OVERLAY_ID_0);
    LoadOverlay(OVERLAY_ID_2);

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

    if (gWirelessSettings == NULL)
    {
        gWirelessSettings = new WirelessSettings();
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
    InitFaceInfo();
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

    if (data_02196f0c->state & GAME_STATE_UNK_25)
    {
        return;
    }

    lr = gElapsedFrames;
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

    if ((data_02196f0c->pCurrentMap->unk_0a != 0) && (data_02196f0c->state & GAME_STATE_UNK_0))
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

                pUnit->MoveToForce(2, TRUE);
                func_020421c4(pUnit, uVar4);

                data_02196f0c->state |= GAME_STATE_UNK_17;
            }
        }
    }

    if (data_02196f0c->state & GAME_STATE_UNK_16)
    {
        data_ov000_021e3324->fogActive = gWirelessSettings->fogActive;
        data_ov000_021e3324->timeLimit = gWirelessSettings->timeLimit * 60;
        data_ov000_021e3324->turnLimit = gWirelessSettings->turnLimit;
    }

    return;
}

EC void func_0202214c(ProcPtr proc)
{
    Unit * unit;

    Event::StartEventByName("MapBegin\0\0\0", proc);

    if (!(data_02196f0c->state & GAME_STATE_UNK_16))
    {
        return;
    }

    unit = Force::Get(gWirelessSettings->unk_06)->head;

    if (unit != NULL)
    {
        gMapStateManager->camera->ScrollInstant(unit->xPos, unit->yPos, 1);
    }

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

    StartProcTutCardMaybe(data_02196f20->unk_19c, -1);

    return;
}

EC void func_0202225c(void)
{
    struct Unit * pUnit;
    int unitId;

    func_0204b790();

    unitId =
        gMapStateManager->unk_028[gMapStateManager->cursor->xTile | gMapStateManager->cursor->yTile << 5];

    if (unitId == 0)
    {
        pUnit = NULL;
    }
    else
    {
        pUnit = gUnitList + unitId - 1;
    }

    func_0204e1a4(pUnit, 0, 1);
    func_0204eab8(gMapStateManager->cursor->xTile, gMapStateManager->cursor->yTile, 0);
    func_0204f6d0();

    func_0204ad38(data_02196f20->unk_19b, 0, 0);

    if (!(((data_02196f20->unk_19c >= 0) ? TRUE : FALSE) & 0xFF))
    {
        return;
    }

    StartProcTutCardMaybe(data_02196f20->unk_19c, -1);

    return;
}

EC void func_02022324(void)
{
    data_02196f1c->unk_09 = data_02196f0c->unk_10;

    if (!(data_02196f0c->state & GAME_STATE_UNK_6))
    {
        return;
    }

    GameCtrl_GotoLabel(L_GAMECTRL_7);

    return;
}

EC void func_02022364(ProcPtr proc)
{
    if (data_02196f0c->state & GAME_STATE_UNK_6)
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
    if (!(data_02196f0c->state & GAME_STATE_UNK_11))
    {
        return;
    }

    GameCtrl_GotoLabel(L_GAMECTRL_10);

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

    if (data_02196f0c->state & (GAME_STATE_UNK_5 | GAME_STATE_UNK_16))
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

        if (pUnit->state2 & US_UNK_18)
        {
            pUnit->_0203c19c();
        }

        pUnit->state2 &= ~US_UNK_8;

        if (pUnit->state2 & US_ITEMS_TO_CONVOY)
        {
            s32 j;
            struct Item * pUnitItem;

            pUnit->state2 &= ~US_ITEMS_TO_CONVOY;
            pUnit->unk_30.unk_04 = GetMapDBIndex(data_02196f0c->pCurrentMap);

            for (j = 0, pUnitItem = pUnit->items; j < UNIT_ITEM_COUNT; j++, pUnitItem++)
            {
                if (((pUnitItem->id == 0) ? TRUE : FALSE) & 0xFF)
                {
                    continue;
                }

                pUnitItem->flags &= ~(ITEM_FLAG_EQUIPPED | ITEM_FLAG_DROPPABLE);

                AddItemToConvoy(pUnitItem);
                pUnitItem->Clear();
            }
        }

        if (pUnit->state2 & US_UNK_19)
        {
            pUnit->MoveToForce(4, TRUE);
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

        pUnit->MoveToForce(2, TRUE);
    }

    if (data_02196f0c->state & GAME_STATE_UNK_11)
    {
        return;
    }

    func_0202511c();

    return;
}

EC void func_0202272c(ProcPtr proc)
{
    Event::StartEventByName("ChapterNext", proc);

    if (!(data_02196f0c->state & GAME_STATE_UNK_0))
    {
        if (!(data_02196f0c->state & GAME_STATE_UNK_11))
        {
            data_02196f0c->state |= GAME_STATE_UNK_0;
        }

        data_02196f1c->unk_09 = 0;
    }

    data_02196f0c->state &= ~GAME_STATE_UNK_8;
    data_02196f0c->state &= ~GAME_STATE_UNK_9;
    data_02196f0c->state &= ~GAME_STATE_UNK_11;
    data_02196f0c->state &= ~GAME_STATE_UNK_12;
    data_02196f0c->state &= ~GAME_STATE_UNK_10;
    data_02196f0c->state &= ~GAME_STATE_SUPPLY_OFF;
    data_02196f0c->state &= ~GAME_STATE_UNK_17;
    data_02196f0c->state &= ~GAME_STATE_UNK_20;

    data_02196f20->unk_194 = Random_GetState();

    return;
}

EC void func_02022814(void)
{
    if (IsOverlayLoaded(OVERLAY_ID_A))
    {
        UnloadOverlay(OVERLAY_ID_A);
    }

    if (IsOverlayLoaded(OVERLAY_ID_B))
    {
        UnloadOverlay(OVERLAY_ID_B);
    }

    return;
}

EC void func_0202284c(ProcPtr proc)
{
    switch (gWirelessSettings->mode)
    {
        case WIRELESS_MODE_LOCAL:
            func_ov003_021e42c8(proc, 0);
            break;

        case WIRELESS_MODE_WFC_PLAY_ANYONE:
            func_ov003_021e4310(proc, 0);
            break;

        case WIRELESS_MODE_WFC_PLAY_FRIEND:
            func_ov003_021e4354(proc, 0);
            break;

        case WIRELESS_MODE_PRACTICE:
            GameCtrl_GotoLabel(L_GAMECTRL_MULTIPLAYER_PRACTICE);
            break;
    }

    return;
}

EC void func_020228ac(ProcPtr proc)
{
    switch (gWirelessSettings->mode)
    {
        case WIRELESS_MODE_LOCAL:
            func_ov003_021e42c8(proc, 1);
            break;

        case WIRELESS_MODE_WFC_PLAY_FRIEND:
            func_ov003_021e4354(proc, 1);
            break;
    }

    return;
}

EC void func_020228ec(ProcPtr unused)
{
    if (gWirelessSettings->mode != WIRELESS_MODE_PRACTICE)
    {
        data_02196f0c->state |= GAME_STATE_UNK_5;
    }

    data_02196f0c->state |= GAME_STATE_UNK_16;
    data_02196f0c->state |= GAME_STATE_SUPPLY_OFF;
    data_02196f0c->state |= GAME_STATE_UNK_0;

    if (gWirelessSettings->IsWifiPlayAnyoneMode())
    {
        func_0202118c();
        return;
    }

    func_02021178(0);

    return;
}

EC BOOL func_02022988(void)
{
    return gWirelessSettings->IsWifiPlayAnyoneMode();
}

EC void func_020229a8(void)
{
    switch (gWirelessSettings->mode)
    {
        case WIRELESS_MODE_LOCAL:
            LoadOverlay(OVERLAY_ID_A);
            break;

        case WIRELESS_MODE_WFC_PLAY_ANYONE:
        case WIRELESS_MODE_WFC_PLAY_FRIEND:
            LoadOverlay(OVERLAY_ID_B);
            break;

        case WIRELESS_MODE_PRACTICE:
            break;

        default:
            break;
    }

    return;
}

EC void func_020229f0(void)
{
    int random;

    if (gWirelessSettings->_02022b10())
    {
        return;
    }

    if (gWirelessSettings->IsPracticeMode())
    {
        return;
    }

    if (gWirelessSettings->_02022b50())
    {
        random = RollRN(1, gFE11Database->pDBFE11Footer->unk_14 - 1);
        gWirelessSettings->unk_11 = random;
        data_02196f18->unk_000->SetById(random);

        if (gWirelessSettings->unk_0b != 0 && func_02021410(gWirelessSettings->unk_06)->unk_756 == 0x14)
        {
            random = RollRN(1, gFE11Database->pDBFE11Footer->unk_14 - 2);

            if (random >= gWirelessSettings->unk_11)
            {
                random += 1;
            }

            gWirelessSettings->unk_12 = random;

            data_02196f18->unk_000->SetById(random);
        }
    }

    func_02025344();
    func_0202454c(0x18, 0, 0);

    return;
}

EC BOOL func_02022b10(void)
{
    return gWirelessSettings->_02022b10();
}

EC BOOL GameCtrl_IsWirelessPracticeMode(void)
{
    return gWirelessSettings->IsPracticeMode();
}

EC BOOL func_02022b50(void)
{
    return gWirelessSettings->_02022b50();
}

EC void func_02022b70(ProcPtr proc)
{
    if (gWirelessSettings->_02022b50())
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
    u32 mode;

    if (!gWirelessSettings->IsPracticeMode())
    {
        if (gWirelessSettings->unk_08 != 0)
        {
            return;
        }

        func_020146a0();
        func_02012bbc();
        func_02012680(proc);

        mode = gWirelessSettings->mode;
        func_02021b14();
        gWirelessSettings->mode = mode;

        func_020228ec(proc);
        GameCtrl_GotoLabel(L_GAMECTRL_30);

        gSoundManager->unk_a4->vfunc_3c(0x10, 0x48, 0);
    }

    Random_Next();

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
    data_02196f0c->state |= GAME_STATE_UNK_2;
    return;
}

EC void func_02022cb0(ProcPtr proc)
{
    func_020240a0(11, proc);
    data_02196f0c->state |= GAME_STATE_UNK_2;
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

    if (data_02196f0c->state & GAME_STATE_UNK_13)
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

            if (!(pUnit->state2 & US_UNK_18))
            {
                continue;
            }

            pUnit->_0203c19c();
        }

        data_02196f0c->state &= ~GAME_STATE_UNK_13;
        GameCtrl_GotoLabel(L_GAMECTRL_13);

        return;
    }

    if (data_02196f0c->state & GAME_STATE_UNK_16)
    {
        data_02196f0c->state &= ~GAME_STATE_UNK_16;
        GameCtrl_GotoLabel(L_GAMECTRL_54);

        return;
    }

    if (!(data_02196f0c->state & GAME_STATE_UNK_7))
    {
        StartMainMenu_ProcMain(proc);
        return;
    }

    data_02196f0c->state &= ~GAME_STATE_UNK_7;

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

    GetText("MBackup_LoadError\0\0");
    func_0201f8a0();

    return;
}

EC void func_02022dfc(void)
{
    func_02021790(gWirelessSettings);
    return;
}

EC void func_02022e14(void)
{
    func_02021430(gWirelessSettings, 0, 0);
    return;
}

EC BOOL func_02022e34(void)
{
    return data_02196f0c->unk_14 == 1 ? TRUE : FALSE;
}

EC void func_02022e54(void)
{
    gWirelessSettings->fogActive = 1;
    gWirelessSettings->timeLimit = 300;
    gWirelessSettings->turnLimit = 10;
    gWirelessSettings->unk_0b = 1;
    gWirelessSettings->cardsAllowed = 0;
    gWirelessSettings->unk_11 = 0;
    gWirelessSettings->unk_12 = 0;
    gWirelessSettings->unk_17 = 0;
    gWirelessSettings->unk_08 = 0;

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

EC void GameCtrl_GotoLabel(u32 label)
{
    Proc_Goto(Proc_Find(ProcScr_GameCtrl), label, 0);
    return;
}
