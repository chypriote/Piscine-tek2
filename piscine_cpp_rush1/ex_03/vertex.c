#include	<stdio.h>
#include	<stdlib.h>
#include	"new.h"
#include	"vertex.h"

typedef	struct
{
  Class	base;
  int	x, y, z;
}	VertexClass;

static	void	Vertex_ctor(VertexClass *self, va_list *args)
{
  self->x = va_arg(*args, int);
  self->y = va_arg(*args, int);
  self->z = va_arg(*args, int);
}

static	void	Vertex_dtor(VertexClass *self)
{
  (void) self;
}

static	char const *Vertex_to_string(VertexClass *self)
{
  char		*str;

  str = malloc(sizeof(char) * 255);
  snprintf(str, 255, "<Vertex (%i, %i, %i)>", self->x, self->y, self->z);
  return str;
}

static	Object	*Vertex_add(const VertexClass *self, const VertexClass *other)
{
  int		x, y, z;
  Object	*sum;

  x = self->x + other->x;
  y = self->y + other->y;
  z = self->z + other->z;
  sum = new(Vertex, x, y, z);
  return sum;
}

static	Object	*Vertex_sub(const VertexClass *self, const VertexClass *other)
{
  int		x, y, z;
  Object	*sum;

  x = self->x - other->x;
  y = self->y - other->y;
  z = self->z - other->z;
  sum = new(Vertex, x, y, z);
  return sum;
}

static	VertexClass _description = {
  { sizeof(VertexClass), "Vertex", (ctor_t)&Vertex_ctor, (dtor_t)&Vertex_dtor, (to_string_t)&Vertex_to_string, (binary_operator_t)&Vertex_add, (binary_operator_t)&Vertex_sub },
  0, 0, 0
};

Class* Vertex = (Class*) &_description;
