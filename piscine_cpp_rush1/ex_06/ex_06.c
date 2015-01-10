#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"
#include "int.h"
#include "new.h"
#include "raise.h"

void		put_in_list(t_list **list, Object *c)
{
  t_list	*tmp;
  t_list	*elem;

  tmp = *list;
  if (!(elem = malloc(sizeof(t_list))))
    raise("Malloc fail");
  elem->data = c;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = elem;
    }
}

int main()
{
    Object* list = new(List, 10, Int, 0);
    Object* it = begin(list);
    Object* it_end = end(list);
    
    printf("list size: %zu\n", len(list));
    setitem(list, 5, 12);
    setitem(list, 6, 13);
    while (lt(it, it_end))
    {
        printf("%s\n", str(getval(it)));
        incr(it);
    }

    delete(it);
    delete(it_end);
    delete(list);
    return 0;
}

