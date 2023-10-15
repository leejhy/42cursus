/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:38:09 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 16:00:16 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && *(s + len))
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_length;
	size_t	i;

	i = 0;
	s_length = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	// if (!s)//s 널처리
	// 	return (NULL);
	if (s_length <= start)
		return (NULL);
	while (s && i < len && *(s + start + i))
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	if (!*str)
		return (NULL);
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "012345";
// 	printf("%s\n",ft_substr(str, 0,100));//345
// 	printf("%s\n",ft_substr(str, 0,1));//345
// 	printf("%s\n",ft_substr("", 0,1));
// 	printf("%s\n",ft_substr(NULL, 23,0));//456
// 	printf("%s\n",ft_substr(str, 20,100));//
// }
