/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:40:01 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/08 13:51:49 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	handle_pipe(t_cmd *cmd, t_info *info)
{
	if (cmd->next_pipe == TRUE)//pipe인식이 redirection 보다 먼저
	{
		dup2(info->pipe_fd[1], 1);//다음 파이프 존재하면 파이프에다가 쓰기
		close(info->pipe_fd[0]);
		close(info->pipe_fd[1]);
	}
	if (info->input_fd != -1)
	{
		dup2(info->input_fd , 0);
		close(info->input_fd);
	}
}