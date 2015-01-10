#ifndef		VERBOSE_H_
#define		VERBOSE_H_

#include	<cstdio>
#include	<cstdlib>

#define		ON 0

#define		verbose(msg)	\
  do {				\
    if (ON == 1)		\
      fprintf(stdout, "%s\n", msg);		\
  } while (0)

#endif
