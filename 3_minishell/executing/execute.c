/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:39:38 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/10 19:50:39 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	parent_prc(t_info *info)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (info->input_fd != -1)
		close(info->input_fd);
	info->input_fd = info->pipe_fd[0];
}

void	child_prc(t_info *info, t_list *curr_cmd)
{
	t_cmd	*cmd;
	char	*exe_cmd;
	char	**exe_argv;
	char	**exe_envp;
	
	cmd = (t_cmd *)(curr_cmd->content);
	handle_pipe(cmd, info);
	handle_redirection(curr_cmd);
	//redirection 에서 에러나면 알아서 redirection 함수 안에서 알아서 에러처리, exit
	if (cmd->simple_cmd == NULL)//redirection만 들어왔을때 정상종료
		exit(0);
	exe_argv = make_exe_argv(cmd->simple_cmd, info->env);
	exe_envp = make_exe_envp(info->env);
	exe_cmd = ((t_token *)(cmd->simple_cmd->content))->exp_value;
	exec_cmd_check(exe_cmd);
	if (execve(exe_cmd, exe_argv, exe_envp) == -1)
		exec_error_manager(PROMPT_ERROR, exe_cmd, 127);
}

void	run_execute(t_info *info)
{
	pid_t	pid;
	t_list	*cmd;
	int		prc_cnt;

	prc_cnt = 0;
	info->input_fd = -1;
	cmd = info->cmd;
	while (cmd)//non built-in
	{
		if (((t_cmd *)(cmd->content))->next_pipe == TRUE)
			pipe(info->pipe_fd);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pid = fork_pid();
		if (pid == 0)
			child_prc(info, cmd);
		if (cmd->next != NULL)
			close(info->pipe_fd[1]);
		parent_prc(info);
		prc_cnt++;
		cmd = cmd->next;
	}
	wait_prc(prc_cnt, pid);
	signal(SIGINT, signal_handle);
}

void	run_process(t_info *info)
{
	//already handled heredoc, exitcode = 0;
	if (check_one_builtin(info))
	{
		run_one_builtin(info);
	}
	else
	{
		run_execute(info);//자식만들어서 execve
	}
}
