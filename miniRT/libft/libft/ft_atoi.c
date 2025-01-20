/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:23:18 by junhapar          #+#    #+#             */
/*   Updated: 2024/02/16 14:25:56 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_except_atoi(unsigned long long n);

int	ft_atoi(const char *str)
{
	size_t				i_str;
	int					sign;
	unsigned long long	result;

	i_str = 0;
	while (str[i_str] == '\t' || str[i_str] == '\n' || str[i_str] == '\v'
		|| str[i_str] == '\f' || str[i_str] == '\r' || str[i_str] == ' ')
		i_str++;
	sign = 1;
	if (str[i_str] == '+' || str[i_str] == '-')
	{
		if (str[i_str] == '-')
			sign = -1;
		i_str++;
	}
	result = 0;
	while ('0' <= str[i_str] && str[i_str] <= '9')
		result = result * 10 + (str[i_str++] - '0');
	if (ft_except_atoi(result))
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int)(sign * result));
}

static int	ft_except_atoi(unsigned long long n)
{
	long long	compare;

	compare = (long long)n;
	while (1)
	{
		if (compare % 10 != n % 10)
			return (1);
		compare /= 10;
		n /= 10;
		if (compare == 0)
			break ;
	}
	return (0);
}
