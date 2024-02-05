/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:55:40 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/05 22:12:20 by junhylee         ###   ########.fr       */
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
	int		prev_pipe[2];
}	t_info;
//executing
void	start_execute(t_list *cmds, t_list *env);
void	child_prc(t_info *info, int *pipe_fd, char **exe_argv);
//execute_utils.c
pid_t	fork_pid(void);
int	cnt_simplecmd(t_list *cmd);
char	**make_exe_argv(t_list *cmd, t_list *env);
char	**make_exe_envp(t_list *env);
//execve_cmd.c
char	*cat_path(char *cmd, t_list *env);
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