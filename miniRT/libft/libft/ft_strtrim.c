/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:26:18 by junhapar          #+#    #+#             */
/*   Updated: 2024/02/16 21:16:00 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_n_del_front(char const *s, size_t len, char const *set);
static size_t	ft_n_del_b(char const *s, size_t l, size_t i, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	num_front;
	size_t	num_back;
	char	*result;

	if (s1 == 0 || set == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	num_front = ft_n_del_front(s1, len_s1, set);
	num_back = ft_n_del_b(s1, len_s1, 1, set);
	if (len_s1 <= num_front + num_back)
	{
		result = ft_calloc(1, 1);
		return (result);
	}
	else
		result = malloc(len_s1 + 1 - num_front - num_back);
	if (!(result))
		return (0);
	ft_strlcpy(result, s1 + num_front, len_s1 + 1 - num_front - num_back);
	return (result);
}

static size_t	ft_n_del_front(char const *s, size_t len, char const *set)
{
	if (len == 0)
		return (0);
	else if (ft_strchr(set, *s))
		return (1 + ft_n_del_front(s + 1, len, set));
	else
		return (0);
}

static size_t	ft_n_del_b(char const *s, size_t l, size_t i, char const *set)
{
	if (l == 0)
		return (0);
	else if (l - i == 0)
	{
		if (ft_strchr(set, s[0]))
			return (1);
		else
			return (0);
	}
	else if (ft_strchr(set, s[l - i]))
		return (1 + ft_n_del_b(s, l, i + 1, set));
	else
		return (0);
}
