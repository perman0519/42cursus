/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:04:45 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:59 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	set_vars(t_paraboloid *paraboloid, t_ray *ray, t_hit_info *vars);
static int	is_root_exist(t_rec *rec, t_hit_info *vars);
static void	set_rec(t_paraboloid *paraboloid, t_ray *ray, t_rec *rec,
				t_hit_info *vars);

int	is_hit_paraboloid(t_paraboloid *paraboloid, t_ray *ray, t_rec *rec)
{
	t_hit_info	math_vars;

	set_vars(paraboloid, ray, &math_vars);
	if (is_root_exist(rec, &math_vars))
	{
		set_rec(paraboloid, ray, rec, &math_vars);
		if (vec_dot(vec_minus_v(rec->origin, ray->origin), rec->normal_dir) > 0)
			rec->normal_dir = vec_mult(rec->normal_dir, -1);
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_vars(t_paraboloid *paraboloid, t_ray *ray, t_hit_info *vars)
{
	vars->a = pow(paraboloid->b, 2) * pow(ray->unit_dir.x, 2)
		+ pow(paraboloid->a, 2) * pow(ray->unit_dir.y, 2);
	vars->half_b = (2 * pow(paraboloid->b, 2) * ray->unit_dir.x
			* (ray->origin.x - paraboloid->origin.x)
			+ 2 * pow(paraboloid->a, 2) * ray->unit_dir.y
			* (ray->origin.y - paraboloid->origin.y) - pow(paraboloid->a, 2)
			* pow(paraboloid->b, 2) * ray->unit_dir.z) / 2;
	vars->c = pow(paraboloid->b, 2)
		* pow((ray->origin.x - paraboloid->origin.x), 2)
		+ pow(paraboloid->a, 2)
		* pow((ray->origin.y - paraboloid->origin.y), 2)
		- pow(paraboloid->a, 2) * pow(paraboloid->b, 2)
		* (ray->origin.z - paraboloid->origin.z);
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
	if (vars->discriminant >= 0)
	{
		vars->t = (-(vars->half_b) - sqrt(vars->discriminant)) / vars->a;
		if (vars->t < rec->t_min || rec->t_max < vars->t)
		{
			vars->t = (-(vars->half_b) + sqrt(vars->discriminant)) / vars->a;
			if (vars->t < rec->t_min || rec->t_max < vars->t)
				return (FALSE);
		}
		return (TRUE);
	}
	else
		return (FALSE);
}

static void	set_rec(t_paraboloid *paraboloid, t_ray *ray, t_rec *rec,
				t_hit_info *vars)
{
	rec->t_max = vars->t;
	rec->origin = vec_plus_v(ray->origin,
			vec_mult(ray->unit_dir, rec->t_max));
	rec->normal_dir.x = (2 * rec->origin.x - 2 * paraboloid->origin.x)
		/ pow(paraboloid->a, 2);
	rec->normal_dir.y = (2 * rec->origin.y - 2 * paraboloid->origin.y)
		/ pow(paraboloid->b, 2);
	rec->normal_dir.z = -1;
	rec->normal_dir = vec_unit(rec->normal_dir);
	rec->color = *((t_color *)paraboloid->color_obj.data);
}
