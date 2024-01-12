#include "pipex.h"

// int	ft_strncmp(char *s1, char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (n <= 0)
// 		return (0);
// 	while ((s1[i] && s2[i]) && i + 1 < n)
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (s1[i] - s2[i]);
// }


// char	*ft_get_path(char **envp)
// {
// 	char	*str_path;
// 	size_t	i;

// 	i = 0;
// 	str_path = NULL;
// 	while (envp[i])
// 	{
// 		if (ft_strncmp(envp[i], "PATH", 4) == 0)
// 		{
// 			str_path = envp[i];
// 			break ;
// 		}
// 		i++;
// 	}
// 	while (*str_path != '=')
// 		str_path++;
// 	str_path++;
// 	return (str_path);
// }

int	main(int argc, char **argv, char **envp)
{
	if (argc > 2000000)
		return (0);
	char	*path;

	path = ft_get_path(envp);
	while (*path)
	{
		printf("%c", *path);
		path++;
	}
}
