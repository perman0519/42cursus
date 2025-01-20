/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:13:28 by junhapar          #+#    #+#             */
/*   Updated: 2024/02/08 11:16:37 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *),
				int type)
{
	t_list	*head;
	t_list	*current_lst;
	void	*content_f;
	t_list	*new_lst;

	if (!(lst) || !(f) || !(del))
		return (0);
	head = 0;
	current_lst = lst;
	while (current_lst)
	{
		content_f = f(current_lst->content);
		new_lst = ft_lstnew(content_f, type);
		if (!(new_lst))
		{
			del(content_f);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new_lst);
		current_lst = current_lst->next;
	}
	return (head);
}
