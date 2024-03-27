/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:04:33 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:41:30 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTILS_BONUS_H
# define VEC_UTILS_BONUS_H

# include "structure_bonus.h"

t_vec	vec_create(double x, double y, double z);
t_point	point_create(double x, double y, double z);
t_color	color_create(double r, double g, double b);

t_vec	vec_plus(t_vec vec, double f);
t_vec	vec_plus_v(t_vec vec, t_vec vec2);
t_vec	vec_minus(t_vec vec, double f);
t_vec	vec_minus_v(t_vec vec, t_vec vec2);

t_vec	vec_mult(t_vec vec, double f);
t_vec	vec_mult_v(t_vec vec, t_vec vec2);
t_vec	vec_div(t_vec vec, double f);

double	vec_dot(t_vec vec, t_vec vec2);
t_vec	vec_cross(t_vec vec, t_vec vec2);

double	vec_len(t_vec vec);

t_vec	vec_unit(t_vec vec);

#endif
