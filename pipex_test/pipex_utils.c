/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:28:09 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/15 18:01:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_wait_prcs(int prc_cnt)
{
	int	i;
	int	status;

	i = 0;
	while (i < prc_cnt)
	{
		if (wait(&status) == -1)
			ft_error(errno);
		i++;
	}
	printf("done\n");
}

pid_t	get_fork_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error(errno);
	return (pid);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
