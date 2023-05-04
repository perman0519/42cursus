/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:43 by junssong          #+#    #+#             */
/*   Updated: 2023/03/19 16:06:44 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*return_arr;
	size_t			s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_len <= start)
	{
		return_arr = (char *)malloc(sizeof(char) * 1);
		if (!return_arr)
			return (NULL);
		return_arr[0] = '\0';
		return (return_arr);
	}
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	return_arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!return_arr)
		return (NULL);
	ft_strlcpy(return_arr, s + start, len + 1);
	return (return_arr);
}
