/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:41:52 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 11:42:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size2(t_list **list)
{
	if ((*list)->data > (*list)->next ->data)
	{
		sa(list);
	}
}

void	sort_size3(t_list **list)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*list)->data;
	middle = ((*list)->next)->data;
	bottom = ((*list)->prev)->data;
	if (top > middle && top < bottom)
		sa(list);
	else if (top > middle && top > bottom && middle > bottom)
	{
		sa(list);
		rra(list);
	}
	else if (top > middle && top > bottom && middle < bottom)
		ra(list);
	else if (top < middle && top < bottom && middle > bottom)
	{
		sa(list);
		ra(list);
	}
	else if (top < middle && top > bottom && middle > bottom)
		rra(list);
}
