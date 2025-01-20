/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:22:46 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/24 13:15:04 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	init_info(char *str, t_info *info)
{
	info->camera.fov = -1;
	info->ambient.color.x = -1;
	info->object = NULL;
	info->light = NULL;
	if (check_filename(str))
	{
		if (parse_rtfile(info, str)
			&& !(info->camera.fov == -1 || info->ambient.color.x == -1))
			return (TRUE);
		else
			str_exit("Error\nWrong File.\n");
	}
	else
		str_exit("Error\nWrong File.\n");
	return (TRUE);
}
