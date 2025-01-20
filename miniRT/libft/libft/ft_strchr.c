/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:02:26 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:40:51 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	result = (char *)ft_memchr((void *)s, c, ft_strlen(s) + 1);
	if (result)
		return (result);
	else
		return (0);
}
