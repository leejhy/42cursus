/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/07 10:00:11 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

int	get_close_quote_idx(char *str, int last_idx, char c)
{
	last_idx++;
	while (str[last_idx])
	{
		if (str[last_idx] == c)
			break ;
		last_idx++;
	}
	return (last_idx);
}

int	get_last_simplecmd_idx(char *str, int *idx, int re_token)
{
	int	last_idx;

	last_idx = *idx;
	while (str[last_idx])
	{
		if (str[last_idx] == '\'' || str[last_idx] == '\"')
			last_idx = get_close_quote_idx(str, last_idx, str[last_idx]);
		else if (ft_isspace(str[last_idx]) || \
			(re_token == FALSE && ft_strchr("<|>", str[last_idx]) != NULL))
			break ;
		if (str[last_idx] == '\0')
		{
			*idx = last_idx;
			return (-1);
		}
		last_idx++;
	}
	*idx = last_idx;
	return (last_idx);
}

void	token_free(void	*ptr)
{
	free(((t_token *)ptr)->value);
	free(((t_token *)ptr)->exp_value);
	free(ptr);
}

t_list	*ft_tokenlistdup(t_list *node)
{
	t_token	*res_token;
	t_list	*res;

	res_token = ft_calloc(1, sizeof(t_token));
	if (res_token == NULL)
		return (NULL);
	res_token->type = ((t_token *)node->content)->type;
	res_token->is_ambiguous = ((t_token *)node->content)->is_ambiguous;
	if (((t_token *)node->content)->value != NULL)
	{
		res_token->value = ft_strdup(((t_token *)node->content)->value);
		if (res_token->value == NULL)
			return (NULL);
	}
	if (((t_token *)node->content)->exp_value != NULL)
	{
		res_token->exp_value = ft_strdup(((t_token *)node->content)->exp_value);
		if (res_token->exp_value == NULL)
			return (NULL);
	}
	res = ft_lstnew(res_token);
	if (res == NULL)
		return (NULL);
	return (res);
}

void	print_node(t_list *tokens)
{
	t_token	*tok;

	while (tokens != NULL)
	{
		tok = tokens->content;
		if (tok->type == ERROR)
			printf("ERROR TOKEN : [%s] [%s] [%d]\n", tok->value, tok->exp_value, tok->is_ambiguous);
		if (tok->type == INREDIRECTION)
			printf("INREDIRECTION : [%s] [%s] [%d]\n", tok->value, tok->exp_value, tok->is_ambiguous);
		if (tok->type == OUTREDIRECTION)
			printf("OUTREDIRECTION : [%s] [%s] [%d]\n", tok->value, tok->exp_value, tok->is_ambiguous);
		if (tok->type == HEREDOC)
			printf("HEREDOC : [%s] [%s] [%d]\n", tok->value, tok->exp_value, tok->is_ambiguous);
		if (tok->type == APPEND)
			printf("APPEND : [%s] [%s] [%d]\n", tok->value, tok->exp_value, tok->is_ambiguous);
		if (tok->type == PIPE)
			printf("PIPE : [%s] [%s] [%d]\n", tok->value, tok->exp_value, tok->is_ambiguous);
		if (tok->type == SIMPLECMD)
			printf("SIMPLECMD : [%s] [%s] [%d]\n", tok->value, tok->exp_value, tok->is_ambiguous);
		tokens = tokens->next;
	}
}
