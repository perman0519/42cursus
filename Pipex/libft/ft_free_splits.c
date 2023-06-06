/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:47:31 by junssong          #+#    #+#             */
/*   Updated: 2023/05/26 12:48:41 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
