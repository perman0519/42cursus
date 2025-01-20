/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:37:04 by junhapar          #+#    #+#             */
/*   Updated: 2024/02/10 19:58:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"

t_vec	vec_create(double x, double y, double z)
{
	t_vec	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_point	point_create(double x, double y, double z)
{
	return (vec_create(x, y, z));
}

t_color	color_create(double r, double g, double b)
{
	return (vec_create(r, g, b));
}

t_vec	vec_plus(t_vec vec, double t)
{
	vec.x += t;
	vec.y += t;
	vec.z += t;
	return (vec);
}

t_vec	vec_plus_v(t_vec vec, t_vec vec2)
{
	vec.x += vec2.x;
	vec.y += vec2.y;
	vec.z += vec2.z;
	return (vec);
}
