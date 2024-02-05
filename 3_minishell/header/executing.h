/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:55:40 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/04 21:58:02 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H

#include "tokenize.h"

typedef struct s_info
{
	t_list	*cmds;
	t_list	*env;
	int		exitcode;
}	t_info;

//executing
void	start_execute(t_list *cmds, t_list *env);
//execute_utils.c
pid_t	fork_pid(void);
//heredoc.c
void	handle_heredoc(t_list *parsed);
void	run_heredoc(t_list *redirect, int doc_nb);
void	read_heredoc(char *doc_name, t_list *parsed);
int		cnt_heredoc(t_list *parsed);
char	*make_heredoc_name(int nb);
//redirect.c
void	handle_redirection(t_list *cmds, int *pipe_fd);
void	handle_inredirection(t_token *token);
void	handle_outredirection(t_token *token);
void	handle_append(t_token *token);
//
void	ft_test(t_list *cmds);

#endif