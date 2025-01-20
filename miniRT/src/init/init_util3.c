/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:25:10 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:46:50 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	parse_point(char **point_str)
{
	int		i;
	t_point	ret;
	double	value[3];

	ret.x = INFINITY;
	if (check_split_size(point_str, 3))
		return (ret);
	i = 0;
	while (point_str[i])
	{
		value[i] = ft_atof(point_str[i]);
		if (value[i] == INFINITY)
			return (ret);
		i++;
	}
	ret.x = value[0];
	ret.y = value[1];
	ret.z = value[2];
	return (ret);
}

t_vec	parse_vec(char **vec_str)
{
	int		i;
	t_vec	ret;
	double	value[3];

	ret.x = INFINITY;
	if (check_split_size(vec_str, 3))
		return (ret);
	i = 0;
	while (vec_str[i])
	{
		value[i] = ft_atof(vec_str[i]);
		if (value[i] == INFINITY || (value[i] < -1.0 || value[i] > 1.0))
			return (ret);
		i++;
	}
	ret.x = value[0];
	ret.y = value[1];
	ret.z = value[2];
	return (ret);
}

int	ambient_init(char **split, t_info *info)
{
	static int	count = 0;
	double		ratio;
	t_color		color;
	char		**value3_split;

	if (++count > 1 || check_split_size(split, 3))
		return (FALSE);
	ratio = ft_atof(split[1]);
	value3_split = ft_split(split[2], ',');
	if (value3_split == NULL)
		return (FALSE);
	color = parse_color(value3_split);
	ft_free_split(value3_split);
	if ((is_strv3(split[2])) == FALSE || color.x == -1
		|| (ratio < 0.0 || ratio > 1.0))
		return (FALSE);
	else
		info->ambient = ambient_create(color, ratio);
	return (TRUE);
}

int	camera_init(char **split, t_info *info)
{
	static int	count = 0;
	t_ray		ray;
	int			fov;
	char		**value3_split;

	if ((++count > 1 || check_split_size(split, 4)) || \
		((is_strv3(split[1]) & is_strv3(split[2])) & is_strnum(split[3])) == 0)
		return (FALSE);
	value3_split = ft_split(split[1], ',');
	if (value3_split == NULL)
		return (FALSE);
	ray.origin = parse_point(value3_split);
	ft_free_split(value3_split);
	value3_split = ft_split(split[2], ',');
	if (value3_split == NULL)
		return (FALSE);
	ray.unit_dir = parse_vec(value3_split);
	ft_free_split(value3_split);
	fov = ft_atoi(split[3]);
	if (ray.origin.x == INFINITY || ray.unit_dir.x == INFINITY \
		|| fov <= 0 || fov > 180)
		return (FALSE);
	else
		info->camera = camera_create(ray.origin, ray.unit_dir, fov);
	return (TRUE);
}

int	light_init(char **split, t_info *info)
{
	static int	count = 0;
	t_light		light;
	double		ratio;
	char		**value3_split;

	if ((++count > 1 || check_split_size(split, 3)) || \
			is_strv3(split[1]) == FALSE)
		return (FALSE);
	value3_split = ft_split(split[1], ',');
	if (value3_split == NULL)
		return (FALSE);
	light.origin = parse_point(value3_split);
	ft_free_split(value3_split);
	ratio = ft_atof(split[2]);
	light.color = color_create(1, 1, 1);
	if (light.origin.x == INFINITY || light.color.x == -1 || \
		ratio < 0 || ratio > 1.0)
		return (FALSE);
	else
		info->light = light_create(light.origin, light.color, ratio);
	return (TRUE);
}
