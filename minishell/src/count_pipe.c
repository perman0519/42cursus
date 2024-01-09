/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:44 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/09 20:47:44 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipe(t_cmd **pipeline)
{
	t_cmd	*iter;
	int		cnt;

	cnt = 0;
	iter = *pipeline;
	while (iter)
	{
		cnt++;
		iter = iter->next;
	}
	return (cnt);
}
