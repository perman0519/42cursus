/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:22:11 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:32:09 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index_dst;
	size_t	end_index_src;

	end_index_src = ft_strlen(src);
	if (dstsize == 0)
		return (end_index_src);
	else
	{
		index_dst = 0;
		while (*src && index_dst++ < dstsize - 1)
			*dst++ = *src++;
		*dst = '\0';
		return (end_index_src);
	}
}
