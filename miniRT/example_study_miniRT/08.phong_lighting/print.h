/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:48:26 by junssong          #+#    #+#             */
/*   Updated: 2024/02/04 19:24:40 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "stdio.h"
# include "structures.h"

void	write_color(t_color3 pixel_color, int samples_per_pixel);
double	clamp(double x, double min, double max);
double	rand_num(int anti);

#endif
