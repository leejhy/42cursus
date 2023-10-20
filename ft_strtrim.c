/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:38:05 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/19 20:56:35 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_front_set(char const *s1, char const *set)
{
	size_t	cnt;

	cnt = 0;
	while (*(s1 + cnt) && is_set(*(s1 + cnt), set))
		cnt++;
	return (cnt);// cnt - 1 이 인덱스
}

static size_t	ft_rear_set(char const *s1, char const *set)
{
	size_t	cnt;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s1_len--;// s1_len은 널문자 가리키기 때문에 1줄임
	cnt = 0;
	while (s1_len - cnt >= 0 && is_set(*(s1 + (s1_len - cnt)), set))
		cnt++;
	return (cnt);
}

static char	*ft_error(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char *substr;
	size_t	s1_len;
	size_t	front;
	size_t	rear;
	size_t	i;

	i = 0;
	s1_len = ft_strlen(s1);//20
	front = ft_front_set(s1, set);//4
	rear = ft_rear_set(s1, set);// 8 여기 까지 문제 x
	if (s1_len == front && s1_len == rear)
	{
		substr = ft_error();
		return (substr);
	}
	substr = malloc(sizeof(char) * s1_len - front - rear + 1);
	if (!substr)
		return (NULL);
	while (i < s1_len - rear - front)
	{
		*(substr + i) = *(s1 + front + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}

int	main(void)
{
	printf("%s\n",ft_strtrim("2132He213llo21112312","213"));
	printf("%s\n",ft_strtrim("",""));
	printf("%s\n",ft_strtrim("", "cdef"));
	printf("%s\n",ft_strtrim("          "," "));
	printf("%s\n",ft_strtrim("ab cd  f    ", " "));
	printf("%s\n",ft_strtrim("xxxz  test with x and z and x .  zx  xx z", "z x"));//26바이트 할당해야함
}