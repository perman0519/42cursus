/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:05:09 by junssong          #+#    #+#             */
/*   Updated: 2023/03/16 11:05:10 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (a >= 'A' && a <= 'Z')
	{
		a += 32;
		return ((int)a);
	}
	else
	{
		return (c);
	}
}
