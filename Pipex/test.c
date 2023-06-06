/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:00:27 by junssong          #+#    #+#             */
/*   Updated: 2023/06/06 19:35:07 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	*find_absolute_path(t_param *s_param, char **envp, char **cmd_arg);

int	main(int argc, char **argv, char **envp)
{
	t_param	param;

	if (argc != 5)
		return (0);
	if (!(access(argv[1], F_OK) == 0 && access(argv[1], R_OK) == 0))
	{
		ft_printf("no such file or directory: %s", argv[1]);
		return (1);
	}
	param.cmd1_arg = ft_split(argv[2], ' ');
	param.cmd2_arg = ft_split(argv[3], ' ');
	param.apsolute_path = find_absolute_path(&param, envp, param.cmd1_arg);
	param.fd_file1 = open(argv[1], O_RDONLY);
	param.fd_file2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (param.fd_file1 < 0 || param.fd_file2 < 0 || pipe(param.pipefd1) < 0)
	{
		perror("error");
		return (1);
	}
	param.first_child = fork();
	if (param.first_child == -1)
		perror("fork error");
	dup2(param.fd_file1, 0);
	close(param.fd_file1);
	if (param.first_child == 0)
	{
		dup2(0, param.pipefd1[0]);
		close(param.pipefd1[0]);
		dup2(param.pipefd1[1], STDOUT_FILENO);
		execve(param.apsolute_path, param.cmd1_arg, envp);
	}
	else
	{
		dup2(param.pipefd1[0], 0);
		close(param.pipefd1[1]);
		dup2(param.fd_file2, 1);
		ft_free_split(param.cmd1_arg);
		param.apsolute_path = find_absolute_path(&param, envp, param.cmd2_arg);
		execve(param.apsolute_path, param.cmd2_arg, envp);
	}
	waitpid(param.first_child, NULL, 0);
}

char	*find_path(t_param *param, char **split_path, char **cmd_arg)
{
	int		i;
	char	*path;

	i = 0;
	while (split_path[i] != NULL)
	{
		split_path[i] = ft_strjoin(split_path[i], "/");
		split_path[i] = ft_strjoin(split_path[i], cmd_arg[0]);
		if (access(split_path[i], F_OK | R_OK) == 0)
		{
			path = ft_strdup(split_path[i]);
			ft_free_split(split_path);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*find_absolute_path(t_param *param, char **envp, char **cmd_arg)
{
	char	*path;
	char	**split_path;
	int		i;

	i = 0;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = *envp;
			break ;
		}
		envp++;
	}
	path = ft_substr(path, 5, ft_strlen(path));
	split_path = ft_split(path, ':');
	free(path);
	return (find_path(param, split_path, cmd_arg));
}
