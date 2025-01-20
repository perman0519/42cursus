/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_obj_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:50:14 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:24:06 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_e_color	check_color_obj(char *str)
{
	if (ft_strlen(str) == 2)
	{
		if (!ft_strncmp(str, "cl", 2))
			return (COLOR);
		else if (!ft_strncmp(str, "ck", 2))
			return (CHECKER);
		else if (!ft_strncmp(str, "bp", 2))
			return (BUMPMAP);
		else
			return (FAIL);
	}
	else
		return (FAIL);
}

static int	put_color(t_color_obj *color_obj, char *str1, char *str2)
{
	char	**value3_split;
	t_color	*color;

	if (ft_strlen(str2) != 4 || ft_strncmp(str2, "NULL", 4))
		str_exit("Error\nInvalid color object type.\n");
	value3_split = ft_split(str1, ',');
	if (value3_split == NULL)
		return (FALSE);
	if (check_split_size(value3_split, 3))
	{
		ft_free_split(value3_split);
		return (FALSE);
	}
	color = (t_color *)malloc(sizeof(t_color));
	if (color == NULL)
		str_exit("Error\ncolor_malloc_fail");
	*color = parse_color(value3_split);
	ft_free_split(value3_split);
	color_obj->data = color;
	return (TRUE);
}

static int	put_checker(t_color_obj *color_obj, char *str1, char *str2)
{
	char		**value3_split;
	t_checker	*checker;

	checker = malloc(sizeof(t_checker));
	if (checker == NULL)
		str_exit("Error\nchecker_malloc_fail");
	value3_split = ft_split(str1, ',');
	if (value3_split == NULL)
		return (FALSE);
	if (check_split_size(value3_split, 3))
		return (FALSE);
	checker->color1 = parse_color(value3_split);
	ft_free_split(value3_split);
	value3_split = ft_split(str2, ',');
	if (value3_split == NULL)
		return (FALSE);
	if (check_split_size(value3_split, 3))
		return (FALSE);
	checker->color2 = parse_color(value3_split);
	ft_free_split(value3_split);
	checker->width = CHECK_WIDTH;
	checker->height = CHECK_HEIGHT;
	color_obj->data = checker;
	return (TRUE);
}

int	parse_color_obj(t_info *info, t_color_obj *color_obj, \
		char *str1, char *str2)
{
	if (color_obj->type == COLOR)
	{
		return (put_color(color_obj, str1, str2));
	}
	else if (color_obj->type == CHECKER)
	{
		return (put_checker(color_obj, str1, str2));
	}
	else if (color_obj->type == BUMPMAP)
	{
		return (put_bumpmap(info, color_obj, str1, str2));
	}
	return (FALSE);
}
