#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"mem_ptr.h"

void	add_str(char *str1, char *str2, char **res)
{
  int	i = 0;
  char	*rest;

  if ((rest = malloc(sizeof(strlen(str1) + strlen(str2) + 1))) != NULL)
    {
      while (*str1)
	{
	  rest[i] = *str1++;
	  i++;
	}
      while (*str2)
	{
	  rest[i] = *str2++;
	  i++;
	}
      rest[i] = '\0';
      *res = rest;
    }
}

void	add_str_struct(t_str_op *str_op)
{
  add_str(str_op->str1, str_op->str2, &str_op->res);
}
