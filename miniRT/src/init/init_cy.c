/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:14:24 by junssong          #+#    #+#             */
/*   Updated: 2024/03/21 20:44:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	help_cy_init(char **split, t_cylinder *tmp)
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
	value3_split = ft_split(split[5], ',');
	if (value3_split == NULL)
		return (FALSE);
	tmp->color = parse_color(value3_split);
	ft_free_split(value3_split);
	return (TRUE);
}

int	cy_init(char **split, t_info *info)
{
	t_cylinder	tmp;
	t_cylinder	*cylinder;

	if (check_split_size(split, 6) \
		|| !((is_strv3(split[1]) & is_strv3(split[2])) & is_strv3(split[5])))
		return (FALSE);
	if (help_cy_init(split, &tmp) == FALSE)
		return (FALSE);
	tmp.r = ft_atof(split[3]) * 0.5;
	tmp.height = ft_atof(split[4]);
	if (tmp.origin.x == INFINITY || tmp.normal_dir.x == INFINITY \
		|| tmp.color.x == -1 || tmp.height == INFINITY \
			|| tmp.r == INFINITY * 0.5)
		return (FALSE);
	else
	{
		cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
		if (cylinder == NULL)
			return (FALSE);
		*cylinder = cylinder_create(tmp);
		ft_lstadd_back(&(info->object), ft_lstnew(cylinder, CYLINDER));
	}
	return (TRUE);
}
