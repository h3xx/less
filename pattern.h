/*@@copyright@@*/

#if HAVE_GNU_REGEX
#define __USE_GNU 1
#include <regex.h>
#define PATTERN_TYPE          struct re_pattern_buffer *
#define CLEAR_PATTERN(name)   name = NULL
#endif

#if HAVE_POSIX_REGCOMP
#include <regex.h>
#ifdef REG_EXTENDED
#define REGCOMP_FLAG    REG_EXTENDED
#else
#define REGCOMP_FLAG    0
#endif
#define PATTERN_TYPE          regex_t *
#define CLEAR_PATTERN(name)   name = NULL
#endif

#if HAVE_PCRE
#include <pcre.h>
#define PATTERN_TYPE          pcre *
#define CLEAR_PATTERN(name)   name = NULL
#endif

#if HAVE_RE_COMP
char *re_comp();
int re_exec();
#define PATTERN_TYPE          int
#define CLEAR_PATTERN(name)   name = 0
#endif

#if HAVE_REGCMP
char *regcmp();
char *regex();
extern char *__loc1;
#define PATTERN_TYPE          char **
#define CLEAR_PATTERN(name)   name = NULL
#endif

#if HAVE_V8_REGCOMP
#include "regexp.h"
extern int reg_show_error;
#define PATTERN_TYPE          struct regexp *
#define CLEAR_PATTERN(name)   name = NULL
#endif

#if NO_REGEX
#define PATTERN_TYPE          void *
#define CLEAR_PATTERN(name)   
#endif
