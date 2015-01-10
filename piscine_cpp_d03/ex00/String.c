/*
** String.c for d03 in /home/temeni_n/rendu/piscine_cpp_d03/ex00
** 
** Made by Nicolas Temenides
** Login   <temeni_n@epitech.net>
** 
** Started on  Fri Jan 10 08:14:26 2014 Nicolas Temenides
** Last update Fri Jan 10 10:37:31 2014 Nicolas Temenides
*/

#include	<stdlib.h>
#include	"String.h"

void		StringInit(String *this, char const *s)
{
  this->str = s;
}

void		StringDestroy(String *this)
{
  this->str = NULL;
}
