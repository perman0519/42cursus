/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_absolute_path_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:18:17 by junssong          #+#    #+#             */
/*   Updated: 2023/06/13 10:42:00 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	*find_path(char **split_path, char **cmd_arg)
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
	return (cmd_arg[0]);
}

char	*find_absolute_path(char **envp, char **cmd_arg)
{
	char	*path;
	char	**split_path;

	if (access(cmd_arg[0], F_OK | R_OK) == 0)
		return (cmd_arg[0]);
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
	return (find_path(split_path, cmd_arg));
}
