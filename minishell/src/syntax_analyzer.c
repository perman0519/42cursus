/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:29 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/14 17:28:18 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	identify_token_type(t_list **token_list, t_token **type_list)
{
	char	*word;
	t_list	*iter;
	t_token	*token;

	iter = *token_list;
	while (iter)
	{
		word = ft_strdup(iter->content);
		token = ft_token_new(-1, word);
		if (!ft_strcmp("<", word))
			token->type = LSR;
		else if (!ft_strcmp(">", word))
			token->type = GRT;
		else if (!ft_strcmp("<<", word))
			token->type = D_LSR;
		else if (!ft_strcmp(">>", word))
			token->type = D_GRT;
		else if (!ft_strcmp("|", word))
			token->type = PIPE;
		else
			token->type = WORD;
		ft_tokenadd_back(type_list, token);
		iter = iter->next;
	}
	ft_lstclear(token_list, free);
}

int	syntax_error(t_token **type_list)
{
	t_token	*iter;

	if (!*type_list)
		return (SYNTAX_SUCCESS);
	iter = *type_list;
	if (iter->type == PIPE)
		return (ft_error(type_list, "|"));
	while (iter->next)
	{
		if (iter->type <= D_LSR && iter->next->type != WORD)
			return (ft_error(type_list, iter->next->content));
		if (iter->type == PIPE && iter->next->type == PIPE)
			return (ft_error(type_list, iter->next->content));
		iter = iter->next;
	}
	if (iter->type != WORD)
		return (ft_error(type_list, "newline"));
	return (SYNTAX_SUCCESS);
}

int	ft_error(t_token **type_list, char *content)
{
	ft_putstr_fd(SYNTAX_ERROR_MSG, STDERR_FILENO);
	ft_putstr_fd("`", STDERR_FILENO);
	ft_putstr_fd(content, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	ft_tokenclear(type_list, free);
	g_exit_code = SYNTAX_ERROR;
	return (SYNTAX_ERROR);
}
