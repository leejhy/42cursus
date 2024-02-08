/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:55:40 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/07 15:55:27 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H
# include "type_header.h"
# include "include_header.h"
# include "builtin.h"

/*  executing */
void	start_execute(t_list *parsed, char **envp);

/* execute_utils.c */
pid_t	fork_pid(void);

/* heredoc.c */
t_list	*handle_heredoc(t_list *cmds);

/* redirect.c */
void	handle_redirection(t_list *cmds, int *pipe_fd);
void	handle_inredirection(t_token *token);
void	handle_outredirection(t_token *token);
void	handle_append(t_token *token);

/* redirect.c */
void	ft_test(t_list *cmds);

/* error_manager.c */
void	*exec_error_manager(char *prompt, char *str, int exitcode);

void	signal_handle(int signo);

/* utils.c */
int		get_simple_cmd_cnt(t_list *simple_cmd);
char	**get_argv(t_list *simple_cmd);

/* one_builtin_process */
void	run_one_builtin(t_info *info);
int		check_one_builtin(t_info *info);

/* execute */
void	run_process(t_info *info);
#endif
