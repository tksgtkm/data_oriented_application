#include "sysfuncs.h"
#include "memlib.h"

char *my_strdup(const char *str) {
  char *ret_str = malloc(strlen(str) + 1);
  if (ret_str)
    return strcpy(ret_str, str);
  else
    return (char *) 0;
}

Malloc_func Xmalloc = malloc;

Realloc_func Xrealloc = realloc;

Free_func Xfree = free;

Strdup_func Xstrdup = my_strdup;
