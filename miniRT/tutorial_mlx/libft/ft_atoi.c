/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:39:20 by junssong          #+#    #+#             */
/*   Updated: 2023/03/17 16:39:21 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_overflow(long long value, long long temp, int sign);

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	value;
	long long	temp;

	sign = 1;
	i = 0;
	value = 0;
	temp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		value = 10 * temp + ((int)str[i++] - '0');
		if (return_overflow(value, temp, sign) == 1)
			temp = value;
		else if (return_overflow(value, temp, sign) == -1)
			return (-1);
		else if (return_overflow(value, temp, sign) == 0)
			return (0);
	}
	return (sign * (int)value);
}

static int	return_overflow(long long value, long long temp, int sign)
{
	if (value / 10 == temp)
		return (1);
	if (sign > 0)
		return (-1);
	if (sign < 0)
		return (0);
	return (1);
}
