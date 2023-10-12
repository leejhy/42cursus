
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	if (!str)
		return (NULL);
	while (i < len && *(s + start + i))
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char str[] = "123456789";
	printf("%s\n",ft_substr(str, 3,3));//456
	printf("%s\n",ft_substr("", 3,3));//456
	printf("%s\n",ft_substr(NULL, 3,3));//456
	printf("%s\n",ft_substr(str, 1,100));//
}
