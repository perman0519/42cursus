/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:14:51 by junssong          #+#    #+#             */
/*   Updated: 2023/03/23 11:14:52 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*return_arr;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return_arr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!return_arr)
		return (NULL);
	ft_strlcpy(return_arr, s1, s1_len + 1);
	ft_strlcpy(return_arr + s1_len, s2, s2_len + 1);
	return (return_arr);
}
