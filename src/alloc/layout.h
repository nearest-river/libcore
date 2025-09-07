#ifndef LIBCORE_ALLOC_LAYOUT_H
#define LIBCORE_ALLOC_LAYOUT_H
#include "../prelude.h"
#include "alignment.h"





/// Layout of a block of memory.
///
/// An instance of `Layout` describes a particular layout of memory.
/// You build a `Layout` up as an input to give to an allocator.
///
/// All layouts have an associated size and a power-of-two alignment. The size, when rounded up to
/// the nearest multiple of `align`, does not overflow `isize` (i.e., the rounded value will always be
/// less than or equal to `isize::MAX`).
///
/// (Note that layouts are *not* required to have non-zero size,
/// even though `GlobalAlloc` requires that all memory requests
/// be non-zero in size. A caller must either ensure that conditions
/// like this are met, use specific allocators with looser
/// requirements, or use the more lenient `Allocator` interface.)
typedef struct {
  // size of the requested block of memory, measured in bytes.
  usize size;
  // alignment of the requested block of memory, measured in bytes.
  // we ensure that this is always a power-of-two, because API's
  // like `posix_memalign` require it and it is a reasonable
  // constraint to impose on Layout constructors.
  //
  // (However, we do not analogously require `align >= sizeof(void*)`,
  //  even though that is *also* a requirement of `posix_memalign`.)
  Alignment align;
} Layout;



#define layout_of(ty) (Layout){ .size=sizeof(ty), .align=alignof(ty) }









#endif // !LIBCORE_ALLOC_LAYOUT_H
