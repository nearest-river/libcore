#ifndef LIBCORE_INTRINSICS_BUILTIN_INT_OPS_H
#define LIBCORE_INTRINSICS_BUILTIN_INT_OPS_H
#include "../common.h"
#include "../../num.h"
#include "../../types.h"
#include <assert.h>




u32 intrinsics_u128_popct(const u128 x);
u32 intrinsics_i128_popct(const i128 x);


u32 intrinsics_u128_ctlz(const u128 x);
u32 intrinsics_i128_ctlz(const i128 x);


u32 intrinsics_u128_cttz(const u128 x);
u32 intrinsics_i128_cttz(const i128 x);




#define intrinsics_ctpop(x) _Generic((x), \
  unsigned int: (u32)__builtin_popcount(x), \
  unsigned long: (u32)__builtin_popcountl(x), \
  unsigned long long: (u32)__builtin_popcountll(x), \
  unsigned short: (u32)__builtin_popcount((unsigned int)(x)), \
  unsigned char: (u32)__builtin_popcount((unsigned int)(x)), \
  int: (u32)__builtin_popcount(intrinsics_transmute(x,unsigned int)), \
  long: (u32)__builtin_popcountl(intrinsics_transmute(x,unsigned long)), \
  long long: (u32)__builtin_popcountll(intrinsics_transmute(x,unsigned long long)), \
  short: (u32)__builtin_popcount(intrinsics_transmute((int)(x),unsigned int)), \
  char: (u32)__builtin_popcount(intrinsics_transmute((int)(x),unsigned int)), \
  u128: intrinsics_u128_popct(x), \
  i128: intrinsics_i128_popct(x) \
)

#define intrinsics_ctlz(x) _Generic((x), \
  unsigned int: (u32)__builtin_clz((x)), \
  unsigned long: (u32)__builtin_clzl((x)), \
  unsigned long long: (u32)__builtin_clzll((x)), \
  unsigned short: (u32)__builtin_clz((unsigned int)(x)<<(BITS(int)-BITS(short))), \
  unsigned char: (u32)__builtin_clz((unsigned int)(x)<<(BITS(int)-BITS(char))), \
  int: (u32)__builtin_clz(intrinsics_transmute(x,unsigned int)), \
  long: (u32)__builtin_clzl(intrinsics_transmute(x,unsigned long)), \
  long long: (u32)__builtin_clzll(intrinsics_transmute(x,unsigned long long)), \
  short: (u32)__builtin_clz(intrinsics_transmute((int)(x),unsigned int)<<(BITS(int)-BITS(short))), \
  char: (u32)__builtin_clz(intrinsics_transmute((int)(x),unsigned int)<<(BITS(int)-BITS(char))), \
  u128: intrinsics_i128_ctlz(x), \
  i128: intrinsics_i128_ctlz(x) \
)



#define intrinsics_cttz(x) _Generic((x), \
  unsigned int: (u32)__builtin_ctz(x), \
  unsigned long: (u32)__builtin_ctzl(x), \
  unsigned long long: (u32)__builtin_ctzll(x), \
  unsigned short: (u32)__builtin_ctz((unsigned int)(x)), \
  unsigned char: (u32)__builtin_ctz((unsigned int)(x)), \
  int: (u32)__builtin_ctz(intrinsics_transmute(x,unsigned int)), \
  long: (u32)__builtin_ctzl(intrinsics_transmute(x,unsigned long)), \
  long long: (u32)__builtin_ctzll(intrinsics_transmute(x,unsigned long long)), \
  short: (u32)__builtin_ctz(intrinsics_transmute((int)(x),unsigned int)), \
  char: (u32)__builtin_ctz(intrinsics_transmute((int)(x),unsigned int)), \
  u128: intrinsics_u128_cttz(x), \
  i128: intrinsics_i128_cttz(x) \
)

#define intrinsics_overflowing_add(a,b) _Generic(a, \
  u8: intrinsics_u8_overflowing_add(a,b), \
  u16: intrinsics_u16_overflowing_add(a,b), \
  u32: intrinsics_u32_overflowing_add(a,b), \
  u64: intrinsics_u64_overflowing_add(a,b), \
  u128: intrinsics_u128_overflowing_add(a,b), \
  i8: intrinsics_i8_overflowing_add(a,b), \
  i16: intrinsics_i16_overflowing_add(a,b), \
  i32: intrinsics_i32_overflowing_add(a,b), \
  i64: intrinsics_i64_overflowing_add(a,b), \
  i128: intrinsics_i128_overflowing_add(a,b) \
)

#define intrinsics_overflowing_sub(a,b) _Generic(a, \
  u8: intrinsics_u8_overflowing_sub(a,b), \
  u16: intrinsics_u16_overflowing_sub(a,b), \
  u32: intrinsics_u32_overflowing_sub(a,b), \
  u64: intrinsics_u64_overflowing_sub(a,b), \
  u128: intrinsics_u128_overflowing_sub(a,b), \
  i8: intrinsics_i8_overflowing_sub(a,b), \
  i16: intrinsics_i16_overflowing_sub(a,b), \
  i32: intrinsics_i32_overflowing_sub(a,b), \
  i64: intrinsics_i64_overflowing_sub(a,b), \
  i128: intrinsics_i128_overflowing_sub(a,b) \
)

#define intrinsics_overflowing_mul(a,b) _Generic(a, \
  u8: intrinsics_u8_overflowing_mul(a,b), \
  u16: intrinsics_u16_overflowing_mul(a,b), \
  u32: intrinsics_u32_overflowing_mul(a,b), \
  u64: intrinsics_u64_overflowing_mul(a,b), \
  u128: intrinsics_u128_overflowing_mul(a,b), \
  i8: intrinsics_i8_overflowing_mul(a,b), \
  i16: intrinsics_i16_overflowing_mul(a,b), \
  i32: intrinsics_i32_overflowing_mul(a,b), \
  i64: intrinsics_i64_overflowing_mul(a,b), \
  i128: intrinsics_i128_overflowing_mul(a,b) \
)

#define intrinsics_overflowing_div(a,b) ({ \
  assert((b)!=0 && "cannot divide by zero"); \
  __auto_type x=(a)/(b); \
  _Generic((y), \
    u8: (OverflowingU8){ .x=x, .overflow=flase }, \
    u16: (OverflowingU16){ .x=x, .overflow=flase }, \
    u32: (OverflowingU32){ .x=x, .overflow=flase }, \
    u64: (OverflowingU64){ .x=x, .overflow=flase }, \
    u128: (OverflowingU128){ .x=x, .overflow=flase }, \
    i8: (OverflowingI8){ .x=x, .overflow=flase }, \
    i16: (OverflowingI16){ .x=x, .overflow=flase }, \
    i32: (OverflowingI32){ .x=x, .overflow=flase }, \
    i64: (OverflowingI64){ .x=x, .overflow=flase }, \
    i128: (OverflowingI128){ .x=x, .overflow=flase } \
  ) \
})






















#endif // LIBCORE_INTRINSICS_BUILTIN_INT_OPS_H
