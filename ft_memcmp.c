/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:02:37 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/08 19:24:05 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) > *(unsigned char *)(s2 + i))
			return (1);
		if (*(unsigned char *)(s1 + i) < *(unsigned char *)(s2 + i))
			return (-1);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", memcmp("abced", "abcee", 6));//같을때
	printf("%d\n", ft_memcmp("abced", "abcee", 6));
	printf("%d\n", memcmp("abc", "abz", 4));// 다를때
	printf("%d\n", ft_memcmp("abc", "abz", 4));
	printf("%d\n", memcmp("abced", "abced", 10));//같은데 바이트 더클때
	printf("%d\n", ft_memcmp("abced", "abced", 10));
	printf("%d\n", memcmp("abczd", "abc", 10));//문자열 길이 다를때
	printf("%d\n", ft_memcmp("abczd", "abc", 10));
	printf("%d\n", memcmp("abc", "abcccz", 10));//문자열 길이 다를때
	printf("%d\n", ft_memcmp("abc", "abcccz", 10));

}