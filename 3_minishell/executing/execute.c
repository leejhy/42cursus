/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:39:38 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/08 13:57:55 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	parent_prc(t_info *info)
{
	if (info->input_fd != -1)
		close(info->input_fd);
	info->input_fd = info->pipe_fd[0];
}

void	child_prc(t_info *info)
{
	t_cmd	*cmd;
	char	*str;
	char	**exe_argv;
	char	**exe_envp;

	cmd = (t_cmd *)(info->cmd->content);
	handle_pipe(cmd, info);
	handle_redirection(info->cmd, info->pipe_fd);
	if (g_last_exitcode != 0)//캐스팅 해서 exit 할건지, exit하고 캐스팅할건지
		exit(g_last_exitcode);
	exe_argv = make_exe_argv(cmd->simple_cmd, info->env);
	exe_envp = make_exe_envp(info->env);
	//자식안에서 malloc하면 알아서 free
	if (execve(((t_token *)(cmd->simple_cmd->content))->exp_value, exe_argv, exe_envp) == -1)
	{
		str = strerror(errno);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		exit(1);
	}
}

void	run_execute(t_info *info)
{
	pid_t	pid;
	int		prc_cnt;

	prc_cnt = 0;
	info->input_fd = -1;
	while (info->cmd)//non built-in
	{
		if (((t_cmd *)(info->cmd->content))->next_pipe == TRUE)
			pipe(info->pipe_fd);
		pid = fork_pid();
		if (pid == 0)
			child_prc(info);
		if (info->cmd->next != NULL)
			close(info->pipe_fd[1]);
		parent_prc(info->pipe_fd);
		prc_cnt++;
		info->cmd = info->cmd->next;
	}
	wait_prc(prc_cnt);
}

void	run_process(t_info *info)
{
	//already handled heredoc, exitcode = 0;
	if (check_one_builtin(info))
		run_one_builtin(info);
	else
	{
		run_execute(info);//자식만들어서 execve
	}
}
