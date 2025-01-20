/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:19:56 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/21 21:11:30 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	ray_primary(t_info *info, double u, double v)
{
	t_ray	ray;
	t_vec	mv_h;
	t_vec	mv_v;

	ray.origin = info->camera.origin;
	mv_h = vec_mult(vec_mult(info->camera.dir_viewpoint_h, \
				info->camera.width_viewpoint), u);
	mv_v = vec_mult(vec_mult(info->camera.dir_viewpoint_v, \
				info->camera.height_viewpoint), v);
	ray.unit_dir = vec_unit(vec_minus_v(vec_plus_v \
	(vec_plus_v(info->camera.left_bottom, mv_h), mv_v), info->camera.origin));
	return (ray);
}

int	ray_color(t_info *info)
{
	t_color	color;

	info->rec = rec_create();
	if (is_hit(info))
		color = phong_lighting(info);
	else
		color = color_create(1, 1, 1);
	color = color_create(fmin(color.x, 1), fmin(color.y, 1), fmin(color.z, 1));
	color = color_create(fmax(color.x, 0), fmax(color.y, 0), fmax(color.z, 0));
	color.x *= 255.999;
	color.y *= 255.999;
	color.z *= 255.999;
	return (((int)color.x << 16) + ((int)color.y << 8) + ((int)color.z));
}
