/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_process_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:03:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/11 17:08:21 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_minishell(void)
{
	g_last_exitcode = 0;
	rl_catch_signals = 0;
	signal(SIGINT, signal_handle);
	signal(SIGQUIT, SIG_IGN);
}

int	is_str_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ctrl_d(void)
{
	ft_putendl_fd("exit", 1);
	exit(g_last_exitcode);
}
