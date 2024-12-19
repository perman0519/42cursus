#include "bonus.h"
#include <string.h>

int cmp(void *data1, void *data2) {
    char *str1 = (char *)data1;
    char *str2 = (char *)data2;
    return strcmp(str1, str2);
}
int main() {
    t_list *list = ft_create_elem("qwer");
    ft_list_push_front(&list, "asdf");
    ft_list_push_front(&list, "second");
    ft_list_push_front(&list, "first");
    ft_list_push_front(&list, "zzzz");
    ft_list_push_front(&list, "bcasd");
    ft_list_push_front(&list, "eeee");

    t_list *tmp = list;
    while (tmp) {
        printf("%s\n", (char *)tmp->data);
        tmp = tmp->next;
    }
    int size = ft_list_size(list);
    printf("size: %d\n", size);
    ft_list_sort(&list, cmp);
    tmp = list;
    while (tmp) {
        printf("%s\n", (char *)tmp->data);
        tmp = tmp->next;
    }
}