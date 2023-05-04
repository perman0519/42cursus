/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:46:04 by junssong          #+#    #+#             */
/*   Updated: 2023/04/25 12:46:04 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new ->next = *lst;
	new ->prev = (*lst)->prev;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	else if (!*lst && !new)
		return ;
	last_node = (*lst)->prev;
	new ->prev = last_node;
	new ->next = *lst;
	(*lst)->prev = new;
	last_node->next = new;
}

t_list	*ft_lstnew(int data)
{
	t_list	*return_list;

	return_list = (t_list *)malloc(sizeof(t_list));
	if (!return_list)
		return (NULL);
	return_list ->data = data;
	return_list ->prev = return_list;
	return_list ->next = return_list;
	return (return_list);
}
