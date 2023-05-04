/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:52:43 by junssong          #+#    #+#             */
/*   Updated: 2023/04/25 17:52:44 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*remove_node;

	if (*list_a == NULL)
		return ;
	remove_node = remove_list_top(list_a);
	add_list_top(list_b, remove_node);
	ft_printf("pb\n");
	return ;
}
