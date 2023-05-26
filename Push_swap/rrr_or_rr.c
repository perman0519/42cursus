/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_or_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:23:07 by junssong          #+#    #+#             */
/*   Updated: 2023/05/09 10:24:42 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
