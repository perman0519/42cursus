/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:29:58 by junssong          #+#    #+#             */
/*   Updated: 2023/12/19 11:59:30 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	make_philo_t(t_philo *philo_t, t_arg *arg, \
						t_share *share_t, int philo_num);

int	init_philo(t_philo *(philo_array)[], t_arg *arg, t_share *share)
{
	int		i;

	i = 0;
	*philo_array = (t_philo *)malloc(sizeof(t_philo) \
					* arg->number_of_philo);
	if (*philo_array == NULL)
	{
		print_error(3);
		return (3);
	}
	while (i < arg->number_of_philo)
	{
		if (make_philo_t(&((*philo_array)[i]), arg, share, i + 1) != 0)
		{
			free (*philo_array);
			print_error(3);
			return (3);
		}
		i++;
	}
	return (0);
}

static int	make_philo_t(t_philo *philo_t, t_arg *arg, \
						t_share *share_t, int philo_num)
{
	char	*str_id;
	char	*strjoin_sem;

	str_id = ft_itoa(philo_num);
	if (str_id == NULL)
		return (1);
	strjoin_sem = ft_strjoin("time_to_eat", str_id);
	if (strjoin_sem == NULL)
		return (1);
	free(str_id);
	sem_unlink(strjoin_sem);
	philo_t->time_to_eat_sem = sem_open(strjoin_sem, O_CREAT | O_EXCL, 0644, 1);
	if (philo_t->time_to_eat_sem == SEM_FAILED)
		return (1);
	philo_t->id = philo_num;
	philo_t->time_to_eat = 0;
	philo_t->eating_count = 0;
	philo_t->arg_t = arg;
	philo_t->share_t = share_t;
	free(strjoin_sem);
	return (0);
}
