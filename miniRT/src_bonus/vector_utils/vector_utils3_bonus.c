/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:53:55 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:21:10 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils_bonus.h"
#include "miniRT_bonus.h"
#include <math.h>
#include <stdio.h>

double	vec_dot(t_vec vec, t_vec vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

t_vec	vec_cross(t_vec vec, t_vec vec2)
{
	t_vec	ret;

	ret.x = vec.y * vec2.z - vec.z * vec2.y;
	ret.y = vec.z * vec2.x - vec.x * vec2.z;
	ret.z = vec.x * vec2.y - vec.y * vec2.x;
	return (ret);
}

double	vec_len(t_vec vec)
{
	return (sqrt(vec_dot(vec, vec)));
}

t_vec	vec_unit(t_vec vec)
{
	double	len;

	len = vec_len(vec);
	if (len == 0)
		str_exit("Error\nDevider is 0.\n");
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
