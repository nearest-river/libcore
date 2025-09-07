#ifndef LIBCORE_ALLOC_ALIGNMENT_H
#define LIBCORE_ALLOC_ALIGNMENT_H

#include "../prelude.h"

typedef enum: usize {
#if TARGET_PTR_WIDTH>=16
  _Align1Shl0=(usize)1 << 0,
  _Align1Shl1=(usize)1 << 1,
  _Align1Shl2=(usize)1 << 2,
  _Align1Shl3=(usize)1 << 3,
  _Align1Shl4=(usize)1 << 4,
  _Align1Shl5=(usize)1 << 5,
  _Align1Shl6=(usize)1 << 6,
  _Align1Shl7=(usize)1 << 7,
  _Align1Shl8=(usize)1 << 8,
  _Align1Shl9=(usize)1 << 9,
  _Align1Shl10=(usize)1 << 10,
  _Align1Shl11=(usize)1 << 11,
  _Align1Shl12=(usize)1 << 12,
  _Align1Shl13=(usize)1 << 13,
  _Align1Shl14=(usize)1 << 14,
  _Align1Shl15=(usize)1 << 15,
#endif
#if TARGET_PTR_WIDTH>=32
  _Align1Shl16=(usize)1 << 16,
  _Align1Shl17=(usize)1 << 17,
  _Align1Shl18=(usize)1 << 18,
  _Align1Shl19=(usize)1 << 19,
  _Align1Shl20=(usize)1 << 20,
  _Align1Shl21=(usize)1 << 21,
  _Align1Shl22=(usize)1 << 22,
  _Align1Shl23=(usize)1 << 23,
  _Align1Shl24=(usize)1 << 24,
  _Align1Shl25=(usize)1 << 25,
  _Align1Shl26=(usize)1 << 26,
  _Align1Shl27=(usize)1 << 27,
  _Align1Shl28=(usize)1 << 28,
  _Align1Shl29=(usize)1 << 29,
  _Align1Shl30=(usize)1 << 30,
  _Align1Shl31=(usize)1 << 31,
#endif
#if TARGET_PTR_WIDTH>=64
  _Align1Shl32=(usize)1 << 32,
  _Align1Shl33=(usize)1 << 33,
  _Align1Shl34=(usize)1 << 34,
  _Align1Shl35=(usize)1 << 35,
  _Align1Shl36=(usize)1 << 36,
  _Align1Shl37=(usize)1 << 37,
  _Align1Shl38=(usize)1 << 38,
  _Align1Shl39=(usize)1 << 39,
  _Align1Shl40=(usize)1 << 40,
  _Align1Shl41=(usize)1 << 41,
  _Align1Shl42=(usize)1 << 42,
  _Align1Shl43=(usize)1 << 43,
  _Align1Shl44=(usize)1 << 44,
  _Align1Shl45=(usize)1 << 45,
  _Align1Shl46=(usize)1 << 46,
  _Align1Shl47=(usize)1 << 47,
  _Align1Shl48=(usize)1 << 48,
  _Align1Shl49=(usize)1 << 49,
  _Align1Shl50=(usize)1 << 50,
  _Align1Shl51=(usize)1 << 51,
  _Align1Shl52=(usize)1 << 52,
  _Align1Shl53=(usize)1 << 53,
  _Align1Shl54=(usize)1 << 54,
  _Align1Shl55=(usize)1 << 55,
  _Align1Shl56=(usize)1 << 56,
  _Align1Shl57=(usize)1 << 57,
  _Align1Shl58=(usize)1 << 58,
  _Align1Shl59=(usize)1 << 59,
  _Align1Shl60=(usize)1 << 60,
  _Align1Shl61=(usize)1 << 61,
  _Align1Shl62=(usize)1 << 62,
  _Align1Shl63=(usize)1 << 63,
#endif
} Alignment;

#define alignof(ty) _Alignof(ty)




#endif // !LIBCORE_ALLOC_ALIGNMENT_H
