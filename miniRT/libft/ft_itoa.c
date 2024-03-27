/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:24:31 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 23:00:24 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_n_len(int n);
static void		ft_make_result(char *result, int result_size, int n);

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	size = ft_find_n_len(n);
	result = malloc(size + 1);
	if (!(result))
		return (0);
	ft_make_result(result, size, n);
	return (result);
}

static int	ft_find_n_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (1)
	{
		len++;
		n = n / 10;
		if (n == 0)
			break ;
	}
	return (len);
}

static void	ft_make_result(char *result, int result_size, int n)
{
	long long	num;
	int			i;

	i = 0;
	if (n < 0)
	{
		result[i++] = '-';
		num = (long long)n * -1;
	}
	else
		num = n;
	result[result_size] = '\0';
	while (i < result_size)
	{
		result[result_size - 1] = (num % 10) + '0';
		num /= 10;
		result_size--;
	}
}
