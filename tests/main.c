#include <stdint.h>
#include <stdio.h>
#include "../src/prelude.h"








/* _Static_assert(false,"invalid monomorphization of `ctlz` intrinsic: expected basic integer type"); \
*/

int main(int argc,const char** argv) {
  char c='a';

  printf("%u\n",intrinsic_ctpop(c));


  return 0;
}




