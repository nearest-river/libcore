#ifndef LIBCORE_INTRINSICS_H
#define LIBCORE_INTRINSICS_H
// #include <builtins.h>

#ifdef __has_builtin
#include "intrinsics/builtin.h"
#else
#include "intrinsics/fallback.h"
#endif

#endif // !LIBCORE_INTRINSICS_H
