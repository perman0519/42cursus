/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:40 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 16:46:51 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokenadd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_tokendelone(t_token *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_tokendel_mid(t_token **lst, t_token *node)
{
	t_token	*prev;
	t_token	*next;

	prev = node->prev;
	next = node->next;
	if (prev)
		prev->next = next;
	else
		*lst = next;
	if (next)
		next->prev = prev;
	ft_tokendelone(node, free);
}

void	ft_tokenclear(t_token **lst, void (*del)(void *))
{
	t_token	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		del((*lst)->content);
		del((*lst)->temp);
		*lst = tmp->next;
		free(tmp);
	}
	lst = NULL;
}

void	ft_tokeniter(t_token *lst, void (*f)(t_token *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
