/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:58:57 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 16:53:58 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	ra(t_list **list)
{
	(*list) = (*list)->next;
	ft_printf("ra\n");
	return ;
}

void	n_ra(t_list **list, int n)
{
	while (n > 0)
	{
		ra(list);
		n--;
	}
}
