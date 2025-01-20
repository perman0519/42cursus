/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeha <pjeha@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:53:08 by junssong          #+#    #+#             */
/*   Updated: 2024/02/25 20:50:18 by pjeha            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"

t_vec	vec_minus(t_vec vec, double t)
{
	vec.x -= t;
	vec.y -= t;
	vec.z -= t;
	return (vec);
}

t_vec	vec_minus_v(t_vec vec, t_vec vec2)
{
	vec.x -= vec2.x;
	vec.y -= vec2.y;
	vec.z -= vec2.z;
	return (vec);
}

t_vec	vec_mult(t_vec vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec	vec_mult_v(t_vec vec, t_vec vec2)
{
	t_vec	ret;

	ret.x = vec.x * vec2.x;
	ret.y = vec.y * vec2.y;
	ret.z = vec.z * vec2.z;
	return (ret);
}

t_vec	vec_div(t_vec vec, double t)
{
	vec.x *= 1 / t;
	vec.y *= 1 / t;
	vec.z *= 1 / t;
	return (vec);
}
