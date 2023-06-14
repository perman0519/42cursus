/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:27:37 by junssong          #+#    #+#             */
/*   Updated: 2023/06/13 17:48:44 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	set_path(t_param *param, char **argv, char **envp, int i);
void	open_file(t_param *param, char **argv, int argc);
void	open_pipe(t_param *param, int argc);

int	set_param(t_param *param, char **argv, char **envp, int argc)
{
	int	i;

	i = -1;
	param->index = -1;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		param->here_doc = 1;
	param->here_doc = 0;
	param->cmd_count = argc - 3;
	param->cmd_absolutepath = \
		(char **)malloc(sizeof(char *) * param->cmd_count);
	param->cmd_arg = (char ***)malloc(sizeof(char **) * argc - 3);
	if (param -> cmd_absolutepath == NULL || param -> cmd_arg == NULL)
		exit(1);
	while (++i < argc - 3)
		set_path(param, argv, envp, i);
	param->fd_file1 = open(argv[1], O_RDONLY);
	open_file(param, argv, argc);
	open_pipe(param, argc);
	return (0);
}

void	open_pipe(t_param *param, int argc)
{
	int	i;

	i = -1;
	param->pipefd = \
		(int (*)[2])malloc(sizeof(int) * (param->cmd_count - 1) * 2);
	if (param -> pipefd == NULL)
	{
		put_err("split");
		exit(1);
	}
	while (++i < argc - 4)
	{
		if (pipe(param->pipefd[i]) < 0)
		{
			put_err("pipe");
			exit(1);
		}
	}
}

void	open_file(t_param *param, char **argv, int argc)
{
	if (param->fd_file1 < 0)
	{
		put_err(argv[1]);
		exit(1);
	}
	param->fd_file2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (param->fd_file2 < 0)
	{
		put_err(argv[argc - 1]);
		exit(1);
	}
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
