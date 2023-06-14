/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:42:33 by junssong          #+#    #+#             */
/*   Updated: 2023/06/13 16:19:52 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	char	***cmd_arg;
	char	**cmd_absolutepath;
	int		fd_file1;
	int		fd_file2;
	int		(*pipefd)[2];
	int		cmd_count;
	int		index;
}				t_param;

char	*find_absolute_path(char **envp, char **cmd_arg);
int		set_param(t_param *param, char **argv, char **envp, int argc);
void	do_cmd_first(t_param *param, char **envp);
void	do_cmd_last(t_param *param, char **envp);
void	do_cmd_middle(t_param *param, char **envp);
void	put_err(char *file);
void	close_pipe(t_param *param);

#endif
