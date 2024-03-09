/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:48:51 by junssong          #+#    #+#             */
/*   Updated: 2024/02/04 19:26:12 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print.h"

void	write_color(t_color3 pixel_color, int samples_per_pixel)
{
	double r;
	double g;
	double b;
	// Divide the color by the number of samples.
	double scale;

	scale = 1.0 / samples_per_pixel;
	r = pixel_color.x * scale;
	g = pixel_color.y * scale;
	b = pixel_color.z * scale;

	// printf("%d %d %d\n", \
	// 	(int)(255.999 * pixel_color.x), \
	// 	(int)(255.999 * pixel_color.y), \
	// 	(int)(255.999 * pixel_color.z));
	printf("%d %d %d\n", \
		(int)(255.999 * clamp(r, 0.0, 0.999)), \
		(int)(255.999 * clamp(g, 0.0, 0.999)), \
		(int)(255.999 * clamp(b, 0.0, 0.999)));
}
