/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:21:27 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 12:03:40 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "get_next_line_bonus.h"
# include "mlx.h"
# include "structure.h"
# include "vec_utils.h"

# define FALSE 0
# define TRUE 1

# define EPSILON 1e-6 // 0.000001
# define _INFINITY 100000

/* Screen */
# define WIN_WIDTH 720
# define WIN_HEIGHT 480
# define VIEWPOINT_W 2.0

/* Object Number */
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2

# define KEYPRESS 2
# define X_BUTTON 17

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

/* init */
int			check_filename(char *str);
int			parse_rtfile(t_info *info, char *str);
void		ft_free_split(char **split_string);
int			ambient_init(char **split, t_info *info);
int			camera_init(char **split, t_info *info);
int			light_init(char **split, t_info *info);
int			sp_init(char **split, t_info *info);
int			cy_init(char **split, t_info *info);
int			pl_init(char **split, t_info *info);

int			check_split_size(char **split, int split_size);
int			is_strv3(char *str);
int			is_strnum(char *str);
t_color		parse_color(char **rgb_str);
void		ft_free_split(char **split_string);
t_point		parse_point(char **point_str);
t_vec		parse_vec(char **vec_str);

/* camera */
t_camera	camera_create(t_point origin, t_vec dir, int FOV);

/* object */
t_sphere	sphere_create(t_point origin, t_color color, double r);
t_plane		plane_create(t_point origin, t_vec dir, t_color color);
t_cylinder	cylinder_create(t_cylinder cylinder);
/* ray */
t_ray		ray_create(t_point origin, t_vec dir);
t_ray		ray_primary(t_info *info, double u, double v);
int			ray_color(t_info *info);

/* light */
t_light		light_create(t_point origin, t_color color, double ratio);
t_ambient	ambient_create(t_color color, double ratio);

/* phong */
t_color		phong_lighting(t_info *info);
int			is_in_shadow(t_info *info);
int			is_hit_sphere_shadow(t_info *info, t_sphere *sphere);
int			is_hit_plane_shadow(t_info *info, t_plane *plane);
int			is_hit_cylinder_shadow(t_info *info, t_cylinder *cylinder);
int			is_hit_cylinder_plane_shadow(t_info *info, t_plane *plane, float r);

/* mlx */
int			init_info(char *str, t_info *info);
t_mlx		init_mlx(void);
void		mlx_event(t_info *info);

int			minirt_loop(t_info *info);

/* mlx image */
void		my_mlx_pixel_put(t_info *info, int x, int y, int color);

/* rec */
t_rec		rec_create(void);

/* hit */
int			is_hit(t_info *info);
int			is_hit_sphere(t_info *info, t_sphere *sphere);
int			is_hit_plane(t_info *info, t_plane *plane);
int			is_hit_cylinder(t_info *info, t_cylinder *cylinder);
int			is_hit_cylinder_plane(t_info *info, t_plane *plane, float r);
#endif
