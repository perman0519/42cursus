/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:24:43 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:09:02 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_rec	rec_create(void)
{
	t_rec	rec;

	rec.t_min = EPSILON;
	rec.t_max = _INFINITY;
	rec.origin = point_create(0, 0, 0);
	rec.normal_dir = vec_create(0, 0, 0);
	rec.color = color_create(0, 0, 0);
	rec.type = DEFAULT;
	return (rec);
}
