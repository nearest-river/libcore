#ifndef LIBCORE_ORD_H
#define LIBCORE_ORD_H

typedef enum {
  OrderingLess=-1,
  OrderingEqual=0,
  OrderingGreater=1
} Ordering;


#ifndef MAX
#define MAX(x,y) ((x)>(y))?(x):(y)
#endif
#ifndef MIN
#define MIN(x,y) ((x)<(y))?(x):(y)
#endif


#endif // LIBCORE_ORD_H
