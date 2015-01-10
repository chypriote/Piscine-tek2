/*
** main.c for d03 in /home/temeni_n/rendu/piscine_cpp_d03/ex00
** 
** Made by Nicolas Temenides
** Login   <temeni_n@epitech.net>
** 
** Started on  Fri Jan 10 09:46:36 2014 Nicolas Temenides
** Last update Fri Jan 10 10:09:36 2014 Nicolas Temenides
*/

#include	"String.h"

int		main(void)
{
  String	lapin;

  StringInit(&lapin, "coucou");
  StringDestroy(&lapin);
  return 0;
}
