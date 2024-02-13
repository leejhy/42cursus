/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/13 14:34:25 by tajeong          ###   ########.fr       */
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

t_list	*remove_empty_simplecmd(t_list *tokens)
{
	t_list	*temp;
	t_list	*res;
	t_list	*node;

	temp = tokens;
	res = NULL;
	while (tokens)
	{
		if (((t_token *)tokens->content)->type == SIMPLECMD && \
			((t_token *)tokens->content)->value != NULL && \
			ft_strlen(((t_token *)tokens->content)->exp_value) == 0)
		{
		}
		else
		{
			node = ft_tokenlistdup(tokens);
			ft_lstadd_back(&res, node);
		}
		tokens = tokens->next;
	}
	ft_lstclear(&temp, token_free);
	return (res);
}

t_list	*parsing(char *str, t_list *env)
{
	t_list	*tokens;
	t_list	*cmds;

	if (str == NULL || is_empty_line(str))
		return (NULL);
	tokens = tokenize(str, FALSE);
	if (!is_valid_syntax(tokens))
	{
		g_last_exitcode = 258;
		ft_lstclear(&tokens, token_free);
		return (print_error(PROMPT_ERROR, "syntax error\n"));
	}
	tokens = merge_oper_simplecmd(tokens);
	if (expansion(tokens, env) == FALSE)
		return (print_error(PROMPT_ERROR, "malloc error1"));
	tokens = re_tokenize(tokens);
	remove_quote_in_tokens(tokens);
	check_ambigious(tokens, env);
	tokens = remove_empty_simplecmd(tokens);
	cmds = get_cmds(tokens);
	if (tokens != NULL)
		ft_lstclear(&tokens, token_free);
	return (cmds);
}
