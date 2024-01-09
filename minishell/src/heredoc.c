/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:48:53 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 14:27:24 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_readline(int fd, char *lim)
{
	char	*input;

	while (1)
	{
		input = readline("heredoc> ");
		if (!input)
			return ;
		if (!ft_strcmp(input, lim))
		{
			free(input);
			return ;
		}
		else
			ft_putendl_fd(input, fd);
		free(input);
	}
}

void	heredoc_open_error(void)
{
	perror("minishell: ");
	exit(1);
}

void	read_heredoc(t_cmd **pipeline)
{
	t_cmd	*iter;
	t_token	*red_iter;
	int		fd;

	iter = *pipeline;
	while (iter)
	{
		red_iter = iter->redir_header;
		while (red_iter)
		{
			if (red_iter->type == D_LSR)
			{
				fd = open(red_iter->content, O_RDWR, 0644);
				if (fd == -1)
					heredoc_open_error();
				heredoc_readline(fd, red_iter->temp);
				close(fd);
			}
			red_iter = red_iter->next;
		}
		iter = iter->next;
	}
	exit(0);
}
