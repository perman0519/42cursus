/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:24:17 by junssong          #+#    #+#             */
/*   Updated: 2023/06/14 18:44:37 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	is_here_doc(t_param *param, char **argv, char **envp, int argc)
{
	int	i;

	i = -1;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		param->here_doc = 1;
		param->index = 0;
		while (++i < argc - 4)
			set_path(param, argv, envp, i + 1);
	}
	else
	{
		while (++i < argc - 3)
			set_path(param, argv, envp, i);
	}
}

void	child_here_doc(t_param *param, char **argv)
{
	char	*here_doc;

	dup2(param->pipefd[0][1], STDOUT_FILENO);
	close(param->fd_file1);
	while (1)
	{
		here_doc = get_next_line(STDIN_FILENO);
		if (ft_strncmp(here_doc, argv[2], ft_strlen(argv[2])) == 0)
		{
			break ;
		}
		else
		{
			ft_putstr_fd(here_doc, STDOUT_FILENO);
			free(here_doc);
		}
	}
}
