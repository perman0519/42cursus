/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:07:55 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/21 20:07:56 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	ray_create(t_point origin, t_vec dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.unit_dir = dir;
	return (ray);
}
