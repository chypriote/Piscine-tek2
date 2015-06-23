#include	<stdio.h>
#include	<stdlib.h>

int	menger(int size, int level);

int	power(int nb, int pui)
{
  if (pui == 0)
    return 0;
  else if (pui > 1)
    nb = nb * power(nb, pui - 1);
  return nb;
}

int	getnbr(char *str)
{
  int	nb;

  nb = 0;
  while (*str >= '0' && *str <= '9')
    nb = (nb * 10) + (*str++ - 48);
  return nb;
}

int	check_menger(char *str1, char *str2)
{
  int	nb1;
  int	nb2;
  int	i;

  nb1 = getnbr(str1);
  nb2 = getnbr(str2);
  if (nb1 < nb2)
    {
      printf("Depth must be inferior to size\n");
      return 0;
    }
  if (nb1 % 3 != 0)
    {
      printf("Depth must be a power of 3\n");
      return 0;
    }
  i = 0;
  while (power(3, i) != nb1)
    i++;
  if (nb2 > i)
    {
      printf("Depth must be inferior to the size's power of 3\n");
      return 0;
    }
  return 1;
}

int	main(int ac, char **av)
{
  if (ac != 3)
    printf("Usage: ./menger size depth\n");
  else if (check_menger(av[1], av[2]))
    {
      if (getnbr(av[2]) == 1)
	printf("%03d %03d %03d\n", getnbr(av[1]) / 3, getnbr(av[1]) / 3, getnbr(av[1]) / 3);
      else
	menger(getnbr(av[1]), getnbr(av[2]));
    }
  return (0);
}
