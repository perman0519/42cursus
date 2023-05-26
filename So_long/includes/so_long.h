/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:20:25 by junssong          #+#    #+#             */
/*   Updated: 2023/05/26 19:48:42 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "hook.h"
# include <fcntl.h>
# include <stdlib.h>

# define TRUE	1
# define FALSE	0
# define CHECK	0x80

typedef struct s_param
{
	int		fd;
	char	*map;
	char	**split_map;
	int		count_e;
	int		count_p;
	int		count_c;
	int		x_size;
	int		y_size;
	int		move_count;
	int		player_x;
	int		player_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*g_img;
	void	*w_img;
	void	*c_img;
	void	*e_img;
	void	*p_img;
	int		width;
	int		heigth;
}				t_param;

typedef struct s_find_ce
{
	int	find_c;
	int	find_e;
}				t_find_ce;

int		key_press(int keycode, t_param *param);
int		close_red(t_param *x_y);

int		set_param(t_param *par, char *map);

void	read_map(char *map, t_param *param);
void	check_map_err(t_param *param);
void	err_map(t_param *param, char *err_msg);
void	map_dfs(t_param *param);
void	print_map(t_param *param);

void	move_up(t_param *param);
void	move_down(t_param *param);
void	move_left(t_param *param);
void	move_right(t_param *param);
int		check_c_e(t_param *param, int i, int j);

#endif
