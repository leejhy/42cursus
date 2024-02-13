/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/13 18:43:08 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	signal_handle(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_last_exitcode = 1;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*env;

	init_minishell();
	if (argc != 1)
		return (0);
	argv = NULL;
	env = get_env_list(envp);
	loop_shell(env);
	exit(0);
	return (0);
}
