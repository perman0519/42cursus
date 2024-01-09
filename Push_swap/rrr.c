/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:08:40 by junssong          #+#    #+#             */
/*   Updated: 2023/05/09 14:07:27 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	rrr(t_list **list_a, t_list **list_b)
{
	*list_a = (*list_a)->prev;
	*list_b = (*list_b)->prev;
	ft_printf("rrr\n");
}

void	n_rrr(t_list **list_a, t_list **list_b, int n)
{
	while (n > 0)
	{
		*list_a = (*list_a)->prev;
		*list_b = (*list_b)->prev;
		ft_printf("rrr\n");
		n--;
	}
}
