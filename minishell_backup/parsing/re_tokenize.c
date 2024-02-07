/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/01 21:39:13 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	remove_quote(char *str)
{
	const int	size = ft_strlen(str);
	int			idx;
	int			end;

	idx = 0;
	end = 0;
	while (str[idx])
	{
		if (str[idx] == '\'' || str[idx] == '\"')
		{
			end = get_close_quote_idx(str, idx, str[idx]);
			ft_strlcpy(&str[end], &str[end + 1], size);
			ft_strlcpy(&str[idx], &str[idx + 1], size);
			idx = end - 1;
		}
		else
			idx++;
	}
}


void	remove_quote_in_tokens(t_list *tokens)
{
	t_list	*curr;

	curr = tokens;
	while (curr != NULL)
	{
		if (((t_token *)curr->content)->type != PIPE)
		{
			remove_quote(((t_token *)curr->content)->exp_value);
		}
		curr = curr->next;
	}
}

void	move_value(t_list *tokens_tmp)
{
	while (tokens_tmp)
	{
		((t_token *)tokens_tmp->content)->exp_value = \
			((t_token *)tokens_tmp->content)->value;
		((t_token *)tokens_tmp->content)->value = NULL;
		tokens_tmp = tokens_tmp->next;
	}
}

t_list	*re_tokenize(t_list *tokens)
{
	t_list	*re_tokens;
	t_list	*tokens_tmp;
	t_list	*curr;

	curr = tokens;
	re_tokens = NULL;
	while (curr != NULL)
	{
		if (((t_token *)curr->content)->type == SIMPLECMD && \
		(((t_token *)curr->content)->exp_value)[0] != '\0')
			tokens_tmp = tokenize(((t_token *)curr->content)->exp_value, TRUE);
		else
			tokens_tmp = ft_tokenlistdup(curr);
		if (tokens_tmp == NULL)
			return (NULL);
		if (((t_token *)curr->content)->type == SIMPLECMD && \
			(((t_token *)curr->content)->exp_value)[0] != '\0')
			move_value(tokens_tmp);
		ft_lstadd_back(&re_tokens, tokens_tmp);
		curr = curr->next;
	}
	ft_lstclear(&tokens, token_free);
	return (re_tokens);
}
