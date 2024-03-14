/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:39:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/03/14 18:55:23 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	exec_cmd_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			break ;
		i++;
	}
	if (str[i] == '\0' && i == ft_strlen(str))
		custom_error_manager(PROMPT_ERROR, str, "command not found", 127);
}

void	wait_prc(int prc_cnt, pid_t pid)
{
	int		i;
	int		stat;
	pid_t	wait_pid;

	i = 0;
	stat = 0;
	while (i < prc_cnt)
	{
		wait_pid = wait(&stat);
		if (pid == wait_pid)
		{
			if (WIFSIGNALED(stat))
			{
				if (WTERMSIG(stat) == SIGQUIT)
					ft_putendl_fd("Quit: 3", 2);
				else if (WTERMSIG(stat) == SIGINT)
					ft_putchar_fd('\n', 2);
				g_last_exitcode = 128 + WTERMSIG(stat);
			}
			else
				g_last_exitcode = WEXITSTATUS(stat);
		}
		i++;
	}
}

pid_t	fork_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	return (pid);
}
