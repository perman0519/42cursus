/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_mid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:43:38 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:15:12 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_mid(t_list **lst, t_list *node)
{
	t_list	*prev;
	t_list	*next;

	prev = node->prev;
	next = node->next;
	if (prev)
		prev->next = next;
	else
		*lst = next;
	if (next)
		next->prev = prev;
	ft_lstdelone(node, free);
}
