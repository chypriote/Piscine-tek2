/*
** pyramid.c for pyramid in /home/temeni_n/rendu/piscine_cpp_d01/ex05
** 
** Made by Nicolas Temenides
** Login   <temeni_n@epitech.net>
** 
** Started on  Thu Jan  9 09:12:05 2014 Nicolas Temenides
** Last update Thu Jan  9 09:31:34 2014 Nicolas Temenides
*/

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int	pyramid(int size, int **map, int current, int pos)
{
  if (current == size - 1)
    {
      return MIN(map[current][pos], map[current][pos + 1]);
    }
  return MIN(pyramid(size, map, current + 1, pos), pyramid(size, map, current + 1, pos + 1)) + map[current][pos];
}

int	pyramid_path(int size, int **map)
{
  return pyramid(size, map, 0, 0);
}
