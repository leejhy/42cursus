/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:10:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/13 18:39:17 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	handle_pipe(t_cmd *cmd, t_info *info)
{
	if (cmd->next_pipe == TRUE)
	{
		dup2(info->pipe_fd[1], 1);
		close(info->pipe_fd[0]);
		close(info->pipe_fd[1]);
	}
	if (info->input_fd != -1)
	{
		dup2(info->input_fd, 0);
		close(info->input_fd);
	}
}

void	handle_inredirection(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exec_error_manager(PROMPT_ERROR, filename, 1);
	dup2(fd, 0);
	close(fd);
}

void	handle_outredirection(char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		exec_error_manager(PROMPT_ERROR, filename, 1);
	dup2(fd, 1);
	close(fd);
}

void	handle_append(char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		exec_error_manager(PROMPT_ERROR, filename, 1);
	dup2(fd, 1);
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
	{
		type = ((t_token *)(redirect->content))->type;
		value = ((t_token *)(redirect->content))->value;
		exp_value = ((t_token *)(redirect->content))->exp_value;
		if (((t_token *)(redirect->content))->is_ambiguous == TRUE)
			custom_error_manager(PROMPT_ERROR, value, "ambiguous redirect", 1);
		if (type == INREDIRECTION)
			handle_inredirection(exp_value);
		else if (type == OUTREDIRECTION)
			handle_outredirection(exp_value);
		else if (type == APPEND)
			handle_append(exp_value);
		redirect = redirect->next;
	}
}
