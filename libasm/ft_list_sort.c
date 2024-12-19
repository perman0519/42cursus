#include "bonus.h"

void ft_list_sort(t_list **begin_list, int (*cmp)()) {
    t_list *tmp;
    t_list *tmp2;
    void *tmp_data;
    tmp = *begin_list;
    while (tmp) {
        tmp2 = tmp->next;
        while (tmp2) {
            // if (1) {
            if (cmp(tmp->data, tmp2->data) > 0) {
                void *tmp_data = tmp->data;
                tmp->data = tmp2->data;
                tmp2->data = tmp_data;
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}