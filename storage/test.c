#include <stdio.h>
#include <string.h>

#include "file_structure.h"

int main() {

  char fileName[30];

  strcpy(fileName, "../sample/input.txt");

  average(fileName);

  return 0;
}
