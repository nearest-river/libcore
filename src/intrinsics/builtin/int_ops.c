#ifndef LIBCORE_INTRINSICS_BUILTIN_INT_OPS_C
#define LIBCORE_INTRINSICS_BUILTIN_INT_OPS_C
#include "../common.h"
#include "../../prelude.h"


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
u32 intrinsics_u128_cttz(const u128 x) {
  const u64 ls_half=x&(u128)U64_MAX;
  const u64 ms_half=x>>64;
  return ls_half==0?(u32)__builtin_ctzll(ms_half)+64:(u32)__builtin_ctzll(ls_half);
}

inline_always
u32 intrinsics_i128_cttz(const i128 x) {
  const u128 y=intrinsics_transmute(x,u128);
  const u64 ls_half=y&(u128)U64_MAX;
  const u64 ms_half=y>>64;
  return ls_half==0?(u32)__builtin_ctzll(ms_half)+64:(u32)__builtin_ctzll(ls_half);
}



OverflowingU8 intrinsics_u8_overflowing_add(const u8 a,const u8 b) {
  u8 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingU8){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU16 intrinsics_u16_overflowing_add(const u16 a,const u16 b) {
  u16 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingU16){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU32 intrinsics_u32_overflowing_add(const u32 a,const u32 b) {
  u32 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingU32){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU64 intrinsics_u64_overflowing_add(const u64 a,const u64 b) {
  u64 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingU64){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU128 intrinsics_u128_overflowing_add(const u128 a,const u128 b) {
  u128 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingU128){
    .x=x,
    .overflow=overflow
  };
}

OverflowingUsize intrinsics_usize_overflowing_add(const usize a,const usize b) {
  usize x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingUsize){
    .x=x,
    .overflow=overflow
  };
}


OverflowingI8 intrinsics_i8_overflowing_add(const i8 a,const i8 b) {
  i8 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingI8){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI16 intrinsics_i16_overflowing_add(const i16 a,const i16 b) {
  i16 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingI16){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI32 intrinsics_i32_overflowing_add(const i32 a,const i32 b) {
  i32 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingI32){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI64 intrinsics_i64_overflowing_add(const i64 a,const i64 b) {
  i64 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingI64){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI128 intrinsics_i128_overflowing_add(const i128 a,const i128 b) {
  i128 x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingI128){
    .x=x,
    .overflow=overflow
  };
}

OverflowingIsize intrinsics_isize_overflowing_add(const isize a,const isize b) {
  isize x;
  bool overflow=__builtin_add_overflow(a,b,&x);
  return (OverflowingIsize){
    .x=x,
    .overflow=overflow
  };
}





OverflowingU8 intrinsics_u8_overflowing_sub(const u8 a,const u8 b) {
  u8 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingU8){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU16 intrinsics_u16_overflowing_sub(const u16 a,const u16 b) {
  u16 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingU16){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU32 intrinsics_u32_overflowing_sub(const u32 a,const u32 b) {
  u32 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingU32){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU64 intrinsics_u64_overflowing_sub(const u64 a,const u64 b) {
  u64 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingU64){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU128 intrinsics_u128_overflowing_sub(const u128 a,const u128 b) {
  u128 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingU128){
    .x=x,
    .overflow=overflow
  };
}

OverflowingUsize intrinsics_usize_overflowing_sub(const usize a,const usize b) {
  usize x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingUsize){
    .x=x,
    .overflow=overflow
  };
}






OverflowingI8 intrinsics_i8_overflowing_sub(const i8 a,const i8 b) {
  i8 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingI8){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI16 intrinsics_i16_overflowing_sub(const i16 a,const i16 b) {
  i16 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingI16){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI32 intrinsics_i32_overflowing_sub(const i32 a,const i32 b) {
  i32 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingI32){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI64 intrinsics_i64_overflowing_sub(const i64 a,const i64 b) {
  i64 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingI64){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI128 intrinsics_i128_overflowing_sub(const i128 a,const i128 b) {
  i128 x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingI128){
    .x=x,
    .overflow=overflow
  };
}

OverflowingIsize intrinsics_isize_overflowing_sub(const isize a,const isize b) {
  isize x;
  bool overflow=__builtin_sub_overflow(a,b,&x);
  return (OverflowingIsize){
    .x=x,
    .overflow=overflow
  };
}







OverflowingU8 intrinsics_u8_overflowing_mul(const u8 a,const u8 b) {
  u8 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingU8){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU16 intrinsics_u16_overflowing_mul(const u16 a,const u16 b) {
  u16 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingU16){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU32 intrinsics_u32_overflowing_mul(const u32 a,const u32 b) {
  u32 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingU32){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU64 intrinsics_u64_overflowing_mul(const u64 a,const u64 b) {
  u64 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingU64){
    .x=x,
    .overflow=overflow
  };
}

OverflowingU128 intrinsics_u128_overflowing_mul(const u128 a,const u128 b) {
  u128 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingU128){
    .x=x,
    .overflow=overflow
  };
}

OverflowingUsize intrinsics_usize_overflowing_mul(const usize a,const usize b) {
  usize x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingUsize){
    .x=x,
    .overflow=overflow
  };
}






OverflowingI8 intrinsics_i8_overflowing_mul(const i8 a,const i8 b) {
  i8 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingI8){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI16 intrinsics_i16_overflowing_mul(const i16 a,const i16 b) {
  i16 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingI16){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI32 intrinsics_i32_overflowing_mul(const i32 a,const i32 b) {
  i32 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingI32){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI64 intrinsics_i64_overflowing_mul(const i64 a,const i64 b) {
  i64 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingI64){
    .x=x,
    .overflow=overflow
  };
}

OverflowingI128 intrinsics_i128_overflowing_mul(const i128 a,const i128 b) {
  i128 x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingI128){
    .x=x,
    .overflow=overflow
  };
}

OverflowingIsize intrinsics_isize_overflowing_mul(const isize a,const isize b) {
  isize x;
  bool overflow=__builtin_mul_overflow(a,b,&x);
  return (OverflowingIsize){
    .x=x,
    .overflow=overflow
  };
}


















#endif // LIBCORE_INTRINSICS_BUILTIN_INT_OPS_C
