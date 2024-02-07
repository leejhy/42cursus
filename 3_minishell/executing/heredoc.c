/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:05:06 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/05 18:18:42 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

char	*make_heredoc_name(int nb)
{
	char	*doc_name;
	char	*doc_nb;

	if (nb < 10)
	{
		doc_nb = malloc(sizeof(char) * 2);//숫자 1개, 널
		doc_nb[0] = nb + '0';
		doc_nb[1] = '\0';
	}
	else
	{
		doc_nb = malloc(sizeof(char) * 3);
		doc_nb[0] = '1';
		doc_nb[1] = (nb % 10) + '0';
		doc_nb[2] = '\0';
	}
	// doc_name[i] = ft_strjoin("/tmp/here_doc", doc_nb);//i번째에 이름넣기
	doc_name = ft_strjoin("./here_doc/", doc_nb);//tmp로 바꾸기
	free(doc_nb);
	return (doc_name);
}

int	cnt_heredoc(t_list *cmds)
{
//((t_token *)(((t_cmd *)(cmds->content))->redirect->content))->type
//지금 얘는 한개의 파이프에 here_doc밖에 체크못함
	t_list *temp;
	int	cnt;

	cnt = 0;
	temp = NULL;
	while (cmds)
	{
		temp = ((t_cmd *)(cmds->content))->redirect;
		while (temp != NULL)
		{
			if (((t_token *)(temp->content))->type == HEREDOC)
				cnt++;
			temp = temp->next;
		}
		cmds = cmds->next;
	}
	if (cnt > 16)
	{
		write(2, "minishell: maximum here-document count exceeded\n", 48);
		exit(2);//16개 넘을 때 에러처리 exit code 2, env에 코드 itoa
	}
	return (cnt);
}

void	read_heredoc(char *doc_name, t_list *redirect, t_list *env)
{
	char	*input;
	char	*exp_input;
	char	*deli;
	int		fd;

	fd = open(doc_name, O_TRUNC | O_CREAT | O_RDWR, 0666);
	while (1)
	{
		deli = ((t_token *)redirect->content)->exp_value;
		// printf("delimiter : %s\n", deli);
		input = readline("> ");
		if (ft_strncmp(input, deli, ft_strlen(deli) + 1) == 0)
			break ;
		exp_input = expanse_input(env, input);
		if (exp_input == NULL)
		{//에러처리 생각
			write(2, "exp error\n", 10);
			exit(1);
		}
		ft_putendl_fd(exp_input, fd);
		free(input);
		free(exp_input);
	}
	close(fd);
	exit(0);
}

void	run_heredoc(t_list *redirect, t_list *env, int doc_nb)
{
	char	*doc_name;
	pid_t	pid;
	int		status;

	doc_name = make_heredoc_name(doc_nb);
	pid = fork_pid();
	if (pid == 0)//here_doc 자식에서 시그널 처리 필요
		read_heredoc(doc_name, redirect, env);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		((t_token *)redirect->content)->type = INREDIRECTION;
		((t_token *)redirect->content)->exp_value = doc_name;
		free(doc_name);
	}
}

void	handle_heredoc(t_list *cmds, t_list *env)
{
	// int		docs_cnt;
	t_list	*redirect;
	int		i;
	
	i = 0;
	// docs_cnt = cnt_heredoc(cmds);//이거 here document개수를 갖고 있을 필요가 있나?
	cnt_heredoc(cmds);//이거 here document개수를 갖고 있을 필요가 있나?
	while (cmds != NULL)
	{
		redirect = ((t_cmd *)(cmds->content))->redirect;
		while (redirect)
		{
			if (redirect && ((t_token *)(redirect->content))->type == HEREDOC)
				run_heredoc(redirect, env, i++);
			redirect = redirect->next; 
		}
		cmds = cmds->next;
	}
	// return (pipe_cnt);
}
