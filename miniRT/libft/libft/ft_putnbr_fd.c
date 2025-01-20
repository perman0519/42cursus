/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:34:29 by junhapar          #+#    #+#             */
/*   Updated: 2023/03/28 22:58:48 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_n(long long n, int fd, int flag);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_write_n((long long)n * -1, fd, 1);
	}
	else
		ft_write_n((long long)n, fd, 1);
}

static void	ft_write_n(long long n, int fd, int flag)
{
	if (n == 0 && flag == 0)
		return ;
	ft_write_n(n / 10, fd, 0);
	ft_putchar_fd(n % 10 + '0', fd);
}
