/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:49:59 by junssong          #+#    #+#             */
/*   Updated: 2023/05/17 17:37:06 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

int	check_dup(t_list **list, t_list *tmp_list)
{
	t_list	*index_list;

	index_list = *list;
	while (index_list ->next != *list)
	{
		if (tmp_list ->data == index_list ->data)
			return (0);
		index_list = index_list ->next;
	}
	return (1);
}

void	free_list(t_list **list_a, int size_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < size_a)
	{
		tmp = *list_a;
		*list_a = (*list_a)->next;
		free(tmp);
		i++;
	}
}

int	check_sign(char **split_string, int i, int j)
{
	if (((!ft_strncmp(split_string[i], "+", 1)
				|| !ft_strncmp(split_string[i], "-", 1))
			&& ((split_string[i][1] == '\0') || (split_string[i][1] == '0')))
			|| split_string[i][j] == '\0')
		return (1);
	return (0);
}
