#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"func_ptr.h"

void		print_normal(char *str)
{
  printf("%s\n", str);
}

void		print_reverse(char *str)
{
  int		i;

  i = strlen(str) - 1;
  while (i >= 0)
    printf("%c", str[i--]);
  printf("\n");
}

void		print_upper(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	printf("%c", str[i] - 32);
      else
	printf("%c", str[i]);
      i++;
    }
  printf("\n");
}

void		print_42(char *str)
{
  char	*coucou=str;

  str = coucou;
  printf("42\n");
}

void		do_action(t_action action, char *str)
{
  int		i;
  t_action_tab	tab[]=
    {
      {PRINT_NORMAL, &print_normal},
      {PRINT_REVERSE, &print_reverse},
      {PRINT_UPPER, &print_upper},
      {PRINT_42, &print_42}
    };
  
  i = 0;
  while (i < 4)
    {
      if (action == tab[i].action)
	(*tab[i].func)(str);
      i++;
    }
}
