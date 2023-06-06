/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:45:39 by junssong          #+#    #+#             */
/*   Updated: 2023/05/22 16:37:30 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset_gnl(void *b, int c, size_t len)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_legth;

	i = 0;
	src_legth = ft_strlen_gnl(src);
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

size_t	ft_strlen_gnl(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
	{
		++count;
	}
	return (count);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*return_arr;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	return_arr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!return_arr)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ft_strlcpy_gnl(return_arr, s1, s1_len + 1);
	ft_strlcpy_gnl(return_arr + s1_len, s2, s2_len + 1);
	free(s1);
	return (return_arr);
}

int	reset_fd_list(t_fd_list *fd_list, int fd)
{
	fd_list->fd = fd;
	fd_list->index = 0;
	fd_list->buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (fd_list->buf == 0)
		return (0);
	ft_memset_gnl(fd_list->buf, 0, BUFFER_SIZE);
	fd_list->read_size = read(fd, fd_list->buf, BUFFER_SIZE);
	if (fd_list->read_size < 0)
	{
		free(fd_list->buf);
		return (0);
	}
	else if (fd_list ->read_size == 0)
	{
		free(fd_list->buf);
		return (-1);
	}
	return (1);
}
