/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:26:15 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/21 21:43:02 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "libft.h"

typedef struct s_vec		t_vec;
typedef struct s_vec		t_point;
typedef struct s_vec		t_color;

typedef struct s_ray		t_ray;

typedef struct s_camera		t_camera;

typedef struct s_light		t_light;
typedef struct s_light		t_ambient;

typedef struct s_hit_info	t_hit_info;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

typedef struct s_rec		t_rec;

typedef struct s_info		t_info;

typedef struct s_image		t_image;
typedef struct s_mlx		t_mlx;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

struct s_ray
{
	t_point	origin;
	t_vec	unit_dir;
};

struct s_camera
{
	t_point	origin;
	t_vec	unit_dir;
	double	width_viewpoint;
	double	height_viewpoint;
	double	foacl_len;
	double	fov;
	t_vec	dir_viewpoint_h;
	t_vec	dir_viewpoint_v;
	t_point	left_bottom;
};

struct s_light
{
	t_point	origin;
	t_color	color;
	double	ratio;
};

struct s_hit_info
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	const_d;
	double	t;
	t_ray	v_rec_to_light;
};

struct s_sphere
{
	t_point	origin;
	t_color	color;
	double	r;
};

struct s_plane
{
	t_point	origin;
	t_vec	normal_dir;
	t_color	color;
};

struct s_cylinder
{
	t_point	origin;
	t_vec	normal_dir;
	t_color	color;
	double	r;
	double	height;
};

struct s_rec
{
	double	t_min;
	double	t_max;
	t_point	origin;
	t_vec	normal_dir;
	t_color	color;
};

struct s_info
{
	t_ray		ray;
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_list		*object;
	t_rec		rec;
	t_mlx		*mlx;
};

struct s_image
{
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
};

struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_image	image;
};
#endif
