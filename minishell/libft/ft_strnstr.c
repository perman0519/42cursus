/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:49:41 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:15:52 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_idx;
	size_t	n_idx;

	if (!(*needle))
		return ((char *)haystack);
	h_idx = 0;
	while (haystack[h_idx] && h_idx < len)
	{
		if (haystack[h_idx] == needle[0])
		{
			n_idx = 0;
			while (h_idx + n_idx < len && \
					needle[n_idx] && haystack[h_idx + n_idx] == needle[n_idx])
				n_idx++;
			if (!needle[n_idx])
				return ((char *)(haystack + h_idx));
		}
		h_idx++;
	}
	return (0);
}
