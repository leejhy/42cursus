/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/13 15:09:13 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	not_home_manager(char **argv, t_list *env, char *prompt, int flag)
{
	t_list	*home;

	home = get_list_env("HOME", env);
	if (home == NULL)
	{
		if (flag == TRUE)
			builtin_perror_manager(prompt, argv[0], "HOME not set", NULL);
		return (1);
	}
	else if (((t_env *)home->content)->value[0] == '\0')
		return (0);
	else
		return (-1);
}

int	move_home(char **argv, t_list *env, char *prompt)
{
	t_list	*home;
	int		chdir_res;
	char	*oldpwd;
	char	*pwd;
	int		res;

	res = 0;
	if (not_home_manager(argv, env, prompt, FALSE) != -1)
		return (not_home_manager(argv, env, prompt, TRUE));
	home = get_list_env("HOME", env);
	oldpwd = getcwd(NULL, 0);
	chdir_res = chdir(((t_env *)home->content)->value);
	pwd = getcwd(NULL, 0);
	if (chdir_res == 0)
		change_pwd_oldpwd(env, oldpwd, pwd, prompt);
	else
	{
		builtin_perror_manager(prompt, argv[0], \
					((t_env *)home->content)->value, strerror(errno));
		res = 1;
	}
	free(oldpwd);
	free(pwd);
	return (res);
}
