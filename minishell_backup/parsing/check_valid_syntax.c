/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/31 05:30:06 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	is_valid_syntax(t_list *tokens)
{
	if (tokens == NULL || ((t_token *)tokens->content)->type == PIPE)
		return (FALSE);
	while (tokens != NULL)
	{
		if ((((t_token *)tokens->content)->type == INREDIRECTION || \
			((t_token *)tokens->content)->type == OUTREDIRECTION || \
			((t_token *)tokens->content)->type == HEREDOC || \
			((t_token *)tokens->content)->type == APPEND))
		{
			if (tokens->next == NULL)
				return (FALSE);
			if ((((t_token *)tokens->next->content)->type != SIMPLECMD))
				return (FALSE);
			tokens = tokens->next;
		}
		else if (((t_token *)tokens->content)->type == ERROR)
			return (FALSE);
		else if (((t_token *)tokens->content)->type == SIMPLECMD || \
				(((t_token *)tokens->content)->type == PIPE && \
					tokens->next != NULL))
			tokens = tokens->next;
		else
			return (FALSE);
	}
	return (TRUE);
}
