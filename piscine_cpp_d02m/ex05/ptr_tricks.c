/*
** ptr.tricks.c for ptr_tricks in /home/temeni_n/rendu/piscine_cpp_d02/ex05
** 
** Made by Nicolas Temenides
** Login   <temeni_n@epitech.net>
** 
** Started on  Thu Jan  9 16:29:15 2014 Nicolas Temenides
** Last update Thu Jan  9 16:50:09 2014 Nicolas Temenides
*/

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
