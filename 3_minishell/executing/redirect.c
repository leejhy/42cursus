/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:10:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/10 17:28:11 by junhylee         ###   ########.fr       */
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

void	handle_inredirection(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exec_error_manager(PROMPT_ERROR, filename, 1);
	dup2(fd, 0);//dup2해주고
	close(fd);
}

void	handle_outredirection(char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		exec_error_manager(PROMPT_ERROR, filename, 1);
	dup2(fd, 1);//dup2해주고
	close(fd);
}

void	handle_append(char *filename)
{
	int		fd;
	
	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		exec_error_manager(PROMPT_ERROR, filename, 1);
	dup2(fd, 1);//dup2해주고
	close(fd);
}

void	handle_redirection(t_list *cmds)
{
	t_list	*redirect;
	int		type;
	char	*value;
	char	*exp_value;

	redirect = ((t_cmd *)(cmds->content))->redirect;
	while (redirect)
	{//while 돌리면서 전역변수 0세팅 계속
		type = ((t_token *)(redirect->content))->type;
		value = ((t_token *)(redirect->content))->value;
		exp_value = ((t_token *)(redirect->content))->exp_value;
		if (value)
		{
			if (((t_token *)(redirect->content))->is_ambiguous == TRUE
				|| (ft_strncmp("$", value, 1) == 0 && value[1] != '?' && value[1] != '\0'))
				custom_error_manager(PROMPT_ERROR, value, "ambiguous redirect", 1);
		}
		if (type == INREDIRECTION)
			handle_inredirection(exp_value);
		else if (type == OUTREDIRECTION)
			handle_outredirection(exp_value);
		else if (type == APPEND)
			handle_append(exp_value);
		redirect = redirect->next;
	}
}
