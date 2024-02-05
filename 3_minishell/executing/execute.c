/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:39:38 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/04 21:46:24 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	parent_prc(int *pipe_fd)
{
	close(pipe_fd[0]);//부모에서 막 닫아도되나?
	close(pipe_fd[1]);
}

void	child_prc(t_list cmds, int *prev_pipe, int *pipe_fd, char **exe_envp)
{
	char	**exe_argv;

	handle_redirection(cmds, pipe_fd);
	if (prev_pipe[0] != -1)
	{
		dup2(prev_pipe[0] ,0);
		close(prev_pipe[0]);//dup2 했으니 close
	}
	if (((t_cmd *)(cmds->content))->next_pipe == TRUE)
	{
		dup2(pipe_fd[1], 1);//다음 파이프 존재하면 파이프에다가 쓰기
		close(pipe_fd[1]);//dup2 -> close
	}
	//execve에 들어갈 argv, envp 전처리 해야함
	exe_argv = make_exe_argv(((t_cmd *)(cmds->content))->simple_cmd);
	//이렇게하면 free를못하는디
	execve(exe_argv[0], exe_argv, exe_envp);
}

void	start_execute(t_list *cmds, t_list *env)
{
	// t_info	*info;
	pid_t	pid;
	int		pipe_fd[2];
	int		prev_pipe[2];
	// char	**exe_argv;
	char	**exe_envp;
	
	// info->cmd = ((t_token *)(((t_cmd *)(cmds->content))->simple_cmd->content))->;
	// info = malloc(sizeof(t_info));
	// info->cmds = cmds;
	// info->env = env;
	handle_heredoc(cmds);//HEREDOC -> INREDIRECT
	//if built-in
	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	prev_pipe[0] = -1;
	prev_pipe[1] = -1;
	while (cmds)//non built-in
	{
		if (cmds->next != NULL)
			pipe(pipe_fd);//cmds 구조체 -1개 만큼 pipe생성, 파이프세팅하는 함수 만들어도될듯
		//다음파이프가 존재하면 파이프를 만들고, 만든 파이프의 1번에다가 출력
		// exe_argv = make_exe_argv(((t_cmd *)(cmds->content))->simple_cmd);
		exe_envp = make_exe_envp(env);
		prev_pipe[0] = pipe_fd[0];
		prev_pipe[1] = pipe_fd[1];
		pid = fork_pid();
		if (pid == 0)
			child_prc(cmds, prev_pipe, pipe_fd, exe_envp);
		else if (pid > 0)
			parent_prc(pipe_fd);
		cmds = cmds->next;
	}
}
