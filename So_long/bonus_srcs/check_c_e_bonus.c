/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c_e_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:45:59 by junssong          #+#    #+#             */
/*   Updated: 2023/05/30 12:49:43 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	check_c_e(t_param *param, int i, int j)
{
	if (param->split_map[i][j] == 'C')
	{
		param->split_map[i][j] = '0';
		param->count_c--;
		param->move_count++;
		ft_printf("moveCount : %d\n", param->move_count);
		return (1);
	}
	else if (param->split_map[i][j] == 'E' && param->count_c == 0)
	{
		ft_printf("moveCount : %d\n", param->move_count);
		ft_free_split(param->split_map);
		exit(1);
		return (0);
	}
	param->move_count++;
	ft_printf("moveCount : %d\n", param->move_count);
	return (0);
}
