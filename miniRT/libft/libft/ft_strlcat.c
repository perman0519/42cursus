/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:10:04 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:30:41 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_origin_dst;
	size_t	len_src;
	size_t	index_src;

	if (dst == 0)
		len_origin_dst = 0;
	else
		len_origin_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_origin_dst >= dstsize)
		return (dstsize + len_src);
	else
	{
		while (*dst)
			dst++;
		index_src = 0;
		while (*src && index_src++ < dstsize - len_origin_dst - 1)
			*dst++ = *src++;
		*dst = '\0';
		return (len_origin_dst + len_src);
	}
}
