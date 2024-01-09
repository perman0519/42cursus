/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:47 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/09 20:49:47 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_delim_in_dquote(char c)
{
	return (c == '<' || c == '>' || c == '\'' \
		|| c == '|' || c == '$' || c == ' ');
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] || us2[i])
	{
		if (us1[i] - us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}

t_token	*ft_token_new(int type, void *content)
{
	t_token	*tmp;

	tmp = (t_token *)malloc(sizeof(t_token));
	if (!tmp)
		exit(1);
	tmp->type = type;
	tmp->content = content;
	tmp->temp = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("0123456789", str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atouc(char *str, unsigned char *num)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (check_num(str) == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*(str++) - '0');
		if (check_over_max(sign, result, str))
			return (0);
		if (check_under_min(sign, result, str))
			return (0);
	}
	*num = (unsigned char)(result * sign);
	return (1);
}
