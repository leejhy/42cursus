/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:26:58 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/09 20:49:11 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

char	**set_exe_argv(t_list *cmd, char *path_cmd, int cnt)
{
	t_list	*tmp_lst;
	char	**exe_argv;
	int		i;

	i = 0;
	tmp_lst = cmd;
	exe_argv = malloc(sizeof(char *) * (cnt + 1));
	//if (exe_argv == NULL)
	while (path_cmd && tmp_lst)
	{
		exe_argv[i] = ((t_token *)(tmp_lst->content))->exp_value;
		i++;
		tmp_lst = tmp_lst->next;
	}
	exe_argv[i] = NULL;
	return (exe_argv);
}

char	**make_exe_argv(t_list *cmd, t_list *env)
{
	t_list	*tmp_lst;
	char	**exe_argv;
	char	*path_cmd;
	int		cnt;

	tmp_lst = cmd;
	// if (tmp_lst == NULL)//여기까지 들어오기 전에 처리해야함
	// 	exit (1);//얘때문에 redirection만 들어왔을때 exit코드 1로 찍힘 수정수정수정
	//얘때문에 redirection만 들어왔을때 exit코드 1로 찍힘 수정수정수정
	while (tmp_lst && ((t_token *)(tmp_lst->content))->exp_value[0] == '\0')
		tmp_lst = tmp_lst->next;
	cnt = cnt_simplecmd(tmp_lst);
	path_cmd = find_path(((t_token *)(tmp_lst->content))->exp_value, env);
	if (path_cmd != 0)
	{
		free(((t_token *)(cmd->content))->exp_value);
		((t_token *)(cmd->content))->exp_value = path_cmd;
	}
	exe_argv = set_exe_argv(tmp_lst, path_cmd, cnt);
	return (exe_argv);
}

char	*get_path(t_list *env)
{
	t_env	*temp_env;
	char	*path;

	path = NULL;
	while (env)
	{
		temp_env = (t_env *)(env->content);
		if (ft_strncmp(temp_env->key, "PATH", 5) == 0)
		{
			path = temp_env->value;
			break ;
		}
		env = env->next;
	}
	return (path);
}

char	*find_path(char *cmd, t_list *env)
{
	char	*path;
	char	*path_cmd;
	size_t	len;

	path = NULL;
	path = get_path(env);
	slash_check(cmd);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (*path)
	{
		len = 0;
		while (path[len] && path[len] != ':')
			len++;
		path_cmd = cat_path(&path, cmd, len);
		if (access(path_cmd, X_OK) == 0)
			return (path_cmd);
		if (*path != '\0')
			path++;
	}
	// if (access(cmd, F_OK) == -1)
	// {
	// 	write(2, "acc\n", 4);
	// 	exec_error_manager(PROMPT_ERROR, cmd, 127);
	// }
	return (0);
}

char	**make_exe_envp(t_list *env)
{
	t_env	*one_env;
	int		i;
	int		cnt;
	char	*temp_envp;
	char	**exe_envp;

	i = 0;
	cnt = env_cnt(env);
	exe_envp = ft_calloc((cnt + 1), sizeof(char *));
	env = env->next;
	while (env)
	{
		if (((t_env *)(env->content))->value_null == TRUE)
		{
			env = env->next;
			continue ;
		}
		one_env = (t_env *)(env->content);
		temp_envp = cat_keyvalue(one_env);
		exe_envp[i] = temp_envp;
		i++;
		env = env->next;
	}
	return (exe_envp);//얘는 싹 free해야함
}