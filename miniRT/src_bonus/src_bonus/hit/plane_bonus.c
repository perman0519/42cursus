/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:02:17 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 20:04:11 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	set_vars(t_plane *plane, t_ray *ray, t_hit_info *vars,
				double *cos_cam_with_plane);
static int	is_root_exist(t_rec *rec, t_hit_info *vars);
static void	set_rec(t_plane *plane, t_ray *ray, t_rec *rec, t_hit_info *vars);

int	is_hit_plane(t_plane *plane, t_ray *ray, t_rec *rec)
{
	t_hit_info	math_vars;
	double		cos_cam_with_plane;

	cos_cam_with_plane = vec_dot(ray->unit_dir, plane->normal_dir);
	if (cos_cam_with_plane == 0)
		return (FALSE);
	set_vars(plane, ray, &math_vars, &cos_cam_with_plane);
	if (is_root_exist(rec, &math_vars))
	{
		set_rec(plane, ray, rec, &math_vars);
		if (cos_cam_with_plane > 0)
			rec->normal_dir = vec_mult(rec->normal_dir, -1);
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_vars(t_plane *plane, t_ray *ray, t_hit_info *vars,
			double *cos_cam_with_plane)
{
	vars->const_d = vec_dot(plane->normal_dir, plane->origin) * -1;
	vars->t = (vec_dot(ray->origin, plane->normal_dir) + vars->const_d)
		* -1 / *cos_cam_with_plane;
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

static void	set_rec(t_plane *plane, t_ray *ray, t_rec *rec, t_hit_info *vars)
{
	rec->t_max = vars->t;
	rec->origin = vec_plus_v(ray->origin, vec_mult(ray->unit_dir, vars->t));
	rec->normal_dir = plane->normal_dir;
	rec->color = *((t_color *)plane->color_obj.data);
}

int	is_hit_cylinder_plane(t_plane *plane, float r, t_ray *ray, t_rec *rec)
{
	t_hit_info	math_vars;
	double		cos_cam_with_plane;
	t_point		rec_origin;

	cos_cam_with_plane = vec_dot(ray->unit_dir, plane->normal_dir);
	if (cos_cam_with_plane == 0)
		return (FALSE);
	set_vars(plane, ray, &math_vars, &cos_cam_with_plane);
	if (math_vars.t >= 0)
	{
		if (math_vars.t < rec->t_min || rec->t_max < math_vars.t)
			return (FALSE);
		rec_origin = vec_plus_v(ray->origin,
				vec_mult(ray->unit_dir, math_vars.t));
		if (vec_len(vec_minus_v(plane->origin, rec_origin)) > r)
			return (FALSE);
		set_rec(plane, ray, rec, &math_vars);
		if (cos_cam_with_plane > 0)
			rec->normal_dir = vec_mult(rec->normal_dir, -1);
		return (TRUE);
	}
	return (FALSE);
}
