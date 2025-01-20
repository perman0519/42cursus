/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:14:24 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:24:03 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static t_color_obj	make_color_obj(t_info *info, char **split)
{
	t_color_obj	ret;

	ret.type = check_color_obj(split[5]);
	if (ret.type == FAIL || ret.type == BUMPMAP || ret.type == CHECKER)
		str_exit("Error\nInvalid color object type.\n");
	else
	{
		if (parse_color_obj(info, &ret, split[6], split[7]))
			;
		else
			str_exit("Error\nInvalid color object type.\n");
	}
	return (ret);
}

int	help_cy_init(char **split, t_cylinder *tmp, t_info *info)
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
	tmp->normal_dir = vec_unit(parse_vec(value3_split));
	ft_free_split(value3_split);
	tmp->color_obj = make_color_obj(info, split);
	return (TRUE);
}

int	cy_init(char **split, t_info *info)
{
	t_cylinder	tmp;
	t_cylinder	*cylinder;

	if (check_split_size(split, 6 + 2) \
		|| !(is_strv3(split[1]) & is_strv3(split[2])))
		return (FALSE);
	if (help_cy_init(split, &tmp, info) == FALSE)
		return (FALSE);
	tmp.r = ft_atof(split[3]) * 0.5;
	tmp.height = ft_atof(split[4]);
	if (tmp.origin.x == INFINITY || tmp.normal_dir.x == INFINITY \
		|| tmp.color_obj.data == NULL || tmp.height == INFINITY \
			|| tmp.r == INFINITY * 0.5 || tmp.r <= 0 || tmp.height <= 0)
		return (FALSE);
	else
	{
		cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
		if (cylinder == NULL)
			return (FALSE);
		*cylinder = tmp;
		ft_lstadd_back(&(info->object), ft_lstnew(cylinder, CYLINDER));
	}
	return (TRUE);
}
