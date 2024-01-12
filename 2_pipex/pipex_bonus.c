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

void	ft_fo()
{
	pid = fork();
	if (pid == 0)
	{
		if (close(pipe_fd[0]) == -1 ||
			dup2(pipe_fd[1], 0) == -1 ||
			dup2(pipe_fd[1], 1) == -1 ||
			execve(cmd_path, cmd, 0) == -1)
			ft_error(errno);
	}
	if (pid > 0)
		return ;
}

int	main(void)
{
	pid_t pid;

	int	i;
	
	i = 0;
	pid = fork();
	if (pid == 0)
		ft_child();
	if (pid > 0)
	{
		while (i < 10)
		{
			ft_fo;
			i++;
		}
	}
}

void	ft_child_one(char *file, int *pipe_fd, char **cmd1, char *path)
{
	int	fd_file1;

	fd_file1 = open(file, O_RDWR);
	if (fd_file1 == -1 ||
		dup2(pipe_fd[1], 1) == -1 ||
		dup2(fd_file1, 0) == -1 ||
		close(pipe_fd[0]) == -1 ||
		close(fd_file1) == -1 ||
		execve(path, cmd1, 0) == -1)
		ft_error(errno);
}

void	ft_child_two(char *file, int *pipe_fd, char **cmd2, char *path)
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
		execve(path, cmd2, 0) == -1)
		ft_error(errno);
}

void	ft_parent(int *pipe_fd, char **argv, char **envp)
{
	pid_t	child_two;
	char	**cmd2;
	char	*cmd2_path;

	cmd2 = ft_split(argv[3]);
	cmd2_path = ft_find_path(cmd2[0], envp);
	child_two = fork();
	if (child_two < 0)
		ft_error(errno);
	else if (child_two == 0)
		ft_child_two(argv[4], pipe_fd, cmd2, cmd2_path);
	else if (child_two > 0)
	{
		if (close(pipe_fd[0]) == -1 ||
			close(pipe_fd[i] == -1))
			ft_error(errno);
		wait_process(2);
		split_frees(cmd2);
		free(cmd2_path);
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	child_one;
	int		pipe_fd[2];
	char	**cmd1;
	char	*cmd1_path;

	if (argc != 5)
		return (0);
	cmd1 = ft_split(argv[2]);
	cmd1_path = ft_find_path(cmd1[0], envp);
	if (pipe(pipe_fd) == -1)
		ft_error(errno);
	child_one = fork();
	if (child_one < 0)
		ft_error(errno);
	else if (child_one == 0)
		ft_child_one(argv[1], pipe_fd, cmd1, cmd1_path);
	else if (child_one > 0)
	{
		ft_parent(pipe_fd, argv, envp);
		free(cmd1_path);
		split_frees(cmd1);
	}
	return (0);
}
