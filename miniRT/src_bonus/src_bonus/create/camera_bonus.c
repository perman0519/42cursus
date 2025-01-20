/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:22:02 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:59 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_camera	camera_create(t_point origin, t_vec dir, int FOV)
{
	t_camera	camera;

	camera.origin = origin;
	camera.unit_dir = vec_unit(dir);
	camera.width_viewpoint = VIEWPOINT_W;
	camera.height_viewpoint = VIEWPOINT_W * WIN_HEIGHT / WIN_WIDTH;
	camera.foacl_len = (((int)VIEWPOINT_W >> 1)) / tan((FOV >> 1) * M_PI / 180);
	camera.fov = FOV;
	if (vec_len(vec_cross(camera.unit_dir, vec_create(0, 1, 0))) != 0)
		camera.dir_viewpoint_h = vec_unit(vec_mult(vec_cross(camera.unit_dir, \
										vec_create(0, 1, 0)), 1));
	else
		camera.dir_viewpoint_h = vec_unit(vec_mult(vec_cross(camera.unit_dir, \
												vec_create(0, 0, 1)), 1));
	camera.dir_viewpoint_v = vec_unit(vec_mult(vec_cross(camera.unit_dir, \
								camera.dir_viewpoint_h), -1));
	camera.left_bottom = vec_minus_v(vec_minus_v(vec_plus_v(camera.origin, \
		vec_mult(camera.unit_dir, camera.foacl_len)), \
			vec_mult(camera.dir_viewpoint_h, camera.width_viewpoint / 2)), \
				vec_mult(camera.dir_viewpoint_v, camera.height_viewpoint / 2));
	return (camera);
}
