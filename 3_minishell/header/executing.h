/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:55:40 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/13 15:01:43 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H
# include "type_header.h"
# include "include_header.h"
# include "builtin.h"
# include "tokenize.h"

void	signal_handle(int signo);

/* exec_builtin_check.c*/
int		exec_check_builtin(t_list *curr_cmd);
void	exec_run_built_in(t_cmd *cmd, t_list *env, char *cmd_name);

/* exec_builtin_exit.c */
int		exec_builtin_exit(int argc, char **argv, char *prompt);

/*  execute.c */
void	run_process(t_info *info);
void	run_execute(t_info *info);
void	parent_prc(t_info *info);
void	child_prc(t_info *info, t_list *curr_cmd);

/* execute_utils.c */
pid_t	fork_pid(void);
void	wait_prc(int prc_cnt, pid_t pid);
void	exec_cmd_check(char *str);

/* exe_vars.c */
char	**set_exe_argv(t_list *cmd, char *path_cmd, int cnt);
char	**make_exe_argv(t_list *cmd, t_list *env);
char	*get_path(t_list *env);
char	*find_path(char *cmd, t_list *env);
char	**make_exe_envp(t_list *env);

/* exe_vars_utils.c */
char	*cat_keyvalue(t_env *env);
void	slash_check(char *cmd);
char	*cat_path(char **path, char *cmd, size_t path_len);
int		env_cnt(t_list *env);
int		cnt_simplecmd(t_list *cmd);

/* heredoc.c */
t_list	*handle_heredoc(t_list *cmds, t_list *env);
int		run_heredoc(t_list *redirect, t_list **here_doc_filenames, \
					int doc_nb, t_list *env);
void	read_heredoc(char *doc_name, t_list *redirect, int fd, t_list *env);
void	max_heredoc_handle(t_list *cmds);
char	*make_heredoc_name(int nb, t_list **here_doc_filenames);

/* heredoc_utils.c */
void	here_doc_signal(int signo);
char	*expanse_input(t_list *env, char *input);
void	expansion_size(char *str, t_list *env, int *size);
void	expansion_simplecmd(char *str, char *res, int size, t_list *env);

/* redirect.c */
void	handle_redirection(t_list *cmds);
void	handle_inredirection(char *filename);
void	handle_outredirection(char *filename);
void	handle_append(char *filename);
void	handle_pipe(t_cmd *cmd, t_info *info);

/* error_manager.c */
void	*exec_error_manager(char *prompt, char *str, int exitcode);
void	*custom_error_manager(char *prompt, char *name, \
							char *message, int exitcode);
void	malloc_failed(void);

/* utils.c */
int		get_simple_cmd_cnt(t_list *simple_cmd);
char	**get_argv(t_list *simple_cmd);

/* one_builtin_process */
void	run_one_builtin(t_info *info);
int		check_one_builtin(t_info *info);

/* execute */
void	run_process(t_info *info);
#endif
