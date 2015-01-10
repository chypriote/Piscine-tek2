#ifndef	LIST_H_
#define	LIST_H_

#include	"container.h"

extern	Class*	List;

typedef	struct	s_list
{
  Object	*data;
  struct s_list	*next;
}		t_list;

void	put_in_list(t_list **, Object *);

#endif
