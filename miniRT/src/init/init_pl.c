/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:28:58 by junssong          #+#    #+#             */
/*   Updated: 2024/03/04 13:01:10 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	help_pl_init(char **split, t_plane *tmp)
{
	char	**value3_split;

	value3_split = ft_split(split[1], ',');
	if (value3_split == NULL)
		return (FALSE);
	tmp->origin = parse_point(value3_split);
	ft_free_split(value3_split);
	value3_split = ft_split(split[2], ',');
	if (value3_split == NULL)
		return (FALSE);
	tmp->normal_dir = parse_vec(value3_split);
	ft_free_split(value3_split);
	value3_split = ft_split(split[3], ',');
	if (value3_split == NULL)
		return (FALSE);
	tmp->color = parse_color(value3_split);
	ft_free_split(value3_split);
	return (TRUE);
}

int	pl_init(char **split, t_info *info)
{
	t_plane	*plane;
	t_plane	tmp;

	if (check_split_size(split, 4) \
	|| ((is_strv3(split[1]) & is_strv3(split[2])) & is_strv3(split[3])) == 0)
		return (FALSE);
	if (help_pl_init(split, &tmp) == FALSE)
		return (FALSE);
	if (tmp.origin.x == INFINITY \
	|| tmp.normal_dir.x == INFINITY || tmp.color.x == -1)
		return (FALSE);
	else
	{
		plane = malloc(sizeof(t_plane));
		if (plane == NULL)
			return (FALSE);
		*plane = plane_create(tmp.origin, tmp.normal_dir, tmp.color);
		ft_lstadd_back(&(info->object), ft_lstnew(plane, PLANE));
	}
	return (TRUE);
}
