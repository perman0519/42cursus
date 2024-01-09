/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:51:25 by junssong          #+#    #+#             */
/*   Updated: 2023/03/24 13:51:26 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*return_lst;
	t_list	*next_lst;
	void	*f_value;

	if (!lst || !f || !del)
		return (NULL);
	return_lst = NULL;
	while (lst)
	{
		f_value = f(lst->content);
		next_lst = ft_lstnew(f_value);
		if (!next_lst)
		{
			ft_lstclear(&return_lst, del);
			del(f_value);
			return (NULL);
		}
		ft_lstadd_back(&return_lst, next_lst);
		lst = lst->next;
	}
	return (return_lst);
}
