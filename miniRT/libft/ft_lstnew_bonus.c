/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:16:02 by junhapar          #+#    #+#             */
/*   Updated: 2024/02/12 20:07:27 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, int type)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list) * 1);
	if (!(result))
		return (0);
	result->type = type;
	result->content = content;
	result->next = NULL;
	return (result);
}
