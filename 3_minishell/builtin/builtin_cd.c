/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/13 14:59:46 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	change_pwd_oldpwd(t_list *env, char *oldpwd_value, \
						char *pwd_value, char *prompt)
{
	char	**argv;

	if (env == NULL)
		return ;
	if (oldpwd_value)
	{
		argv = make_argv("OLDPWD=", oldpwd_value);
		builtin_export(2, argv, env, prompt);
		free(argv[0]);
		free(argv[1]);
		free(argv);
	}
	if (pwd_value)
	{
		argv = make_argv("PWD=", pwd_value);
		builtin_export(2, argv, env, prompt);
		free(argv[0]);
		free(argv[1]);
		free(argv);
	}
}

void	no_dir_handler(char **argv, t_list *env, char *prompt)
{
	t_list		*pwd_env;
	char		*pwd;

	ft_putendl_fd("cd: error retrieving current directory:\
	getcwd: cannot access parent directories: No such file or directory", 2);
	pwd_env = get_list_env("PWD", env);
	if (pwd_env != NULL)
	{
		if (!ft_strncmp("..", argv[1], 3))
			pwd = ft_strjoin(((t_env *)pwd_env->content)->value, "/..");
		if (!ft_strncmp(".", argv[1], 2))
			pwd = ft_strjoin(((t_env *)pwd_env->content)->value, "/.");
		if (!ft_strncmp("../", argv[1], 4))
			pwd = ft_strjoin(((t_env *)pwd_env->content)->value, "/../");
		if (!ft_strncmp("./", argv[1], 3))
			pwd = ft_strjoin(((t_env *)pwd_env->content)->value, "/./");
		change_pwd_oldpwd(env, NULL, pwd, prompt);
		free(pwd);
	}
}

int	cd_error_manager(char **argv, t_list *env, char *prompt)
{
	char		*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		no_dir_handler(argv, env, prompt);
		return (0);
	}
	else
	{
		free(pwd);
		builtin_perror_manager(prompt, argv[0], argv[1], strerror(errno));
		return (1);
	}
}

int	builtin_cd(int argc, char **argv, t_list *env, char *prompt)
{
	int		chdir_res;
	char	*prev_dir;
	char	*curr_dir;

	if (argc == 1)
		return (move_home(argv, env, prompt));
	prev_dir = getcwd(NULL, 0);
	chdir_res = chdir(argv[1]);
	curr_dir = getcwd(NULL, 0);
	if (curr_dir != NULL && chdir_res == 0)
	{
		change_pwd_oldpwd(env, prev_dir, curr_dir, prompt);
	}
	else
	{
		free(prev_dir);
		free(curr_dir);
		return (cd_error_manager(argv, env, prompt));
	}
	free(prev_dir);
	free(curr_dir);
	return (0);
}
