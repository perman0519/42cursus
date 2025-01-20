/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rec_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:27:33 by junssong          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:58 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	get_bumpmap_color(t_bumpmap *bumpmap, \
			t_rec *rec, double u, double v)
{
	unsigned int	pos;

	pos = *(unsigned int *)(bumpmap->texture.img.addr + \
		((int)round(v * (bumpmap->texture.height -1)) * \
		(bumpmap->texture.img.line_length) + \
			(int)round(u * bumpmap->texture.width) * \
			(bumpmap->texture.img.bits_per_pixel / 8)));
	rec->color = color_create(((pos << 8) >> 24) / 255.99, \
		((pos << 16) >> 24) / 255.99, ((pos << 24) >> 24) / 255.99);
}

void	get_bumpmap_normal(t_bumpmap *bumpmap, t_rec *rec, double u, double v)
{
	t_vec			t;
	t_vec			b;
	t_vec			n;
	t_vec			bp_normal;
	unsigned int	bump_pos;

	if (bumpmap->bumpmap.img.img == NULL)
		return ;
	t = vec_unit(vec_cross(vec_create(0, 0, 1), rec->normal_dir));
	if (!vec_len(t))
		t = vec_create(1, 0, 0);
	b = vec_unit(vec_cross(rec->normal_dir, t));
	n = rec->normal_dir;
	bump_pos = *(unsigned int *)(bumpmap->bumpmap.img.addr + \
		((int)round(v * (bumpmap->bumpmap.height - 1)) * \
		bumpmap->bumpmap.img.line_length + (int)round(u * \
		(bumpmap->bumpmap.width - 1)) * \
			(bumpmap->texture.img.bits_per_pixel / 8)));
	bp_normal = vec_unit(vec_div(vec_minus(vec_create(((bump_pos << 8) >> 24), \
		((bump_pos << 16) >> 24), ((bump_pos << 24) >> 24)), 128), 128));
	rec->normal_dir = vec_unit(vec_create \
		((t.x * bp_normal.x) +(b.x * bp_normal.y) + (n.x * bp_normal.z), \
		(t.y * bp_normal.x) + (b.y * bp_normal.y) + (n.y * bp_normal.z), \
		(t.z * bp_normal.x) + (b.z * bp_normal.y) + (n.z * bp_normal.z)));
}

void	get_rec_color(t_color_obj *color_obj, t_rec *rec, double u, double v)
{
	t_checker	*checker;
	t_color		*color;

	if (color_obj->type == COLOR)
	{
		color = (t_color *)color_obj->data;
		rec->color = color_create(color->x, color->y, color->z);
	}
	else if (color_obj->type == CHECKER)
	{
		checker = color_obj->data;
		if ((int)(ceil(u * checker->width) + ceil(v * checker->height)) % 2)
			rec->color = checker->color1;
		else
			rec->color = checker->color2;
	}
	else if (color_obj->type == BUMPMAP)
	{
		get_bumpmap_color((t_bumpmap *)color_obj->data, rec, u, v);
		get_bumpmap_normal((t_bumpmap *)color_obj->data, rec, u, v);
	}
}
