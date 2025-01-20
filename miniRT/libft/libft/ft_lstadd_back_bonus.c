/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:30:51 by junhapar          #+#    #+#             */
/*   Updated: 2024/02/16 19:14:10 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_lst;

	if (lst == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		current_lst = *lst;
		while (current_lst->next)
			current_lst = current_lst->next;
		current_lst->next = new;
	}
}
