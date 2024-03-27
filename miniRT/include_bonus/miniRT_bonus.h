/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:21:27 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/24 15:43:29 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "get_next_line_bonus.h"
# include "../mlx/mlx.h"
# include "structure_bonus.h"
# include "vec_utils_bonus.h"

# define FALSE 0
# define TRUE 1
# define DEFAULT -1

# define EPSILON 1e-6 // 0.000001
# define _INFINITY 100000

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define VIEWPOINT_W 2.0

/* Object Number */
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define LIGHT 3
# define PARABOLOID 4
# define NSP 5

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

# define CHECK_WIDTH 19
# define CHECK_HEIGHT 19

# define NUM_THREAD 6

/* init */
int				check_filename(char *str);
int				parse_rtfile(t_info *info, char *str);
void			ft_free_split(char **split_string);
int				ambient_init(char **split, t_info *info);
int				camera_init(char **split, t_info *info);
int				light_init(char **split, t_info *info);
int				sp_init(char **split, t_info *info);
int				nsp_init(char **split, t_info *info);
int				cy_init(char **split, t_info *info);
int				pl_init(char **split, t_info *info);
int				pb_init(char **split, t_info *info);

int				check_split_size(char **split, int split_size);
int				is_strv3(char *str);
int				is_strnum(char *str);
t_color			parse_color(char **rgb_str);
void			ft_free_split(char **split_string);
t_point			parse_point(char **point_str);
t_vec			parse_vec(char **vec_str);

/* camera */
t_camera		camera_create(t_point origin, t_vec dir, int FOV);

/* object */
t_sphere		sphere_create(t_point origin, t_color_obj color_obj, double r);
t_plane			plane_create(t_point origin, t_vec dir, t_color_obj color_obj);
t_cylinder		cylinder_create(t_point origin, t_vec dir,
					t_color_obj color_obj, t_obj_info obj_info);
t_paraboloid	paraboloid_create(t_point origin, double a, double b, \
								t_color_obj	color_obj);

/* ray */
t_ray			ray_create(t_point origin, t_vec dir);
t_ray			ray_primary(t_info *info, double u, double v);
int				ray_color(t_info *info, t_ray *ray);

/* light */
t_light			light_create(t_point origin, t_color color, double ratio);
t_ambient		ambient_create(t_color color, double ratio);

/* phong */
t_color			phong_lighting(t_info *info, t_ray *ray, t_rec *rec);
int				is_in_shadow(t_info *info, t_light *light, t_rec *rec);
int				is_hit_sphere_shadow(t_sphere *sphere, t_light *light, \
								t_rec *rec);
int				is_hit_plane_shadow(t_plane *plane, t_light *light, t_rec *rec);
int				is_hit_cy_shadow(t_cylinder *cylinder, t_light *light, \
								t_rec *rec);
int				is_hit_cy_plane_shadow(t_plane *plane, double r,
					t_light *light, t_rec *rec);
int				is_hit_paraboloid_shadow(t_paraboloid *paraboloid, \
								t_light *light, t_rec *rec);

/* mlx */
int				init_info(char *str, t_info *info);
t_mlx			init_mlx(void);
void			mlx_event(t_info *info);

int				minirt_loop(t_info *info);

/* mlx image */
void			my_mlx_pixel_put(t_info *info, int x, int y, int color);

/* rec */
t_rec			rec_create(void);

/* hit */
int				is_hit(t_info *info, t_ray *ray, t_rec *rec);
int				is_hit_sphere(t_sphere *sphere, t_ray *ray, t_rec *rec);
int				is_hit_plane(t_plane *plane, t_ray *ray, t_rec *rec);
int				is_hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_rec *rec);
int				is_hit_cylinder_plane(t_plane *plane, float r,
					t_ray *ray, t_rec *rec);
int				is_hit_paraboloid(t_paraboloid *paraboloid, t_ray *ray, \
								t_rec *rec);

/* uv mapping and bump */
t_e_color		check_color_obj(char *str);
int				parse_color_obj(t_info *info, t_color_obj *color_obj, \
								char *str1, char *str2);
int				check_xpm_file(char *str);
void			get_rec_color(t_color_obj *color_obj, t_rec *rec, \
								double u, double v);
void			create_thread(t_info *info);
void			str_exit(char *str);
int				put_bumpmap(t_info *info, t_color_obj *color_obj, \
								char *str1, char *str2);
#endif
