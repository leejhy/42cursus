/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:49:22 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/13 18:38:28 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	here_doc_signal(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		exit(1);
	}
}

char	*expanse_input(t_list *env, char *input)
{
	int		size;
	char	*exp_input;

	size = 0;
	expansion_size(input, env, &size);
	exp_input = ft_calloc(size + 1, sizeof(char));
	if (exp_input == NULL)
		return (FALSE);
	expansion_simplecmd(input, exp_input, size, env);
	return (exp_input);
}
