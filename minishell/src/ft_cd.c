/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:55 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/14 16:44:21 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path(char *word, t_list **environ)
{
	char	*pathname;

	if (word)
		pathname = ft_strdup(word);
	else
	{
		pathname = ft_getenv(environ, "HOME");
		if (!pathname)
		{
			print_cd_err("HOME", "not set");
			return (NULL);
		}
	}
	return (pathname);
}

int	renew_pwd(t_list **environ)
{
	char	*cwd;
	t_list	*tmp;

	cwd = check_cwd();
	if (!cwd)
		return (1);
	tmp = ft_getenvnode(environ, "PWD");
	if (tmp == NULL)
		return (1);
	free(tmp->content);
	tmp->content = ft_strjoin("PWD=", cwd);
	free(cwd);
	return (0);
}

char	*find_oldpwd(t_list **environ)
{
	char	*oldpwd;

	oldpwd = ft_getenv(environ, "PWD");
	if (oldpwd == NULL)
		return (NULL);
	return (oldpwd);
}

int	renew_oldpwd(char *oldpwd_str, t_list **environ)
{
	t_list	*oldpwd;
	char	*str;

	oldpwd = ft_getenvnode(environ, "OLDPWD");
	if (oldpwd_str == NULL || oldpwd == NULL)
		return (1);
	str = ft_substr(oldpwd_str, \
						ft_indexof(oldpwd_str, '=') + 1, ft_strlen(oldpwd_str));
	if (oldpwd == NULL)
		ft_lstadd_back(environ, ft_lstnew((void *)ft_strjoin("OLDPWD=", str)));
	else
	{
		free(oldpwd->content);
		oldpwd->content = ft_strjoin("OLDPWD=", str);
	}
	free(str);
	free(oldpwd_str);
	return (0);
}

void	ft_cd(char **simple_cmd, t_list **environ, int fd)
{
	char	*pathname;
	char	*oldpwd;
	int		ch;

	(void)fd;
	g_exit_code = 0;
	pathname = check_path(simple_cmd[1], environ);
	if (!pathname)
		return ;
	oldpwd = find_oldpwd(environ);
	ch = chdir(pathname);
	if (ch < 0)
	{
		free(oldpwd);
		print_cd_err(pathname, "No such file or directory");
	}
	else
	{
		renew_pwd(environ);
		renew_oldpwd(oldpwd, environ);
	}
	free(pathname);
}
