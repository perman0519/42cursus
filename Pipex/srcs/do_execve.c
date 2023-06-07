/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:19:35 by junssong          #+#    #+#             */
/*   Updated: 2023/06/07 16:22:50 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	do_child(t_param *param, char **envp)
{
	dup2(0, param->pipefd1[0]);
	close(param->pipefd1[0]);
	dup2(param->pipefd1[1], STDOUT_FILENO);
	execve(param->cmd1_absolutepath, param->cmd1_arg, envp);
	ft_free_split(param->cmd1_arg);
}

void	do_parent(t_param *param, char **envp)
{
	dup2(param->pipefd1[0], 0);
	close(param->pipefd1[1]);
	dup2(param->fd_file2, STDOUT_FILENO);
	execve(param->cmd2_absolutepath, param->cmd2_arg, envp);
	ft_free_split(param->cmd2_arg);
	ft_free_split(param->cmd1_arg);
}
