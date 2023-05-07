/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:42:02 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 15:05:21 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

t_field *filed_new(int size_a, t_list **list_a, t_list **list_b);

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*tmp;
	int		size_a;

	list_a = 0;
	list_b = 0;
	size_a = parse_argv(argc, &list_a, argv);
	if (!size_a)
		return (0);
	tmp = list_a;
	while (tmp->next != list_a)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->data);
	if(is_sorted(&list_a))
	{
		ft_printf("Yes\n");
		return (0);
	}
	else
		ft_printf("No\n");
	sort(&list_a, &list_b, size_a);
	// tmp = list_a;
	// while (tmp->next != list_a)
	// {
	// 	ft_printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	// ft_printf("%d\n", tmp->data);
	// if(is_sorted(&list_a))
	// 	ft_printf("Yes\n");
	// else
	// 	ft_printf("No\n");
}

// t_field *filed_new(int size_a, t_list **list_a, t_list **list_b)
// {
// 	t_field	*new_filed;

// 	new_filed = (t_field *)malloc(sizeof(t_field));
// 	if (!new_filed)
// 	{
// 		free(list_a); // ㅇㅏㄴ에도 다  지지워워줘줘야야함
// 		return (NULL);
// 	}
// 	new_filed ->size_a = size_a;
// 	new_filed ->top_a = *list_a;
// 	new_filed ->bottom_a = (*list_a)->prev;
// 	new_filed ->top_a = 0;
// 	new_filed ->bottom_b = 0;
// 	new_filed ->size_b = 0;
// 	return (new_filed);
// }

