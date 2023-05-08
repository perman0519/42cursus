/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:14:25 by junssong          #+#    #+#             */
/*   Updated: 2023/05/08 17:56:27 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_count(t_list **list);

void	rrr_or_else(t_list **list_a, t_list **list_b,
			int rb_count, int count_ra_rra)
{
	if (-1 * rb_count > -1 * count_ra_rra)
	{
		n_rrr(list_a, list_b, -1 * count_ra_rra);
		n_rrb(list_b, -1 * rb_count - -1 * count_ra_rra);
	}
	else
	{
		n_rrr(list_a, list_b, -1 * rb_count);
		n_rra(list_a, -1 * count_ra_rra - -1 * rb_count);
	}
}

void	rr_or_else(t_list **list_a, t_list **list_b,
			int rb_count, int count_ra_rra)
{
	if (rb_count > count_ra_rra)
	{
		n_rr(list_a, list_b, count_ra_rra);
		n_rb(list_b, rb_count - count_ra_rra);
	}
	else
	{
		n_rr(list_a, list_b, rb_count);
		n_ra(list_a, count_ra_rra - rb_count);
	}
}

int	greedy(t_list **list_a, t_list **list_b, int *size_a)
{
	int	count_ra_rra;
	int	rb_count;
	int	list_b_size;

	list_b_size = stack_count(list_b);
	count_ra_rra = 0;
	rb_count = greedy_pa(list_a, list_b, &count_ra_rra, size_a);
	if (rb_count < 0 && count_ra_rra < 0)
		rrr_or_else(list_a, list_b, rb_count, count_ra_rra);
	else if (rb_count > 0 && count_ra_rra > 0)
		rr_or_else(list_a, list_b, rb_count, count_ra_rra);
	else
	{
		if (rb_count < 0)
			n_rrb(list_b, rb_count * -1);
		else
			n_rb(list_b, rb_count);
		if (count_ra_rra > 0)
			n_ra(list_a, count_ra_rra);
		else
			n_rra(list_a, -1 * count_ra_rra);
	}
	pa(list_a, list_b);
	(*size_a)++;
	return (1);
}

t_field	make_field(t_list **list_a, t_list **list_b,
			int *count_ra_rra, int size_a)
{
	t_field	field;

	field.blist_size = stack_count(list_b);
	field.tmp = *list_b;
	field.i = 0;
	field.flag = 1;
	field.alist_min_data = find_min(list_a);
	field.alist_max_data = find_max(list_a);
	field.blist_data = field.tmp ->data;
	field.find_index = index_node(list_a, field.alist_min_data, &size_a);
	if (field.blist_data > field.alist_min_data
		&& field.blist_data < field.alist_max_data)
		field.find_index = index_node_middle(list_a, field.blist_data, &size_a);
	if ((float)field.find_index < (float)size_a / 2)
	{
		field.rotate_a = field.find_index;
		*count_ra_rra = field.find_index;
	}
	else
	{
		field.rotate_a = size_a - field.find_index;
		*count_ra_rra = field.find_index - size_a;
	}
	field.rotate_b = field.i;
	field.total_count = field.rotate_a;
	return (field);
}

int	greedy_pa(t_list **list_a, t_list **list_b, int *count_ra_rra, int *size_a)
{
	t_field	field;
	int	j;

	field = make_field(list_a, list_b, count_ra_rra, *size_a);


	while (field.i < field.blist_size)
	{
		field.blist_data = field.tmp ->data;
		field.find_index = index_node(list_a, field.alist_min_data, size_a);
		if (field.blist_data > field.alist_min_data && field.blist_data < field.alist_max_data)
			field.find_index = index_node_middle(list_a, field.blist_data, size_a);
		if ((float)field.find_index < (float)(*size_a) / 2)
			field.rotate_a = field.find_index;
		else
			field.rotate_a = (*size_a) - field.find_index;

		if (field.i > field.blist_size / 2)
		{
			field.flag = 0;
			j = field.blist_size - field.i;
		}
		else
			j = field.i;

		if (field.rotate_a + j < field.total_count)
		{
			if (field.flag == 0)
				field.rotate_b = j * -1;
			else
				field.rotate_b = j;
			if ((float)field.find_index < (float)(*size_a) / 2)
				*count_ra_rra = field.find_index;
			else
				*count_ra_rra = field.find_index - (*size_a);
			field.total_count = field.rotate_a + j;
		}
		field.i++;
		field.tmp = field.tmp ->next;
	}
	return (field.rotate_b);
}

int	stack_count(t_list **list)
{
	int		i;
	t_list	*tmp;

	tmp = *list;
	i = 0;
	while (1)
	{
		i++;
		tmp = tmp ->next;
		if (tmp ->next == (*list)->next)
			break ;
	}
	return (i);
}
