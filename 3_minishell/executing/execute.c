/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:39:38 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/06 22:23:15 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

// void	parent_prc(void)
void	parent_prc(t_pipe *vars, int *pipe_fd)
{//파이프 교체는 항상 parent에서 일어나야함
	if (vars->prev_pipe[0] != -1)//이전파이프가 존재한 상태로 이미 자식으로 들어갔으니까 close해줌
		close(vars->prev_pipe[0]);
	vars->prev_pipe[0] = pipe_fd[0];//부모에서 현재 파이프를 백업해줌, pipe_fd[0]을 바로 close하면안됨 위에서 close해주네
	// close(pipe_fd[1]);//얘는 쓸모가없어서 바로 close
	//pipe_fd[1]이 마지막 파이프면 어떻게하지?
	// free(vars->exe_argv);
	// free(vars->exe_envp);//envp는 싹 free
	wait(0);
//부모에서 막 닫아도되나? -> 부모에서 바로 닫아주는게 아니라 이전 파이프에서 읽은 이후에 닫아줘야함
}

void	child_prc(t_info *info, t_pipe *vars, int *pipe_fd)
{
	t_list	*cmd;
	char	*str;

	cmd = ((t_cmd *)(info->cmds->content))->simple_cmd;
	if (((t_cmd *)(info->cmds->content))->next_pipe == TRUE)//pipe인식이 redirection 보다 먼저!
	{
		dup2(pipe_fd[1], 1);//다음 파이프 존재하면 파이프에다가 쓰기
	}
	if (vars->prev_pipe[0] != -1)//이거 위치도 조정해야함
	{
		dup2(vars->prev_pipe[0] ,0);
	}
	handle_redirection(info->cmds, pipe_fd);
	if (execve(((t_token *)(cmd->content))->exp_value, vars->exe_argv, vars->exe_envp) == -1)
	{
		str = strerror(errno);
		write(2,"=======\n", 8);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		exit(1);
	}
}

void	start_execute(t_info *info)
{
	t_pipe	*vars;
	pid_t	pid;
	int		pipe_fd[2];

	handle_heredoc(info->cmd, info->env);//heredoc은 메인프로세스에서 진행되니까 info exitcode 갱신
	// check_builtin();
	vars = init_vars();
	while (info->cmds)//non built-in
	{
		if (((t_cmd *)(info->cmds->content))->next_pipe == TRUE)
			pipe(pipe_fd);//cmds 구조체 -1개 만큼 pipe생성, 파이프세팅하는 함수 만들어도될듯
		//다음파이프가 존재하면 파이프를 만들고, 만든 파이프의 1번에다가 출력
		vars->exe_argv = make_exe_argv(((t_cmd *)(info->cmds->content))->simple_cmd, info->env);//2차원포인터만 free
		vars->exe_envp = make_exe_envp(info->env);//envp는 모든 인덱스 free
		pid = fork_pid();
		if (pid == 0)
			child_prc(info, vars, pipe_fd);
		else if (pid > 0)
		{
			if (info->cmds->next != NULL)//다음 노드가 없으면 파이프가 없다는 뜻이니까 파이프 안닫음
				close(pipe_fd[1]);
			parent_prc(vars, pipe_fd);
			// parent_prc();
			// free(vars->exe_argv);
		}
		info->cmds = info->cmds->next;
	}
}
