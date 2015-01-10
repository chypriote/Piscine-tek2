#include	<stdlib.h>
#include	<stdarg.h>
#include	<string.h>
#include	"raise.h"
#include	"new.h"


Object		*va_new(Class *class, va_list *list)
{
  Object	*new;

  if (!(new = malloc(class->__size__)))
    raise("Malloc fail");
  memcpy(new, class, class->__size__);
  if (class->__init__)
    class->__init__(new, list);
  return new;
}

Object		*new(Class *class, ...)
{
  Object	*new;
  va_list	ap;
  
  va_start(ap, class);
  new = va_new(class, &ap);
  va_end(ap);
  return new;
}

void		delete(Object *ptr)
{
  Class		*tmp;

  tmp = ptr;
  if (tmp->__del__)
    tmp->__del__(ptr);
  //  free(ptr);
}
