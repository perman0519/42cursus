/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:36:35 by junssong          #+#    #+#             */
/*   Updated: 2023/05/26 19:36:40 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_param		param;

	if (argc != 2)
		exit(1);
	set_param(&param, argv[1]);
	read_map(argv[1], &param);
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.x_size * param.heigth, \
	param.y_size * param.width, "zelda");
	print_map(&param);
	mlx_key_hook(param.win_ptr, &key_press, &param);
	mlx_hook(param.win_ptr, PRESS_RED_BUTTON, 0, &close_red, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}

int	close_red(t_param *param)
{
	ft_free_split(param->split_map);
	exit(0);
	return (0);
}
