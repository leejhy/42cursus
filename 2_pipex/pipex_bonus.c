/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:27:25 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/16 18:07:02 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_prc(char *file, int *pipe_fd, char **cmd, char **envp)
{
	int	fd_file1;

	fd_file1 = open(file, O_RDWR);
	if (fd_file1 == -1
		|| dup2(fd_file1, 0) == -1
		|| dup2(pipe_fd[1], 1) == -1
		|| close(pipe_fd[0]) == -1
		|| close(fd_file1) == -1
		|| execve(cmd[0], cmd, envp) == -1)
		ft_error(errno);
}

void	mid_prc(int *in_pipe, int *out_pipe, char **cmd, char **envp)
{
	if (dup2(in_pipe[0], 0) == -1)
		ft_error(errno);
	if (dup2(out_pipe[1], 1) == -1)
		ft_error(errno);
	if (close(in_pipe[1]) == -1)
		ft_error(errno);
	if (close(out_pipe[0]) == -1)
		ft_error(errno);
	if (execve(cmd[0], cmd, envp) == -1)
		ft_error(errno);
}

void	make_mid_prc(int prc_cnt, int **pipe_fd, char **argv, char **envp)
{
	int		i;
	pid_t	pid;
	char	**cmd;

	i = 0;
	while (i < prc_cnt - 2)
	{
		if (pipe(pipe_fd[i + 1]) == -1)
			ft_error(errno);
		cmd = ft_split(argv[i + 3], envp);
		pid = get_fork_pid();
		if (pid == 0)
			mid_prc(pipe_fd[i], pipe_fd[i + 1], cmd, envp);
		if (pid > 0)
		{
			if (close(pipe_fd[i][0]) == -1)
				ft_error(errno);
			if (close(pipe_fd[i][1]) == -1)
				ft_error(errno);
			split_frees(cmd);
		}
		i++;
	}
}

void	last_prc(int argc, char **argv, int *pipe_fd, char **envp)
{
	int		fd_file;
	char	**cmd;
	pid_t	pid;

	if (access(argv[argc - 1], F_OK) == 0)
		fd_file = open(argv[argc - 1], O_TRUNC | O_WRONLY);
	else
		fd_file = open(argv[argc - 1], O_CREAT | O_WRONLY, 0666);
	if (fd_file == -1)
		ft_error(errno);
	cmd = ft_split(argv[argc - 2], envp);
	pid = get_fork_pid();
	if (pid == 0)
	{
		if (dup2(pipe_fd[0], 0) == -1 || dup2(fd_file, 1) == -1
			|| close(pipe_fd[1]) == -1 || close(fd_file) == -1
			|| execve(cmd[0], cmd, envp) == -1)
			ft_error(errno);
	}
	if (pid > 0)
	{
		if (close(pipe_fd[0]) == -1 || close(pipe_fd[1]) == -1)
			ft_error(errno);
		split_frees(cmd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	first_pid;
	int		prc_cnt;
	int		**pipe_fd;
	char	**cmd;

	pipe_fd = init_pipe(argc, &prc_cnt);
	cmd = ft_split(argv[2], envp);
	first_pid = get_fork_pid();
	if (first_pid == 0)
		first_prc(argv[1], pipe_fd[0], cmd, envp);
	else if (first_pid > 0)
	{
		make_mid_prc(prc_cnt, pipe_fd, argv, envp);
		last_prc(argc, argv, pipe_fd[prc_cnt - 2], envp);
		pipes_free(pipe_fd, prc_cnt - 1);
		wait_process(prc_cnt);
		split_frees(cmd);
	}
}
