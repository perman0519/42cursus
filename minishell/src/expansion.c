/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:48:26 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 15:01:57 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_delim(char c)
{
	return (c == '$' || c == '\'' || c == '\"');
}

char	*ft_lst_strjoin(t_list **lst)
{
	t_list	*iter;
	char	*res;
	char	*tmp;

	res = ft_strdup((char *)(*lst)->content);
	iter = (*lst)->next;
	tmp = 0;
	while (iter)
	{
		tmp = res;
		res = ft_strjoin(res, iter->content);
		free(tmp);
		iter = iter->next;
	}
	return (res);
}

void	expansion(t_list *node, char *content, int *idx, t_list **environ)
{
	t_vars	vars;
	t_list	*lst;

	init_vars(&vars);
	lst = NULL;
	while (content[vars.i])
	{
		vars.size = 0;
		if (content[vars.i + vars.size] == '$' && vars.q_flag != '\'')
			expand_key(content, &vars, environ);
		else if (content[vars.i + vars.size] == '\''
			|| content[vars.i + vars.size] == '\"')
			check_quote(&vars, content[vars.i + vars.size]);
		else
			sub_key(content, &vars);
		ft_lstadd_back(&lst, ft_lstnew(vars.str));
	}
	*idx = vars.i;
	free(node->content);
	node->content = ft_lst_strjoin(&lst);
	ft_lstclear(&lst, free);
}

void	delete_empty_node(t_list **token_list)
{
	t_list	*iter;

	iter = *token_list;
	while (iter)
	{
		if (ft_strlen(iter->content) == 0)
			ft_lstdel_mid(token_list, iter);
		iter = iter->next;
	}
}

void	expand_env(t_list **token_list, t_list **environ)
{
	t_list	*iter;
	t_list	*next_head;
	char	*tmp;
	int		exp_flag;

	iter = *token_list;
	while (iter)
	{
		exp_flag = 0;
		tmp = (char *)iter->content;
		if (iter->prev && !ft_strcmp("<<", iter->prev->content))
		{
			iter = iter->next;
			if (!iter)
				break ;
		}
		next_head = iter->next;
		if (ft_strchr(tmp, '$'))
			search_exp(iter, *environ, &exp_flag, 0);
		iter = iter->next;
		if (exp_flag && iter != NULL)
			delete_double(token_list, &iter, &next_head);
	}
	delete_empty_node(token_list);
}
