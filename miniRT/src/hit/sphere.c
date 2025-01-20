/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:01:45 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/20 13:24:55 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	set_vars(t_info *info, t_sphere *sphere,
				t_hit_info *vars, t_vec *v_sphere_to_camera);
static int	is_root_exist(t_info *info, t_hit_info *vars);
static void	set_rec(t_info *info, t_sphere *sphere, t_hit_info *vars);

int	is_hit_sphere(t_info *info, t_sphere *sphere)
{
	t_hit_info	math_vars;
	t_vec		v_sphere_to_camera;

	v_sphere_to_camera = vec_minus_v(info->ray.origin, sphere->origin);
	set_vars(info, sphere, &math_vars, &v_sphere_to_camera);
	if (is_root_exist(info, &math_vars))
	{
		set_rec(info, sphere, &math_vars);
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_vars(t_info *info, t_sphere *sphere,
			t_hit_info *vars, t_vec *v_sphere_to_camera)
{
	vars->a = vec_dot(info->ray.unit_dir, info->ray.unit_dir);
	vars->half_b = vec_dot(info->ray.unit_dir, *v_sphere_to_camera);
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

static int	is_root_exist(t_info *info, t_hit_info *vars)
{
	double		t;

	if (vars->discriminant >= 0)
	{
		t = (-(vars->half_b) - sqrt(vars->discriminant)) / vars->a;
		if (t < info->rec.t_min || info->rec.t_max < t)
		{
			t = (-(vars->half_b) + sqrt(vars->discriminant)) / vars->a;
			if (t < info->rec.t_min || info->rec.t_max < t)
				return (FALSE);
		}
		vars->t = t;
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_rec(t_info *info, t_sphere *sphere, t_hit_info *vars)
{
	double	s_sphere_to_cam;

	info->rec.t_max = vars->t;
	info->rec.origin = vec_plus_v(info->ray.origin,
			vec_mult(info->ray.unit_dir, vars->t));
	info->rec.normal_dir = vec_unit(vec_minus_v(info->rec.origin,
				sphere->origin));
	info->rec.color = sphere->color;
	s_sphere_to_cam = vec_len(vec_minus_v(info->ray.origin, sphere->origin));
	if (s_sphere_to_cam < sphere->r)
		info->rec.normal_dir = vec_mult(info->rec.normal_dir, -1);
}
