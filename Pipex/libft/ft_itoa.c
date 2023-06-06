/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:43:04 by junssong          #+#    #+#             */
/*   Updated: 2023/05/26 20:02:59 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_n_size(int n)
{
	int	n_size;

	n_size = 0;
	if (n < 0)
		++n_size;
	if (n == 0)
		++n_size;
	else
	{
		while (n != 0)
		{
			n /= 10;
			++n_size;
		}
	}
	return (n_size);
}

static void	return_array(char *return_arr, int n, int n_size)
{
	int	i;

	if (n < 0)
	{
		return_arr[0] = '-';
		n *= -1;
	}
	i = n_size - 1;
	while (n != 0)
	{
		return_arr[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*return_arr;
	int		n_size;

	n_size = return_n_size(n);
	return_arr = (char *)malloc(sizeof(char) * (n_size + 1));
	if (!return_arr)
		return ("");
	return_arr[n_size] = '\0';
	if (n == -2147483648)
	{
		ft_strlcpy(return_arr, "-2147483648", n_size + 1);
		return (return_arr);
	}
	if (n == 0)
	{
		return_arr[0] = '0';
		return (return_arr);
	}
	return_array(return_arr, n, n_size);
	return (return_arr);
}
