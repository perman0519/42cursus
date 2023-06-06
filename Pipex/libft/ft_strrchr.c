/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:22:25 by junssong          #+#    #+#             */
/*   Updated: 2023/03/16 14:22:28 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	char	*a_ptr;

	a = (char)c;
	a_ptr = NULL;
	while (*s != '\0')
	{
		if (*s == a)
			a_ptr = (char *)s;
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	if (a_ptr == NULL)
		return (NULL);
	else
		return (a_ptr);
}
