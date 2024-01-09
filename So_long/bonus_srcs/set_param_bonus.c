/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:58:38 by junssong          #+#    #+#             */
/*   Updated: 2023/05/30 12:50:03 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	set_param(t_param *par, char *map)
{
	par->fd = open(map, O_RDONLY);
	par->map = NULL;
	par->count_e = 0;
	par->count_p = 0;
	par->count_c = 0;
	par->x_size = 0;
	par->y_size = 0;
	par->move_count = 0;
	par->player_x = 0;
	par->player_y = 0;
	par->mlx_ptr = mlx_init();
	par->g_img = mlx_xpm_file_to_image(par->mlx_ptr \
	, "./imgs/ground.xpm", &par->width, &par->heigth);
	par->p_img = mlx_xpm_file_to_image(par->mlx_ptr \
	, "./imgs/player.xpm", &par->width, &par->heigth);
	par->w_img = mlx_xpm_file_to_image(par->mlx_ptr \
	, "./imgs/wall.xpm", &par->width, &par->heigth);
	par->c_img = mlx_xpm_file_to_image(par->mlx_ptr \
	, "./imgs/coin.xpm", &par->width, &par->heigth);
	par->e_img = mlx_xpm_file_to_image(par->mlx_ptr \
	, "./imgs/e.xpm", &par->width, &par->heigth);
	if (par->g_img == NULL || par->p_img == NULL || par->w_img == NULL || \
	par->c_img == NULL || par->e_img == NULL)
		exit(1);
	return (1);
}
