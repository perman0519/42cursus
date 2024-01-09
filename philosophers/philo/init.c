/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:29:58 by junssong          #+#    #+#             */
/*   Updated: 2023/12/22 10:34:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_t_share_mutex(t_share *t_share, int fork_count);
static int	make_share_t(t_share *share_t, t_arg *arg);
static int	make_philo_t(t_philo *philo_t, t_arg *arg, \
						t_share *share_t, int philo_num);

int	init_philo(t_philo *(philo_array)[], t_arg *arg)
{
	t_share	*share_t;
	int		i;

	i = 0;
	share_t = (t_share *)malloc(sizeof(t_share));
	if (make_share_t(share_t, arg))
		return (1);
	*philo_array = (t_philo *)malloc(sizeof(t_philo) \
					* arg->number_of_philo);
	if (philo_array == NULL)
	{
		free(share_t);
		return (1);
	}
	while (i < arg->number_of_philo)
	{
		if (make_philo_t(&((*philo_array)[i]), arg, share_t, i + 1) != 0)
		{
			free (share_t);
			free (philo_array);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_arg(t_arg *arg, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (1);
	arg->number_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (arg->number_of_philo <= 0 || arg->time_to_die <= 0 || \
		arg->time_to_eat <= 0 || arg ->time_to_sleep <= 0)
		return (2);
	if (argc == 6)
	{
		arg->each_philo_must_eat = ft_atoi(argv[5]);
		if (arg->each_philo_must_eat <= 0)
			return (2);
	}
	return (0);
}

static int	init_t_share_mutex(t_share *t_share, int fork_count)
{
	int	i;

	i = 0;
	while (i < fork_count)
	{
		if (pthread_mutex_init(&(t_share->forks_mutexes[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(t_share->eat_count_mutex), NULL))
		return (1);
	if (pthread_mutex_init(&(t_share->all_alive_mutex), NULL))
		return (1);
	return (0);
}

static int	make_share_t(t_share *share_t, t_arg *arg)
{
	if (share_t == NULL)
		return (1);
	share_t->forks_array = (int *)malloc(sizeof(int) * arg->number_of_philo);
	share_t->forks_mutexes = (pthread_mutex_t *) \
				malloc(sizeof(pthread_mutex_t) * arg->number_of_philo);
	if (share_t->forks_array == NULL)
	{
		free(share_t);
		return (1);
	}
	if (share_t->forks_mutexes == NULL)
	{
		free(share_t->forks_array);
		free(share_t);
		return (1);
	}
	share_t->all_alive = 1;
	share_t->eat_count = 0;
	if (init_t_share_mutex(share_t, arg->number_of_philo) == 1)
		printf("is failed\n");
	return (0);
}

static int	make_philo_t(t_philo *philo_t, t_arg *arg, \
						t_share *share_t, int philo_num)
{
	philo_t->id = philo_num;
	philo_t->time_to_eat = 0;
	philo_t->eating_count = 0;
	philo_t->arg_t = arg;
	philo_t->left_fork = philo_num - 1;
	philo_t->right_fork = (philo_num - 1 + 1) % arg->number_of_philo;
	philo_t->share_t = share_t;
	if (pthread_mutex_init(&(philo_t->time_to_eat_mutex), NULL))
		return (1);
	return (0);
}
