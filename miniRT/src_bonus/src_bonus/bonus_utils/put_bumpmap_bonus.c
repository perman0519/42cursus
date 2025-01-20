/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bumpmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:06:22 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:22:48 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	init_bumpmap_texture(t_info *info, t_bumpmap *bumpmap, char *str1)
{
	bumpmap->texture.img.img = mlx_xpm_file_to_image(info->mlx->mlx, str1, \
		&(bumpmap->texture.width), &(bumpmap->texture.height));
	if (bumpmap->texture.img.img == NULL)
		str_exit("Error\ntexture_mlx_xpm_file_to_image_fail.\n");
	bumpmap->texture.img.bits_per_pixel = 0;
	bumpmap->texture.img.line_length = 0;
	bumpmap->texture.img.endian = 0;
	bumpmap->texture.img.addr = mlx_get_data_addr(bumpmap->texture.img.img, \
		&(bumpmap->texture.img.bits_per_pixel), \
		&(bumpmap->texture.img.line_length), \
		&(bumpmap->texture.img.endian));
	if (bumpmap->texture.img.addr == NULL)
		str_exit("Error\ntexture_mlx_get_data_addr_fail.\n");
}

static void	init_bumpmap_bumpmap(t_info *info, t_bumpmap *bumpmap, char *str2)
{
	if (!ft_strncmp(str2, "NULL", 4))
	{
		bumpmap->bumpmap.img.img = NULL;
		return ;
	}
	bumpmap->bumpmap.img.img = mlx_xpm_file_to_image(info->mlx->mlx, str2,
			&(bumpmap->bumpmap.width), &(bumpmap->bumpmap.height));
	if (bumpmap->bumpmap.img.img == NULL)
		str_exit("Error\nbumpmap_mlx_xpm_file_to_image_fail.\n");
	bumpmap->bumpmap.img.bits_per_pixel = 0;
	bumpmap->bumpmap.img.line_length = 0;
	bumpmap->bumpmap.img.endian = 0;
	bumpmap->bumpmap.img.addr = mlx_get_data_addr(bumpmap->bumpmap.img.img, \
		&(bumpmap->bumpmap.img.bits_per_pixel), \
		&(bumpmap->bumpmap.img.line_length), \
		&(bumpmap->bumpmap.img.endian));
	if (bumpmap->bumpmap.img.addr == NULL)
		str_exit("Error\nbumpmap_mlx_get_data_addr_fail.\n");
}

int	put_bumpmap(t_info *info, t_color_obj *color_obj, \
					char *str1, char *str2)
{
	t_bumpmap	*bumpmap;

	bumpmap = (t_bumpmap *)malloc(sizeof(t_bumpmap));
	if (!(check_xpm_file(str1) && check_xpm_file(str2)) && !bumpmap)
		return (FALSE);
	init_bumpmap_texture(info, bumpmap, str1);
	init_bumpmap_bumpmap(info, bumpmap, str2);
	color_obj->data = bumpmap;
	return (TRUE);
}
