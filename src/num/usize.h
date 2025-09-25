#ifndef LIBCORE_PRIMITIVES_USIZE_H
#define LIBCORE_PRIMITIVES_USIZE_H
#include "../types.h"


#define USIZE_MIN (usize)(0)
#define USIZE_MAX (usize)(~USIZE_MIN)
#define USIZE_BYTES (u32)(sizeof(usize))
#define USIZE_BITS (u32)(USIZE_BYTES*8u)





u32 usize_count_ones(const usize self);
u32 usize_count_zeros(const usize self);
u32 usize_leading_zeros(const usize self);

bool usize_is_power_of_two(usize x);
usize usize_next_power_of_two(usize x);


















usize usize_wrapping_add(usize self,usize rhs);
usize usize_wrapping_sub(usize self,usize rhs);
usize usize_wrapping_mul(usize self,usize rhs);
usize usize_wrapping_div(usize self,usize rhs);
usize usize_wrapping_rem(usize self,usize rhs);
usize usize_wrapping_neg(const usize self);
usize usize_wrapping_shl(const usize self,const u32 rhs);
usize usize_wrapping_shr(const usize self,const u32 rhs);



/*
usize_checked_add(usize self,usize rhs) -> Option<usize>
usize_checked_sub(usize self,usize rhs) -> Option<usize>
usize_checked_mul(usize self,usize rhs) -> Option<usize>
usize_checked_div(usize self,usize rhs) -> Option<usize>
usize_checked_rem(usize self,usize rhs) -> Option<usize>
*/

usize usize_saturating_add(usize self,usize rhs);
usize usize_saturating_sub(usize self,usize rhs);
usize usize_saturating_mul(usize self,usize rhs);

/*
usize_overflowing_add(usize self,usize rhs) -> (usize,bool)
usize_overflowing_sub(usize self,usize rhs) -> (usize,bool)
usize_overflowing_mul(usize self,usize rhs) -> (usize,bool)
*/









#endif // !LIBCORE_PRIMITIVES_USIZE_H
