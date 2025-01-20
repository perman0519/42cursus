/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:40:10 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:58 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static t_color	ambient(t_color *color, t_info *info);
static t_color	diffuse(t_rec *rec, t_color *color, t_list *light,
					int num_shadow);
static t_color	specular(t_ray *ray, t_rec *rec, t_list *light, t_color *color);

t_color	phong_lighting(t_info *info, t_ray *ray, t_rec *rec)
{
	t_color	color;
	t_list	*current_light;
	int		num_shadow;

	rec->origin = vec_plus_v(rec->origin,
			vec_mult(rec->normal_dir, EPSILON));
	color = vec_plus_v(color_create(0, 0, 0), rec->color);
	color = ambient(&color, info);
	current_light = info->light;
	while (current_light)
	{
		num_shadow = is_in_shadow(info,
				((t_light *)current_light->content), rec);
		color = diffuse(rec, &color, current_light, num_shadow);
		if (num_shadow)
		{
			color = vec_div(color, 1.5);
			current_light = current_light->next;
			continue ;
		}
		color = specular(ray, rec, current_light, &color);
		current_light = current_light->next;
	}
	return (color);
}

static t_color	ambient(t_color *color, t_info *info)
{
	return (vec_mult_v(*color, \
				vec_mult(info->ambient.color, info->ambient.ratio)));
}

static t_color	diffuse(t_rec *rec, t_color *color, t_list *light,
					int num_shadow)
{
	t_vec	v_rec_to_light;
	double	ratio_diffuse;

	v_rec_to_light = vec_unit(
			vec_minus_v(((t_light *)light->content)->origin, rec->origin));
	ratio_diffuse = vec_dot(v_rec_to_light, rec->normal_dir);
	if (ratio_diffuse > 0 && !num_shadow)
		return (vec_plus_v(*color,
				vec_mult(((t_light *)light->content)->color,
					((t_light *)light->content)->ratio * ratio_diffuse)));
	else
		return (*color);
}

static t_color	specular(t_ray *ray, t_rec *rec, t_list *light, t_color *color)
{
	t_vec	v_rec_to_light;
	double	t;
	t_vec	v_reflection;
	double	ratio_specular;

	v_rec_to_light = vec_unit(
			vec_minus_v(((t_light *)light->content)->origin, rec->origin));
	t = vec_dot(rec->normal_dir, v_rec_to_light);
	v_reflection = vec_unit(vec_plus_v(vec_mult(v_rec_to_light, -1),
				vec_mult(rec->normal_dir, 2 * t)));
	ratio_specular = (vec_dot(v_reflection, vec_mult(ray->unit_dir, -1)));
	if (ratio_specular < 0)
		ratio_specular = 0.0;
	else
		ratio_specular = pow(ratio_specular, 128);
	return (vec_plus_v(*color,
			vec_mult(vec_mult(((t_light *)light->content)->color, 0.5),
				ratio_specular)));
}
