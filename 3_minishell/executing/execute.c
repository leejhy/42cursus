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
void	parent_prc(t_pipe *vars)
{
	close(vars->prev_pipe[1]);//이전 파이프에다가 쓸 일이 없으니까 1번은 그냥 닫고
	if (vars->prev_pipe[0] != -1)//이전 파이프에서 읽을일은 있으니까 -1인지만 체크하고 닫기
		close(vars->prev_pipe[0]);
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
		// close(pipe_fd[1]);//dup2 -> close
	}
	handle_redirection(info->cmds, pipe_fd);
	if (vars->prev_pipe[0] != -1)
	{
		dup2(vars->prev_pipe[0] ,0);
		// close(vars->prev_pipe[0]);//dup2 했으니 close
	}
	//outredirection이 지정돼 있지 않을 경우에는 파이프로 쓴다!!
	//out redirection이 지정돼 있는지 아닌지 어떻게 판단???????????????????????
	//그냥 while 돌리면서 outredirection or append 있는지 확인하면 되는데 그건 좀 에반가
	vars->prev_pipe[0] = pipe_fd[0];
	//이렇게하면 free를못하는디
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
	
	handle_heredoc(info->cmds);//heredoc은 메인프로세스에서 진행되니까 info exitcode 갱신
	// check_builtin();
	vars = init_vars();
	// info->cmd = ((t_token *)(((t_cmd *)(cmds->content))->simple_cmd->content))->;
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
			parent_prc(vars);
			// parent_prc();
			// free(vars->exe_argv);
		}
		info->cmds = info->cmds->next;
	}
}
