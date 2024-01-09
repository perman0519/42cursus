/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:30:45 by junssong          #+#    #+#             */
/*   Updated: 2023/12/19 11:58:20 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_arg
{
	int		number_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		each_philo_must_eat;
}			t_arg;

typedef struct s_share
{
	pthread_mutex_t	*forks_mutexes;
	int				*forks_array;
	pthread_mutex_t	all_alive_mutex;
	int				all_alive;
	pthread_mutex_t	eat_count_mutex;
	int				eat_count;
}			t_share;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_arg			*arg_t;
	t_share			*share_t;
	int				eating_count;
	int				left_fork;
	int				right_fork;
	unsigned long	time_of_start;
	pthread_mutex_t	time_to_eat_mutex;
	unsigned long	time_to_eat;
}			t_philo;

// util
long long		ft_atoi(const char *str);
void			print_error(int errn);

int				init_arg(t_arg *arg, int argc, char *argv[]);
int				init_philo(t_philo *(philo_array)[], t_arg *arg);
void			*thread_main(void *argu);
int				start_threads(t_philo *(philos)[], t_arg *arg);
int				monitor(t_philo *(philos)[], t_arg *arg);

unsigned long	get_time(void);
int				is_all_alive(t_share *share);
int				print_thread(t_philo *philo, t_share *share, char *msg);
int				eat_philo(t_philo *philo, t_arg *arg, t_share *share);
int				usleep_thread(t_share *share, unsigned long wait_time);

#endif
