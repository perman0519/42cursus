/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:01:17 by junssong          #+#    #+#             */
/*   Updated: 2023/05/09 11:28:56 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	sort(t_list **list_a, t_list **list_b, int size_a)
{
	if (size_a == 1)
		return ;
	else if (size_a == 2)
		sort_size2(list_a);
	else if (size_a == 3)
		sort_size3(list_a);
	else if (size_a <= 5)
		sort_size5(list_a, list_b, size_a);
	else
		sort_size_more(list_a, list_b, size_a);
}

void	less_3_pb(t_list **list_a, t_list **list_b, int size_a, int min_index)
{
	int	i;

	i = 0;
	min_index = size_a / 3;
	while (size_a > 3)
	{
		if ((*list_a)->data < min_index)
		{
			i++;
			pb(list_a, list_b);
			size_a--;
		}
		else
			ra(list_a);
		if (i == min_index - 1)
			min_index += min_index;
		if (i >= 330)
		{
			while (size_a > 3)
			{
				pb(list_a, list_b);
				size_a--;
			}
		}
	}
}

void	sort_size_more(t_list **list_a, t_list **list_b, int size_a)
{
	int		min_index;

	min_index = 0;
	less_3_pb(list_a, list_b, size_a, min_index);
	size_a = 3;
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
