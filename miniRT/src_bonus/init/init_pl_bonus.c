/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pl_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:28:58 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:24:14 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static t_color_obj	make_color_obj(t_info *info, char **split)
{
	t_color_obj	ret;

	ret.type = check_color_obj(split[3]);
	if (ret.type == FAIL || ret.type == BUMPMAP || ret.type == CHECKER)
		str_exit("Error\nInvalid color object type.\n");
	else
	{
		if (parse_color_obj(info, &ret, split[4], split[5]))
			;
		else
			str_exit("Error\nInvalid color object type.\n");
	}
	return (ret);
}

int	help_pl_init(char **split, t_plane *tmp, t_info *info)
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
	tmp->color_obj = make_color_obj(info, split);
	return (TRUE);
}

int	pl_init(char **split, t_info *info)
{
	t_plane	*plane;
	t_plane	tmp;

	if (check_split_size(split, 4 + 2) \
	|| (is_strv3(split[1]) & is_strv3(split[2])) == 0)
		return (FALSE);
	if (help_pl_init(split, &tmp, info) == FALSE)
		return (FALSE);
	if (tmp.origin.x == INFINITY \
	|| tmp.normal_dir.x == INFINITY || tmp.color_obj.data == NULL)
		return (FALSE);
	else
	{
		plane = malloc(sizeof(t_plane));
		if (plane == NULL)
			return (FALSE);
		*plane = plane_create(tmp.origin, tmp.normal_dir, tmp.color_obj);
		ft_lstadd_back(&(info->object), ft_lstnew(plane, PLANE));
	}
	return (TRUE);
}
