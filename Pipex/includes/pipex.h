/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:42:33 by junssong          #+#    #+#             */
/*   Updated: 2023/06/05 19:50:03 by junssong         ###   ########.fr       */
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
# include "../libft/libft.h"

typedef struct s_param
{
	pid_t	first_child;
	pid_t	second_child;
	char	**cmd1_arg;
	char	**cmd2_arg;
	char	*apsolute_path;
	int		fd_file1;
	int		fd_file2;
	int		pipefd1[2];
	int		pipefd2[2];
	int		*status;
}				t_param;

#endif
