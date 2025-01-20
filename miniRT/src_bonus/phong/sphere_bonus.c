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

static void	set_vars(t_sphere *sphere, t_hit_info *vars,
				t_vec *v_rec_to_light, t_vec *v_sphere_to_rec);
static int	is_root_exist(t_rec *rec, t_hit_info *vars);

int	is_hit_sphere_shadow(t_sphere *sphere, t_light *light, t_rec *rec)
{
	t_hit_info	vars;
	t_vec		v_rec_to_light;
	t_vec		v_sphere_to_rec;

	v_rec_to_light = vec_minus_v(light->origin, rec->origin);
	rec->t_max = vec_len(v_rec_to_light);
	v_rec_to_light = vec_unit(v_rec_to_light);
	v_sphere_to_rec = vec_minus_v(rec->origin, sphere->origin);
	set_vars(sphere, &vars, &v_rec_to_light, &v_sphere_to_rec);
	if (is_root_exist(rec, &vars))
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
		return (TRUE);
	}
	else
		return (FALSE);
}
