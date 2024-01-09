/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:25:21 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:15:36 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p_b;

	p_b = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p_b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
