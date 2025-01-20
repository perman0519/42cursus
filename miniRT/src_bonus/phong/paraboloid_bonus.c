/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:04:45 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:58 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	set_vars(t_paraboloid *paraboloid, t_hit_info *vars);
static int	is_root_exist(t_rec *rec, t_hit_info *vars);

int	is_hit_paraboloid_shadow(t_paraboloid *paraboloid, t_light *light,
		t_rec *rec)
{
	t_hit_info	vars;

	vars.v_rec_to_light.origin = rec->origin;
	vars.v_rec_to_light.unit_dir = vec_minus_v(light->origin, rec->origin);
	rec->t_max = vec_len(vars.v_rec_to_light.unit_dir);
	vars.v_rec_to_light.unit_dir = vec_unit(vars.v_rec_to_light.unit_dir);
	set_vars(paraboloid, &vars);
	if (is_root_exist(rec, &vars))
		return (TRUE);
	else
		return (FALSE);
}

static void	set_vars(t_paraboloid *paraboloid, t_hit_info *vars)
{
	vars->a = pow(paraboloid->b, 2) * pow(vars->v_rec_to_light.unit_dir.x, 2)
		+ pow(paraboloid->a, 2) * pow(vars->v_rec_to_light.unit_dir.y, 2);
	vars->half_b = (2 * pow(paraboloid->b, 2) * vars->v_rec_to_light.unit_dir.x
			* (vars->v_rec_to_light.origin.x - paraboloid->origin.x)
			+ 2 * pow(paraboloid->a, 2) * vars->v_rec_to_light.unit_dir.y
			* (vars->v_rec_to_light.origin.y - paraboloid->origin.y)
			- pow(paraboloid->a, 2) * pow(paraboloid->b, 2)
			* vars->v_rec_to_light.unit_dir.z) / 2;
	vars->c = pow(paraboloid->b, 2)
		* pow((vars->v_rec_to_light.origin.x - paraboloid->origin.x), 2)
		+ pow(paraboloid->a, 2)
		* pow((vars->v_rec_to_light.origin.y - paraboloid->origin.y), 2)
		- pow(paraboloid->a, 2) * pow(paraboloid->b, 2)
		* (vars->v_rec_to_light.origin.z - paraboloid->origin.z);
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
