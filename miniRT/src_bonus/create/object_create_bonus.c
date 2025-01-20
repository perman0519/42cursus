/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:08:40 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:59 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_sphere	sphere_create(t_point origin, t_color_obj color_obj, double r)
{
	t_sphere	ret;

	ret.origin = origin;
	ret.color_obj = color_obj;
	ret.r = r;
	return (ret);
}

t_plane	plane_create(t_point origin, t_vec dir, t_color_obj color_obj)
{
	t_plane	ret;

	ret.origin = origin;
	ret.normal_dir = vec_unit(dir);
	ret.color_obj = color_obj;
	return (ret);
}

t_cylinder	cylinder_create(t_point origin, t_vec dir, t_color_obj color_obj,
						t_obj_info obj_info)
{
	t_cylinder	ret;

	ret.origin = origin;
	ret.normal_dir = vec_unit(dir);
	ret.r = obj_info.r;
	ret.height = obj_info.height;
	ret.color_obj = color_obj;
	return (ret);
}

t_paraboloid	paraboloid_create(t_point origin, double a, double b,
								t_color_obj	color_obj)
{
	t_paraboloid	ret;

	ret.origin = origin;
	ret.a = a;
	ret.b = b;
	ret.color_obj = color_obj;
	return (ret);
}
