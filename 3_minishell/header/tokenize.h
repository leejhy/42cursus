/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/03/15 14:10:20 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H
# include "type_header.h"
# include "include_header.h"

/* find_ambigous.c  */
void	check_ambigious(t_list *tokens, t_list *env);

/* remove_oper.c */
t_list	*merge_oper_simplecmd(t_list *tokens);

/* error_manager.c */
void	*parse_error_manager(char *prompt, char *str, int exitcode);
void	*print_error(char *prompt, char *str);

/* check_valid_syntax.c */
int		is_valid_syntax(t_list *tokens);

/* re_tokenize.c */
t_list	*re_tokenize(t_list *tokens);
void	remove_quote_in_tokens(t_list *tokens);

/* expansion.c */
int		expansion(t_list *tokens, t_list *env);
char	*get_env_str(char *str, t_list *env, int key_start, int key_end);
int		get_last_name_idx(char *str, int end);

/* parsing.c */
t_list	*parsing(char *str, t_list *env);



/* tokenize.c */
t_list	*tokenize(char *str, int re_token);

/* utils.c */
void	print_node(t_list *tokens);
int		ft_isspace(char c);
int		get_last_simplecmd_idx(char *str, int *idx, int re_token);
int		get_close_quote_idx(char *str, int last_idx, char c);
void	token_free(void	*ptr);
t_list	*ft_tokenlistdup(t_list *node);

#endif
