/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:55:55 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:48:31 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_lst;
	t_list	*temp_lst;

	if (*lst == 0 || lst == 0 || del == 0)
		return ;
	else
	{
		current_lst = *lst;
		while (current_lst)
		{
			temp_lst = current_lst->next;
			ft_lstdelone(current_lst, del);
			current_lst = temp_lst;
		}
		*lst = 0;
	}
}
