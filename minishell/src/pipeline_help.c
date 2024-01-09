/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:13 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/14 16:35:02 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_execve_error(t_cmd *cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd->simple_cmd[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	exit(127);
}

void	file_access_error(char *valid_cmd, int exit_code)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	perror(valid_cmd);
	exit(exit_code);
}

void	print_execve_error(char *simple_cmd, char *msg, int err_status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(simple_cmd, 2);
	ft_putendl_fd(msg, 2);
	exit(err_status);
}

void	check_execve_fail(char *valid_cmd, t_cmd *cmd)
{
	if (valid_cmd)
	{
		if (access(valid_cmd, F_OK) < 0)
			file_access_error(valid_cmd, 127);
		else if (access(valid_cmd, X_OK) < 0)
			file_access_error(valid_cmd, 126);
		else if (opendir(valid_cmd) != 0)
		{
			if (ft_strchr(valid_cmd, '/'))
				print_execve_error(valid_cmd, ": is a directory", 126);
			else
				print_execve_error(valid_cmd, ": command not found", 127);
		}
		else
			exit(0);
	}
	else
		ft_execve_error(cmd);
}

void	ft_execve(t_exec arg, t_cmd *cmd, char **envp)
{
	char	*valid_cmd;

	valid_cmd = valid(arg.path, cmd->simple_cmd[0]);
	if (!valid_cmd && !access(cmd->simple_cmd[0], F_OK | X_OK))
		valid_cmd = cmd->simple_cmd[0];
	if (execve(valid_cmd, cmd->simple_cmd, envp) < 0)
		check_execve_fail(valid_cmd, cmd);
}
