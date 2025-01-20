/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:56:48 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:59 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_light	light_create(t_point origin, t_color color, double ratio)
{
	t_light	ret;

	ret.origin = origin;
	ret.color = color;
	ret.ratio = ratio;
	return (ret);
}

t_ambient	ambient_create(t_color color, double ratio)
{
	t_ambient	ret;

	ret.origin = vec_create(0, 0, 0);
	ret.color = color;
	ret.ratio = ratio;
	return (ret);
}
