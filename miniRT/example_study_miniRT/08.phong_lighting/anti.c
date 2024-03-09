/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:24:54 by junssong          #+#    #+#             */
/*   Updated: 2024/02/04 19:24:54 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "print.h"

double	rand_num(int anti)
{
	if (anti == 0) // anti 횟수를 변수로 받아와서 anti가 0 이라면 return 0;
		return (0);
	else
		return ((double)rand() / (double)RAND_MAX);
}

double	clamp(double x, double min, double max) {
	if (x < min) return min;
	if (x > max) return max;
	return x;
}
