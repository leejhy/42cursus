/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:02:02 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/03 17:11:37 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	ft_test(t_list *cmds)
{
	t_list	*cmd;
	char	*str;
	char	*argv[] = {"ls", 0};
	pid_t	pid;

	cmd = ((t_cmd *)(cmds->content))->simple_cmd;
	str = ((t_token *)(cmd->content))->exp_value;
	pid = fork();
	if (pid == 0)
	{
		execve(str, argv, 0);
	}
}
