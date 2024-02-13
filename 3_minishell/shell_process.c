/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/13 18:43:51 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	remove_here_doc_files(t_list *here_doc_files)
{
	t_list	*temp;

	while (here_doc_files != NULL)
	{
		temp = here_doc_files;
		unlink((char *)here_doc_files->content);
		here_doc_files = here_doc_files->next;
		free(temp);
	}
}

void	clear_cmd(void *cmd)
{
	ft_lstclear(&((t_cmd *)cmd)->redirect, token_free);
	ft_lstclear(&((t_cmd *)cmd)->simple_cmd, token_free);
	free(cmd);
}

void	all_process(t_info *info)
{
	t_list	*here_doc_files;

	here_doc_files = handle_heredoc(info->cmd, info->env);
	if (g_last_exitcode == 0)
		run_process(info);
	remove_here_doc_files(here_doc_files);
	ft_lstclear(&info->cmd, clear_cmd);
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
		if (info.cmd)
		{
			g_last_exitcode = 0;
			all_process(&info);
		}
		if (ft_strlen(str) > 0)
			add_history(str);
		free(str);
	}
}
