/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:59:21 by junssong          #+#    #+#             */
/*   Updated: 2023/05/30 12:41:18 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	help_print_map(t_param *param, int i, int j);

void	print_map(t_param *param)
{
	int		i;
	int		j;

	i = 0;
	while (i < param->y_size)
	{
		j = -1;
		while (++j < param->x_size)
		{
			help_print_map(param, i, j);
		}
		i++;
	}
}

void	help_print_map(t_param *param, int i, int j)
{
	mlx_put_image_to_window(param ->mlx_ptr, param->win_ptr, \
	param->g_img, param ->width * j, param ->heigth * i);
	if (param->split_map[i][j] == '1')
		mlx_put_image_to_window(param ->mlx_ptr, param->win_ptr, \
		param->w_img, param ->width * j, param ->heigth * i);
	if (param->split_map[i][j] == 'E')
		mlx_put_image_to_window(param ->mlx_ptr, param->win_ptr, \
		param->e_img, param ->width * j, param ->heigth * i);
	if (param->split_map[i][j] == 'C')
		mlx_put_image_to_window(param ->mlx_ptr, param->win_ptr, \
		param->c_img, param ->width * j, param ->heigth * i);
	mlx_put_image_to_window(param ->mlx_ptr, param->win_ptr, \
	param->p_img, param ->player_x * 64, param->player_y * 64);
}
