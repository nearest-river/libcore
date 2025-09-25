#ifndef LIBCORE_INTRINSICS_C
#define LIBCORE_INTRINSICS_C

#ifndef __has_builtin
#include "intrinsics/fallback.c"
#else
#include "intrinsics/builtin.c"
#endif


#include "intrinsics/common.c"


#endif /* ifndef LIBCORE_INTRINSICS_C */
