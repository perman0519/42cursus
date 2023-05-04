/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:47:49 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 16:52:12 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_list_top(t_list **list, t_list *node)
{
	if (*list == NULL)
	{
		*list = node;
		return (1);
	}
	node ->next = *list;
	node ->prev = (*list)->prev;
	((*list)->prev)->next = node;
	(*list)->prev = node;
	(*list) = node;
	return (1);
}

t_list	*remove_list_top(t_list **list)
{
	t_list	*return_node;

	if (!list)
		return (0);
	return_node = (*list);
	((*list)->next)->prev = (*list)->prev;
	((*list)->prev)->next = (*list)->next;
	if ((*list)->next != *list)
		*list = (*list)->next;
	else
		*list = NULL;
	return_node ->next = return_node;
	return_node ->prev = return_node;
	return (return_node);
}
