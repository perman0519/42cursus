/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:02:17 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 13:40:40 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	set_vars(t_plane *plane, t_hit_info *vars,
				double *cos_cam_with_plane);
static int	is_root_exist(t_info *info, t_hit_info *vars);

int	is_hit_plane_shadow(t_info *info, t_plane *plane)
{
	t_hit_info	vars;
	double		cos_cam_with_plane;

	vars.v_rec_to_light.origin = info->rec.origin;
	vars.v_rec_to_light.unit_dir = vec_minus_v(info->light.origin,
			info->rec.origin);
	info->rec.t_max = vec_len(vars.v_rec_to_light.unit_dir);
	vars.v_rec_to_light.unit_dir = vec_unit(vars.v_rec_to_light.unit_dir);
	cos_cam_with_plane = vec_dot(vars.v_rec_to_light.unit_dir,
			plane->normal_dir);
	if (cos_cam_with_plane == 0)
		return (FALSE);
	set_vars(plane, &vars, &cos_cam_with_plane);
	if (is_root_exist(info, &vars))
		return (TRUE);
	else
		return (FALSE);
}

static void	set_vars(t_plane *plane, t_hit_info *vars,
				double *cos_cam_with_plane)
{
	vars->const_d = vec_dot(plane->normal_dir, plane->origin) * -1;
	vars->t = (vec_dot(vars->v_rec_to_light.origin, plane->normal_dir)
			+ vars->const_d) * -1 / *cos_cam_with_plane;
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

int	is_hit_cylinder_plane_shadow(t_info *info, t_plane *plane, float r)
{
	t_hit_info	vars;
	double		cos_cam_with_plane;

	vars.v_rec_to_light.origin = info->rec.origin;
	vars.v_rec_to_light.unit_dir = vec_minus_v(info->light.origin,
			info->rec.origin);
	info->rec.t_max = vec_len(vars.v_rec_to_light.unit_dir);
	vars.v_rec_to_light.unit_dir = vec_unit(vars.v_rec_to_light.unit_dir);
	cos_cam_with_plane = vec_dot(vars.v_rec_to_light.unit_dir,
			plane->normal_dir);
	if (cos_cam_with_plane == 0)
		return (FALSE);
	set_vars(plane, &vars, &cos_cam_with_plane);
	if (vars.t >= 0)
	{
		if (vars.t < info->rec.t_min || info->rec.t_max < vars.t)
			return (FALSE);
		if (vec_len(vec_minus_v(plane->origin,
					vec_plus_v(vars.v_rec_to_light.origin,
						vec_mult(vars.v_rec_to_light.unit_dir, vars.t)))) > r)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}
