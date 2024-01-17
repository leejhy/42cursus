/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/16 18:58:08 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

void	ft_error(int err)
{
	char	*str;
	size_t	len;

	str = strerror(err);
	len = ft_strlen(str);
	write(2, str, len);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	malloc_failed(void)
{
	write(2, "malloc failed\n", 14);
	exit(EXIT_FAILURE);
}

void	argument_error(void)
{
	write(2, "invalid number of arguments\n", 28);
	exit(EXIT_FAILURE);
}

void	input_error(void)
{
	write(2, "wrong argument input\n", 21);
	exit(EXIT_FAILURE);
}

void	cmd_error(char **cmd, char **envp)
{
	if (execve(cmd, cmd, envp) == -1)
		ft_error(errno);
}