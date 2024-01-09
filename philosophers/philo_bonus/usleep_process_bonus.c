/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:10:06 by junssong          #+#    #+#             */
/*   Updated: 2023/12/19 11:03:51 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	usleep_process(unsigned long wait_time)
{
	unsigned long	start;

	start = get_time();
	while (1)
	{
		if ((get_time() - start) >= wait_time)
			return (0);
		usleep(200);
	}
	return (0);
}
