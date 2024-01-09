/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:58:13 by junssong          #+#    #+#             */
/*   Updated: 2023/05/30 12:50:01 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	is_correct_mapfile(char *map);
static void	join_new_line(t_param *param, char *new_line);
static void	check_wrong_map(t_param *param);
static void	gnl_map(t_param *param);

void	read_map(char *map, t_param *param)
{
	if (is_correct_mapfile(map) == 0 || param ->fd < 0)
	{
		ft_printf("Error\nWrong File");
		exit(1);
	}
	gnl_map(param);
	close(param ->fd);
	check_wrong_map(param);
	check_map_err(param);
}

static void	gnl_map(t_param *param)
{
	char	*new_line;

	new_line = get_next_line(param ->fd);
	if (new_line == NULL)
		exit(1);
	param ->map = new_line;
	param ->x_size = ft_strlen(new_line) - 1;
	param ->y_size++;
	while (new_line != NULL)
	{
		param ->y_size++;
		new_line = get_next_line(param ->fd);
		if (new_line != NULL)
		{
			join_new_line(param, new_line);
			free(new_line);
		}
	}
	param ->y_size--;
}

static int	is_correct_mapfile(char *map)
{
	char	*str;

	str = ft_substr(map, ft_strlen(map) - 4, 4);
	if (str == NULL)
		return (0);
	if (ft_strncmp(str, ".ber", 4) != 0)
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

static void	join_new_line(t_param *param, char *new_line)
{
	char	*str;

	str = ft_strjoin(param ->map, new_line);
	free(param ->map);
	if (str == NULL)
		exit(1);
	param ->map = str;
}

static void	check_wrong_map(t_param *param)
{
	size_t	i;
	char	*map;

	map = param ->map;
	i = 0;
	while (i < ft_strlen(map))
	{
		if (map[i] != '0' && map[i] != 'P' && map[i] != 'E' \
		&& map[i] != 'C' && map[i] != '1' && map[i] != '\n')
		{
			ft_printf("Error\nWrong map");
			free(param ->map);
			exit(1);
		}
		else if (map[i] == 'C')
			param ->count_c++;
		else if (map[i] == 'P')
			param ->count_p++;
		else if (map[i] == 'E')
			param ->count_e++;
		i++;
	}
}
