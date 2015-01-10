/*
** menger.c for menger in /home/temeni_n/rendu/piscine_cpp_d01/ex01
** 
** Made by Nicolas Temenides
** Login   <temeni_n@epitech.net>
** 
** Started on  Wed Jan  8 15:16:09 2014 Nicolas Temenides
** Last update Wed Jan  8 21:15:15 2014 Nicolas Temenides
*/

#include	<stdio.h>

void		print_square(int size, int x, int y)
{
  printf("%03d %03d %03d\n", size, x, y);
}

void		next_square(int size, int level, int posx, int posy)
{
  int		div;

  if (!(size % 3) && (level > 0) && (level < size))
    {
      div = size / 3;
      print_square(div, div + posx, div + posy);
      level--;
      next_square(div, level, posx, posy);
      next_square(div, level, posx, posy + div);
      next_square(div, level, posx, posy + 2 * div);
      next_square(div, level, posx + div, posy);
      next_square(div, level, posx + div, posy + 2 * div);
      next_square(div, level, posx + 2 * div, posy);
      next_square(div, level, posx + 2 * div, posy + div);
      next_square(div, level, posx + 2 * div, posy + 2 * div);
    }
}

void		menger(int size, int level)
{
  if (level < size)
    next_square(size, level, 0, 0);
}
