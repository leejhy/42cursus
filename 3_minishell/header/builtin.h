/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 21:46:54 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "include_header.h"
# include "type_header.h"

/* builtin_cd.c */
int		builtin_cd(int argc, char **argv, t_list *env, char *prompt);

/* builtin_echo */
int		builtin_echo(int argc, char **argv);

/* builtin_env.c */
int		builtin_env(int argc, char **argv, t_list *env, char *prompt);

/* builtin_exit.c */
int		builtin_exit(int argc, char **argv, char *prompt);

/* builtin_export.c */
int		builtin_export(int argc, char **argv, t_list *env, char *prompt);

/* builtin_pwd.c */
int		builtin_pwd(int argc, char **argv, t_list *env, char *prompt);

/* builtin_unset.c */
int		builtin_unset(int argc, char **argv, t_list *env, char *prompt);

/* builtin_utils.c */
void	builtin_perror_manager(\
		char *_prompt, char *_cmd, char *_argument, char *_strerror);
void	builtin_env_error_message(\
		char *_prompt, char *_cmd, char *_argument, char *_strerror);
int		is_valid_identifier(char *str);
t_list	*get_list_env(char *key, t_list *env);
char	**make_argv(char *key, char *argv1);

#endif
