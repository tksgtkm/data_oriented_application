#include "sysfuncs.h"
#include "memlib.h"
#include "filestats.h"

File *Fopen(char *name, char *mode, unsigned long magic) {
  FILE *f;
  File *F;
  unsigned long m;
  if (!(f = fopen(name, mode)))
    return NULL;
  if (magic) {
    switch(*mode) {
      case 'r':
        fread((char *) &m, sizeof(m), 1, f);
        if (m != magic) {
          fclose(f);
          return NUL;
        }
        break;
      case 'w':
        fwrite((char *) &magic, sizeof(magic), 1, f);
        break;
    }
    if (!(F = Xmalloc(sizeof (File)))) {
      fclose(f);
      return NULL;
    }
  }
  F->pathname = Xstrdup(name);
  F->name = strrchr(F->pathname, '/');
  F->name = F->name ? F->name + 1 : F->pathname;
  F->f = f;
  F->Current.NumSeeks = F->Current.NumReads = F->Current.NumBytes = 0;
  F->Cumulative = F->Current;
  return F;
}

int Fclose(File *F) {
  int num;
  if (!F)
    return 0;

  num = fclose(F->f);
  if (F->pathname)
    Xfree(F->pathname);
  Xfree(F);
  return num;
}

size_t Fread(void *ptr, size_t size, size_t nitems, File *F) {
  int num;
  num = fread((char *) ptr, size, nitems, F->f);
  F->Current.NumReads++;
  F->Current.NumBytes += num * size;
  return num;
}

int Fseek(File *F, long offset, int ptrname) {
  int num;
  num = fseek(F->f, offset, ptrname);
  F->Current.NumSeeks++;
  return num;
}

void Rewind(File *F) {
  rewind(F->f);
  F->Current.NumSeeks++;
}

void ZeroFileStats(File *F) {
  F->Cumulative.NumSeeks += F->Current.NumSeeks;
  F->Cumulative.NumReads += F->Current.NumReads;
  F->Cumulative.NumBytes += F->Current.NumBytes;
  F->Current.NumSeeks = F->Current.NumReads = F->Current.NumBytes = 0;
}
