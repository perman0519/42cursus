/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:20:01 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:59 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	is_any_hit(t_list *object, t_ray *ray, t_rec *rec);

int	is_hit(t_info *info, t_ray *ray, t_rec *rec)
{
	t_list	*object;
	int		is_hit;

	object = info->object;
	is_hit = FALSE;
	while (object)
	{
		if (is_any_hit(object, ray, rec))
			is_hit = TRUE;
		object = object->next;
	}
	if (is_hit)
		return (TRUE);
	else
		return (FALSE);
}

static int	is_any_hit(t_list *object, t_ray *ray, t_rec *rec)
{
	if (object->type == SPHERE
		&& is_hit_sphere(object->content, ray, rec))
		rec->type = SPHERE;
	else if (object->type == PLANE
		&& is_hit_plane(object->content, ray, rec))
		rec->type = PLANE;
	else if (object->type == CYLINDER
		&& is_hit_cylinder(object->content, ray, rec))
		rec->type = CYLINDER;
	else if (object->type == PARABOLOID
		&& is_hit_paraboloid(object->content, ray, rec))
		rec->type = PARABOLOID;
	else if (object->type == NSP
		&& is_hit_sphere(object->content, ray, rec))
		rec->type = NSP;
	if (rec->type != DEFAULT)
		return (TRUE);
	else
		return (FALSE);
}
