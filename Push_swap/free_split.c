/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:11:28 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 16:51:46 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split_string)
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

void	sorted_data_list(int *int_list, int argv_num)
{
	int		a;
	int		i;
	int		j;

	i = 0;
	while (i < argv_num)
	{
		j = i + 1;
		while (j < argv_num)
		{
			if (int_list[i] > int_list[j])
			{
				a = int_list[i];
				int_list[i] = int_list[j];
				int_list[j] = a;
			}
			++j;
		}
		++i;
	}
}

void	change_data_to_index(t_list **list, int *int_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*list);
	while (tmp->next != *list)
	{
		i = 0;
		while (tmp->data != int_list[i])
			++i;
		tmp->data = i;
		tmp = tmp->next;
	}
	i = 0;
	while (tmp->data != int_list[i])
		++i;
	tmp->data = i;
}
