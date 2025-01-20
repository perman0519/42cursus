/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:35:56 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/24 13:23:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_mlx	init_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		str_exit("Error\nmlx_init_fail.\n");
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	if (mlx.mlx_win == NULL)
		str_exit("Error\nmlx_new_window_fail.\n");
	mlx.image.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (mlx.image.img == NULL)
		str_exit("Error\nmlx_new_image_fail.\n");
	mlx.image.bits_per_pixel = 0;
	mlx.image.line_length = 0;
	mlx.image.endian = 0;
	mlx.image.addr = mlx_get_data_addr(
			mlx.image.img,
			&(mlx.image.bits_per_pixel),
			&(mlx.image.line_length),
			&(mlx.image.endian));
	if (mlx.image.addr == NULL)
		str_exit("Error\nmlx.image.addr_fail.\n");
	return (mlx);
}
