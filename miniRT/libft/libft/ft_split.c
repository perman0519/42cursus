/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:38:01 by junhapar          #+#    #+#             */
/*   Updated: 2024/03/22 19:55:03 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_sentence(char *s, char c);
static size_t	ft_len_sentence(char *s, char c);
static void		ft_free_malloc(char	**result, int max_num_sentence);
static int		ft_m_result(char **result, char const *s, char c, size_t num_s);

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	num_sentence;
	int		is_possible;

	if (s == 0)
		return (0);
	num_sentence = ft_num_sentence((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (num_sentence + 1));
	if (!(result))
		return (0);
	is_possible = ft_m_result(result, s, c, num_sentence);
	if (is_possible == 0)
		return (0);
	else
		return (result);
}

static size_t	ft_num_sentence(char *s, char c)
{
	size_t	num_sentence;
	char	*word_sentence_first;

	num_sentence = 0;
	word_sentence_first = s;
	while (1)
	{
		if (*s == '\0' && s != word_sentence_first)
		{
			num_sentence++;
			break ;
		}
		else if (*s == '\0' && s == word_sentence_first)
			break ;
		else if (*s == c && s != word_sentence_first)
		{
			num_sentence++;
			word_sentence_first = s + 1;
		}
		else if (*s == c && s == word_sentence_first)
			word_sentence_first = s + 1;
		s++;
	}
	return (num_sentence);
}

static size_t	ft_len_sentence(char *s, char c)
{
	size_t	len;

	len = 0;
	while (1)
	{
		if (*s == '\0' || *s == c)
			return (len);
		s++;
		len++;
	}
	return (len);
}

static void	ft_free_malloc(char	**result, int max_num_sentence)
{
	int	current_sentence;

	current_sentence = 0;
	while (current_sentence < max_num_sentence)
	{
		free(result[current_sentence]);
		current_sentence++;
	}
	free(result);
}

static int	ft_m_result(char **result, char const *s, char c, size_t num_s)
{
	size_t	current_sentence;
	size_t	sentence_len;

	current_sentence = 0;
	while (current_sentence < num_s)
	{
		sentence_len = ft_len_sentence((char *)s, c);
		if (sentence_len != 0)
		{
			result[current_sentence] = malloc(sentence_len + 1);
			if (!(result[current_sentence]))
			{
				ft_free_malloc(result, current_sentence);
				return (0);
			}
			ft_strlcpy(result[current_sentence], s, sentence_len + 1);
			current_sentence++;
		}
		s = s + sentence_len + 1;
	}
	result[current_sentence] = 0;
	return (1);
}
