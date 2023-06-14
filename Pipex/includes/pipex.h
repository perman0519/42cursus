/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:42:33 by junssong          #+#    #+#             */
/*   Updated: 2023/06/14 16:09:50 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_param
{
	pid_t	child_pid;
	pid_t	second_child;
	char	**cmd_arg[2];
	char	*cmd_absolutepath[2];
	int		fd_file1;
	int		fd_file2;
	int		pipefd1[2];
	int		index;
}				t_param;

char	*find_absolute_path(char **envp, char **cmd_arg);
int		set_param(t_param *param, char **argv, char **envp);
void	do_cmd_first(t_param *param, char **envp);
void	do_cmd_last(t_param *param, char **envp);
void	put_err(char *file);

#endif
