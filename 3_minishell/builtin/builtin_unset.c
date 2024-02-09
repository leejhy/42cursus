/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/08 16:03:01 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	free_env(void *env)
{
	free(((t_env *)env)->key);
	free(((t_env *)env)->value);
	free(((t_env *)env));
}

static void	remove_env(t_list *env_start, t_list *del_node)
{
	t_list	*prev;

	prev = env_start;
	while (prev->next != del_node)
		prev = prev->next;
	prev->next = del_node->next;
	del_node->next = NULL;
	ft_lstdelone(del_node, free_env);
}

int	builtin_unset(int argc, char **argv, t_list *env, char *prompt)
{
	int	idx;
	int	exitcode;

	idx = 1;
	exitcode = 0;
	while (idx < argc)
	{
		if (is_valid_identifier(argv[idx]))
		{
			if (get_list_env(argv[idx], env) != NULL)
				remove_env(env, get_list_env(argv[idx], env));
		}
		else
		{
			builtin_env_error_message(prompt, argv[0], \
					argv[idx], "not a valid identifier");
			exitcode = 1;
		}
		idx++;
	}
	return (exitcode);
}
