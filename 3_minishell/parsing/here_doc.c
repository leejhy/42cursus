/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:05:06 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/02 21:51:47 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

char	*make_doc_name(int nb)
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

pid_t	fork_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);//에러처리
	return (pid);
}

int	cnt_docs(t_list *parsed)
{//t_list parsed->content->type == HEREDOC
	t_list *temp;
	int	cnt;
	
	cnt = 0;
	temp = parsed;
	while (temp != NULL)
	{
		if (((t_token *)(temp->content))->type == HEREDOC)
			cnt++;
		temp = temp->next;
	}
	printf("heredoc cnt = %d\n", cnt);
	if (cnt > 16)
	{
		printf("minishell: maximum here-document count exceeded\n");
		exit(2);//16개 넘을 때 에러처리 exit code 2, env에 코드 itoa
	}
	return (cnt);
}

void	heredoc_read(char *doc_name, t_list *parsed)
{
	char	*input;
	char	*deli;
	int		fd;

	fd = open(doc_name, O_TRUNC | O_CREAT | O_RDWR, 0666);
	while (1)
	{
		deli = ((t_token *)parsed->content)->exp_value;
		printf("delimiter : %s\n", deli);
		input = readline("> ");
		if (strncmp(input, deli, ft_strlen(deli) + 1) == 0)
			break ;
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
	}
	//t_cmd->redirect->HEREDOC을 INREDIRECT로 바꾸기
	close(fd);
	exit(0);//pid == 0부터 여기까지 함수로 만들기
}

void	run_heredoc(t_list *parsed)
{
	char	*doc_name;
	pid_t	pid;
	int		docs_cnt;
	int		status;
	int		i;
	// ((t_token *)tokens->content)->exp_value 값이 heredoc의 delimiter
	i = 0;
	// docs_cnt = cnt_docs(parsed);
	docs_cnt = cnt_docs(parsed);//이거 here document개수를 갖고 있을 필요가 있나?
	while (parsed != NULL)
	{
		if (((t_token *)parsed->content)->type == HEREDOC)
		{
			doc_name = make_doc_name(i);
			i++;
			pid = fork_pid();
			if (pid == 0)//here_doc 자식에서 시그널 처리 필요
				heredoc_read(doc_name, parsed);
			else if (pid > 0)
			{
				waitpid(pid, &status, 0);
				((t_token *)parsed->content)->type = INREDIRECTION;
				((t_token *)parsed->content)->exp_value = doc_name;
				free(doc_name);
			}
		}
		parsed = parsed->next;
	}
}
