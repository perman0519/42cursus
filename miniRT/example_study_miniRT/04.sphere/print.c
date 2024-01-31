/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:48:51 by junssong          #+#    #+#             */
/*   Updated: 2024/01/29 14:03:13 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print.h"

void	write_color(t_color3 pixel_color)
{
	printf("%d %d %d\n", \
		(int)(255.999 * pixel_color.x), \
		(int)(255.999 * pixel_color.y), \
		(int)(255.999 * pixel_color.z));
}
