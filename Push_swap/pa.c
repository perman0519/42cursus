/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:41:39 by junssong          #+#    #+#             */
/*   Updated: 2023/04/25 17:41:40 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*remove_node;

	if (*list_b == NULL)
		return ;
	remove_node = remove_list_top(list_b);
	add_list_top(list_a, remove_node);
	ft_printf("pa\n");
	return ;
}
