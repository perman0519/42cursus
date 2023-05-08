/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:42:15 by junssong          #+#    #+#             */
/*   Updated: 2023/05/08 17:10:25 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_node_middle(t_list **list_a, int list_b_data, int *size_a)
{
	int		i;
	t_list	*tmp;

	tmp = *list_a;
	i = 0;
	while (i < *size_a)
	{
		if (tmp ->data > list_b_data && (tmp ->prev)->data < list_b_data)
			return (i);
		i++;
		tmp = tmp ->next;
	}
	return (-1);
}

int	index_node(t_list **list_a, int min_data, int *size_a)
{
	int		i;
	t_list	*tmp;

	tmp = *list_a;
	i = 0;
	while (i < *size_a)
	{
		if (tmp ->data == min_data)
			return (i);
		i++;
		tmp = tmp ->next;
	}
	return (-1);
}

int	is_possible_pa(t_list **list_a, int list_b_data, int *size_a)
{
	int	min_data;
	int	max_data;
	int	min_index;

	min_data = find_min(list_a);
	max_data = find_max(list_a);
	min_index = index_node(list_a, min_data, size_a);
	if (list_b_data > min_data && list_b_data < max_data)
		min_index = index_node_middle(list_a, list_b_data, size_a);
	if ((float)min_index < (float)(*size_a) / 2)
		n_ra(list_a, min_index);
	else
		n_rra(list_a, *size_a - min_index);
	return (1);
}

void	sort_size5(t_list **list_a, t_list **list_b, int size_a)
{
	int		min_index;

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
