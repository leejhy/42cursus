/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:55:40 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/06 20:45:16 by junhylee         ###   ########.fr       */
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

typedef struct s_pipe
{
	int		prev_pipe[2];
	char	**exe_envp;
	char	**exe_argv;
}	t_pipe;

//executing
void	start_execute(t_info *info);
void	parent_prc(t_pipe *vars);
// void	parent_prc(void);
void	child_prc(t_info *info, t_pipe *vars, int *pipe_fd);

//execute_utils.c
pid_t	fork_pid(void);
int	cnt_simplecmd(t_list *cmd);
char	**make_exe_argv(t_list *cmd, t_list *env);
char	**make_exe_envp(t_list *env);
//execve_cmd.c
char	*find_path(char *cmd, t_list *env);
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
//init_struct.c
t_info	*init_info(void);
t_pipe	*init_vars(void);
//
void	ft_test(t_list *cmds);

#endif