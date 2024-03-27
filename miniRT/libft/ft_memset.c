/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:37:40 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 14:53:24 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index_b;

	index_b = 0;
	while (index_b < len)
	{
		((unsigned char *)b)[index_b] = (unsigned char)c;
		index_b++;
	}
	return (b);
}
