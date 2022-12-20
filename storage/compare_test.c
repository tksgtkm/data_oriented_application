#include <stdio.h>
#include "util.h"

#define MaxName 20

int main() {
  char file1[MaxName];
  char file2[MaxName];

  // strcpy(file1, "../sample/file1.txt");
  // strcpy(file2, "../sample/file2.txt");

  compare(file1, file2);

  return 0;
}
