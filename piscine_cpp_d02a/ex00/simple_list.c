#include	<stdlib.h>
#include	<stdio.h>
#include	"simple_list.h"

// Informative

unsigned int	list_get_size(t_list list)
{
  unsigned int	i;

  i = 0;
  while (list)
    {
      i++;
      list = list->next;
    }
  return i;
}

t_bool		list_is_empty(t_list list)
{
  if (list)
    return FALSE;
  return TRUE;
}

void		list_dump(t_list list)
{
  while (list)
    {
      printf("%f\n", list->value);
      list = list->next;
    }
}

// Modification

t_node		*list_create_node(double elem)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  node->value = elem;
  node->next = NULL;
  return node;
}

t_bool		list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_node	*new;

  new = list_create_node(elem);
  if (!new)
    return FALSE;
  new->next = *front_ptr;
  *front_ptr = new;
  return TRUE;
}

t_bool		list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_list	list;
  t_node	*new;

  list = *front_ptr;
  new = list_create_node(elem);
  if (!new)
    return FALSE;
  if (!list)
    *front_ptr = new;
  else
    {
      list = *front_ptr;
      while (list->next)
	list = list->next;
      list->next = new;
    }
  return TRUE;
}

t_bool		list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{
  t_list	list;
  t_node	*node;

  if (position == 0)
    return list_add_elem_at_front(front_ptr, elem);
  if (!*front_ptr)
    return FALSE;
  list = *front_ptr;
  node = list_create_node(elem);
  if (!node)
    return FALSE;
  while (position != 0)
    {
      list = list->next;
      if (!list)
	return FALSE;
      position--;
    }
  node->next = list->next;
  list->next = node;
  return TRUE;
}

t_bool		list_del_elem_at_front(t_list *front_ptr)
{
  t_list	list;

  list = *front_ptr;
  if (!list)
    return FALSE;
  *front_ptr = list->next;
  free(list);
  return TRUE;
}

t_bool		list_del_elem_at_back(t_list *front_ptr)
{
  t_list	list;
  t_list	prev;

  list = *front_ptr;
  prev = NULL;
  if (!list)
    return FALSE;
  while (list->next)
    {
      prev = list;
      list = list->next;
    }
  if (prev)
    prev->next = NULL;
  else
    *front_ptr = NULL;
  free(list);
  return TRUE;
}

t_bool		list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list	list;
  t_list	prev;

  if (position == 0)
    return list_del_elem_at_front(front_ptr);
  if (!*front_ptr)
    return FALSE;
  prev = *front_ptr;
  list = prev->next;
  while (position != 0)
    {
      if (!list)
	return FALSE;
      prev = list;
      list = list->next;
      position--;
    }
  if (list)
    prev->next = list->next;
  free(list);
  return TRUE;
}

// Value Access

double		list_get_elem_at_front(t_list list)
{
  if (!list)
    return 0;
  return list->value;
}

double		list_get_elem_at_back(t_list list)
{
  if (!list)
    return 0;
  while (list->next)
    list = list->next;
  return list->value;
}

double		list_get_elem_at_position(t_list list, unsigned int position)
{
  if (!list)
    return 0;
  while (position != 0)
    {
      list = list->next;
      if (!list)
	return 0;
      position--;
    }
  return list->value;
}

//	Access

t_node		*list_get_first_node_with_value(t_list list, double value)
{
  while (list)
    {
      if (list->value == value)
	return list;
      list = list->next;
    }
  return NULL;
}	
