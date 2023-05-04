/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:14:25 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 19:10:05 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greedy(t_list **list_a, t_list **list_b, int *size_a)
{
	int	count_ra_rra;
	int	rb_count;

	count_ra_rra = 0;
	rb_count = greedy_pa(list_a, list_b, &count_ra_rra, size_a);
	if (count_ra_rra > 0)
		n_ra(list_a, count_ra_rra);
	else
		n_rra(list_a, -1 * count_ra_rra);
	pa(list_a, list_b);
	(*size_a)++;
	return (1);
}

int	greedy_pa(t_list **list_a, t_list **list_b, int *count_ra_rra, int *size_a)
{
	int	min_data;
	int	max_data;
	int	min_index;
	int	total_count;
	int	i;
	int	rotate_a;
	int	b_index;
	int	list_b_data;
	t_list *tmp;

	tmp = *list_b;
	i = 0;
	min_data = find_min(list_a);
	max_data = find_max(list_a);
	b_index = i;
	while (1)
	{
		list_b_data = tmp ->data;
		min_index = index_node(list_a, min_data, size_a);
		if (list_b_data > min_data && list_b_data < max_data)
			min_index = index_node_middle(list_a, list_b_data, size_a);
		if ((float)min_index < (float)(*size_a) / 2)
			rotate_a = min_index;
		else
			rotate_a = (*size_a) - min_index;
		i++;
		if ()
		tmp = tmp ->next;
		if (tmp ->next == (*list_b)->next)
			break ;
	}
	return (b_index);
}
