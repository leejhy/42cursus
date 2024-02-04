/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:10:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/04 17:18:23 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	handle_inredirection(t_token *token)
{
	char	*filename;
	int		fd;

	filename = token->exp_value;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
		exit(errno);// 에러처리
	}
	dup2(fd, 0);//dup2해주고
	close(fd);
}

void	handle_outredirection(t_token *token)
{
	char	*filename;
	int		fd;
	
	filename = token->exp_value;
	fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
		exit(errno);// 에러처리
	}
	dup2(fd, 1);//dup2해주고
	close(fd);
}

void	handle_append(t_token *token)
{
	char	*filename;
	int		fd;

	filename = token->exp_value;
	fd = open(filename, O_WRONLY | O_CREAT);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
		exit(errno);// 에러처리
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
	if (cmd->next_pipe == TRUE)// 파이프 있는데 outredirection 없으면 파이프로 출력
		dup2(pipe_fd[1], 1);
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