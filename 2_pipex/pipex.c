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

void	ft_child_one(int fd_file1, char *cmd1, int *pipe_fd)
{//여기서 file1, cmd1실행 해야함 실행결과를 fds[1]로 넣음
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);//stdout이 fds[2]를 가리킴
	// dup2(fds[1], fd_file1);//stdout을 fds[1]로 바꿈
	execve(cmd1, 0, NULL);
	printf("11 ");
	printf("write!! child_one \n");//stdout이 아니라 fds[1]으로 출력됨
}

void	ft_child_two(int fd_file2, char *cmd2, int *pipe_fd)
{//fds[0]에서 읽고 , file2로 쓸거임//일단 테스트니까 stdout으로 씀
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);//stdin이 fds[0] 을 가리킴
	// dup2(fds[0], fd_fil2);
	char *buf;
	buf = malloc(100);
	read(0, buf, 32);
	printf("now, two get -> %s\n", buf);
}

int	main(int argc, char **argv, char **envp)
{//argv[1] = file1, argv[2] = cmd1, argv[3] = cmd2, argv[4] = file2 
	int		pipe_fd[2];
	int		file1;
	int		file2;
	pid_t	child_one;
	pid_t	child_two;
	int		status;

	if (argc != 5)
		return (0);
	// file1 = open(argv[1], O_RDONLY);얘한테 들어있는 텍스트 읽어서 실행 시키고 fd[0]에다가 쓸거임
	// file2 = open(argv[4], O_WRONLY);fd[1]를 read해서 얘한테 쓸거임
	pipe(pipe_fd);
	child_one = fork();
	if (child_one == -1)
		ft_error(errno);
	if (child_one == 0) //fork된 자식에서 실행
	{
		ft_child_one(file1, argv[2], pipe_fd);
		printf("child_done\n");
	}
	if (child_one > 0)//부모에서 실행
	{//부모 프로세스에서는 얘만 실행됨
		child_two = fork();
		if (child_two == 0)//child_two 일때만 함수 실행
			ft_child_two(file2, argv[3], pipe_fd);
		waitpid(child_one, &status, 0);
		waitpid(child_two, &status, 0);//둘 다 끝날때까지 기다리기
		if (child_two > 0)// 부모에서만 실행됨
			printf("parent done\n");
	}
}
// ---------------------------------------
//     ㄴ child_one     ㄴchild_two