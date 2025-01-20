/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:39:23 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:22:16 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	create_thread(t_info *info)
{
	pthread_t	pthread[NUM_THREAD];
	int			nth_pthread;

	nth_pthread = 0;
	info->start_i = 0;
	while (nth_pthread < NUM_THREAD)
	{
		if (pthread_create(&(pthread[nth_pthread]), NULL, \
			(void *)minirt_loop, info))
			str_exit("Error\npthread_create_fail.\n");
		nth_pthread++;
	}
	nth_pthread = 0;
	while (nth_pthread < NUM_THREAD)
	{
		if (pthread_join(pthread[nth_pthread], NULL) != 0)
			str_exit("Error\npthread_join_fail.\n");
		nth_pthread++;
	}
	pthread_mutex_lock(&(info->mlx_img_mutex));
	mlx_put_image_to_window(info->mlx->mlx, info->mlx->mlx_win, \
						info->mlx->image.img, 0, 0);
	pthread_mutex_unlock(&(info->mlx_img_mutex));
}
