
#include "../src/alloc/layout.h"
#include <stdio.h>
#include <assert.h>

static usize usize_next_power_of_two(usize x) {
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


int main(int argc,const char** argv) {
  printf("%lu\n", usize_next_power_of_two((1ul<<63)+1));

  return 0;
}




