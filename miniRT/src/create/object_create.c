/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:08:40 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 12:02:58 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	sphere_create(t_point origin, t_color color, double r)
{
	t_sphere	ret;

	ret.origin = origin;
	ret.color = color;
	ret.r = r;
	return (ret);
}

t_plane	plane_create(t_point origin, t_vec dir, t_color color)
{
	t_plane	ret;

	ret.origin = origin;
	ret.normal_dir = vec_unit(dir);
	ret.color = color;
	return (ret);
}

t_cylinder	cylinder_create(t_cylinder cylinder)
{
	t_cylinder	ret;

	ret.origin = cylinder.origin;
	ret.normal_dir = vec_unit(cylinder.normal_dir);
	ret.color = cylinder.color;
	ret.r = cylinder.r;
	ret.height = cylinder.height;
	return (ret);
}
