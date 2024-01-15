/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:11:56 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/13 16:16:21 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**init_pipe(int argc, char **argv, int *prc_cnt)
{
	int	**fds;
	int	i;

	i = 0;
	if (argc < 4)
		argument_error();
	if (strncmp(argv[1], "here_doc", 8) == 0)
		*prc_cnt = argc - 4;
	else
		*prc_cnt = argc - 3;
	fds = malloc(sizeof(int *) * (*prc_cnt - 1));//파이프는 process 개수 - 1 개만큼 필요
	if (!fds)
		malloc_failed();
	while (i < (*prc_cnt - 1))
	{
		fds[i] = malloc(sizeof(int) * 2);
		if (!fds[i])
			malloc_failed();
		if (pipe(fds[i]) == -1)
			ft_error(errno);
		i++;
	}
	return (fds);
}
