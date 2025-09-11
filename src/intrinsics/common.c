#ifndef LIBCORE_INTRINSICS_COMMON_C
#define LIBCORE_INTRINSICS_COMMON_C

#include "../prelude.h"
#include "common.h"


inline_always
u32 intrinsics_u128_ctlz(const u128 x) {
  const u64 ls_half=x&(u128)U64_MAX;
  const u64 ms_half=x>>64;
  return ms_half==0?(u32)__builtin_clzll(ls_half)+64:(u32)__builtin_clzll(ms_half);
}


inline_always
u32 intrinsics_i128_ctlz(const i128 x) {
  const u128 y=intrinsics_transmute(x,u128);
  const u64 ls_half=(y&I64_MAX);
  const u64 ms_half=y>>64;
  return ms_half==0?(u32)__builtin_clzll(ls_half)+64:(u32)__builtin_clzll(ms_half);
}




inline_always
u32 intrinsics_u128_popct(const u128 x) {
  const u64 ls_half=x&(u128)U64_MAX;
  const u64 ms_half=x>>64;
  return (u32)(__builtin_popcountll(ms_half)+__builtin_popcountll(ls_half));
}

inline_always
u32 intrinsics_i128_popct(const i128 x) {
  const u128 y=intrinsics_transmute(x,u128);
  const u64 ls_half=(y&I64_MAX);
  const u64 ms_half=y>>64;
  return (u32)(__builtin_popcountll(ms_half)+__builtin_popcountll(ls_half));
}












#endif // LIBCORE_INTRINSICS_COMMON_C
