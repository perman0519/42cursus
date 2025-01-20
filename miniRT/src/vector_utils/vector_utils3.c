/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:53:55 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:20:37 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
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
	{
		ft_putstr_fd("Error\nDevider is 0.\n", 2);
		exit(0);
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
