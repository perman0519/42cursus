/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:48:30 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/13 15:13:17 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_n_option(char *simple_cmd)
{
	int	i;

	i = 0;
	if (simple_cmd[i] && simple_cmd[i] == '-')
		i++;
	else
		return (0);
	if (!simple_cmd[i])
		return (0);
	while (simple_cmd[i] && simple_cmd[i] == 'n')
		i++;
	if (simple_cmd[i] && simple_cmd[i] != 'n')
		return (0);
	return (1);
}

int	printable_cmd_idx(char **simple_cmd)
{
	int	i;

	i = 1;
	while (simple_cmd[i])
	{
		if (!is_n_option(simple_cmd[i]))
			return (i);
		i++;
	}
	return (i);
}

void	ft_echo(char **simple_cmd, t_list **environ, int fd)
{
	int	newline_flag;
	int	idx;

	g_exit_code = 0;
	newline_flag = 1;
	if (!environ)
		return ;
	idx = printable_cmd_idx(simple_cmd);
	if (idx > 1)
		newline_flag = 0;
	while (simple_cmd[idx] != NULL)
	{
		ft_putstr_fd(simple_cmd[idx], fd);
		if (simple_cmd[idx + 1] != NULL)
			ft_putstr_fd(" ", fd);
		idx++;
	}
	if (newline_flag)
		ft_putchar_fd('\n', fd);
}
