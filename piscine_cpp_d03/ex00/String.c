#include	<stdlib.h>
#include	"String.h"

void		StringInit(String *this, char const *s)
{
  this->str = s;
}

void		StringDestroy(String *this)
{
  this->str = NULL;
}
