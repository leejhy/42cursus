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

#include "tokenize.h"

void	parent_prc(int *pipe_fd)
{
	close(pipe_fd[0]);//부모에서 막 닫아도되나?
	close(pipe_fd[1]);
}

void	child_prc(t_list *cmds, int *prev_pipe, int *pipe_fd, char **envp)
{
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
	
	execve(((t_token *)(cmds->content))->exp_value, 0,envp);
}

void	start_execute(t_list *cmds, char **envp)
{
	// int	pipe_cnt;
	pid_t	pid;
	int		pipe_fd[2];
	int		prev_pipe[2];
	
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
		prev_pipe[0] = pipe_fd[0];
		prev_pipe[1] = pipe_fd[1];
		pid = fork_pid();
		if (pid == 0)
			child_prc(cmds, prev_pipe, pipe_fd, envp);
		else if (pid > 0)
			parent_prc(pipe_fd);
		cmds = cmds->next;
	}
}
