/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/03 14:36:08 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	is_empty_line(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_isspace(str[idx]))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}


t_cmd	*get_cmd(t_list	**tokens)
{
	t_cmd	*cmd;
	t_list	*node;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	while ((*tokens) != NULL && ((t_token *)((*tokens)->content))->type != PIPE)
	{
		node = ft_tokenlistdup((*tokens));
		if (node == NULL)
			return (NULL);
		if (((t_token *)((*tokens)->content))->type == SIMPLECMD)
			ft_lstadd_back(&(cmd->simple_cmd), node);
		else if (((t_token *)((*tokens)->content))->type != SIMPLECMD)
			ft_lstadd_back(&(cmd->redirect), node);
		(*tokens) = (*tokens)->next;
	}
	if ((*tokens) != NULL)
		cmd->next_pipe = TRUE;
	return (cmd);
}

t_list	*get_cmds(t_list *tokens)
{
	t_cmd	*cmd;
	t_list	*res;
	t_list	*node;

	res = NULL;
	while (tokens != NULL)
	{
		cmd = get_cmd(&tokens);
		if (cmd == NULL)
			return (NULL);
		node = ft_lstnew(cmd);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&res, node);
		if (tokens != NULL)
			tokens = tokens->next;
	}
	return (res);
}

void	print_cmds(t_list *cmds)
{
	int	iter;

	iter = 1;
	while (cmds != NULL)
	{
		printf("---%dth cmd---\n", iter);
		printf("===redirection===\n");
		print_node(((t_cmd *)cmds->content)->redirect);
		printf("=================\n");
		printf("===simplecmds====\n");
		print_node(((t_cmd *)cmds->content)->simple_cmd);
		printf("=================\n");
		iter++;
		cmds = cmds->next;
	}
}

t_list	*parsing(char *str, t_list *env, char *prompt)
{
	t_list	*tokens;
	t_list	*cmds;

	if (str == NULL || is_empty_line(str))
		return (NULL);
	tokens = tokenize(str, FALSE);
	if (!is_valid_syntax(tokens))
	{
		ft_lstclear(&tokens, token_free);
		return (print_error(prompt, "syntax error\n"));
	}
	tokens = merge_oper_simplecmd(tokens);
	if (expansion(tokens, env) == FALSE)
		return (print_error(prompt, "malloc error1"));
	print_node(tokens);
	tokens = re_tokenize(tokens);
	if (tokens == NULL)
		return (print_error(prompt, "malloc error2"));
	remove_quote_in_tokens(tokens);
	check_ambigious(tokens, env);
	cmds = get_cmds(tokens);
	// ft_lstclear(&tokens, token_free);
	print_cmds(cmds);
	// ft_lstclear(&((t_cmd *)cmds->content)->redirect, token_free);
	// ft_lstclear(&((t_cmd *)cmds->content)->simple_cmd, token_free);
	// printf("type :: %d\n", ((t_token *)(((t_cmd *)(cmds->content))->redirect->content))->type);
	// ft_lstclear(&cmds, free);
	// return (NULL);
	return (cmds);
}
