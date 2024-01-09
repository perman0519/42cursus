/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:21 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/14 20:25:34 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_minishell(void)
{
	printf("              %s_%s %s        _%s  %s     %s%s  __ \
	     %s%s %s%s__%s%s    __ %s\n", RED, RES, ORG, RES, \
	YEL, RES, GRE, RES, BLU, RES, NAV, RES, PUR, RES);
	printf("   %s____ ___  (_)%s %s____  (_)%s %s_____%s%s / /_  %s %s___\
	\b\b\b\b\b  %s%s/ /%s   %s/ /%s\n", RED, RES, ORG, RES, \
	YEL, RES, GRE, RES, BLU, RES, NAV, RES, PUR, RES);
	printf("  %s/ __ `__ \\/ /%s %s/ __ \\/ /%s %s/ ___/%s%s/ __ \\%s %s/ _ \
	\b\b\b\b\b\\%s%s/ /%s   %s/ /%s\n", RED, RES, ORG, RES, \
	YEL, RES, GRE, RES, BLU, RES, NAV, RES, PUR, RES);
	printf(" %s/ / / / / / /%s %s/ / / / /%s %s(__  )%s%s/ / / /%s%s( ___/\
	\b\b\b\b%s %s/___%s%s/ /___%s\n", RED, RES, ORG, RES, \
	YEL, RES, GRE, RES, BLU, RES, NAV, RES, PUR, RES);
	printf("%s/_/ /_/ /_/_/%s %s/_/ /_/_/%s %s/____/%s%s/_/ /_/%s %s\\___/\
	\b\b\b\b\b%s%s_____/%s%s_____/%s\n", RED, RES, ORG, RES, \
	YEL, RES, GRE, RES, BLU, RES, NAV, RES, PUR, RES);
	printf("				%sver.1%s %s@hcho2%s %s@junsssong%s\n", \
	GRE, RES, BLU, RES, PUR, RES);
}

t_list	*dup_envp(char **envp)
{
	t_list	*environ;
	int		i;

	environ = NULL;
	i = -1;
	while (envp[++i])
		ft_lstadd_back(&environ, ft_lstnew(ft_strdup(envp[i])));
	return (environ);
}

void	init_main(t_list **environ, t_list **token_list, \
					t_token **type_list, char **envp)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	*token_list = NULL;
	*type_list = NULL;
	*environ = dup_envp(envp);
	print_minishell();
}
