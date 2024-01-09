/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:15 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 20:20:15 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_exec(t_exec *exec, t_cmd **pipeline, t_list **env)
{
	exec->count = count_pipe(pipeline);
	exec->repeat_fork = 0;
	exec->path = detec_path(env);
}

void	wait_child(pid_t pid, int count)
{
	int	fork_count;
	int	status;

	fork_count = 0;
	while (pid != 0 && fork_count < count)
	{
		if (waitpid(-1, &status, 0) > 0)
		{
			if (WIFEXITED(status))
				g_exit_code = WEXITSTATUS(status);
			else if (WTERMSIG(status) == 2)
				g_exit_code = 130;
			else if (WTERMSIG(status) == 3)
			{
				g_exit_code = 131;
				printf("QUIT: 3\n");
			}
		}
		else
			return ;
		fork_count++;
	}
	return ;
}

void	close_fd(t_exec *arg)
{
	close(arg->fds_prev[0]);
	close(arg->fds_prev[1]);
	if (arg->count > 0)
	{
		close(arg->fds_next[1]);
		close(arg->fds_next[0]);
	}
}

void	fork_heredoc(t_cmd **pipeline, t_exec *exec)
{
	pid_t	pid;
	int		status;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		signal(SIGINT, c_handler);
		signal(SIGTERM, c_handler);
		signal(SIGQUIT, SIG_IGN);
		read_heredoc(pipeline);
	}
	if (waitpid(-1, &status, 0) > 0)
	{
		g_exit_code = WEXITSTATUS(status);
		if (g_exit_code && exec->path)
			free_all(exec->path);
	}
}
