#ifndef LIBCORE_NUM_ISIZE_H
#define LIBCORE_NUM_ISIZE_H
#include "../types.h"



#define ISIZE_BITS (sizeof(isize)*8)
#define ISIZE_MAX ((isize)((1ULL << (ISIZE_BITS-1)) - 1))
#define ISIZE_MIN (-ISIZE_MAX - 1)



#endif // LIBCORE_NUM_ISIZE_H
