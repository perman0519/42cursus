/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:53:34 by junssong          #+#    #+#             */
/*   Updated: 2023/03/23 12:53:34 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_check(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	return_word(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && is_check(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] != '\0' && !is_check(s[i], c))
			i++;
	}
	return (count);
}

static int	ft_put_point(char **arr, char const *s, char c, int word_count)
{
	int	j;
	int	k;

	k = 0;
	while (*s && k < word_count)
	{
		j = 0;
		while (*s && is_check(*s, c))
			s++;
		while (*(s + j) && !is_check(*(s + j), c))
			j++;
		arr[k] = (char *)malloc(sizeof(char) * (j + 1));
		if (!arr[k])
		{
			while (k-- > 0)
				free(arr[k]);
			free(arr);
			return (-1);
		}
		ft_strlcpy(arr[k], s, j + 1);
		k++;
		s += j;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = return_word(s, c);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (NULL);
	arr[word_count] = 0;
	if (word_count != 0)
		if (ft_put_point(arr, s, c, word_count) == -1)
			return (NULL);
	return (arr);
}
