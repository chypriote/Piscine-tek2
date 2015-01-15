#include	"ptr_tricks.h"

int	get_array_nb_elem(int *ptr1, int *ptr2)
{
  int	i;

  i = 0;
  while (ptr1 != ptr2)
    {
      i++;
      ptr1++;
    }
  return i;
}
