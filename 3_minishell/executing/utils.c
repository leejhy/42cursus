/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:02:02 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/11 14:41:47 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	get_simple_cmd_cnt(t_list *simple_cmd)
{
	int		simple_cmd_cnt;

	simple_cmd_cnt = 0;
	while (simple_cmd != NULL)
	{
		simple_cmd_cnt++;
		simple_cmd = simple_cmd->next;
	}
	return (simple_cmd_cnt);
}

char	**get_argv(t_list *simple_cmd)
{
	char	**argv;
	int		cmd_cnt;
	int		idx;

	cmd_cnt = get_simple_cmd_cnt(simple_cmd);
	argv = ft_calloc(cmd_cnt + 1, sizeof(char *));
	idx = 0;
	while (simple_cmd != NULL)
	{
		argv[idx] = ((t_token *)simple_cmd->content)->exp_value;
		idx++;
		simple_cmd = simple_cmd->next;
	}
	return (argv);
}
