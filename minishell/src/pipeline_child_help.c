/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_child_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:08 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/09 20:49:08 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_child_help(t_exec *arg, t_cmd *cmd)
{
	dup2(cmd->io_fd[0], STDIN_FILENO);
	if (cmd->io_fd[1] != 1)
		dup2(cmd->io_fd[1], STDOUT_FILENO);
	else if (arg->count > 1)
		dup2(arg->fds_next[1], STDOUT_FILENO);
	if (cmd->io_fd[1] != 1)
		close(cmd->io_fd[1]);
	if (cmd->io_fd[0] != 0)
		close(cmd->io_fd[0]);
	close(arg->fds_next[0]);
	close(arg->fds_next[1]);
}

void	middle_child_help(t_exec *arg, t_cmd *cmd)
{
	if (cmd->io_fd[1] != 1)
		dup2(cmd->io_fd[1], STDOUT_FILENO);
	else
		dup2(arg->fds_next[1], STDOUT_FILENO);
	if (cmd->io_fd[0] != 0)
		dup2(cmd->io_fd[0], STDIN_FILENO);
	else
		dup2(arg->fds_prev[0], STDIN_FILENO);
	if (cmd->io_fd[0] != 0)
		close(cmd->io_fd[0]);
	else
		close(arg->fds_prev[0]);
	if (cmd->io_fd[1] != 1)
		close(cmd->io_fd[1]);
	else
		close(arg->fds_next[1]);
}

void	last_child_help(t_exec *arg, t_cmd *cmd)
{
	if (cmd->io_fd[1] != 1)
		dup2(cmd->io_fd[1], STDOUT_FILENO);
	if (cmd->io_fd[0] != 0)
		dup2(cmd->io_fd[0], STDIN_FILENO);
	else
		dup2(arg->fds_prev[0], STDIN_FILENO);
	close(arg->fds_prev[0]);
	if (cmd->io_fd[0] != 0)
		close(cmd->io_fd[0]);
	else
		close(arg->fds_prev[0]);
	if (cmd->io_fd[1] != 1)
		close(cmd->io_fd[1]);
}
