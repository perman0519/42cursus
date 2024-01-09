/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:48:33 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:11:48 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **simple_cmd, t_list **environ, int fd)
{
	t_list	*iter;

	g_exit_code = 0;
	if (!simple_cmd)
		return ;
	iter = *environ;
	while (iter)
	{
		if (ft_strchr(iter->content, '='))
			ft_putendl_fd(iter->content, fd);
		iter = iter->next;
	}
}
