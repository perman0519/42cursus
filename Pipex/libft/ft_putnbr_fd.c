/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:29:09 by junssong          #+#    #+#             */
/*   Updated: 2023/03/23 16:29:10 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	n_chr[15];
	size_t	i;
	long	n_long;

	n_long = (long)n;
	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n_long *= -1;
	}
	while (n_long != 0)
	{
		n_chr[i++] = '0' + (n_long % 10);
		n_long /= 10;
	}
	n_chr[i] = '\0';
	while (i--)
		write(fd, &n_chr[i], 1);
}
