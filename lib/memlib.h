#ifndef MEMLIB_H
#define MEMLIB_H

#define STD_MEM

#define Xmalloc malloc
#define Xrealloc realloc
#define Xfree free
#define Xstrdup strdup

#else

#include "sysfuncs.h"

typedef void *(*Malloc_func) (size_t);
typedef void *(*Realloc_func) (void *, size_t);
typedef void *(*Free_func) (void *);
typedef char *(*Strdup_func) (const char *);

extern Malloc_func Xmalloc;
extern Realloc_func Xrealloc;
extern Free_func Xfree;
extern Strdup_func Xstrdup;
#endif

#endif
