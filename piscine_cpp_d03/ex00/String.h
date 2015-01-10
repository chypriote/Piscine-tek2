/*
** String.h for d03 in /home/temeni_n/rendu/piscine_cpp_d03/ex00
** 
** Made by Nicolas Temenides
** Login   <temeni_n@epitech.net>
** 
** Started on  Fri Jan 10 09:43:21 2014 Nicolas Temenides
** Last update Fri Jan 10 10:16:12 2014 Nicolas Temenides
*/

#ifndef		STRING_H_
#define		STRING_H_

typedef	struct	String
{
  const char	*str;

  void		(*assign_s)(struct String *this, struct String const *str);
  void		(*assign_c)(struct String *this, char const *s);
}		String;

void		StringInit(String *this, char const *s);
void		StringDestroy(String *this);

#endif
