/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/09 21:24:35 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	f(void){system("leaks minishell");}

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

void	do_noting(void *ptr)
{
	void	*tmp_ptr;

	tmp_ptr = ptr;
}

void	print_cmds(t_list *cmds)
{
	int	iter;

	iter = 1;
	while (cmds != NULL)
	{
		printf("--- address : %p---\n", cmds);
		printf("---%dth cmd---\n", iter);
		printf("===redirection===\n");
		print_node(((t_cmd *)cmds->content)->redirect);
		printf("=================\n");
		printf("===simplecmds====\n");
		print_node(((t_cmd *)cmds->content)->simple_cmd);
		printf("=================\n\n");
		iter++;
		cmds = cmds->next;
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
