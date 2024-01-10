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

void	ft_child_one(int *pipe_fd, int fd_file1, char **cmd1, char **envp)
{//open file 1
//얘의 stdin fd_file1로,
	close(pipe_fd[0]);
	dup2(fd_file1, 0);
	dup2(pipe_fd[1], 1);//stdout을 pipe_fd1로 바꾸고 실행
	execve("/bin/", cmd1, envp);//실행결과를 pipe_fd[1]에 출력(넘기기)
}

void	ft_child_two(int *pipe_fd, int fd_file2, char **cmd2, char **envp)
{//open file2
	//stdin을 pipe로
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	dup2(fd_file2, 1);//stdout을 file2로
	execve("/bin/", cmd2, envp);
}

void	ft_parent(pid_t child_one, int *pipe_fd, char **argv, char **envp)
{
	pid_t	child_two;
	char	**cmd2;
	int		fd_file2;
	// int		status_one;
	// int		status_two;

	fd_file2 = open(argv[4], O_RDWR);
	cmd2 = ft_split(argv[3]);
	int i= 0;
	// while (cmd2[i])
	// {
	// 	printf("%s\n", cmd2[i]);
	// 	i++;
	// }
	child_two = fork();
	if (child_two == 0)
		ft_child_two(pipe_fd, fd_file2, cmd2, envp);
	if (child_one > 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(child_one, &status_one, WNOHANG);
		waitpid(child_two, &status_two, 0);
		close(fd_file2);
		printf("parent done\n");
	}
	free(cmd2);
}

int	main(int argc, char **argv, char **envp)
{//argv[1] = file1, argv[2] = cmd1, argv[3] = cmd2, argv[4] = file2 
//pipe, child one, parent 여기서 선언, 호출
	int		fd_file1;
	pid_t	child_one;
	int		pipe_fd[2];
	char	**cmd1;

	if (argc != 5)
		return (0);
	cmd1 = ft_split(argv[2]);
	fd_file1 = open(argv[1], O_RDWR);
	child_one = fork();
	if (child_one == 0)
		ft_child_one(pipe_fd, fd_file1, cmd1, envp);
	if (child_one > 0)
	{
		waitpid(child_one, &status_one, WNOHANG);
		ft_parent(child_one, pipe_fd, argv, envp);
	}
	free(cmd1);
	close(fd_file1);
}
