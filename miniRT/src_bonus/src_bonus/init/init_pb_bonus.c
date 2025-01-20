/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pb_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:28:58 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:24:11 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static t_color_obj	make_color_obj(t_info *info, char **split)
{
	t_color_obj	ret;

	ret.type = check_color_obj(split[4]);
	if (ret.type == FAIL || ret.type == BUMPMAP || ret.type == CHECKER)
		str_exit("Error\nInvalid color object type.\n");
	else
	{
		if (parse_color_obj(info, &ret, split[5], split[6]))
			;
		else
			str_exit("Error\nInvalid color object type.\n");
	}
	return (ret);
}

int	help_pb_init(char **split, t_paraboloid *tmp, t_info *info)
{
	char	**value3_split;

	value3_split = ft_split(split[1], ',');
	if (value3_split == NULL)
		return (FALSE);
	tmp->origin = parse_point(value3_split);
	ft_free_split(value3_split);
	tmp->a = ft_atof(split[2]);
	tmp->b = ft_atof(split[3]);
	tmp->color_obj = make_color_obj(info, split);
	return (TRUE);
}

int	pb_init(char **split, t_info *info)
{
	t_paraboloid	*paraboloid;
	t_paraboloid	tmp;

	if (check_split_size(split, 7) || !is_strv3(split[1]))
		return (FALSE);
	if (help_pb_init(split, &tmp, info) == FALSE)
		return (FALSE);
	if (tmp.origin.x == INFINITY || tmp.a == INFINITY || tmp.b == INFINITY
		|| tmp.color_obj.data == NULL)
		return (FALSE);
	else
	{
		paraboloid = malloc(sizeof(t_paraboloid));
		if (paraboloid == NULL)
			return (FALSE);
		*paraboloid = paraboloid_create(tmp.origin, \
							tmp.a, tmp.b, tmp.color_obj);
		ft_lstadd_back(&(info->object), ft_lstnew(paraboloid, PARABOLOID));
	}
	return (TRUE);
}
