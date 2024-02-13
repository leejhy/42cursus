/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/13 15:01:57 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "tokenize.h"
# include "builtin.h"
# include "include_header.h"
# include "type_header.h"
# include "executing.h"

/* shell_process.c */
void	remove_here_doc_files(t_list *here_doc_files);
void	clear_cmd(void *cmd);
void	do_process(t_info *info);
void	all_process(t_info *info);
void	loop_shell(t_list *env);

/* shell_process_utils.c */
int		is_str_empty(char *str);
void	ctrl_d(void);
void	init_minishell(void);

/* init_env.c */
t_env	*get_env_1(char *envp);
t_list	*add_env_manual(t_list *env, char *key, char *value, int value_null);
t_list	*get_env_list(char **envp);
#endif
