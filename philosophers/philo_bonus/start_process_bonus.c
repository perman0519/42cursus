/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:01:28 by junssong          #+#    #+#             */
/*   Updated: 2023/12/18 17:47:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_philos(int philo_num, pid_t *child_arr);
void	help_start_process(t_philo *(philos)[], t_arg *arg, \
							unsigned long now, pid_t *child_arr);

int	start_process(t_philo *(philos)[], t_arg *arg)
{
	pid_t			*child_arr;
	unsigned long	now;

	now = get_time();
	child_arr = (pid_t *)malloc(sizeof(pid_t) \
					* (*philos[0]).arg_t->number_of_philo);
	if (child_arr == NULL)
		exit(1);
	help_start_process(philos, arg, now, child_arr);
	return (0);
}

void	help_start_process(t_philo *(philos)[], t_arg *arg, \
							unsigned long now, pid_t *child_arr)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philo)
	{
		(*philos)[i].time_of_start = now;
		(*philos)[i].time_to_eat = now;
		sem_post((*philos)[i].time_to_eat_sem);
		child_arr[i] = fork();
		if (child_arr[i] == 0)
		{
			if (pthread_create(&((*philos)[i].monitoring_thread), \
				NULL, monitor, &((*philos)[i])) != 0)
				exit(1);
			process_main(&((*philos)[i]));
			if (pthread_join((*philos)[i].monitoring_thread, NULL))
				exit(1);
		}
		i++;
	}
	wait_philos(arg->number_of_philo, child_arr);
}

void	wait_philos(int philo_num, pid_t *child_arr)
{
	int	status;
	int	i;

	i = philo_num;
	while (philo_num--)
	{
		waitpid(-1, &status, 0);
		if (status == 256)
			break ;
	}
	i = 0;
	while (i < philo_num)
	{
		kill(child_arr[i], SIGKILL);
		i++;
	}
	free (child_arr);
}
