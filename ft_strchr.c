/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:48:09 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/10 21:52:32 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "abcccdebbc";
// 	printf("%s\n", ft_strchr(str,'b'));
// 	printf("%s\n", strchr(str,'b'));
// 	printf("%s\n", ft_strchr(str,'c'));
// 	printf("%s\n", strchr(str,'c'));
// 	printf("%s\n", ft_strchr(str,'W'));
// 	printf("%s\n", strchr(str,'W'));
// 	printf("%s\n", ft_strchr(str,'\0'));
// 	printf("%s\n", strchr(str,'\0'));
// }