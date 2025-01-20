/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:22:46 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/24 13:18:02 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_info(char *str, t_info *info)
{
	info->ray = ray_create(point_create(0, 0, 0), vec_create(0, 0, 0));
	info->camera.fov = -1;
	info->ambient.color.x = -1;
	info->object = NULL;
	info->rec = rec_create();
	if (check_filename(str))
	{
		if (parse_rtfile(info, str)
			&& !(info->camera.fov == -1 || info->ambient.color.x == -1))
			return (TRUE);
		else
		{
			ft_lstclear(&(info->object), free);
			ft_putstr_fd("Error\nWrong File.\n", 2);
			return (FALSE);
		}
	}
	else
	{
		ft_putstr_fd("Error\nWrong File.\n", 2);
		return (FALSE);
	}
}
