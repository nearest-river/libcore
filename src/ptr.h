#ifndef LIBCORE_PTR_H
#define LIBCORE_PTR_H
#include "types.h"
#include "alloc/alignment.h"



void* ptr_without_provenance(usize addr);



#define ptr_dangling(T) ((T*)ptr_without_provenance(alignof(T)))


#endif // LIBCORE_PTR_H
