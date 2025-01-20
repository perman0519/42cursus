/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:11:27 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:59 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	is_hit_cylinder_body(t_cylinder *cylinder, t_ray *ray, t_rec *rec);
static void	set_vars(t_cylinder *cylinder, t_ray *ray, t_hit_info *vars,
				t_vec *v_center_to_camera);
static int	is_root_exist(t_cylinder *cylinder, t_ray *ray, t_rec *rec,
				t_hit_info *vars);
static void	set_rec(t_cylinder *cylinder, t_ray *ray, t_rec *rec,
				t_hit_info *vars);

int	is_hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_rec *rec)
{
	t_plane	bot_plane;
	t_plane	top_plane;

	bot_plane = plane_create(cylinder->origin, cylinder->normal_dir,
			cylinder->color_obj);
	top_plane = plane_create(vec_plus_v(cylinder->origin,
				vec_mult(cylinder->normal_dir, cylinder->height)),
			cylinder->normal_dir, cylinder->color_obj);
	if (is_hit_cylinder_plane(&bot_plane, cylinder->r, ray, rec)
		| is_hit_cylinder_plane(&top_plane, cylinder->r, ray, rec)
		| is_hit_cylinder_body(cylinder, ray, rec))
		return (TRUE);
	else
		return (FALSE);
}

static int	is_hit_cylinder_body(t_cylinder *cylinder, t_ray *ray, t_rec *rec)
{
	t_hit_info	math_vars;
	t_vec		v_center_to_camera;
	t_vec		v_cylinder_to_rec;

	v_center_to_camera = vec_minus_v(ray->origin, cylinder->origin);
	set_vars(cylinder, ray, &math_vars, &v_center_to_camera);
	if (is_root_exist(cylinder, ray, rec, &math_vars))
	{
		v_cylinder_to_rec = vec_minus_v(vec_plus_v(ray->origin,
					vec_mult(ray->unit_dir, math_vars.t)), cylinder->origin);
		if (vec_dot(v_cylinder_to_rec, cylinder->normal_dir) < 0)
			return (FALSE);
		set_rec(cylinder, ray, rec, &math_vars);
		if (vec_dot(rec->normal_dir, ray->unit_dir) > 0)
			rec->normal_dir = vec_mult(rec->normal_dir, -1);
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_vars(t_cylinder *cylinder, t_ray *ray, t_hit_info *vars,
				t_vec *v_center_to_camera)
{
	vars->a = pow(vec_dot(ray->unit_dir, cylinder->normal_dir), 2)
		- vec_dot(ray->unit_dir, ray->unit_dir);
	vars->half_b = (vec_dot(ray->unit_dir, cylinder->normal_dir)
			* vec_dot(cylinder->normal_dir, *v_center_to_camera)
			- vec_dot(*v_center_to_camera, ray->unit_dir));
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

static int	is_root_exist(t_cylinder *cylinder, t_ray *ray, t_rec *rec,
				t_hit_info *vars)
{
	t_vec	v_center_to_camera;
	double	height_with_t;

	v_center_to_camera = vec_minus_v(ray->origin, cylinder->origin);
	if (vars->discriminant >= 0)
	{
		vars->t = (-(vars->half_b) - sqrt(vars->discriminant)) / vars->a;
		height_with_t = vec_dot(cylinder->normal_dir,
				vec_plus_v(v_center_to_camera,
					vec_mult(ray->unit_dir, vars->t)));
		if (vars->t < rec->t_min || rec->t_max < vars->t
			|| !(0 <= height_with_t && height_with_t <= cylinder->height))
		{
			vars->t = (-(vars->half_b) + sqrt(vars->discriminant)) / vars->a;
			height_with_t = vec_dot(cylinder->normal_dir,
					vec_plus_v(v_center_to_camera,
						vec_mult(ray->unit_dir, vars->t)));
			if (vars->t < rec->t_min || rec->t_max < vars->t
				|| !(0 <= height_with_t && height_with_t <= cylinder->height))
				return (FALSE);
		}
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_rec(t_cylinder *cylinder, t_ray *ray, t_rec *rec,
				t_hit_info *vars)
{
	t_vec	v_center_to_camera;
	t_vec	v_center_to_rec;

	v_center_to_camera = vec_minus_v(ray->origin, cylinder->origin);
	v_center_to_rec = vec_plus_v(v_center_to_camera,
			vec_mult(ray->unit_dir, vars->t));
	rec->t_max = vars->t;
	rec->origin = vec_plus_v(ray->origin,
			vec_mult(ray->unit_dir, vars->t));
	rec->normal_dir = vec_unit(vec_minus_v(v_center_to_rec,
				vec_mult(cylinder->normal_dir,
					vec_dot(v_center_to_rec, cylinder->normal_dir))));
	rec->color = *((t_color *)cylinder->color_obj.data);
}
