/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:46:57 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:38:41 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
	{
		result = ft_calloc(1, 1);
		return (result);
	}
	if (ft_strlen(s + start) < len)
	{
		result = malloc(ft_strlen(s + start) + 1);
		if (!(result))
			return (0);
		ft_strlcpy(result, s + start, ft_strlen(s + start) + 1);
	}
	else
	{
		result = malloc(len + 1);
		if (!(result))
			return (0);
		ft_strlcpy(result, s + start, len + 1);
	}
	return (result);
}
