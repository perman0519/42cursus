/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sp_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:14:51 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:24:17 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static t_color_obj	make_color_obj(t_info *info, char **split)
{
	t_color_obj	ret;

	ret.type = check_color_obj(split[3]);
	if (ret.type == FAIL)
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

int	help_sp_init(char **split, t_sphere *tmp, t_info *info)
{
	char	**value3_split;

	value3_split = ft_split(split[1], ',');
	if (value3_split == NULL)
		return (FALSE);
	tmp->origin = parse_point(value3_split);
	ft_free_split(value3_split);
	tmp->color_obj = make_color_obj(info, split);
	return (TRUE);
}

int	sp_init(char **split, t_info *info)
{
	t_sphere	tmp;
	t_sphere	*sphere;

	if (check_split_size(split, 6) || !is_strv3(split[1]))
		return (FALSE);
	if (help_sp_init(split, &tmp, info) == FALSE)
		return (FALSE);
	tmp.r = ft_atof(split[2]) * 0.5;
	if (tmp.origin.x == INFINITY || tmp.r == INFINITY * 0.5 || tmp.r <= 0 \
		|| tmp.color_obj.data == NULL)
		return (FALSE);
	else
	{
		sphere = malloc(sizeof(t_sphere));
		if (sphere == NULL)
			return (FALSE);
		*sphere = sphere_create(tmp.origin, tmp.color_obj, tmp.r);
		ft_lstadd_back(&(info->object), ft_lstnew(sphere, SPHERE));
	}
	return (TRUE);
}

int	nsp_init(char **split, t_info *info)
{
	t_sphere	tmp;
	t_sphere	*sphere;

	if (check_split_size(split, 6) || !is_strv3(split[1]))
		return (FALSE);
	if (help_sp_init(split, &tmp, info) == FALSE)
		return (FALSE);
	tmp.r = ft_atof(split[2]) * 0.5;
	if (tmp.origin.x == INFINITY || tmp.r == INFINITY * 0.5 || tmp.r <= 0 \
		|| tmp.color_obj.data == NULL)
		return (FALSE);
	else
	{
		sphere = malloc(sizeof(t_sphere));
		if (sphere == NULL)
			return (FALSE);
		*sphere = sphere_create(tmp.origin, tmp.color_obj, tmp.r);
		ft_lstadd_back(&(info->object), ft_lstnew(sphere, NSP));
	}
	return (TRUE);
}
