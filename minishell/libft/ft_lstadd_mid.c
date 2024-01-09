/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_mid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:42:50 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:15:07 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_mid(t_list *target_node, t_list **new_lst)
{
	t_list	*tmp;
	t_list	*target_next;
	t_list	*cpy_lst;
	t_list	*last;

	if (!*new_lst)
		return ;
	tmp = *new_lst;
	cpy_lst = NULL;
	while (tmp)
	{
		ft_lstadd_back(&cpy_lst, ft_lstnew(ft_strdup(tmp->content)));
		tmp = tmp->next;
	}
	target_next = target_node->next;
	target_node->next = cpy_lst;
	cpy_lst->prev = target_node;
	last = ft_lstlast(cpy_lst);
	last->next = target_next;
	if (target_next)
		target_next->prev = last;
}
