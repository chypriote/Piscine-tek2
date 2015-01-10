#include	<stdio.h>
#include	<stdlib.h>
#include	"int.h"
#include	"new.h"

typedef struct
{
  Class		base;
  int		x;
}		IntClass;

static void	Int_ctor(IntClass *self, va_list *args)
{
  self->x = va_arg(*args, int);
}

static void	Int_dtor(IntClass *self)
{
  (void)self;
}

static char const	*Int_to_string(IntClass *self)
{
  char			*str;

  if ((str = malloc(30)) == NULL)
    return NULL;
  snprintf(str, 30, "%i", self->x);
  return str;
}

Object		*Int_add(const IntClass* self, const IntClass* other)
{
  int		result;
  Object	*add;

  result = self->x + other->x;
  add = new(Int, result);
  return (add);
}

Object		*Int_sub(const IntClass* self, const IntClass* other)
{
  int		result;
  Object	*sub;

  result = self->x - other->x;
  sub = new(Int, result);
  return (sub);
}

Object		*Int_mul(const IntClass* self, const IntClass* other)
{
  int		result;
  Object	*mul;

  result = self->x * other->x;
  mul = new(Int, result);
  return (mul);
}

Object		*Int_div(const IntClass* self, const IntClass* other)
{
  int		result;
  Object	*div;

  if (self->x != 0 && other->x != 0)
    result = self->x / other->x;
  else
    result = 0;
  div = new(Int, result);
  return (div);
}

bool		Int_eq(const IntClass* self, const IntClass* other)
{
  if (self->x == other->x)
    return (true);
  return (false);
}

bool		Int_lt(const IntClass* self, const IntClass* other)
{
  if (self->x < other->x)
    return (true);
  return (false);
}

bool		Int_gt(const IntClass* self, const IntClass* other)
{
  if (self->x > other->x)
    return (true);
  return (false);
}

static IntClass _description = {
  { sizeof(IntClass), "Int",
    (ctor_t)&Int_ctor,
    (dtor_t)&Int_dtor,
    (to_string_t)&Int_to_string,
    (binary_operator_t)&Int_add,
    (binary_operator_t)&Int_sub,
    (binary_operator_t)&Int_mul,
    (binary_operator_t)&Int_div,
    (binary_comparator_t)&Int_eq,
    (binary_comparator_t)&Int_gt,
    (binary_comparator_t)&Int_lt
  },
  0
};

Class* Int = (Class*) &_description;
