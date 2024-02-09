/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:39:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/09 19:28:06 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	wait_prc(int prc_cnt, pid_t pid)
{
	int i;
	int	stat;

	i = 0;
	stat = 0;
	while (i < prc_cnt)
	{
		if (pid == wait(&stat))
			g_last_exitcode = WEXITSTATUS(stat);
		i++;
	}
}

pid_t	fork_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);//에러처리
	return (pid);
}
