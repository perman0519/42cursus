/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:20:01 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 13:33:33 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_hit(t_info *info)
{
	t_list	*object;
	int		is_hit;

	object = info->object;
	is_hit = FALSE;
	while (object)
	{
		if (object->type == SPHERE
			&& is_hit_sphere(info, object->content))
			is_hit = TRUE;
		else if (object->type == PLANE
			&& is_hit_plane(info, object->content))
			is_hit = TRUE;
		else if (object->type == CYLINDER
			&& is_hit_cylinder(info, object->content))
			is_hit = TRUE;
		object = object->next;
	}
	if (is_hit)
		return (TRUE);
	else
		return (FALSE);
}
