/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:24 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/11 19:49:57 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(char *file, int *pipe_fd, char **cmd1, char *path)
{
	int	fd_file1;

	if (access(file, F_OK) == 0)
		fd_file1 = open(file, O_RDWR);
	else
		fd_file1 = open(file, O_CREAT | O_RDWR);
	fd_file1 = open(file, O_RDWR);
	if (dup2(pipe_fd[1], 1) == -1)
		ft_error(errno);
	if (dup2(fd_file1, 0) == -1)
		ft_error(errno);
	if (close(pipe_fd[0]) == -1)
		ft_error(errno);
	if (close(fd_file1) == -1)
		ft_error(errno);
	if (execve(path, cmd1, 0) == -1)
		ft_error(errno);
}

void	ft_child_two(char *file, int *pipe_fd, char **cmd2, char *path)
{
	int	fd_file2;

	if (access(file, F_OK) == 0)
		fd_file2 = open(file, O_TRUNC | O_RDWR);
	else
		fd_file2 = open(file, O_CREAT | O_RDWR);
	if (dup2(pipe_fd[0], 0) == -1) 
		ft_error(errno);
	if (dup2(fd_file2, 1) == -1)
		ft_error(errno);
	if (close(pipe_fd[1]) == -1)
		ft_error(errno);
	if (close(fd_file2) == -1)
		ft_error(errno);
	if (execve(path, cmd2, 0) == -1)
		ft_error(errno);
}

void	ft_parent(int *pipe_fd, char **argv, char **envp)
{
	pid_t	child_two;
	char	**cmd2;
	char	*cmd2_path;

	cmd2 = ft_split(argv[3]);
	cmd2_path = ft_path_cmd(cmd2[0], envp);
	child_two = fork();
	if (child_two < 0)
		ft_error(errno);
	else if (child_two == 0)
		ft_child_two(argv[4], pipe_fd, cmd2, cmd2_path);
	else if (child_two > 0)
	{
		if (close(pipe_fd[0]) == -1)
			ft_error(errno);
		if (close(pipe_fd[1]) == -1)
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
	cmd1_path = ft_path_cmd(cmd1[0], envp);
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
}
