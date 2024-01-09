/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequotenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:48:19 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/12 19:44:08 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*modify_word(char *word, char *wd_flag, int wd_len)
{
	char	*res;
	int		i;
	int		j;
	int		res_len;

	i = -1;
	res_len = 0;
	while (++i < wd_len)
	{
		if (wd_flag[i] != 1)
			res_len++;
	}
	res = (char *)malloc(res_len + 1);
	if (!res)
		exit(1);
	i = 0;
	j = 0;
	while (i < wd_len && j < res_len)
	{
		if (wd_flag[i] == 0)
			res[j++] = word[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	check_quote_2(char *word, int i, int *q_flag, char **wd_flag)
{
	if (word[i] && word[i] == '\"')
	{
		if (*q_flag != '\'')
			(*wd_flag)[i] = 1;
		if (*q_flag == 0)
			*q_flag = '\"';
		else if (*q_flag == '\"')
			*q_flag = 0;
	}
	else if (word[i] && word[i] == '\'')
	{
		if (*q_flag != '\"')
			(*wd_flag)[i] = 1;
		if (*q_flag == 0)
			*q_flag = '\'';
		else if (*q_flag == '\'')
			*q_flag = 0;
	}
}

void	dequotenize(t_token **type_list)
{
	t_token	*iter;
	char	*word;
	int		q_flag;
	char	*wd_flag;
	int		i;

	iter = *type_list;
	while (iter)
	{
		word = iter->content;
		q_flag = 0;
		wd_flag = (char *)ft_calloc(1, ft_strlen(word) + 1);
		i = 0;
		while (word[i])
		{
			check_quote_2(word, i, &q_flag, &wd_flag);
			i++;
		}
		iter->content = modify_word(word, wd_flag, ft_strlen(word));
		free(word);
		free(wd_flag);
		iter = iter->next;
	}
}
