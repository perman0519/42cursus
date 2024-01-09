/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_share_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:12:40 by junssong          #+#    #+#             */
/*   Updated: 2023/12/18 17:10:19 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_t_share_sem(t_share *share, int fork_count);

int	init_share_t(t_share *share, t_arg *arg)
{
	share->arg = arg;
	if (init_t_share_sem(share, arg->number_of_philo) == 1)
	{
		print_error(3);
		return (3);
	}
	return (0);
}

static int	init_t_share_sem(t_share *share, int fork_count)
{
	sem_unlink("forks_sem");
	share->forks_sem = sem_open("forks_sem", \
									O_CREAT | O_EXCL, 644, fork_count);
	if (share->forks_sem == SEM_FAILED)
		return (1);
	sem_unlink("print_sem");
	share->print_sem = sem_open("print_sem", O_CREAT | O_EXCL, 0644, 1);
	if (share->forks_sem == SEM_FAILED)
		return (1);
	sem_unlink("eat_count_sem");
	share->eat_count_sem = sem_open("eat_count_sem", \
										O_CREAT | O_EXCL, 0644, 1);
	if (share->forks_sem == SEM_FAILED)
	{
		sem_close(share->print_sem);
		return (1);
	}
	return (0);
}
