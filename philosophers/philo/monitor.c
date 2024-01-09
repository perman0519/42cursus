/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:47:56 by junssong          #+#    #+#             */
/*   Updated: 2023/12/22 10:38:11 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_time_to_die(t_philo *(philos)[], t_arg *arg, t_share *share);

int	monitor(t_philo *(philos)[], t_arg *arg)
{
	t_share	*share;

	share = (*philos)[0].share_t;
	while (is_all_alive(share))
	{
		pthread_mutex_lock(&(share->eat_count_mutex));
		if ((arg->each_philo_must_eat != 0) && \
				arg->number_of_philo == share->eat_count)
		{
			pthread_mutex_unlock(&(share->eat_count_mutex));
			pthread_mutex_lock(&(share->all_alive_mutex));
			share->all_alive = 0;
			pthread_mutex_unlock(&(share->all_alive_mutex));
			return (0);
		}
		else
			pthread_mutex_unlock(&(share->eat_count_mutex));
		if (is_time_to_die(philos, arg, share))
			return (0);
		usleep(1000);
	}
	return (0);
}

static int	is_time_to_die(t_philo *(philos)[], t_arg *arg, t_share *share)
{
	int				i;
	unsigned long	now;

	i = 0;
	while (i < arg->number_of_philo)
	{
		now = get_time();
		pthread_mutex_lock(&((*philos)[i].time_to_eat_mutex));
		if (now - (*philos)[i].time_to_eat >= (unsigned long)arg->time_to_die)
		{
			pthread_mutex_unlock(&((*philos)[i].time_to_eat_mutex));
			pthread_mutex_lock(&(share->all_alive_mutex));
			share->all_alive = 0;
			printf("%lu %d %s\n", now - (*philos)[i].time_of_start, \
					(*philos)[i].id, "died");
			pthread_mutex_unlock(&(share->all_alive_mutex));
			return (1);
		}
		else
			pthread_mutex_unlock(&(*philos)[i].time_to_eat_mutex);
		i++;
	}
	return (0);
}
