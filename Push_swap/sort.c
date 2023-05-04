/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:01:17 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 18:48:01 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	sort(t_list **list_a, t_list **list_b, int size_a)
{
	ft_printf("%p\n", list_b);
	if (size_a == 1)
		return ;
	else if (size_a == 2)
		sort_size2(list_a);
	else if (size_a == 3)
		sort_size3(list_a);
	else if (size_a <= 5)
	{
		sort_size5(list_a, list_b, size_a);
	}
	else
	{
		sort_size_more(list_a, list_b, size_a);
	}
}

void	sort_size_more(t_list **list_a, t_list **list_b, int size_a)
{
	t_list	*tmp;
	int		min_index;

	tmp = *list_b;
	min_index = size_a / 2;
	while (size_a > 3)
	{
		pb(list_a, list_b);
		if ((*list_b)->data > min_index)
			rb(list_b);
		size_a--;
	}
	sort_size3(list_a);
	while ((*list_b) != NULL)
	{
		greedy(list_a, list_b, &size_a);
	}
	min_index = index_node(list_a, 0, &size_a);
	while ((*list_a)->data != 0)
	{
		if ((float)min_index < (float)size_a / 2)
			n_ra(list_a, min_index);
		else
			n_rra(list_a, size_a - min_index);
	}
}

void	sort_size5(t_list **list_a, t_list **list_b, int size_a)
{
	t_list	*tmp;
	int		min_index;

	tmp = *list_b;
	while (size_a > 3)
	{
		pb(list_a, list_b);
		size_a--;
	}
	sort_size3(list_a);
	while ((*list_b) != NULL)
	{
		make_pa(list_a, list_b, &size_a);
	}
	min_index = index_node(list_a, 0, &size_a);
	while ((*list_a)->data != 0)
	{
		if ((float)min_index < (float)size_a / 2)
			n_ra(list_a, min_index);
		else
			n_rra(list_a, size_a - min_index);
	}
}

int	make_pa(t_list **list_a, t_list **list_b, int *size_a)
{
	int	list_b_data;

	list_b_data = (*list_b)->data;
	if (is_possible_pa(list_a, list_b_data, size_a))
	{
		pa(list_a, list_b);
		(*size_a)++;
	}
	return (1);
}
