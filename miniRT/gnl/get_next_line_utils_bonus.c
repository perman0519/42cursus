/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:56:14 by junhapar          #+#    #+#             */
/*   Updated: 2023/05/18 15:18:46 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

long long	ft_check(char *s, int flag)
{
	unsigned long long	index;

	index = 0;
	if (flag == 0)
	{
		if (s == 0)
			return (-1);
		while (s[index])
		{
			if (s[index] == '\n')
				return ((long long)index);
			index++;
		}
		return (NOT_EXIST_INT);
	}
	else if (flag == 1)
	{
		if (s == 0)
			return (0);
		while (s[index])
			index++;
		return (index);
	}
	return (NOT_EXIST_INT);
}

char	*ft_saved_and_return(t_link **current, t_link **head, char **buf)
{
	char		*temp;
	long long	i_n;
	long long	l_saved;

	i_n = ft_check((*current)->saved, 0);
	if (!(ft_memsetup(buf, (*current)->saved, i_n + 1)))
		return (ft_free_all(head, buf));
	l_saved = ft_check((*current)->saved, 1);
	temp = 0;
	if (!(ft_memsetup(&temp, (*current)->saved + i_n + 1, l_saved - (i_n + 1))))
		return (ft_free_all(head, buf));
	free((*current)->saved);
	if (l_saved - (i_n + 1) == 0)
	{
		free(temp);
		temp = 0;
	}
	(*current)->saved = temp;
	return (*buf);
}

int	ft_memsetup(char **dst, char *src, long long size)
{
	char		*result;
	long long	i;

	result = malloc(size + 1);
	if (!(result))
		return (ERROR);
	i = 0;
	while (i < size)
	{
		result[i] = src[i];
		i++;
	}
	result[size] = '\0';
	free(*dst);
	*dst = 0;
	*dst = result;
	return (SUCCESS);
}

int	ft_strcat(char **dst, char *src)
{
	char		*result;
	long long	len_dst;
	long long	len_src;
	long long	i;

	len_dst = ft_check(*dst, 1);
	len_src = ft_check(src, 1);
	result = malloc(len_dst + len_src + 1);
	if (!(result))
		return (ERROR);
	i = -1;
	while (++i < len_dst)
		result[i] = (*dst)[i];
	i--;
	while (++i <= len_dst + len_src)
		result[i] = src[i - len_dst];
	if (*dst != 0)
		free(*dst);
	(*dst) = result;
	return (SUCCESS);
}

char	*ft_free_all(t_link **head, char **buf)
{
	t_link	*current_link;
	t_link	*temp;

	if (*head != 0)
	{
		current_link = *head;
		while (current_link)
		{
			temp = current_link;
			current_link = current_link->next_link;
			temp->next_link = 0;
			free(temp->saved);
			temp->saved = 0;
			free(temp);
			temp = 0;
		}
		*head = 0;
	}
	if (*buf != 0)
	{
		free(*buf);
		*buf = 0;
	}
	return (ERROR);
}
