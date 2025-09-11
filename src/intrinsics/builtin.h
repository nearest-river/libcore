#ifndef LIBCORE_INTRINSICS_BUILTIN_H
#define LIBCORE_INTRINSICS_BUILTIN_H

#if !defined(__has_builtin)
#error "unreachable"
#endif

#include "../types.h"
#include "../num.h"
#include "common.h"





#define intrinsics_ctlz(x) _Generic((x), \
  unsigned int: (u32)__builtin_clz((x)), \
  unsigned long: (u32)__builtin_clzl((x)), \
  unsigned long long: (u32)__builtin_clzll((x)), \
  unsigned short: (u32)__builtin_clz((unsigned int)(x)<<(BITS(int)-BITS(short))), \
  unsigned char: (u32)__builtin_clz((unsigned int)(x)<<(BITS(int)-BITS(char))), \
  int: (u32)__builtin_clz(intrinsics_transmute(x,unsigned int)), \
  long: (u32)__builtin_clzl(intrinsics_transmute(x,unsigned long)), \
  long long: (u32)__builtin_clzll(intrinsics_transmute(x,unsigned long long)), \
  short: (u32)__builtin_clz(intrinsics_transmute(x,unsigned int)<<(BITS(int)-BITS(short))), \
  char: (u32)__builtin_clz(intrinsics_transmute(x,unsigned int)<<(BITS(int)-BITS(char))), \
  u128: intrinsics_i128_ctlz(x), \
  i128: intrinsics_i128_ctlz(x) \
)

#define intrinsics_ctpop(x) _Generic((x), \
  unsigned int: (u32)__builtin_popcount(x), \
  unsigned long: (u32)__builtin_popcountl(x), \
  unsigned long long: (u32)__builtin_popcountll(x), \
  unsigned short: (u32)__builtin_popcount((unsigned int)(x)), \
  unsigned char: (u32)__builtin_popcount((unsigned int)(x)), \
  int: (u32)__builtin_popcount(intrinsics_transmute(x,unsigned int)), \
  long: (u32)__builtin_popcountl(intrinsics_transmute(x,unsigned long)), \
  long long: (u32)__builtin_popcountll(intrinsics_transmute(x,unsigned long long)), \
  short: (u32)__builtin_popcount(intrinsics_transmute(x,unsigned int)), \
  char: (u32)__builtin_popcount(intrinsics_transmute(x,unsigned int)), \
  u128: intrinsics_u128_popct(x), \
  i128: intrinsics_i128_popct(x) \
)




#endif // LIBCORE_INTRINSICS_BUILTIN_H
