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

void	parent_prc(t_info *info)
{
	close(info->prev_pipe[1]);//이전 파이프에다가 쓸 일이 없으니까 1번은 그냥 닫고
	if (info->prev_pipe[0] != -1)//이전 파이프에서 읽을일은 있으니까 -1인지만 체크하고 닫기
		close(info->prev_pipe[0]);
	wait(0);
//부모에서 막 닫아도되나? -> 부모에서 바로 닫아주는게 아니라 이전 파이프에서 읽은 이후에 닫아줘야함
}

void	child_prc(t_info *info, int *pipe_fd, char **exe_argv)
// void	child_prc(t_list *cmds, int *prev_pipe, int *pipe_fd, char **exe_argv, char **exe_envp)
{
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
	if (execve(exe_argv[0], exe_argv, 0) == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
}

void	start_execute(t_list *cmds, t_list *env)
{
	pid_t	pid;
	t_info	*info;
	int		pipe_fd[2];
	char	**exe_argv;
	char	**exe_envp;
	
	handle_heredoc(cmds);//HEREDOC -> INREDIRECT
	// info->cmd = ((t_token *)(((t_cmd *)(cmds->content))->simple_cmd->content))->;
	info = malloc(sizeof(t_info));
	info->cmds = cmds;
	info->env = env;
	info->prev_pipe[0] = -1;
	info->prev_pipe[1] = -1;
	while (info->cmds)//non built-in
	{
		if (((t_cmd *)(info->cmds->content))->next_pipe == TRUE)
			pipe(pipe_fd);//cmds 구조체 -1개 만큼 pipe생성, 파이프세팅하는 함수 만들어도될듯
		//다음파이프가 존재하면 파이프를 만들고, 만든 파이프의 1번에다가 출력
		exe_argv = make_exe_argv(((t_cmd *)(info->cmds->content))->simple_cmd, info->env);
		exe_envp = make_exe_envp(env);
		pid = fork_pid();
		if (pid == 0)
			child_prc(info, pipe_fd, exe_argv);
		else if (pid > 0)
			parent_prc(info);
		info->cmds = info->cmds->next;
	}
}
