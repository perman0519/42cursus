/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:35:56 by junhapar          #+#    #+#             */
/*   Updated: 2024/02/10 19:28:40 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mlx	init_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		exit (1);
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	if (mlx.mlx_win == NULL)
		exit (1);
	mlx.image.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (mlx.image.img == NULL)
		exit (1);
	mlx.image.bits_per_pixel = 0;
	mlx.image.line_length = 0;
	mlx.image.endian = 0;
	mlx.image.addr = mlx_get_data_addr(
			mlx.image.img,
			&(mlx.image.bits_per_pixel),
			&(mlx.image.line_length),
			&(mlx.image.endian));
	if (mlx.image.addr == NULL)
		exit (1);
	return (mlx);
}
