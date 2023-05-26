/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:23:40 by junssong          #+#    #+#             */
/*   Updated: 2023/03/23 11:23:40 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*return_arr;

	if (*s1 == 0 || *set == 0)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
		--end;
	return_arr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!return_arr)
		return (NULL);
	ft_strlcpy(return_arr, s1 + start, end - start + 1);
	return (return_arr);
}
