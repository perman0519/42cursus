/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:07:06 by junssong          #+#    #+#             */
/*   Updated: 2023/12/19 11:06:45 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	usleep_thread(t_share *share, unsigned long wait_time)
{
	unsigned long	start;

	start = get_time();
	while (1)
	{
		if ((get_time() - start) >= wait_time || !is_all_alive(share))
			return (0);
		usleep(200);
	}
	return (0);
}
