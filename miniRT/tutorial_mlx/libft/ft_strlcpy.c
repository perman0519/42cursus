/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:26:10 by junssong          #+#    #+#             */
/*   Updated: 2023/03/15 16:34:34 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_legth;

	i = 0;
	src_legth = ft_strlen(src);
	if (dstsize == 0)
		return (src_legth);
	while (i < dstsize - 1)
	{
		if (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		else
		{
			dst[i] = src[i];
			return (src_legth);
		}
	}
	dst[i] = '\0';
	return (src_legth);
}
