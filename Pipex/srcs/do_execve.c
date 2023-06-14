/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:19:35 by junssong          #+#    #+#             */
/*   Updated: 2023/06/14 16:12:27 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	do_cmd_first(t_param *param, char **envp)
{
	dup2(param->fd_file1, STDIN_FILENO);
	dup2(param->pipefd1[1], STDOUT_FILENO);
	close(param->pipefd1[0]);
	close(param->pipefd1[1]);
	close(param->fd_file1);
	if (execve(param->cmd_absolutepath[param->index], \
		param->cmd_arg[param->index], envp) == -1)
	{
		put_err(param->cmd_arg[0][0]);
		exit(1);
	}
}

void	do_cmd_last(t_param *param, char **envp)
{
	dup2(param->pipefd1[0], STDIN_FILENO);
	dup2(param->fd_file2, STDOUT_FILENO);
	close(param->pipefd1[0]);
	close(param->pipefd1[1]);
	close(param->fd_file2);
	if (execve(param->cmd_absolutepath[param->index], \
		param->cmd_arg[param->index], envp) == -1)
	{
		put_err(param->cmd_arg[1][0]);
		exit(1);
	}
}
