/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/11 21:23:46 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	builtin_pwd(t_list *env)
{
	t_list	*pwd;
	char	*pwd_ptr;

	pwd_ptr = getcwd(NULL, 0);
	pwd = get_list_env("PWD", env);
	if (pwd != NULL)
	{
		ft_putstr_fd(((t_env *)pwd->content)->value, 1);
	}
	else if (pwd_ptr != NULL)
	{
		ft_putstr_fd(pwd_ptr, 1);
	}
	ft_putchar_fd('\n', 1);
	free(pwd_ptr);
	return (0);
}
