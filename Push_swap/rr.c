/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:01:45 by junssong          #+#    #+#             */
/*   Updated: 2023/05/09 14:07:47 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	rr(t_list **list_a, t_list **list_b)
{
	(*list_a) = (*list_a)->next;
	(*list_b) = (*list_b)->next;
	ft_printf("rr\n");
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
