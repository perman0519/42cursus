/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:35:57 by junssong          #+#    #+#             */
/*   Updated: 2023/03/17 12:35:58 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_length;
	size_t	haystack_length;
	size_t	i;
	size_t	j;

	i = 0;
	needle_length = ft_strlen(needle);
	haystack_length = ft_strlen(haystack);
	if (needle_length == 0)
		return ((char *)haystack);
	if (len == 0 || haystack_length == 0 || len < needle_length)
		return (NULL);
	while (i < len && i < haystack_length)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (++j == needle_length)
				return ((char *)(haystack + i));
			if (i + j + 1 > len)
				break ;
		}
		i++;
	}
	return (NULL);
}
