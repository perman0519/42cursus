/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:48:35 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/13 14:27:12 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **simple_cmd, t_list **environ, int fd)
{
	(void)fd;
	if (!environ)
		return ;
	if (simple_cmd[1] && ft_atouc(simple_cmd[1], \
		(unsigned char *)&g_exit_code) == 0)
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(simple_cmd[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		g_exit_code = 255;
		exit(255);
	}
	else if (simple_cmd[1] && simple_cmd[2])
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(simple_cmd[1], STDERR_FILENO);
		ft_putendl_fd(": too many arguments", STDERR_FILENO);
		g_exit_code = 1;
		return ;
	}
	exit(g_exit_code);
}
