/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:27:23 by junssong          #+#    #+#             */
/*   Updated: 2023/03/15 16:21:54 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exception_handling(void *dst, const void *src, size_t len);
static void	help_ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (exception_handling(dst, src, len))
		return (dst);
	help_ft_memmove(dst, src, len);
	return (dst);
}

static int	exception_handling(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;

	tmp = dst;
	if (len == 0)
		return (1);
	if (tmp == NULL && src == NULL)
	{
		return (1);
	}
	return (0);
}

static void	help_ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp;
	const unsigned char	*srcs;
	size_t				i;

	tmp = dst;
	srcs = src;
	i = 0;
	if (dst <= src)
	{
		while (i < len)
		{
			tmp[i] = srcs[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i > 0)
		{
			tmp[i] = srcs[i];
			i--;
		}
		tmp[i] = srcs[i];
	}
}
