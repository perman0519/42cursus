/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:56:09 by junhapar          #+#    #+#             */
/*   Updated: 2023/09/12 16:11:49 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SUCCESS 1
# define ERROR 0
# define NOT_EXIST_INT -1
# define NOT_EXIST_LINK 0

# include <stdlib.h>
# include <unistd.h>

typedef struct s_link
{
	int				fd;
	char			*saved;
	struct s_link	*next_link;
}	t_link;

char		*get_next_line(int fd);
t_link		*ft_find_link(t_link *current_link, int fd);
t_link		*ft_add_new_link(t_link **head, int fd);
char		*ft_fd_gnl(t_link **current_link, t_link **head);
char		*ft_free_fd(t_link **current, t_link **head, char **buf, int f);

long long	ft_check(char *s, int flag);
char		*ft_saved_and_return(t_link **current, t_link **head, char **buf);
int			ft_memsetup(char **dst, char *src, long long size);
int			ft_strcat(char **dst, char *src);
char		*ft_free_all(t_link **head, char **buf);

#endif