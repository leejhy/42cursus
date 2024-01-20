/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/19 18:16:22 by junhylee         ###   ########.fr       */
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

void	cmd_error(void)
{
	char	*str;
	size_t	len;

	str = strerror(2);
	len = ft_strlen(str);
	write(2, str, len);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	check_cmd(char **cmd)
{
	char	*str;
	size_t	i;

	i = 0;
	if (cmd == NULL)
		return (1);
	str = cmd[0];
	if (*str == '\0')
		return (1);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
