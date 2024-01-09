/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:46 by junssong          #+#    #+#             */
/*   Updated: 2023/12/22 10:38:07 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_main(void *argu)
{
	t_philo	*philo;
	t_share	*share;

	philo = (t_philo *)argu;
	share = philo->share_t;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (is_all_alive(share))
	{
		eat_philo(philo, philo->arg_t, share);
		if (philo->arg_t->number_of_philo == 1)
			break ;
		if (philo->eating_count == philo->arg_t->each_philo_must_eat)
		{
			pthread_mutex_lock(&(share->eat_count_mutex));
			share->eat_count++;
			pthread_mutex_unlock(&(share->eat_count_mutex));
			break ;
		}
		print_thread(philo, share, "is sleeping");
		usleep_thread(share, philo->arg_t->time_to_sleep);
		print_thread(philo, share, "is thinking");
	}
	return (NULL);
}
