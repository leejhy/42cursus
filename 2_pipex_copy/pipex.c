/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:24 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/08 20:13:09 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(int fd_file1, char **cmd1, int *pipe_fd, char **envp)
{//open file 1
	close(pipe_fd[0]);
	dup2(pipe_fd[1], fd_file1);
	execve("/bin/sh", cmd1, envp);
	printf("11 ");
	printf("write!! child_one \n");//stdout이 아니라 fds[1]으로 출력됨
}

void	ft_child_two(int fd_file2, char **cmd2, int *pipe_fd, char **envp)
{//open file2
	close(pipe_fd[1]);
	dup2(pipe_fd[0], fd_file2);//stdin이 fds[0] 을 가리킴
	char *buf;
	buf = malloc(100);
	read(0, buf, 32);
	printf("now, two get -> %s\n", buf);
}

void	ft_parent(int file1, int file2, char **argv, char **envp)
{
	int		pipe_fd[2];
	ptd_t	child_one;
	ptd_t	child_two;
	char	**cmd1;
	char	**cmd2;

	cmd1 = ft_split(argv[2]);
	cmd2 = ft_split(argv[3]);
	pipe(pipe_fd);
	// close(pipe_fd[0]);
	// close(pipe_fd[1]);
	child_one = fork();
	if (child_one == 0)
		ft_child_one(file1, cmd1, pipe_fd, envp);
	if (child_one > 0)
	{
		child_two = fork();
		if (child_two == 0)
			ft_child_two(file2, cmd2, pipe_fd, envp);
		waitpid(child_one, &status, 0);
		waitpid(child_two, &status, 0);
		if (child_two > 0)
			printf("parent done\n");
	}
}

int	main(int argc, char **argv, char **envp)
{//argv[1] = file1, argv[2] = cmd1, argv[3] = cmd2, argv[4] = file2 
	int		file1;
	int		file2;
//pipe, child one, parent 여기서 선언, 호출
	if (argc != 5)
		return (0);
	file1 = open(argv[1], O_RDONLY);//얘한테 들어있는 텍스트 읽어서 실행 시키고 fd[0]에다가 쓸거임
	file2 = open(argv[4], O_WRONLY);//fd[1]를 read해서 얘한테 쓸거임
	ft_parent(file1, file2, argv, envp);
}
