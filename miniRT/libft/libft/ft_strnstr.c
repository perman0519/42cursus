/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:48:43 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:35:37 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0] && i + ft_strlen(needle) <= len)
		{
			if (!(ft_strncmp(&haystack[i], needle, ft_strlen(needle))))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
