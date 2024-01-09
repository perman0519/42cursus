/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:52 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 21:34:03 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fork_child(pid_t pid, t_exec *exec, t_cmd **iter, t_list **env)
{
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	if (pid == 0 && exec->repeat_fork == 0)
		first_child(*exec, *iter, env);
	else if (pid == 0 && exec->repeat_fork == exec->count - 1)
		last_child(*exec, *iter, env);
	else if (pid == 0)
		middle_child(*exec, *iter, env);
	else
	{
		exec->repeat_fork++;
		*iter = ((*iter)->next);
	}
}

void	ft_check_pipe(t_exec *exec)
{
	if (exec->repeat_fork > 0)
	{
		close(exec->fds_prev[0]);
		close(exec->fds_prev[1]);
		exec->fds_prev[0] = exec->fds_next[0];
		exec->fds_prev[1] = exec->fds_next[1];
	}
	if (pipe(exec->fds_next) < 0)
		exit(1);
}

int	check_heredoc_error(t_cmd *iter)
{
	if (g_exit_code != 0)
	{
		while (iter)
		{
			unlink_temp_files(iter);
			iter = iter->next;
		}
		return (1);
	}
	else
		return (0);
}

void	pipexline(t_cmd **pipeline, t_list **env)
{
	pid_t	pid;
	t_exec	exec;
	t_cmd	*iter;

	g_exit_code = 0;
	iter = *pipeline;
	init_exec(&exec, pipeline, env);
	fork_heredoc(pipeline, &exec);
	if (check_heredoc_error(iter))
		return ;
	if (pipe(exec.fds_prev) < 0)
		exit(1);
	while (exec.repeat_fork < exec.count)
	{
		ft_check_pipe(&exec);
		signal(SIGINT, SIG_IGN);
		pid = fork();
		ft_fork_child(pid, &exec, &iter, env);
	}
	if (exec.path)
		free_all(exec.path);
	close_fd(&exec);
	wait_child(pid, exec.count);
}
