/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:31 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:13:01 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_token(char *input, t_list **token_list, int token_size)
{
	char	*token;
	t_list	*new_token;

	token = ft_substr(input, 0, token_size);
	new_token = ft_lstnew(token);
	if (new_token == NULL)
		exit(1);
	ft_lstadd_back(token_list, new_token);
}

void	check_pipe(int *token_size, char **input, t_list **token_list)
{
	if (*token_size)
	{
		make_token(*input - *token_size, token_list, *token_size);
		*token_size = 0;
	}
	make_token((*input)++, token_list, 1);
}

void	check_lsr_grt(int *token_size, char **input, t_list **token_list)
{
	if (*token_size)
	{
		make_token(*input - *token_size, token_list, *token_size);
		*token_size = 0;
	}
	if (*(*input + 1) == **input)
	{
		make_token(*input, token_list, 2);
		*input += 2;
	}
	else
		make_token((*input)++, token_list, 1);
}

int	check_quote_3(int *flag, int *token_size, char **input)
{
	*flag = **input;
	while (*flag && **input)
	{
		(*token_size)++;
		(*input)++;
		if (**input == *flag)
		{
			(*token_size)++;
			(*input)++;
			*flag = 0;
		}
	}
	if (*flag)
		return (1);
	return (0);
}

int	help_tokenizer(char **input, int *token_size, \
						int *flag, t_list **token_list)
{
	if (**input == '|')
		check_pipe(token_size, input, token_list);
	else if (**input == '<' || **input == '>')
		check_lsr_grt(token_size, input, token_list);
	else if (**input == '\"' || **input == '\'')
	{
		if (check_quote_3(flag, token_size, input))
			return (1);
	}
	else
	{
		(*token_size)++;
		(*input)++;
	}
	return (0);
}
