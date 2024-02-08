/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:10:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/08 13:54:50 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	handle_inredirection(t_token *token)
{
	char	*filename;
	int		fd;

	filename = token->exp_value;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		g_last_exitcode = errno;
		exit ((unsigned char)g_last_exitcode);
	}
	dup2(fd, 0);//dup2해주고
	close(fd);
}

void	handle_outredirection(t_token *token)
{
	char	*filename;
	int		fd;

	filename = token->exp_value;
	fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		g_last_exitcode = errno;
		exit ((unsigned char)g_last_exitcode);
	}
	dup2(fd, 1);//dup2해주고
	close(fd);
}

void	handle_append(t_token *token)
{
	char	*filename;
	int		fd;

	filename = token->exp_value;
	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		g_last_exitcode = errno;
		exit ((unsigned char)g_last_exitcode);
	}
	dup2(fd, 1);//dup2해주고
	close(fd);
}

void	handle_redirection(t_list *cmds, int *pipe_fd)
{//자식 프로세스 내에서 작동한다고 판단
//파이프도 받아와야함
	// ((t_token *)(parsed->content))
	t_list	*redirect;
	t_cmd	*cmd;

	redirect = ((t_cmd *)(cmds->content))->redirect;
	cmd = (t_cmd *)(cmds->content);
	while (redirect)
	{
		if (((t_token *)(cmds->content))->type == INREDIRECTION)
			handle_inredirection(((t_token *)(cmds->content)));
		else if (((t_token *)(cmds->content))->type == OUTREDIRECTION)
			handle_outredirection(((t_token *)(cmds->content)));
		else if (((t_token *)(cmds->content))->type == APPEND)
			handle_append(((t_token *)(cmds->content)));
		//else
			//??
		redirect = redirect->next;
	}
}
