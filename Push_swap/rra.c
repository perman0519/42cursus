/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:05:52 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 14:18:58 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	rra(t_list **list_a)
{
	*list_a = (*list_a)->prev;
	ft_printf("rra\n");
	return ;
}

void	n_rra(t_list **list, int n)
{
	while (n > 0)
	{
		rra(list);
		n--;
	}
}
