/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:48:51 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/24 13:14:34 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_mlx	mlx;

	if (argc == 2)
	{
		if (init_info(argv[1], &info) == FALSE)
			return (1);
	}
	else
	{
		ft_putstr_fd("Error\narguments count\n", 2);
		exit (1);
	}
	mlx = init_mlx();
	info.mlx = &mlx;
	mlx_event(&info);
	minirt_loop(&info);
	mlx_loop(mlx.mlx);
	return (0);
}
