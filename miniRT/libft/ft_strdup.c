/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:01:56 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:25:28 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	result = malloc(len_s1 + 1);
	if (!(result))
		return (0);
	ft_memcpy(result, s1, len_s1 + 1);
	return (result);
}
