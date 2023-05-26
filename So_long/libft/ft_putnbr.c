/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:29:09 by junssong          #+#    #+#             */
/*   Updated: 2023/03/23 16:29:10 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_is_zero(int n);
static int	n_is_minus(int n, long *n_long, int *size);

int	ft_putnbr(int n)
{
	char	n_chr[15];
	size_t	i;
	long	n_long;
	int		size;

	n_long = (long)n;
	i = 0;
	size = n_is_zero(n);
	if (size == 1)
		return (1);
	else if (size == -1)
		return (-1);
	if (n_is_minus(n, &n_long, &size) == -1)
		return (-1);
	while (n_long != 0)
	{
		n_chr[i++] = '0' + (n_long % 10);
		n_long /= 10;
		size += 1;
	}
	n_chr[i] = '\0';
	while (i--)
		if (write(1, &n_chr[i], 1) == -1)
			return (-1);
	return (size);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	n_chr[15];
	size_t	i;
	long	n_long;
	int		size;

	n_long = (long)n;
	i = 0;
	size = n_is_zero(n);
	if (size == 1)
		return (1);
	else if (size == -1)
		return (-1);
	while (n_long != 0)
	{
		n_chr[i++] = '0' + (n_long % 10);
		n_long /= 10;
		size += 1;
	}
	n_chr[i] = '\0';
	while (i--)
		if (write(1, &n_chr[i], 1) == -1)
			return (-1);
	return (size);
}

static int	n_is_zero(int n)
{
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	n_is_minus(int n, long *n_long, int *size)
{
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		*n_long *= -1;
		*size += 1;
	}
	return (0);
}
