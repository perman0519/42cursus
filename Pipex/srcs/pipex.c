/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:00:27 by junssong          #+#    #+#             */
/*   Updated: 2023/06/07 16:10:23 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_param	param;

	if (argc != 5)
		return (0);
	if (set_param(&param, argv, envp) == 1)
		return (1);
	param.first_child = fork();
	if (param.first_child == -1)
		perror("fork error");
	dup2(param.fd_file1, 0);
	close(param.fd_file1);
	if (param.first_child == 0)
		do_child(&param, envp);
	else
		do_parent(&param, envp);
}
