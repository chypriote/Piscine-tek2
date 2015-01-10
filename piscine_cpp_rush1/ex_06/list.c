#include	<stdlib.h>
#include	<stdarg.h>
#include	"raise.h"
#include	"list.h"
#include	"new.h"

typedef	struct	ListClass_s {
  Container	base;
  Class*	_type;
  size_t	_size;
  t_list	*_list;
}		ListClass;

typedef	struct		{
  Iterator	base;
  ListClass	*_list;
  size_t	_idx;
}		ListIteratorClass;

void		ListIterator_ctor(ListIteratorClass* self, va_list* args)
{
  self->_list = va_arg(*args, ListClass *);
  self->_idx = va_arg(*args, int);
}

bool		ListIterator_eq(ListIteratorClass* self, ListIteratorClass* other)
{
  if ((self->_list == other->_list) && (self->_idx == other->_idx))
    return 1;
  return 0;
}

bool		ListIterator_gt(ListIteratorClass* self, ListIteratorClass* other)
{
  if ((self->_list == other->_list) && (self->_idx > other->_idx))
    return 1;
  return 0;				     
}

bool		ListIterator_lt(ListIteratorClass* self, ListIteratorClass* other)
{
  if ((self->_list == other->_list) && (self->_idx < other->_idx))
    return 1;
  return 0;
}

void		ListIterator_incr(ListIteratorClass* self)
{
  self->_idx++;
}

Object		*ListIterator_getval(ListIteratorClass* self)
{
  return (*((Container *) self->_list)->__getitem__)((Container *) self->_list, self->_idx);
}

void		ListIterator_setval(ListIteratorClass* self, ...)
{
  va_list	ap;
  int		size;
  t_list	*list;

  va_start(ap, self);
  size = self->_idx;
  if (size >= 0 && size < (int) self->_list->_size)
    {
      list =  self->_list->_list;
      while (size > 0)
	{
	  list = list->next;
	  size--;
	}
      delete((Object *) list->data);
      list->data = va_new(self->_list->_type, &ap);
    }
  va_end(ap);
}

static	ListIteratorClass	ListIteratorDescr = {
  {
    {
      sizeof (ListIteratorClass), "ListIterator",
      (ctor_t) & ListIterator_ctor,
      NULL, /* dtor */
      NULL, /* str */
      NULL, NULL, NULL, NULL, /* add, sub, mul, div */
      (binary_comparator_t) & ListIterator_eq,
      (binary_comparator_t) & ListIterator_gt,
      (binary_comparator_t) & ListIterator_lt,
    },
    (incr_t) &ListIterator_incr,
    (getval_t) & ListIterator_getval,
    (setval_t) & ListIterator_setval,
  },
  NULL,
  0
};

static	Class*	ListIterator = (Class*) & ListIteratorDescr;

void		List_ctor(ListClass* self, va_list* args)
{
  size_t size;
  va_list cpy;
  
  self->_size = va_arg(*args, int);
  self->_type = va_arg(*args, Class *);
  size = self->_size;
  self->_list = NULL;
  while (size > 0)
    {
      va_copy(cpy, *args);
      put_in_list(&self->_list, va_new(self->_type, &cpy));
      va_end(cpy);
      size--;
    }
}

void		List_dtor(ListClass* self)
{
  t_list *list;
  t_list *del;

  list = self->_list;
  while (list)
    {
      del = list;
      list = list->next;
      delete((Object *) del->data);
      free(del);
    }
}

size_t		List_len(ListClass* self)
{
  return self->_size;
}

Iterator*	List_begin(ListClass* self)
{
  return new(ListIterator, self, 0);
}

Iterator*	List_end(ListClass* self)
{
  return new(ListIterator, self, self->_size - 1);
}

Object*		List_getitem(ListClass* self, ...)
{
  va_list	ap;
  int		size;
  t_list	*list;

  va_start(ap, self);
  size = va_arg(ap, int);
  va_end(ap);
  if (size >= 0 && size < (int) self->_size) {
    list = self->_list;
    while (size > 0)
      {
	list = list->next;
	size--;
      }
    return (Object *) list->data;
  }
  return NULL;
}

void		List_setitem(ListClass* self, ...)
{
  va_list	ap;
  int		size;
  t_list	*list;

  va_start(ap, self);
  size = va_arg(ap, int);
  if (size > 0 && size < (int) self->_size)
    {
      list = self->_list;
      while (size > 0 && list->next)
	{
	  list = list->next;
	  size--;
	}
      delete((Object *) list->data);
      list->data = va_new(self->_type, &ap);
    }
  va_end(ap);
}

static	ListClass _descr = {
  { /* Container */
    { /* Class */
      sizeof (ListClass), "List",
      (ctor_t) & List_ctor, (dtor_t) & List_dtor,
      NULL, /*str */
      NULL, NULL, NULL, NULL, /* add, sub, mul, div */
      NULL, NULL, NULL, /* eq, gt, lt */
    },
    (len_t) &List_len,
    (iter_t) & List_begin,
    (iter_t) & List_end,
    (getitem_t) & List_getitem,
    (setitem_t) & List_setitem,
  },
  NULL, 0, NULL
};

Class*	List = (Class*) & _descr;
