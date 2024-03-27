/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:21:43 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:36:07 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index_s;

	index_s = ft_strlen(s);
	while (1)
	{
		if (s[index_s] == (char)c)
			return ((char *)&s[index_s]);
		if (index_s == 0)
			return (0);
		index_s--;
	}
}
