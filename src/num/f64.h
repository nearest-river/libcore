#ifndef LIBCORE_PRIMITIVES_F64_H
#define LIBCORE_PRIMITIVES_F64_H

//! Constants for the `f64` double-precision floating point type.
//!
//! *[See also the `f64` primitive type][f64].*
//!
//! Mathematically significant numbers are provided in the `consts` sub-module.
//!
//! For the constants defined directly in this module
//! (as distinct from those defined in the `consts` sub-module),
//! new code should instead use the associated constants
//! defined directly on the `f64` type.
#include "../types.h"




/// The radix or base of the internal representation of `f64`.
#define F64_RADIX (u32)2

/// Number of significant digits in base 2.
#define F64_MANTISSA_DIGITS (u32)53

/// Approximate number of significant digits in base 10.
///
/// This is the maximum <i>x</i> such that any decimal number with <i>x</i>
/// significant digits can be converted to `f64` and back without loss.
///
/// Equal to floor(log<sub>10</sub>&nbsp;2<sup>[`MANTISSA_DIGITS`]&nbsp;&minus;&nbsp;1</sup>).
///
/// [`MANTISSA_DIGITS`]: F64_MANTISSA_DIGITS
#define F64_DIGITS (u32)15

/// [Machine epsilon] value for `f64`.
///
/// This is the difference between `1.0` and the next larger representable number.
///
/// Equal to 2<sup>1&nbsp;&minus;&nbsp;[`MANTISSA_DIGITS`]</sup>.
///
/// [Machine epsilon]: https://en.wikipedia.org/wiki/Machine_epsilon
/// [`MANTISSA_DIGITS`]: F64_MANTISSA_DIGITS
#define F64_EPSILON (f64)2.2204460492503131e-16

/// Smallest finite `f64` value.
///
/// Equal to &minus;[`MAX`].
///
/// [`MAX`]: F64_MAX
#define F64_MIN (f64)-1.7976931348623157e+308

/// Smallest positive normal `f64` value.
///
/// Equal to 2<sup>[`MIN_EXP`]&nbsp;&minus;&nbsp;1</sup>.
///
/// [`MIN_EXP`]: F64_MIN_EXP
#define F64_MIN_POSITIVE (f64)2.2250738585072014e-308

/// Largest finite `f64` value.
///
/// Equal to
/// (1&nbsp;&minus;&nbsp;2<sup>&minus;[`MANTISSA_DIGITS`]</sup>)&nbsp;2<sup>[`MAX_EXP`]</sup>.
///
/// [`MANTISSA_DIGITS`]: F64_MANTISSA_DIGITS
/// [`MAX_EXP`]: F64_MAX_EXP
#define F64_MAX (f64)1.7976931348623157e+308

/// One greater than the minimum possible normal power of 2 exponent.
///
/// If <i>x</i>&nbsp;=&nbsp;`MIN_EXP`, then normal numbers
/// ≥&nbsp;0.5&nbsp;×&nbsp;2<sup><i>x</i></sup>.
#define F64_MIN_EXP (i32)-1021

/// Maximum possible power of 2 exponent.
///
/// If <i>x</i>&nbsp;=&nbsp;`MAX_EXP`, then normal numbers
/// &lt;&nbsp;1&nbsp;×&nbsp;2<sup><i>x</i></sup>.
#define F64_MAX_EXP (i32)1024

/// Minimum <i>x</i> for which 10<sup><i>x</i></sup> is normal.
///
/// Equal to ceil(log<sub>10</sub>&nbsp;[`MIN_POSITIVE`]).
///
/// [`MIN_POSITIVE`]: F64_MIN_POSITIVE
#define F64_MIN_10_EXP (i32)-307

/// Maximum <i>x</i> for which 10<sup><i>x</i></sup> is normal.
///
/// Equal to floor(log<sub>10</sub>&nbsp;[`MAX`]).
///
/// [`MAX`]: F64_MAX
#define F64_MAX_10_EXP (i32)308

/// Not a Number (NaN).
///
/// Note that IEEE 754 doesn't define just a single NaN value;
/// a plethora of bit patterns are considered to be NaN.
/// Furthermore, the standard makes a difference
/// between a "signaling" and a "quiet" NaN,
/// and allows inspecting its "payload" (the unspecified bits in the bit pattern).
/// This constant isn't guaranteed to equal to any specific NaN bitpattern,
/// and the stability of its representation over Rust versions
/// and target platforms isn't guaranteed.
#define F64_NAN (f64)0.0 / 0.0

/// Infinity (∞).
#define F64_INFINITY (f64)(1.0 / 0.0)

/// Negative infinity (−∞).
#define F64_NEG_INFINITY (f64)(-1.0 / 0.0)



/// Basic mathematical constants.
// FIXME: replace with mathematical constants from cmath.

/// Archimedes' constant (π)
#define F64_PI (f64)3.14159265358979323846264338327950288

/// The full circle constant (τ)
///
/// Equal to 2π.
#define F64_TAU (f64)6.28318530717958647692528676655900577

/// The golden ratio (φ)
#define F64_PHI (f64)1.618033988749894848204586834365638118

/// The Euler-Mascheroni constant (γ)
#define F64_EGAMMA (f64)0.577215664901532860606512090082402431

/// π/2
#define F64_FRAC_PI_2 (f64)1.57079632679489661923132169163975144

/// π/3
#define F64_FRAC_PI_3 (f64)1.04719755119659774615421446109316763

/// π/4
#define F64_FRAC_PI_4 (f64)0.785398163397448309615660845819875721

/// π/6
#define F64_FRAC_PI_6 (f64)0.52359877559829887307710723054658381

/// π/8
#define F64_FRAC_PI_8 (f64)0.39269908169872415480783042290993786

/// 1/π
#define F64_FRAC_1_PI (f64)0.318309886183790671537767526745028724

/// 1/sqrt(π)
#define F64_FRAC_1_SQRT_PI (f64)0.564189583547756286948079451560772586

/// 2/π
#define F64_FRAC_2_PI (f64)0.636619772367581343075535053490057448

/// 2/sqrt(π)
#define F64_FRAC_2_SQRT_PI (f64)1.12837916709551257389615890312154517

/// sqrt(2)
#define F64_SQRT_2 (f64)1.41421356237309504880168872420969808

/// 1/sqrt(2)
#define F64_FRAC_1_SQRT_2 (f64)0.707106781186547524400844362104849039

/// sqrt(3)
#define F64_SQRT_3 (f64)1.732050807568877293527446341505872367

/// 1/sqrt(3)
#define F64_FRAC_1_SQRT_3 (f64)0.577350269189625764509148780501957456

/// Euler's number (e)
#define F64_E (f64)2.71828182845904523536028747135266250

/// log<sub>2</sub>(10)
#define F64_LOG2_10 (f64)3.32192809488736234787031942948939018

/// log<sub>2</sub>(e)
#define F64_LOG2_E (f64)1.44269504088896340735992468100189214

/// log<sub>10</sub>(2)
#define F64_LOG10_2 (f64)0.301029995663981195213738894724493027

/// log<sub>10</sub>(e)
#define F64_LOG10_E (f64)0.434294481903251827651128918916605082

/// ln(2)
#define F64_LN_2 (f64)0.693147180559945309417232121458176568

/// ln(10)
#define F64_LN_10 (f64)2.30258509299404568401799145468436421





#endif // !LIBCORE_PRIMITIVES_F64_H
