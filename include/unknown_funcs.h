#ifndef UNKNOWN_FUNCS_H
#define UNKNOWN_FUNCS_H

#include "global.h"
#include "types.h"
#include "unknown_types.h"

#include "proc.h"
#include "unit.h"

EXTERN_C

EC void func_01ff8000(void * unk1, u8 a, u8 b, s32 c, u8 d, s32 e);
EC void func_01ff8d88(void *, struct Unit *, s32, s32, s32, s32);
EC void func_01ff8db8(void *, struct Unit *, s32, s32, s32, s32);
EC void func_01ff9300(void *, s32, s32, s32, s32);
EC void func_01ff9758(void *, void *);
EC void func_01ff976c(void *, void *);
EC void * func_01ffb934(void *, s32);
EC void func_01ffbb90(void *, void *);

EC void * func_02000c70(void);
EC void func_02000c7c(void *);
EC void func_02000d14(struct UnkStruct_Func_2000C7C * buf, s32 a);

EC int func_020016e8(struct UnkStruct_Func_2000D2C * unk1, struct Unit * unit, int a, int b);
EC int func_02001770(struct UnkStruct_Func_2000D2C * buf, int a, int b);
EC int func_02001820(struct UnkStruct_Func_2000D2C * buf, int a, int b, int c);
EC int func_02001bac(struct UnkStruct_Func_2000D2C * buf, int a);

EC void func_02002058(struct UnkStruct_020e3ca0 *);
EC BOOL func_020020e0(struct UnkStruct_020e3ca0 *);

EC void func_02003f88(void);

EC void func_020076a8(void);

EC void func_0200c888(void);

EC void func_0200ef04(void);
EC void func_0200f028(void);
EC void func_0200f04c(void);

EC void LoadOverlay(u32 overlayId);
EC void UnloadOverlay(u32 overlayId);
EC void func_0200f28c(u32 arg_0);
EC BOOL IsOverlayLoaded(u32 overlayId);

EC void * _Znwm(s32);
EC void _ZdlPv(void *);
EC void _ZdaPv(void *);
EC int func_020114dc(void *, void *);
EC void func_020115a4(void *);
EC BOOL func_0201160c(char *);

EC s32 func_02012190(void);
EC BOOL func_02012298(void);
EC s32 func_02012478(void);
EC BOOL func_02012584(void);
EC void func_02012680(void *);
EC void func_02012b64(void *, s32);
EC void func_02012bbc(void);
EC void func_020146a0(void);
EC BOOL func_02014b20(ProcPtr, s32);
EC void func_02015f64(void);
EC BOOL func_02016250(s32);
EC void func_02018f54(struct Proc *, void *);

EC s32 func_0201bce4(void);
EC s32 func_0201bcf4(void);
EC BOOL func_0201bd6c(void);

EC void func_0201d728(struct Proc * proc, u16 data, u32 flag);
EC void func_0201d778(struct Proc * proc, u16 data, u32 flag);
EC void func_0201d7c8(struct Proc * proc, u16 data, u32 flag);
EC void func_0201d814(struct Proc * proc, u16 data, u32 flag);
EC void func_0201d860(struct Proc * proc, u16 data, u32 flag);
EC void func_0201d8b0(struct Proc * proc, u16 data, u32 flag);
EC void func_0201d900(struct Proc * proc, u16 data, u32 flag);
EC void func_0201d950(struct Proc * proc, u16 data, u32 flag);
EC void func_0201d9a0(struct Proc * proc, u16 data, u32 flag);
EC void func_0201d9f4(struct Proc * proc, u16 data, u32 flag);
EC void func_0201da48(struct Proc * proc, u16 data, u32 flag);
EC void func_0201da98(struct Proc * proc, u16 data, u32 flag);
EC BOOL func_0201dae8(void);
EC void func_0201db38(void *, s32, s32, s32, s32);
EC BOOL func_0201dc30(s32);

EC BOOL func_0201f690(void);
EC BOOL func_0201f6a0(void);
EC BOOL func_0201f760(s32);
EC void func_0201f8a0(void);
EC s32 func_0201ffc0(void);
EC u32 func_0201ffd0(void);

EC s32 RollRN(s32, s32);

EC void func_020210d0(struct UnkStruct_02196f0c_00 *, s32);
EC void func_02021014(void);
EC void func_02021178(s32);
EC void func_0202118c(void);
EC char * GetBattleMapNameMaybe(void);
EC struct UnkStruct_Func_02021410_Ret * func_02021410(u32);
EC void func_02021430(struct UnkStruct_02196f10 *, s32, s32);
EC void func_02021790(struct UnkStruct_02196f10 *);

EC void StartGame(void);

EC void func_020240a0(s32, void *);
EC void func_0202437c(void *);
EC void func_0202454c(s32, s32, s32);
EC void func_02024c74(void);
EC void func_02024c80(void);
EC void func_02024d28(void);
EC void func_02024d8c(void);
EC void func_02024e70(void);
EC void func_02024f34(void);
EC s32 func_02025060(void);
EC void func_0202511c(void);
EC void func_02025344(void);
EC void func_02028c68(void);

EC s32 func_020295ec(u16 *, char *, u32, u32, u32, u32, u32, u32, u32, u32);
EC void func_02029850(u16 *, s32, u32, u32, u32, u32, u32, u32, u32);

EC void func_020302e0(void *);
EC void func_020303bc(void *, char *, u32 *, ProcPtr, s32, s32);

EC void func_020355e4(void);
EC s32 func_020357e8(void);
//EC void * func_02035b98(void *);
EC char * GetEventStr(void *, u16);
EC void func_02035c7c(void *, s32);
EC void func_02035ccc(void *);
EC void func_02035dc4(void *, void *);
EC void func_02035e5c(void *, void *);
EC void func_02035f20(void *);

EC void func_020377c8(void);
EC BOOL func_020377e8(char *);
EC void * func_02037800(char *);
EC void func_020379c0(void);
EC struct MapData * func_020379e0(char *, u32);
EC void func_02037a04(struct Unknown_02197254 *);
EC struct PersonData * GetPersonByPidStr(char *);
EC struct JobData * GetJobByJidStr(char *);
EC s32 func_02037fd8(struct JobData *);

EC s32 func_02038108(struct UnkStruct_02196f0c_00 *);
EC u32 func_02038248(s8 *);
EC s32 func_0203826c(void *, u8);
EC s32 func_02038348(struct ItemData *);
EC s32 GetItemMaxRange(struct ItemData *, struct Unit *);

EC s32 func_02039088(struct Unit * unit, int b, int c, int d, int e, int f, int g);
EC char * func_02039e10(char *);
EC BOOL func_02039e7c(char *);
EC void func_02039eac(char *);
EC void func_02039f00(char *, s32);
EC void func_02039f40(char *, s32);

EC void func_0203a728(struct Unit *, struct PersonData *, struct JobData *, s32);
EC void func_0203a94c(struct Unit *);

EC void func_0203bd34(struct Unit *, s32, s32);
EC void func_0203c19c(struct Unit *);
EC s32 GetUnitMaxHp(struct Unit * unit);
EC s32 GetUnitMag(struct Unit * unit, struct ItemData * item, BOOL unused);
EC s32 func_0203c480(struct Unit * unit, struct ItemData * item, BOOL unused);
EC s32 func_0203c610(struct Unit * unit, struct ItemData * item, BOOL unused);
EC s32 func_0203c660(struct Unit * unit, struct ItemData * item, BOOL unused);
EC s32 func_0203c6c0(struct Unit * unit, u32 arg_1, struct ItemData * item, s32 arg_3);
EC s32 func_0203c77c(struct Unit * unit);
EC s32 func_0203c790(struct Unit * unit);
EC s32 func_0203c7ac(struct Unit * unit, u32 arg_1);
EC s32 func_0203c7e4(struct Unit * unit, u32 arg_1);
EC s32 CheckUnitAttribute(struct Unit * unit, int attribute);
EC BOOL func_0203c834(struct Unit * unit, struct ItemData * item, s32 arg_2);
EC s32 GetUnitEquippedWeaponSlot(struct Unit * unit);
EC struct ItemData * GetItemData(struct Item *);
EC s32 func_0203dbd4(struct Unit *, s32, s32);
EC void func_0203dd48(struct Unit *);
EC void func_0203de10(struct Unit *);
EC void func_0203e02c(struct Item *);
EC void func_0203e008(struct Item *, u8);
EC void func_0203e040(struct Item *, struct Item *);
EC void func_0203fafc(void);
EC struct Unit * func_0203fcb8(s32);
EC void func_0203fb68(void);
EC void func_0203fc88(void);
EC struct Unit * func_0203fff4(s32, s32);

s32 func_02040c74(struct Unit **);
void func_02040cb0(struct Unit **, s32, s32);
void func_02040f5c(struct Item *);
struct Unit ** func_02040c98(s32);
EC void func_02040eec(void);
EC void func_02040f28(void);
EC void func_020411e8(void);
EC void func_02041234(void);
EC void func_02041458(void);
EC s32 func_02041928(void);
EC void func_020421c4(struct Unit *, s32);
EC void func_020423fc(void);
EC void func_02042420(const char *);
EC void func_02042460(char *);
EC void func_0204246c(char *);
EC void func_020424ac(void);
EC BOOL func_020424b8(char *);

EC void RegisterEventFunctions(void);
EC BOOL StartEventByName(char *, void *);
EC void func_020476a0(void);
EC BOOL func_020479b0(void);
EC BOOL _ZN11EventCaller13func_02048610EPcS0_(char *, char *);
BOOL TryStartVisitEvent(ProcPtr parent, u32 arg_1, u32 arg_2, u32 arg_3);

EC void func_020484b0(void);
EC void func_020485d0(void);
EC void func_02049024(void *, ProcPtr);
EC s32 func_02049370(void *, void *);
EC s32 _ZN11FlagManager12FindIdByNameEPc(struct UnkStruct_02196f0c_04 *, char *);
EC BOOL _ZN11FlagManager7GetByIdEm(struct UnkStruct_02196f0c_04 *, u32);
EC BOOL _ZN11FlagManager9GetByNameEPc(struct UnkStruct_02196f0c_04 *, char *);
EC void _ZN11FlagManager7SetByIdEm(struct UnkStruct_02196f0c_04 *, u32);
EC void _ZN11FlagManager9SetByNameEPc(struct UnkStruct_02196f0c_04 *, char *);
EC void _ZN11FlagManager12RegisterNameEPcl(struct UnkStruct_02196f0c_04 *, char *, s32);
EC void _ZN11FlagManager9RemoveAllEv(struct UnkStruct_02196f0c_04 *);
EC void _ZN12ValueManager9SetByNameEPcl(struct UnkStruct_02196f0c_08 *, char *, s32);
EC BOOL func_0204a66c(void);
EC void func_0204a9e0(s32);
EC void func_0204abe4(void);
EC BOOL func_0204b1f8(u32);
EC void func_0204ac00(void);
EC void func_0204ac18(ProcPtr);
EC void func_0204aca8(ProcPtr);
EC BOOL func_0204ad38(s32, s32, s32);
EC void func_0204ae60(s32, s32);
EC void func_0204ae9c(u32, BOOL);
EC void func_0204b194(s32, s32);
EC void func_0204b1e0(ProcPtr);
EC BOOL func_0204b260(u32);
EC void func_0204b39c(ProcPtr);
EC void func_0204b3b8(ProcPtr);
EC void func_0204b3d4(ProcPtr);
EC void func_0204b40c(ProcPtr);
EC void func_0204b790(void);
EC void func_0204bbb4(s32);
EC void func_0204e1a4(struct Unit *, s32, s32);
EC void func_0204eab8(s32, s32, s32);
EC void func_0204eb24(void);
EC void func_0204f6d0(void);

EC void func_0205038c(s32, s32);
EC BOOL func_02050474(void);
EC void func_02054870(struct Unit *, ProcPtr);
EC void func_02055224(struct Unit *, ProcPtr);
EC void func_02055ab0(struct Unit *, ProcPtr);
EC void func_0205633c(void);
EC BOOL func_020563fc(void);
EC void func_0205e138(struct Unit *, ProcPtr);

EC void func_02062a54(u32);
EC void func_02067510(void);
EC void func_0206ecbc(void);

EC void func_020a3080(void *, void *, void *, void *, s32, s32);
EC BOOL func_020a3350(void *);
EC void func_020a341c(void *);
EC void func_020a36ac(void (*)(void *, void *));
EC void func_020a374c(void *, void (*)(void *));

EC void func_020a5734(s32, void *, s32);
EC void func_020a5780(void *, void *, s32);
EC void func_020a5824(void * buf, int a, int b);
EC void func_020a58b8(void *, void *, s32);

EC void func_020a8f40(char *);

EC void * __cxa_vec_new(s32, s32, s32, s32, s32);

EC void func_020ad244(int a);

EC int func_020b6e2c(char *, char *);

// Overlay 000:

EC void func_ov000_021a340c(void);
EC void func_ov000_021a3498(struct Unit *, BOOL, u32, u32);
EC void func_ov000_021a354c(struct Unit *, s32, s32);
EC void func_ov000_021a35a0(void);
EC void func_ov000_021a378c(void);
EC BOOL func_ov000_021a37b4(void);
EC void func_ov000_021a38b4(void);
EC void func_ov000_021a3c20(u8 *, s32, struct Unit *);
EC void func_ov000_021a3c84(u8 *, s32, s32, s16, s16, s32, s32, u8 *);
EC BOOL func_ov000_021a3da0(struct Unit *);
EC void func_ov000_021a3ee4(struct Unit *, s32);
EC void func_ov000_021a43e8(void);
EC void func_ov000_021a4694(void);
EC void func_ov000_021a46b8(void);
EC void func_ov000_021a4718(void);
EC BOOL func_ov000_021a471c(void);
EC BOOL func_ov000_021a478c(void);
EC BOOL func_ov000_021a47e4(void);
EC s32 func_ov000_021a4854(struct Unit *);
EC void func_ov000_021a48d8(void);
EC void func_ov000_021a4cec(void *, s32, s32, s32, s32, s32);
EC void func_ov000_021a516c(s32);
EC BOOL func_ov000_021a5650(void *, u32);
EC BOOL func_ov000_021a5768(void *, u32);
EC void func_ov000_021a5774(void *, u32);
EC void func_ov000_021a57e4(void *, u32);
EC void func_ov000_021a5810(void *, u32);
EC void func_ov000_021a5d5c(void *, u32);
EC void func_ov000_021a6bd0(void *);
EC void func_ov000_021a7284(void);
EC void func_ov000_021a81d4(void);
EC BOOL func_ov000_021a8248(void);
EC void func_ov000_021a969c(s32);
EC void func_ov000_021a9714(void *);
EC void func_ov000_021a98a4(ProcPtr, s32, s32, s32);
EC BOOL func_ov000_021a98ec(s32, s32);
EC BOOL func_ov000_021a995c(u32, s32);
EC void func_ov000_021a9a48(void);
EC BOOL func_ov000_021a9cac(void);
EC void func_ov000_021a9ce4(void);
EC void func_ov000_021aa1d0(void);
EC void func_ov000_021ab768(void);
EC BOOL func_ov000_021abf30(void);

EC void func_ov000_021b06d4(ProcPtr);
EC void func_ov000_021b0de8(s32, s32, s32, s32);
EC void func_ov000_021b799c(s32, s32, s32);
EC void func_ov000_021b79f8(void);
EC void func_ov000_021b95e8(void *);
EC void func_ov000_021b9960(void *);
EC void func_ov000_021b9978(void *);
EC void func_ov000_021bb318(void *);
EC void func_ov000_021bc540(void *);
EC void func_ov000_021bc5a8(void *);
EC void func_ov000_021bc994(void *, s32, s32, s32);
EC void func_ov000_021bc9e4(void *);
EC void func_ov000_021bec24(ProcPtr);
EC void func_ov000_021bfb80(ProcPtr);

EC void func_ov000_021c266c(ProcPtr, s32, struct Unit *);
EC void func_ov000_021c52fc(ProcPtr, struct Unit *);
EC void func_ov000_021c63f8(void);
EC void func_ov000_021c669c(void);

EC void func_ov000_021d3fa8(void);
EC void func_ov000_021d604c(s32, ProcPtr);
EC void func_ov000_021d609c(void);
EC void func_ov000_021d6dfc(u32);
EC void func_ov000_021d6e30(u32);
EC void func_ov000_021d6f1c(ProcPtr, u32);
EC void func_ov000_021d95ec(ProcPtr);
EC void func_ov000_021db624(void);

// Overlay 002:

EC void func_ov002_021e69ac(void);

// Overlay 003:

EC void func_ov003_021e3610(void *);
EC void func_ov003_021e4204(void *);
EC void func_ov003_021e4244(void *);
EC void func_ov003_021e4284(void *);
EC void func_ov003_021e42c8(void *, s32);
EC void func_ov003_021e4310(void *, s32);
EC void func_ov003_021e4354(void *, s32);
EC void func_ov003_021e439c(void *);
EC void func_ov003_021eb9b0(void *);
EC void func_ov003_021ebb8c(void *);
EC void func_ov003_021ed664(void *);
EC void func_ov003_021edf2c(void *);
EC void func_ov003_021f049c(void *);
EC void func_ov003_021f24e4(void *);
EC void func_ov003_021f31f0(void *);
EC void func_ov003_021f4a84(void *);
EC void func_ov003_021f6ce8(void *);
EC void func_ov003_021f9470(void *);
EC void func_ov003_021fb690(void *);
EC void func_ov003_021fb704(void *);
EC void func_ov003_021fc0d4(void *);

// Overlay 005:

EC void func_ov005_022052d0(void *);
EC void func_ov005_022054b0(s32);

// Overlay 006:

EC void func_ov006_0221776c(void *);
EC void func_ov006_0221bdbc(void *);
EC void func_ov006_02221aec(void *);
EC void func_ov006_022226cc(void *);

// Overlay 007:

EC void func_ov007_02218284(void *);
EC void func_ov007_0221ad60(void *);

// Overlay 009:

EC void func_ov009_02204e10(void *);
EC void func_ov009_02206020(void *);
EC void func_ov009_022065a0(void *);

// Overlay 011:

EC void func_ov011_022069b8(u32, void *, ProcPtr);

EXTERN_C_END

#endif // UNKNOWN_FUNCS_H
