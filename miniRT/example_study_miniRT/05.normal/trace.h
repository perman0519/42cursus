/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:41:49 by junssong          #+#    #+#             */
/*   Updated: 2024/01/31 15:30:00 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);

t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_ray *ray, t_sphere *sphere);

// trace/hit/
double      hit_sphere(t_sphere *sp, t_ray *ray);
#endif
