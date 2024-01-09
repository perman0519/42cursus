/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:09:21 by junssong          #+#    #+#             */
/*   Updated: 2023/12/18 17:11:01 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_process(t_philo *philo, t_share *share, char *msg)
{
	unsigned long	now;

	sem_wait(share->print_sem);
	now = get_time();
	if (now == 0)
		return (-1);
	if (msg[3] == 'e')
	{
		sem_wait(philo->time_to_eat_sem);
		philo->time_to_eat = now;
		sem_post(philo->time_to_eat_sem);
	}
	printf("%lu %d %s\n", now - philo->time_of_start, philo->id, msg);
	if (msg[3] == 'd')
		exit(1);
	sem_post(share->print_sem);
	return (0);
}
