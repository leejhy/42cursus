#include "pipex.h"

void	ft_fo()
{
	pid = fork();
	if (pid == 0)
	{
		if (close(pipe_fd[0]) == -1)
			ft_error(errno);
		if (dup2(pipe_fd[1], 0) == -1)
			ft_error(errno);
		if (dup2(pipe_fd[1], 1) == -1)//stdout을 file2 == -1)
			ft_error(errno);
		if (execve(cmd_path, cmd, 0) == -1)
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