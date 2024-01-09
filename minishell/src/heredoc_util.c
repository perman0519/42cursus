/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:48:50 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:12:08 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unlink_temp_files(t_cmd *cmd)
{
	t_token	*iter;

	iter = cmd->redir_header;
	while (iter)
	{
		if (iter->type == D_LSR)
			unlink(iter->content);
		iter = iter->next;
	}
}

char	*heredoc_file(void)
{
	int		heredoc_idx;
	char	*tmp;
	char	*itoa;

	heredoc_idx = 0;
	itoa = ft_itoa(heredoc_idx);
	tmp = ft_strjoin(".tmp_", itoa);
	while (access(tmp, F_OK) >= 0)
	{
		heredoc_idx++;
		free(tmp);
		free(itoa);
		itoa = ft_itoa(heredoc_idx);
		tmp = ft_strjoin(".tmp_", itoa);
	}
	free(itoa);
	return (tmp);
}

void	change_heredoc(t_cmd **pipeline)
{
	t_cmd	*iter;
	t_token	*red_iter;
	char	*file_str;
	int		fd;

	iter = *pipeline;
	while (iter)
	{
		red_iter = iter->redir_header;
		while (red_iter)
		{
			if (red_iter->type == D_LSR)
			{
				file_str = heredoc_file();
				fd = open(file_str, O_CREAT, 0644);
				close(fd);
				red_iter->temp = ft_strdup(red_iter->content);
				free(red_iter->content);
				red_iter->content = file_str;
			}
			red_iter = red_iter->next;
		}
		iter = iter->next;
	}
}
