/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:38:41 by junssong          #+#    #+#             */
/*   Updated: 2023/03/29 13:38:42 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s);

int	ft_putstr(char *s)
{
	int	size;

	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	size = ft_strlen(s);
	if (write(1, s, size) == -1)
		return (-1);
	return (size);
}

static size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++ != '\0')
	{
		++count;
	}
	return (count);
}
