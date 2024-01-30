/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:34:48 by junssong          #+#    #+#             */
/*   Updated: 2024/01/29 14:06:12 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"

int	main(void)
{
	int			i;
	int			j;
	int			canvas_width;
	int			canvas_height;
	t_color3	pixel_color;

	canvas_width = 1024;
	canvas_height = 1024;

	printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
	j = 0;
	while (j < canvas_height)
	{
		i = 0;
		while (i < canvas_width)
		{
			pixel_color.x = (double)i / (canvas_width - 1);
			pixel_color.y = (double)j / (canvas_height - 1);
			pixel_color.z = 0;
			write_color(pixel_color);
			++i;
		}
		++j;
	}
	return (0);
}
