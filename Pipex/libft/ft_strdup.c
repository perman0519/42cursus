/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:05:27 by junssong          #+#    #+#             */
/*   Updated: 2023/03/19 16:05:28 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy_str;
	size_t	s1_length;
	size_t	i;

	i = 0;
	s1_length = ft_strlen(s1) + 1;
	copy_str = (char *)malloc(s1_length * sizeof(char));
	if (copy_str == NULL)
		return (NULL);
	while (s1[i])
	{
		copy_str[i] = s1[i];
		i++;
	}
	copy_str[i] = '\0';
	return (copy_str);
}
