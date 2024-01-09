/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:42:02 by junssong          #+#    #+#             */
/*   Updated: 2023/05/17 16:19:14 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

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
		return (1);
	if (is_sorted(&list_a))
	{
		free_list(&list_a, size_a);
		return (0);
	}
	sort(&list_a, &list_b, size_a);
	free_list(&list_a, size_a);
	return (0);
}
