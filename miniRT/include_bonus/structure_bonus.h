/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:26:15 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 17:41:24 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_BONUS_H
# define STRUCTURE_BONUS_H

# include "libft.h"
# include "pthread.h"

typedef struct s_vec		t_vec;
typedef struct s_vec		t_point;
typedef struct s_vec		t_color;

typedef struct s_ray		t_ray;

typedef struct s_camera		t_camera;

typedef struct s_light		t_light;
typedef struct s_light		t_ambient;

typedef struct s_color_obj	t_color_obj;
typedef struct s_hit_info	t_hit_info;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_paraboloid	t_paraboloid;

typedef struct s_rec		t_rec;

typedef struct s_info		t_info;

typedef struct s_obj_info	t_obj_info;

typedef struct s_image		t_image;
typedef struct s_mlx		t_mlx;

typedef struct s_checker	t_checker;
typedef struct s_xpm		t_xpm;
typedef struct s_bumpmap	t_bumpmap;

typedef enum e_color
{
	FAIL = -1,
	COLOR,
	CHECKER,
	BUMPMAP
}			t_e_color;

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

struct s_color_obj
{
	t_e_color	type;
	void		*data;
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
	t_point		origin;
	t_color_obj	color_obj;
	double		r;
};

struct s_plane
{
	t_point		origin;
	t_vec		normal_dir;
	t_color_obj	color_obj;
	double		u;
	double		v;
};

struct s_cylinder
{
	t_point		origin;
	t_vec		normal_dir;
	t_color_obj	color_obj;
	double		r;
	double		height;
};

struct s_paraboloid
{
	t_point		origin;
	double		a;
	double		b;
	t_color_obj	color_obj;
};

/* ray의 origin is 교점, dir is 법선벡터 */
struct s_rec
{
	double	t_min;
	double	t_max;
	t_vec	normal_dir;
	t_point	origin;
	t_color	color;
	int		type;
};

struct s_info
{
	t_camera		camera;
	t_ambient		ambient;
	t_list			*light;
	t_list			*object;
	t_mlx			*mlx;
	pthread_mutex_t	mlx_img_mutex;
	int				start_i;
	pthread_mutex_t	start_i_mutex;
};

struct s_obj_info
{
	double	r;
	double	height;
};

struct s_image
{
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
};

struct s_checker
{
	t_color	color1;
	t_color	color2;
	int		width;
	int		height;
};

struct s_xpm
{
	t_image	img;
	int		width;
	int		height;
};

struct s_bumpmap
{
	t_xpm	texture;
	t_xpm	bumpmap;
};

struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_image	image;
};

#endif
