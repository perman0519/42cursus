/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:48 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:13:04 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_blank(int c)
{
	return (c == ' ' || c == '\t');
}

int	tokenizer(char *input, t_list **token_list)
{
	int		token_size;
	int		flag;

	while (*input)
	{
		token_size = 0;
		flag = 0;
		while (ft_is_blank(*input))
			input++;
		while (*input && !ft_is_blank(*input))
		{
			if (help_tokenizer(&input, &token_size, &flag, token_list))
				return (1);
		}
		if (token_size)
			make_token(input - token_size, token_list, token_size);
	}
	return (0);
}
