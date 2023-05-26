/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:04:32 by junssong          #+#    #+#             */
/*   Updated: 2023/05/22 16:38:49 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*help_gnl(t_fd_list *fd_list, char *new_str,
			char *return_str, ssize_t i);
int		is_nextline(t_fd_list *fd_list, char *new_str,
			char **return_str, ssize_t *i);
int		is_readsize_over(t_fd_list *fd_list, char *new_str,
			char **return_str, ssize_t *i);
int		is_same_readsize(t_fd_list *fd_list, char *new_str,
			char **return_str, ssize_t *i);

char	*get_next_line(int fd)
{
	static t_fd_list	fd_list;
	char				*return_str;
	char				*new_str;
	ssize_t				i;

	i = 0;
	return_str = NULL;
	if (fd < 0)
		return (NULL);
	if (fd_list.index == 0)
		if (reset_fd_list(&fd_list, fd) == 0 || fd_list.read_size == 0)
			return (NULL);
	new_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_str)
	{
		fd_list.index = 0;
		free(fd_list.buf);
		return (NULL);
	}
	ft_memset_gnl(new_str, 0, BUFFER_SIZE + 1);
	return_str = help_gnl(&fd_list, new_str, return_str, i);
	return (return_str);
}

char	*help_gnl(t_fd_list *fd_list, char *new_str,
			char *return_str, ssize_t i)
{
	while (1)
	{
		new_str[i++] = fd_list->buf[fd_list->index++];
		if ((fd_list->index) == fd_list->read_size)
		{
			fd_list->f_b = is_same_readsize(fd_list, new_str, &return_str, &i);
			if (fd_list->f_b == 0)
				return (NULL);
			else if (fd_list->f_b == 1)
				return (return_str);
			i = 0;
			ft_memset_gnl(new_str, 0, BUFFER_SIZE + 1);
			fd_list->f_b = is_readsize_over(fd_list, new_str, &return_str, &i);
			if (fd_list->f_b == 0)
				return (NULL);
			else if (fd_list->f_b == 1)
				return (return_str);
		}
		else
			fd_list->f_b = is_nextline(fd_list, new_str, &return_str, &i);
		if (fd_list->f_b == 0)
			return (NULL);
		else if (fd_list->f_b == 1)
			return (return_str);
	}
}

int	is_same_readsize(t_fd_list *fd_list, char *new_str,
		char **return_str, ssize_t *i)
{
	*return_str = ft_strjoin_gnl(*return_str, new_str);
	fd_list->index = 0;
	free(fd_list->buf);
	if (!(*return_str))
		return (0);
	if (new_str[*i - 1] == '\n')
	{
		free(new_str);
		return (1);
	}
	if (reset_fd_list(fd_list, fd_list->fd) == 0)
	{
		free(new_str);
		free(*return_str);
		return (0);
	}
	else if (fd_list->read_size == 0)
	{
		free(new_str);
		return (1);
	}
	return (-1);
}

int	is_readsize_over(t_fd_list *fd_list, char *new_str,
	char **return_str, ssize_t *i)
{
	if (fd_list->read_size < BUFFER_SIZE)
	{
		while (*(i) < fd_list->read_size)
		{
			new_str[(*i)++] = fd_list->buf[fd_list->index++];
			if (fd_list->buf[fd_list->index - 1] == '\n'
				|| fd_list->buf[fd_list->index] == 0)
				break ;
		}
		*return_str = ft_strjoin_gnl(*return_str, new_str);
		if (!*return_str)
		{
			fd_list->index = 0;
			free(fd_list->buf);
			return (0);
		}
		if (*i == fd_list->read_size)
		{
			fd_list->index = 0;
			free(fd_list->buf);
		}
		free(new_str);
		return (1);
	}
	return (-1);
}

int	is_nextline(t_fd_list *fd_list, char *new_str,
			char **return_str, ssize_t *i)
{
	if (new_str[*i - 1] != '\n' && fd_list->buf[fd_list->index] == '\n')
		new_str[*i] = '\n';
	if (new_str[*i - 1] == '\n' || fd_list->buf[fd_list->index] == '\n')
	{
		*return_str = ft_strjoin_gnl(*return_str, new_str);
		if (!(*return_str))
		{
			fd_list->index = 0;
			free(fd_list->buf);
			return (0);
		}
		if (new_str[*i - 1] != '\n' && fd_list->buf[fd_list->index] == '\n')
		{
			if (++(fd_list->index) == fd_list->read_size)
			{
				fd_list->index = 0;
				free(fd_list->buf);
			}
		}
		free (new_str);
		return (1);
	}
	return (-1);
}
