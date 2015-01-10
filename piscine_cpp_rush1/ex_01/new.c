#include	<stdlib.h>
#include	<string.h>
#include	"raise.h"
#include	"new.h"

void		*new(Class *class)
{
  Object	*new;

  if (!(new = malloc(class->__size__)))
    raise("Malloc fail");
  memcpy(new, class, class->__size__);
  if (class->__init__)
    class->__init__(new);
  return (new);
  
}

void		delete(Object *ptr)
{
  Class		*tmp;

  tmp = ptr;
  if (tmp->__del__)
    tmp->__del__(ptr);
  free(ptr);
}
