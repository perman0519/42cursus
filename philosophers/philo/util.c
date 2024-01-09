/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:39:20 by junssong          #+#    #+#             */
/*   Updated: 2023/12/22 09:22:05 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
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
		value = 10 * temp + (str[i++] - '0');
		temp = value;
	}
	if ((str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9')))
		return (0);
	if (sign * value > 2147483647)
		return (0);
	return (sign * value);
}

void	print_error(int errn)
{
	if (errn == 1)
		printf("Error: number of arguments.\n");
	else if (errn == 2)
		printf("Error: Invalid arguments.\n");
	else if (errn == 3)
		printf("Error: Invalid arguments.\n");
}

int	is_all_alive(t_share *share)
{
	int	all_alive;

	pthread_mutex_lock(&(share->all_alive_mutex));
	all_alive = share->all_alive;
	pthread_mutex_unlock(&(share->all_alive_mutex));
	return (all_alive);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}
