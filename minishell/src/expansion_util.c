/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:15 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 16:54:20 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_vars(t_vars *vars)
{
	vars->str = NULL;
	vars->size = 0;
	vars->q_flag = 0;
	vars->i = 0;
}

char	*expanded(char *str, t_list **environ, int size)
{
	char	*ret;
	char	*tmp;
	char	*error_status;

	error_status = ft_itoa(g_exit_code);
	tmp = ft_substr(str, 1, ft_strlen(str));
	ret = ft_getenv(environ, str);
	if (ret == NULL && !ft_strncmp(str, "?", 1))
		ret = ft_strjoin(error_status, tmp);
	else if (ret == NULL && size != 0)
		ret = ft_strdup("");
	else if (ret == NULL && size == 0)
		ret = ft_strdup("$");
	free(str);
	free(tmp);
	free(error_status);
	return (ret);
}

void	expand_key(char *content, t_vars *vars, t_list **environ)
{
	vars->i++;
	while (content[vars->i + vars->size]
		&& !is_delim(content[vars->i + vars->size]))
	{
		if (vars->q_flag == '\"' && (ft_is_blank(content[vars->i + vars->size]) \
			|| content[vars->i + vars->size] == '$'))
			break ;
		vars->size++;
	}
	vars->str = ft_substr(content, vars->i, vars->size);
	vars->str = expanded(vars->str, environ, vars->size);
	vars->i += vars->size;
}

void	sub_key(char *content, t_vars *vars)
{
	while (content[vars->i + vars->size]
		&& !ft_strchr("\'\"", content[vars->i + vars->size]))
	{
		if (vars->q_flag != '\'' && content[vars->i + vars->size] == '$')
			break ;
		vars->size++;
	}
	vars->str = ft_substr(content, vars->i, vars->size);
	vars->i += vars->size;
}

void	check_quote(t_vars *vars, char q)
{
	if (vars->q_flag == 0)
		vars->q_flag = q;
	else if (vars->q_flag == q)
		vars->q_flag = 0;
	vars->str = malloc(2);
	if (vars->str == NULL)
		exit(1);
	vars->str[0] = q;
	vars->str[1] = '\0';
	vars->i += 1;
}
