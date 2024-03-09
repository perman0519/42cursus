/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:34:48 by junssong          #+#    #+#             */
/*   Updated: 2024/02/04 13:29:32 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"

int	main(void)
{
	int			i;
	int			j;
	double		u;
    double		v;
	t_color3	pixel_color;

	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;
	t_object	*world;
	//Scene setting;
	canv = canvas(800, 400);
	cam = camera(&canv, point3(0, 0, 0));

	world = object(SP, sphere(point3(-2, 0, -5), 2));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2)));
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 990)));

	// 랜더링
	// P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
	printf("P3\n%d %d\n255\n", canv.width, canv.height);
	j = canv.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < canv.width)
		{
			u = (double)i / (canv.width - 1);
			v = (double)j / (canv.height - 1);
			//ray from camera origin to pixel
			ray = ray_primary(&cam, u, v);
			pixel_color = ray_color(&ray, world);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
	return (0);
}
