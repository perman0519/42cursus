/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:20:59 by junssong          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:59 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	help_light_init(t_light light, t_info *info, double ratio)
{
	t_light	*content;

	if (light.origin.x == INFINITY || light.color.x == -1 || \
		ratio < 0 || ratio > 1.0)
		return (FALSE);
	else
	{
		content = (t_light *)malloc(sizeof(t_light));
		if (content == NULL)
			return (FALSE);
		*content = light_create(light.origin, light.color, ratio);
		ft_lstadd_back(&(info->light), ft_lstnew(content, LIGHT));
		return (TRUE);
	}
}

int	light_init(char **split, t_info *info)
{
	t_light	light;
	double	ratio;
	char	**value3_split;

	if (check_split_size(split, 4) \
		|| (is_strv3(split[1]) & is_strv3(split[3])) == FALSE)
		return (FALSE);
	value3_split = ft_split(split[1], ',');
	if (value3_split == NULL)
		return (FALSE);
	light.origin = parse_point(value3_split);
	ft_free_split(value3_split);
	ratio = ft_atof(split[2]);
	value3_split = ft_split(split[3], ',');
	if (value3_split == NULL)
		return (FALSE);
	light.color = parse_color(value3_split);
	ft_free_split(value3_split);
	return (help_light_init(light, info, ratio));
}
