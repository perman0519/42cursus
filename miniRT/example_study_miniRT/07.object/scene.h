/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:57:16 by junssong          #+#    #+#             */
/*   Updated: 2024/02/02 14:08:50 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas	canvas(int  width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);

t_object	*object(t_object_type type, void *element);
t_sphere	*sphere(t_point3 center, double radius);

#endif
