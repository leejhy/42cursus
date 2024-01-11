/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:24 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/09 20:38:39 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(int *pipe_fd, int fd_file1, char **cmd1, char *cmd1_path)
{//open file 1
//얘의 stdin fd_file1로,
	if (close(pipe_fd[0]) == -1)
		ft_error(errno);
	if (dup2(fd_file1, 0) == -1)
		ft_error(errno);
	if (dup2(pipe_fd[1], 1) == -1)
		ft_error(errno);
	if (execve(cmd1_path, cmd1, 0) == -1)
		ft_error(errno);
	//실행결과를 pipe_fd[1]에 출력(넘기기)
}

void	ft_child_two(int *pipe_fd, int fd_file2, char **cmd2, char *cmd2_path)
{//open file2
	//stdin을 pipe로
	if (close(pipe_fd[1]) == -1)
		ft_error(errno);
	if (dup2(pipe_fd[0], 0) == -1)
		ft_error(errno);
	if (dup2(fd_file2, 1) == -1)//stdout을 file2 == -1)
		ft_error(errno);
	if (execve(cmd2_path, cmd2, 0) == -1)
		ft_error(errno);
}

void	ft_parent(int *pipe_fd, char **argv, char **envp)
{
	pid_t	child_two;
	char	**cmd2;
	char	*cmd2_path;
	int		fd_file2;

	cmd2 = ft_split(argv[3]);
	cmd2_path = ft_path_cmd(cmd2[0], envp);
	fd_file2 = ft_open(argv[4], O_RDWR);
	child_two = fork();
	if (child_two < 0)
		ft_error(errno);
	else if (child_two == 0)
		ft_child_two(pipe_fd, fd_file2, cmd2, cmd2_path);
	else if (child_two > 0)
	{
		if (close(pipe_fd[0]) == -1)
			ft_error(errno);
		if (close(pipe_fd[1]) == -1)
			ft_error(errno);
		wait_process(2);
		if (close(fd_file2) == -1)
			ft_error(errno);
		split_frees(cmd2);
		free(cmd2_path);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_file1;
	pid_t	child_one;
	int		pipe_fd[2];
	char	**cmd1;
	char	*cmd1_path;

	if (argc != 5)
		return (0);
	cmd1 = ft_split(argv[2]);
	cmd1_path = ft_path_cmd(cmd1[0], envp);
	fd_file1 = ft_open(argv[1], O_RDWR);
	if (pipe(pipe_fd) == -1)
		ft_error(errno);
	child_one = fork();
	if (child_one < 0)
		ft_error(errno);
	else if (child_one == 0)
		ft_child_one(pipe_fd, fd_file1, cmd1, cmd1_path);
	else if (child_one > 0)
	{
		ft_parent(pipe_fd, argv, envp);
		free(cmd1_path);
		split_frees(cmd1);
		close(fd_file1);
	}
}
