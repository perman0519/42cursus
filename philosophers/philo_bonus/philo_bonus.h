/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:30:45 by junssong          #+#    #+#             */
/*   Updated: 2023/12/19 12:01:55 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <signal.h>

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
	sem_t		*forks_sem;
	sem_t		*print_sem;
	sem_t		*eat_count_sem;
	t_arg		*arg;
}			t_share;

typedef struct s_philo
{
	int				id;
	pthread_t		monitoring_thread;
	t_arg			*arg_t;
	t_share			*share_t;
	int				eating_count;
	unsigned long	time_of_start;
	sem_t			*time_to_eat_sem;
	unsigned long	time_to_eat;
}			t_philo;

// util
void			print_error(int errn);
long long		ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

int				init_arg(t_arg *arg, int argc, char *argv[]);
int				init_share_t(t_share *share, t_arg *arg);
int				init_philo(t_philo *(philo_array)[], \
							t_arg *arg, t_share *share);
void			*process_main(void *argu);
int				start_process(t_philo *(philos)[], t_arg *arg);
void			*monitor(void *data);

unsigned long	get_time(void);
int				print_process(t_philo *philo, t_share *share, char *msg);
int				eat_philo(t_philo *philo, t_arg *arg, t_share *share);
int				usleep_process(unsigned long wait_time);

#endif
