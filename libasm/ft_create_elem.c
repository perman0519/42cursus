#include "bonus.h"

t_list *ft_create_elem(void *data) {
    t_list *new_elem = malloc(sizeof(t_list));
    if (new_elem == NULL)
        return (NULL);

    new_elem->data = data;
    new_elem->next = NULL;
    return (new_elem);
}
