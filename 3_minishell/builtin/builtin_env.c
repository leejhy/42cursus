/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 18:10:08 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	builtin_env(int argc, char **argv, t_list *env, char *prompt)
{
	argc = 0;
	argv = NULL;
	prompt = NULL;
	env = env->next;
	while (env != NULL)
	{
		if (((t_env *)env->content)->value_null == FALSE)
		{
			ft_putstr_fd(((t_env *)env->content)->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(((t_env *)env->content)->value, 1);
			ft_putchar_fd('\n', 1);
		}
		env = env->next;
	}
	return (0);
}
