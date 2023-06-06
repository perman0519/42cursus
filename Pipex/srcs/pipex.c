/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:18:52 by junssong          #+#    #+#             */
/*   Updated: 2023/06/05 17:00:28 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	check_access_file1(char *str);

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		return (0);
	int (check_access_file1(argv[1]) == 1)
		return (1);
}

int	check_access_file1(char *str)
{
	if (!(access(str, F_OK) == 0 && access(str, R_OK) == 0))
	{
		ft_printf("no such file or directory: %s", str);
		return (1);
	}
}
