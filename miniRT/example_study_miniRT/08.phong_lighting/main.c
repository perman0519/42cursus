/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:34:48 by junssong          #+#    #+#             */
/*   Updated: 2024/02/12 19:02:28 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"

t_scene *scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka; // 8.4 에서 설명

	// malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(720, 480);
	scene->camera = camera(&scene->canvas, point3(0,0,20));
	world = object(SP, sphere(point3(0, 0, -5), 2), color3(0.5, 0.5, 0)); // world 에 구1 추가
	// oadd(&world, object(SP, sphere(point3(3, 4, -6), 2), color3(0, 0.5, 0.5))); // world 에 구2 추가
	// oadd(&world, object(SP, sphere(point3(-5, 4, -8), 2), color3(0.5, 0, 0.5))); // world 에 구2 추가
	oadd(&world, object(SP, sphere(point3(0, -1000, -50), 999), color3(1, 1, 1))); // world 에 구3 추가
	scene->world = world;
	// lights = object(LIGHT_POINT, light_point(point3(-50, 5, 5), color3(1, 1, 1), 0.5), color3(0, 0, 0)); // 더미 albedo
	lights = object(LIGHT_POINT, light_point(point3(0, 0, 2), color3(1, 1, 1), 0.5), color3(0, 0, 0)); // 더미 albedo
	scene->light = lights;
	ka = 0.3; // 8.4 에서 설명
	scene->ambient = vmult(color3(1,1,1), ka); // 8.4 에서 설명
return (scene);
}

int	main(void)
{
	int			i;
	int			j;
	int			k;
	double		u;
	double		v;
	t_color3	pixel_color;
	t_scene		*scene;
	int samples_per_pixel = 100;

	scene = scene_init();
	// 랜더링
	// P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값

	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	j = scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			k = 0;
			pixel_color = color3(0, 0, 0);
			while (k < samples_per_pixel)
			{
				u = (double)(i + rand_num(1)) / (scene->canvas.width - 1);
				v = (double)(j + rand_num(1)) / (scene->canvas.height - 1);
				//ray from camera origin to pixel
				scene->ray = ray_primary(&scene->camera, u, v);
				pixel_color = vplus(ray_color(scene), pixel_color);
				k++;
				// ray_color함수의 인자도 ray, world를 모두 담고 있는 scene으로 바꿨다.
			}
			write_color(pixel_color, samples_per_pixel);
			++i;
		}
		--j;
	}
	return (0);
}
