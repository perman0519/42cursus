/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:07:33 by junssong          #+#    #+#             */
/*   Updated: 2023/05/08 11:45:15 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	rrb(t_list **list_b)
{
	*list_b = (*list_b)->prev;
	ft_printf("rrb\n");
	return ;
}

void	n_rrb(t_list **list, int n)
{
	while (n > 0)
	{
		rrb(list);
		n--;
	}
}
