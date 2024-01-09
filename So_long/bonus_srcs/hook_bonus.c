/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:59:12 by junssong          #+#    #+#             */
/*   Updated: 2023/05/30 12:49:51 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		move_up(param);
	else if (keycode == KEY_S)
		move_down(param);
	else if (keycode == KEY_A)
		move_left(param);
	else if (keycode == KEY_D)
		move_right(param);
	else if (keycode == KEY_ESC)
	{
		ft_free_split(param->split_map);
		exit(0);
	}
	print_map(param);
	return (1);
}

void	move_up(t_param *param)
{
	int	i;
	int	j;

	param->player_y--;
	j = param->player_x;
	i = param->player_y;
	if (param->split_map[i][j] == '1')
	{
		param->player_y++;
		return ;
	}
	if (check_c_e(param, i, j) == 1)
		return ;
}

void	move_down(t_param *param)
{
	int	i;
	int	j;

	param->player_y++;
	j = param->player_x;
	i = param->player_y;
	if (param->split_map[i][j] == '1')
	{
		param->player_y--;
		return ;
	}
	if (check_c_e(param, i, j) == 1)
		return ;
}

void	move_left(t_param *param)
{
	int	i;
	int	j;

	param->player_x--;
	j = param->player_x;
	i = param->player_y;
	if (param->split_map[i][j] == '1')
	{
		param->player_x++;
		return ;
	}
	if (check_c_e(param, i, j) == 1)
		return ;
}

void	move_right(t_param *param)
{
	int	i;
	int	j;

	param->player_x++;
	j = param->player_x;
	i = param->player_y;
	if (param->split_map[i][j] == '1')
	{
		param->player_x--;
		return ;
	}
	if (check_c_e(param, i, j) == 1)
		return ;
}
