/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:02:17 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:58 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	set_vars(t_plane *plane, t_hit_info *vars,
				double *cos_cam_with_plane);
static int	is_root_exist(t_rec *rec, t_hit_info *vars);

int	is_hit_plane_shadow(t_plane *plane, t_light *light, t_rec *rec)
{
	t_hit_info	vars;
	double		cos_cam_with_plane;

	vars.v_rec_to_light.origin = rec->origin;
	vars.v_rec_to_light.unit_dir = vec_minus_v(light->origin, rec->origin);
	rec->t_max = vec_len(vars.v_rec_to_light.unit_dir);
	vars.v_rec_to_light.unit_dir = vec_unit(vars.v_rec_to_light.unit_dir);
	cos_cam_with_plane = vec_dot(vars.v_rec_to_light.unit_dir,
			plane->normal_dir);
	if (cos_cam_with_plane == 0)
		return (FALSE);
	set_vars(plane, &vars, &cos_cam_with_plane);
	if (is_root_exist(rec, &vars))
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

static int	is_root_exist(t_rec *rec, t_hit_info *vars)
{
	if (vars->t >= 0)
	{
		if (vars->t < rec->t_min || rec->t_max < vars->t)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

int	is_hit_cy_plane_shadow(t_plane *plane, double r, t_light *light, t_rec *rec)
{
	t_hit_info	vars;
	double		cos_cam_with_plane;

	vars.v_rec_to_light.origin = rec->origin;
	vars.v_rec_to_light.unit_dir = vec_minus_v(light->origin, rec->origin);
	rec->t_max = vec_len(vars.v_rec_to_light.unit_dir);
	vars.v_rec_to_light.unit_dir = vec_unit(vars.v_rec_to_light.unit_dir);
	cos_cam_with_plane = vec_dot(vars.v_rec_to_light.unit_dir,
			plane->normal_dir);
	if (cos_cam_with_plane == 0)
		return (FALSE);
	set_vars(plane, &vars, &cos_cam_with_plane);
	if (vars.t >= 0)
	{
		if (vars.t < rec->t_min || rec->t_max < vars.t)
			return (FALSE);
		if (vec_len(vec_minus_v(plane->origin,
					vec_plus_v(vars.v_rec_to_light.origin,
						vec_mult(vars.v_rec_to_light.unit_dir, vars.t)))) > r)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}
