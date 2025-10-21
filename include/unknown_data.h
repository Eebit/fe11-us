#ifndef UNKNOWN_DATA_H
#define UNKNOWN_DATA_H

#include "global.h"
#include "types.h"

#include "unknown_types.h"

#include "proc.h"

EXTERN_C

extern u8 data_027e1b9c[];


extern u32 data_020ce6ec;
extern struct ProcCmd ProcScr_020ce6f0[];
extern struct ProcCmd ProcScr_020ce710[];
extern struct ProcCmd ProcScr_020ce730[];
extern struct ProcCmd ProcScr_020ce750[];

extern struct ProcCmd data_020ceb84[];
extern struct ProcCmd data_020ceba4[];
extern struct ProcCmd data_020cebc4[];
extern struct ProcCmd data_020cebec[];
extern struct ProcCmd data_020cec14[];

extern struct Unknown_02197254 * data_02197254; // FE11 database

extern int data_027e00e0;

extern struct UnkStruct_020ca61c * data_020ca61c;

extern struct UnkStruct_02196f20 * data_02196f20;
extern struct UnkStruct_02196f24 * data_02196f24;
extern u16 data_021970c4[];
extern struct UnkStruct_021974fc * data_021974fc;

// Overlay 000:

extern u32 data_ov000_021e2ca0[];
extern u32 data_ov000_021e2cac[];

extern void * data_ov000_021dcebc[];
extern void * __vt__10DI_ArenaNo[];
extern void * __vt__11DI_ArenaYes[];

extern struct UnkStruct_021e3340 * data_ov000_021e3340;

extern struct UnkStruct_021e3508 data_ov000_021e3508[];

// Overlay 002:

extern struct UnkStruct_021faf8c data_ov002_021faf8c;

EXTERN_C_END

#endif // UNKNOWN_DATA_H
