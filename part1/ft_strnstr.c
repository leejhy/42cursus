/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:47 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/10 21:56:13 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 != 0 || *s2 != 0) && *s2 != 0)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!needle)
		return (NULL);
	while (i < len && *(haystack + i))
	{
		if (!ft_strcmp(haystack + i, needle))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

int main(void)
{
    printf("%s\n",ft_strnstr("2212212212211","2211",20));
    printf("%s\n",ft_strnstr("2212212212211","2211",20));
}
