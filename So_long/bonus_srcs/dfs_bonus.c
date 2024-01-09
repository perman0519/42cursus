/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:27:27 by junssong          #+#    #+#             */
/*   Updated: 2023/05/30 12:49:48 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	recur_dfs(t_param *param, t_find_ce *find_ce, int x, int y);

void	map_dfs(t_param *param)
{
	t_find_ce	find_ce;
	int			x;
	int			y;

	find_ce.find_c = 0;
	find_ce.find_e = 0;
	x = param ->player_x;
	y = param ->player_y;
	recur_dfs(param, &find_ce, x, y);
	if (param ->count_c != find_ce.find_c || param ->count_e != find_ce.find_e)
	{
		err_map(param, "Don't go C or E");
	}
}

void	recur_dfs(t_param *param, t_find_ce *find_ce, int x, int y)
{
	if (param ->split_map[y][x] == 'K')
		return ;
	else if (param ->split_map[y][x] == '1')
		return ;
	else if (param ->split_map[y][x] == 'C' \
	|| param ->split_map[y][x] == 'P' \
	|| param ->split_map[y][x] == 'E' \
	|| param ->split_map[y][x] == '0')
	{
		if (param ->split_map[y][x] == 'E')
				find_ce->find_e++;
		if (param ->split_map[y][x] == 'C')
				find_ce->find_c++;
		param ->split_map[y][x] = 'K';
		recur_dfs(param, find_ce, x + 1, y);
		recur_dfs(param, find_ce, x - 1, y);
		recur_dfs(param, find_ce, x, y + 1);
		recur_dfs(param, find_ce, x, y - 1);
		return ;
	}
}
