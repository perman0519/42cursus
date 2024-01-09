/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:49:04 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/11 20:30:03 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(void)
{
	char	**spl;
	char	*tmp;
	char	*joined;
	int		size;

	tmp = getcwd(NULL, 0);
	if (tmp == NULL)
		return (ft_strdup(".-$ "));
	spl = ft_split(tmp, '/');
	free(tmp);
	if (spl && !*spl)
	{
		free_all(spl);
		return (ft_strdup("/-$ "));
	}
	size = 0;
	while (spl[size])
		size++;
	joined = ft_strjoin(spl[size - 1], "-$ ");
	if (spl)
		free_all(spl);
	return (joined);
}

void	do_execve(t_cmd *pipeline, t_list **environ)
{
	int	func_idx;

	if (!pipeline)
		return ;
	func_idx = is_built_in(pipeline->simple_cmd);
	if (count_pipe(&pipeline) == 1 && func_idx > -1)
	{
		if (init_redir(pipeline) == OPEN_ERROR)
		{
			unlink_temp_files(pipeline);
			exit(1);
		}
		if (func_idx == 0)
			ft_putendl_fd("exit", STDOUT_FILENO);
		run_cmd(pipeline, environ, func_idx, 1);
	}
	else
		pipexline(&pipeline, environ);
}

void	check_input(char *input)
{
	if (!input)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(0);
	}
}

int	do_parse(t_list	**environ, t_list **token_list, t_token **type_list)
{
	char	*input;
	char	*prompt;

	signal(SIGINT, p_handler);
	signal(SIGQUIT, SIG_IGN);
	prompt = get_pwd();
	input = readline(prompt);
	free(prompt);
	check_input(input);
	if (*input)
		add_history(input);
	if (!*input || tokenizer(input, token_list))
	{
		ft_lstclear(token_list, free);
		free(input);
		return (1);
	}
	expand_env(token_list, environ);
	identify_token_type(token_list, type_list);
	free(input);
	if (syntax_error(type_list) == SYNTAX_ERROR)
		return (1);
	dequotenize(type_list);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	struct termios	term;
	t_list			*environ;
	t_list			*token_list;
	t_token			*type_list;
	t_cmd			*pipeline;

	(void)ac;
	(void)av;
	tcgetattr(STDIN_FILENO, &term);
	init_main(&environ, &token_list, &type_list, envp);
	while (1)
	{
		if (do_parse(&environ, &token_list, &type_list))
			continue ;
		pipeline = struct_cmd(&type_list);
		change_heredoc(&pipeline);
		do_execve(pipeline, &environ);
		ft_cmdclear(&pipeline, free);
		ft_tokenclear(&type_list, free);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
