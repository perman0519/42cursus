/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:01:45 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/21 19:01:47 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	set_vars(t_sphere *sphere, t_hit_info *vars,
				t_vec *v_rec_to_light, t_vec *v_sphere_to_rec);
static int	is_root_exist(t_info *info, t_hit_info *vars);

int	is_hit_sphere_shadow(t_info *info, t_sphere *sphere)
{
	t_hit_info	vars;
	t_vec		v_rec_to_light;
	t_vec		v_sphere_to_rec;

	v_rec_to_light = vec_minus_v(info->light.origin, info->rec.origin);
	info->rec.t_max = vec_len(v_rec_to_light);
	v_rec_to_light = vec_unit(v_rec_to_light);
	v_sphere_to_rec = vec_minus_v(info->rec.origin, sphere->origin);
	set_vars(sphere, &vars, &v_rec_to_light, &v_sphere_to_rec);
	if (is_root_exist(info, &vars))
		return (TRUE);
	else
		return (FALSE);
}

static void	set_vars(t_sphere *sphere, t_hit_info *vars,
				t_vec *v_rec_to_light, t_vec *v_sphere_to_rec)
{
	vars->a = vec_dot(*v_rec_to_light, *v_rec_to_light);
	vars->half_b = vec_dot(*v_rec_to_light, *v_sphere_to_rec);
	vars->c = vec_dot(*v_sphere_to_rec, *v_sphere_to_rec) - pow(sphere->r, 2.0);
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
		return (TRUE);
	}
	else
		return (FALSE);
}
