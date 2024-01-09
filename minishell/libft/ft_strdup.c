/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:46:43 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:14:24 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	s_len;

	s_len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * s_len + 1);
	if (!temp)
		exit(1);
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (temp - s_len);
}
