/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:48:51 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/24 13:49:39 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_mlx	mlx;

	mlx = init_mlx();
	info.mlx = &mlx;
	if (argc == 2)
	{
		if (init_info(argv[1], &info) == FALSE)
			return (1);
	}
	else
		str_exit("Error\nInvalid arguments.\n");
	mlx_event(&info);
	if (pthread_mutex_init(&(info.mlx_img_mutex), NULL))
		str_exit("Error\npthread_mutex_init_fail.\n");
	if (pthread_mutex_init(&(info.start_i_mutex), NULL))
		str_exit("Error\npthread_mutex_init_fail.\n");
	create_thread(&info);
	mlx_loop(mlx.mlx);
	return (0);
}
