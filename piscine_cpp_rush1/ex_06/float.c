/*
** float.c for  in /home/gros_j/semestre3/piscine/rush1/ex_04
** 
** Made by jeremy gros
** Login   <gros_j@epitech.net>
** 
** Started on  Sat Jan 11 17:50:14 2014 jeremy gros
** Last update Sat Jan 11 19:30:43 2014 Nicolas Temenides
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "new.h"
#include "float.h"
#include "bool.h"

typedef struct
{
  Class base;
  float x;
}	FloatClass;


static void	Float_ctor(FloatClass *self, va_list *args)
{
  self->x = va_arg(*args, double);
}

static  void    Float_dtor(FloatClass *self)
{
  (void) self;
}

static  char const *Float_to_string(FloatClass *self)
{
  char          *str;

  if (!(str = malloc(30)))
    return NULL;
  memset(str, 0, 30);
  snprintf(str, 30, "%f", self->x);
  return str;
}

static Object *Float_add(const FloatClass *self, const FloatClass *other)
{
  float		x;
  Object	*sum;

  x = self->x + other->x;
  sum = new(Float, x);
  return sum;
}

static Object *Float_sub(const FloatClass *self, const FloatClass *other)
{
  float		x;
  Object	*sum;

  x = self->x - other->x;
  sum = new(Float, x);
  return sum;
}

static Object *Float_mul(const FloatClass *self, const FloatClass *other)
{
  float		x;
  Object	*sum;

  x = self->x * other->x;
  sum = new(Float, x);
  return sum;
}

static Object *Float_div(const FloatClass *self, const FloatClass *other)
{
  float		x;
  Object	*sum;

  x = 0;
  if (other->x != 0)
    x = self->x / other->x;
  sum = new(Float, x);
  return sum;
}

static bool Float_eq(const FloatClass *self, const FloatClass *other)
{
  if(self->x == other->x)
    return (1);
  return (0);
}

static bool Float_lt(const FloatClass *self, const FloatClass *other)
{
  if(self->x < other->x)
    return (1);
  return (0);
}

static bool Float_gt(const FloatClass *self, const FloatClass *other)
{
  if(self->x > other->x)
    return (1);
  return (0);
}

static FloatClass _description ={
  { sizeof(FloatClass),
    "Float",
    (ctor_t)&Float_ctor,
    (dtor_t)&Float_dtor,
    (to_string_t)&Float_to_string,
    (binary_operator_t)&Float_add,
    (binary_operator_t)&Float_sub,
    (binary_operator_t)&Float_mul,
    (binary_operator_t)&Float_div,
    (binary_comparator_t)&Float_eq,
    (binary_comparator_t)&Float_gt,
    (binary_comparator_t)&Float_lt
  },
  0
};

Class * Float = (Class*) &_description;
