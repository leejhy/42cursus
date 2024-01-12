/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:28:09 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/11 20:32:11 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_process(int process_cnt)
{
	int	i;
	int	status;

	i = 0;
	while (i < process_cnt)
	{
		if (wait(&status) == -1)
			ft_error(errno);
		i++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
