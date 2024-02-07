/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:12:03 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/02 22:16:00 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"


void	handle_inredirection(t_token *token)
{

}

void	handle_outredirection(t_token *token)
{

}

void	handle_append(t_token *token)
{

}

void	handle_redirection(t_list *parsed)
{//자식 프로세스 내에서 작동한다고 판단
	// ((t_token *)(parsed->content))
	t_list	*temp;

	temp = parsed;
	while (temp)
	{
		if (((t_token *)(parsed->content))->type == INREDIRECTION)
			handle_inredirection(((t_token *)(parsed->content)));
		if (((t_token *)(parsed->content))->type == OUTREDIRECTION)
			handle_outredirection(((t_token *)(parsed->content)));
		if (((t_token *)(parsed->content))->type == APPEND)
			handle_append(((t_token *)(parsed->content)));
		temp = temp->next;
	}
}