/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:38:12 by junssong          #+#    #+#             */
/*   Updated: 2023/03/24 11:38:13 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_len;
	t_list	*next_lst;

	lst_len = 1;
	next_lst = lst;
	if (!lst)
		return (0);
	while (next_lst->next != NULL)
	{
		next_lst = next_lst->next;
		++lst_len;
	}
	return (lst_len);
}
