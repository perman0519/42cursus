/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:56:47 by junssong          #+#    #+#             */
/*   Updated: 2023/12/18 17:10:16 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_arg(t_arg *arg, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		print_error(1);
		return (1);
	}
	arg->number_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (arg->number_of_philo <= 0 || arg->time_to_die <= 0 || \
		arg->time_to_eat <= 0 || arg ->time_to_sleep <= 0)
	{
		print_error(1);
		return (1);
	}
	if (argc == 6)
	{
		arg->each_philo_must_eat = ft_atoi(argv[5]);
		if (arg->each_philo_must_eat <= 0)
		{
			print_error(1);
			return (1);
		}
	}
	return (0);
}
