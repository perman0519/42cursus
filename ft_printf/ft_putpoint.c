/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:09:41 by junssong          #+#    #+#             */
/*   Updated: 2023/03/30 12:09:42 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_ptrnum_zero(unsigned long long ptr_num, char *temp,
				char *hex, int *size);

int	ft_putpoint(void *ptr)
{
	unsigned long long	ptr_num;
	char				*hex;
	char				temp[19];
	int					size;
	int					i;

	ptr_num = (unsigned long long)ptr;
	hex = "0123456789abcdef";
	size = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ptr_num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (size + 1);
	}
	i = is_ptrnum_zero(ptr_num, temp, hex, &size);
	temp[i] = '\0';
	while (i--)
		if (write(1, &temp[i], 1) == -1)
			return (-1);
	return (size);
}

static int	is_ptrnum_zero(unsigned long long ptr_num, char *temp
				, char *hex, int *size)
{
	int	i;

	i = 0;
	while (ptr_num != 0)
	{
		temp[i] = hex[ptr_num % 16];
		ptr_num /= 16;
		i++;
		++*size;
	}
	return (i);
}
