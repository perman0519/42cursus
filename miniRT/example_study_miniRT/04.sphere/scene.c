/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:59:50 by junssong          #+#    #+#             */
/*   Updated: 2024/01/31 15:20:57 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

// t_camera	camera(t_canvas *canvas, t_point3 orig)
// {
// 	t_camera	cam;
// 	double		focal_len;
// 	double		viewport_height;

// 	viewport_height = 2.0;
// 	focal_len = 1.0;
// 	cam.orig = orig;
// 	cam.viewprot_h = canvas->height;
// 	cam.viewprot_w = canvas->height * canvas->aspect_ratio;
// 	cam.focal_len = focal_len;
// 	cam.horizontal = vec3(cam.viewprot_w, 0, 0);
// 	cam.vertical = vec3(0, cam.viewprot_h, 0);
// 	// 왼쪽 아래 코너점 좌표, origin - horizontal / 2 - vertical / 2 - vec3(0,0,focal_length)
//     cam.left_bottom = vminus(vminus(vminus(cam.orig, vdivide(cam.horizontal, 2)),
//                                 vdivide(cam.vertical, 2)), vec3(0, 0, focal_len));
// 	return (cam);
// }

t_camera    camera(t_canvas *canvas, t_point3 orig)
{
    t_camera    cam;
    double      focal_len;
    double      viewport_height;

    viewport_height = 2.0;
    focal_len = 1.0;
    cam.orig = orig;
    cam.viewport_h = viewport_height;
    cam.viewport_w = viewport_height * canvas->aspect_ratio;
    cam.focal_len = focal_len;
    cam.horizontal = vec3(cam.viewport_w, 0, 0);
    cam.vertical = vec3(0, cam.viewport_h, 0);
    // 왼쪽 아래 코너점 좌표, origin - horizontal / 2 - vertical / 2 - vec3(0,0,focal_length)
    cam.left_bottom = vplus(vminus(vminus(cam.orig, vdivide(cam.horizontal, 2)),
                                vdivide(cam.vertical, 2)), vec3(0, 0, focal_len));
    return (cam);
}