/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:40 by junssong          #+#    #+#             */
/*   Updated: 2023/04/28 11:20:41 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	intcmp(int a, int b);

int	is_sorted(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp ->next != *list)
	{
		if (intcmp(tmp ->data, (tmp ->next)->data) > 0)
			return (0);
		tmp = tmp ->next;
	}
	return (1);
}

int	intcmp(int a, int b)
{
	if (a > b)
		return (1);
	else if (a < b)
		return (-1);
	else
		return (0);
}
