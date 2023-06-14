/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:00:27 by junssong          #+#    #+#             */
/*   Updated: 2023/06/13 17:45:35 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_param	param;

	if (argc < 5)
		return (1);
	set_param(&param, argv, envp, argc);
	while (++(param.index) < argc - 3)
	{
		param.child_pid = fork();
		if (param.child_pid == -1)
		{
			put_err("fork");
			exit(1);
		}
		if (param.index == 0 && param.child_pid == 0)
			do_cmd_first(&param, envp);
		else if (param.index == argc - 4 && param.child_pid == 0)
			do_cmd_last(&param, envp);
		else if (param.child_pid == 0)
			do_cmd_middle(&param, envp);
	}
	close_pipe(&param);
	while (--(param.index) > -1)
		waitpid(-1, NULL, 0);
	return (0);
}
