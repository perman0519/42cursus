/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:54:28 by junssong          #+#    #+#             */
/*   Updated: 2023/05/10 16:55:56 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	sa(t_list **list_a)
{
	t_list	*tmp;
	t_list	*last_node;

	if (((*list_a)->next)->next == *list_a)
	{
		*list_a = (*list_a)->next;
		ft_printf("sa\n");
		return ;
	}
	last_node = (*list_a)->prev;
	if ((*list_a) == NULL || (*list_a)->next == (*list_a))
		return ;
	tmp = (*list_a)->next;
	(tmp ->next)->prev = *list_a;
	(*list_a)->next = tmp ->next;
	(*list_a)->prev = tmp;
	tmp ->prev = last_node;
	tmp ->next = *list_a;
	last_node ->next = tmp;
	*list_a = tmp;
	ft_printf("sa\n");
}
