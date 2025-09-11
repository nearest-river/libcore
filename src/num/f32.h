#ifndef LIBCORE_PRIMITIVES_F32_H
#define LIBCORE_PRIMITIVES_F32_H

//Basic mathematical constants.
// FIXME: replace with mathematical constants from cmath.
#include "../types.h"

/// Archimedes' constant (π)
#define F32_PI (f32)3.14159265358979323846264338327950288F

/// The full circle constant (τ)
/// Equal to 2π.
#define F32_TAU (f32)6.28318530717958647692528676655900577F

/// The golden ratio (φ)
#define F32_PHI (f32)1.618033988749894848204586834365638118F

/// The Euler-Mascheroni constant (γ)
#define F32_EGAMMA (f32)0.577215664901532860606512090082402431F

/// π/2
#define F32_FRAC_PI_2 (f32)1.57079632679489661923132169163975144F

/// π/3
#define F32_FRAC_PI_3 (f32)1.04719755119659774615421446109316763F

/// π/4
#define F32_FRAC_PI_4 (f32)0.785398163397448309615660845819875721F

/// π/6
#define F32_FRAC_PI_6 (f32)0.52359877559829887307710723054658381F

/// π/8
#define F32_FRAC_PI_8 (f32)0.39269908169872415480783042290993786F

/// 1/π
#define F32_FRAC_1_PI (f32)0.318309886183790671537767526745028724F

/// 1/sqrt(π)
#define F32_FRAC_1_SQRT_PI (f32)0.564189583547756286948079451560772586F

/// 2/π
#define F32_FRAC_2_PI (f32)0.636619772367581343075535053490057448F

/// 2/sqrt(π)
#define F32_FRAC_2_SQRT_PI (f32)1.12837916709551257389615890312154517F

/// sqrt(2)
#define F32_SQRT_2 (f32)1.41421356237309504880168872420969808F

/// 1/sqrt(2)
#define F32_FRAC_1_SQRT_2 (f32)0.707106781186547524400844362104849039F

/// sqrt(3)
#define F32_SQRT_3 (f32)1.732050807568877293527446341505872367F

/// 1/sqrt(3)
#define F32_FRAC_1_SQRT_3 (f32)0.577350269189625764509148780501957456F

/// Euler's number (e)
#define F32_E (f32)2.71828182845904523536028747135266250F

/// log<sub>2</sub>(e)
#define F32_LOG2_E (f32)1.44269504088896340735992468100189214F

/// log<sub>2</sub>(10)
#define F32_LOG2_10 (f32)3.32192809488736234787031942948939018F

/// log<sub>10</sub>(e)
#define F32_LOG10_E (f32)0.434294481903251827651128918916605082F

/// log<sub>10</sub>(2)
#define F32_LOG10_2 (f32)0.301029995663981195213738894724493027F

/// ln(2)
#define F32_LN_2 (f32)0.693147180559945309417232121458176568F

/// ln(10)
#define F32_LN_10 (f32)2.30258509299404568401799145468436421F


/// The radix or base of the internal representation of `f32`.
#define F32_RADIX (u32)2

/// Number of significant digits in base 2.
#define F32_MANTISSA_DIGITS (u32)24

/// Approximate number of significant digits in base 10.
///
/// This is the maximum <i>x</i> such that any decimal number with <i>x</i>
/// significant digits can be converted to `f32` and back without loss.
///
/// Equal to floor(log<sub>10</sub>&nbsp;2<sup>`F32_MANTISSA_DIGITS`&nbsp;&minus;&nbsp;1</sup>).
#define F32_DIGITS (u32)6

/// [Machine epsilon] value for `f32`.
///
/// This is the difference between `1.0` and the next larger representable number.
///
/// Equal to 2<sup>1&nbsp;&minus;&nbsp;`F32_MANTISSA_DIGITS`</sup>.
///
/// [Machine epsilon]: https://en.wikipedia.org/wiki/Machine_epsilon
#define F32_EPSILON (f32)1.19209290e-07F

/// @brief Smallest finite `f32` value.
///
/// Equal to &minus;`F32_MAX`.
#define F32_MIN (f32)-3.40282347e+38F

/// Smallest positive normal `f32` value.
///
/// Equal to 2<sup>`MIN_EXP`&nbsp;&minus;&nbsp;1</sup>.
#define F32_MIN_POSITIVE (f32)1.17549435e-38F

/// Largest finite `f32` value.
///
/// Equal to
/// (1&nbsp;&minus;&nbsp;2<sup>&minus;`F32_MANTISSA_DIGITS`</sup>)&nbsp;2<sup>`MAX_EXP`</sup>.
#define F32_MAX (f32)3.40282347e+38F

/// One greater than the minimum possible normal power of 2 exponent.
///
/// If <i>x</i>&nbsp;=&nbsp;`MIN_EXP`, then normal numbers
/// ≥&nbsp;0.5&nbsp;×&nbsp;2<sup><i>x</i></sup>.
#define F32_MIN_EXP (i32)-125

/// Maximum possible power of 2 exponent.
///
/// If <i>x</i>&nbsp;=&nbsp;`MAX_EXP`, then normal numbers
/// &lt;&nbsp;1&nbsp;×&nbsp;2<sup><i>x</i></sup>.
#define F32_MAX_EXP (i32)128

/// Minimum <i>x</i> for which 10<sup><i>x</i></sup> is normal.
///
/// Equal to ceil(log<sub>10</sub>&nbsp;`MIN_POSITIVE`).
///
/// 
#define F32_MIN_10_EXP (i32)-37

/// Maximum <i>x</i> for which 10<sup><i>x</i></sup> is normal.
///
/// Equal to floor(log<sub>10</sub>&nbsp;`MAX`).
#define F32_MAX_10_EXP (i32)38

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
#define F32_NAN (f32)0.0F / 0.0F

/// Infinity (∞).
#define F32_INFINITY (f32)1.0F / 0.0F

/// Negative infinity (−∞).
#define F32_NEG_INFINITY (f32)-1.0F / 0.0F

#endif // LIBCORE_PRIMITIVES_F32_H
