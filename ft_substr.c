/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:38:09 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/17 22:12:46 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
    }
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*(s + start + i) && i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

int	main(void)
{
	printf("%s\n",ft_substr("",1,1));
}
// ft_substr("", 1, 1): Bus error
// /* 2 */ mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();
// MKO 28: 	/* 6 */ mcheck(s, 1); free(s); showLeaks();