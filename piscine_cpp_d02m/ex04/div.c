/*
** div.c for div in /home/temeni_n/rendu/piscine_cpp_d02/ex04
** 
** Made by Nicolas Temenides
** Login   <temeni_n@epitech.net>
** 
** Started on  Thu Jan  9 12:57:09 2014 Nicolas Temenides
** Last update Thu Jan  9 15:06:35 2014 Nicolas Temenides
*/

#include	"castmania.h"

int	integer_div(int a, int b)
{
  if (b != 0)
    return (a / b);
  return b;
}

float	decimale_div(int a, int b)
{
  if (b != 0)
    return ((float)a / b);
  return b;
}

void	exec_div(t_div *operation)
{
  int	a;
  int	b;

  a = ((t_integer_op *) operation->div_op)->a;
  b = ((t_integer_op *) operation->div_op)->b;
  if(operation->div_type == INTEGER)
    ((t_integer_op *) operation->div_op)->res = integer_div(a, b);

  else if(operation->div_type == DECIMALE)
    ((t_decimale_op *) operation->div_op)->res = decimale_div(a, b);         
}
