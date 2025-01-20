/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:13:24 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 13:18:14 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_in_shadow(t_info *info)
{
	int		num_shadow;
	t_list	*current_object;

	num_shadow = 0;
	current_object = info->object;
	while (current_object && !num_shadow)
	{
		if (current_object->type == SPHERE
			&& is_hit_sphere_shadow(info, current_object->content))
			num_shadow++;
		else if (current_object->type == PLANE
			&& is_hit_plane_shadow(info, current_object->content))
			num_shadow++;
		else if (current_object->type == CYLINDER
			&& is_hit_cylinder_shadow(info, current_object->content))
			num_shadow++;
		current_object = current_object->next;
	}
	return (num_shadow);
}
