/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:01:45 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:58 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	set_vars(t_sphere *sphere, t_ray *ray, t_hit_info *vars,
				t_vec *v_sphere_to_camera);
static int	is_root_exist(t_rec *rec, t_hit_info *vars);
static void	set_rec(t_sphere *sphere, t_ray *ray, t_rec *rec, t_hit_info *vars);

int	is_hit_sphere(t_sphere *sphere, t_ray *ray, t_rec *rec)
{
	t_hit_info	math_vars;
	t_vec		v_sphere_to_camera;
	double		s_sphere_to_cam;

	v_sphere_to_camera = vec_minus_v(ray->origin, sphere->origin);
	set_vars(sphere, ray, &math_vars, &v_sphere_to_camera);
	if (is_root_exist(rec, &math_vars))
	{
		set_rec(sphere, ray, rec, &math_vars);
		s_sphere_to_cam = vec_len(vec_minus_v(ray->origin, sphere->origin));
		if (s_sphere_to_cam < sphere->r)
			rec->normal_dir = vec_mult(rec->normal_dir, -1);
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_vars(t_sphere *sphere, t_ray *ray, t_hit_info *vars,
			t_vec *v_sphere_to_camera)
{
	vars->a = vec_dot(ray->unit_dir, ray->unit_dir);
	vars->half_b = vec_dot(ray->unit_dir, *v_sphere_to_camera);
	vars->c = vec_dot(*v_sphere_to_camera, *v_sphere_to_camera)
		- pow(sphere->r, 2);
	if (vars->a < 0)
	{
		vars->a *= -1;
		vars->half_b *= -1;
		vars->c *= -1;
	}
	vars->discriminant = vars->half_b * vars->half_b - vars->a * vars->c;
}

static int	is_root_exist(t_rec *rec, t_hit_info *vars)
{
	double		t;

	if (vars->discriminant >= 0)
	{
		t = (-(vars->half_b) - sqrt(vars->discriminant)) / vars->a;
		if (t < rec->t_min || rec->t_max < t)
		{
			t = (-(vars->half_b) + sqrt(vars->discriminant)) / vars->a;
			if (t < rec->t_min || rec->t_max < t)
				return (FALSE);
		}
		vars->t = t;
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_rec(t_sphere *sphere, t_ray *ray, t_rec *rec, t_hit_info *vars)
{
	rec->t_max = vars->t;
	rec->origin = vec_plus_v(ray->origin, vec_mult(ray->unit_dir, rec->t_max));
	rec->normal_dir = vec_unit(vec_minus_v(rec->origin, sphere->origin));
	get_rec_color(&(sphere->color_obj), rec, \
	((atan2(rec->origin.x - sphere->origin.x, rec->origin.z - sphere->origin.z))
			+ M_PI) / (2 * M_PI),
		acos((rec->origin.y - sphere->origin.y) / sphere->r) / M_PI);
}
