/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/10 16:29:19 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	remove_here_doc_files(t_list *here_doc_files)
{//fix the heredoc leaks
	t_list	*temp;

	while (here_doc_files != NULL)
	{
		temp = here_doc_files;
		unlink((char *)here_doc_files->content);
		here_doc_files = here_doc_files->next;
		free(temp);
	}
}

void	init_minishell(void)
{
	g_last_exitcode = 0;
	rl_catch_signals = 0;
	signal(SIGINT, signal_handle);
	signal(SIGQUIT, SIG_IGN);
}

void	clear_cmd(t_list *cmd)
{
	ft_lstclear(&((t_cmd *)cmd->content)->redirect, token_free);
	ft_lstclear(&((t_cmd *)cmd->content)->simple_cmd, token_free);
	ft_lstclear(&cmd, free);
}


void	do_process(t_info *info)
{
	//already handled heredoc
	run_process(info);
}

void	all_process(t_info *info)
{
	t_list	*here_doc_files;

	here_doc_files = handle_heredoc(info->cmd, info->env);
	if (g_last_exitcode == 0)
		do_process(info);
	remove_here_doc_files(here_doc_files);
	clear_cmd(info->cmd);
}

void	ctrl_d(void)
{
	ft_putendl_fd("\033[A\033[11Cexit", 2);
	exit(g_last_exitcode);
}

void	loop_shell(t_list *env)
{
	t_info	info;
	char	*str;

	info.env = env;
	while (1)
	{
		str = readline(PROMPT);
		if (str == NULL)
			ctrl_d();
		info.cmd = parsing(str, env);
		g_last_exitcode = 0;
		if (info.cmd)
			all_process(&info);
		if (ft_strlen(str) > 0)
			add_history(str);
		free(str);
	}
}
