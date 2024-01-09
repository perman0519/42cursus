/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:21:00 by junssong          #+#    #+#             */
/*   Updated: 2023/12/18 17:10:13 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	eat_philo(t_philo *philo, t_arg *arg, t_share *share)
{
	sem_wait(share->forks_sem);
	print_process(philo, share, "has taken a fork");
	if (arg->number_of_philo != 1)
	{
		sem_wait(share->forks_sem);
		print_process(philo, share, "has taken a fork");
		print_process(philo, share, "is eating");
		usleep_process(arg->time_to_eat);
		philo->eating_count++;
		sem_post(share->forks_sem);
	}
	else
		usleep_process(arg->time_to_die);
	sem_post(share->forks_sem);
	return (0);
}
