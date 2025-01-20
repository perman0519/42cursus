/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:13:24 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:58 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	is_any_hit_shadow(t_light *light, t_rec *rec, t_list *object);

int	is_in_shadow(t_info *info, t_light *light, t_rec *rec)
{
	int		num_shadow;
	t_list	*current_object;

	num_shadow = 0;
	current_object = info->object;
	while (current_object && !num_shadow)
	{
		if (is_any_hit_shadow(light, rec, current_object))
			num_shadow++;
		current_object = current_object->next;
	}
	return (num_shadow);
}

static int	is_any_hit_shadow(t_light *light, t_rec *rec, t_list *object)
{
	if (object->type == NSP
		&& is_hit_sphere_shadow(object->content, light, rec))
		return (FALSE);
	else if (object->type == SPHERE
		&& is_hit_sphere_shadow(object->content, light, rec))
		return (TRUE);
	else if (object->type == PLANE
		&& is_hit_plane_shadow(object->content, light, rec))
		return (TRUE);
	else if (object->type == CYLINDER
		&& is_hit_cy_shadow(object->content, light, rec))
		return (TRUE);
	else if (object->type == PARABOLOID
		&& is_hit_paraboloid_shadow(object->content, light, rec))
		return (TRUE);
	return (FALSE);
}
