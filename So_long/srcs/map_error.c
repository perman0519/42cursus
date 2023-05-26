/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:09:48 by junssong          #+#    #+#             */
/*   Updated: 2023/05/26 19:34:10 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

static void	check_map_square(t_param *param, size_t width);
static void	check_map_wall(t_param *param, size_t width);
static void	find_p(t_param *param);
void		err_map(t_param *param, char *err_msg);

void	check_map_err(t_param *param)
{
	size_t	width;

	param ->split_map = ft_split(param ->map, '\n');
	width = ft_strlen(param->split_map[0]);
	if (param ->count_e != 1 || param ->count_p != 1 || param ->count_c < 1)
	{
		free(param ->map);
		err_map(param, "Wrong C or E in MapFile\n");
	}
	check_map_square(param, width);
	check_map_wall(param, width);
	find_p(param);
	map_dfs(param);
	ft_free_split(param ->split_map);
	param ->split_map = ft_split(param ->map, '\n');
	free(param ->map);
}

static void	check_map_square(t_param *param, size_t width)
{
	int		i;

	i = 0;
	while (param ->split_map[i] != NULL)
	{
		if (width != ft_strlen(param->split_map[i]))
			err_map(param, "Not Square");
		i++;
	}
}

static void	check_map_wall(t_param *param, size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (param ->split_map[i] != NULL)
	{
		if (i == 0 || i == (size_t)param->y_size - 1)
		{
			j = 0;
			while (j < width)
			{
				if (param ->split_map[i][j] != '1')
					err_map(param, "Square is not Wall.");
				j++;
			}
		}
		else
		{
			if (param ->split_map[i][0] != '1' \
			|| param ->split_map[i][width - 1] != '1')
				err_map(param, "Square is not Wall.");
		}
		i++;
	}
}

void	err_map(t_param *param, char *err_msg)
{
	ft_printf("Error\n%s\n", err_msg);
	ft_free_split(param ->split_map);
	exit(1);
}

static void	find_p(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (param ->split_map[i])
	{
		j = 0;
		while (param ->split_map[i][j])
		{
			if (param ->split_map[i][j] == 'P')
				param ->player_x = j;
			j++;
		}
		if (param ->player_x != 0)
			break ;
		param ->player_y++;
		i++;
	}
}
