/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:42:02 by junssong          #+#    #+#             */
/*   Updated: 2023/05/09 14:01:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	free_list(t_list **list_a, int size_a);

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		size_a;
	int		i;

	i = 0;
	list_a = 0;
	list_b = 0;
	size_a = parse_argv(argc, &list_a, argv);
	if (!size_a)
		return (0);
	if (is_sorted(&list_a))
	{
		free_list(&list_a, size_a);
		return (1);
	}
	sort(&list_a, &list_b, size_a);
	free_list(&list_a, size_a);
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
