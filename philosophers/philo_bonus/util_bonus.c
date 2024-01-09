/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:39:20 by junssong          #+#    #+#             */
/*   Updated: 2023/12/22 09:22:18 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	value;
	long long	temp;

	sign = 1;
	i = 0;
	value = 0;
	temp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		value = 10 * temp + (str[i++] - '0');
		temp = value;
	}
	if ((str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9')))
		return (0);
	if (sign * value > 2147483647)
		return (0);
	return (sign * value);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*return_arr;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return_arr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!return_arr)
		return (NULL);
	ft_strlcpy(return_arr, s1, s1_len + 1);
	ft_strlcpy(return_arr + s1_len, s2, s2_len + 1);
	return (return_arr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_legth;

	i = 0;
	src_legth = ft_strlen(src);
	if (dstsize == 0)
		return (src_legth);
	while (i < dstsize - 1)
	{
		if (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		else
		{
			dst[i] = src[i];
			return (src_legth);
		}
	}
	dst[i] = '\0';
	return (src_legth);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++ != '\0')
	{
		++count;
	}
	return (count);
}
