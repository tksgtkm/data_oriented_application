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
