/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:00 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:12:17 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_built_in(char **simple_cmd)
{
	char	*cmd;

	if (!simple_cmd || !*simple_cmd)
		return (-2);
	cmd = simple_cmd[0];
	if (!ft_strcmp(cmd, "exit"))
		return (0);
	else if (!ft_strcmp(cmd, "pwd"))
		return (1);
	else if (!ft_strcmp(cmd, "cd"))
		return (2);
	else if (!ft_strcmp(cmd, "export"))
		return (3);
	else if (!ft_strcmp(cmd, "unset"))
		return (4);
	else if (!ft_strcmp(cmd, "env"))
		return (5);
	else if (!ft_strcmp(cmd, "echo"))
		return (6);
	return (-1);
}

int	run_cmd(t_cmd *cmd, t_list **environ, int flag, int is_p)
{
	void	(*f[7])(char **, t_list **, int);

	f[0] = ft_exit;
	f[1] = ft_pwd;
	f[2] = ft_cd;
	f[3] = ft_export;
	f[4] = ft_unset;
	f[5] = ft_env;
	f[6] = ft_echo;
	if (flag > -1)
	{
		if (is_p)
			f[flag](cmd->simple_cmd, environ, cmd->io_fd[1]);
		else
			f[flag](cmd->simple_cmd, environ, STDOUT_FILENO);
		return (1);
	}
	else
		return (flag);
}
