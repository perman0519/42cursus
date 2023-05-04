/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:36:44 by junssong          #+#    #+#             */
/*   Updated: 2023/04/25 17:36:44 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **list_b)
{
	t_list	*tmp;
	t_list	*last_node;

	last_node = (*list_b)->prev;
	if ((*list_b) == NULL || (*list_b)->next == (*list_b))
		return ;
	tmp = (*list_b)->next;
	(*list_b)->next = tmp ->next;
	(*list_b)->prev = tmp;
	tmp ->prev = last_node;
	tmp ->next = *list_b;
	last_node ->next = tmp;
	*list_b = tmp;
}
