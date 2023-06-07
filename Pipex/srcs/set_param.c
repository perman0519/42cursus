/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:27:37 by junssong          #+#    #+#             */
/*   Updated: 2023/06/07 17:37:31 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	set_param(t_param *param, char **argv, char **envp)
{
	if (!(access(argv[1], F_OK) == 0 && access(argv[1], R_OK) == 0))
	{
		perror("error");
		return (1);
	}
	param->cmd1_arg = ft_split(argv[2], ' ');
	param->cmd2_arg = ft_split(argv[3], ' ');
	param->cmd1_absolutepath = find_absolute_path(envp, param->cmd1_arg);
	param->cmd2_absolutepath = find_absolute_path(envp, param->cmd2_arg);
	param->fd_file1 = open(argv[1], O_RDONLY);
	param->fd_file2 = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
	ft_printf("%d\n", param->fd_file2);
	if (param->fd_file1 < 0 || param->fd_file2 < 0 || pipe(param->pipefd1) < 0 \
	|| param->cmd1_absolutepath == NULL || param->cmd2_absolutepath == NULL)
	{
		perror("error");
		return (1);
	}
	return (0);
}
