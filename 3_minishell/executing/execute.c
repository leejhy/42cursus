/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:39:38 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/05 21:55:51 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	parent_prc(t_info *info, t_pipe *vars)
{
	close(info->prev_pipe[1]);//이전 파이프에다가 쓸 일이 없으니까 1번은 그냥 닫고
	if (info->prev_pipe[0] != -1)//이전 파이프에서 읽을일은 있으니까 -1인지만 체크하고 닫기
		close(info->prev_pipe[0]);
	free(vars->exe_argv);
	free(vars->exe_envp);//envp는 싹 free
	wait(0);
//부모에서 막 닫아도되나? -> 부모에서 바로 닫아주는게 아니라 이전 파이프에서 읽은 이후에 닫아줘야함
}

void	child_prc(t_info *info, t_pipe *vars, int *pipe_fd)
// void	child_prc(t_list *cmds, int *prev_pipe, int *pipe_fd, char **exe_argv, char **exe_envp)
{
	t_list	*cmd;

	cmd = ((t_cmd *)(info->cmds->content))->simple_cmd;
	handle_redirection(info->cmds, pipe_fd);
	if (info->prev_pipe[0] != -1)
	{
		dup2(info->prev_pipe[0] ,0);
		close(info->prev_pipe[0]);//dup2 했으니 close
	}
	if (((t_cmd *)(info->cmds->content))->next_pipe == TRUE)
	{
		dup2(pipe_fd[1], 1);//다음 파이프 존재하면 파이프에다가 쓰기
		close(pipe_fd[1]);//dup2 -> close
	}
	info->prev_pipe[0] = pipe_fd[0];
	//이렇게하면 free를못하는디
	//execve에 envp 잘못넣으면 badaddress남
	if (execve(((t_token *)(cmd->content))->exp_value, vars->exe_argv, vars->exe_envp) == -1)
	{
		printf("%s\n", strerror(errno));
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
		info->exe_argv = make_exe_argv(((t_cmd *)(info->cmds->content))->simple_cmd, info->env);
		info->exe_envp = make_exe_envp(info->env);
		pid = fork_pid();
		if (pid == 0)
			child_prc(info, vars, pipe_fd);
		else if (pid > 0)
		{
			parent_prc(info, vars);
			free(info->exe_argv);
		}
		info->cmds = info->cmds->next;
	}
}
