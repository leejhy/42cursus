#include <unistd.h>
#include <stdio.h>

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
    size_t  len;

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

char	*ft_match_path(char *str_path)
{
	size_t	len;

	len = 0;
	printf("%s\n", str_path);
	while (str_path[len] != ':')
		len++;
}

int main(int argc, char **argv, char **envp)
{
    char *str;
    
    str = ft_get_path(envp);
    printf("%s\n", str);
}