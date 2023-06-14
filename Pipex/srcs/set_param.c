/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:27:37 by junssong          #+#    #+#             */
/*   Updated: 2023/06/14 16:11:05 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	set_path(t_param *param, char **argv, char **envp, int i);

int	set_param(t_param *param, char **argv, char **envp)
{
	int	i;

	i = -1;
	while (++i < 2)
		set_path(param, argv, envp, i);
	param->fd_file1 = open(argv[1], O_RDONLY);
	param->fd_file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (param->fd_file1 < 0 || param->fd_file2 < 0)
	{
		put_err("file open");
		exit(1);
	}
	if (pipe(param->pipefd1) < 0)
	{
		put_err("pipe");
		exit(1);
	}
	param->index = -1;
	return (0);
}

void	set_path(t_param *param, char **argv, char **envp, int i)
{
	param->cmd_arg[i] = ft_split(argv[i + 2], ' ');
	if (param->cmd_arg[i] == NULL)
	{
		put_err("split");
		exit(1);
	}
	param->cmd_absolutepath[i] = find_absolute_path(envp, param->cmd_arg[i]);
}

void	put_err(char *file)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
