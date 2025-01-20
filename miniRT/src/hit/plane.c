/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:02:17 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 13:39:10 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	set_vars(t_info *info, t_plane *plane, t_hit_info *vars,
				double *cos_cam_with_plane);
static int	is_root_exist(t_info *info, t_hit_info *vars);
static void	set_rec(t_info *info, t_plane *plane, t_hit_info *vars,
				double *cos_cam_with_plane);

int	is_hit_plane(t_info *info, t_plane *plane)
{
	t_hit_info	math_vars;
	double		cos_cam_with_plane;

	cos_cam_with_plane = vec_dot(info->ray.unit_dir, plane->normal_dir);
	if (cos_cam_with_plane == 0)
		return (FALSE);
	set_vars(info, plane, &math_vars, &cos_cam_with_plane);
	if (is_root_exist(info, &math_vars))
	{
		set_rec(info, plane, &math_vars, &cos_cam_with_plane);
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_vars(t_info *info, t_plane *plane, t_hit_info *vars,
			double *cos_cam_with_plane)
{
	vars->const_d = vec_dot(plane->normal_dir, plane->origin) * -1;
	vars->t = (vec_dot(info->ray.origin, plane->normal_dir) + vars->const_d)
		* -1 / (*cos_cam_with_plane);
}

static int	is_root_exist(t_info *info, t_hit_info *vars)
{
	if (vars->t >= 0)
	{
		if (vars->t < info->rec.t_min || info->rec.t_max < vars->t)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

static void	set_rec(t_info *info, t_plane *plane, t_hit_info *vars,
				double *cos_cam_with_plane)
{
	info->rec.t_max = vars->t;
	info->rec.origin = vec_plus_v(info->ray.origin,
			vec_mult(info->ray.unit_dir, vars->t));
	info->rec.normal_dir = plane->normal_dir;
	info->rec.color = plane->color;
	if ((*cos_cam_with_plane) > 0)
		info->rec.normal_dir = vec_mult(info->rec.normal_dir, -1);
}

int	is_hit_cylinder_plane(t_info *info, t_plane *plane, float r)
{
	t_hit_info	math_vars;
	double		cos_cam_with_plane;
	t_point		rec_origin;

	cos_cam_with_plane = vec_dot(info->ray.unit_dir, plane->normal_dir);
	if (cos_cam_with_plane == 0)
		return (FALSE);
	set_vars(info, plane, &math_vars, &cos_cam_with_plane);
	if (math_vars.t >= 0)
	{
		if (math_vars.t < info->rec.t_min || info->rec.t_max < math_vars.t)
			return (FALSE);
		rec_origin = vec_plus_v(info->ray.origin,
				vec_mult(info->ray.unit_dir, math_vars.t));
		if (vec_len(vec_minus_v(plane->origin, rec_origin)) > r)
			return (FALSE);
		set_rec(info, plane, &math_vars, &cos_cam_with_plane);
		return (TRUE);
	}
	return (FALSE);
}
