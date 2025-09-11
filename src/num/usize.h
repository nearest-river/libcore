#ifndef LIBCORE_PRIMITIVES_USIZE_H
#define LIBCORE_PRIMITIVES_USIZE_H
#include "../types.h"


#define USIZE_MIN (usize)(0)
#define USIZE_MAX (usize)(~USIZE_MIN)
#define USIZE_BYTES (u32)(sizeof(usize))
#define USIZE_BITS (u32)(USIZE_BYTES*8u)


usize usize_wrapping_add(usize self,usize rhs);
usize usize_wrapping_sub(usize self,usize rhs);
usize usize_wrapping_mul(usize self,usize rhs);
usize usize_wrapping_div(usize self,usize rhs);
usize usize_wrapping_rem(usize self,usize rhs);
usize usize_wrapping_neg(usize self);
usize usize_wrapping_shl(usize self,u32 rhs);
usize usize_wrapping_shr(usize self,u32 rhs);

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
