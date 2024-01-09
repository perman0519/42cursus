/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:30:22 by junssong          #+#    #+#             */
/*   Updated: 2023/03/16 11:30:24 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_uc;
	unsigned char		c_uc;
	size_t				i;

	i = 0;
	s_uc = s;
	c_uc = c;
	while (i < n)
	{
		if (s_uc[i] == c_uc)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
