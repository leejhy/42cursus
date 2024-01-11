#include "pipex.h"

int ft_strncmp(char *s1, char *s2, int n)//이거paco 확인
{
    int i = 0;

    while ((s1[i] && s2[i]) && i + 1 < n)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_get_path(char **envp)
{
	char	*str_path;
	size_t	i;

	i = 0;
	str_path = NULL;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
            str_path = envp[i];
			break ;
		}
        i++;
    }
	while(*str_path != '=')
		str_path++;
    str_path++;// '=' 이후 path들만 리턴
	return (str_path);
}

char	*ft_match_path(char *str_path, char *cmd)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	cmd_len;

	i = 0;
	len = 0;
	while (str_path[len] != ':')
		len++;
	cmd_len = ft_strlen(cmd);
	str = malloc(sizeof(char) * (len + cmd_len + 2));
	while (str_path[i] && i < len)
	{
		str[i] = str_path[i];
		i++;
	}
	if (str_path[i])
	{
		str[i] = '/';
		i++;
	}
	while (*cmd)
	{
		str[i] = *cmd;
		i++;
		cmd++;
	}
	str[i] = '\0';
	if (access(str, F_OK & X_OK) == 0)
		return(str);
	free(str);
	return (str_path + len + 1);
}

char	*ft_path_cmd(char *cmd, char **envp)
{
    char *str_path;
    char *match_path;
  
    str_path = ft_get_path(envp);//ok
	match_path = str_path;
	while (*match_path)
	{
		match_path = ft_match_path(match_path, cmd);
		if (*match_path && access(match_path, F_OK & X_OK) == 0)
			break ;
	}
	return (match_path);
	// execve(match_path, cmd, envp);
}