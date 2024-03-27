/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:41:08 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:33:32 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index_s;

	index_s = 0;
	while (index_s < n)
	{
		if (s1[index_s] != s2[index_s])
			return ((unsigned char)s1[index_s] - (unsigned char)s2[index_s]);
		if (s1[index_s] == 0 || s2[index_s] == 0)
			return (0);
		index_s++;
	}
	return (0);
}
