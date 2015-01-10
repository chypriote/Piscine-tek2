#include	<stdio.h>
#include	<stdlib.h>
#include	"point.h"

typedef	struct
{
  Class	base;
  int	x, y;
}	PointClass;

static void Point_ctor(PointClass* self, va_list *args)
{
  self->x = va_arg(*args, int);
  self->y = va_arg(*args, int);
}

static	void	Point_dtor(PointClass *self)
{
  (void) self;
}

static	char const *Point_to_string(PointClass *self)
{
  char		*str;

  str = malloc(sizeof(char) * 255);
  snprintf(str, 255, "<Point (%i, %i)>", self->x, self->y);
  return str;
}

static	PointClass _description = {
  { sizeof(PointClass), "Point", (ctor_t)&Point_ctor, (dtor_t)&Point_dtor, (to_string_t)&Point_to_string },
  0, 0
};

Class* Point = (Class*) &_description;
