/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:33:48 by junssong          #+#    #+#             */
/*   Updated: 2024/03/22 16:56:37 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	help_ft_atof(char *str, int i, \
					double decimal_factor, double decimal_place)
{
	double	res;
	int		infinity;

	res = 0.0;
	infinity = 100000;
	while (str[i] != '\0')
	{
		if (str[i] == '.' && (decimal_place == 0 && i != 0))
			decimal_place = 1;
		else if (ft_isdigit(str[i]))
		{
			if (decimal_place == 1)
			{
				decimal_factor /= 10.0;
				res += (str[i] - '0') * decimal_factor;
			}
			else
				res = res * 10.0 + (str[i] - '0');
		}
		else
			return (infinity);
		i++;
	}
	return (res);
}

double	ft_atof(char *str)
{
	double	res;
	int		sign;
	int		decimal_place;
	double	decimal_factor;
	int		i;

	decimal_place = 0;
	decimal_factor = 1.0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = help_ft_atof(str, i, decimal_factor, decimal_place);
	return (sign * res);
}
