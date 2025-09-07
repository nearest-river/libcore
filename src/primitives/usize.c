#include "../../prelude.h"

/// Returns true if and only if self == 2^k for some unsigned integer k.
inline_always
bool usize_is_power_of_two(usize x) {
  return x != 0 && (x & (x - 1)) == 0;
}

/// Returns the smallest power of two greater than or equal to self.
///
/// When return value overflows (i.e., self > (1 << (N-1)) for type uN).
/// it panics in debug mode and the return value is wrapped to 0 in release mode
/// (the only situation in which this method can return 0).
inline_always
usize usize_next_power_of_two(usize x) {
  if(x==0) {
    return 1;
  }

  x-= 1;
  x|=x>>1;
  x|=x>>2;
  x|=x>>4;
  x|=x>>8;
  x|=x>>16;
  x|=x>>32;

  #ifdef DEBUG
    assert(x!=USIZE_MAX); 
  #endif

  return x + 1;
}



// pub fn is_power_of_two(x: u64) -> bool {
//    x != 0 && (x & (x - 1)) == 0
//}
