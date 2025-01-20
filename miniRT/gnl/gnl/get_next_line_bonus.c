/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:56:05 by junhapar          #+#    #+#             */
/*   Updated: 2023/05/18 15:18:39 by junhapar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_link	*head;
	t_link			*current_link;
	char			*return_buf;

	current_link = ft_find_link(head, fd);
	return_buf = 0;
	if (!(current_link))
	{
		current_link = ft_add_new_link(&head, fd);
		if (!(current_link))
			return (ft_free_all(&head, &return_buf));
	}
	return_buf = ft_fd_gnl(&current_link, &head);
	return (return_buf);
}

t_link	*ft_find_link(t_link *current_link, int fd)
{
	while (current_link)
	{
		if (current_link->fd == fd)
			return (current_link);
		current_link = current_link->next_link;
	}
	return (NOT_EXIST_LINK);
}

t_link	*ft_add_new_link(t_link **head, int fd)
{
	t_link			*new_link;

	if (*head == 0)
	{
		new_link = (t_link *)malloc(sizeof(t_link));
		if (!(new_link))
			return (0);
		*head = new_link;
	}
	else
	{
		new_link = *head;
		while (new_link->next_link)
			new_link = new_link->next_link;
		new_link->next_link = (t_link *)malloc(sizeof(t_link));
		if (!(new_link->next_link))
			return (0);
		new_link = new_link->next_link;
	}
	new_link->fd = fd;
	new_link->saved = 0;
	new_link->next_link = 0;
	return (new_link);
}

char	*ft_fd_gnl(t_link **current, t_link **head)
{
	char			*buf;
	long long		return_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!(buf) || BUFFER_SIZE < 1)
		return (ft_free_all(head, &buf));
	if (ft_check((*current)->saved, 0) >= 0)
		return (ft_saved_and_return(current, head, &buf));
	return_read = read((*current)->fd, buf, BUFFER_SIZE);
	if ((return_read < 0) || (return_read == 0 && (*current)->saved == 0))
		return (ft_free_fd(current, head, &buf, 3));
	while (return_read > 0)
	{
		buf[return_read] = '\0';
		if (!(ft_strcat(&((*current)->saved), buf)))
			return (ft_free_all(head, &buf));
		if (ft_check(buf, 0) >= 0)
			return (ft_saved_and_return(current, head, &buf));
		return_read = read((*current)->fd, buf, BUFFER_SIZE);
	}
	if (!(ft_memsetup(&buf, (*current)->saved, ft_check((*current)->saved, 1))))
		return (ft_free_all(head, &buf));
	ft_free_fd(current, head, &buf, 2);
	return (buf);
}

char	*ft_free_fd(t_link **current, t_link **head, char **buf, int f)
{
	t_link	*temp;

	if (*head == *current)
	{
		*head = (*current)->next_link;
	}
	else
	{
		temp = *head;
		while (temp->next_link != *current)
			temp = temp->next_link;
		temp->next_link = (*current)->next_link;
	}
	(*current)->next_link = 0;
	free((*current)->saved);
	(*current)->saved = 0;
	free(*current);
	*current = 0;
	if (f >= 3 && *buf != 0)
	{
		free(*buf);
		*buf = 0;
	}
	return (ERROR);
}
