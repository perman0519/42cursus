/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:11:55 by junssong          #+#    #+#             */
/*   Updated: 2023/03/15 18:26:27 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	i;

	if (dst == 0 && dstsize == 0)
		return (0);
	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	i = 0;
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	while (dstsize - dst_length - i - 1 > 0)
	{
		if (src[i] != 0)
			dst[dst_length + i] = src[i];
		else
		{
			dst[dst_length + i] = '\0';
			return (dst_length + src_length);
		}
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}
