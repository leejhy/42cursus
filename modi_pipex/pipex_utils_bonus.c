/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:11:56 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/16 17:57:09 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

int	**init_pipe(int argc, int *prc_cnt)
{
	int	**fds;
	int	i;

	i = 0;
	if (argc <= 4)
		argument_error();
	*prc_cnt = argc - 3;
	fds = malloc(sizeof(int *) * (*prc_cnt - 1));
	if (!fds)
		malloc_failed();
	while (i < (*prc_cnt - 1))
	{
		fds[i] = malloc(sizeof(int) * 2);
		if (!fds[i])
			malloc_failed();
		i++;
	}
	if (pipe(fds[0]) == -1)
		ft_error(errno);
	return (fds);
}

void	pipes_free(int **pipes, int free_cnt)
{
	int	i;

	i = 0;
	while (i < free_cnt)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	execute_last(int fd_file, int *pipe_fd, char **cmd, char **envp)
{
	if (dup2(pipe_fd[0], 0) == -1 || dup2(fd_file, 1) == -1
		|| close(pipe_fd[1]) == -1 || close(fd_file) == -1
		|| execve(cmd[0], cmd, envp) == -1)
		ft_error(errno);
}