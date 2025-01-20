/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:56:48 by junhapar          #+#    #+#             */
/*   Updated: 2024/02/26 12:32:25 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
