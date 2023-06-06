/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:04:22 by junssong          #+#    #+#             */
/*   Updated: 2023/05/22 16:36:13 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_fd_list
{
	ssize_t	read_size;
	int		fd;
	char	*buf;
	int		index;
	int		fd_over;
	int		return_zero;
	int		f_b;
}				t_fd_list;

char	*get_next_line(int fd);
int		reset_fd_list(t_fd_list *fd_list, int fd);
void	*ft_memset_gnl(void *b, int c, size_t len);
size_t	ft_strlen_gnl(const char *s);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
