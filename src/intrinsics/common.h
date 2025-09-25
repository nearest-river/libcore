#ifndef LIBCORE_INTRINSICS_COMMON_H
#define LIBCORE_INTRINSICS_COMMON_H

#include "../num.h"
#include "common/int_wrappers.h"




#define intrinsics_transmute(x,ty) ({ \
  typeof(x) _y=x; \
  *((ty*)&_y); \
})



/// ub if (x & y) != 0
#define intrinsics_unchecked_disjoint_bitor(x, y) ((x) | (y))
#define intrinsics_unchecked_add(x, y) ((x) + (y))
#define intrinsics_unchecked_sub(x, y) ((x) - (y))
#define intrinsics_unchecked_mul(x, y) ((x) * (y))
#define intrinsics_unchecked_shl(x, y) ((x) << (y))
#define intrinsics_unchecked_shr(x, y) ((x) >> (y))
/// ub if y==0, or x%y!=0, or x==min&&y==-1 (signed)
#define intrinsics_unchecked_exact_div(x, y) ((x) / (y))








#endif // LIBCORE_INTRINSICS_COMMON_H
