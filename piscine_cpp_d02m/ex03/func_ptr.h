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
