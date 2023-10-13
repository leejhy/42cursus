/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:38:02 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/12 19:38:03 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

static size_t ft_strlen(const char *s)
{
    int len;

    len = 0;
    while (s && *(s + len))//여기서 널처리
        len++;
    return (len);
}

static char	*ft_strcat(char *dest, char *src)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	i;

	i = 0;
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	while (i < src_length)
	{
		*(dest + dest_length + i) = *(src + i);
		i++;
	}
	*(dest + dest_length + i) = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	// if (!s1 || !s2)
	// 	return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	*str = '\0';
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);

	return (str);
}
#include <stdio.h>
int	main(void)
{
	printf("%s\n",ft_strjoin("abcd", "aaaa"));
	printf("%s\n",ft_strjoin("", "aaaa"));
	printf("%s\n",ft_strjoin("aaaa", ""));
	printf("%s\n",ft_strjoin("", ""));

	printf("%s\n",ft_strjoin("abc", NULL));
	printf("%s\n",ft_strjoin(NULL, "abc"));
	printf("%s\n",ft_strjoin(NULL, NULL));
}