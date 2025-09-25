#include "../prelude.h"
#include "../types.h"
#include "usize.h"
#include "../intrinsics.h"



/*
#[cfg(target_pointer_width = "64")]
impl usize {

    uint_impl! {

        Self = usize,

        ActualT = u64,

        SignedT = isize,

        BITS = 64,

        BITS_MINUS_ONE = 63,

        MAX = 18446744073709551615,

        rot = 12,

        rot_op = "0xaa00000000006e1",

        rot_result = "0x6e10aa",

        swap_op = "0x1234567890123456",

        swapped = "0x5634129078563412",

        reversed = "0x6a2c48091e6a2c48",

        le_bytes = "[0x56, 0x34, 0x12, 0x90, 0x78, 0x56, 0x34, 0x12]",

        be_bytes = "[0x12, 0x34, 0x56, 0x78, 0x90, 0x12, 0x34, 0x56]",

        to_xe_bytes_doc = usize_isize_to_xe_bytes_doc!(),

        from_xe_bytes_doc = usize_isize_from_xe_bytes_doc!(),

        bound_condition = " on 64-bit targets",

    }

    midpoint_impl! { usize, u128, unsigned }

}
*/

/**

        pub const unsafe fn unchecked_add(self, rhs: Self) -> Self {
            assert_unsafe_precondition!(
                check_language_ub,
                concat!(stringify!($SelfT), "::unchecked_add cannot overflow"),
                (
                    lhs: $SelfT = self,
                    rhs: $SelfT = rhs,
                ) => !lhs.overflowing_add(rhs).1,
            );

            // SAFETY: this is guaranteed to be safe by the caller.
            unsafe {
                intrinsics::unchecked_add(self, rhs)
            }
        }
*/
inline_always
unsafe usize usize_unchecked_add(const usize self,const usize other) {
  assert(!intrinsics_overflowing_add(self,other).overflow && "usize_unchecked_add cannot overflow");
  return intrinsics_unchecked_add(self,other);
}

inline_always
unsafe usize usize_unchecked_sub(const usize self,const usize other) {
  assert(!intrinsics_overflowing_sub(self,other).overflow && "usize_unchecked_sub cannot overflow");
  return intrinsics_unchecked_sub(self,other);
}

inline_always
unsafe usize usize_unchecked_mul(const usize self,const usize other) {
  assert(intrinsics_overflowing_mul(self,other).overflow && "usize_unchecked_mul cannot overflow");
  return intrinsics_unchecked_mul(self,other);
}

inline_always
unsafe usize usize_unchecked_exact_div(const usize self,const usize other) {
  assert(other!=0 && "division by 0");
  return intrinsics_unchecked_exact_div(self,other);
}

inline_always
unsafe usize usize_unchecked_disjoint_bitor(const usize self,const usize other) {
  assert((self&other)==0);
  return intrinsics_unchecked_disjoint_bitor(self,other);
}

inline_always
unsafe usize usize_unchecked_shr(const usize self,const u32 rhs) {
  assert(rhs<USIZE_BITS);
  return intrinsics_unchecked_shr(self,rhs);
}

inline_always
unsafe usize usize_unchecked_shl(const usize self,const u32 rhs) {
  assert(rhs<USIZE_BITS);
  return intrinsics_unchecked_shl(self,rhs);
}

inline_always
usize usize_unbounded_shr(const usize self,const u32 rhs) {
  return rhs<USIZE_BITS?intrinsics_unchecked_shr(self,rhs):0;
}

inline_always
usize usize_unbounded_shl(const usize self,const u32 rhs) {
  return rhs<USIZE_BITS?intrinsics_unchecked_shl(self,rhs):0;
}




inline_always
usize usize_wrapping_add(const usize self,const usize rhs) {
  return 0;
}




inline_always
usize usize_wrapping_shr(const usize self,const u32 rhs) {
  // SAFETY: the masking by the bitsize of the type
  // ensures that we do not shift out of bounds.
  return unsafe usize_unchecked_shr(self,rhs&(USIZE_BITS-1));
}










inline_always
u32 usize_count_ones(const usize self) {
  return intrinsics_ctpop(self);
}

inline_always
u32 usize_count_zeros(const usize self) {
  return usize_count_ones(~self);
}

inline_always
u32 usize_leading_zeros(const usize self) {
  return intrinsics_ctlz((u64)self);
}

inline_always
u32 usize_trailing_zeros(const usize self) {
  return intrinsics_cttz(self);
}

inline_always
u32 usize_leading_ones(const usize self) {
  return usize_leading_zeros(~self);
}

inline_always
u32 usize_trailing_ones(const usize self) {
  return usize_trailing_zeros(~self);
}

inline_always
u32 usize_bit_width(const usize self) {
  return USIZE_BITS-usize_leading_zeros(self);
}

inline_always
usize usize_isolate_highest_one(const usize self) {
  return self & (1 << usize_wrapping_shr(USIZE_BITS-1,usize_leading_zeros(self)));
}

inline_always
usize usize_isolate_lowest_one(const usize self) {
  return self & usize_wrapping_neg(self);
}

/**
isize usize_cast_signed(const usize self) {
(isize)self
}
usize usize_rotate_left(const usize self, const u32 n) {
return intrinsics_rotate_left(self, n);
}
usize usize_rotate_right(const usize self, const u32 n) {
return intrinsics_rotate_right(self, n);
}
usize usize_swap_bytes(const usize self) {
(usize)intrinsics_bswap((u64)self)
}
usize usize_reverse_bits(const usize self) {
(usize)intrinsics_bitreverse((u64)self)
}
usize usize_from_be(const usize x) {
{
swap_bytes(x)
}
}
usize usize_from_le(const usize x) {
{
x
}
}
usize usize_to_be(const usize self) {
{
swap_bytes(self)
}
}
usize usize_to_le(const usize self) {
{
self
}
}
usize usize_strict_div(const usize self, const usize rhs) {
self / rhs
}
usize usize_strict_div_euclid(const usize self, const usize rhs) {
self / rhs
}
usize usize_wrapping_div(const usize self, const usize rhs) {
self / rhs
}
usize usize_wrapping_div_euclid(const usize self, const usize rhs) {
self / rhs
}
usize usize_wrapping_rem(const usize self, const usize rhs) {
self % rhs
}
usize usize_wrapping_rem_euclid(const usize self, const usize rhs) {
self % rhs
}
usize usize_wrapping_neg(const usize self) {
wrapping_sub(((usize)0), self)
}
usize usize_div_euclid(const usize self, const usize rhs) {
self / rhs
}
usize usize_rem_euclid(const usize self, const usize rhs) {
self % rhs
}
usize usize_div_floor(const usize self, const usize rhs) {
self / rhs
}
usize usize_div_ceil(const usize self, const usize rhs) {
d = self / rhs;
r = self % rhs;
if (r > 0) {
d + 1
} else {
d
}
}
usize usize_next_multiple_of(const usize self, const usize rhs) {
r = self % rhs;
if (r == 0) {
self
} else {
self + (rhs - r)
}
}
i32 usize_is_multiple_of(const usize self, const usize rhs) {
if (rhs == 0) {
self == 0
} else {
(i32)(self % rhs == 0)
}
}
i32 usize_is_power_of_two(const usize self) {
(i32)(count_ones(self) == 1)
}
usize usize_wrapping_next_power_of_two(const usize self) {
wrapping_add(one_less_than_next_power_of_two(self), 1)
}
u8 arrname[size_of::<usize>()] usize_to_be_bytes(const usize self) {
to_ne_bytes(to_be(self))
}
u8 arrname[size_of::<usize>()] usize_to_le_bytes(const usize self) {
to_ne_bytes(to_le(self))
}
usize usize_from_be_bytes(const u8 bytes[size_of]) {
usize_from_be(usize_from_ne_bytes(bytes))
}
usize usize_from_le_bytes(const u8 bytes[size_of]) {
usize_from_le(usize_from_ne_bytes(bytes))
}
usize usize_min_value() {
return USIZE_MIN;
}
usize usize_max_value() {
return USIZE_MAX;
}
*/












/// Returns true if and only if self == 2^k for some unsigned integer k.
inline_always
bool usize_is_power_of_two(usize x) {
  return x != 0 && (x & (x - 1)) == 0;
}

/// Returns the smallest power of two greater than or equal to self.
///
/// When return value overflows (i.e., self > (1 << (N-1)) for type uN).
/// it panics in debug mode and the return value is wrapped to 0 in release mode
/// (the only situation in which this method can return 0).
inline_always
usize usize_next_power_of_two(usize x) {
  if(x==0) {
    return 1;
  }

  x-= 1;
  x|=x>>1;
  x|=x>>2;
  x|=x>>4;
  x|=x>>8;
  x|=x>>16;
  x|=x>>32;

  #ifdef DEBUG
    assert(x!=USIZE_MAX); 
  #endif

  return x + 1;
}


// pub fn is_power_of_two(x: u64) -> bool {
//    x != 0 && (x & (x - 1)) == 0
//}
