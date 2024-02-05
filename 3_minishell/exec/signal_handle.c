/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:52:09 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/30 18:48:33 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(int signo)
{//^C 문자 제거 해야함
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_sigquit(int signo)
{//이게맞나.. a.out argv[0]으로 수정
	printf("zsh: quit\t./a.out\n");
	exit(1);
}

int	main(void)
{
	char	*str;

	signal(SIGQUIT, ft_sigquit);
	signal(SIGINT, ft_sigint);
	while (1)
	{
		str = readline("hello $ ");
		add_history(str);
		printf("readline : %s\n", str);
	}
}
