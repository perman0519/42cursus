/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:13:21 by junssong          #+#    #+#             */
/*   Updated: 2023/03/29 11:13:22 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_null(const char *str);
static int	printf_help(const char *str, va_list arg_ptr, int *count);
static int	loop_str(const char *str, int count, va_list arg_ptr);
static int	ft_putpercent(void);

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		count;

	count = 0;
	if (is_null(str))
		return (6);
	va_start(arg_ptr, str);
	count = loop_str(str, count, arg_ptr);
	va_end(arg_ptr);
	return (count);
}

static int	is_null(const char *str)
{
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	loop_str(const char *str, int count, va_list arg_ptr)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (printf_help(str, arg_ptr, &count) == -1)
				return (-1);
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			count += 1;
		}
		str++;
	}
	return (count);
}

static int	printf_help(const char *str, va_list arg_ptr, int *count)
{
	int	size;

	size = 0;
	if (*str == 'd' || *str == 'i')
		size = ft_putnbr(va_arg(arg_ptr, int));
	else if (*str == 'u')
		size = ft_putnbr_unsigned(va_arg(arg_ptr, unsigned int));
	else if (*str == 'p')
		size = ft_putpoint(va_arg(arg_ptr, void *));
	else if (*str == 'x')
		size = ft_puthex_small(va_arg(arg_ptr, unsigned int));
	else if (*str == 'X')
		size = ft_puthex_large(va_arg(arg_ptr, unsigned int));
	else if (*str == 'c')
		size = ft_putchar(va_arg(arg_ptr, int));
	else if (*str == 's')
		size = ft_putstr(va_arg(arg_ptr, char *));
	else if (*str == '%')
		size = ft_putpercent();
	if (size == -1)
		return (-1);
	*count += size;
	return (0);
}

static int	ft_putpercent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
