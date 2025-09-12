#ifndef LIBCORE_INTRINSICS_COMMON_H
#define LIBCORE_INTRINSICS_COMMON_H

#include "../num.h"


u32 intrinsics_u128_popct(const u128 x);
u32 intrinsics_i128_popct(const i128 x);


u32 intrinsics_u128_ctlz(const u128 x);
u32 intrinsics_i128_ctlz(const i128 x);


u32 intrinsics_u128_cttz(const u128 x);
u32 intrinsics_i128_cttz(const i128 x);


#define intrinsics_transmute(x,ty) ({ \
  typeof(x) _y=x; \
  *((ty*)&_y); \
})






#endif // LIBCORE_INTRINSICS_COMMON_H
