#include	<stdio.h>
#include	<stdlib.h>
#include	"new.h"
#include	"char.h"

typedef	struct
{
  Class base;
  char	c;
}	CharClass;

static	void	Char_ctor(CharClass *self, va_list *args)
{
  self->c = va_arg(*args, int);
}

static	void	Char_dtor(CharClass *self)
{
  (void) self;
}

static	char const *Char_to_string(CharClass *self)
{
  char		*str;

  if (!(str = malloc(sizeof(char) * 2)))
    return NULL;
  str[0] = self->c;
  str[1] = '\0';
  return str;
}

static	CharClass	*Char_add(const CharClass *self, const CharClass *other)
{
  char			c = self->c + other->c;
  CharClass		*res = new(Char, c);
  return res;
}

static	CharClass	*Char_sub(const CharClass *self, const CharClass *other)
{
  char			c = self->c - other->c;
  CharClass		*res = new(Char, c);
  return res;
}

static	CharClass	*Char_mul(const CharClass *self, const CharClass *other)
{
  char			c = self->c * other->c;
  CharClass		*res = new(Char, c);
  return res;
}

static	CharClass	*Char_div(const CharClass *self, const CharClass *other)
{
  char			c = 0;
  
  if (other->c == 0)
   c = self->c / other->c;  
  CharClass		*res = new(Char, c);
  return res;
}

static	bool		Char_eq(const CharClass *self, const CharClass *other)
{
  if (self->c == other->c)
    return 1;
  return 0;
}

static	bool		Char_gt(const CharClass *self, const CharClass *other)
{
  if (self->c > other->c)
    return 1;
  return 0;
}

static	bool		Char_lt(const CharClass *self, const CharClass *other)
{
  if (self->c < other->c)
    return 1;
  return 0;
}

static	CharClass _description = {
  {
    sizeof(CharClass),
    "Char",
    (ctor_t)&Char_ctor,
    (dtor_t)&Char_dtor,
    (to_string_t)&Char_to_string,
    (binary_operator_t)&Char_add,
    (binary_operator_t)&Char_sub,
    (binary_operator_t)&Char_mul,
    (binary_operator_t)&Char_div,
    (binary_comparator_t)&Char_eq,
    (binary_comparator_t)&Char_gt,
    (binary_comparator_t)&Char_lt
  },
  0
};

Class* Char = (Class*) &_description;
