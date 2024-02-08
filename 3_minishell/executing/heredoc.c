/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:05:06 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/07 13:31:26 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

char	*make_heredoc_name(int nb, t_list **here_doc_filenames)
{
	char	*doc_name;
	char	*tmp_name;
	char	*number;
	t_list	*node;

	number = ft_itoa(nb);
	if (number == NULL)
		return (NULL);
	doc_name = ft_strjoin("/tmp/.here_doc", number);
	free(number);
	while (access(doc_name, F_OK) == 0)
	{
		tmp_name = ft_strjoin(doc_name, "_tmp");
		free(doc_name);
		if (tmp_name == NULL)
			return (NULL);
		doc_name = tmp_name;
	}
	if (doc_name == NULL)
		return (NULL);
	node = ft_lstnew(doc_name);
	if (node == NULL)
		return (NULL);
	ft_lstadd_back(here_doc_filenames, node);
	return (doc_name);
}

void	max_heredoc_handle(t_list *cmds)
{
	t_list	*temp;
	int		cnt;

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
		ft_putendl_fd("minishell: maximum here-document count exceeded", 2);
		exit(2);
	}
}

void	here_doc_signal(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		exit(1);
	}
}

void	read_heredoc(char *doc_name, t_list *redirect, int fd)
{
	char	*input;
	char	*deli;

	rl_catch_signals = 1;
	signal(SIGINT, here_doc_signal);
	if (fd == -1)
		exec_error_manager(PROMPT_ERROR, doc_name, 1);
	deli = ((t_token *)redirect->content)->exp_value;
	while (1)
	{
		input = readline("> ");
		if (input == NULL || ft_strncmp(input, deli, ft_strlen(deli) + 1) == 0)
			break ;
		ft_putendl_fd(input, fd);
		free(input);
	}
	free(input);
	exit(0);
}

int	run_heredoc(t_list *redirect, t_list **here_doc_filenames, int doc_nb)
{
	char	*doc_name;
	pid_t	pid;
	int		status;
	int		fd;

	doc_name = make_heredoc_name(doc_nb, here_doc_filenames);
	if (doc_name == NULL)
		return (FALSE);
	fd = open(doc_name, O_TRUNC | O_CREAT | O_RDWR, 0666);
	pid = fork_pid();
	if (pid != 0)
		signal(SIGINT, SIG_IGN);
	if (pid == 0)
		read_heredoc(doc_name, redirect, fd);
	close(fd);
	waitpid(pid, &status, 0);
	g_last_exitcode = WEXITSTATUS(status);
	signal(SIGINT, signal_handle);
	((t_token *)redirect->content)->type = INREDIRECTION;
	free(((t_token *)redirect->content)->exp_value);
	((t_token *)redirect->content)->exp_value = doc_name;
	return (TRUE);
}

t_list	*handle_heredoc(t_list *cmds)
{
	t_list	*redirect;
	t_list	*here_doc_filenames;
	int		i;

	i = 0;
	here_doc_filenames = NULL;
	max_heredoc_handle(cmds);
	while (cmds != NULL)
	{
		redirect = ((t_cmd *)(cmds->content))->redirect;
		while (redirect != NULL)
		{
			if (g_last_exitcode != 1 && \
				((t_token *)(redirect->content))->type == HEREDOC)
				run_heredoc(redirect, &here_doc_filenames, i++);
			redirect = redirect->next;
		}
		cmds = cmds->next;
	}
	return (here_doc_filenames);
}
