/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:56:22 by junssong          #+#    #+#             */
/*   Updated: 2023/06/12 14:50:24 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*return_list;

	return_list = (t_list *)malloc(sizeof(t_list));
	if (!return_list)
		return (NULL);
	return_list ->content = content;
	return_list ->next = NULL;
	return (return_list);
}
