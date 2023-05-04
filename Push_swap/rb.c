/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:00:44 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 18:05:59 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "push_swap.h"

void	rb(t_list **list)
{
	*list = (*list)->next;
	ft_printf("rb\n");
	return ;
}

void	n_rb(t_list **list, int n)
{
	while (n > 0)
	{
		ra(list);
		n--;
	}
}
