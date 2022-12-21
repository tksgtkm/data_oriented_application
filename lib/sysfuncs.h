#ifndef SYSFUNC_H
#define SYSFUNC_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// https://manpages.ubuntu.com/manpages/bionic/ja/man3/alloca.3.html
#ifdef __GNU__
#define alloca __builtin_alloca
#else
#if HAVE_ALLOCA_H
#include <alloca.h>
#endif
#endif

#include <sys/types.h>

#include <stdlib.h>
#include <math.h>

#ifndef log2
#ifndef M_LN2
#define M_LN2 0.69314718055994530942
#endif
#define log2(x) (log(x)/M_LN2)
#endif

// http://www9.plala.or.jp/sgwr-t/lib/setvbuf.html
// f: ファイルポインタ b: バッファの格納先 _IOFBF: バッファリング形式 s: バッファの大きさ
#ifndef HAVE_SETBUFFER
#define setbuffer(f, b, s) setvbuf(f, b, _IOFBF, s)
#endif

#include <assert.h>

#define voidstar void *

#include <ctype.h>

#if STDC_HEADERS
#define ISASCII(Char) 1
#else
#ifdef isascii
#define ISASCII(Char) isascii (Char)
#else
#if HAVE_ISASCII
#define ISASCII(Char) isascii (Char)
#else
#define ISASCII(Char) 1
#endif
#endif
#endif

voidstar xmalloc __P ((size_t));
voidstar xrealloc __P ((voidstar, size_t));
char *xstrdup __P ((const char *));

#endif
