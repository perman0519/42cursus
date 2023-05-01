/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:31:01 by junssong          #+#    #+#             */
/*   Updated: 2023/03/29 16:31:02 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_null(int num);

int	ft_puthex_small(unsigned int num)
{
	char	*hex;
	char	temp[9];
	int		size;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	size = is_null(num);
	if (size == -1)
		return (-1);
	else if (size == 1)
		return (1);
	while (num != 0)
	{
		temp[i] = hex[num % 16];
		num /= 16;
		i++;
		size += 1;
	}
	temp[i] = '\0';
	while (i--)
		if (write(1, &temp[i], 1) == -1)
			return (-1);
	return (size);
}

int	ft_puthex_large(unsigned int num)
{
	char	*hex;
	char	temp[9];
	int		size;
	int		i;

	hex = "0123456789ABCDEF";
	i = 0;
	size = is_null(num);
	if (size == -1)
		return (-1);
	else if (size == 1)
		return (1);
	while (num != 0)
	{
		temp[i] = hex[num % 16];
		num /= 16;
		i++;
		size += 1;
	}
	temp[i] = '\0';
	while (i--)
		if (write(1, &temp[i], 1) == -1)
			return (-1);
	return (size);
}

static int	is_null(int num)
{
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}
