/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_builtin_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:39:38 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/13 18:40:18 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	run_one_builtin(t_info *info)
{
	one_builtin_fd_save_load(info, SAVE_MODE);
	one_builtin_dup_process(info);
	if (g_last_exitcode == 0)
	{
		run_one_builtin_sub(info, \
		((t_token *)((t_list *)((t_cmd *)info->cmd->content)-> \
		simple_cmd)->content)->exp_value);
	}
	one_builtin_fd_save_load(info, LOAD_MODE);
}
