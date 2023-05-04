/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:03:06 by junssong          #+#    #+#             */
/*   Updated: 2023/03/19 16:03:07 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*return_voidp;

	return_voidp = malloc(size * count);
	if (return_voidp == 0)
		return (NULL);
	ft_memset(return_voidp, 0, size * count);
	return (return_voidp);
}
