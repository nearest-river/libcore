#ifndef LIBCORE_ALLOC_ALLOCATOR_H
#define LIBCORE_ALLOC_ALLOCATOR_H
#include "../types.h"
#include "allocator_fn.h"


typedef struct {
  const void* self;
  AllocFn* const allocate;
  AllocFn* const allocate_zeroed;
  ReallocFn* const reallocate;
  DeallocFn* const dealloc;
  AllocResizeFn* const grow;
  AllocResizeFn* const grow_zeroed;
  AllocResizeFn* const shrink; 
} Allocator;






#endif // LIBCORE_ALLOC_ALLOCATOR_H
