/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/01 18:19:52 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_list	*get_error_token(void)
{
	t_list	*node;
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = ERROR;
	token->value = NULL;
	node = ft_lstnew(token);
	if (node == NULL)
		return (NULL);
	return (node);
}

t_list	*get_simplecmd_token(char *str, int *idx, int re_token)
{
	t_list	*node;
	t_token	*token;
	int		start;
	int		end;

	token = ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		return (NULL);
	start = *idx;
	end = get_last_simplecmd_idx(str, idx, re_token);
	if (end == -1)
		return (get_error_token());
	token->type = SIMPLECMD;
	token->value = ft_substr(str, start, end - start);
	token->exp_value = NULL;
	if (token->value == NULL)
		return (NULL);
	node = ft_lstnew(token);
	if (node == NULL)
		return (NULL);
	return (node);
}

t_list	*get_operation_token(char *str, int *idx, char c)
{
	t_list	*node;
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		return (NULL);
	if (c != '|' && str[*idx] == str[*idx + 1] && c == '<')
		token->type = HEREDOC;
	else if (c != '|' && str[*idx] == str[*idx + 1] && c == '>')
		token->type = APPEND;
	else if (c == '<')
		token->type = INREDIRECTION;
	else if (c == '>')
		token->type = OUTREDIRECTION;
	else if (c == '|')
		token->type = PIPE;
	token->value = NULL;
	token->exp_value = NULL;
	if (c != '|' && str[*idx] == str[*idx + 1])
		(*idx)++;
	(*idx)++;
	node = ft_lstnew(token);
	if (node == NULL)
		return (NULL);
	return (node);
}

t_list	*tokenize(char *str, int re_token)
{
	t_list	*res;
	t_list	*node;
	int		idx;

	res = NULL;
	idx = 0;
	while (str && str[idx])
	{
		if (ft_isspace(str[idx]))
		{
			idx++;
			continue ;
		}
		else if (re_token == FALSE && \
				(str[idx] == '<' || str[idx] == '>' || str[idx] == '|'))
			node = get_operation_token(str, &idx, str[idx]);
		else if (!ft_isspace(str[idx]) || \
				(re_token == TRUE && ft_strchr("<|>", str[idx]) != NULL))
			node = get_simplecmd_token(str, &idx, re_token);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&res, node);
	}
	return (res);
}
