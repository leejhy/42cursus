/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:39:38 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/07 19:11:16 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

// void	parent_prc(void)
void	parent_prc(t_pipe *vars, int *pipe_fd)
{//파이프 교체는 항상 parent에서 일어나야함
	if (vars->prev_pipe[0] != -1)//이전파이프가 존재한 상태로 이미 자식으로 들어갔으니까 close해줌
		close(vars->prev_pipe[0]);
	vars->prev_pipe[0] = pipe_fd[0];//부모에서 현재 파이프를 백업해줌, pipe_fd[0]을 바로 close하면안됨 위에서 close해주네
	//free(vars->argv), free(vars->envp); 추가
	// close(pipe_fd[1]);//얘는 쓸모가없어서 바로 close
	//pipe_fd[1]이 마지막 파이프면 어떻게하지?
	// free(vars->exe_argv);
	// free(vars->exe_envp);//envp는 싹 free
	// wait(0);
}

void	child_prc(t_info *info, t_pipe *vars, int *pipe_fd)
{
	t_list	*cmd;
	char	*str;

	cmd = ((t_cmd *)(info->cmds->content))->simple_cmd;
	if (((t_cmd *)(info->cmds->content))->next_pipe == TRUE)//pipe인식이 redirection 보다 먼저!
	{
		dup2(pipe_fd[1], 1);//다음 파이프 존재하면 파이프에다가 쓰기
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	if (vars->prev_pipe[0] != -1)
	{
		dup2(vars->prev_pipe[0] , 0);
		close(vars->prev_pipe[0]);
	}
	handle_redirection(info->cmds, pipe_fd);
	if (execve(((t_token *)(cmd->content))->exp_value, vars->exe_argv, vars->exe_envp) == -1)
	{
		write(2, "---------------------------------\n", 34);
		str = strerror(errno);
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
	int		prc_cnt;

	handle_heredoc(info->cmds, info->env);//heredoc은 메인프로세스에서 진행되니까 info exitcode 갱신

	// printf("%s\n", (((t_token *)(((t_cmd *)(info->cmds->content))->redirect->content))->exp_value));
	// check_builtin();
	prc_cnt = 0;
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
		///////////////parent process
		if (info->cmds->next != NULL)//다음 노드가 없으면 파이프가 없다는 뜻이니까 파이프 안닫음
			close(pipe_fd[1]);
		parent_prc(vars, pipe_fd);
		//pid == 0에서 자식프로세스 들어가서 execve로 프로세스 종료되니까 else if 필요 없을듯
		prc_cnt++;
		info->cmds = info->cmds->next;
	}
	for (int i = 0; i < prc_cnt; i++)
		wait(0);
}
