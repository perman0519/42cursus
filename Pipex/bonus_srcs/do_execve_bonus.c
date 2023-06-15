/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_execve_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:19:35 by junssong          #+#    #+#             */
/*   Updated: 2023/06/15 17:01:49 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	do_cmd_first(t_param *param, char **envp)
{
	dup2(param->fd_file1, STDIN_FILENO);
	dup2(param->pipefd[0][1], STDOUT_FILENO);
	close(param->fd_file1);
	close_pipe(param);
	if (execve(param->cmd_absolutepath[param->index], \
		param->cmd_arg[param->index], envp) == -1)
	{
		put_err(param->cmd_absolutepath[param->index]);
		exit(1);
	}
}

void	do_cmd_last(t_param *param, char **envp)
{
	dup2(param->pipefd[param->index - 1][0], STDIN_FILENO);
	dup2(param->fd_file2, STDOUT_FILENO);
	close_pipe(param);
	if (execve(param->cmd_absolutepath[param->index], \
		param->cmd_arg[param->index], envp) == -1)
	{
		put_err(param->cmd_absolutepath[param->index]);
		exit(1);
	}
}

void	do_cmd_middle(t_param *param, char **envp)
{
	dup2(param->pipefd[param->index - 1][0], STDIN_FILENO);
	dup2(param->pipefd[param->index][1], STDOUT_FILENO);
	close_pipe(param);
	if (execve(param->cmd_absolutepath[param->index], \
		param->cmd_arg[param->index], envp) == -1)
	{
		put_err(param->cmd_absolutepath[param->index]);
		exit(1);
	}
}

void	close_pipe(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->cmd_count - 1)
	{
		close(param->pipefd[i][0]);
		close(param->pipefd[i][1]);
		i++;
	}
	i = 0;
}

void	free_all(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->cmd_count)
	{
		ft_free_split(param->cmd_arg[i]);
		free(param->cmd_absolutepath[i]);
		i++;
	}
	free(param->cmd_arg);
	free(param->cmd_absolutepath);
	free(param->pipefd);
}
