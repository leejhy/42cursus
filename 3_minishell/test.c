#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int	main()
{
	pid_t	pid;
	int pipe_fd[2];
	int	in;
	int	out;

	in = -1;
	out = -1;
	for (int i = 1; i < 3; i++)
	{
		printf("=================\n");
		pipe(pipe_fd);
		in = pipe_fd[0];
		out = pipe_fd[1];
		pid = fork();
		if (pid == 0)
		{
			printf("%d pipe : %d %d\n", i, pipe_fd[0], pipe_fd[1]);
			printf("infd %d outfd %d\n", in, out);
			exit(1);
		}
		else if (pid > 0)
		{
			printf("%dth parent\n", i);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
		}
	}
}