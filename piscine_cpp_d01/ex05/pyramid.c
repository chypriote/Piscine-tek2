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
