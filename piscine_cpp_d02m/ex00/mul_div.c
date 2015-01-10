void	add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void	add_mul_2param(int *first, int *second)
{
  int	add;
  int	mul;

  add = *first + *second;
  mul = *first * *second;
  *first = add;
  *second = mul;
}
