/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:03:45 by junssong          #+#    #+#             */
/*   Updated: 2023/03/24 13:03:46 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now_lst;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		now_lst = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(now_lst, del);
	}
}
