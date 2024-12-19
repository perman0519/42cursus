#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

int ft_atoi_base(const char *str, int str_base);
t_list *ft_create_elem(void *data);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
void ft_list_sort(t_list **begin_list, int (*cmp)());
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

