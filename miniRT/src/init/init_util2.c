/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:11:06 by junssong          #+#    #+#             */
/*   Updated: 2024/03/24 13:27:03 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_filename(char *str)
{
	size_t	str_len;
	char	*extension;

	if (str == NULL)
		return (FALSE);
	str_len = ft_strlen(str);
	if (str == NULL || str_len <= 3)
		return (FALSE);
	extension = ft_substr(str, str_len - 3, str_len);
	if (extension == NULL)
		return (FALSE);
	if (ft_strncmp(".rt", extension, 3))
	{
		free(extension);
		return (FALSE);
	}
	free(extension);
	return (TRUE);
}

static int	parse_split_line(char **split, t_info *info)
{
	if (ft_strlen(split[0]) == 1 && !ft_strncmp(split[0], "A", 1))
		return (ambient_init(split, info));
	else if (ft_strlen(split[0]) == 1 && !ft_strncmp(split[0], "C", 1))
		return (camera_init(split, info));
	else if (ft_strlen(split[0]) == 1 && !ft_strncmp(split[0], "L", 1))
		return (light_init(split, info));
	else if (ft_strlen(split[0]) == 2 && !ft_strncmp(split[0], "pl", 1))
		return (pl_init(split, info));
	else if (ft_strlen(split[0]) == 2 && !ft_strncmp(split[0], "sp", 1))
		return (sp_init(split, info));
	else if (ft_strlen(split[0]) == 2 && !ft_strncmp(split[0], "cy", 1))
		return (cy_init(split, info));
	else if (ft_strlen(split[0]) == 1 && !ft_strncmp(split[0], "\n", 1))
		;
	else if (ft_strlen(split[0]) == 1 && !ft_strncmp(split[0], "#", 1))
		;
	else
		return (FALSE);
	return (TRUE);
}

static char	*get_del_newline(char *line)
{
	char	*del_newline;

	if (!ft_strncmp(line, "\n", 1))
	{
		del_newline = malloc(sizeof(char) * 2);
		if (del_newline == NULL)
			return (NULL);
		ft_strlcpy(del_newline, line, 2);
	}
	else
		del_newline = ft_strtrim(line, "\n");
	return (del_newline);
}

int	help_parse_rtfile(t_info *info, int fd, char *line, char *del_newline)
{
	char	**split_line;
	int		bool_parse;

	while (line != NULL)
	{
		free(line);
		split_line = ft_split(del_newline, ' ');
		bool_parse = parse_split_line(split_line, info);
		free(del_newline);
		ft_free_split(split_line);
		if (bool_parse == FALSE)
		{
			ft_lstclear(&(info->object), free);
			return (FALSE);
		}
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		del_newline = get_del_newline(line);
	}
	return (TRUE);
}

int	parse_rtfile(t_info *info, char *str)
{
	int		fd;
	char	*line;
	char	*del_newline;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		return (FALSE);
	}
	line = get_next_line(fd);
	if (line == NULL)
		return (FALSE);
	del_newline = get_del_newline(line);
	if (help_parse_rtfile(info, fd, line, del_newline))
		return (TRUE);
	else
		return (FALSE);
}
