/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:43:56 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 13:47:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **list_a)
{
	t_list	*tmp;
	int		min_data;

	tmp = *list_a;
	min_data = tmp ->data;
	while (1)
	{
		tmp = tmp ->next;
		if (tmp == *list_a)
			break ;
		if (min_data > tmp->data)
			min_data = tmp->data;
	}
	return (min_data);
}

int	find_max(t_list **list_a)
{
	t_list	*tmp;
	int		max_data;

	tmp = *list_a;
	max_data = tmp ->data;
	while (1)
	{
		tmp = tmp ->next;
		if (tmp == *list_a)
			break ;
		if (max_data < tmp->data)
			max_data = tmp->data;
	}
	return (max_data);
}
