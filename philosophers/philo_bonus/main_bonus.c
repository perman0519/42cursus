/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:23:40 by junssong          #+#    #+#             */
/*   Updated: 2023/12/18 17:49:34 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	destory_all_mutex(t_philo *(philos)[], t_arg *arg, t_share *share);

int	main(int argc, char *argv[])
{
	int		errn;
	t_arg	arg;
	t_share	share;
	t_philo	*philosopher_array;

	philosopher_array = NULL;
	errn = init_arg(&arg, argc, argv);
	if (errn)
		return (errn);
	errn = init_share_t(&share, &arg);
	if (errn)
		return (errn);
	errn = init_philo(&philosopher_array, &arg, &share);
	if (errn)
		return (errn);
	errn = start_process(&philosopher_array, &arg);
	destory_all_mutex(&philosopher_array, &arg, &share);
	free(philosopher_array);
	return (errn);
}

void	print_error(int errn)
{
	if (errn == 1)
		printf("Error: number of arguments.\n");
	else if (errn == 2)
		printf("Error: Invalid arguments.\n");
	else if (errn == 3)
		printf("Error: init failed.\n");
}

static void	destory_all_mutex(t_philo *(philos)[], t_arg *arg, t_share *share)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philo)
	{
		sem_close((*philos)[i].time_to_eat_sem);
		i++;
	}
	sem_close(share->forks_sem);
	sem_close(share->print_sem);
	sem_close(share->eat_count_sem);
}
