/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:00:27 by junssong          #+#    #+#             */
/*   Updated: 2023/06/14 14:08:52 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_param	param;

	if (argc != 5)
		return (1);
	set_param(&param, argv, envp);
	while (++(param.index) < 2)
	{
		param.child_pid = fork();
		if (param.child_pid == -1)
		{
			perror("fork error");
			exit(1);
		}
		if (param.index == 0 && param.child_pid == 0)
			do_cmd_first(&param, envp);
		else if (param.index == 1 && param.child_pid == 0)
			do_cmd_last(&param, envp);
	}
	close(param.pipefd1[0]);
	close(param.pipefd1[1]);
	while (--(param.index) > -1)
		waitpid(-1, NULL, 0);
	return (0);
}
