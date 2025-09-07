#ifndef GLOBAL_H
#define GLOBAL_H

#include "types.h"

#ifdef __cplusplus
#  define EXTERN_C extern "C" {
#  define EXTERN_C_END }
#else
#  define EXTERN_C
#  define EXTERN_C_END
#endif

// helper for temporary declarations
#ifdef __cplusplus
#  define EC extern "C"
#else // #ifndef __cplusplus
#  define EC extern
#endif

EXTERN_C

#define STRUCT_PAD(from, to) unsigned char _pad_ ## from[(to) - (from)]

#define ABS(val) ((val) >= 0 ? (val) : -(val))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#pragma define_section force_text ".text"

EXTERN_C_END

#endif // GLOBAL_H
