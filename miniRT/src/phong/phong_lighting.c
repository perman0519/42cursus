/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:40:10 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 13:17:12 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	ambient(t_color *color, t_info *info);
static t_color	specular(t_info *info, t_color *color, t_vec *v_rec_to_light);

t_color	phong_lighting(t_info *info)
{
	t_color	color;
	t_vec	v_rec_to_light;
	double	ratio_diffuse;
	int		num_shadow;

	info->rec.origin = vec_plus_v(info->rec.origin,
			vec_mult(info->rec.normal_dir, EPSILON));
	color = vec_plus_v(color_create(0, 0, 0), info->rec.color);
	color = ambient(&color, info);
	v_rec_to_light = vec_unit(
			vec_minus_v(info->light.origin, info->rec.origin));
	ratio_diffuse = vec_dot(v_rec_to_light, info->rec.normal_dir);
	num_shadow = is_in_shadow(info);
	if (ratio_diffuse > 0 && !num_shadow)
		color = vec_plus_v(color,
				vec_mult(info->light.color, info->light.ratio * ratio_diffuse));
	if (num_shadow)
	{
		color = vec_div(color, num_shadow + 1);
		return (color);
	}
	color = specular(info, &color, &v_rec_to_light);
	return (color);
}

static t_color	ambient(t_color *color, t_info *info)
{
	return (vec_mult_v(*color,
			vec_mult(info->ambient.color, info->ambient.ratio)));
}

static t_color	specular(t_info *info, t_color *color, t_vec *v_rec_to_light)
{
	double	t;
	t_vec	v_reflection;
	double	ratio_specular;

	t = vec_dot(info->rec.normal_dir, *v_rec_to_light);
	v_reflection = vec_unit(vec_plus_v(vec_mult(*v_rec_to_light, -1),
				vec_mult(info->rec.normal_dir, 2 * t)));
	ratio_specular = vec_dot(v_reflection, vec_mult(info->ray.unit_dir, -1));
	if (ratio_specular < 0)
		ratio_specular = 0.0;
	else
		ratio_specular = pow(ratio_specular, 2);
	return (vec_plus_v(*color,
			vec_mult(vec_mult(info->light.color, 0.5), ratio_specular)));
}
