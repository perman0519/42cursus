/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:54:01 by junssong          #+#    #+#             */
/*   Updated: 2023/03/23 15:54:01 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	i;
	char	*return_arr;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	return_arr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!return_arr)
		return (NULL);
	return_arr[s_len] = '\0';
	i = 0;
	while (s[i])
	{
		return_arr[i] = f(i, s[i]);
		i++;
	}
	return (return_arr);
}
