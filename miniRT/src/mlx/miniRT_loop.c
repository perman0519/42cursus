/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:40:32 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/21 21:10:18 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;
	t_image	*img;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	img = &(info->mlx->image);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	minirt_loop(t_info *info)
{
	double	u;
	double	v;
	int		i;
	int		j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			u = (double)j / (WIN_WIDTH - 1);
			v = (double)i / (WIN_HEIGHT - 1);
			info->ray = ray_primary(info, u, v);
			my_mlx_pixel_put(info, j, WIN_HEIGHT - i, ray_color(info));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->mlx->mlx, info->mlx->mlx_win, \
						info->mlx->image.img, 0, 0);
	return (0);
}
