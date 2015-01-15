#include	<stdio.h>
#include	<stdlib.h>

int	follow_the_white_rabbit(void)
{
  int	result;
  int	dice;

  result = 0;
  while (result < 397)
    {
      dice = random() % 37;
      dice++;
      result = result + dice;
      if (dice == 37 || dice == 1)
	{
	  printf("LAPIN !!!\n");
	  return result;
	}
      else if (dice == 6 || dice == 17 || dice == 28 || dice == 4 || dice == 5 || dice == 20 || dice == 21 || dice == 19 || dice == 19)
	printf("gauche\n");
      else if (dice == 13|| (dice >= 34 && dice < 37))
	printf("droite\n");
      else if (dice == 10 || dice == 15 || dice == 23)
	printf("devant\n");
      else if (dice == 8 || dice == 16 || dice == 24 || dice == 26 || dice == 32)
	printf("derriere\n");
    }
  printf("LAPIN !!!\n");
  return result;;
}
