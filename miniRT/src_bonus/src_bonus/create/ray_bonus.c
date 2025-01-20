/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:10:29 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:10:50 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_ray	ray_create(t_point origin, t_vec dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.unit_dir = dir;
	return (ray);
}
