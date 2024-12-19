#include "bonus.h"

void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new_elem;

    new_elem = ft_create_elem(data);
    new_elem->next = *begin_list;
    *begin_list = new_elem;
}