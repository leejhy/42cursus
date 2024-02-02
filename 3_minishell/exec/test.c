#include "minishell.h"

// void	simple_parsing(t_cmd *pa, char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '<')
// 		{
// 			i++;
// 			if (str[i] != '<')
// 				pa->redirect = 1;
// 			else
// 				pa->redirect = 2;
// 		}
// 		if (str[i] == '>')
// 		{
// 			i++;
// 			if (str[i] != '>')
// 				pa->redirect = 3;
// 			else
// 				pa->redirect = 4;
// 		}
// 	}
// }

void	execute_cmd(int i, int *pipe_fd)
{
	char	str[5] = "hell\n";
	int	fd;

	if (i == 0)
	{
		close(pipe_fd[0]);
		write(pipe_fd[1], str, 5);
		close(pipe_fd[1]);
	}
	if (i == 1)
	{
		close(pipe_fd[1]);
		read(pipe_fd[0], str, 5);
		write(1, str, 5);
		close(pipe_fd[0]);
	}
}

void	ft_execute(void)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		i;

	i = 0;
	while (i < 2)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
		{
			execute_cmd(i, pipe_fd);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			exit(1);
		}
		else if (pid > 0)
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			while (wait(NULL) != -1);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	ft_execute();
}