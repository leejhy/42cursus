/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:16:36 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/08 17:04:42 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
		{
			temp = (char *)s;
			cnt++;
		}
		s++;
	}
	if (!cnt && c == '\0')
		return ((char *)s);
	if (!cnt && c != '\0')
		return (NULL);
	return (temp);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "abcdebbc";
	printf("%s\n", strrchr(str,'b'));
	printf("%s\n", ft_strrchr(str,'b'));
	printf("%s\n", strrchr(str,'d'));
	printf("%s\n", ft_strrchr(str,'d'));
	printf("%s\n", strrchr(str,'W'));
	printf("%s\n", ft_strrchr(str,'W'));
	printf("%s\n", strrchr(str,'\0'));
	printf("%s\n", ft_strrchr(str,'\0'));
}