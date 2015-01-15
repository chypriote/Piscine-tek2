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
