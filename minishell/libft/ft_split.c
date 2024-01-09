/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:54:02 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 13:14:24 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	wc;

	wc = 0;
	if (*s && *s != c)
		wc++;
	while (*s && *(s + 1))
	{
		if (c == *s && c != *(s + 1))
			wc++;
		s++;
	}
	return (wc);
}

static char	*make_str(char const *s, int w_len)
{
	char	*w;
	char	*new_w;

	w = (char *)malloc(sizeof(char) * (w_len + 1));
	if (!w)
		exit(1);
	ft_memmove(w, s, w_len);
	w[w_len] = '\0';
	new_w = ft_strdup(w);
	free(w);
	return (new_w);
}

static char	**free_all(char **w_list, int w_idx)
{
	int	i;

	i = 0;
	while (i <= w_idx)
		free(w_list[i++]);
	free(w_list);
	return (0);
}

static char	**insert_word_to_list(char **w_list, char const *s, \
		char c, int w_list_len)
{
	int	idx;
	int	w_len;

	idx = 0;
	while (idx < w_list_len)
	{
		while (*s && *s == c)
			s++;
		w_len = 0;
		while (*(s + w_len) && *(s + w_len) != c)
			w_len++;
		if (w_len)
		{
			w_list[idx] = make_str(s, w_len);
			if (!w_list[idx])
			{
				free_all(w_list, idx);
				return (0);
			}
			s += w_len;
			idx++;
		}
	}
	w_list[w_list_len] = 0;
	return (w_list);
}

char	**ft_split(char const *s, char c)
{
	char	**w_list;
	int		w_list_len;

	if (!s)
		return (0);
	w_list_len = word_count(s, c);
	w_list = (char **)malloc(sizeof(char *) * (w_list_len + 1));
	if (!w_list)
		exit(1);
	w_list = insert_word_to_list(w_list, s, c, w_list_len);
	return (w_list);
}
