/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:24 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/14 20:26:37 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_type(t_token **type_list, t_token *node)
{
	char	*tmp;

	tmp = node->content;
	node->content = ft_strdup(node->next->content);
	free(tmp);
	ft_tokendel_mid(type_list, node->next);
}

char	**make_simple_cmd(t_token *word_list)
{
	t_token	*iter;
	char	**ret;
	int		size;

	iter = word_list;
	size = 0;
	while (iter)
	{
		size++;
		iter = iter->next;
	}
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		exit(1);
	iter = word_list;
	size = 0;
	while (iter)
	{
		ret[size++] = ft_strdup(iter->content);
		iter = iter->next;
	}
	ret[size] = NULL;
	return (ret);
}

void	adjust_command_structure(t_token *iter, t_token **word_list, \
									t_cmd **cmd, t_cmd **pipeline)
{
	if (iter->type == WORD)
	{
		ft_tokenadd_back(word_list, \
			ft_token_new(WORD, ft_strdup(iter->content)));
	}
	else if (iter->type == PIPE)
	{
		(*cmd)->simple_cmd = make_simple_cmd(*word_list);
		ft_tokenclear(word_list, free);
		ft_cmdadd_back(pipeline, *cmd);
		*cmd = ft_cmd_new();
	}
}

void	add_redir_token(t_token *iter, t_token **type_list, t_cmd **cmd)
{
	t_token	*new;

	if (iter->type != WORD && iter->type != PIPE)
	{
		redir_type(type_list, iter);
		new = ft_token_new(iter->type, ft_strdup(iter->content));
		ft_tokenadd_back(&((*cmd)->redir_header), new);
	}
}

t_cmd	*struct_cmd(t_token **type_list)
{
	t_cmd	*pipeline;
	t_cmd	*cmd;
	t_token	*iter;
	t_token	*word_list;

	iter = *type_list;
	pipeline = NULL;
	word_list = NULL;
	cmd = ft_cmd_new();
	while (iter)
	{
		adjust_command_structure(iter, &word_list, &cmd, &pipeline);
		add_redir_token(iter, type_list, &cmd);
		if (iter->next == NULL)
		{
			cmd->simple_cmd = make_simple_cmd(word_list);
			ft_tokenclear(&word_list, free);
			ft_cmdadd_back(&pipeline, cmd);
		}
		iter = iter->next;
	}
	return (pipeline);
}
