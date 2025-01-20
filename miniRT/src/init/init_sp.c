/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:14:51 by junssong          #+#    #+#             */
/*   Updated: 2024/03/04 13:01:19 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	help_sp_init(char **split, t_sphere *tmp)
{
	char	**value3_split;

	value3_split = ft_split(split[1], ',');
	if (value3_split == NULL)
		return (FALSE);
	tmp->origin = parse_point(value3_split);
	ft_free_split(value3_split);
	value3_split = ft_split(split[3], ',');
	if (value3_split == NULL)
		return (FALSE);
	tmp->color = parse_color(value3_split);
	ft_free_split(value3_split);
	return (TRUE);
}

int	sp_init(char **split, t_info *info)
{
	t_sphere	tmp;
	t_sphere	*sphere;

	if (check_split_size(split, 4) \
		|| !(is_strv3(split[1]) & is_strv3(split[3])))
		return (FALSE);
	if (help_sp_init(split, &tmp) == FALSE)
		return (FALSE);
	tmp.r = ft_atof(split[2]) * 0.5;
	if (tmp.origin.x == INFINITY || tmp.r == INFINITY * 0.5 \
		|| tmp.color.x == -1)
		return (FALSE);
	else
	{
		sphere = malloc(sizeof(t_sphere));
		if (sphere == NULL)
			return (FALSE);
		*sphere = sphere_create(tmp.origin, tmp.color, tmp.r);
		ft_lstadd_back(&(info->object), ft_lstnew(sphere, SPHERE));
	}
	return (TRUE);
}
