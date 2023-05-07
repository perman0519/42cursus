/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:46:14 by junssong          #+#    #+#             */
/*   Updated: 2023/05/04 17:08:38 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

int	parse_argv(int argc, t_list **list_a, char **argv)
{
	int	argv_num;
	int	*int_list;

	int_list = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv_num = is_one_argv(list_a, argv, &int_list);
	else
		argv_num = is_more_argv(list_a, argv, &int_list);
	if (!argv_num)
	{
		ft_printf("Error\n");
		return (0);
	}
	sorted_data_list(int_list, argv_num);
	change_data_to_index(list_a, int_list);
	return (argv_num);
}

int	is_one_argv(t_list **list, char **argv, int **int_list)
{
	char		**split_string;
	int			argv_num;
	long long	doub;

	argv_num = 0;
	doub = 0;
	split_string = ft_split(argv[1], ' ');
	if (is_not_number(split_string))
		return (0);
	while (split_string[argv_num] != 0)
		argv_num++;
	*int_list = (int *)malloc(sizeof(int) * argv_num);
	if (!*int_list)
		return (0);
	if (parse_split_string(split_string, doub, list, *int_list) == 0)
		return (0);
	free_split(split_string);
	return (argv_num);
}

int	parse_split_string(char **split_string, long long doub,
				t_list **list, int *int_list)
{
	t_list	*tmp_list;
	t_list	*index_list;
	int		i;

	i = 0;
	while (*split_string)
	{
		doub = ft_atoi(*split_string);
		if (doub > 2147483647 || doub < -2147483648)
			return (0);
		tmp_list = ft_lstnew((int)doub);
		int_list[i++] = doub;
		ft_lstadd_back(list, tmp_list);
		index_list = *list;
		while (index_list ->next != *list)
		{
			if (tmp_list ->data == index_list ->data)
				return (0);
			index_list = index_list ->next;
		}
		split_string++;
	}
	return (1);
}

int	is_not_number(char **split_string)
{
	int	i;
	int	j;

	i = 0;
	if (*split_string == NULL)
		return (1);
	while (split_string[i])
	{
		j = 0;
		if (((!ft_strncmp(split_string[i], "+", 1)
					|| !ft_strncmp(split_string[i], "-", 1)) && split_string[i][1] == '\0')
		|| split_string[i][j] == '\0')
			return (1);
		while (split_string[i][j])
		{
			if (!ft_isdigit(split_string[i][j]) && j == 0)
				if (split_string[i][j] != '+' && split_string[i][j] != '-')
					return (1);
			if (!ft_isdigit(split_string[i][j]) && j != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_more_argv(t_list **list, char **argv, int **int_list)
{
	long long	doub;
	int			argv_num;

	doub = 0;
	if (is_not_number(argv + 1))
		return (0);
	argv_num = 0;
	while (argv[argv_num] != 0)
		argv_num++;
	*int_list = (int *)malloc(sizeof(int) * (argv_num - 1));
	if (!*int_list)
		return (0);
	*list = NULL;
	++argv;
	if (parse_split_string(argv, doub, list, *int_list) == 0)
		return (0);
	return (argv_num - 1);
}
