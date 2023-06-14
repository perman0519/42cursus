/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:49:15 by junssong          #+#    #+#             */
/*   Updated: 2023/03/24 11:49:15 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	else if (!*lst && !new)
		return ;
	last_list = ft_lstlast(*lst);
	last_list ->next = new;
}
