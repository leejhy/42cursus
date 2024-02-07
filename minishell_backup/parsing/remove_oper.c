/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/31 12:55:05 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_list	*get_merge_node(t_token	*oper, t_token *simplecmd)
{
	t_token	*res_token;
	t_list	*res;

	res_token = ft_calloc(1, sizeof(t_token));
	if (res_token == NULL)
		return (NULL);
	res_token->type = oper->type;
	res_token->value = ft_strdup(simplecmd->value);
	res_token->exp_value = NULL;
	if (res_token == NULL)
		return (NULL);
	res = ft_lstnew(res_token);
	if (res == NULL)
		return (NULL);
	return (res);
}

t_list	*merge_oper_simplecmd(t_list *tokens)
{
	t_list	*res;
	t_list	*curr;
	t_list	*node;

	curr = tokens;
	res = NULL;
	while (curr != NULL)
	{
		if (((t_token *)curr->content)->type == INREDIRECTION || \
			((t_token *)curr->content)->type == OUTREDIRECTION || \
			((t_token *)curr->content)->type == HEREDOC || \
			((t_token *)curr->content)->type == APPEND)
		{
			node = get_merge_node(curr->content, curr->next->content);
			curr = curr->next;
		}
		else
			node = ft_tokenlistdup(curr);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&res, node);
		curr = curr->next;
	}
	ft_lstclear(&tokens, token_free);
	return (res);
}
