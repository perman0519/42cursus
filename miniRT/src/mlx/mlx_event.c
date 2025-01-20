/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:39:23 by junhapar          #+#    #+#             */
/*   Updated: 2024/02/22 17:16:30 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	key_press(int keycode, t_info *info);
int	close_win_with_x(void);

void	mlx_event(t_info *info)
{
	mlx_hook(info->mlx->mlx_win, KEYPRESS, 0, key_press, info);
	mlx_hook(info->mlx->mlx_win, X_BUTTON, 0, close_win_with_x, info);
}

void	help_move(t_info *info, int keycode)
{
	if (keycode == KEY_A)
		info->camera = camera_create(vec_plus_v(info->camera.origin, \
		vec_mult(info->camera.dir_viewpoint_h, -1)), \
		info->camera.unit_dir, info->camera.fov);
	else if (keycode == KEY_D)
		info->camera = camera_create(vec_plus_v(info->camera.origin, \
		info->camera.dir_viewpoint_h), info->camera.unit_dir, info->camera.fov);
	else if (keycode == KEY_W)
		info->camera = camera_create(vec_plus_v(info->camera.origin, \
		info->camera.unit_dir), info->camera.unit_dir, info->camera.fov);
	else if (keycode == KEY_S)
		info->camera = camera_create(vec_plus_v(info->camera.origin, \
		vec_mult(info->camera.unit_dir, -1)), \
		info->camera.unit_dir, info->camera.fov);
	minirt_loop(info);
}

void	help_rotate(t_info *info, int keycode)
{
	if (keycode == KEY_LEFT)
		info->camera = camera_create(info->camera.origin, \
		(vec_plus_v(info->camera.unit_dir, \
		vec_mult(info->camera.dir_viewpoint_h, -0.1))), info->camera.fov);
	else if (keycode == KEY_RIGHT)
		info->camera = camera_create(info->camera.origin, \
		(vec_plus_v(info->camera.unit_dir, \
		vec_mult(info->camera.dir_viewpoint_h, 0.1))), info->camera.fov);
	else if (keycode == KEY_UP)
		info->camera = camera_create(info->camera.origin, \
		(vec_plus_v(info->camera.unit_dir, \
		vec_create(0, 0.1, 0))), info->camera.fov);
	else if (keycode == KEY_DOWN)
		info->camera = camera_create(info->camera.origin, \
		(vec_plus_v(info->camera.unit_dir, \
		vec_create(0, -0.1, 0))), info->camera.fov);
	minirt_loop(info);
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
	{
		ft_lstclear(&(info->object), free);
		exit(0);
	}
	else if (KEY_LEFT <= keycode && keycode <= KEY_UP)
		help_rotate(info, keycode);
	else if ((KEY_A <= keycode && keycode <= KEY_D) || keycode == KEY_W)
		help_move(info, keycode);
	return (0);
}

int	close_win_with_x(void)
{
	exit(0);
}
