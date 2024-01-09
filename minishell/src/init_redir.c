/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:48:57 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/13 14:31:05 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_redir_in(t_cmd *cmd, t_token *iter)
{
	if (cmd->io_fd[0] != 0)
		close(cmd->io_fd[0]);
	cmd->io_fd[0] = open(iter->content, O_RDONLY);
	if (cmd->io_fd[0] < 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(iter->content);
		return (OPEN_ERROR);
	}
	return (OPEN_SUCCESS);
}

int	open_redir_out_grt(t_cmd *cmd, t_token *iter)
{
	if (cmd->io_fd[1] != 1)
		close(cmd->io_fd[1]);
	cmd->io_fd[1] = open(iter->content, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (cmd->io_fd[1] < 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(iter->content);
		return (OPEN_ERROR);
	}
	return (OPEN_SUCCESS);
}

int	open_redir_out_dgrt(t_cmd *cmd, t_token *iter)
{
	if (cmd->io_fd[1] != 1)
		close(cmd->io_fd[1]);
	cmd->io_fd[1] = open(iter->content, O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (cmd->io_fd[1] < 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(iter->content);
		return (OPEN_ERROR);
	}
	return (OPEN_SUCCESS);
}

int	init_redir(t_cmd *cmd)
{
	t_token	*redir_iter;
	int		type;

	redir_iter = cmd->redir_header;
	while (redir_iter)
	{
		type = redir_iter->type;
		if (type == LSR || type == D_LSR)
		{
			if (open_redir_in(cmd, redir_iter) == OPEN_ERROR)
				return (OPEN_ERROR);
		}
		else if (type == GRT)
		{
			if (open_redir_out_grt(cmd, redir_iter) == OPEN_ERROR)
				return (OPEN_ERROR);
		}
		else if (type == D_GRT)
		{
			if (open_redir_out_dgrt(cmd, redir_iter) == OPEN_ERROR)
				return (OPEN_ERROR);
		}
		redir_iter = redir_iter->next;
	}
	return (OPEN_SUCCESS);
}
