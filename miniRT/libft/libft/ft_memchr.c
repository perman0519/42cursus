/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:48:18 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/25 15:33:45 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index_s;

	index_s = 0;
	while (index_s < n)
	{
		if (((unsigned char *)s)[index_s] == (unsigned char)c)
			return ((void *)&s[index_s]);
		index_s++;
	}
	return (0);
}
