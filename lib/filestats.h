#ifndef FILESTATS_H
#define FILESTATS_H

#include "sysfuncs.h"

typedef struct FileStats {
  unsigned long NumSeeks;
  unsigned long NumReads;
  unsigned long NumBytes;
} FileStats;

typedef struct {
  FILE *f;
  char *pathname;
  FileStats Current;
  FileStats Cumulative;
} FILE;

// magicが0ならば、マジックナンバーは読み書きしない
FILE *Fopen(char *name, char *mode, unsigned long magic);

size_t Fread(void *ptr, size_t size, size_t nitems, File *F);

int Fseek(File *F, long offset, int ptrname);

void Rewind(File *F);

int Fclose(File *F);

#define Getc(F) (F->Current.NumReads++, F->Current.NumBytes++, getc(F->f))

void ZeroFileStats(File *F);

#endif
