/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:47:56 by junssong          #+#    #+#             */
/*   Updated: 2023/12/19 11:14:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *data)
{
	t_share			*share;
	t_arg			*arg;
	t_philo			*philo;
	unsigned long	now;

	philo = (t_philo *)data;
	arg = philo->arg_t;
	share = philo->share_t;
	while (1)
	{
		now = get_time();
		sem_wait(philo->time_to_eat_sem);
		if (now - philo->time_to_eat >= (unsigned long)arg->time_to_die)
		{
			sem_post(philo->time_to_eat_sem);
			print_process(philo, share, "died");
			exit(1);
		}
		else
			sem_post(philo->time_to_eat_sem);
		usleep(1000);
	}
	return (NULL);
}
