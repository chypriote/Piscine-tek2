/*
** func_ptr.h for piscine in /home/temeni_n/rendu/piscine_cpp_d02/ex03
** 
** Made by Nicolas Temenides
** Login   <temeni_n@epitech.net>
** 
** Started on  Thu Jan  9 12:07:32 2014 Nicolas Temenides
** Last update Thu Jan  9 12:44:27 2014 Nicolas Temenides
*/

#include	"func_ptr_enum.h"

#ifndef		FUNC_PTR_H_
#define		FUNC_PTR_H_

typedef	void	(*t_func)(char *str);

typedef	struct	s_action_tab
{
  t_action	action;
  t_func	func;
}		t_action_tab;


void		print_normal(char *str);
void		print_reverse(char *str);
void		print_upper(char *str);
void		print_42(char *str);
void		do_action(t_action action, char *str);

#endif		/* FUNC_PTR_H_ */
