/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhapar <junhapar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:12:54 by junssong          #+#    #+#             */
/*   Updated: 2024/03/22 17:08:58 by junhapar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	check_xpm_file(char *str)
{
	size_t	str_len;
	char	*extension;
	int		fd;

	if (str == NULL)
		return (FALSE);
	if (!strncmp(str, "NULL", 4))
		return (TRUE);
	str_len = ft_strlen(str);
	if (str_len <= 4)
		return (FALSE);
	extension = ft_substr(str, str_len - 4, str_len);
	if (extension == NULL)
		return (FALSE);
	if (ft_strncmp(".xpm", extension, 4))
	{
		free(extension);
		return (FALSE);
	}
	free(extension);
	fd = (size_t)open(str, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}
