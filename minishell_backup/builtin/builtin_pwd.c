/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 21:21:13 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	builtin_pwd(int argc, char **argv, t_list *env, char *prompt)
{
	t_list	*pwd;
	char	*pwd_ptr;

	pwd_ptr = getcwd(NULL, 0);
	pwd = get_list_env("PWD", env);
	if (pwd_ptr != NULL)
	{
		ft_putstr_fd(pwd, 1);
	}
	else if (pwd != NULL)
	{
		ft_putstr_fd(((t_env *)pwd->content)->value, 1);
	}
	ft_putchar_fd('\n', 1);
	free(pwd_ptr);
	return (0);
}
