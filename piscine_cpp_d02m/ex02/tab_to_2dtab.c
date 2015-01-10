#include	<stdlib.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int	i;
  int	j;

  *res = malloc(sizeof(int *) * length);

  i = 0;
  while (i < length)
    {
      (*res)[i] = malloc(width * sizeof(int));
      j = 0;
      while (j < width)
	{
	  (*res)[i][j] = tab[i * width + j];
	  j++;
	}
      i++;
    }
}
