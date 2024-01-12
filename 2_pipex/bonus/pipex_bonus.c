/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:27:25 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/11 18:27:26 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_process(char *file, int *pipe_fd, char **cmd1, char **envp)
{
	int	fd_file1;

	fd_file1 = open(file, O_RDWR);
	if (fd_file1 == -1 ||
		dup2(pipe_fd[1], 1) == -1 ||
		dup2(fd_file1, 0) == -1 ||
		close(pipe_fd[0]) == -1 ||
		close(fd_file1) == -1 ||
		execve(cmd1[0], cmd1, envp) == -1)
		ft_error(errno);
}

void	ft_last_process(char *file, int *pipe_fd, char **cmd2, char **envp)
{
	int	fd_file2;

	if (access(file, F_OK) == 0)
		fd_file2 = open(file, O_TRUNC | O_WRONLY);
	else
		fd_file2 = open(file, O_CREAT | O_WRONLY, 0777);
	if (fd_file2 == -1 ||
		dup2(pipe_fd[0], 0) == -1 ||
		dup2(fd_file2, 1) == -1 ||
		close(pipe_fd[1]) == -1 ||
		close(fd_file2) == -1 ||
		execve(cmd2[0], cmd2, envp) == -1)
		ft_error(errno);
}

void	ft_mid_process()
{
	pid = fork();
	if (pid == 0)

		if (close(pipe_fd[0]) == -1 ||
			dup2(pipe_fd[1], 0) == -1 ||
			dup2(pipe_fd[1], 1) == -1 ||
			execve(cmd_path, cmd, 0) == -1)
			ft_error(errno);
	}
	if (pid > 0)
		return ;
}

void	ft_parent(int **pipe_fd, char **argv, char **envp)
{
	int		i;
	pid_t	pid;
	char	**cmd;

	i = 0;
	while (i < prc_cnt)
	{
		if (pipe(pipe_fd[i + 1]) == -1)
			ft_error(errno)
		cmd = ft_split(argv[i + 2]);
		cmd[0] = ft_find_path(cmd[0], envp);
		pid = fork();
		if (pid < 0)
			ft_error(errno);
		if (pid == 0)
			ft_prc_mid(pipefd[i + 1], cmd, envp);
		if (pid > 0)
		{
			if ((close(pipe_fd[i + 1][0]) == -1) || 
				(close(pipe_fd[i + 1][0] == -1)))
				ft_error(errno);
		}
		i++;
	}
		if (close(pipe_fd[0]) == -1 ||
			close(pipe_fd[1]) == -1)
			ft_error(errno);
		wait_process(2);
		split_frees(cmd2);
	}
}


int	main(int argc, char **argv, char **envp)
{//argc-3이 cmd개수, 자식 프로세스 개수
	pid_t	first_prc;
	int		prc_cnt;
	int		**pipe_fd;

	pipe_fd = init_pipe(argc, argv, &prc_cnt);
	if (pipe(pipe_fd[0]) == -1)
		ft_error(errno);
	first_prc = fork();
	if (first_prc < 0)
		ft_error(errno);
	else if (first_prc == 0)
		ft_first_process();
	else if (first_prc > 0)
	{
		ft_parent(pipe_fd, argv, envp);
	}
}
