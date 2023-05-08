/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:42:02 by junssong          #+#    #+#             */
/*   Updated: 2023/05/08 17:00:57 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

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
	tmp = list_a;
	while (tmp->next != list_a)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->data);
	if(is_sorted(&list_a))
		ft_printf("Yes\n");
	else
		ft_printf("No\n");
}
