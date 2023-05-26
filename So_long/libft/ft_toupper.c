/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:00:18 by junssong          #+#    #+#             */
/*   Updated: 2023/03/16 11:00:20 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (a >= 'a' && a <= 'z')
	{
		a -= 32;
		return ((int)a);
	}
	else
	{
		return (c);
	}
}
