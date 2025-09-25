#ifndef LIBCORE_PRELUDE_H
#define LIBCORE_PRELUDE_H
#include <assert.h>
#include <stdio.h>

#include "types.h"

#include "ord.h"

#include "num.h"





/// A function that frees the resources held by `self`.
typedef void (Destructor)(void* self);

/// A function that clones from `src` to `dest` without forgetting about the resources held by `self`.
typedef void (Clone)(void* dest,void* src);

typedef Ordering (ComparisonFn)(const void*,const void*);

typedef bool (Eq)(const void* self,const void* other);

typedef bool (PredicateFn)(const void*);


#define let const __auto_type
#define let_mut __auto_type


#define panic(...) { fprintf(stderr,__VA_ARGS__);exit(1); }

#define inline_always __inline __attribute__ ((__always_inline__))
#define must_use __attribute__((warn_unused_result))
// TODO
#define unsafe /* UNSAFE: This function is marked unsafe. */



#ifndef not_null
#define not_null(ptr) { assert(ptr!=NULL); }
#endif
#ifndef not_null2
#define not_null2(ptr1,ptr2) { assert(ptr1!=NULL);assert(ptr2); }
#endif

#ifndef MIN_NON_ZERO_CAP
#define MIN_NON_ZERO_CAP(SIZE) ((SIZE)==1)?(8):((SIZE)<=1024)?4:1
#endif // !MIN_NON_ZERO_CAP





#endif // !LIBCORE_PRELUDE_H
