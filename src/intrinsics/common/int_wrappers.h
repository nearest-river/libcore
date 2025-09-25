#ifndef LIBCORE_INTRINSICS_OPS_H
#define LIBCORE_INTRINSICS_OPS_H
#include "../../num.h"
#include "../../types.h"


typedef struct {
  i8 x;
  bool overflow;
} OverflowingI8;

typedef struct {
  i16 x;
  bool overflow;
} OverflowingI16;

typedef struct {
  i32 x;
  bool overflow;
} OverflowingI32;

typedef struct {
  i64 x;
  bool overflow;
} OverflowingI64;

typedef struct {
  i128 x;
  bool overflow;
} OverflowingI128;

typedef struct {
  u8 x;
  bool overflow;
} OverflowingU8;

typedef struct {
  u16 x;
  bool overflow;
} OverflowingU16;

typedef struct {
  u32 x;
  bool overflow;
} OverflowingU32;

typedef struct {
  u64 x;
  bool overflow;
} OverflowingU64;

typedef struct {
  u128 x;
  bool overflow;
} OverflowingU128;


// pointer sized ints.
#if TARGET_PTR_WIDTH==64
typedef OverflowingU64 OverflowingUsize;
typedef OverflowingI64 OverflowingIsize;
#elif TARGET_PTR_WIDTH==32
typedef OverflowingU32 OverflowingUsize;
typedef OverflowingI32 OverflowingIsize;
#elif TARGET_PTR_WIDTH==16
typedef OverflowingU16 OverflowingUsize;
typedef OverflowingI16 OverflowingIsize;
#endif







OverflowingU8 intrinsics_u8_overflowing_add(const u8 a,const u8 b);
OverflowingU16 intrinsics_u16_overflowing_add(const u16 a,const u16 b);
OverflowingU32 intrinsics_u32_overflowing_add(const u32 a,const u32 b);
OverflowingU64 intrinsics_u64_overflowing_add(const u64 a,const u64 b);
OverflowingU128 intrinsics_u128_overflowing_add(const u128 a,const u128 b);
OverflowingUsize intrinsics_usize_overflowing_add(const usize a,const usize b);

OverflowingI8 intrinsics_i8_overflowing_add(const i8 a,const i8 b);
OverflowingI16 intrinsics_i16_overflowing_add(const i16 a,const i16 b);
OverflowingI32 intrinsics_i32_overflowing_add(const i32 a,const i32 b);
OverflowingI64 intrinsics_i64_overflowing_add(const i64 a,const i64 b);
OverflowingI128 intrinsics_i128_overflowing_add(const i128 a,const i128 b);
OverflowingIsize intrinsics_isize_overflowing_add(const isize a,const isize b);


OverflowingU8 intrinsics_u8_overflowing_sub(const u8 a,const u8 b);
OverflowingU16 intrinsics_u16_overflowing_sub(const u16 a,const u16 b);
OverflowingU32 intrinsics_u32_overflowing_sub(const u32 a,const u32 b);
OverflowingU64 intrinsics_u64_overflowing_sub(const u64 a,const u64 b);
OverflowingU128 intrinsics_u128_overflowing_sub(const u128 a,const u128 b);
OverflowingUsize intrinsics_usize_overflowing_sub(const usize a,const usize b);

OverflowingI8 intrinsics_i8_overflowing_sub(const i8 a,const i8 b);
OverflowingI16 intrinsics_i16_overflowing_sub(const i16 a,const i16 b);
OverflowingI32 intrinsics_i32_overflowing_sub(const i32 a,const i32 b);
OverflowingI64 intrinsics_i64_overflowing_sub(const i64 a,const i64 b);
OverflowingI128 intrinsics_i128_overflowing_sub(const i128 a,const i128 b);
OverflowingIsize intrinsics_isize_overflowing_sub(const isize a,const isize b);


OverflowingU8 intrinsics_u8_overflowing_mul(const u8 a,const u8 b);
OverflowingU16 intrinsics_u16_overflowing_mul(const u16 a,const u16 b);
OverflowingU32 intrinsics_u32_overflowing_mul(const u32 a,const u32 b);
OverflowingU64 intrinsics_u64_overflowing_mul(const u64 a,const u64 b);
OverflowingU128 intrinsics_u128_overflowing_mul(const u128 a,const u128 b);
OverflowingUsize intrinsics_usize_overflowing_mul(const usize a,const usize b);

OverflowingI8 intrinsics_i8_overflowing_mul(const i8 a,const i8 b);
OverflowingI16 intrinsics_i16_overflowing_mul(const i16 a,const i16 b);
OverflowingI32 intrinsics_i32_overflowing_mul(const i32 a,const i32 b);
OverflowingI64 intrinsics_i64_overflowing_mul(const i64 a,const i64 b);
OverflowingI128 intrinsics_i128_overflowing_mul(const i128 a,const i128 b);
OverflowingIsize intrinsics_isize_overflowing_mul(const isize a,const isize b);









#endif // LIBCORE_INTRINSICS_OPS_H
