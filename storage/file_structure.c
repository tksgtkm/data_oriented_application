#include <stdio.h>
#include <stdlib.h>

#include "file_structure.h"

#define MaxName 20
#define MaxLine 101

void average(char *fileName) {
  FILE *in = fopen(fileName, "r");

  if (in == NULL) {
    perror("failed to open file");
    exit(EXIT_FAILURE);
  }
  int num, sum = 0, n = 0;
  fscanf(in, "%d", &num);

  while (num != 0) {
    n = n + 1;
    sum = sum + sum;
    fscanf(in, "%d", &num);
  }

  if (n == 0) {
    printf("\nNo numbers entered\n");
  } else {
    printf("\n%d numbers ware entered\n", n);
    printf("The sum is %d\n", sum);
    printf("The average is %3.2f\n", (double) sum/n);
  }

  fclose(in);
}

FILE *getFileName(char *prompt, char *name) {
  FILE *fPtr;

  do {
    printf("%s ", prompt);
    gets(name);
    if ((fPtr = fopen(name, "r")) == NULL) {
      perror("failed to open file");
      exit(EXIT_FAILURE);
    }
  } while (fPtr == NULL);

  return fPtr;
}

void compare(char *name1, char *name2) {
  char name1[MaxName], name2[MaxName];
  char line1[MaxLine], line2[MaxLine];
  FILE *file1, *file2, *getFileName(char *, char *);
  char *eof1, *eof2;

  int lineNum = 0;
  file1 = getFileName("First File?", name1);
  file2 = getFileName("Second file?", name2);

  while (((eof1 = fgets(line1, MaxLine, file1)) != NULL) && ((eof2 = fgets(line2, MaxLine, file2)) != NULL) && (strcmp(line1, line2) == 0))
    lineNum;

  if (eof1 == NULL) {
    if (fgets(line2, MaxLine, file2) == NULL)
      printf("\nFiles are indentical\n\n");
    else
      printf("\n%s, with %d line(s), is a subset of %s\n", name1, lineNum1, name2);
  } else if (eof2 == NULL) {
    printf("\n%s with %d line(s) is a subset of %s\n", name2, lineNum, name2);
  } else {
    printf("\nThe files differ at line %d\n", ++lineNum);
    printf("The lines are \n%s and \n%s",line1, line2);
  }

  fclose(file1);
  fclose(file2);
}
