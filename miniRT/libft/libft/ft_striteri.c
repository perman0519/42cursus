/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:13:33 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 17:26:23 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index_s;

	if (f == 0 || s == 0)
		return ;
	index_s = 0;
	while (s[index_s])
	{
		f(index_s, &s[index_s]);
		index_s++;
	}
}
