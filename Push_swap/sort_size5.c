/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:42:15 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 17:52:25 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ra_min_max(t_list **list_a, int min_data, int max_data)
{
	if ((*list_a)->data == min_data && ((*list_a)->prev)->data == max_data)
		return (1);
	return (0);
}

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
