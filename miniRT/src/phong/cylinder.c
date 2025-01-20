/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:11:27 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 13:31:45 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	is_hit_cylinder_body_shadow(t_info *info, t_cylinder *cylinder);
static void	set_vars(t_cylinder *cylinder, t_hit_info *vars,
				t_vec *v_center_to_camera);
static int	is_root_exist(t_info *info, t_cylinder *cylinder, t_hit_info *vars,
				t_vec *v_center_to_camera);

int	is_hit_cylinder_shadow(t_info *info, t_cylinder *cylinder)
{
	t_plane	bot_plane;
	t_plane	top_plane;

	bot_plane = plane_create(cylinder->origin, cylinder->normal_dir,
			cylinder->color);
	top_plane = plane_create(vec_plus_v(cylinder->origin,
				vec_mult(cylinder->normal_dir, cylinder->height)),
			cylinder->normal_dir, cylinder->color);
	if (is_hit_cylinder_plane_shadow(info, &bot_plane, cylinder->r)
		|| is_hit_cylinder_plane_shadow(info, &top_plane, cylinder->r)
		|| is_hit_cylinder_body_shadow(info, cylinder))
		return (TRUE);
	else
		return (FALSE);
}

static int	is_hit_cylinder_body_shadow(t_info *info, t_cylinder *cylinder)
{
	t_hit_info	vars;
	t_vec		v_center_to_camera;
	t_vec		v_cylinder_to_rec;

	vars.v_rec_to_light.origin = info->rec.origin;
	vars.v_rec_to_light.unit_dir = vec_minus_v(info->light.origin,
			info->rec.origin);
	info->rec.t_max = vec_len(vars.v_rec_to_light.unit_dir);
	vars.v_rec_to_light.unit_dir = vec_unit(vars.v_rec_to_light.unit_dir);
	v_center_to_camera = vec_minus_v(vars.v_rec_to_light.origin,
			cylinder->origin);
	set_vars(cylinder, &vars, &v_center_to_camera);
	if (is_root_exist(info, cylinder, &vars, &v_center_to_camera))
	{
		v_cylinder_to_rec = vec_minus_v(vec_plus_v(vars.v_rec_to_light.origin,
					vec_mult(vars.v_rec_to_light.unit_dir, vars.t)),
				cylinder->origin);
		if (vec_dot(v_cylinder_to_rec, cylinder->normal_dir) < 0)
			return (FALSE);
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_vars(t_cylinder *cylinder, t_hit_info *vars,
				t_vec *v_center_to_camera)
{
	vars->a = pow(vec_dot(vars->v_rec_to_light.unit_dir,
				cylinder->normal_dir), 2)
		- vec_dot(vars->v_rec_to_light.unit_dir, vars->v_rec_to_light.unit_dir);
	vars->half_b = (vec_dot(vars->v_rec_to_light.unit_dir, cylinder->normal_dir)
			* vec_dot(cylinder->normal_dir, *v_center_to_camera)
			- vec_dot(*v_center_to_camera, vars->v_rec_to_light.unit_dir));
	vars->c = pow(vec_dot(cylinder->normal_dir, *v_center_to_camera), 2)
		+ pow(cylinder->r, 2)
		- vec_dot(*v_center_to_camera, *v_center_to_camera);
	if (vars->a < 0)
	{
		vars->a *= -1;
		vars->half_b *= -1;
		vars->c *= -1;
	}
	vars->discriminant = vars->half_b * vars->half_b - vars->a * vars->c;
}

static int	is_root_exist(t_info *info, t_cylinder *cylinder, t_hit_info *vars,
				t_vec *v_center_to_camera)
{
	double	height_with_t;

	if (vars->discriminant >= 0)
	{
		vars->t = (-(vars->half_b) - sqrt(vars->discriminant)) / vars->a;
		height_with_t = vec_dot(cylinder->normal_dir,
				vec_plus_v(*v_center_to_camera,
					vec_mult(vars->v_rec_to_light.unit_dir, vars->t)));
		if (vars->t < info->rec.t_min || info->rec.t_max < vars->t
			|| !(0 <= height_with_t && height_with_t <= cylinder->height))
		{
			vars->t = (-(vars->half_b) + sqrt(vars->discriminant)) / vars->a;
			height_with_t = vec_dot(cylinder->normal_dir,
					vec_plus_v(*v_center_to_camera,
						vec_mult(vars->v_rec_to_light.unit_dir, vars->t)));
			if (vars->t < info->rec.t_min || info->rec.t_max < vars->t
				|| !(0 <= height_with_t && height_with_t <= cylinder->height))
				return (FALSE);
		}
		return (TRUE);
	}
	else
		return (FALSE);
}
