#include <stdio.h>
#include <stdlib.h>
#include "../src/prelude.h"


u32 naive_usize_ctpop(usize x) {
  u32 n=0;
  while(x>0) {
    n+=x&1;
    x>>=1;
  }

  return n;
}

u32 naive_usize_ctlz(usize x) {
  u32 n=0;
  usize mask=~(usize)ISIZE_MAX;

  while((x&mask)==0) {
    n++;
    x<<=1;
  }

  return n;
}


void test_usize_ctpop() {
  printf("test_usize_ctpop:\n");
  for(u32 i=0;i<10;i++) {
    usize x=rand();
    u32 naive=naive_usize_ctpop(x);
    u32 core=usize_count_ones(x);
    printf("x: %lb, naive: %u, core: %u\n",x,naive,core);
    assert(naive==core);
  }

  puts("");
}

void test_usize_ctlz() {
  printf("test_usize_ctlz:\n");
  for(u32 i=0;i<10;i++) {
    usize x=rand();
    u32 naive=naive_usize_ctlz(x);
    u32 core=usize_leading_zeros(x);
    printf("x: %lb, naive: %u, core: %u\n",x,naive,core);
    assert(naive==core);
  }

  puts("");
}



int main(int argc,const char** argv) {
  test_usize_ctpop();
  test_usize_ctlz();
}





