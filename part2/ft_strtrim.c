/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:38:05 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 15:43:51 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
#include "../libft.h"

int	is_in(char s, const char *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *(s + len))
		len++;
	return (len);
}

static size_t	ft_back(char *s1, char const *set)
{
	size_t	back;

	back = ft_strlen(s1) - 1;
	while (is_in(*(s1 + back), (char *)set))
	{
		if (back == 0 && back - 1 != 0)
			return (0);
		back--;
	}
	return (back);
}

static size_t	ft_front(char *s1, char const *set)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)s1;
	while (is_in(*(temp + i), (char *)set))
		i++;
	if (i == ft_strlen(s1))
		return (0);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		back;
	size_t		front;
	char		*temp;
	char		*str;

	if (!s1 || !*s1)
		return (NULL);
	i = 0;
	temp = (char *)s1;
	back = ft_back(temp, set);
	front = ft_front(temp, set);
	if (front == 0 && back == 0 && is_in(*temp, set))
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (i <= back - front)
	{
		*(str + i) = *(temp + front + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

// int	main(void)
// {
// 	// char set[] = "3";
// 	// char s1[] = "123123123";
// 	printf("%s\n", ft_strtrim("", NULL));
// }