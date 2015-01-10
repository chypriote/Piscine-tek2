/*
** add.c for castmania in /home/temeni_n/rendu/piscine_cpp_d02/ex04
** 
** Made by Nicolas Temenides
** Login   <temeni_n@epitech.net>
** 
** Started on  Thu Jan  9 14:52:22 2014 Nicolas Temenides
** Last update Thu Jan  9 14:54:02 2014 Nicolas Temenides
*/

#include	"castmania.h"

#define		ABS(x) ((x) > 0 ? (x) : (-x))

int		normal_add(int a, int b)
{
  return a + b;
}

int		absolute_add(int a, int b)
{
  return ABS(a) + ABS(b);
}

void		exec_add(t_add *operation)
{
  int		a;
  int		b;

  a = operation->add_op.a;
  b = operation->add_op.b;
  if (operation->add_type == NORMAL)
    operation->add_op.res = normal_add(a, b);
  else if (operation->add_type == ABSOLUTE) {
    operation->add_op.res = absolute_add(a, b);
  }
}
