/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:01:45 by junssong          #+#    #+#             */
/*   Updated: 2023/05/08 14:18:58 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	rr(t_list **list_a, t_list **list_b)
{
	ra(list_a);
	rb(list_b);
	return ;
}

void	n_rr(t_list **list_a, t_list **list_b, int n)
{
	while (n > 0)
	{
		(*list_a) = (*list_a)->next;
		(*list_b) = (*list_b)->next;
		ft_printf("rr\n");
		n--;
	}
}
