/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:46 by junssong          #+#    #+#             */
/*   Updated: 2023/12/19 11:06:31 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*process_main(void *argu)
{
	t_philo	*philo;
	t_arg	*arg;
	t_share	*share;

	philo = (t_philo *)argu;
	arg = philo->arg_t;
	share = philo->share_t;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (1)
	{
		eat_philo(philo, arg, share);
		if (arg->number_of_philo == 1)
			break ;
		if (philo->eating_count == arg->each_philo_must_eat)
		{
			sem_wait(share->eat_count_sem);
			sem_post(share->eat_count_sem);
			exit (2);
		}
		print_process(philo, share, "is sleeping");
		usleep_process(arg->time_to_sleep);
		print_process(philo, share, "is thinking");
	}
	return (NULL);
}
