#ifndef LIBCORE_PRIMITIVES_H
#define LIBCORE_PRIMITIVES_H

#ifndef TARGET_PTR_WIDTH
#define TARGET_PTR_WIDTH (__SIZEOF_POINTER__*8)
#endif // !TARGET_PTR_WIDTH


typedef __UINT8_TYPE__ u8;
typedef __UINT16_TYPE__ u16;
typedef __UINT32_TYPE__ u32;
typedef __UINT64_TYPE__ u64;
#ifdef __SIZEOF_INT128__
typedef __uint128_t u128;
#endif

typedef __INT8_TYPE__ i8;
typedef __INT16_TYPE__ i16;
typedef __INT32_TYPE__ i32;
typedef __INT64_TYPE__ i64;
#ifdef __SIZEOF_INT128__
typedef __int128_t i128;
#endif


// pointer sized ints.
#if TARGET_PTR_WIDTH==64
typedef i64 isize;
typedef u64 usize;
#elif TARGET_PTR_WIDTH==32
typedef i32 isize;
typedef u32 usize;
#elif TARGET_PTR_WIDTH==16
typedef i16 isize;
typedef u16 usize;
#endif

typedef struct {
  char chars[4];
} utf8char;

typedef _Float16 f16;
typedef float f32;
typedef double f64;
#ifdef __FLOAT128__
typedef __float128 f128;
#endif

#ifndef __STDBOOL_H
#define __bool_true_false_are_defined 1

#if defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L
#elif !defined(__cplusplus)
typedef _Bool bool;
#define true 1
#define false 0
#elif defined(__GNUC__) && !defined(__STRICT_ANSI__)
/* Define _Bool as a GNU extension. */
#define _Bool bool
#if defined(__cplusplus) && __cplusplus < 201103L
/* For C++98, define bool, false, true as a GNU extension. */
typedef bool bool;
#define false false
#define true true
#endif
#endif
#endif


#endif // LIBCORE_PRIMITIVES_H
