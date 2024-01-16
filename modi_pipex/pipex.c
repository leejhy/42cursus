/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:24 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/16 18:14:28 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(char *file, int *pipe_fd, char **cmd1, char **envp)
{
	int	fd_file1;

	fd_file1 = open(file, O_RDWR);
	if (fd_file1 == -1
		|| dup2(pipe_fd[1], 1) == -1
		|| dup2(fd_file1, 0) == -1
		|| close(pipe_fd[0]) == -1
		|| close(fd_file1) == -1
		|| execve(cmd1[0], cmd1, envp) == -1)
		ft_error(errno);
}

void	ft_child_two(char *file, int *pipe_fd, char **cmd2, char **envp)
{
	int	fd_file2;

	if (access(file, F_OK) == 0)
		fd_file2 = open(file, O_TRUNC | O_WRONLY);
	else
		fd_file2 = open(file, O_CREAT | O_WRONLY, 0666);
	if (fd_file2 == -1
		|| dup2(pipe_fd[0], 0) == -1
		|| dup2(fd_file2, 1) == -1
		|| close(pipe_fd[1]) == -1
		|| close(fd_file2) == -1
		|| execve(cmd2[0], cmd2, envp) == -1)
		ft_error(errno);
}

void	ft_parent(int *pipe_fd, char **argv, char **envp)
{
	pid_t	child_two;
	char	**cmd2;

	cmd2 = ft_split(argv[3], envp);
	child_two = get_fork_pid();
	if (child_two == 0)
		ft_child_two(argv[4], pipe_fd, cmd2, envp);
	else if (child_two > 0)
	{
		if (close(pipe_fd[0]) == -1 || close(pipe_fd[1]) == -1)
			ft_error(errno);
		split_frees(cmd2);
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	child_one;
	int		pipe_fd[2];
	char	**cmd1;

	if (argc != 5)
		argument_error();
	cmd1 = ft_split(argv[2], envp);
	if (pipe(pipe_fd) == -1)
		ft_error(errno);
	child_one = get_fork_pid();
	if (child_one == 0)
		ft_child_one(argv[1], pipe_fd, cmd1, envp);
	else if (child_one > 0)
	{
		ft_parent(pipe_fd, argv, envp);
		wait_process(2);
		split_frees(cmd1);
	}
	return (0);
}
