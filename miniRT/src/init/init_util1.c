/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:10:02 by junssong          #+#    #+#             */
/*   Updated: 2024/03/04 13:04:43 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_split_size(char **split, int split_size)
{
	int	i;

	i = 0;
	while (split[i++])
		;
	if (i - 1 != split_size)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_free_split(char **split_string)
{
	int	i;

	i = 0;
	while (split_string[i])
	{
		free(split_string[i]);
		i++;
	}
	free(split_string[i]);
	free(split_string);
}

int	is_strv3(char *str)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] == ',')
			t++;
		i++;
	}
	if (t != 2)
		return (FALSE);
	else
		return (TRUE);
}

int	is_strnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_color	parse_color(char **rgb_str)
{
	int		i;
	t_color	ret;
	int		value[3];

	ret.x = -1;
	if (check_split_size(rgb_str, 3))
		return (ret);
	i = 0;
	while (rgb_str[i])
	{
		value[i] = ft_atoi(rgb_str[i]);
		if (is_strnum(rgb_str[i]) == FALSE || value[i] < 0 || value[i] > 255)
			return (ret);
		i++;
	}
	ret.x = (double)value[0] / 255.0;
	ret.y = (double)value[1] / 255.0;
	ret.z = (double)value[2] / 255.0;
	return (ret);
}
