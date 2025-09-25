#ifndef LIBCORE_ALLOC_GLOBAL_H
#define LIBCORE_ALLOC_GLOBAL_H
#include "../types.h"
#include "allocator_fn.h"


typedef struct {
  const void* self;
  AllocFn* const alloc;
  AllocFn* const alloc_zeroed;
  ReallocFn* const realloc;
  DeallocFn* const dealloc;
} GlobalAlloc;






#endif // LIBCORE_ALLOC_GLOBAL_H
