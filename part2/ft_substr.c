/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:38:09 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/12 19:38:33 by junhylee         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (!s)//s 널처리
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
	char str[] = "0123456789";
	printf("%s\n",ft_substr(str, 3,3));//345
	printf("%s\n",ft_substr("", 3,3));
	printf("%s\n",ft_substr(NULL, 3,3));//456
	printf("%s\n",ft_substr(str, 20,100));//
}
