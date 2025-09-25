#ifndef LIBCORE_ALLOC_ALLOCATOR_FN_H
#define LIBCORE_ALLOC_ALLOCATOR_FN_H
#include "../types.h"
#include "layout.h"
#include "alignment.h"


typedef u8* (AllocFn)(const void* self,Layout layout);
typedef u8* (ReallocFn)(const void* self,u8* ptr,Layout layout,usize new_size);
typedef void (DeallocFn)(const void* self,u8* ptr,Layout layout);
typedef u8* (AllocResizeFn)(const void* self,u8* ptr,Layout old_layout,Layout new_layout);








#endif // LIBCORE_ALLOC_ALLOCATOR_FN_H
