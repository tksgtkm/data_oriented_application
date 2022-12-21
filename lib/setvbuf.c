#include <stdio.h>
#include "sysfuncs.h"

int main() {
  char buf[20];
  long l;

  setvbuf(stdout, buf, _IOLBF, sizeof(buf));

  printf("1234567890");

  for (l=0; l<1000000000; l++);

  printf("\n");
}
