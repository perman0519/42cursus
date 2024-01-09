/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:10:17 by junssong          #+#    #+#             */
/*   Updated: 2023/03/15 14:33:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;

	i = 0;
	dest = dst;
	srcs = (unsigned char *)src;
	if (n == 0)
		return (dst);
	if (dst == NULL && src == NULL)
	{
		return (dst);
	}
	if (dst == NULL || src == NULL)
	{
		*dest = 1;
	}
	while (i < n)
	{
		dest[i] = srcs[i];
		++i;
	}
	return (dst);
}
