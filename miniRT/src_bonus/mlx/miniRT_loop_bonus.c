/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:40:32 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:58 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;
	t_image	*img;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pthread_mutex_lock(&(info->mlx_img_mutex));
	img = &(info->mlx->image);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	pthread_mutex_unlock(&(info->mlx_img_mutex));
}

int	minirt_loop(t_info *info)
{
	int		i;
	int		end_i;
	int		j;
	t_ray	ray;

	pthread_mutex_lock(&info->start_i_mutex);
	i = info->start_i * (WIN_HEIGHT / NUM_THREAD);
	end_i = (info->start_i + 1) * (WIN_HEIGHT / NUM_THREAD);
	if (info->start_i == 8)
		end_i = WIN_HEIGHT;
	info->start_i++;
	pthread_mutex_unlock(&(info->start_i_mutex));
	while (i < end_i)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			ray = ray_primary(info, (double)j / (WIN_WIDTH - 1),
					(double)i / (WIN_HEIGHT - 1));
			my_mlx_pixel_put(info, j, WIN_HEIGHT - i, ray_color(info, &ray));
			j++;
		}
		i++;
	}
	return (0);
}
